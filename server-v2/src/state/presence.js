/**
 * PRESENCE: the one authoritative record of where every live player is.
 *
 * Implements `analysis/PRESENCE-AND-COUNTS-DESIGN.md` sections 2.1-2.4 and 3.3,
 * MINUS its C6b claim. That claim - "the op-0x49 current sum participates in
 * unlocking the cursor" - was struck by the review in
 * `analysis/CREATE-ROOM-GATES-REVIEW-CORRECTIONS.md` section 4: the summing at
 * `FUN_005c13e0` is real, but `0x6CF286` has two writers and no absolute-addressed
 * reader, so nothing here may be justified by it. The room counts below are
 * derived because derivation is cheaper and cannot desync, not because a cursor
 * depends on them.
 *
 * ## The defect this exists to remove
 *
 * `SnapLobbySession.#enteredBoxId` recorded location at the DEEPEST level a
 * player reaches and only once an op-0x06 ENTER resolved. Four of the six places
 * the protocol asks for a count ask BEFORE that - the TCP-10127 `0x6212` and
 * `0x6510` replies, and the first op-0x48 of a session - so every count above the
 * area level was structurally zero and looked like a data bug when it was an
 * ordering bug. A presence therefore exists from the moment the 566-byte bind is
 * accepted, at depth `server`, and deepens as the player descends.
 *
 * ## Location is a path with a depth
 *
 *   depth 0  detached   no record at all
 *   depth 1  server     serverEntryId
 *   depth 2  area       + boxId
 *   depth 3  room       + roomHandle
 *   depth 4  slot       + slot        (positional within a room, not a container)
 *
 * INVARIANT P1 (prefix-closure): a non-null level implies every shallower level
 * is non-null. It is what makes "count at-or-below" well defined, and it is
 * enforced by throwing rather than tolerated - `{boxId: 3, serverEntryId: null}`
 * is a bug in this server, never something a peer can provoke.
 *
 * INVARIANT P2 (single home): nothing else stores a player's location. Not the
 * session, not the room. A field is derived if and only if deleting a session
 * must change it.
 *
 * ## Sets, not counters
 *
 * The obvious O(1) count is `count[area] += 1` / `-= 1`. That is an independent
 * source of truth which can be decremented twice or missed once, and nothing in
 * the data can tell you afterwards. `Set.add` and `Set.delete` are both
 * idempotent and membership is a fact about the presence object, so the failure
 * mode "someone forgot to decrement" does not exist here. `assertConsistent()`
 * makes that checkable by rebuilding the indices and comparing.
 *
 * ## No await, ever, on any path through this module
 *
 * Node runs handlers to completion, so a count read and the payload it is written
 * into are atomic with respect to every other player's transition - PROVIDED no
 * `await` appears between them. That is the entire concurrency design; it costs
 * nothing and it makes locks unnecessary. Treat any `await` appearing in a
 * transition or a count path as a design change, not a refactor.
 *
 * ## Keyed on the account session, never the source address
 *
 * `accountSessionId` is the key. The UDP routing key is transport addressing: a
 * NAT rebind changes it while the player has not moved, and BioServer's one
 * genuinely good identity decision was recording the source address and never
 * reading it.
 */

export class PresenceError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'PresenceError';
    this.code = code;
  }
}

function fail(code, message) {
  throw new PresenceError(code, message);
}

/** The depth names, in order. Exported so a log can say where a player is. */
export const PRESENCE_DEPTH = Object.freeze({
  DETACHED: 0,
  SERVER: 1,
  AREA: 2,
  ROOM: 3,
  SLOT: 4
});

/** Bounded like every other table here: a full one refuses, it never evicts. */
const DEFAULT_MAXIMUM_PRESENCES = 4096;

/**
 * One live player. Constructed only by `PresenceRegistry`; `location` is
 * deliberately readable and NOT writable from outside, because the only function
 * allowed to change it is the same one that fixes the indices.
 */
class Presence {
  #presenceId;
  #accountSessionId;
  #userid;
  #displayName;
  #attachedAtMs;
  #serverEntryId = null;
  #boxId = null;
  #roomHandle = null;
  #slot = null;

  constructor({ presenceId, accountSessionId, userid, displayName, serverEntryId, attachedAtMs }) {
    this.#presenceId = presenceId;
    this.#accountSessionId = accountSessionId;
    this.#userid = userid;
    this.#displayName = displayName;
    this.#serverEntryId = serverEntryId;
    this.#attachedAtMs = attachedAtMs;
  }

  get presenceId() {
    return this.#presenceId;
  }

  get accountSessionId() {
    return this.#accountSessionId;
  }

  get userid() {
    return this.#userid;
  }

  /** The 16 bytes the roster renders. Held here because the roster is a query. */
  get displayName() {
    return this.#displayName;
  }

