import crypto from 'node:crypto';

import { DnasPacketStoreError } from './packet-store.js';

/**
 * A DNAS packet store that gives each request its own platform-session token.
 *
 * ## Why
 *
 * V2 replays canned DNAS replies. One of the records in those replies carries
 * the 32-byte value the client afterwards presents as `?DNAS=` and inside the
 * TCP-10127 `0x1007` payload. Because the asset is static, EVERY console
 * receives the identical token, which is why it identifies nobody (T27,
 * OQ-022/OQ-023).
 *
 * The client never validates it: `0x35ba00` is written by the DNAS server, read
 * only as the source of two base64 encodings, and never compared - unlike the
 * UDP register reply, which the client does `strcmp`. So the server may choose
 * the value freely, and a per-session token costs nothing on the client side.
 *
 * ## What this does, and deliberately does not do
 *
 * It COPIES the stored reply and rewrites exactly the 32 bytes of that one
 * record. The asset on disk is never modified. Every other byte, including the
 * record tag, the length byte, the game id and the trailing structure, is passed
 * through untouched - so if the reply turns out to carry an integrity check over
 * that field, the failure will be the client rejecting DNAS rather than this
 * module silently corrupting something.
 *
 * It does NOT make the token an identity key. Whether a proven-distinct token
 * may narrow a set of candidate account sessions is a separate decision with its
 * own risk: review has already demonstrated one privilege escalation from
 * letting the token break a tie. See `account-session.js`.
 *
 * ## The record
 *
 * ```
 * 01 00 00 00   record tag
 * 20            blob length, 32
 * <32 bytes>    the token
 * ```
 *
 * Verified in `packets/b198010bd61490f8_01088008` at `+0x28`, whose 32 bytes
 * base64-encode to the exact value the real client presented.
 */

/** `01 00 00 00 20` - the record tag followed by a 32-byte length. */
const TOKEN_RECORD_PREFIX = Buffer.from([0x01, 0x00, 0x00, 0x00, 0x20]);
export const DNAS_TOKEN_BYTES = 32;

/**
 * Every offset in `packet` where the token record begins, i.e. the offset of the
 * first token byte. Exported so a caller can inspect an asset without rewriting
 * it.
 */
export function findTokenRecordOffsets(packet) {
  const offsets = [];
  let from = 0;
  for (;;) {
    const at = packet.indexOf(TOKEN_RECORD_PREFIX, from);
    if (at === -1) break;
    const tokenAt = at + TOKEN_RECORD_PREFIX.length;
    if (tokenAt + DNAS_TOKEN_BYTES <= packet.length) offsets.push(tokenAt);
    from = at + 1;
  }
  return offsets;
}

export class DynamicTokenDnasPacketStore {
  #inner;
  #generateToken;
  #onToken;

  /**
   * @param {object} options
   * @param {{get: (key: string) => Promise<Buffer|null>}} options.store the
   *   underlying store, normally `FileDnasPacketStore`.
   * @param {() => Buffer} [options.generateToken] injectable for tests. Defaults
   *   to `crypto.randomBytes`, which is the point of the exercise.
   * @param {(event: object) => void} [options.onToken] called with each issued
   *   token so the composed app can record what it handed out.
   */
  constructor({ store, generateToken = null, onToken = null } = {}) {
    if (typeof store?.get !== 'function') {
      throw new TypeError('a DNAS packet store with a get(packetKey) method is required');
    }
    this.#inner = store;
    this.#generateToken = generateToken ?? (() => crypto.randomBytes(DNAS_TOKEN_BYTES));
    this.#onToken = onToken;
  }

  async get(packetKey) {
    const stored = await this.#inner.get(packetKey);
    if (stored == null) return null;

    const offsets = findTokenRecordOffsets(stored);
    // Zero is the normal case: most packets in the store carry no token record.
    // More than one is not something any observed asset does, and rewriting the
    // wrong field would be worse than issuing a shared token, so it is refused
    // rather than guessed at.
    if (offsets.length === 0) return stored;
    if (offsets.length > 1) {
      throw new DnasPacketStoreError(
        'AMBIGUOUS_TOKEN_RECORD',
        `DNAS packet ${packetKey} carries ${offsets.length} token records; refusing to rewrite`
      );
    }

    const token = this.#generateToken();
    if (!Buffer.isBuffer(token) || token.length !== DNAS_TOKEN_BYTES) {
      throw new DnasPacketStoreError(
        'INVALID_GENERATED_TOKEN',
        `generated DNAS token must be a ${DNAS_TOKEN_BYTES}-byte Buffer`
      );
    }

    // Copy. The asset on disk, and the buffer the inner store returned, are
    // both left alone - a cached store must not be poisoned by one request.
    const reply = Buffer.from(stored);
    token.copy(reply, offsets[0]);

    this.#onToken?.({
      packetKey,
      offset: offsets[0],
      token: token.toString('base64')
    });
    return reply;
  }
}
