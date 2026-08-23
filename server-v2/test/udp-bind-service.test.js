import test from 'node:test';
import assert from 'node:assert/strict';
import { createHash } from 'node:crypto';
import dgram from 'node:dgram';

import { BIND_ATTACHMENT, SnapRegisterService } from '../src/udp/register-service.js';
import { RegistrationNonceTable } from '../src/udp/registration-nonces.js';
import { RegisterSessionTable } from '../src/udp/register-sessions.js';
import {
  DATAGRAM_TRAILER,
  decodeBindRequest,
  decodeSnapUdpDatagram
} from '../src/protocol/snap-udp-register-codec.js';

const LOOPBACK = '127.0.0.1';

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
  return {
    getCompatibilitySecretByLoginIdentity: (userid) => map[userid] ?? null
  };
}

function registerDatagram({ loginIdentity = '12345', token = 0x02f807d0 } = {}) {
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
  body.writeUInt16BE(0, 0x78);
  DATAGRAM_TRAILER.copy(datagram, 150);
  return datagram;
}

/**
 * The real client's bind, rebuilt from `captures/v2-live/v2-run4-register.pcap`
 * frame 6 and identical in shape to the archived V1 `IN #3`. 330 bytes:
 * `31 46 00 01`, the client address/port/quantum, then the endpoint name - the
 * login identity with the trailing dash `FUN_00626900` appends.
 */
function bindDatagram({ identity = '12345', token = 0x02f807d0, sequence = 0 } = {}) {
  const datagram = Buffer.alloc(330);
  datagram.writeUInt16BE(0x3146, 0x00);
  datagram.writeUInt8(0x00, 0x02);
  datagram.writeUInt8(0x01, 0x03);
  datagram.writeUInt32BE(token, 0x04);
  datagram.writeUInt32BE(sequence, 0x08);
  const body = datagram.subarray(0x10);
  Buffer.from([192, 0, 2, 248]).copy(body, 0x00);
  body.writeUInt32BE(0, 0x04);
  body.writeUInt32BE(1, 0x08);
  body.writeUInt16BE(2000, 0x0c);
  body.writeUInt16BE(100, 0x0e);
  body.write(`${identity}-`, 0x10, 'latin1');
  body.writeUInt32BE(0xcaf3, 0x20);
  // The TLV list trails the 0x128-byte template: count 2, then MR then LC -
  // the REVERSE of the register's order. Omitting it is what the first version
  // of this fixture got wrong, and only the captured bytes exposed it.
  body.writeUInt16BE(2, 0x128);
  body.write('MR', 0x12a, 'latin1');
  body.writeUInt32BE(48, 0x12c);
  body.write('LC', 0x130, 'latin1');
  body.writeUInt32BE(1600, 0x132);
  DATAGRAM_TRAILER.copy(datagram, 326);
  return datagram;
}

/** The captured 20-byte opcode-0x02 application acknowledgement. */
function appAckDatagram({ token = 0x02f807d0, sequence = 0 } = {}) {
  const datagram = Buffer.alloc(20);
  datagram.writeUInt16BE(0xb010, 0x00);
  datagram.writeUInt8(0x02, 0x03);
  datagram.writeUInt32BE(token, 0x04);
  datagram.writeUInt32BE(sequence, 0x08);
  DATAGRAM_TRAILER.copy(datagram, 16);
  return datagram;
}

async function fixture(t, accounts, { sessions = null } = {}) {
  const logger = recordingLogger();
  const service = new SnapRegisterService({
    bindAddress: LOOPBACK,
    advertisedAddress: '192.0.2.121',
    accountRepository: accounts,
    logger,
    port: 0,
    sessions
  });
  await service.start();
  const client = dgram.createSocket('udp4');
  await new Promise((resolve) => client.bind(0, LOOPBACK, resolve));
  t.after(async () => {
    await new Promise((resolve) => client.close(resolve));
    await service.stop();
  });
  return { service, client, logger };
}

