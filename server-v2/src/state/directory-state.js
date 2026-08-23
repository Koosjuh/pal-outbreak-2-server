/**
 * Authoritative server-side directory state behind the four TCP 10127 providers.
 *
 * Structure, not naming: SLES_533.19 keeps one array of fixed-stride entries at
 * `0x365e20` with stride `0x260`, each owning a pointer array of fixed-stride
 * records allocated from one pool with stride `0x134`. Both the `0x6504` reply
 * parser `FUN_001c7a70` and the `0x6510` reply parser `FUN_001c8790` compute the
 * entry base with the same `((index * 0x12) + index) * 0x20` sequence
 * (`0x001c7b38..0x001c7b48` and `0x001c8930..0x001c8940`), and `0x6510` reaches
 * its records by loading the pointers `0x6504` wrote (`0x001c88fc lw v1,384(v1)`
 * against `0x001c808c lw a1,384(v0)`), so this is one structure with four views.
 * Full derivation and every instruction address: session log T17, 2026-08-02.
 *
 * What this file deliberately does NOT claim:
 *
 * - That an entry is an area and a record is a room. The Area-Select overlay does
 *   read this array, but those functions are not in the main EE ELF and cannot be
 *   disassembled, so that correspondence stays one evidence rank lower and is not
 *   promoted into domain names here. Entries and records are named structurally.
 * - Any meaning for `pageField`, the record fields, or `unknownWord6510`. They are
 *   opaque values the operator supplies. `pageField` is NOT called a page name.
 * - Any total size limit on the directory. The proven `0x40` limit is a limit on
 *   what one CLIENT can hold resident at once (see client-directory-projection.js),
 *   not a limit on authoritative state.
 *
 * The limits are kept separate on purpose:
 *
 * | Limit | Value | Status |
 * |---|---|---|
 * | records in one entry | 64 | Proven: the entry's pointer array is `+0x160..+0x25f`, exactly 64 slots, and the entry stride is `0x260`. |
 * | records resident in one client across entries | 64 | Proven: one shared 64-slot ownership table at `0x3619d0`, checked at `0x001c7c08`/`0x001c7cfc`/`0x001c8370`. |
 * | records in authoritative server state | none | Unknown. No server-side evidence exists, so none is imposed. |
 * | rooms or players visible in an area | none | Unknown. Not modelled at all; see the room seam below. |
 */

/**
 * Where a value in this store came from. A store built for tests can never be
 * mistaken for one an operator configured: composition refuses `test-fixture`
 * unless the caller opts in explicitly, so a fixture cannot drift into
 * production by being convenient.
 */
export const DIRECTORY_PROVENANCE = Object.freeze({
  OPERATOR: 'operator',
  TEST_FIXTURE: 'test-fixture'
});

/** Proven bounds. Every one of these is enforced, never defaulted around. */
export const DIRECTORY_LIMITS = Object.freeze({
  // FUN_001c3b90 bound `li a2,15` at 0x001c8094 and 0x001c80e4.
  maximumField0Length: 0x0f,
  maximumField1Length: 0x0f,
  // Eight raw bytes read one at a time, loop bound `slti a0,s3,8` at 0x001c8180.
  rawFieldLength: 8,
  // FUN_001c3b90 bound `li a2,255` at 0x001c81cc.
  maximumField2Length: 0xff,
  // FUN_001c3b90 bound `li a2,62` at 0x001c892c for the entry-level field.
  maximumPageFieldLength: 0x3e,
  /*
   * The 0x6503 entry fields, from corpus `001c70b0_recv_roomlist_entries`:
   * "stream 0x260 records (name0x3e/id0xf/8flags/data0xff)". The first field is
   * what T30 proved the client RESOLVES as a connect target - the corpus calls
   * it "name", which is wrong; it lands at entry +0x00 and is the host.
   */
  maximumEntryHostLength: 0x3e,
  maximumEntryNameLength: 0x0f,
  entryRawLength: 8,
  maximumEntryDescriptionLength: 0xff,
  // "clamp list to 16" (same corpus record). A 0x6503 declaring 0 entries is a
  // terminal client error, so the floor is 1.
  maximumEntries: 16,
  // The entry's pointer array occupies +0x160..+0x25f of a 0x260-byte entry.
  maximumRecordsPerEntry: 0x40,
  // The single ownership table at 0x3619d0 has 64 slots shared by all entries.
  clientResidencyBudget: 0x40
});

