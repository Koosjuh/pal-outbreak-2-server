import assert from 'node:assert/strict';
import crypto from 'node:crypto';
import dgram from 'node:dgram';
import fs from 'node:fs';
import net from 'node:net';
import os from 'node:os';
import path from 'node:path';
import test from 'node:test';

import { createApplication } from '../src/app/application.js';
import { loadServerConfig } from '../src/config/server-config.js';
import { createLogger } from '../src/logging/logger.js';
import { blowfishEcbDecrypt, createBlowfishKey } from '../src/crypto/blowfish.js';
import { ACCOUNT_PROOF } from '../src/sessions/account-session.js';
import { encodeSnapField } from '../src/protocol/snap-field-codec.js';
import { DIRECTORY_PROVENANCE, createDirectoryState } from '../src/state/directory-state.js';
import { parseDirectoryDocument } from '../src/state/directory-source.js';
import { createV1ObservedAreaTable } from '../src/state/area-table-v1.js';

/**
 * Integration tests over the composed application.
 *
 * Everything here comes from V2 state and validated configuration. No V1
 * constant appears: not `SLOT0001`, not `OPEN`, not `Test Slot`, and no codec
 * byte other than the one the connection actually holds.
 */

const MASTER_KEY = Buffer.alloc(32, 7).toString('base64');

/** An operator-shaped directory document with neutral opaque values. */
function directoryDocument({ provenance = DIRECTORY_PROVENANCE.OPERATOR } = {}) {
  return {
    provenance,
    // These composed tests need OPERATOR provenance (production refuses a
    // test-fixture directory), but they carry rig-shaped values - a private
    // host, placeholder keys. Declaring the rig boundary is the honest way to
    // say so, and it keeps the production gate armed for everything else.
    rigFixture: true,
    entries: [{
      entryId: 'entry-0',
      host: '10.0.0.1',
      name: 'E0',
      raw8: { hex: '0000000000000000' },
      description: 'test entry',
      pageField: 'ENTRY0',
      command6502Unknown0: 0x2a,
      command6502Unknown1: 0x2b,
      records: [{
        recordId: 'record-0',
        unknownField0: 'E0R0',
        unknownField1: 'F1',
        unknownRaw8: { hex: '0102030405060708' },
        unknownField2: 'DETAIL',
        unknownWord0: 0x0102,
        unknownWord1: 0x0304,
        unknownDword: 0x05060708,
        unknownWord6510: 0x0009
      }]
    },
    /*
     * A SECOND ENTRY, because `createApplication` now refuses a one-entry
     * directory: `FUN_00606fc0` substate 1 auto-selects entry 1 below a count of
     * 2 and never draws the list, so a one-entry directory is a Server Select
     * the player cannot use. The shipped `config/directory.example.json` said so
     * already; nothing enforced it, and these composed tests ran on exactly the
     * shape it warned against.
     *
     * It is deliberately the SMALLEST entry that satisfies the rules - one
     * record, distinct host and name - so the walk assertions below still
     * describe entry-0's records and are not re-tuned to a fixture change.
     */
    {
      entryId: 'entry-1',
      host: '10.0.0.2',
      name: 'E1',
      raw8: { hex: '0000000000000000' },
      description: 'second test entry',
      pageField: 'ENTRY1',
      command6502Unknown0: 0,
      command6502Unknown1: 0,
      records: [{
        recordId: 'record-1',
        unknownField0: 'E1R0',
        unknownField1: 'F1',
        unknownRaw8: { hex: '0000000000000000' },
        unknownField2: 'DETAIL',
        unknownWord0: 0,
        unknownWord1: 0x0304,
        unknownDword: 0,
        unknownWord6510: 0
      }]
    }]
  };
}

function makeEnvironment(directory = directoryDocument()) {
  const root = fs.mkdtempSync(path.join(os.tmpdir(), 'pal-v2-'));
  const directoryFile = path.join(root, 'directory.json');
  fs.writeFileSync(directoryFile, JSON.stringify(directory), 'utf8');
  return {
    root,
    directoryFile,
    env: {
      PAL_V2_MASTER_KEY: MASTER_KEY,
      PAL_V2_DATA_DIR: path.join(root, 'data'),
      PAL_V2_SELF_HOST: '127.0.0.1',
      PAL_V2_SNAP_HOST: '127.0.0.1',
      PAL_V2_DIRECTORY_FILE: directoryFile,
      PAL_V2_LOBBY_NAME: 'V2 TEST LOBBY',
      PAL_V2_BIND_HOST: '127.0.0.1',
      PAL_V2_ENABLE_DNS: 'false',
      PAL_V2_ENABLE_DNAS: 'false',
      PAL_V2_HTTP_PORT: '0',
      PAL_V2_TCP_PORT: '0',
      PAL_V2_UDP_REGISTER_PORT: '0',
      PAL_V2_LOG_LEVEL: 'error'
    }
  };
}

/** Windows keeps sqlite files locked briefly after close; never fail a test on it. */
function removeTree(root) {
  try {
    fs.rmSync(root, { recursive: true, force: true, maxRetries: 5, retryDelay: 50 });
  } catch {
    // Temporary directory cleanup is not what any of these tests assert.
  }
}

function silentLogger(records = []) {
  return createLogger({
    level: 'debug',
    write: (line) => records.push(JSON.parse(line))
  });
}

async function startApplication(t, overrides = {}, directory = directoryDocument()) {
  const { root, env } = makeEnvironment(directory);
  const config = loadServerConfig({ ...env, ...overrides });
  const records = [];
  const application = createApplication({ config, logger: silentLogger(records) });
  t.after(async () => {
    await application.stop();
    removeTree(root);
  });
  await application.start();
  return { application, config, records, root };
}

// ---- HTTP helpers ------------------------------------------------------

function httpRequest(port, method, target, body = null) {
  return new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port }, () => {
      const payload = body == null ? '' : body;
      socket.write(
        `${method} ${target} HTTP/1.1\r\n` +
        'Host: 127.0.0.1\r\n' +
        (body == null
          ? ''
          : 'Content-Type: application/x-www-form-urlencoded\r\n' +
            `Content-Length: ${Buffer.byteLength(payload)}\r\n`) +
        'Connection: close\r\n\r\n' +
        payload
      );
    });
    const chunks = [];
    socket.on('data', (chunk) => chunks.push(chunk));
    socket.on('end', () => resolve(Buffer.concat(chunks).toString('latin1')));
    socket.on('error', reject);
  });
}

function newDnasToken() {
  return crypto.randomBytes(32).toString('base64');
}

/** Walk the captured browser flow, ending with a session bound to the token. */
async function authenticate(port, { userid, password, dnasToken }) {
  const index = await httpRequest(port, 'GET', `/mhweb/index.jsp?DNAS=${encodeURIComponent(dnasToken)}`);
  assert.match(index, /create\.jsp\?DNAS=/, 'the index page must carry the token forward');
  const created = await httpRequest(
    port,
    'POST',
    `/mhweb/create.jsp?DNAS=${encodeURIComponent(dnasToken)}`,
    `userid=${userid}&password=${password}`
  );
  const sessionId = /sessid=(\d+)/.exec(created)?.[1] ?? null;
  assert.notEqual(sessionId, null, `account creation failed: ${created.slice(-200)}`);

  // The captured client then opens the game-start page and posts to lbs.jsp,
  // which is what hands it the SN@P endpoint. That completed POST is also what
  // arms the address for the lobby transcript (T20); without it the next TCP
  // 10127 connection is a boot-auth connection and receives 0x1001/0x1002/0x1004.
  await httpRequest(port, 'GET', `/mhweb/startsession?sessid=${sessionId}`);
  const lbs = await httpRequest(
    port, 'POST', '/mhweb/lbs.jsp', `connection-id=${sessionId}`
  );
  assert.match(lbs, /CRS-LBS-INFO-GET/, `lbs.jsp failed: ${lbs.slice(-200)}`);
  return sessionId;
}

// ---- TCP ladder --------------------------------------------------------

const CODEC_BYTE = 0;
// The area table the TCP service defaults to, so the expected reply length below
// stays derived from the table rather than remembered.
const AREA_TABLE = createV1ObservedAreaTable();

function frame({ direction = 1, command, sequence, unknown7 = 0xff, payload = Buffer.alloc(0) }) {
  const header = Buffer.alloc(8);
  header.writeUInt16BE(payload.length, 0);
  header[2] = direction;
  header.writeUInt16BE(command, 3);
  header[5] = sequence;
  header[6] = 0;
  header[7] = unknown7;
  return Buffer.concat([header, payload]);
}

/** The captured 0x1007 request shape, carrying a chosen DNAS token. */
function lobbyInitRequest(dnasToken, sequence = 0xcf) {
  const payload = Buffer.concat([
    Buffer.from([0x01]),
    encodeSnapField({
      plain: Buffer.from(dnasToken, 'latin1'),
      maximumDecodedLength: 44,
      sequence,
      unknownCodecByte: CODEC_BYTE
    })
  ]);
  return frame({ command: 0x1007, sequence, payload });
}

function command6510Request(key, sequence = 0xd8) {
  const payload = Buffer.concat([
    Buffer.from([1]),
    encodeSnapField({
      plain: Buffer.from(key, 'latin1'),
      maximumDecodedLength: 0x0f,
      sequence,
      unknownCodecByte: CODEC_BYTE
    }),
    Buffer.from('000258d8', 'hex')
  ]);
  return frame({ command: 0x6510, sequence, payload });
}

function ladderRequests(dnasToken) {
  return [
    lobbyInitRequest(dnasToken),
    frame({ command: 0x6103, sequence: 0xd0 }),
    frame({ command: 0x6212, sequence: 0xd1 }),
    frame({ command: 0x6203, sequence: 0xd2, payload: Buffer.from('000252d2', 'hex') }),
    frame({ command: 0x6211, sequence: 0xd3 }),
    frame({ command: 0x6213, sequence: 0xd4 }),
    frame({ command: 0x6501, sequence: 0xd5, payload: Buffer.alloc(4) }),
    // The mode-1 route: FUN_001c7000 asks for entries [0x365e18, 0x365e1a) and
    // the mode-1 0x6501 reply just set that count to 8. Sequence 0xda is
    // synthetic - no capture contains a 0x6503 - and is outside the captured
    // 0xcf..0xd9 run so it cannot be mistaken for one.
    frame({ command: 0x6503, sequence: 0xda, payload: Buffer.from('00000008', 'hex') }),
    // ONE 0x6502/0x6504 PAIR PER ENTRY. The client asks again for as long as
    // entries remain (`FUN_001c7a70`'s tail, routing back to the 0x6502 builder
    // while `0x365e0c < 0x365e1e`), and the directory holds two entries because
    // a one-entry Server Select is auto-selected and never drawn.
    ...directoryDocument().entries.flatMap(() => [
      frame({ command: 0x6502, sequence: 0xd6, payload: Buffer.from('00000000000257d7', 'hex') }),
      frame({ command: 0x6504, sequence: 0xd7, payload: Buffer.from('00000008000258d8', 'hex') })
    ]),
    ...directoryDocument().entries.map((entry) =>
      command6510Request(entry.records[0].unknownField0)),
    frame({ command: 0x1004, sequence: 0xd9 })
  ];
}

