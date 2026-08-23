import assert from 'node:assert/strict';
import test from 'node:test';

import {
  CLIENT_NAME_QUERY_RECORD_CEILING,
  COMPLETION_SELECTOR,
  KEEPALIVE_BODY_BYTES,
  KEEPALIVE_PLAINTEXT_BYTES,
  MAXIMUM_NAME_QUERY_RECORDS,
  SnapLobbyCodecError,
  buildCompletionPayload,
  buildKeepalivePayload,
  buildNameQueryReplyPayload,
  buildRoomListPayload,
  buildSuccessTransitionPayload,
  decodeNameQuery
} from '../src/udp/snap-lobby-codec.js';

/**
 * Payload layouts for the post-selection phase.
 *
 * Expectations are DERIVED, not pattern-matched: the op-0x48 fixtures below are
 * the archived bytes of the session that rendered Area Select on real PS2
 * hardware, sliced out of
 * `C:\dnas\pi-evidence-archive\extracted\captures\udp9090\`
 * `2026_07_30_14_52_53_udp_192_0_2_248_2000.log` (IN #9 at line 152, OUT #9 at
 * line 160), with private addresses sanitized and each deviation stated.
 */

/** Archive IN #9, the 70-byte NAME query, payload only (wire 0x10 onward). */
const ARCHIVE_NAME_QUERY_PAYLOAD = Buffer.from(
  '0000000a020000004e414d4544313932' +
  '2e302e322e31323130310000004e414d' +
  '45463139322e302e322e313231313000' +
  '0000', 'hex');

/** Archive OUT #9, the 392-byte reply, payload only. All five words are zero. */
const ARCHIVE_NAME_QUERY_REPLY_PAYLOAD = Buffer.from(
  '0000000a000000000000000a' +
  Array.from({ length: 10 }, (_unused, index) =>
    Buffer.from(`AREA00${String(index + 1).padStart(2, '0')}`, 'latin1')
      .toString('hex').padEnd(0x20, '0') + '0'.repeat(0x28)).join(''),
  'hex');

test('the archived NAME query decodes to its tag and its two record keys', () => {
  const query = decodeNameQuery(ARCHIVE_NAME_QUERY_PAYLOAD);
  assert.equal(query.tag, 10);
  assert.equal(query.declaredEntryCount, 2);
  assert.equal(query.truncated, false);
  // record[0].key + "01" and + "10" - the TCP-10127 0x6504 key, which in that
  // session was the literal dotted quad "192.0.2.121".
  assert.deepEqual(query.entries, [
    { flag: 0x44, value: '192.0.2.12101' },
    { flag: 0x46, value: '192.0.2.12110' }
  ]);
});

test('a NAME query declaring more entries than it carries yields only what is there', () => {
  const payload = Buffer.from(ARCHIVE_NAME_QUERY_PAYLOAD);
  payload.writeUInt8(9, 0x04);
  const query = decodeNameQuery(payload);
  assert.equal(query.declaredEntryCount, 9);
  assert.equal(query.truncated, true);
  assert.equal(query.entries.length, 2);
});

test('the op-0x48 reply is byte-identical to the archive except for the +0x20 keys', () => {
  const records = Array.from({ length: 10 }, (_unused, index) => ({
    name: `AREA00${String(index + 1).padStart(2, '0')}`,
    playerCount: 0,
    key: index + 1
  }));
  const payload = buildNameQueryReplyPayload({ tag: 10, statusWord: 0, records });

  // The expectation is the archive's own bytes with ONE documented change: V1
  // shipped key 0 in all ten records, which made every refresh resolve to box 0
  // (FUN_005bf280). Patch the expected bytes rather than assert the actual ones.
  const expected = Buffer.from(ARCHIVE_NAME_QUERY_REPLY_PAYLOAD);
  for (let index = 0; index < 10; index += 1) {
    expected.writeUInt32BE(index + 1, 12 + index * 0x24 + 0x20);
  }
  assert.deepEqual(payload, expected);
  // 16 header + this payload is the archived 388-byte message, 392 on the wire.
  assert.equal(payload.length + 0x10, 0x184);
});

test('the player count lands at record +0x10, where FUN_005bc990 sums it', () => {
  const payload = buildNameQueryReplyPayload({
    tag: 1,
    records: [{ name: 'AREA0001', playerCount: 0x1234, key: 1 }]
  });
  assert.equal(payload.readUInt32BE(12 + 0x10), 0x1234);
});

