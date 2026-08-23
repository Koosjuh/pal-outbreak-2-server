import assert from 'node:assert/strict';
import test from 'node:test';

import {
  ConnectionIdentityError,
  ConnectionIdentityRegistry,
  normalizeDnasToken
} from '../src/sessions/connection-identity.js';
import { ACCOUNT_PROOF, AccountSessionRegistry } from '../src/sessions/account-session.js';
import { decodeSnapField } from '../src/protocol/snap-field-codec.js';
import { decodeTcp10127Frame } from '../src/protocol/tcp10127-codec.js';
import {
  TCP10127_LOBBY_INITIALIZATION,
  TCP10127_LOBBY_INITIALIZATION_STATE,
  Tcp10127LobbyInitializationSession
} from '../src/tcp/lobby-initialization-session.js';
import { createV1ObservedAreaTable } from '../src/state/area-table-v1.js';

// The DNAS token observed on the wire, identical in three emulator captures and
// one real PS2 capture, and identical to the `DNAS=` query parameter in
// docs/evidence/traces/protocol_trace.ndjson.
const CAPTURED_DNAS_TOKEN = 'KLa0ZocQ6MWC3ADgVYbw2h69t0MsMnF5Z4OmwnhY3zc=';

// Ignored raw captures; the first is real PS2 hardware, the rest emulator.
const CAPTURED_LOBBY_INIT_REQUESTS = [
  '0031011007ff00ff01002e0e48f9052e731422291f7c0c10087504062114003d246c356c672e611a281b3b1463085d200e19030237591b0456',
  '0031011007cf00ff01002e5e18c9d5fea3c4f2f9cfacdcc0d8a5d4d6f1c4f0cdd49cc59c97de91ead8ebcbe493f88df0dec9d3d2e789cbd486',
  '00310110070400ff01002e124d020029761f2f26127709170d6e19193c0f053a216738636a25641d2d20062b5e3358270b120e0d3a521e0353',
  '00310110074600ff01002e548f404267385d6d6054354b49532c5b5f7a4d47746f257a252c6726635362446d18711a6945504c4b7c105c5d0d'
];

/**
 * The identity model resolves a lobby connection against a GAME-ACCOUNT SESSION,
 * which the UDP-9090 register and bind establish. The DNAS token is not an
 * identity key: V2 mints it from a static replay asset, so every console
 * presents the same value (T27). These fixtures therefore establish an account
 * session the way the register does, and use the token only where a correlation
 * signal is what is under test.
 */
function createRegistry(sessions = new Map(), options = {}) {
  const accountSessions = new AccountSessionRegistry();
  return {
    sessions,
    accountSessions,
    registry: new ConnectionIdentityRegistry({
      sessionLookup: (id) => sessions.get(id) ?? null,
      accountSessions,
      ...options
    })
  };
}

test('every captured 0x1007 request carries the same DNAS token', () => {
  for (const hex of CAPTURED_LOBBY_INIT_REQUESTS) {
    const frame = decodeTcp10127Frame(Buffer.from(hex, 'hex'));
    const decoded = decodeSnapField({
      field: frame.payload.subarray(TCP10127_LOBBY_INITIALIZATION.identityFieldOffset),
      maximumDecodedLength: TCP10127_LOBBY_INITIALIZATION.identityFieldMaximumLength,
      sequence: frame.sequence,
      unknownCodecByte: TCP10127_LOBBY_INITIALIZATION.identityCodecByte
    });
    assert.notEqual(decoded, null, 'captured identity field must decode and checksum');
    assert.equal(decoded.toString('latin1'), CAPTURED_DNAS_TOKEN);
    // 44 base64 characters decode to exactly the 32-byte DNAS token.
    assert.equal(Buffer.from(decoded.toString('latin1'), 'base64').length, 32);
  }
});