  get attachedAtMs() {
    return this.#attachedAtMs;
  }

  get serverEntryId() {
    return this.#serverEntryId;
  }

  get boxId() {
    return this.#boxId;
  }

  get roomHandle() {
    return this.#roomHandle;
  }

  get slot() {
    return this.#slot;
  }

  get depth() {
    if (this.#serverEntryId == null) return PRESENCE_DEPTH.DETACHED;
    if (this.#boxId == null) return PRESENCE_DEPTH.SERVER;
    if (this.#roomHandle == null) return PRESENCE_DEPTH.AREA;
    return this.#slot == null ? PRESENCE_DEPTH.ROOM : PRESENCE_DEPTH.SLOT;
  }

  /** A snapshot for logs and tests. Never a handle onto the mutable state. */
  location() {
    return {
      serverEntryId: this.#serverEntryId,
      boxId: this.#boxId,
      roomHandle: this.#roomHandle,
      slot: this.#slot,
      depth: this.depth
    };
  }

  /**
   * PACKAGE-PRIVATE in spirit: called only by `PresenceRegistry.#write`, which is
   * also the function that repairs the indices. There is no public setter, which
   * is the structural half of invariant I1 - the other two halves are the
   * property test and `assertConsistent()`.
   */
  _write({ serverEntryId, boxId, roomHandle, slot }) {
    this.#serverEntryId = serverEntryId;
    this.#boxId = boxId;
    this.#roomHandle = roomHandle;
    this.#slot = slot;
  }
}

export class PresenceRegistry {
  #maximum;
  #nextPresenceId = 1;
  #areaPopulationVersion = 0;
  #logger;

  // accountSessionId -> Presence. THE table; everything else is an index over it.
  #presences = new Map();
  // key -> Set<Presence>, membership at-or-below that container.
  #byServer = new Map();
  #byArea = new Map();
  #byRoom = new Map();

  #onRoomEmptied;

  constructor({
    maximumPresences = DEFAULT_MAXIMUM_PRESENCES,
    /**
     * Called synchronously when the last presence leaves a room, so a room's
     * EXISTENCE can be derived rather than swept. See `state/lobby-rooms.js`:
     * this is what removes BioServer's `cleanGhostRooms` from the design instead
     * of reimplementing it.
     */
    onRoomEmptied = null,
    logger = null
  } = {}) {
    if (!Number.isSafeInteger(maximumPresences) || maximumPresences < 1) {
      fail('MAXIMUM_PRESENCES', 'maximumPresences must be a positive whole number');
    }
    if (onRoomEmptied !== null && typeof onRoomEmptied !== 'function') {
      fail('ROOM_EMPTIED_HANDLER', 'onRoomEmptied must be a function when supplied');
    }
    this.#maximum = maximumPresences;
    this.#onRoomEmptied = onRoomEmptied;
    this.#logger = logger;
  }

  get size() {
    return this.#presences.size;
  }

  get maximumPresences() {
    return this.#maximum;
  }

  /**
   * Bumped by every mutation that changes an area bucket.
   *
   * The memo key for the op-0x48 payload: that reply is polled at about 25 Hz per
   * player and changes only when someone enters or leaves an area, a read:write
   * ratio around 50 000:1. A version counter makes staleness a checkable equality
   * rather than a hope.
   */
  get areaPopulationVersion() {
    return this.#areaPopulationVersion;
  }

  /* ---- reads. All O(1), all synchronous, no logging ---------------------- */

  /** C4, the `0x6510` record `+0x12c` "current players" for one directory entry. */
  countInServer(serverEntryId) {
    return this.#byServer.get(serverEntryId)?.size ?? 0;
  }

  /** C5, the op-0x48 record `+0x10` per-area population. */
  countInArea(boxId) {
    if (boxId == null) return 0;
    return this.#byArea.get(boxId)?.size ?? 0;
  }

  /** C7/C8/C9, the members of one room. */
  countInRoom(roomHandle) {
    if (roomHandle == null) return 0;
    return this.#byRoom.get(roomHandle)?.size ?? 0;
  }

  /**
   * C10, the complete member list of a room in JOIN ORDER.
   *
   * A JS `Set` preserves insertion order, so join order is free - which is what
   * the client's four-slot table wants, and the op-0x28 selector-0x0a reply must
   * carry the WHOLE roster every time because the client `memset`s its copy
   * before refilling it.
   */
  rosterOf(roomHandle) {
    if (roomHandle == null) return [];
    return [...(this.#byRoom.get(roomHandle) ?? [])];
  }

  /** Everyone attached to this process. Operations, metrics, and the C6 check. */
  totalAttached() {
    return this.#presences.size;
  }

  /** The presence for one account session, or null. */
  get(accountSessionId) {
    return this.#presences.get(accountSessionId) ?? null;
  }

  /* ---- the only three mutations ----------------------------------------- */

  /**
   * S5: the 566-byte bind was accepted and a lobby session opened.
   *
   * Depth 1, `server`. Not S9, not the ENTER - THAT is the whole ordering fix.
   * Nothing on the wire advertises a server-level arrival, so this emits nothing.
   *
   * Displacement is the caller's ordering obligation and is enforced here: an
   * account that attaches twice must have been detached first, because
   * attach-then-detach momentarily double-counts and an attach-first path that
   * then removes "the presence for this account" can remove the NEW one.
   */
  attach({ accountSessionId, userid = null, displayName = '', serverEntryId, nowMs = 0 }) {
    if (typeof accountSessionId !== 'string' || accountSessionId.length === 0) {
      fail('PRESENCE_KEY', 'a presence is keyed on a non-empty account session id');
    }
    if (serverEntryId == null) {
      fail('PRESENCE_DEPTH', 'a presence attaches at depth server, so serverEntryId is required');
    }
    if (this.#presences.has(accountSessionId)) {
      fail(
        'PRESENCE_DUPLICATE',
        `account session ${accountSessionId} is already present; displacement must detach the ` +
        'old presence BEFORE attaching the new one, or a count between the two is wrong'
      );
    }
    if (this.#presences.size >= this.#maximum) {
      // Fail closed. Refusing a NEW presence is a bounded loss; evicting a live
      // one hands an attacker a way to drop a player who is already in.
      fail(
        'PRESENCE_CAPACITY',
        `${this.#presences.size} presences are live and the cap is ${this.#maximum}`
      );
    }
    const presence = new Presence({
      presenceId: this.#nextPresenceId,
      accountSessionId,
      userid,
      displayName,
      serverEntryId,
      attachedAtMs: nowMs
    });
    this.#nextPresenceId += 1;
    this.#presences.set(accountSessionId, presence);
    this.#bucket(this.#byServer, serverEntryId).add(presence);
    return presence;
  }

  /**
   * Move a presence to a new location. ONE synchronous function.
   *
   * `moveTo(p, { boxId: null })` clears everything BELOW it as well: leaving an
   * area and leaving the room inside it are one operation that cannot half-apply.
   * Levels not named are left where they are, so `moveTo(p, { roomHandle: h,
   * slot: 0 })` deepens without restating the area.
   */
  moveTo(presence, { boxId, roomHandle, slot } = {}) {
    this.#requireLive(presence);
    const from = presence.location();

    const nextBox = boxId === undefined ? from.boxId : boxId;
    // Prefix-closure, applied as a CONSEQUENCE rather than checked and refused:
    // clearing a level clears everything below it, so the caller cannot express
    // an impossible location by omission.
    const nextRoom = nextBox == null
      ? null
      : (roomHandle === undefined ? from.roomHandle : roomHandle);
    const nextSlot = nextRoom == null ? null : (slot === undefined ? from.slot : slot);

    if (nextBox == null && (boxId === undefined ? false : roomHandle != null)) {
      fail('PRESENCE_PREFIX', 'a room without an area violates prefix-closure (P1)');
    }
    if (nextRoom == null && slot != null) {
      fail('PRESENCE_PREFIX', 'a slot without a room violates prefix-closure (P1)');
    }
    if (nextSlot != null && (!Number.isSafeInteger(nextSlot) || nextSlot < 0)) {
      fail('PRESENCE_SLOT', `a slot must be a non-negative whole number, not ${nextSlot}`);
    }

    this.#write(presence, {
      serverEntryId: from.serverEntryId,
      boxId: nextBox,
      roomHandle: nextRoom,
      slot: nextSlot
    }, from);
    return presence;
  }

  /**
   * Move a presence one level SHALLOWER.
   *
   * The op-0x07 LEAVE is one message and the client uses it for both "back out of
   * this room" and "back out of this area" - `FUN_005c1c80` step 2 sends it after
   * probing which channels are occupied. Expressing that as "up one level" keeps
   * the server's model matching the client's single message instead of guessing
   * which of the two it meant. Returns the depth it ended at.
   */
  ascend(presence) {
    this.#requireLive(presence);
    const at = presence.location();
    if (at.roomHandle != null) {
      this.moveTo(presence, { roomHandle: null });
    } else if (at.boxId != null) {
      this.moveTo(presence, { boxId: null });
    }
    return presence.depth;
  }

  /** Remove a presence entirely. Idempotent for an already-detached presence. */
  detach(presence, reason = 'detached') {
    if (presence == null) return false;
    if (this.#presences.get(presence.accountSessionId) !== presence) return false;
    const from = presence.location();
    this.#presences.delete(presence.accountSessionId);
    this.#write(presence, {
      serverEntryId: null, boxId: null, roomHandle: null, slot: null
    }, from);
    this.#logger?.debug?.('presence-detached', {
      presenceId: presence.presenceId,
      accountSessionId: presence.accountSessionId,
      reason,
      from
    });
    return true;
  }

