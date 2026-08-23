import assert from 'node:assert/strict';
import fs from 'node:fs';
import http from 'node:http';
import os from 'node:os';
import path from 'node:path';
import test from 'node:test';

import { AccountRepository } from '../src/accounts/account-repository.js';
import { createWebService } from '../src/http/web-service.js';
import { SessionRegistry } from '../src/sessions/session-registry.js';
import { JsonFile } from '../src/storage/json-file.js';

function request(port, { method = 'GET', path: requestPath, form = null }) {
  const body = form ? Buffer.from(new URLSearchParams(form).toString(), 'latin1') : Buffer.alloc(0);
  return new Promise((resolve, reject) => {
    const req = http.request(
      {
        host: '127.0.0.1',
        port,
        method,
        path: requestPath,
        headers: form
          ? {
              'Content-Type': 'application/x-www-form-urlencoded',
              'Content-Length': body.length
            }
          : {}
      },
      (res) => {
        const chunks = [];
        res.on('data', (chunk) => chunks.push(chunk));
        res.on('end', () =>
          resolve({
            statusCode: res.statusCode,
            body: Buffer.concat(chunks).toString('latin1')
          })
        );
      }
    );
    req.on('error', reject);
    req.end(body);
  });
}

async function serviceFixture(t) {
  const directory = fs.mkdtempSync(path.join(os.tmpdir(), 'pal-v2-http-'));
  t.after(() => fs.rmSync(directory, { recursive: true, force: true }));

  const accounts = new AccountRepository(
    new JsonFile(path.join(directory, 'accounts.json'), {
      createDefault: AccountRepository.emptyDocument
    }),
    { clock: () => new Date('2026-07-30T20:00:00.000Z') }
  );
  let nextSession = 12_345_678;
  const sessions = new SessionRegistry(
    new JsonFile(path.join(directory, 'sessions.json'), {
      createDefault: SessionRegistry.emptyDocument
    }),
    {
      clock: () => Date.parse('2026-07-30T20:00:00.000Z'),
      idFactory: () => String(nextSession++)
    }
  );
  const server = createWebService({
    accountRepository: accounts,
    sessionRegistry: sessions,
    selfHost: 'stage6.sega.com',
    snapHost: 'snap01.capcom.client.sf.yav4.com',
    snapPort: 10127,
    descriptiveHexAddress: 'c0000279278f'
  });
  await new Promise((resolve, reject) => {
    server.once('error', reject);
    server.listen(0, '127.0.0.1', resolve);
  });
  t.after(() => new Promise((resolve) => server.close(resolve)));

  return {
    port: server.address().port,
    accounts,
    sessions
  };
}

test('creates an account and emits the runtime-confirmed login-name markers', async (t) => {
  const fixture = await serviceFixture(t);
  const response = await request(fixture.port, {
    method: 'POST',
    path: '/mhweb/create.jsp',
    form: { userid: 'PLAYER1', password: 'secret42' }
  });

  assert.equal(response.statusCode, 200);
  assert.match(response.body, /<!--COMP-SIGNUP-->/);
  assert.ok(response.body.includes('<!--INPUT-IDS-->PLAYER1\x00<br>'));
  assert.match(response.body, /startsession\?sessid=12345678/);
  assert.equal(fixture.accounts.findByUserId('PLAYER1').compatibilitySecret, 'secret42');
});

/**
 * The HTTP POST is the real enforcement surface. `maxlength="10"` on the input
 * is client-side advice and the in-game browser is not proven to honour it, so
 * the server must refuse an over-long identity itself - and refuse it, never
 * truncate it, because the client's own account-creation copy is a fixed-width
 * `strncpy(dst, cursor + 12, 10)` and two identities that differ only past byte
 * 10 would collide on the wire.
 */