test('decodeSnapField refuses a field whose checksum does not verify', () => {
  const frame = decodeTcp10127Frame(Buffer.from(CAPTURED_LOBBY_INIT_REQUESTS[1], 'hex'));
  const field = Buffer.from(frame.payload.subarray(1));
  // Any other codec byte must fail rather than yield plausible-looking bytes.
  for (const codecByte of [1, 2, 0x7f, 0xff]) {
    assert.equal(
      decodeSnapField({
        field,
        maximumDecodedLength: 44,
        sequence: frame.sequence,
        unknownCodecByte: codecByte
      }),
      null
    );
  }
  // A corrupted body must also fail.
  const corrupted = Buffer.from(field);
  corrupted[4] ^= 0x01;
  assert.equal(
    decodeSnapField({
      field: corrupted,
      maximumDecodedLength: 44,
      sequence: frame.sequence,
      unknownCodecByte: 0
    }),
    null
  );
});

test('normalizeDnasToken accepts the captured token and rejects near misses', () => {
  assert.equal(normalizeDnasToken(CAPTURED_DNAS_TOKEN), CAPTURED_DNAS_TOKEN);
  assert.equal(
    normalizeDnasToken(Buffer.from(CAPTURED_DNAS_TOKEN, 'base64')),
    CAPTURED_DNAS_TOKEN
  );
  for (const bad of [
    '',
    'not base64!!',
    Buffer.alloc(31).toString('base64'),
    Buffer.alloc(33).toString('base64'),
    CAPTURED_DNAS_TOKEN.slice(0, -1),
    42,
    null
  ]) {
    assert.throws(
      () => normalizeDnasToken(bad),
      (error) => error instanceof ConnectionIdentityError
    );
  }
});

test('separates connection, session and player identity', () => {
  const { sessions, registry, accountSessions } = createRegistry();
  sessions.set('7788', { connectionId: '7788', userid: 'real' });

  const connectionRef = registry.openConnection({ remote: { address: '192.0.2.129', port: 1634 } });
  // A fresh connection is anonymous and has no player identity.
  assert.equal(registry.isAuthenticated(connectionRef), false);
  assert.throws(
    () => registry.requirePlayer(connectionRef),
    (error) => error.code === 'UNAUTHENTICATED_CONNECTION'
  );

  // The UDP register and bind are the authentication event.
  accountSessions.establish({ userid: 'real', sourceAddress: '192.0.2.129' });
  registry.bindDnasToken({ dnasToken: CAPTURED_DNAS_TOKEN, sessionConnectionId: '7788' });
  const associated = registry.associateConnection({
    connectionRef,
    dnasToken: CAPTURED_DNAS_TOKEN
  });
  // The HTTP path is preserved: the live HTTP session id still resolves.
  assert.equal(associated.sessionConnectionId, '7788');
  assert.equal(associated.userid, 'real');
  assert.equal(registry.isAuthenticated(connectionRef), true);
  assert.deepEqual(registry.requirePlayer(connectionRef), {
    userid: 'real',
    accountSessionId: associated.accountSessionId,
    // Present because the browser flow ran. A UDP-only player has null here and
    // is no less authenticated - the account session is the identity.
    sessionConnectionId: '7788'
  });

  // The connection reference is server-minted and distinct from both the
  // session id and the player id.
  assert.notEqual(connectionRef, '7788');
  assert.notEqual(connectionRef, 'real');
});

