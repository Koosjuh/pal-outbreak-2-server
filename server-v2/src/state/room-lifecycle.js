/**
 * ROOM LIFECYCLE: the bioserver `Slot` status machine, kept BESIDE `LobbyRoom`
 * rather than inside it. PORT-PLAN §A.0/§A.1: the PAL room the client creates
 * and joins maps to the bioserver SLOT (the game unit), so the slot's status
 * lifecycle attaches to the room HANDLE. `lobby-rooms.js` stays untouched -
 * identity/capacity live there, population stays DERIVED from presence, and
 * this registry is the single home of the AUTHORED status plus the slot-only
 * fields the room record does not carry (password/protection, scenario/slot
 * type, wait timer, rules).
 *
 * Reference oracle (Observation, code-read):
 * `references/bioserver/.../bioserv2/bioserver/Slot.java` +
 * `PacketHandler.java`.
 *
 * Status values (Slot.java lines 30-34): 0 DISABLED, 1 FREE, 2 INCREATE,
 * 3 GAMESET (joinable), 4 BUSY (full / in game).
 *
 * Explicit transitions, each tied to its reference line:
 * - create            -> INCREATE  (sendCreateSlot line 1196)
 * - create-complete   -> GAMESET   (send6504 lines 1330-1333, host only;
 *                                   "last packet from slot creator" - the room
 *                                   becomes joinable ONLY here, which is the
 *                                   create-dialogue's final step)
 * - start OR full     -> BUSY      (broadcastGetReady line 392; sendJoinGame
 *                                   lines 1683-1686 when count reaches max)
 * - recompute on leave            (sendCancelSlot lines 1383-1389: 0 players
 *                                   -> FREE reset; host remains + non-full ->
 *                                   GAMESET. Host leaving resets the slot
 *                                   outright, lines 1365-1372)
 *
 * Every other edge throws: an unexpected transition is a server bug or a
 * guessed message, never something to paper over.
 *
 * Timing is injectable and explicit: no `Date.now` in this module. Callers
 * pass `nowMs`; `WAITTIME` semantics follow Slot.setLivetime/getLivetime
 * (lines 187-197: livetime = now + waitMinutes*60s; remaining clamps at 0, and
 * 0 is the auto-start signal the reference fires from a SLOTTIMER read).
 */

import { createRuleSet } from './rule-set.js';

export class RoomLifecycleError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'RoomLifecycleError';
    this.code = code;
  }
}

function fail(code, message) {
  throw new RoomLifecycleError(code, message);
}

/** Slot.java lines 30-34. */
export const ROOM_STATUS = Object.freeze({
  DISABLED: 0,
  FREE: 1,
  INCREATE: 2,
  GAMESET: 3,
  BUSY: 4
});

/** Slot.java lines 52-53. */
export const PROTECTION = Object.freeze({ OFF: 0, ON: 1 });

/** Bounded like every other table: refuse new, never evict live. */
const DEFAULT_MAXIMUM_ROOMS = 4096;

/**
 * The lifecycle record of one room. Constructed only by the registry; status
 * writes go through the registry's named transitions.
 */
class RoomLifecycleRecord {
  #handle;
  #status = ROOM_STATUS.INCREATE;
  #password = Buffer.alloc(0);
  #protection = PROTECTION.OFF;
  #scenario = 0;    // Slot.java SCENARIO_TRAINING
  #slotType = 0;    // Slot.java LOAD_NOTSET (stored raw; 0x11/0x12 observed)
  #livetimeMs = -1; // -1 = never armed (Slot.java line 95)
  #rules;

  constructor({ handle, rules }) {
    this.#handle = handle;
    this.#rules = rules;
  }

  get handle() {
    return this.#handle;
  }

  get status() {
    return this.#status;
  }

  get protection() {
    return this.#protection;
  }

  get scenario() {
    return this.#scenario;
  }

  get slotType() {
    return this.#slotType;
  }

  get rules() {
    return this.#rules;
  }

  /** Package-private in spirit: only the registry's transitions call these. */
  _setStatus(status) {
    this.#status = status;
  }

  _setPassword(password) {
    this.#password = Buffer.from(password);
    // Slot.setPassword (lines 122-125): a non-empty password flips protection
    // ON. Note the reference never flips it back OFF except through reset().
    if (password.length > 0) this.#protection = PROTECTION.ON;
  }

  _passwordMatches(candidate) {
    return this.#password.equals(candidate);
  }

  _setScene({ slotType, scenario }) {
    this.#slotType = slotType;
    this.#scenario = scenario;
  }

  _armWaitTimer(nowMs, waitMinutes) {
    this.#livetimeMs = nowMs + waitMinutes * 60 * 1000;
  }

