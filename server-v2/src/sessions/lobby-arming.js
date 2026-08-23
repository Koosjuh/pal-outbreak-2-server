/**
 * Which transcript a new TCP 10127 connection should receive.
 *
 * The server speaks first on this port, so the choice has to be made when the
 * socket is accepted, before the client says anything - it never says anything
 * first. The captures show two shapes:
 *
 * - BOOT AUTH: three server frames, `0x1001`/`0x1002`/`0x1004` at direction
 *   `0x02`, and the client sends nothing at all for the whole connection.
 * - LOBBY: one `0x6001` challenge at direction `0x10`, after which the client
 *   drives with `0x1007` or `0x6501`. The client ships a dedicated handler for
 *   that unsolicited frame: `SLES_533.19` receive-dispatch entry `0x0c` binds
 *   command `0x6001` direction `0x10` to `FUN_001c92d0`.
 *
 * V1 chose between them exactly this way (`server/snap_server.js:1657-1697`):
 * `getPendingOnline(socket.remoteAddress)` returns an arming record created by a
 * completed `POST /mhweb/lbs.jsp` (or a UDP 9090 register, or a post-lobby
 * resume); no record means boot auth. The real client accepted that behaviour,
 * which makes it known-good rather than a guess.
 *
 * ## Why keying on the remote address is acceptable HERE and nowhere else
 *
 * This registry selects a TRANSCRIPT. It never establishes identity, and it can
 * never grant any. A lobby connection still has to present a valid DNAS token in
 * its `0x1007` payload before `ConnectionIdentityRegistry` will associate it with
 * an authenticated session, and an unarmed address that somehow reached the
 * lobby transcript would simply fail that association closed.
 *
 * So the worst outcome of a wrong answer here is the wrong opening frame, which
 * the client either ignores or fails to act on - never a session belonging to
 * someone else. Identity stays keyed on the token, exactly as R-020 requires.
 *
 * The entries are bounded and short-lived so a stale arming cannot accumulate or
 * silently change how a much later connection is treated.
 */

export const CONNECTION_PURPOSE = Object.freeze({
  BOOT_AUTH: 'pre-browser',
  LOBBY: 'lobby-initialization'
});

export class LobbyArmingRegistry {
  #clock;
  #ttlMs;
  #maxEntries;
  #armed = new Map();

  constructor({
    clock = () => Date.now(),
    // A player moves from the lbs.jsp response to the game's lobby connection in
    // seconds. Minutes of slack, then the arming lapses back to boot auth.
    // 90 seconds. It has to cover the observed sequence - bind to lobby
    // connection is about 1 s, and the resume follows roughly 14 s after the
    // ladder completes - while being far too short to survive a console reboot.
    //
    // It was 5 minutes, and that caused a D907 regression: a player who
    // rebooted about 3 minutes after playing had their address still armed, so
    // the fresh boot's BOOT-AUTH connection was handed the lobby challenge
    // instead of the 0x1001/0x1002/0x1004 transcript, and the client refused it.
    ttlMs = 90 * 1000,
    // Hundreds of concurrent players. One entry per source address, so this is
    // the number of distinct consoles that may be mid-handover at once.
    maxEntries = 4096
  } = {}) {
    if (!Number.isSafeInteger(ttlMs) || ttlMs <= 0) {
      throw new TypeError('ttlMs must be a positive integer');
    }
    if (!Number.isSafeInteger(maxEntries) || maxEntries <= 0) {
      throw new TypeError('maxEntries must be a positive integer');
    }
    this.#clock = clock;
    this.#ttlMs = ttlMs;
    this.#maxEntries = maxEntries;
  }

  get size() {
    return this.#armed.size;
  }

  #sweep() {
    const now = this.#clock();
    for (const [address, record] of this.#armed) {
      if (now - record.armedAtMs > this.#ttlMs) this.#armed.delete(address);
    }
  }

  /**
   * Forget an arming, so the next connection from this address falls back to the
   * BOOT-AUTH transcript.
   *
   * Called when a console completes DNAS, which is the platform step that
   * precedes boot auth on a fresh start. A console that is doing DNAS is
   * starting over, so whatever we armed for its previous session is stale - and
   * serving the lobby challenge to a boot-auth connection is exactly the D907
   * this prevents.
   */
  disarm(address) {
    if (typeof address !== 'string' || address === '') return false;
    return this.#armed.delete(address);
  }

  /** Called when a completed lbs.jsp, or the UDP-9090 bind, hands the client its SN@P endpoint. */
  arm(address, details = {}) {
    if (typeof address !== 'string' || address === '') return null;
    this.#sweep();
    if (!this.#armed.has(address) && this.#armed.size >= this.#maxEntries) {
      // Bounded rather than unbounded: refuse quietly and let the connection
      // fall back to boot auth, which is the safe transcript.
      return null;
    }
    // MERGE rather than replace. A client can be armed twice by two different
    // sources - a completed `lbs.jsp` and then the UDP-9090 bind - and a
    // wholesale overwrite would silently drop whatever the first one recorded
    // (the HTTP path's `sessionConnectionId`, for instance). Nothing reads those
    // fields today, which is exactly why losing them would go unnoticed until
    // something did.
    const previous = this.#armed.get(address);
    const record = { ...previous, address, armedAtMs: this.#clock(), ...details };
    this.#armed.set(address, record);
    return record;
  }

  isArmed(address) {
    if (typeof address !== 'string' || address === '') return false;
    const record = this.#armed.get(address);
    if (record == null) return false;
    if (this.#clock() - record.armedAtMs > this.#ttlMs) {
      this.#armed.delete(address);
      return false;
    }
    return true;
  }

  /**
   * The purpose for a connection from this address. Unarmed means boot auth,
   * which is what the captured client receives on its first connection.
   */
  resolvePurpose(address) {
    return this.isArmed(address)
      ? CONNECTION_PURPOSE.LOBBY
      : CONNECTION_PURPOSE.BOOT_AUTH;
  }
}
