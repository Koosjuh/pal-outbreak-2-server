import assert from 'node:assert/strict';
import net from 'node:net';
import test from 'node:test';

import { createTcp10127Service } from '../src/tcp/tcp10127-service.js';
import { encodeSnapField } from '../src/protocol/snap-field-codec.js';
import { AREA_TABLE_TRANSFER } from '../src/state/area-table.js';
import { createV1ObservedAreaTable } from '../src/state/area-table-v1.js';

const PRE_BROWSER_TRANSCRIPT = Buffer.from(
  '0000021001000000' +
  '0000021002000000' +
  '0000021004000000',
  'hex'
);

const LOBBY_INITIALIZATION_REQUEST = Buffer.from(
  '0031011007cf00ff01002e5e18c9d5fea3c4f2f9cfacdcc0d8a5d4d6f1c4f0cdd49cc59c97de91ead8ebcbe493f88df0dec9d3d2e789cbd486',
  'hex'
);
const LOBBY_INITIALIZATION_RESPONSE = Buffer.from('0001021007cf00ff00', 'hex');
/**
 * Every lobby connection opens with the server-initiated 0x6001 challenge (T20).
 * The captured client sends nothing on TCP 10127 until it has received a
 * server frame, so this prefixes every lobby-purpose response stream.
 */
const LOBBY_CHALLENGE = Buffer.from('0000106001010000', 'hex');
const KEYED_MANIFEST_REQUEST = Buffer.from('0000016103d000ff', 'hex');
const EMPTY_KEYED_MANIFEST_RESPONSE = Buffer.from('0002026103d000ff0000', 'hex');
const PLAYER_COUNT_REQUEST = Buffer.from('0000016212d100ff', 'hex');
const PLAYER_COUNT_RESPONSE = Buffer.from('0004026212d100ff00000001', 'hex');
const COMMAND_6203_REQUEST = Buffer.from('0004016203d200ff000252d2', 'hex');
/**
 * The mode-1 area-table declaration the service's default table produces.
 *
 * These transcripts then go straight from `0x6203` to `0x6211`, which is the
 * CACHE-HIT branch `FUN_001c4960.c:46-49` takes when the version the server sent
 * equals the client's cached copy - a legitimate client path, and the one that
 * keeps these tests about the SERVICE (framing, fragmentation, teardown) rather
 * than about the blob. The seven-slice transfer is walked end to end over a real
 * socket in `test/tcp10127-state-backed-ladder.test.js`, and byte-exactly
 * against V1's own wire in `test/tcp10127-lobby-initialization.test.js`.
 */
const AREA_TABLE = createV1ObservedAreaTable();
const COMMAND_6203_RESPONSE = (() => {
  const version = encodeSnapField({
    plain: AREA_TABLE.version,
    maximumDecodedLength: AREA_TABLE_TRANSFER.maximumVersionLength,
    sequence: COMMAND_6203_REQUEST[5],
    unknownCodecByte: 0
  });
  const chunkTable = Buffer.alloc(6);
  chunkTable.writeUInt16BE(1, 0);
  chunkTable.writeUInt32BE(AREA_TABLE.byteLength, 2);
  const payload = Buffer.concat([Buffer.from([0x01]), version, chunkTable]);
  const header = Buffer.alloc(8);
  header.writeUInt16BE(payload.length, 0);
  header[2] = 0x02;
  header.writeUInt16BE(0x6203, 3);
  header[5] = COMMAND_6203_REQUEST[5];
  header[7] = 0xff;
  return Buffer.concat([header, payload]);
})();
const COMMAND_6211_REQUEST = Buffer.from('0000016211d300ff', 'hex');
const COMMAND_6211_RESPONSE = Buffer.from('0004026211d300ff00000000', 'hex');
const COMMAND_6213_REQUEST = Buffer.from('0000016213d400ff', 'hex');
const COMMAND_6213_RESPONSE = Buffer.from(
  '0010026213d400ff00000000000000000000000000000000',
  'hex'
);
const PLAYER_COUNT_CLIENT_DEFAULT_RESPONSE = Buffer.from('0000026212d1ffff', 'hex');
const COMMAND_6211_CLIENT_DEFAULT_RESPONSE = Buffer.from('0000026211d3ffff', 'hex');
const COMMAND_6213_CLIENT_DEFAULT_RESPONSE = Buffer.from('0000026213d4ffff', 'hex');
const COMMAND_6501_REQUEST = Buffer.from('0004016501d500ff00000000', 'hex');
const COMMAND_6501_MODE0_RESPONSE = Buffer.from('0001026501d500ff00', 'hex');
const COMMAND_6501_MODE1_RESPONSE = Buffer.from(
  '0009026501d500ff011234567889abcdef',
  'hex'
);
const COMMAND_6502_REQUEST = Buffer.from('0008016502d600ff00000000000257d7', 'hex');
const COMMAND_6502_MODE1_RESPONSE = Buffer.from(
  '0009026502d600ff010000000100000001',
  'hex'
);
/**
 * `FUN_001c7000` appends two BE16 values - the offset already received and the
 * count wanted - so the request payload is four bytes, not none. It was
 * zero-length here while `0x6503` was merely observed; T32 implemented it.
 */
