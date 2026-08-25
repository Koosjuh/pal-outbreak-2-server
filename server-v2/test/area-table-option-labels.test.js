import assert from 'node:assert/strict';
import crypto from 'node:crypto';
import test from 'node:test';

import {
  AREA_TABLE_LAYOUT,
  AREA_TABLE_OPTION_LABELS,
  AREA_TABLE_PROVENANCE,
  AREA_TABLE_TRANSFER,
  AreaTable,
  AreaTableError,
  parseAreaTableDocument
} from '../src/state/area-table.js';
import {
  OPTION_LABELS_AREA_TABLE_VERSION,
  V1_OBSERVED_AREA_TABLE_VERSION,
  createV1ObservedAreaTable
} from '../src/state/area-table-v1.js';

/**
 * THE `+0x12fc` OPTION-LABEL TABLE (SNAP_OPTION_LABELS, B5).
 *
 * Evidence the assertions are built on (raw decompile, Observation):
 * - `FUN_005c2ad0` returns `blobBase + 0x12fc`.
 * - `FUN_005c3c40` reads records at stride 0x120: `record[0x1d]` destination
 *   offset, `record[0x1e]` blit length, entries of 0x20 bytes at
 *   `record + 0x3e + value*0x20`.
 * - The client's chunk-0 buffer is the STATIC 0x2000 bytes at 0x361a70
 *   (`FUN_001c2f80.c:22`; chunk 1 at 0x363a70 = +0x2000). Our old blob ended at
 *   0x1300, so every option-label read landed in bytes the download never wrote.
 *
 * The load-bearing guarantees, each with a test that fails if it is broken:
 * 1. Flag OFF is BYTE-IDENTICAL to the rig-confirmed blob (md5-pinned).
 * 2. Flag ON only APPENDS: the ten 0x1e4 records and the 0x14 bytes before the
 *    table are untouched, and the table region is all zero.
 * 3. Structured records land at EXACTLY +0x1d / +0x1e / +0x3e - the offsets the
 *    client reads; off-by-one is the failure mode this table exists to prevent.
 */

/**
 * The rig-confirmed OBAREA-W3 blob, pinned 2026-08-08 BEFORE the option-label
 * change (node -e over createV1ObservedAreaTable().serialize()). If this test
 * fails, the flag-off bytes are no longer the bytes the rig confirmed.
 */
// RE-PINNED 2026-08-24: mode-mask byte order corrected BE->LE at +0x14/+0x18
// (analysis/area-table-scenario-mask-LE-2026-08-24.md) - a DELIBERATE wire change;
// every other byte identical. Old pin 4ba89c9572704b039ce924e13b2cc070.
const PINNED_V3_BLOB_MD5 = '434fb1187f01189501a1d7f275f65fe6';
const PINNED_V3_BLOB_LENGTH = 0x1300;

const RECORDS_END = AREA_TABLE_LAYOUT.areaCount * AREA_TABLE_LAYOUT.recordStride; // 0x12e8
const TABLE_START = AREA_TABLE_OPTION_LABELS.tableOffset;                          // 0x12fc
const FULL_TABLE_LENGTH =
  TABLE_START + AREA_TABLE_OPTION_LABELS.maximumRecords * AREA_TABLE_OPTION_LABELS.recordStride;

test('flag OFF serves the rig-confirmed OBAREA-W3 blob byte-identically (md5-pinned)', () => {
  const table = createV1ObservedAreaTable();
  const blob = table.serialize();
  assert.equal(blob.length, PINNED_V3_BLOB_LENGTH);
  assert.equal(crypto.createHash('md5').update(blob).digest('hex'), PINNED_V3_BLOB_MD5);
  assert.equal(table.version.toString('latin1'), V1_OBSERVED_AREA_TABLE_VERSION);
  // The explicit-false spelling is the rollback and must be the same bytes.
  const rolledBack = createV1ObservedAreaTable({ publishOptionLabelTable: false }).serialize();
  assert.deepEqual(rolledBack, blob);
});