/**
 * How many response bytes a complete ladder is, derived from the fixture above
 * rather than remembered.
 *
 * Every frame is an 8-byte header plus its payload, and every encoded field is
 * `[BE16 length+2][BE16 checksum][plaintext]`, i.e. 4 + plaintext. Re-derived
 * for T32, when the 0x6501 mode became 1, a 0x6503 exchange appeared, and the
 * 0x6510 trailer became the entry host (8 bytes) rather than `pageField` (6).
 */
const LOBBY_CHALLENGE_LENGTH = 8;
const FIELD_OVERHEAD = 4;
const HEADER = 8;
/** One entry's record batch: total/start/count, four encoded fields, three words. */
function command6504Length(record) {
  return HEADER + 5 +
    (FIELD_OVERHEAD + record.unknownField0.length) +              //   unknownField0
    (FIELD_OVERHEAD + record.unknownField1.length) +              //   unknownField1
    8 +                                                           //   unknownRaw8
    (FIELD_OVERHEAD + record.unknownField2.length) +              //   unknownField2
    8;                                                            //   two BE16 + one BE32
}

/*
 * Named per command, because a RESUMED connection replays only the tail of this
 * list and composing both totals from the same parts is what stops the two
 * drifting apart.
 */
const REPLY_LENGTH = Object.freeze({
  command1007: HEADER + 1,
  command6103: HEADER + 2,
  command6212: HEADER,
  /*
   * Mode byte, the area-table version field, and the one-chunk table.
   *
   * These ladders then go straight to 0x6211, the cache-hit branch
   * FUN_001c4960.c:46-49 takes when the version matches what the client already
   * holds. The seven-slice 0x6204 transfer is walked over a real socket in
   * tcp10127-state-backed-ladder.test.js and byte-exactly against V1's own wire
   * in tcp10127-lobby-initialization.test.js.
   */
  command6203: HEADER + 1 + (FIELD_OVERHEAD + AREA_TABLE.version.length) + 2 + 4,
  command6211: HEADER,
  command6213: HEADER,
  command6501: HEADER + 9,                                        // mode 1 + two BE32
  /*
   * EVERY entry, summed from the fixture rather than written out: the batch is
   * `[0,8)` so all of them come back in one reply, and the directory now holds
   * two because a one-entry directory is refused at startup (the client
   * auto-selects below a count of 2 and never draws the list).
   */
  command6503: HEADER + 5 +                                       // total/start/count
    directoryDocument().entries.reduce((sum, entry) =>
      sum +
      (FIELD_OVERHEAD + entry.host.length) +                      //   entry host
      (FIELD_OVERHEAD + entry.name.length) +                      //   entry name
      8 +                                                         //   entry raw8
      (FIELD_OVERHEAD + entry.description.length), 0),            //   entry description
  command6502: HEADER + 9,                                        // mode 1 + two BE32
  // ONE PER ENTRY: the walk visits every entry and each entry's records come
  // back in their own 0x6504 batch, so a two-entry directory is two of these.
  command6504: directoryDocument().entries.map((entry) => command6504Length(entry.records[0])),
  /*
   * ALSO ONE PER ENTRY. The key exchange walks the entries in turn - answering
   * one entry's keys advances `entryIndex` and only the last one reaches
   * COMPLETE - so a two-entry directory takes two 0x6510 round trips before a
   * resume can rewind the projection. That was unreachable while the client
   * could not walk past entry 0.
   */
  command6510: directoryDocument().entries.map((entry) =>
    HEADER + 1 + 2 + (FIELD_OVERHEAD + entry.host.length)),
  command1004: HEADER
});
const LADDER_RESPONSE_LENGTH =
  LOBBY_CHALLENGE_LENGTH +                                        // 0x6001 challenge, no payload
  REPLY_LENGTH.command1007 +
  REPLY_LENGTH.command6103 +
  REPLY_LENGTH.command6212 +
  REPLY_LENGTH.command6203 +
  REPLY_LENGTH.command6211 +
  REPLY_LENGTH.command6213 +
  REPLY_LENGTH.command6501 +
  REPLY_LENGTH.command6503 +
  // A 0x6502/0x6504 pair PER ENTRY. `FUN_001c7a70`'s tail routes back to the
  // 0x6502 builder while entries remain, and that branch became reachable only
  // when 0x6503 started declaring a total above one.
  REPLY_LENGTH.command6504.reduce((sum, length) => sum + REPLY_LENGTH.command6502 + length, 0) +
  REPLY_LENGTH.command6510.reduce((sum, length) => sum + length, 0) +
  REPLY_LENGTH.command1004;

function walkLadder(port, dnasToken, { fragment = false } = {}) {
  return new Promise((resolve, reject) => {
    const requests = Buffer.concat(ladderRequests(dnasToken));
    const socket = net.createConnection({ host: '127.0.0.1', port }, () => {
      if (fragment) {
        for (const byte of requests) socket.write(Buffer.from([byte]));
      } else {
        socket.write(requests);
      }
    });
    let bytes = Buffer.alloc(0);
    socket.on('data', (chunk) => {
      bytes = Buffer.concat([bytes, chunk]);
      if (bytes.length >= LADDER_RESPONSE_LENGTH) {
        socket.destroy();
        resolve(bytes);
      }
    });
    socket.on('close', () => resolve(bytes));
    socket.on('error', reject);
  });
}

// ---- tests -------------------------------------------------------------

test('starts every configured listener and shuts down cleanly', async (t) => {
  const { application, records } = await startApplication(t);
  assert.equal(application.running, true);
  const addresses = application.addresses();
  assert.ok(addresses.tcp.port > 0);
  assert.ok(addresses.http.port > 0);
  assert.equal(addresses.dns, null, 'DNS was disabled by configuration');
  assert.equal(addresses.dnas, null, 'DNAS was disabled by configuration');

  const startedListeners = records
    .filter((record) => record.event === 'listener-started')
    .map((record) => record.listener);
  assert.deepEqual(startedListeners, ['tcp10127', 'http', 'udp9090']);

  await application.stop();
  assert.equal(application.running, false);
  assert.ok(records.some((record) => record.event === 'stopped'));
  // The ports really are released.
  await assert.doesNotReject(async () => {
    const probe = net.createServer();
    await new Promise((resolve, reject) => {
      probe.once('error', reject);
      probe.listen(addresses.http.port, '127.0.0.1', resolve);
    });
    await new Promise((resolve) => probe.close(resolve));
  });
});

test('a listener that cannot bind fails the whole process, leaving nothing up', async (t) => {
  // Occupy the HTTP port so the second listener in the plan cannot bind.
  const blocker = net.createServer();
  const blockedPort = await new Promise((resolve, reject) => {
    blocker.once('error', reject);
    blocker.listen(0, '127.0.0.1', () => resolve(blocker.address().port));
  });
  t.after(() => new Promise((resolve) => blocker.close(resolve)));

  const { root, env } = makeEnvironment();
  t.after(() => removeTree(root));
  const config = loadServerConfig({ ...env, PAL_V2_HTTP_PORT: String(blockedPort) });
  const records = [];
  const application = createApplication({ config, logger: silentLogger(records) });

  await assert.rejects(
    () => application.start(),
    (error) => error.code === 'LISTENER_BIND_FAILED' && error.listener === 'http'
  );
  assert.equal(application.running, false);
  // The TCP listener that DID bind was rolled back rather than left serving.
  assert.equal(application.addresses().tcp, null);
  assert.ok(records.some((record) => record.event === 'listener-stopped'));
});

test('refuses to start from a test-provenance directory', async (t) => {
  const { root, env } = makeEnvironment(
    directoryDocument({ provenance: DIRECTORY_PROVENANCE.TEST_FIXTURE })
  );
  t.after(() => removeTree(root));
  const config = loadServerConfig(env);
  assert.throws(
    () => createApplication({ config, logger: silentLogger() }),
    /refusing to serve a test-fixture directory/
  );
});

test('binds a DNAS token at login and associates the TCP connection with it', async (t) => {
  const { application } = await startApplication(t);
  const { http, tcp } = application.addresses();
  const dnasToken = newDnasToken();

  const sessionId = await authenticate(http.port, {
    userid: 'player1', password: 'secret1', dnasToken
  });
  assert.equal(application.identity.boundTokenCount, 1);

  const received = await walkLadder(tcp.port, dnasToken);
  assert.equal(received.length, LADDER_RESPONSE_LENGTH, 'the full ladder was answered');
  // The association really resolved to the authenticated session.
  assert.ok(application.repositories.sessions.get(sessionId) != null);
});

test('a lobby connection with no authenticated account session is served nothing', async (t) => {
  // The security property, restated for the corrected model. It used to be
  // "reject an unknown DNAS token"; that is now theatre, because the token
  // proves nothing - V2 mints it from a static replay asset (T27). What
  // actually gates the lobby is a game-account session, established by the UDP
  // register/bind or an HTTP login. Without one, nothing is served, whatever
  // token is presented.
  const { application } = await startApplication(t);
  const { http, tcp } = application.addresses();

  // Arm the address so these connections get the lobby transcript and the
  // refusal under test is the identity check, not the boot-auth path. Arming
  // selects a transcript and grants no identity.
  application.arming.arm('127.0.0.1', { source: 'test' });

  for (const [label, token] of [
    ['an unrecognised token', newDnasToken()],
    ['the captured production token', 'KLa0ZocQ6MWC3ADgVYbw2h69t0MsMnF5Z4OmwnhY3zc='],
    ['a malformed token', Buffer.alloc(16).toString('base64').padEnd(44, 'A')]
  ]) {
    const received = await walkLadder(tcp.port, token);
    assert.equal(
      received.length,
      LOBBY_CHALLENGE_LENGTH,
      `${label} gets the fixed challenge and nothing else`
    );
  }

  // And with an account session present, the SAME connection shape succeeds -
  // proving the refusals above were the identity gate and not a broken ladder.
  await authenticate(http.port, {
    userid: 'realplayer', password: 'secret0', dnasToken: newDnasToken()
  });
  const served = await walkLadder(tcp.port, newDnasToken());
  assert.equal(served.length, LADDER_RESPONSE_LENGTH, 'an authenticated account is served');
});

