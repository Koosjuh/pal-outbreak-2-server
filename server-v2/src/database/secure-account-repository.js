import crypto from 'node:crypto';
import { checkDisplayName, checkLoginIdentity, checkPassword } from '../accounts/identity-rules.js';

const SCRYPT_N = 1 << 14;
const SCRYPT_R = 8;
const SCRYPT_P = 1;
const HASH_BYTES = 32;
const SALT_BYTES = 16;
const SCRYPT_MAX_MEMORY = 32 * 1024 * 1024;

function requireLoginIdentity(value, field = 'userid') {
  const normalized = String(value ?? '');
  const failure = checkLoginIdentity(normalized, field);
  if (failure) throw new SecureAccountError(failure.code, failure.message);
  return normalized;
}

function requireDisplayName(value, field = 'displayName') {
  const normalized = String(value ?? '');
  const failure = checkDisplayName(normalized, field);
  if (failure) throw new SecureAccountError(failure.code, failure.message);
  return normalized;
}

function requirePassword(value) {
  const normalized = String(value ?? '');
  const failure = checkPassword(normalized);
  if (failure) throw new SecureAccountError(failure.code, failure.message);
  return normalized;
}

function derive(password, salt, n = SCRYPT_N, r = SCRYPT_R, p = SCRYPT_P) {
  return crypto.scryptSync(Buffer.from(password, 'latin1'), salt, HASH_BYTES, {
    N: n,
    r,
    p,
    maxmem: SCRYPT_MAX_MEMORY
  });
}

function publicAccount(row) {
  return {
    // The persistent authentication identity. This is what the UDP-9090
    // register carries and what its account lookup must key on.
    userid: row.userid,
    // The roster display name. The `handle` COLUMN holds it; the name predates
    // the distinction and is kept so no schema migration is needed.
    displayName: row.handle,
    createdAtMs: row.created_at_ms,
    lastLoginAtMs: row.last_login_at_ms
  };
}

export class SecureAccountError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'SecureAccountError';
    this.code = code;
  }
}

export class SecureAccountRepository {
  constructor(database, vault, { clock = () => Date.now() } = {}) {
    this.database = database;
    this.connection = database.connection;
    this.vault = vault;
    this.clock = clock;
    this.dummySalt = Buffer.alloc(SALT_BYTES, 0x5a);
    this.dummyHash = derive('invalid-credential', this.dummySalt);
  }

  create({ userid, password, displayName = userid }) {
    const id = requireLoginIdentity(userid);
    const rosterDisplayName = requireDisplayName(displayName);
    const compatibilitySecret = requirePassword(password);
    // Two namespaces, checked separately. `userid OR handle` would reject a new
    // account whose display name merely equals SOME OTHER account's login
    // identity - one namespace with two meanings, which is the bug class this
    // whole module exists to prevent. It would also leak identity existence
    // through the display-name field.
    const identityTaken = this.connection
      .prepare('SELECT 1 FROM accounts WHERE userid = ?')
      .get(id);
    if (identityTaken) throw new SecureAccountError('USER_EXISTS', 'account already exists');
    const displayNameTaken = this.connection
      .prepare('SELECT 1 FROM accounts WHERE handle = ?')
      .get(rosterDisplayName);
    if (displayNameTaken) {
      throw new SecureAccountError('DISPLAY_NAME_TAKEN', 'display name already in use');
    }

    const salt = crypto.randomBytes(SALT_BYTES);
    const hash = derive(compatibilitySecret, salt);
    const sealed = this.vault.seal(id, compatibilitySecret);
    const now = this.clock();

    this.connection
      .prepare(`
        INSERT INTO accounts (
          userid, handle, password_salt, password_hash, scrypt_n, scrypt_r, scrypt_p,
          secret_key_version, secret_nonce, secret_ciphertext, secret_authentication_tag,
          created_at_ms, last_login_at_ms
        ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, NULL)
      `)
      .run(
        id,
        rosterDisplayName,
        salt,
        hash,
        SCRYPT_N,
        SCRYPT_R,
        SCRYPT_P,
        sealed.keyVersion,
        sealed.nonce,
        sealed.ciphertext,
        sealed.authenticationTag,
        now
      );
    return this.findByUserId(id);
  }

  authenticate(userid, password) {
    let id;
    let supplied;
    try {
      id = requireLoginIdentity(userid);
      supplied = requirePassword(password);
    } catch {
      derive('invalid-credential', this.dummySalt);
      return null;
    }

    const row = this.connection.prepare('SELECT * FROM accounts WHERE userid = ?').get(id);
    const actual = row
      ? derive(supplied, row.password_salt, row.scrypt_n, row.scrypt_r, row.scrypt_p)
      : derive(supplied, this.dummySalt);
    const expected = row ? row.password_hash : this.dummyHash;
    if (!crypto.timingSafeEqual(actual, expected) || !row) return null;

    const now = this.clock();
    this.connection
      .prepare('UPDATE accounts SET last_login_at_ms = ? WHERE userid = ?')
      .run(now, id);
    row.last_login_at_ms = now;
    return publicAccount(row);
  }

  findByUserId(userid) {
    const row = this.connection
      .prepare('SELECT * FROM accounts WHERE userid = ?')
      .get(String(userid ?? ''));
    return row ? publicAccount(row) : null;
  }

  findByDisplayName(displayName) {
    const row = this.connection
      .prepare('SELECT * FROM accounts WHERE handle = ?')
      .get(String(displayName ?? ''));
    return row ? publicAccount(row) : null;
  }

  /**
   * The plaintext password, for the one protocol that genuinely needs it: the
   * UDP-9090 register reply body is Blowfish-encrypted with the raw account
   * password as the key.
   *
   * Keyed on the LOGIN IDENTITY, never on the display name. The identity the
   * client puts in the register is the one written to its memory card by the
   * account-creation flow, which is `accounts.userid`. Keying this on the
   * display name would work only for as long as the two happen to be equal.
   *
   * CALLER OBLIGATION: the register's wire field is 40 bytes NUL-padded
   * (`strncpy(msg + 0, handle, 0x28)`). Pass the trimmed C string, never the raw
   * padded buffer - otherwise every lookup returns null, and because this feeds
   * the Blowfish key that surfaces as a crypto failure rather than as a missing
   * account.
   */
  getCompatibilitySecretByLoginIdentity(userid) {
    const row = this.connection
      .prepare('SELECT * FROM accounts WHERE userid = ?')
      .get(String(userid ?? ''));
    if (!row) return null;
    return this.vault.open(row.userid, {
      keyVersion: row.secret_key_version,
      nonce: row.secret_nonce,
      ciphertext: row.secret_ciphertext,
      authenticationTag: row.secret_authentication_tag
    });
  }
}

