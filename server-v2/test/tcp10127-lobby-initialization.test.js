import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import test from 'node:test';
import { fileURLToPath } from 'node:url';

import {
  Tcp10127ProtocolError,
  decodeTcp10127Frame
} from '../src/protocol/tcp10127-codec.js';
import { decodeSnapField, encodeSnapField } from '../src/protocol/snap-field-codec.js';
import {
  TCP10127_LOBBY_INITIALIZATION_STATE,
  Tcp10127LobbyInitializationSession
} from '../src/tcp/lobby-initialization-session.js';
import {
  AREA_TABLE_PROVENANCE,
  AREA_TABLE_TRANSFER,
  createAreaTable
} from '../src/state/area-table.js';
import { createV1ObservedAreaTable } from '../src/state/area-table-v1.js';

/**
 * Every session in this file serves the same area table the service defaults to,
 * so the ladder these tests walk is the ladder a client walks.
 */
const AREA_TABLE = createV1ObservedAreaTable();

/**
 * V1's own `0x6203` + `0x6204` frames, both directions, from the session that
 * rendered Area Select on real PS2 hardware. Provenance and derivation are in
 * `test/area-table.test.js`; here they are the byte-exact transcript V2 must
 * reproduce when replayed at V1's sequences.
 */
const V1_AREA_WIRE = JSON.parse(fs.readFileSync(path.join(
  path.dirname(fileURLToPath(import.meta.url)), 'fixtures', 'area-table-v1-wire.json'
), 'utf8'));

/**
 * `FUN_001c4c80.c:8-11`: command index 0x14, then BE16 chunk index, BE32 offset,
 * and the literal BE16 0x2f2. Synthetic so that malformed and out-of-cursor
 * shapes the captures do not contain can be exercised.
 */
function buildCommand6204Request({
  sequence,
  chunkIndex = 0,
  offset,
  sliceLength = AREA_TABLE_TRANSFER.sliceLength,
  unknown7 = 0xff,
  error = 0,
  direction = 0x01
}) {
  const payload = Buffer.alloc(8);
  payload.writeUInt16BE(chunkIndex, 0);
  payload.writeUInt32BE(offset, 2);
  payload.writeUInt16BE(sliceLength, 6);
  const header = Buffer.alloc(8);
  header.writeUInt16BE(payload.length, 0);
  header[2] = direction;
  header.writeUInt16BE(0x6204, 3);
  header[5] = sequence;
  header[6] = error;
  header[7] = unknown7;
  return Buffer.concat([header, payload]);
}

/** Walk the whole area blob, as the client does after a mode-1 0x6203 reply. */
function advanceThroughAreaTable(session, firstSequence = 0xd4) {
  const responses = [];
  let sequence = firstSequence;
  for (let offset = 0; offset < AREA_TABLE.byteLength;
    offset += AREA_TABLE_TRANSFER.sliceLength) {
    responses.push(session.handleFrame(decodeTcp10127Frame(
      buildCommand6204Request({ sequence, offset })
    )));
    sequence = (sequence + 1) & 0xff;
  }
  return responses;
}

// Ignored raw captures/snap_session2_in_1_*.bin, SHA-256 values recorded in
// docs/findings/protocol/SESSION-LOG-2026-08-01.md. These are three unique PAL
// requests; their payload contents deliberately remain uninterpreted.
const CAPTURED_REQUESTS = [
  '0031011007cf00ff01002e5e18c9d5fea3c4f2f9cfacdcc0d8a5d4d6f1c4f0cdd49cc59c97de91ead8ebcbe493f88df0dec9d3d2e789cbd486',
  '00310110070400ff01002e124d020029761f2f26127709170d6e19193c0f053a216738636a25641d2d20062b5e3358270b120e0d3a521e0353',
  '00310110074600ff01002e548f404267385d6d6054354b49532c5b5f7a4d47746f257a252c6726635362446d18711a6945504c4b7c105c5d0d'
].map((hex) => Buffer.from(hex, 'hex'));

const CAPTURED_KEYED_MANIFEST_REQUESTS = [
  '0000016103d000ff',
  '00000161030500ff',
  '00000161034700ff'
].map((hex) => Buffer.from(hex, 'hex'));

const CAPTURED_COMMAND_6212_EXCHANGES = [
  {
    request: '00000162120700ff',
    response: '00040262120700ff00000001'
  },
  {
    request: '0000016212d200ff',
    response: '0004026212d200ff00000001'
  }
];

/**
 * The two unique captured PAL `0x6203` REQUESTS. Both carry an empty version
 * field - `000253d3` is the empty field's checksum at sequence 0xd3 - which is a
 * client whose area-table cache at `0x36842c` is still zeroed.
 *
 * Only the requests are captured evidence. Their old `response` entries recorded
 * what V2 answered while it was answering mode 2, and the client's `nextRequest`
 * after a mode-2 reply is not the request it sends after a mode-1 one, so both
 * are gone rather than adjusted: the first request's real mode-1 answer is
 * asserted byte for byte against V1's own wire below.
 */
const CAPTURED_COMMAND_6203_REQUESTS = [
  '0004016203d300ff000253d3',
  '00040162030800ff00020808'
];

const CAPTURED_COMMAND_6211_EXCHANGES = [
  {
    request: '0000016211d400ff',
    response: '0004026211d400ff00000000',
    nextRequest: '0000016213d500ff'
  },
  {
    request: '00000162110900ff',
    response: '00040262110900ff00000000',
    nextRequest: '00000162130a00ff'
  }
];

const CAPTURED_COMMAND_6213_EXCHANGES = [
  {
    request: '0000016213d500ff',
    response: '0010026213d500ff00000000000000000000000000000000',
    nextRequest: '0004016501d600ff00000000'
  },
  {
    request: '00000162130a00ff',
    response: '00100262130a00ff00000000000000000000000000000000',
    nextRequest: '00040165010b00ff00000000'
  }
];

const CLIENT_DEFAULT_RESPONSES = Object.freeze({
  command6212: Buffer.from('000002621207ffff', 'hex'),
  command6211: Buffer.from('0000026211d4ffff', 'hex'),
  command6213: Buffer.from('0000026213d5ffff', 'hex')
});

const CAPTURED_COMMAND_6501_EXCHANGES = [
  {
    request: '0004016501d600ff00000000',
    response: '0001026501d600ff00',
    nextRequest: '0008016502d700ff00000000000257d7'
  },
  {
    request: '00040165010b00ff00000000',
    response: '00010265010b00ff00',
    nextRequest: '00080165020c00ff0000000000020c0c'
  }
];

const CAPTURED_COMMAND_6502_EXCHANGES = [
  {
    request: '0008016502d700ff00000000000257d7',
    response: '0009026502d700ff010000000100000001',
    nextRequest: '0008016504d800ff00000008000258d8'
  },
  {
    request: '00080165020c00ff0000000000020c0c',
    response: '00090265020c00ff010000000100000001',
    nextRequest: '00080165040d00ff0000000800020d0d'
  }
];

const CAPTURED_COMMAND_6504_REQUESTS = [
  '0008016504d800ff00000008000258d8',
  '00080165040d00ff0000000800020d0d'
];

function runtimeCompatibleCommand6504Selection() {
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
}

/**
 * Real captured PAL client <-> V1 `0x6510` exchanges, in the same twelve-triplet
 * form the earlier ladder steps use. Ignored raw captures under `captures/`:
 *
 *   snap_session2_in_11_* / snap_session2_out_12_*  (10x seq 0xd9, 2x seq 0x0e)
 *   snap_session3_in_2_*  / snap_session3_out_3_*   (10x seq 0x47, 2x seq 0xb5)
 *
 * All four decode to one record field whose plaintext is `SLOT0001`. The two
 * shapes differ in the request's trailing field: the session-2 requests carry an
 * empty trailer, the session-3 requests carry `SLOT0001` again. A third shape
 * exists in `docs/evidence/logs/2026_06_04_22_25_57_snap_session3_trace.log`
 * (p5 0xa8) whose trailer decodes to `PAL Lobby`. The trailing field therefore
 * round-trips whatever the server last wrote to the client's page block; its
 * production source is still Unknown (OQ-019).
 *
 * The session-3 frames come from a later TCP connection that does NOT begin with
 * `0x1007`, so they are used here only as byte-level `0x6510` evidence, not as
 * proof of the lobby-initialization ladder's shape.
 *
 * These are V1 compatibility fixtures: they prove the client accepted these exact
 * bytes. They are not production defaults.
 */
const CAPTURED_COMMAND_6510_EXCHANGES = [
  {
    request: '0011016510d900ff01000a5bdcc7dfdac9a0a7a099000259d9',
    response: '000f026510d900ff010000000a5bdcc7dfdac9a0a7a099',
    nextRequest: '0000011004da00ff'
  },
  {
    request: '00110165100e00ff01000a1011100a11046f6a6b6c00020e0e',
    response: '000f0265100e00ff010000000a1011100a11046f6a6b6c',
    nextRequest: '00000110040f00ff'
  },
  {
    request: '00190165104700ff01000a494a594d485f36353237000a494a594d485f36353237',
    response: '000f0265104700ff010000000a494a594d485f36353237',
    nextRequest: '00000110044800ff'
  },
  {
    request: '0019016510b500ff01000a37b8abb3b6adc4c3c4c5000a37b8abb3b6adc4c3c4c5',
    response: '000f026510b500ff010000000a37b8abb3b6adc4c3c4c5',
    nextRequest: null
  }
];

// snap_session2_in_12_* / snap_session2_out_13_*: the terminal completion is a
// bare header in both directions.
const CAPTURED_COMMAND_1004_EXCHANGES = [
  { request: '0000011004da00ff', response: '0000021004da00ff' },
  { request: '00000110040f00ff', response: '00000210040f00ff' }
];

// FUN_001c85c0 emits one count byte, that many FUN_001c4020 fields, then one
// more. Synthetic builder for shapes the captures do not cover (multi-record
// batches, zero-record batches, malformed envelopes).
function buildCommand6510Request({
  sequence,
  recordFields,
  trailingField = Buffer.alloc(0),
  unknownCodecByte = 0,
  unknown7 = 0xff,
  error = 0
}) {
  const parts = [Buffer.from([recordFields.length])];
  for (const plain of recordFields) {
    parts.push(encodeSnapField({
      plain,
      maximumDecodedLength: 0xff,
      sequence,
      unknownCodecByte
    }));
  }
  parts.push(encodeSnapField({
    plain: trailingField,
    maximumDecodedLength: 0x3e,
    sequence,
    unknownCodecByte
  }));
  const payload = Buffer.concat(parts);
  const header = Buffer.alloc(8);
  header.writeUInt16BE(payload.length, 0);
  header[2] = 0x01;
  header.writeUInt16BE(0x6510, 3);
  header[5] = sequence;
  header[6] = error;
  header[7] = unknown7;
  return Buffer.concat([header, payload]);
}

function runtimeCompatibleCommand6510Selection({ requestRecordCount }) {
  return {
    unknownCodecByte: 0,
    recordWords: Array(requestRecordCount).fill(0),
    unknownTrailingField: Buffer.from('SLOT0001', 'latin1')
  };
}

/**
 * A one-entry `0x6503` batch. The four fields are the ones `FUN_001c70b0`
 * writes to entry `+0x00` / `+0x3f` / `+0x4f` / `+0x57`.
 */
const defaultCommand6503Selection = () => ({
  total: 1,
  batchStart: 0,
  unknownCodecByte: 0,
  entries: [{
    host: Buffer.from('10.0.0.1', 'latin1'),
    name: Buffer.from('E', 'latin1'),
    raw8: Buffer.alloc(8),
    description: Buffer.from('d', 'latin1')
  }]
});

function createSession(
  resolveCommand6212Value = () => 1,
  resolveCommand6211Value = () => 0,
  resolveCommand6213Words = () => Array(8).fill(0),
  resolveCommand6501Response = () => ({ mode: 0 }),
  resolveCommand6502Response = () => ({ mode: 1, unknown0: 1, unknown1: 1 }),
  resolveCommand6504Response = runtimeCompatibleCommand6504Selection,
  resolveCommand6510Response = runtimeCompatibleCommand6510Selection,
  resolveCommand6503Response = defaultCommand6503Selection
) {
  return new Tcp10127LobbyInitializationSession({
    areaTable: AREA_TABLE,
    resolveCommand6212Value,
    resolveCommand6211Value,
    resolveCommand6213Words,
    resolveCommand6501Response,
    resolveCommand6503Response,
    resolveCommand6502Response,
    resolveCommand6504Response,
    resolveCommand6510Response
  });
}

