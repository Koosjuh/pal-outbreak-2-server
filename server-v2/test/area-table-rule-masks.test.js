import assert from 'node:assert/strict';
import crypto from 'node:crypto';
import test from 'node:test';

import {
  AREA_TABLE_LAYOUT,
  AREA_TABLE_PROVENANCE,
  AREA_TABLE_RULE_SCREEN,
  AREA_TABLE_TRANSFER,
  AreaTable,
  AreaTableError
} from '../src/state/area-table.js';
import {
  OPTION_LABELS_AREA_TABLE_VERSION,
  RULE_MASKS_AREA_TABLE_VERSION,
  RULE_MASKS_OPTION_LABELS_AREA_TABLE_VERSION,
  V1_OBSERVED_AREA_TABLE_VERSION,
  createV1ObservedAreaTable
} from '../src/state/area-table-v1.js';

/**
 * THE CREATE-SCREEN RULE BYTES (SNAP_RULE_MASKS_AUTHENTIC).
 *
 * Every expected byte below is copied from `docs/design/v2-port/RULES-MASK-RE.md`
 * §6.2 DIRECTLY - hex literals, not the builder's own constants - so a builder
 * that drifts from the document fails here even if it stays self-consistent.
 *
 * Evidence grades carried over from that document:
 * - block byte layouts, descriptor shape, `+0x16b`, `+0x03`, `+0x04..0x13`:
 *   Confirmed (decompile, cited there per line).
 * - the ON/OFF value bytes on the Friendly Fire / Nightmare / Infinity rows:
 *   Likely (bioserver `off, on` ordering); a wrong index renders a blank
 *   value, never a crash.
 * - both `+0x16c` and `+0x1a8` blocks carry IDENTICAL content because the
 *   `FUN_005c4f00` block-select ambiguity (§7) is unresolved.
 */

/** The rig-confirmed OBAREA-V3 blob, pinned before the option-label change. */
const PINNED_V3_BLOB_MD5 = '4ba89c9572704b039ce924e13b2cc070';
const PINNED_V3_BLOB_LENGTH = 0x1300;

const STRIDE = AREA_TABLE_LAYOUT.recordStride;
const BLOCKS = [0x16c, 0x1a8];

/**
 * RULES-MASK-RE.md §6.2, verbatim: `F3 E2`, the group-1 count, then the
 * 4-byte `{record, value, present, changeable}` descriptors, per area in
 * blob order. Areas 6 (reserved) and 10 (SECRET) are disabled but still
 * carry the plain block, exactly as the document's table lists them.
 */
const EXPECTED_BLOCK_PREFIX = [
  'f3e20101030101',                       // 1 Free Area: 3 rows, all white
  'f3e2020103010105010100',               // 2 Nightmare: Nightmare fixed ON (red)
  'f3e2020103010102010100',               // 3 Survival: Friendly Fire fixed ON (red)
  'f3e203010301010201010005010100',       // 4 Panic: two red rows
  'f3e20401030101020001010500010106010100', // 5 Infinity: ff/nm white, Infinity red
  'f3e20101030101',                       // 6 reserved (disabled)
  'f3e20101030101',                       // 7 TESTING
  'f3e20101030101',                       // 8 Elimination
  'f3e20101030101',                       // 9 Showdown
  'f3e20101030101'                        // 10 SECRET (disabled)
].map((hex) => Buffer.from(hex, 'hex'));

/** V1_OBSERVED_AREAS order: reserved (5) and SECRET (9) ship `+0x14c = 0`. */
const DISABLED_AREAS = new Set([5, 9]);

function recordAt(blob, area) {
  return blob.subarray(area * STRIDE, (area + 1) * STRIDE);
}