test('never uses the source address as an identity key', () => {
  const { sessions, registry, accountSessions } = createRegistry();
  sessions.set('7788', { connectionId: '7788', userid: 'real' });
  accountSessions.establish({ userid: 'real', sourceAddress: '192.0.2.129' });
  registry.bindDnasToken({ dnasToken: CAPTURED_DNAS_TOKEN, sessionConnectionId: '7788' });

  // Two connections from the SAME address stay independent, and the second is
  // not authenticated just because the first was. Sharing an address grants
  // nothing: the only account session is already claimed, single-use.
  const first = registry.openConnection({ remote: { address: '192.0.2.129', port: 1634 } });
  const second = registry.openConnection({ remote: { address: '192.0.2.129', port: 1635 } });
  registry.associateConnection({ connectionRef: first, dnasToken: CAPTURED_DNAS_TOKEN });

  assert.equal(registry.isAuthenticated(first), true);
  assert.equal(registry.isAuthenticated(second), false);
  assert.throws(
    () => registry.requirePlayer(second),
    (error) => error.code === 'UNAUTHENTICATED_CONNECTION'
  );
  assert.throws(
    () => registry.associateConnection({ connectionRef: second, dnasToken: CAPTURED_DNAS_TOKEN }),
    (error) => error.code === 'NO_ELIGIBLE_ACCOUNT_SESSION'
  );
});

test('two accounts may hold the SAME DNAS token, because we mint it ourselves', () => {
  // The corrected behaviour. The old model refused the second holder, which
  // would have rejected player two: V2 replays one static DNAS asset, so both
  // consoles present an identical token (T27, OQ-022).
  const { sessions, registry, accountSessions } = createRegistry();
  sessions.set('s-alice', { connectionId: 's-alice', userid: 'alice' });
  sessions.set('s-bob', { connectionId: 's-bob', userid: 'bob' });

  assert.doesNotThrow(() => {
    registry.bindDnasToken({ dnasToken: CAPTURED_DNAS_TOKEN, sessionConnectionId: 's-alice' });
    registry.bindDnasToken({ dnasToken: CAPTURED_DNAS_TOKEN, sessionConnectionId: 's-bob' });
  });

  // And both reach the lobby, because the account session resolves them.
  accountSessions.establish({ userid: 'alice', sourceAddress: '10.0.0.1' });
  const alice = registry.openConnection({ remote: { address: '10.0.0.1', port: 1 } });
  assert.equal(
    registry.associateConnection({ connectionRef: alice, dnasToken: CAPTURED_DNAS_TOKEN }).userid,
    'alice'
  );

  accountSessions.establish({ userid: 'bob', sourceAddress: '10.0.0.2' });
  const bob = registry.openConnection({ remote: { address: '10.0.0.2', port: 1 } });
  assert.equal(
    registry.associateConnection({ connectionRef: bob, dnasToken: CAPTURED_DNAS_TOKEN }).userid,
    'bob'
  );
  assert.notEqual(registry.get(alice).userid, registry.get(bob).userid);
});

test('two eligible sessions behind ONE address are refused, not guessed', () => {
  const { registry, accountSessions } = createRegistry();
  accountSessions.establish({ userid: 'alice', sourceAddress: '10.0.0.9' });
  accountSessions.establish({ userid: 'bob', sourceAddress: '10.0.0.9' });

  const connectionRef = registry.openConnection({ remote: { address: '10.0.0.9', port: 5 } });
  assert.throws(
    () => registry.associateConnection({ connectionRef, dnasToken: CAPTURED_DNAS_TOKEN }),
    (error) => error.code === 'AMBIGUOUS_ACCOUNT_SESSION'
  );
});

test('the source address disambiguates but never grants on its own', () => {
  const { registry, accountSessions } = createRegistry();
  accountSessions.establish({ userid: 'alice', sourceAddress: '10.0.0.1' });
  accountSessions.establish({ userid: 'bob', sourceAddress: '10.0.0.2' });

  // Two eligible sessions; the address narrows to exactly one.
  const bob = registry.openConnection({ remote: { address: '10.0.0.2', port: 7 } });
  assert.equal(
    registry.associateConnection({ connectionRef: bob, dnasToken: CAPTURED_DNAS_TOKEN }).userid,
    'bob'
  );

  // A stranger does NOT get the one remaining session. The address is a
  // necessary correlation signal - it decides which sessions are candidates -
  // even though identity itself comes from the account session, never the
  // address and never the token.
  const stranger = registry.openConnection({ remote: { address: '203.0.113.7', port: 9 } });
  assert.throws(
    () => registry.associateConnection({ connectionRef: stranger, dnasToken: CAPTURED_DNAS_TOKEN }),
    (error) => error.code === 'NO_ELIGIBLE_ACCOUNT_SESSION'
  );
});