/** Up to and including the mode-1 0x6203 reply, but before the blob transfer. */
function advanceToCommand6204(session, request = CAPTURED_COMMAND_6203_REQUESTS[0]) {
  session.handleFrame(decodeTcp10127Frame(CAPTURED_REQUESTS[0]));
  session.handleFrame(decodeTcp10127Frame(CAPTURED_KEYED_MANIFEST_REQUESTS[0]));
  session.handleFrame(decodeTcp10127Frame(
    Buffer.from(CAPTURED_COMMAND_6212_EXCHANGES[0].request, 'hex')
  ));
  session.handleFrame(decodeTcp10127Frame(Buffer.from(request, 'hex')));
}

function advanceToCommand6211(session, request = CAPTURED_COMMAND_6203_REQUESTS[0]) {
  advanceToCommand6204(session, request);
  advanceThroughAreaTable(session);
}

function advanceToCommand6213(session, index = 0) {
  advanceToCommand6211(session, CAPTURED_COMMAND_6203_REQUESTS[index]);
  session.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6211_EXCHANGES[index].request,
    'hex'
  )));
}

function advanceToCommand6501(session, index = 0) {
  advanceToCommand6213(session, index);
  session.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6213_EXCHANGES[index].request,
    'hex'
  )));
}

function advanceToCommand6502(session, index = 0) {
  advanceToCommand6501(session, index);
  session.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6501_EXCHANGES[index].request,
    'hex'
  )));
}

function advanceToCommand6504(session, index = 0) {
  advanceToCommand6502(session, index);
  session.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6502_EXCHANGES[index].request,
    'hex'
  )));
}

function createCommand6504Session(resolveCommand6504Response) {
  return createSession(
    () => 1,
    () => 0,
    () => Array(8).fill(0),
    () => ({ mode: 0 }),
    () => ({ mode: 1, unknown0: 1, unknown1: 1 }),
    resolveCommand6504Response
  );
}

test('answers all three captured PAL 0x1007 requests with the mode-0 response', () => {
  for (const request of CAPTURED_REQUESTS) {
    const frame = decodeTcp10127Frame(request);
    const session = createSession();
    const result = session.handleFrame(frame);
    const expected = Buffer.from(`0001021007${frame.sequence.toString(16).padStart(2, '0')}00ff00`, 'hex');

    assert.deepEqual(result.response, expected);
    assert.deepEqual(result.request.unknownPayload, frame.payload);
    assert.equal(
      session.state,
      TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_KEYED_MANIFEST_REQUEST
    );
  }
});

test('does not invent validation for the opaque 49-byte request payload', () => {
  const request = Buffer.from(CAPTURED_REQUESTS[0]);
  request[8] ^= 0xff;
  request[56] ^= 0xff;

  const session = createSession();
  const result = session.handleFrame(decodeTcp10127Frame(request));
  assert.deepEqual(result.response, Buffer.from('0001021007cf00ff00', 'hex'));
});

test('rejects only decoded and captured first-frame invariant violations', () => {
  const cases = [
    { offset: 2, value: 0x02, code: 'LOBBY_INIT_DIRECTION' },
    { offset: 4, value: 0x08, code: 'LOBBY_INIT_COMMAND' },
    { offset: 6, value: 0x01, code: 'LOBBY_INIT_STATUS' },
    { offset: 7, value: 0x00, code: 'LOBBY_INIT_UNKNOWN7' }
  ];

  for (const fixture of cases) {
    const request = Buffer.from(CAPTURED_REQUESTS[0]);
    request[fixture.offset] = fixture.value;
    const session = createSession();
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(request)),
      (error) => error instanceof Tcp10127ProtocolError && error.code === fixture.code
    );
  }

  const shortRequest = Buffer.from(CAPTURED_REQUESTS[0].subarray(0, -1));
  shortRequest.writeUInt16BE(48, 0);
  const session = createSession();
  assert.throws(
    () => session.handleFrame(decodeTcp10127Frame(shortRequest)),
    (error) => error instanceof Tcp10127ProtocolError && error.code === 'LOBBY_INIT_LENGTH'
  );
});

test('answers all three captured PAL 0x6103 requests with an empty keyed manifest', () => {
  for (let index = 0; index < CAPTURED_KEYED_MANIFEST_REQUESTS.length; index += 1) {
    const session = createSession();
    session.handleFrame(decodeTcp10127Frame(CAPTURED_REQUESTS[index]));
    const frame = decodeTcp10127Frame(CAPTURED_KEYED_MANIFEST_REQUESTS[index]);
    const result = session.handleFrame(frame);
    const expected = Buffer.from(
      `0002026103${frame.sequence.toString(16).padStart(2, '0')}00ff0000`,
      'hex'
    );

    assert.deepEqual(result.response, expected);
    assert.equal(result.request.unknownPayload.length, 0);
    assert.equal(session.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6212);
  }
});

test('rejects malformed or out-of-order 0x6103 requests', () => {
  const cases = [
    { offset: 2, value: 0x02, code: 'KEYED_MANIFEST_DIRECTION' },
    { offset: 4, value: 0x04, code: 'KEYED_MANIFEST_COMMAND' },
    { offset: 6, value: 0x01, code: 'KEYED_MANIFEST_STATUS' },
    { offset: 7, value: 0x00, code: 'KEYED_MANIFEST_UNKNOWN7' }
  ];

  for (const fixture of cases) {
    const request = Buffer.from(CAPTURED_KEYED_MANIFEST_REQUESTS[0]);
    request[fixture.offset] = fixture.value;
    const session = createSession();
    session.handleFrame(decodeTcp10127Frame(CAPTURED_REQUESTS[0]));
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(request)),
      (error) => error instanceof Tcp10127ProtocolError && error.code === fixture.code
    );
  }

  const requestWithPayload = Buffer.from('0001016103d000ff00', 'hex');
  const session = createSession();
  session.handleFrame(decodeTcp10127Frame(CAPTURED_REQUESTS[0]));
  assert.throws(
    () => session.handleFrame(decodeTcp10127Frame(requestWithPayload)),
    (error) => error instanceof Tcp10127ProtocolError && error.code === 'KEYED_MANIFEST_LENGTH'
  );
});

test('answers both unique captured canonical 0x6212 requests with the captured BE32 value', () => {
  for (const exchange of CAPTURED_COMMAND_6212_EXCHANGES) {
    const providerCalls = [];
    const session = createSession((request) => {
      providerCalls.push(request);
      return 1;
    });
    session.handleFrame(decodeTcp10127Frame(CAPTURED_REQUESTS[0]));
    session.handleFrame(decodeTcp10127Frame(CAPTURED_KEYED_MANIFEST_REQUESTS[0]));

    const result = session.handleFrame(decodeTcp10127Frame(
      Buffer.from(exchange.request, 'hex')
    ));
    assert.deepEqual(result.response, Buffer.from(exchange.response, 'hex'));
    assert.deepEqual(providerCalls, [{
      command: 0x6212,
      sequence: Buffer.from(exchange.request, 'hex')[5]
    }]);
    assert.equal(
      session.state,
      TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6203
    );
  }
});

test('serializes the injected 0x6212 value as an unsigned BE32 field', () => {
  const cases = [
    { value: 0, suffix: '00000000' },
    { value: 0x12345678, suffix: '12345678' },
    { value: 0xffffffff, suffix: 'ffffffff' }
  ];

  for (const fixture of cases) {
    const session = createSession(() => fixture.value);
    session.handleFrame(decodeTcp10127Frame(CAPTURED_REQUESTS[0]));
    session.handleFrame(decodeTcp10127Frame(CAPTURED_KEYED_MANIFEST_REQUESTS[0]));
    const result = session.handleFrame(decodeTcp10127Frame(
      Buffer.from(CAPTURED_COMMAND_6212_EXCHANGES[0].request, 'hex')
    ));
    assert.equal(result.response.subarray(-4).toString('hex'), fixture.suffix);
  }
});

test('rejects noncanonical or out-of-order 0x6212 requests', () => {
  const cases = [
    { offset: 2, value: 0x02, code: 'COMMAND_6212_DIRECTION' },
    { offset: 4, value: 0x13, code: 'COMMAND_6212_COMMAND' },
    { offset: 6, value: 0x01, code: 'COMMAND_6212_STATUS' },
    { offset: 7, value: 0x00, code: 'COMMAND_6212_UNKNOWN7' }
  ];

  for (const fixture of cases) {
    const request = Buffer.from(CAPTURED_COMMAND_6212_EXCHANGES[0].request, 'hex');
    request[fixture.offset] = fixture.value;
    const session = createSession();
    session.handleFrame(decodeTcp10127Frame(CAPTURED_REQUESTS[0]));
    session.handleFrame(decodeTcp10127Frame(CAPTURED_KEYED_MANIFEST_REQUESTS[0]));
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(request)),
      (error) => error instanceof Tcp10127ProtocolError && error.code === fixture.code
    );
  }

  const requestWithPayload = Buffer.from('00010162120700ff00', 'hex');
  const session = createSession();
  session.handleFrame(decodeTcp10127Frame(CAPTURED_REQUESTS[0]));
  session.handleFrame(decodeTcp10127Frame(CAPTURED_KEYED_MANIFEST_REQUESTS[0]));
  assert.throws(
    () => session.handleFrame(decodeTcp10127Frame(requestWithPayload)),
    (error) => error instanceof Tcp10127ProtocolError && error.code === 'COMMAND_6212_LENGTH'
  );
});

test('validates a synchronous unsigned 32-bit provider value for 0x6212 when supplied', () => {
  const invalidProviders = [
    { provider: () => -1, code: 'COMMAND_6212_VALUE' },
    { provider: () => 0x100000000, code: 'COMMAND_6212_VALUE' },
    { provider: () => 1.5, code: 'COMMAND_6212_VALUE' },
    { provider: async () => 1, code: 'COMMAND_6212_VALUE_PROVIDER' },
    {
      provider: () => { throw new Error('registry unavailable'); },
      code: 'COMMAND_6212_VALUE_PROVIDER'
    }
  ];

  for (const fixture of invalidProviders) {
    const session = createSession(fixture.provider);
    session.handleFrame(decodeTcp10127Frame(CAPTURED_REQUESTS[0]));
    session.handleFrame(decodeTcp10127Frame(CAPTURED_KEYED_MANIFEST_REQUESTS[0]));
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(
        Buffer.from(CAPTURED_COMMAND_6212_EXCHANGES[0].request, 'hex')
      )),
      (error) => error instanceof Tcp10127ProtocolError && error.code === fixture.code
    );
  }
});

/**
 * THE MILESTONE ASSERTION. Replay V1's own `0x6203` and seven `0x6204` requests
 * at V1's own sequences and demand V1's own reply bytes back, byte for byte.
 *
 * This is the exchange that was missing entirely: V2 answered `0x6203` with mode
 * 2, which `FUN_001c4960.c:26-29` routes past the whole fetch, so the client's
 * area table stayed empty and `FUN_005ad350.c:31` could never let an area be
 * entered. Nothing here is pattern-matched into agreement - the expectations are
 * the archived server's bytes.
 */
/**
 * V1's table EXACTLY: its version, its empty `+0x34`, its zero masks.
 *
 * THE SPLIT, and why it is not the cop-out it looks like. This replay is the
 * oracle for the TRANSFER: the framing, the seven slice offsets, the checksums,
 * the declaration layout and the state machine. Those are properties of the
 * carrier and must be pinned against the archived bytes forever, so the carrier is
 * fed a table whose content is V1's - otherwise every future content change would
 * force a re-baseline of assertions that have nothing to do with content, and the
 * pressure would be to loosen them.
 *
 * The CONTENT has its own oracle, and it is strictly stronger than what this test
 * used to provide: `test/area-table.test.js`, "the shipped area table is V1's blob
 * with only the +0x34 second line added", diffs the shipped blob against the same
 * decoded V1 capture and blanks only the single field we meant to change. Any
 * other byte moving fails it. That is the guard on the rig-confirmed rendering.
 *
 * SUPERSEDED, twice, and both worth remembering:
 * - This was briefly driven from the SHIPPED table while content and transfer were
 *   pinned together. That is the correct arrangement only while the two happen to
 *   coincide, and it silently becomes a re-baseline treadmill when they diverge.
 * - Before that, a reconstruction was introduced with NO separate content oracle -
 *   which left the deployed blob unguarded at exactly the moment it was changing.
 *   A reconstruction here is only legitimate because the content test above exists.
 *   If it is ever deleted, this must go back to the shipped table.
 */
function v1ExactAreaTable() {
  const shipped = createV1ObservedAreaTable();
  return createAreaTable({
    version: Buffer.from('OBAREA-V1', 'latin1'),
    provenance: AREA_TABLE_PROVENANCE.V1_OBSERVED,
    areas: Array.from({ length: shipped.areaCount }, (_unused, index) => {
      const area = shipped.areaAt(index);
      return {
        name: area.name,
        // V1 left +0x34 NUL: it believed +0x1c was a 0x30-byte name field.
        secondLine: Buffer.alloc(0),
        // V1 shipped the +0x16c block all-zero, which decodes to a ONE-player max.
        roomParameters: { published: false },
        description: area.description,
        enabled: area.enabled,
        unknownLeadWord: area.unknownLeadWord,
        alwaysAvailableModeMask: 0,
        progressGatedModeMask: 0
      };
    })
  });
}