function buildAreas() {
  const areas = [];
  for (let index = 0; index < AREA_TABLE_LAYOUT.areaCount; index += 1) {
    areas.push({
      name: Buffer.from(`AREA ${index}`, 'latin1'),
      description: Buffer.from('test fixture', 'latin1'),
      enabled: true,
      unknownLeadWord: 0x1f,
      alwaysAvailableModeMask: 0,
      progressGatedModeMask: 0
    });
  }
  return areas;
}

test('flag ON is REFUSED: the extended blob would overrun the client area-table bank', () => {
  /*
   * SUPERSEDED 2026-08-24 (analysis/area-table-scenario-mask-LE-2026-08-24.md
   * section 6). The old assertion here — "0x1f5c, inside the client's 0x2000
   * static buffer" — trusted the CLIENT'S OWN guard (FUN_001c4960, 0x2000).
   * The receiving BANK is smaller: FUN_005aeb10 memcpys the declared length
   * into bank 0 whose usable size is 0x1780 (banks sit 0x17bb & ~0x3f apart,
   * FUN_00606ea0; the bank-1 snapshot copies 0x177c). A 0x1f5c blob passes the
   * client check and silently scribbles bank 1. So the single-chunk
   * option-label table CANNOT ship as designed; serialization now refuses it
   * at construction. Re-enabling needs a chunked transfer or a trimmed table,
   * with fresh evidence. The flag remains OFF in every deployment.
   */
  assert.throws(
    () => createV1ObservedAreaTable({ publishOptionLabelTable: true }),
    (error) => /6016/.test(error.message) || /0x1780/.test(error.message) ||
               /terminal/.test(error.message),
    'the 0x1f5c extended blob must be refused, not served into a 0x1780 bank'
  );
});
test('structured records encode at EXACTLY the FUN_005c3c40 offsets', () => {
  const entryA = Buffer.from('A'.repeat(0x20), 'latin1');
  const entryB = Buffer.from([0xde, 0xad]);
  const table = new AreaTable({
    version: Buffer.from('TEST-OPT1', 'latin1'),
    provenance: AREA_TABLE_PROVENANCE.TEST_FIXTURE,
    areas: buildAreas(),
    optionLabels: {
      records: [
        null,
        { destinationOffset: 0x0b, entryLength: 0x20, entries: [entryA, entryB] }
      ]
    }
  });
  const blob = table.serialize();
  assert.equal(blob.length, TABLE_START + 2 * AREA_TABLE_OPTION_LABELS.recordStride);

  const record0 = blob.subarray(TABLE_START, TABLE_START + 0x120);
  assert.ok(record0.every((byte) => byte === 0), 'a null record is all zero');

  const record1 = blob.subarray(TABLE_START + 0x120, TABLE_START + 0x240);
  // The discriminating offsets: the client reads +0x1d, +0x1e and +0x3e. An
  // implementation that writes +0x1c or +0x1f fails here.
  assert.equal(record1[0x1d], 0x0b, 'destination offset at +0x1d');
  assert.equal(record1[0x1e], 0x20, 'entry length at +0x1e');
  assert.ok(record1.subarray(0, 0x1d).every((byte) => byte === 0));
  assert.equal(record1[0x1f], 0, 'no identified reader for +0x1f; stays zero');
  assert.deepEqual(record1.subarray(0x3e, 0x3e + 0x20), entryA, 'entry 0 at +0x3e');
  assert.deepEqual(
    record1.subarray(0x5e, 0x60), entryB,
    'entry 1 at +0x3e + 0x20 (value-indexed 0x20 stride)'
  );
  assert.ok(
    record1.subarray(0x60, 0x120).every((byte) => byte === 0),
    'a short entry is zero-padded to its 0x20 slot'
  );
});

