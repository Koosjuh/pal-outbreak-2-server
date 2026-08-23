import assert from 'node:assert/strict';
import crypto from 'node:crypto';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import test from 'node:test';

import {
  DnasApplicationService,
  deriveV25ResponseKeys,
  describeDnasRequest,
  parseDnasHttpRequest,
  transformV25Response
} from '../src/dnas/application-codec.js';
import {
  DnasPacketStoreError,
  FileDnasPacketStore,
  assertPacketKey
} from '../src/dnas/packet-store.js';

const I_CONNECT_BODY = Buffer.from(
  'AQgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABDAACAAX0wmzRP7HfVc9WqIfOF4MoO5i4r0kqcXVr6mFa6LkGNyVLKRi0NFMO1WPphtBmSghgBYmh/Gi9vT8fT0Qsdnp0i/BS2kE0Gp66S8wIuIPwAQrKAzuM9xvNwx9ditafzI9hNfJ/cHnQ/KAIg+T1ZKJeFesuW1OHvFpHDY+FjewNP+eFuaV7zXDXyz+AH6OR0nMo15xNhuurTLMXjBqGXXH8Qw94P1wG7N/rb6vpnd96ctKinQ9/J5zyyNQFqv704oN1IWHKL5iTOx3U8gzkYKw4ssAmekH3wux9bOf59+iVhrM2pDcHzs822MCs3hhhj714XrVL/0/cA28qCQMkG4OMaVW74zT/j+Y=',
  'base64'
);
const OTHERS_184_BODY = Buffer.from(
  'AQgAAQIAJRwxLA4SCQfgAAB7lwAAAAAAAAAAsZgBC9YUkPiiAAAAkNNFOtIbO5scst6LFjlPlBx29072atIF1ibCy4el1RB4D1VLLPCHSAcTJrovugloMAG3J2uJLUKv7w02lONHDfOcWR+N4GeV845PIklYinpaQaHFys8Ier4WsFP592DslLkMIpp0t40DB69MYDrGunxogEY3iMD2nnFJl2mqhP5kkSD+BtgAAAAAAAAAAAAAAA==',
  'base64'
);
const OTHERS_44_BODY = Buffer.from(
  'AQiACAIAJRwxLA4SCQfgAAB7lwAAAAAAAAAAsZgBC9YUkPiiAAAABDwzYKQ=',
  'base64'
);

const CAPTURE_HASHES = Object.freeze({
  iConnect: '9ee439d3d5825c66b5ac4c9f898aaa05ea276a7192e6aa43b97c8785ca0dfc49',
  others184: 'b6a65b299354ea4104c341060372c483673dc9b8492a101e59a658dcfe3b29c9',
  others44: '37de1dfeb36d8ffec93bbc61f4d0703702621e43cad4f730ef0cf239932021e3'
});

function sha256(value) {
  return crypto.createHash('sha256').update(value).digest('hex');
}

function httpRequest(requestPath, body) {
  return Buffer.concat([
    Buffer.from(
      `POST ${requestPath} HTTP/1.0\r\n` +
      'User-Agent: open sesame asdfjkl\r\n' +
      'Content-Type: image/gif\r\n' +
      `Content-Length: ${body.length}\r\n\r\n`,
      'latin1'
    ),
    body
  ]);
}

function patternedPacket(length) {
  return Buffer.from(Array.from({ length }, (_, index) => index & 0xff));
}

class MemoryPacketStore {
  constructor(entries = []) {
    this.entries = new Map(entries);
    this.requested = [];
  }

  async get(packetKey) {
    this.requested.push(packetKey);
    const packet = this.entries.get(packetKey);
    return packet ? Buffer.from(packet) : null;
  }
}

test('captured PAL DNAS fixture hashes and lengths remain locked', () => {
  assert.equal(I_CONNECT_BODY.length, 308);
  assert.equal(OTHERS_184_BODY.length, 184);
  assert.equal(OTHERS_44_BODY.length, 44);
  assert.equal(sha256(I_CONNECT_BODY), CAPTURE_HASHES.iConnect);
  assert.equal(sha256(OTHERS_184_BODY), CAPTURE_HASHES.others184);
  assert.equal(sha256(OTHERS_44_BODY), CAPTURE_HASHES.others44);
});