test('reproduces V1\'s 0x6203 and seven 0x6204 replies byte for byte', () => {
  const session = new Tcp10127LobbyInitializationSession({
    areaTable: v1ExactAreaTable(),
    resolveCommand6212Value: () => 1,
    resolveCommand6211Value: () => 0,
    resolveCommand6213Words: () => Array(8).fill(0),
    resolveCommand6501Response: () => ({ mode: 0 }),
    resolveCommand6503Response: defaultCommand6503Selection,
    resolveCommand6502Response: () => ({ mode: 1, unknown0: 1, unknown1: 1 }),
    resolveCommand6504Response: runtimeCompatibleCommand6504Selection,
    resolveCommand6510Response: runtimeCompatibleCommand6510Selection
  });
  session.handleFrame(decodeTcp10127Frame(CAPTURED_REQUESTS[0]));
  session.handleFrame(decodeTcp10127Frame(CAPTURED_KEYED_MANIFEST_REQUESTS[0]));
  session.handleFrame(decodeTcp10127Frame(
    Buffer.from(CAPTURED_COMMAND_6212_EXCHANGES[0].request, 'hex')
  ));

  const inbound = V1_AREA_WIRE.frames.filter((frame) => frame.dir === 'in');
  const outbound = V1_AREA_WIRE.frames.filter((frame) => frame.dir === 'out');
  assert.equal(inbound.length, 8, 'V1 answered one 0x6203 and seven 0x6204 requests');
  assert.equal(outbound.length, 8);

  const states = [];
  for (let index = 0; index < inbound.length; index += 1) {
    const result = session.handleFrame(decodeTcp10127Frame(
      Buffer.from(inbound[index].hex, 'hex')
    ));
    assert.equal(
      result.response.toString('hex'),
      outbound[index].hex,
      `frame ${index} (${inbound[index].cmd} seq 0x${inbound[index].seq.toString(16)})`
    );
    states.push(result.state);
  }
  assert.deepEqual(states, [
    TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6204,
    ...Array(6).fill(TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_MORE_COMMAND_6204),
    // The final slice completes the only declared chunk, so the client moves to
    // substate 0x14 and emits 0x6211 (FUN_001c4d40.c:46-51).
    TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6211
  ]);
});

test('answers both unique captured 0x6203 requests with a mode-1 declaration', () => {
  for (const request of CAPTURED_COMMAND_6203_REQUESTS) {
    const session = createSession();
    session.handleFrame(decodeTcp10127Frame(CAPTURED_REQUESTS[0]));
    session.handleFrame(decodeTcp10127Frame(CAPTURED_KEYED_MANIFEST_REQUESTS[0]));
    session.handleFrame(decodeTcp10127Frame(
      Buffer.from(CAPTURED_COMMAND_6212_EXCHANGES[0].request, 'hex')
    ));

    const frame = decodeTcp10127Frame(Buffer.from(request, 'hex'));
    const result = session.handleFrame(frame);
    const payload = decodeTcp10127Frame(result.response).payload;
    assert.equal(payload[0], 1, 'mode 2 skips the fetch and leaves every area un-enterable');
    const version = decodeSnapField({
      field: payload.subarray(1),
      maximumDecodedLength: AREA_TABLE_TRANSFER.maximumVersionLength,
      sequence: frame.sequence,
      unknownCodecByte: 0
    });
    assert.deepEqual(version, AREA_TABLE.version);
    const chunkTable = payload.subarray(1 + 4 + version.length);
    assert.equal(chunkTable.length, 2 + 4);
    assert.equal(chunkTable.readUInt16BE(0), 1);
    assert.equal(chunkTable.readUInt32BE(2), AREA_TABLE.byteLength);
    // The client's own cached version, which the captured requests leave empty.
    assert.deepEqual(result.request.cachedAreaTableVersion, Buffer.alloc(0));
    assert.deepEqual(result.request.unknownPayload, Buffer.from(request, 'hex').subarray(8));
    assert.equal(session.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6204);
  }
});

test('validates only the decoded 0x6203 dynamic envelope, not its opaque contents', () => {
  const session = createSession();
  session.handleFrame(decodeTcp10127Frame(CAPTURED_REQUESTS[0]));
  session.handleFrame(decodeTcp10127Frame(CAPTURED_KEYED_MANIFEST_REQUESTS[0]));
  session.handleFrame(decodeTcp10127Frame(
    Buffer.from(CAPTURED_COMMAND_6212_EXCHANGES[0].request, 'hex')
  ));

  // A field that will not decode under this connection's codec word is served
  // anyway: the version the client cached is a diagnostic, not a gate.
  const request = Buffer.from('00070162035500ff0005a1b2c3d4e5', 'hex');
  const result = session.handleFrame(decodeTcp10127Frame(request));
  assert.equal(result.request.cachedAreaTableVersion, null);
  assert.equal(decodeTcp10127Frame(result.response).payload[0], 1);
  assert.deepEqual(result.request.unknownPayload, request.subarray(8));
});

test('serves the whole blob in seven slices and then expects 0x6211', () => {
  const session = createSession();
  advanceToCommand6204(session);

  const assembled = [];
  let offset = 0;
  let sequence = 0x11;
  while (session.state !== TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6211) {
    const frame = decodeTcp10127Frame(buildCommand6204Request({ sequence, offset }));
    const payload = decodeTcp10127Frame(session.handleFrame(frame).response).payload;
    assert.equal(payload.readUInt16BE(0), 0, 'the reply must echo the requested chunk index');
    assert.equal(payload.readUInt32BE(2), offset, 'the reply must echo the requested offset');
    const slice = decodeSnapField({
      field: payload.subarray(6),
      maximumDecodedLength: AREA_TABLE_TRANSFER.sliceLength,
      sequence,
      unknownCodecByte: 0
    });
    assert.notEqual(slice, null);
    assembled.push(slice);
    offset += AREA_TABLE_TRANSFER.sliceLength;
    sequence = (sequence + 1) & 0xff;
  }
  assert.equal(assembled.length, 7);
  assert.deepEqual(Buffer.concat(assembled), AREA_TABLE.serialize());
});

test('accepts 0x6211 instead of 0x6204 when the client already cached this table', () => {
  // FUN_001c4960.c:46-49 compares the version it was sent with the client's
  // cached copy and, when they match, goes straight to the 0x6211 builder.
  const session = createSession();
  advanceToCommand6204(session);
  const result = session.handleFrame(decodeTcp10127Frame(Buffer.from('0000016211d400ff', 'hex')));
  assert.equal(result.unimplemented, false);
  assert.equal(session.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6213);
});

test('refuses a 0x6204 that does not match the cursor the client should hold', () => {
  const cases = [
    {
      request: { sequence: 0x11, offset: AREA_TABLE_TRANSFER.sliceLength },
      code: 'COMMAND_6204_CURSOR'
    },
    { request: { sequence: 0x11, offset: 0, chunkIndex: 1 }, code: 'COMMAND_6204_CURSOR' },
    {
      request: { sequence: 0x11, offset: 0, sliceLength: 0x100 },
      code: 'COMMAND_6204_SLICE_LENGTH'
    },
    { request: { sequence: 0x11, offset: 0, direction: 0x02 }, code: 'COMMAND_6204_DIRECTION' },
    { request: { sequence: 0x11, offset: 0, error: 1 }, code: 'COMMAND_6204_STATUS' },
    { request: { sequence: 0x11, offset: 0, unknown7: 0 }, code: 'COMMAND_6204_UNKNOWN7' }
  ];
  for (const fixture of cases) {
    const session = createSession();
    advanceToCommand6204(session);
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(buildCommand6204Request(fixture.request))),
      (error) => error instanceof Tcp10127ProtocolError && error.code === fixture.code,
      JSON.stringify(fixture.request)
    );
  }

  const shortSession = createSession();
  advanceToCommand6204(shortSession);
  assert.throws(
    () => shortSession.handleFrame(decodeTcp10127Frame(
      Buffer.from('00060162041100ff000000000000', 'hex')
    )),
    (error) => error instanceof Tcp10127ProtocolError && error.code === 'COMMAND_6204_LENGTH'
  );
});

test('the 0x6510 re-fetch rewinds the transfer cursor, as FUN_001c4960 does', () => {
  // FUN_001c4960.c:93-95 zeroes the client's chunk index and offset on every
  // mode-1 reply, so a second transfer must start at offset 0 rather than
  // continue the first one's cursor.
  const session = createSession();
  advanceToCommand6510(session);
  session.handleFrame(decodeTcp10127Frame(buildCommand6510Request({
    sequence: 0xd8,
    recordFields: [Buffer.from('SLOT0001', 'latin1')]
  })));
  const restarted = session.handleFrame(decodeTcp10127Frame(
    Buffer.from('0004016203db00ff00025bdb', 'hex')
  ));
  assert.equal(decodeTcp10127Frame(restarted.response).payload[0], 1);
  assert.equal(session.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6204);
  const first = session.handleFrame(decodeTcp10127Frame(
    buildCommand6204Request({ sequence: 0xdc, offset: 0 })
  ));
  assert.equal(decodeTcp10127Frame(first.response).payload.readUInt32BE(2), 0);
  assert.equal(session.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_MORE_COMMAND_6204);
});

test('rejects malformed or out-of-order 0x6203 requests', () => {
  const cases = [
    { request: '0004026203d300ff000253d3', code: 'COMMAND_6203_DIRECTION' },
    { request: '0004016204d300ff000253d3', code: 'COMMAND_6203_COMMAND' },
    { request: '0004016203d301ff000253d3', code: 'COMMAND_6203_STATUS' },
    { request: '0004016203d30000000253d3', code: 'COMMAND_6203_UNKNOWN7' },
    { request: '0000016203d300ff', code: 'COMMAND_6203_LENGTH' },
    { request: '0001016203d300ff00', code: 'COMMAND_6203_LENGTH' },
    { request: '0002016203d300ff0000', code: 'COMMAND_6203_LENGTH' },
    { request: '0003016203d300ff000000', code: 'COMMAND_6203_LENGTH' },
    { request: '0004016203d300ff000353d3', code: 'COMMAND_6203_ENVELOPE' }
  ];

  for (const fixture of cases) {
    const session = createSession();
    session.handleFrame(decodeTcp10127Frame(CAPTURED_REQUESTS[0]));
    session.handleFrame(decodeTcp10127Frame(CAPTURED_KEYED_MANIFEST_REQUESTS[0]));
    session.handleFrame(decodeTcp10127Frame(
      Buffer.from(CAPTURED_COMMAND_6212_EXCHANGES[0].request, 'hex')
    ));
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(Buffer.from(fixture.request, 'hex'))),
      (error) => error instanceof Tcp10127ProtocolError && error.code === fixture.code
    );
  }

  const outOfOrderSession = createSession();
  outOfOrderSession.handleFrame(decodeTcp10127Frame(CAPTURED_REQUESTS[0]));
  outOfOrderSession.handleFrame(decodeTcp10127Frame(CAPTURED_KEYED_MANIFEST_REQUESTS[0]));
  assert.throws(
    () => outOfOrderSession.handleFrame(decodeTcp10127Frame(Buffer.from(
      CAPTURED_COMMAND_6203_REQUESTS[0],
      'hex'
    ))),
    (error) => error instanceof Tcp10127ProtocolError && error.code === 'COMMAND_6212_COMMAND'
  );
});

test('answers both unique captured canonical 0x6211 requests with provider value zero', () => {
  for (let index = 0; index < CAPTURED_COMMAND_6211_EXCHANGES.length; index += 1) {
    const exchange = CAPTURED_COMMAND_6211_EXCHANGES[index];
    const providerCalls = [];
    const session = createSession(() => 1, (request) => {
      providerCalls.push(request);
      return 0;
    });
    advanceToCommand6211(session, CAPTURED_COMMAND_6203_REQUESTS[index]);

    const result = session.handleFrame(decodeTcp10127Frame(
      Buffer.from(exchange.request, 'hex')
    ));
    assert.deepEqual(result.response, Buffer.from(exchange.response, 'hex'));
    assert.deepEqual(providerCalls, [{
      command: 0x6211,
      sequence: Buffer.from(exchange.request, 'hex')[5]
    }]);
    assert.equal(
      session.state,
      TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6213
    );
  }
});

