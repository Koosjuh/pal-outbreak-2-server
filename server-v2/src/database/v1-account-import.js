import { checkDisplayName, checkLoginIdentity, checkPassword } from '../accounts/identity-rules.js';
import { SecureAccountError } from './secure-account-repository.js';

/**
 * Import V1's `accounts.json` into a V2 `SecureAccountRepository`.
 *
 * WHY this exists at all: the UDP-9090 register reply body is Blowfish-encrypted
 * with the account's RAW PASSWORD as the key (see
 * `SecureAccountRepository#getCompatibilitySecretByLoginIdentity`), so a memory
 * card written under V1 keeps working under V2 only if the exact plaintext
 * password survives the move into the vault. V1's `password` therefore becomes
 * the V2 compatibility secret, and V1's `handle` becomes the V2 roster
 * `displayName` - not the other way around, and never guessed or reset.
 *
 * Fails CLOSED per account, never per run: one bad V1 record must not stop the
 * other fifteen from migrating, and a record this function cannot place safely
 * is rejected with a specific, inspectable reason rather than repaired,
 * defaulted or truncated. In particular this function will never invent a
 * password or an identity: a field that does not validate is a reject, not a
 * best-effort import.
 *
 * @param {object} accounts
 *   V1's parsed `accounts.json`: a plain object keyed by userid, each value
 *   shaped like `{ userid, password, handle?, created?, lastLogin? }`.
 * @param {import('./secure-account-repository.js').SecureAccountRepository} repository
 * @param {{info: Function, warn: Function}} [logger]
 *   Optional structured logger (see `src/logging/logger.js`). Defaults to a
 *   no-op so this stays usable from a plain unit test.
 * @param {boolean} [dryRun]
 *   When true, every write happens inside a transaction that is always rolled
 *   back, so the returned result describes exactly what a real run would do
 *   without persisting anything. Requires `repository.database` to expose the
 *   `transaction()` helper (true for every repository built on
 *   `SqliteDatabase`).
 * @returns {{
 *   examined: number,
 *   imported: number,
 *   skippedExisting: number,
 *   rejected: Array<{ userid: string, reason: string, code: string }>,
 *   importedUserids: string[],
 *   skippedUserids: string[],
 *   timestampsPreserved: boolean
 * }}
 */
export function importV1Accounts({ accounts, repository, logger = NOOP_LOGGER, dryRun = false }) {
  if (accounts == null || typeof accounts !== 'object' || Array.isArray(accounts)) {
    // A malformed TOP-LEVEL document (not the per-account records inside it) is
    // a caller/file-format bug, not something a per-account reject can express
    // - there is no per-account list to walk.
    throw new TypeError('accounts must be a plain object mapping userid to a V1 account record');
  }

  const result = {
    examined: 0,
    imported: 0,
    skippedExisting: 0,
    rejected: [],
    importedUserids: [],
    skippedUserids: [],
    // SecureAccountRepository#create() always stamps `createdAtMs = now()` and
    // leaves `lastLoginAtMs` null; it accepts no override. Checked against the
    // current implementation, not assumed - so this is reported, never faked.
    timestampsPreserved: false
  };

  const run = () => {
    for (const [key, record] of Object.entries(accounts)) {
      result.examined += 1;
      importOne(key, record, repository, result, logger);
    }
  };

  if (!dryRun) {
    run();
    return result;
  }

  // Dry run: reuse the database's own transaction so "writes nothing" is a
  // property of SQLite's rollback, not of a hand-rolled undo that could drift
  // from what create() actually does.
  class DryRunAbort extends Error {}
  try {
    repository.database.transaction(() => {
      run();
      throw new DryRunAbort('dry run - discarding writes');
    });
  } catch (error) {
    if (!(error instanceof DryRunAbort)) throw error;
  }
  return result;
}

const NOOP_LOGGER = { info() {}, warn() {} };

function reject(result, logger, userid, code, reason) {
  result.rejected.push({ userid, reason, code });
  logger.warn('v1-account-rejected', { userid, code, reason });
}

/**
 * Validate and classify one V1 record. Returns either `{ ok: true, userid,
 * password, displayName }` or `{ ok: false, userid, code, reason }` -
 * `userid` here is the best identifier available for reporting, which for a
 * record missing/disagreeing on its own userid field falls back to the
 * `accounts.json` object key.
 */
