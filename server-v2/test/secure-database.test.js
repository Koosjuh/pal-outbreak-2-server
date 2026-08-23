import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import test from 'node:test';

import { SecretVault } from '../src/crypto/secret-vault.js';
import { SecureAccountRepository } from '../src/database/secure-account-repository.js';
import { SqliteDatabase } from '../src/database/sqlite-database.js';
import { SqliteSessionRegistry } from '../src/database/sqlite-session-registry.js';

function fixture(t) {
  const directory = fs.mkdtempSync(path.join(os.tmpdir(), 'pal-v2-secure-db-'));
  const filePath = path.join(directory, 'accounts.sqlite3');
  const database = new SqliteDatabase(filePath);
  const masterKey = Buffer.from(
    '000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f',
    'hex'
  );
  const vault = new SecretVault(masterKey);
  const clock = () => Date.parse('2026-07-31T08:00:00.000Z');
  const accounts = new SecureAccountRepository(database, vault, { clock });
  const sessions = new SqliteSessionRegistry(database, {
    clock,
    idFactory: () => '12345678'
  });
  t.after(() => {
    database.close();
    fs.rmSync(directory, { recursive: true, force: true });
  });
  return { accounts, database, filePath, masterKey, sessions };
}

test('stores a verifier and authenticated ciphertext, not the plaintext password', (t) => {
  const { accounts, database, filePath } = fixture(t);
  accounts.create({ userid: 'PLAYER1', password: 'secret42' });

  const row = database.connection
    .prepare('SELECT * FROM accounts WHERE userid = ?')
    .get('PLAYER1');
  assert.equal(row.password_salt.length, 16);
  assert.equal(row.password_hash.length, 32);
  assert.equal(row.secret_nonce.length, 12);
  assert.equal(row.secret_authentication_tag.length, 16);
  assert.notEqual(row.secret_ciphertext.toString('latin1'), 'secret42');

  database.connection.exec('PRAGMA wal_checkpoint(TRUNCATE)');
  const rawDatabase = fs.readFileSync(filePath);
  assert.equal(rawDatabase.includes(Buffer.from('secret42', 'latin1')), false);
});

test('authenticates with scrypt and recovers the compatibility secret only on demand', (t) => {
  const { accounts } = fixture(t);
  accounts.create({ userid: 'PLAYER2', password: 'correct2', displayName: 'HANDLE2' });

  assert.equal(accounts.authenticate('PLAYER2', 'wrong222'), null);
  assert.equal(accounts.authenticate('PLAYER2', 'correct2').displayName, 'HANDLE2');
  // The secret is keyed on the LOGIN IDENTITY, never the display name.
  assert.equal(accounts.getCompatibilitySecretByLoginIdentity('PLAYER2'), 'correct2');
  assert.equal(accounts.getCompatibilitySecretByLoginIdentity('HANDLE2'), null);
});

test('binds ciphertext to account identity and master key', (t) => {
  const { accounts, database } = fixture(t);
  accounts.create({ userid: 'PLAYER3', password: 'secret43' });

  database.connection
    .prepare('UPDATE accounts SET userid = ? WHERE userid = ?')
    .run('PLAYER4', 'PLAYER3');

  // The sealed secret is bound to the login identity as AES-GCM additional
  // authenticated data, so moving the row to a different identity must make it
  // unopenable rather than silently yielding the old account's password. The
  // lookup now finds the row under its NEW identity; it is the unseal that fails.
  assert.throws(
    () => accounts.getCompatibilitySecretByLoginIdentity('PLAYER4'),
    /authenticate data|Unsupported state|unable to authenticate/i
  );
  // The old identity is simply gone.
  assert.equal(accounts.getCompatibilitySecretByLoginIdentity('PLAYER3'), null);
});

test('persists sessions with account identity and expiry', (t) => {
  const { accounts, sessions } = fixture(t);
  const account = accounts.create({ userid: 'PLAYER5', password: 'secret45' });
  const session = sessions.create({ account, remoteAddress: '192.0.2.50' });

  assert.equal(session.connectionId, '12345678');
  assert.equal(session.displayName, 'PLAYER5');
  assert.equal(session.lobbyProvisionedAtMs, null);

  const provisioned = sessions.markLobbyProvisioned('12345678', '192.0.2.51');
  assert.equal(provisioned.remoteAddress, '192.0.2.51');
  assert.equal(
    provisioned.lobbyProvisionedAtMs,
    Date.parse('2026-07-31T08:00:00.000Z')
  );
});

