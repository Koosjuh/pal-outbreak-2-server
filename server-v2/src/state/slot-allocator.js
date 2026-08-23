/**
 * SLOT ALLOCATOR: playernum assignment and the join guards, ported from
 * bioserver `ClientList.getFreePlayerNum` + `PacketHandler.sendJoinGame` /
 * `sendCreateSlot` / `sendCancelSlot`. PORT-PLAN §A.1 row "getFreePlayerNum".
 *
 * Division of ownership (SERVER-V2-SURFACE §4.3 pattern):
 * - PRESENCE holds the assignment itself - `presence.moveTo(p, {roomHandle,
 *   slot})` is the only writer of WHERE (invariant P2);
 * - the PROFILE holds the attributes (`playernum`, `hostflag`);
 * - the LIFECYCLE holds the authored room status;
 * - this module is the ordering: guards first, then assignment, then the
 *   status consequence, mutate-then-emit throughout (rule L1).
 *
 * Playernum vs presence slot: bioserver playernums are 1..4 (host 1, joiners
 * first-free of 2..4 - ClientList.getFreePlayerNum lines 98-108). The
 * rig-confirmed create path already parks the host at presence slot 0
 * (`lobby-rooms.js openFor`), so presence slot = playernum - 1. The profile's
 * playernum is the wire-facing number; the presence slot is positional.
 *
 * Join guards, in the REFERENCE ORDER (sendJoinGame lines 1650-1702) - the
 * order is observable when a room is in more than one refusable state at once,
 * so it is pinned by tests:
 *   1. status BUSY            -> 'full'           ("game is full")
 *   2. status != GAMESET      -> 'not-possible'   ("not possible")
 *   3. password check          -> 'wrong-password' ("wrong password")
 * The PAL rejection VEHICLE is evidence-gated (PORT-PLAN slice 1b: no real
 * rejection has been captured), so the result is a reason code, not bytes.
 */

import { ROOM_STATUS } from './room-lifecycle.js';

export class SlotAllocatorError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'SlotAllocatorError';
    this.code = code;
  }
}

function fail(code, message) {
  throw new SlotAllocatorError(code, message);
}

/**
 * The refusal reasons. The first three map to the reference's markup messages
 * (sendJoinGame lines 1652, 1661, 1698); NO_PROFILE is a PAL-side state the
 * reference cannot reach (bioserver constructs the Client with its session),
 * added 2026-08-08 (nora pre-deploy fix 3): a session whose profile open was
 * refused at bind CAN send a join, and that is peer-reachable state, not a
 * programmer error - so it is a refusal result, never a throw through the
 * dispatch guard.
 */
export const JOIN_REFUSAL = Object.freeze({
  FULL: 'full',                     // "game is full"
  NOT_POSSIBLE: 'not-possible',     // "not possible"
  WRONG_PASSWORD: 'wrong-password', // "wrong password"
  NO_PROFILE: 'no-profile'          // profile-less session (profile open refused at bind)
});

const EMPTY_PASSWORD = Buffer.alloc(0);

export class SlotAllocator {
  #presence;
  #profiles;
  #lifecycle;

  /**
   * All three seams are REQUIRED (the constructor-seam pattern of
   * `SnapLobbySession`): an unwired allocator refuses to construct rather than
   * defaulting to a lambda nobody chose.
   */
  constructor({ presence, profiles, lifecycle }) {
    if (presence == null || typeof presence.moveTo !== 'function') {
      fail('ALLOCATOR_SEAM', 'the presence registry is required; it is the home of the assignment');
    }
    if (profiles == null || typeof profiles.get !== 'function') {
      fail('ALLOCATOR_SEAM', 'the profile registry is required; it holds playernum/hostflag');
    }
    if (lifecycle == null || typeof lifecycle.statusOf !== 'function') {
      fail('ALLOCATOR_SEAM', 'the lifecycle registry is required; it authors the room status');
    }
    this.#presence = presence;
    this.#profiles = profiles;
    this.#lifecycle = lifecycle;
  }

  /**
   * The host's assignment at create: playernum 1, hostflag 1
   * (sendCreateSlot lines 1194-1195). The presence move (slot 0) is already
   * done by `rooms.openFor` on the rig-confirmed create path, so this only
   * writes the attributes - and verifies the precondition instead of assuming.
   */
  assignHost({ room, hostPresence }) {
    const profile = this.#profileOf(hostPresence);
    if (hostPresence.roomHandle !== room.handle) {
      fail('ALLOCATOR_ORDER', 'assignHost runs after openFor moved the host into the room');
    }
    profile.setPlayerNum(1);
    profile.setHostFlag(1);
    return profile;
  }

