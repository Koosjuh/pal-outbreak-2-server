/**
 * GAME SESSION: the gamenumber bookkeeping of bioserver `broadcastGetReady`
 * plus the relay/meeting-room scope queries. PORT-PLAN §A.1 row
 * "broadcastGetReady + AGL membership". In-memory only - DB persistence is
 * deliberately absent (T37 shows post-game re-entry on the SAME session, so
 * the reconnect-routing half of gamenumber is not yet needed).
 *
 * Reference oracle (Observation, code-read):
 * `references/bioserver/.../bioserv2/bioserver/PacketHandler.java`
 * `broadcastGetReady` lines 367-398, in THIS order:
 *   1. if the slot has no gamenumber, mint one (monotone counter,
 *      getNextGameNumber line 141-143) and set it on EVERY client in the slot
 *      (lines 375-389) - minted ONCE: a second start of the same room reuses
 *      the number;
 *   2. slot status -> BUSY so nobody else joins (line 392);
 *   3. GETREADY to the slot members (lines 396-397) - which in PAL is NOT a
 *      server push at all (the host's op-0x10 sub-3 carries it, B1 §3), so
 *      this module's job ends at the party bookkeeping and the BUSY
 *      transition. It sends nothing.
 *
 * Relay scope: GameServerPacketHandler relays every in-game buffer to every
 * client with the SAME gamenumber except the sender; the after-game lobby
 * (`broadcastInAgl`, ClientList) is membership by gamenumber too. Both are the
 * same query here. LEAVEAGL clears the member's gamenumber (sendLeaveAGL
 * lines 1628-1631).
 *
 * No wall clock anywhere: the gamenumber source is an injectable counter and
 * defaults to a monotone one starting at 1 - never `Date.now`.
 */

export class GameSessionError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'GameSessionError';
    this.code = code;
  }
}

function fail(code, message) {
  throw new GameSessionError(code, message);
}

/** The default mint: monotone from 1, like the reference's ++counter. */
function monotoneCounter() {
  let next = 0;
  return () => {
    next += 1;
    return next;
  };
}

/** One started game: the number and the party snapshot taken at start. */
class GameSession {
  #gamenumber;
  #roomHandle;
  #party;

  constructor({ gamenumber, roomHandle, party }) {
    this.#gamenumber = gamenumber;
    this.#roomHandle = roomHandle;
    this.#party = Object.freeze([...party]);
  }

  get gamenumber() {
    return this.#gamenumber;
  }

  get roomHandle() {
    return this.#roomHandle;
  }

  /**
   * The account session ids of the party AS OF THE START, in member order. A
   * snapshot, not a live query: the reference persists the party via the DB
   * gamenumber rows at mint time, and later membership questions (relay, AGL)
   * are answered by the LIVE gamenumber attribute, not by this list.
   */
  get party() {
    return this.#party;
  }
}

export class GameSessionRegistry {
  #nextGameNumber;
  // roomHandle -> GameSession. The slot's `gamenr` field in the reference.
  #byRoom = new Map();

  constructor({
    /** Injectable mint (PORT-PLAN A: no Date.now in tests without injection). */
    nextGameNumber = monotoneCounter()
  } = {}) {
    if (typeof nextGameNumber !== 'function') {
      fail('GAME_MINT', 'nextGameNumber must be a function returning the next number');
    }
    this.#nextGameNumber = nextGameNumber;
  }

  get size() {
    return this.#byRoom.size;
  }

  /** The live session for a room, or null. */
  forRoom(roomHandle) {
    return this.#byRoom.get(roomHandle) ?? null;
  }

  /**
   * The start bookkeeping, in the REFERENCE ORDER:
   * mint-once -> gamenumber onto every member profile (the party) -> room
   * BUSY. The order is observable - `markBusy` runs after every member already
   * carries the gamenumber - and is pinned by a test, because the relay scope
   * of a message sent the instant the room goes BUSY depends on it.
   *
   * `members` are the room's member PROFILES in roster order (the caller reads
   * them from presence + profiles; this module never touches location - P2).
   * Sends nothing: the PAL GETREADY analogue is host-driven (B1 §3).
   */
  start({ roomHandle, members, lifecycle }) {
    if (!Number.isSafeInteger(roomHandle) || roomHandle < 1) {
      fail('GAME_ROOM', `a room handle is a positive integer, not ${roomHandle}`);
    }
    if (!Array.isArray(members) || members.length === 0) {
      fail('GAME_PARTY', 'a game starts with at least one member profile');
    }
    if (lifecycle == null || typeof lifecycle.markBusy !== 'function') {
      fail('GAME_SEAM', 'the lifecycle registry is required for the BUSY transition');
    }

    // 1. Mint ONCE per room: an existing session's number is reused
    //    (broadcastGetReady lines 374-389 run only when gamenr == 0).
    let session = this.#byRoom.get(roomHandle);
    if (session == null) {
      const gamenumber = this.#requireMinted(this.#nextGameNumber());
      session = new GameSession({
        gamenumber,
        roomHandle,
        party: members.map((profile) => profile.accountSessionId)
      });
      this.#byRoom.set(roomHandle, session);
    }

    // 2. The party: every member carries the gamenumber (lines 380-386).
    for (const profile of members) {
      profile.setGameNumber(session.gamenumber);
    }

    // 3. Room -> BUSY (line 392), AFTER the party is set.
    lifecycle.markBusy(roomHandle);
    return session;
  }

  /**
   * The relay scope: every live profile with the same gamenumber except the
   * sender (GameServerPacketHandler's dumb-relay audience), which is also the
   * after-game meeting-room membership (`broadcastInAgl`).
   */
  relayScope({ gamenumber, profiles, except = null }) {
    this.#requireGameNumber(gamenumber);
    if (profiles == null || typeof profiles.all !== 'function') {
      fail('GAME_SEAM', 'the profile registry is required for a scope query');
    }
    return profiles.all().filter((profile) =>
      profile.gamenumber === gamenumber && profile !== except
    );
  }

  /** Meeting-room membership IS the gamenumber set (InAgl). */
  meetingRoomMembers({ gamenumber, profiles }) {
    return this.relayScope({ gamenumber, profiles });
  }

  /** LEAVEAGL: the member's gamenumber -> 0 (sendLeaveAGL lines 1628-1631). */
  leaveMeetingRoom(profile) {
    if (profile == null || typeof profile.setGameNumber !== 'function') {
      fail('GAME_PROFILE', 'a player profile is required');
    }
    profile.setGameNumber(0);
    return profile;
  }

  /**
   * Forget a room's session (the slot reset path: Slot.reset() clears gamenr).
   * Members who already carry the number keep it - that is the reference
   * behaviour too, and it is what lets the party regroup in the meeting room
   * after the lobby-side room dissolved (contract §7.4 step 5).
   */
  clearRoom(roomHandle) {
    return this.#byRoom.delete(roomHandle);
  }

  #requireMinted(gamenumber) {
    this.#requireGameNumber(gamenumber);
    for (const session of this.#byRoom.values()) {
      if (session.gamenumber === gamenumber) {
        fail('GAME_MINT', `the mint returned ${gamenumber}, which is already live`);
      }
    }
    return gamenumber;
  }

  #requireGameNumber(gamenumber) {
    if (!Number.isSafeInteger(gamenumber) || gamenumber < 1) {
      fail('GAME_NUMBER', `a gamenumber is a positive integer, not ${gamenumber}`);
    }
  }
}

export function createGameSessionRegistry(options) {
  return new GameSessionRegistry(options);
}