class DirectoryStateError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'DirectoryStateError';
    this.code = code;
  }
}

export { DirectoryStateError };

function fail(code, message) {
  throw new DirectoryStateError(code, message);
}

function requireOpaqueField(value, name, maximumLength) {
  if (!Buffer.isBuffer(value)) {
    fail('DIRECTORY_FIELD_TYPE', `${name} must be a Buffer`);
  }
  if (value.length > maximumLength) {
    fail(
      'DIRECTORY_FIELD_LENGTH',
      `${name} is ${value.length} bytes, above the PAL parser bound ${maximumLength}`
    );
  }
  return Buffer.from(value);
}

function requireExactField(value, name, exactLength) {
  if (!Buffer.isBuffer(value)) {
    fail('DIRECTORY_FIELD_TYPE', `${name} must be a Buffer`);
  }
  if (value.length !== exactLength) {
    fail('DIRECTORY_FIELD_LENGTH', `${name} must be exactly ${exactLength} bytes`);
  }
  return Buffer.from(value);
}

function requireUnsigned(value, name, maximum) {
  if (!Number.isSafeInteger(value) || value < 0 || value > maximum) {
    fail('DIRECTORY_FIELD_VALUE', `${name} must be an integer in 0..${maximum}`);
  }
  return value;
}

function requireIdentifier(value, name) {
  if (typeof value !== 'string' || value.length === 0) {
    fail('DIRECTORY_IDENTIFIER', `${name} must be a nonempty string`);
  }
  return value;
}

function requireOnlyKeys(object, name, allowed) {
  const extra = Object.keys(object).filter((key) => !allowed.includes(key));
  if (extra.length > 0) {
    fail('DIRECTORY_SHAPE', `${name} has unsupported fields: ${extra.join(', ')}`);
  }
  const missing = allowed.filter((key) => !Object.hasOwn(object, key));
  if (missing.length > 0) {
    fail('DIRECTORY_SHAPE', `${name} is missing required fields: ${missing.join(', ')}`);
  }
}

const RECORD_KEYS = [
  'recordId',
  'unknownField0',
  'unknownField1',
  'unknownRaw8',
  'unknownField2',
  'unknownWord0',
  'unknownWord1',
  'unknownDword',
  'unknownWord6510'
];

const ENTRY_KEYS = [
  'entryId',
  'host',
  'name',
  'raw8',
  'description',
  'pageField',
  'command6502Unknown0',
  'command6502Unknown1',
  'records'
];

/**
 * One record, in the exact shape `FUN_001c7a70` parses it.
 *
 * `recordId` is server-owned and never appears on the wire. It is kept separate
 * from `unknownField0` on purpose: `unknownField0` is the key the client echoes
 * back in its `0x6510` request, but nothing proves it is, or must remain, a
 * primary key in server state.
 *
 * `unknownWord6510` is the BE16 the `0x6510` reply supplies. `0x6504` never
 * writes record `+0x12c`, which is why this value lives beside the seven
 * `0x6504` fields rather than inside them.
 */
function normalizeRecord(record, entryId, index) {
  const where = `entry ${entryId} record ${index}`;
  if (record == null || typeof record !== 'object' || Array.isArray(record)) {
    fail('DIRECTORY_SHAPE', `${where} must be an object`);
  }
  requireOnlyKeys(record, where, RECORD_KEYS);
  return Object.freeze({
    recordId: requireIdentifier(record.recordId, `${where} recordId`),
    unknownField0: requireOpaqueField(
      record.unknownField0, `${where} unknownField0`, DIRECTORY_LIMITS.maximumField0Length
    ),
    unknownField1: requireOpaqueField(
      record.unknownField1, `${where} unknownField1`, DIRECTORY_LIMITS.maximumField1Length
    ),
    unknownRaw8: requireExactField(
      record.unknownRaw8, `${where} unknownRaw8`, DIRECTORY_LIMITS.rawFieldLength
    ),
    unknownField2: requireOpaqueField(
      record.unknownField2, `${where} unknownField2`, DIRECTORY_LIMITS.maximumField2Length
    ),
    unknownWord0: requireUnsigned(record.unknownWord0, `${where} unknownWord0`, 0xffff),
    unknownWord1: requireUnsigned(record.unknownWord1, `${where} unknownWord1`, 0xffff),
    unknownDword: requireUnsigned(record.unknownDword, `${where} unknownDword`, 0xffffffff),
    unknownWord6510: requireUnsigned(record.unknownWord6510, `${where} unknownWord6510`, 0xffff)
  });
}