test('an account has at most one live game session', () => {
  // Matches the reference server, which disconnects a double session for a
  // userid rather than letting two coexist.
  const { accountSessions } = createRegistry();
  const first = accountSessions.establish({ userid: 'alice', sourceAddress: '10.0.0.1' });
  assert.equal(first.displaced, null);
  // Replacing a LIVE session takes proof of the account since D-2; without one
  // the second establishment is refused instead, which the registry's own tests
  // and composition.test.js both cover.
  const second = accountSessions.establish({
    userid: 'alice',
    sourceAddress: '10.0.0.5',
    proof: ACCOUNT_PROOF.REGISTRATION_NONCE
  });
  assert.equal(second.displaced.accountSessionId, first.session.accountSessionId);
  assert.equal(accountSessions.size, 1);
});

test('an account session expires out of the claim window', () => {
  let now = 1_000_000;
  const accountSessions = new AccountSessionRegistry({
    clock: () => now,
    lobbyClaimWindowMs: 60_000
  });
  const sessions = new Map();
  const registry = new ConnectionIdentityRegistry({
    sessionLookup: (id) => sessions.get(id) ?? null,
    accountSessions,
    clock: () => now
  });
  accountSessions.establish({ userid: 'alice', sourceAddress: '10.0.0.1' });

  now += 60_001;
  const late = registry.openConnection({ remote: { address: '10.0.0.1', port: 3 } });
  assert.throws(
    () => registry.associateConnection({ connectionRef: late, dnasToken: CAPTURED_DNAS_TOKEN }),
    (error) => error.code === 'NO_ELIGIBLE_ACCOUNT_SESSION'
  );
});

test('closing a lobby connection releases its claim so the player can reconnect', () => {
  const { registry, accountSessions } = createRegistry();
  accountSessions.establish({ userid: 'alice', sourceAddress: '10.0.0.1' });

  const first = registry.openConnection({ remote: { address: '10.0.0.1', port: 1 } });
  registry.associateConnection({ connectionRef: first, dnasToken: CAPTURED_DNAS_TOKEN });
  registry.closeConnection(first);

  const second = registry.openConnection({ remote: { address: '10.0.0.1', port: 2 } });
  assert.equal(
    registry.associateConnection({ connectionRef: second, dnasToken: CAPTURED_DNAS_TOKEN }).userid,
    'alice'
  );
});

test('fails closed on unknown, expired and conflicting associations', () => {
  const { sessions, registry, accountSessions } = createRegistry();
  const connectionRef = registry.openConnection({ remote: { address: '10.0.0.1', port: 1 } });

  // No completed UDP register/bind, so nothing authenticates this connection.
  // Previously this said UNKNOWN_DNAS_TOKEN, which framed a correlation miss as
  // a DNAS failure even though DNAS completes long before the lobby.
  assert.throws(
    () => registry.associateConnection({ connectionRef, dnasToken: CAPTURED_DNAS_TOKEN }),
    (error) => error.code === 'NO_ELIGIBLE_ACCOUNT_SESSION'
  );

  // A connection that already presented one token cannot switch to another.
  sessions.set('7788', { connectionId: '7788', userid: 'real' });
  accountSessions.establish({ userid: 'real', sourceAddress: '10.0.0.1' });
  registry.bindDnasToken({ dnasToken: CAPTURED_DNAS_TOKEN, sessionConnectionId: '7788' });
  registry.associateConnection({ connectionRef, dnasToken: CAPTURED_DNAS_TOKEN });
  const otherToken = Buffer.alloc(32, 9).toString('base64');
  assert.throws(
    () => registry.associateConnection({ connectionRef, dnasToken: otherToken }),
    (error) => error.code === 'CONNECTION_TOKEN_CONFLICT'
  );

  // Re-presenting the same token is idempotent, not an error, and does not
  // consume a second account session.
  assert.equal(
    registry.associateConnection({ connectionRef, dnasToken: CAPTURED_DNAS_TOKEN }).userid,
    'real'
  );
});