const COMMAND_6503_REQUEST = Buffer.from('0004016503d600ff00000008', 'hex');
/**
 * total=1, batchStart=0, batchCount=1, then one entry: snapField '10.0.0.1',
 * snapField 'E', eight raw bytes, snapField 'd', all keyed on sequence 0xd6 with
 * codec byte 0. The byte-exact transcript for this reply lives in
 * `tcp10127-state-backed-ladder.test.js`; here it only has to be the answer the
 * provider asked for.
 */
const COMMAND_6503_RESPONSE_LENGTH =
  8 +                    // frame header
  5 +                    // total, batchStart, batchCount
  (4 + '10.0.0.1'.length) +
  (4 + 'E'.length) +
  8 +
  (4 + 'd'.length);
const COMMAND_6503_ENTRY = Object.freeze({
  host: Buffer.from('10.0.0.1', 'latin1'),
  name: Buffer.from('E', 'latin1'),
  raw8: Buffer.alloc(8),
  description: Buffer.from('d', 'latin1')
});
const COMMAND_6504_REQUEST = Buffer.from('0008016504d700ff00000008000258d8', 'hex');
const COMMAND_6504_RESPONSE = Buffer.from(
  '0036026504d700ff' +
  '0001000001' +
  '000a59dac9ddd8cfa6a5a2a7' +
  '00065909d5c1d2d5' +
  '0000000000000000' +
  '000b5b39cef4e4efb6c6fef9e6' +
  '00000008c00002c4',
  'hex'
);
// FUN_001c85c0 batch: count byte 0x01, one encoded 'SLOT0001' record field, then
// the trailing field. Its empty-field bytes 000258d8 are byte-identical to the
// captured client's own empty field at the same p5, cross-checking the codec.
const COMMAND_6510_REQUEST = Buffer.from(
  '0011016510d800ff01000a5adbc6dcdbcea1a4a1a6000258d8',
  'hex'
);
// Echoed count 0x01, one BE16 record word, then the 0x3e-bounded trailing field.
const COMMAND_6510_RESPONSE = Buffer.from(
  '000f026510d800ff010000000a5adbc6dcdbcea1a4a1a6',
  'hex'
);
// FUN_001c8dd0 appends no fields; FUN_001c8e90 consumes no reply payload.
const COMMAND_1004_REQUEST = Buffer.from('0000011004d900ff', 'hex');
const COMMAND_1004_RESPONSE = Buffer.from('0000021004d900ff', 'hex');

async function listen(server) {
  await new Promise((resolve, reject) => {
    server.once('error', reject);
    server.listen(0, '127.0.0.1', resolve);
  });
  return server.address().port;
}

async function close(server) {
  await new Promise((resolve) => server.close(resolve));
}

test('sends the captured pre-browser transcript in order on a real socket', async (t) => {
  const events = [];
  const server = createTcp10127Service({
    resolveConnectionPurpose: () => 'pre-browser',
    preBrowserDelaysMs: [0, 1, 2],
    logger: (event) => events.push(event)
  });
  const port = await listen(server);
  t.after(() => close(server));

  const received = await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port });
    let bytes = Buffer.alloc(0);
    socket.on('data', (chunk) => {
      bytes = Buffer.concat([bytes, chunk]);
      if (bytes.length === PRE_BROWSER_TRANSCRIPT.length) {
        socket.end();
        resolve(bytes);
      }
    });
    socket.on('error', reject);
  });

  assert.deepEqual(received, PRE_BROWSER_TRANSCRIPT);
  assert.deepEqual(
    events.filter((event) => event.type === 'frame-send').map((event) => event.command),
    [0x1001, 0x1002, 0x1004]
  );
});

