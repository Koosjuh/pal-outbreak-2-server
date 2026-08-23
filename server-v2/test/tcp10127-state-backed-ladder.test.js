import assert from 'node:assert/strict';
import net from 'node:net';
import test from 'node:test';

import { createTcp10127Service } from '../src/tcp/tcp10127-service.js';
import { decodeTcp10127Frame } from '../src/protocol/tcp10127-codec.js';
import { decodeSnapField, encodeSnapField } from '../src/protocol/snap-field-codec.js';
import {
  DIRECTORY_PROVENANCE,
  StaticDirectoryProvider,
  createDirectoryState
} from '../src/state/directory-state.js';
import {
  LOBBY_CONNECTION_CODEC_BYTE,
  createDirectoryBackedProviders
} from '../src/state/lobby-initialization-providers.js';
import { AREA_TABLE_TRANSFER } from '../src/state/area-table.js';
import { createV1ObservedAreaTable } from '../src/state/area-table-v1.js';

/**
 * The proven ladder, driven by directory state instead of inline fixtures.
 *
 * The values below are neutral on purpose. V1's `SLOT0001`, `OPEN` and
 * `Test Slot` are not used anywhere here: they are V1 output that one client
 * tolerated, never proven PAL content, and a fixture that reaches production by
 * being convenient is exactly the failure this store exists to prevent.
 *
 * ## The single-entry transcript is a HYBRID, and says so
 *
 * `FUN_001c7580` (`0x6502`), `FUN_001c7980` (`0x6504`) and `FUN_001c85c0`
 * (`0x6510`) all send the entry's CURRENT `+0x00` field as their trailing field.
 * The requests frozen below were captured from a mode-0 session, where `0x6503`
 * never ran and that field was still empty - so they carry the empty envelope
 * `000258d8`. A real mode-1 client, whose `0x6503` has just written a host
 * there, would send the ENCODED HOST in all three.
 *
 * That costs nothing in correctness: V2 treats those trailers as opaque and not
 * one response byte differs. But this transcript must not be read as "what a
 * real client sends" - it is a `0x6503` spliced into captured mode-0 requests,
 * and it is kept that way because the captured bytes are the valuable part.
 *
 * The two-entry walk at the end of this file builds all three trailers
 * faithfully instead, and is the honest end-to-end coverage of the mode-1 route.
 */

const CODEC_BYTE = LOBBY_CONNECTION_CODEC_BYTE;
const RECORD_KEY = 'E0R0';
/*
 * The entry's four 0x6503 fields. `ENTRY_HOST` is deliberately the same string
 * the 0x6510 trailer carries: FUN_001c8790 writes that trailer back into entry
 * +0x00, so a server whose two sources disagreed would silently destroy the
 * connect target it had just published (T30).
 */
const ENTRY_HOST = '10.0.0.1';
const ENTRY_NAME = 'E';
const ENTRY_DESCRIPTION = 'd';
const PAGE_FIELD = ENTRY_HOST;

const LOBBY_INITIALIZATION_REQUEST = Buffer.from(
  '0031011007cf00ff01002e5e18c9d5fea3c4f2f9cfacdcc0d8a5d4d6f1c4f0cdd49cc59c97de91ead8ebcbe493f88df0dec9d3d2e789cbd486',
  'hex'
);
const LOBBY_INITIALIZATION_RESPONSE = Buffer.from('0001021007cf00ff00', 'hex');
const KEYED_MANIFEST_REQUEST = Buffer.from('0000016103d000ff', 'hex');
const EMPTY_KEYED_MANIFEST_RESPONSE = Buffer.from('0002026103d000ff0000', 'hex');
const COMMAND_6212_REQUEST = Buffer.from('0000016212d100ff', 'hex');
const COMMAND_6212_CLIENT_DEFAULT_RESPONSE = Buffer.from('0000026212d1ffff', 'hex');
const COMMAND_6203_REQUEST = Buffer.from('0004016203d200ff000252d2', 'hex');

/**
 * The area table, and the eight frames that carry it.
 *
 * The transfer is not optional decoration in this transcript: `0x6203` mode 2
 * routes the client past the fetch, its table at `0x361a70` is never written, and
 * `FUN_005ad350.c:31` then refuses every area. Mode 1 is what this ladder now
 * serves, so the ladder has to walk the seven `0x6204` round trips a client
 * walks.
 *
 * SEQUENCES ARE SYNTHETIC. No V2 session has ever contained a `0x6204`, so there
 * are no captured bytes to use; `0xe0..0xe6` sit outside this file's captured run
 * `0xcf..0xd9` so they cannot be mistaken for capture. The byte-exact oracle for
 * these two commands is V1's own wire, replayed at V1's own sequences in
 * `test/tcp10127-lobby-initialization.test.js`.
 */
