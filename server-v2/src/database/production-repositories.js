import path from 'node:path';

import { parseMasterKey, SecretVault } from '../crypto/secret-vault.js';
import { SecureAccountRepository } from './secure-account-repository.js';
import { SqliteDatabase } from './sqlite-database.js';
import { SqliteSessionRegistry } from './sqlite-session-registry.js';

export function openProductionRepositories({
  dataDirectory,
  masterKey = process.env.PAL_V2_MASTER_KEY,
  clock
}) {
  if (!dataDirectory) throw new Error('dataDirectory is required');
  const database = new SqliteDatabase(path.join(dataDirectory, 'pal-server-v2.sqlite3'));
  const vault = new SecretVault(
    Buffer.isBuffer(masterKey) ? masterKey : parseMasterKey(masterKey)
  );
  return {
    database,
    accounts: new SecureAccountRepository(database, vault, { clock }),
    sessions: new SqliteSessionRegistry(database, { clock })
  };
}