test('i-connect parses the runtime-proven path, query, game ID, and offset', () => {
  const request = parseDnasHttpRequest(httpRequest('/eu-gw/v2.5_i-connect', I_CONNECT_BODY));
  const query = describeDnasRequest(request);

  assert.equal(request.httpVersion, 'HTTP/1.0');
  assert.equal(query.kind, 'v2.5_i-connect');
  assert.equal(query.gameIdOffset, 0x2c);
  assert.equal(query.queryType, '01080000');
  assert.equal(query.gameId, 'f4c26cd13fb1df55');
  assert.equal(query.packetKey, 'f4c26cd13fb1df55_01080000');
});

test('i-connect key derivation matches the keys recorded by the accepted V1 runtime', () => {
  const keys = deriveV25ResponseKeys(I_CONNECT_BODY);
  assert.deepEqual(
    Object.fromEntries(Object.entries(keys).map(([name, value]) => [name, value.toString('hex')])),
    {
      desK1: 'd59ec24acbe83c8f',
      desK2: '5f5fa2ae1b95e3b5',
      desK3: '323d2bf6738ba4bd',
      xorSeed: '1b7da225bdc50571'
    }
  );
});

test('both captured others requests use the PAL-proven game ID at offset 0x1b', () => {
  const first = describeDnasRequest(
    parseDnasHttpRequest(httpRequest('/eu-gw/v2.5_others', OTHERS_184_BODY))
  );
  const second = describeDnasRequest(
    parseDnasHttpRequest(httpRequest('/eu-gw/v2.5_others', OTHERS_44_BODY))
  );

  assert.deepEqual(
    {
      kind: first.kind,
      gameIdOffset: first.gameIdOffset,
      queryType: first.queryType,
      gameId: first.gameId,
      packetKey: first.packetKey
    },
    {
      kind: 'v2.5_others',
      gameIdOffset: 0x1b,
      queryType: '01080001',
      gameId: 'b198010bd61490f8',
      packetKey: 'b198010bd61490f8_01080001'
    }
  );
  assert.equal(second.gameIdOffset, 0x1b);
  assert.equal(second.queryType, '01088008');
  assert.equal(second.gameId, 'b198010bd61490f8');
  assert.equal(second.packetKey, 'b198010bd61490f8_01088008');
});

test('v2.5 transform is deterministic and leaves bytes before the envelope untouched', () => {
  const packet = patternedPacket(328);
  const transformed = transformV25Response(packet, I_CONNECT_BODY);

  assert.equal(transformed.length, 328);
  assert.deepEqual(transformed.subarray(0, 0x28), packet.subarray(0, 0x28));
  assert.equal(
    transformed.subarray(0x28, 0x48).toString('hex'),
    'f850f0d31a6f466347a0fe1111132280929b154cfc443edef9b68ba97a73abcf'
  );
  assert.equal(sha256(transformed), '215c5a6f5df1db5aaa70f8e018e71d45bf20ce2907b95a57e784b1fb11dfde9f');
  assert.deepEqual(packet, patternedPacket(328), 'source asset must not be mutated');
});

test('application service transforms i-connect and frames the observed HTTP/1.0 response', async () => {
  const packet = patternedPacket(328);
  const store = new MemoryPacketStore([['f4c26cd13fb1df55_01080000', packet]]);
  const service = new DnasApplicationService({ packetStore: store });

  const result = await service.handle(httpRequest('/eu-gw/v2.5_i-connect', I_CONNECT_BODY));

  assert.equal(result.ok, true);
  assert.deepEqual(store.requested, ['f4c26cd13fb1df55_01080000']);
  assert.equal(result.responseBody.length, 328);
  const split = result.responseBytes.indexOf('\r\n\r\n', 0, 'latin1');
  assert.equal(
    result.responseBytes.subarray(0, split + 4).toString('latin1'),
    'HTTP/1.0 200 OK\r\nContent-Type: image/gif\r\nContent-Length: 328\r\n\r\n'
  );
  assert.deepEqual(result.responseBytes.subarray(split + 4), result.responseBody);
});