test('serializes the injected 0x6211 value as an unsigned BE32 field', () => {
  const cases = [
    { value: 0, suffix: '00000000' },
    { value: 0x12345678, suffix: '12345678' },
    { value: 0xffffffff, suffix: 'ffffffff' }
  ];

  for (const fixture of cases) {
    const session = createSession(() => 1, () => fixture.value);
    advanceToCommand6211(session);
    const result = session.handleFrame(decodeTcp10127Frame(
      Buffer.from(CAPTURED_COMMAND_6211_EXCHANGES[0].request, 'hex')
    ));
    assert.equal(result.response.subarray(-4).toString('hex'), fixture.suffix);
  }
});

test('rejects malformed or out-of-order 0x6211 requests', () => {
  const cases = [
    { request: '0000026211d400ff', code: 'COMMAND_6211_DIRECTION' },
    { request: '0000016212d400ff', code: 'COMMAND_6211_COMMAND' },
    { request: '0000016211d401ff', code: 'COMMAND_6211_STATUS' },
    { request: '0000016211d40000', code: 'COMMAND_6211_UNKNOWN7' },
    { request: '0001016211d400ff00', code: 'COMMAND_6211_LENGTH' }
  ];

  for (const fixture of cases) {
    const session = createSession();
    advanceToCommand6211(session);
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(Buffer.from(fixture.request, 'hex'))),
      (error) => error instanceof Tcp10127ProtocolError && error.code === fixture.code
    );
  }

  const outOfOrderSession = createSession();
  outOfOrderSession.handleFrame(decodeTcp10127Frame(CAPTURED_REQUESTS[0]));
  outOfOrderSession.handleFrame(decodeTcp10127Frame(CAPTURED_KEYED_MANIFEST_REQUESTS[0]));
  outOfOrderSession.handleFrame(decodeTcp10127Frame(
    Buffer.from(CAPTURED_COMMAND_6212_EXCHANGES[0].request, 'hex')
  ));
  assert.throws(
    () => outOfOrderSession.handleFrame(decodeTcp10127Frame(Buffer.from(
      CAPTURED_COMMAND_6211_EXCHANGES[0].request,
      'hex'
    ))),
    (error) => error instanceof Tcp10127ProtocolError && error.code === 'COMMAND_6203_COMMAND'
  );
});

test('validates a synchronous unsigned 32-bit provider value for 0x6211 when supplied', () => {
  const invalidProviders = [
    { provider: () => -1, code: 'COMMAND_6211_VALUE' },
    { provider: () => 0x100000000, code: 'COMMAND_6211_VALUE' },
    { provider: () => 1.5, code: 'COMMAND_6211_VALUE' },
    { provider: async () => 1, code: 'COMMAND_6211_VALUE_PROVIDER' },
    {
      provider: () => { throw new Error('registry unavailable'); },
      code: 'COMMAND_6211_VALUE_PROVIDER'
    }
  ];

  for (const fixture of invalidProviders) {
    const session = createSession(() => 1, fixture.provider);
    advanceToCommand6211(session);
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(
        Buffer.from(CAPTURED_COMMAND_6211_EXCHANGES[0].request, 'hex')
      )),
      (error) => error instanceof Tcp10127ProtocolError && error.code === fixture.code
    );
  }
});

test('answers both unique captured canonical 0x6213 requests when the provider supplies zeros', () => {
  for (let index = 0; index < CAPTURED_COMMAND_6213_EXCHANGES.length; index += 1) {
    const exchange = CAPTURED_COMMAND_6213_EXCHANGES[index];
    const providerCalls = [];
    const session = createSession(() => 1, () => 0, (request) => {
      providerCalls.push(request);
      return Array(8).fill(0);
    });
    advanceToCommand6213(session, index);

    const result = session.handleFrame(decodeTcp10127Frame(
      Buffer.from(exchange.request, 'hex')
    ));
    assert.deepEqual(result.response, Buffer.from(exchange.response, 'hex'));
    assert.deepEqual(providerCalls, [{
      command: 0x6213,
      sequence: Buffer.from(exchange.request, 'hex')[5]
    }]);
    assert.equal(
      session.state,
      TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6501
    );
  }
});

test('serializes eight injected 0x6213 words in parser order as BE16', () => {
  const words = [0, 1, 0x1234, 0xabcd, 0x0708, 0xffff, 0x8000, 0x00ff];
  const session = createSession(() => 1, () => 0, () => words);
  advanceToCommand6213(session);

  const result = session.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6213_EXCHANGES[0].request,
    'hex'
  )));
  assert.equal(
    result.response.subarray(8).toString('hex'),
    '000000011234abcd0708ffff800000ff'
  );
});

test('rejects malformed or out-of-order 0x6213 requests', () => {
  const cases = [
    { request: '0000026213d500ff', code: 'COMMAND_6213_DIRECTION' },
    { request: '0000016212d500ff', code: 'COMMAND_6213_COMMAND' },
    { request: '0000016213d501ff', code: 'COMMAND_6213_STATUS' },
    { request: '0000016213d50000', code: 'COMMAND_6213_UNKNOWN7' },
    { request: '0001016213d500ff00', code: 'COMMAND_6213_LENGTH' }
  ];

  for (const fixture of cases) {
    const session = createSession();
    advanceToCommand6213(session);
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(Buffer.from(fixture.request, 'hex'))),
      (error) => error instanceof Tcp10127ProtocolError && error.code === fixture.code
    );
  }

  const outOfOrderSession = createSession();
  advanceToCommand6211(outOfOrderSession);
  assert.throws(
    () => outOfOrderSession.handleFrame(decodeTcp10127Frame(Buffer.from(
      CAPTURED_COMMAND_6213_EXCHANGES[0].request,
      'hex'
    ))),
    (error) => error instanceof Tcp10127ProtocolError && error.code === 'COMMAND_6211_COMMAND'
  );
});

test('validates exactly eight synchronous unsigned 16-bit words for 0x6213 when supplied', () => {
  const invalidProviders = [
    { provider: () => null, code: 'COMMAND_6213_WORDS_SHAPE' },
    { provider: () => Array(7).fill(0), code: 'COMMAND_6213_WORDS_SHAPE' },
    { provider: () => Array(9).fill(0), code: 'COMMAND_6213_WORDS_SHAPE' },
    { provider: async () => Array(8).fill(0), code: 'COMMAND_6213_WORDS_PROVIDER' },
    {
      provider: () => { throw new Error('configuration unavailable'); },
      code: 'COMMAND_6213_WORDS_PROVIDER'
    },
    { provider: () => [-1, 0, 0, 0, 0, 0, 0, 0], code: 'COMMAND_6213_WORD_VALUE' },
    { provider: () => [0x10000, 0, 0, 0, 0, 0, 0, 0], code: 'COMMAND_6213_WORD_VALUE' },
    { provider: () => [1.5, 0, 0, 0, 0, 0, 0, 0], code: 'COMMAND_6213_WORD_VALUE' }
  ];

  for (const fixture of invalidProviders) {
    const session = createSession(() => 1, () => 0, fixture.provider);
    advanceToCommand6213(session);
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(Buffer.from(
        CAPTURED_COMMAND_6213_EXCHANGES[0].request,
        'hex'
      ))),
      (error) => error instanceof Tcp10127ProtocolError && error.code === fixture.code
    );
  }
});

test('uses payload-less status-0xff client defaults only for the three proven ladder handlers', () => {
  const session = new Tcp10127LobbyInitializationSession({ areaTable: AREA_TABLE });
  session.handleFrame(decodeTcp10127Frame(CAPTURED_REQUESTS[0]));
  session.handleFrame(decodeTcp10127Frame(CAPTURED_KEYED_MANIFEST_REQUESTS[0]));

  let result = session.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6212_EXCHANGES[0].request,
    'hex'
  )));
  assert.deepEqual(result.response, CLIENT_DEFAULT_RESPONSES.command6212);
  assert.equal(session.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6203);

  result = session.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6203_REQUESTS[0],
    'hex'
  )));
  // 0x6203 has no status-0xff client default: it always answers mode 1 from the
  // area table, and the client may then skip straight to 0x6211.
  assert.equal(decodeTcp10127Frame(result.response).payload[0], 1);

  result = session.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6211_EXCHANGES[0].request,
    'hex'
  )));
  assert.deepEqual(result.response, CLIENT_DEFAULT_RESPONSES.command6211);
  assert.equal(session.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6213);

  result = session.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6213_EXCHANGES[0].request,
    'hex'
  )));
  assert.deepEqual(result.response, CLIENT_DEFAULT_RESPONSES.command6213);
  assert.equal(session.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6501);
});

test('selects explicit and client-default branches independently per ladder command', () => {
  const session = new Tcp10127LobbyInitializationSession({
    areaTable: AREA_TABLE,
    resolveCommand6212Value: () => 0x01020304,
    resolveCommand6213Words: () => [1, 2, 3, 4, 5, 6, 7, 8]
  });
  session.handleFrame(decodeTcp10127Frame(CAPTURED_REQUESTS[0]));
  session.handleFrame(decodeTcp10127Frame(CAPTURED_KEYED_MANIFEST_REQUESTS[0]));

  let result = session.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6212_EXCHANGES[0].request,
    'hex'
  )));
  assert.equal(result.response.toString('hex'), '00040262120700ff01020304');
  session.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6203_REQUESTS[0],
    'hex'
  )));

  result = session.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6211_EXCHANGES[0].request,
    'hex'
  )));
  assert.deepEqual(result.response, CLIENT_DEFAULT_RESPONSES.command6211);

  result = session.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6213_EXCHANGES[0].request,
    'hex'
  )));
  assert.equal(result.response.subarray(8).toString('hex'), '00010002000300040005000600070008');
  assert.equal(session.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6501);
});

test('answers both captured 0x6501 requests with resolver-selected mode 0', () => {
  for (let index = 0; index < CAPTURED_COMMAND_6501_EXCHANGES.length; index += 1) {
    const calls = [];
    const session = createSession(
      () => 1,
      () => 0,
      () => Array(8).fill(0),
      (request) => {
        calls.push(request);
        return { mode: 0 };
      }
    );
    advanceToCommand6501(session, index);
    const exchange = CAPTURED_COMMAND_6501_EXCHANGES[index];
    const result = session.handleFrame(decodeTcp10127Frame(Buffer.from(exchange.request, 'hex')));

    assert.deepEqual(result.response, Buffer.from(exchange.response, 'hex'));
    // `resumed` is the entry path the session observed: false because these
    // sessions were advanced through 0x1007. It is what the mode policy
    // discriminates on (T32), so the resolver must actually be told.
    assert.deepEqual(calls, [{
      command: 0x6501,
      sequence: Buffer.from(exchange.request, 'hex')[5],
      unknownRequestValue: 0,
      resumed: false
    }]);
    assert.equal(
      session.state,
      TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6501_MODE_0
    );
  }
});

test('serializes 0x6501 mode 1 fields in parser order as BE32', () => {
  const session = createSession(
    () => 1,
    () => 0,
    () => Array(8).fill(0),
    () => ({ mode: 1, unknown0: 0x12345678, unknown1: 0x89abcdef })
  );
  advanceToCommand6501(session);
  const result = session.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6501_EXCHANGES[0].request,
    'hex'
  )));

  assert.equal(result.response.toString('hex'), '0009026501d600ff011234567889abcdef');
  assert.equal(session.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6503);
});

test('rejects malformed 0x6501 requests and invalid resolver results', () => {
  const malformed = [
    { request: '0004026501d600ff00000000', code: 'COMMAND_6501_DIRECTION' },
    { request: '0004016502d600ff00000000', code: 'COMMAND_6501_COMMAND' },
    { request: '0003016501d600ff000000', code: 'COMMAND_6501_LENGTH' },
    { request: '0004016501d601ff00000000', code: 'COMMAND_6501_STATUS' },
    { request: '0004016501d6000000000000', code: 'COMMAND_6501_UNKNOWN7' }
  ];
  for (const fixture of malformed) {
    const session = createSession();
    advanceToCommand6501(session);
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(Buffer.from(fixture.request, 'hex'))),
      (error) => error instanceof Tcp10127ProtocolError && error.code === fixture.code
    );
  }

  const invalid = [
    { provider: undefined, code: 'COMMAND_6501_RESPONSE_PROVIDER' },
    { provider: async () => ({ mode: 0 }), code: 'COMMAND_6501_RESPONSE_PROVIDER' },
    { provider: () => { throw new Error('state unavailable'); }, code: 'COMMAND_6501_RESPONSE_PROVIDER' },
    { provider: () => null, code: 'COMMAND_6501_RESPONSE_SHAPE' },
    { provider: () => [], code: 'COMMAND_6501_RESPONSE_SHAPE' },
    { provider: () => ({ mode: 2 }), code: 'COMMAND_6501_RESPONSE_MODE' },
    { provider: () => ({ mode: 0, unknown0: 0 }), code: 'COMMAND_6501_RESPONSE_SHAPE' },
    { provider: () => ({ mode: 1, unknown0: 0 }), code: 'COMMAND_6501_RESPONSE_SHAPE' },
    { provider: () => ({ mode: 1, unknown0: -1, unknown1: 0 }), code: 'COMMAND_6501_RESPONSE_VALUE' },
    { provider: () => ({ mode: 1, unknown0: 0, unknown1: 0x100000000 }), code: 'COMMAND_6501_RESPONSE_VALUE' },
    { provider: () => ({ mode: 1, unknown0: 0, unknown1: 1.5 }), code: 'COMMAND_6501_RESPONSE_VALUE' }
  ];
  for (const fixture of invalid) {
    const session = new Tcp10127LobbyInitializationSession({
      areaTable: AREA_TABLE,
      resolveCommand6501Response: fixture.provider
    });
    advanceToCommand6501(session);
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(Buffer.from(
        CAPTURED_COMMAND_6501_EXCHANGES[0].request,
        'hex'
      ))),
      (error) => error instanceof Tcp10127ProtocolError && error.code === fixture.code
    );
  }
});