test('bounds concurrent connections and token bindings', () => {
  const sessions = new Map();
  const registry = new ConnectionIdentityRegistry({
    sessionLookup: (id) => sessions.get(id) ?? null,
    maxConnections: 2,
    maxTokenBindings: 1
  });
  registry.openConnection({});
  registry.openConnection({});
  assert.throws(() => registry.openConnection({}), (error) => error.code === 'CONNECTION_LIMIT');

  registry.bindDnasToken({ dnasToken: CAPTURED_DNAS_TOKEN, sessionConnectionId: 's1' });
  assert.throws(
    () => registry.bindDnasToken({
      dnasToken: Buffer.alloc(32, 1).toString('base64'),
      sessionConnectionId: 's2'
    }),
    (error) => error.code === 'TOKEN_BINDING_LIMIT'
  );
  // Additional holders of an already-tracked token stay allowed at the limit:
  // multiple accounts legitimately share one token while DNAS replays a static
  // asset, so this must not be treated as a new binding.
  registry.bindDnasToken({ dnasToken: CAPTURED_DNAS_TOKEN, sessionConnectionId: 's3' });
});

test('closing a connection releases only that connection', () => {
  const { sessions, registry, accountSessions } = createRegistry();
  sessions.set('7788', { connectionId: '7788', userid: 'real' });
  accountSessions.establish({ userid: 'real', sourceAddress: '10.0.0.1' });
  registry.bindDnasToken({ dnasToken: CAPTURED_DNAS_TOKEN, sessionConnectionId: '7788' });
  // A remote address is required: a connection with none matches no session,
  // because a null address is treated as matching nothing rather than anything.
  const first = registry.openConnection({ remote: { address: '10.0.0.1', port: 1 } });
  const second = registry.openConnection({ remote: { address: '10.0.0.1', port: 2 } });
  registry.associateConnection({ connectionRef: first, dnasToken: CAPTURED_DNAS_TOKEN });

  assert.equal(registry.openConnectionCount, 2);
  registry.closeConnection(first);
  assert.equal(registry.openConnectionCount, 1);
  assert.equal(registry.get(first), null);
  assert.notEqual(registry.get(second), null);
  // The token binding outlives the connection: the client reconnects.
  assert.equal(registry.boundTokenCount, 1);
});

test('the lobby session associates a captured 0x1007 and fails closed otherwise', () => {
  const providers = {
    areaTable: createV1ObservedAreaTable(),
    resolveCommand6501Response: () => ({ mode: 0 }),
    resolveCommand6502Response: () => ({ mode: 1, unknown0: 1, unknown1: 1 })
  };

  const presented = [];
  const associating = new Tcp10127LobbyInitializationSession({
    ...providers,
    associateDnasToken: ({ presentedToken }) => { presented.push(presentedToken); }
  });
  const result = associating.handleFrame(decodeTcp10127Frame(
    Buffer.from(CAPTURED_LOBBY_INIT_REQUESTS[0], 'hex')
  ));
  assert.equal(result.response.toString('hex'), '0001021007ff00ff00');
  assert.deepEqual(presented, [CAPTURED_DNAS_TOKEN]);
  assert.equal(
    associating.state,
    TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_KEYED_MANIFEST_REQUEST
  );

  // A rejected association must stop the connection, not continue anonymously.
  const refusing = new Tcp10127LobbyInitializationSession({
    ...providers,
    associateDnasToken: () => {
      const error = new Error('no authenticated HTTP session has presented this DNAS token');
      error.code = 'UNKNOWN_DNAS_TOKEN';
      throw error;
    }
  });
  assert.throws(
    () => refusing.handleFrame(decodeTcp10127Frame(
      Buffer.from(CAPTURED_LOBBY_INIT_REQUESTS[0], 'hex')
    )),
    (error) => error.code === 'UNKNOWN_DNAS_TOKEN'
  );
  assert.equal(
    refusing.state,
    TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_LOBBY_INIT_REQUEST,
    'a refused association must not advance the ladder'
  );

  // An identity field that does not decode is rejected rather than guessed.
  const corrupted = Buffer.from(CAPTURED_LOBBY_INIT_REQUESTS[0], 'hex');
  corrupted[corrupted.length - 1] ^= 0xff;
  const undecodable = new Tcp10127LobbyInitializationSession({
    ...providers,
    associateDnasToken: () => { throw new Error('must not be called'); }
  });
  assert.throws(
    () => undecodable.handleFrame(decodeTcp10127Frame(corrupted)),
    (error) => error.code === 'LOBBY_INIT_IDENTITY_FIELD'
  );
});