const AREA_TABLE = createV1ObservedAreaTable();
const AREA_TRANSFER_FIRST_SEQUENCE = 0xe0;

function frame({ command, sequence, payload, direction = 0x01, error = 0, unknown7 = 0xff }) {
  const header = Buffer.alloc(8);
  header.writeUInt16BE(payload.length, 0);
  header[2] = direction;
  header.writeUInt16BE(command, 3);
  header[5] = sequence;
  header[6] = error;
  header[7] = unknown7;
  return Buffer.concat([header, payload]);
}

/** `[u8 mode 1][snapField version][BE16 chunkCount][BE32 length per chunk]`. */
const COMMAND_6203_RESPONSE = frame({
  command: 0x6203,
  direction: 0x02,
  sequence: COMMAND_6203_REQUEST[5],
  payload: Buffer.concat([
    Buffer.from([0x01]),
    encodeSnapField({
      plain: AREA_TABLE.version,
      maximumDecodedLength: AREA_TABLE_TRANSFER.maximumVersionLength,
      sequence: COMMAND_6203_REQUEST[5],
      unknownCodecByte: CODEC_BYTE
    }),
    (() => {
      const table = Buffer.alloc(2 + 4);
      table.writeUInt16BE(1, 0);
      table.writeUInt32BE(AREA_TABLE.byteLength, 2);
      return table;
    })()
  ])
});

/** `FUN_001c4c80`: BE16 chunk index, BE32 offset, the literal BE16 0x2f2. */
const AREA_TRANSFER = [];
for (let offset = 0, index = 0; offset < AREA_TABLE.byteLength;
  offset += AREA_TABLE_TRANSFER.sliceLength, index += 1) {
  const sequence = (AREA_TRANSFER_FIRST_SEQUENCE + index) & 0xff;
  const requestPayload = Buffer.alloc(8);
  requestPayload.writeUInt16BE(0, 0);
  requestPayload.writeUInt32BE(offset, 2);
  requestPayload.writeUInt16BE(AREA_TABLE_TRANSFER.sliceLength, 6);
  const replyHeader = Buffer.alloc(6);
  replyHeader.writeUInt16BE(0, 0);
  replyHeader.writeUInt32BE(offset, 2);
  AREA_TRANSFER.push({
    request: frame({ command: 0x6204, sequence, payload: requestPayload }),
    response: frame({
      command: 0x6204,
      direction: 0x02,
      sequence,
      payload: Buffer.concat([
        replyHeader,
        encodeSnapField({
          plain: AREA_TABLE.sliceAt({ chunkIndex: 0, offset }).data,
          maximumDecodedLength: AREA_TABLE_TRANSFER.sliceLength,
          sequence,
          unknownCodecByte: CODEC_BYTE
        })
      ])
    })
  });
}
const AREA_TRANSFER_REQUESTS = Buffer.concat(AREA_TRANSFER.map((slice) => slice.request));
const AREA_TRANSFER_RESPONSES = Buffer.concat(AREA_TRANSFER.map((slice) => slice.response));
const COMMAND_6211_REQUEST = Buffer.from('0000016211d300ff', 'hex');
const COMMAND_6211_CLIENT_DEFAULT_RESPONSE = Buffer.from('0000026211d3ffff', 'hex');
const COMMAND_6213_REQUEST = Buffer.from('0000016213d400ff', 'hex');
const COMMAND_6213_CLIENT_DEFAULT_RESPONSE = Buffer.from('0000026213d4ffff', 'hex');
const COMMAND_6501_REQUEST = Buffer.from('0004016501d500ff00000000', 'hex');
/**
 * Mode 1: `[u8 1][BE32 refetch cooldown ticks][BE32 cookie]`, both zero.
 * `FUN_001c6e80` reads them into `0x365e04`/`0x365e00`, sets `0x365e1a = 8` and
 * routes to phase 6, which is the `0x6503` builder.
 */
