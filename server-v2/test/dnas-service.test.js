import assert from 'node:assert/strict';
import fs from 'node:fs';
import net from 'node:net';
import path from 'node:path';
import test from 'node:test';

import { createConfiguredDnasService } from '../src/dnas/dnas-service.js';

const captureDirectory = process.env.DNAS_CAPTURE_DIR;
const packetDirectory = process.env.DNAS_PACKET_DIR;
const runtimeDirectory = process.env.DNAS_V1_RUNTIME_DIR;
const externalFixturesAvailable = Boolean(captureDirectory && packetDirectory && runtimeDirectory);

function loadFixture() {
  const input = fs.readFileSync(path.join(captureDirectory, 'dnas_conn4_raw_in.bin'));
  const output = fs.readFileSync(path.join(captureDirectory, 'dnas_conn4_raw_out.bin'));
  return {
    input,
    output,
    serverRandom: output.subarray(11, 43)
  };
}

async function startService(t, fixture, events, { idleTimeoutMs = 1_000 } = {}) {
  const server = createConfiguredDnasService({
    certificatePath: path.join(runtimeDirectory, 'server.crt'),
    caCertificatePath: path.join(runtimeDirectory, 'ca-cert.pem'),
    privateKeyPath: path.join(runtimeDirectory, 'server.key'),
    packetDirectory,
    idleTimeoutMs,
    randomBytes: (length) => {
      assert.equal(length, 32);
      return Buffer.from(fixture.serverRandom);
    },
    logger: (event) => events.push(event)
  });
  await new Promise((resolve, reject) => {
    server.once('error', reject);
    server.listen(0, '127.0.0.1', resolve);
  });
  t.after(() => new Promise((resolve) => server.close(resolve)));
  return server.address().port;
}

function socketExchange(port, input, chunkSizes) {
  return new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port });
    const output = [];
    let offset = 0;
    let chunkIndex = 0;
    const timer = setTimeout(() => {
      socket.destroy();
      reject(new Error('DNAS socket exchange timed out'));
    }, 5_000);

    function finish(error = null) {
      clearTimeout(timer);
      if (error) reject(error);
      else resolve(Buffer.concat(output));
    }

    function writeNext() {
      if (offset >= input.length) return;
      const requested = chunkSizes[chunkIndex % chunkSizes.length];
      const length = Math.min(requested, input.length - offset);
      const chunk = input.subarray(offset, offset + length);
      offset += length;
      chunkIndex += 1;
      socket.write(chunk, () => setImmediate(writeNext));
    }

    socket.on('connect', writeNext);
    socket.on('data', (chunk) => output.push(chunk));
    socket.on('end', () => finish());
    socket.on('error', (error) => finish(error));
  });
}

test(
  'configured DNAS service reproduces the capture through a real TCP socket',
  { skip: externalFixturesAvailable ? false : 'set DNAS_CAPTURE_DIR, DNAS_PACKET_DIR, and DNAS_V1_RUNTIME_DIR' },
  async (t) => {
    const fixture = loadFixture();
    const events = [];
    const port = await startService(t, fixture, events);

    const output = await socketExchange(port, fixture.input, [1, 7, 31, 2, 128, 5, 64]);

    assert.deepEqual(output, fixture.output);
    assert.ok(events.some((event) => event.type === 'connection-open'));
    assert.ok(events.some(
      (event) => event.type === 'tls-event' && event.event.type === 'client-finished-verified'
    ));
    assert.ok(events.some(
      (event) => event.type === 'tls-event' &&
        event.event.type === 'application-response' &&
        event.event.packetKey === 'f4c26cd13fb1df55_01080000'
    ));
    assert.ok(events.some(
      (event) => event.type === 'tls-event' && event.event.type === 'close-notify'
    ));
    assert.equal(
      events.some((event) => JSON.stringify(event).includes('d59ec24acbe83c8f')),
      false,
      'structured events must not expose derived key material'
    );
  }
);

test(
  'a corrupted connection does not poison the next DNAS connection',
  { skip: externalFixturesAvailable ? false : 'set DNAS_CAPTURE_DIR, DNAS_PACKET_DIR, and DNAS_V1_RUNTIME_DIR' },
  async (t) => {
    const fixture = loadFixture();
    const events = [];
    const port = await startService(t, fixture, events);
    const corrupted = Buffer.from(fixture.input);
    corrupted[corrupted.length - 1] ^= 0x01;

    await socketExchange(port, corrupted, [corrupted.length]);
    assert.ok(events.some(
      (event) => event.type === 'protocol-error' && event.errorCode === 'BAD_RECORD_MAC'
    ));

    const validOutput = await socketExchange(port, fixture.input, [13, 3, 89, 1]);
    assert.deepEqual(validOutput, fixture.output);
    const opens = events.filter((event) => event.type === 'connection-open');
    assert.equal(opens.length, 2);
    assert.notEqual(opens[0].connectionId, opens[1].connectionId);
  }
);

test(
  'idle DNAS connections are bounded by the configured timeout',
  { skip: externalFixturesAvailable ? false : 'set DNAS_CAPTURE_DIR, DNAS_PACKET_DIR, and DNAS_V1_RUNTIME_DIR' },
  async (t) => {
    const fixture = loadFixture();
    const events = [];
    const port = await startService(t, fixture, events, { idleTimeoutMs: 50 });

    await new Promise((resolve, reject) => {
      const socket = net.createConnection({ host: '127.0.0.1', port });
      const timer = setTimeout(() => reject(new Error('idle connection was not closed')), 2_000);
      socket.on('close', () => {
        clearTimeout(timer);
        resolve();
      });
      socket.on('error', reject);
    });

    assert.ok(events.some(
      (event) => event.type === 'connection-timeout' && event.idleTimeoutMs === 50
    ));
  }
);