test('preserves only branch-specific commands after 0x6501', () => {
  const mode0For6510 = createSession();
  advanceToCommand6501(mode0For6510);
  mode0For6510.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6501_EXCHANGES[0].request,
    'hex'
  )));
  const answered6510 = mode0For6510.handleFrame(decodeTcp10127Frame(buildCommand6510Request({
    sequence: 0xd7,
    recordFields: [Buffer.from('SLOT0001', 'latin1')]
  })));
  assert.equal(answered6510.request.command, 0x6510);
  assert.equal(answered6510.unimplemented, false);
  assert.equal(
    answered6510.state,
    TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6510
  );

  // The mode-1 branch ANSWERS 0x6503 (T32); it used to merely preserve it. The
  // request carries FUN_001c7000's two BE16 values, so a zero-payload frame is
  // no longer a valid 0x6503 at all.
  const mode1 = createSession(
    () => 1,
    () => 0,
    () => Array(8).fill(0),
    () => ({ mode: 1, unknown0: 0, unknown1: 0 })
  );
  advanceToCommand6501(mode1);
  mode1.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6501_EXCHANGES[0].request,
    'hex'
  )));
  const listed = mode1.handleFrame(
    decodeTcp10127Frame(Buffer.from('0004016503d700ff00000008', 'hex'))
  );
  assert.equal(listed.request.command, 0x6503);
  assert.equal(listed.unimplemented, false);
  assert.equal(
    listed.state,
    TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6503_COMPLETE
  );

  // 0x6502 is the only command FUN_001c70b0 can reach once the list is complete
  // (it sets phase 8), so anything else after it is a divergence, not traffic to
  // absorb quietly.
  assert.throws(
    () => mode1.handleFrame(decodeTcp10127Frame(Buffer.from('0000016510d800ff', 'hex'))),
    (error) => error instanceof Tcp10127ProtocolError &&
      error.code === 'COMMAND_6503_COMPLETE_FOLLOWUP_COMMAND'
  );

  // 0x6503 belongs to the mode-1 branch, so a mode-0 session must reject it
  // while still parked after 0x6501.
  const mode0Rejecting = createSession();
  advanceToCommand6501(mode0Rejecting);
  mode0Rejecting.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6501_EXCHANGES[0].request,
    'hex'
  )));
  assert.throws(
    () => mode0Rejecting.handleFrame(
      decodeTcp10127Frame(Buffer.from('0004016503d800ff00000008', 'hex'))
    ),
    (error) => error instanceof Tcp10127ProtocolError &&
      error.code === 'COMMAND_6501_MODE_0_FOLLOWUP_COMMAND'
  );
  // Once 0x6510 has been answered, only its own decoded continuations remain.
  assert.throws(
    () => mode0For6510.handleFrame(decodeTcp10127Frame(Buffer.from('0000016503d800ff', 'hex'))),
    (error) => error instanceof Tcp10127ProtocolError &&
      error.code === 'COMMAND_6510_FOLLOWUP_COMMAND'
  );
  // A mode-1 session PARKED on 0x6503 accepts nothing else. `nextRequest` here
  // is the captured 0x6502, which is legal only AFTER the entry list is
  // complete - reaching it early would mean the client had skipped the list.
  const mode1Awaiting = createSession(
    () => 1,
    () => 0,
    () => Array(8).fill(0),
    () => ({ mode: 1, unknown0: 0, unknown1: 0 })
  );
  advanceToCommand6501(mode1Awaiting);
  mode1Awaiting.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6501_EXCHANGES[0].request,
    'hex'
  )));
  assert.throws(
    () => mode1Awaiting.handleFrame(decodeTcp10127Frame(Buffer.from(
      CAPTURED_COMMAND_6501_EXCHANGES[0].nextRequest,
      'hex'
    ))),
    (error) => error instanceof Tcp10127ProtocolError &&
      error.code === 'COMMAND_6503_COMMAND'
  );
  // And once the list IS complete, that same 0x6502 is exactly what belongs.
  assert.equal(
    mode1.handleFrame(decodeTcp10127Frame(Buffer.from(
      CAPTURED_COMMAND_6501_EXCHANGES[0].nextRequest,
      'hex'
    ))).request.command,
    0x6502
  );
});

/* ---- 0x6503, the entry list ------------------------------------------- */

/** A session that has been answered mode 1 and is parked awaiting 0x6503. */
function sessionAwaitingCommand6503(resolveCommand6503Response = defaultCommand6503Selection) {
  const session = createSession(
    () => 1,
    () => 0,
    () => Array(8).fill(0),
    () => ({ mode: 1, unknown0: 0, unknown1: 0 }),
    undefined,
    undefined,
    undefined,
    resolveCommand6503Response
  );
  advanceToCommand6501(session);
  session.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6501_EXCHANGES[0].request,
    'hex'
  )));
  return session;
}

const COMMAND_6503_REQUEST_AT_ZERO = Buffer.from('0004016503d700ff00000008', 'hex');

test('encodes a single-entry 0x6503 batch in parser order, byte for byte', () => {
  const calls = [];
  const session = sessionAwaitingCommand6503((request) => {
    calls.push(request);
    return defaultCommand6503Selection();
  });
  const result = session.handleFrame(decodeTcp10127Frame(COMMAND_6503_REQUEST_AT_ZERO));

  // FUN_001c7000 sends the offset it holds and the count it wants; both must
  // reach the provider, because the provider owns which window it answers.
  assert.deepEqual(calls, [{
    command: 0x6503,
    sequence: 0xd7,
    requestedStart: 0,
    requestedCount: 8
  }]);
  const payload = result.response.subarray(8);
  assert.equal(result.response.readUInt16BE(0), payload.length);
  assert.equal(result.response[2], 0x02, 'server direction');
  assert.equal(result.response.readUInt16BE(3), 0x6503);
  assert.equal(result.response[5], 0xd7, 'the sequence of the request it answers');
  assert.equal(payload.readUInt16BE(0), 1, 'total -> 0x365e1e');
  assert.equal(payload.readUInt16BE(2), 0, 'batchStart -> 0x365e18');
  assert.equal(payload[4], 1, 'batchCount -> 0x365e1c');

  // Field for field, in FUN_001c70b0's own order and against its own bounds.
  let cursor = 5;
  const decoded = [];
  for (const bound of [0x3e, 0x0f]) {
    const lengthWord = payload.readUInt16BE(cursor);
    decoded.push(decodeSnapField({
      field: payload.subarray(cursor, cursor + 2 + lengthWord),
      maximumDecodedLength: bound,
      sequence: 0xd7,
      unknownCodecByte: 0
    }).toString('latin1'));
    cursor += 2 + lengthWord;
  }
  assert.equal(payload.subarray(cursor, cursor + 8).toString('hex'), '0000000000000000');
  cursor += 8;
  const descriptionLengthWord = payload.readUInt16BE(cursor);
  decoded.push(decodeSnapField({
    field: payload.subarray(cursor, cursor + 2 + descriptionLengthWord),
    maximumDecodedLength: 0xff,
    sequence: 0xd7,
    unknownCodecByte: 0
  }).toString('latin1'));
  cursor += 2 + descriptionLengthWord;
  assert.equal(cursor, payload.length, 'the entry consumes the whole payload');
  assert.deepEqual(decoded, ['10.0.0.1', 'E', 'd']);
  assert.equal(result.unimplemented, false);
});

test('rejects malformed 0x6503 requests', () => {
  for (const [label, hex] of [
    ['a zero-length payload', '0000016503d700ff'],
    ['a truncated window', '0002016503d700ff0000'],
    ['an over-long payload', '0006016503d700ff000000080000'],
    ['a nonzero status byte', '0004016503d701ff00000008'],
    ['the wrong header byte 7', '0004016503d7000000000008'],
    ['a server-direction frame', '0004026503d700ff00000008']
  ]) {
    const session = sessionAwaitingCommand6503();
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(Buffer.from(hex, 'hex'))),
      (error) => error instanceof Tcp10127ProtocolError &&
        error.code.startsWith('COMMAND_6503_'),
      `expected ${label} to be refused`
    );
  }
});

test('rejects 0x6503 resolver results the PAL parser could not survive', () => {
  const entry = () => ({
    host: Buffer.from('10.0.0.1', 'latin1'),
    name: Buffer.from('E', 'latin1'),
    raw8: Buffer.alloc(8),
    description: Buffer.from('d', 'latin1')
  });
  const base = { total: 1, batchStart: 0, unknownCodecByte: 0, entries: [entry()] };

  for (const [label, selection, code] of [
    // total == 0 is a terminal -1 inside FUN_001c70b0, so it must never be sent.
    ['a zero total', { ...base, total: 0 }, 'COMMAND_6503_RESPONSE_TOTAL'],
    // > 0x10 is terminal when the connection state word is 1, which V2 cannot see.
    ['a total above the client ceiling', { ...base, total: 17 }, 'COMMAND_6503_RESPONSE_TOTAL'],
    ['a fractional total', { ...base, total: 1.5 }, 'COMMAND_6503_RESPONSE_TOTAL'],
    ['a negative batchStart', { ...base, batchStart: -1 }, 'COMMAND_6503_RESPONSE_START'],
    ['an empty batch', { ...base, entries: [] }, 'COMMAND_6503_RESPONSE_ENTRIES'],
    [
      'a batch that runs past the declared total',
      { ...base, batchStart: 1 },
      'COMMAND_6503_RESPONSE_RANGE'
    ],
    [
      'a codec byte that is not a byte',
      { ...base, unknownCodecByte: 256 },
      'COMMAND_6503_RESPONSE_CODEC_BYTE'
    ],
    [
      'a host above the 0x3e bound enforced by FUN_001c3b90',
      { ...base, entries: [{ ...entry(), host: Buffer.alloc(0x3f, 0x41) }] },
      'COMMAND_6503_RESPONSE_ENTRY_LENGTH'
    ],
    [
      'a name above the 0x0f bound',
      { ...base, entries: [{ ...entry(), name: Buffer.alloc(0x10, 0x41) }] },
      'COMMAND_6503_RESPONSE_ENTRY_LENGTH'
    ],
    [
      'a description above the 0xff bound',
      { ...base, entries: [{ ...entry(), description: Buffer.alloc(0x100, 0x41) }] },
      'COMMAND_6503_RESPONSE_ENTRY_LENGTH'
    ],
    [
      'a raw block that is not eight bytes',
      { ...base, entries: [{ ...entry(), raw8: Buffer.alloc(7) }] },
      'COMMAND_6503_RESPONSE_ENTRY_LENGTH'
    ],
    [
      'a host that is not a Buffer',
      { ...base, entries: [{ ...entry(), host: '10.0.0.1' }] },
      'COMMAND_6503_RESPONSE_ENTRY_BUFFER'
    ],
    [
      'an entry missing a parser-consumed field',
      {
        ...base,
        entries: [{ host: Buffer.alloc(1), name: Buffer.alloc(1), raw8: Buffer.alloc(8) }]
      },
      'COMMAND_6503_RESPONSE_ENTRY_SHAPE'
    ],
    [
      'an entry carrying an extra field',
      { ...base, entries: [{ ...entry(), extra: 1 }] },
      'COMMAND_6503_RESPONSE_ENTRY_SHAPE'
    ],
    ['an extra top-level field', { ...base, extra: 1 }, 'COMMAND_6503_RESPONSE_SHAPE'],
    ['an array', [], 'COMMAND_6503_RESPONSE_SHAPE'],
    ['null', null, 'COMMAND_6503_RESPONSE_SHAPE']
  ]) {
    const session = sessionAwaitingCommand6503(() => selection);
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(COMMAND_6503_REQUEST_AT_ZERO)),
      (error) => error instanceof Tcp10127ProtocolError && error.code === code,
      `expected ${label} to be refused with ${code}`
    );
  }

  // A provider that throws, and one that returns a promise, are both refused
  // rather than turned into a half-built frame.
  for (const resolver of [
    () => { throw new Error('no directory'); },
    () => Promise.resolve(base)
  ]) {
    const session = sessionAwaitingCommand6503(resolver);
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(COMMAND_6503_REQUEST_AT_ZERO)),
      (error) => error instanceof Tcp10127ProtocolError &&
        error.code === 'COMMAND_6503_RESPONSE_PROVIDER'
    );
  }
});