const COMMAND_6501_MODE1_RESPONSE = Buffer.from('0009026501d500ff010000000000000000', 'hex');
/**
 * `FUN_001c7000`: builder index 0x20, direction 1, status 0, then BE16
 * `0x365e18` (offset already received, 0) and BE16 `0x365e1a` (count wanted,
 * which the mode-1 reply just set to 8).
 *
 * SEQUENCE IS SYNTHETIC. Every other frame in this file carries the sequence
 * byte from a real capture, but no capture has ever contained a `0x6503` - V2
 * has never sent mode 1 before - so there is no captured byte to use. `0xda` is
 * chosen outside the captured run `0xcf..0xd9` precisely so it cannot be
 * mistaken for one. The frame carries no encoded field, so nothing in the
 * REQUEST depends on it; the reply's fields are keyed on it and are derived
 * below.
 */
const COMMAND_6503_REQUEST = Buffer.from('0004016503da00ff00000008', 'hex');

/**
 * The `0x6503` reply, byte for byte.
 *
 *   0023        payload length 35 = 5 header bytes + 12 + 5 + 8 + 5
 *   02 6503     server direction, command
 *   da 00 ff    sequence (synthetic, see above), status, unknown7
 *   0001        total       -> 0x365e1e   one entry
 *   0000        batchStart  -> 0x365e18
 *   01          batchCount  -> 0x365e1c
 *   000a5c56 a6a2bcacbda68198   snapField '10.0.0.1'  -> entry +0x00  host
 *   00035b1f d2                 snapField 'E'         -> entry +0x3f  name
 *   0000000000000000            eight raw bytes       -> entry +0x4f
 *   00035b3e f3                 snapField 'd'         -> entry +0x57  description
 *
 * Each field envelope is `[BE16 plaintextLength+2][BE16 checksum][ciphertext]`,
 * so 8 plaintext bytes give the length word `0x000a`. The three fields were
 * derived from the fixture and then checked by decoding them back through
 * `decodeSnapField` at this sequence; the structural test below re-checks them
 * against the directory rather than against this literal.
 */
const COMMAND_6503_RESPONSE = Buffer.from(
  '0023026503da00ff' +
  '0001000001' +
  '000a5c56a6a2bcacbda68198' +
  '00035b1fd2' +
  '0000000000000000' +
  '00035b3ef3',
  'hex'
);
const COMMAND_6502_REQUEST = Buffer.from('0008016502d600ff00000000000257d7', 'hex');
const COMMAND_6504_REQUEST = Buffer.from('0008016504d700ff00000008000258d8', 'hex');
const COMMAND_1004_REQUEST = Buffer.from('0000011004d900ff', 'hex');
const COMMAND_1004_RESPONSE = Buffer.from('0000021004d900ff', 'hex');

const COMMAND_6510_SEQUENCE = 0xd8;

/**
 * `FUN_001c85c0` sends one encoded field per resident record - the record's own
 * `unknownField0`, which the server supplied in `0x6504` - and then the entry's
 * current `+0x00` field. On the first pass that entry field is still empty, and
 * `000258d8` is byte-identical to the captured client's own empty field at this
 * sequence.
 */
function buildCommand6510Request(key) {
  const payload = Buffer.concat([
    Buffer.from([1]),
    encodeSnapField({
      plain: Buffer.from(key, 'latin1'),
      maximumDecodedLength: 0x0f,
      sequence: COMMAND_6510_SEQUENCE,
      unknownCodecByte: CODEC_BYTE
    }),
    Buffer.from('000258d8', 'hex')
  ]);
  const header = Buffer.alloc(8);
  header.writeUInt16BE(payload.length, 0);
  header[2] = 0x01;
  header.writeUInt16BE(0x6510, 3);
  header[5] = COMMAND_6510_SEQUENCE;
  header[6] = 0x00;
  header[7] = 0xff;
  return Buffer.concat([header, payload]);
}

function buildDirectory() {
  return createDirectoryState({
    provenance: DIRECTORY_PROVENANCE.TEST_FIXTURE,
    entries: [{
      entryId: 'entry-0',
      host: Buffer.from(ENTRY_HOST, 'latin1'),
      name: Buffer.from(ENTRY_NAME, 'latin1'),
      raw8: Buffer.alloc(8),
      description: Buffer.from(ENTRY_DESCRIPTION, 'latin1'),
      pageField: Buffer.from(PAGE_FIELD, 'latin1'),
      command6502Unknown0: 0x0000002a,
      command6502Unknown1: 0x0000002b,
      records: [{
        recordId: 'record-0',
        unknownField0: Buffer.from(RECORD_KEY, 'latin1'),
        unknownField1: Buffer.from('F1', 'latin1'),
        unknownRaw8: Buffer.from('0102030405060708', 'hex'),
        unknownField2: Buffer.from('DETAIL', 'latin1'),
        unknownWord0: 0x0102,
        unknownWord1: 0x0304,
        unknownDword: 0x05060708,
        unknownWord6510: 0x0009
      }]
    }]
  });
}

