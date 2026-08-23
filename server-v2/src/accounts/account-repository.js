import { checkDisplayName, checkLoginIdentity, checkPassword } from './identity-rules.js';

function requireLoginIdentity(value, field = 'userid') {
  const normalized = String(value ?? '');
  const failure = checkLoginIdentity(normalized, field);
  if (failure) throw new AccountValidationError(failure.code, failure.message);
  return normalized;
}

function requireDisplayName(value, field = 'displayName') {
  const normalized = String(value ?? '');
  const failure = checkDisplayName(normalized, field);
  if (failure) throw new AccountValidationError(failure.code, failure.message);
  return normalized;
}

function requirePassword(value) {
  const normalized = String(value ?? '');
  const failure = checkPassword(normalized);
  if (failure) throw new AccountValidationError(failure.code, failure.message);
  return normalized;
}

export class AccountValidationError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'AccountValidationError';
    this.code = code;
  }
}

/**
 * Account storage retains the exact compatibility secret because the PAL UDP registration reply is
 * encrypted with the password the player typed. A one-way password verifier alone cannot produce
 * that reply. The production data directory must therefore be private and backed up as sensitive
 * data.
 */
export class AccountRepository {
  constructor(jsonFile, { clock = () => new Date() } = {}) {
    this.jsonFile = jsonFile;
    this.clock = clock;
    const document = this.jsonFile.read();
    if (document.schemaVersion !== 1 || typeof document.accounts !== 'object') {
      throw new Error('unsupported or malformed account store');
    }
  }

  static emptyDocument() {
    return { schemaVersion: 1, accounts: {} };
  }

  create({ userid, password, displayName = userid }) {
    const id = requireLoginIdentity(userid);
    const rosterDisplayName = requireDisplayName(displayName);
    const compatibilitySecret = requirePassword(password);
    const document = this.jsonFile.read();
    if (document.accounts[id]) {
      throw new AccountValidationError('USER_EXISTS', 'account already exists');
    }
    // Matches SecureAccountRepository, which gets this from the `handle` column's
    // UNIQUE constraint. Two display names that collide would make two players
    // indistinguishable in a roster.
    const displayNameTaken = Object.values(document.accounts).some(
      (candidate) => candidate.displayName === rosterDisplayName
    );
    if (displayNameTaken) {
      throw new AccountValidationError('DISPLAY_NAME_TAKEN', 'display name already in use');
    }

    const now = this.clock().toISOString();
    const account = {
      userid: id,
      displayName: rosterDisplayName,
      compatibilitySecret,
      createdAt: now,
      lastLoginAt: null
    };
    document.accounts[id] = account;
    this.jsonFile.replace(document);
    return { ...account };
  }

  authenticate(userid, password) {
    const id = requireLoginIdentity(userid);
    const supplied = requirePassword(password);
    const document = this.jsonFile.read();
    const account = document.accounts[id];
    if (!account || account.compatibilitySecret !== supplied) return null;

    account.lastLoginAt = this.clock().toISOString();
    this.jsonFile.replace(document);
    return { ...account };
  }

  findByUserId(userid) {
    const id = String(userid ?? '');
    const account = this.jsonFile.read().accounts[id];
    return account ? { ...account } : null;
  }

  findByDisplayName(displayName) {
    const wanted = String(displayName ?? '');
    const account = Object.values(this.jsonFile.read().accounts).find(
      (candidate) => candidate.displayName === wanted
    );
    return account ? { ...account } : null;
  }
}

