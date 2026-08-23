import assert from 'node:assert/strict';
import fs from 'node:fs';
import http from 'node:http';
import os from 'node:os';
import path from 'node:path';
import test from 'node:test';

import { SecretVault } from '../src/crypto/secret-vault.js';
import { SecureAccountRepository } from '../src/database/secure-account-repository.js';
import { SqliteDatabase } from '../src/database/sqlite-database.js';
import { SqliteSessionRegistry } from '../src/database/sqlite-session-registry.js';
import { createWebService } from '../src/http/web-service.js';

function postForm(port, requestPath, form) {
  const body = Buffer.from(new URLSearchParams(form).toString(), 'latin1');
  return new Promise((resolve, reject) => {
    const request = http.request(
      {
        host: '127.0.0.1',
        port,
        method: 'POST',
        path: requestPath,
        headers: {
          'Content-Type': 'application/x-www-form-urlencoded',
          'Content-Length': body.length
        }
      },
      (response) => {
        const chunks = [];
        response.on('data', (chunk) => chunks.push(chunk));
        response.on('end', () => resolve(Buffer.concat(chunks).toString('latin1')));
      }
    );
    request.on('error', reject);
    request.end(body);
  });
}

test('uses the encrypted SQLite repository through the PAL browser contract', async (t) => {
  const directory = fs.mkdtempSync(path.join(os.tmpdir(), 'pal-v2-secure-http-'));
  const database = new SqliteDatabase(path.join(directory, 'server.sqlite3'));
  const vault = new SecretVault(Buffer.alloc(32, 0x42));
  const accounts = new SecureAccountRepository(database, vault);
  let nextId = 22_000_000;
  const sessions = new SqliteSessionRegistry(database, {
    idFactory: () => String(nextId++)
  });
  const service = createWebService({
    accountRepository: accounts,
    sessionRegistry: sessions,
    selfHost: 'stage6.sega.com',
    snapHost: 'snap01.capcom.client.sf.yav4.com'
  });
  await new Promise((resolve, reject) => {
    service.once('error', reject);
    service.listen(0, '127.0.0.1', resolve);
  });
  t.after(
    () =>
      new Promise((resolve) =>
        service.close(() => {
          database.close();
          fs.rmSync(directory, { recursive: true, force: true });
          resolve();
        })
      )
  );

  const create = await postForm(service.address().port, '/mhweb/create.jsp', {
    userid: 'SECURE1',
    password: 'secret99'
  });
  assert.match(create, /<!--COMP-SIGNUP-->/);
  assert.ok(create.includes('<!--INPUT-IDS-->SECURE1\x00<br>'));
  assert.equal(accounts.getCompatibilitySecretByLoginIdentity('SECURE1'), 'secret99');

  const login = await postForm(service.address().port, '/mhweb/login.jsp', {
    userid: 'SECURE1',
    password: 'secret99'
  });
  assert.match(login, /<!--COMP-SIGNUP-->/);
});

