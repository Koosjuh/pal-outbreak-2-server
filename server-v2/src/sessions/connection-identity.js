import { AccountSessionRegistry } from './account-session.js';

/** Holders of a single DNAS token. One static asset means everyone shares one. */
const MAXIMUM_HOLDERS_PER_TOKEN = 512;

import crypto from 'node:crypto';

/**
 * LOBBY TRANSPORT SESSIONS — layer 3 of three. See `account-session.js` for the
 * other two and for why they are kept apart.
 *
 * CONNECTION identity is per TCP socket. The server mints it; the client never
 * sends it. It carries no player meaning at all.
 *
 * PLAYER identity comes from the GAME-ACCOUNT SESSION this connection claims,
 * which the UDP-9090 register/bind or an HTTP login established. That, and
 * nothing else, is what authenticates a connection.
 *
 * ## The DNAS token is NOT an identity, and this file used to say it was
 *
 * The header here previously read: "AUTHENTICATED SESSION identity is the DNAS
 * token the client itself presents ... it is bound to the account, not to a
 * console or an address." That is refuted. T27 established, and direct
 * verification confirmed, that the 32 bytes come out of a canned DNAS reply
 * asset THIS SERVER sends (`packets/b198010bd61490f8_01088008` at `+0x2d`).
 * Every console that completes DNAS against V2 therefore receives the identical
 * value. R-020's observation - the same token on both transports for one login -
 * was real; the conclusion drawn from it was not.
 *
 * Keying identity on it made the browser the only route into the lobby, which a
 * client whose memory card already holds an account never takes, and it would
 * have refused player two.
 *
 * The token is still tracked, because knowing which token a session presented is
 * useful, and MULTIPLE accounts may legitimately share one. It never resolves a
 * connection to an account and it never breaks a tie.
 *
 * ## Source address
 *
 * Never an identity. It is a NECESSARY correlation filter - a session is only a
 * candidate for a connection from where it was authenticated - and nothing more.
 * Two eligible sessions behind one address are refused rather than told apart.
 * That is a real limitation for two consoles behind one NAT, and it is preferred
 * to guessing which player a connection belongs to.
 */

const DNAS_TOKEN_BYTES = 32;

export class ConnectionIdentityError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'ConnectionIdentityError';
    this.code = code;
  }
}

/**
 * Canonicalize a presented DNAS token.
 *
 * Accepts the base64 form the client sends on both HTTP and TCP, or the raw
 * 32 bytes. Rejects anything that is not exactly 32 bytes so a truncated or
 * padded value can never alias another session.
 */
export function normalizeDnasToken(value) {
  let raw;
  if (Buffer.isBuffer(value)) {
    raw = value;
  } else if (typeof value === 'string') {
    const text = value.trim();
    if (!/^[A-Za-z0-9+/]+={0,2}$/.test(text)) {
      throw new ConnectionIdentityError('DNAS_TOKEN_FORMAT', 'DNAS token is not base64');
    }
    raw = Buffer.from(text, 'base64');
    // Buffer.from is permissive; require a faithful round trip.
    if (raw.toString('base64') !== text) {
      throw new ConnectionIdentityError('DNAS_TOKEN_FORMAT', 'DNAS token is not canonical base64');
    }
  } else {
    throw new ConnectionIdentityError('DNAS_TOKEN_FORMAT', 'DNAS token must be a string or Buffer');
  }
  if (raw.length !== DNAS_TOKEN_BYTES) {
    throw new ConnectionIdentityError(
      'DNAS_TOKEN_LENGTH',
      `DNAS token must be ${DNAS_TOKEN_BYTES} bytes, got ${raw.length}`
    );
  }
  return raw.toString('base64');
}

/** Constant-time compare of two canonical tokens. */
function tokensMatch(left, right) {
  const a = Buffer.from(left, 'base64');
  const b = Buffer.from(right, 'base64');
  return a.length === b.length && crypto.timingSafeEqual(a, b);
}

export class ConnectionIdentityRegistry {
  #clock;
  #connections = new Map();
  #tokenToSession = new Map();
  #sessionLookup;
  #accountSessions;
  #maxConnections;
  #maxTokenBindings;
  #tokenBindingTtlMs;
  #nextConnectionId = 1n;

