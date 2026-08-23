import assert from 'node:assert/strict';
import dgram from 'node:dgram';
import test from 'node:test';

import { DATAGRAM_TRAILER } from '../src/protocol/snap-udp-register-codec.js';
import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import { SnapRegisterService } from '../src/udp/register-service.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * The service seam: the 566-byte post-lobby snapshot, and the hand-off from the
 * register handshake to the post-selection subsystem.
 *
 * The T32 rig run of 2026-08-06 reached Server Select, the client opened its
 * SN@P session on 9090, sent opcode 0x01 at message length 0x236 - and V2 logged
 * "observed, not answered". 57 seconds later it reset and reported error 840.
 * That run is the negative control these tests encode against.
 */

const LOOPBACK = '127.0.0.1';
const TOKEN = 0x02f807d0;

function recordingLogger() {
  const entries = [];
  const record = (level) => (message, fields) => entries.push({ level, message, fields });
  return {
    entries,
    debug: record('debug'),
    info: record('info'),
    warn: record('warn'),
    error: record('error')
  };
}

function accountsWith(map) {
  return { getCompatibilitySecretByLoginIdentity: (userid) => map[userid] ?? null };
}

function registerDatagram({ loginIdentity = '12345', token = TOKEN, latencyTicks = 1600 } = {}) {
  const datagram = Buffer.alloc(154);
  datagram.writeUInt16BE(0x3096, 0x00);
  datagram.writeUInt8(0x2c, 0x03);
  datagram.writeUInt32BE(token, 0x04);
  const body = datagram.subarray(0x10);
  body.write(loginIdentity, 0x00, 'latin1');
  body.write(`${loginIdentity}@cee-auth`, 0x28, 'latin1');
  body.writeUInt32BE(0xcaf3, 0x64);
  Buffer.from([192, 0, 2, 248]).copy(body, 0x6c);
  body.writeUInt32BE(2000, 0x70);
  body.writeUInt32BE(100, 0x74);
  // The archive's TLV list: LC then MR. LC is conn+0x510, the watchdog quantum.
  body.writeUInt16BE(2, 0x78);
  body.write('LC', 0x7a, 'latin1');
  body.writeUInt32BE(latencyTicks, 0x7c);
  body.write('MR', 0x80, 'latin1');
  body.writeUInt32BE(48, 0x82);
  DATAGRAM_TRAILER.copy(datagram, 150);
  return datagram;
}

/**
 * Archive IN #8, the 570-byte post-lobby snapshot: `32 36 00 01`, the client's
 * own address, `00 00 00 f0` at body +0x04 - which is `conn+0x64`, the argument
 * that makes this the same builder as the 330-byte bind - then `F7E00001`, the
 * port and quantum, the endpoint name, and the 0xcaf3 selector.
 */
function snapshotDatagram({ identity = '12345', token = TOKEN, sequence = 0 } = {}) {
  const datagram = Buffer.alloc(570);
  datagram.writeUInt16BE(0x3236, 0x00);
  datagram.writeUInt8(0x01, 0x03);
  datagram.writeUInt32BE(token, 0x04);
  datagram.writeUInt32BE(sequence, 0x08);
  const body = datagram.subarray(0x10);
  Buffer.from([192, 0, 2, 248]).copy(body, 0x00);
  body.writeUInt32BE(0xf0, 0x04);
  body.writeUInt32BE(0xf7e00001, 0x08);
  body.writeUInt16BE(2000, 0x0c);
  body.writeUInt16BE(100, 0x0e);
  body.write(`${identity}-`, 0x10, 'latin1');
  body.writeUInt32BE(0xcaf3, 0x20);
  body.writeUInt16BE(2, 0x218);
  body.write('MR', 0x21a, 'latin1');
  body.writeUInt32BE(48, 0x21c);
  body.write('LC', 0x220, 'latin1');
  body.writeUInt32BE(1600, 0x222);
  DATAGRAM_TRAILER.copy(datagram, 566);
  return datagram;
}

/** Archive IN #9: the op-0x48 NAME query, reliable, sequence 0. */
const ARCHIVE_NAME_QUERY = Buffer.from(
  'f042004802f807d000000000000000000000000a020000004e414d4544313932' +
  '2e302e322e31323130310000004e414d45463139322e302e322e313231313000' +
  '0000ba476611', 'hex');

