'use strict';
/**
 * server/lobby_engine.js — the reference-server (Bioserver) PacketHandler port, FOUNDATION step 1.
 *
 * Design: docs/design/ROOM-ENGINE-DESIGN-2026-07-17.md (three-review final) +
 * docs/design/FOUNDATION-MAP-2026-07-17.md (the remap dictionary, T24 owner plan of record).
 *
 * SHAPE (per the reviewed design §4.2):
 *  - PURE TRANSITIONS over lobby_state: each inbound transition mutates the registry and returns an
 *    EMISSION PLAN — an array of { to, kind, args } — WITHOUT building any wire bytes.
 *  - `to` is a lobby_state player object (the frontends resolve it to a transport adapter per
 *    recipient: nextTxSeq/sendSnapPacket/rel-window on UDP, conn write on TCP). The engine NEVER
 *    sends; the frontends own transport, seq, generation echo, and the multiplex/reliable layers.
 *  - `kind` names a vehicle from the FOUNDATION MAP. Proven vehicles get builders in the frontends;
 *    unmapped kinds are emitted as `needs-vehicle:*` — the frontends LOG these (journal-visible) and
 *    drop them, so every missing dictionary entry is observable instead of silently wrong.
 *  - Bioserver order is preserved inside each plan (the reference's reply/broadcast sequences).
 *
 * Deployment: routing inbound messages into the engine is gated per increment
 * (SNAP_ROOM_ENGINE master + _TRACE/_LIVENESS/_REBUILD/_LIFECYCLE sub-flags — design §6 ladder).
 * This module itself is inert until a frontend routes to it.
 */

const defaultState = require('./lobby_state');
const SLOT = defaultState.SLOT;

// Emission kinds (the vehicle dictionary — FOUNDATION-MAP §per-phase tables).
// Proven/live vehicles:
const K = Object.freeze({
  AREA_COUNT: 'area-count-0x6205',            // TCP 0x6205 T+B (Bioserver AREAPLAYERCNT)
  ROOM_COUNT: 'room-count-0x6303',            // TCP 0x6303 (Bioserver ROOMPLAYERCNT)
  SERVER_COUNT: 'server-count-0x6504',        // TCP 0x6504 current-players (replaces the =0 stub)
  ROOMLIST_DIRTY: 'op49-roomlist-refresh',    // op49 records re-derive from the registry on next pull
  MEMBER_JOIN: 'op06-member-join-push',       // member record push (Bioserver PLAYERSTATBC analog)
  MEMBER_LEAVE: 'op07-member-leave-push',     // SPINE-3 survivor-notify: op07 slot-6 FUN_005bb670 (leaver id @body+0)
  MEMBER_LIST: 'op0a-memberlist',             // full member list (pull reply; PROVEN multi-record)
  COUNT_0X11: 'op10-sub11-count',             // in-room count update (Bioserver SLOTPLRSTATUS analog)
  JOIN_ACCEPT_0C: 'op10-sub0c-join-accept',   // fires FUN_00601300 (PROVEN, T22)
  LIVENESS_0F: 'op10-sub0f-liveness',         // reply to sub-0x0e (ladder 1a)
  // NEEDS-VEHICLE stubs (targeted-RE list, design §5) — frontends log + drop:
  // NV_LEAVE_NOTIFY / NV_CANCEL_NOTIFY are REPURPOSED to the real MEMBER_LEAVE vehicle (SPINE-3:
  // SPINE-2-3-lobby-leave-RE-2026-07-19 — host-departure uses the SAME op07 with the host's id, no
  // distinct dissolve op). Kept as aliases of MEMBER_LEAVE for any dictionary/doc reference continuity.
  NV_LEAVE_NOTIFY: 'op07-member-leave-push',              // -> MEMBER_LEAVE (member leave survivor-notify)
  NV_CANCEL_NOTIFY: 'op07-member-leave-push',             // -> MEMBER_LEAVE (host departure = same op07, SPINE-3)
  NV_CONFIG_PUSH: 'needs-vehicle:room-config-push',       // rules/scenario (op10 sub-3/5/6/7 driver)
  NV_CHAT_OUT: 'needs-vehicle:chat-out',                  // Bioserver CHATOUT relay
});

function emit(to, kind, args = {}) { return { to, kind, args }; }