test('closes without protocol output when connection purpose is unresolved', async (t) => {
  const events = [];
  const server = createTcp10127Service({
    resolveConnectionPurpose: () => null,
    logger: (event) => events.push(event)
  });
  const port = await listen(server);
  t.after(() => close(server));

  const received = await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port });
    let bytes = Buffer.alloc(0);
    socket.on('data', (chunk) => { bytes = Buffer.concat([bytes, chunk]); });
    socket.on('close', () => resolve(bytes));
    socket.on('error', reject);
  });

  assert.equal(received.length, 0);
  assert.ok(events.some((event) =>
    event.type === 'protocol-error' && event.errorCode === 'UNRESOLVED_CONNECTION_PURPOSE'
  ));
});

test('rejects any client bytes in the captured pre-browser purpose', async (t) => {
  const events = [];
  const server = createTcp10127Service({
    resolveConnectionPurpose: () => 'pre-browser',
    preBrowserDelaysMs: [100, 200, 300],
    logger: (event) => events.push(event)
  });
  const port = await listen(server);
  t.after(() => close(server));

  await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port }, () => socket.write(Buffer.from([0])));
    socket.on('close', resolve);
    socket.on('error', reject);
  });

  assert.ok(events.some((event) =>
    event.type === 'protocol-error' && event.errorCode === 'UNEXPECTED_PRE_BROWSER_BYTES'
  ));
  assert.equal(events.filter((event) => event.type === 'frame-send').length, 0);
});

test('does not lose early bytes while an asynchronous purpose resolver is pending', async (t) => {
  const events = [];
  let resolvePurpose;
  const server = createTcp10127Service({
    resolveConnectionPurpose: () => new Promise((resolve) => { resolvePurpose = resolve; }),
    preBrowserDelaysMs: [100, 200, 300],
    logger: (event) => events.push(event)
  });
  const port = await listen(server);
  t.after(() => close(server));

  await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port }, () => {
      socket.write(Buffer.from([0]));
      setImmediate(() => resolvePurpose('pre-browser'));
    });
    socket.on('close', resolve);
    socket.on('error', reject);
  });

  assert.ok(events.some((event) =>
    event.type === 'protocol-error' && event.errorCode === 'UNEXPECTED_PRE_BROWSER_BYTES'
  ));
  assert.equal(events.filter((event) => event.type === 'frame-send').length, 0);
});

test('contains a synchronous purpose-resolver failure to the connection', async (t) => {
  const events = [];
  const server = createTcp10127Service({
    resolveConnectionPurpose: () => { throw new Error('resolver unavailable'); },
    logger: (event) => events.push(event)
  });
  const port = await listen(server);
  t.after(() => close(server));

  await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port });
    socket.on('close', resolve);
    socket.on('error', reject);
  });

  assert.ok(events.some((event) =>
    event.type === 'protocol-error' && event.errorCode === 'CONNECTION_PURPOSE_RESOLVER'
  ));
});

test('reassembles a fragmented 0x1007 request on a lobby-initialization connection', async (t) => {
  const events = [];
  const server = createTcp10127Service({
    resolveConnectionPurpose: () => 'lobby-initialization',
    resolveCommand6212Value: () => 1,
    resolveCommand6211Value: () => 0,
    resolveCommand6213Words: () => Array(8).fill(0),
    resolveCommand6501Response: () => ({ mode: 0 }),
    logger: (event) => events.push(event)
  });
  const port = await listen(server);
  t.after(() => close(server));

  const received = await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port }, () => {
      socket.write(LOBBY_INITIALIZATION_REQUEST.subarray(0, 1));
      socket.write(LOBBY_INITIALIZATION_REQUEST.subarray(1, 7));
      socket.write(LOBBY_INITIALIZATION_REQUEST.subarray(7, 31));
      socket.write(LOBBY_INITIALIZATION_REQUEST.subarray(31));
    });
    let bytes = Buffer.alloc(0);
    socket.on('data', (chunk) => {
      // The challenge arrives first and separately from the 0x1007 reply, so
      // accumulate rather than taking the first chunk.
      bytes = Buffer.concat([bytes, chunk]);
      if (bytes.length >= LOBBY_CHALLENGE.length + LOBBY_INITIALIZATION_RESPONSE.length) {
        socket.end();
        resolve(bytes);
      }
    });
    socket.on('error', reject);
  });

  assert.deepEqual(received, Buffer.concat([LOBBY_CHALLENGE, LOBBY_INITIALIZATION_RESPONSE]));
  assert.ok(events.some((event) =>
    event.type === 'frame-receive' && event.command === 0x1007 && event.length === 57
  ));
  assert.ok(events.some((event) =>
    event.type === 'frame-send' && event.command === 0x1007 &&
    event.state === 'awaiting-0x6103'
  ));
});