async function fixture(t, { withLobby = true } = {}) {
  const logger = recordingLogger();
  const wheelErrors = [];
  const wheel = new TimingWheel({ onError: (report) => wheelErrors.push(report) });
  wheel.start();
  const lobby = withLobby
    ? new SnapLobbySessions({
      wheel,
      areaDirectory: createV1ObservedAreaDirectory(),
      keepaliveKey: 'SNAP-SWAN',
      logger
    })
    : null;
  const service = new SnapRegisterService({
    bindAddress: LOOPBACK,
    advertisedAddress: '192.0.2.121',
    accountRepository: accountsWith({ 12345: '1234567890' }),
    logger,
    port: 0,
    lobby
  });
  await service.start();
  const client = dgram.createSocket('udp4');
  await new Promise((resolve) => client.bind(0, LOOPBACK, resolve));
  t.after(async () => {
    await new Promise((resolve) => client.close(resolve));
    await service.stop();
    wheel.stop();
  });
  return { service, client, logger, lobby, wheel, wheelErrors };
}

function collect(client, service, datagram, { ms = 250 } = {}) {
  return new Promise((resolve) => {
    const received = [];
    const onMessage = (reply) => received.push(reply);
    client.on('message', onMessage);
    client.send(datagram, service.address().port, LOOPBACK);
    setTimeout(() => {
      client.removeListener('message', onMessage);
      resolve(received);
    }, ms);
  });
}

async function registered(t, options) {
  const f = await fixture(t, options);
  const replies = await collect(f.client, f.service, registerDatagram());
  assert.equal(replies.length, 1, 'the register must succeed before anything downstream');
  return f;
}

test('the 566-byte snapshot is answered with an ACK and the slot-0x1c push', async (t) => {
  const f = await registered(t);
  const replies = await collect(f.client, f.service, snapshotDatagram());
  // Two datagrams for the snapshot, plus the first op-0x40 keepalive.
  const ack = replies.find((reply) => reply.length === 20);
  const push = replies.find((reply) => reply.length === 28);
  assert.ok(ack, 'the transport ACK');
  assert.ok(push, 'the slot-0x1c push');
  // Archive OUT #6 and #7, byte for byte.
  assert.deepEqual(ack, Buffer.from('6010000002f807d00000000000000000ba476611', 'hex'));
  assert.deepEqual(
    push,
    Buffer.from('b018002802f807d000000000000000000000000100000000ba476611', 'hex')
  );
});

/**
 * REPLACES a test that pinned the MIRRORED form (`push.seq == snapshot.seq`).
 *
 * That form was V1's and it is byte-identical on every real client input, because
 * every archived snapshot carries sequence 0. It is not identical on a synthetic
 * non-zero, and that is a latent desync rather than a curiosity: the push is
 * RELIABLE, `#openLobbySession` starts the client's stream at `inboundReceiveBase
 * 0`, and a reliable push at 0x2b would be buffered above the base and never
 * delivered - the same "buffered -> 840" the bind's push already avoids by
 * sending the constant. The ACK still mirrors, because an acknowledgement that
 * does not name the sequence it acknowledges acknowledges nothing.
 */
test('the slot-0x1c push carries the constant 0 while the ACK mirrors the snapshot', async (t) => {
  const f = await registered(t);
  const replies = await collect(f.client, f.service, snapshotDatagram({ sequence: 0x2b }));
  const push = replies.find((reply) => reply.length === 28);
  assert.equal(push.readUInt32BE(0x08), 0, 'the push sequence is not the peer\'s to choose');
  const ack = replies.find((reply) => reply.length === 20);
  assert.equal(ack.readUInt32BE(0x0c), 0x2b, 'the ACK names the message it acknowledges');
});

test('the stamped stream starts above the push, not above the peer sequence', async (t) => {
  const f = await registered(t);
  await collect(f.client, f.service, snapshotDatagram({ sequence: 0x2b }));
  // The op-0x48 query is reliable at sequence 0, which is where a fresh epoch's
  // client stream starts. Its reply must land at 1 - one above the push we sent -
  // and NOT at 0x2c, which is where mirroring the snapshot would have put it,
  // above a receive base of 0 that no later message can lift.
  const replies = await collect(f.client, f.service, ARCHIVE_NAME_QUERY);
  const reply = replies.find((entry) => entry.length === 392);
  assert.ok(reply, 'the area records');
  assert.equal(reply.readUInt32BE(0x08), 1);
});

test('the snapshot starts the op-0x40 keepalive, which is what defers 840', async (t) => {
  const f = await registered(t);
  const replies = await collect(f.client, f.service, snapshotDatagram());
  const keepalive = replies.find((reply) => reply.length === 296);
  assert.ok(keepalive, 'the keepalive leaves as soon as the snapshot is answered');
  assert.deepEqual(
    keepalive.subarray(0, 16),
    Buffer.from('3124004002f807d00000000100000000', 'hex')
  );
});

