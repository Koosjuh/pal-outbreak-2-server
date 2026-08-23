import test from 'node:test';
import assert from 'node:assert/strict';

import {
  DATAGRAM_TRAILER,
  OPCODE_REGISTER,
  REPLY_PLAINTEXT_BYTES,
  SnapUdpFramingError,
  buildRegisterReplyPlaintext,
  decodeRegisterRequest,
  decodeSnapUdpDatagram,
  encodeRegisterReply
} from '../src/protocol/snap-udp-register-codec.js';
import { blowfishEcbEncrypt, createBlowfishKey } from '../src/crypto/blowfish.js';

/**
 * The real client's register, rebuilt field by field from the spec in
 * `docs/findings/protocol/UDP9090-REGISTER-RE-2026-08-03.md` section 3. These are
 * the same 154 bytes captured from `192.0.2.248:2000` in
 * `captures/v2-live/v2-run2.pcap` frame 29, byte-identical across 41 archived V1
 * sessions. Built rather than pasted so a layout mistake fails loudly here.
 */
function capturedRegister() {
  // Rebuild from the field spec rather than trusting a hand-wrapped hex blob:
  // this is the same 154 bytes, and it fails loudly if the layout is wrong.
  const datagram = Buffer.alloc(154);
  datagram.writeUInt16BE(0x3096, 0x00);
  datagram.writeUInt8(0x00, 0x02);
  datagram.writeUInt8(0x2c, 0x03);
  datagram.writeUInt32BE(0x02f807d0, 0x04); // endpoint token: 192.0.2.248 / 2000
  datagram.writeUInt32BE(0, 0x08);
  datagram.writeUInt32BE(0, 0x0c);
  const body = datagram.subarray(0x10);
  body.write('12345', 0x00, 'latin1');
  body.write('12345@cee-auth', 0x28, 'latin1');
  body.writeUInt32BE(0xcaf3, 0x64);
  body.writeUInt32BE(0, 0x68);
  Buffer.from([192, 0, 2, 248]).copy(body, 0x6c);
  body.writeUInt32BE(2000, 0x70);
  body.writeUInt32BE(100, 0x74);
  body.writeUInt16BE(2, 0x78);
  body.write('LC', 0x7a, 'latin1');
  body.writeUInt32BE(1600, 0x7c);
  body.write('MR', 0x80, 'latin1');
  body.writeUInt32BE(48, 0x82);
  DATAGRAM_TRAILER.copy(datagram, 150);
  return datagram;
}

test('decodes the captured 154-byte register exactly', () => {
  const datagram = capturedRegister();
  assert.equal(datagram.length, 154);

  const messages = decodeSnapUdpDatagram(datagram);
  assert.equal(messages.length, 1);
  const [message] = messages;
  assert.equal(message.who, 0x3096);
  assert.equal(message.length, 0x96);
  assert.equal(message.flags, 0x3000);
  assert.equal(message.opcode, OPCODE_REGISTER);
  assert.equal(message.subSelector, 0);
  assert.equal(message.endpointToken, 0x02f807d0);
  assert.equal(message.sequence, 0);

  const request = decodeRegisterRequest(message);
  assert.equal(request.loginIdentity, '12345');
  assert.equal(request.auth, '12345@cee-auth');
  assert.equal(request.selector, 0xcaf3);
  assert.equal(request.clientIpv4.toString('hex'), 'c00002f8');
  assert.equal(request.clientPort, 2000);
  assert.equal(request.quantum, 100);
  assert.deepEqual(request.tlvs, [
    { tag: 'LC', value: 1600 },
    { tag: 'MR', value: 48 }
  ]);
});

test('the login identity is read as a C string out of its NUL-padded field', () => {
  // The wire field is 40 bytes NUL-padded. Passing the padded buffer to an
  // account lookup would miss every time, and because the register reply is
  // Blowfish-keyed on the found account, that would look like a crypto fault.
  const datagram = capturedRegister();
  datagram.subarray(0x10).write('test123', 0x00, 'latin1');
  const request = decodeRegisterRequest(decodeSnapUdpDatagram(datagram)[0]);
  assert.equal(request.loginIdentity, 'test123');
  assert.equal(request.loginIdentity.length, 7, 'no NUL padding leaks into the string');
});

