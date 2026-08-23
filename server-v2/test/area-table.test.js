import assert from 'node:assert/strict';
import fs from 'node:fs';
import path from 'node:path';
import test from 'node:test';
import { fileURLToPath } from 'node:url';

import { decodeSnapField } from '../src/protocol/snap-field-codec.js';
import { decodeTcp10127Frame } from '../src/protocol/tcp10127-codec.js';
import {
  AREA_TABLE_LAYOUT,
  AREA_TABLE_PROVENANCE,
  AREA_TABLE_TRANSFER,
  AreaTableError,
  V1_OBSERVED_LEAD_WORD,
  createAreaTable,
  parseAreaTableDocument
} from '../src/state/area-table.js';
import { createV1ObservedAreaTable } from '../src/state/area-table-v1.js';

/**
 * The V1 wire that rendered Area Select on real PS2 hardware.
 *
 * `test/fixtures/area-table-v1-wire.json` holds the `0x6203` and seven `0x6204`
 * frames of `2026_07_30_14_52_53_snap_session5_trace.log`, verbatim in both
 * directions. It is the oracle for this whole slice: the expected blob is
 * DERIVED from it by decoding the slices, never written out by hand.
 */
const fixturePath = path.join(
  path.dirname(fileURLToPath(import.meta.url)), 'fixtures', 'area-table-v1-wire.json'
);
const wire = JSON.parse(fs.readFileSync(fixturePath, 'utf8'));

function framesOf(direction, command) {
  return wire.frames
    .filter((frame) => frame.dir === direction && frame.cmd === command)
    .map((frame) => decodeTcp10127Frame(Buffer.from(frame.hex, 'hex')));
}

/** Decode V1's slices back into the blob the client assembled at 0x361a70. */
function decodeV1Blob() {
  const slices = framesOf('out', '0x6204').map((frame) => {
    const plain = decodeSnapField({
      field: frame.payload.subarray(6),
      maximumDecodedLength: AREA_TABLE_TRANSFER.sliceLength,
      sequence: frame.sequence,
      unknownCodecByte: 0
    });
    assert.notEqual(plain, null, 'every V1 slice must verify its own checksum');
    return { offset: frame.payload.readUInt32BE(2), plain };
  });
  slices.sort((left, right) => left.offset - right.offset);
  let expected = 0;
  for (const slice of slices) {
    assert.equal(slice.offset, expected, 'V1 slices must tile the blob without a gap');
    expected += slice.plain.length;
  }
  return Buffer.concat(slices.map((slice) => slice.plain));
}

function testArea(overrides = {}) {
  return {
    name: Buffer.from('A', 'latin1'),
    description: Buffer.from('d', 'latin1'),
    enabled: true,
    unknownLeadWord: V1_OBSERVED_LEAD_WORD,
    alwaysAvailableModeMask: 0,
    progressGatedModeMask: 0,
    ...overrides
  };
}

function testTable(overrides = {}) {
  return createAreaTable({
    version: Buffer.from('T', 'latin1'),
    provenance: AREA_TABLE_PROVENANCE.TEST_FIXTURE,
    areas: Array.from({ length: AREA_TABLE_LAYOUT.areaCount }, () => testArea()),
    ...overrides
  });
}

/**
 * The shipped blob is V1's blob with EXACTLY the `+0x34` second line added.
 *
 * The control is the point. The naive assertions - byte-for-byte equality, or its
 * opposite, "they differ" - are each useless once the blob legitimately changes:
 * the first has to be deleted, and the second permits any change at all. This
 * blanks the one field we meant to change and asserts every remaining byte is
 * still V1's, so the intended edit is demonstrably the ONLY edit and the captured
 * blob stays the oracle.
 *
 * The rule masks are NOT blanked here any more. They are withheld at zero, which
 * is V1's value, so they need no exemption - and not exempting them means this
 * test would fail if a mask were published without updating it. That is deliberate.
 */
