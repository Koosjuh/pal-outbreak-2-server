import test from 'node:test';
import assert from 'node:assert/strict';

import {
  ACCOUNT_PROOF,
  AccountSessionError,
  AccountSessionRegistry
} from '../src/sessions/account-session.js';
import { ConnectionIdentityRegistry } from '../src/sessions/connection-identity.js';
import {
  TCP10127_DIRECTION,
  decodeTcp10127Frame,
  encodeTcp10127Frame
} from '../src/protocol/tcp10127-codec.js';
import {
  TCP10127_LOBBY_INITIALIZATION_STATE,
  Tcp10127LobbyInitializationSession
} from '../src/tcp/lobby-initialization-session.js';
import { createV1ObservedAreaTable } from '../src/state/area-table-v1.js';

/**
 * R-019, the resume connection.
 *
 * After a completed lobby initialization the client resets and reopens on a
 * fresh source port whose FIRST frame is `0x6501` - there is no second
 * `0x1007`. Observed 2026-08-04 on the wire: the ladder completed at 18:10:26
 * and the client reconnected at 18:10:41 (port 1245) with
 * `0004 01 6501 b4 00 ff 00000000`.
 *
 * The two frames differ ONLY in the sequence byte - fresh `0x0a`, resume `0xb4`
 * - and their 4-byte payloads are both `00000000`. So the sequence is the only
 * protocol-carried state available, and it is used as a replay filter; one byte
 * cannot be an identity. Resolution is otherwise the source address as a FILTER
 * plus exactly-one-candidate, with ambiguity refused.
 */
const CAPTURED_RESUME_6501 = '0004016501b400ff00000000';
const CAPTURED_FRESH_6501 = '0004016501' + '0a' + '00ff00000000';

function resumeFrame(sequence = 0xb4) {
  return decodeTcp10127Frame(
    encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.CLIENT_REQUEST,
      command: 0x6501,
      sequence,
      payload: Buffer.alloc(4)
    })
  );
}

function fixture({ clock = () => Date.now(), resumeWindowMs } = {}) {
  const accountSessions = new AccountSessionRegistry({ clock, resumeWindowMs });
  const identity = new ConnectionIdentityRegistry({
    sessionLookup: () => null,
    accountSessions,
    clock
  });
  return { accountSessions, identity };
}

/**
 * A session that has been established, claimed and completed initialization,
 * then released because the client reset - exactly the state the captures show
 * just before a resume arrives.
 *
 * It claims by explicit id rather than through `resolveForLobby`, because
 * building TWO such sessions at one address is a state the fresh path refuses
 * to create for itself (it is ambiguous). Constructing it directly is the only
 * way to test what the RESUME path does when it happens.
 */
function completedSession(fixtureRefs, { userid, address }) {
  const { accountSessions, identity } = fixtureRefs;
  const { session } = accountSessions.establish({ userid, sourceAddress: address });
  const first = identity.openConnection({ remote: { address, port: 1244 } });
  accountSessions.claim({
    accountSessionId: session.accountSessionId,
    connectionRef: first
  });
  identity.markInitializationComplete(first, { resumed: false });
  accountSessions.releaseClaim(first);
  identity.closeConnection(first);
  return first;
}

function lobbySession({ associateResumeSession = null } = {}) {
  return new Tcp10127LobbyInitializationSession({
    areaTable: createV1ObservedAreaTable(),
    associateResumeSession,
    resolveCommand6212Value: () => 1,
    resolveCommand6211Value: () => 0,
    resolveCommand6213Words: () => Array(8).fill(0),
    resolveCommand6501Response: () => ({ mode: 0 }),
    resolveCommand6502Response: () => ({ mode: 1, unknown0: 1, unknown1: 1 }),
    resolveCommand6504Response: () => ({ records: [] }),
    resolveCommand6510Response: () => ({ words: [], trailing: Buffer.alloc(0) })
  });
}

test('the resume differs from the fresh 0x6501 only in its sequence byte', () => {
  // Decode BOTH captured frames and compare, rather than asserting a property
  // of one and naming it a comparison.
  const resume = decodeTcp10127Frame(Buffer.from(CAPTURED_RESUME_6501, 'hex'));
  const fresh = decodeTcp10127Frame(Buffer.from(CAPTURED_FRESH_6501, 'hex'));

  assert.equal(resume.command, fresh.command);
  assert.equal(resume.payloadLength, fresh.payloadLength);
  assert.equal(resume.unknown7, fresh.unknown7);
  assert.equal(
    resume.payload.toString('hex'),
    fresh.payload.toString('hex'),
    'the payload identifies nothing'
  );
  assert.notEqual(resume.sequence, fresh.sequence, 'the sequence is the one thing that differs');
  assert.equal(resume.sequence, 0xb4);
  assert.equal(fresh.sequence, 0x0a);
});

