import assert from 'node:assert/strict';
import test from 'node:test';

import {
  CLIENT_TAIL_ALLOCATION_OVERRUN_BYTES,
  CLIENT_TAIL_ECHO_WINDOW_BYTES,
  CLIENT_TAIL_PASSWORD_OVERWRITE_BYTES,
  REGISTRATION_NONCE_BYTES,
  REPLY_PLAINTEXT_BYTES,
  buildRegisterReplyPlaintext,
  readBindTailBlob
} from '../src/protocol/snap-udp-register-codec.js';
import {
  NONCE_REFUSAL,
  RegistrationNonceError,
  RegistrationNonceTable
} from '../src/udp/registration-nonces.js';

/**
 * The UDP attachment nonce (T33).
 *
 * The register-reply tail blob is the only value in the register/bind exchange
 * that the SERVER chooses and the CLIENT returns. Everything else a bind carries
 * is client-supplied and replayable - the source address and port, the endpoint
 * token (itself only `(3rd octet << 24) | (4th octet << 16) | localPort` of the
 * client's own LAN address), and the account handle.
 *
 * Two properties are under test here and they are not the same thing:
 *
 *  1. SAFETY. The client's copy of this field is an UNBOUNDED memcpy from our
 *     decrypted reply. The server is the only bound that exists.
 *  2. ATTACHMENT. A bind must resolve to its registration by nonce alone, with
 *     no fallback to the source address - the fallback is what makes two players
 *     behind one NAT collide.
 */

const PLAIN_TAIL_LENGTH = 0x34;
const PLAIN_TAIL_BLOB = 0x3c;

function nonceOf(byte) {
  return Buffer.alloc(REGISTRATION_NONCE_BYTES, byte);
}

/* ---- safety: the client's capacity, not ours -------------------------- */

test('the reply carries no tail by default, byte-identical to what V1 sent', () => {
  const plaintext = buildRegisterReplyPlaintext({
    loginIdentity: '12345', serverIpv4: '192.0.2.121', portNow: 9090
  });
  assert.equal(plaintext.length, REPLY_PLAINTEXT_BYTES);
  assert.equal(plaintext.readUInt32BE(PLAIN_TAIL_LENGTH), 0, 'tail length 0');
  assert.equal(
    plaintext.subarray(PLAIN_TAIL_BLOB).every((byte) => byte === 0), true,
    'and no blob - this is the negative control and the rollback'
  );
});

test('a 16-byte nonce lands at plaintext +0x34/+0x3c and nowhere else', () => {
  const nonce = nonceOf(0xab);
  const plaintext = buildRegisterReplyPlaintext({
    loginIdentity: '12345', serverIpv4: '192.0.2.121', portNow: 9090, tailBlob: nonce
  });
  assert.equal(plaintext.readUInt32BE(PLAIN_TAIL_LENGTH), REGISTRATION_NONCE_BYTES);
  assert.deepEqual(
    plaintext.subarray(PLAIN_TAIL_BLOB, PLAIN_TAIL_BLOB + REGISTRATION_NONCE_BYTES), nonce
  );
  // It must not have widened the plaintext or disturbed the proven layout.
  assert.equal(plaintext.length, REPLY_PLAINTEXT_BYTES);
  assert.equal(
    PLAIN_TAIL_BLOB + REGISTRATION_NONCE_BYTES <= REPLY_PLAINTEXT_BYTES, true,
    'the nonce ends inside the 0x80-byte plaintext V1 proved the client accepts'
  );
});

test('every tail length except 0 and 16 is refused, never clamped', () => {
  const build = (length) => buildRegisterReplyPlaintext({
    loginIdentity: '12345',
    serverIpv4: '192.0.2.121',
    portNow: 9090,
    tailBlob: Buffer.alloc(length, 0x41)
  });

  // Under-length and over-length, both inside our own buffer: still refused,
  // because a value we did not intend to send is a defect even when it is safe.
  for (const length of [1, 8, 15, 17, 32, 68]) {
    assert.throws(
      () => build(length),
      (error) => error.code === 'TAIL_BLOB_UNSUPPORTED_LENGTH',
      `expected ${length} bytes to be refused`
    );
  }

  // Past OUR buffer.
  assert.throws(() => build(69), (error) => error.code === 'TAIL_BLOB_TOO_LONG');

  /*
   * Past the CLIENT's capacity. These are the ones that matter: the client
   * memcpys our declared length with no clamp, so each of these would corrupt
   * a different part of a real retail console's memory.
   */
  assert.throws(
    () => build(CLIENT_TAIL_ECHO_WINDOW_BYTES + 1),
    (error) => error.code === 'TAIL_BLOB_OVERRUNS_CLIENT',
    'past the echo window it corrupts the lobby session blob'
  );
  assert.throws(
    () => build(CLIENT_TAIL_PASSWORD_OVERWRITE_BYTES),
    (error) => error.code === 'TAIL_BLOB_OVERRUNS_CLIENT',
    'at 0x3d8 it overwrites the account password'
  );
  assert.throws(
    () => build(CLIENT_TAIL_ALLOCATION_OVERRUN_BYTES),
    (error) => error.code === 'TAIL_BLOB_OVERRUNS_CLIENT',
    'at ~0x578 it overruns the connection allocation'
  );
});