test('the shipped area table is V1\'s blob with only the intended fields changed', () => {
  const expected = decodeV1Blob();
  assert.equal(expected.length, 0x1300);
  const actual = createV1ObservedAreaTable().serialize();
  assert.equal(actual.length, expected.length);

  const masked = Buffer.from(actual);
  let populated = 0;
  for (let index = 0; index < AREA_TABLE_LAYOUT.areaCount; index += 1) {
    const record = index * AREA_TABLE_LAYOUT.recordStride;

    // +0x34: V1 left it all-NUL because it believed +0x1c was a 0x30-byte name
    // field. FUN_005affb0.c:97-99 renders it a line below the name, so V1's Area
    // Select drew ten blank second lines.
    const line = record + AREA_TABLE_LAYOUT.secondLineOffset;
    const lineEnd = line + AREA_TABLE_LAYOUT.secondLineFieldLength;
    assert.equal(expected.subarray(line, lineEnd).every((byte) => byte === 0), true,
      `V1 left area ${index}'s +0x34 empty - if it did not, this whole premise is wrong`);
    if (actual[line] !== 0) populated += 1;
    masked.fill(0, line, lineEnd);

    // +0x14/+0x18: the rule masks. V1 shipped both zero, which is an empty ring.
    for (const offset of [
      AREA_TABLE_LAYOUT.progressGatedModeMaskOffset,
      AREA_TABLE_LAYOUT.alwaysAvailableModeMaskOffset
    ]) {
      assert.equal(expected.readUInt32BE(record + offset), 0,
        `V1 left area ${index} +0x${offset.toString(16)} zero`);
      masked.fill(0, record + offset, record + offset + 4);
    }

    // +0x16c: the first two bytes of BOTH room-parameter blocks. V1 shipped them
    // zero, which FUN_005c3490.c:89 decodes as a maximum of ONE player.
    for (let block = 0; block < AREA_TABLE_LAYOUT.roomParameterBlockCount; block += 1) {
      const at = record + AREA_TABLE_LAYOUT.roomParameterBlockOffset +
        block * AREA_TABLE_LAYOUT.roomParameterBlockLength;
      assert.equal(expected[at], 0, `V1 left area ${index} block ${block} byte0 zero`);
      assert.equal(expected[at + 1], 0, `V1 left area ${index} block ${block} byte1 zero`);
      masked.fill(0, at, at + 2);
    }
  }
  assert.deepEqual(masked, expected,
    'nothing outside +0x14, +0x18, +0x34 and the two +0x16c byte pairs moved');
  // Nine of ten: the disabled `reserved` row has nothing to say.
  assert.equal(populated, 9, 'every area but the disabled one publishes a second line');
});

test('every area offers a party of four, so a room can actually be joined', () => {
  // The regression this pins is silence, not noise: all-zero bytes are a VALID
  // encoding that decodes to max 1, so nothing throws and nothing looks wrong -
  // the room simply never admits a second player.
  const blob = createV1ObservedAreaTable().serialize();
  for (let index = 0; index < AREA_TABLE_LAYOUT.areaCount; index += 1) {
    for (let block = 0; block < AREA_TABLE_LAYOUT.roomParameterBlockCount; block += 1) {
      const at = index * AREA_TABLE_LAYOUT.recordStride +
        AREA_TABLE_LAYOUT.roomParameterBlockOffset +
        block * AREA_TABLE_LAYOUT.roomParameterBlockLength;
      // FUN_005c3490.c:69,88 - cRam007006a5 = (byte0 >> 4 & 3) + 1
      assert.equal((blob[at] >> 4 & 3) + 1, 4, `area ${index} block ${block} max players`);
      // FUN_005c3490.c:69,87 - cRam007006a4 = (byte0 >> 2 & 3) + 1, read by
      // FUN_005be330.c:48 as the member count selection unlock waits for.
      assert.equal((blob[at] >> 2 & 3) + 1, 1, `area ${index} block ${block} min players`);
      // FUN_005be330 needs uRam007006a6 != 0 or selection never unlocks at all.
      assert.notEqual(blob[at + 1] & 0x3f, 0, `area ${index} block ${block} time limit unit`);
    }
  }
});

