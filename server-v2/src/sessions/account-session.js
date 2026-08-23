/**
 * GAME-ACCOUNT SESSIONS — layer 2 of three.
 *
 * The three layers, kept deliberately separate because conflating them is what
 * produced `UNKNOWN_DNAS_TOKEN` (T25-T27):
 *
 *   1. DNAS / platform session - completed before the lobby via the DNAS
 *      exchange. V2 does not model it and does not need to: the cracked
 *      certificate path already satisfies it, and the token it yields is
 *      ISSUED BY US from a replayed asset (T27), so it identifies nothing.
 *   2. GAME-ACCOUNT session - THIS module. Established by the UDP-9090
 *      register followed by the client's continuation into the bind.
 *   3. Lobby transport session - a TCP 10127 connection presenting `0x1007`.
 *      It must be correlated to a layer-2 session; see `connection-identity.js`.
 *
 * ## Why the register is the authentication event, and what it does NOT prove
 *
 * The `0x2d` register reply is Blowfish-encrypted with the account password,
 * and an HONEST client only continues to the bind if that body decrypts, under
 * the password IT holds, to the handle it sent (`FUN_001d9678`'s `strcmp`). So a
 * bind from a real client is evidence that both ends hold the same password.
 *
 * **It is not evidence about an arbitrary sender.** The register carries no
 * credential and V2 verifies nothing about who sent it: anyone who knows a
 * login identity can send a register and then a bind, and will obtain a lobby
 * identity as that user. This is a real and accepted cost of treating the
 * register as the authentication event, and it is a REDUCTION in strength from
 * the previous model, where reaching the lobby required a scrypt-verified HTTP
 * login. It is accepted because the previous model made the browser the only
 * route in, which a client whose memory card already holds an account never
 * takes, and because it keyed identity on a token we mint ourselves.
 *
 * Closing it properly needs the register to carry something only the account
 * holder can produce, which the captured protocol does not provide. Recorded
 * rather than papered over.
 *
 * ## Displacing a live session needs PROOF OF THE ACCOUNT, never its name
 *
 * `establish` replaces an account's previous session. Until 2026-08-06 it did so
 * unconditionally, and the audit drove the consequence over a real socket: an
 * arbitrary UDP sender registered with a victim's login identity, bound from its
 * own address, and the victim's live lobby session was destroyed - `#forget` ->
 * `onSessionReleased` -> `LobbySession.terminate()`. The attacker could not read
 * the register reply, and did not need to: naming the victim was enough, and
 * login identities are short numeric handles.
 *
 * So displacement now requires a `proof` (see `ACCOUNT_PROOF`), and an
 * establishment that cannot prove the account is REFUSED rather than allowed to
 * replace anyone. It is not silently downgraded to "keep the old session and
 * hand this caller something": that would give an unproven caller a session id
 * for an account it never proved.
 *
 * ## What is NOT an identity key
 *
 * - The DNAS token. We mint it from a static replay asset, so every console
 *   receives the same value (T27, OQ-022). It is recorded as a correlation
 *   signal and nothing more.
 * - The source address. It is a NECESSARY correlation signal - a session is only
 *   a candidate for a connection from where it was authenticated - but never a
 *   sufficient one and never the identity itself. Two sessions behind one
 *   address are refused, not told apart by it.
 *
 * ## Ambiguity is refused, never guessed
 *
 * A lobby connection claims a session only when exactly one is eligible. Zero
 * or several is a refusal. Claiming is single-use, so a second connection
 * cannot ride in behind the first.
 */

const DEFAULT_LOBBY_CLAIM_WINDOW_MS = 2 * 60 * 1000;
/**
 * The observed reconnect gap is about 15 s (R-019, and 2026-08-04: complete
 * 18:10:26, resume 18:10:41). 45 s gives margin without leaving a completed
 * session claimable for minutes - every second of that window is an opening for
 * anyone sharing the address.
 */
const DEFAULT_RESUME_WINDOW_MS = 45 * 1000;
/**
 * The capture shows exactly ONE resume per completed initialization. The
 * allowance above that exists only so a client whose first attempt was lost can
 * retry; it is an implementation control, not a protocol fact.
 */