test('a player can reconnect: closing a lobby connection releases its claim', async (t) => {
  // A claim is single-use while it is HELD - two simultaneous connections cannot
  // both take one, which `connection-identity.test.js` proves directly. But it
  // must be released on close, or a dropped connection would strand the session
  // and the player could never come back without registering again. The client
  // legitimately reconnects: the captures show it opening several lobby
  // connections in a row.
  const { application } = await startApplication(t);
  const { http, tcp } = application.addresses();
  await authenticate(http.port, {
    userid: 'oneshot', password: 'secret1', dnasToken: newDnasToken()
  });

  const first = await walkLadder(tcp.port, newDnasToken());
  assert.equal(first.length, LADDER_RESPONSE_LENGTH);

  const second = await walkLadder(tcp.port, newDnasToken());
  assert.equal(second.length, LADDER_RESPONSE_LENGTH, 'the player can reconnect');

  const player = application.accountSessions.findByUserId('oneshot');
  assert.notEqual(player, null, 'and still has exactly one account session');
});

test('an account session whose HTTP session vanished still authenticates the lobby', async (t) => {
  // The account session is what authenticates, so losing the HTTP session row
  // must not lock the player out - it only means the HTTP correlation signal is
  // gone. Previously this failed closed, because the HTTP binding WAS identity.
  const { application } = await startApplication(t);
  const { http, tcp } = application.addresses();
  const dnasToken = newDnasToken();
  const sessionId = await authenticate(http.port, {
    userid: 'player3', password: 'secret3', dnasToken
  });

  application.repositories.database.connection.exec(
    `DELETE FROM sessions WHERE connection_id = '${sessionId}'`
  );

  const received = await walkLadder(tcp.port, dnasToken);
  assert.equal(received.length, LADDER_RESPONSE_LENGTH);
  const player = application.accountSessions.findByUserId('player3');
  assert.notEqual(player, null);
  assert.notEqual(player.claimedByConnection, null);
});

test('a fragmented walk answers identically to a coalesced one', async (t) => {
  // This used to run two SIMULTANEOUS authenticated connections, one of each
  // delivery shape. It cannot any more, and that is correct rather than a
  // regression: both came from 127.0.0.1, so both account sessions are eligible
  // at one address and the model refuses ambiguity instead of guessing. Two
  // players sharing a source address is a real limitation, recorded in the
  // CHANGELOG.
  //
  // Simultaneous projection ISOLATION is still covered, at the layer that owns
  // it: `tcp10127-state-backed-ladder.test.js`, "two simultaneous clients each
  // get their own projection and identical bytes".
  const { application } = await startApplication(t);
  const { http, tcp } = application.addresses();

  // ONE account, two sequential connections. A second account would make both
  // sessions eligible at this address and the walk would be refused, which is
  // the point of the test below.
  await authenticate(http.port, { userid: 'iso1', password: 'secret1', dnasToken: newDnasToken() });
  const coalesced = await walkLadder(tcp.port, newDnasToken());
  assert.equal(coalesced.length, LADDER_RESPONSE_LENGTH);

  const fragmented = await walkLadder(tcp.port, newDnasToken(), { fragment: true });
  assert.equal(fragmented.toString('hex'), coalesced.toString('hex'));
});

test('two eligible account sessions at one address are refused, not merged', async (t) => {
  const { application } = await startApplication(t);
  const { http, tcp } = application.addresses();
  await authenticate(http.port, { userid: 'natA', password: 'secret1', dnasToken: newDnasToken() });
  await authenticate(http.port, { userid: 'natB', password: 'secret2', dnasToken: newDnasToken() });

  // Both eligible, same source: the lobby connection cannot tell which player
  // this is, so it is served the challenge and nothing else.
  const received = await walkLadder(tcp.port, newDnasToken());
  assert.equal(received.length, LOBBY_CHALLENGE_LENGTH);
});

test('disconnect releases connection state while the directory survives', async (t) => {
  const { application } = await startApplication(t);
  const { http, tcp } = application.addresses();
  const dnasToken = newDnasToken();
  await authenticate(http.port, { userid: 'cleanup', password: 'secret1', dnasToken });

  await walkLadder(tcp.port, dnasToken);
  await new Promise((resolve) => setTimeout(resolve, 60));
  // The projection is RETAINED on disconnect, deliberately. The client keeps its
  // directory state across a transport reset and afterwards fetches by a key
  // issued on the closed connection, so releasing it here is what broke the
  // resume. It belongs to the lobby session and is released with it.
  assert.equal(application.lobbyProviders.openConnectionCount(), 1, 'projection retained');
  assert.equal(application.identity.openConnectionCount, 0, 'connection identity released');

  const [accountSessionId] = [...application.lobbySessions.keys()];
  application.releaseLobbySession(accountSessionId, 'test');
  assert.equal(application.lobbyProviders.openConnectionCount(), 0, 'released with its session');
  assert.equal(application.lobbySessions.size, 0);
  // The token binding outlives the connection: the client reconnects with it.
  assert.equal(application.identity.boundTokenCount, 1);

  const directory = application.directoryProvider.currentDirectory();
  // The served directory is the fixture: two entries, one record each - the
  // minimum a usable Server Select needs.
  assert.equal(directory.entryCount, 2);
  assert.equal(directory.totalRecordCount, 2);

  // And a second connection with the same token still walks the full ladder.
  const again = await walkLadder(tcp.port, dnasToken);
  assert.equal(again.length, LADDER_RESPONSE_LENGTH);
});

test('publishing a newer directory does not disturb an in-flight projection', async (t) => {
  const { application } = await startApplication(t);
  const before = application.directoryProvider.currentDirectory();

  const replacement = createDirectoryState({
    provenance: DIRECTORY_PROVENANCE.OPERATOR,
    entries: [
      { ...parseDirectoryDocument(directoryDocument()).entryAt(0), entryId: 'entry-0' },
      {
        entryId: 'entry-1',
        host: Buffer.from('10.0.0.2', 'latin1'),
        name: Buffer.from('E1', 'latin1'),
        raw8: Buffer.alloc(8),
        description: Buffer.from('second', 'latin1'),
        pageField: Buffer.from('ENTRY1', 'latin1'),
        command6502Unknown0: 1,
        command6502Unknown1: 2,
        records: [{
          recordId: 'record-1',
          unknownField0: Buffer.from('E1R0', 'latin1'),
          unknownField1: Buffer.from('F1', 'latin1'),
          unknownRaw8: Buffer.alloc(8),
          unknownField2: Buffer.from('D', 'latin1'),
          unknownWord0: 0,
          unknownWord1: 0,
          unknownDword: 0,
          unknownWord6510: 1
        }]
      }
    ]
  });
  application.directoryProvider.publish(replacement);

  assert.equal(application.directoryProvider.currentDirectory().entryCount, 2);
  // The snapshot a live projection captured is a different, unchanged object.
  assert.equal(before.entryCount, 2);
  assert.notEqual(before, application.directoryProvider.currentDirectory());

  // An actually in-flight projection: built from the old snapshot, half way
  // through its walk when the new one is published, and unaffected by it.
  const { createClientDirectoryProjection } = await import(
    '../src/state/client-directory-projection.js'
  );
  const inFlight = createClientDirectoryProjection({ directory: before, codecByte: 0 });
  // The walk visits EVERY entry - one 0x6502/0x6504 pair each - and only then
  // does the key exchange begin. The snapshot holds two entries because a
  // one-entry directory is refused at startup.
  const batches = before.entryCount;
  let batch = null;
  for (let index = 0; index < batches; index += 1) {
    inFlight.selectCommand6502Response();
    batch = inFlight.takeCommand6504Batch({ sequence: 0x20 });
    assert.equal(batch.unknownTotal, 1, 'each fixture entry holds exactly one record');
  }

  application.directoryProvider.publish(createDirectoryState({
    provenance: DIRECTORY_PROVENANCE.OPERATOR,
    entries: [parseDirectoryDocument(directoryDocument()).entryAt(0)]
  }));

  // Still walking the world it started in, with its own records: the publish
  // above replaced the authoritative directory and this snapshot is untouched.
  const answer = inFlight.resolveCommand6510Response({
    sequence: 0x21,
    encodedRecordFields: [encodeSnapField({
      plain: Buffer.from('E0R0', 'latin1'),
      maximumDecodedLength: 0x0f,
      sequence: 0x21,
      unknownCodecByte: 0
    })]
  });
  assert.deepEqual(answer.recordWords, [0x0009]);
  assert.equal(answer.unknownTrailingField.toString('latin1'), '10.0.0.1');
});

/**
 * DNS wire helpers, written here rather than imported from `src/dns/dns-codec.js`
 * on purpose: a test that both asks and answers with the same encoder proves only
 * that the encoder agrees with itself.
 */
function encodeDnsQuery(name, { id = 0x1234 } = {}) {
  const labels = name.split('.').filter(Boolean);
  const nameLength = labels.reduce((total, label) => total + 1 + label.length, 0) + 1;
  const message = Buffer.alloc(12 + nameLength + 4);
  message.writeUInt16BE(id, 0);
  message.writeUInt16BE(0x0100, 2);
  message.writeUInt16BE(1, 4);
  let offset = 12;
  for (const label of labels) {
    message[offset] = label.length;
    message.write(label, offset + 1, 'ascii');
    offset += 1 + label.length;
  }
  message[offset] = 0;
  offset += 1;
  message.writeUInt16BE(1, offset);
  message.writeUInt16BE(1, offset + 2);
  return message;
}

function parseDnsResponseAddresses(message) {
  const answerCount = message.readUInt16BE(6);
  let offset = 12;
  while (message[offset] !== 0) offset += 1 + message[offset];
  offset += 1 + 4;
  const addresses = [];
  for (let index = 0; index < answerCount; index += 1) {
    if ((message[offset] & 0xc0) === 0xc0) {
      offset += 2;
    } else {
      while (message[offset] !== 0) offset += 1 + message[offset];
      offset += 1;
    }
    const type = message.readUInt16BE(offset);
    const dataLength = message.readUInt16BE(offset + 8);
    const data = message.subarray(offset + 10, offset + 10 + dataLength);
    if (type === 1 && dataLength === 4) addresses.push(Array.from(data).join('.'));
    offset += 10 + dataLength;
  }
  return addresses;
}