test('refuses an over-long login identity at the HTTP boundary without truncating', async (t) => {
  const fixture = await serviceFixture(t);
  const response = await request(fixture.port, {
    method: 'POST',
    path: '/mhweb/create.jsp',
    form: { userid: '12345abcdef', password: 'secret42' }
  });

  assert.equal(response.statusCode, 200);
  // The form is re-rendered with an error, not the completion page.
  assert.doesNotMatch(response.body, /<!--COMP-SIGNUP-->/);
  assert.match(response.body, /INVALID_USERID/);
  assert.match(response.body, /maxlength="10"/);
  // Neither the full nor the truncated identity was stored.
  assert.equal(fixture.accounts.findByUserId('12345abcdef'), null);
  assert.equal(fixture.accounts.findByUserId('12345abcde'), null);
});

test('accepts a login identity at exactly the 10-byte ceiling', async (t) => {
  const fixture = await serviceFixture(t);
  const response = await request(fixture.port, {
    method: 'POST',
    path: '/mhweb/create.jsp',
    form: { userid: '12345abcde', password: 'secret42' }
  });

  assert.match(response.body, /<!--COMP-SIGNUP-->/);
  assert.ok(response.body.includes('<!--INPUT-IDS-->12345abcde\x00<br>'));
  assert.equal(fixture.accounts.findByUserId('12345abcde').userid, '12345abcde');
});

test('a display name cannot be injected through a field no form emits', async (t) => {
  const fixture = await serviceFixture(t);
  await request(fixture.port, {
    method: 'POST',
    path: '/mhweb/create.jsp',
    form: { userid: 'PLAYER9', password: 'secret42', displayName: 'INJECTED' }
  });

  // The create handler forwards only userid and password, so the display name
  // still defaults to the login identity.
  assert.equal(fixture.accounts.findByUserId('PLAYER9').displayName, 'PLAYER9');
  assert.equal(fixture.accounts.findByDisplayName('INJECTED'), null);
});

test('validates login and rejects the wrong compatibility secret', async (t) => {
  const fixture = await serviceFixture(t);
  fixture.accounts.create({ userid: 'PLAYER2', password: 'correct1' });

  const bad = await request(fixture.port, {
    method: 'POST',
    path: '/mhweb/login.jsp',
    form: { userid: 'PLAYER2', password: 'incorrect' }
  });
  assert.doesNotMatch(bad.body, /<!--COMP-SIGNUP-->/);
  assert.match(bad.body, /BAD LOGIN/);

  const good = await request(fixture.port, {
    method: 'POST',
    path: '/mhweb/login.jsp',
    form: { userid: 'PLAYER2', password: 'correct1' }
  });
  assert.match(good.body, /<!--COMP-SIGNUP-->/);
});

test('emits decoded GAME-START and LBS CSV field order', async (t) => {
  const fixture = await serviceFixture(t);
  const account = fixture.accounts.create({ userid: 'PLAYER3', password: 'secret43' });
  const session = fixture.sessions.create({
    account,
    remoteAddress: '127.0.0.1'
  });

  const start = await request(fixture.port, {
    path: `/mhweb/startsession?sessid=${session.connectionId}`
  });
  assert.match(start.body, /<!--CRS-GAME-START-->/);
  assert.ok(
    start.body.includes(
      `"OK","${session.connectionId}","http://stage6.sega.com/mhweb/lbs.jsp"`
    )
  );

  const lbs = await request(fixture.port, {
    path: `/mhweb/lbs.jsp?sessid=${session.connectionId}`
  });
  assert.match(lbs.body, /<!--CRS-LBS-INFO-GET-->/);
  assert.ok(lbs.body.includes('"snap01.capcom.client.sf.yav4.com:10127",'));
  assert.ok(lbs.body.includes('"c0000279278f,PAL Lobby",'));
  assert.equal(
    fixture.sessions.get(session.connectionId).lobbyProvisionedAtMs,
    Date.parse('2026-07-30T20:00:00.000Z')
  );
});

test('does not provision LBS for an unknown connection id', async (t) => {
  const fixture = await serviceFixture(t);
  const response = await request(fixture.port, {
    path: '/mhweb/lbs.jsp?sessid=99999999'
  });

  assert.match(response.body, /<!--CRS-ERROR-->/);
  assert.match(response.body, /BAD LBS SESSION/);
});