test('0x6503 loops while the batch is short of the total and then admits 0x6502', () => {
  // FUN_001c70b0: `0x365e18 += batchCount`, and while that is below the total it
  // returns to phase 6 for another 0x6503. The session must stay open to one.
  let seenStart = null;
  const session = sessionAwaitingCommand6503(({ requestedStart }) => {
    seenStart = requestedStart;
    return {
      total: 3,
      batchStart: requestedStart,
      unknownCodecByte: 0,
      entries: [defaultCommand6503Selection().entries[0]]
    };
  });

  for (const [offset, expectedState] of [
    [0, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_MORE_COMMAND_6503],
    [1, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_MORE_COMMAND_6503],
    [2, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6503_COMPLETE]
  ]) {
    const window = Buffer.alloc(4);
    window.writeUInt16BE(offset, 0);
    window.writeUInt16BE(8, 2);
    const request = Buffer.concat([Buffer.from('0004016503d700ff', 'hex'), window]);
    const result = session.handleFrame(decodeTcp10127Frame(request));
    assert.equal(seenStart, offset, 'the requested offset reaches the provider unchanged');
    assert.equal(result.state, expectedState);
  }

  assert.equal(
    session.handleFrame(decodeTcp10127Frame(Buffer.from(
      CAPTURED_COMMAND_6501_EXCHANGES[0].nextRequest,
      'hex'
    ))).request.command,
    0x6502
  );
});

test('answers both captured 0x6502 requests with resolver-selected mode 1', () => {
  for (let index = 0; index < CAPTURED_COMMAND_6502_EXCHANGES.length; index += 1) {
    const calls = [];
    const session = createSession(
      () => 1,
      () => 0,
      () => Array(8).fill(0),
      () => ({ mode: 0 }),
      (request) => {
        calls.push(request);
        return { mode: 1, unknown0: 1, unknown1: 1 };
      }
    );
    advanceToCommand6502(session, index);
    const exchange = CAPTURED_COMMAND_6502_EXCHANGES[index];
    const result = session.handleFrame(decodeTcp10127Frame(Buffer.from(exchange.request, 'hex')));

    assert.deepEqual(result.response, Buffer.from(exchange.response, 'hex'));
    assert.equal(calls[0].command, 0x6502);
    assert.equal(calls[0].sequence, Buffer.from(exchange.request, 'hex')[5]);
    assert.equal(calls[0].unknownRequestValue, 0);
    assert.equal(calls[0].unknownEncodedField.toString('hex'), exchange.request.slice(24));
    assert.equal(session.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6504);
  }
});

test('preserves a variable 0x6502 encoded field and serializes distinctive mode-1 BE32 order', () => {
  const calls = [];
  const session = createSession(
    () => 1,
    () => 0,
    () => Array(8).fill(0),
    () => ({ mode: 0 }),
    (request) => {
      calls.push(request);
      return { mode: 1, unknown0: 0x12345678, unknown1: 0x89abcdef };
    }
  );
  advanceToCommand6502(session);
  const request = Buffer.from('000a016502d700ff112233440004abcd0102', 'hex');
  const result = session.handleFrame(decodeTcp10127Frame(request));

  assert.equal(result.response.toString('hex'), '0009026502d700ff011234567889abcdef');
  assert.equal(calls[0].unknownRequestValue, 0x11223344);
  assert.equal(calls[0].unknownEncodedField.toString('hex'), '0004abcd0102');
});

test('rejects malformed 0x6502 requests and invalid resolver results', () => {
  const malformed = [
    { request: '0008026502d700ff00000000000257d7', code: 'COMMAND_6502_DIRECTION' },
    {
      request: '0008016503d700ff00000000000257d7',
      code: 'COMMAND_6501_MODE_0_FOLLOWUP_COMMAND'
    },
    { request: '0007016502d700ff00000000000257', code: 'COMMAND_6502_LENGTH' },
    { request: '0008016502d700ff00000000000357d7', code: 'COMMAND_6502_ENVELOPE' },
    { request: '0008016502d701ff00000000000257d7', code: 'COMMAND_6502_STATUS' },
    { request: '0008016502d7000000000000000257d7', code: 'COMMAND_6502_UNKNOWN7' }
  ];
  for (const fixture of malformed) {
    const session = createSession();
    advanceToCommand6502(session);
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(Buffer.from(fixture.request, 'hex'))),
      (error) => error instanceof Tcp10127ProtocolError && error.code === fixture.code
    );
  }

  const invalid = [
    { provider: undefined, code: 'COMMAND_6502_RESPONSE_PROVIDER' },
    { provider: async () => ({ mode: 0 }), code: 'COMMAND_6502_RESPONSE_PROVIDER' },
    { provider: () => { throw new Error('state unavailable'); }, code: 'COMMAND_6502_RESPONSE_PROVIDER' },
    { provider: () => null, code: 'COMMAND_6502_RESPONSE_SHAPE' },
    { provider: () => ({ mode: 2 }), code: 'COMMAND_6502_RESPONSE_MODE' },
    { provider: () => ({ mode: 0, unknown0: 0 }), code: 'COMMAND_6502_RESPONSE_SHAPE' },
    { provider: () => ({ mode: 1, unknown0: 0 }), code: 'COMMAND_6502_RESPONSE_SHAPE' },
    { provider: () => ({ mode: 1, unknown0: -1, unknown1: 0 }), code: 'COMMAND_6502_RESPONSE_VALUE' },
    { provider: () => ({ mode: 1, unknown0: 0, unknown1: 0x100000000 }), code: 'COMMAND_6502_RESPONSE_VALUE' }
  ];
  for (const fixture of invalid) {
    const session = new Tcp10127LobbyInitializationSession({
      areaTable: AREA_TABLE,
      resolveCommand6501Response: () => ({ mode: 0 }),
      resolveCommand6502Response: fixture.provider
    });
    advanceToCommand6502(session);
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(Buffer.from(
        CAPTURED_COMMAND_6502_EXCHANGES[0].request,
        'hex'
      ))),
      (error) => error instanceof Tcp10127ProtocolError && error.code === fixture.code
    );
  }
});

test('preserves only branch-specific commands after 0x6502', () => {
  const mode1 = createSession();
  advanceToCommand6502(mode1);
  mode1.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6502_EXCHANGES[0].request,
    'hex'
  )));
  assert.equal(mode1.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6504);

  let selectionCount = 0;
  const looping = createSession(
    () => 1,
    () => 0,
    () => Array(8).fill(0),
    () => ({ mode: 0 }),
    () => (++selectionCount === 1
      ? { mode: 0 }
      : { mode: 1, unknown0: 2, unknown1: 3 })
  );
  advanceToCommand6502(looping);
  let result = looping.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6502_EXCHANGES[0].request,
    'hex'
  )));
  assert.equal(result.response.toString('hex'), '0001026502d700ff00');
  assert.equal(looping.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6502_MODE_0);
  result = looping.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6502_EXCHANGES[1].request,
    'hex'
  )));
  assert.equal(result.response.subarray(8).toString('hex'), '010000000200000003');

  const finishing = createSession(
    () => 1,
    () => 0,
    () => Array(8).fill(0),
    () => ({ mode: 0 }),
    () => ({ mode: 0 })
  );
  advanceToCommand6502(finishing);
  finishing.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6502_EXCHANGES[0].request,
    'hex'
  )));
  const answered = finishing.handleFrame(decodeTcp10127Frame(buildCommand6510Request({
    sequence: 0xd8,
    recordFields: [Buffer.from('SLOT0001', 'latin1')]
  })));
  assert.equal(answered.request.command, 0x6510);
  assert.equal(answered.unimplemented, false);
  assert.equal(
    finishing.state,
    TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6510
  );
});

test('encodes the runtime-confirmed p5-0x0d 0x6504 record byte-for-byte', () => {
  const calls = [];
  const session = createCommand6504Session((request) => {
    calls.push(request);
    return runtimeCompatibleCommand6504Selection();
  });
  advanceToCommand6504(session, 1);
  const result = session.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6504_REQUESTS[1],
    'hex'
  )));

  assert.equal(result.response.toString('hex'),
    '00360265040d00ff' +
    '0001000001' +
    '000a0f10130b0e056c6b6c6d' +
    '00060e3f0f17041f' +
    '0000000000000000' +
    '000b106f142232257c0830332c' +
    '00000008c00002c4');
  assert.equal(calls.length, 1);
  assert.equal(calls[0].command, 0x6504);
  assert.equal(calls[0].sequence, 0x0d);
  assert.equal(calls[0].unknownRequestWord0, 0);
  assert.equal(calls[0].unknownRequestWord1, 8);
  assert.equal(calls[0].unknownEncodedField.toString('hex'), '00020d0d');
  assert.equal(
    session.state,
    TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6504_COMPLETE
  );
});

test('serializes distinctive 0x6504 fields and follows decoded batch substates', () => {
  let callCount = 0;
  const firstRecord = {
    unknownField0: Buffer.from([0x10, 0x20]),
    unknownField1: Buffer.from([0x30]),
    unknownRaw8: Buffer.from('0102030405060708', 'hex'),
    unknownField2: Buffer.from([0x40, 0x50, 0x60]),
    unknownWord0: 0x1234,
    unknownWord1: 0x5678,
    unknownDword: 0x89abcdef
  };
  const session = createCommand6504Session(() => {
    callCount += 1;
    return callCount === 1
      ? { unknownTotal: 3, unknownStart: 1, unknownCodecByte: 0x17, records: [firstRecord] }
      : {
          unknownTotal: 3,
          unknownStart: 2,
          unknownCodecByte: 0x17,
          records: [{
            unknownField0: Buffer.alloc(0),
            unknownField1: Buffer.alloc(0),
            unknownRaw8: Buffer.alloc(8),
            unknownField2: Buffer.alloc(0),
            unknownWord0: 0,
            unknownWord1: 0,
            unknownDword: 0
          }]
        };
  });
  advanceToCommand6504(session);
  let result = session.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6504_REQUESTS[0],
    'hex'
  )));
  const expectedPayload = Buffer.concat([
    Buffer.from('0003000101', 'hex'),
    encodeSnapField({
      plain: firstRecord.unknownField0,
      maximumDecodedLength: 0x0f,
      sequence: 0xd8,
      unknownCodecByte: 0x17
    }),
    encodeSnapField({
      plain: firstRecord.unknownField1,
      maximumDecodedLength: 0x0f,
      sequence: 0xd8,
      unknownCodecByte: 0x17
    }),
    firstRecord.unknownRaw8,
    encodeSnapField({
      plain: firstRecord.unknownField2,
      maximumDecodedLength: 0xff,
      sequence: 0xd8,
      unknownCodecByte: 0x17
    }),
    Buffer.from('1234567889abcdef', 'hex')
  ]);
  assert.deepEqual(result.response.subarray(8), expectedPayload);
  assert.equal(session.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_MORE_COMMAND_6504);
  assert.throws(
    () => session.handleFrame(decodeTcp10127Frame(Buffer.from('0000016510d900ff', 'hex'))),
    (error) => error instanceof Tcp10127ProtocolError && error.code === 'COMMAND_6504_COMMAND'
  );

  result = session.handleFrame(decodeTcp10127Frame(Buffer.from(
    '0008016504d900ff00020008000259d9',
    'hex'
  )));
  assert.equal(result.response.subarray(8, 13).toString('hex'), '0003000201');
  assert.equal(
    session.state,
    TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6504_COMPLETE
  );
});

