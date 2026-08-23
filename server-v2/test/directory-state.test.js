import assert from 'node:assert/strict';
import test from 'node:test';

import {
  DIRECTORY_LIMITS,
  DIRECTORY_PROVENANCE,
  DirectoryStateError,
  StaticDirectoryProvider,
  createDirectoryState
} from '../src/state/directory-state.js';

function record(overrides = {}) {
  return {
    recordId: 'record-0',
    unknownField0: Buffer.from('K0', 'latin1'),
    unknownField1: Buffer.from('F1', 'latin1'),
    unknownRaw8: Buffer.alloc(8),
    unknownField2: Buffer.from('F2', 'latin1'),
    unknownWord0: 0,
    unknownWord1: 0,
    unknownDword: 0,
    unknownWord6510: 0,
    ...overrides
  };
}

function entry(overrides = {}) {
  return {
    entryId: 'entry-0',
    host: Buffer.from('10.0.0.1', 'latin1'),
    name: Buffer.from('E', 'latin1'),
    raw8: Buffer.alloc(8),
    description: Buffer.from('d', 'latin1'),
    pageField: Buffer.alloc(0),
    command6502Unknown0: 0,
    command6502Unknown1: 0,
    records: [record()],
    ...overrides
  };
}

function fixture(entries) {
  return createDirectoryState({
    entries,
    provenance: DIRECTORY_PROVENANCE.TEST_FIXTURE
  });
}

test('accepts an entry whose fields sit inside every proven PAL bound', () => {
  const state = fixture([entry({
    host: Buffer.from('10.0.0.1', 'latin1'),
    name: Buffer.from('E', 'latin1'),
    raw8: Buffer.alloc(8),
    description: Buffer.from('d', 'latin1'),
    pageField: Buffer.alloc(DIRECTORY_LIMITS.maximumPageFieldLength, 0x41),
    records: [record({
      unknownField0: Buffer.alloc(DIRECTORY_LIMITS.maximumField0Length, 0x42),
      unknownField1: Buffer.alloc(DIRECTORY_LIMITS.maximumField1Length, 0x43),
      unknownField2: Buffer.alloc(DIRECTORY_LIMITS.maximumField2Length, 0x44),
      unknownWord0: 0xffff,
      unknownWord1: 0xffff,
      unknownDword: 0xffffffff,
      unknownWord6510: 0xffff
    })]
  })]);
  assert.equal(state.entryCount, 1);
  assert.equal(state.totalRecordCount, 1);
  assert.equal(state.entryAt(0).records[0].unknownWord6510, 0xffff);
});

test('copies buffers so a caller cannot mutate authoritative state afterwards', () => {
  const key = Buffer.from('K0', 'latin1');
  const page = Buffer.from('P0', 'latin1');
  const state = fixture([entry({ pageField: page, records: [record({ unknownField0: key })] })]);
  key[0] = 0x00;
  page[0] = 0x00;
  assert.equal(state.entryAt(0).records[0].unknownField0.toString('latin1'), 'K0');
  assert.equal(state.entryAt(0).pageField.toString('latin1'), 'P0');
});

test('authoritative state may hold far more than the client residency budget', () => {
  // The 0x40 limit belongs to the client's slot table at 0x3619d0, not to the
  // server. Ten full entries is 640 records and must be accepted here.
  const entries = [];
  for (let entryIndex = 0; entryIndex < 10; entryIndex += 1) {
    const records = [];
    for (let index = 0; index < DIRECTORY_LIMITS.maximumRecordsPerEntry; index += 1) {
      records.push(record({
        recordId: `record-${entryIndex}-${index}`,
        unknownField0: Buffer.from(`K${index}`, 'latin1')
      }));
    }
    entries.push(entry({ entryId: `entry-${entryIndex}`, records }));
  }
  const state = fixture(entries);
  assert.equal(state.entryCount, 10);
  assert.equal(state.totalRecordCount, 640);
  assert.ok(state.totalRecordCount > DIRECTORY_LIMITS.clientResidencyBudget);
});

test('rejects an entry that declares more records than one entry can hold', () => {
  const records = [];
  for (let index = 0; index <= DIRECTORY_LIMITS.maximumRecordsPerEntry; index += 1) {
    records.push(record({
      recordId: `record-${index}`,
      unknownField0: Buffer.from(`K${index}`, 'latin1')
    }));
  }
  assert.throws(
    () => fixture([entry({ records })]),
    (error) => error instanceof DirectoryStateError &&
      error.code === 'DIRECTORY_ENTRY_CAPACITY'
  );
});

test('rejects duplicate 0x6510 keys inside one entry', () => {
  assert.throws(
    () => fixture([entry({
      records: [
        record({ recordId: 'a', unknownField0: Buffer.from('SAME', 'latin1') }),
        record({ recordId: 'b', unknownField0: Buffer.from('SAME', 'latin1') })
      ]
    })]),
    (error) => error instanceof DirectoryStateError && error.code === 'DIRECTORY_DUPLICATE_KEY'
  );
});