test('the client capacity constants are ordered as the disassembly says', () => {
  // If anyone reorders these the bounds above would silently stop meaning what
  // their names claim.
  assert.equal(REGISTRATION_NONCE_BYTES < CLIENT_TAIL_ECHO_WINDOW_BYTES, true);
  assert.equal(
    CLIENT_TAIL_ECHO_WINDOW_BYTES < CLIENT_TAIL_PASSWORD_OVERWRITE_BYTES, true,
    'the echo window ends well before the password'
  );
  assert.equal(
    CLIENT_TAIL_PASSWORD_OVERWRITE_BYTES < CLIENT_TAIL_ALLOCATION_OVERRUN_BYTES, true,
    'the password is overwritten before the allocation is overrun'
  );
});

/* ---- reading what the client echoed back ------------------------------ */

test('the echoed tail is read from bind body +0x24/+0x28', () => {
  const nonce = nonceOf(0x5a);
  const body = Buffer.alloc(0x128);
  body.writeUInt32BE(REGISTRATION_NONCE_BYTES, 0x24);
  nonce.copy(body, 0x28);
  const echoed = readBindTailBlob({ body });
  assert.equal(echoed.declaredLength, REGISTRATION_NONCE_BYTES);
  assert.deepEqual(echoed.blob, nonce);
});

test('a bind that echoes length 0 is distinguished from one too short to carry the field', () => {
  // These are different failures and must not be conflated: the first says the
  // client dropped our nonce, the second says the frame is truncated.
  assert.deepEqual(readBindTailBlob({ body: Buffer.alloc(0x128) }).blob, Buffer.alloc(0));
  assert.equal(readBindTailBlob({ body: Buffer.alloc(0x10) }), null);
  assert.equal(readBindTailBlob({}), null);
});

test('a bind declaring a tail it did not send is refused, not believed', () => {
  const body = Buffer.alloc(0x128);
  body.writeUInt32BE(0x1000, 0x24);
  const echoed = readBindTailBlob({ body });
  assert.equal(echoed.blob, null);
  assert.match(echoed.refusal, /echo window/);

  const short = Buffer.alloc(0x30);
  short.writeUInt32BE(0x20, 0x24);
  assert.match(readBindTailBlob({ body: short }).refusal, /past the bind body/);
});

/* ---- attachment ------------------------------------------------------- */

test('a nonce is 128 bits, unique, and from a cryptographic source', () => {
  const table = new RegistrationNonceTable();
  const seen = new Set();
  for (let index = 0; index < 500; index += 1) {
    const nonce = table.issue({ handle: `player-${index}` });
    assert.equal(nonce.length, REGISTRATION_NONCE_BYTES, '128 bits');
    assert.equal(seen.has(nonce.toString('hex')), false, 'no repeat');
    seen.add(nonce.toString('hex'));
  }
});

test('a bind attaches by nonce alone, and two players behind ONE NAT stay separate', () => {
  /*
   * THE REQUIREMENT. Both players present the same public source address - what
   * NAT produces - and differ only in source port, which is exactly what the
   * old address-keyed resolution could not use. Attachment must not consult
   * either.
   *
   * The identical endpoint tokens below are the CARRIER-GRADE case, not the
   * household one: the token is `(3rd octet << 24) | (4th octet << 16) | port`
   * of the client's own LAN address, so two consoles behind one household
   * router have DIFFERENT tokens (captures: 192.0.2.129 -> 0x028107D0,
   * 192.0.2.248 -> 0x02F807D0), while two households each running
   * x.x.1.100:2000 collide. Either way the token is a truncated routing hint,
   * never an identifier - and the 3rd-octet contribution is decompile-only,
   * since both captured hosts were in one /24.
   */
  const table = new RegistrationNonceTable();
  const alice = table.issue({
    handle: 'alice', sourceAddress: '203.0.113.7', sourcePort: 40001, endpointToken: 0x016407d0
  });
  const bob = table.issue({
    handle: 'bob', sourceAddress: '203.0.113.7', sourcePort: 40002, endpointToken: 0x016407d0
  });
  // Identical tokens too - the token collides for any two LANs sharing their
  // last two octets, so it cannot be the discriminator either.
  assert.equal(table.consume(alice).registration.handle, 'alice');
  assert.equal(table.consume(bob).registration.handle, 'bob');
});

