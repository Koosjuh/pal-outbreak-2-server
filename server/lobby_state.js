'use strict';
/**
 * server/lobby_state.js — the live, in-memory session/area/room/slot registry.
 *
 * G12 core. Replaces the FAKED app layer (hardcoded area counts, canned room list) with a
 * REAL retained membership model. ONE shared singleton for UDP (game_udp_server.js) and TCP
 * (snap_server.js) — both run in the same node process (start_all.js), so a shared require works.
 *
 * Design (docs/findings/protocol/G12-KICKOFF-HANDOVER-2026-07-09.md + G12-DESIGN-REVIEW-2026-07-09.md,
 * second_opinion + Codex 2026-07-11):
 *  - Keyed by CANONICAL player identity: userid when known, else normalized handle, else a transient
 *    endpoint key until bind. ip:port is a transport ENDPOINT, not identity (avoids NAT/port churn).
 *  - session_store.js stays the disk-backed pending-login bridge; THIS module owns the live in-memory
 *    area/room/slot membership, indexes, and timeout cleanup. No disk here.
 *  - Derived outputs (area counts, room list) are computed from indexes ON DEMAND, never stored fields.
 *  - Bioserver is the BEHAVIOR model, but it is TCP middleware and we are SN@P/UDP — mirror its state
 *    transitions (Client{area,room,slot}, countPlayersInArea; ClientList.java / PacketHandler.java),
 *    NOT its bytes. The SN@P wire form of each read/write is confirmed separately on the pcap.
 *
 * Lifecycle (Codex review): re-register REPLACES the active endpoint for the same identity;
 * disconnect/timeout CLEARS area/room/slot; multiple endpoints behind one IP must not collide
 * (bind by identity, fall back to endpoint only until bind).
 */

const AREA_SELECT = 0; // area == 0 means "in Area Select / not in an area" (Bioserver convention)

// Slot status lifecycle — direct port of Slot.java:30-34 (FOUNDATION-MAP step 1).
// FREE -> INCREATE (host configuring; NOT joinable, PacketHandler.java:1660) -> GAMESET (joinable,
// set at the host's go-live 6504 burst) -> BUSY (full or started) -> back to FREE on reset.
const SLOT = Object.freeze({ FREE: 1, INCREATE: 2, GAMESET: 3, BUSY: 4 });

function normHandle(h) { return h == null ? null : String(h).trim().toLowerCase(); }

class LobbyState {
  constructor() {
    this.players = new Map();       // idKey -> player object
    this.endpointIndex = new Map(); // "ip:port" (UDP transport key) -> idKey
    this.areaIndex = new Map();     // areaId -> Set<idKey>   (players currently in that area)
    this.rooms = new Map();         // roomHandle (u32) -> room object  (the 0x6fee68 registry gap)
    this._nextRoomHandle = 1;       // server-minted room handles (client renders these in op49, ENTERs to them)
    this._vacantHandles = [];       // pre-minted handles for VACANT slots (Bioserver model: slots EXIST
                                    // server-side; "Vacant" is a status). The client's create-ENTER targets
                                    // 0x6fee68[idx], which is 0 for an unadvertised slot -> the ENTER never
                                    // transmits (rig-proven 2026-07-12). Advertising vacant handles in op49
                                    // is what makes create-on-a-Vacant-slot possible.
  }

  // ---- vacant slots (create targets) --------------------------------------
  /** Ensure n pre-minted vacant slot handles exist (persistent; consumed by createRoom, replenished here). */
  vacantHandles(n) {
    while (this._vacantHandles.length < n) this._vacantHandles.push(this._nextRoomHandle++);
    return this._vacantHandles.slice(0, n);
  }

  // ---- identity ----------------------------------------------------------
  _canonicalId({ userid, handle, transportKey }) {
    if (userid != null && userid !== '') return `uid:${userid}`;
    const nh = normHandle(handle);
    if (nh) return `h:${nh}`;
    return `ep:${transportKey}`; // transient identity until a register/bind supplies userid/handle
  }