test('a verbatim frame replay is refused by the sequence filter', () => {
  const refs = fixture();
  completedSession(refs, { userid: 'test123', address: '192.0.2.248' });

  const first = refs.identity.openConnection({ remote: { address: '192.0.2.248', port: 1245 } });
  refs.identity.associateResumeConnection({ connectionRef: first, sequence: 0xb4 });
  refs.identity.closeConnection(first);

  // The exact same frame, replayed. The session is free again, but the sequence
  // it already accepted is not usable twice.
  const replay = refs.identity.openConnection({ remote: { address: '192.0.2.248', port: 1246 } });
  assert.throws(
    () => refs.identity.associateResumeConnection({ connectionRef: replay, sequence: 0xb4 }),
    (error) => error.code === 'DUPLICATE_RESUME_SEQUENCE'
  );
  // A different sequence, as a genuine reconnect would carry, is accepted.
  const genuine = refs.identity.openConnection({ remote: { address: '192.0.2.248', port: 1247 } });
  assert.equal(
    refs.identity.associateResumeConnection({ connectionRef: genuine, sequence: 0xb5 }).userid,
    'test123'
  );
});

test('a malformed 0x6501 does not claim a session before being refused', () => {
  // It used to: the association ran before validation, so a bad frame briefly
  // took a live session - a resume denial-of-service against that player.
  let associated = 0;
  const session = lobbySession({ associateResumeSession: () => { associated += 1; } });
  const malformed = decodeTcp10127Frame(
    encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.CLIENT_REQUEST,
      command: 0x6501,
      sequence: 0xb4,
      payload: Buffer.alloc(0)
    })
  );
  assert.throws(
    () => session.handleFrame(malformed),
    (error) => error.code === 'COMMAND_6501_LENGTH'
  );
  assert.equal(associated, 0, 'nothing was claimed');
});

/* ---- successful resume ---------------------------------------------------- */

test('a resume attaches the new transport to the EXISTING session', () => {
  const refs = fixture();
  completedSession(refs, { userid: 'test123', address: '192.0.2.248' });
  const before = refs.accountSessions.findByUserId('test123');

  const resumeRef = refs.identity.openConnection({
    remote: { address: '192.0.2.248', port: 1245 }
  });
  const record = refs.identity.associateResumeConnection({ connectionRef: resumeRef });

  assert.equal(record.userid, 'test123');
  assert.equal(record.resumed, true);
  assert.equal(
    record.accountSessionId,
    before.accountSessionId,
    'the same session, not a new identity'
  );
  const after = refs.accountSessions.findByUserId('test123');
  assert.equal(after.resumeCount, 1);
  assert.notEqual(
    after.initializationCompletedAtMs,
    null,
    'the completed-initialization state is preserved'
  );
});

test('the lobby session takes a distinct entry path for 0x6501', () => {
  let associated = 0;
  const session = lobbySession({ associateResumeSession: () => { associated += 1; } });
  assert.equal(session.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_LOBBY_INIT_REQUEST);

  const result = session.handleFrame(resumeFrame());
  assert.notEqual(result, null, 'the resume is answered');
  assert.equal(associated, 1, 'identity was resolved through the resume path');
  assert.notEqual(session.state, TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_LOBBY_INIT_REQUEST);
});

/* ---- refusals ------------------------------------------------------------- */

test('no eligible session: a resume is refused', () => {
  const refs = fixture();
  const resumeRef = refs.identity.openConnection({
    remote: { address: '192.0.2.248', port: 1245 }
  });
  assert.throws(
    () => refs.identity.associateResumeConnection({ connectionRef: resumeRef }),
    (error) => error.code === 'NO_RESUMABLE_SESSION'
  );
});

test('a session that never completed initialization is not resumable', () => {
  // The guard that stops a resume being a second, weaker way into an account.
  const refs = fixture();
  refs.accountSessions.establish({ userid: 'test123', sourceAddress: '192.0.2.248' });

  const resumeRef = refs.identity.openConnection({
    remote: { address: '192.0.2.248', port: 1245 }
  });
  assert.throws(
    () => refs.identity.associateResumeConnection({ connectionRef: resumeRef }),
    (error) => error.code === 'NO_RESUMABLE_SESSION'
  );
});

test('an expired completed session is refused', () => {
  let now = 1_000_000;
  const refs = fixture({ clock: () => now, resumeWindowMs: 60_000 });
  completedSession(refs, { userid: 'test123', address: '192.0.2.248' });

  now += 60_001;
  const resumeRef = refs.identity.openConnection({
    remote: { address: '192.0.2.248', port: 1245 }
  });
  assert.throws(
    () => refs.identity.associateResumeConnection({ connectionRef: resumeRef }),
    (error) => error.code === 'NO_RESUMABLE_SESSION'
  );
});