test('preserves early lobby bytes while an asynchronous purpose resolver is pending', async (t) => {
  let resolvePurpose;
  const server = createTcp10127Service({
    resolveConnectionPurpose: () => new Promise((resolve) => { resolvePurpose = resolve; }),
    resolveCommand6212Value: () => 1,
    resolveCommand6211Value: () => 0,
    resolveCommand6213Words: () => Array(8).fill(0),
    resolveCommand6501Response: () => ({ mode: 0 })
  });
  const port = await listen(server);
  t.after(() => close(server));

  const received = await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port }, () => {
      socket.write(LOBBY_INITIALIZATION_REQUEST);
      setImmediate(() => resolvePurpose('lobby-initialization'));
    });
    socket.once('data', (chunk) => {
      socket.end();
      resolve(chunk);
    });
    socket.on('error', reject);
  });

  assert.deepEqual(received, Buffer.concat([LOBBY_CHALLENGE, LOBBY_INITIALIZATION_RESPONSE]));
});

test('bounds client bytes while purpose resolution is pending', async (t) => {
  const events = [];
  const server = createTcp10127Service({
    resolveConnectionPurpose: () => new Promise(() => {}),
    maxPendingBytes: 16,
    logger: (event) => events.push(event)
  });
  const port = await listen(server);
  t.after(() => close(server));

  await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port }, () => {
      socket.write(Buffer.alloc(17));
    });
    socket.on('close', resolve);
    socket.on('error', reject);
  });

  assert.ok(events.some((event) =>
    event.type === 'protocol-error' && event.errorCode === 'PRE_PURPOSE_BUFFER_LIMIT'
  ));
});

test('closes a lobby connection when its required 0x6501 resolver is missing', async (t) => {
  const events = [];
  const server = createTcp10127Service({
    resolveConnectionPurpose: () => 'lobby-initialization',
    logger: (event) => events.push(event)
  });
  const port = await listen(server);
  t.after(() => close(server));

  await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port });
    socket.on('close', resolve);
    socket.on('error', reject);
  });
  assert.ok(events.some((event) =>
    event.type === 'protocol-error' &&
    event.errorCode === 'MISSING_COMMAND_6501_RESPONSE_RESOLVER'
  ));
});