const DEFAULT_MAXIMUM_RESUME_ATTEMPTS = 3;
const DEFAULT_TTL_MS = 30 * 60 * 1000;
/** Sweeping walks every session, so it is rate-limited rather than per-call. */
const SWEEP_INTERVAL_MS = 1000;
// Hundreds of concurrent players is the design target, so these are sized for
// that rather than for a single rig. One entry per logged-in account.
const DEFAULT_MAXIMUM = 4096;

/**
 * WHAT COUNTS AS PROOF OF AN ACCOUNT, stated as precisely as the evidence allows.
 *
 * `PASSWORD_VERIFIED` - the HTTP flow scrypt-verified the password on this very
 * request before calling us (`web-service.js` create/login). Strongest thing V2
 * has; it is a direct check of the credential.
 *
 * `REGISTRATION_NONCE` - the UDP bind echoed the 16-byte nonce this server
 * minted for that registration. What that actually proves, and what it does not:
 *
 *   PROVEN (Observation). The nonce sits at register-reply PLAINTEXT +0x3c,
 *   inside the 0x80 bytes we Blowfish-ECB encrypt under the account password
 *   (`register-service.js`), so it leaves this server only in ciphertext keyed
 *   by that password. The rig run of 2026-08-06 (`captures/v2-live/
 *   t33-run11-nonce-echo.pcap`, Pi journal `udp9090 bind-tail-echoed`,
 *   `matched: true`) shows a real PS2 echoing it back verbatim, and the nonce
 *   byte string occurs exactly ONCE in that whole capture - in the client's
 *   bind, never in our reply. So a bind carrying it demonstrates that its sender
 *   obtained a value that only a holder of the account password could read out
 *   of our reply.
 *
 *   NOT PROVEN, and deliberately not claimed:
 *     - it is not secrecy against a network observer. UDP 9090 is cleartext, so
 *       anyone who can see the victim's own bind sees the nonce and could reuse
 *       it inside its short life. This raises the bar from "knows a handle" to
 *       "sits on the path"; it does not close it.
 *     - it is not 128 bits of security. The ciphertext carries a KNOWN plaintext
 *       (the login identity at +0x00), so an attacker who registers as the
 *       victim can attack the password offline and then read the nonce. The
 *       strength is the password's entropy, not the nonce's.
 *     - it says nothing about the platform/DNAS layer, which identifies nobody
 *       (T27).
 *
 * `NONE` - nothing about the sender was verified. This is the DEFAULT, because
 * the only safe way to be wrong here is to refuse. Contrast
 * `markInitializationComplete`'s `resumed`, which is required precisely because
 * BOTH of its defaults are unsafe; here one of them cannot be.
 */
export const ACCOUNT_PROOF = Object.freeze({
  NONE: 'none',
  PASSWORD_VERIFIED: 'password-verified',
  REGISTRATION_NONCE: 'registration-nonce'
});

/**
 * The proofs that may take a live session away from whoever holds it. Both are
 * evidence about the ACCOUNT. Nothing about the transport is in this set, and in
 * particular the source address is not - two players behind one NAT share it,
 * so admitting it would make one of them able to evict the other.
 */
const PROOFS_THAT_MAY_DISPLACE = new Set([
  ACCOUNT_PROOF.PASSWORD_VERIFIED,
  ACCOUNT_PROOF.REGISTRATION_NONCE
]);

const KNOWN_PROOFS = new Set(Object.values(ACCOUNT_PROOF));

export class AccountSessionError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'AccountSessionError';
    this.code = code;
  }
}

let nextSessionSerial = 1;

export class AccountSessionRegistry {
  #sessions = new Map();
  // userid -> accountSessionId. Kept so `establish` and `findByUserId` do not
  // scan every live session; with hundreds of players every lobby connection
  // would otherwise walk the whole table.
  #byUserId = new Map();
  // connectionRef -> accountSessionId, so a disconnect does not scan either.
  #byConnection = new Map();
  // Sessions currently claimable, so resolution does not walk claimed ones.
  #unclaimed = new Set();
  #clock;
  #ttlMs;
  #lobbyClaimWindowMs;
  #resumeWindowMs;
  #maximumResumeAttempts;
  #onSessionReleased;
  #maximum;
  #lastSweepMs = 0;

