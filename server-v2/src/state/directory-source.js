import fs from 'node:fs';

import {
  DIRECTORY_PROVENANCE,
  DirectoryState,
  DirectoryStateError,
  createDirectoryState
} from './directory-state.js';

/**
 * The directory a connection reads, and how a newer one replaces it.
 *
 * `DirectoryState` is immutable, so "publishing" is a pointer swap: a projection
 * captures the snapshot it was built with and keeps reading that exact object
 * for the life of the connection. A client already walking entry 3 of a
 * seven-entry directory is therefore never handed a shorter list mid-walk, and a
 * newer snapshot cannot corrupt an in-flight projection. New connections get the
 * new snapshot.
 *
 * This is the seam for dynamic rooms. Nothing here builds one: when a room store
 * exists, composition assembles static areas plus live rooms into a fresh
 * `DirectoryState` and calls `publish`. Until the room-browser path proves that
 * a record IS a room, no such mapping is assumed.
 */
export class PublishableDirectoryProvider {
  #state;
  #publishedCount = 1;
  #onPublish;

  constructor(state, { onPublish = () => {} } = {}) {
    if (!(state instanceof DirectoryState)) {
      throw new TypeError('PublishableDirectoryProvider requires a DirectoryState');
    }
    this.#state = state;
    this.#onPublish = onPublish;
  }

  /** Called once per connection; the returned snapshot is that connection's. */
  currentDirectory() {
    return this.#state;
  }

  get publishedCount() {
    return this.#publishedCount;
  }

  publish(state) {
    if (!(state instanceof DirectoryState)) {
      throw new TypeError('publish requires a DirectoryState');
    }
    state.assertServable({
      allowTestFixture: state.provenance === DIRECTORY_PROVENANCE.TEST_FIXTURE &&
        this.#state.provenance === DIRECTORY_PROVENANCE.TEST_FIXTURE
    });
    const previous = this.#state;
    this.#state = state;
    this.#publishedCount += 1;
    this.#onPublish({
      publishedCount: this.#publishedCount,
      entryCount: state.entryCount,
      recordCount: state.totalRecordCount,
      previousEntryCount: previous.entryCount
    });
    return state;
  }
}

/**
 * Opaque bytes in the directory file.
 *
 * A bare string is latin1, which is what the PAL field codec transports, and
 * `{ "hex": "…" }` carries values that are not printable. Nothing is guessed: a
 * field the operator did not write is a validation error, not an empty default.
 */
function readOpaque(value, where, problems) {
  if (typeof value === 'string') return Buffer.from(value, 'latin1');
  if (value != null && typeof value === 'object' && typeof value.hex === 'string') {
    if (!/^[0-9a-f]*$/i.test(value.hex) || value.hex.length % 2 !== 0) {
      problems.push(`${where} hex must be an even-length hex string`);
      return Buffer.alloc(0);
    }
    return Buffer.from(value.hex, 'hex');
  }
  problems.push(`${where} must be a latin1 string or { "hex": "…" }`);
  return Buffer.alloc(0);
}

function readNumber(value, where, problems) {
  if (!Number.isSafeInteger(value) || value < 0) {
    problems.push(`${where} must be a non-negative integer`);
    return 0;
  }
  return value;
}

/**
 * Parse an operator-authored directory document into a `DirectoryState`.
 *
 * Provenance is taken from the document, not assumed: a file that declares
 * itself a test fixture stays one, and production startup refuses it.
 */
export function parseDirectoryDocument(document, { source = 'directory document' } = {}) {
  const problems = [];
  if (document == null || typeof document !== 'object' || Array.isArray(document)) {
    throw new DirectoryStateError('DIRECTORY_SHAPE', `${source} must be a JSON object`);
  }
  const provenance = document.provenance;
  if (provenance !== DIRECTORY_PROVENANCE.OPERATOR &&
      provenance !== DIRECTORY_PROVENANCE.TEST_FIXTURE) {
    problems.push(
      `${source} must declare "provenance": "operator" or "test-fixture"`
    );
  }
  if (!Array.isArray(document.entries)) {
    throw new DirectoryStateError('DIRECTORY_SHAPE', `${source} needs an "entries" array`);
  }

  // An explicit, self-declaring rig boundary. The file carrying rig values is
  // the file that admits to it; a production document simply omits this.
  const rigFixture = document.rigFixture === true;
  const entries = document.entries.map((entry, entryIndex) => {
    const where = `${source} entry ${entryIndex}`;
    const records = Array.isArray(entry?.records) ? entry.records : [];
    if (!Array.isArray(entry?.records)) {
      problems.push(`${where} needs a "records" array`);
    }
    return {
      entryId: String(entry?.entryId ?? `entry-${entryIndex}`),
      // The 0x6503 entry fields. `host` is the connect target the client
      // resolves on selection (T30/T31); the rest are opaque.
      host: readOpaque(entry?.host, `${where} host`, problems),
      name: readOpaque(entry?.name, `${where} name`, problems),
      raw8: readOpaque(entry?.raw8, `${where} raw8`, problems),
      description: readOpaque(entry?.description, `${where} description`, problems),
      pageField: readOpaque(entry?.pageField, `${where} pageField`, problems),
      command6502Unknown0: readNumber(
        entry?.command6502Unknown0, `${where} command6502Unknown0`, problems
      ),
      command6502Unknown1: readNumber(
        entry?.command6502Unknown1, `${where} command6502Unknown1`, problems
      ),
      records: records.map((record, recordIndex) => {
        const recordWhere = `${where} record ${recordIndex}`;
        return {
          recordId: String(record?.recordId ?? `${entryIndex}-${recordIndex}`),
          unknownField0: readOpaque(record?.unknownField0, `${recordWhere} unknownField0`, problems),
          unknownField1: readOpaque(record?.unknownField1, `${recordWhere} unknownField1`, problems),
          unknownRaw8: readOpaque(record?.unknownRaw8, `${recordWhere} unknownRaw8`, problems),
          unknownField2: readOpaque(record?.unknownField2, `${recordWhere} unknownField2`, problems),
          unknownWord0: readNumber(record?.unknownWord0, `${recordWhere} unknownWord0`, problems),
          unknownWord1: readNumber(record?.unknownWord1, `${recordWhere} unknownWord1`, problems),
          unknownDword: readNumber(record?.unknownDword, `${recordWhere} unknownDword`, problems),
          unknownWord6510: readNumber(
            record?.unknownWord6510, `${recordWhere} unknownWord6510`, problems
          )
        };
      })
    };
  });

  if (problems.length > 0) {
    throw new DirectoryStateError(
      'DIRECTORY_DOCUMENT',
      `${source} is invalid:\n  - ${problems.join('\n  - ')}`
    );
  }
  return createDirectoryState({ entries, provenance, rigFixture });
}

export function loadDirectoryFile(filePath) {
  let text;
  try {
    text = fs.readFileSync(filePath, 'utf8');
  } catch (error) {
    throw new DirectoryStateError(
      'DIRECTORY_FILE',
      `cannot read directory file ${filePath}: ${error.message}`
    );
  }
  let document;
  try {
    document = JSON.parse(text);
  } catch (error) {
    throw new DirectoryStateError(
      'DIRECTORY_FILE',
      `directory file ${filePath} is not valid JSON: ${error.message}`
    );
  }
  return parseDirectoryDocument(document, { source: filePath });
}
