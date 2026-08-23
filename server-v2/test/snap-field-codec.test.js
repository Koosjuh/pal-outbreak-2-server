import assert from 'node:assert/strict';
import test from 'node:test';

import { encodeSnapField } from '../src/protocol/snap-field-codec.js';

test('encodes the runtime-confirmed p5-0x0d 0x6504 fields byte-for-byte', () => {
  const fixtures = [
    ['SLOT0001', 0x0f, '000a0f10130b0e056c6b6c6d'],
    ['OPEN', 0x0f, '00060e3f0f17041f'],
    ['Test Slot', 0xff, '000b106f142232257c0830332c']
  ];
  for (const [text, maximumDecodedLength, expected] of fixtures) {
    assert.equal(encodeSnapField({
      plain: Buffer.from(text, 'latin1'),
      maximumDecodedLength,
      sequence: 0x0d,
      unknownCodecByte: 0
    }).toString('hex'), expected);
  }
});

test('uses the explicit nonzero codec byte in the PAL transform', () => {
  assert.equal(encodeSnapField({
    plain: Buffer.from([0x10, 0x20, 0x30]),
    maximumDecodedLength: 3,
    sequence: 0x42,
    unknownCodecByte: 0x17
  }).toString('hex'), '000542a2043325');
});

test('rejects unsupported field inputs instead of truncating or defaulting', () => {
  const base = {
    plain: Buffer.alloc(0),
    maximumDecodedLength: 0,
    sequence: 0,
    unknownCodecByte: 0
  };
  for (const override of [
    { plain: 'text' },
    { maximumDecodedLength: -1 },
    { maximumDecodedLength: 0xfffe },
    { sequence: -1 },
    { sequence: 0x100 },
    { unknownCodecByte: -1 },
    { unknownCodecByte: 0x100 }
  ]) {
    assert.throws(() => encodeSnapField({ ...base, ...override }), TypeError);
  }
  assert.throws(() => encodeSnapField({
    ...base,
    plain: Buffer.alloc(2),
    maximumDecodedLength: 1
  }), RangeError);
});