test('rejects malformed 0x6504 requests and invalid resolver results', () => {
  const malformed = [
    { request: '0008026504d800ff00000008000258d8', code: 'COMMAND_6504_DIRECTION' },
    { request: '0008016503d800ff00000008000258d8', code: 'COMMAND_6504_COMMAND' },
    { request: '0007016504d800ff00000008000258', code: 'COMMAND_6504_LENGTH' },
    { request: '0008016504d800ff00000008000358d8', code: 'COMMAND_6504_ENVELOPE' },
    { request: '0008016504d8ffff00000008000258d8', code: 'COMMAND_6504_STATUS' },
    { request: '0008016504d8000000000008000258d8', code: 'COMMAND_6504_UNKNOWN7' }
  ];
  for (const fixture of malformed) {
    const session = createSession();
    advanceToCommand6504(session);
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(Buffer.from(fixture.request, 'hex'))),
      (error) => error instanceof Tcp10127ProtocolError && error.code === fixture.code
    );
  }

  const valid = runtimeCompatibleCommand6504Selection();
  const invalid = [
    { provider: async () => valid, code: 'COMMAND_6504_RESPONSE_PROVIDER' },
    { provider: () => { throw new Error('state unavailable'); }, code: 'COMMAND_6504_RESPONSE_PROVIDER' },
    { provider: () => null, code: 'COMMAND_6504_RESPONSE_SHAPE' },
    { provider: () => ({ ...valid, extra: 1 }), code: 'COMMAND_6504_RESPONSE_SHAPE' },
    { provider: () => ({ ...valid, unknownTotal: 0 }), code: 'COMMAND_6504_RESPONSE_TOTAL' },
    { provider: () => ({ ...valid, unknownTotal: 65 }), code: 'COMMAND_6504_RESPONSE_TOTAL' },
    { provider: () => ({ ...valid, unknownStart: -1 }), code: 'COMMAND_6504_RESPONSE_START' },
    { provider: () => ({ ...valid, unknownCodecByte: 256 }), code: 'COMMAND_6504_RESPONSE_CODEC_BYTE' },
    { provider: () => ({ ...valid, records: [] }), code: 'COMMAND_6504_RESPONSE_RECORDS' },
    { provider: () => ({ ...valid, unknownStart: 1 }), code: 'COMMAND_6504_RESPONSE_RANGE' },
    {
      provider: () => ({ ...valid, records: [{ ...valid.records[0], unknownField0: 'text' }] }),
      code: 'COMMAND_6504_RESPONSE_RECORD_BUFFER'
    },
    {
      provider: () => ({ ...valid, records: [{
        ...valid.records[0], unknownField2: Buffer.alloc(0x100)
      }] }),
      code: 'COMMAND_6504_RESPONSE_RECORD_LENGTH'
    },
    {
      provider: () => ({ ...valid, records: [{ ...valid.records[0], unknownRaw8: Buffer.alloc(7) }] }),
      code: 'COMMAND_6504_RESPONSE_RECORD_LENGTH'
    },
    {
      provider: () => ({ ...valid, records: [{ ...valid.records[0], unknownWord1: -1 }] }),
      code: 'COMMAND_6504_RESPONSE_RECORD_VALUE'
    },
    {
      provider: () => ({ ...valid, records: [{
        ...valid.records[0], unknownDword: 0x100000000
      }] }),
      code: 'COMMAND_6504_RESPONSE_RECORD_VALUE'
    }
  ];
  for (const fixture of invalid) {
    const session = createCommand6504Session(fixture.provider);
    advanceToCommand6504(session);
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(Buffer.from(
        CAPTURED_COMMAND_6504_REQUESTS[0],
        'hex'
      ))),
      (error) => error instanceof Tcp10127ProtocolError && error.code === fixture.code
    );
  }

  const missingProvider = new Tcp10127LobbyInitializationSession({
    areaTable: AREA_TABLE,
    resolveCommand6501Response: () => ({ mode: 0 }),
    resolveCommand6502Response: () => ({ mode: 1, unknown0: 1, unknown1: 1 })
  });
  advanceToCommand6504(missingProvider);
  assert.throws(
    () => missingProvider.handleFrame(decodeTcp10127Frame(Buffer.from(
      CAPTURED_COMMAND_6504_REQUESTS[0],
      'hex'
    ))),
    (error) => error instanceof Tcp10127ProtocolError &&
      error.code === 'COMMAND_6504_RESPONSE_PROVIDER'
  );
});

test('answers both decoded continuations after a complete 0x6504 batch', () => {
  /*
   * 0x6502 here is the NEXT ENTRY, and it is answered as of T32.
   *
   * FUN_001c7a70's tail increments 0x365e0c when an entry's records are done
   * and, while 0x365e0c < 0x365e1e, routes to phase 8 - the 0x6502 builder -
   * rather than to 0x6510. It used to be observed-but-unanswered here, and that
   * was invisible because 0x365e1e is written only by 0x6503: with no entry list
   * the total stayed 0 and no client could reach a second entry.
   */
  const nextEntry = createSession();
  advanceToCommand6504(nextEntry);
  nextEntry.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6504_REQUESTS[0],
    'hex'
  )));
  const answeredEntry = nextEntry.handleFrame(decodeTcp10127Frame(
    Buffer.from('0008016502d900ff0000000000020000', 'hex')
  ));
  assert.equal(answeredEntry.unimplemented, false);
  assert.equal(answeredEntry.request.command, 0x6502);
  assert.equal(
    answeredEntry.state,
    TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6504,
    "the default provider answers mode 1, which sends the client to that entry's records"
  );

  // Anything outside the two decoded continuations is still refused.
  const rejecting = createSession();
  advanceToCommand6504(rejecting);
  rejecting.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6504_REQUESTS[0],
    'hex'
  )));
  assert.throws(
    () => rejecting.handleFrame(decodeTcp10127Frame(Buffer.from('0000016503d900ff', 'hex'))),
    (error) => error instanceof Tcp10127ProtocolError &&
      error.code === 'COMMAND_6504_COMPLETE_FOLLOWUP_COMMAND'
  );

  // 0x6510 is now answered from the same completed-batch state.
  const answering = createSession();
  advanceToCommand6504(answering);
  answering.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6504_REQUESTS[0],
    'hex'
  )));
  const answered = answering.handleFrame(decodeTcp10127Frame(buildCommand6510Request({
    sequence: 0xd9,
    recordFields: [Buffer.from('SLOT0001', 'latin1')]
  })));
  assert.equal(answered.unimplemented, false);
  assert.equal(answered.request.command, 0x6510);
  assert.equal(
    answering.state,
    TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6510
  );

  const rejected = createSession();
  advanceToCommand6504(rejected);
  rejected.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6504_REQUESTS[0],
    'hex'
  )));
  assert.throws(
    () => rejected.handleFrame(decodeTcp10127Frame(Buffer.from(
      CAPTURED_COMMAND_6504_REQUESTS[0],
      'hex'
    ))),
    (error) => error instanceof Tcp10127ProtocolError &&
      error.code === 'COMMAND_6504_COMPLETE_FOLLOWUP_COMMAND'
  );
});

function buildCommand6510Frame({
  sequence = 0xd9,
  payload,
  direction = 0x01,
  error = 0,
  unknown7 = 0xff
}) {
  const header = Buffer.alloc(8);
  header.writeUInt16BE(payload.length, 0);
  header[2] = direction;
  header.writeUInt16BE(0x6510, 3);
  header[5] = sequence;
  header[6] = error;
  header[7] = unknown7;
  return Buffer.concat([header, payload]);
}

function advanceToCommand6510(session, index = 0) {
  advanceToCommand6504(session, index);
  session.handleFrame(decodeTcp10127Frame(Buffer.from(
    CAPTURED_COMMAND_6504_REQUESTS[index],
    'hex'
  )));
}

function createCommand6510Session(resolveCommand6510Response) {
  return createSession(
    () => 1,
    () => 0,
    () => Array(8).fill(0),
    () => ({ mode: 0 }),
    () => ({ mode: 1, unknown0: 1, unknown1: 1 }),
    runtimeCompatibleCommand6504Selection,
    resolveCommand6510Response
  );
}

test('encodes a single-record 0x6510 batch byte-for-byte and echoes the request count', () => {
  const calls = [];
  const session = createCommand6510Session((request) => {
    calls.push(request);
    return {
      unknownCodecByte: 0,
      recordWords: [0],
      unknownTrailingField: Buffer.from('SLOT0001', 'latin1')
    };
  });
  advanceToCommand6510(session);

  const result = session.handleFrame(decodeTcp10127Frame(buildCommand6510Request({
    sequence: 0xd8,
    recordFields: [Buffer.from('SLOT0001', 'latin1')]
  })));

  // Header, echoed count 0x01, one BE16 record word, then the trailing field.
  assert.equal(
    result.response.toString('hex'),
    '000f026510d800ff' + '01' + '0000' + '000a5adbc6dcdbcea1a4a1a6'
  );
  assert.equal(session.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6510);

  assert.equal(calls.length, 1);
  assert.equal(calls[0].command, 0x6510);
  assert.equal(calls[0].sequence, 0xd8);
  assert.equal(calls[0].requestRecordCount, 1);
  assert.equal(calls[0].unknownEncodedRecordFields.length, 1);
  assert.equal(
    calls[0].unknownEncodedRecordFields[0].toString('hex'),
    '000a5adbc6dcdbcea1a4a1a6'
  );
  assert.equal(calls[0].unknownEncodedTrailingField.toString('hex'), '000258d8');
});

test('serializes 0x6510 record words in request order and accepts the full 12-record batch', () => {
  const words = [0x1122, 0x3344, 0x5566, 0x7788, 0x99aa, 0xbbcc,
    0xddee, 0x0001, 0x0002, 0x0003, 0x0004, 0xffff];
  const session = createCommand6510Session(() => ({
    unknownCodecByte: 0,
    recordWords: words,
    unknownTrailingField: Buffer.alloc(0)
  }));
  advanceToCommand6510(session);

  const result = session.handleFrame(decodeTcp10127Frame(buildCommand6510Request({
    sequence: 0xd8,
    recordFields: words.map((_, index) => Buffer.from('REC' + index, 'latin1'))
  })));

  const payload = result.response.subarray(8);
  assert.equal(payload[0], 12);
  for (let index = 0; index < words.length; index += 1) {
    assert.equal(payload.readUInt16BE(1 + index * 2), words[index]);
  }
  // The trailing field follows the words: BE16 length 2 for an empty plaintext.
  assert.equal(payload.readUInt16BE(1 + words.length * 2), 2);
  assert.equal(payload.length, 1 + words.length * 2 + 4);
});

test('answers a zero-record 0x6510 batch without inventing words', () => {
  const session = createCommand6510Session(({ requestRecordCount }) => {
    assert.equal(requestRecordCount, 0);
    return {
      unknownCodecByte: 0,
      recordWords: [],
      unknownTrailingField: Buffer.alloc(0)
    };
  });
  advanceToCommand6510(session);

  const result = session.handleFrame(decodeTcp10127Frame(buildCommand6510Request({
    sequence: 0xd8,
    recordFields: []
  })));
  assert.equal(result.response.subarray(8).toString('hex'), '00' + '000258d8');
});

test('rejects malformed 0x6510 requests', () => {
  const validField = encodeSnapField({
    plain: Buffer.from('SLOT0001', 'latin1'),
    maximumDecodedLength: 0xff,
    sequence: 0xd9,
    unknownCodecByte: 0
  });
  const emptyField = encodeSnapField({
    plain: Buffer.alloc(0),
    maximumDecodedLength: 0x3e,
    sequence: 0xd9,
    unknownCodecByte: 0
  });

  const cases = [
    // FUN_001c85c0 always writes the count byte, so a payload-less 0x6510 is not
    // something the PAL builder can emit.
    [{ payload: Buffer.alloc(0) }, 'COMMAND_6510_LENGTH'],
    // `li v0,12` caps the batch; 13 is unreachable.
    [{ payload: Buffer.from([13]) }, 'COMMAND_6510_REQUEST_COUNT'],
    // Declared record field runs past the payload.
    [{ payload: Buffer.from([1, 0x00]) }, 'COMMAND_6510_ENVELOPE'],
    [{ payload: Buffer.concat([Buffer.from([1]), Buffer.from([0x00, 0x0a])]) },
      'COMMAND_6510_ENVELOPE'],
    // FUN_001c3f40 never writes a length word below two.
    [{ payload: Buffer.concat([Buffer.from([1]), Buffer.from([0x00, 0x01, 0x00, 0x00])]) },
      'COMMAND_6510_ENVELOPE'],
    // Record field present but the trailing field is missing.
    [{ payload: Buffer.concat([Buffer.from([1]), validField]) }, 'COMMAND_6510_ENVELOPE'],
    // Trailing bytes beyond the trailing field.
    [{ payload: Buffer.concat([Buffer.from([1]), validField, emptyField, Buffer.from([0xff])]) },
      'COMMAND_6510_ENVELOPE'],
    // Only the normal-status path is implemented.
    [{ payload: Buffer.concat([Buffer.from([1]), validField, emptyField]), error: 0xff },
      'COMMAND_6510_STATUS'],
    [{ payload: Buffer.concat([Buffer.from([1]), validField, emptyField]), unknown7: 0x00 },
      'COMMAND_6510_UNKNOWN7'],
    [{ payload: Buffer.concat([Buffer.from([1]), validField, emptyField]), direction: 0x02 },
      'COMMAND_6510_DIRECTION']
  ];

  for (const [options, code] of cases) {
    const session = createSession();
    advanceToCommand6510(session);
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(buildCommand6510Frame(options))),
      (error) => error instanceof Tcp10127ProtocolError && error.code === code,
      'expected ' + code
    );
  }
});

