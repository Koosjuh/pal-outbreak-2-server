import { MAXIMUM_ROOM_LIST_RECORDS } from '../udp/snap-lobby-codec.js';

/**
 * THE ROOM MODEL: what the op-0x49 room list reports, held as state rather than
 * produced by a default.
 *
 * ## Why this exists at all when it is empty
 *
 * Nothing in this build creates a room. The create/join opcodes are a later
 * slice, so the honest answer to "which rooms exist in area N" today is NONE -
 * and an empty in-area lobby is a real, renderable state, not a failure. What is
 * NOT acceptable is that answer arriving as `roomListProvider = () => []`, a
 * default nobody chose, sitting in a constructor where the composed application
 * never passed anything: that reads identically whether the room model is empty
 * or was never wired, and the 2026-08-06 review found production running on it.
 *
 * So the emptiness is STRUCTURAL and inspectable - `size` is 0 because this
 * registry holds nothing, the startup log says so, and the day a create slice
 * lands it opens rooms here instead of replacing a lambda.
 *
 * ## Capacity and identity are stored; population is DERIVED
 *
 * `current` used to be a field set at `open()` that nothing ever updated - a
 * materialised counter with no writer, which reads identically to a room nobody
 * has joined. It is now a getter over `presence.countInRoom(handle)`. The line is
 * the one `PRESENCE-AND-COUNTS-DESIGN.md` section 2.6 draws: **a field is derived
 * if and only if deleting a session must change it.** `max`, `name`, `flags` and
 * the handle are authored; the population is not.
 *
 * A room is therefore also created WITH its host already moved into it, and
 * closed by the same transition that removes its last member, so it can never
 * exist with zero members. That is what removes the need for a ghost-room
 * sweeper rather than reimplementing one.
 *
 * ## Rooms belong to an area, and the area comes from the ENTER
 *
 * A room is listed for the area its members are in, and the asking session's
 * area is the one its accepted op-0x06 ENTER resolved (`snap-lobby-session.js`).
 * That is Inference, not Observation: no capture shows a populated op-0x49, and
 * the request's payload has not been decoded, so filtering by the REQUEST would
 * be reading bytes we have not established. Filtering by the session's own
 * entered area needs no wire format at all, and with zero rooms the two are
 * indistinguishable anyway - stated here so the first populated capture is
 * checked against it rather than assumed to agree.
 *
 * ## The per-area bound is the datagram, not a policy number
 *
 * One op-0x49 reply is one SN@P message and the length field is ten bits, so at
 * most `MAXIMUM_ROOM_LIST_RECORDS` records fit. Opening past that is refused
 * HERE, at the point a room is created, because the alternative is a codec
 * refusal at send time - which would leave a client that asked for a list with
 * no reply at all, and the missing reply, not the full lobby, would be what a
 * player saw.
 */

export class LobbyRoomsError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'LobbyRoomsError';
    this.code = code;
  }
}

function fail(code, message) {
  throw new LobbyRoomsError(code, message);
}

/**
 * `buildRoomListPayload` writes the name into the 0x14 bytes before the
 * current-players word, so 19 plus a NUL is the whole field. Enforced here so a
 * name is refused when a room is opened rather than when the list is drawn.
 */
const MAXIMUM_ROOM_NAME_BYTES = 0x13;

function uint32(value, field) {
  if (!Number.isSafeInteger(value) || value < 0 || value > 0xffffffff) {
    fail('INVALID_U32', `${field} must be a uint32, not ${value}`);
  }
  return value >>> 0;
}

/**
 * One live room. `current` is a QUERY, not a field - see the module docstring.
 *
 * Frozen instances are not used because a getter is the whole point: a frozen
 * object literal would have to carry a number, and a number is the defect.
 */
class LobbyRoom {
  #countInRoom;

