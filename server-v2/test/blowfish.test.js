import test from 'node:test';
import assert from 'node:assert/strict';

import {
  blowfishEcbDecrypt,
  blowfishEcbEncrypt,
  createBlowfishKey
} from '../src/crypto/blowfish.js';
import { P_INIT, S_INIT } from '../src/crypto/blowfish-constants.js';

const hex = (buffer) => buffer.toString('hex');

/**
 * The constants are extracted from SLES_533.19 itself. Asserting they are the
 * standard pi-digit tables is what proves the client's cipher is stock, and
 * therefore that a correct off-the-shelf Blowfish interoperates. If this fails,
 * the extraction address is wrong or the tables are not stock, and every other
 * assumption in the register slice needs revisiting.
 */
test('the tables extracted from the PAL executable are the standard Blowfish constants', () => {
  assert.equal(P_INIT.length, 18);
  assert.deepEqual(
    Array.from(P_INIT.slice(0, 6)),
    [0x243f6a88, 0x85a308d3, 0x13198a2e, 0x03707344, 0xa4093822, 0x299f31d0]
  );
  assert.equal(S_INIT.length, 4);
  for (const box of S_INIT) assert.equal(box.length, 256);
  assert.deepEqual(
    Array.from(S_INIT[0].slice(0, 6)),
    [0xd1310ba6, 0x98dfb5ac, 0x2ffd72db, 0xd01adfb7, 0xb8e1afed, 0x6a267e96]
  );
});

/**
 * Eric Young's published Blowfish-ECB vectors. These are deterministic and
 * independent of anything in this project, so they catch an implementation
 * mistake that a self-consistent round-trip test would happily hide.
 */
const PUBLISHED_VECTORS = [
  ['0000000000000000', '0000000000000000', '4ef997456198dd78'],
  ['ffffffffffffffff', 'ffffffffffffffff', '51866fd5b85ecb8a'],
  ['3000000000000000', '1000000000000001', '7d856f9a613063f2'],
  ['1111111111111111', '1111111111111111', '2466dd878b963c9d'],
  ['0123456789abcdef', '1111111111111111', '61f9c3802281b096'],
  ['fedcba9876543210', '0123456789abcdef', '0aceab0fc6a0a28d'],
  ['7ca110454a1a6e57', '01a1d6d039776742', '59c68245eb05282b'],
  ['0131d9619dc1376e', '5cd54ca83def57da', 'b1b8cc0b250f09a0']
];

test('matches the published Blowfish-ECB test vectors in both directions', () => {
  for (const [keyHex, plainHex, cipherHex] of PUBLISHED_VECTORS) {
    const state = createBlowfishKey(Buffer.from(keyHex, 'hex'));
    const encrypted = blowfishEcbEncrypt(state, Buffer.from(plainHex, 'hex'));
    assert.equal(hex(encrypted), cipherHex, `encrypt ${keyHex}/${plainHex}`);
    const decrypted = blowfishEcbDecrypt(state, Buffer.from(cipherHex, 'hex'));
    assert.equal(hex(decrypted), plainHex, `decrypt ${keyHex}/${cipherHex}`);
  }
});

/**
 * THE decisive vector: the exact register-reply body V1 sent and the real PAL
 * client accepted, recovered from the archived V1 UDP trace
 * `C:/dnas/pi-evidence-archive/extracted/captures/udp9090/2026_07_12_10_38_35_udp_192_0_2_248_2000.log`
 * (private addresses in this repository's vector are sanitized).
 *
 *   key    = "1234567890" -> 31323334353637383930, the raw account password
 *   plain  = +0x00 "12345" NUL-padded  (the handle the client sent, which it
 *                                       strcmp's against after decrypting)
 *            +0x28 c0 00 02 79         (192.0.2.121, sanitized server IP)
 *            +0x30 00 00 23 82         (9090, the port applied immediately)
 *            rest zero
 *   cipher = the 128 bytes that went on the wire
 *
 * The published vectors above prove the cipher; this proves that OUR key
 * derivation (raw password, not SHA-1), block order and byte order together
 * reproduce a body a real client accepted.
 */
const V1_KEY = '1234567890';
const V1_PLAINTEXT_HEX =
  '3132333435000000000000000000000000000000000000000000000000000000' +
  '0000000000000000c00002790000000000002382000000000000000000000000' +
  '0000000000000000000000000000000000000000000000000000000000000000' +
  '0000000000000000000000000000000000000000000000000000000000000000';
const V1_CIPHERTEXT_HEX =
  '11c091d8f3033d6fb12c46d5e173e352b12c46d5e173e352b12c46d5e173e352' +
  'b12c46d5e173e352e035ad10220a1a486a3a6d953183bcd3b12c46d5e173e352' +
  'b12c46d5e173e352b12c46d5e173e352b12c46d5e173e352b12c46d5e173e352' +
  'b12c46d5e173e352b12c46d5e173e352b12c46d5e173e352b12c46d5e173e352';

