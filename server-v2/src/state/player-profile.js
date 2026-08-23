/**
 * PLAYER PROFILE: the identity/attribute half of bioserver's `Client`, keyed on
 * the account session id. PORT-PLAN §A.1 row "Client - identity/attribute half".
 *
 * Reference oracle (Observation, code-read):
 * `references/bioserver/bioserver-docker-2.4.1/bioserver-docker-2.4.1/bioserv2/
 * bioserver/Client.java` - a bioserver Client carries BOTH location
 * (`area/room/slot`) and attributes (`playernum`, `hostflag`, HNPair,
 * `characterstats` 0xD0 blob, `gamenumber`). server-v2 already has a single home
 * for location - `state/presence.js`, invariant P2 - so this module holds ONLY
 * the attribute half and stores no location field, ever. A profile knowing where
 * its player is would be a second home for WHERE, which is the defect P2 exists
 * to remove.
 *
 * Field provenance:
 * - `handle`: the login handle. PAL has no IDHNPAIRS/HNSELECT exchange (the
 *   FOUNDATION-MAP finding, PORT-PLAN §D) - the name echoed into member records
 *   is the login handle and the client renders our bytes verbatim.
 * - `characterStats`: store-and-echo. Client.java line 34 sizes it 0xD0; the
 *   plan notes a 0xF0 variant. We store whatever blob the client supplies and
 *   default to 0xD0 zero bytes because today's op-0x0a ships zeros
 *   (SERVER-V2-SURFACE §1.2, Observation).
 * - `playernum`: 0 = unassigned; host = 1 (PacketHandler.sendCreateSlot line
 *   1195), joiners 2..4 (ClientList.getFreePlayerNum lines 98-108). Written by
 *   the slot allocator, never by transport code.
 * - `hostflag`: 0/1 (Client.java line 44).
 * - `gamenumber`: 0 = none; the thread tying party -> in-game relay group ->
 *   meeting room (BIOSERVER-CONTRACT §9.5). Written by `state/game-session.js`.
 */

export class PlayerProfileError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'PlayerProfileError';
    this.code = code;
  }
}

function fail(code, message) {
  throw new PlayerProfileError(code, message);
}

/** Client.java line 34: `characterstats; // 0xd0 in len`. */
export const DEFAULT_CHARACTER_STATS_LENGTH = 0xd0;

/**
 * Upper bound for a supplied blob. The reference reads the length the client
 * states (Client.java getPreGameStat writes `statLen:2` then the blob); PAL
 * evidence names 0xD0 and 0xF0 variants. 0x200 bounds a hostile length without
 * refusing either observed size.
 */
const MAXIMUM_CHARACTER_STATS_LENGTH = 0x200;

/** Bounded like every other table here: a full one refuses, it never evicts. */
const DEFAULT_MAXIMUM_PROFILES = 4096;

/**
 * One player's attributes. Constructed only by the registry. There is no
 * location field on purpose (invariant P2) - do not add one.
 */
class PlayerProfile {
  #accountSessionId;
  #handle;
  #playernum = 0;
  #hostflag = 0;
  #gamenumber = 0;
  #characterStats;

  constructor({ accountSessionId, handle }) {
    this.#accountSessionId = accountSessionId;
    this.#handle = handle;
    this.#characterStats = Buffer.alloc(DEFAULT_CHARACTER_STATS_LENGTH);
  }

  get accountSessionId() {
    return this.#accountSessionId;
  }

  /** The login handle - the name echoed into member records verbatim. */
  get handle() {
    return this.#handle;
  }

  /** 0 unassigned, 1 host, 2..4 joiners. */
  get playernum() {
    return this.#playernum;
  }

  /** 1 while this player hosts a room (Client.java `host`), else 0. */
  get hostflag() {
    return this.#hostflag;
  }

  /** 0 = no game; otherwise the minted party/relay/meeting-room key. */
  get gamenumber() {
    return this.#gamenumber;
  }