test('flag OFF serves the previous blob byte-identically (md5-pinned)', () => {
  const table = createV1ObservedAreaTable({ publishAuthenticRuleMasks: false });
  const blob = table.serialize();
  assert.equal(blob.length, PINNED_V3_BLOB_LENGTH);
  assert.equal(crypto.createHash('md5').update(blob).digest('hex'), PINNED_V3_BLOB_MD5);
  assert.equal(table.version.toString('latin1'), V1_OBSERVED_AREA_TABLE_VERSION);
  // The rollback spelling and the say-nothing spelling are the same bytes.
  assert.deepEqual(createV1ObservedAreaTable().serialize(), blob);
});

test('flag ON: every fix byte lands at its exact offset, in BOTH parameter blocks', () => {
  const table = createV1ObservedAreaTable({ publishAuthenticRuleMasks: true });
  const blob = table.serialize();
  assert.equal(blob.length, PINNED_V3_BLOB_LENGTH, 'the rule bytes live inside the records');

  for (let area = 0; area < AREA_TABLE_LAYOUT.areaCount; area += 1) {
    const record = recordAt(blob, area);

    // rec+0x03 = 0xFF: all 8 base characters (FUN_005baf20 gates them by this
    // byte ALONE). The lead word's other three bytes stay the observed 0x0000001f
    // high bytes - 00 00 00.
    assert.deepEqual(
      record.subarray(0x00, 0x03), Buffer.from('000000', 'hex'),
      `area ${area}: lead word high bytes untouched`
    );
    assert.equal(record[0x03], 0xff, `area ${area}: cast mask at +0x03`);

    // rec+0x04..0x13 = 0xFF x16: permit any extra cast the savedata unlocked.
    assert.deepEqual(
      record.subarray(0x04, 0x14), Buffer.alloc(0x10, 0xff),
      `area ${area}: extra-cast permission at +0x04..0x13`
    );

    // rec+0x14 and rec+0x18 = 0x7FF, the full scenario ring, on ENABLED areas.
    const expectedMask = DISABLED_AREAS.has(area) ? 0 : 0x7ff;
    assert.equal(record.readUInt32BE(0x14), expectedMask, `area ${area}: +0x14 scenario mask`);
    assert.equal(record.readUInt32BE(0x18), expectedMask, `area ${area}: +0x18 scenario mask`);

    // rec+0x16b = 0x03: Room Title (bit0) + Password (bit1) settable.
    assert.equal(record[0x16b], 0x03, `area ${area}: title/password byte at +0x16b`);

    // BOTH parameter blocks, identical content: F3 E2, group-1 count,
    // descriptors - and the rest of each 0x3c block zero, including the
    // group-2 count at block +0x2b.
    const expected = EXPECTED_BLOCK_PREFIX[area];
    for (const base of BLOCKS) {
      assert.deepEqual(
        record.subarray(base, base + expected.length), expected,
        `area ${area}: block at +0x${base.toString(16)} carries the §6.2 bytes`
      );
      assert.ok(
        record.subarray(base + expected.length, base + 0x3c).every((byte) => byte === 0),
        `area ${area}: rest of block +0x${base.toString(16)} stays zero`
      );
      assert.equal(record[base + 0x2b], 0, `area ${area}: group-2 count untouched`);
    }
  }
});

test('flag ON changes ONLY the documented offsets; every other byte is identical', () => {
  const off = createV1ObservedAreaTable().serialize();
  const on = createV1ObservedAreaTable({ publishAuthenticRuleMasks: true }).serialize();
  assert.equal(on.length, off.length);

  // The complete set of record offsets RULES-MASK-RE.md §6.2 names: the cast
  // byte + permission bitmap, the two scenario-mask words, the title/password
  // byte, and the two parameter blocks up to (not including) the group-2
  // count at block +0x2b. A diff anywhere else means the fix touched a field
  // it had no business in - the area names / second lines / enables are
  // rig-confirmed rendering.
  const allowed = new Set();
  for (let o = 0x03; o <= 0x13; o += 1) allowed.add(o);     // cast + permission
  for (let o = 0x14; o <= 0x1b; o += 1) allowed.add(o);     // +0x14 and +0x18 words
  allowed.add(0x16b);                                       // title/password
  for (const base of BLOCKS) {
    for (let o = base; o < base + 0x2b; o += 1) allowed.add(o);
  }

  for (let index = 0; index < on.length; index += 1) {
    if (on[index] === off[index]) continue;
    const withinRecord = index % STRIDE;
    assert.ok(
      index < AREA_TABLE_LAYOUT.areaCount * STRIDE && allowed.has(withinRecord),
      `byte 0x${index.toString(16)} (record offset 0x${withinRecord.toString(16)}) changed ` +
      'outside the offsets the fix documents'
    );
  }
});