function buildService({ logger = () => {} } = {}) {
  const providers = createDirectoryBackedProviders({
    directoryProvider: new StaticDirectoryProvider(buildDirectory().assertServable({
      allowTestFixture: true
    }))
  });
  const server = createTcp10127Service({
    resolveConnectionPurpose: () => 'lobby-initialization',
    createConnectionProviders: providers.createConnectionProviders,
    logger
  });
  return { server, providers };
}

const LADDER_REQUESTS = Buffer.concat([
  LOBBY_INITIALIZATION_REQUEST,
  KEYED_MANIFEST_REQUEST,
  COMMAND_6212_REQUEST,
  COMMAND_6203_REQUEST,
  AREA_TRANSFER_REQUESTS,
  COMMAND_6211_REQUEST,
  COMMAND_6213_REQUEST,
  COMMAND_6501_REQUEST,
  COMMAND_6503_REQUEST,
  COMMAND_6502_REQUEST,
  COMMAND_6504_REQUEST,
  buildCommand6510Request(RECORD_KEY),
  COMMAND_1004_REQUEST
]);

/**
 * Frozen expectation for the whole state-backed ladder.
 *
 * Every byte after the first six frames comes from directory state: the
 * `0x6502` mode-1 fields are the entry's two configured BE32 values, the
 * `0x6504` record is the configured record, and the `0x6510` reply carries the
 * configured `unknownWord6510` and page field.
 */
/**
 * Every lobby connection now opens with the server-initiated 0x6001 challenge
 * (T20): direction 0x10, command 0x6001, sequence 0x01, empty payload. The
 * captured client never speaks until it has received this.
 */
const LOBBY_CHALLENGE = Buffer.from('0000106001010000', 'hex');

const LADDER_RESPONSES = Buffer.concat([
  LOBBY_CHALLENGE,
  LOBBY_INITIALIZATION_RESPONSE,
  EMPTY_KEYED_MANIFEST_RESPONSE,
  COMMAND_6212_CLIENT_DEFAULT_RESPONSE,
  COMMAND_6203_RESPONSE,
  AREA_TRANSFER_RESPONSES,
  COMMAND_6211_CLIENT_DEFAULT_RESPONSE,
  COMMAND_6213_CLIENT_DEFAULT_RESPONSE,
  COMMAND_6501_MODE1_RESPONSE,
  // total=1, batchStart=0, batchCount=1, then the configured entry: encoded
  // '10.0.0.1' (host), encoded 'E' (name), eight raw zero bytes, encoded 'd'
  // (description). Derived in DERIVATION.md-style below and checked field by
  // field by the structural test.
  COMMAND_6503_RESPONSE,
  // mode 1 with the entry's two configured BE32 values, 0x2a and 0x2b.
  Buffer.from('0009026502d600ff010000002a0000002b', 'hex'),
  // total=1, start=0, count=1, then the configured record: encoded 'E0R0',
  // encoded 'F1', the eight raw bytes, encoded 'DETAIL', word0, word1, dword.
  Buffer.from(
    '002d026504d700ff' +
    '0001000001' +
    '000658cedfa1c5ab' +
    '0004584edca0' +
    '0102030405060708' +
    '0008598aded4c3dadfd9' +
    '0102030405060708',
    'hex'
  ),
  /*
   * Echoed count 1, the configured unknownWord6510 0x0009, then the ENTRY HOST
   * as the trailing field - `FUN_001c8790` writes it straight to entry +0x00,
   * which is what the client later resolves as a connect target (T30/T31).
   * Payload 0x0f = 1 + 2 + 12: '10.0.0.1' is 8 plaintext bytes, so the field
   * envelope is 12 and its length word is 0x000a.
   */
  Buffer.from('000f026510d800ff010009000a5a54a4a0baaabfa4bfa6', 'hex'),
  COMMAND_1004_RESPONSE
]);

async function listen(server) {
  await new Promise((resolve, reject) => {
    server.once('error', reject);
    server.listen(0, '127.0.0.1', resolve);
  });
  return server.address().port;
}

/**
 * V2 never closes a lobby connection first (R-019), so every client socket in
 * this file is destroyed rather than half-closed with end(); otherwise the
 * server would hold the connection open and server.close() would never settle.
 */