test('derives length from the header, not from the datagram size', () => {
  // `udp.length` includes the 8-byte UDP header and has misled a session before.
  // Trailing slack must be REJECTED rather than tolerated: the client requires
  // the message lengths to sum to exactly datagramLength - 4, so a datagram we
  // would accept but it would discard is the worst possible outcome.
  const padded = Buffer.concat([capturedRegister(), Buffer.alloc(8)]);
  DATAGRAM_TRAILER.copy(padded, padded.length - 4);
  assert.throws(
    () => decodeSnapUdpDatagram(padded),
    (error) => error instanceof SnapUdpFramingError && error.code === 'TRUNCATED_HEADER'
  );

  // Slack large enough to look like another message is rejected too: the walk
  // lands on the original trailer, reads who=0xba47 -> length 583, and that
  // overruns. Either way the datagram is refused rather than half-believed.
  const paddedMore = Buffer.concat([capturedRegister(), Buffer.alloc(16)]);
  DATAGRAM_TRAILER.copy(paddedMore, paddedMore.length - 4);
  assert.throws(
    () => decodeSnapUdpDatagram(paddedMore),
    (error) => error.code === 'MESSAGE_OVERRUNS'
  );

  // The header's own length is what is believed: a message declaring 0x96 is
  // parsed as 0x96 regardless of how many bytes the socket handed us.
  const [message] = decodeSnapUdpDatagram(capturedRegister());
  assert.equal(message.length, 0x96);
  assert.equal(message.body.length, 0x96 - 0x10);
});

test('rejects malformed and truncated datagrams instead of guessing', () => {
  const cases = [
    [Buffer.alloc(19), 'TOO_SHORT'],
    [Buffer.alloc(24), 'BAD_TRAILER']
  ];
  for (const [datagram, code] of cases) {
    assert.throws(
      () => decodeSnapUdpDatagram(datagram),
      (error) => error.code === code,
      `expected ${code}`
    );
  }

  // A truncated register: valid framing, body too short for the fixed fields.
  const short = Buffer.alloc(0x30);
  short.writeUInt16BE(0x3000 | 0x2c, 0x00);
  short.writeUInt8(0x2c, 0x03);
  DATAGRAM_TRAILER.copy(short, 0x2c);
  assert.throws(
    () => decodeRegisterRequest(decodeSnapUdpDatagram(short)[0]),
    (error) => error.code === 'BODY_TOO_SHORT'
  );

  // A message claiming to be shorter than its own header.
  const undersized = Buffer.alloc(24);
  undersized.writeUInt16BE(0x3000 | 0x08, 0x00);
  DATAGRAM_TRAILER.copy(undersized, 20);
  assert.throws(
    () => decodeSnapUdpDatagram(undersized),
    (error) => error.code === 'MESSAGE_TOO_SHORT'
  );

  // A message claiming to be longer than the datagram.
  const overrunning = Buffer.alloc(24);
  overrunning.writeUInt16BE(0x3000 | 0x3ff, 0x00);
  DATAGRAM_TRAILER.copy(overrunning, 20);
  assert.throws(
    () => decodeSnapUdpDatagram(overrunning),
    (error) => error.code === 'MESSAGE_OVERRUNS'
  );

  // A TLV count that overruns the body.
  const lyingTlvCount = capturedRegister();
  lyingTlvCount.subarray(0x10).writeUInt16BE(0xff, 0x78);
  assert.throws(
    () => decodeRegisterRequest(decodeSnapUdpDatagram(lyingTlvCount)[0]),
    (error) => error.code === 'TLV_OVERRUNS'
  );
});

test('accepts only the top three trailer bytes, as the client does', () => {
  for (const low of [0x00, 0x11, 0xff]) {
    const datagram = capturedRegister();
    datagram.writeUInt8(low, 153);
    assert.equal(decodeSnapUdpDatagram(datagram).length, 1, `low byte 0x${low.toString(16)}`);
  }
  const wrong = capturedRegister();
  wrong.writeUInt8(0xbb, 150);
  assert.throws(() => decodeSnapUdpDatagram(wrong), (error) => error.code === 'BAD_TRAILER');
});