function normalizeEntry(entry, index) {
  const where = `entry ${index}`;
  if (entry == null || typeof entry !== 'object' || Array.isArray(entry)) {
    fail('DIRECTORY_SHAPE', `${where} must be an object`);
  }
  requireOnlyKeys(entry, where, ENTRY_KEYS);
  const entryId = requireIdentifier(entry.entryId, `${where} entryId`);
  if (!Array.isArray(entry.records)) {
    fail('DIRECTORY_SHAPE', `${where} records must be an array`);
  }
  if (entry.records.length > DIRECTORY_LIMITS.maximumRecordsPerEntry) {
    fail(
      'DIRECTORY_ENTRY_CAPACITY',
      `${where} declares ${entry.records.length} records; one entry holds at most ` +
      `${DIRECTORY_LIMITS.maximumRecordsPerEntry} pointers`
    );
  }
  const records = entry.records.map((record, recordIndex) =>
    normalizeRecord(record, entryId, recordIndex));

  // The client's 0x6510 request identifies records by unknownField0. Duplicate
  // keys inside one entry would make that request ambiguous and force the
  // provider to fail closed at run time, so it is rejected at construction.
  const seenKeys = new Set();
  const seenIds = new Set();
  for (const record of records) {
    const key = record.unknownField0.toString('latin1');
    if (seenKeys.has(key)) {
      fail(
        'DIRECTORY_DUPLICATE_KEY',
        `${where} repeats unknownField0 ${JSON.stringify(key)}; the 0x6510 request ` +
        'identifies records by that field, so it must be unique within an entry'
      );
    }
    seenKeys.add(key);
    if (seenIds.has(record.recordId)) {
      fail('DIRECTORY_DUPLICATE_ID', `${where} repeats recordId ${record.recordId}`);
    }
    seenIds.add(record.recordId);
  }

  return Object.freeze({
    entryId,
    /*
     * The 0x6503 entry fields. `host` is NOT opaque and is the one field here
     * whose consumer is known: FUN_001c8790 stores it at entry +0x00, and on
     * selection FUN_001c08e0 parses it as a dotted-quad and otherwise resolves
     * it by DNS (T30 runtime, T31 disassembly). The rest stay opaque.
     */
    host: requireOpaqueField(
      entry.host, `${where} host`, DIRECTORY_LIMITS.maximumEntryHostLength
    ),
    name: requireOpaqueField(
      entry.name, `${where} name`, DIRECTORY_LIMITS.maximumEntryNameLength
    ),
    raw8: requireExactField(
      entry.raw8, `${where} raw8`, DIRECTORY_LIMITS.entryRawLength
    ),
    description: requireOpaqueField(
      entry.description, `${where} description`, DIRECTORY_LIMITS.maximumEntryDescriptionLength
    ),
    pageField: requireOpaqueField(
      entry.pageField, `${where} pageField`, DIRECTORY_LIMITS.maximumPageFieldLength
    ),
    // FUN_001c7680 mode 1 stores the first BE32 in global 0x365e08 and the second
    // at entry +0x15c. Both are opaque and operator-supplied.
    command6502Unknown0: requireUnsigned(
      entry.command6502Unknown0, `${where} command6502Unknown0`, 0xffffffff
    ),
    command6502Unknown1: requireUnsigned(
      entry.command6502Unknown1, `${where} command6502Unknown1`, 0xffffffff
    ),
    records: Object.freeze(records)
  });
}

/**
 * Immutable authoritative directory.
 *
 * Immutable is the point, not an optimization. A connection walking its
 * initialization sequence must never be able to mutate what every other
 * connection sees, and the client's own eviction behaviour must never delete
 * anything here (see client-directory-projection.js).
 */
