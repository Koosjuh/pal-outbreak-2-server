import assert from 'node:assert/strict';
import crypto from 'node:crypto';
import fs from 'node:fs';
import path from 'node:path';
import test from 'node:test';

import { DnasApplicationService } from '../src/dnas/application-codec.js';
import { LegacyDnasTlsConnection, LegacyTlsError } from '../src/dnas/legacy-tls.js';
import { FileDnasPacketStore } from '../src/dnas/packet-store.js';

const captureDirectory = process.env.DNAS_CAPTURE_DIR;
const packetDirectory = process.env.DNAS_PACKET_DIR;
const runtimeDirectory = process.env.DNAS_V1_RUNTIME_DIR;
const externalFixturesAvailable = Boolean(captureDirectory && packetDirectory && runtimeDirectory);

function loadFixture() {
  const input = fs.readFileSync(path.join(captureDirectory, 'dnas_conn4_raw_in.bin'));
  const output = fs.readFileSync(path.join(captureDirectory, 'dnas_conn4_raw_out.bin'));
  const certificatePem = fs.readFileSync(path.join(runtimeDirectory, 'server.crt'), 'utf8');
  const caCertificatePem = fs.readFileSync(path.join(runtimeDirectory, 'ca-cert.pem'), 'utf8');
  const privateKey = crypto.createPrivateKey(
    fs.readFileSync(path.join(runtimeDirectory, 'server.key'), 'utf8')
  );
  return {
    input,
    output,
    certificateDer: Buffer.from(new crypto.X509Certificate(certificatePem).raw),
    caCertificateDer: Buffer.from(new crypto.X509Certificate(caCertificatePem).raw),
    privateKey,
    serverRandom: output.subarray(11, 43)
  };
}

function createConnection(fixture) {
  return new LegacyDnasTlsConnection({
    certificateDer: fixture.certificateDer,
    caCertificateDer: fixture.caCertificateDer,
    privateKey: fixture.privateKey,
    serverRandom: fixture.serverRandom,
    applicationService: new DnasApplicationService({
      packetStore: new FileDnasPacketStore(packetDirectory)
    })
  });
}

async function replay(fixture, chunkSizes) {
  const connection = createConnection(fixture);
  const writes = [];
  let offset = 0;
  let chunkIndex = 0;
  while (offset < fixture.input.length) {
    const requested = chunkSizes[chunkIndex % chunkSizes.length];
    const length = Math.min(requested, fixture.input.length - offset);
    writes.push(...await connection.feed(fixture.input.subarray(offset, offset + length)));
    offset += length;
    chunkIndex += 1;
  }
  return { connection, output: Buffer.concat(writes) };
}

test(
  'captured PAL i-connect TLS transcript replays byte-for-byte',
  { skip: externalFixturesAvailable ? false : 'set DNAS_CAPTURE_DIR, DNAS_PACKET_DIR, and DNAS_V1_RUNTIME_DIR' },
  async () => {
    const fixture = loadFixture();
    assert.equal(fixture.input.length, 754);
    assert.equal(fixture.output.length, 1760);

    const { connection, output } = await replay(fixture, [fixture.input.length]);

    assert.deepEqual(output, fixture.output);
    assert.equal(connection.state, 'APPLICATION_DATA');
    assert.equal(connection.closedByPeer, true);
    assert.equal(connection.failed, false);
    assert.equal(
      connection.events.filter((event) => event.type === 'record-mac-verified').length,
      3
    );
    assert.ok(connection.events.some((event) => event.type === 'client-finished-verified'));
    assert.ok(connection.events.some(
      (event) => event.type === 'application-response' &&
        event.ok === true &&
        event.packetKey === 'f4c26cd13fb1df55_01080000' &&
        event.responseBodyLength === 328
    ));
    assert.ok(connection.events.some((event) => event.type === 'close-notify'));
  }
);

test(
  'TLS replay output is independent of captured TCP segmentation',
  { skip: externalFixturesAvailable ? false : 'set DNAS_CAPTURE_DIR, DNAS_PACKET_DIR, and DNAS_V1_RUNTIME_DIR' },
  async () => {
    const fixture = loadFixture();
    const oneByte = await replay(fixture, [1]);
    const uneven = await replay(fixture, [1, 2, 7, 31, 3, 128, 5, 64, 11]);

    assert.deepEqual(oneByte.output, fixture.output);
    assert.deepEqual(uneven.output, fixture.output);
    assert.deepEqual(oneByte.output, uneven.output);
  }
);

test(
  'TLS engine rejects a tampered encrypted record MAC',
  { skip: externalFixturesAvailable ? false : 'set DNAS_CAPTURE_DIR, DNAS_PACKET_DIR, and DNAS_V1_RUNTIME_DIR' },
  async () => {
    const fixture = loadFixture();
    const tampered = Buffer.from(fixture.input);
    tampered[tampered.length - 1] ^= 0x01;
    const connection = createConnection(fixture);

    await assert.rejects(
      connection.feed(tampered),
      (error) => error instanceof LegacyTlsError && error.code === 'BAD_RECORD_MAC'
    );
    assert.equal(connection.failed, true);
    assert.ok(connection.events.some(
      (event) => event.type === 'protocol-error' && event.code === 'BAD_RECORD_MAC'
    ));
  }
);