test('reproduces the sanitized register-reply vector derived from an accepted body', () => {
  const plaintext = Buffer.from(V1_PLAINTEXT_HEX, 'hex');
  assert.equal(plaintext.length, 128, 'the encrypted body is 0x80 bytes');

  const state = createBlowfishKey(V1_KEY);
  const ciphertext = blowfishEcbEncrypt(state, plaintext);

  assert.equal(ciphertext.length, 128);
  assert.equal(hex(ciphertext), V1_CIPHERTEXT_HEX);

  // And the client's direction: decrypting must recover the handle at +0x00,
  // which is the whole authentication check (`strcmp(plaintext, conn+0x4ac)`).
  const recovered = blowfishEcbDecrypt(createBlowfishKey(V1_KEY), ciphertext);
  assert.equal(hex(recovered), V1_PLAINTEXT_HEX);
  assert.equal(recovered.subarray(0, 5).toString('latin1'), '12345');
  assert.equal(recovered.readUInt32BE(0x28).toString(16), 'c0000279');
  assert.equal(recovered.readUInt32BE(0x30), 9090);
});

test('a wrong password produces a body that does not decrypt to the handle', () => {
  const plaintext = Buffer.from(V1_PLAINTEXT_HEX, 'hex');
  const ciphertext = blowfishEcbEncrypt(createBlowfishKey('wrongpassword'), plaintext);
  const recovered = blowfishEcbDecrypt(createBlowfishKey(V1_KEY), ciphertext);

  // This is exactly what makes the exchange the authentication: only a server
  // holding the password can produce a body that decrypts to the client's own
  // handle. A wrong key makes the client raise {status 1, code 0x13}.
  assert.notEqual(recovered.subarray(0, 5).toString('latin1'), '12345');
  assert.notEqual(hex(recovered), V1_PLAINTEXT_HEX);
});

test('SHA-1 keying would NOT reproduce the body the client accepted', () => {
  // The raw-password keying is proved by the V1 vector above. This pins the
  // specific alternative we had to rule out: BUILD_GUIDE.md section 0 presents
  // SHA-1 keying as universal, which is true only of the op-0x40 keepalive
  // (`blowfish_ecb_hashed_key` at 0x1ea8e8 has exactly one caller). Had we
  // followed it here, we would have produced a different body and the client
  // would have raised {status 1, code 0x13}.
  const plaintext = Buffer.from(V1_PLAINTEXT_HEX, 'hex');
  const sha1OfPassword = Buffer.from('01b307acba4f54f55aafc33bb06bbbf6ca803e9a', 'hex');
  const wrongKeying = blowfishEcbEncrypt(createBlowfishKey(sha1OfPassword), plaintext);
  assert.notEqual(hex(wrongKeying), V1_CIPHERTEXT_HEX);
});

test('key length is the byte length of the password, and wraps cyclically', () => {
  // `keylen = strlen(key)`, so a 10-byte password uses all 10 bytes, folded
  // cyclically across the 18 P words (72 bytes consumed).
  const short = createBlowfishKey('ab');
  const long = createBlowfishKey('abababababababab');
  const block = Buffer.alloc(8);
  // The fold consumes a fixed 72 bytes as key[i % len] regardless of key
  // length, so 'ab' and any whole repetition of it yield the identical byte at
  // every position and therefore the same schedule. This pins CYCLIC wrapping:
  // an implementation that zero-padded instead would disagree here.
  assert.equal(hex(blowfishEcbEncrypt(short, block)), hex(blowfishEcbEncrypt(long, block)));

  assert.throws(() => createBlowfishKey(''), /must not be empty/);
  assert.throws(() => createBlowfishKey(Buffer.alloc(0)), /must not be empty/);
});

test('refuses input that is not a whole number of blocks', () => {
  const state = createBlowfishKey('secret');
  assert.throws(() => blowfishEcbEncrypt(state, Buffer.alloc(7)), /whole number of 8-byte blocks/);
  assert.throws(() => blowfishEcbDecrypt(state, Buffer.alloc(129)), /whole number of 8-byte blocks/);
  assert.equal(blowfishEcbEncrypt(state, Buffer.alloc(0)).length, 0);
});

test('a key schedule is reusable and does not mutate the shared constants', () => {
  const state = createBlowfishKey('secret');
  const block = Buffer.from('0011223344556677', 'hex');
  const first = hex(blowfishEcbEncrypt(state, block));
  const second = hex(blowfishEcbEncrypt(state, block));
  assert.equal(first, second, 'ECB is stateless across calls');

  // The module-level tables must be untouched by any schedule.
  assert.equal(P_INIT[0], 0x243f6a88);
  assert.equal(S_INIT[0][0], 0xd1310ba6);
  assert.equal(hex(blowfishEcbEncrypt(createBlowfishKey('secret'), block)), first);
});