test('the source address is metadata and is never a fallback', () => {
  const table = new RegistrationNonceTable();
  table.issue({ handle: 'alice', sourceAddress: '203.0.113.7', sourcePort: 40001 });
  // A bind from alice's exact source, carrying a nonce we never minted, gets
  // nothing. There is deliberately no path that says "but the address matches".
  assert.equal(table.consume(nonceOf(0xff)).refusal, NONCE_REFUSAL.UNKNOWN);
  assert.equal(table.consume(null).refusal, NONCE_REFUSAL.ABSENT);
  assert.equal(table.consume(Buffer.alloc(8)).refusal, NONCE_REFUSAL.MALFORMED);
});

test('one successful bind per nonce, with a bounded retransmission window', () => {
  let now = 1000;
  const table = new RegistrationNonceTable({
    clock: () => now, retransmissionWindowMs: 5000, ttlMs: 60_000
  });
  const nonce = table.issue({ handle: 'alice' });

  const first = table.consume(nonce);
  assert.equal(first.registration.handle, 'alice');
  assert.equal(first.retransmission, false);

  // A duplicate inside the window is answered identically - the bind is
  // unreliable and one-shot, so a duplicate is the network's doing.
  now += 4999;
  assert.equal(table.consume(nonce).retransmission, true);

  // Past the window it is a replay, and refused.
  now += 2;
  assert.equal(table.consume(nonce).refusal, NONCE_REFUSAL.CONSUMED);
});

test('an expired registration is refused and does not linger', () => {
  let now = 1000;
  const table = new RegistrationNonceTable({ clock: () => now, ttlMs: 30_000 });
  const nonce = table.issue({ handle: 'alice' });
  assert.equal(table.size, 1);
  now += 30_000;
  assert.equal(table.consume(nonce).refusal, NONCE_REFUSAL.EXPIRED);
  assert.equal(table.size, 0, 'and it is gone, not merely refused');
});

test('a captured nonce cannot be replayed against a later registration', () => {
  let now = 1000;
  const table = new RegistrationNonceTable({ clock: () => now });
  const first = table.issue({ handle: 'alice' });
  table.consume(first);
  // alice re-registers: a NEW nonce, and the old one is dead.
  now += 1000;
  const second = table.issue({ handle: 'alice' });
  assert.notDeepEqual(first, second, 'each registration mints its own');
  now += 10_000;
  assert.equal(table.consume(first).refusal, NONCE_REFUSAL.CONSUMED);
  assert.equal(table.consume(second).registration.handle, 'alice');
});

test('the pending table is bounded and fails closed', () => {
  const table = new RegistrationNonceTable({ maximum: 2 });
  table.issue({ handle: 'a' });
  table.issue({ handle: 'b' });
  // Refuse a NEW registration rather than evict one mid-handshake: otherwise a
  // flood displaces players who are already connecting.
  assert.throws(
    () => table.issue({ handle: 'c' }),
    (error) => error instanceof RegistrationNonceError && error.code === 'PENDING_CAPACITY'
  );
  assert.equal(table.size, 2);
});

test('a broken random source refuses to mint rather than emitting a weak nonce', () => {
  const short = new RegistrationNonceTable({ randomBytes: () => Buffer.alloc(4) });
  assert.throws(
    () => short.issue({ handle: 'alice' }),
    (error) => error.code === 'RANDOM_SOURCE'
  );
  // A source that always returns the same bytes cannot produce a unique nonce
  // for a second registration, and says so rather than issuing a duplicate.
  const constant = new RegistrationNonceTable({ randomBytes: () => nonceOf(7) });
  constant.issue({ handle: 'alice' });
  assert.throws(
    () => constant.issue({ handle: 'bob' }),
    (error) => error.code === 'RANDOM_SOURCE'
  );
});

test('a registration requires a handle', () => {
  const table = new RegistrationNonceTable();
  for (const handle of [undefined, null, '', 42]) {
    assert.throws(
      () => table.issue({ handle }),
      (error) => error.code === 'HANDLE_REQUIRED'
    );
  }
});