test('walks the whole lobby-initialization ladder from 0x1007 to the 0x1004 completion', async (t) => {
  const events = [];
  const resolverCalls = [];
  const server = createTcp10127Service({
    resolveConnectionPurpose: () => 'lobby-initialization',
    resolveCommand6501Response: (request) => {
      resolverCalls.push(request);
      return { mode: 0 };
    },
    resolveCommand6502Response: (request) => {
      resolverCalls.push(request);
      return { mode: 1, unknown0: 1, unknown1: 1 };
    },
    resolveCommand6504Response: (request) => {
      resolverCalls.push(request);
      return {
        unknownTotal: 1,
        unknownStart: 0,
        unknownCodecByte: 0,
        records: [{
          unknownField0: Buffer.from('SLOT0001', 'latin1'),
          unknownField1: Buffer.from('OPEN', 'latin1'),
          unknownRaw8: Buffer.alloc(8),
          unknownField2: Buffer.from('Test Slot', 'latin1'),
          unknownWord0: 0,
          unknownWord1: 8,
          unknownDword: 0xc00002c4
        }]
      };
    },
    resolveCommand6510Response: (request) => {
      resolverCalls.push(request);
      return {
        unknownCodecByte: 0,
        recordWords: Array(request.requestRecordCount).fill(0),
        unknownTrailingField: Buffer.from('SLOT0001', 'latin1')
      };
    },
    logger: (event) => events.push(event)
  });
  const port = await listen(server);
  t.after(() => close(server));

  const expected = Buffer.concat([
    LOBBY_CHALLENGE,
    LOBBY_INITIALIZATION_RESPONSE,
    EMPTY_KEYED_MANIFEST_RESPONSE,
    PLAYER_COUNT_CLIENT_DEFAULT_RESPONSE,
    COMMAND_6203_RESPONSE,
    COMMAND_6211_CLIENT_DEFAULT_RESPONSE,
    COMMAND_6213_CLIENT_DEFAULT_RESPONSE,
    COMMAND_6501_MODE0_RESPONSE,
    COMMAND_6502_MODE1_RESPONSE,
    COMMAND_6504_RESPONSE,
    COMMAND_6510_RESPONSE,
    COMMAND_1004_RESPONSE
  ]);
  const received = await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port }, () => {
      socket.write(Buffer.concat([
        LOBBY_INITIALIZATION_REQUEST,
        KEYED_MANIFEST_REQUEST,
        PLAYER_COUNT_REQUEST,
        COMMAND_6203_REQUEST,
        COMMAND_6211_REQUEST,
        COMMAND_6213_REQUEST,
        COMMAND_6501_REQUEST,
        COMMAND_6502_REQUEST,
        COMMAND_6504_REQUEST,
        COMMAND_6510_REQUEST,
        COMMAND_1004_REQUEST
      ]));
    });
    let bytes = Buffer.alloc(0);
    socket.on('data', (chunk) => {
      bytes = Buffer.concat([bytes, chunk]);
      if (bytes.length === expected.length) {
        socket.end();
        resolve(bytes);
      }
    });
    socket.on('error', reject);
  });

  assert.deepEqual(received, expected);
  assert.equal(events.some((event) => event.type === 'unimplemented-frame'), false);
  assert.equal(events.some((event) => event.type === 'protocol-error'), false);
  assert.equal(resolverCalls.length, 4);
  assert.equal(resolverCalls[0].command, 0x6501);
  assert.equal(resolverCalls[0].sequence, 0xd5);
  assert.equal(resolverCalls[0].unknownRequestValue, 0);
  assert.deepEqual(resolverCalls[0].remote, {
    address: '127.0.0.1',
    port: resolverCalls[0].remote.port
  });
  assert.equal(resolverCalls[1].command, 0x6502);
  assert.equal(resolverCalls[1].sequence, 0xd6);
  assert.equal(resolverCalls[1].unknownRequestValue, 0);
  assert.equal(resolverCalls[1].unknownEncodedField.toString('hex'), '000257d7');
  assert.deepEqual(resolverCalls[1].remote, {
    address: '127.0.0.1',
    port: resolverCalls[1].remote.port
  });
  assert.equal(resolverCalls[2].command, 0x6504);
  assert.equal(resolverCalls[2].sequence, 0xd7);
  assert.equal(resolverCalls[2].unknownRequestWord0, 0);
  assert.equal(resolverCalls[2].unknownRequestWord1, 8);
  assert.equal(resolverCalls[2].unknownEncodedField.toString('hex'), '000258d8');
  assert.deepEqual(resolverCalls[2].remote, {
    address: '127.0.0.1',
    port: resolverCalls[2].remote.port
  });
  assert.equal(resolverCalls[3].command, 0x6510);
  assert.equal(resolverCalls[3].sequence, 0xd8);
  assert.equal(resolverCalls[3].requestRecordCount, 1);
  assert.equal(resolverCalls[3].unknownEncodedRecordFields.length, 1);
  assert.equal(
    resolverCalls[3].unknownEncodedRecordFields[0].toString('hex'),
    '000a5adbc6dcdbcea1a4a1a6'
  );
  assert.equal(resolverCalls[3].unknownEncodedTrailingField.toString('hex'), '000258d8');
  assert.deepEqual(resolverCalls[3].remote, {
    address: '127.0.0.1',
    port: resolverCalls[3].remote.port
  });
});