  _remainingSeconds(nowMs) {
    if (this.#livetimeMs < 0) return null;
    const remaining = Math.floor((this.#livetimeMs - nowMs) / 1000);
    return remaining < 0 ? 0 : remaining;
  }

  /** Slot.reset() (lines 98-108) minus the fields LobbyRoom owns. */
  _reset() {
    this.#status = ROOM_STATUS.FREE;
    this.#password = Buffer.alloc(0);
    this.#protection = PROTECTION.OFF;
    this.#scenario = 0;
    this.#slotType = 0;
    this.#livetimeMs = -1;
    this.#rules.reset();
  }
}

export class RoomLifecycleRegistry {
  #maximum;
  #createRules;
  // room handle -> RoomLifecycleRecord. A handle with no record is a room this
  // registry was never told about; statusOf answers FREE for it, matching the
  // reference's default slot state.
  #records = new Map();

  constructor({
    maximumRooms = DEFAULT_MAXIMUM_ROOMS,
    /**
     * How a room's rule set is built from its area number. Injectable so tests
     * can pin a flavour; defaults to the reference tables.
     */
    createRules = createRuleSet
  } = {}) {
    if (!Number.isSafeInteger(maximumRooms) || maximumRooms < 1) {
      fail('MAXIMUM_ROOMS', 'maximumRooms must be a positive whole number');
    }
    if (typeof createRules !== 'function') {
      fail('RULES_SEAM', 'createRules must be a function');
    }
    this.#maximum = maximumRooms;
    this.#createRules = createRules;
  }

  get size() {
    return this.#records.size;
  }

  /** The status a browser sees. No record = FREE (the reference's empty slot). */
  statusOf(handle) {
    return this.#records.get(handle)?.status ?? ROOM_STATUS.FREE;
  }

  /** The record, or null. Reads only; writes go through the transitions. */
  get(handle) {
    return this.#records.get(handle) ?? null;
  }

  /* ---- the explicit transitions ------------------------------------------ */

  /**
   * create -> INCREATE. Called when the PAL create-room is accepted (the
   * CREATESLOT analogue, sendCreateSlot line 1196). The room is NOT joinable
   * yet: the create dialogue is still running.
   */
  beginCreate(handle, { areaNumber = 0 } = {}) {
    this.#requireHandle(handle);
    if (this.#records.has(handle)) {
      fail('LIFECYCLE_DUPLICATE', `room 0x${handle.toString(16)} already has a lifecycle record`);
    }
    if (this.#records.size >= this.#maximum) {
      fail('LIFECYCLE_CAPACITY', `${this.#records.size} lifecycle records are live; cap ${this.#maximum}`);
    }
    const record = new RoomLifecycleRecord({ handle, rules: this.#createRules(areaNumber) });
    this.#records.set(handle, record);
    return record;
  }

  /**
   * create-complete -> GAMESET, the create dialogue's FINAL step (send6504,
   * host path, lines 1330-1333) - the ONLY transition that makes the room
   * joinable, and it also arms the wait timer (setLivetime, line 1332).
   * Refused from any state but INCREATE: a completion for a room that was
   * never in-create is a protocol violation, not a state to absorb.
   */
  completeCreate(handle, { nowMs = 0 } = {}) {
    const record = this.#require(handle);
    if (record.status !== ROOM_STATUS.INCREATE) {
      fail(
        'LIFECYCLE_TRANSITION',
        `create-complete requires INCREATE; room 0x${handle.toString(16)} is ${record.status}`
      );
    }
    record._setStatus(ROOM_STATUS.GAMESET);
    record._armWaitTimer(nowMs, record.rules.waitTimeMinutes());
    return record;
  }

  /**
   * start/full -> BUSY. Two reference triggers, one edge: broadcastGetReady
   * (line 392) and join-made-it-full (sendJoinGame lines 1683-1686). BUSY ->
   * BUSY is idempotent because broadcastGetReady is re-entrant through
   * SLOTTIMER reads (sendSlotTimer lines 1291-1294 fire it on every 0 read).
   */
  markBusy(handle) {
    const record = this.#require(handle);
    if (record.status !== ROOM_STATUS.GAMESET && record.status !== ROOM_STATUS.BUSY) {
      fail(
        'LIFECYCLE_TRANSITION',
        `BUSY requires GAMESET (or is idempotent from BUSY); room 0x${handle.toString(16)} ` +
        `is ${record.status}`
      );
    }
    record._setStatus(ROOM_STATUS.BUSY);
    return record;
  }

  /**
   * The leave recompute, sendCancelSlot lines 1365-1392 in reference order:
   * 1. host leaving resets the slot outright (lines 1365-1372);
   * 2. zero members -> FREE (lines 1383-1386) - here the record is RELEASED,
   *    because in PAL a room with zero members no longer exists at all
   *    (`onRoomEmptied` closes it in the room registry);
   * 3. members remain, room non-full and the leaver was NOT the host ->
   *    GAMESET (lines 1387-1389) - a full-then-BUSY room reopens.
   *
   * `memberCount` is passed in, not counted here: population is presence's
   * (P2), and the caller reads it AFTER the presence move (rule L1).
   */
  recomputeOnLeave(handle, { memberCount, maxPlayers, hostLeft }) {
    const record = this.#require(handle);
    if (!Number.isSafeInteger(memberCount) || memberCount < 0) {
      fail('LIFECYCLE_COUNT', `memberCount must be a non-negative integer, not ${memberCount}`);
    }
    if (!Number.isSafeInteger(maxPlayers) || maxPlayers < 1) {
      fail('LIFECYCLE_COUNT', `maxPlayers must be a positive integer, not ${maxPlayers}`);
    }
    if (hostLeft !== true && hostLeft !== false) {
      fail('LIFECYCLE_COUNT', 'hostLeft must be a boolean');
    }
    if (hostLeft) record._reset();
    if (memberCount === 0) {
      this.#records.delete(handle);
      return null;
    }
    if (memberCount < maxPlayers && !hostLeft) {
      record._setStatus(ROOM_STATUS.GAMESET);
    }
    return record;
  }

  /** Forget a record (room closed by other means). Idempotent. */
  release(handle) {
    return this.#records.delete(handle);
  }

  /* ---- the slot-only fields ---------------------------------------------- */

  /** SLOTPASSWD: non-empty flips protection ON (Slot.setPassword). */
  setPassword(handle, password) {
    if (!Buffer.isBuffer(password)) {
      fail('LIFECYCLE_PASSWORD', 'a password is the client\'s bytes, passed as a Buffer');
    }
    this.#require(handle)._setPassword(password);
  }

  /**
   * The JOINGAME password check, exactly the reference's acceptance
   * (sendJoinGame line 1670): pass when the bytes match OR protection is off.
   */
  passwordAccepts(handle, candidate) {
    if (!Buffer.isBuffer(candidate)) {
      fail('LIFECYCLE_PASSWORD', 'a candidate password is passed as a Buffer');
    }
    const record = this.#require(handle);
    return record.protection === PROTECTION.OFF || record._passwordMatches(candidate);
  }

  /** SCENESELECT: stores slotType + scenario raw (sendSceneSelect 1223-1224). */
  setScene(handle, { slotType, scenario }) {
    if (!Number.isSafeInteger(slotType) || slotType < 0 || slotType > 0xff) {
      fail('LIFECYCLE_SCENE', `slotType must be a byte, not ${slotType}`);
    }
    if (!Number.isSafeInteger(scenario) || scenario < 0 || scenario > 0xff) {
      fail('LIFECYCLE_SCENE', `scenario must be a byte, not ${scenario}`);
    }
    this.#require(handle)._setScene({ slotType, scenario });
  }

  /* ---- the wait timer ---------------------------------------------------- */

  /** Re-arm (SCENESELECT also arms it, sendSceneSelect line 1225). */
  armWaitTimer(handle, { nowMs }) {
    this.#requireNow(nowMs);
    const record = this.#require(handle);
    record._armWaitTimer(nowMs, record.rules.waitTimeMinutes());
  }

  /**
   * SLOTTIMER's read: remaining seconds clamped at 0, and `expired` is the
   * reference's auto-start signal (a 0 read fires broadcastGetReady). Pure -
   * the caller decides whether to start; a read must not mutate.
   * `remainingSeconds` is null when the timer was never armed.
   */
  checkWaitTimer(handle, { nowMs }) {
    this.#requireNow(nowMs);
    const record = this.#require(handle);
    const remainingSeconds = record._remainingSeconds(nowMs);
    return {
      remainingSeconds,
      expired: remainingSeconds === 0 && record.status === ROOM_STATUS.GAMESET
    };
  }

  /* ---- internals --------------------------------------------------------- */

  #requireHandle(handle) {
    if (!Number.isSafeInteger(handle) || handle < 1 || handle > 0xffffffff) {
      fail('LIFECYCLE_HANDLE', `a room handle is a non-zero uint32, not ${handle}`);
    }
  }

  #require(handle) {
    this.#requireHandle(handle);
    const record = this.#records.get(handle);
    if (record == null) {
      fail('LIFECYCLE_UNKNOWN', `room 0x${handle.toString(16)} has no lifecycle record`);
    }
    return record;
  }

  #requireNow(nowMs) {
    if (!Number.isSafeInteger(nowMs) || nowMs < 0) {
      fail('LIFECYCLE_CLOCK', `nowMs must be a non-negative integer, not ${nowMs}`);
    }
  }
}

export function createRoomLifecycleRegistry(options) {
  return new RoomLifecycleRegistry(options);
}