test('rejects missing or invalid 0x6510 resolver results', () => {
  const request = buildCommand6510Request({
    sequence: 0xd8,
    recordFields: [Buffer.from('SLOT0001', 'latin1')]
  });

  // Built without the provider at all: 0x6510 has no safe status-0xff fallback,
  // so an absent provider must fail closed rather than answer.
  const missing = new Tcp10127LobbyInitializationSession({
    areaTable: AREA_TABLE,
    resolveCommand6212Value: () => 1,
    resolveCommand6211Value: () => 0,
    resolveCommand6213Words: () => Array(8).fill(0),
    resolveCommand6501Response: () => ({ mode: 0 }),
    resolveCommand6502Response: () => ({ mode: 1, unknown0: 1, unknown1: 1 }),
    resolveCommand6504Response: runtimeCompatibleCommand6504Selection
  });
  advanceToCommand6510(missing);
  assert.throws(
    () => missing.handleFrame(decodeTcp10127Frame(request)),
    (error) => error instanceof Tcp10127ProtocolError &&
      error.code === 'COMMAND_6510_RESPONSE_PROVIDER'
  );

  const cases = [
    [() => Promise.resolve({}), 'COMMAND_6510_RESPONSE_PROVIDER'],
    [() => { throw new Error('state unavailable'); }, 'COMMAND_6510_RESPONSE_PROVIDER'],
    [() => null, 'COMMAND_6510_RESPONSE_SHAPE'],
    [() => [], 'COMMAND_6510_RESPONSE_SHAPE'],
    // No silent extra or missing keys.
    [() => ({ unknownCodecByte: 0, recordWords: [0] }), 'COMMAND_6510_RESPONSE_SHAPE'],
    [() => ({
      unknownCodecByte: 0,
      recordWords: [0],
      unknownTrailingField: Buffer.alloc(0),
      extra: 1
    }), 'COMMAND_6510_RESPONSE_SHAPE'],
    [() => ({
      unknownCodecByte: 256,
      recordWords: [0],
      unknownTrailingField: Buffer.alloc(0)
    }), 'COMMAND_6510_RESPONSE_CODEC_BYTE'],
    // The client only stores the words when the counts match.
    [() => ({
      unknownCodecByte: 0,
      recordWords: [],
      unknownTrailingField: Buffer.alloc(0)
    }), 'COMMAND_6510_RESPONSE_WORD_COUNT'],
    [() => ({
      unknownCodecByte: 0,
      recordWords: [0, 0],
      unknownTrailingField: Buffer.alloc(0)
    }), 'COMMAND_6510_RESPONSE_WORD_COUNT'],
    [() => ({
      unknownCodecByte: 0,
      recordWords: [0x10000],
      unknownTrailingField: Buffer.alloc(0)
    }), 'COMMAND_6510_RESPONSE_WORD_VALUE'],
    [() => ({
      unknownCodecByte: 0,
      recordWords: [0],
      unknownTrailingField: 'SLOT0001'
    }), 'COMMAND_6510_RESPONSE_TRAILING_BUFFER'],
    // FUN_001c3b90 rejects anything above the 0x3e decoded bound with -2.
    [() => ({
      unknownCodecByte: 0,
      recordWords: [0],
      unknownTrailingField: Buffer.alloc(0x3f)
    }), 'COMMAND_6510_RESPONSE_TRAILING_LENGTH']
  ];

  for (const [resolver, code] of cases) {
    const session = createCommand6510Session(resolver);
    advanceToCommand6510(session);
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(request)),
      (error) => error instanceof Tcp10127ProtocolError && error.code === code,
      'expected ' + code
    );
  }

  // The 0x3e bound itself is accepted.
  const atBound = createCommand6510Session(() => ({
    unknownCodecByte: 0,
    recordWords: [0],
    unknownTrailingField: Buffer.alloc(0x3e)
  }));
  advanceToCommand6510(atBound);
  assert.equal(atBound.handleFrame(decodeTcp10127Frame(request)).unimplemented, false);
});

test('loops 0x6510 batches and preserves only its decoded continuations', () => {
  const session = createSession();
  advanceToCommand6510(session);

  for (const sequence of [0xd8, 0xd9, 0xda]) {
    const result = session.handleFrame(decodeTcp10127Frame(buildCommand6510Request({
      sequence,
      recordFields: [Buffer.from('SLOT0001', 'latin1')]
    })));
    assert.equal(result.unimplemented, false);
    assert.equal(result.response.readUInt16BE(3), 0x6510);
    assert.equal(result.response[5], sequence);
    assert.equal(session.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6510);
  }

  // Major state 4 routes back to 0x6203, whose mode-1 reply re-enters the area
  // transfer and then the 0x6211 -> 0x6213 -> 0x6501 sub-ladder.
  const looping = createSession();
  advanceToCommand6510(looping);
  looping.handleFrame(decodeTcp10127Frame(buildCommand6510Request({
    sequence: 0xd8,
    recordFields: [Buffer.from('SLOT0001', 'latin1')]
  })));
  const next = looping.handleFrame(decodeTcp10127Frame(
    // Empty-field checksum for p5 0xdb: (0 + 0xdb * 0x101) & 0x7fff = 0x5bdb.
    Buffer.from('0004016203db00ff00025bdb', 'hex')
  ));
  assert.equal(next.unimplemented, false);
  assert.equal(decodeTcp10127Frame(next.response).payload[0], 1);
  assert.equal(looping.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6204);
  advanceThroughAreaTable(looping, 0xdc);
  assert.equal(looping.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6211);
  // The re-entered sub-ladder really does continue from 0x6211.
  assert.equal(
    looping.handleFrame(decodeTcp10127Frame(Buffer.from('0000016211dc00ff', 'hex')))
      .unimplemented,
    false
  );
  assert.equal(looping.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6213);

  assert.throws(
    () => session.handleFrame(decodeTcp10127Frame(Buffer.from('0000016502db00ff', 'hex'))),
    (error) => error instanceof Tcp10127ProtocolError &&
      error.code === 'COMMAND_6510_FOLLOWUP_COMMAND'
  );
});

function advanceToCommand1004(session) {
  advanceToCommand6510(session);
  session.handleFrame(decodeTcp10127Frame(buildCommand6510Request({
    sequence: 0xd8,
    recordFields: [Buffer.from('SLOT0001', 'latin1')]
  })));
}

test('completes lobby initialization with an empty 0x1004 reply', () => {
  const session = createSession();
  advanceToCommand1004(session);

  const result = session.handleFrame(decodeTcp10127Frame(
    Buffer.from('0000011004d900ff', 'hex')
  ));

  // FUN_001c8e90 consumes nothing, so the reply is the bare header.
  assert.equal(result.unimplemented, false);
  assert.equal(result.response.toString('hex'), '0000021004d900ff');
  assert.equal(
    session.state,
    TCP10127_LOBBY_INITIALIZATION_STATE.LOBBY_INITIALIZATION_COMPLETE
  );
});

test('rejects malformed 0x1004 completions and any frame after completion', () => {
  const cases = [
    // FUN_001c8dd0 appends no fields.
    ['0001011004d900ff00', 'COMMAND_1004_LENGTH'],
    ['0000021004d900ff', 'COMMAND_1004_DIRECTION'],
    ['0000011004d90000', 'COMMAND_1004_UNKNOWN7'],
    ['0000011004d9ffff', 'COMMAND_1004_STATUS']
  ];

  for (const [hex, code] of cases) {
    const session = createSession();
    advanceToCommand1004(session);
    assert.throws(
      () => session.handleFrame(decodeTcp10127Frame(Buffer.from(hex, 'hex'))),
      (error) => error instanceof Tcp10127ProtocolError && error.code === code,
      'expected ' + code
    );
  }

  // Nothing beyond the completion is answered, but frames are observed rather
  // than fatal: what the client does after 0x1004 is still an open question, and
  // destroying the connection would suppress that evidence.
  const completed = createSession();
  advanceToCommand1004(completed);
  completed.handleFrame(decodeTcp10127Frame(Buffer.from('0000011004d900ff', 'hex')));
  for (const hex of ['0000011004da00ff', '0000016103da00ff', '0004016203da00ff00025bda']) {
    const observed = completed.handleFrame(decodeTcp10127Frame(Buffer.from(hex, 'hex')));
    assert.equal(observed.unimplemented, true);
    assert.equal(observed.response, null);
    assert.equal(
      completed.state,
      TCP10127_LOBBY_INITIALIZATION_STATE.LOBBY_INITIALIZATION_COMPLETE
    );
  }
});

test('reproduces every captured 0x6510 reply the real client accepted, byte for byte', () => {
  for (const exchange of CAPTURED_COMMAND_6510_EXCHANGES) {
    const calls = [];
    // V1's accepted replies carried record word 0 and echoed the record name as
    // the trailing field. Supplied here as capture-derived fixture data, not as
    // a V2 default: the session refuses to answer 0x6510 without a provider.
    const session = createCommand6510Session((request) => {
      calls.push(request);
      return {
        unknownCodecByte: 0,
        recordWords: Array(request.requestRecordCount).fill(0),
        unknownTrailingField: Buffer.from('SLOT0001', 'latin1')
      };
    });
    advanceToCommand6510(session);

    const request = decodeTcp10127Frame(Buffer.from(exchange.request, 'hex'));
    const result = session.handleFrame(request);

    assert.equal(
      result.response.toString('hex'),
      exchange.response,
      `V2 must reproduce the captured 0x6510 reply at p5 0x${request.sequence.toString(16)}`
    );
    assert.equal(calls.length, 1);
    assert.equal(calls[0].requestRecordCount, 1);
    assert.equal(calls[0].unknownEncodedRecordFields.length, 1);
    // The request's own fields reach the provider untouched.
    assert.equal(
      Buffer.concat([
        Buffer.from([calls[0].requestRecordCount]),
        calls[0].unknownEncodedRecordFields[0],
        calls[0].unknownEncodedTrailingField
      ]).toString('hex'),
      exchange.request.slice(16)
    );
    assert.equal(session.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6510);

    if (exchange.nextRequest != null) {
      const next = session.handleFrame(decodeTcp10127Frame(
        Buffer.from(exchange.nextRequest, 'hex')
      ));
      assert.equal(next.unimplemented, false, 'the captured next command must be answered');
    }
  }
});

test('decodes every captured 0x6510 record field to the same SLOT0001 plaintext', () => {
  const KEY = Buffer.from('MINAMIOH', 'ascii');
  const decodeField = (field, sequence) => {
    const plainLength = field.readUInt16BE(0) - 2;
    const plain = Buffer.alloc(plainLength);
    for (let index = 0; index < plainLength; index += 1) {
      plain[index] = field[4 + index] ^ KEY[index & 7] ^ ((sequence + index) & 0xff);
    }
    return plain.toString('latin1');
  };

  const trailers = [];
  for (const exchange of CAPTURED_COMMAND_6510_EXCHANGES) {
    const frame = decodeTcp10127Frame(Buffer.from(exchange.request, 'hex'));
    const recordLength = 4 + (frame.payload.readUInt16BE(1) - 2);
    const record = frame.payload.subarray(1, 1 + recordLength);
    assert.equal(decodeField(record, frame.sequence), 'SLOT0001');

    trailers.push(decodeField(frame.payload.subarray(1 + recordLength), frame.sequence));

    // Every captured reply's trailing field decodes back to the same plaintext.
    const reply = Buffer.from(exchange.response, 'hex');
    assert.equal(decodeField(reply.subarray(11), frame.sequence), 'SLOT0001');
    assert.equal(reply.readUInt16BE(9), 0, 'captured V1 record word is zero');
  }
  // The request trailer is not constant: it round-trips whatever the server last
  // wrote to the client page block, so it must never be treated as a fixed value.
  assert.deepEqual(trailers, ['', '', 'SLOT0001', 'SLOT0001']);
});

test('reproduces the captured 0x1004 completions byte for byte', () => {
  for (const exchange of CAPTURED_COMMAND_1004_EXCHANGES) {
    const session = createSession();
    advanceToCommand6510(session);
    session.handleFrame(decodeTcp10127Frame(buildCommand6510Request({
      sequence: 0xd8,
      recordFields: [Buffer.from('SLOT0001', 'latin1')]
    })));

    const result = session.handleFrame(decodeTcp10127Frame(
      Buffer.from(exchange.request, 'hex')
    ));
    assert.equal(result.response.toString('hex'), exchange.response);
    assert.equal(
      session.state,
      TCP10127_LOBBY_INITIALIZATION_STATE.LOBBY_INITIALIZATION_COMPLETE
    );
  }
});