  /**
   * @param {object} [options]
   * @param {() => number} [options.clock]
   * @param {number} [options.ttlMs] how long a session lives without activity,
   *   where activity means being established, claimed or released. A long-lived
   *   lobby connection does not currently refresh it.
   * @param {number} [options.lobbyClaimWindowMs] how long after the bind a lobby
   *   connection may claim the session. The observed register-to-lobby gap is
   *   about 260 ms (T25); this is generous but still short, because an
   *   unclaimed session is a standing invitation.
   * @param {number} [options.maximum]
   */
  constructor({
    clock = () => Date.now(),
    ttlMs = DEFAULT_TTL_MS,
    lobbyClaimWindowMs = DEFAULT_LOBBY_CLAIM_WINDOW_MS,
    // How long after completing initialization a resume may attach. Observed
    // gap is about 15 s (R-019, and 2026-08-04: complete 18:10:26, resume
    // 18:10:41). Generous, but an unattached completed session is a standing
    // invitation, so not unlimited.
    resumeWindowMs = DEFAULT_RESUME_WINDOW_MS,
    maximumResumeAttempts = DEFAULT_MAXIMUM_RESUME_ATTEMPTS,
    maximum = DEFAULT_MAXIMUM,
    // Deterministic release hook. Fired exactly once per session, from the one
    // place a session is ever forgotten, so displacement, expiry, explicit
    // removal and shutdown all release owned state on the same path.
    onSessionReleased = null
  } = {}) {
    this.#clock = clock;
    this.#ttlMs = ttlMs;
    this.#lobbyClaimWindowMs = lobbyClaimWindowMs;
    this.#resumeWindowMs = resumeWindowMs;
    this.#maximumResumeAttempts = maximumResumeAttempts;
    this.#onSessionReleased = onSessionReleased;
    this.#maximum = maximum;
  }

  get size() {
    this.#sweep();
    return this.#sessions.size;
  }

  /**
   * Record a completed UDP register + bind. This is the authentication event.
   *
   * A repeat for the same account REPLACES its previous session rather than
   * adding one: an account has at most one live game session. The reference
   * server goes further and DISCONNECTS the displaced client
   * (`PacketHandler.check_session`, "Disconnect double session for userid");
   * V2 does not yet do that, so a displaced connection keeps operating from its
   * cached record until it closes. The displaced session is returned so a caller
   * can tear it down once there is something to tear down.
   *
   * Replacing a LIVE session requires `proof` - see `ACCOUNT_PROOF` and the D-2
   * note at the top of this file. Establishing when nothing is live does not:
   * that path grants an identity but takes none away, and it is the pre-existing
   * accepted cost of treating the register as the authentication event, recorded
   * above rather than quietly widened here.
   *
   * @param {object} options
   * @param {string} options.userid
   * @param {string|null} [options.sourceAddress] correlation signal only.
   * @param {number|null} [options.endpointToken] correlation signal only.
   * @param {string} [options.proof] one of `ACCOUNT_PROOF`. Defaults to `NONE`.
   * @returns {{session: object, displaced: object | null}}
   */
  establish({
    userid,
    sourceAddress = null,
    endpointToken = null,
    proof = ACCOUNT_PROOF.NONE
  }) {
    if (typeof userid !== 'string' || userid.length === 0) {
      throw new AccountSessionError('USERID_REQUIRED', 'userid must be a non-empty string');
    }
    // A proof value we do not recognise is a programming error, and treating it
    // as "not good enough" would hide it behind a refusal that looks like an
    // attack. Say which it is.
    if (!KNOWN_PROOFS.has(proof)) {
      throw new AccountSessionError(
        'ACCOUNT_PROOF_UNKNOWN',
        `proof ${JSON.stringify(proof)} is not one of ${[...KNOWN_PROOFS].join(', ')}`
      );
    }
    this.#sweep();

    let displaced = null;
    const existingId = this.#byUserId.get(userid);
    if (existingId != null) {
      displaced = this.#sessions.get(existingId) ?? null;
      if (displaced != null && !PROOFS_THAT_MAY_DISPLACE.has(proof)) {
        // THE D-2 GATE. Refuse, and leave the live session exactly as it was:
        // the caller gets nothing, the player keeps their game. Fails closed -
        // an establishment we cannot attribute to the account holder cannot
        // reach `#forget`, which is the one path that terminates a LobbySession.
        throw new AccountSessionError(
          'ACCOUNT_DISPLACEMENT_UNPROVEN',
          `refusing to displace the live session of ${userid}: this establishment proved ` +
          `nothing about the account (proof=${proof}). Naming an account is not owning it, ` +
          'and login identities are short enumerable handles'
        );
      }
      // #forget, not a bare delete: a displaced session must leave the
      // unclaimed and by-connection indexes too, or they leak.
      if (displaced != null) this.#forget(existingId, displaced);
      else {
        // A stale index entry with no session behind it displaces nobody, so it
        // needs no proof - there is no live player to take anything from.
        this.#sessions.delete(existingId);
        this.#byUserId.delete(userid);
      }
    }

    if (displaced == null && this.#sessions.size >= this.#maximum) {
      // Bounded, and it fails closed: refuse a NEW session rather than evict a
      // live one, so a flood cannot displace a player who is already in.
      throw new AccountSessionError(
        'ACCOUNT_SESSION_LIMIT',
        `refusing to track more than ${this.#maximum} account sessions`
      );
    }

    const now = this.#clock();
    const session = {
      accountSessionId: `as-${nextSessionSerial++}`,
      userid,
      // WHAT AUTHENTICATED THIS SESSION, kept so a later displacement decision
      // and any journal line can say what was actually shown, rather than
      // leaving "how did this session come to exist" unanswerable after the fact.
      proof,
      // Correlation signals. NEITHER is an identity key.
      sourceAddress,
      endpointToken,
      dnasToken: null,
      establishedAtMs: now,
      lastSeenAtMs: now,
      claimedByConnection: null,
      claimedAtMs: null,
      // Set when a lobby connection for this session reaches
      // `lobby-initialization-complete`. Only a session that got that far may be
      // RESUMED, which is what makes a resume a continuation rather than a
      // second, weaker way in.
      initializationCompletedAtMs: null,
      resumeCount: 0,
      // Every resume ATTEMPT that got as far as being resolved, successful or
      // not. Bounded by #maximumResumeAttempts.
      resumeAttempts: 0,
      // The last `0x6501` sequence this session accepted. One byte, so it is a
      // replay filter and never an identity: a resume presenting the SAME
      // sequence is a verbatim frame replay and is refused.
      lastResumeSequence: null
    };
    this.#unclaimed.add(session.accountSessionId);
    this.#sessions.set(session.accountSessionId, session);
    this.#byUserId.set(userid, session.accountSessionId);
    return { session: { ...session }, displaced: displaced ? { ...displaced } : null };
  }

