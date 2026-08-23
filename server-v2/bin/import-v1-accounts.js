#!/usr/bin/env node
/**
 * One-shot migration: import V1's `accounts.json` into the V2 SQLite account
 * store, so a memory card written under V1 keeps authenticating under V2.
 *
 * Deliberately does NOT go through `loadServerConfig()` (`src/config/
 * server-config.js`): that validates the WHOLE composed server - DNS records,
 * a DNAS certificate, `PAL_V2_SELF_HOST`/`PAL_V2_SNAP_HOST`, a directory file -
 * none of which a database-only migration touches or needs. This tool sources
 * exactly the two environment variables the account store itself needs,
 * `PAL_V2_DATA_DIR` and `PAL_V2_MASTER_KEY`, through the SAME factory the
 * composed server uses (`openProductionRepositories`, which derives
 * `pal-server-v2.sqlite3` under `PAL_V2_DATA_DIR` and seals secrets with the
 * same `SecretVault`/`parseMasterKey` path as `src/app/application.js`). So the
 * master-key handling is identical to the server's; only the surrounding
 * configuration surface is narrower, on purpose.
 *
 * Usage:
 *   node server-v2/bin/import-v1-accounts.js <path-to-v1-accounts.json> [--dry-run]
 *
 * Exit codes: 0 clean import, 1 one or more accounts rejected (or a hard
 * failure), 64 (EX_USAGE) bad arguments, 66 (EX_NOINPUT) the accounts file
 * could not be read/parsed, 78 (EX_CONFIG) missing required environment.
 */
import fs from 'node:fs';
import path from 'node:path';
import process from 'node:process';
import { parseArgs } from 'node:util';

import { openProductionRepositories } from '../src/database/production-repositories.js';
import { importV1Accounts } from '../src/database/v1-account-import.js';
import { createLogger } from '../src/logging/logger.js';

function usage() {
  return [
    'Usage: node bin/import-v1-accounts.js <path-to-v1-accounts.json> [--dry-run]',
    '',
    'Imports V1 accounts (userid -> { userid, password, handle, created, lastLogin })',
    'into the V2 account store. Idempotent: an account that already exists under',
    'its userid is left untouched and counted as skipped, never overwritten.',
    '',
    'Required environment (same sourcing as the composed server):',
    '  PAL_V2_DATA_DIR    directory holding pal-server-v2.sqlite3',
    '  PAL_V2_MASTER_KEY  32-byte key (hex or base64) sealing the compatibility secret',
    '',
    'Optional:',
    '  --dry-run          report what would happen; writes nothing',
    '  PAL_V2_LOG_LEVEL   debug|info|warn|error (default info)'
  ].join('\n');
}

function readAccountsFile(filePath, logger) {
  let raw;
  try {
    raw = fs.readFileSync(filePath, 'utf8');
  } catch (error) {
    logger.error('accounts-file-unreadable', { filePath, error: error.message });
    return null;
  }
  try {
    return JSON.parse(raw);
  } catch (error) {
    logger.error('accounts-file-invalid-json', { filePath, error: error.message });
    return null;
  }
}

async function main() {
  const { values, positionals } = parseArgs({
    args: process.argv.slice(2),
    options: {
      'dry-run': { type: 'boolean', default: false },
      help: { type: 'boolean', default: false }
    },
    allowPositionals: true
  });

  const logger = createLogger({
    level: process.env.PAL_V2_LOG_LEVEL ?? 'info',
    service: 'pal-v2-import-v1-accounts'
  });

  if (values.help || positionals.length !== 1) {
    process.stdout.write(`${usage()}\n`);
    process.exitCode = values.help ? 0 : 64; // EX_USAGE
    return;
  }

  const accountsPath = path.resolve(positionals[0]);

  const dataDirectory = process.env.PAL_V2_DATA_DIR;
  const masterKey = process.env.PAL_V2_MASTER_KEY;
  const problems = [];
  if (dataDirectory == null || String(dataDirectory).trim() === '') {
    problems.push('PAL_V2_DATA_DIR is required');
  }
  if (masterKey == null || String(masterKey).trim() === '') {
    problems.push('PAL_V2_MASTER_KEY is required');
  }
  if (problems.length > 0) {
    logger.error('configuration-invalid', { problems });
    process.exitCode = 78; // EX_CONFIG
    return;
  }

  const accounts = readAccountsFile(accountsPath, logger);
  if (accounts == null) {
    process.exitCode = 66; // EX_NOINPUT
    return;
  }

  const resolvedDataDirectory = path.resolve(dataDirectory);
  // Mirrors src/app/application.js: the data directory may not exist yet on a
  // fresh checkout, and creating it here is the same operation the composed
  // server performs before opening the same database file.
  fs.mkdirSync(resolvedDataDirectory, { recursive: true });

  let repositories;
  try {
    repositories = openProductionRepositories({ dataDirectory: resolvedDataDirectory, masterKey });
  } catch (error) {
    logger.error('database-open-failed', { error: error.message });
    process.exitCode = 1;
    return;
  }

  logger.info('import-starting', {
    accountsPath,
    dataDirectory: resolvedDataDirectory,
    dryRun: values['dry-run']
  });

  let result;
  try {
    result = importV1Accounts({
      accounts,
      repository: repositories.accounts,
      logger,
      dryRun: values['dry-run']
    });
  } catch (error) {
    logger.error('import-failed', { error: error.message });
    process.exitCode = 1;
    repositories.database.close();
    return;
  }

  repositories.database.close();

  logger.info('import-finished', {
    dryRun: values['dry-run'],
    examined: result.examined,
    imported: result.imported,
    skippedExisting: result.skippedExisting,
    rejectedCount: result.rejected.length,
    timestampsPreserved: result.timestampsPreserved
  });

  if (!result.timestampsPreserved) {
    // Not a defect being papered over - stated loudly on every run, because
    // `created`/`lastLogin` from V1 are silently dropped: SecureAccountRepository
    // .create() always stamps `createdAtMs = now()` and leaves `lastLoginAtMs`
    // null, and inventing a way to backdate them was explicitly out of scope.
    logger.warn('timestamps-not-preserved', {
      note: 'V1 created/lastLogin are not carried over; imported accounts get ' +
        'createdAtMs = import time and lastLoginAtMs = null'
    });
  }

  for (const rejection of result.rejected) {
    logger.warn('account-rejected', rejection);
  }

  process.exitCode = result.rejected.length > 0 ? 1 : 0;
}

await main();