test('two completed sessions at ONE address are refused, not guessed', () => {
  const refs = fixture();
  completedSession(refs, { userid: 'alice', address: '203.0.113.9' });
  completedSession(refs, { userid: 'bob', address: '203.0.113.9' });

  const resumeRef = refs.identity.openConnection({
    remote: { address: '203.0.113.9', port: 1245 }
  });
  assert.throws(
    () => refs.identity.associateResumeConnection({ connectionRef: resumeRef }),
    (error) => error.code === 'AMBIGUOUS_RESUMABLE_SESSION'
  );
});

test('an attacker from a DIFFERENT address cannot attach', () => {
  const refs = fixture();
  completedSession(refs, { userid: 'victim', address: '192.0.2.248' });

  // Someone else, from somewhere else, cannot attach to the victim's session.
  const attacker = refs.identity.openConnection({
    remote: { address: '203.0.113.7', port: 1245 }
  });
  assert.throws(
    () => refs.identity.associateResumeConnection({ connectionRef: attacker }),
    (error) => error.code === 'NO_RESUMABLE_SESSION'
  );
  // And the victim can still resume.
  const victim = refs.identity.openConnection({
    remote: { address: '192.0.2.248', port: 1246 }
  });
  assert.equal(
    refs.identity.associateResumeConnection({ connectionRef: victim }).userid,
    'victim'
  );
});

/* ---- replay and double resume --------------------------------------------- */

test('a replayed 0x6501 on a second connection cannot steal the session', () => {
  const refs = fixture();
  completedSession(refs, { userid: 'test123', address: '192.0.2.248' });

  const first = refs.identity.openConnection({ remote: { address: '192.0.2.248', port: 1245 } });
  assert.equal(refs.identity.associateResumeConnection({ connectionRef: first }).userid, 'test123');

  // The same frame replayed from the same address on a NEW connection: the
  // session is already attached, so there is nothing to resume.
  const replay = refs.identity.openConnection({ remote: { address: '192.0.2.248', port: 1246 } });
  assert.throws(
    () => refs.identity.associateResumeConnection({ connectionRef: replay }),
    (error) => error.code === 'NO_RESUMABLE_SESSION'
  );
});

test('a second resume attempt on the SAME connection is refused', () => {
  const refs = fixture();
  completedSession(refs, { userid: 'test123', address: '192.0.2.248' });
  const resumeRef = refs.identity.openConnection({
    remote: { address: '192.0.2.248', port: 1245 }
  });
  refs.identity.associateResumeConnection({ connectionRef: resumeRef });

  assert.throws(
    () => refs.identity.associateResumeConnection({ connectionRef: resumeRef }),
    (error) => error.code === 'NO_RESUMABLE_SESSION',
    'the session is attached to this very connection already'
  );
});

test('a resume that closes may be resumed again by the same player', () => {
  // Not a replay: the client legitimately reconnects, and closing releases the
  // attachment exactly as it does for the first lobby connection.
  const refs = fixture();
  completedSession(refs, { userid: 'test123', address: '192.0.2.248' });

  const first = refs.identity.openConnection({ remote: { address: '192.0.2.248', port: 1245 } });
  refs.identity.associateResumeConnection({ connectionRef: first });
  refs.identity.closeConnection(first);

  const second = refs.identity.openConnection({ remote: { address: '192.0.2.248', port: 1246 } });
  assert.equal(refs.identity.associateResumeConnection({ connectionRef: second }).userid, 'test123');
  assert.equal(refs.accountSessions.findByUserId('test123').resumeCount, 2);
});

test('a refused resume is not answered by the lobby session either', () => {
  const session = lobbySession({
    associateResumeSession: () => {
      const error = new Error('no completed lobby initialization from this source');
      error.code = 'NO_RESUMABLE_SESSION';
      throw error;
    }
  });
  assert.throws(
    () => session.handleFrame(resumeFrame()),
    (error) => error.code === 'NO_RESUMABLE_SESSION'
  );
});

test('0x6501 without a resume associator is refused rather than served anonymously', () => {
  const session = lobbySession();
  assert.throws(
    () => session.handleFrame(resumeFrame()),
    (error) => error.code === 'LOBBY_RESUME_UNSUPPORTED'
  );
});

/* ---- the fresh path is unchanged ------------------------------------------ */