async function close(server) {
  await new Promise((resolve) => server.close(resolve));
}

function exchange(port, requests, expectedLength) {
  return new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port }, () => {
      socket.write(requests);
    });
    let bytes = Buffer.alloc(0);
    socket.on('data', (chunk) => {
      bytes = Buffer.concat([bytes, chunk]);
      if (bytes.length >= expectedLength) {
        socket.destroy();
        resolve(bytes);
      }
    });
    // A refused frame tears the connection down, and without this the promise
    // would simply never settle - the test would hang for the runner's whole
    // timeout instead of reporting how far the ladder actually got.
    socket.on('close', () => resolve(bytes));
    socket.on('error', reject);
  });
}

test('refuses to combine a per-connection factory with flat providers', () => {
  assert.throws(
    () => createTcp10127Service({
      resolveConnectionPurpose: () => 'lobby-initialization',
      createConnectionProviders: () => ({ resolveCommand6501Response: () => ({ mode: 0 }) }),
      resolveCommand6501Response: () => ({ mode: 0 }),
      resolveCommand6213Words: () => new Array(8).fill(0)
    }),
    (error) => error instanceof TypeError &&
      /cannot be combined with flat providers/.test(error.message) &&
      /resolveCommand6213Words/.test(error.message) &&
      /resolveCommand6501Response/.test(error.message)
  );
});

test('walks the whole ladder on a real socket with every byte sourced from state', async (t) => {
  const events = [];
  const { server } = buildService({ logger: (event) => events.push(event) });
  const port = await listen(server);
  t.after(() => close(server));

  const received = await exchange(port, LADDER_REQUESTS, LADDER_RESPONSES.length);
  assert.equal(received.toString('hex'), LADDER_RESPONSES.toString('hex'));
  assert.equal(events.some((event) => event.type === 'protocol-error'), false);
  assert.equal(events.some((event) => event.type === 'unimplemented-frame'), false);
});

test('the configured record and page field are what actually reach the wire', async (t) => {
  const { server } = buildService();
  const port = await listen(server);
  t.after(() => close(server));

  const received = await exchange(port, LADDER_REQUESTS, LADDER_RESPONSES.length);

  // Decode the 0x6504 record back out of the response rather than trusting the
  // frozen hex: a structural regression must fail even if the literal is stale.
  let offset = 0;
  const frames = [];
  while (offset < received.length) {
    const length = 8 + received.readUInt16BE(offset);
    frames.push(decodeTcp10127Frame(received.subarray(offset, offset + length)));
    offset += length;
  }
  // 0x6503 - the entry list. Decoded field by field, in the parser's own order
  // and against its own bounds, because these four fields are the ones that
  // populate Server Select and a stale literal must not be able to hide a
  // regression in any of them.
  const list = frames.find((frame) => frame.command === 0x6503);
  assert.equal(list.payload.readUInt16BE(0), 1, 'total is the directory entry count');
  assert.equal(list.payload.readUInt16BE(2), 0, 'batchStart is the requested offset');
  assert.equal(list.payload[4], 1, 'one entry in this batch');
  const entryFields = [];
  let cursor = 5;
  for (const bound of [0x3e, 0x0f]) {
    const lengthWord = list.payload.readUInt16BE(cursor);
    const field = list.payload.subarray(cursor, cursor + 2 + lengthWord);
    entryFields.push(decodeSnapField({
      field, maximumDecodedLength: bound, sequence: list.sequence, unknownCodecByte: CODEC_BYTE
    }));
    cursor += 2 + lengthWord;
  }
  const raw8 = list.payload.subarray(cursor, cursor + 8);
  cursor += 8;
  const descriptionLengthWord = list.payload.readUInt16BE(cursor);
  entryFields.push(decodeSnapField({
    field: list.payload.subarray(cursor, cursor + 2 + descriptionLengthWord),
    maximumDecodedLength: 0xff,
    sequence: list.sequence,
    unknownCodecByte: CODEC_BYTE
  }));
  cursor += 2 + descriptionLengthWord;
  assert.equal(cursor, list.payload.length, 'the entry consumes the whole 0x6503 payload');
  assert.equal(entryFields[0].toString('latin1'), ENTRY_HOST, 'entry +0x00 is the connect host');
  assert.equal(entryFields[1].toString('latin1'), ENTRY_NAME, 'entry +0x3f is the display name');
  assert.equal(raw8.toString('hex'), '0000000000000000', 'entry +0x4f is eight raw bytes');
  assert.equal(
    entryFields[2].toString('latin1'), ENTRY_DESCRIPTION, 'entry +0x57 is the description'
  );

  const batch = frames.find((frame) => frame.command === 0x6504);
  assert.equal(batch.payload.readUInt16BE(0), 1, 'unknownTotal is the entry record count');
  assert.equal(batch.payload.readUInt16BE(2), 0, 'unknownStart is the connection cursor');
  assert.equal(batch.payload[4], 1, 'one record in this batch');
  const field0 = decodeSnapField({
    field: batch.payload.subarray(5),
    maximumDecodedLength: 0x0f,
    sequence: batch.sequence,
    unknownCodecByte: CODEC_BYTE
  });
  assert.equal(field0.toString('latin1'), RECORD_KEY);

  const keyed = frames.find((frame) => frame.command === 0x6510);
  assert.equal(keyed.payload[0], 1, 'the request count is echoed');
  assert.equal(keyed.payload.readUInt16BE(1), 0x0009, 'the configured unknownWord6510');
  const trailing = decodeSnapField({
    field: keyed.payload.subarray(3),
    maximumDecodedLength: 0x3e,
    sequence: keyed.sequence,
    unknownCodecByte: CODEC_BYTE
  });
  assert.equal(trailing.toString('latin1'), PAGE_FIELD);
});

