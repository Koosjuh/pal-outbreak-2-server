import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import test from 'node:test';

import { SecretVault } from '../src/crypto/secret-vault.js';
import { SecureAccountRepository } from '../src/database/secure-account-repository.js';
import { SqliteDatabase } from '../src/database/sqlite-database.js';
import { importV1Accounts } from '../src/database/v1-account-import.js';

// Synthetic V1-shaped fixture data only - never the real Pi accounts.json, per
// the migration task's instruction to keep real passwords out of test files.
const MASTER_KEY = Buffer.from(
  '000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f',
  'hex'
);

function fixture(t) {
  const directory = fs.mkdtempSync(path.join(os.tmpdir(), 'pal-v1-import-'));
  const filePath = path.join(directory, 'accounts.sqlite3');
  const database = new SqliteDatabase(filePath);
  const vault = new SecretVault(MASTER_KEY);
  const clock = () => Date.parse('2026-08-03T00:00:00.000Z');
  const repository = new SecureAccountRepository(database, vault, { clock });
  t.after(() => {
    database.close();
    fs.rmSync(directory, { recursive: true, force: true });
  });
  return { database, repository, filePath };
}

function record({ userid, password, handle = userid, created, lastLogin }) {
  return {
    userid,
    password,
    handle,
    created: created ?? '2026-01-01T00:00:00.000Z',
    lastLogin: lastLogin ?? '2026-01-02T00:00:00.000Z'
  };
}

function rowFor(database, userid) {
  return database.connection.prepare('SELECT * FROM accounts WHERE userid = ?').get(userid);
}

test('a realistic multi-account fixture imports cleanly and every account authenticates with its original password', (t) => {
  const { repository } = fixture(t);
  const accounts = {
    player1: record({ userid: 'player1', password: 'secret42' }),
    ab_c: record({ userid: 'ab_c', password: 'p4ss', handle: 'ab_c' }),
    // Exactly 10 bytes: the client's max, so this must be ACCEPTED (11 is
    // covered by the dedicated rejection test below).
    tenbytes12: record({ userid: 'tenbytes12', password: '1234567890' })
  };

  const result = importV1Accounts({ accounts, repository });

  assert.equal(result.examined, 3);
  assert.equal(result.imported, 3);
  assert.equal(result.skippedExisting, 0);
  assert.deepEqual(result.rejected, []);
  assert.equal(result.timestampsPreserved, false);

  for (const [userid, source] of Object.entries(accounts)) {
    assert.equal(repository.authenticate(source.userid, source.password)?.userid, source.userid);
    assert.equal(
      repository.getCompatibilitySecretByLoginIdentity(source.userid),
      source.password,
      `compatibility secret for ${userid} must equal the original V1 password verbatim`
    );
  }
});

test('idempotency: a second run imports nothing, changes nothing, and the sealed secret still opens', (t) => {
  const { repository, database } = fixture(t);
  const accounts = {
    player1: record({ userid: 'player1', password: 'secret42' }),
    player2: record({ userid: 'player2', password: 'another1' })
  };

  const first = importV1Accounts({ accounts, repository });
  assert.equal(first.imported, 2);
  assert.equal(first.skippedExisting, 0);

  const rowBefore = rowFor(database, 'player1');

  const second = importV1Accounts({ accounts, repository });
  assert.equal(second.imported, 0);
  assert.equal(second.skippedExisting, 2);
  assert.deepEqual(second.rejected, []);
  assert.deepEqual(second.skippedUserids.sort(), ['player1', 'player2']);

  const rowAfter = rowFor(database, 'player1');
  assert.deepEqual(rowBefore, rowAfter);
  assert.equal(repository.getCompatibilitySecretByLoginIdentity('player1'), 'secret42');
  assert.equal(repository.authenticate('player2', 'another1')?.userid, 'player2');
});

test('an 11-byte userid is rejected, not truncated, and no row appears under either form', (t) => {
  const { repository } = fixture(t);
  const elevenBytes = 'abcdefghijk'; // 11 ASCII bytes
  assert.equal(elevenBytes.length, 11);
  const accounts = {
    [elevenBytes]: record({ userid: elevenBytes, password: 'goodpass1' })
  };

  const result = importV1Accounts({ accounts, repository });

  assert.equal(result.imported, 0);
  assert.equal(result.rejected.length, 1);
  assert.equal(result.rejected[0].userid, elevenBytes);
  assert.equal(result.rejected[0].code, 'INVALID_USERID');

  assert.equal(repository.findByUserId(elevenBytes), null);
  assert.equal(repository.findByUserId(elevenBytes.slice(0, 10)), null);
});

test('a blank password and an invalid password are both rejected with distinct reasons', (t) => {
  const { repository } = fixture(t);
  const accounts = {
    blankpw: record({ userid: 'blankpw', password: '' }),
    hasspace: record({ userid: 'hasspace', password: 'bad pass' }) // space: not in the password charset
  };

  const result = importV1Accounts({ accounts, repository });

  assert.equal(result.imported, 0);
  assert.equal(result.rejected.length, 2);
  const byUserid = Object.fromEntries(result.rejected.map((entry) => [entry.userid, entry]));
  assert.equal(byUserid.blankpw.code, 'MISSING_PASSWORD');
  assert.equal(byUserid.hasspace.code, 'INVALID_PASSWORD');
});