test('a fresh connection still requires 0x1007, and 0x6110 is still refused', () => {
  const session = lobbySession({ associateResumeSession: () => {} });
  const notLobbyInit = decodeTcp10127Frame(
    encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.CLIENT_REQUEST,
      command: 0x6110,
      sequence: 1,
      payload: Buffer.alloc(0)
    })
  );
  assert.throws(
    () => session.handleFrame(notLobbyInit),
    (error) => error.code === 'LOBBY_INIT_COMMAND',
    '0x6110 is a separate RE slice and must not be answered by accident'
  );
});

test('the fresh 0x1007 path still resolves through the normal associator', () => {
  const refs = fixture();
  refs.accountSessions.establish({ userid: 'fresh', sourceAddress: '192.0.2.248' });
  const connectionRef = refs.identity.openConnection({
    remote: { address: '192.0.2.248', port: 1244 }
  });
  const record = refs.identity.associateConnection({
    connectionRef,
    dnasToken: 'KLa0ZocQ6MWC3ADgVYbw2h69t0MsMnF5Z4OmwnhY3zc='
  });
  assert.equal(record.userid, 'fresh');
  assert.notEqual(record.resumed, true, 'a fresh connection is not a resume');
});

test('ACCEPTED RISK: an attacker sharing the source address can take the session', () => {
  // Recorded as a test so it cannot be forgotten, and named for what it is.
  //
  // Exactly-one protects against choosing between two candidates. It does
  // nothing against an outsider taking the only one, and the resume presents no
  // credential, no token and a one-byte sequence - the protocol offers nothing
  // else to bind to. Mitigated by narrowing the window to the observed
  // reconnect gap plus margin, and by refusing a replayed sequence; not solved.
  //
  // Same class of accepted cost as the register being the authentication event.
  const refs = fixture();
  completedSession(refs, { userid: 'victim', address: '192.0.2.248' });

  const attacker = refs.identity.openConnection({
    remote: { address: '192.0.2.248', port: 4444 }
  });
  const stolen = refs.identity.associateResumeConnection({
    connectionRef: attacker,
    sequence: 0x99
  });
  assert.equal(stolen.userid, 'victim', 'this is the accepted residual risk, not a passing grade');

  // And the consequence: the real player is then locked out until it releases.
  const victim = refs.identity.openConnection({
    remote: { address: '192.0.2.248', port: 1245 }
  });
  assert.throws(
    () => refs.identity.associateResumeConnection({ connectionRef: victim, sequence: 0xb4 }),
    (error) => error.code === 'NO_RESUMABLE_SESSION'
  );
});

test('the resume window is narrow, not minutes', async () => {
  const { AccountSessionRegistry } = await import('../src/sessions/account-session.js');
  let now = 1_000_000;
  const sessions = new AccountSessionRegistry({ clock: () => now });
  const { session } = sessions.establish({ userid: 'a', sourceAddress: '10.0.0.1' });
  sessions.claim({ accountSessionId: session.accountSessionId, connectionRef: 'c1' });
  sessions.markInitializationComplete('c1', { resumed: false });
  sessions.releaseClaim('c1');

  // The observed reconnect gap is ~15 s, so this must still resolve.
  now += 20_000;
  assert.notEqual(sessions.resolveForResume({ sourceAddress: '10.0.0.1' }).session, undefined);

  // A minute later it must not - every second is an opening for anyone sharing
  // the address.
  now += 40_000;
  assert.equal(
    sessions.resolveForResume({ sourceAddress: '10.0.0.1' }).code,
    'NO_RESUMABLE_SESSION'
  );
});

/* ---- lifecycle hardening -------------------------------------------------- */

test('twenty resumes below the old sliding timeout do NOT extend the window', () => {
  // Review drove exactly this and found the session still resumable 800 s after
  // the original completion, because markInitializationComplete re-armed on
  // every resumed ladder. The deadline is now absolute.
  let now = 1_000_000;
  const refs = fixture({ clock: () => now });
  completedSession(refs, { userid: 'slider', address: '10.0.0.1' });
  const completedAt = refs.accountSessions.findByUserId('slider').initializationCompletedAtMs;

  for (let attempt = 0; attempt < 20; attempt += 1) {
    now += 40_000;
    const ref = refs.identity.openConnection({ remote: { address: '10.0.0.1', port: attempt } });
    try {
      refs.identity.associateResumeConnection({ connectionRef: ref, sequence: attempt });
      // A RESUMED ladder ends in 0x1004 just like a fresh one; it must not
      // slide the deadline. That distinction is the whole fix.
      refs.accountSessions.markInitializationComplete(ref, { resumed: true });
      refs.identity.closeConnection(ref);
    } catch {
      // Expected once the window or the attempt budget closes.
    }
  }

  const session = refs.accountSessions.findByUserId('slider');
  if (session != null) {
    assert.equal(
      session.initializationCompletedAtMs,
      completedAt,
      'a resumed ladder must not slide the deadline'
    );
  }
  // 800 s after completion nothing is resumable, whatever happened in between.
  const late = refs.identity.openConnection({ remote: { address: '10.0.0.1', port: 999 } });
  assert.throws(
    () => refs.identity.associateResumeConnection({ connectionRef: late, sequence: 0x7f }),
    (error) => error.code === 'NO_RESUMABLE_SESSION' || error.code === 'RESUME_ATTEMPTS_EXHAUSTED'
  );
});

