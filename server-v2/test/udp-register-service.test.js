import test from 'node:test';
import assert from 'node:assert/strict';
import dgram from 'node:dgram';

import { SnapRegisterService } from '../src/udp/register-service.js';
import {
  DATAGRAM_TRAILER,
  decodeSnapUdpDatagram
} from '../src/protocol/snap-udp-register-codec.js';
import { blowfishEcbDecrypt, createBlowfishKey } from '../src/crypto/blowfish.js';

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

/** An account store with exactly the one method the service depends on. */
function accountsWith(map, { throwFor = null } = {}) {
  return {
    getCompatibilitySecretByLoginIdentity(userid) {
      if (throwFor && userid === throwFor) throw new Error('unable to authenticate data');
      return map[userid] ?? null;
    }
  };
}

function registerDatagram({ loginIdentity = '12345', auth, token = 0x02f807d0 } = {}) {
  const datagram = Buffer.alloc(154);
  datagram.writeUInt16BE(0x3096, 0x00);
  datagram.writeUInt8(0x2c, 0x03);
  datagram.writeUInt32BE(token, 0x04);
  const body = datagram.subarray(0x10);
  body.write(loginIdentity, 0x00, 'latin1');
  body.write(auth ?? `${loginIdentity}@cee-auth`, 0x28, 'latin1');
  body.writeUInt32BE(0xcaf3, 0x64);
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

/** Start the service on an ephemeral port plus a client socket to drive it. */
async function fixture(t, accounts, { port = 0 } = {}) {
  const logger = recordingLogger();
  const service = new SnapRegisterService({
    bindAddress: LOOPBACK,
    advertisedAddress: '192.0.2.121',
    accountRepository: accounts,
    logger,
    port
  });
  await service.start();
  const client = dgram.createSocket('udp4');
  await new Promise((resolve) => client.bind(0, LOOPBACK, resolve));
  t.after(async () => {
    await new Promise((resolve) => client.close(resolve));
    await service.stop();
  });
  return { service, client, logger, port: service.address().port };
}

/** Send one datagram and wait for a reply, or resolve null after a timeout. */
function exchange(client, service, datagram, { timeoutMs = 400 } = {}) {
  return new Promise((resolve) => {
    const timer = setTimeout(() => {
      client.removeListener('message', onMessage);
      resolve(null);
    }, timeoutMs);
    function onMessage(reply, remote) {
      clearTimeout(timer);
      client.removeListener('message', onMessage);
      resolve({ reply, remote });
    }
    client.on('message', onMessage);
    client.send(datagram, service.address().port, LOOPBACK);
  });
}

test('binds and closes cleanly, and refuses a wildcard bind address', async (t) => {
  const { service, port } = await fixture(t, accountsWith({}));
  assert.ok(port > 0);
  assert.equal(service.address().address, LOOPBACK);

  // The client discards any reply whose source address is not exactly the one
  // it registered against, so a wildcard bind is refused at construction.
  for (const bindAddress of ['0.0.0.0', '::', '', undefined]) {
    assert.throws(
      () =>
        new SnapRegisterService({
          bindAddress,
          advertisedAddress: '192.0.2.121',
          accountRepository: accountsWith({}),
          logger: recordingLogger()
        }),
      /specific bind address|required/
    );
  }
});

test('stop() is idempotent and a second start() is refused', async (t) => {
  const { service } = await fixture(t, accountsWith({}));
  await assert.rejects(() => service.start(), /already started/);
  await service.stop();
  await service.stop();
  assert.equal(service.address(), null);
});

test('answers a known account with a reply its own password decrypts', async (t) => {
  const { client, service, logger } = await fixture(t, accountsWith({ 12345: '1234567890' }));

  const result = await exchange(client, service, registerDatagram());
  assert.ok(result, 'a known account must be answered');
  const { reply } = result;

  assert.equal(reply.length, 154);
  assert.equal(reply.readUInt16BE(0x00), 0xb096);
  assert.equal(reply.readUInt8(0x03), 0x2d);
  assert.equal(reply.readUInt32BE(0x04), 0x02f807d0, 'the request token is echoed');
  assert.equal(reply.readUInt32BE(0x08), 0);
  assert.equal(reply.subarray(150).toString('hex'), 'ba476611');

  // The client's own check: decrypt with the password it holds and strcmp the
  // plaintext against the identity it sent. That comparison IS the auth.
  const plaintext = blowfishEcbDecrypt(
    createBlowfishKey('1234567890'),
    reply.subarray(0x10, 0x90)
  );
  const recovered = plaintext.subarray(0, plaintext.indexOf(0)).toString('latin1');
  assert.equal(recovered, '12345');
  assert.equal(plaintext.readUInt32BE(0x28).toString(16), 'c0000279', 'advertised server IPv4');
  assert.equal(plaintext.readUInt32BE(0x30), service.address().port, 'port applied immediately');
  assert.equal(plaintext.readUInt32BE(0x2c), 0, 'port at bind stays 0');

  // Our own framing decoder accepts what we put on the wire.
  assert.equal(decodeSnapUdpDatagram(reply)[0].opcode, 0x2d);

  const replied = logger.entries.find((entry) => entry.message === 'udp9090 register-replied');
  assert.ok(replied, 'the accepted outcome is logged');
  assert.equal(replied.fields.outcome, 'accepted');
  assert.equal(replied.fields.loginIdentity, '12345');
  assert.equal(replied.fields.endpointToken, '0x02f807d0');
  assert.equal(replied.fields.tlvs, 'LC=1600,MR=48');
});

test('the wrong password produces a body the client would reject', async (t) => {
  const { client, service } = await fixture(t, accountsWith({ 12345: 'not-the-password' }));
  const { reply } = await exchange(client, service, registerDatagram());

  const plaintext = blowfishEcbDecrypt(
    createBlowfishKey('1234567890'),
    reply.subarray(0x10, 0x90)
  );
  // The client would fail its strcmp and raise {status 1, code 0x13} locally.
  assert.notEqual(plaintext.subarray(0, 5).toString('latin1'), '12345');
});

test('an unknown account is dropped silently, and the reason is logged', async (t) => {
  const { client, service, logger } = await fixture(t, accountsWith({ 12345: '1234567890' }));

  const result = await exchange(client, service, registerDatagram({ loginIdentity: 'nobody' }));
  assert.equal(result, null, 'silence is the documented path, not a 0x31 reject');

  const refused = logger.entries.find((entry) => entry.message === 'udp9090 register-refused');
  assert.ok(refused);
  assert.equal(refused.fields.outcome, 'silent-drop');
  assert.match(refused.fields.reason, /no account/);
  assert.equal(refused.fields.loginIdentity, 'nobody');
});

test('an unsealable secret is reported as a server fault, not a missing account', async (t) => {
  const accounts = accountsWith({ 12345: '1234567890' }, { throwFor: '12345' });
  const { client, service, logger } = await fixture(t, accounts);

  const result = await exchange(client, service, registerDatagram());
  assert.equal(result, null);
  const entry = logger.entries.find(
    (item) => item.message === 'udp9090 register-secret-unsealable'
  );
  assert.ok(entry, 'a vault failure must not be logged as an unknown account');
  assert.equal(entry.level, 'error');
});

test('malformed and truncated datagrams are dropped without a reply', async (t) => {
  const { client, service, logger } = await fixture(t, accountsWith({ 12345: '1234567890' }));

  const badTrailer = registerDatagram();
  badTrailer.writeUInt8(0x00, 150);
  const truncated = registerDatagram().subarray(0, 40);
  const tooShort = Buffer.alloc(8);

  for (const datagram of [badTrailer, truncated, tooShort]) {
    assert.equal(await exchange(client, service, datagram, { timeoutMs: 200 }), null);
  }
  assert.ok(
    logger.entries.filter((entry) => entry.message === 'udp9090 framing-rejected').length >= 3
  );

  // And the service is still healthy afterwards.
  assert.ok(await exchange(client, service, registerDatagram()));
});

test("the client's transport ACK is consumed and never answered", async (t) => {
  const { client, service, logger } = await fixture(t, accountsWith({}));

  // Exactly as captured: `60 10 00 00 02 f8 07 d0 ...` - who 0x6010, opcode 0.
  const ack = Buffer.alloc(20);
  ack.writeUInt16BE(0x6010, 0x00);
  ack.writeUInt32BE(0x02f807d0, 0x04);
  DATAGRAM_TRAILER.copy(ack, 16);

  // Acking an ack is how a loop starts.
  assert.equal(await exchange(client, service, ack, { timeoutMs: 200 }), null);
  assert.ok(
    logger.entries.find((entry) => entry.message === 'udp9090 transport-ack-received')
  );
});

test('an opcode we do not implement is observed, not answered', async (t) => {
  const { client, service, logger } = await fixture(t, accountsWith({}));

  // The 570-byte second 0x01 of the game phase is out of scope; use another
  // unimplemented opcode to prove the observe-only path still exists.
  const other = Buffer.alloc(20);
  other.writeUInt16BE(0xb010, 0x00);
  other.writeUInt8(0x40, 0x03);
  other.writeUInt32BE(0x02f807d0, 0x04);
  DATAGRAM_TRAILER.copy(other, 16);

  assert.equal(await exchange(client, service, other, { timeoutMs: 200 }), null);
  const observed = logger.entries.find((entry) => entry.message === 'udp9090 observed-message');
  assert.ok(observed);
  assert.equal(observed.fields.opcode, '0x40');
});

test('the login identity is looked up as a trimmed C string', async (t) => {
  const { client, service, logger } = await fixture(t, accountsWith({ test123: 'secret42' }));
  const result = await exchange(client, service, registerDatagram({ loginIdentity: 'test123' }));

  assert.ok(result, 'the 40-byte NUL padding must not reach the lookup');
  const replied = logger.entries.find((entry) => entry.message === 'udp9090 register-replied');
  assert.equal(replied.fields.loginIdentity, 'test123');
});

test('an unexpected auth form is recorded but never gated on', async (t) => {
  const { client, service, logger } = await fixture(t, accountsWith({ 12345: '1234567890' }));
  const result = await exchange(
    client,
    service,
    registerDatagram({ loginIdentity: '12345', auth: '12345@something-else' })
  );

  // The documented alternative form is identity + DNAS blob; refusing it would
  // break a path we have never captured. So: log it, answer anyway.
  assert.ok(result, 'an unexpected auth form must still be answered');
  assert.ok(
    logger.entries.find((entry) => entry.message === 'udp9090 register-auth-unexpected-form')
  );
});

test('handles two clients independently in one epoch', async (t) => {
  const accounts = accountsWith({ 12345: '1234567890', test123: 'secret42' });
  const { client, service } = await fixture(t, accounts);

  const first = await exchange(client, service, registerDatagram({ loginIdentity: '12345' }));
  const second = await exchange(
    client,
    service,
    registerDatagram({ loginIdentity: 'test123', token: 0x02f907d1 })
  );

  assert.equal(first.reply.readUInt32BE(0x04), 0x02f807d0);
  assert.equal(second.reply.readUInt32BE(0x04), 0x02f907d1, 'each reply echoes its own token');

  const firstPlain = blowfishEcbDecrypt(
    createBlowfishKey('1234567890'),
    first.reply.subarray(0x10, 0x90)
  );
  const secondPlain = blowfishEcbDecrypt(
    createBlowfishKey('secret42'),
    second.reply.subarray(0x10, 0x90)
  );
  assert.equal(firstPlain.subarray(0, 5).toString('latin1'), '12345');
  assert.equal(secondPlain.subarray(0, 7).toString('latin1'), 'test123');
});

test('a retried register is answered again, identically', async (t) => {
  // The connect screen retries up to three times when no reply arrives, so a
  // duplicate must be idempotent rather than treated as a protocol violation.
  const { client, service } = await fixture(t, accountsWith({ 12345: '1234567890' }));
  const first = await exchange(client, service, registerDatagram());
  const second = await exchange(client, service, registerDatagram());
  assert.equal(first.reply.toString('hex'), second.reply.toString('hex'));
});

/**
 * `FUN_001d72a8` discards any datagram whose source IP:port do not exactly match
 * the serverIP:9090 the client registered against. This is the single easiest
 * way to make correct crypto look broken, so assert the observable directly:
 * the reply must arrive FROM the bound address and the register port.
 */
test('the reply leaves from exactly the address and port the client registered against', async (t) => {
  const { client, service } = await fixture(t, accountsWith({ 12345: '1234567890' }));
  const { remote } = await exchange(client, service, registerDatagram());

  assert.equal(remote.address, LOOPBACK, 'source IP must be the bound interface address');
  assert.equal(remote.port, service.address().port, 'source port must be the register port');
});

test('mirrors the request tail into the six filler bytes, as the accepted reply did', async (t) => {
  // V1 built its reply as a copy of the request, so wire 0x90..0x95 carried the
  // request's own tail. The client never reads them, but matching the datagram
  // that is PROVEN accepted beats being merely spec-equivalent.
  const { client, service } = await fixture(t, accountsWith({ 12345: '1234567890' }));
  const request = registerDatagram();
  const { reply } = await exchange(client, service, request);

  assert.equal(
    reply.subarray(0x90, 0x96).toString('hex'),
    request.subarray(0x90, 0x96).toString('hex')
  );
  // The captured request's tail is the MR TLV value 48 followed by the trailer's
  // first two bytes, exactly as the archived accepted reply carried.
  assert.equal(reply.subarray(0x90, 0x96).toString('hex'), '4d5200000030');
});

test('answers only the first register in a coalesced datagram', async (t) => {
  const { client, service, logger } = await fixture(t, accountsWith({ 12345: '1234567890' }));
  const one = registerDatagram().subarray(0, 0x96);
  const datagram = Buffer.concat([one, one, DATAGRAM_TRAILER]);

  const replies = [];
  client.on('message', (reply) => replies.push(reply));
  client.send(datagram, service.address().port, LOOPBACK);
  await new Promise((resolve) => setTimeout(resolve, 400));

  assert.equal(replies.length, 1, 'one datagram in, one datagram out');
  assert.ok(
    logger.entries.find((entry) => entry.message === 'udp9090 extra-message-ignored')
  );
});

test('a bind failure leaves no socket behind and the port free', async (t) => {
  const first = new SnapRegisterService({
    bindAddress: LOOPBACK,
    advertisedAddress: '192.0.2.121',
    accountRepository: accountsWith({}),
    logger: recordingLogger(),
    port: 0
  });
  await first.start();
  const takenPort = first.address().port;

  const second = new SnapRegisterService({
    bindAddress: LOOPBACK,
    advertisedAddress: '192.0.2.121',
    accountRepository: accountsWith({}),
    logger: recordingLogger(),
    port: takenPort
  });
  await assert.rejects(() => second.start(), /EADDRINUSE/);
  assert.equal(second.address(), null, 'no socket is left behind a failed bind');
  await assert.doesNotReject(() => second.stop());

  await first.stop();
  // The port is genuinely free again, so the composed rollback really rolls back.
  const third = new SnapRegisterService({
    bindAddress: LOOPBACK,
    advertisedAddress: '192.0.2.121',
    accountRepository: accountsWith({}),
    logger: recordingLogger(),
    port: takenPort
  });
  await third.start();
  assert.equal(third.address().port, takenPort);
  await third.stop();
});
