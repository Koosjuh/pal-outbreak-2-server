import assert from 'node:assert/strict';
import test from 'node:test';

import {
  TCP10127_DIRECTION,
  Tcp10127ProtocolError,
  Tcp10127StreamDecoder,
  decodeTcp10127Frame,
  encodeTcp10127Frame
} from '../src/protocol/tcp10127-codec.js';

// docs/evidence/logs/2026_06_04_22_25_57_snap_session2_trace.log:77
const AREA_COUNT_REQUEST = Buffer.from('00040162032c00ff00022c2c', 'hex');
// Same trace:83-85; accepted by the PAL client.
const AREA_COUNT_RESPONSE = Buffer.from('00010262032c00ff02', 'hex');

test('decodes and re-encodes a captured client request byte-for-byte', () => {
  const frame = decodeTcp10127Frame(AREA_COUNT_REQUEST);
  assert.equal(frame.payloadLength, 4);
  assert.equal(frame.direction, TCP10127_DIRECTION.CLIENT_REQUEST);
  assert.equal(frame.command, 0x6203);
  assert.equal(frame.sequence, 0x2c);
  assert.equal(frame.error, 0);
  assert.equal(frame.unknown7, 0xff);
  assert.equal(frame.payload.toString('hex'), '00022c2c');

  assert.deepEqual(encodeTcp10127Frame(frame), AREA_COUNT_REQUEST);
});

test('decodes and re-encodes a captured server response byte-for-byte', () => {
  const frame = decodeTcp10127Frame(AREA_COUNT_RESPONSE);
  assert.equal(frame.direction, TCP10127_DIRECTION.SERVER_RESPONSE);
  assert.equal(frame.command, 0x6203);
  assert.equal(frame.payload.toString('hex'), '02');
  assert.deepEqual(encodeTcp10127Frame(frame), AREA_COUNT_RESPONSE);
});

test('reassembles one frame delivered in header and payload fragments', () => {
  const decoder = new Tcp10127StreamDecoder();
  assert.deepEqual(decoder.push(AREA_COUNT_REQUEST.subarray(0, 1)), []);
  assert.deepEqual(decoder.push(AREA_COUNT_REQUEST.subarray(1, 7)), []);
  assert.deepEqual(decoder.push(AREA_COUNT_REQUEST.subarray(7, 10)), []);
  const frames = decoder.push(AREA_COUNT_REQUEST.subarray(10));
  assert.equal(frames.length, 1);
  assert.deepEqual(frames[0].raw, AREA_COUNT_REQUEST);
  assert.equal(decoder.bufferedLength, 0);
  decoder.finish();
});

test('emits coalesced frames independently and preserves a partial tail', () => {
  const decoder = new Tcp10127StreamDecoder();
  const next = AREA_COUNT_REQUEST.subarray(0, 5);
  const frames = decoder.push(Buffer.concat([
    AREA_COUNT_REQUEST,
    AREA_COUNT_RESPONSE,
    next
  ]));
  assert.deepEqual(frames.map((frame) => frame.raw), [
    AREA_COUNT_REQUEST,
    AREA_COUNT_RESPONSE
  ]);
  assert.equal(decoder.bufferedLength, 5);
  assert.throws(
    () => decoder.finish(),
    (error) => error instanceof Tcp10127ProtocolError && error.code === 'TRUNCATED_HEADER'
  );
});

test('fails closed before buffering a declared payload above the configured limit', () => {
  const decoder = new Tcp10127StreamDecoder({ maxPayloadLength: 16 });
  const header = Buffer.from('00110110010000ff', 'hex');
  assert.throws(
    () => decoder.push(header),
    (error) => error instanceof Tcp10127ProtocolError && error.code === 'PAYLOAD_LIMIT'
  );
});

test('rejects exact-frame length mismatches', () => {
  assert.throws(
    () => decodeTcp10127Frame(AREA_COUNT_REQUEST.subarray(0, -1)),
    (error) => error instanceof Tcp10127ProtocolError && error.code === 'TRUNCATED_PAYLOAD'
  );
  assert.throws(
    () => decodeTcp10127Frame(Buffer.concat([AREA_COUNT_REQUEST, Buffer.from([0])])),
    (error) => error instanceof Tcp10127ProtocolError && error.code === 'TRAILING_BYTES'
  );
});

