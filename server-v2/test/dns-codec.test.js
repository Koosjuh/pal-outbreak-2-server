import assert from 'node:assert/strict';
import test from 'node:test';

import { buildDnsResponse, normalizeDnsRecords, parseDnsQuery } from '../src/dns/dns-codec.js';

function encodeName(name) {
  const labels = name.split('.');
  return Buffer.concat([
    ...labels.map((label) => Buffer.concat([Buffer.from([label.length]), Buffer.from(label, 'ascii')])),
    Buffer.from([0])
  ]);
}

function query(name, { id = 0x1234, type = 1, dnsClass = 1 } = {}) {
  const header = Buffer.alloc(12);
  header.writeUInt16BE(id, 0);
  header.writeUInt16BE(0x0100, 2);
  header.writeUInt16BE(1, 4);
  const tail = Buffer.alloc(4);
  tail.writeUInt16BE(type, 0);
  tail.writeUInt16BE(dnsClass, 2);
  return Buffer.concat([header, encodeName(name), tail]);
}

const records = normalizeDnsRecords({
  'gate1.eu.dnas.playstation.org': '192.0.2.121',
  'stage6.sega.com': '192.0.2.121',
  'snap01.capcom.client.sf.yav4.com': '192.0.2.121'
});

test('known A query receives one deterministic IPv4 answer', () => {
  const request = query('gate1.eu.dnas.playstation.org');
  const result = buildDnsResponse(request, records, { ttl: 60 });
  const parsed = parseDnsQuery(request);

  assert.equal(parsed.id, 0x1234);
  assert.equal(parsed.name, 'gate1.eu.dnas.playstation.org');
  assert.equal(result.address, '192.0.2.121');
  assert.equal(result.rcode, 0);
  assert.equal(result.answerCount, 1);
  assert.equal(result.bytes.readUInt16BE(2), 0x8180);
  assert.equal(result.bytes.readUInt16BE(6), 1);
  assert.deepEqual(result.bytes.subarray(-4), Buffer.from([192, 0, 2, 121]));
});

test('unknown names are NXDOMAIN and suffixes are not wildcarded', () => {
  for (const name of [
    'unknown.yav4.com',
    'unknown.dnas.playstation.org',
    'slot0001.pcsx2'
  ]) {
    const result = buildDnsResponse(query(name), records);
    assert.equal(result.address, null);
    assert.equal(result.rcode, 3);
    assert.equal(result.answerCount, 0);
    assert.equal(result.bytes.readUInt16BE(2), 0x8183);
  }
});

test('known name with unsupported AAAA type is NOERROR with no A answer', () => {
  const result = buildDnsResponse(query('stage6.sega.com', { type: 28 }), records);
  assert.equal(result.address, '192.0.2.121');
  assert.equal(result.rcode, 0);
  assert.equal(result.answerCount, 0);
  assert.equal(result.bytes.readUInt16BE(2), 0x8180);
});

test('record configuration rejects wildcard and invalid IPv4 values', () => {
  assert.throws(() => normalizeDnsRecords({ '*.yav4.com': '192.0.2.121' }));
  assert.throws(() => normalizeDnsRecords({ 'stage6.sega.com': '999.1.1.1' }));
});

test('parser rejects compression loops and truncated questions', () => {
  const loop = Buffer.alloc(18);
  loop.writeUInt16BE(0x1234, 0);
  loop.writeUInt16BE(0x0100, 2);
  loop.writeUInt16BE(1, 4);
  loop[12] = 0xc0;
  loop[13] = 0x0c;
  loop.writeUInt16BE(1, 14);
  loop.writeUInt16BE(1, 16);

  assert.throws(() => parseDnsQuery(loop), (error) => error.code === 'COMPRESSION_LOOP');
  assert.throws(() => parseDnsQuery(Buffer.alloc(11)), (error) => error.code === 'TRUNCATED_HEADER');
});

export { query as buildDnsQueryFixture };