export class DirectoryState {
  #entries;
  #provenance;
  #rigFixture;

  constructor({ entries, provenance, rigFixture = false }) {
    if (!Array.isArray(entries)) {
      fail('DIRECTORY_SHAPE', 'entries must be an array');
    }
    if (provenance !== DIRECTORY_PROVENANCE.OPERATOR &&
        provenance !== DIRECTORY_PROVENANCE.TEST_FIXTURE) {
      fail(
        'DIRECTORY_PROVENANCE',
        'provenance must be stated explicitly as operator or test-fixture'
      );
    }
    // The client clamps its own list to 16 (corpus `001c70b0`), and a 0x6503
    // declaring more than it can seat would desynchronise the entry table it
    // walks. Bounded at construction rather than truncated at send time.
    if (entries.length > DIRECTORY_LIMITS.maximumEntries) {
      fail(
        'DIRECTORY_ENTRY_COUNT',
        `${entries.length} entries declared; the client seats at most ` +
        `${DIRECTORY_LIMITS.maximumEntries}`
      );
    }
    const normalized = entries.map((entry, index) => normalizeEntry(entry, index));
    const seen = new Set();
    for (const entry of normalized) {
      if (seen.has(entry.entryId)) {
        fail('DIRECTORY_DUPLICATE_ID', `duplicate entryId ${entry.entryId}`);
      }
      seen.add(entry.entryId);
    }
    this.#entries = Object.freeze(normalized);
    this.#provenance = provenance;
    /*
     * EXPLICIT RIG BOUNDARY. A directory may declare that it is the development
     * rig's, which exempts it from the rig-fixture gate. It is deliberately a
     * property of the DOCUMENT rather than an environment variable: the file
     * that carries the rig values is the file that should admit to carrying
     * them, and a production file simply omits this.
     */
    this.#rigFixture = rigFixture === true;
  }

  get provenance() {
    return this.#provenance;
  }

  /** True when this document declares itself the development rig's. */
  get rigFixture() {
    return this.#rigFixture;
  }

  /** The value the client stores as its entry total, read back at 0x365e1e. */
  get entryCount() {
    return this.#entries.length;
  }

  get totalRecordCount() {
    return this.#entries.reduce((total, entry) => total + entry.records.length, 0);
  }

  entryAt(index) {
    if (!Number.isSafeInteger(index) || index < 0 || index >= this.#entries.length) {
      return null;
    }
    return this.#entries[index];
  }

  entries() {
    return this.#entries;
  }

  /**
   * Startup gate. Composition calls this so a directory that cannot serve the
   * ladder fails when the process starts rather than when a client arrives.
   */
  assertServable({ allowTestFixture = false } = {}) {
    if (this.#provenance === DIRECTORY_PROVENANCE.TEST_FIXTURE && !allowTestFixture) {
      fail(
        'DIRECTORY_PROVENANCE',
        'refusing to serve a test-fixture directory; supply operator-configured state'
      );
    }
    if (this.#entries.length === 0) {
      fail('DIRECTORY_EMPTY', 'a servable directory needs at least one entry');
    }
    if (this.totalRecordCount === 0) {
      fail(
        'DIRECTORY_EMPTY',
        'a servable directory needs at least one record; every entry would otherwise be ' +
        'skipped with 0x6502 mode 0 and the walk would carry no data'
      );
    }
    return this;
  }
}

export function createDirectoryState(options) {
  return new DirectoryState(options);
}

/**
 * Seam for dynamic rooms, memberships and player slots.
 *
 * Nothing is modelled here yet, and nothing should be until a room-browser
 * command proves what a room record contains. What this reserves is the shape:
 * a source of entries that composition can swap for one backed by repositories
 * over static servers/areas plus rooms created at run time, without any TCP
 * handler changing. `DirectoryProvider` is the only thing the providers depend
 * on, so a live implementation replaces a static one at composition.
 */
export class StaticDirectoryProvider {
  #state;

  constructor(state) {
    if (!(state instanceof DirectoryState)) {
      fail('DIRECTORY_SHAPE', 'StaticDirectoryProvider requires a DirectoryState');
    }
    this.#state = state;
  }

  /** Called once per connection, so a later dynamic provider can snapshot. */
  currentDirectory() {
    return this.#state;
  }
}
