import { P_INIT, S_INIT } from './blowfish-constants.js';

/**
 * Blowfish-ECB, as the PAL client implements it.
 *
 * The client's cipher is STOCK: its P/S tables are the standard pi-digit
 * constants (read straight out of SLES_533.19 by
 * `tools/gen/extract-blowfish-constants.js`), `FUN_001e4ec8` is the textbook
 * Feistel F, and `FUN_001e5234` is the standard key schedule. So any correct
 * Blowfish interoperates and nothing here is PAL-specific.
 *
 * What IS PAL-specific, and what this module deliberately does NOT decide:
 *
 *   - The KEY is the raw account password string, used verbatim with
 *     `keylen = strlen(password)`. It is NOT a SHA-1 digest. `FUN_001d9678`
 *     (the cmd-0x2d parser) calls the plain `blowfish_decrypt_buffer` with
 *     `key = conn+0x484`, which the password soft-keyboard filled.
 *     `blowfish_ecb_hashed_key` (0x1ea8e8, SHA-1 keyed) has exactly one caller
 *     and it is the op-0x40 keepalive. This corrects BUILD_GUIDE.md section 0,
 *     which presents SHA-1 keying as universal.
 *   - No byte swapping around the cipher. `FUN_001e5538` bswap32s each word
 *     before and after the block call, which on the little-endian EE means the
 *     cipher sees the wire bytes in order. So: big-endian block words over the
 *     wire byte stream, exactly as textbook Blowfish specifies.
 *   - The client DECRYPTS the register reply, so the server ENCRYPTS.
 *
 * See docs/findings/protocol/UDP9090-REGISTER-RE-2026-08-03.md sections 0 and 5.
 */

const BLOCK_BYTES = 8;
/** Standard Blowfish maximum key length, 448 bits. */
const MAX_KEY_BYTES = 56;

function feistel(state, word) {
  const a = (word >>> 24) & 0xff;
  const b = (word >>> 16) & 0xff;
  const c = (word >>> 8) & 0xff;
  const d = word & 0xff;
  const sum = (state.s[0][a] + state.s[1][b]) >>> 0;
  const xored = (sum ^ state.s[2][c]) >>> 0;
  return (xored + state.s[3][d]) >>> 0;
}

function encryptBlockWords(state, left, right) {
  let xl = left >>> 0;
  let xr = right >>> 0;
  for (let round = 0; round < 16; round += 1) {
    xl = (xl ^ state.p[round]) >>> 0;
    xr = (xr ^ feistel(state, xl)) >>> 0;
    const swap = xl;
    xl = xr;
    xr = swap;
  }
  // Undo the final swap, then the two post-whitening words.
  const swap = xl;
  xl = xr;
  xr = swap;
  xr = (xr ^ state.p[16]) >>> 0;
  xl = (xl ^ state.p[17]) >>> 0;
  return [xl, xr];
}

function decryptBlockWords(state, left, right) {
  let xl = left >>> 0;
  let xr = right >>> 0;
  for (let round = 17; round > 1; round -= 1) {
    xl = (xl ^ state.p[round]) >>> 0;
    xr = (xr ^ feistel(state, xl)) >>> 0;
    const swap = xl;
    xl = xr;
    xr = swap;
  }
  const swap = xl;
  xl = xr;
  xr = swap;
  xr = (xr ^ state.p[1]) >>> 0;
  xl = (xl ^ state.p[0]) >>> 0;
  return [xl, xr];
}

/**
 * Standard Blowfish key schedule: fold the key cyclically into P, then re-encrypt
 * P and S with the cipher itself (9 + 512 = 521 block encryptions).
 *
 * @param {Buffer|Uint8Array|string} key raw key bytes. A string is taken as
 *   latin1, one byte per code unit, which is what the client's `strlen`-bounded
 *   password buffer holds.
 */