  constructor({ handle, boxId, name, max, flags, ownerAccountSessionId, countInRoom }) {
    this.handle = handle;
    this.boxId = boxId;
    this.name = name;
    this.max = max;
    this.flags = flags;
    /** Who created it. Identity, so it is stored; not a location, so it is not presence. */
    this.ownerAccountSessionId = ownerAccountSessionId;
    this.#countInRoom = countInRoom;
    Object.freeze(this);
  }

  /** C7 op-0x49 `+0x14`, C8's current byte: the members, counted now. */
  get current() {
    return this.#countInRoom(this.handle);
  }
}

/** Live rooms, by area. Bounded, fail-closed, and empty until something opens one. */
export class LobbyRoomRegistry {
  #maximumPerArea;
  #countInRoom;
  #nextHandle;
  // handle -> room. One map, insertion-ordered, because the list a client sees
  // must be stable across the ~1 Hz refresh: a row that moves under the cursor
  // is a row the player selects by accident.
  #rooms = new Map();

  constructor({
    maximumRoomsPerArea = MAXIMUM_ROOM_LIST_RECORDS,
    /**
     * How many members a room has. Injected rather than counted here, because
     * membership is presence's and this registry must not become a second home
     * for it (invariant P2). Defaults to zero ONLY so a test can construct a
     * registry with no presence; the composed application always passes it, and
     * `openFor` refuses without a host anyway.
     */
    countInRoom = () => 0,
    /**
     * Where minted handles start. Non-zero because 0 is the client's empty-slot
     * marker in its own `0x6fee8c` table, and small because a handle is BE32 on
     * the create accept: a small monotonic value stays legible in a hex log.
     */
    firstHandle = 1
  } = {}) {
    if (!Number.isSafeInteger(maximumRoomsPerArea) || maximumRoomsPerArea < 1 ||
      maximumRoomsPerArea > MAXIMUM_ROOM_LIST_RECORDS) {
      fail(
        'MAXIMUM_ROOMS',
        `maximumRoomsPerArea must be 1..${MAXIMUM_ROOM_LIST_RECORDS}; one op-0x49 reply is one ` +
        'SN@P message and its length field is ten bits'
      );
    }
    if (typeof countInRoom !== 'function') {
      fail('ROOM_COUNT_SEAM', 'countInRoom must be a function; room population is derived');
    }
    if (!Number.isSafeInteger(firstHandle) || firstHandle < 1 || firstHandle > 0xffffffff) {
      fail('ROOM_HANDLE', 'firstHandle must be a non-zero uint32');
    }
    this.#maximumPerArea = maximumRoomsPerArea;
    this.#countInRoom = countInRoom;
    this.#nextHandle = firstHandle;
  }

  /** How many rooms exist across every area. 0 is the state this build ships in. */
  get size() {
    return this.#rooms.size;
  }

  get maximumRoomsPerArea() {
    return this.#maximumPerArea;
  }

  /**
   * The rooms of one area, in the order they were opened.
   *
   * A null or unknown box - a session that has not entered an area, or one whose
   * ENTER key resolved to nothing - gets an empty list rather than every room on
   * the server. Leaking another area's rooms into that gap would put rooms on
   * screen that the player cannot be in.
   */
  roomsIn(boxId) {
    if (boxId == null) return [];
    const rooms = [];
    for (const room of this.#rooms.values()) {
      if (room.boxId === boxId) rooms.push(room);
    }
    return rooms;
  }