test('reassembles 0x6501, emits ordered mode-1 fields, and answers coalesced 0x6503', async (t) => {
  const events = [];
  const providerCalls = [];
  const server = createTcp10127Service({
    resolveConnectionPurpose: () => 'lobby-initialization',
    resolveCommand6212Value: (request) => {
      providerCalls.push(request);
      return 1;
    },
    resolveCommand6211Value: (request) => {
      providerCalls.push(request);
      return 0;
    },
    resolveCommand6213Words: (request) => {
      providerCalls.push(request);
      return Array(8).fill(0);
    },
    resolveCommand6501Response: (request) => {
      providerCalls.push(request);
      return { mode: 1, unknown0: 0x12345678, unknown1: 0x89abcdef };
    },
    resolveCommand6503Response: (request) => {
      providerCalls.push(request);
      return {
        total: 1,
        batchStart: 0,
        unknownCodecByte: 0,
        entries: [{ ...COMMAND_6503_ENTRY }]
      };
    },
    logger: (event) => events.push(event)
  });
  const port = await listen(server);
  t.after(() => close(server));

  const received = await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port }, () => {
      socket.write(Buffer.concat([
        LOBBY_INITIALIZATION_REQUEST,
        KEYED_MANIFEST_REQUEST,
        PLAYER_COUNT_REQUEST,
        COMMAND_6203_REQUEST,
        COMMAND_6211_REQUEST,
        COMMAND_6213_REQUEST.subarray(0, 5)
      ]));
      socket.write(Buffer.concat([
        COMMAND_6213_REQUEST.subarray(5),
        COMMAND_6501_REQUEST.subarray(0, 6)
      ]));
      socket.write(Buffer.concat([
        COMMAND_6501_REQUEST.subarray(6),
        COMMAND_6503_REQUEST
      ]));
    });
    let bytes = Buffer.alloc(0);
    socket.on('data', (chunk) => {
      bytes = Buffer.concat([bytes, chunk]);
      if (bytes.length === (
        LOBBY_CHALLENGE.length +
        LOBBY_INITIALIZATION_RESPONSE.length +
        EMPTY_KEYED_MANIFEST_RESPONSE.length +
        PLAYER_COUNT_RESPONSE.length +
        COMMAND_6203_RESPONSE.length +
        COMMAND_6211_RESPONSE.length +
        COMMAND_6213_RESPONSE.length +
        COMMAND_6501_MODE1_RESPONSE.length +
        COMMAND_6503_RESPONSE_LENGTH
      )) {
        assert.equal(socket.destroyed, false);
        socket.end();
        resolve(bytes);
      }
    });
    socket.on('error', reject);
  });

  const throughCommand6501 = Buffer.concat([
    LOBBY_CHALLENGE,
    LOBBY_INITIALIZATION_RESPONSE,
    EMPTY_KEYED_MANIFEST_RESPONSE,
    PLAYER_COUNT_RESPONSE,
    COMMAND_6203_RESPONSE,
    COMMAND_6211_RESPONSE,
    COMMAND_6213_RESPONSE,
    COMMAND_6501_MODE1_RESPONSE
  ]);
  assert.deepEqual(received.subarray(0, throughCommand6501.length), throughCommand6501);
  // The 0x6503 reply is checked by shape here and byte for byte in
  // tcp10127-state-backed-ladder.test.js; what this test owns is that a request
  // coalesced into the tail of a fragmented 0x6501 is still answered, in order.
  const entryList = received.subarray(throughCommand6501.length);
  assert.equal(entryList.length, COMMAND_6503_RESPONSE_LENGTH);
  assert.equal(entryList.readUInt16BE(0), COMMAND_6503_RESPONSE_LENGTH - 8, 'declared body length');
  assert.equal(entryList[2], 0x02, 'server direction');
  assert.equal(entryList.readUInt16BE(3), 0x6503);
  assert.equal(entryList[5], 0xd6, 'the sequence of the request it answers');
  assert.equal(entryList.readUInt16BE(8), 1, 'total');
  assert.equal(entryList.readUInt16BE(10), 0, 'batchStart');
  assert.equal(entryList[12], 1, 'batchCount');
  assert.equal(
    events.some((event) => event.type === 'unimplemented-frame'), false,
    '0x6503 is answered now, not merely observed'
  );
  assert.deepEqual(
    events.filter((event) => event.type === 'frame-send').map((event) => event.command),
    [0x6001, 0x1007, 0x6103, 0x6212, 0x6203, 0x6211, 0x6213, 0x6501, 0x6503]
  );
  assert.equal(providerCalls.length, 5);
  assert.equal(providerCalls[4].command, 0x6503);
  assert.equal(providerCalls[4].requestedStart, 0);
  assert.equal(providerCalls[4].requestedCount, 8);
  assert.equal(providerCalls[0].command, 0x6212);
  assert.equal(providerCalls[0].sequence, 0xd1);
  assert.deepEqual(providerCalls[0].remote, {
    address: '127.0.0.1',
    port: providerCalls[0].remote.port
  });
  assert.equal(providerCalls[1].command, 0x6211);
  assert.equal(providerCalls[1].sequence, 0xd3);
  assert.deepEqual(providerCalls[1].remote, {
    address: '127.0.0.1',
    port: providerCalls[1].remote.port
  });
  assert.equal(providerCalls[2].command, 0x6213);
  assert.equal(providerCalls[2].sequence, 0xd4);
  assert.deepEqual(providerCalls[2].remote, {
    address: '127.0.0.1',
    port: providerCalls[2].remote.port
  });
  assert.equal(providerCalls[3].command, 0x6501);
  assert.equal(providerCalls[3].sequence, 0xd5);
  assert.equal(providerCalls[3].unknownRequestValue, 0);
  assert.deepEqual(providerCalls[3].remote, {
    address: '127.0.0.1',
    port: providerCalls[3].remote.port
  });
});