test('every enabled area publishes its rule mask in BOTH +0x14 and +0x18', () => {
  /*
   * SUPERSEDED twice, and the sequence is the point. This first asserted the
   * masks were PUBLISHED, was rewritten to assert they were WITHHELD after a
   * review disputed what +0x18 is, and now asserts publication again - because
   * the dispute was settled by tracing *(u32*)0x6C5480 to a copy of this very
   * blob, and then confirmed on real hardware when +0x34 (same accessor family,
   * same record) rendered on every Area Select row.
   *
   * BOTH fields, which is the correction that matters. The old doctrine - "put
   * everything in +0x18, because +0x14 is ANDed with player savedata and would
   * be invisible on a fresh console" - holds for FUN_005fe1e0 and ONLY for it.
   * FUN_005f78c0.c:47-62 builds the mode button strip from +0x14 RAW, with no
   * savedata AND and without consulting +0x18 at all. Publishing one and not the
   * other leaves half the UI empty, which reads as "rules still do not work".
   */
  const blob = createV1ObservedAreaTable().serialize();
  const published = [];
  for (let index = 0; index < AREA_TABLE_LAYOUT.areaCount; index += 1) {
    const at = index * AREA_TABLE_LAYOUT.recordStride;
    const gated = blob.readUInt32BE(at + AREA_TABLE_LAYOUT.progressGatedModeMaskOffset);
    const always = blob.readUInt32BE(at + AREA_TABLE_LAYOUT.alwaysAvailableModeMaskOffset);
    assert.equal(gated, always,
      `area ${index}: both fields carry the same mask - we have no evidence about which modes ` +
      'belong behind progression, and a split would make two consoles differ inexplicably');
    published.push(always);
  }
  assert.equal(published[0], 0x7ff, 'Free Area offers every mode id the client can reach');
  assert.ok(new Set(published).size > 1,
    'the ten areas are differentiated; V1 shipped ten byte-identical records');
  // The two disabled areas offer nothing: they are unreachable (+0x14c = 0), so
  // an empty ring is the honest value rather than an unreachable promise.
  assert.equal(published[5], 0, 'the reserved area offers no rules');
  assert.equal(published[9], 0, 'the SECRET area offers no rules');
});

test('the mask PLUMBING still works, so publishing them later is a constant edit', () => {
  // The withholding is a value decision, not a removal. Everything needed to ship
  // a mask is present and exercised: the field round-trips through the encoder at
  // the offset the layout names, in BE32 as the client's byteswap requires.
  const table = testTable({
    areas: Array.from({ length: AREA_TABLE_LAYOUT.areaCount },
      (_unused, index) => testArea({ alwaysAvailableModeMask: index === 0 ? 0x7ff : 0x003 }))
  });
  const blob = table.serialize();
  assert.equal(blob.readUInt32BE(AREA_TABLE_LAYOUT.alwaysAvailableModeMaskOffset), 0x7ff);
  assert.equal(
    blob.readUInt32BE(AREA_TABLE_LAYOUT.recordStride + AREA_TABLE_LAYOUT.alwaysAvailableModeMaskOffset),
    0x003
  );
});

test('a rule mask above the client\'s eleven mode ids is refused, never masked off', () => {
  // FUN_005fe1e0 loops while i + 1 < 0xc, so bit 11 is never tested and a value
  // carrying it would be silently dropped by the client.
  assert.throws(
    () => testTable({
      areas: Array.from({ length: AREA_TABLE_LAYOUT.areaCount },
        () => testArea({ alwaysAvailableModeMask: 0x800 }))
    }),
    (error) => error instanceof AreaTableError && error.code === 'AREA_TABLE_MODE_MASK'
  );
  assert.doesNotThrow(() => testTable({
    areas: Array.from({ length: AREA_TABLE_LAYOUT.areaCount },
      () => testArea({ alwaysAvailableModeMask: 0x7ff }))
  }));
});

