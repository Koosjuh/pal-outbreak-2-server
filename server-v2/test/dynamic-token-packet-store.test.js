import test from 'node:test';
import assert from 'node:assert/strict';
import crypto from 'node:crypto';

import {
  DNAS_TOKEN_BYTES,
  DynamicTokenDnasPacketStore,
  findTokenRecordOffsets
} from '../src/dnas/dynamic-token-packet-store.js';
import { ConnectionIdentityRegistry } from '../src/sessions/connection-identity.js';
import { AccountSessionRegistry } from '../src/sessions/account-session.js';

/**
 * The real 77-byte asset, rebuilt from the bytes verified on disk and against
 * the wire: `packets/b198010bd61490f8_01088008`. Its 32 token bytes base64 to
 * `KLa0ZocQ6MWC3ADgVYbw2h69t0MsMnF5Z4OmwnhY3zc=`, which is exactly what the real
 * client presented in `0x1007` and as `?DNAS=` (T26/T27).
 */
const CAPTURED_TOKEN_HEX =
  '28b6b4668710e8c582dc00e05586f0da1ebdb7432c3271796783a6c27858df37';
const CAPTURED_TOKEN_BASE64 = 'KLa0ZocQ6MWC3ADgVYbw2h69t0MsMnF5Z4OmwnhY3zc=';

function capturedAsset() {
  const packet = Buffer.alloc(77);
  // The 8-byte game id at +0x1b, as recorded.
  Buffer.from('b198010bd61490f8', 'hex').copy(packet, 0x1b);
  packet.writeUInt32BE(0x00000025, 0x24);
  Buffer.from([0x01, 0x00, 0x00, 0x00]).copy(packet, 0x28);
  packet.writeUInt8(0x20, 0x2c);
  Buffer.from(CAPTURED_TOKEN_HEX, 'hex').copy(packet, 0x2d);
  return packet;
}

function storeReturning(packet) {
  return { get: async () => (packet == null ? null : packet) };
}

test('locates the token record in the real captured asset', () => {
  const asset = capturedAsset();
  const offsets = findTokenRecordOffsets(asset);
  assert.deepEqual(offsets, [0x2d]);
  assert.equal(
    asset.subarray(0x2d, 0x2d + DNAS_TOKEN_BYTES).toString('base64'),
    CAPTURED_TOKEN_BASE64,
    'the located bytes are the value the real client presented'
  );
});

test('replaces ONLY the token field, leaving every other byte untouched', async () => {
  const asset = capturedAsset();
  const replacement = Buffer.alloc(DNAS_TOKEN_BYTES, 0xab);
  const store = new DynamicTokenDnasPacketStore({
    store: storeReturning(asset),
    generateToken: () => replacement
  });

  const served = await store.get('b198010bd61490f8_01088008');
  assert.equal(served.length, asset.length, 'the reply keeps its length');
  assert.equal(served.subarray(0x2d, 0x2d + DNAS_TOKEN_BYTES).toString('hex'), replacement.toString('hex'));

  // Everything outside the 32 bytes is byte-identical, including the record tag,
  // the length byte and the game id.
  const before = Buffer.concat([served.subarray(0, 0x2d), served.subarray(0x2d + DNAS_TOKEN_BYTES)]);
  const original = Buffer.concat([asset.subarray(0, 0x2d), asset.subarray(0x2d + DNAS_TOKEN_BYTES)]);
  assert.equal(before.toString('hex'), original.toString('hex'));
  assert.equal(served.readUInt8(0x2c), 0x20, 'the length byte still says 32');
});

test('never mutates the stored asset', async () => {
  const asset = capturedAsset();
  const pristine = Buffer.from(asset);
  const store = new DynamicTokenDnasPacketStore({
    store: storeReturning(asset),
    generateToken: () => Buffer.alloc(DNAS_TOKEN_BYTES, 0x01)
  });

  await store.get('b198010bd61490f8_01088008');
  await store.get('b198010bd61490f8_01088008');
  assert.equal(
    asset.toString('hex'),
    pristine.toString('hex'),
    'a cached buffer must not be poisoned by a request'
  );
});

test('issues a DIFFERENT token per request, from a CSPRNG by default', async () => {
  const store = new DynamicTokenDnasPacketStore({ store: storeReturning(capturedAsset()) });

  const seen = new Set();
  for (let index = 0; index < 32; index += 1) {
    const served = await store.get('b198010bd61490f8_01088008');
    const token = served.subarray(0x2d, 0x2d + DNAS_TOKEN_BYTES).toString('base64');
    assert.notEqual(token, CAPTURED_TOKEN_BASE64, 'the static token is gone');
    seen.add(token);
  }
  assert.equal(seen.size, 32, 'every request gets its own token');
});

test('the generator is injectable and deterministic for tests', async () => {
  let counter = 0;
  const store = new DynamicTokenDnasPacketStore({
    store: storeReturning(capturedAsset()),
    generateToken: () => Buffer.alloc(DNAS_TOKEN_BYTES, counter++)
  });

  const first = await store.get('k_00000000'.replace('k', 'b198010bd61490f8'));
  const second = await store.get('b198010bd61490f8_01088008');
  assert.equal(first.readUInt8(0x2d), 0);
  assert.equal(second.readUInt8(0x2d), 1);
});

test('reports each issued token so the server knows what it handed out', async () => {
  const issued = [];
  const store = new DynamicTokenDnasPacketStore({
    store: storeReturning(capturedAsset()),
    generateToken: () => Buffer.alloc(DNAS_TOKEN_BYTES, 0x07),
    onToken: (event) => issued.push(event)
  });

  await store.get('b198010bd61490f8_01088008');
  assert.equal(issued.length, 1);
  assert.equal(issued[0].offset, 0x2d);
  assert.equal(issued[0].packetKey, 'b198010bd61490f8_01088008');
  assert.equal(issued[0].token, Buffer.alloc(DNAS_TOKEN_BYTES, 0x07).toString('base64'));
});