export function createBlowfishKey(key) {
  const keyBytes = Buffer.isBuffer(key)
    ? key
    : typeof key === 'string'
      ? Buffer.from(key, 'latin1')
      : Buffer.from(key);
  if (keyBytes.length === 0) {
    throw new Error('blowfish key must not be empty');
  }
  // Standard Blowfish tops out at 448 bits. Past 72 bytes the cyclic P-fold
  // stops consuming input at all, so two longer keys sharing a 72-byte prefix
  // would silently collide. Refuse rather than let that happen quietly; the
  // client's own key buffer is a strncpy(..., 0x28) so it can never exceed 39.
  if (keyBytes.length > MAX_KEY_BYTES) {
    throw new Error(`blowfish key must be at most ${MAX_KEY_BYTES} bytes, got ${keyBytes.length}`);
  }
  if (typeof key === 'string') {
    for (let index = 0; index < key.length; index += 1) {
      if (key.charCodeAt(index) > 0xff) {
        throw new Error('blowfish string key must be latin1; encode the bytes yourself');
      }
    }
  }

  // Uint32Array throughout: the constants and every intermediate are unsigned
  // 32-bit, and a signed view would sign-extend the high-bit words.
  const state = {
    p: Uint32Array.from(P_INIT),
    s: S_INIT.map((box) => Uint32Array.from(box))
  };

  let keyIndex = 0;
  for (let index = 0; index < 18; index += 1) {
    let word = 0;
    for (let byte = 0; byte < 4; byte += 1) {
      word = ((word << 8) | keyBytes[keyIndex % keyBytes.length]) >>> 0;
      keyIndex += 1;
    }
    state.p[index] = (state.p[index] ^ word) >>> 0;
  }

  let left = 0;
  let right = 0;
  for (let index = 0; index < 18; index += 2) {
    [left, right] = encryptBlockWords(state, left, right);
    state.p[index] = left;
    state.p[index + 1] = right;
  }
  for (let box = 0; box < 4; box += 1) {
    for (let index = 0; index < 256; index += 2) {
      [left, right] = encryptBlockWords(state, left, right);
      state.s[box][index] = left;
      state.s[box][index + 1] = right;
    }
  }
  return state;
}

function transform(state, input, encrypt) {
  if (!Buffer.isBuffer(input)) {
    if (!ArrayBuffer.isView(input)) {
      throw new TypeError('blowfish-ecb input must be a Buffer or a typed array');
    }
    input = Buffer.from(input.buffer, input.byteOffset, input.byteLength);
  }
  if (input.length % BLOCK_BYTES !== 0) {
    throw new Error(
      `blowfish-ecb needs a whole number of ${BLOCK_BYTES}-byte blocks, got ${input.length}`
    );
  }
  const output = Buffer.alloc(input.length);
  for (let offset = 0; offset < input.length; offset += BLOCK_BYTES) {
    const left = input.readUInt32BE(offset);
    const right = input.readUInt32BE(offset + 4);
    const [outLeft, outRight] = encrypt
      ? encryptBlockWords(state, left, right)
      : decryptBlockWords(state, left, right);
    output.writeUInt32BE(outLeft >>> 0, offset);
    output.writeUInt32BE(outRight >>> 0, offset + 4);
  }
  return output;
}

/**
 * Encrypt whole 8-byte blocks, big-endian words, no padding.
 * @param {ReturnType<typeof createBlowfishKey>} state
 * @param {Buffer|Uint8Array} plaintext length must be a multiple of 8
 * @returns {Buffer}
 */
export function blowfishEcbEncrypt(state, plaintext) {
  return transform(state, plaintext, true);
}

/**
 * Decrypt whole 8-byte blocks, big-endian words, no padding.
 * @param {ReturnType<typeof createBlowfishKey>} state
 * @param {Buffer|Uint8Array} ciphertext length must be a multiple of 8
 * @returns {Buffer}
 */
export function blowfishEcbDecrypt(state, ciphertext) {
  return transform(state, ciphertext, false);
}