test('keeps the internal record id separate from the protocol key', () => {
  const state = fixture([entry({
    records: [
      record({ recordId: 'internal-1', unknownField0: Buffer.from('K1', 'latin1') }),
      record({ recordId: 'internal-2', unknownField0: Buffer.from('K2', 'latin1') })
    ]
  })]);
  const [first, second] = state.entryAt(0).records;
  assert.equal(first.recordId, 'internal-1');
  assert.equal(first.unknownField0.toString('latin1'), 'K1');
  assert.notEqual(first.recordId, first.unknownField0.toString('latin1'));
  assert.notEqual(second.recordId, first.recordId);
});

test('rejects every out-of-bound field rather than truncating it', () => {
  const cases = [
    [{ unknownField0: Buffer.alloc(DIRECTORY_LIMITS.maximumField0Length + 1) },
      'DIRECTORY_FIELD_LENGTH'],
    [{ unknownField1: Buffer.alloc(DIRECTORY_LIMITS.maximumField1Length + 1) },
      'DIRECTORY_FIELD_LENGTH'],
    [{ unknownField2: Buffer.alloc(DIRECTORY_LIMITS.maximumField2Length + 1) },
      'DIRECTORY_FIELD_LENGTH'],
    [{ unknownRaw8: Buffer.alloc(7) }, 'DIRECTORY_FIELD_LENGTH'],
    [{ unknownRaw8: Buffer.alloc(9) }, 'DIRECTORY_FIELD_LENGTH'],
    [{ unknownWord0: 0x10000 }, 'DIRECTORY_FIELD_VALUE'],
    [{ unknownWord1: -1 }, 'DIRECTORY_FIELD_VALUE'],
    [{ unknownDword: 0x100000000 }, 'DIRECTORY_FIELD_VALUE'],
    [{ unknownWord6510: 0x10000 }, 'DIRECTORY_FIELD_VALUE'],
    [{ unknownField0: 'K0' }, 'DIRECTORY_FIELD_TYPE'],
    [{ recordId: '' }, 'DIRECTORY_IDENTIFIER']
  ];
  for (const [overrides, code] of cases) {
    assert.throws(
      () => fixture([entry({ records: [record(overrides)] })]),
      (error) => error instanceof DirectoryStateError && error.code === code,
      `expected ${code} for ${JSON.stringify(Object.keys(overrides))}`
    );
  }
});

test('rejects every out-of-bound 0x6503 entry field rather than truncating it', () => {
  // Each bound is FUN_001c70b0's own argument to FUN_001c3b90, whose -2 return
  // on an over-long decode aborts the whole ladder. Truncating here would put a
  // silently different string in the client's entry table; refusing at
  // construction fails at startup instead, where an operator can see it.
  const cases = [
    [
      { host: Buffer.alloc(DIRECTORY_LIMITS.maximumEntryHostLength + 1) },
      'DIRECTORY_FIELD_LENGTH'
    ],
    [
      { name: Buffer.alloc(DIRECTORY_LIMITS.maximumEntryNameLength + 1) },
      'DIRECTORY_FIELD_LENGTH'
    ],
    [
      { description: Buffer.alloc(DIRECTORY_LIMITS.maximumEntryDescriptionLength + 1) },
      'DIRECTORY_FIELD_LENGTH'
    ],
    [{ raw8: Buffer.alloc(DIRECTORY_LIMITS.entryRawLength - 1) }, 'DIRECTORY_FIELD_LENGTH'],
    [{ raw8: Buffer.alloc(DIRECTORY_LIMITS.entryRawLength + 1) }, 'DIRECTORY_FIELD_LENGTH'],
    [{ host: '10.0.0.1' }, 'DIRECTORY_FIELD_TYPE'],
    [{ name: 'E' }, 'DIRECTORY_FIELD_TYPE'],
    [{ description: 'd' }, 'DIRECTORY_FIELD_TYPE'],
    [{ raw8: '00000000' }, 'DIRECTORY_FIELD_TYPE']
  ];
  for (const [overrides, code] of cases) {
    assert.throws(
      () => fixture([entry(overrides)]),
      (error) => error instanceof DirectoryStateError && error.code === code,
      `expected ${code} for ${JSON.stringify(Object.keys(overrides))}`
    );
  }
});

test('accepts every 0x6503 entry field at exactly its bound', () => {
  // The boundary itself must PASS: a bound that refused its own maximum would
  // quietly shrink the usable field by one byte.
  const state = fixture([entry({
    host: Buffer.alloc(DIRECTORY_LIMITS.maximumEntryHostLength, 0x31),
    name: Buffer.alloc(DIRECTORY_LIMITS.maximumEntryNameLength, 0x32),
    raw8: Buffer.alloc(DIRECTORY_LIMITS.entryRawLength),
    description: Buffer.alloc(DIRECTORY_LIMITS.maximumEntryDescriptionLength, 0x33)
  })]);
  const stored = state.entryAt(0);
  assert.equal(stored.host.length, DIRECTORY_LIMITS.maximumEntryHostLength);
  assert.equal(stored.name.length, DIRECTORY_LIMITS.maximumEntryNameLength);
  assert.equal(stored.description.length, DIRECTORY_LIMITS.maximumEntryDescriptionLength);
});

