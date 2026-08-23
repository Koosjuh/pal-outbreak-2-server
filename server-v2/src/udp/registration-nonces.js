import crypto from 'node:crypto';

import { REGISTRATION_NONCE_BYTES } from '../protocol/snap-udp-register-codec.js';

/**
 * Pending registrations, keyed BY THE NONCE.
 *
 * ## Why the nonce is the primary key
 *
 * Everything else a bind carries is client-supplied and replayable: the source
 * address and port, the endpoint token (which is only
 * `(3rd octet << 24) | (4th octet << 16) | localPort` of the client's own LAN
 * address - a truncated routing hint whose collision domain is any two LANs
 * sharing their last two octets), and the endpoint name (the account handle).
 * None of them is a proof of anything.
 *
 * The register-reply tail blob is the only value in this exchange the server
 * chooses and the client returns. `FUN_001d9678` copies it to `conn+0xac`
 * without inspecting it; `FUN_001d6ee0` copies the connection template, which
 * contains it, into the bind body. Written at exactly one site in the client,
 * read at exactly one site, then dead: an opaque cookie.
 *
 * THE ECHO IS OBSERVED, as of the T33 rig run of 2026-08-06. An unmodified
 * retail client echoed a server-minted nonce back in its bind:
 * `captures/v2-live/t33-run11-nonce-echo.pcap`, where the 16 bytes appear in
 * cleartext exactly once, in the client's bind. The nonce now defaults ON
 * (`config/server-config.js`) and `udp/register-service.js`,
 * `sessions/account-session.js` and `app/application.js` all treat the echo as
 * the bind's attachment proof.
 *
 * The older note here said the echo had never been seen and must not be
 * promoted without a capture. That was right when it was written - every
 * archived V1 bind carries zeros at wire +0x34, which is equally consistent
 * with an echo of V1's own length-0 tail - and the capture it demanded is the
 * one cited above. It is kept, corrected rather than deleted, because the
 * distinction it drew is what made T33 a gate instead of an assumption.
 *
 * So the nonce IS the identity of a pending registration, and the source
 * address, port and token are demoted to what they actually are: telemetry and
 * rate-limit context. Keying on any of them is what breaks two players behind
 * one NAT, and it is what V1 did - its UDP table was NAT-survivable but its
 * UDP-to-TCP handoff dropped the port and resolved newest-wins per IP, so
 * player A's connection received player B's identity. That was specified
 * behaviour in V1, not a race.
 *
 * ## What this deliberately does NOT do
 *
 * It never falls back to the source address when a nonce is absent, unknown or
 * expired. A fallback would reintroduce exactly the ambiguity the nonce exists
 * to remove, and it would do so on the failure path - the one that gets least
 * testing and most attacker attention.
 */

export class RegistrationNonceError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'RegistrationNonceError';
    this.code = code;
  }
}

/** Refusal reasons. Distinct so a rig log always says which one happened. */
export const NONCE_REFUSAL = Object.freeze({
  ABSENT: 'the bind carried no tail blob',
  MALFORMED: 'the bind tail is not a well-formed nonce',
  UNKNOWN: 'no pending registration holds this nonce',
  EXPIRED: 'the pending registration for this nonce has expired',
  CONSUMED: 'this nonce has already been bound and its retransmission window has closed'
});

const DEFAULT_TTL_MS = 60_000;
/**
 * How long after a successful bind a byte-identical retransmission is still
 * answered. The bind is sent UNRELIABLE and one-shot (`FUN_001d7104`), so the
 * client has no retransmit of its own - but the network does duplicate, and a
 * duplicate must be answered identically rather than refused. Bounded, so a
 * captured bind cannot be replayed indefinitely.
 */
const DEFAULT_RETRANSMISSION_WINDOW_MS = 5_000;
const DEFAULT_MAXIMUM_PENDING = 4096;

export class RegistrationNonceTable {
  #pending = new Map();
  #ttlMs;
  #retransmissionWindowMs;
  #maximum;
  #clock;
  #randomBytes;

  constructor({
    ttlMs = DEFAULT_TTL_MS,
    retransmissionWindowMs = DEFAULT_RETRANSMISSION_WINDOW_MS,
    maximum = DEFAULT_MAXIMUM_PENDING,
    clock = () => Date.now(),
    randomBytes = (size) => crypto.randomBytes(size)
  } = {}) {
    this.#ttlMs = ttlMs;
    this.#retransmissionWindowMs = retransmissionWindowMs;
    this.#maximum = maximum;
    this.#clock = clock;
    this.#randomBytes = randomBytes;
  }

  get size() {
    return this.#pending.size;
  }

  clock() {
    return this.#clock();
  }