test('serves the ladder identically when it arrives one byte at a time', async (t) => {
  const { server } = buildService();
  const port = await listen(server);
  t.after(() => close(server));

  const received = await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port }, () => {
      for (const byte of LADDER_REQUESTS) {
        socket.write(Buffer.from([byte]));
      }
    });
    let bytes = Buffer.alloc(0);
    socket.on('data', (chunk) => {
      bytes = Buffer.concat([bytes, chunk]);
      if (bytes.length >= LADDER_RESPONSES.length) {
        socket.end();
        resolve(bytes);
      }
    });
    socket.on('error', reject);
  });
  assert.equal(received.toString('hex'), LADDER_RESPONSES.toString('hex'));
});

test('two simultaneous clients each get their own projection and identical bytes', async (t) => {
  const { server, providers } = buildService();
  const port = await listen(server);
  t.after(() => close(server));

  const [first, second] = await Promise.all([
    exchange(port, LADDER_REQUESTS, LADDER_RESPONSES.length),
    exchange(port, LADDER_REQUESTS, LADDER_RESPONSES.length)
  ]);
  assert.equal(first.toString('hex'), LADDER_RESPONSES.toString('hex'));
  assert.equal(second.toString('hex'), LADDER_RESPONSES.toString('hex'));
  assert.equal(providers.openConnectionCount(), 2);
});

test('closing a connection drops its projection and leaves the directory servable', async (t) => {
  const { server, providers } = buildService();
  const port = await listen(server);
  t.after(() => close(server));

  await exchange(port, LADDER_REQUESTS, LADDER_RESPONSES.length);
  await new Promise((resolve) => setTimeout(resolve, 50));
  assert.equal(providers.openConnectionCount(), 0);

  // A fresh connection still walks the full ladder from authoritative state.
  const again = await exchange(port, LADDER_REQUESTS, LADDER_RESPONSES.length);
  assert.equal(again.toString('hex'), LADDER_RESPONSES.toString('hex'));
});

/**
 * A TWO-ENTRY walk, end to end over a real socket.
 *
 * This path has never been reachable. `0x365e1e` is written only by `0x6503`,
 * and both `FUN_001c7a70` and `FUN_001c8790` bound their entry loop with it, so
 * while V2 answered `0x6501` with mode 0 the client could never walk past entry
 * 0 no matter how many entries the server held. Everything V2's projection
 * models about multiple entries was therefore unexercised against the framing.
 *
 * The request stream below is what `FUN_001c7000`, `FUN_001c7580`,
 * `FUN_001c7980` and `FUN_001c85c0` build, in the order `FUN_001c70b0`,
 * `FUN_001c7680`, `FUN_001c7a70` and `FUN_001c8790` route them.
 */