test('a collision with a pre-existing row under the same userid is skipped, and the row is left byte-identical', (t) => {
  const { repository, database } = fixture(t);
  // Simulate an account that already exists in V2 (e.g. created natively,
  // or from an earlier migration run) BEFORE this import runs, under a
  // DIFFERENT password than the one V1 has on file for the same userid.
  repository.create({ userid: 'preexist', password: 'v2password', displayName: 'preexist' });
  const rowBefore = rowFor(database, 'preexist');

  const accounts = {
    preexist: record({ userid: 'preexist', password: 'v1diffpass1' })
  };

  const result = importV1Accounts({ accounts, repository });

  assert.equal(result.imported, 0);
  assert.equal(result.skippedExisting, 1);
  assert.deepEqual(result.rejected, []);

  const rowAfter = rowFor(database, 'preexist');
  assert.deepEqual(rowBefore, rowAfter);
  // The pre-existing V2 password must still be the one that authenticates -
  // the V1 record must never have overwritten it.
  assert.equal(repository.authenticate('preexist', 'v2password')?.userid, 'preexist');
  assert.equal(repository.authenticate('preexist', 'v1diffpass1'), null);
});

test('a display-name collision with a DIFFERENT existing account is rejected, not silently merged', (t) => {
  const { repository } = fixture(t);
  repository.create({ userid: 'ownerone', password: 'ownerpass', displayName: 'shared_name' });

  const accounts = {
    ownertwo: record({ userid: 'ownertwo', password: 'otherpass', handle: 'shared_name' })
  };

  const result = importV1Accounts({ accounts, repository });

  assert.equal(result.imported, 0);
  assert.equal(result.rejected.length, 1);
  assert.equal(result.rejected[0].userid, 'ownertwo');
  assert.equal(result.rejected[0].code, 'DISPLAY_NAME_COLLISION');
  assert.equal(repository.findByUserId('ownertwo'), null);
});

test('malformed input: top-level accounts value that is not a plain object throws', (t) => {
  const { repository } = fixture(t);
  assert.throws(() => importV1Accounts({ accounts: [], repository }), TypeError);
  assert.throws(() => importV1Accounts({ accounts: 'nope', repository }), TypeError);
  assert.throws(() => importV1Accounts({ accounts: null, repository }), TypeError);
});

test('malformed input: an empty object imports cleanly with zero examined accounts', (t) => {
  const { repository } = fixture(t);
  const result = importV1Accounts({ accounts: {}, repository });
  assert.deepEqual(result, {
    examined: 0,
    imported: 0,
    skippedExisting: 0,
    rejected: [],
    importedUserids: [],
    skippedUserids: [],
    timestampsPreserved: false
  });
});

test('malformed input: an entry missing required fields is rejected with a specific reason', (t) => {
  const { repository } = fixture(t);
  const accounts = {
    nouserid: { password: 'somepass1' },
    nopassword: { userid: 'nopassword' },
    notanobject: 'just-a-string'
  };

  const result = importV1Accounts({ accounts, repository });

  assert.equal(result.imported, 0);
  assert.equal(result.rejected.length, 3);
  const byUserid = Object.fromEntries(result.rejected.map((entry) => [entry.userid, entry]));
  assert.equal(byUserid.nouserid.code, 'MISSING_USERID');
  assert.equal(byUserid.nopassword.code, 'MISSING_PASSWORD');
  assert.equal(byUserid.notanobject.code, 'MALFORMED_ENTRY');
});

/**
 * Policy: the `userid` FIELD is authoritative, and a disagreement with the
 * object's own key is rejected outright rather than trusting either value by
 * guesswork - accounts.json is meant to be keyed by its own userid, so a
 * mismatch signals a corrupt or hand-edited record, not two candidate truths
 * to arbitrate between.
 */
test('malformed input: an entry whose key disagrees with its userid field is rejected, not silently resolved', (t) => {
  const { repository } = fixture(t);
  const accounts = {
    keyone: record({ userid: 'fieldtwo', password: 'goodpass1' })
  };

  const result = importV1Accounts({ accounts, repository });

  assert.equal(result.imported, 0);
  assert.equal(result.rejected.length, 1);
  assert.equal(result.rejected[0].code, 'KEY_USERID_MISMATCH');
  assert.equal(repository.findByUserId('keyone'), null);
  assert.equal(repository.findByUserId('fieldtwo'), null);
});

test('--dry-run semantics: dryRun writes nothing and the database is left untouched', (t) => {
  const { repository, database, filePath } = fixture(t);
  const accounts = {
    player1: record({ userid: 'player1', password: 'secret42' })
  };

  database.connection.exec('PRAGMA wal_checkpoint(TRUNCATE)');
  const before = fs.readFileSync(filePath);

  const result = importV1Accounts({ accounts, repository, dryRun: true });

  assert.equal(result.imported, 1);
  assert.equal(result.skippedExisting, 0);
  assert.deepEqual(result.rejected, []);
  assert.equal(repository.findByUserId('player1'), null);

  database.connection.exec('PRAGMA wal_checkpoint(TRUNCATE)');
  const after = fs.readFileSync(filePath);
  assert.deepEqual(before, after);

  // A real run afterwards must see a clean slate, not a half-applied dry run.
  const real = importV1Accounts({ accounts, repository });
  assert.equal(real.imported, 1);
  assert.equal(repository.authenticate('player1', 'secret42')?.userid, 'player1');
});
