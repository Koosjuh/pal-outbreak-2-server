/**
 * Live UDP register sessions: which source address has completed a register,
 * and as which login identity.
 *
 * WHY: the post-register bind (opcode `0x01`) carries NO credential. Its only
 * identity-bearing field is the endpoint name, which is the login identity with
 * a trailing dash - client-supplied, so it proves nothing. The REGISTER is what
 * authenticated, because only a server holding the account password could have
 * produced a `0x2d` body the client accepted. This table is what lets the bind
 * inherit that proof instead of creating a second, unauthenticated identity path.
 *
 * IMPORTANT - this is an implementation security control, NOT captured
 * behaviour. V1 kept no such table and answered any bind it received. Recorded
 * plainly so nobody later mistakes it for protocol. If a real client is ever
 * refused because of it, that is a V2 policy decision to revisit, not a client
 * bug.
 *
 * Sessions are keyed on transport identity - source address, source port - and
 * additionally required to present the endpoint token the register carried. The
 * token encodes the client's own IPv4 low half and UDP port (`FUN_001d46ec`), so
 * it is not a secret; it is a consistency check, not a bearer credential. The
 * security comes from the source binding plus the register having succeeded.
 *
 * The login identity is the account key. The display name is never used here.
 */

const DEFAULT_TTL_MS = 5 * 60 * 1000;
// Sized for hundreds of concurrent players registering and re-registering.
const DEFAULT_MAXIMUM = 4096;

export function sessionKey(address, port) {
  return `${address}:${port}`;
}

export class RegisterSessionTable {
  /**
   * @param {object} [options]
   * @param {number} [options.ttlMs] idle lifetime before a session is swept.
   * @param {number} [options.maximum] hard bound on concurrent sessions.
   * @param {() => number} [options.clock]
   */
  constructor({ ttlMs = DEFAULT_TTL_MS, maximum = DEFAULT_MAXIMUM, clock = () => Date.now() } = {}) {
    this.ttlMs = ttlMs;
    this.maximum = maximum;
    this.clock = clock;
    this.sessions = new Map();
  }

  get size() {
    return this.sessions.size;
  }

  /**
   * Record a completed register. A repeat register from the same source is a
   * legitimate client behaviour - the archived traces show the client
   * re-registering for the game phase - so it REFRESHES the session rather than
   * being refused.
   */
  register({ address, port, loginIdentity, endpointToken, latencyTicks = null }) {
    this.sweep();
    const key = sessionKey(address, port);
    if (!this.sessions.has(key) && this.sessions.size >= this.maximum) {
      // Bounded, and it fails closed: a full table refuses a NEW session rather
      // than evicting a live one, so a flood cannot displace a real player.
      return null;
    }
    const now = this.clock();
    const existing = this.sessions.get(key);
    const session = {
      key,
      address,
      port,
      loginIdentity,
      endpointToken,
      /*
       * `conn+0x510`, from the register's `LC` TLV. Recorded here because the
       * message that NEEDS it - the post-lobby snapshot, which starts the
       * keepalive - does not carry it, and the client's watchdog budget
       * (`LC * 32 + 4000`) must be the one the client declared rather than one
       * this server assumed. Null when the client sent no LC.
       */
      latencyTicks,
      registeredAtMs: existing?.registeredAtMs ?? now,
      lastSeenAtMs: now,
      registerCount: (existing?.registerCount ?? 0) + 1,
      boundAtMs: null,
      appAcknowledgedAtMs: null
    };
    this.sessions.set(key, session);
    return session;
  }

  /**
   * Resolve the session a datagram belongs to, or a reason it does not.
   *
   * @returns {{session: object} | {refusal: string}}
   */
  resolve({ address, port, endpointToken }) {
    this.sweep();
    const session = this.sessions.get(sessionKey(address, port));
    if (!session) {
      return { refusal: 'no completed register for this source address' };
    }
    if (endpointToken != null && session.endpointToken !== endpointToken) {
      // The token is derived from the client's own address and port, so a
      // mismatch means this is not the endpoint that registered. Refuse rather
      // than serve the session to a different endpoint.
      return { refusal: 'endpoint token does not match the registered session' };
    }
    session.lastSeenAtMs = this.clock();
    return { session };
  }

  markBound(session) {
    session.boundAtMs = this.clock();
    session.lastSeenAtMs = session.boundAtMs;
  }

  markAppAcknowledged(session) {
    session.appAcknowledgedAtMs = this.clock();
    session.lastSeenAtMs = session.appAcknowledgedAtMs;
  }

  /** Drop sessions idle beyond the TTL. Returns the keys removed. */
  sweep() {
    const cutoff = this.clock() - this.ttlMs;
    const expired = [];
    for (const [key, session] of this.sessions) {
      if (session.lastSeenAtMs <= cutoff) expired.push(key);
    }
    for (const key of expired) this.sessions.delete(key);
    return expired;
  }

  clear() {
    this.sessions.clear();
  }
}