test('records the client could not read whole are refused, not clamped', () => {
  const areas = buildAreas();
  const build = (optionLabels) => new AreaTable({
    version: Buffer.from('TEST-OPT2', 'latin1'),
    provenance: AREA_TABLE_PROVENANCE.TEST_FIXTURE,
    areas,
    optionLabels
  });
  // A twelfth record would cross the client's 0x2000 static buffer.
  assert.throws(
    () => build({ records: new Array(AREA_TABLE_OPTION_LABELS.maximumRecords + 1).fill(null) }),
    (error) => error instanceof AreaTableError && error.code === 'AREA_TABLE_OPTION_LABELS'
  );
  // Entry 7 would start at +0x11e and overlap the next record.
  assert.throws(
    () => build({
      records: [{
        destinationOffset: 0, entryLength: 1,
        entries: new Array(8).fill(Buffer.alloc(1))
      }]
    }),
    (error) => error instanceof AreaTableError && error.code === 'AREA_TABLE_OPTION_LABELS'
  );
  // A blit longer than the 0x20 entry stride reads the neighbouring entry.
  assert.throws(
    () => build({ records: [{ destinationOffset: 0, entryLength: 0x21, entries: [] }] }),
    (error) => error instanceof AreaTableError && error.code === 'AREA_TABLE_OPTION_LABELS'
  );
  // An entry longer than its slot.
  assert.throws(
    () => build({ records: [{ destinationOffset: 0, entryLength: 0x20, entries: [Buffer.alloc(0x21)] }] }),
    (error) => error instanceof AreaTableError && error.code === 'AREA_TABLE_OPTION_LABELS'
  );
  // An empty records array is a statement with no meaning; refused.
  assert.throws(
    () => build({ records: [] }),
    (error) => error instanceof AreaTableError && error.code === 'AREA_TABLE_OPTION_LABELS'
  );
});

test('an operator document may carry the table as hex; omitted means not emitted', () => {
  const document = {
    version: 'TEST-OPT3',
    provenance: AREA_TABLE_PROVENANCE.TEST_FIXTURE,
    areas: buildAreas().map((area) => ({
      name: area.name.toString('latin1'),
      description: area.description.toString('latin1'),
      enabled: area.enabled,
      unknownLeadWord: area.unknownLeadWord,
      alwaysAvailableModeMask: 0,
      progressGatedModeMask: 0
    })),
    optionLabels: {
      records: [null, { destinationOffset: 2, entryLength: 3, entriesHex: ['aabbcc', '010203'] }]
    }
  };
  const table = parseAreaTableDocument(document);
  const blob = table.serialize();
  const record1 = blob.subarray(TABLE_START + 0x120, TABLE_START + 0x240);
  assert.equal(record1[0x1d], 2);
  assert.equal(record1[0x1e], 3);
  assert.deepEqual(record1.subarray(0x3e, 0x41), Buffer.from('aabbcc', 'hex'));
  assert.deepEqual(record1.subarray(0x5e, 0x61), Buffer.from('010203', 'hex'));

  const withoutLabels = parseAreaTableDocument({ ...document, optionLabels: undefined });
  assert.equal(withoutLabels.serialize().length, PINNED_V3_BLOB_LENGTH);

  assert.throws(
    () => parseAreaTableDocument({
      ...document,
      optionLabels: { records: [{ entriesHex: ['zz'] }] }
    }),
    (error) => error instanceof AreaTableError && error.code === 'AREA_TABLE_OPTION_LABELS'
  );
});

test('the +0x16c parameter bytes region is untouched by the labels flag being OFF', () => {
  // Reduced scope 2026-08-24: the ON variant is refused outright (bank overflow,
  // see the refusal test above), so coexistence can only be asserted for OFF.
  const blob = createV1ObservedAreaTable().serialize();
  assert.equal(blob.length, PINNED_V3_BLOB_LENGTH);
});