  /**
   * JOINGAME. Guards in the reference order, then first-free-of-2..4, then the
   * presence move, then full -> BUSY (sendJoinGame lines 1650-1686).
   *
   * Returns `{ok: true, playernum}` or `{ok: false, reason}` - refusals are
   * results, not exceptions, because a peer choosing a full room is protocol,
   * not a server bug.
   */
  join({ room, presence, password = EMPTY_PASSWORD }) {
    if (presence == null || typeof presence.accountSessionId !== 'string') {
      // Still a programmer error: no handler can produce a join without a live
      // presence record, so a missing one is a defect, not peer input.
      fail('ALLOCATOR_PRESENCE', 'a live Presence is required');
    }
    /*
     * Guard 0 (PAL-side, no reference row): a profile-less session REFUSES the
     * join rather than throwing. The profile open at bind is "logged and
     * tolerated" (`snap-lobby-sessions.js open()`), so a session without one
     * is reachable by a peer whose profile was refused - and the old
     * `#profileOf` throw surfaced in the journal as a misleading generic
     * "snap-lobby handler-threw" instead of a join refusal (nora pre-deploy
     * fix 3). `assignHost`/`leave` keep the throw: their callers run inside
     * transitions the server itself initiated, where a missing profile IS a
     * defect.
     */
    const profile = this.#profiles.get(presence.accountSessionId);
    if (profile == null) {
      return { ok: false, reason: JOIN_REFUSAL.NO_PROFILE };
    }
    if (!Buffer.isBuffer(password)) {
      fail('ALLOCATOR_PASSWORD', 'a candidate password is passed as a Buffer');
    }

    // Guard 1: BUSY -> "game is full" (lines 1651-1657).
    const status = this.#lifecycle.statusOf(room.handle);
    if (status === ROOM_STATUS.BUSY) {
      return { ok: false, reason: JOIN_REFUSAL.FULL };
    }
    // Guard 2: anything but GAMESET -> "not possible" (lines 1660-1666).
    if (status !== ROOM_STATUS.GAMESET) {
      return { ok: false, reason: JOIN_REFUSAL.NOT_POSSIBLE };
    }
    // Guard 3: password (line 1670: match OR protection off).
    if (!this.#lifecycle.passwordAccepts(room.handle, password)) {
      return { ok: false, reason: JOIN_REFUSAL.WRONG_PASSWORD };
    }

    const playernum = this.#freePlayerNum(room.handle);
    if (playernum === 0) {
      // getFreePlayerNum returns 0 when 2..4 are all held (lines 106-107). The
      // reference would assign playernum 0 and corrupt its roster; unreachable
      // there because full rooms are BUSY. Fail closed as 'full' instead of
      // reproducing the corruption - deviation documented, guarded by tests.
      return { ok: false, reason: JOIN_REFUSAL.FULL };
    }

    // Assignment: attributes to the profile, the location to presence
    // (playernum - 1: the host precedent is playernum 1 at presence slot 0).
    profile.setPlayerNum(playernum);
    this.#presence.moveTo(presence, { roomHandle: room.handle, slot: playernum - 1 });

    // Full -> BUSY, counted AFTER the move (lines 1683-1686; rule L1 makes the
    // post-mutation count the correct operand).
    if (room.current >= room.max) {
      this.#lifecycle.markBusy(room.handle);
    }
    return { ok: true, playernum };
  }

  /**
   * Leave (CANCELSLOT, sendCancelSlot lines 1356-1396): capture hostflag,
   * clear the leaver's attributes, ascend the presence out of the room, then
   * recompute the room status from the POST-move count. The playernum is freed
   * simply by the leaver no longer being a member - the free-num scan reads
   * the live roster, so reuse is automatic.
   */
  leave({ room, presence }) {
    const profile = this.#profileOf(presence);
    if (presence.roomHandle !== room.handle) {
      fail('ALLOCATOR_ORDER', 'leave requires the presence to be in the room it is leaving');
    }
    const hostLeft = profile.hostflag === 1;
    if (hostLeft) profile.setHostFlag(0);    // line 1366
    profile.setPlayerNum(0);                 // line 1376

    // One level up: out of the room (the PAL op-0x07 semantics; clears the
    // presence slot with it by prefix-closure). If this was the LAST member,
    // presence fires `onRoomEmptied` synchronously INSIDE this call, and the
    // composed close path (room registry close + lifecycle release) has
    // already run by the time it returns.
    this.#presence.moveTo(presence, { roomHandle: null });

    // Post-move count (rule L1), then the reference recompute - unless the
    // emptied-room hook already released the record, which IS the reference's
    // 0-players -> FREE outcome expressed as PAL room closure.
    if (this.#lifecycle.get(room.handle) == null) return null;
    const memberCount = this.#presence.countInRoom(room.handle);
    return this.#lifecycle.recomputeOnLeave(room.handle, {
      memberCount,
      maxPlayers: room.max,
      hostLeft
    });
  }

  /**
   * ClientList.getFreePlayerNum (lines 98-108): mark the playernums held by
   * the room's members, return the first free of 2, 3, 4, else 0.
   */
  #freePlayerNum(roomHandle) {
    const held = [false, false, false, false, false];
    for (const member of this.#presence.rosterOf(roomHandle)) {
      const profile = this.#profiles.get(member.accountSessionId);
      const num = profile?.playernum ?? 0;
      if (num >= 1 && num <= 4) held[num] = true;
    }
    for (let candidate = 2; candidate <= 4; candidate += 1) {
      if (!held[candidate]) return candidate;
    }
    return 0;
  }

  #profileOf(presence) {
    if (presence == null || typeof presence.accountSessionId !== 'string') {
      fail('ALLOCATOR_PRESENCE', 'a live Presence is required');
    }
    const profile = this.#profiles.get(presence.accountSessionId);
    if (profile == null) {
      fail(
        'ALLOCATOR_PROFILE',
        `account session ${presence.accountSessionId} has no player profile`
      );
    }
    return profile;
  }
}

export function createSlotAllocator(options) {
  return new SlotAllocator(options);
}