test('walks a two-entry directory through 0x6503 and one 0x6510 per entry', async (t) => {
  const events = [];
  const directory = createDirectoryState({
    provenance: DIRECTORY_PROVENANCE.TEST_FIXTURE,
    entries: [0, 1].map((index) => ({
      entryId: `entry-${index}`,
      // Distinct hosts: the 0x6510 trailer is written back to the entry the walk
      // is on, so a server that answered every entry with entry 0's host would
      // overwrite the connect target of every other one.
      host: Buffer.from(`10.0.0.${index + 1}`, 'latin1'),
      name: Buffer.from(`E${index}`, 'latin1'),
      raw8: Buffer.alloc(8),
      description: Buffer.from(`entry ${index}`, 'latin1'),
      pageField: Buffer.from(`P${index}`, 'latin1'),
      command6502Unknown0: 0x2a + index,
      command6502Unknown1: 0x2b + index,
      records: [{
        recordId: `record-${index}`,
        unknownField0: Buffer.from(`E${index}R0`, 'latin1'),
        unknownField1: Buffer.from('F1', 'latin1'),
        unknownRaw8: Buffer.alloc(8),
        unknownField2: Buffer.from('DETAIL', 'latin1'),
        unknownWord0: 0,
        unknownWord1: 30,
        unknownDword: 0,
        unknownWord6510: 0x0100 + index
      }]
    }))
  });
  const providers = createDirectoryBackedProviders({
    directoryProvider: new StaticDirectoryProvider(
      directory.assertServable({ allowTestFixture: true })
    )
  });
  const server = createTcp10127Service({
    resolveConnectionPurpose: () => 'lobby-initialization',
    createConnectionProviders: providers.createConnectionProviders,
    logger: (event) => events.push(event)
  });
  const port = await listen(server);
  t.after(() => close(server));

  const request = (command, sequence, payload = Buffer.alloc(0)) => {
    const header = Buffer.alloc(8);
    header.writeUInt16BE(payload.length, 0);
    header[2] = 0x01;
    header.writeUInt16BE(command, 3);
    header[5] = sequence;
    header[6] = 0x00;
    header[7] = 0xff;
    return Buffer.concat([header, payload]);
  };
  const field = (text, bound, sequence) => encodeSnapField({
    plain: Buffer.from(text, 'latin1'),
    maximumDecodedLength: bound,
    sequence,
    unknownCodecByte: CODEC_BYTE
  });
  const window = (start, count) => {
    const payload = Buffer.alloc(4);
    payload.writeUInt16BE(start, 0);
    payload.writeUInt16BE(count, 2);
    return payload;
  };
  // FUN_001c7580: one BE32 cookie then the entry's own +0x00 field.
  const enter = (sequence, host) =>
    request(0x6502, sequence, Buffer.concat([Buffer.alloc(4), field(host, 0x3e, sequence)]));
  // FUN_001c7980: two BE16 values then the entry's +0x00 field.
  const fetch = (sequence, host) =>
    request(0x6504, sequence, Buffer.concat([window(0, 8), field(host, 0x3e, sequence)]));
  // FUN_001c85c0: a count byte, that many record keys, then the entry's +0x00.
  const keys = (sequence, key, host) => request(0x6510, sequence, Buffer.concat([
    Buffer.from([1]), field(key, 0x0f, sequence), field(host, 0x3e, sequence)
  ]));

  const requests = Buffer.concat([
    LOBBY_INITIALIZATION_REQUEST,
    KEYED_MANIFEST_REQUEST,
    COMMAND_6212_REQUEST,
    COMMAND_6203_REQUEST,
    AREA_TRANSFER_REQUESTS,
    COMMAND_6211_REQUEST,
    COMMAND_6213_REQUEST,
    COMMAND_6501_REQUEST,
    request(0x6503, 0x20, window(0, 8)),
    enter(0x21, '10.0.0.1'),
    fetch(0x22, '10.0.0.1'),
    // Entry 0's records are complete, so FUN_001c7a70 advances 0x365e0c to 1 and,
    // because 1 < 0x365e1e, routes back to phase 8 for the NEXT entry rather
    // than to 0x6510. That branch only exists once 0x6503 has set the total.
    enter(0x23, '10.0.0.2'),
    fetch(0x24, '10.0.0.2'),
    // Now the key exchange, once per entry, restarting at entry 0.
    keys(0x25, 'E0R0', '10.0.0.1'),
    keys(0x26, 'E1R0', '10.0.0.2'),
    request(0x1004, 0x27)
  ]);

  const expectedLength =
    LOBBY_CHALLENGE.length +
    LOBBY_INITIALIZATION_RESPONSE.length +
    EMPTY_KEYED_MANIFEST_RESPONSE.length +
    COMMAND_6212_CLIENT_DEFAULT_RESPONSE.length +
    COMMAND_6203_RESPONSE.length +
    AREA_TRANSFER_RESPONSES.length +
    COMMAND_6211_CLIENT_DEFAULT_RESPONSE.length +
    COMMAND_6213_CLIENT_DEFAULT_RESPONSE.length +
    COMMAND_6501_MODE1_RESPONSE.length +
    // 0x6503: header + total/start/count + two entries of host/name/raw8/description
    (8 + 5 + 2 * ((4 + 8) + (4 + 2) + 8 + (4 + 7))) +
    2 * (8 + 9) +                                   // two 0x6502 mode-1 replies
    2 * (8 + 5 + (4 + 4) + (4 + 2) + 8 + (4 + 6) + 8) +  // two 0x6504 batches
    2 * (8 + 1 + 2 + (4 + 8)) +                     // two 0x6510 replies
    COMMAND_1004_RESPONSE.length;

  const received = await exchange(port, requests, expectedLength);
  assert.equal(received.length, expectedLength, 'every frame in the two-entry walk was answered');
  assert.equal(events.some((event) => event.type === 'protocol-error'), false);
  assert.equal(events.some((event) => event.type === 'unimplemented-frame'), false);

  const frames = [];
  let offset = 0;
  while (offset < received.length) {
    const length = 8 + received.readUInt16BE(offset);
    frames.push(decodeTcp10127Frame(received.subarray(offset, offset + length)));
    offset += length;
  }
  assert.deepEqual(
    frames.map((frame) => frame.command),
    [0x6001, 0x1007, 0x6103, 0x6212, 0x6203,
      ...Array(AREA_TRANSFER.length).fill(0x6204),
      0x6211, 0x6213,
      0x6501, 0x6503, 0x6502, 0x6504, 0x6502, 0x6504, 0x6510, 0x6510, 0x1004]
  );

  // The entry list declares TWO, which is the value 0x365e1e takes and the one
  // the "n/N" counter and the per-entry loops are bounded by.
  const list = frames.find((frame) => frame.command === 0x6503);
  assert.equal(list.payload.readUInt16BE(0), 2, 'total');
  assert.equal(list.payload[4], 2, 'both entries in one batch');

  // Each 0x6510 answers with its OWN entry's word and its OWN entry's host.
  const answers = frames.filter((frame) => frame.command === 0x6510);
  assert.equal(answers.length, 2);
  for (const [index, answer] of answers.entries()) {
    assert.equal(answer.payload[0], 1, 'the requested count is echoed');
    assert.equal(answer.payload.readUInt16BE(1), 0x0100 + index, 'that entry’s current-player word');
    const trailing = decodeSnapField({
      field: answer.payload.subarray(3),
      maximumDecodedLength: 0x3e,
      sequence: answer.sequence,
      unknownCodecByte: CODEC_BYTE
    });
    assert.equal(trailing.toString('latin1'), `10.0.0.${index + 1}`);
  }
});