  _ensurePlayer(idKey, seed = {}) {
    let p = this.players.get(idKey);
    if (!p) {
      p = {
        idKey,
        userid: seed.userid ?? null,
        handle: seed.handle ?? null,
        udpKeys: new Set(),   // "ip:port" transport endpoints bound to this identity
        tcpConnIds: new Set(),// TCP snap_server conn ids (for 0x6205 etc.), added when wired
        area: AREA_SELECT,
        room: 0,
        slot: 0,
        playerNo: 0,
        host: false,
        state: 'connected',
        // Identity (FOUNDATION step 1/3): the Bioserver HNPair + charstats port. hnpair is set by the
        // HNSELECT handler when the identity layer lands; until then roster names stay synthetic.
        hnpair: null,          // { handle: string(<=6), nickname: string } | null
        charStats: null,       // opaque client blob (Bioserver 0xD0), stored on CHARSELECT, echoed in rosters
        // Liveness (FOUNDATION step 1): room-level soft net (op10 sub-0x0e) + conncheck port.
        lastRoomLivenessAt: 0, // updated by the engine on each in-room liveness ping
        connAlive: true,       // Bioserver Client.connalive analog (conncheck cycle)
        firstSeen: Date.now(),
        lastSeen: Date.now(),
      };
      this.players.set(idKey, p);
    }
    if (seed.userid != null && seed.userid !== '') p.userid = seed.userid;
    if (seed.handle != null) p.handle = seed.handle;
    p.lastSeen = Date.now();
    return p;
  }

  // ---- binding -----------------------------------------------------------
  /**
   * Bind a UDP transport endpoint (ip:port) to a player, keyed by identity when known.
   * Called on UDP register (session_store has userid/handle by then). Re-register with the same
   * identity from a new endpoint REPLACES: the endpoint moves to the identity's player, and a prior
   * transient player for that endpoint is reclaimed.
   */
  bindEndpoint({ transportKey, userid = null, handle = null }) {
    if (!transportKey) return null;
    const idKey = this._canonicalId({ userid, handle, transportKey });
    const p = this._ensurePlayer(idKey, { userid, handle });
    const prev = this.endpointIndex.get(transportKey);
    if (prev && prev !== idKey) {
      // endpoint was on a transient/other player — carry over its area membership, then detach
      const prevP = this.players.get(prev);
      if (prevP && p.area === AREA_SELECT && prevP.area !== AREA_SELECT) this._setArea(p, prevP.area);
      this._detachEndpoint(transportKey, prev);
    }
    this.endpointIndex.set(transportKey, idKey);
    p.udpKeys.add(transportKey);
    p.state = 'connected';
    return p;
  }

  playerByEndpoint(transportKey) {
    const idKey = this.endpointIndex.get(transportKey);
    return idKey ? this.players.get(idKey) || null : null;
  }

  /** Resolve a player for a transport endpoint, creating a transient (unbound) one if needed. */
  resolve(transportKey) {
    return this.playerByEndpoint(transportKey) || this.bindEndpoint({ transportKey });
  }

  // ---- transitions (event-style mutations) --------------------------------
  /** enterArea: op06 area-confirm completed (screen 0x6c4b90 1->2). areaId is the entered area. */
  enterArea(transportKey, areaId) {
    const p = this.resolve(transportKey);
    this._setArea(p, areaId);
    return p;
  }

  /** exitArea: op07/op08 leave completed (back to Area Select). Clears area + room + slot. */
  exitArea(transportKey) {
    const p = this.playerByEndpoint(transportKey);
    if (!p) return null;
    if (p.room) this.leaveRoom(transportKey); // leaving the area leaves any room first
    this._setArea(p, AREA_SELECT);
    p.room = 0; p.slot = 0;
    return p;
  }

  _setArea(p, areaId) {
    if (p.area === areaId) { p.lastSeen = Date.now(); return; }
    if (p.area != null && p.area !== AREA_SELECT) {
      const old = this.areaIndex.get(p.area);
      if (old) { old.delete(p.idKey); if (old.size === 0) this.areaIndex.delete(p.area); }
    }
    p.area = areaId;
    p.lastSeen = Date.now();
    if (areaId != null && areaId !== AREA_SELECT) {
      let set = this.areaIndex.get(areaId);
      if (!set) { set = new Set(); this.areaIndex.set(areaId, set); }
      set.add(p.idKey);
    }
  }