test('reassembles a 0x6510 batch split inside its encoded record field', async (t) => {
  const events = [];
  const server = createTcp10127Service({
    resolveConnectionPurpose: () => 'lobby-initialization',
    resolveCommand6501Response: () => ({ mode: 0 }),
    resolveCommand6502Response: () => ({ mode: 1, unknown0: 1, unknown1: 1 }),
    resolveCommand6504Response: () => ({
      unknownTotal: 1,
      unknownStart: 0,
      unknownCodecByte: 0,
      records: [{
        unknownField0: Buffer.from('SLOT0001', 'latin1'),
        unknownField1: Buffer.from('OPEN', 'latin1'),
        unknownRaw8: Buffer.alloc(8),
        unknownField2: Buffer.from('Test Slot', 'latin1'),
        unknownWord0: 0,
        unknownWord1: 8,
        unknownDword: 0xc00002c4
      }]
    }),
    resolveCommand6510Response: ({ requestRecordCount }) => ({
      unknownCodecByte: 0,
      recordWords: Array(requestRecordCount).fill(0),
      unknownTrailingField: Buffer.from('SLOT0001', 'latin1')
    }),
    logger: (event) => events.push(event)
  });
  const port = await listen(server);
  t.after(() => close(server));

  const ladder = Buffer.concat([
    LOBBY_INITIALIZATION_REQUEST,
    KEYED_MANIFEST_REQUEST,
    PLAYER_COUNT_REQUEST,
    COMMAND_6203_REQUEST,
    COMMAND_6211_REQUEST,
    COMMAND_6213_REQUEST,
    COMMAND_6501_REQUEST,
    COMMAND_6502_REQUEST,
    COMMAND_6504_REQUEST
  ]);
  const expectedLength = Buffer.concat([
    LOBBY_CHALLENGE,
    LOBBY_INITIALIZATION_RESPONSE,
    EMPTY_KEYED_MANIFEST_RESPONSE,
    PLAYER_COUNT_CLIENT_DEFAULT_RESPONSE,
    COMMAND_6203_RESPONSE,
    COMMAND_6211_CLIENT_DEFAULT_RESPONSE,
    COMMAND_6213_CLIENT_DEFAULT_RESPONSE,
    COMMAND_6501_MODE0_RESPONSE,
    COMMAND_6502_MODE1_RESPONSE,
    COMMAND_6504_RESPONSE,
    COMMAND_6510_RESPONSE
  ]).length;

  // Split the 0x6510 frame in the middle of its encoded 'SLOT0001' record field.
  const splitAt = 14;
  const received = await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port }, () => {
      socket.write(Buffer.concat([ladder, COMMAND_6510_REQUEST.subarray(0, splitAt)]));
      setTimeout(() => socket.write(COMMAND_6510_REQUEST.subarray(splitAt)), 20);
    });
    let bytes = Buffer.alloc(0);
    socket.on('data', (chunk) => {
      bytes = Buffer.concat([bytes, chunk]);
      if (bytes.length === expectedLength) {
        socket.end();
        resolve(bytes);
      }
    });
    socket.on('error', reject);
  });

  assert.deepEqual(received.subarray(received.length - COMMAND_6510_RESPONSE.length),
    COMMAND_6510_RESPONSE);
  assert.equal(events.some((event) => event.type === 'protocol-error'), false);
  assert.equal(events.some((event) => event.type === 'unimplemented-frame'), false);
});

function createLadderServer(events) {
  return createTcp10127Service({
    resolveConnectionPurpose: () => 'lobby-initialization',
    resolveCommand6501Response: () => ({ mode: 0 }),
    resolveCommand6502Response: () => ({ mode: 1, unknown0: 1, unknown1: 1 }),
    resolveCommand6504Response: () => ({
      unknownTotal: 1,
      unknownStart: 0,
      unknownCodecByte: 0,
      records: [{
        unknownField0: Buffer.from('SLOT0001', 'latin1'),
        unknownField1: Buffer.from('OPEN', 'latin1'),
        unknownRaw8: Buffer.alloc(8),
        unknownField2: Buffer.from('Test Slot', 'latin1'),
        unknownWord0: 0,
        unknownWord1: 8,
        unknownDword: 0xc00002c4
      }]
    }),
    resolveCommand6510Response: ({ requestRecordCount }) => ({
      unknownCodecByte: 0,
      recordWords: Array(requestRecordCount).fill(0),
      unknownTrailingField: Buffer.from('SLOT0001', 'latin1')
    }),
    logger: (event) => events.push(event)
  });
}

const FULL_LADDER_REQUESTS = () => Buffer.concat([
  LOBBY_INITIALIZATION_REQUEST,
  KEYED_MANIFEST_REQUEST,
  PLAYER_COUNT_REQUEST,
  COMMAND_6203_REQUEST,
  COMMAND_6211_REQUEST,
  COMMAND_6213_REQUEST,
  COMMAND_6501_REQUEST,
  COMMAND_6502_REQUEST,
  COMMAND_6504_REQUEST,
  COMMAND_6510_REQUEST,
  COMMAND_1004_REQUEST
]);

