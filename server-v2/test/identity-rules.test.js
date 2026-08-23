import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';

import {
  DISPLAY_NAME_MAX_BYTES,
  LOGIN_IDENTITY_MAX_BYTES,
  byteLength,
  checkDisplayName,
  checkLoginIdentity,
  checkPassword
} from '../src/accounts/identity-rules.js';
import { AccountRepository } from '../src/accounts/account-repository.js';
import { JsonFile } from '../src/storage/json-file.js';
import { SqliteDatabase } from '../src/database/sqlite-database.js';
import { SecureAccountRepository } from '../src/database/secure-account-repository.js';
import { SecretVault } from '../src/crypto/secret-vault.js';

function fixture(t) {
  const directory = fs.mkdtempSync(path.join(os.tmpdir(), 'pal-identity-'));
  const database = new SqliteDatabase(path.join(directory, 'accounts.sqlite3'));
  const vault = new SecretVault(Buffer.alloc(32, 0x2b));
  const accounts = new SecureAccountRepository(database, vault);
  t.after(() => {
    database.close();
    fs.rmSync(directory, { recursive: true, force: true });
  });
  return accounts;
}

/**
 * The client's account-creation path is a fixed-width `strncpy(dst, src, 10)`,
 * so 10 bytes is the last identity that survives the round trip through HTML,
 * the memory card and the UDP-9090 register intact. 11 must be REJECTED, never
 * truncated: truncating would let two distinct accounts collide on the wire and
 * would surface as a Blowfish failure, because the register reply is keyed on
 * the looked-up account's password.
 */
test('login identity boundary is exactly 10 bytes: 9 and 10 pass, 11 is rejected', () => {
  assert.equal(checkLoginIdentity('a'.repeat(9)), null);
  assert.equal(checkLoginIdentity('a'.repeat(10)), null);
  assert.equal(LOGIN_IDENTITY_MAX_BYTES, 10);

  const rejected = checkLoginIdentity('a'.repeat(11));
  assert.ok(rejected, '11 bytes must be rejected');
  assert.equal(rejected.code, 'INVALID_USERID');

  // The whole 11-14 band the old validator accepted.
  for (const length of [11, 12, 13, 14]) {
    assert.ok(checkLoginIdentity('x'.repeat(length)), `${length} must be rejected`);
  }
  // And the lower bound still holds.
  assert.ok(checkLoginIdentity('ab'));
  assert.equal(checkLoginIdentity('abc'), null);
});

test('the repository rejects an over-long identity instead of truncating it', (t) => {
  const accounts = fixture(t);
  assert.throws(
    () => accounts.create({ userid: '12345abcdef', password: 'secret42' }),
    (error) => error.code === 'INVALID_USERID'
  );
  // Nothing was written under the truncated form either.
  assert.equal(accounts.findByUserId('12345abcde'), null);
  assert.equal(accounts.findByUserId('12345abcdef'), null);
});

test('the longest identity ever seen on the wire is still accepted', (t) => {
  const accounts = fixture(t);
  // V1's account store held exactly this, created 2026-05-24.
  const account = accounts.create({ userid: '12345abcde', password: 'secret42' });
  assert.equal(account.userid, '12345abcde');
  assert.equal(byteLength(account.userid), 10);
});

test('both repositories enforce the same 9/10/11 boundary through create()', (t) => {
  const accounts = fixture(t);
  assert.equal(accounts.create({ userid: 'a'.repeat(9), password: 'secret42' }).userid, 'aaaaaaaaa');
  assert.equal(accounts.create({ userid: 'b'.repeat(10), password: 'secret42' }).userid, 'bbbbbbbbbb');
  assert.throws(
    () => accounts.create({ userid: 'c'.repeat(11), password: 'secret42' }),
    (error) => error.code === 'INVALID_USERID'
  );

  // The JSON repository is a second create() implementation and must agree.
  const directory = fs.mkdtempSync(path.join(os.tmpdir(), 'pal-identity-json-'));
  t.after(() => fs.rmSync(directory, { recursive: true, force: true }));
  const jsonAccounts = new AccountRepository(
    new JsonFile(path.join(directory, 'accounts.json'), {
      createDefault: AccountRepository.emptyDocument
    })
  );
  assert.equal(jsonAccounts.create({ userid: 'd'.repeat(9), password: 'secret42' }).userid, 'ddddddddd');
  assert.equal(jsonAccounts.create({ userid: 'e'.repeat(10), password: 'secret42' }).userid, 'eeeeeeeeee');
  assert.throws(
    () => jsonAccounts.create({ userid: 'f'.repeat(11), password: 'secret42' }),
    (error) => error.code === 'INVALID_USERID'
  );
});