  /**
   * @param sessionLookup  (sessionConnectionId) => session|null. The HTTP-owned
   *   session store. Required: without it no connection can ever be associated,
   *   and this registry must not invent an authenticated state.
   */
  constructor({
    sessionLookup,
    accountSessions = null,
    clock = () => Date.now(),
    // Hundreds of concurrent players, each with a lobby connection and possibly
    // a resume connection in flight.
    maxConnections = 8192,
    maxTokenBindings = 8192,
    // Long enough for a player to finish the browser flow and let the game open
    // its lobby connection; short enough that an observed token stops being
    // useful quickly. Not a protocol value.
    tokenBindingTtlMs = 15 * 60 * 1000
  } = {}) {
    if (typeof sessionLookup !== 'function') {
      throw new TypeError('sessionLookup is required');
    }
    if (!Number.isSafeInteger(maxConnections) || maxConnections <= 0) {
      throw new TypeError('maxConnections must be a positive integer');
    }
    if (!Number.isSafeInteger(maxTokenBindings) || maxTokenBindings <= 0) {
      throw new TypeError('maxTokenBindings must be a positive integer');
    }
    if (!Number.isSafeInteger(tokenBindingTtlMs) || tokenBindingTtlMs <= 0) {
      throw new TypeError('tokenBindingTtlMs must be a positive integer');
    }
    this.#sessionLookup = sessionLookup;
    this.#accountSessions = accountSessions ?? new AccountSessionRegistry({ clock });
    this.#clock = clock;
    this.#maxConnections = maxConnections;
    this.#maxTokenBindings = maxTokenBindings;
    this.#tokenBindingTtlMs = tokenBindingTtlMs;
  }

  get openConnectionCount() {
    return this.#connections.size;
  }

  get boundTokenCount() {
    return this.#tokenToSession.size;
  }