  get(accountSessionId) {
    const session = this.#sessions.get(accountSessionId);
    return session ? { ...session } : null;
  }

  findByUserId(userid) {
    this.#sweep();
    const id = this.#byUserId.get(userid);
    if (id == null) return null;
    const session = this.#sessions.get(id);
    return session ? { ...session } : null;
  }

  /**
   * Sessions a lobby connection could currently claim: established, still
   * inside the claim window, and not already claimed.
   */
  eligibleForLobby() {
    this.#sweep();
    const now = this.#clock();
    const eligible = [];
    // Only unclaimed sessions, so a lobby full of playing users costs nothing
    // to resolve against.
    for (const id of this.#unclaimed) {
      const session = this.#sessions.get(id);
      if (session == null) continue;
      if (now - session.establishedAtMs > this.#lobbyClaimWindowMs) continue;
      eligible.push(session);
    }
    return eligible.map((session) => ({ ...session }));
  }

  /**
   * Resolve the ONE account session a lobby connection may claim.
   *
   * `sourceAddress` filters which sessions are candidates at all; it never
   * grants one. Exactly one candidate is claimed, zero or several is refused,
   * and identity comes from the account session rather than from the address or
   * the DNAS token.
   *
   * @returns {{session: object} | {refusal: string, code: string, candidates: number}}
   */
  resolveForLobby({ sourceAddress = null } = {}) {
    const eligible = this.eligibleForLobby();
    if (eligible.length === 0) {
      return {
        code: 'NO_ELIGIBLE_ACCOUNT_SESSION',
        refusal:
          'no authenticated account session is waiting for a lobby connection; ' +
          'the game-account session is what authenticates, not the DNAS token',
        candidates: 0
      };
    }

    // The source address is a NECESSARY correlation signal, never a sufficient
    // one and never the identity. Requiring it to match closes the obvious
    // race: without it, any connection arriving while exactly one session was
    // unclaimed would claim it, and that session might belong to someone else.
    // Identity still comes from the account session - the address only decides
    // which sessions are candidates at all.
    // A null on EITHER side matches nothing. Treating it as a wildcard would
    // make the filter fail open in exactly the case where we know least.
    const candidates =
      sourceAddress == null
        ? []
        : eligible.filter(
          (session) => session.sourceAddress != null && session.sourceAddress === sourceAddress
        );

    if (candidates.length === 0) {
      return {
        code: 'NO_ELIGIBLE_ACCOUNT_SESSION',
        refusal:
          `${eligible.length} account session(s) are waiting but none was authenticated ` +
          'from this source; refusing rather than handing one to a different endpoint',
        candidates: 0
      };
    }
    if (candidates.length === 1) return { session: candidates[0] };

    // MORE THAN ONE: refuse. Nothing narrows it, deliberately.
    //
    // An earlier version narrowed by which accounts had presented this DNAS
    // token to the HTTP flow. That was wrong twice over: the token is the same
    // static value for every console (T27), so it distinguishes nobody; and
    // reducing an ambiguous set to one and then claiming it IS granting on the
    // strength of that value. Review demonstrated the consequence - an attacker
    // sharing a source address with a victim who had used the browser received
    // the victim's identity.
    //
    // A per-session token would be a legitimate FILTER, on the same footing as
    // the address. It would belong in the candidate set, not in a tie-break, and
    // only once the token is proven distinct.
    return {
      code: 'AMBIGUOUS_ACCOUNT_SESSION',
      refusal:
        `${candidates.length} account sessions are eligible for this source; ` +
        'refusing rather than guessing which player this is',
      candidates: candidates.length
    };
  }

  /**
   * Bind a lobby connection to an account session. Single-use: a session that
   * has already been claimed cannot be claimed again, so a second connection
   * cannot follow the first in.
   */
  claim({ accountSessionId, connectionRef, dnasToken = null }) {
    this.#sweep();
    const session = this.#sessions.get(accountSessionId);
    if (session == null) {
      throw new AccountSessionError('UNKNOWN_ACCOUNT_SESSION', 'account session is not live');
    }
    if (session.claimedByConnection != null) {
      throw new AccountSessionError(
        'ACCOUNT_SESSION_ALREADY_CLAIMED',
        'this account session has already been claimed by another connection'
      );
    }
    session.claimedByConnection = connectionRef;
    this.#unclaimed.delete(accountSessionId);
    this.#byConnection.set(connectionRef, accountSessionId);
    session.claimedAtMs = this.#clock();
    session.lastSeenAtMs = session.claimedAtMs;
    // Recorded AFTER the fact, as an observation about this session. It is not
    // what granted it, and it is deliberately not required to be unique: while
    // DNAS replays a static asset every console presents the same token.
    if (dnasToken != null) session.dnasToken = dnasToken;
    return { ...session };
  }

  /**
   * Record that a lobby connection completed initialization for this session.
   *
   * The client resets immediately afterwards and reopens on a fresh source port
   * whose FIRST frame is `0x6501` (R-019). Only sessions marked here are
   * resumable.
   */
  markInitializationComplete(connectionRef, { resumed } = {}) {
    // REQUIRED, deliberately not defaulted. It used to default to `false`, which
    // is the branch that re-arms the deadline and clears the budget - so a
    // future caller that simply forgot the flag would silently reintroduce the
    // unbounded resume window this whole policy exists to bound. There is no
    // safe default here: defaulting the other way would silently fail to clear
    // the budget instead. Fail loud and make every call site state which event
    // it is.
    if (typeof resumed !== 'boolean') {
      throw new AccountSessionError(
        'RESUMED_FLAG_REQUIRED',
        'markInitializationComplete requires an explicit { resumed } boolean: a FRESH ' +
        'initialization re-arms the deadline and clears the attempt budget, a RESUMED one ' +
        'does neither, and guessing which this is has been a defect twice'
      );
    }
    const id = this.#byConnection.get(connectionRef);
    if (id == null) return null;
    const session = this.#sessions.get(id);
    if (session == null) return null;
    // ABSOLUTE DEADLINE. The resume window runs from the ORIGINAL completed
    // initialization and is never extended.
    //
    // This used to re-arm unconditionally, and every resumed ladder ends in
    // 0x1004 - so each resume slid the window forward. Review drove 20 resumes
    // at 40 s spacing and the session was still resumable 800 s after the
    // original completion, which made the stated 45 s bound fiction.
    const now = this.#clock();
    if (resumed) {
      // A RESUME must never slide the deadline or refund the budget. This is
      // the case that used to re-arm and made the window unbounded.
      session.lastSeenAtMs = now;
      return { ...session };
    }
    // A FRESH initialization is a new evidenced event, not a continuation: the
    // client walked 0x1007 and rebuilt its directory state from nothing. It
    // therefore starts a new absolute deadline and clears the attempt budget.
    //
    // HOW REACHABLE THIS RECOVERY ACTUALLY IS, stated precisely because the
    // first version of this comment overstated it. Reaching here a second time
    // for the SAME session requires the address to be still armed (90 s from
    // the bind, `lobby-arming.js`) AND the session to be unclaimed and inside
    // `lobbyClaimWindowMs` (120 s from the register). The ARMING is the binding
    // constraint of the two: past 90 s the connection is served the boot-auth
    // transcript and never sends 0x1007 at all, so the claim window's own
    // boundary (measured: accepted +119 s, refused +121 s) is never reached.
    // Beyond that the session stays exhausted for the rest of its 30-minute
    // TTL. And no capture shows the client EVER sending a second 0x1007 on a
    // live session - R-019 records that the second ladder does not begin with
    // one - so this path is time-reachable in the normal timeline but
    // unevidenced as client behaviour.
    //
    // The recovery that always works is a new UDP register, and note that it
    // does NOT run this code: `establish` forgets the old session and mints a
    // new one whose budget starts at zero. So this branch is the honest
    // mechanism for a same-session fresh ladder, not the mechanism a stuck
    // player would actually hit.
    //
    // Consequence worth naming: because a fresh ladder resets the counter, the
    // bound is 3 attempts PER FRESH INITIALIZATION, not 3 per session. Review
    // drove five fresh ladders and obtained 15 resume attempts. That buys an
    // attacker nothing new - completing a fresh ladder already means claiming
    // the session, which grants the identity outright - but the bound is not
    // "3 per account session" and must not be described as one.
    session.initializationCompletedAtMs = now;
    session.resumeAttempts = 0;
    session.lastSeenAtMs = now;
    return { ...session };
  }

  /**
   * Resolve the ONE completed session a resume connection may attach to.
   *
   * Deliberately NOT the same pool as `resolveForLobby`: a resume continues an
   * initialization that already finished, so a session that never completed one
   * is not a candidate. That is what stops a resume being a second, weaker
   * entry path.
   *
   * The resume frame differs from the fresh ladder's `0x6501` ONLY in its
   * sequence byte (fresh `0x0a`, resume `0xb4`); the 4-byte payload is
   * `00000000` in both. So the sequence is the only protocol-carried state
   * available, and it is used as a REPLAY filter - one byte cannot be an
   * identity. Resolution is otherwise the source address as a filter plus
   * exactly-one, with ambiguity refused.
   *
   * ## Accepted residual risk, stated plainly
   *
   * An attacker sharing a source address with a player, who opens a connection
   * inside the resume window, will be handed that player's session. Exactly-one
   * protects against choosing between two candidates; it does nothing against an
   * outsider taking the only one. The protocol offers nothing else to bind to:
   * the resume presents no credential, no token, and a one-byte sequence.
   *
   * Mitigated, not solved: the window is narrowed to the observed reconnect gap
   * plus margin rather than left at minutes, and a replayed sequence is refused.
   * This is the same class of accepted cost as the register being the
   * authentication event, and it is recorded here for the same reason.
   *
   * @returns {{session: object} | {refusal: string, code: string, candidates: number}}
   */
  resolveForResume({ sourceAddress = null, sequence = null } = {}) {
    this.#sweep();
    if (sourceAddress == null) {
      return {
        code: 'NO_RESUMABLE_SESSION',
        refusal: 'a resume needs a source address to filter on',
        candidates: 0
      };
    }

    const now = this.#clock();
    const candidates = [];
    const exhausted = [];
    const duplicates = [];
    for (const session of this.#sessions.values()) {
      if (session.initializationCompletedAtMs == null) continue;
      // Already attached to a live connection: a second one would be a double
      // resume, or a replay from somewhere else.
      if (session.claimedByConnection != null) continue;
      if (session.sourceAddress == null || session.sourceAddress !== sourceAddress) continue;
      if (now - session.initializationCompletedAtMs > this.#resumeWindowMs) continue;
      // Duplicate suppression ONLY. This refuses a resume repeating the
      // sequence byte the session last accepted, which catches a verbatim
      // retransmission. It is NOT authentication and NOT replay protection:
      // one byte is trivially varied, and review defeated it with 45,000
      // resumes on alternating 0x00/0x01. The real bound is the attempt
      // counter below.
      if (
        sequence != null &&
        session.lastResumeSequence != null &&
        session.lastResumeSequence === sequence
      ) {
        // Collected, not silently dropped. A duplicate is a DIFFERENT fact from
        // "nothing is waiting" - a completed, unclaimed, in-window session IS
        // waiting - and saying the latter was simply untrue.
        duplicates.push(session);
        continue;
      }
      // BOUNDED ATTEMPTS, checked LAST so that `exhausted` means exactly
      // "would have been a candidate but for the budget".
      //
      // This has now been wrong twice, in opposite directions. Originally the
      // check ran FIRST, so one exhausted session anywhere on the server
      // misreported every unrelated refusal as RESUME_ATTEMPTS_EXHAUSTED.
      // a4a64d66 moved it below the claimed and source-address filters but
      // left it ABOVE the window and duplicate-sequence filters, and claimed in
      // its message that it now ran "only for sessions that are otherwise
      // candidates for this source" - which the code contradicted. Review
      // demonstrated TWO surviving misreports for the session's own source
      // address, which on a single-client rig is the only address there is: an
      // exhausted session whose 45 s window had lapsed 75 s earlier, and a
      // duplicate-sequence replay. Placed last, both report their true reason.
      //
      // A THIRD case is unchanged, deliberately: a second account behind the
      // same NAT still sees RESUME_ATTEMPTS_EXHAUSTED while the exhausted
      // session is still inside its window, because such a session genuinely
      // exists at that address and the address is not identity, so the two
      // cannot be told apart. Telling them apart would mean treating the
      // address as identity, which this module refuses by design.
      if (session.resumeAttempts >= this.#maximumResumeAttempts) {
        exhausted.push(session);
        continue;
      }
      candidates.push(session);
    }

    if (candidates.length === 0) {
      // Most specific reason first. The buckets are disjoint by construction:
      // the duplicate test runs before the attempt test, so a session that is
      // both lands in `duplicates` only.
      if (duplicates.length > 0) {
        return {
          code: 'DUPLICATE_RESUME_SEQUENCE',
          refusal:
            'a completed session from this source is waiting, but this resume repeats the ' +
            `sequence byte 0x${Number(sequence).toString(16)} it last accepted, so this is a ` +
            'verbatim retransmission rather than a new reconnect. Duplicate suppression only: ' +
            'one byte is not authentication and not replay protection',
          candidates: 0
        };
      }
      return {
        code: exhausted.length > 0 ? 'RESUME_ATTEMPTS_EXHAUSTED' : 'NO_RESUMABLE_SESSION',
        refusal:
          exhausted.length > 0
            ? `resume attempts exhausted (limit ${this.#maximumResumeAttempts} per fresh ` +
              'initialization); the recovery that always works is a NEW UDP register, which ' +
              'displaces this session for a new one. A fresh 0x1007 also clears the budget but ' +
              'only while this address is still armed and inside the lobby claim window, and no ' +
              'capture shows the client sending a second 0x1007 on a live session'
            : 'no completed lobby initialization from this source is waiting to be resumed',
        candidates: 0
      };
    }
    if (candidates.length > 1) {
      return {
        code: 'AMBIGUOUS_RESUMABLE_SESSION',
        refusal:
          `${candidates.length} completed sessions from this source could be resumed; ` +
          'refusing rather than attaching to the wrong player',
        candidates: candidates.length
      };
    }
    // Charge the attempt now, so a resume that is resolved but then refused
    // downstream still costs budget.
    //
    // HONEST LIMIT: this does NOT stop an attacker sharing the source address
    // from exhausting a victim's budget - review demonstrated three dropped
    // connections locking the victim out before they reconnected. It cannot,
    // because a resume carries no credential and the address is not identity.
    // The recovery is a fresh initialization, which clears the budget.
    const live = this.#sessions.get(candidates[0].accountSessionId);
    if (live != null) live.resumeAttempts += 1;
    return { session: { ...candidates[0] } };
  }

  /**
   * Attach a new TCP transport to an EXISTING session. It does not create an
   * identity: the session, its userid and its completed-initialization state all
   * survive, and only the connection changes.
   */
  resume({ accountSessionId, connectionRef, sequence = null }) {
    this.#sweep();
    const session = this.#sessions.get(accountSessionId);
    if (session == null) {
      throw new AccountSessionError('UNKNOWN_ACCOUNT_SESSION', 'account session is not live');
    }
    if (session.initializationCompletedAtMs == null) {
      throw new AccountSessionError(
        'SESSION_NOT_RESUMABLE',
        'this session never completed a lobby initialization'
      );
    }
    if (session.claimedByConnection != null) {
      throw new AccountSessionError(
        'ACCOUNT_SESSION_ALREADY_CLAIMED',
        'this session is already attached to a live connection'
      );
    }
    session.claimedByConnection = connectionRef;
    session.claimedAtMs = this.#clock();
    session.lastSeenAtMs = session.claimedAtMs;
    session.resumeCount += 1;
    if (sequence != null) session.lastResumeSequence = sequence;
    this.#unclaimed.delete(accountSessionId);
    this.#byConnection.set(connectionRef, accountSessionId);
    return { ...session };
  }

  /** Release a claim, e.g. when the lobby connection closes. */
  releaseClaim(connectionRef) {
    const id = this.#byConnection.get(connectionRef);
    if (id == null) return null;
    this.#byConnection.delete(connectionRef);
    const session = this.#sessions.get(id);
    if (session == null) return null;
    session.claimedByConnection = null;
    session.claimedAtMs = null;
    session.lastSeenAtMs = this.#clock();
    this.#unclaimed.add(id);
    return { ...session };
  }

  touch(accountSessionId) {
    const session = this.#sessions.get(accountSessionId);
    if (session == null) return null;
    session.lastSeenAtMs = this.#clock();
    return { ...session };
  }

  remove(accountSessionId) {
    const session = this.#sessions.get(accountSessionId);
    if (session == null) return false;
    this.#forget(accountSessionId, session);
    return true;
  }

  /**
   * The ONE place a session is ever forgotten. Displacement, expiry, explicit
   * removal and shutdown all funnel through here, so the release hook fires
   * EXACTLY ONCE per session on every path - which is what makes the owned
   * LobbySession and its projection deterministically releasable rather than
   * dependent on someone remembering to call a cleanup at each site.
   */
  #forget(id, session) {
    if (!this.#sessions.has(id)) return false;
    this.#sessions.delete(id);
    this.#unclaimed.delete(id);
    if (this.#byUserId.get(session.userid) === id) this.#byUserId.delete(session.userid);
    if (session.claimedByConnection != null) this.#byConnection.delete(session.claimedByConnection);
    try {
      this.#onSessionReleased?.({ ...session });
    } catch {
      // A failing release hook must never leave a dead session in the table.
    }
    return true;
  }

  /** Drop every session, e.g. at shutdown. Each gets its release hook once. */
  clear() {
    for (const [id, session] of [...this.#sessions]) this.#forget(id, session);
  }

  /** Run the expiry sweep now, bypassing the rate limit. For the cleanup timer. */
  sweepNow() {
    this.#lastSweepMs = 0;
    this.#sweep();
  }

  #sweep() {
    const now = this.#clock();
    // Sweeping is O(n), so it runs at most once a second rather than on every
    // lookup. With hundreds of players and a lookup per lobby connection the
    // per-call scan was the hot path.
    if (now - this.#lastSweepMs < SWEEP_INTERVAL_MS) return;
    this.#lastSweepMs = now;
    const cutoff = now - this.#ttlMs;
    for (const [id, session] of this.#sessions) {
      if (session.lastSeenAtMs <= cutoff) this.#forget(id, session);
    }
  }
}