/**
 * The DNS service binds TCP and UDP on the SAME port, so an ephemeral TCP port
 * is not enough: the matching UDP port must also be free. Probe for one that is
 * free on both rather than letting the kernel pick a TCP port that UDP refuses.
 */
async function findFreeDnsPort() {
  for (let attempt = 0; attempt < 40; attempt += 1) {
    const port = 20000 + Math.floor((Date.now() + attempt * 977) % 20000);
    const usable = await new Promise((resolve) => {
      const udp = dgram.createSocket('udp4');
      udp.once('error', () => resolve(false));
      udp.bind(port, '127.0.0.1', () => {
        const tcp = net.createServer();
        tcp.once('error', () => udp.close(() => resolve(false)));
        tcp.listen(port, '127.0.0.1', () => {
          tcp.close(() => udp.close(() => resolve(true)));
        });
      });
    });
    if (usable) return port;
  }
  throw new Error('no port free on both TCP and UDP');
}

test('composes and answers DNS when it is enabled', async (t) => {
  // Every other test disables DNS; this one proves the composed DNS path
  // actually binds and answers, rather than only being configured.
  const dnsPort = await findFreeDnsPort();
  const { application } = await startApplication(t, {
    PAL_V2_ENABLE_DNS: 'true',
    PAL_V2_DNS_PORT: String(dnsPort),
    PAL_V2_DNS_RECORDS: 'snap01.capcom.client.sf.yav4.com=192.0.2.121'
  });
  const address = application.addresses().dns;
  assert.notEqual(address, null);
  assert.ok(address.port > 0);

  const answer = await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port: address.port }, () => {
      const query = encodeDnsQuery('snap01.capcom.client.sf.yav4.com');
      const framed = Buffer.alloc(2 + query.length);
      framed.writeUInt16BE(query.length, 0);
      query.copy(framed, 2);
      socket.write(framed);
    });
    const chunks = [];
    socket.on('data', (chunk) => {
      chunks.push(chunk);
      const all = Buffer.concat(chunks);
      if (all.length >= 2 && all.length >= 2 + all.readUInt16BE(0)) {
        socket.destroy();
        resolve(all.subarray(2));
      }
    });
    socket.on('error', reject);
  });
  assert.deepEqual(parseDnsResponseAddresses(answer), ['192.0.2.121']);
});

test('an unarmed connection gets the boot transcript, an armed one gets the challenge', async (t) => {
  const { application } = await startApplication(t);
  const { http, tcp } = application.addresses();

  // No browser flow yet: this is the connection the real client makes right
  // after DNAS, and the captures show it receiving 0x1001/0x1002/0x1004 with the
  // client sending nothing at all.
  const boot = await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port: tcp.port });
    let bytes = Buffer.alloc(0);
    socket.on('data', (chunk) => {
      bytes = Buffer.concat([bytes, chunk]);
      if (bytes.length >= 24) {
        socket.destroy();
        resolve(bytes);
      }
    });
    socket.on('error', reject);
  });
  assert.equal(
    boot.toString('hex'),
    '000002100100000000000210020000000000021004000000',
    'boot auth is the three captured server frames'
  );

  // Completing the browser flow arms the address; the next connection opens with
  // the 0x6001 challenge instead.
  await authenticate(http.port, {
    userid: 'armed1', password: 'secret1', dnasToken: newDnasToken()
  });
  assert.equal(application.arming.isArmed('127.0.0.1'), true);

  const lobby = await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port: tcp.port });
    let bytes = Buffer.alloc(0);
    socket.on('data', (chunk) => {
      bytes = Buffer.concat([bytes, chunk]);
      if (bytes.length >= 8) {
        socket.destroy();
        resolve(bytes);
      }
    });
    socket.on('error', reject);
  });
  assert.equal(lobby.toString('hex'), '0000106001010000', 'lobby opens with the challenge');
});

test('the production TCP service takes no flat providers', async (t) => {
  const { application } = await startApplication(t);
  // Composition passes only the per-connection factory; the service refuses the
  // combination outright, so a fallback cannot be reintroduced by accident.
  const { createTcp10127Service } = await import('../src/tcp/tcp10127-service.js');
  assert.throws(
    () => createTcp10127Service({
      resolveConnectionPurpose: () => 'lobby-initialization',
      createConnectionProviders: () => ({ resolveCommand6501Response: () => ({ mode: 0 }) }),
      resolveCommand6504Response: () => ({})
    }),
    /cannot be combined with flat providers/
  );
  assert.equal(application.running, true);
});

test('no V1 fixture value can reach production state through the directory loader', () => {
  // The loader has no defaults at all: a record missing a field is refused
  // rather than filled in, so nothing can be inherited from V1.
  assert.throws(
    () => parseDirectoryDocument({
      provenance: DIRECTORY_PROVENANCE.OPERATOR,
      entries: [{ entryId: 'e', host: '10.0.0.1', name: 'E', raw8: { hex: '0000000000000000' }, description: 'd', pageField: 'P', command6502Unknown0: 0, command6502Unknown1: 0, records: [{ recordId: 'r' }] }]
    }),
    /unknownField0 must be a latin1 string/
  );
  assert.throws(
    () => parseDirectoryDocument({ entries: [] }),
    /must declare "provenance"/
  );
});

/**
 * The path the real client actually walks, composed end to end: create an
 * account through the in-game browser's HTTP flow, then register over UDP 9090
 * as the client would, and verify the reply decrypts under the password that
 * account was created with.
 *
 * This is the composition that unit tests cannot catch. `associateDnasToken`
 * passed every unit test while never being called; the same class of mistake
 * here would be an account store the register cannot actually read.
 */
test('an account created over HTTP can register over UDP 9090', async (t) => {
  const { application } = await startApplication(t);
  const httpPort = application.addresses().http.port;
  const registerPort = application.addresses().udpRegister.port;
  assert.ok(registerPort > 0, 'the register service is composed and bound');

  const created = await httpRequest(
    httpPort,
    'POST',
    '/mhweb/create.jsp',
    'userid=rigtest&password=secret42'
  );
  assert.match(created, /<!--COMP-SIGNUP-->/);
  // The identity the client will carry on the memory card is the string the
  // server put after INPUT-IDS - which is what the register then presents.
  assert.ok(created.includes('<!--INPUT-IDS-->rigtest\x00<br>'));

  const client = dgram.createSocket('udp4');
  t.after(() => new Promise((resolve) => client.close(resolve)));
  await new Promise((resolve) => client.bind(0, '127.0.0.1', resolve));

  const request = Buffer.alloc(154);
  request.writeUInt16BE(0x3096, 0x00);
  request.writeUInt8(0x2c, 0x03);
  request.writeUInt32BE(0x02f807d0, 0x04);
  const body = request.subarray(0x10);
  body.write('rigtest', 0x00, 'latin1');
  body.write('rigtest@cee-auth', 0x28, 'latin1');
  body.writeUInt32BE(0xcaf3, 0x64);
  Buffer.from([127, 0, 0, 1]).copy(body, 0x6c);
  body.writeUInt32BE(2000, 0x70);
  body.writeUInt32BE(100, 0x74);
  body.writeUInt16BE(0, 0x78);
  Buffer.from([0xba, 0x47, 0x66, 0x11]).copy(request, 150);

  const reply = await new Promise((resolve, reject) => {
    const timer = setTimeout(() => reject(new Error('no register reply')), 2000);
    client.once('message', (datagram) => {
      clearTimeout(timer);
      resolve(datagram);
    });
    client.send(request, registerPort, '127.0.0.1');
  });

  assert.equal(reply.length, 154);
  assert.equal(reply.readUInt8(0x03), 0x2d);
  assert.equal(reply.readUInt32BE(0x04), 0x02f807d0);

  // The client's own acceptance test, run here: decrypt with the password the
  // account was created with, and strcmp the plaintext against what we sent.
  const plaintext = blowfishEcbDecrypt(
    createBlowfishKey('secret42'),
    reply.subarray(0x10, 0x90)
  );
  assert.equal(plaintext.subarray(0, plaintext.indexOf(0)).toString('latin1'), 'rigtest');
  assert.equal(plaintext.readUInt32BE(0x30), registerPort, 'the port the client will use next');

  // A different password must NOT produce an acceptable body.
  const wrong = blowfishEcbDecrypt(createBlowfishKey('wrongpass'), reply.subarray(0x10, 0x90));
  assert.notEqual(wrong.subarray(0, 7).toString('latin1'), 'rigtest');
});

test('a register for an account the server does not hold is answered with silence', async (t) => {
  const { application } = await startApplication(t);
  const registerPort = application.addresses().udpRegister.port;

  const client = dgram.createSocket('udp4');
  t.after(() => new Promise((resolve) => client.close(resolve)));
  await new Promise((resolve) => client.bind(0, '127.0.0.1', resolve));

  const request = Buffer.alloc(154);
  request.writeUInt16BE(0x3096, 0x00);
  request.writeUInt8(0x2c, 0x03);
  request.writeUInt32BE(0x02f807d0, 0x04);
  request.subarray(0x10).write('ghost', 0x00, 'latin1');
  request.subarray(0x10).writeUInt16BE(0, 0x78);
  Buffer.from([0xba, 0x47, 0x66, 0x11]).copy(request, 150);

  const outcome = await new Promise((resolve) => {
    const timer = setTimeout(() => resolve('silence'), 500);
    client.once('message', () => {
      clearTimeout(timer);
      resolve('replied');
    });
    client.send(request, registerPort, '127.0.0.1');
  });
  assert.equal(outcome, 'silence', 'there is no error reply to send; the client retries');
});

/**
 * Reproduces the T24 divergence exactly: a client whose memory card already
 * holds an account never opens the browser, so it goes DNAS -> UDP register ->
 * TCP lobby with NO HTTP request at all. V2 armed lobby mode only from
 * `POST /mhweb/lbs.jsp`, so every such connection was classified boot auth and
 * the real client reset it three times.
 *
 * No unit test could have caught this: the arming registry was correct, the
 * register service was correct, and they were simply never connected.
 */