test('application service returns captured others assets byte-for-byte', async () => {
  const packet184 = patternedPacket(170);
  const packet44 = patternedPacket(77);
  const store = new MemoryPacketStore([
    ['b198010bd61490f8_01080001', packet184],
    ['b198010bd61490f8_01088008', packet44]
  ]);
  const service = new DnasApplicationService({ packetStore: store });

  const first = await service.handle(httpRequest('/eu-gw/v2.5_others', OTHERS_184_BODY));
  const second = await service.handle(httpRequest('/eu-gw/v2.5_others', OTHERS_44_BODY));

  assert.equal(first.ok, true);
  assert.equal(first.responseBody.length, 170);
  assert.deepEqual(first.responseBody, packet184);
  assert.equal(second.ok, true);
  assert.equal(second.responseBody.length, 77);
  assert.deepEqual(second.responseBody, packet44);
});

test('others does not search speculative alternate game ID offsets', async () => {
  const body = Buffer.alloc(44);
  body.writeUInt32BE(0x01088008, 0);
  Buffer.from('b198010bd61490f8', 'hex').copy(body, 0x24);
  const store = new MemoryPacketStore([['b198010bd61490f8_01088008', patternedPacket(77)]]);
  const service = new DnasApplicationService({ packetStore: store });

  const result = await service.handle(httpRequest('/eu-gw/v2.5_others', body));

  assert.equal(result.ok, false);
  assert.equal(result.errorCode, 'PACKET_NOT_FOUND');
  assert.deepEqual(store.requested, ['0000000000000000_01088008']);
});

test('missing assets and malformed client forms fail explicitly without fabricated packets', async () => {
  const service = new DnasApplicationService({ packetStore: new MemoryPacketStore() });
  const missing = await service.handle(httpRequest('/eu-gw/v2.5_i-connect', I_CONNECT_BODY));
  const wrongLength = await service.handle(
    httpRequest('/eu-gw/v2.5_i-connect', I_CONNECT_BODY.subarray(0, 307))
  );
  const wrongPath = await service.handle(httpRequest('/eu-gw/v2.5_unknown', OTHERS_44_BODY));

  for (const result of [missing, wrongLength, wrongPath]) {
    assert.equal(result.ok, false);
    assert.equal(result.responseBody.toString('ascii'), 'ERROR');
    assert.match(result.responseBytes.toString('latin1'), /^HTTP\/1\.0 500 Internal Server Error\r\n/);
  }
  assert.equal(missing.errorCode, 'PACKET_NOT_FOUND');
  assert.equal(wrongLength.errorCode, 'UNEXPECTED_I_CONNECT_LENGTH');
  assert.equal(wrongPath.errorCode, 'UNKNOWN_DNAS_PATH');
  assert.throws(
    () => transformV25Response(Buffer.alloc(327), I_CONNECT_BODY),
    (error) => error.code === 'V25_PACKET_TOO_SHORT'
  );
});

test('HTTP parser rejects mismatched lengths and duplicate headers', () => {
  const mismatched = Buffer.from(
    'POST /eu-gw/v2.5_others HTTP/1.0\r\nContent-Length: 4\r\n\r\nabc',
    'latin1'
  );
  const duplicate = Buffer.from(
    'POST /eu-gw/v2.5_others HTTP/1.0\r\nContent-Length: 0\r\ncontent-length: 0\r\n\r\n',
    'latin1'
  );

  assert.throws(
    () => parseDnasHttpRequest(mismatched),
    (error) => error.code === 'HTTP_BODY_LENGTH_MISMATCH'
  );
  assert.throws(
    () => parseDnasHttpRequest(duplicate),
    (error) => error.code === 'DUPLICATE_HTTP_HEADER'
  );
});

test('file packet store confines reads to evidence-shaped packet keys', async (t) => {
  const directory = fs.mkdtempSync(path.join(os.tmpdir(), 'pal-v2-dnas-'));
  t.after(() => fs.rmSync(directory, { recursive: true, force: true }));
  const key = 'f4c26cd13fb1df55_01080000';
  const packet = patternedPacket(328);
  fs.writeFileSync(path.join(directory, key), packet);
  const store = new FileDnasPacketStore(directory);

  assert.deepEqual(await store.get(key), packet);
  assert.equal(await store.get('0000000000000000_00000000'), null);
  assert.equal(assertPacketKey(key), key);
  assert.throws(
    () => assertPacketKey('../server.key'),
    (error) => error instanceof DnasPacketStoreError && error.code === 'INVALID_PACKET_KEY'
  );
});