  /**
   * Record that an authenticated HTTP session presented this DNAS token. Called
   * from the HTTP flow, which is where the token is first observed.
   */
  bindDnasToken({ dnasToken, sessionConnectionId }) {
    const token = normalizeDnasToken(dnasToken);
    if (typeof sessionConnectionId !== 'string' || sessionConnectionId.length === 0) {
      throw new ConnectionIdentityError(
        'SESSION_ID_REQUIRED',
        'sessionConnectionId must be a non-empty string'
      );
    }
    this.#sweepExpiredBindings();

    const existing = this.#tokenToSession.get(token) ?? [];
    // Bound the PER-TOKEN list too. With one static asset every login shares a
    // single token, so without this the map stays size 1 while its one array
    // grows without limit - and every association then scans it.
    if (existing.length >= MAXIMUM_HOLDERS_PER_TOKEN) {
      throw new ConnectionIdentityError(
        'TOKEN_BINDING_LIMIT',
        `refusing to track more than ${MAXIMUM_HOLDERS_PER_TOKEN} holders of one DNAS token`
      );
    }
    if (existing.length === 0 && this.#tokenToSession.size >= this.#maxTokenBindings) {
      throw new ConnectionIdentityError(
        'TOKEN_BINDING_LIMIT',
        `refusing to track more than ${this.#maxTokenBindings} DNAS token bindings`
      );
    }

    // MULTIPLE accounts may hold the same token, and this is not a conflict.
    // V2 mints the token from a static DNAS replay asset, so every console
    // receives the identical value (T27, OQ-022). Refusing the second holder -
    // which is what this did before - would have rejected player two.
    //
    // The token therefore records WHICH TOKEN a session presented, and is never
    // what resolves a connection to an account. That is the account session's
    // job; see `account-session.js`.
    const withoutThisSession = existing.filter(
      (binding) => binding.sessionConnectionId !== sessionConnectionId
    );
    withoutThisSession.push({ sessionConnectionId, boundAtMs: this.#clock() });
    this.#tokenToSession.set(token, withoutThisSession);
    return token;
  }

  /**
   * Drop bindings past their lifetime, and any whose session has gone.
   *
   * A binding is a standing invitation for a TCP connection to claim an account,
   * so it must not outlive the login that created it. This is an implementation
   * security control: no capture establishes how long the original service kept
   * one, only that the client presents the same token on both transports.
   */
  #sweepExpiredBindings() {
    const now = this.#clock();
    for (const [token, bindings] of this.#tokenToSession) {
      const live = bindings.filter(
        (binding) => now - binding.boundAtMs <= this.#tokenBindingTtlMs
      );
      if (live.length === 0) this.#tokenToSession.delete(token);
      else if (live.length !== bindings.length) this.#tokenToSession.set(token, live);
    }
  }

  /**
   * Forget ONE holder's token binding, e.g. on logout.
   *
   * Deleting the whole token entry - which this used to do - would drop every
   * other account that legitimately shares it, and under the static replay asset
   * that is every player.
   */
  releaseDnasToken(dnasToken, sessionConnectionId = null) {
    const token = normalizeDnasToken(dnasToken);
    const bindings = this.#tokenToSession.get(token);
    if (bindings == null) return false;
    if (sessionConnectionId == null) {
      return this.#tokenToSession.delete(token);
    }
    const remaining = bindings.filter(
      (binding) => binding.sessionConnectionId !== sessionConnectionId
    );
    if (remaining.length === bindings.length) return false;
    if (remaining.length === 0) this.#tokenToSession.delete(token);
    else this.#tokenToSession.set(token, remaining);
    return true;
  }

  /**
   * Open a connection identity. It starts anonymous: the captured client does
   * not present anything identifying until `0x1007`, and its later connections
   * never do.
   */
  openConnection({ remote } = {}) {
    if (this.#connections.size >= this.#maxConnections) {
      throw new ConnectionIdentityError(
        'CONNECTION_LIMIT',
        `refusing more than ${this.#maxConnections} concurrent connection identities`
      );
    }
    const connectionRef = `c${this.#nextConnectionId}`;
    this.#nextConnectionId += 1n;
    this.#connections.set(connectionRef, {
      connectionRef,
      // Diagnostics only. Never a lookup key.
      remote: remote == null ? null : { ...remote },
      openedAtMs: this.#clock(),
      dnasToken: null,
      sessionConnectionId: null,
      userid: null
    });
    return connectionRef;
  }

  closeConnection(connectionRef) {
    // Release the account-session claim too, or a dropped lobby connection
    // would strand the session as permanently claimed and the player could
    // never reconnect without registering again.
    this.#accountSessions.releaseClaim(connectionRef);
    return this.#connections.delete(connectionRef);
  }

  get(connectionRef) {
    const record = this.#connections.get(connectionRef);
    return record == null ? null : { ...record };
  }

  /**
   * Associate an open connection with the authenticated session that presented
   * the same DNAS token. Fails closed: an unknown token, a token whose session
   * has expired or vanished, or a second, conflicting association all throw.
   */
  associateConnection({ connectionRef, dnasToken }) {
    const record = this.#connections.get(connectionRef);
    if (record == null) {
      throw new ConnectionIdentityError('UNKNOWN_CONNECTION', 'connection identity is not open');
    }
    const token = normalizeDnasToken(dnasToken);

    if (record.dnasToken != null) {
      if (!tokensMatch(record.dnasToken, token)) {
        throw new ConnectionIdentityError(
          'CONNECTION_TOKEN_CONFLICT',
          'connection already presented a different DNAS token'
        );
      }
      return { ...record };
    }

    this.#sweepExpiredBindings();

    // THE GAME-ACCOUNT SESSION IS WHAT AUTHENTICATES. The UDP-9090 register
    // reply is Blowfish-keyed on the account password and the client only
    // continues to the bind if it decrypts under the password IT holds, so a
    // completed bind proves both ends share that password. The DNAS token
    // proves nothing: we mint it ourselves from a static replay asset, so every
    // console presents the same value (T27).
    //
    // The token is still USED - as a correlation signal to narrow an otherwise
    // ambiguous set, and recorded on the session afterwards - but it can never
    // grant one on its own.
    const resolution = this.#accountSessions.resolveForLobby({
      sourceAddress: record.remote?.address ?? null
    });
    if (resolution.refusal != null) {
      throw new ConnectionIdentityError(resolution.code, resolution.refusal);
    }

    const claimed = this.#accountSessions.claim({
      accountSessionId: resolution.session.accountSessionId,
      connectionRef,
      dnasToken: token
    });

    record.dnasToken = token;
    record.accountSessionId = claimed.accountSessionId;
    record.userid = claimed.userid;
    // `sessionConnectionId` names an HTTP session and NOTHING ELSE. Putting an
    // account-session id here made `requirePlayer` throw for every player who
    // arrived by UDP, because it feeds this field to the HTTP session lookup.
    // Two id namespaces must not share one field. It stays null when the
    // browser flow was not used; the connection is still fully authenticated,
    // which `isAuthenticated` and `requirePlayer` now judge by `userid`.
    const httpSession = this.#findHttpSessionForUserId(claimed.userid, token);
    record.sessionConnectionId = httpSession?.connectionId ?? null;
    return { ...record };
  }

  /**
   * The live HTTP session for an account, if the browser flow ran. Used only to
   * keep the existing HTTP path working: anything keyed on `sessionConnectionId`
   * continues to resolve. It is NOT consulted to decide identity.
   */
  #findHttpSessionForUserId(userid, token) {
    for (const binding of this.#tokenToSession.get(token) ?? []) {
      const session = this.#sessionLookup(binding.sessionConnectionId);
      if (session != null && session.userid === userid) return session;
    }
    return null;
  }

  /** The account-session registry this identity model resolves against. */
  get accountSessions() {
    return this.#accountSessions;
  }

  /**
   * Attach a RESUME connection to the session whose initialization already
   * completed. R-019: the client resets after `0x1004` and reopens on a fresh
   * source port whose first frame is `0x6501`.
   *
   * This binds a new transport to an EXISTING identity. It never creates one,
   * so a resume cannot be a second, weaker way into an account: only a session
   * that actually completed an initialization is a candidate.
   */
  associateResumeConnection({ connectionRef, sequence = null }) {
    const record = this.#connections.get(connectionRef);
    if (record == null) {
      throw new ConnectionIdentityError('UNKNOWN_CONNECTION', 'connection identity is not open');
    }
    const resolution = this.#accountSessions.resolveForResume({
      sourceAddress: record.remote?.address ?? null,
      sequence
    });
    if (resolution.refusal != null) {
      throw new ConnectionIdentityError(resolution.code, resolution.refusal);
    }
    const resumed = this.#accountSessions.resume({
      accountSessionId: resolution.session.accountSessionId,
      connectionRef,
      sequence
    });
    record.accountSessionId = resumed.accountSessionId;
    record.userid = resumed.userid;
    record.resumed = true;
    return { ...record };
  }

  /** Mark this connection's session as having completed lobby initialization. */
  markInitializationComplete(connectionRef, options = {}) {
    return this.#accountSessions.markInitializationComplete(connectionRef, options);
  }

  /** True once a connection carries a valid authenticated session. */
  isAuthenticated(connectionRef) {
    const record = this.#connections.get(connectionRef);
    // Authenticated means "carries an account identity". An HTTP session is not
    // required: a player who arrived through the UDP register has one without
    // ever opening the browser.
    return record != null && record.userid != null;
  }

  /**
   * Player identity for a connection. Fails closed rather than returning a
   * placeholder, so no caller can accidentally act for an unidentified player.
   *
   * Note that the captured later connections are legitimately anonymous: they
   * only walk the server list, which is server-global data. Anonymous
   * connections are therefore allowed to exist, but nothing player-specific may
   * be served to them.
   */
  requirePlayer(connectionRef) {
    const record = this.#connections.get(connectionRef);
    if (record == null) {
      throw new ConnectionIdentityError('UNKNOWN_CONNECTION', 'connection identity is not open');
    }
    if (record.userid == null) {
      throw new ConnectionIdentityError(
        'UNAUTHENTICATED_CONNECTION',
        'connection has no authenticated session; player identity is unavailable'
      );
    }
    // The account session is the identity. The HTTP session id is reported when
    // there is one, and its absence is not an error - it only means this player
    // did not arrive through the browser.
    return {
      userid: record.userid,
      accountSessionId: record.accountSessionId ?? null,
      sessionConnectionId: record.sessionConnectionId ?? null
    };
  }
}