  /**
   * Rebuild the indices from the presence set and compare. O(n).
   *
   * INVARIANT I1: rebuilding from scratch yields exactly the current indices.
   * Tests and a debug flag only - running an O(n) integrity check per datagram
   * would be `RegisterSessionTable.sweep()` in a new costume.
   */
  assertConsistent() {
    const server = new Map();
    const area = new Map();
    const room = new Map();
    for (const presence of this.#presences.values()) {
      const at = presence.location();
      if (at.serverEntryId == null) {
        fail('PRESENCE_INCONSISTENT', `presence ${presence.presenceId} is held but detached`);
      }
      if (at.boxId == null && at.roomHandle != null) {
        fail('PRESENCE_INCONSISTENT', `presence ${presence.presenceId} holds a room with no area`);
      }
      if (at.roomHandle == null && at.slot != null) {
        fail('PRESENCE_INCONSISTENT', `presence ${presence.presenceId} holds a slot with no room`);
      }
      bucketOf(server, at.serverEntryId).add(presence);
      if (at.boxId != null) bucketOf(area, at.boxId).add(presence);
      if (at.roomHandle != null) bucketOf(room, at.roomHandle).add(presence);
    }
    compareIndex('byServer', server, this.#byServer);
    compareIndex('byArea', area, this.#byArea);
    compareIndex('byRoom', room, this.#byRoom);
    return true;
  }

  /* ---- internals -------------------------------------------------------- */

  #requireLive(presence) {
    if (presence == null || typeof presence.location !== 'function') {
      fail('PRESENCE_REQUIRED', 'a Presence is required');
    }
    if (this.#presences.get(presence.accountSessionId) !== presence) {
      fail('PRESENCE_DETACHED', 'that presence is not held by this registry');
    }
  }

  /**
   * The ONE place location and the indices change together.
   *
   * Mutate the set FIRST, then let the caller emit (rule L1): every view is
   * derived, so every message built after this returns is automatically correct.
   */
  #write(presence, to, from) {
    if (from.serverEntryId !== to.serverEntryId) {
      this.#unbucket(this.#byServer, from.serverEntryId, presence);
      if (to.serverEntryId != null) this.#bucket(this.#byServer, to.serverEntryId).add(presence);
    }
    if (from.boxId !== to.boxId) {
      this.#unbucket(this.#byArea, from.boxId, presence);
      if (to.boxId != null) this.#bucket(this.#byArea, to.boxId).add(presence);
      this.#areaPopulationVersion += 1;
    }
    if (from.roomHandle !== to.roomHandle) {
      const emptied = this.#unbucket(this.#byRoom, from.roomHandle, presence);
      if (to.roomHandle != null) this.#bucket(this.#byRoom, to.roomHandle).add(presence);
      presence._write(to);
      // AFTER the write, so a handler that reads counts sees the post-state.
      if (emptied) this.#onRoomEmptied?.(from.roomHandle);
      return;
    }
    presence._write(to);
  }

  #bucket(index, key) {
    let bucket = index.get(key);
    if (bucket == null) {
      bucket = new Set();
      index.set(key, bucket);
    }
    return bucket;
  }

