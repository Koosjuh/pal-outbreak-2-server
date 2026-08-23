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
 * The rig-confirmed OBAREA-V3 blob, pinned 2026-08-08 BEFORE the option-label
 * change (node -e over createV1ObservedAreaTable().serialize()). If this test
 * fails, the flag-off bytes are no longer the bytes the rig confirmed.
 */
const PINNED_V3_BLOB_MD5 = '4ba89c9572704b039ce924e13b2cc070';
const PINNED_V3_BLOB_LENGTH = 0x1300;

const RECORDS_END = AREA_TABLE_LAYOUT.areaCount * AREA_TABLE_LAYOUT.recordStride; // 0x12e8
const TABLE_START = AREA_TABLE_OPTION_LABELS.tableOffset;                          // 0x12fc
const FULL_TABLE_LENGTH =
  TABLE_START + AREA_TABLE_OPTION_LABELS.maximumRecords * AREA_TABLE_OPTION_LABELS.recordStride;

test('flag OFF serves the rig-confirmed OBAREA-V3 blob byte-identically (md5-pinned)', () => {
  const table = createV1ObservedAreaTable();
  const blob = table.serialize();
  assert.equal(blob.length, PINNED_V3_BLOB_LENGTH);
  assert.equal(crypto.createHash('md5').update(blob).digest('hex'), PINNED_V3_BLOB_MD5);
  assert.equal(table.version.toString('latin1'), V1_OBSERVED_AREA_TABLE_VERSION);
  // The explicit-false spelling is the rollback and must be the same bytes.
  const rolledBack = createV1ObservedAreaTable({ publishOptionLabelTable: false }).serialize();
  assert.deepEqual(rolledBack, blob);
});

test('flag ON is purely additive: same records, zeroed table, bumped version', () => {
  const off = createV1ObservedAreaTable().serialize();
  const table = createV1ObservedAreaTable({ publishOptionLabelTable: true });
  const on = table.serialize();

  // 0x12fc + 11*0x120 = 0x1f5c, inside the client's 0x2000 static buffer.
  assert.equal(on.length, FULL_TABLE_LENGTH);
  assert.equal(on.length, 0x1f5c);
  assert.ok(on.length <= AREA_TABLE_TRANSFER.maximumChunkLength);

  // Every byte the rig-confirmed blob named is unchanged: the ten records AND
  // the 0x14 unnamed bytes between the records' end and the table.
  assert.deepEqual(on.subarray(0, TABLE_START), off.subarray(0, TABLE_START));
  // The table region is all zero - every record's length byte is 0, so the
  // client blits NOTHING where it previously blitted stale memory.
  assert.ok(on.subarray(TABLE_START).every((byte) => byte === 0));

  // The version MUST differ or a console that cached V3 this power cycle never
  // refetches (FUN_001c4960.c:46-49) and keeps rendering the garbage.
  assert.equal(table.version.toString('latin1'), OPTION_LABELS_AREA_TABLE_VERSION);
  assert.notEqual(OPTION_LABELS_AREA_TABLE_VERSION, V1_OBSERVED_AREA_TABLE_VERSION);
  assert.equal(
    OPTION_LABELS_AREA_TABLE_VERSION.length, V1_OBSERVED_AREA_TABLE_VERSION.length,
    'the declaration layout depends on the version length staying nine characters'
  );
});

test('the extended blob still walks the 0x2f2-slice transfer to a final slice', () => {
  const table = createV1ObservedAreaTable({ publishOptionLabelTable: true });
  assert.deepEqual(table.chunkLengths(), [0x1f5c]);
  const sliceCount = table.sliceCount;
  assert.equal(sliceCount, Math.ceil(0x1f5c / AREA_TABLE_TRANSFER.sliceLength)); // 11
  const reassembled = [];
  for (let index = 0; index < sliceCount; index += 1) {
    const slice = table.sliceAt({
      chunkIndex: 0,
      offset: index * AREA_TABLE_TRANSFER.sliceLength
    });
    assert.equal(
      slice.final, index === sliceCount - 1,
      `slice ${index} final flag`
    );
    if (!slice.final) {
      // FUN_001c4d40.c:31 advances the cursor by exactly 0x2f2 regardless, so a
      // short non-final slice would tear a hole in the client's table.
      assert.equal(slice.data.length, AREA_TABLE_TRANSFER.sliceLength);
    }
    reassembled.push(slice.data);
  }
  assert.deepEqual(Buffer.concat(reassembled), table.serialize());
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

test('the option-labels region and the +0x16c parameter bytes coexist untouched', () => {
  // The +0x16c blocks are on the rig-confirmed create path; prove the new
  // section did not displace them.
  const table = createV1ObservedAreaTable({ publishOptionLabelTable: true });
  const blob = table.serialize();
  for (let area = 0; area < AREA_TABLE_LAYOUT.areaCount; area += 1) {
    const record = blob.subarray(
      area * AREA_TABLE_LAYOUT.recordStride, (area + 1) * AREA_TABLE_LAYOUT.recordStride
    );
    const expected = createV1ObservedAreaTable().serialize().subarray(
      area * AREA_TABLE_LAYOUT.recordStride, (area + 1) * AREA_TABLE_LAYOUT.recordStride
    );
    assert.deepEqual(record, expected, `area record ${area} unchanged by the flag`);
  }
  assert.equal(RECORDS_END, 0x12e8);
  assert.equal(TABLE_START - RECORDS_END, 0x14, 'the 0x14 unnamed bytes before the table');
});