test('the shipped table declares the chunk table V1 declared', () => {
  const declaration = framesOf('out', '0x6203')[0];
  const version = decodeSnapField({
    field: declaration.payload.subarray(1),
    maximumDecodedLength: AREA_TABLE_TRANSFER.maximumVersionLength,
    sequence: declaration.sequence,
    unknownCodecByte: 0
  });
  const table = createV1ObservedAreaTable();
  assert.equal(declaration.payload[0], 1, 'V1 answered mode 1');
  /*
   * SUPERSEDED 2026-08-07: this asserted the version must DIFFER from V1's, to
   * accompany the non-zero rule masks. Those masks are withheld, so the content is
   * byte-for-byte V1's again and the version must MATCH - a bump would force every
   * console through a needless seven-reply re-fetch of bytes it already holds.
   *
   * The rule the old assertion encoded is still true and still matters, so it is
   * restated rather than dropped: `FUN_001c4960.c:46-49` skips the whole 0x6204
   * fetch when the version matches the client's cache at `0x36842c`. Any commit
   * that changes a name, a description, an enable byte or a mask MUST bump the
   * version, or the change will not reach a console that cached this one - and it
   * will look exactly like the change not working.
   */
  /*
   * The version MUST differ from V1's, because the content does: every enabled
   * area now carries a `+0x34` second line V1 left NUL. `FUN_001c4960.c:46-49`
   * skips the whole 0x6204 fetch when the version matches the client's cache at
   * `0x36842c`, so a console that cached `OBAREA-V1` in this power cycle would
   * keep the blank-second-line table and the fix would look like it had not
   * landed. The LENGTH is asserted equal because the declaration's layout
   * depends on it.
   */
  assert.notDeepEqual(table.version, version, 'the content changed, so the version must too');
  /*
   * Pin the LITERAL. When the replay ran against the shipped table it pinned the
   * version bytes byte-for-byte via the 0x6203 declaration; the transfer oracle now
   * feeds a hardcoded V1 string, so without this `OBAREA-VX` or nine bytes of
   * garbage would satisfy every other assertion here.
   */
  assert.equal(table.version.toString('latin1'), 'OBAREA-V3',
    'the shipped version is pinned: nothing else in the suite constrains its content');
  assert.equal(table.version.length, version.length);
  const chunkTable = declaration.payload.subarray(1 + 4 + version.length);
  assert.equal(chunkTable.readUInt16BE(0), table.chunkLengths().length);
  assert.equal(chunkTable.readUInt32BE(2), table.chunkLengths()[0]);
});

test('every area V1 shipped enabled carries the byte FUN_005ad350 requires', () => {
  const blob = createV1ObservedAreaTable().serialize();
  const enabled = [];
  for (let index = 0; index < AREA_TABLE_LAYOUT.areaCount; index += 1) {
    const record = blob.subarray(
      index * AREA_TABLE_LAYOUT.recordStride, (index + 1) * AREA_TABLE_LAYOUT.recordStride
    );
    if (record[AREA_TABLE_LAYOUT.enableOffset] === AREA_TABLE_LAYOUT.enabledValue) {
      enabled.push(index);
    }
  }
  // V1 disabled exactly "reserved" (5) and "SECRET Area" (9).
  assert.deepEqual(enabled, [0, 1, 2, 3, 4, 6, 7, 8]);
});

test('slices tile the whole table and the last one carries only the remainder', () => {
  const table = createV1ObservedAreaTable();
  assert.equal(table.sliceCount, 7);
  const parts = [];
  for (let offset = 0; offset < table.byteLength; offset += AREA_TABLE_TRANSFER.sliceLength) {
    const slice = table.sliceAt({ chunkIndex: 0, offset });
    assert.equal(slice.offset, offset);
    assert.equal(
      slice.final,
      offset + AREA_TABLE_TRANSFER.sliceLength >= table.byteLength,
      'only the slice that reaches the declared length completes the chunk'
    );
    parts.push(slice.data);
  }
  assert.deepEqual(Buffer.concat(parts), table.serialize());
  assert.equal(parts.at(-1).length, table.byteLength % AREA_TABLE_TRANSFER.sliceLength);
  assert.equal(parts.at(-1).length, 0x154);
  for (const part of parts.slice(0, -1)) {
    assert.equal(part.length, AREA_TABLE_TRANSFER.sliceLength);
  }
});

test('an off-step or out-of-range slice is refused rather than clamped', () => {
  const table = createV1ObservedAreaTable();
  for (const [request, code] of [
    [{ chunkIndex: 1, offset: 0 }, 'AREA_TABLE_CHUNK_INDEX'],
    [{ chunkIndex: 0, offset: 1 }, 'AREA_TABLE_OFFSET'],
    [{ chunkIndex: 0, offset: -1 }, 'AREA_TABLE_OFFSET'],
    [{ chunkIndex: 0, offset: table.byteLength }, 'AREA_TABLE_OFFSET']
  ]) {
    assert.throws(
      () => table.sliceAt(request),
      (error) => error instanceof AreaTableError && error.code === code,
      JSON.stringify(request)
    );
  }
});

