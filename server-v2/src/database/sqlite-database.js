import fs from 'node:fs';
import path from 'node:path';
import { DatabaseSync } from 'node:sqlite';

const SCHEMA = `
CREATE TABLE IF NOT EXISTS schema_migrations (
  version INTEGER PRIMARY KEY,
  applied_at_ms INTEGER NOT NULL
);

CREATE TABLE IF NOT EXISTS accounts (
  userid TEXT PRIMARY KEY COLLATE BINARY,
  handle TEXT NOT NULL UNIQUE COLLATE BINARY,
  password_salt BLOB NOT NULL,
  password_hash BLOB NOT NULL,
  scrypt_n INTEGER NOT NULL,
  scrypt_r INTEGER NOT NULL,
  scrypt_p INTEGER NOT NULL,
  secret_key_version INTEGER NOT NULL,
  secret_nonce BLOB NOT NULL,
  secret_ciphertext BLOB NOT NULL,
  secret_authentication_tag BLOB NOT NULL,
  created_at_ms INTEGER NOT NULL,
  last_login_at_ms INTEGER
) STRICT;

CREATE TABLE IF NOT EXISTS sessions (
  connection_id TEXT PRIMARY KEY,
  userid TEXT NOT NULL REFERENCES accounts(userid) ON DELETE CASCADE,
  remote_address TEXT NOT NULL,
  created_at_ms INTEGER NOT NULL,
  updated_at_ms INTEGER NOT NULL,
  expires_at_ms INTEGER NOT NULL,
  lobby_provisioned_at_ms INTEGER
) STRICT;

CREATE INDEX IF NOT EXISTS sessions_userid_idx ON sessions(userid);
CREATE INDEX IF NOT EXISTS sessions_expiry_idx ON sessions(expires_at_ms);
`;

export class SqliteDatabase {
  constructor(filePath) {
    if (!filePath) throw new Error('database path is required');
    this.filePath = filePath === ':memory:' ? filePath : path.resolve(filePath);
    if (this.filePath !== ':memory:') {
      fs.mkdirSync(path.dirname(this.filePath), { recursive: true });
    }
    this.connection = new DatabaseSync(this.filePath);
    this.connection.exec('PRAGMA foreign_keys = ON');
    this.connection.exec('PRAGMA busy_timeout = 5000');
    if (this.filePath !== ':memory:') {
      this.connection.exec('PRAGMA journal_mode = WAL');
      this.connection.exec('PRAGMA synchronous = FULL');
    }
    this.#migrate();
  }

  #migrate() {
    this.transaction(() => {
      this.connection.exec(SCHEMA);
      this.connection
        .prepare(
          'INSERT OR IGNORE INTO schema_migrations(version, applied_at_ms) VALUES (?, ?)'
        )
        .run(1, Date.now());
    });
  }

  transaction(callback) {
    this.connection.exec('BEGIN IMMEDIATE');
    try {
      const result = callback();
      this.connection.exec('COMMIT');
      return result;
    } catch (error) {
      this.connection.exec('ROLLBACK');
      throw error;
    }
  }

  close() {
    this.connection.close();
  }
}