test('a 0x6510 key the connection does not hold closes the connection', async (t) => {
  const events = [];
  const { server } = buildService({ logger: (event) => events.push(event) });
  const port = await listen(server);
  t.after(() => close(server));

  const requests = Buffer.concat([
    LOBBY_INITIALIZATION_REQUEST,
    KEYED_MANIFEST_REQUEST,
    COMMAND_6212_REQUEST,
    COMMAND_6203_REQUEST,
    AREA_TRANSFER_REQUESTS,
    COMMAND_6211_REQUEST,
    COMMAND_6213_REQUEST,
    COMMAND_6501_REQUEST,
    COMMAND_6503_REQUEST,
    COMMAND_6502_REQUEST,
    COMMAND_6504_REQUEST,
    buildCommand6510Request('WRONG')
  ]);

  // Asserted on the server's own event: what matters is that V2 refuses the key
  // and tears the connection down, not how quickly the client observes it.
  const error = await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port }, () => {
      socket.write(requests);
    });
    socket.on('error', reject);
    const poll = setInterval(() => {
      const event = events.find((candidate) => candidate.type === 'protocol-error');
      if (event != null) {
        clearInterval(poll);
        socket.destroy();
        resolve(event);
      }
    }, 5);
    t.after(() => clearInterval(poll));
  });

  assert.notEqual(error, undefined, 'an unknown key must fail closed');
  assert.equal(error.errorCode, 'COMMAND_6510_RESPONSE_PROVIDER');
  assert.match(error.message, /not a record this connection currently holds/);
});