test('alternating sequence bytes do not buy unlimited resumes', () => {
  // The sequence check is duplicate suppression, not replay protection: review
  // defeated it with 45,000 resumes alternating 0x00/0x01. The attempt budget
  // is the actual bound.
  const refs = fixture();
  completedSession(refs, { userid: 'alt', address: '10.0.0.2' });

  let accepted = 0;
  for (let attempt = 0; attempt < 50; attempt += 1) {
    const ref = refs.identity.openConnection({ remote: { address: '10.0.0.2', port: attempt } });
    try {
      refs.identity.associateResumeConnection({ connectionRef: ref, sequence: attempt % 2 });
      accepted += 1;
      refs.identity.closeConnection(ref);
    } catch {
      break;
    }
  }
  assert.ok(accepted <= 3, `bounded, got ${accepted} accepted resumes`);
});

test('a refused resume still consumes its attempt', () => {
  const refs = fixture();
  completedSession(refs, { userid: 'charge', address: '10.0.0.3' });

  // Hold the session so every following attempt is refused, and confirm the
  // budget is charged rather than drainable for free.
  const holder = refs.identity.openConnection({ remote: { address: '10.0.0.3', port: 1 } });
  refs.identity.associateResumeConnection({ connectionRef: holder, sequence: 1 });
  assert.equal(refs.accountSessions.findByUserId('charge').resumeAttempts, 1);
});

test('a released lobby session cannot be resurrected by a stale reference', async () => {
  const { LobbySession } = await import('../src/sessions/lobby-session.js');
  let closed = 0;
  const session = new LobbySession({
    accountSessionId: 'as-x',
    userid: 'ghost',
    projection: { close: () => { closed += 1; } }
  });
  session.attachTransport('t1');

  assert.equal(session.terminate(), true);
  assert.equal(session.released, true);
  assert.equal(closed, 1);
  // Idempotent: a second termination releases nothing twice.
  assert.equal(session.terminate(), false);
  assert.equal(closed, 1);
  // And the stale reference is inert.
  assert.throws(() => session.projection, (error) => error.code === 'LOBBY_SESSION_TERMINATED');
  assert.throws(() => session.attachTransport('t2'), (error) => error.code === 'LOBBY_SESSION_TERMINATED');
  assert.equal(session.ownsTransport('t1'), false);
});

test('the release hook fires exactly once per session, on every path', async () => {
  const { AccountSessionRegistry } = await import('../src/sessions/account-session.js');
  const released = [];
  let now = 1_000_000;
  const sessions = new AccountSessionRegistry({
    clock: () => now,
    ttlMs: 60_000,
    onSessionReleased: (session) => released.push(session.userid)
  });

  // displacement - which takes proof of the account, or it is refused
  sessions.establish({ userid: 'a', sourceAddress: '10.0.0.1' });
  sessions.establish({
    userid: 'a', sourceAddress: '10.0.0.1', proof: ACCOUNT_PROOF.REGISTRATION_NONCE
  });
  assert.deepEqual(released, ['a'], 'displacement releases once');

  // explicit removal, and a repeat is a no-op
  const { session: b } = sessions.establish({ userid: 'b', sourceAddress: '10.0.0.2' });
  assert.equal(sessions.remove(b.accountSessionId), true);
  assert.equal(sessions.remove(b.accountSessionId), false, 'idempotent');
  assert.deepEqual(released, ['a', 'b']);

  // expiry, via the deterministic sweep rather than a lookup. Account 'a' still
  // has a live session from the displacement above, so it expires here too -
  // exactly once more.
  sessions.establish({ userid: 'c', sourceAddress: '10.0.0.3' });
  now += 60_001;
  sessions.sweepNow();
  assert.equal(released.filter((id) => id === 'c').length, 1, 'expiry releases once');
  assert.equal(released.filter((id) => id === 'a').length, 2, 'displaced once, then expired once');
  assert.equal(sessions.size, 0);

  // A second sweep releases nothing: the table is already empty.
  const beforeSecondSweep = released.length;
  sessions.sweepNow();
  assert.equal(released.length, beforeSecondSweep, 'repeated cleanup is idempotent');

  // shutdown
  sessions.establish({ userid: 'd', sourceAddress: '10.0.0.4' });
  sessions.clear();
  sessions.clear();
  assert.equal(released.filter((id) => id === 'd').length, 1, 'shutdown releases once, and only once');
});