test('passes through packets that carry no token record', async () => {
  const plain = Buffer.from('deadbeefcafebabe', 'hex');
  const store = new DynamicTokenDnasPacketStore({
    store: storeReturning(plain),
    generateToken: () => Buffer.alloc(DNAS_TOKEN_BYTES, 0xff)
  });
  const served = await store.get('0044d711bb7bfb3a_01080000');
  assert.equal(served.toString('hex'), plain.toString('hex'));
});

test('a missing packet stays missing', async () => {
  const store = new DynamicTokenDnasPacketStore({ store: storeReturning(null) });
  assert.equal(await store.get('0044d711bb7bfb3a_01080000'), null);
});

test('refuses to rewrite a packet with more than one token record', async () => {
  const doubled = Buffer.concat([capturedAsset(), capturedAsset()]);
  const store = new DynamicTokenDnasPacketStore({ store: storeReturning(doubled) });
  await assert.rejects(
    () => store.get('b198010bd61490f8_01088008'),
    (error) => error.code === 'AMBIGUOUS_TOKEN_RECORD',
    'rewriting the wrong field is worse than issuing a shared token'
  );
});

test('refuses a generator that does not produce 32 bytes', async () => {
  const store = new DynamicTokenDnasPacketStore({
    store: storeReturning(capturedAsset()),
    generateToken: () => Buffer.alloc(16)
  });
  await assert.rejects(
    () => store.get('b198010bd61490f8_01088008'),
    (error) => error.code === 'INVALID_GENERATED_TOKEN'
  );
});

/* ---- two clients ---------------------------------------------------------- */

test('two clients behind ONE source address receive distinct tokens that coexist', async () => {
  // The point of the experiment. With the static asset both consoles received
  // the identical value; with per-session tokens they do not, and the identity
  // layer tracks both without either displacing the other.
  const store = new DynamicTokenDnasPacketStore({ store: storeReturning(capturedAsset()) });

  const firstReply = await store.get('b198010bd61490f8_01088008');
  const secondReply = await store.get('b198010bd61490f8_01088008');
  const firstToken = firstReply.subarray(0x2d, 0x2d + DNAS_TOKEN_BYTES).toString('base64');
  const secondToken = secondReply.subarray(0x2d, 0x2d + DNAS_TOKEN_BYTES).toString('base64');
  assert.notEqual(firstToken, secondToken, 'two consoles no longer share one value');

  const sessions = new Map([
    ['http-a', { connectionId: 'http-a', userid: 'alice' }],
    ['http-b', { connectionId: 'http-b', userid: 'bob' }]
  ]);
  const accountSessions = new AccountSessionRegistry();
  const registry = new ConnectionIdentityRegistry({
    sessionLookup: (id) => sessions.get(id) ?? null,
    accountSessions
  });

  // Both from the SAME address, as two consoles on one LAN behind one NAT.
  // Under the static asset these were one key; they are now two, and neither
  // binding evicts the other.
  registry.bindDnasToken({ dnasToken: firstToken, sessionConnectionId: 'http-a' });
  registry.bindDnasToken({ dnasToken: secondToken, sessionConnectionId: 'http-b' });
  assert.equal(registry.boundTokenCount, 2, 'two distinct tokens, tracked separately');
  assert.equal(registry.releaseDnasToken(firstToken, 'http-a'), true);
  assert.equal(registry.boundTokenCount, 1, 'and separately releasable');
});

test('one client at a time is resolved, and the account session is what resolves it', async () => {
  const store = new DynamicTokenDnasPacketStore({ store: storeReturning(capturedAsset()) });
  const reply = await store.get('b198010bd61490f8_01088008');
  const token = reply.subarray(0x2d, 0x2d + DNAS_TOKEN_BYTES).toString('base64');

  const accountSessions = new AccountSessionRegistry();
  const registry = new ConnectionIdentityRegistry({
    sessionLookup: () => null,
    accountSessions
  });

  accountSessions.establish({ userid: 'alice', sourceAddress: '203.0.113.9' });
  const alice = registry.openConnection({ remote: { address: '203.0.113.9', port: 1 } });
  assert.equal(
    registry.associateConnection({ connectionRef: alice, dnasToken: token }).userid,
    'alice'
  );
});

test('distinct tokens do NOT yet resolve two SIMULTANEOUS players at one address', async () => {
  // Recorded honestly, because it is the obvious next question, and because the
  // test above proves only that the TOKENS coexist - not that two players do.
  //
  // Commit 1 removed all narrowing after review demonstrated a privilege
  // escalation from letting the token break a tie. Making a proven-distinct
  // token part of the candidate FILTER - on the same footing as the address -
  // would resolve this case, but it is a separate decision with its own gate and
  // is deliberately not taken here. Until then, two players sharing one source
  // address are refused rather than guessed at.
  const accountSessions = new AccountSessionRegistry();
  const registry = new ConnectionIdentityRegistry({
    sessionLookup: () => null,
    accountSessions
  });
  accountSessions.establish({ userid: 'alice', sourceAddress: '203.0.113.9' });
  accountSessions.establish({ userid: 'bob', sourceAddress: '203.0.113.9' });

  const connectionRef = registry.openConnection({ remote: { address: '203.0.113.9', port: 1 } });
  assert.throws(
    () => registry.associateConnection({
      connectionRef,
      dnasToken: crypto.randomBytes(DNAS_TOKEN_BYTES).toString('base64')
    }),
    (error) => error.code === 'AMBIGUOUS_ACCOUNT_SESSION'
  );
});