test('a UDP bind arms the lobby transcript with no HTTP request at all', async (t) => {
  const { application } = await startApplication(t);
  const registerPort = application.addresses().udpRegister.port;
  const tcpPort = application.addresses().tcp.port;

  // Seed an account directly, exactly as a memory card already holding one.
  application.repositories.accounts.create({ userid: 'cardacct', password: 'secret42' });

  const udp = dgram.createSocket('udp4');
  t.after(() => new Promise((resolve) => udp.close(resolve)));
  await new Promise((resolve) => udp.bind(0, '127.0.0.1', resolve));

  const trailer = Buffer.from([0xba, 0x47, 0x66, 0x11]);
  const register = Buffer.alloc(154);
  register.writeUInt16BE(0x3096, 0x00);
  register.writeUInt8(0x2c, 0x03);
  register.writeUInt32BE(0x02f807d0, 0x04);
  register.subarray(0x10).write('cardacct', 0x00, 'latin1');
  register.subarray(0x10).write('cardacct@cee-auth', 0x28, 'latin1');
  register.subarray(0x10).writeUInt16BE(0, 0x78);
  trailer.copy(register, 150);

  const bind = Buffer.alloc(330);
  bind.writeUInt16BE(0x3146, 0x00);
  bind.writeUInt8(0x01, 0x03);
  bind.writeUInt32BE(0x02f807d0, 0x04);
  bind.subarray(0x10).write('cardacct-', 0x10, 'latin1');
  bind.subarray(0x10).writeUInt32BE(0xcaf3, 0x20);
  trailer.copy(bind, 326);

  const exchangeUdp = (datagram, ms) =>
    new Promise((resolve) => {
      const received = [];
      const onMessage = (reply) => received.push(reply);
      udp.on('message', onMessage);
      udp.send(datagram, registerPort, '127.0.0.1');
      setTimeout(() => {
        udp.removeListener('message', onMessage);
        resolve(received);
      }, ms);
    });

  assert.equal((await exchangeUdp(register, 500)).length, 1, 'register answered');
  assert.equal((await exchangeUdp(bind, 500)).length, 2, 'bind answered with ACK + push');

  // Now the TCP connection the client makes next must get the LOBBY challenge,
  // not the boot transcript. The boot transcript is three 8-byte frames; the
  // lobby transcript is one.
  const first = await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port: tcpPort });
    const chunks = [];
    socket.on('data', (chunk) => chunks.push(chunk));
    socket.on('error', reject);
    setTimeout(() => {
      socket.destroy();
      resolve(Buffer.concat(chunks));
    }, 400);
  });

  assert.equal(
    first.toString('hex'),
    '0000106001010000',
    'the 0x6001 lobby challenge, not the boot transcript'
  );
});

/**
 * The central path of the corrected model, end to end through the composed app:
 * a UDP-9090 register and bind establish the game-account session, and the
 * lobby connection that follows is authenticated by it - with no HTTP request
 * anywhere, which is exactly the flow a client whose memory card already holds
 * an account performs. Unit tests could not catch a break here: the registries
 * were each correct and simply not connected.
 */
test('a UDP register and bind authenticate the whole lobby ladder, with no HTTP', async (t) => {
  const { application } = await startApplication(t);
  const registerPort = application.addresses().udpRegister.port;
  const tcpPort = application.addresses().tcp.port;

  application.repositories.accounts.create({ userid: 'udponly', password: 'secret42' });

  const udp = dgram.createSocket('udp4');
  t.after(() => new Promise((resolve) => udp.close(resolve)));
  await new Promise((resolve) => udp.bind(0, '127.0.0.1', resolve));

  const trailer = Buffer.from([0xba, 0x47, 0x66, 0x11]);
  const register = Buffer.alloc(154);
  register.writeUInt16BE(0x3096, 0x00);
  register.writeUInt8(0x2c, 0x03);
  register.writeUInt32BE(0x02f807d0, 0x04);
  register.subarray(0x10).write('udponly', 0x00, 'latin1');
  register.subarray(0x10).write('udponly@cee-auth', 0x28, 'latin1');
  register.subarray(0x10).writeUInt16BE(0, 0x78);
  trailer.copy(register, 150);

  const bind = Buffer.alloc(330);
  bind.writeUInt16BE(0x3146, 0x00);
  bind.writeUInt8(0x01, 0x03);
  bind.writeUInt32BE(0x02f807d0, 0x04);
  bind.subarray(0x10).write('udponly-', 0x10, 'latin1');
  bind.subarray(0x10).writeUInt32BE(0xcaf3, 0x20);
  trailer.copy(bind, 326);

  const send = (datagram, ms) =>
    new Promise((resolve) => {
      const received = [];
      const onMessage = (reply) => received.push(reply);
      udp.on('message', onMessage);
      udp.send(datagram, registerPort, '127.0.0.1');
      setTimeout(() => {
        udp.removeListener('message', onMessage);
        resolve(received);
      }, ms);
    });

  assert.equal((await send(register, 500)).length, 1, 'register answered');
  assert.equal((await send(bind, 500)).length, 2, 'bind answered with ACK + push');

  // The account session now exists, established purely by UDP.
  const session = application.accountSessions.findByUserId('udponly');
  assert.notEqual(session, null);
  assert.equal(session.sourceAddress, '127.0.0.1', 'the dgram address matches the TCP one');

  // And it authenticates the entire lobby ladder.
  const served = await walkLadder(tcpPort, newDnasToken());
  assert.equal(served.length, LADDER_RESPONSE_LENGTH, 'the full ladder was answered');

  // requirePlayer works for a player who never opened the browser - it used to
  // throw here, because an account-session id was being fed to the HTTP lookup.
  const claimed = application.accountSessions.findByUserId('udponly');
  assert.notEqual(claimed.claimedByConnection, null);
  const player = application.identity.requirePlayer(claimed.claimedByConnection);
  assert.equal(player.userid, 'udponly');
  assert.equal(player.sessionConnectionId, null, 'no HTTP session, and that is not an error');
});

/**
 * THE OWNERSHIP BOUNDARY, end to end.
 *
 * The capture (2026-08-04, v2-run7-freshboot.pcap) proves the client RETAINS its
 * directory state across the transport reset: it completed the ladder on port
 * 1249, reset, reopened on 1250 and sent
 * `0015 01 6510 00 00ff 01 000600f708781e72000a01ef1d09006f1f7e647f` - one
 * record key, issued on the PREVIOUS connection. V2 had minted an empty
 * projection for the new connection, so the key matched nothing, the provider
 * failed with "0x6510 is not expected during record-delivery", and V2 sent FIN.
 *
 * So the projection belongs to the LOBBY SESSION, not the connection.
 */
test('a resume resolves a 0x6510 key issued on the PREVIOUS transport', async (t) => {
  const { application, records } = await startApplication(t);
  const { http, tcp } = application.addresses();
  const dnasToken = newDnasToken();
  await authenticate(http.port, { userid: 'retain', password: 'secret1', dnasToken });

  // 1-3. Complete the fresh ladder, which populates the projection and issues
  // the record key, then close the transport.
  const first = await walkLadder(tcp.port, dnasToken);
  assert.equal(first.length, LADDER_RESPONSE_LENGTH, 'the fresh ladder completed');
  await new Promise((resolve) => setTimeout(resolve, 60));

  const [accountSessionId] = [...application.lobbySessions.keys()];
  const lobbySession = application.lobbySessions.get(accountSessionId);
  assert.notEqual(lobbySession, undefined, 'the lobby session outlived its transport');
  assert.equal(lobbySession.transportRef, null, 'and has no transport');
  const retainedProjection = lobbySession.projection;

  /*
   * 4-5. Resume on a second transport and RE-WALK.
   *
   * The resumed connection is answered `0x6501` MODE 1, the same as the fresh
   * one. T32 answered it mode 0 on the inference that a `0x6501`-first
   * connection is client state 5, and V1's own session 6 refutes that: line 17
   * of `2026_07_30_14_52_53_snap_session6_trace.log` is `01 00000000 00000000`
   * on exactly that connection and line 22 is the client's `0x6503`. So the
   * resumed client rebuilds its entry table and walks the directory again, and
   * the transcript below is that walk.
   */
  const resumed = await new Promise((resolve, reject) => {
    const socket = net.createConnection({ host: '127.0.0.1', port: tcp.port }, () => {
      socket.write(frame({ command: 0x6501, sequence: 0xff, payload: Buffer.alloc(4) }));
      const rewalk = [
        frame({ command: 0x6503, sequence: 0xe0, payload: Buffer.from('00000008', 'hex') }),
        // One pair per entry, exactly as the fresh walk: the re-walk re-seats
        // every entry's records, not only the first one's.
        ...directoryDocument().entries.flatMap(() => [
          frame({
            command: 0x6502, sequence: 0xe1, payload: Buffer.from('00000000000257d7', 'hex')
          }),
          frame({
            command: 0x6504, sequence: 0xe2, payload: Buffer.from('00000008000258d8', 'hex')
          })
        ]),
        ...directoryDocument().entries.map((entry) =>
          command6510Request(entry.records[0].unknownField0, 0x00))
      ];
      rewalk.forEach((request, index) => {
        setTimeout(() => socket.write(request), 60 * (index + 1));
      });
    });
    let bytes = Buffer.alloc(0);
    socket.on('data', (chunk) => { bytes = Buffer.concat([bytes, chunk]); });
    setTimeout(() => { socket.destroy(); resolve(bytes); }, 600);
    socket.on('error', reject);
  });

  /*
   * 6. The SAME projection is reattached, rewound, and re-walked to the key.
   *
   * The ownership property this test exists for is unchanged by the mode
   * correction: the session hands back the projection it already owns rather
   * than minting one. What changed is that the projection is REWOUND by the
   * `0x6503` at offset 0 - the only thing that zeroes the client's `0x365e18` is
   * a mode-1 `0x6501` reply - so the re-walk re-seats the records and the
   * retained key is answered from a model that matches the client again.
   */
  const resumedLength =
    LOBBY_CHALLENGE_LENGTH +
    REPLY_LENGTH.command6501 +
    REPLY_LENGTH.command6503 +
    REPLY_LENGTH.command6504.reduce((sum, length) => sum + REPLY_LENGTH.command6502 + length, 0) +
    REPLY_LENGTH.command6510.reduce((sum, length) => sum + length, 0);
  assert.equal(
    resumed.length,
    resumedLength,
    'challenge + mode-1 0x6501 reply + the re-walk + the answered 0x6510'
  );
  const answer = resumed.subarray(resumedLength - REPLY_LENGTH.command6510.at(-1));
  assert.equal(answer.readUInt8(2), 0x02, 'a server-direction frame');
  assert.equal(answer.readUInt16BE(3), 0x6510, 'and it is the 0x6510 reply');
  assert.equal(answer.readUInt8(6), 0x00, 'status 0: accepted, not refused');
  assert.equal(
    application.lobbySessions.get(accountSessionId).projection,
    retainedProjection,
    'reattached, not rebuilt'
  );
  assert.equal(application.lobbySessions.get(accountSessionId).resumeCount, 1);

  // 7. The ownership boundary itself: a FRESHLY constructed projection is in a
  // different phase from the retained one, so it could never stand in for it.
  const fresh = application.lobbyProviders.createProjection();
  assert.notEqual(
    fresh.phase,
    retainedProjection.phase,
    'a new projection is not interchangeable with the retained one'
  );
  application.lobbyProviders.releaseProjection(fresh);
});