  /** A COPY of the stored blob; the stored bytes are not reachable to mutate. */
  get characterStats() {
    return Buffer.from(this.#characterStats);
  }

  setPlayerNum(playernum) {
    if (!Number.isSafeInteger(playernum) || playernum < 0 || playernum > 4) {
      fail('PROFILE_PLAYERNUM', `playernum must be 0..4, not ${playernum}`);
    }
    this.#playernum = playernum;
    return this;
  }

  setHostFlag(hostflag) {
    if (hostflag !== 0 && hostflag !== 1) {
      fail('PROFILE_HOSTFLAG', `hostflag is 0 or 1, not ${hostflag}`);
    }
    this.#hostflag = hostflag;
    return this;
  }

  setGameNumber(gamenumber) {
    if (!Number.isSafeInteger(gamenumber) || gamenumber < 0) {
      fail('PROFILE_GAMENUMBER', `gamenumber must be a non-negative integer, not ${gamenumber}`);
    }
    this.#gamenumber = gamenumber;
    return this;
  }

  /**
   * Store-and-echo: keep a COPY of whatever blob the client supplied, bounded.
   * The server never interprets the bytes (Client.java stores and replays them).
   */
  setCharacterStats(blob) {
    if (!Buffer.isBuffer(blob)) {
      fail('PROFILE_CHARSTATS', 'character stats are a Buffer supplied by the client');
    }
    if (blob.length === 0 || blob.length > MAXIMUM_CHARACTER_STATS_LENGTH) {
      fail(
        'PROFILE_CHARSTATS',
        `character stats length ${blob.length} is outside 1..${MAXIMUM_CHARACTER_STATS_LENGTH}`
      );
    }
    this.#characterStats = Buffer.from(blob);
    return this;
  }
}

export class PlayerProfileRegistry {
  #maximum;
  // accountSessionId -> PlayerProfile. THE table.
  #profiles = new Map();

  constructor({ maximumProfiles = DEFAULT_MAXIMUM_PROFILES } = {}) {
    if (!Number.isSafeInteger(maximumProfiles) || maximumProfiles < 1) {
      fail('MAXIMUM_PROFILES', 'maximumProfiles must be a positive whole number');
    }
    this.#maximum = maximumProfiles;
  }

  get size() {
    return this.#profiles.size;
  }

  /**
   * Open a profile for an account session. Refuses duplicates: the profile's
   * lifetime is the session's, and the displacement rules live with the session
   * registries, not here.
   */
  open({ accountSessionId, handle }) {
    if (typeof accountSessionId !== 'string' || accountSessionId.length === 0) {
      fail('PROFILE_KEY', 'a profile is keyed on a non-empty account session id');
    }
    if (typeof handle !== 'string' || handle.length === 0) {
      fail('PROFILE_HANDLE', 'a profile needs the login handle; it is what the roster renders');
    }
    if (this.#profiles.has(accountSessionId)) {
      fail('PROFILE_DUPLICATE', `account session ${accountSessionId} already has a profile`);
    }
    if (this.#profiles.size >= this.#maximum) {
      // Fail closed: refuse the new profile, never evict a live one.
      fail('PROFILE_CAPACITY', `${this.#profiles.size} profiles are live and the cap is ${this.#maximum}`);
    }
    const profile = new PlayerProfile({ accountSessionId, handle });
    this.#profiles.set(accountSessionId, profile);
    return profile;
  }

  /** The profile for one account session, or null. */
  get(accountSessionId) {
    return this.#profiles.get(accountSessionId) ?? null;
  }

  /** Every live profile, in open order. The relay-scope query iterates this. */
  all() {
    return [...this.#profiles.values()];
  }

  /** Forget a profile. Idempotent. */
  release(accountSessionId) {
    return this.#profiles.delete(accountSessionId);
  }
}

export function createPlayerProfileRegistry(options) {
  return new PlayerProfileRegistry(options);
}