test('without an associator the lobby session still serves, unchanged', () => {
  // The associator is optional so existing evidence-only tests and the
  // captured-ladder replay keep working; composition supplies it.
  const session = new Tcp10127LobbyInitializationSession({
    areaTable: createV1ObservedAreaTable(),
    resolveCommand6501Response: () => ({ mode: 0 })
  });
  const result = session.handleFrame(decodeTcp10127Frame(
    Buffer.from(CAPTURED_LOBBY_INIT_REQUESTS[1], 'hex')
  ));
  assert.equal(result.response.toString('hex'), '0001021007cf00ff00');
});

test('a connection with no source address matches nothing', () => {
  // A null address must not act as a wildcard. It is the case where we know
  // least, so it fails closed rather than open.
  const { registry, accountSessions } = createRegistry();
  accountSessions.establish({ userid: 'alice', sourceAddress: '10.0.0.1' });
  const anonymous = registry.openConnection({});
  assert.throws(
    () => registry.associateConnection({ connectionRef: anonymous, dnasToken: CAPTURED_DNAS_TOKEN }),
    (error) => error.code === 'NO_ELIGIBLE_ACCOUNT_SESSION'
  );
});

test('a session established without a source address is claimable from nowhere', () => {
  const { registry, accountSessions } = createRegistry();
  accountSessions.establish({ userid: 'alice' });
  const anywhere = registry.openConnection({ remote: { address: '203.0.113.1', port: 1 } });
  assert.throws(
    () => registry.associateConnection({ connectionRef: anywhere, dnasToken: CAPTURED_DNAS_TOKEN }),
    (error) => error.code === 'NO_ELIGIBLE_ACCOUNT_SESSION'
  );
});

test('the DNAS token never narrows an ambiguous set - the review case', () => {
  // Review demonstrated the escalation this prevents: two sessions eligible at
  // one address, only the victim having used the browser, and an attacker
  // connecting first received the VICTIM's identity because the token narrowed
  // 2 -> 1. The token is the same static value for every console, so it
  // distinguishes nobody and must never break a tie.
  const { sessions, registry, accountSessions } = createRegistry();
  sessions.set('http-victim', { connectionId: 'http-victim', userid: 'victim' });
  accountSessions.establish({ userid: 'victim', sourceAddress: '203.0.113.5' });
  accountSessions.establish({ userid: 'attacker', sourceAddress: '203.0.113.5' });
  registry.bindDnasToken({ dnasToken: CAPTURED_DNAS_TOKEN, sessionConnectionId: 'http-victim' });

  const attacker = registry.openConnection({ remote: { address: '203.0.113.5', port: 1 } });
  assert.throws(
    () => registry.associateConnection({ connectionRef: attacker, dnasToken: CAPTURED_DNAS_TOKEN }),
    (error) => error.code === 'AMBIGUOUS_ACCOUNT_SESSION',
    'ambiguity must be refused even when the token would narrow it'
  );
});