test('walks a coalesced multi-message datagram and closes exactly', () => {
  const first = Buffer.alloc(0x10);
  first.writeUInt16BE(0x0800 | 0x10, 0x00);
  first.writeUInt8(0x40, 0x03);
  const second = capturedRegister().subarray(0, 0x96);
  const datagram = Buffer.concat([first, second, DATAGRAM_TRAILER]);

  const messages = decodeSnapUdpDatagram(datagram);
  assert.equal(messages.length, 2);
  assert.equal(messages[0].opcode, 0x40);
  assert.equal(messages[1].opcode, OPCODE_REGISTER);
  assert.equal(decodeRegisterRequest(messages[1]).loginIdentity, '12345');
});

/**
 * The reply must reproduce, byte for byte, what V1 sent and a real client
 * accepted - archived trace udp9090/2026_07_12_10_38_35, `OUT #1`.
 */
test('builds the sanitized register reply derived from a real accepted reply', () => {
  const plaintext = buildRegisterReplyPlaintext({
    loginIdentity: '12345',
    serverIpv4: '192.0.2.121',
    portNow: 9090
  });
  assert.equal(plaintext.length, REPLY_PLAINTEXT_BYTES);
  assert.equal(
    plaintext.toString('hex'),
      '3132333435000000000000000000000000000000000000000000000000000000' +
      '0000000000000000c00002790000000000002382000000000000000000000000' +
      '0000000000000000000000000000000000000000000000000000000000000000' +
      '0000000000000000000000000000000000000000000000000000000000000000'
  );

  const encrypted = blowfishEcbEncrypt(createBlowfishKey('1234567890'), plaintext);
  const datagram = encodeRegisterReply({ encryptedBody: encrypted, endpointToken: 0x02f807d0 });

  assert.equal(datagram.length, 154, 'the reply is 154 bytes on the wire');
  assert.equal(datagram.readUInt16BE(0x00), 0xb096, 'RELIABLE | set | DATA | length 0x96');
  assert.equal(datagram.readUInt8(0x03), 0x2d);
  assert.equal(datagram.readUInt32BE(0x04), 0x02f807d0, 'the request token is echoed');
  assert.equal(datagram.readUInt32BE(0x08), 0, 'first reliable message of the epoch');
  assert.equal(datagram.subarray(150).toString('hex'), 'ba476611');
  assert.equal(
    datagram.subarray(0x10, 0x90).toString('hex'),
    '11c091d8f3033d6f' +
      'b12c46d5e173e352'.repeat(4) +
      'e035ad10220a1a486a3a6d953183bcd3' +
      'b12c46d5e173e352'.repeat(9)
  );

  // And our own decoder must accept what we emit.
  const [message] = decodeSnapUdpDatagram(datagram);
  assert.equal(message.opcode, 0x2d);
  assert.equal(message.length, 0x96);
});

test('the reply plaintext carries the endpoint the client will use next', () => {
  const plaintext = buildRegisterReplyPlaintext({
    loginIdentity: 'test123',
    serverIpv4: '192.0.2.121',
    portNow: 9090,
    sessionId: 0x11223344
  });
  assert.equal(plaintext.subarray(0, 7).toString('latin1'), 'test123');
  assert.equal(plaintext.readUInt8(7), 0, 'NUL-terminated for the client strcmp');
  assert.equal(plaintext.readUInt32BE(0x28).toString(16), 'c0000279');
  assert.equal(plaintext.readUInt32BE(0x30), 9090, 'port applied immediately');
  assert.equal(plaintext.readUInt32BE(0x2c), 0, 'port at bind stays 0 so the port above holds');
  assert.equal(plaintext.readUInt32BE(0x34), 0, 'no tail blob');
  assert.equal(plaintext.readUInt32BE(0x38), 0x11223344);
});

test('refuses a login identity that cannot round-trip through the field', () => {
  // 40-byte field, and the client strcmps it, so it needs a terminator.
  assert.throws(
    () => buildRegisterReplyPlaintext({
      loginIdentity: 'x'.repeat(40),
      serverIpv4: '192.0.2.121',
      portNow: 9090
    }),
    (error) => error.code === 'FIELD_TOO_LONG'
  );
  assert.doesNotThrow(() =>
    buildRegisterReplyPlaintext({
      loginIdentity: 'x'.repeat(39),
      serverIpv4: '192.0.2.121',
      portNow: 9090
    })
  );
});

test('refuses a body that is not exactly 0x80 bytes', () => {
  assert.throws(
    () => encodeRegisterReply({ encryptedBody: Buffer.alloc(120), endpointToken: 1 }),
    (error) => error.code === 'BAD_BODY_LENGTH'
  );
});