test('hundreds of sessions do not accumulate retained state', async () => {
  const { AccountSessionRegistry } = await import('../src/sessions/account-session.js');
  const live = new Set();
  let now = 1_000_000;
  const sessions = new AccountSessionRegistry({
    clock: () => now,
    ttlMs: 60_000,
    onSessionReleased: (session) => live.delete(session.accountSessionId)
  });

  for (let index = 0; index < 400; index += 1) {
    const { session } = sessions.establish({
      userid: `p${index}`,
      sourceAddress: `10.${Math.floor(index / 254)}.0.${(index % 254) + 1}`
    });
    live.add(session.accountSessionId);
  }
  assert.equal(live.size, 400);
  assert.equal(sessions.size, 400);

  // Re-establishing every account displaces its predecessor: no growth. Each
  // one proves the account, as a real returning player's bind does.
  for (let index = 0; index < 400; index += 1) {
    const { session } = sessions.establish({
      userid: `p${index}`,
      sourceAddress: `10.${Math.floor(index / 254)}.0.${(index % 254) + 1}`,
      proof: ACCOUNT_PROOF.REGISTRATION_NONCE
    });
    live.add(session.accountSessionId);
  }
  assert.equal(sessions.size, 400, 'displaced, not accumulated');
  assert.equal(live.size, 400, 'and every displaced session was released');

  now += 60_001;
  sessions.sweepNow();
  assert.equal(sessions.size, 0);
  assert.equal(live.size, 0, 'nothing retained after expiry');
});

test('an unproven establishment cannot take a live session away from its owner', () => {
  /*
   * D-2 at the layer that owns the rule; composition.test.js drives the same
   * property over real sockets. An establishment that proves nothing about the
   * account is refused outright rather than being allowed to displace: it must
   * neither destroy the live session nor be handed one of its own, because
   * either would mean naming an account was enough to take it.
   */
  const released = [];
  const sessions = new AccountSessionRegistry({
    onSessionReleased: (session) => released.push(session.accountSessionId)
  });
  const { session: live } = sessions.establish({
    userid: 'victim', sourceAddress: '10.0.0.1', proof: ACCOUNT_PROOF.REGISTRATION_NONCE
  });

  assert.throws(
    () => sessions.establish({ userid: 'victim', sourceAddress: '10.0.0.9' }),
    (error) => error instanceof AccountSessionError &&
      error.code === 'ACCOUNT_DISPLACEMENT_UNPROVEN'
  );
  assert.deepEqual(released, [], 'nothing was released, so no lobby session was terminated');
  assert.equal(sessions.findByUserId('victim').accountSessionId, live.accountSessionId);
  assert.equal(sessions.size, 1, 'and no second session was minted for the account');

  // Either proof displaces. Both are evidence about the ACCOUNT: the scrypt
  // check on the HTTP request, or a bind echoing a nonce that only the password
  // could have decrypted.
  for (const proof of [ACCOUNT_PROOF.PASSWORD_VERIFIED, ACCOUNT_PROOF.REGISTRATION_NONCE]) {
    const before = sessions.findByUserId('victim').accountSessionId;
    const { displaced } = sessions.establish({
      userid: 'victim', sourceAddress: '10.0.0.1', proof
    });
    assert.equal(displaced.accountSessionId, before, `${proof} displaces`);
  }

  // A proof value nobody defined is a programming error, not an attack, and it
  // says so instead of hiding inside the refusal above.
  assert.throws(
    () => sessions.establish({ userid: 'fresh', sourceAddress: '10.0.0.1', proof: 'trust-me' }),
    (error) => error.code === 'ACCOUNT_PROOF_UNKNOWN'
  );

  // Establishing when NOTHING is live needs no proof: it takes nothing away.
  // That remains the accepted cost of the register being the authentication
  // event, recorded in account-session.js rather than widened here.
  const fresh = sessions.establish({ userid: 'nobody-live', sourceAddress: '10.0.0.2' });
  assert.equal(fresh.displaced, null);
  assert.equal(fresh.session.proof, ACCOUNT_PROOF.NONE, 'and the session records that');
});