const FULL_LADDER_RESPONSE_LENGTH = () => Buffer.concat([
  LOBBY_CHALLENGE,
  LOBBY_INITIALIZATION_RESPONSE,
  EMPTY_KEYED_MANIFEST_RESPONSE,
  PLAYER_COUNT_CLIENT_DEFAULT_RESPONSE,
  COMMAND_6203_RESPONSE,
  COMMAND_6211_CLIENT_DEFAULT_RESPONSE,
  COMMAND_6213_CLIENT_DEFAULT_RESPONSE,
  COMMAND_6501_MODE0_RESPONSE,
  COMMAND_6502_MODE1_RESPONSE,
  COMMAND_6504_RESPONSE,
  COMMAND_6510_RESPONSE,
  COMMAND_1004_RESPONSE
]).length;

test('never closes first after 0x1004 and stays silent until the client ends it', async (t) => {
  const events = [];
  const server = createLadderServer(events);
  const port = await listen(server);
  t.after(() => close(server));

  const expectedLength = FULL_LADDER_RESPONSE_LENGTH();
  const outcome = await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port }, () => {
      socket.write(FULL_LADDER_REQUESTS());
    });
    let bytes = Buffer.alloc(0);
    let serverEnded = false;
    socket.on('data', (chunk) => {
      bytes = Buffer.concat([bytes, chunk]);
      if (bytes.length === expectedLength) {
        // The captured client waits ~70 ms before ending the connection. Hold the
        // socket open past that and assert the server neither writes nor closes.
        setTimeout(() => {
          const outcome = { bytes, serverEnded, extra: bytes.length - expectedLength };
          // The client ends it, exactly as the captured PS2 client does.
          socket.resetAndDestroy();
          resolve(outcome);
        }, 250);
      }
    });
    socket.on('end', () => { serverEnded = true; });
    socket.on('error', reject);
  });

  assert.equal(outcome.bytes.length, expectedLength, 'server must send nothing after the 0x1004 reply');
  assert.equal(outcome.serverEnded, false, 'server must not initiate the close after 0x1004');
  assert.ok(events.some((event) => event.type === 'lobby-initialization-complete'));
  assert.equal(events.some((event) => event.type === 'protocol-error'), false);
});

test('treats a client reset after the 0x1004 completion as normal termination', async (t) => {
  const events = [];
  const server = createLadderServer(events);
  const port = await listen(server);
  t.after(() => close(server));

  const expectedLength = FULL_LADDER_RESPONSE_LENGTH();
  await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port }, () => {
      socket.write(FULL_LADDER_REQUESTS());
    });
    let bytes = Buffer.alloc(0);
    socket.on('data', (chunk) => {
      bytes = Buffer.concat([bytes, chunk]);
      if (bytes.length === expectedLength) {
        // Reproduce the real PS2 termination: an abortive reset, not a FIN.
        socket.resetAndDestroy();
        setTimeout(resolve, 150);
      }
    });
    socket.on('error', () => {});
    socket.on('close', () => {});
    setTimeout(() => reject(new Error('ladder did not complete')), 4000).unref?.();
  });

  assert.ok(
    events.some((event) => event.type === 'expected-client-reset'),
    'a post-completion reset must be logged as expected termination'
  );
  assert.equal(
    events.some((event) => event.type === 'socket-error'),
    false,
    'a post-completion reset must not be reported as a socket fault'
  );
  const closeEvent = events.find((event) => event.type === 'connection-close');
  assert.equal(closeEvent.lobbyInitializationCompleted, true);
});

test('still reports a reset that arrives before the 0x1004 completion', async (t) => {
  const events = [];
  const server = createLadderServer(events);
  const port = await listen(server);
  t.after(() => close(server));

  await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port }, () => {
      socket.write(LOBBY_INITIALIZATION_REQUEST);
    });
    socket.on('data', () => {
      socket.resetAndDestroy();
      setTimeout(resolve, 150);
    });
    socket.on('error', () => {});
    setTimeout(() => reject(new Error('no response')), 4000).unref?.();
  });

  assert.equal(
    events.some((event) => event.type === 'expected-client-reset'),
    false,
    'an early reset is not the captured completion behaviour'
  );
  const closeEvent = events.find((event) => event.type === 'connection-close');
  assert.equal(closeEvent.lobbyInitializationCompleted, false);
});