  /**
   * Mint a nonce for a registration.
   *
   * `handle` is the authenticated account this registration is FOR. The address,
   * port and token are recorded as metadata and are never consulted to resolve
   * a bind.
   */
  issue({ handle, sourceAddress, sourcePort, endpointToken, epoch }) {
    if (typeof handle !== 'string' || handle.length === 0) {
      throw new RegistrationNonceError('HANDLE_REQUIRED', 'handle must be a non-empty string');
    }
    this.sweep();
    if (this.#pending.size >= this.#maximum) {
      // Fail closed. Evicting a live pending registration to make room would let
      // a flood displace a player who is mid-handshake.
      throw new RegistrationNonceError(
        'PENDING_CAPACITY',
        `refusing to mint: ${this.#pending.size} pending registrations already`
      );
    }

    // Uniqueness against LIVE pending registrations. At 128 bits a collision is
    // not a practical concern; the check is here because "not a practical
    // concern" is how collisions ship.
    let nonce;
    for (let attempt = 0; attempt < 4; attempt += 1) {
      const candidate = this.#randomBytes(REGISTRATION_NONCE_BYTES);
      if (!Buffer.isBuffer(candidate) || candidate.length !== REGISTRATION_NONCE_BYTES) {
        throw new RegistrationNonceError(
          'RANDOM_SOURCE',
          `randomBytes must return ${REGISTRATION_NONCE_BYTES} bytes`
        );
      }
      if (!this.#pending.has(candidate.toString('hex'))) {
        nonce = candidate;
        break;
      }
    }
    if (nonce == null) {
      throw new RegistrationNonceError(
        'RANDOM_SOURCE',
        'could not mint a unique nonce; the random source is not behaving'
      );
    }

    const issuedAtMs = this.#clock();
    this.#pending.set(nonce.toString('hex'), {
      nonce: Buffer.from(nonce),
      handle,
      // Telemetry and rate-limit context ONLY. Never a resolution key.
      sourceAddress: sourceAddress ?? null,
      sourcePort: sourcePort ?? null,
      // Protocol metadata only - it is a routing hint, not an identifier.
      endpointToken: endpointToken ?? null,
      epoch: epoch ?? null,
      issuedAtMs,
      expiresAtMs: issuedAtMs + this.#ttlMs,
      boundAtMs: null
    });
    return Buffer.from(nonce);
  }

  /**
   * Resolve a bind's echoed tail to its registration.
   *
   * Returns `{ registration, retransmission }` or `{ refusal }`. Never throws on
   * client input, and never resolves by anything but the nonce.
   */
  consume(blob) {
    /*
     * Deliberately does NOT sweep first. Sweeping would delete an expired
     * record before the lookup and turn a precise EXPIRED refusal into a vague
     * UNKNOWN one - and on the rig those mean very different things: EXPIRED
     * says the handshake was too slow, UNKNOWN says the nonce was never ours.
     * Expiry is evaluated explicitly below and the record is dropped there;
     * `issue()` sweeps, and the table is bounded regardless.
     */
    if (blob == null || !Buffer.isBuffer(blob) || blob.length === 0) {
      return { refusal: NONCE_REFUSAL.ABSENT };
    }
    if (blob.length !== REGISTRATION_NONCE_BYTES) {
      return { refusal: NONCE_REFUSAL.MALFORMED };
    }

    /*
     * Constant-time comparison. The Map lookup below is not constant time and
     * cannot be - but the SECRET comparison is, so a timing signal cannot be
     * used to recover a nonce byte by byte. The lookup only reveals whether
     * some registration exists, which a caller learns from the refusal anyway.
     */
    const record = this.#pending.get(blob.toString('hex'));
    if (record == null) return { refusal: NONCE_REFUSAL.UNKNOWN };
    if (!crypto.timingSafeEqual(record.nonce, blob)) {
      return { refusal: NONCE_REFUSAL.UNKNOWN };
    }

    const now = this.#clock();
    if (now >= record.expiresAtMs) {
      this.#pending.delete(blob.toString('hex'));
      return { refusal: NONCE_REFUSAL.EXPIRED };
    }

    if (record.boundAtMs != null) {
      // Already bound. A duplicate within the window is answered identically -
      // the bind is unreliable and one-shot, so a duplicate is the network's
      // doing, not the client's, and refusing it would strand a real player.
      if (now - record.boundAtMs <= this.#retransmissionWindowMs) {
        return { registration: this.#exposed(record), retransmission: true };
      }
      return { refusal: NONCE_REFUSAL.CONSUMED };
    }

    record.boundAtMs = now;
    return { registration: this.#exposed(record), retransmission: false };
  }

  /**
   * A caller-safe view. `{ ...record }` hands out the LIVE nonce buffer, and a
   * caller zeroing it desynchronises the record from its Map key - every later
   * legitimate retransmission would then refuse as UNKNOWN.
   */
  #exposed(record) {
    return { ...record, nonce: Buffer.from(record.nonce) };
  }

  /** Drop pending registrations past their expiry, and consumed ones past their window. */
  sweep() {
    const now = this.#clock();
    const removed = [];
    for (const [key, record] of this.#pending) {
      const deadline = record.boundAtMs == null
        ? record.expiresAtMs
        : Math.max(record.expiresAtMs, record.boundAtMs + this.#retransmissionWindowMs);
      if (now >= deadline) removed.push(key);
    }
    for (const key of removed) this.#pending.delete(key);
    return removed.length;
  }

  /** Live pending nonces as hex. Test support only - never a protocol path. */
  pendingNoncesForTest() {
    return [...this.#pending.keys()];
  }

  /** Drop everything. Used when a listener restarts and its epochs are void. */
  clear() {
    this.#pending.clear();
  }
}