test('a name or description that would run into the next field is refused', () => {
  for (const [overrides, code] of [
    [{ name: Buffer.alloc(AREA_TABLE_LAYOUT.nameFieldLength, 0x41) }, 'AREA_TABLE_FIELD_LENGTH'],
    [
      { description: Buffer.alloc(AREA_TABLE_LAYOUT.descriptionFieldLength, 0x41) },
      'AREA_TABLE_FIELD_LENGTH'
    ],
    [{ name: Buffer.from('a b', 'latin1') }, 'AREA_TABLE_FIELD_VALUE'],
    [{ enabled: 1 }, 'AREA_TABLE_FIELD_VALUE'],
    [{ unknownLeadWord: 0x1_0000_0000 }, 'AREA_TABLE_FIELD_VALUE']
  ]) {
    assert.throws(
      () => testTable({
        areas: Array.from({ length: AREA_TABLE_LAYOUT.areaCount }, () => testArea(overrides))
      }),
      (error) => error instanceof AreaTableError && error.code === code,
      JSON.stringify(Object.keys(overrides))
    );
  }
  // One byte short of the field is the largest name that still terminates.
  const longest = Buffer.alloc(AREA_TABLE_LAYOUT.nameFieldLength - 1, 0x41);
  const table = testTable({
    areas: Array.from({ length: AREA_TABLE_LAYOUT.areaCount }, () => testArea({ name: longest }))
  });
  assert.equal(table.serialize()[AREA_TABLE_LAYOUT.descriptionOffset - 1], 0);
});

test('a table refuses any area count but the ten the client indexes', () => {
  for (const count of [0, 9, 11]) {
    assert.throws(
      () => testTable({
        areas: Array.from({ length: count }, () => testArea())
      }),
      (error) => error instanceof AreaTableError && error.code === 'AREA_TABLE_AREA_COUNT'
    );
  }
});

test('provenance must be stated and an empty version is refused', () => {
  assert.throws(
    () => testTable({ provenance: 'made-up' }),
    (error) => error instanceof AreaTableError && error.code === 'AREA_TABLE_PROVENANCE'
  );
  // FUN_001c4960.c:46-49 skips the fetch when the version matches the client's
  // cache, and a zero-length version matches a cache that was never written.
  assert.throws(
    () => testTable({ version: Buffer.alloc(0) }),
    (error) => error instanceof AreaTableError && error.code === 'AREA_TABLE_VERSION'
  );
  assert.throws(
    () => testTable({
      version: Buffer.alloc(AREA_TABLE_TRANSFER.maximumVersionLength + 1, 0x41)
    }),
    (error) => error instanceof AreaTableError && error.code === 'AREA_TABLE_VERSION'
  );
});

test('an operator document round-trips to the same bytes as the shipped table', () => {
  const shipped = createV1ObservedAreaTable();
  const areas = [];
  for (let index = 0; index < AREA_TABLE_LAYOUT.areaCount; index += 1) {
    const area = shipped.areaAt(index);
    areas.push({
      name: area.name.toString('latin1'),
      secondLine: area.secondLine.toString('latin1'),
      description: area.description.toString('latin1'),
      enabled: area.enabled,
      unknownLeadWord: area.unknownLeadWord,
      alwaysAvailableModeMask: area.alwaysAvailableModeMask,
      progressGatedModeMask: area.progressGatedModeMask
    });
  }
  const parsed = parseAreaTableDocument({
    version: shipped.version.toString('latin1'),
    provenance: AREA_TABLE_PROVENANCE.OPERATOR,
    areas
  });
  assert.equal(parsed.provenance, AREA_TABLE_PROVENANCE.OPERATOR);
  assert.deepEqual(parsed.serialize(), shipped.serialize());
});

test('the shipped table declares its provenance as V1-observed, not operator', () => {
  assert.equal(createV1ObservedAreaTable().provenance, AREA_TABLE_PROVENANCE.V1_OBSERVED);
});