  // ---- derived outputs (computed on demand) -------------------------------
  /**
   * Bioserver countPlayersInArea (ClientList.java:206-227): number of players whose area==areaId
   * AND room==0 (i.e. in the area lobby, not inside a room). Room-aware counting refines later.
   */
  areaPlayerCount(areaId) {
    const set = this.areaIndex.get(areaId);
    if (!set) return 0;
    let n = 0;
    for (const idKey of set) { const p = this.players.get(idKey); if (p && p.room === 0) n++; }
    return n;
  }

  /** Recipients for an area-count broadcast: players in that area OR in Area Select with room==0. */
  areaCountRecipients(areaId) {
    const out = [];
    for (const p of this.players.values()) {
      if (p.room !== 0) continue;
      if (p.area === areaId || p.area === AREA_SELECT) out.push(p);
    }
    return out;
  }

  // ---- FOUNDATION step 1: Bioserver count/audience ports -------------------
  /**
   * countArea — the full Bioserver AREAPLAYERCNT triple (ClientList.java:207-227):
   * inLobby = area==N && room==0; inRoom = area==N && room>0; inGame = reserved (gameserver clients,
   * none yet). Distinct from areaPlayerCount() (kept unchanged for the live 0x6205 path).
   */
  countArea(areaId) {
    let inLobby = 0, inRoom = 0;
    for (const p of this.players.values()) {
      if (p.area !== areaId) continue;
      if (p.room === 0) inLobby++; else inRoom++;
    }
    return { inLobby, inRoom, inGame: 0 };
  }

  /** Total online players (the server-select 0x6504 current-players value — replaces the =0 stub). */
  countOnline() { return this.players.size; }

  /** Audience: players viewing the room list of an area (area==N, room==0) — broadcastInArea port. */
  viewersOfArea(areaId) {
    const out = [];
    for (const p of this.players.values()) if (p.area === areaId && p.room === 0) out.push(p);
    return out;
  }

  /** Audience: players sitting in Area Select (area==0) — the area-select half of
   *  broadcastInAreaNAreaSelect (PacketHandler.java:189-207). */
  areaSelectViewers() {
    const out = [];
    for (const p of this.players.values()) if (p.area === AREA_SELECT && p.room === 0) out.push(p);
    return out;
  }

  /** Audience: a room's members as player objects (broadcastInSlot port). */
  membersOf(handle) {
    const room = this.rooms.get(handle);
    if (!room) return [];
    const out = [];
    for (const idKey of room.members) { const p = this.players.get(idKey); if (p) out.push(p); }
    return out;
  }

  /** Audience: room members PLUS same-area room-list viewers — broadcastInSlotNRoom port
   *  (PacketHandler.java:274-292): the people whose SCREEN shows this room's status/count. */
  roomAndListViewers(handle) {
    const room = this.rooms.get(handle);
    if (!room) return [];
    const seen = new Set();
    const out = [];
    for (const p of this.membersOf(handle)) { seen.add(p.idKey); out.push(p); }
    for (const p of this.viewersOfArea(room.area)) if (!seen.has(p.idKey)) out.push(p);
    return out;
  }

  // ---- FOUNDATION step 1: identity + liveness setters ----------------------
  /** HNSELECT port: store the chosen handle/nickname pair. Default-seeded from the login name. */
  setIdentity(transportKey, { handle, nickname }) {
    const p = this.resolve(transportKey);
    p.hnpair = { handle: String(handle ?? '').slice(0, 6), nickname: String(nickname ?? handle ?? '') };
    return p;
  }

  /** CHARSELECT port: store the opaque charstats blob (echoed into rosters when the vehicle lands). */
  setCharStats(transportKey, blob) {
    const p = this.resolve(transportKey);
    p.charStats = blob || null;
    return p;
  }

  /** Display name for roster records: real identity when known, synthetic fallback otherwise. */
  displayName(p, fallback) {
    return (p && p.hnpair && p.hnpair.nickname) || (p && p.hnpair && p.hnpair.handle)
      || (p && p.handle) || fallback;
  }

  touchRoomLiveness(transportKey) {
    const p = this.playerByEndpoint(transportKey);
    if (p) p.lastRoomLivenessAt = Date.now();
    return p;
  }