test('accepts 16 entries and refuses the 17th at construction', () => {
  // FUN_001c70b0 clamps a total above 0x10 to 0x10 when the connection state
  // word is not 1 and treats it as terminal when it is. V2 sees neither, so it
  // never builds a directory whose handling would depend on that word.
  const entries = (count) => Array.from({ length: count }, (_unused, index) => entry({
    entryId: `entry-${index}`,
    records: [record({ recordId: `record-${index}`, unknownField0: Buffer.from(`K${index}`) })]
  }));

  const full = fixture(entries(DIRECTORY_LIMITS.maximumEntries));
  assert.equal(full.entryCount, DIRECTORY_LIMITS.maximumEntries);
  assert.equal(full.entryAt(DIRECTORY_LIMITS.maximumEntries - 1).entryId, 'entry-15');
  assert.equal(full.entryAt(DIRECTORY_LIMITS.maximumEntries), null);

  assert.throws(
    () => fixture(entries(DIRECTORY_LIMITS.maximumEntries + 1)),
    (error) => error instanceof DirectoryStateError &&
      error.code === 'DIRECTORY_ENTRY_COUNT'
  );
});

test('rejects a page field above the 0x3e decoded bound', () => {
  assert.throws(
    () => fixture([entry({
      host: Buffer.from('10.0.0.1', 'latin1'),
      name: Buffer.from('E', 'latin1'),
      raw8: Buffer.alloc(8),
      description: Buffer.from('d', 'latin1'),
      pageField: Buffer.alloc(DIRECTORY_LIMITS.maximumPageFieldLength + 1)
    })]),
    (error) => error instanceof DirectoryStateError && error.code === 'DIRECTORY_FIELD_LENGTH'
  );
});

test('rejects unknown and missing fields instead of ignoring them', () => {
  assert.throws(
    () => fixture([entry({ records: [{ ...record(), somethingInvented: 1 }] })]),
    (error) => error instanceof DirectoryStateError && error.code === 'DIRECTORY_SHAPE'
  );
  const incomplete = record();
  delete incomplete.unknownWord6510;
  assert.throws(
    () => fixture([entry({ records: [incomplete] })]),
    (error) => error instanceof DirectoryStateError && error.code === 'DIRECTORY_SHAPE'
  );
});

test('requires provenance to be stated and refuses to serve a fixture directory', () => {
  assert.throws(
    () => createDirectoryState({ entries: [entry()] }),
    (error) => error instanceof DirectoryStateError && error.code === 'DIRECTORY_PROVENANCE'
  );
  const fixtureState = fixture([entry()]);
  assert.throws(
    () => fixtureState.assertServable(),
    (error) => error instanceof DirectoryStateError && error.code === 'DIRECTORY_PROVENANCE'
  );
  assert.equal(fixtureState.assertServable({ allowTestFixture: true }), fixtureState);
  const operatorState = createDirectoryState({
    entries: [entry()],
    provenance: DIRECTORY_PROVENANCE.OPERATOR
  });
  assert.equal(operatorState.assertServable(), operatorState);
});

test('refuses to serve an empty directory at startup rather than at request time', () => {
  const empty = createDirectoryState({
    entries: [],
    provenance: DIRECTORY_PROVENANCE.OPERATOR
  });
  assert.throws(
    () => empty.assertServable(),
    (error) => error instanceof DirectoryStateError && error.code === 'DIRECTORY_EMPTY'
  );
});

test('refuses a directory whose entries all hold no records', () => {
  const state = createDirectoryState({
    entries: [entry({ records: [] }), entry({ entryId: 'entry-1', records: [] })],
    provenance: DIRECTORY_PROVENANCE.OPERATOR
  });
  assert.equal(state.entryCount, 2);
  assert.throws(
    () => state.assertServable(),
    (error) => error instanceof DirectoryStateError && error.code === 'DIRECTORY_EMPTY'
  );
});

test('rejects duplicate entry identifiers', () => {
  assert.throws(
    () => fixture([entry({ entryId: 'same' }), entry({ entryId: 'same' })]),
    (error) => error instanceof DirectoryStateError && error.code === 'DIRECTORY_DUPLICATE_ID'
  );
});

test('entryAt is bounded and returns null outside the directory', () => {
  const state = fixture([entry()]);
  assert.equal(state.entryAt(-1), null);
  assert.equal(state.entryAt(1), null);
  assert.equal(state.entryAt(1.5), null);
  assert.notEqual(state.entryAt(0), null);
});

test('the static provider hands out the same authoritative state to every connection', () => {
  const state = fixture([entry()]);
  const provider = new StaticDirectoryProvider(state);
  assert.equal(provider.currentDirectory(), state);
  assert.equal(provider.currentDirectory(), provider.currentDirectory());
  assert.throws(() => new StaticDirectoryProvider({}), DirectoryStateError);
});