test('an exhausted session does not misreport UNRELATED refusals', () => {
  // The attempts check used to run before the address/claim/window filters, so
  // ONE exhausted session anywhere made every refusal on the server report
  // RESUME_ATTEMPTS_EXHAUSTED - a wrong diagnostic on the rig, no attacker
  // needed.
  const refs = fixture();
  completedSession(refs, { userid: 'burned', address: '9.9.9.9' });
  for (let attempt = 0; attempt < 3; attempt += 1) {
    const ref = refs.identity.openConnection({ remote: { address: '9.9.9.9', port: attempt } });
    try {
      refs.identity.associateResumeConnection({ connectionRef: ref, sequence: attempt });
      refs.identity.closeConnection(ref);
    } catch { /* budget exhausts */ }
  }

  // A completely unrelated address with nothing waiting must say so.
  const stranger = refs.identity.openConnection({ remote: { address: '8.8.8.8', port: 1 } });
  assert.throws(
    () => refs.identity.associateResumeConnection({ connectionRef: stranger, sequence: 5 }),
    (error) => error.code === 'NO_RESUMABLE_SESSION',
    'an unrelated refusal must not be reported as exhausted'
  );
});

test('a FRESH initialization clears the attempt budget and re-arms the deadline', () => {
  // Recovery has to actually work. resumeAttempts was set once and never reset,
  // so an account stayed unresumable for its whole 30-minute TTL while the
  // refusal text named a recovery that did nothing.
  let now = 1_000_000;
  const refs = fixture({ clock: () => now });
  completedSession(refs, { userid: 'recover', address: '10.0.0.7' });

  for (let attempt = 0; attempt < 3; attempt += 1) {
    const ref = refs.identity.openConnection({ remote: { address: '10.0.0.7', port: attempt } });
    try {
      refs.identity.associateResumeConnection({ connectionRef: ref, sequence: attempt });
      refs.identity.closeConnection(ref);
    } catch { /* exhausts */ }
  }
  assert.equal(refs.accountSessions.findByUserId('recover').resumeAttempts, 3);

  // A fresh 0x1007 ladder: a new evidenced event, not a continuation.
  now += 5_000;
  const fresh = refs.identity.openConnection({ remote: { address: '10.0.0.7', port: 50 } });
  refs.accountSessions.claim({
    accountSessionId: refs.accountSessions.findByUserId('recover').accountSessionId,
    connectionRef: fresh
  });
  refs.identity.markInitializationComplete(fresh, { resumed: false });
  refs.accountSessions.releaseClaim(fresh);
  refs.identity.closeConnection(fresh);

  const recovered = refs.accountSessions.findByUserId('recover');
  assert.equal(recovered.resumeAttempts, 0, 'the budget is cleared');
  assert.equal(recovered.initializationCompletedAtMs, now, 'and the deadline is re-armed');

  const again = refs.identity.openConnection({ remote: { address: '10.0.0.7', port: 51 } });
  assert.equal(
    refs.identity.associateResumeConnection({ connectionRef: again, sequence: 0x40 }).userid,
    'recover'
  );
});

test('a RESUMED initialization clears nothing and slides nothing', () => {
  let now = 1_000_000;
  const refs = fixture({ clock: () => now });
  completedSession(refs, { userid: 'noslide', address: '10.0.0.8' });
  const completedAt = refs.accountSessions.findByUserId('noslide').initializationCompletedAtMs;

  const ref = refs.identity.openConnection({ remote: { address: '10.0.0.8', port: 1 } });
  refs.identity.associateResumeConnection({ connectionRef: ref, sequence: 1 });
  now += 5_000;
  refs.identity.markInitializationComplete(ref, { resumed: true });

  const session = refs.accountSessions.findByUserId('noslide');
  assert.equal(session.initializationCompletedAtMs, completedAt, 'deadline unchanged');
  assert.equal(session.resumeAttempts, 1, 'budget not refunded');
});

test('an exhausted session must not mask an EXPIRED-WINDOW refusal from its own source', () => {
  // a4a64d66 moved the attempt check below the claimed and source-address
  // filters but left it ABOVE the window filter, while its commit message
  // claimed it now ran "only for sessions that are otherwise candidates for
  // this source". Review demonstrated the gap: a session whose 45 s window
  // lapsed 75 s earlier still poisoned the diagnostic for its own address, for
  // the rest of its 30-minute TTL. On a single-client rig - one client, one
  // address - that is exactly the misdiagnosis the reorder was meant to remove.
  let now = 1_000_000;
  const refs = fixture({ clock: () => now });
  completedSession(refs, { userid: 'stale', address: '10.0.0.9' });

  for (let attempt = 0; attempt < 3; attempt += 1) {
    const ref = refs.identity.openConnection({ remote: { address: '10.0.0.9', port: attempt } });
    try {
      refs.identity.associateResumeConnection({ connectionRef: ref, sequence: attempt });
      refs.identity.closeConnection(ref);
    } catch { /* exhausts the budget */ }
  }

  now += 120_000; // far outside the 45 s resume window
  const late = refs.identity.openConnection({ remote: { address: '10.0.0.9', port: 90 } });
  assert.throws(
    () => refs.identity.associateResumeConnection({ connectionRef: late, sequence: 0x55 }),
    (error) => error.code === 'NO_RESUMABLE_SESSION',
    'the true reason is the expired window, not the spent budget'
  );
});

