import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import test from 'node:test';

import {
  AccountRepository,
  AccountValidationError
} from '../src/accounts/account-repository.js';
import { JsonFile } from '../src/storage/json-file.js';

function fixture() {
  const directory = fs.mkdtempSync(path.join(os.tmpdir(), 'pal-v2-account-'));
  const filePath = path.join(directory, 'accounts.json');
  const clock = () => new Date('2026-07-30T20:00:00.000Z');
  const jsonFile = new JsonFile(filePath, { createDefault: AccountRepository.emptyDocument });
  return {
    directory,
    filePath,
    repository: new AccountRepository(jsonFile, { clock })
  };
}

test('persists the exact PAL compatibility secret and can reload it', (t) => {
  const { directory, filePath, repository } = fixture();
  t.after(() => fs.rmSync(directory, { recursive: true, force: true }));

  repository.create({ userid: 'PLAYER_1', password: 'secret42' });
  const reloaded = new AccountRepository(
    new JsonFile(filePath, { createDefault: AccountRepository.emptyDocument })
  );

  assert.equal(reloaded.authenticate('PLAYER_1', 'secret42').displayName, 'PLAYER_1');
  assert.equal(reloaded.authenticate('PLAYER_1', 'wrong-password'), null);
});

test('rejects duplicate and out-of-range account input', (t) => {
  const { directory, repository } = fixture();
  t.after(() => fs.rmSync(directory, { recursive: true, force: true }));

  repository.create({ userid: 'PLAYER2', password: 'abcd' });
  assert.throws(
    () => repository.create({ userid: 'PLAYER2', password: 'abcd' }),
    (error) => error instanceof AccountValidationError && error.code === 'USER_EXISTS'
  );
  assert.throws(
    () => repository.create({ userid: '../bad', password: 'abcd' }),
    (error) => error instanceof AccountValidationError && error.code === 'INVALID_USERID'
  );
});