test('one token cannot accumulate unbounded holders', () => {
  const sessions = new Map();
  const registry = new ConnectionIdentityRegistry({
    sessionLookup: (id) => sessions.get(id) ?? null,
    accountSessions: new AccountSessionRegistry()
  });
  // Every login shares one token while DNAS replays a static asset, so the
  // per-token list is what grows, not the map.
  assert.throws(() => {
    for (let index = 0; index < 1000; index += 1) {
      registry.bindDnasToken({ dnasToken: CAPTURED_DNAS_TOKEN, sessionConnectionId: `s${index}` });
    }
  }, (error) => error.code === 'TOKEN_BINDING_LIMIT');
  assert.equal(registry.boundTokenCount, 1);
});

test('releasing a token binding drops only that holder', () => {
  const { sessions, registry } = createRegistry();
  sessions.set('a', { connectionId: 'a', userid: 'alice' });
  sessions.set('b', { connectionId: 'b', userid: 'bob' });
  registry.bindDnasToken({ dnasToken: CAPTURED_DNAS_TOKEN, sessionConnectionId: 'a' });
  registry.bindDnasToken({ dnasToken: CAPTURED_DNAS_TOKEN, sessionConnectionId: 'b' });

  assert.equal(registry.releaseDnasToken(CAPTURED_DNAS_TOKEN, 'a'), true);
  // Bob still holds it: dropping the whole entry would have evicted every
  // account sharing the one static token.
  assert.equal(registry.boundTokenCount, 1);
  assert.equal(registry.releaseDnasToken(CAPTURED_DNAS_TOKEN, 'a'), false);
  assert.equal(registry.releaseDnasToken(CAPTURED_DNAS_TOKEN, 'b'), true);
  assert.equal(registry.boundTokenCount, 0);
});

test('hundreds of concurrent players each resolve to their own account', () => {
  // The design target. Every player has a distinct source address, which is the
  // normal case, and each must resolve to their own session without the others
  // interfering or the resolution degrading.
  const { registry, accountSessions } = createRegistry();
  const PLAYERS = 400;

  for (let index = 0; index < PLAYERS; index += 1) {
    accountSessions.establish({
      userid: `player${index}`,
      sourceAddress: `10.${Math.floor(index / 254)}.0.${(index % 254) + 1}`
    });
  }
  assert.equal(accountSessions.size, PLAYERS);

  const started = Date.now();
  for (let index = 0; index < PLAYERS; index += 1) {
    const address = `10.${Math.floor(index / 254)}.0.${(index % 254) + 1}`;
    const connectionRef = registry.openConnection({ remote: { address, port: 1024 + index } });
    const bound = registry.associateConnection({
      connectionRef,
      dnasToken: CAPTURED_DNAS_TOKEN
    });
    assert.equal(bound.userid, `player${index}`, `player ${index} got their own account`);
  }
  // Not a benchmark, just a guard against an accidental quadratic: 400 players
  // resolving one after another used to walk every session twice per lookup.
  assert.ok(Date.now() - started < 5000, 'resolution does not degrade with player count');

  // Every session is now claimed, so nothing is left dangling.
  assert.equal(accountSessions.eligibleForLobby().length, 0);
});

test('a claim and its release stay O(1) as the table grows', () => {
  const { registry, accountSessions } = createRegistry();
  for (let index = 0; index < 300; index += 1) {
    accountSessions.establish({ userid: `p${index}`, sourceAddress: `10.0.0.${index % 254}` });
  }
  const target = accountSessions.findByUserId('p42');
  assert.notEqual(target, null);

  const connectionRef = registry.openConnection({ remote: { address: '10.0.0.42', port: 1 } });
  // 10.0.0.42 is shared by p42 and p296 (index % 254), so this is ambiguous and
  // must be refused - the scale change must not have weakened that.
  assert.throws(
    () => registry.associateConnection({ connectionRef, dnasToken: CAPTURED_DNAS_TOKEN }),
    (error) => error.code === 'AMBIGUOUS_ACCOUNT_SESSION'
  );
});