/** Collect every datagram arriving within a window. */
function collect(client, service, datagram, { ms = 400 } = {}) {
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

async function registered(t, identity = '12345', password = '1234567890', options = {}) {
  const f = await fixture(t, accountsWith({ [identity]: password }), options);
  const replies = await collect(f.client, f.service, registerDatagram({ loginIdentity: identity }));
  assert.equal(replies.length, 1, 'the register must succeed before a bind can be tested');
  return f;
}

/**
 * The REAL client's bind, verbatim from `captures/v2-live/v2-run4-register.pcap`
 * frame 6 (2026-08-03 20:23:28, address sanitized to 192.0.2.248 -> the Pi). Not reconstructed
 * apart from that privacy substitution:
 * these are the bytes a PS2 actually sent. Decoding THESE is what pins the body
 * offsets, and it is what caught a 2-byte error in the endpoint-name field width
 * that a hand-built fixture had faithfully reproduced.
 */
const CAPTURED_BIND_HEX =
  '3146000102f807d00000000000000000c00002f8000000000000000107d0006474657374' +
  '3132332d00000000000000000000caf30000000000000000000000000000000000000000' +
  '000000000000000000000000000000000000000000000000000000000000000000000000' +
  '000000000000000000000000000000000000000000000000000000000000000000000000' +
  '000000000000000000000000000000000000000000000000000000000000000000000000' +
  '000000000000000000000000000000000000000000000000000000000000000000000000' +
  '000000000000000000000000000000000000000000000000000000000000000000000000' +
  '000000000000000000000000000000000000000000000000000000000000000000000000' +
  '00000000000000000000000000000000000000000000000000024d52000000304c430000' +
  '0640ba476611';

test('decodes the real captured bind, field for field', () => {
  const datagram = Buffer.from(CAPTURED_BIND_HEX, 'hex');
  assert.equal(datagram.length, 330);

  const messages = decodeSnapUdpDatagram(datagram);
  assert.equal(messages.length, 1);
  assert.equal(messages[0].opcode, 0x01);
  assert.equal(messages[0].length, 0x146);
  assert.equal(messages[0].who, 0x3146);
  assert.equal(messages[0].endpointToken, 0x02f807d0);

  const bind = decodeBindRequest(messages[0]);
  // The endpoint name is a 16-byte NUL-padded field at body +0x10, so the
  // selector is a BE32 at +0x20. Reading the name as 18 bytes shifted the
  // selector to +0x22 and yielded 0xcaf30000 instead of 0xcaf3.
  assert.equal(bind.endpointName, 'test123-');
  assert.equal(bind.endpointIdentity, 'test123', 'the dash FUN_00626900 appends is stripped');
  assert.equal(bind.selector, 0xcaf3);
  assert.equal(bind.clientPort, 2000);
  assert.equal(bind.quantum, 100);
  assert.equal(Array.from(bind.clientIpv4).join('.'), '192.0.2.248');
  assert.equal(bind.sequence, 0);
  // MR before LC - the reverse of the register's LC, MR.
  assert.deepEqual(bind.tlvs, [
    { tag: 'MR', value: 48 },
    { tag: 'LC', value: 1600 }
  ]);
});

test('the reconstructed fixture matches the captured bind byte for byte', () => {
  // If these ever diverge, every other test in this file is testing a fiction.
  const captured = Buffer.from(CAPTURED_BIND_HEX, 'hex');
  const rebuilt = bindDatagram({ identity: 'test123' });
  assert.equal(rebuilt.toString('hex'), captured.toString('hex'));
});

/**
 * GOLDEN: byte-identical to what V1 sent and the real client accepted, from the
 * archived trace `udp9090/2026_07_12_10_38_35` OUT #2 and OUT #3.
 * The push is byte-identical in all 39 archived sessions that contain one, up to
 * the endpoint token.
 */
test('GOLDEN: the bind is answered with the exact captured ACK and slot-0x1c push', async (t) => {
  const { client, service } = await registered(t);
  const replies = await collect(client, service, bindDatagram());

  assert.equal(replies.length, 2, 'two separate datagrams, as the trace shows');
  assert.equal(
    replies[0].toString('hex'),
    '6010000002f807d00000000000000000ba476611',
    'transport ACK'
  );
  assert.equal(
    replies[1].toString('hex'),
    'b018002802f807d000000000000000000000000100000000ba476611',
    'slot-0x1c push: opcode 0x28, selector 1, status 0'
  );
});

test('the ACK field carries the acknowledged sequence, not a constant', async (t) => {
  // Across the archive this field takes 0x00 and essentially all of 0x05-0xff,
  // and 18/18 sampled incoming sequences match the next ACK's +0x0c exactly. A
  // constant looks correct at the bind, whose sequence is 0, and is wrong
  // everywhere after it.
  const { client, service } = await registered(t);
  const replies = await collect(client, service, bindDatagram({ sequence: 0x2c }));

  assert.equal(replies[0].readUInt32BE(0x0c), 0x2c);
  assert.equal(replies[0].readUInt16BE(0x00), 0x6010, 'CARRIES_ACK | SET, length 0x10');
  assert.equal(replies[1].readUInt32BE(0x08), 0, 'the push sequence is unaffected');
});

test('a bind without a completed register is refused', async (t) => {
  const { client, service, logger } = await fixture(t, accountsWith({ 12345: '1234567890' }));
  assert.equal((await collect(client, service, bindDatagram(), { ms: 300 })).length, 0);

  const refused = logger.entries.find((entry) => entry.message === 'udp9090 bind-refused');
  assert.ok(refused);
  assert.match(refused.fields.reason, /no completed register/);
  assert.match(refused.fields.note, /not captured behaviour/);
});

test('a bind presenting a token other than the registered one is refused', async (t) => {
  const { client, service, logger } = await registered(t);
  const replies = await collect(client, service, bindDatagram({ token: 0xdeadbeef }), { ms: 300 });

  assert.equal(replies.length, 0);
  assert.match(
    logger.entries.find((entry) => entry.message === 'udp9090 bind-refused').fields.reason,
    /endpoint token/
  );
});

test('one client cannot bind another registered session', async (t) => {
  const { client, service, logger } = await registered(t);

  const attacker = dgram.createSocket('udp4');
  t.after(() => new Promise((resolve) => attacker.close(resolve)));
  await new Promise((resolve) => attacker.bind(0, LOOPBACK, resolve));

  const stolen = await collect(attacker, service, bindDatagram(), { ms: 300 });
  assert.equal(stolen.length, 0, 'sessions key on source, so replaying the token gets nothing');
  assert.ok(logger.entries.find((entry) => entry.message === 'udp9090 bind-refused'));

  // The legitimate client is unaffected.
  assert.equal((await collect(client, service, bindDatagram())).length, 2);
});

test('the bind inherits the LOGIN IDENTITY from its register session', async (t) => {
  const { client, service, logger } = await registered(t, 'test123', 'secret42');
  await collect(client, service, bindDatagram({ identity: 'test123' }));

  const bind = logger.entries.find((entry) => entry.message === 'udp9090 bind-request');
  assert.equal(bind.fields.loginIdentity, 'test123');
  assert.equal(bind.fields.endpointName, 'test123-', 'the client sends identity + dash');
  assert.equal(bind.fields.endpointIdentityMatchesSession, true);
});

test('an endpoint name disagreeing with the session is logged, never trusted', async (t) => {
  const { client, service, logger } = await registered(t, 'test123', 'secret42');
  const replies = await collect(client, service, bindDatagram({ identity: 'someoneelse' }));

  // Answered, because the name is client-supplied and is not an authenticator -
  // but the SESSION identity is what is used, and the disagreement is visible.
  assert.equal(replies.length, 2);
  const mismatch = logger.entries.find(
    (entry) => entry.message === 'udp9090 bind-endpoint-identity-mismatch'
  );
  assert.ok(mismatch);
  assert.equal(mismatch.fields.loginIdentity, 'test123');
  assert.equal(mismatch.fields.endpointName, 'someoneelse-');
});

test('a duplicate bind is answered again, identically', async (t) => {
  const { client, service, logger } = await registered(t);
  const first = await collect(client, service, bindDatagram());
  const second = await collect(client, service, bindDatagram());

  assert.equal(first[0].toString('hex'), second[0].toString('hex'));
  assert.equal(first[1].toString('hex'), second[1].toString('hex'));
  const binds = logger.entries.filter((entry) => entry.message === 'udp9090 bind-request');
  assert.equal(binds.length, 2);
  assert.equal(binds[1].fields.duplicateBind, true, 'the retry is visible in the log');
});

test('malformed and truncated binds are dropped without a reply', async (t) => {
  const { client, service, logger } = await registered(t);

  // A short opcode-0x01 never reaches the decoder: the length gate rejects
  // anything that is not the 0x146-byte post-register bind first. Stricter than
  // decoding it and failing, and it is what keeps game-phase 0x01s out.
  const short = Buffer.alloc(0x24);
  short.writeUInt16BE(0x3000 | 0x20, 0x00);
  short.writeUInt8(0x01, 0x03);
  short.writeUInt32BE(0x02f807d0, 0x04);
  DATAGRAM_TRAILER.copy(short, 0x20);
  assert.equal((await collect(client, service, short, { ms: 250 })).length, 0);
  const observed = logger.entries.find(
    (entry) => entry.message === 'udp9090 observed-message' && entry.fields.opcode === '0x1'
  );
  assert.ok(observed, 'a wrong-length 0x01 is observed, not decoded as a bind');

  // Truncated mid-body: framing itself fails.
  const truncated = bindDatagram().subarray(0, 100);
  assert.equal((await collect(client, service, truncated, { ms: 250 })).length, 0);

  // Still healthy afterwards.
  assert.equal((await collect(client, service, bindDatagram())).length, 2);
});

test('the opcode-0x02 app ACK is acknowledged and ends the exchange', async (t) => {
  const { client, service, logger } = await registered(t);
  await collect(client, service, bindDatagram());

  const replies = await collect(client, service, appAckDatagram());
  assert.equal(replies.length, 1, 'the app ACK is RELIABLE and must be acknowledged');
  assert.equal(replies[0].toString('hex'), '6010000002f807d00000000000000000ba476611');

  const received = logger.entries.find((entry) => entry.message === 'udp9090 app-ack-received');
  assert.ok(received, 'the success signal for the whole exchange');
  assert.equal(received.fields.loginIdentity, '12345');
  assert.match(received.fields.note, /TCP 10127/);
});

test('an app ACK acknowledges its own sequence', async (t) => {
  const { client, service } = await registered(t);
  await collect(client, service, bindDatagram());
  const replies = await collect(client, service, appAckDatagram({ sequence: 7 }));
  assert.equal(replies[0].readUInt32BE(0x0c), 7);
});

test('an app ACK without a session is refused', async (t) => {
  const { client, service, logger } = await fixture(t, accountsWith({}));
  assert.equal((await collect(client, service, appAckDatagram(), { ms: 250 })).length, 0);
  assert.ok(logger.entries.find((entry) => entry.message === 'udp9090 app-ack-refused'));
});

test('the full register -> bind -> app-ack sequence on one socket', async (t) => {
  const { client, service, logger } = await fixture(t, accountsWith({ test123: 'secret42' }));

  assert.equal(
    (await collect(client, service, registerDatagram({ loginIdentity: 'test123' }))).length,
    1
  );
  assert.equal((await collect(client, service, bindDatagram({ identity: 'test123' }))).length, 2);
  assert.equal((await collect(client, service, appAckDatagram())).length, 1);

  const events = logger.entries.map((entry) => entry.message);
  for (const expected of [
    'udp9090 register-replied',
    'udp9090 bind-request',
    'udp9090 bind-transport-ack',
    'udp9090 bind-slot1c-push',
    'udp9090 app-ack-received',
    'udp9090 app-ack-transport-ack'
  ]) {
    assert.ok(events.includes(expected), `missing ${expected}`);
  }
});

/* ---- session lifetime --------------------------------------------------- */

test('a session expires after its TTL, and a later bind is refused', async (t) => {
  let now = 1_000_000;
  const sessions = new RegisterSessionTable({ ttlMs: 60_000, clock: () => now });
  const { client, service, logger } = await registered(t, '12345', '1234567890', { sessions });

  assert.equal(sessions.size, 1);
  now += 60_001;
  assert.equal((await collect(client, service, bindDatagram(), { ms: 300 })).length, 0);
  assert.equal(sessions.size, 0, 'the expired session was swept');
  assert.match(
    logger.entries.find((entry) => entry.message === 'udp9090 bind-refused').fields.reason,
    /no completed register/
  );
});

test('activity refreshes a session so a slow player is not evicted mid-exchange', async (t) => {
  let now = 1_000_000;
  const sessions = new RegisterSessionTable({ ttlMs: 60_000, clock: () => now });
  const { client, service } = await registered(t, '12345', '1234567890', { sessions });

  now += 50_000;
  assert.equal((await collect(client, service, bindDatagram())).length, 2);
  now += 50_000; // 100s since register, but only 50s since the bind
  assert.equal((await collect(client, service, appAckDatagram())).length, 1);
});

test('the session table is bounded and refuses new sessions rather than evicting live ones', () => {
  const sessions = new RegisterSessionTable({ maximum: 2 });
  assert.ok(sessions.register({ address: '10.0.0.1', port: 2000, loginIdentity: 'a', endpointToken: 1 }));
  assert.ok(sessions.register({ address: '10.0.0.2', port: 2000, loginIdentity: 'b', endpointToken: 2 }));
  assert.equal(
    sessions.register({ address: '10.0.0.3', port: 2000, loginIdentity: 'c', endpointToken: 3 }),
    null,
    'a flood must not displace a real player'
  );
  // The existing ones survive and can still be resolved.
  assert.equal(sessions.resolve({ address: '10.0.0.1', port: 2000, endpointToken: 1 }).session.loginIdentity, 'a');
  // Re-registering an EXISTING source is a refresh, not a new session.
  assert.ok(sessions.register({ address: '10.0.0.1', port: 2000, loginIdentity: 'a', endpointToken: 1 }));
  assert.equal(sessions.size, 2);
});

test('a repeat register refreshes the session and counts the epoch', async (t) => {
  // The archived traces show the client re-registering for the game phase, so a
  // second register must refresh rather than be refused.
  const { client, service, logger } = await registered(t);
  await collect(client, service, registerDatagram());

  const replied = logger.entries.filter((entry) => entry.message === 'udp9090 register-replied');
  assert.equal(replied.length, 2);
  assert.equal(replied[0].fields.registerCount, 1);
  assert.equal(replied[1].fields.registerCount, 2);
  // And the bind still works after the re-register.
  assert.equal((await collect(client, service, bindDatagram())).length, 2);
});

test('a datagram cannot make the server emit more than one reply', async (t) => {
  // Without a cap, a coalesced datagram of app-ACKs produced one outbound
  // datagram per message - a 1000:1 fan-out from an authenticated but otherwise
  // ordinary source.
  const { client, service, logger } = await registered(t);
  await collect(client, service, bindDatagram());

  const one = appAckDatagram().subarray(0, 16);
  const many = Buffer.concat([one, one, one, one, DATAGRAM_TRAILER]);
  const replies = await collect(client, service, many);

  assert.equal(replies.length, 1, 'one datagram in, at most one datagram out');
  assert.ok(logger.entries.find((entry) => entry.message === 'udp9090 extra-message-ignored'));
});

test('a datagram stuffed with messages is ignored rather than walked', async (t) => {
  // Unauthenticated log amplification: 4000 unknown-opcode messages in one
  // datagram used to produce 4000 log lines.
  const { client, service, logger } = await fixture(t, accountsWith({}));
  const filler = Buffer.alloc(16);
  filler.writeUInt16BE(0xb010, 0x00);
  filler.writeUInt8(0x40, 0x03);
  const many = Buffer.concat([...Array(64).fill(filler), DATAGRAM_TRAILER]);

  assert.equal((await collect(client, service, many, { ms: 250 })).length, 0);
  const capped = logger.entries.find((entry) => entry.message === 'udp9090 datagram-message-cap');
  assert.ok(capped, 'the datagram is refused whole');
  assert.equal(capped.fields.messages, 64);
  assert.equal(
    logger.entries.filter((entry) => entry.message === 'udp9090 observed-message').length,
    0,
    'and no per-message work is done'
  );
});

/* ---- lobby arming ------------------------------------------------------- */

test('a completed bind arms the lobby with the SESSION identity', async (t) => {
  const armed = [];
  const logger = recordingLogger();
  const service = new SnapRegisterService({
    bindAddress: LOOPBACK,
    advertisedAddress: '192.0.2.121',
    accountRepository: accountsWith({ test123: 'secret42' }),
    logger,
    port: 0,
    onLobbyReady: (event) => armed.push(event)
  });
  await service.start();
  const client = dgram.createSocket('udp4');
  await new Promise((resolve) => client.bind(0, LOOPBACK, resolve));
  t.after(async () => {
    await new Promise((resolve) => client.close(resolve));
    await service.stop();
  });

  await collect(client, service, registerDatagram({ loginIdentity: 'test123' }));
  assert.deepEqual(armed, [], 'a register alone does not arm; V1 armed at the bind');

  await collect(client, service, bindDatagram({ identity: 'test123' }));
  assert.equal(armed.length, 1);
  assert.equal(armed[0].loginIdentity, 'test123');
  assert.equal(armed[0].address, LOOPBACK);
});

test('arming uses the authenticated identity, not the name the client sent', async (t) => {
  const armed = [];
  const logger = recordingLogger();
  const service = new SnapRegisterService({
    bindAddress: LOOPBACK,
    advertisedAddress: '192.0.2.121',
    accountRepository: accountsWith({ test123: 'secret42' }),
    logger,
    port: 0,
    onLobbyReady: (event) => armed.push(event)
  });
  await service.start();
  const client = dgram.createSocket('udp4');
  await new Promise((resolve) => client.bind(0, LOOPBACK, resolve));
  t.after(async () => {
    await new Promise((resolve) => client.close(resolve));
    await service.stop();
  });

  await collect(client, service, registerDatagram({ loginIdentity: 'test123' }));
  await collect(client, service, bindDatagram({ identity: 'someoneelse' }));

  assert.equal(armed.length, 1);
  assert.equal(armed[0].loginIdentity, 'test123', 'the endpoint name is not an authenticator');
});

test('a refused bind arms nothing', async (t) => {
  const armed = [];
  const logger = recordingLogger();
  const service = new SnapRegisterService({
    bindAddress: LOOPBACK,
    advertisedAddress: '192.0.2.121',
    accountRepository: accountsWith({ test123: 'secret42' }),
    logger,
    port: 0,
    onLobbyReady: (event) => armed.push(event)
  });
  await service.start();
  const client = dgram.createSocket('udp4');
  await new Promise((resolve) => client.bind(0, LOOPBACK, resolve));
  t.after(async () => {
    await new Promise((resolve) => client.close(resolve));
    await service.stop();
  });

  // No register first, so there is no session to inherit.
  await collect(client, service, bindDatagram(), { ms: 300 });
  assert.deepEqual(armed, [], 'an unauthenticated bind must not arm anything');
});

test('an arming failure does not cost the client its bind reply', async (t) => {
  const logger = recordingLogger();
  const service = new SnapRegisterService({
    bindAddress: LOOPBACK,
    advertisedAddress: '192.0.2.121',
    accountRepository: accountsWith({ 12345: '1234567890' }),
    logger,
    port: 0,
    onLobbyReady: () => {
      throw new Error('arming registry unavailable');
    }
  });
  await service.start();
  const client = dgram.createSocket('udp4');
  await new Promise((resolve) => client.bind(0, LOOPBACK, resolve));
  t.after(async () => {
    await new Promise((resolve) => client.close(resolve));
    await service.stop();
  });

  await collect(client, service, registerDatagram());
  const replies = await collect(client, service, bindDatagram());

  assert.equal(replies.length, 2, 'the ACK and push are sent regardless');
  assert.ok(logger.entries.find((entry) => entry.message === 'udp9090 lobby-arming-failed'));
});

test('the 570-byte post-lobby snapshot is ANSWERED, and never armed', async (t) => {
  /*
   * This test previously asserted the snapshot was not answered. That was the
   * assumption the 2026-08-06 T32 rig run disproved: the client sent opcode 0x01
   * at message length 0x236, V2 logged "observed, not answered", and 57 seconds
   * later it reset with error 840. V1 answered the same message in 38 archived
   * sessions and the client proceeded.
   *
   * The misreading was of V1's guard at `game_udp_server.js:2770-2776`, which
   * says do not ARM THE TCP LOBBY from this message - arming from it "leaves
   * stale pending entries that make the next TCP connect run the wrong state
   * machine". It says nothing about answering, and V1 does both (`:2985-2987`).
   * So the arming half of this test stands and the answering half is inverted.
   *
   * The wider behaviour lives in `test/udp-post-lobby-snapshot.test.js`,
   * including that opcode 0x01 at any OTHER length is still observed and not
   * answered.
   */
  const armed = [];
  const logger = recordingLogger();
  const service = new SnapRegisterService({
    bindAddress: LOOPBACK,
    advertisedAddress: '192.0.2.121',
    accountRepository: accountsWith({ 12345: '1234567890' }),
    logger,
    port: 0,
    onLobbyReady: (event) => armed.push(event)
  });
  await service.start();
  const client = dgram.createSocket('udp4');
  await new Promise((resolve) => client.bind(0, LOOPBACK, resolve));
  t.after(async () => {
    await new Promise((resolve) => client.close(resolve));
    await service.stop();
  });

  await collect(client, service, registerDatagram());

  // The game-phase form: opcode 0x01, message length 0x236, datagram 570.
  const gamePhase = Buffer.alloc(570);
  gamePhase.writeUInt16BE(0x3236, 0x00);
  gamePhase.writeUInt8(0x01, 0x03);
  gamePhase.writeUInt32BE(0x02f807d0, 0x04);
  gamePhase.subarray(0x10).write('12345-', 0x10, 'latin1');
  DATAGRAM_TRAILER.copy(gamePhase, 566);

  const replies = await collect(client, service, gamePhase, { ms: 300 });
  assert.equal(replies.length, 2, 'the transport ACK and the slot-0x1c push');
  assert.deepEqual(armed, [], 'and not armed');
  const snapshot = logger.entries.find((entry) => entry.message === 'udp9090 post-lobby-snapshot');
  assert.ok(snapshot);
  assert.equal(snapshot.fields.length, 0x236);
  assert.match(snapshot.fields.note, /does NOT arm the TCP lobby/);
  // No lobby subsystem is wired into this fixture, so nothing followed the push
  // - the post-selection phase is exercised in its own file.
  assert.ok(!logger.entries.some((entry) => entry.message === 'udp9090 lobby-session-opened'));

  // The real post-register bind still works.
  assert.equal((await collect(client, service, bindDatagram())).length, 2);
  assert.equal(armed.length, 1);
});

/* ---- T33: the attachment nonce, at the service boundary ---------------- */

/**
 * A bind that echoes a tail at body +0x24/+0x28, which is where the client's
 * `conn+0xa8`/`conn+0xac` land inside the 0x128-byte connection template.
 */
function bindDatagramEchoing(tail, options = {}) {
  const datagram = bindDatagram(options);
  const bodyStart = 0x10;
  if (tail != null) {
    datagram.writeUInt32BE(tail.length, bodyStart + 0x24);
    tail.copy(datagram, bodyStart + 0x28);
  }
  return datagram;
}

function nonceService({ logger, nonces = true, accounts = null, onLobbyReady = null }) {
  return new SnapRegisterService({
    bindAddress: LOOPBACK,
    advertisedAddress: '192.0.2.121',
    accountRepository: accounts ?? accountsWith({ 12345: '1234567890' }),
    logger,
    port: 0,
    registrationNonces: nonces,
    onLobbyReady
  });
}

async function startedNonceService(t, logger, nonces = true, options = {}) {
  const service = nonceService({ logger, nonces, ...options });
  await service.start();
  const client = dgram.createSocket('udp4');
  await new Promise((resolve) => client.bind(0, LOOPBACK, resolve));
  t.after(async () => {
    await new Promise((resolve) => client.close(resolve));
    await service.stop();
  });
  return { service, client };
}

test('with the nonce off the reply is byte-identical to every previous build', async (t) => {
  // The negative control, and the rollback. Off must mean tail length 0.
  const logger = recordingLogger();
  const { service, client } = await startedNonceService(t, logger, null);
  const replies = await collect(client, service, registerDatagram());
  assert.equal(replies.length, 1);
  const minted = logger.entries.find((entry) => entry.message === 'udp9090 register-replied');
  assert.equal(minted.fields.attachmentNonceSha256, null, 'nothing minted');
  assert.equal(service.registrationNonces, null);
});

test('with the nonce on, a 16-byte nonce is minted and reported per registration', async (t) => {
  const logger = recordingLogger();
  const { service, client } = await startedNonceService(t, logger);
  await collect(client, service, registerDatagram());
  const minted = logger.entries.filter((entry) => entry.message === 'udp9090 register-replied');
  assert.equal(minted.length, 1);
  assert.match(
    minted[0].fields.attachmentNonceSha256, /^[0-9a-f]{64}$/,
    'the journal carries the HASH, never the nonce itself'
  );
  assert.equal(service.registrationNonces.size, 1, 'and held pending');
});

test('a bind echoing the minted nonce is reported as matched', async (t) => {
  const logger = recordingLogger();
  const { service, client } = await startedNonceService(t, logger);
  await collect(client, service, registerDatagram());
  // The journal carries only the HASH now, so the test reads the nonce from the
  // service's own pending table - which is what a real bind would echo.
  const nonce = Buffer.from(
    [...service.registrationNonces.pendingNoncesForTest()][0], 'hex'
  );

  const replies = await collect(client, service, bindDatagramEchoing(nonce));
  assert.equal(replies.length, 2, 'still answered with the ACK and the push');
  const echoed = logger.entries.find((entry) => entry.message === 'udp9090 bind-tail-echoed');
  assert.ok(echoed, 'the echo is reported');
  assert.equal(echoed.fields.matched, true);
  assert.equal(echoed.fields.attachedHandle, '12345');
  assert.equal(
    echoed.fields.echoedNonceSha256,
    createHash('sha256').update(nonce).digest('hex'),
    'the echo is reported by hash so the two can be correlated without the secret'
  );
  assert.equal(echoed.fields.retransmission, false);
});

test('a bind echoing length 0 is reported distinctly from a truncated one', async (t) => {
  // This is what a client that does NOT echo the tail would produce, and it is
  // the outcome T33 exists to distinguish. It must not look like success.
  const logger = recordingLogger();
  const { service, client } = await startedNonceService(t, logger);
  await collect(client, service, registerDatagram());
  await collect(client, service, bindDatagram());
  assert.ok(
    logger.entries.find((entry) => entry.message === 'udp9090 bind-tail-empty'),
    'an all-zero tail is reported as empty, not as a match'
  );
  assert.equal(
    logger.entries.some((entry) => entry.message === 'udp9090 bind-tail-echoed'), false
  );
});

test('a bind echoing a nonce we never minted is reported unmatched', async (t) => {
  const logger = recordingLogger();
  const { service, client } = await startedNonceService(t, logger);
  await collect(client, service, registerDatagram());
  await collect(client, service, bindDatagramEchoing(Buffer.alloc(16, 0xee)));
  const echoed = logger.entries.find((entry) => entry.message === 'udp9090 bind-tail-echoed');
  assert.equal(echoed.fields.matched, false);
  assert.match(echoed.fields.refusal, /no pending registration/);
  // No handle is reported, because none was attached. Reporting the session's
  // own handle here would read like a match in a journal.
  assert.equal(echoed.fields.attachedHandle, undefined);
});

test('a bind declaring a tail longer than the client could hold is refused, not read', async (t) => {
  const logger = recordingLogger();
  const { service, client } = await startedNonceService(t, logger);
  await collect(client, service, registerDatagram());
  const datagram = bindDatagram();
  datagram.writeUInt32BE(0x1000, 0x10 + 0x24);
  await collect(client, service, datagram);
  const malformed = logger.entries.find((entry) => entry.message === 'udp9090 bind-tail-malformed');
  assert.ok(malformed, 'a client-declared length is validated before any slice');
  assert.equal(malformed.fields.declaredLength, 0x1000);
});

test('a registration that cannot mint a nonce is refused rather than answered', async (t) => {
  /*
   * Sending a reply whose nonce can never match would strand the client: it
   * would bind against a registration the server has no record of. Fail closed
   * at the register instead, where the client's own retry still applies.
   */
  const logger = recordingLogger();
  const full = new RegistrationNonceTable({ maximum: 0 });
  const { service, client } = await startedNonceService(t, logger, full);
  const replies = await collect(client, service, registerDatagram());
  assert.equal(replies.length, 0, 'no reply at all');
  const refused = logger.entries.find(
    (entry) => entry.message === 'udp9090 register-nonce-unavailable'
  );
  assert.equal(refused.fields.code, 'PENDING_CAPACITY');
  assert.equal(refused.fields.outcome, 'silent-drop');
});

/* ---- the attachment verdict the bind hands to composition --------------- */

test('a bind echoing the minted nonce reports a VERIFIED attachment', async (t) => {
  const logger = recordingLogger();
  const armed = [];
  const { service, client } = await startedNonceService(t, logger, true, {
    onLobbyReady: (event) => armed.push(event)
  });
  await collect(client, service, registerDatagram());
  const nonce = Buffer.from([...service.registrationNonces.pendingNoncesForTest()][0], 'hex');

  await collect(client, service, bindDatagramEchoing(nonce));
  assert.equal(armed.length, 1);
  assert.equal(armed[0].attachment.verified, true);
  assert.equal(armed[0].attachment.reason, BIND_ATTACHMENT.VERIFIED);
  assert.equal(armed[0].loginIdentity, '12345');
});

test('a bind that echoes nothing reports an UNVERIFIED attachment, and is still answered', async (t) => {
  // The bind's own reply is deliberately not gated on the echo: a client that
  // does not echo must still complete the exchange it always completed. What it
  // does not get is a verdict that can displace a live player.
  const logger = recordingLogger();
  const armed = [];
  const { service, client } = await startedNonceService(t, logger, true, {
    onLobbyReady: (event) => armed.push(event)
  });
  await collect(client, service, registerDatagram());
  const replies = await collect(client, service, bindDatagram());

  assert.equal(replies.length, 2, 'the ACK and push are unchanged');
  assert.equal(armed[0].attachment.verified, false);
  assert.equal(armed[0].attachment.reason, BIND_ATTACHMENT.TAIL_EMPTY);
});

test('with the nonce switched off, no bind can report a verified attachment', async (t) => {
  const logger = recordingLogger();
  const armed = [];
  const { service, client } = await startedNonceService(t, logger, null, {
    onLobbyReady: (event) => armed.push(event)
  });
  await collect(client, service, registerDatagram());
  await collect(client, service, bindDatagram());
  assert.equal(armed[0].attachment.verified, false);
  assert.equal(armed[0].attachment.reason, BIND_ATTACHMENT.NOT_CONFIGURED);
});

test('a nonce minted for ANOTHER account proves nothing for the one the bind claims', async (t) => {
  /*
   * The attack the handle check exists for. A holder of any account can mint a
   * nonce it can read - its own - and then register as somebody else from the
   * same socket, which is all it takes to make the register session name the
   * victim. Without the cross-check that readable nonce would "prove" the
   * victim's account and buy the attacker a displacement.
   *
   * The test reads the attacker's nonce from the pending table rather than
   * decrypting the reply; that is the same value the attacker's own password
   * would have yielded, and the crypto path is covered end to end in
   * composition.test.js.
   */
  const logger = recordingLogger();
  const armed = [];
  const { service, client } = await startedNonceService(t, logger, true, {
    accounts: accountsWith({ attacker: 'attackerpw', victim: 'victimpw' }),
    onLobbyReady: (event) => armed.push(event)
  });

  await collect(client, service, registerDatagram({ loginIdentity: 'attacker' }));
  const readable = Buffer.from([...service.registrationNonces.pendingNoncesForTest()][0], 'hex');

  // Same socket, now registering as the victim: the register session for this
  // address:port names 'victim' from here on.
  await collect(client, service, registerDatagram({ loginIdentity: 'victim' }));
  await collect(client, service, bindDatagramEchoing(readable, { identity: 'victim' }));

  assert.equal(armed.length, 1);
  assert.equal(armed[0].loginIdentity, 'victim', 'the session identity is still the victim');
  assert.equal(armed[0].attachment.verified, false, 'but nothing was proved about that account');
  assert.equal(armed[0].attachment.reason, BIND_ATTACHMENT.HANDLE_MISMATCH);
  const mismatch = logger.entries.find(
    (entry) => entry.message === 'udp9090 bind-tail-handle-mismatch'
  );
  assert.ok(mismatch, 'and it is logged as its own event, not as a generic miss');
  assert.equal(mismatch.fields.attachedHandle, 'attacker');
});

test('two arming sources merge rather than overwrite each other', async () => {
  const { LobbyArmingRegistry } = await import('../src/sessions/lobby-arming.js');
  const registry = new LobbyArmingRegistry();
  registry.arm('10.0.0.1', { sessionConnectionId: 'abc', userid: 'someone' });
  const merged = registry.arm('10.0.0.1', { userid: 'someone', source: 'udp9090-bind' });

  assert.equal(merged.sessionConnectionId, 'abc', 'the HTTP path record is not dropped');
  assert.equal(merged.source, 'udp9090-bind');
});