test('the version bump: V5 alone, V6 with option labels, all four distinct', () => {
  const rules = createV1ObservedAreaTable({ publishAuthenticRuleMasks: true });
  assert.equal(rules.version.toString('latin1'), RULE_MASKS_AREA_TABLE_VERSION);

  // The two flags stay independent: labels ON with rules ON must be its own
  // version AND still append the zeroed label table over the same records.
  const both = createV1ObservedAreaTable({
    publishAuthenticRuleMasks: true,
    publishOptionLabelTable: true
  });
  assert.equal(both.version.toString('latin1'), RULE_MASKS_OPTION_LABELS_AREA_TABLE_VERSION);
  const bothBlob = both.serialize();
  assert.equal(bothBlob.length, 0x1f5c);
  assert.deepEqual(
    bothBlob.subarray(0, PINNED_V3_BLOB_LENGTH - AREA_TABLE_LAYOUT.trailerLength),
    rules.serialize().subarray(0, PINNED_V3_BLOB_LENGTH - AREA_TABLE_LAYOUT.trailerLength),
    'the records are the same whether or not the label table follows'
  );
  assert.ok(bothBlob.subarray(0x12fc).every((byte) => byte === 0));

  // Four byte images, four version strings - the client caches by version
  // alone (FUN_001c4960.c:46-49), so any collision silently serves stale bytes.
  const versions = [
    V1_OBSERVED_AREA_TABLE_VERSION,
    OPTION_LABELS_AREA_TABLE_VERSION,
    RULE_MASKS_AREA_TABLE_VERSION,
    RULE_MASKS_OPTION_LABELS_AREA_TABLE_VERSION
  ];
  assert.equal(new Set(versions).size, 4, 'every blob shape has its own version');
  for (const version of versions) {
    assert.equal(
      version.length, V1_OBSERVED_AREA_TABLE_VERSION.length,
      'the declaration layout depends on the version length staying nine characters'
    );
  }
});

test('the rules blob still walks the 0x2f2-slice transfer to a final slice', () => {
  const table = createV1ObservedAreaTable({ publishAuthenticRuleMasks: true });
  assert.deepEqual(table.chunkLengths(), [PINNED_V3_BLOB_LENGTH]);
  const sliceCount = table.sliceCount;
  assert.equal(sliceCount, Math.ceil(PINNED_V3_BLOB_LENGTH / AREA_TABLE_TRANSFER.sliceLength)); // 7
  const reassembled = [];
  for (let index = 0; index < sliceCount; index += 1) {
    const slice = table.sliceAt({ chunkIndex: 0, offset: index * AREA_TABLE_TRANSFER.sliceLength });
    assert.equal(slice.final, index === sliceCount - 1);
    if (!slice.final) assert.equal(slice.data.length, AREA_TABLE_TRANSFER.sliceLength);
    reassembled.push(slice.data);
  }
  assert.deepEqual(Buffer.concat(reassembled), table.serialize());
});

function buildArea(overrides = {}) {
  return {
    name: Buffer.from('AREA', 'latin1'),
    description: Buffer.from('test fixture', 'latin1'),
    enabled: true,
    unknownLeadWord: 0x1f,
    alwaysAvailableModeMask: 0,
    progressGatedModeMask: 0,
    ...overrides
  };
}