test('the snapshot does NOT arm the TCP lobby and does not mark the session bound', async (t) => {
  const armed = [];
  const logger = recordingLogger();
  const wheel = new TimingWheel({ onError: () => {} });
  wheel.start();
  const service = new SnapRegisterService({
    bindAddress: LOOPBACK,
    advertisedAddress: '192.0.2.121',
    accountRepository: accountsWith({ 12345: '1234567890' }),
    logger,
    port: 0,
    onLobbyReady: (event) => armed.push(event),
    lobby: new SnapLobbySessions({
      wheel,
      areaDirectory: createV1ObservedAreaDirectory(),
      keepaliveKey: 'SNAP-SWAN',
      logger
    })
  });
  await service.start();
  const client = dgram.createSocket('udp4');
  await new Promise((resolve) => client.bind(0, LOOPBACK, resolve));
  t.after(async () => {
    await new Promise((resolve) => client.close(resolve));
    await service.stop();
    wheel.stop();
  });

  await collect(client, service, registerDatagram());
  await collect(client, service, snapshotDatagram());
  // `game_udp_server.js:2770-2776`: arming from this message leaves stale pending
  // entries that make the next TCP connect run the wrong state machine.
  assert.deepEqual(armed, []);
  const session = service.sessions.resolve({
    address: LOOPBACK, port: client.address().port, endpointToken: TOKEN
  }).session;
  assert.equal(session.boundAtMs, null);
});

test('after the snapshot the op-0x48 query is acked and answered from the socket', async (t) => {
  const f = await registered(t);
  await collect(f.client, f.service, snapshotDatagram());
  const replies = await collect(f.client, f.service, ARCHIVE_NAME_QUERY);
  const ack = replies.find((reply) => reply.length === 20);
  const reply = replies.find((reply) => reply.length === 392);
  assert.ok(ack, 'every reliable inbound is acknowledged');
  assert.equal(ack.readUInt32BE(0x0c), 0);
  assert.ok(reply, 'the area records');
  // Stamped at 1: the mirrored push took the client recvBase to 1.
  assert.deepEqual(reply.subarray(0, 16), Buffer.from('b184004802f807d00000000100000000', 'hex'));
});

test('without a lobby subsystem the snapshot is answered but nothing downstream is', async (t) => {
  const f = await registered(t, { withLobby: false });
  const answered = await collect(f.client, f.service, snapshotDatagram());
  assert.equal(answered.length, 2, 'the ACK and the push still go out; no keepalive');
  const silent = await collect(f.client, f.service, ARCHIVE_NAME_QUERY);
  assert.deepEqual(silent, []);
  assert.ok(f.logger.entries.some((entry) =>
    entry.message === 'udp9090 observed-message' && entry.fields.opcode === '0x48'));
});

test('opcode 0x01 at neither bind length is still observed and not answered', async (t) => {
  const f = await registered(t);
  const odd = Buffer.alloc(84);
  odd.writeUInt16BE(0x3050, 0x00);
  odd.writeUInt8(0x01, 0x03);
  odd.writeUInt32BE(TOKEN, 0x04);
  DATAGRAM_TRAILER.copy(odd, 80);
  assert.deepEqual(await collect(f.client, f.service, odd), []);
  const observed = f.logger.entries.find((entry) =>
    entry.message === 'udp9090 observed-message' && entry.fields.length === 0x50);
  assert.match(observed.fields.note, /neither the post-register bind nor the post-lobby snapshot/);
});

test('a snapshot from a source with no register is silently dropped', async (t) => {
  const f = await fixture(t);
  assert.deepEqual(await collect(f.client, f.service, snapshotDatagram()), []);
  assert.ok(f.logger.entries.some((entry) =>
    entry.message === 'udp9090 post-lobby-snapshot-refused'));
});

test('a fresh register closes the previous epoch lobby session', async (t) => {
  const f = await registered(t);
  await collect(f.client, f.service, snapshotDatagram());
  assert.equal(f.lobby.size, 1);
  const opened = f.lobby.get(`${LOOPBACK}:${f.client.address().port}`);
  await collect(f.client, f.service, registerDatagram());
  assert.equal(f.lobby.size, 0);
  assert.equal(f.wheel.countForOwner(opened), 0);
  assert.equal(f.wheel.countForOwner(opened.channel), 0);
});

test('the keepalive budget comes from the register LC TLV, per session', async (t) => {
  const f = await fixture(t);
  await collect(f.client, f.service, registerDatagram({ latencyTicks: 1600 }));
  await collect(f.client, f.service, snapshotDatagram());
  const opened = f.logger.entries.find((entry) => entry.message === 'udp9090 lobby-session-opened');
  assert.equal(opened.fields.latencyTicks, 1600);
  assert.equal(opened.fields.watchdogBudgetMs, 55_200);
});

test('stopping the service releases every lobby session and leaks no timers', async (t) => {
  const f = await registered(t);
  await collect(f.client, f.service, snapshotDatagram());
  const opened = f.lobby.get(`${LOOPBACK}:${f.client.address().port}`);
  await f.service.stop();
  assert.equal(f.lobby.size, 0);
  assert.equal(f.wheel.countForOwner(opened), 0);
  assert.deepEqual(f.wheelErrors, []);
});