test('a superseded transport can no longer serve from the lobby session', async (t) => {
  const { application } = await startApplication(t);
  const { http, tcp } = application.addresses();
  const dnasToken = newDnasToken();
  await authenticate(http.port, { userid: 'supersede', password: 'secret1', dnasToken });
  await walkLadder(tcp.port, dnasToken);
  await new Promise((resolve) => setTimeout(resolve, 60));

  const [accountSessionId] = [...application.lobbySessions.keys()];
  const lobbySession = application.lobbySessions.get(accountSessionId);

  // Only one transport may own the session at a time.
  const { superseded } = lobbySession.attachTransport('transport-A');
  assert.equal(superseded, null);
  assert.equal(lobbySession.ownsTransport('transport-A'), true);

  const second = lobbySession.attachTransport('transport-B');
  assert.equal(second.superseded, 'transport-A', 'the resume supersedes the prior transport');
  assert.equal(lobbySession.ownsTransport('transport-A'), false);
  assert.equal(lobbySession.ownsTransport('transport-B'), true);

  // The superseded transport closing later must not evict the live one.
  assert.equal(lobbySession.detachTransport('transport-A'), false);
  assert.equal(lobbySession.ownsTransport('transport-B'), true);
});

test('terminating a lobby session releases its retained projection', async (t) => {
  const { application } = await startApplication(t);
  const { http, tcp } = application.addresses();
  const dnasToken = newDnasToken();
  await authenticate(http.port, { userid: 'endoflife', password: 'secret1', dnasToken });
  await walkLadder(tcp.port, dnasToken);
  await new Promise((resolve) => setTimeout(resolve, 60));

  assert.equal(application.lobbyProviders.openConnectionCount(), 1, 'retained');
  const [accountSessionId] = [...application.lobbySessions.keys()];
  const lobbySession = application.lobbySessions.get(accountSessionId);

  application.releaseLobbySession(accountSessionId, 'test');
  assert.equal(application.lobbyProviders.openConnectionCount(), 0, 'released');
  assert.equal(application.lobbySessions.size, 0);
  // A stale reference cannot keep serving from a released session.
  assert.throws(() => lobbySession.projection, (error) => error.code === 'LOBBY_SESSION_TERMINATED');
});

test('a fresh initialization for the same account replaces the retained state', async (t) => {
  const { application } = await startApplication(t);
  const { http, tcp } = application.addresses();
  const dnasToken = newDnasToken();
  await authenticate(http.port, { userid: 'restart', password: 'secret1', dnasToken });

  await walkLadder(tcp.port, dnasToken);
  await new Promise((resolve) => setTimeout(resolve, 60));
  const firstProjection = [...application.lobbySessions.values()][0].projection;

  // The client restarts its directory walk from 0x1007, so the retained state
  // is stale and must be replaced rather than accumulated.
  await walkLadder(tcp.port, dnasToken);
  await new Promise((resolve) => setTimeout(resolve, 60));

  assert.equal(application.lobbySessions.size, 1, 'not accumulated');
  assert.notEqual(
    [...application.lobbySessions.values()][0].projection,
    firstProjection,
    'a fresh initialization gets a fresh projection'
  );
  assert.equal(application.lobbyProviders.openConnectionCount(), 1, 'the old one was released');
});

test('repeated HTTP logins for one account do not accumulate retained sessions', async (t) => {
  // The leak review demonstrated: six logins for ONE account produced six
  // retained lobby sessions and six projections, because the HTTP displacement
  // branch logged the displaced account session but never released its state.
  // Release is now driven by the registry's single forget path.
  const { application } = await startApplication(t);
  const { http, tcp } = application.addresses();

  await authenticate(http.port, { userid: 'repeat', password: 'secret1', dnasToken: newDnasToken() });
  for (let attempt = 0; attempt < 6; attempt += 1) {
    const dnasToken = newDnasToken();
    // Log in again, as a player returning to the lobby would.
    await httpRequest(
      http.port,
      'POST',
      `/mhweb/login.jsp?DNAS=${encodeURIComponent(dnasToken)}`,
      'userid=repeat&password=secret1'
    );
    await walkLadder(tcp.port, dnasToken);
    await new Promise((resolve) => setTimeout(resolve, 40));
  }

  assert.equal(application.accountSessions.size, 1, 'one account, one session');
  assert.equal(application.lobbySessions.size, 1, 'and one retained lobby session');
  assert.equal(application.lobbyProviders.openConnectionCount(), 1, 'one projection');
});

test('a UDP displacement releases the retained lobby session too', async (t) => {
  const { application } = await startApplication(t);
  const { http, tcp } = application.addresses();
  const dnasToken = newDnasToken();
  await authenticate(http.port, { userid: 'udpdisp', password: 'secret1', dnasToken });
  await walkLadder(tcp.port, dnasToken);
  await new Promise((resolve) => setTimeout(resolve, 40));
  assert.equal(application.lobbySessions.size, 1);

  // Re-establishing the same account displaces it, exactly as a repeat UDP
  // register and PROVEN bind would. The proof is required since D-2: a
  // displacement that proves nothing is refused, which the test below drives
  // over real sockets.
  application.accountSessions.establish({
    userid: 'udpdisp',
    sourceAddress: '127.0.0.1',
    proof: ACCOUNT_PROOF.REGISTRATION_NONCE
  });
  assert.equal(application.lobbySessions.size, 0, 'the displaced session released its state');
  assert.equal(application.lobbyProviders.openConnectionCount(), 0);
});

/* ---- the advertised capacity ------------------------------------------- */

test('an entry pointing at THIS server must advertise the capacity we configured', async (t) => {
  // Maximum players is a live client gate (FUN_005bc990 -> "Server full. You
  // cannot participate."), so a number nobody decided is a number that turns
  // real players away. 4 is what the rig shipped, inherited from V1's trace.
  const document = directoryDocument();
  document.entries[0].host = '127.0.0.1';
  document.entries[0].records[0].unknownWord1 = 4;
  const { root, env } = makeEnvironment(document);
  t.after(() => removeTree(root));

  assert.throws(
    () => createApplication({ config: loadServerConfig(env), logger: silentLogger() }),
    (error) => error.code === 'DIRECTORY_CAPACITY' && /advertises 4 maximum players/.test(error.message)
  );

  // The same directory is accepted once the configuration says that IS the
  // capacity - the value has to be a decision, not a particular number.
  const agreed = createApplication({
    config: loadServerConfig({ ...env, PAL_V2_MAXIMUM_PLAYERS: '4' }),
    logger: silentLogger()
  });
  await agreed.stop();
});

test('a record advertising zero maximum players is refused wherever it points', async (t) => {
  const document = directoryDocument();
  // Not our host: an entry describing somebody else's server. Its capacity is
  // theirs to declare - but 0 is not a capacity, it is a permanently full lobby.
  document.entries[0].records[0].unknownWord1 = 0;
  const { root, env } = makeEnvironment(document);
  t.after(() => removeTree(root));
  assert.throws(
    () => createApplication({ config: loadServerConfig(env), logger: silentLogger() }),
    (error) => error.code === 'DIRECTORY_CAPACITY' && /permanently full/.test(error.message)
  );
});

/* ---- M-4: the rules the shipped config states are now enforced ----------- */

test('a one-entry directory is refused: the client auto-selects it, undrawn', async (t) => {
  /*
   * `config/directory.example.json` has told operators this since it was
   * written, and until now nothing checked it: a one-entry directory started
   * cleanly and the player simply never got a Server Select. `FUN_00606fc0`
   * substate 1 auto-selects entry 1 below a count of 2.
   */
  const document = directoryDocument();
  document.entries = [document.entries[0]];
  const { root, env } = makeEnvironment(document);
  t.after(() => removeTree(root));
  assert.throws(
    () => createApplication({ config: loadServerConfig(env), logger: silentLogger() }),
    (error) => error.code === 'DIRECTORY_ENTRY_COUNT' && /Add a second entry/.test(error.message)
  );
});

test('an entry with no records is refused: 0x6503 fills a row from it', async (t) => {
  const document = directoryDocument();
  document.entries[1].records = [];
  const { root, env } = makeEnvironment(document);
  t.after(() => removeTree(root));
  assert.throws(
    () => createApplication({ config: loadServerConfig(env), logger: silentLogger() }),
    (error) => error.code === 'DIRECTORY_ENTRY_WITHOUT_RECORDS' &&
      /entry-1/.test(error.message) && /entry\+0x160/.test(error.message)
  );
});

test('the shipped example directory starts a server and offers a choosable list', async (t) => {
  /*
   * The file operators copy, checked against the rules it has to satisfy rather
   * than against a memory of them: two entries, because `FUN_00606fc0` substate 1
   * auto-selects and never draws the list below that; a record in each, because
   * `0x6502` mode 0 skips a recordless entry and `FUN_005c7bd0` dereferences
   * `entry+0x160` unconditionally; and a capacity that agrees with the default
   * configuration, which is what the startup gate demands.
   */
  const { root, env } = makeEnvironment();
  t.after(() => removeTree(root));
  const application = createApplication({
    config: loadServerConfig({
      ...env,
      PAL_V2_DIRECTORY_FILE: path.resolve(import.meta.dirname, '../config/directory.example.json'),
      PAL_V2_SNAP_HOST: '192.0.2.121',
      // The rig's own address cannot be bound here; nothing in this test needs
      // the register service, and the directory is validated at construction.
      PAL_V2_ENABLE_UDP_REGISTER: 'false'
    }),
    logger: silentLogger()
  });
  t.after(() => application.stop());

  const directory = application.directoryProvider.currentDirectory();
  assert.equal(directory.entryCount, 2, 'one entry is auto-selected and never drawn');
  /*
   * The entries are deliberately NOT required to have distinct hosts.
   *
   * What draws the interactive list is the COUNT: `FUN_00606fc0` substate 1
   * auto-selects entry 1 and never draws the widget when the count is 0 or 1.
   * The host is what the client resolves AFTER a choice is made, and on the rig
   * there is exactly one server - so two entries advertising two hosts would
   * mean one of them fails to connect when selected, which on a run meant to
   * prove Area Select works would read as a protocol fault rather than a
   * fixture choice. Production entries are distinct machines; the rig's are the
   * same machine under two names.
   *
   * What IS required is that each entry is separately renderable and
   * selectable.
   */
  const names = [0, 1].map((index) => directory.entryAt(index).name.toString('latin1'));
  assert.equal(new Set(names).size, 2, 'the two entries must be distinguishable on screen');
  for (const name of names) {
    assert.ok(name.length > 0, 'an unnamed entry renders as a blank row');
  }
  for (let index = 0; index < directory.entryCount; index += 1) {
    const entry = directory.entryAt(index);
    assert.ok(entry.records.length >= 1, `${entry.entryId} has no records`);
    assert.ok(entry.name.length > 0 && entry.description.length > 0);
  }
});