test('an op-0x48 reply with no records is refused rather than leaving every box grey', () => {
  assert.throws(
    () => buildNameQueryReplyPayload({ tag: 1, records: [] }),
    (error) => error instanceof SnapLobbyCodecError && error.code === 'NO_RECORDS'
  );
});

test('the binding record ceiling is the ten-bit message length, not the client 0x37d', () => {
  assert.equal(MAXIMUM_NAME_QUERY_RECORDS, 27);
  assert.ok(MAXIMUM_NAME_QUERY_RECORDS < CLIENT_NAME_QUERY_RECORD_CEILING);
  assert.throws(
    () => buildNameQueryReplyPayload({
      tag: 1,
      records: Array.from({ length: MAXIMUM_NAME_QUERY_RECORDS + 1 }, (_unused, index) => ({
        name: `AREA00${String((index % 10) + 1).padStart(2, '0')}`, key: index + 1
      }))
    }),
    (error) => error instanceof SnapLobbyCodecError && error.code === 'TOO_MANY_RECORDS'
  );
});

test('a record name that leaves no terminating NUL is refused', () => {
  assert.throws(
    () => buildNameQueryReplyPayload({
      tag: 1,
      records: [{ name: 'A'.repeat(16), key: 1 }]
    }),
    (error) => error instanceof SnapLobbyCodecError && error.code === 'RECORD_NAME_LENGTH'
  );
});

test('the completion payload is the archived selector-0x0c body', () => {
  // Archive OUT #11: b018002802f807d0 00000002 00000000 | 0000000c 00000000
  assert.deepEqual(
    buildCompletionPayload({ selector: COMPLETION_SELECTOR.ROOM_QUERY, status: 0 }),
    Buffer.from('0000000c00000000', 'hex')
  );
});

test('the ENTER accept selects 6, which drives FUN_005ad9f0 to the lobby', () => {
  assert.deepEqual(
    buildCompletionPayload({ selector: COMPLETION_SELECTOR.AREA_ENTER }),
    Buffer.from('0000000600000000', 'hex')
  );
});

test('the keepalive body is 0x114 bytes: 0x110 of ciphertext then four zeros', () => {
  const ciphertext = Buffer.alloc(KEEPALIVE_PLAINTEXT_BYTES, 0xab);
  const payload = buildKeepalivePayload(ciphertext);
  assert.equal(payload.length, KEEPALIVE_BODY_BYTES);
  assert.deepEqual(payload.subarray(0, KEEPALIVE_PLAINTEXT_BYTES), ciphertext);
  assert.deepEqual(payload.subarray(KEEPALIVE_PLAINTEXT_BYTES), Buffer.alloc(4));
  // 16 header + 0x114 body = 0x124, the who-length V1 emitted; 296 on the wire.
  assert.equal(payload.length + 0x10, 0x124);
});

test('a keepalive ciphertext of the wrong length is refused, never padded', () => {
  assert.throws(
    () => buildKeepalivePayload(Buffer.alloc(0x100)),
    (error) => error instanceof SnapLobbyCodecError && error.code === 'KEEPALIVE_CIPHERTEXT'
  );
});

test('the success transition carries the token REVERSED at body +0x08', () => {
  const payload = buildSuccessTransitionPayload({ endpointToken: 0x02f807d0 });
  assert.equal(payload.length, 12);
  assert.equal(payload.readUInt32BE(0x00), 0);
  assert.deepEqual(payload.subarray(0x08), Buffer.from('d007f802', 'hex'));
});

test('room list display fields are big-endian and the handle stays little-endian', () => {
  const payload = buildRoomListPayload({
    rooms: [{ name: 'PAL LOBBY', current: 2, flags: 0, max: 4, handle: 0x00010001 }]
  });
  assert.equal(payload.readUInt32BE(0x08), 1);
  const record = payload.subarray(12);
  assert.equal(record.subarray(0, 9).toString('latin1'), 'PAL LOBBY');
  assert.equal(record.readUInt32BE(0x14), 2);
  assert.equal(record.readUInt32BE(0x1c), 0);
  assert.equal(record.readUInt32BE(0x20), 4);
  // Deliberately LE: the handle round-trips through the client's 0x6fee68 table
  // and comes back in the ENTER; the LE round trip is the rig-proven one.
  assert.equal(record.readUInt32LE(0x24), 0x00010001);
});

test('a room name long enough to reach the current-players word is refused', () => {
  assert.throws(
    () => buildRoomListPayload({ rooms: [{ name: 'X'.repeat(20), handle: 1 }] }),
    (error) => error instanceof SnapLobbyCodecError && error.code === 'ROOM_NAME_LENGTH'
  );
});