  // ---- FOUNDATION step 1: slot status lifecycle (engine-gated; additive) ---
  /**
   * Bioserver slot-status recompute (PacketHandler.java:1383-1389 + Slot.java): called by the ENGINE
   * after membership changes. Does NOT alter legacy joinRoom/createRoom behavior (the live flag paths
   * ignore status); seeded rooms sit at GAMESET (always joinable), created rooms enter INCREATE and
   * go GAMESET at the go-live transition.
   */
  recomputeRoomStatus(handle) {
    const room = this.rooms.get(handle);
    if (!room) return null;
    const n = room.members.size;
    if (room.seeded) { room.status = n >= room.maxPlayers ? SLOT.BUSY : SLOT.GAMESET; return room.status; }
    if (n === 0) room.status = SLOT.FREE;
    else if (n >= room.maxPlayers) room.status = SLOT.BUSY;
    else if (room.status === SLOT.BUSY || room.status === SLOT.GAMESET) room.status = SLOT.GAMESET;
    return room.status;
  }

  /** Bioserver getFreePlayerNum port (ClientList.java:98-108): lowest free of {2,3,4}; host is 1. */
  assignPlayerNo(handle, transportKey) {
    const room = this.rooms.get(handle);
    const p = this.playerByEndpoint(transportKey);
    if (!room || !p) return 0;
    if (room.hostId === p.idKey) { p.playerNo = 1; return 1; }
    const taken = new Set();
    for (const idKey of room.members) {
      const m = this.players.get(idKey);
      if (m && m.idKey !== p.idKey && m.playerNo) taken.add(m.playerNo);
    }
    for (let n = 2; n <= (room.maxPlayers || 4); n++) if (!taken.has(n)) { p.playerNo = n; return n; }
    return 0;
  }

  // ---- rooms (the 0x6fee68 room-handle registry) --------------------------
  /**
   * Create a room hosted by the player at transportKey. Server MINTS the handle (the client renders it
   * in op49 and ENTERs 0x6e to it). Rules/area are effectively client-local (area+0x16c), but we retain
   * name/maxPlayers/area so op49 records + occupancy are real. Returns the room.
   */
  createRoom(transportKey, { name = 'ROOM', maxPlayers = 4, flags = 0, handle: wantHandle = 0 } = {}) {
    const p = this.resolve(transportKey);
    if (p.room) this.leaveRoom(transportKey);      // leave any current room first (no leaked occupancy)
    // Bind to the requested handle when it's a free vacant-slot handle (the client ENTERed that slot's
    // advertised handle); otherwise mint fresh. The op09 USER/MAXI replies deliver the authoritative
    // handle back to the client's 0x6fee68 registry, so a collision self-corrects.
    let handle;
    const vi = this._vacantHandles.indexOf(wantHandle >>> 0);
    if (wantHandle && vi !== -1 && !this.rooms.has(wantHandle >>> 0)) {
      handle = wantHandle >>> 0;
      this._vacantHandles.splice(vi, 1);
    } else {
      handle = this._nextRoomHandle++;
    }
    const room = {
      handle,
      name: String(name).slice(0, 20),
      hostId: p.idKey,
      area: p.area,            // the host's area (client-local rules; retained for later game-start)
      maxPlayers,
      flags,
      members: new Set([p.idKey]),
      createdAt: Date.now(),
      status: SLOT.INCREATE,   // Bioserver: CREATESLOT -> INCREATE; go-live (6504 analog) -> GAMESET.
                               // Additive field: the legacy flag paths never read it.
      livetime: 0,             // GAMESET deadline (set at go-live; Slot.java:187-197)
    };
    this.rooms.set(handle, room);
    p.room = handle; p.slot = 0; p.host = true; p.playerNo = 1;
    return room;
  }

  /**
   * Seed a SERVER-OWNED persistent room (no real host). Used while create-your-own-room is still walled
   * (the STAT/0x70 slot handshake needs a slot handle the client can't get for a Vacant slot yet): it lets
   * 2 clients JOIN the SAME real registry room for co-location. Not dissolved when it empties. Returns it.
   */
  seedRoom({ name = 'ROOM', maxPlayers = 4, flags = 0, area = 1 } = {}) {
    const handle = this._nextRoomHandle++;
    const room = {
      handle, name: String(name).slice(0, 20), hostId: null, area, maxPlayers, flags,
      members: new Set(), createdAt: Date.now(), seeded: true,
      status: SLOT.GAMESET, livetime: 0,   // seeded server rooms are always joinable
    };
    this.rooms.set(handle, room);
    return room;
  }