/* ---- D-2: a datagram must not be able to evict a player ------------------ */

const UDP_TRAILER = Buffer.from([0xba, 0x47, 0x66, 0x11]);

function registerDatagram(loginIdentity, { token = 0x02f807d0 } = {}) {
  const datagram = Buffer.alloc(154);
  datagram.writeUInt16BE(0x3096, 0x00);
  datagram.writeUInt8(0x2c, 0x03);
  datagram.writeUInt32BE(token, 0x04);
  const body = datagram.subarray(0x10);
  body.write(loginIdentity, 0x00, 'latin1');
  body.write(`${loginIdentity}@cee-auth`, 0x28, 'latin1');
  body.writeUInt32BE(0xcaf3, 0x64);
  Buffer.from([127, 0, 0, 1]).copy(body, 0x6c);
  body.writeUInt32BE(2000, 0x70);
  body.writeUInt32BE(100, 0x74);
  body.writeUInt16BE(0, 0x78);
  UDP_TRAILER.copy(datagram, 150);
  return datagram;
}

/**
 * The post-register bind. `tail` is what the client echoes at body +0x24/+0x28 -
 * the attachment nonce when the sender was able to read our reply, and nothing
 * at all when it was not.
 */
function bindDatagram(loginIdentity, { token = 0x02f807d0, tail = null } = {}) {
  const datagram = Buffer.alloc(330);
  datagram.writeUInt16BE(0x3146, 0x00);
  datagram.writeUInt8(0x01, 0x03);
  datagram.writeUInt32BE(token, 0x04);
  const body = datagram.subarray(0x10);
  body.write(`${loginIdentity}-`, 0x10, 'latin1');
  body.writeUInt32BE(0xcaf3, 0x20);
  if (tail != null) {
    body.writeUInt32BE(tail.length, 0x24);
    tail.copy(body, 0x28);
  }
  UDP_TRAILER.copy(datagram, 326);
  return datagram;
}

async function udpSocket(t) {
  const socket = dgram.createSocket('udp4');
  t.after(() => new Promise((resolve) => socket.close(resolve)));
  await new Promise((resolve) => socket.bind(0, '127.0.0.1', resolve));
  return socket;
}

function exchange(socket, port, datagram, ms = 400) {
  return new Promise((resolve) => {
    const received = [];
    const onMessage = (reply) => received.push(reply);
    socket.on('message', onMessage);
    socket.send(datagram, port, '127.0.0.1');
    setTimeout(() => {
      socket.removeListener('message', onMessage);
      resolve(received);
    }, ms);
  });
}

/**
 * The attachment nonce, recovered the ONLY way a client can recover it: decrypt
 * the register reply with the account password and read plaintext +0x3c. This is
 * the whole basis of the proof - a sender without the password gets 16 bytes of
 * ciphertext-derived noise here and cannot echo anything that will match.
 */
function nonceFromRegisterReply(reply, password) {
  const plaintext = blowfishEcbDecrypt(createBlowfishKey(password), reply.subarray(0x10, 0x90));
  const length = plaintext.readUInt32BE(0x34);
  assert.equal(length, 16, 'the reply must carry the 16-byte attachment nonce');
  return Buffer.from(plaintext.subarray(0x3c, 0x3c + length));
}

/** Register, read the nonce, bind with it - a real client's whole UDP path. */
async function registerAndBind(t, registerPort, { userid, password, echo = true }) {
  const socket = await udpSocket(t);
  const [reply] = await exchange(socket, registerPort, registerDatagram(userid));
  assert.notEqual(reply, undefined, `no register reply for ${userid}`);
  const tail = echo ? nonceFromRegisterReply(reply, password) : null;
  const answered = await exchange(socket, registerPort, bindDatagram(userid, { tail }));
  return { socket, reply, tail, answered };
}

test('a remote datagram naming a player cannot evict that player', async (t) => {
  /*
   * D-2, demonstrated by the 2026-08-06 audit and driven here the same way: over
   * real sockets against the composed application.
   *
   * The attacker sends a register carrying the victim's login identity and then
   * a bind. It cannot read the register reply - that body is Blowfish-encrypted
   * with the victim's password - and it never needed to: the bind used to reach
   * `establish`, which displaced BY NAME and terminated the victim's live lobby
   * session. Login identities are short numeric handles, so the keyspace is
   * enumerable and this was remote, unauthenticated and live.
   */
  const { application, records } = await startApplication(t);
  const registerPort = application.addresses().udpRegister.port;
  const tcpPort = application.addresses().tcp.port;
  application.repositories.accounts.create({ userid: 'victim', password: 'secret42' });

  // The victim reaches the lobby the ordinary way and is playing.
  const victim = await registerAndBind(t, registerPort, {
    userid: 'victim', password: 'secret42'
  });
  assert.equal(victim.answered.length, 2, 'the victim bind was answered with ACK + push');
  // SERVED rather than refused is the property here, and the exact ladder length
  // deliberately is not: a refused connection gets the challenge and nothing
  // else, which is what this distinguishes. The byte count belongs to the ladder
  // tests, and coupling a security test to it makes it fail for their reasons.
  assert.ok(
    await walkLadder(tcpPort, newDnasToken()).then((bytes) => bytes.length) >
      LOBBY_CHALLENGE_LENGTH,
    'and the victim was served the lobby, not just the challenge'
  );
  await new Promise((resolve) => setTimeout(resolve, 40));
  const before = application.accountSessions.findByUserId('victim');
  assert.notEqual(before, null);
  assert.equal(application.lobbySessions.size, 1);
  const lobbySession = [...application.lobbySessions.values()][0];

  // The attack: a different socket, holding nothing but the victim's name.
  const attacker = await udpSocket(t);
  const [stolen] = await exchange(attacker, registerPort, registerDatagram('victim'));
  assert.notEqual(stolen, undefined, 'the register is answered - it always was');
  // The reply is Blowfish-keyed by the victim's password, so it does not open:
  // this is the client's own acceptance test, run from the attacker's side.
  const opened = blowfishEcbDecrypt(
    createBlowfishKey('not-the-password'), stolen.subarray(0x10, 0x90)
  );
  assert.notEqual(
    opened.subarray(0, 6).toString('latin1'), 'victim',
    'the attacker cannot even validate the reply, let alone read the nonce out of it'
  );
  const answered = await exchange(attacker, registerPort, bindDatagram('victim'));
  assert.equal(answered.length, 2, 'the bind is answered too; that is not the boundary');
  // And guessing at the tail buys nothing either - there is no fallback that
  // would let an unmatched nonce resolve by address, port or endpoint token.
  const guessed = await exchange(
    attacker, registerPort, bindDatagram('victim', { tail: crypto.randomBytes(16) })
  );
  assert.equal(guessed.length, 2);

  // THE PROPERTY: the victim is untouched.
  const after = application.accountSessions.findByUserId('victim');
  assert.equal(
    after.accountSessionId,
    before.accountSessionId,
    'the victim keeps the SAME account session'
  );
  assert.equal(application.lobbySessions.size, 1, 'and its retained lobby session');
  assert.equal(application.lobbyProviders.openConnectionCount(), 1);
  assert.doesNotThrow(() => lobbySession.projection, 'which was never terminated');
  assert.equal(
    application.accountSessions.findByUserId('victim').proof,
    ACCOUNT_PROOF.REGISTRATION_NONCE,
    'and the surviving session is still the one the account holder proved'
  );

  // And every refusal is attributable in the journal rather than silent, with
  // the two attempts distinguishable from each other.
  const refusals = records.filter((record) => record.event === 'account-session-refused');
  assert.equal(refusals.length, 2);
  assert.ok(refusals.every((refusal) => refusal.code === 'ACCOUNT_DISPLACEMENT_UNPROVEN'));
  assert.ok(refusals.every((refusal) => refusal.userid === 'victim'));
  assert.deepEqual(
    refusals.map((refusal) => refusal.attachment),
    ['tail-empty', 'nonce-not-attached'],
    'each refusal names which proof was missing'
  );

  // The victim can still be served: the connection state survived the attempt.
  assert.ok(
    await walkLadder(tcpPort, newDnasToken()).then((bytes) => bytes.length) >
      LOBBY_CHALLENGE_LENGTH
  );
});

test('the player who can read the register reply DOES replace their own session', async (t) => {
  /*
   * The other direction, and the reason the refusal above is not simply "never
   * displace": a player whose console restarts must be able to come back. Their
   * bind echoes the nonce we minted, which they could only have obtained by
   * decrypting our reply with the account password - so that establishment is
   * entitled to take the old session away.
   */
  const { application, records } = await startApplication(t);
  const registerPort = application.addresses().udpRegister.port;
  const tcpPort = application.addresses().tcp.port;
  application.repositories.accounts.create({ userid: 'returning', password: 'secret42' });

  await registerAndBind(t, registerPort, { userid: 'returning', password: 'secret42' });
  await walkLadder(tcpPort, newDnasToken());
  await new Promise((resolve) => setTimeout(resolve, 40));
  const first = application.accountSessions.findByUserId('returning');
  assert.equal(application.lobbySessions.size, 1);

  // A fresh socket, as a restarted console presents: register again, decrypt,
  // echo, bind.
  const again = await registerAndBind(t, registerPort, {
    userid: 'returning', password: 'secret42'
  });
  assert.equal(again.answered.length, 2);

  const second = application.accountSessions.findByUserId('returning');
  assert.notEqual(second.accountSessionId, first.accountSessionId, 'a new session');
  assert.equal(second.proof, ACCOUNT_PROOF.REGISTRATION_NONCE, 'and it says what proved it');
  assert.equal(application.lobbySessions.size, 0, 'the old one released its retained state');
  const displaced = records.find((record) => record.event === 'account-session-displaced');
  assert.equal(displaced.displacedAccountSessionId, first.accountSessionId);
  assert.equal(displaced.proof, ACCOUNT_PROOF.REGISTRATION_NONCE);

  // And the returning player is served on the new session. As above, the exact
  // ladder length is the ladder tests' property, not this one's.
  assert.ok(
    await walkLadder(tcpPort, newDnasToken()).then((bytes) => bytes.length) >
      LOBBY_CHALLENGE_LENGTH
  );
});