function classify(key, record) {
  if (record == null || typeof record !== 'object' || Array.isArray(record)) {
    return { ok: false, userid: key, code: 'MALFORMED_ENTRY', reason: 'account record is not an object' };
  }

  const hasUserid = record.userid != null && String(record.userid).trim() !== '';
  if (!hasUserid) {
    return { ok: false, userid: key, code: 'MISSING_USERID', reason: 'userid is missing or blank' };
  }
  const userid = String(record.userid);

  // Trust the `userid` FIELD as the authoritative identity and reject a
  // disagreement with the object key outright, rather than guessing which of
  // the two is correct (per owner instruction: trust the field, reject the
  // mismatch - see the migration task's key-vs-field policy).
  if (userid !== key) {
    return {
      ok: false,
      userid: key,
      code: 'KEY_USERID_MISMATCH',
      reason: `accounts.json key ${JSON.stringify(key)} disagrees with its own userid field ${JSON.stringify(userid)}`
    };
  }

  const hasPassword = record.password != null && String(record.password) !== '';
  if (!hasPassword) {
    return { ok: false, userid, code: 'MISSING_PASSWORD', reason: 'password is missing or blank' };
  }
  const password = String(record.password);

  const useridFailure = checkLoginIdentity(userid);
  if (useridFailure) {
    return { ok: false, userid, code: useridFailure.code, reason: useridFailure.message };
  }

  const passwordFailure = checkPassword(password);
  if (passwordFailure) {
    return { ok: false, userid, code: passwordFailure.code, reason: passwordFailure.message };
  }

  // V1's invariant is `handle === userid` for every one of the 16 production
  // accounts, so an absent/blank handle defaults to the userid - the same
  // default `SecureAccountRepository#create()` itself uses for a fresh
  // account, not a new convention invented for this migration.
  const rawDisplayName = record.handle != null && String(record.handle).trim() !== ''
    ? String(record.handle)
    : userid;
  const displayNameFailure = checkDisplayName(rawDisplayName);
  if (displayNameFailure) {
    return { ok: false, userid, code: displayNameFailure.code, reason: displayNameFailure.message };
  }

  return { ok: true, userid, password, displayName: rawDisplayName };
}

function importOne(key, record, repository, result, logger) {
  const classified = classify(key, record);
  if (!classified.ok) {
    reject(result, logger, classified.userid, classified.code, classified.reason);
    return;
  }
  const { userid, password, displayName } = classified;

  // Idempotency: an account already present under this login identity is left
  // COMPLETELY alone - no update, no re-seal, no touch - whether it is here
  // because a previous run of this same migration already imported it, or
  // because a V2-native account happens to occupy that identity already.
  if (repository.findByUserId(userid) != null) {
    result.skippedExisting += 1;
    result.skippedUserids.push(userid);
    logger.info('v1-account-already-present', { userid });
    return;
  }

  // A DIFFERENT identity already owns this display name. Unlike the case
  // above there is no existing row to defer to - importing anyway would
  // either violate the `handle` UNIQUE constraint or (impossible here, since
  // we already confirmed no row owns THIS userid) silently take someone
  // else's display name. There is nothing safe to guess, so this one account
  // is rejected and the run continues.
  const displayNameOwner = repository.findByDisplayName(displayName);
  if (displayNameOwner != null) {
    reject(
      result,
      logger,
      userid,
      'DISPLAY_NAME_COLLISION',
      `display name ${JSON.stringify(displayName)} is already used by a different account`
    );
    return;
  }

  try {
    repository.create({ userid, password, displayName });
  } catch (error) {
    // Defensive: a concurrent writer could win a TOCTOU race between the
    // checks above and this insert. Translate the repository's own rejection
    // into the same reject-and-continue shape rather than crashing the run;
    // anything else is a real bug and must propagate.
    if (error instanceof SecureAccountError) {
      reject(result, logger, userid, error.code, error.message);
      return;
    }
    throw error;
  }

  result.imported += 1;
  result.importedUserids.push(userid);
  logger.info('v1-account-imported', { userid });
}