test('an exhausted session must not mask a DUPLICATE-SEQUENCE refusal', async () => {
  // The other filter the attempt check used to precede. A verbatim
  // retransmission is duplicate suppression, and reporting "attempts exhausted"
  // sends the next reader hunting for an attacker that is not there.
  //
  // Driven against the registry directly and deliberately. Going through
  // `associateResumeConnection` would resolve AND resume, and a successful
  // resume overwrites `lastResumeSequence` - so the replayed byte would no
  // longer be a duplicate and RESUME_ATTEMPTS_EXHAUSTED would be the CORRECT
  // answer. The ordering under test is the registry's, so exercise it there:
  // burn the remaining budget with resolves that never became resumes, which
  // is what a client that resolves and then drops actually does.
  const { AccountSessionRegistry } = await import('../src/sessions/account-session.js');
  let now = 1_000_000;
  const sessions = new AccountSessionRegistry({ clock: () => now });
  const { session } = sessions.establish({ userid: 'dup', sourceAddress: '10.0.0.10' });
  sessions.claim({ accountSessionId: session.accountSessionId, connectionRef: 'c1' });
  sessions.markInitializationComplete('c1', { resumed: false });
  sessions.releaseClaim('c1');

  // One real resume, so the session records 0xb4 as the sequence it accepted.
  const first = sessions.resolveForResume({ sourceAddress: '10.0.0.10', sequence: 0xb4 });
  sessions.resume({
    accountSessionId: first.session.accountSessionId,
    connectionRef: 'c2',
    sequence: 0xb4
  });
  sessions.releaseClaim('c2');
  // Two resolved-then-dropped attempts spend the rest of the budget without
  // changing the recorded sequence.
  sessions.resolveForResume({ sourceAddress: '10.0.0.10', sequence: 0x01 });
  sessions.resolveForResume({ sourceAddress: '10.0.0.10', sequence: 0x02 });
  assert.equal(sessions.findByUserId('dup').resumeAttempts, 3, 'the budget is spent');

  now += 1_000;
  const replay = sessions.resolveForResume({ sourceAddress: '10.0.0.10', sequence: 0xb4 });
  assert.equal(
    replay.code,
    'DUPLICATE_RESUME_SEQUENCE',
    'the true reason is duplicate suppression, not the spent budget'
  );
  assert.match(
    replay.refusal,
    /is waiting/,
    'and it must not claim nothing is waiting - a completed session from this source is'
  );
});

test('an exhausted session does not block a healthy one from the same source', () => {
  // The reorder must not cost the thing the exhausted bucket was for: an
  // exhausted session is skipped, not allowed to swallow a live candidate.
  const now = 1_000_000;
  const refs = fixture({ clock: () => now });
  completedSession(refs, { userid: 'spent', address: '10.0.0.11' });
  for (let attempt = 0; attempt < 3; attempt += 1) {
    const ref = refs.identity.openConnection({ remote: { address: '10.0.0.11', port: attempt } });
    try {
      refs.identity.associateResumeConnection({ connectionRef: ref, sequence: attempt });
      refs.identity.closeConnection(ref);
    } catch { /* exhausts */ }
  }
  completedSession(refs, { userid: 'healthy', address: '10.0.0.11' });

  const ref = refs.identity.openConnection({ remote: { address: '10.0.0.11', port: 92 } });
  assert.equal(
    refs.identity.associateResumeConnection({ connectionRef: ref, sequence: 0x77 }).userid,
    'healthy',
    'the live session still resolves past the exhausted one'
  );
});

test('markInitializationComplete refuses to guess whether this was fresh or resumed', async () => {
  // There is no safe default: false silently re-arms the deadline and clears
  // the budget (the unbounded-window bug), true silently withholds the only
  // recovery. Both have shipped. So the flag is required and it fails loud.
  const { AccountSessionRegistry } = await import('../src/sessions/account-session.js');
  const sessions = new AccountSessionRegistry({ clock: () => 1_000_000 });
  const { session } = sessions.establish({ userid: 'explicit', sourceAddress: '10.0.0.12' });
  sessions.claim({ accountSessionId: session.accountSessionId, connectionRef: 'k1' });

  assert.throws(
    () => sessions.markInitializationComplete('k1'),
    (error) => error.code === 'RESUMED_FLAG_REQUIRED'
  );
  assert.throws(
    () => sessions.markInitializationComplete('k1', { resumed: 'yes' }),
    (error) => error.code === 'RESUMED_FLAG_REQUIRED',
    'a truthy non-boolean is not consent either'
  );
});