  /** Join an existing room by handle. Returns the room, or null if missing/full. */
  joinRoom(transportKey, handle) {
    const room = this.rooms.get(handle);
    if (!room) return null;
    const p = this.resolve(transportKey);
    if (p.room && p.room !== handle) this.leaveRoom(transportKey); // leave a different room first
    if (!room.members.has(p.idKey) && room.members.size >= room.maxPlayers) return null; // full
    room.members.add(p.idKey);
    p.room = handle; p.host = (room.hostId === p.idKey);
    return room;
  }

  /** Leave the player's current room; dissolve it if the host leaves or it empties. */
  leaveRoom(transportKey) {
    const p = this.playerByEndpoint(transportKey);
    if (!p || !p.room) return null;
    const room = this.rooms.get(p.room);
    const handle = p.room;
    p.room = 0; p.host = false; p.slot = 0;
    if (room) {
      room.members.delete(p.idKey);
      // seeded (server-owned) rooms persist even when empty; only player-created rooms dissolve.
      if (!room.seeded && (room.hostId === p.idKey || room.members.size === 0)) this._dissolveRoom(handle);
    }
    return handle;
  }

  _dissolveRoom(handle) {
    const room = this.rooms.get(handle);
    if (!room || room.seeded) return;   // never dissolve a seeded server room
    for (const idKey of room.members) { const m = this.players.get(idKey); if (m && m.room === handle) { m.room = 0; m.host = false; } }
    this.rooms.delete(handle);
  }

  roomPlayerCount(handle) { const r = this.rooms.get(handle); return r ? r.members.size : 0; }

  /** UDP transport endpoints ("ip:port") of a room's members, excluding one (the joiner). For the
   *  joiner broadcast: reach each EXISTING member's session to push the new member's record. */
  roomMemberEndpoints(handle, exceptTransportKey = null) {
    const room = this.rooms.get(handle);
    if (!room) return [];
    const eps = [];
    for (const idKey of room.members) {
      const p = this.players.get(idKey);
      if (!p) continue;
      for (const k of p.udpKeys) if (k !== exceptTransportKey) eps.push(k);
    }
    return eps;
  }

  /** All rooms as op49-ready records (handle,name,current,max,flags). Effectively a single global list. */
  roomList() {
    return [...this.rooms.values()].map(r => ({
      handle: r.handle, name: r.name, current: r.members.size, max: r.maxPlayers, flags: r.flags, area: r.area,
    }));
  }

  // ---- lifecycle / cleanup ------------------------------------------------
  _detachEndpoint(transportKey, idKey) {
    const p = this.players.get(idKey);
    if (p) p.udpKeys.delete(transportKey);
    if (p && p.udpKeys.size === 0 && p.tcpConnIds.size === 0) this._removePlayer(idKey);
  }

  /** Called on UDP endpoint TTL expiry / disconnect — clears this endpoint's membership. */
  removeEndpoint(transportKey) {
    const idKey = this.endpointIndex.get(transportKey);
    this.endpointIndex.delete(transportKey);
    if (idKey) this._detachEndpoint(transportKey, idKey);
  }

  _removePlayer(idKey) {
    const p = this.players.get(idKey);
    if (!p) return;
    if (p.room) {                                  // disconnecting leaves any room (dissolve if host/empty)
      const room = this.rooms.get(p.room);
      if (room) {
        room.members.delete(idKey);
        if (!room.seeded && (room.hostId === idKey || room.members.size === 0)) this._dissolveRoom(p.room);
      }
    }
    if (p.area != null && p.area !== AREA_SELECT) {
      const set = this.areaIndex.get(p.area);
      if (set) { set.delete(idKey); if (set.size === 0) this.areaIndex.delete(p.area); }
    }
    for (const k of p.udpKeys) if (this.endpointIndex.get(k) === idKey) this.endpointIndex.delete(k);
    this.players.delete(idKey);
  }

  // ---- diagnostics --------------------------------------------------------
  stats() {
    return {
      players: this.players.size,
      endpoints: this.endpointIndex.size,
      areas: [...this.areaIndex.entries()].map(([a, s]) => `${a}:${s.size}`).join(',') || '-',
    };
  }
}

const singleton = new LobbyState();
singleton.LobbyState = LobbyState; // expose class for unit tests
singleton.AREA_SELECT = AREA_SELECT;
singleton.SLOT = SLOT;
module.exports = singleton;