function buildTable(overrides) {
  const areas = [];
  for (let index = 0; index < AREA_TABLE_LAYOUT.areaCount; index += 1) {
    areas.push(index === 0 ? buildArea(overrides) : buildArea());
  }
  return new AreaTable({
    version: Buffer.from('TEST-RUL1', 'latin1'),
    provenance: AREA_TABLE_PROVENANCE.TEST_FIXTURE,
    areas
  });
}

test('values the client could not render whole are refused, not clamped', () => {
  const refused = (overrides) => assert.throws(
    () => buildTable(overrides),
    (error) => error instanceof AreaTableError &&
      (error.code === 'AREA_TABLE_FIELD_VALUE' || error.code === 'AREA_TABLE_FIELD_TYPE')
  );

  // An 11th group-1 descriptor would overwrite the group-2 count at +0x2b.
  refused({
    roomParameters: {
      rules: new Array(AREA_TABLE_RULE_SCREEN.maximumGroupOneRules + 1)
        .fill({ labelRecord: 1, value: 0, present: true, changeable: true })
    }
  });
  // The client-local label table holds 16 records; 16 indexes past it.
  refused({ roomParameters: { rules: [{ labelRecord: 16, value: 0 }] } });
  // A value past the 8 entries renders blank - the defect this fix removes.
  refused({ roomParameters: { rules: [{ labelRecord: 1, value: 8 }] } });
  // A default choice out of range of its own list is the blank Waiting Time row.
  refused({ roomParameters: { waitingRow: { choiceCount: 5, defaultChoice: 5 } } });
  // byte1 bits 5-3 store choiceCount-1, so 9 does not fit.
  refused({ roomParameters: { waitingRow: { choiceCount: 9, defaultChoice: 0 } } });
  // The default players index is absolute; outside [min..max] renders blank.
  refused({ roomParameters: { maximumPlayers: 4, minimumPlayers: 2, defaultPlayers: 1 } });
  // The cast mask is one byte, one bit per base character.
  refused({ castMask: 0x100 });
  // The extra-cast permission is exactly the 128-bit bitmap FUN_005baf70 reads.
  refused({ extraCastPermission: Buffer.alloc(0x0f, 0xff) });
  refused({ extraCastPermission: Buffer.alloc(0x11, 0xff) });
});

test('the generic layer encodes the confirmed bit layouts, not just the V1 values', () => {
  // An independent check of the byte packing against FUN_005c2bc0:17775-17795:
  // byte0 = present|changeable|max-1|min-1|default-1, byte1 = present|
  // changeable|(count-1)<<3|default.
  const blob = buildTable({
    castMask: 0xa5,
    extraCastPermission: Buffer.alloc(0x10, 0x5a),
    titleSettable: true,
    passwordSettable: false,
    roomParameters: {
      maximumPlayers: 3, minimumPlayers: 2, defaultPlayers: 2,
      playerCountChangeable: true,
      waitingRow: { changeable: false, choiceCount: 3, defaultChoice: 1 },
      rules: [{ labelRecord: 9, value: 2, present: false, changeable: true }]
    }
  }).serialize();
  const record = recordAt(blob, 0);
  assert.equal(record[0x03], 0xa5);
  assert.deepEqual(record.subarray(0x04, 0x14), Buffer.alloc(0x10, 0x5a));
  assert.equal(record[0x16b], 0x01, 'title bit0 only');
  for (const base of BLOCKS) {
    // present(1)|changeable(1)|max-1=2|min-1=1|default-1=1 -> 1110 0101
    assert.equal(record[base], 0xe5, 'byte0 bit packing');
    // present(1)|changeable(0)|count-1=2|default=1 -> 1001 0001
    assert.equal(record[base + 1], 0x91, 'byte1 row-decode packing');
    assert.equal(record[base + 2], 1, 'group-1 count');
    assert.deepEqual(
      record.subarray(base + 3, base + 7), Buffer.from([9, 2, 0, 1]),
      'descriptor {labelRecord, value, present, changeable}'
    );
  }
});