test('a display name may equal another account login identity, and stays unique in its own namespace', (t) => {
  const accounts = fixture(t);
  // ALPHA takes a display name of its own, so the string 'ALPHA' is free in the
  // display-name namespace while being taken in the identity namespace.
  accounts.create({ userid: 'ALPHA', password: 'secret42', displayName: 'Alpha One' });

  // Distinct namespaces: BOB's display name colliding with ALPHA's IDENTITY is
  // fine. `WHERE userid = ? OR handle = ?` used to reject exactly this.
  const bob = accounts.create({ userid: 'BOB', password: 'secret42', displayName: 'ALPHA' });
  assert.equal(bob.userid, 'BOB');
  assert.equal(bob.displayName, 'ALPHA');

  // But two accounts may not share a display name.
  assert.throws(
    () => accounts.create({ userid: 'CAROL', password: 'secret42', displayName: 'ALPHA' }),
    (error) => error.code === 'DISPLAY_NAME_TAKEN'
  );
  // And an identity is still unique in its own namespace.
  assert.throws(
    () => accounts.create({ userid: 'BOB', password: 'secret42', displayName: 'Bob Two' }),
    (error) => error.code === 'USER_EXISTS'
  );
});

test('non-ASCII is refused outright, so a byte count and a character count cannot diverge', () => {
  // Five full-width katakana: 5 characters, but 10 bytes in Shift-JIS and 15 in
  // UTF-8. A character-count check would wave this straight through.
  const fullWidth = 'アイウエオ';
  assert.equal(fullWidth.length, 5, 'five characters');

  const rejected = checkLoginIdentity(fullWidth);
  assert.ok(rejected, 'non-ASCII must not reach the wire');
  assert.equal(rejected.code, 'INVALID_USERID');

  // Latin-1 above ASCII is equally refused, even though it is one byte wide.
  assert.ok(checkLoginIdentity('caféname'));
  // A display name has no proven encoding either, so it is ASCII-only too.
  assert.ok(checkDisplayName(fullWidth));

  // Astral pairs and lone surrogates are rejected as code units rather than
  // silently counted as one "character".
  assert.ok(checkDisplayName('ab\u{1f600}cd'));
  assert.ok(checkDisplayName('ab\ud800cd'));

  // The limits are enforced in bytes. Because the charset gate admits only
  // ASCII, byteLength() and .length agree BY CONSTRUCTION - that equivalence is
  // the purpose of the gate, not a coincidence, and it is what makes a
  // character-counting bug unreachable here.
  assert.equal(byteLength('abc'), 3);
  assert.equal(byteLength(''), 0);
});

test('display name is bounded by the 16-byte roster field, not by the identity limit', () => {
  // The op06 member record name is 16 bytes NUL-padded, so 15 are usable, and a
  // display name is NOT subject to the client's 10-byte account-creation copy.
  assert.equal(DISPLAY_NAME_MAX_BYTES, 15);
  assert.equal(checkDisplayName('a'.repeat(15)), null);
  assert.ok(checkDisplayName('a'.repeat(16)));
  // Longer than a login identity is legitimate here.
  assert.equal(checkDisplayName('a'.repeat(11)), null);
  // A space is fine in a roster name but not in an identity or a password.
  assert.equal(checkDisplayName('Jill Valen'), null);
  assert.ok(checkLoginIdentity('Jill Valen'));
  assert.ok(checkPassword('with space'));
});

test('display name may not end with a dash, because both roster fillers strip it', () => {
  const rejected = checkDisplayName('PLAYER-');
  assert.ok(rejected);
  assert.equal(rejected.code, 'INVALID_DISPLAY_NAME');
  assert.equal(checkDisplayName('PLAY-ER'), null);
});

/**
 * The register looks the account up by LOGIN IDENTITY and uses that account's
 * password as the Blowfish key. If the lookup, the sealed secret and the
 * persisted identity ever disagreed, a correct password would produce a reply
 * the client rejects, and it would look like a crypto bug.
 */
test('lookup, sealed secret and persisted identity all use one validated value', (t) => {
  const accounts = fixture(t);
  const created = accounts.create({
    userid: 'REAL_ID',
    password: '1234567890',
    displayName: 'Display Nm'
  });

  assert.equal(created.userid, 'REAL_ID');
  assert.equal(created.displayName, 'Display Nm');

  // Persisted identity == lookup key == the key the sealed secret is bound to.
  assert.equal(accounts.findByUserId('REAL_ID').userid, 'REAL_ID');
  assert.equal(accounts.getCompatibilitySecretByLoginIdentity('REAL_ID'), '1234567890');

  // The display name is NOT an authentication key and must not open the secret.
  assert.equal(accounts.getCompatibilitySecretByLoginIdentity('Display Nm'), null);
  assert.equal(accounts.findByDisplayName('Display Nm').userid, 'REAL_ID');

  // Authentication is by identity, and returns the display name separately.
  const authenticated = accounts.authenticate('REAL_ID', '1234567890');
  assert.equal(authenticated.userid, 'REAL_ID');
  assert.equal(authenticated.displayName, 'Display Nm');
  assert.equal(accounts.authenticate('Display Nm', '1234567890'), null);
});

test('a display name defaults to the login identity when none is chosen', (t) => {
  const accounts = fixture(t);
  const account = accounts.create({ userid: 'LEGACY1', password: 'secret42' });
  assert.equal(account.displayName, 'LEGACY1');
});
