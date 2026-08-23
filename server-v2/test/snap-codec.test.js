import assert from 'node:assert/strict';
import test from 'node:test';

import {
  FLAG_ACK,
  FLAG_AGGREGATE,
  FLAG_DATA,
  FLAG_RELIABLE,
  FLAG_SET,
  SnapCodecError,
  decodeDatagram,
  encodeDatagram,
  encodeTransportAck
} from '../src/protocol/snap-codec.js';

// Repository wire evidence:
// docs/findings/protocol/_archive/snap-channel-establish-FSM-ROOMENTER-APPENDIX-2026-06-20.md
const ROOM_ENTER_ACCEPT = Buffer.from(
  'b01c0028028107d00000000300000000000000060000000000000000ba476611',
  'hex'
);

// Repository ACK contract:
// docs/findings/protocol/_archive/snap-recvbase-delivery-contract-RE-2026-06-28.md
const ACK_SEQUENCE_ONE = Buffer.from(
  '6010000002e707d00000000000000001ba476611',
  'hex'
);

test('decodes a recorded reliable op28 selector-6 push', () => {
  const decoded = decodeDatagram(ROOM_ENTER_ACCEPT);
  assert.equal(decoded.segments.length, 1);

  const [segment] = decoded.segments;
  assert.equal(segment.flagsAndLength, 0xb01c);
  assert.equal(segment.reliable, true);
  assert.equal(segment.set, true);
  assert.equal(segment.data, true);
  assert.equal(segment.aggregate, false);
  assert.equal(segment.innerLength, 0x1c);
  assert.equal(segment.subSelector, 0);
  assert.equal(segment.opcode, 0x28);
  assert.equal(segment.token.toString('hex'), '028107d0');
  assert.equal(segment.sequence, 3);
  assert.equal(segment.acknowledgement, 0);
  assert.equal(segment.payload.toString('hex'), '000000060000000000000000');
});

test('re-encodes the recorded push byte-for-byte', () => {
  const [segment] = decodeDatagram(ROOM_ENTER_ACCEPT).segments;
  const encoded = encodeDatagram([
    {
      flags: segment.flags,
      subSelector: segment.subSelector,
      opcode: segment.opcode,
      token: segment.token,
      sequence: segment.sequence,
      acknowledgement: segment.acknowledgement,
      payload: segment.payload
    }
  ]);

  assert.deepEqual(encoded, ROOM_ENTER_ACCEPT);
});

test('encodes the recorded 0x6010 transport ACK shape byte-for-byte', () => {
  assert.deepEqual(
    encodeTransportAck({
      token: Buffer.from('02e707d0', 'hex'),
      acknowledgedSequence: 1
    }),
    ACK_SEQUENCE_ONE
  );

  const [ack] = decodeDatagram(ACK_SEQUENCE_ONE).segments;
  assert.equal(ack.flags, FLAG_ACK | FLAG_SET);
  assert.equal(ack.reliable, false);
  assert.equal(ack.acknowledges, true);
  assert.equal(ack.sequence, 0);
  assert.equal(ack.acknowledgement, 1);
});

test('walks aggregate segments using each low-10-bit inner length', () => {
  const datagram = encodeDatagram([
    {
      flags: FLAG_RELIABLE | FLAG_SET | FLAG_DATA,
      opcode: 0x06,
      token: 0x028107d0,
      sequence: 7,
      payload: Buffer.from([1, 2, 3, 4])
    },
    {
      flags: FLAG_RELIABLE | FLAG_SET | FLAG_DATA,
      opcode: 0x09,
      token: 0x028107d0,
      sequence: 8,
      payload: Buffer.alloc(0)
    }
  ]);

  const decoded = decodeDatagram(datagram);
  assert.equal(decoded.aggregate, true);
  assert.equal(decoded.segments.length, 2);
  assert.equal(decoded.segments[0].flags & FLAG_AGGREGATE, FLAG_AGGREGATE);
  assert.equal(decoded.segments[0].innerLength, 20);
  assert.equal(decoded.segments[1].offset, 20);
  assert.equal(decoded.segments[1].opcode, 0x09);
});

test('rejects an invalid trailer instead of accepting an unproven checksum form', () => {
  const bad = Buffer.from(ROOM_ENTER_ACCEPT);
  bad[bad.length - 1] = 0x12;
  assert.throws(
    () => decodeDatagram(bad),
    (error) => error instanceof SnapCodecError && error.code === 'INVALID_TRAILER'
  );
});

test('rejects trailing segment bytes when aggregate was not declared', () => {
  const first = ROOM_ENTER_ACCEPT.subarray(0, -4);
  const second = ROOM_ENTER_ACCEPT.subarray(0, -4);
  const malformed = Buffer.concat([first, second, Buffer.from('ba476611', 'hex')]);

  assert.throws(
    () => decodeDatagram(malformed),
    (error) => error instanceof SnapCodecError && error.code === 'UNDECLARED_AGGREGATE'
  );
});