test('account-session expiry releases the retained projection without traffic', async (t) => {
  const { application } = await startApplication(t);
  const { http, tcp } = application.addresses();
  const dnasToken = newDnasToken();
  await authenticate(http.port, { userid: 'expiring', password: 'secret1', dnasToken });
  await walkLadder(tcp.port, dnasToken);
  await new Promise((resolve) => setTimeout(resolve, 40));
  assert.equal(application.lobbyProviders.openConnectionCount(), 1);

  // Expire it and run the deterministic sweep, with no lookup in between.
  const [accountSessionId] = [...application.lobbySessions.keys()];
  application.accountSessions.remove(accountSessionId);
  assert.equal(application.lobbySessions.size, 0, 'released by the forget hook');
  assert.equal(application.lobbyProviders.openConnectionCount(), 0);
});

test('serving a lobby connection refreshes the ACCOUNT session, not just the lobby one', async (t) => {
  /*
   * Regression, found by the 2026-08-06 architecture audit and fixed the same
   * day. The transport refreshed only the LOBBY session on every provider call;
   * nothing ever refreshed the ACCOUNT session, whose `lastSeenAtMs` was written
   * once at claim time. The 15-second cleanup then reaped the account session of
   * a player who was mid-game, releasing the lobby session under them and
   * leaving the next provider call throwing on a live socket. A hard 30-minute
   * cap on any session - which by itself put two clients finishing a scenario
   * out of reach, and on the rig would have looked like a random disconnect.
   *
   * Asserted by COUNTING the refresh rather than by watching a timestamp. Two
   * earlier attempts watched `lastSeenAtMs` across a second ladder and across a
   * resume; both passed with the fix removed, because establishing and
   * reattaching each refresh the session as a side effect. The property that
   * actually broke is narrower: serving an already-attached connection must
   * refresh it, and only a direct count isolates that from the side effects.
   */
  const { application } = await startApplication(t);
  const { http, tcp } = application.addresses();
  const dnasToken = newDnasToken();
  await authenticate(http.port, { userid: 'active1', password: 'secret1', dnasToken });

  const touched = [];
  const realTouch = application.accountSessions.touch.bind(application.accountSessions);
  application.accountSessions.touch = (id) => {
    touched.push(id);
    return realTouch(id);
  };

  await walkLadder(tcp.port, dnasToken);
  await new Promise((resolve) => setTimeout(resolve, 60));

  const [accountSessionId] = [...application.lobbySessions.keys()];
  assert.ok(
    touched.length > 0,
    'serving the ladder must refresh the account session at least once'
  );
  assert.ok(
    touched.every((id) => id === accountSessionId),
    'and refresh the session this connection is attached to, never another'
  );
});

test('shutdown releases every retained lobby session', async (t) => {
  const { application } = await startApplication(t);
  const { http, tcp } = application.addresses();
  const dnasToken = newDnasToken();
  await authenticate(http.port, { userid: 'shutdown', password: 'secret1', dnasToken });
  await walkLadder(tcp.port, dnasToken);
  await new Promise((resolve) => setTimeout(resolve, 40));
  assert.equal(application.lobbyProviders.openConnectionCount(), 1);

  await application.stop();
  assert.equal(application.lobbySessions.size, 0, 'nothing retained after shutdown');
  assert.equal(application.lobbyProviders.openConnectionCount(), 0);
});

/**
 * THE CREATE-ROOM WALL, driven end to end over a real socket.
 *
 * Unit tests prove the bytes; this proves the WIRING - that a datagram arriving
 * on the bound UDP port reaches a handler that mints a room in the composed
 * application's registry and answers. The op-0x04 handler was missing entirely,
 * and a missing handler is precisely the class of defect a unit test cannot
 * catch, because every unit involved was already correct and simply not
 * connected (the same shape as the T24 arming divergence above).
 */
test('an op-0x04 create over the bound socket mints a room and answers selector 4', async (t) => {
  const { application } = await startApplication(t);
  const registerPort = application.addresses().udpRegister.port;
  application.repositories.accounts.create({ userid: 'maker', password: 'secret42' });

  const udp = dgram.createSocket('udp4');
  t.after(() => new Promise((resolve) => udp.close(resolve)));
  await new Promise((resolve) => udp.bind(0, '127.0.0.1', resolve));

  const trailer = Buffer.from([0xba, 0x47, 0x66, 0x11]);
  const TOKEN = 0x02f807d0;
  const collect = (datagram, ms) => new Promise((resolve) => {
    const received = [];
    const onMessage = (reply) => received.push(reply);
    udp.on('message', onMessage);
    udp.send(datagram, registerPort, '127.0.0.1');
    setTimeout(() => {
      udp.removeListener('message', onMessage);
      resolve(received);
    }, ms);
  });

  const register = Buffer.alloc(154);
  register.writeUInt16BE(0x3096, 0x00);
  register.writeUInt8(0x2c, 0x03);
  register.writeUInt32BE(TOKEN, 0x04);
  register.subarray(0x10).write('maker', 0x00, 'latin1');
  register.subarray(0x10).write('maker@cee-auth', 0x28, 'latin1');
  register.subarray(0x10).writeUInt16BE(0, 0x78);
  trailer.copy(register, 150);

  /*
   * The 566-byte POST-LOBBY SNAPSHOT, not the 330-byte bind. This is the message
   * that opens the post-selection session - and therefore the moment a presence
   * is created. The 330-byte bind arms the TCP transcript and deliberately does
   * not.
   */
  const snapshot = Buffer.alloc(570);
  snapshot.writeUInt16BE(0x3236, 0x00);
  snapshot.writeUInt8(0x01, 0x03);
  snapshot.writeUInt32BE(TOKEN, 0x04);
  const snapshotBody = snapshot.subarray(0x10);
  Buffer.from([127, 0, 0, 1]).copy(snapshotBody, 0x00);
  snapshotBody.writeUInt32BE(0xf0, 0x04);
  snapshotBody.writeUInt32BE(0xf7e00001, 0x08);
  snapshotBody.writeUInt16BE(2000, 0x0c);
  snapshotBody.writeUInt16BE(100, 0x0e);
  snapshotBody.write('maker-', 0x10, 'latin1');
  snapshotBody.writeUInt32BE(0xcaf3, 0x20);
  snapshotBody.writeUInt16BE(1, 0x218);
  snapshotBody.write('LC', 0x21a, 'latin1');
  snapshotBody.writeUInt32BE(1600, 0x21c);
  trailer.copy(snapshot, 566);

  assert.equal((await collect(register, 400)).length, 1, 'register answered');
  const bindReplies = await collect(snapshot, 400);
  assert.ok(bindReplies.length >= 2, `snapshot answered: ${bindReplies.length} replies`);

  // PRESENCE AT BIND-ACCEPT: the player is on the server before entering
  // anything, which is what makes a server-level count possible at all.
  assert.equal(application.presence.totalAttached(), 1);
  assert.equal(application.snapLobbySessions.playersOnServer(), 1);
  assert.equal(application.snapLobbySessions.playersIn(1), 0);


  const reliable = (opcode, sequence, payload = Buffer.alloc(0)) => {
    const inner = 0x10 + payload.length;
    const datagram = Buffer.alloc(inner + 4);
    datagram.writeUInt16BE(0xb000 | inner, 0);
    datagram.writeUInt8(opcode, 3);
    datagram.writeUInt32BE(TOKEN, 4);
    datagram.writeUInt32BE(sequence, 8);
    payload.copy(datagram, 0x10);
    trailer.copy(datagram, inner);
    return datagram;
  };

  /*
   * The client's next reliable sequence continues the epoch the bind seeded, so
   * it is read from the live channel rather than guessed - guessing it would put
   * these messages outside the receive window and the test would prove nothing
   * about the handler.
   */
  const session = application.snapLobbySessions.get('127.0.0.1:' + udp.address().port);
  assert.ok(session, 'the bind opened a post-selection session for this endpoint');
  const base = session.channel.receiveBase;

  // ENTER area 1, so the create has somewhere to go.
  const enterKey = Buffer.alloc(4);
  enterKey.writeUInt32BE(1);
  await collect(reliable(0x06, base, enterKey), 300);
  assert.equal(application.snapLobbySessions.playersIn(1), 1, 'the ENTER moved the presence');

  const createRequest = Buffer.alloc(0x2c);
  createRequest.write('COMPOSED', 0x00, 'latin1');
  createRequest.writeUInt32BE(4, 0x10);
  const replies = await collect(reliable(0x04, base + 1, createRequest), 400);

  const accepts = replies.filter((reply) => reply.length >= 0x1c && reply[0x03] === 0x28 &&
    reply.readUInt32BE(0x10) === 4);
  assert.equal(accepts.length, 1, 'exactly one op-0x28 selector-4 completion left the socket');

  const room = application.lobbyRooms.roomsIn(1)[0];
  assert.ok(room, 'the composed application\'s room registry holds the new room');
  assert.equal(room.name, 'COMPOSED');
  assert.equal(accepts[0].readUInt32BE(0x14), room.handle, 'the handle is BE32 on the wire');
  assert.equal(room.current, 1, 'population is derived: the creator is in it');
  assert.equal(application.presence.countInRoom(room.handle), 1);

  // And the back-out the owner reported: op-0x07 must be answered with selector
  // 7, and the emptied room must go with it.
  const leaveReplies = await collect(reliable(0x07, base + 2), 400);
  const leaveAccepts = leaveReplies.filter((reply) => reply.length >= 0x1c &&
    reply[0x03] === 0x28 && reply.readUInt32BE(0x10) === 7);
  assert.equal(leaveAccepts.length, 1, 'op-0x07 is answered; without it the client parks forever');
  assert.equal(application.lobbyRooms.roomsIn(1).length, 0, 'the emptied room closed itself');
  application.presence.assertConsistent();
});