/** Factory: bind the engine to a state instance (the singleton in production, fresh in tests). */
function createEngine(L) {

/** Count-update emissions for an area transition (Bioserver: B AREAPLAYERCNT -> area + area-select). */
function areaCountEmissions(areaId) {
  const out = [];
  const audience = [...L.viewersOfArea(areaId), ...L.areaSelectViewers()];
  for (const to of audience) out.push(emit(to, K.AREA_COUNT, { areaId, counts: L.countArea(areaId) }));
  return out;
}

/** Room/slot count emissions to everyone whose screen shows this room (broadcastInSlotNRoom port). */
function roomCountEmissions(handle) {
  const room = L.rooms.get(handle);
  if (!room) return [];
  const out = [];
  const count = room.members.size;
  for (const to of L.roomAndListViewers(handle)) {
    out.push(emit(to, K.COUNT_0X11, { handle, count, max: room.maxPlayers }));
    out.push(emit(to, K.ROOMLIST_DIRTY, { handle }));
  }
  return out;
}

const engine = {
  K,
  SLOT,

  // ---- Phase 2: area layer (Bioserver AREASELECT/EXITAREA, PacketHandler.java:733/1136) ----------
  enterArea(transportKey, areaId) {
    const p = L.enterArea(transportKey, areaId);
    return { player: p, plan: areaCountEmissions(areaId) };
  },

  exitArea(transportKey) {
    const p = L.playerByEndpoint(transportKey);
    const oldArea = p ? p.area : 0;
    const leftRoom = p && p.room ? this.leaveRoom(transportKey) : null;
    L.exitArea(transportKey);
    const plan = leftRoom ? [...leftRoom.plan] : [];
    if (oldArea) plan.push(...areaCountEmissions(oldArea));
    return { player: p, plan };
  },

  // ---- Phase 4: room lifecycle (the reviewed room-engine component) ------------------------------
  /** CREATESLOT analog: room minted INCREATE (not joinable until goLive — PacketHandler.java:1196). */
  createRoom(transportKey, opts) {
    const room = L.createRoom(transportKey, opts);
    room.status = SLOT.INCREATE;
    return { room, plan: roomCountEmissions(room.handle) };
  },

  /** The go-live transition (Bioserver 6504 burst, PacketHandler.java:1305-1343): INCREATE->GAMESET.
   *  Config broadcasts (pwdprot/scentype/attrib2) are Phase-3 vehicles -> needs-vehicle stub. */
  goLive(transportKey) {
    const p = L.playerByEndpoint(transportKey);
    if (!p || !p.room) return { room: null, plan: [] };
    const room = L.rooms.get(p.room);
    if (!room || room.hostId !== p.idKey) return { room, plan: [] };
    room.status = SLOT.GAMESET;
    room.livetime = Date.now() + 10 * 60 * 1000;   // Bioserver default waitLimit 10 min
    const plan = roomCountEmissions(room.handle);
    for (const to of L.membersOf(room.handle)) plan.push(emit(to, K.NV_CONFIG_PUSH, { handle: room.handle }));
    return { room, plan };
  },

  /**
   * JOINGAME analog (PacketHandler.java:1642-1703). Guards: INCREATE/BUSY reject. On success:
   * playerNo assign, member-JOIN pushes (joiner's record to EACH member INCLUDING the joiner —
   * PLAYERSTATBC + the T-proven self-push), sub-0x11 counts to the others, count invalidation.
   * NOTE: the sub-0x0C join-accept is NOT emitted here — it answers the joiner's op10 sub-0x02
   * (design §4.2, T21/T22).
   */
  joinRoom(transportKey, handle) {
    const room = L.rooms.get(handle);
    if (!room) return { ok: false, reason: 'not-found', room: null, plan: [] };
    const st = room.status ?? (room.seeded ? SLOT.GAMESET : SLOT.GAMESET);
    if (st === SLOT.BUSY) return { ok: false, reason: 'full', room, plan: [] };
    if (st === SLOT.INCREATE) return { ok: false, reason: 'in-create', room, plan: [] };
    // Idempotency (PoC crit 2): a re-join by an existing member must NOT create a duplicate row or
    // re-emit the join delta. Check membership BEFORE the Set add.
    const pre = L.playerByEndpoint(transportKey);
    const alreadyMember = !!(pre && room.members.has(pre.idKey));
    const joined = L.joinRoom(transportKey, handle);
    if (!joined) return { ok: false, reason: 'full', room, plan: [] };
    const p = L.playerByEndpoint(transportKey);
    if (!alreadyMember) L.assignPlayerNo(handle, transportKey);
    L.recomputeRoomStatus(handle);
    // TWO-VEHICLE roster (SPINE-7, rig-proven): op06 = LIVE incremental draw; op0a = DURABLE whole-list
    // buffer. A join must push BOTH, ORDERED per recipient (op06 delta first, then op0a durable) so the
    // existing members RENDER the new joiner (op06) and survive any redraw (op0a). The joiner itself gets
    // op0a (whole list) → sees everyone. Deterministic order via the single emission plan (kills RF-11).
    // Member record: id = playerNo (host=1, joiners 2..); NAME via authoritative displayName (real login
    // handle, NOT a synthetic 'CREATOR'/'PLAYERn'). This is the RF-15 naming fix.
    const recOf = (m) => {
      const idx = [...room.members].indexOf(m.idKey);
      const id = m.playerNo || (idx + 1);
      return { id, name: L.displayName(m, (room.hostId === m.idKey ? 'HOST' : 'PLAYER' + id)) };
    };
    const members = L.membersOf(handle);
    const plan = [];
    // IDEMPOTENCY (Codex #5): a re-join by an existing member emits NOTHING — no op06 delta, and no op0a/
    // count re-emit. The membership Set is unchanged, so there is no state to re-broadcast (migration-map
    // invariant "skip re-emit if already member"). Only a genuine NEW join produces the plan below.
    if (!alreadyMember) {
      // op06 LIVE-DRAW deltas (SPINE-7 op06=live-draw / op0a=durable): existing members see the joiner,
      // AND the joiner sees EVERY member including itself (the self-push the legacy did as "B sees A"×n +
      // "B sees B"). RF-15: sending the joiner op0a only left it at 1/[host] — it needs op06 to draw rows.
      const joinerRec = recOf(p);
      for (const to of members) if (to.idKey !== p.idKey) plan.push(emit(to, K.MEMBER_JOIN, joinerRec)); // existing ← joiner
      for (const m of members) plan.push(emit(p, K.MEMBER_JOIN, recOf(m)));                               // joiner ← every member (incl self)
      for (const to of members) plan.push(emit(to, K.MEMBER_LIST, { handle }));  // op0a durable buffer to all
      plan.push(...roomCountEmissions(handle));                                  // op10 sub-0x11 count
    }
    return { ok: true, room, player: p, alreadyMember, plan };
  },

  /** The joiner's op10 sub-0x02 join-request -> the PROVEN sub-0x0C accept (ladder; T22). */
  onJoinRequest(transportKey) {
    const p = L.playerByEndpoint(transportKey);
    const room = p && p.room ? L.rooms.get(p.room) : null;
    if (!room) return { plan: [] };
    return { plan: [emit(p, K.JOIN_ACCEPT_0C, { handle: room.handle, count: room.members.size })] };
  },

  /** In-room liveness ping (op10 sub-0x0e) -> touch + sub-0x0f reply (ladder 1a). */
  onRoomLiveness(transportKey) {
    const p = L.touchRoomLiveness(transportKey);
    if (!p) return { plan: [] };
    return { plan: [emit(p, K.LIVENESS_0F, {})] };
  },

  /**
   * Host publish (op10 sub-1 about a member) — AUTHORITATIVE REBUILD (design §4.2: never forward
   * client bytes). 1b GATE: increment-0 decode decides synthetic-vs-store-and-echo; until then this
   * only refreshes the member lists (the durable path) for every member.
   */
  onHostPublish(transportKey /* , decoded */) {
    const p = L.playerByEndpoint(transportKey);
    const room = p && p.room ? L.rooms.get(p.room) : null;
    if (!room || room.hostId !== p.idKey) return { plan: [] };
    const plan = [];
    for (const to of L.membersOf(room.handle)) {
      plan.push(emit(to, K.MEMBER_LIST, { handle: room.handle }));
    }
    return { plan };
  },

  /**
   * roomStateChanged (C1): the authoritative "re-push the whole room state to every member" primitive.
   * Used whenever membership/config changes and the caller has ALREADY mutated lobby_state (e.g. the
   * legacy join path calls lobbyState.joinRoom upstream, then asks the engine to broadcast). Emits the
   * full member list to each member (idempotent full-state, survives the client's whole-list redraw)
   * + the registry-derived count. This is the single source of truth reaching every client.
   */
  roomStateChanged(handle) {
    const room = L.rooms.get(handle);
    if (!room) return { plan: [] };
    const plan = [];
    for (const to of L.membersOf(handle)) plan.push(emit(to, K.MEMBER_LIST, { handle }));
    plan.push(...roomCountEmissions(handle));
    return { plan };
  },

  /** Member list pull (op0a in-room) — the PROVEN registry-backed reply. */
  onMemberListPull(transportKey) {
    const p = L.playerByEndpoint(transportKey);
    const room = p && p.room ? L.rooms.get(p.room) : null;
    if (!room) return { plan: [] };
    return { plan: [emit(p, K.MEMBER_LIST, { handle: room.handle })] };
  },

  /**
   * Leave (client op07/08 or timeout removeClient — Bioserver PacketHandler.java:1353-1396/1945-2028).
   * Host leaving dissolves (no migration); member leaving notifies survivors + recomputes status.
   *
   * SURVIVOR-NOTIFY vehicle = SN@P op07 (MEMBER LEAVE, slot 6 FUN_005bb670), decompile-settled in
   * SPINE-2-3-lobby-leave-RE-2026-07-19: each survivor reads the leaver's 32-bit member-id at body+0,
   * fires event 0x20 REMOVE-render, and decrements the in-room count (0x6cfb62). There is NO distinct
   * host-cancel opcode — a host departure is delivered through the SAME op07 carrying the host's id
   * (SD-5: dissolve). So both member-leave and host-leave emit K.MEMBER_LEAVE (wasHost flags dissolve).
   *
   * TWO-VEHICLE roster (same rule as join, SPINE-3 §Durability): op07 is the LIVE incremental REMOVE;
   * op0a is the DURABLE whole-list so the survivor's next poll does NOT re-add the leaver. Ordered per
   * the single plan: op07(survivors) -> op0a(survivors, durable) -> count.
   */
  leaveRoom(transportKey) {
    const p = L.playerByEndpoint(transportKey);
    if (!p || !p.room) return { plan: [] };
    const handle = p.room;
    const room = L.rooms.get(handle);
    const wasHost = room && room.hostId === p.idKey;
    // Capture the leaver's member-id BEFORE the mutation. The id survivors matched at join is the
    // playerNo (op06 record+0x10); op07 must carry that SAME id so FUN_005bb670 removes the right row.
    const leaverId = p.playerNo || (room ? [...room.members].indexOf(p.idKey) + 1 : 0);
    const leaverName = L.displayName(p, 'PLAYER' + (p.playerNo || '?'));
    // Survivors BEFORE the mutation — a host leave dissolves the room, and Bioserver notifies the
    // survivors of exactly that (the same op07 precedes the reset's effects reaching them).
    const survivors = L.membersOf(handle).filter(m => m.idKey !== p.idKey);
    L.leaveRoom(transportKey);
    const plan = [];
    // op07 LIVE REMOVE delta to every survivor (member id @body+0). Host-cancel = same op07 (SPINE-3).
    for (const to of survivors) {
      plan.push(emit(to, K.MEMBER_LEAVE, { id: leaverId, name: leaverName, handle, wasHost }));
    }
    if (L.rooms.has(handle)) {
      L.recomputeRoomStatus(handle);
      // op0a DURABLE whole-list re-push to the survivors (roster minus the leaver) so the next poll
      // does not re-add the leaver — then the registry-derived count.
      for (const to of L.membersOf(handle)) plan.push(emit(to, K.MEMBER_LIST, { handle }));
      plan.push(...roomCountEmissions(handle));
    } else {
      // Host left / room emptied -> dissolved. Survivors already got op07 (with the host id); the
      // room-list viewers just re-derive on the next pull.
      for (const to of L.viewersOfArea(room ? room.area : 0)) plan.push(emit(to, K.ROOMLIST_DIRTY, { handle }));
    }
    return { plan };
  },

  /** Liveness timeout (op40-primary; room sub-0x0e = soft net) -> the full leave cleanup. */
  onLivenessTimeout(transportKey) {
    return this.leaveRoom(transportKey);
  },

  /** Ghost sweep (Bioserver cleanGhostRooms, 5 min): GAMESET + 0 members -> FREE (seeded exempt). */
  ghostSweep() {
    const plan = [];
    for (const room of L.rooms.values()) {
      if (!room.seeded && room.status === SLOT.GAMESET && room.members.size === 0) {
        room.status = SLOT.FREE;
        for (const to of L.viewersOfArea(room.area)) plan.push(emit(to, K.ROOMLIST_DIRTY, { handle: room.handle }));
      }
    }
    return { plan };
  },

  // ---- shared record shape ----------------------------------------------------------------------
  /** The member record every push/list derives from: real identity when known, synthetic fallback. */
  memberRecord(room, p) {
    const idx = [...room.members].indexOf(p.idKey);
    const no = p.playerNo || (idx >= 0 ? idx + 1 : 0);
    return {
      id: no,
      name: L.displayName(p, (room.hostId === p.idKey) ? 'CREATOR' : 'PLAYER' + no),
      isHost: room.hostId === p.idKey,
      charStats: p.charStats,          // opaque; echoed once the identity layer lands (1b store-and-echo)
    };
  },
};

return engine;
}

module.exports = createEngine(defaultState);
module.exports.createEngine = createEngine;
