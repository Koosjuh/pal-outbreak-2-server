/**
 * The durable LOBBY SESSION: the state that belongs to a logical player in the
 * lobby, and outlives the TCP connection carrying it.
 *
 * ## Why this exists
 *
 * `ClientDirectoryProjection` used to be owned by the connection, built by
 * `createConnectionProviders` and dropped on close. The capture disproved that
 * ownership. On 2026-08-04 the client completed the ladder on port 1249,
 * reset, reopened on port 1250, and sent:
 *
 * ```
 * 0015 01 6510 00 00ff  01 000600f708781e72000a01ef1d09006f1f7e647f
 *                       ^^ count 1, then ONE 20-byte record key
 * ```
 *
 * That key was issued on port 1249. The client had retained its directory state
 * across the transport reset and was making a TARGETED fetch against it - not a
 * fresh walk. V2 had minted an empty projection for the new connection, so the
 * key matched nothing and the provider failed closed with
 * `0x6510 is not expected during record-delivery`. V2 sent FIN, and the player
 * saw "could not connect to lobby server" and then D907.
 *
 * So the projection is session state, not connection state.
 *
 * ## The ownership boundary
 *
 * SESSION-owned, and reattached across a resume:
 *   - the account/player identity reference
 *   - initialization-completed state
 *   - the ClientDirectoryProjection, including record/key allocation and the
 *     `0x6510` correlation state
 *   - resume eligibility and expiry
 *   - which transport currently owns the session
 *
 * TRANSPORT-owned, and rebuilt per connection: the frame parser, the stream
 * buffer, socket timeouts, and the per-connection ladder state machine. Those
 * describe a socket, not a player.
 *
 * ## One transport at a time
 *
 * A lobby session has at most one owning transport. A successful resume
 * SUPERSEDES the previous one, which is what lets a client that reset reconnect
 * without waiting for us to notice the old socket died. The superseded
 * transport is reported so the caller can close it, and it can no longer reach
 * the session.
 */

export class LobbySessionError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'LobbySessionError';
    this.code = code;
  }
}

let nextLobbySessionSerial = 1;

export class LobbySession {
  #projection;
  #clock;

  constructor({ accountSessionId, userid, projection, clock = () => Date.now() }) {
    if (projection == null) throw new TypeError('a ClientDirectoryProjection is required');
    this.lobbySessionId = `ls-${nextLobbySessionSerial++}`;
    this.accountSessionId = accountSessionId ?? null;
    this.userid = userid ?? null;
    this.#projection = projection;
    this.#clock = clock;
    this.createdAtMs = clock();
    this.lastActivityAtMs = this.createdAtMs;
    this.initializationCompletedAtMs = null;
    this.transportRef = null;
    this.resumeCount = 0;
    this.terminated = false;
  }

  /**
   * The one projection this session owns. Never rebuilt, never cloned: a resume
   * hands back this exact object, which is the whole point.
   */
  get projection() {
    if (this.terminated) {
      throw new LobbySessionError('LOBBY_SESSION_TERMINATED', 'lobby session has been released');
    }
    return this.#projection;
  }

  /** True once released. A stale reference must not resurrect it. */
  get released() {
    return this.terminated;
  }

  attachTransport(transportRef) {
    if (this.terminated) {
      throw new LobbySessionError('LOBBY_SESSION_TERMINATED', 'lobby session has been released');
    }
    const superseded = this.transportRef != null && this.transportRef !== transportRef
      ? this.transportRef
      : null;
    this.transportRef = transportRef;
    this.lastActivityAtMs = this.#clock();
    return { superseded };
  }

  /** True only for the transport that currently owns the session. */
  ownsTransport(transportRef) {
    return !this.terminated && this.transportRef === transportRef;
  }

  detachTransport(transportRef) {
    // A superseded transport closing later must NOT clear the live one.
    if (this.transportRef !== transportRef) return false;
    this.transportRef = null;
    this.lastActivityAtMs = this.#clock();
    return true;
  }

  markInitializationComplete() {
    this.initializationCompletedAtMs = this.#clock();
    this.lastActivityAtMs = this.initializationCompletedAtMs;
  }

  get resumable() {
    return !this.terminated && this.initializationCompletedAtMs != null;
  }

  touch() {
    this.lastActivityAtMs = this.#clock();
  }

  /**
   * Release the retained projection. After this the session is inert and its
   * projection cannot be reached, so a stale reference cannot keep serving.
   */
  terminate() {
    if (this.terminated) return false;
    this.terminated = true;
    this.transportRef = null;
    this.#projection?.close?.();
    this.#projection = null;
    return true;
  }
}