  /** Returns whether the bucket became empty and was dropped. */
  #unbucket(index, key, presence) {
    if (key == null) return false;
    const bucket = index.get(key);
    if (bucket == null) return false;
    bucket.delete(presence);
    if (bucket.size > 0) return false;
    // Dropped rather than left empty, so `size` never has to distinguish "no
    // bucket" from "an empty one" and a stale key cannot accumulate per room.
    index.delete(key);
    return true;
  }
}

function bucketOf(index, key) {
  let bucket = index.get(key);
  if (bucket == null) {
    bucket = new Set();
    index.set(key, bucket);
  }
  return bucket;
}

function compareIndex(name, rebuilt, live) {
  if (rebuilt.size !== live.size) {
    fail(
      'PRESENCE_INCONSISTENT',
      `${name} holds ${live.size} keys; rebuilding from the presence set gives ${rebuilt.size}`
    );
  }
  for (const [key, expected] of rebuilt) {
    const actual = live.get(key);
    if (actual == null || actual.size !== expected.size) {
      fail(
        'PRESENCE_INCONSISTENT',
        `${name}[${key}] holds ${actual?.size ?? 'nothing'}; rebuilding gives ${expected.size}`
      );
    }
    for (const presence of expected) {
      if (!actual.has(presence)) {
        fail('PRESENCE_INCONSISTENT', `${name}[${key}] is missing presence ${presence.presenceId}`);
      }
    }
  }
}

export function createPresenceRegistry(options) {
  return new PresenceRegistry(options);
}
