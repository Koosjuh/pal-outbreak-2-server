import assert from 'node:assert/strict';
import dgram from 'node:dgram';
import net from 'node:net';
import test from 'node:test';

import { createDnsService } from '../src/dns/dns-service.js';

function encodeName(name) {
  return Buffer.concat([
    ...name.split('.').map((label) => Buffer.concat([Buffer.from([label.length]), Buffer.from(label)])),
    Buffer.from([0])
  ]);
}

function query(name) {
  const header = Buffer.alloc(12);
  header.writeUInt16BE(0x4567, 0);
  header.writeUInt16BE(0x0100, 2);
  header.writeUInt16BE(1, 4);
  return Buffer.concat([header, encodeName(name), Buffer.from([0, 1, 0, 1])]);
}

/**
 * Pick a UDP/TCP port outside Windows' Hyper-V reserved dynamic ranges.
 *
 * On this workstation `netsh interface ipv4 show excludedportrange protocol=udp`
 * reports 59968-60067 reserved, and the OS was auto-assigning inside it, so any
 * ephemeral bind failed with EACCES. That had been misread as parallel-load
 * flakiness; it is a hard OS exclusion. Choosing from a low, unreserved band and
 * retrying on collision avoids it entirely.
 */
let nextTestPort = 24000 + Math.floor(Math.random() * 2000);
function candidatePort() {
  nextTestPort = 24000 + ((nextTestPort - 24000 + 1) % 4000);
  return nextTestPort;
}

async function bindWithRetry(attempt) {
  let lastError = null;
  for (let tries = 0; tries < 40; tries += 1) {
    try {
      return await attempt(candidatePort());
    } catch (error) {
      if (error.code !== 'EACCES' && error.code !== 'EADDRINUSE') throw error;
      lastError = error;
    }
  }
  throw lastError;
}

async function fixture(t) {
  const events = [];
  const service = createDnsService({
    records: {
      'gate1.eu.dnas.playstation.org': '192.0.2.121',
      'stage6.sega.com': '192.0.2.121',
      'snap01.capcom.client.sf.yav4.com': '192.0.2.121'
    },
    logger: (event) => events.push(event)
  });
  const address = await bindWithRetry(async (port) => {
    try {
      return await service.listen({ host: '127.0.0.1', port });
    } catch (error) {
      await service.close().catch(() => {});
      throw error;
    }
  });
  t.after(() => service.close());
  return { service, events, port: address.port };
}

/**
 * Send one UDP query and read the reply.
 *
 * Retries on EACCES. On Windows, Hyper-V reserves dynamic port ranges (here
 * `netsh interface ipv4 show excludedportrange protocol=udp` reported
 * 59968-60067), and an implicitly bound client socket that lands inside one
 * fails with EACCES. That is an environment fact, not a DNS defect - it had
 * previously been misread as parallel-load flakiness. Binding explicitly and
 * retrying makes the OS hand out a different port.
 */
function udpRequest(port, message, attemptsLeft = 8) {
  return new Promise((resolve, reject) => {
    const socket = dgram.createSocket('udp4');
    const timer = setTimeout(() => {
      socket.close();
      reject(new Error('UDP DNS request timed out'));
    }, 2_000);
    const onError = (error) => {
      clearTimeout(timer);
      try {
        socket.close();
      } catch {
        // Already closed by the failed bind.
      }
      if (error.code === 'EACCES' && attemptsLeft > 0) {
        resolve(udpRequest(port, message, attemptsLeft - 1));
        return;
      }
      reject(error);
    };
    socket.once('error', onError);
    socket.once('message', (response) => {
      clearTimeout(timer);
      socket.close();
      resolve(response);
    });
    socket.bind(candidatePort(), '127.0.0.1', () => {
      socket.send(message, port, '127.0.0.1');
    });
  });
}

function tcpRequest(port, message) {
  return new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port });
    const frame = Buffer.alloc(message.length + 2);
    frame.writeUInt16BE(message.length, 0);
    message.copy(frame, 2);
    let response = Buffer.alloc(0);
    const timer = setTimeout(() => {
      socket.destroy();
      reject(new Error('TCP DNS request timed out'));
    }, 2_000);
    socket.on('connect', () => {
      socket.write(frame.subarray(0, 3));
      socket.write(frame.subarray(3));
    });
    socket.on('data', (chunk) => {
      response = Buffer.concat([response, chunk]);
      if (response.length >= 2 && response.length >= response.readUInt16BE(0) + 2) {
        clearTimeout(timer);
        socket.end();
        resolve(response.subarray(2, response.readUInt16BE(0) + 2));
      }
    });
    socket.on('error', reject);
  });
}

test('DNS service resolves explicit records over UDP and TCP', async (t) => {
  const { events, port } = await fixture(t);
  const message = query('snap01.capcom.client.sf.yav4.com');
  const udpResponse = await udpRequest(port, message);
  const tcpResponse = await tcpRequest(port, message);

  assert.deepEqual(udpResponse, tcpResponse);
  assert.equal(udpResponse.readUInt16BE(2), 0x8180);
  assert.deepEqual(udpResponse.subarray(-4), Buffer.from([192, 0, 2, 121]));
  assert.ok(events.some((event) => event.type === 'query' && event.transport === 'udp'));
  assert.ok(events.some((event) => event.type === 'query' && event.transport === 'tcp'));
});

test('DNS service returns NXDOMAIN instead of resolving a V1 wildcard suffix', async (t) => {
  const { port } = await fixture(t);
  const response = await udpRequest(port, query('not-proven.yav4.com'));
  assert.equal(response.readUInt16BE(2), 0x8183);
  assert.equal(response.readUInt16BE(6), 0);
});