  /**
   * Open a room. Nothing in this build calls it yet; the create slice will.
   *
   * `handle` is the opaque value the client round-trips through its `0x6fee68`
   * table and sends back in the ENTER request, so it is the identity of a room
   * and must be unique across every area - a duplicate would make two rooms
   * indistinguishable at exactly the point one is joined.
   */
  open({ handle, boxId, name, max, flags = 0, ownerAccountSessionId = null }) {
    uint32(handle, 'handle');
    if (handle === 0) {
      fail('ROOM_HANDLE', 'a room handle must be non-zero; 0 is the client\'s empty slot');
    }
    if (this.#rooms.has(handle)) {
      fail('ROOM_HANDLE', `room handle 0x${handle.toString(16)} is already open`);
    }
    if (!Number.isSafeInteger(boxId) || boxId < 1) {
      fail('ROOM_AREA', 'a room belongs to an area box id of 1 or more');
    }
    if (typeof name !== 'string' || name.length === 0) {
      fail('ROOM_NAME', 'a room needs a non-empty name');
    }
    if (Buffer.byteLength(name, 'latin1') > MAXIMUM_ROOM_NAME_BYTES) {
      fail(
        'ROOM_NAME',
        `room name "${name}" does not fit the ${MAXIMUM_ROOM_NAME_BYTES}-byte field with its NUL`
      );
    }
    uint32(flags, 'flags');
    if (!Number.isSafeInteger(max) || max < 1) {
      fail('ROOM_CAPACITY', 'a room needs a maximum of at least one player');
    }
    if (this.roomsIn(boxId).length >= this.#maximumPerArea) {
      // Fail closed rather than truncate the list: a truncated list hides rooms
      // that exist, and the player would be looking at a lobby that disagrees
      // with the server about what is in it.
      fail(
        'ROOM_CAPACITY',
        `area ${boxId} already holds ${this.#maximumPerArea} rooms, the most one op-0x49 reply ` +
        'can carry'
      );
    }
    const room = new LobbyRoom({
      handle: handle >>> 0,
      boxId,
      name,
      max,
      flags,
      ownerAccountSessionId,
      countInRoom: this.#countInRoom
    });
    this.#rooms.set(room.handle, room);
    return room;
  }

  /**
   * Mint a handle and open a room WITH its host already inside it.
   *
   * One operation, because a room that exists with zero members is a ghost with a
   * window for a sweeper to be needed in. The presence move happens after the
   * room is in the map so that the `countInRoom` getter is answerable the instant
   * anything reads the room - including the very reply this call is building.
   *
   * The handle is minted here rather than by the caller because it is the room's
   * identity and it must be unique across every area: the client round-trips it
   * through `0x6fee8c` and hands it back as the ENTER token, so a duplicate makes
   * two rooms indistinguishable at exactly the point one is joined.
   */
  openFor({ presence, host, boxId, name, max, flags = 0 }) {
    if (presence == null || typeof presence.moveTo !== 'function') {
      fail('ROOM_PRESENCE', 'openFor needs the presence registry; a room is opened with its host');
    }
    if (host == null) {
      fail('ROOM_HOST', 'a room is created with its host, so it can never hold zero members');
    }
    const handle = this.#mint();
    const room = this.open({
      handle, boxId, name, max, flags, ownerAccountSessionId: host.accountSessionId
    });
    presence.moveTo(host, { roomHandle: handle, slot: 0 });
    return room;
  }

  /** The room a handle names, or null. This is how a later ENTER resolves. */
  byHandle(handle) {
    if (!Number.isSafeInteger(handle) || handle < 0 || handle > 0xffffffff) return null;
    return this.#rooms.get(handle >>> 0) ?? null;
  }

  /** Forget a room. Returns whether one was open. Idempotent. */
  close(handle) {
    return this.#rooms.delete(uint32(handle, 'handle'));
  }

  /**
   * The next handle, monotonic and never reused within a process.
   *
   * Never reused because a client that still holds a stale handle in its
   * `0x6fee8c` table would otherwise resolve it to a DIFFERENT room, and the
   * player would be admitted somewhere they did not choose. Wrap is refused
   * rather than reset for the same reason.
   */
  #mint() {
    if (this.#nextHandle > 0xffffffff) {
      fail('ROOM_HANDLE_EXHAUSTED', 'the room handle space is exhausted; handles are never reused');
    }
    const handle = this.#nextHandle;
    this.#nextHandle += 1;
    return handle >>> 0;
  }
}
