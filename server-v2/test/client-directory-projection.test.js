import assert from 'node:assert/strict';
import test from 'node:test';

import {
  DIRECTORY_LIMITS,
  DIRECTORY_PROVENANCE,
  createDirectoryState
} from '../src/state/directory-state.js';
import {
  PROJECTION_PHASE,
  ProjectionError,
  createClientDirectoryProjection
} from '../src/state/client-directory-projection.js';
import { encodeSnapField } from '../src/protocol/snap-field-codec.js';

const CODEC_BYTE = 0;

function makeRecord(entryIndex, index, word) {
  return {
    recordId: `record-${entryIndex}-${index}`,
    unknownField0: Buffer.from(`K${entryIndex}-${index}`, 'latin1'),
    unknownField1: Buffer.from(`F${index}`, 'latin1'),
    unknownRaw8: Buffer.alloc(8, index),
    unknownField2: Buffer.from(`D${index}`, 'latin1'),
    unknownWord0: index,
    unknownWord1: index + 1,
    unknownDword: 0x01020304,
    unknownWord6510: word ?? 0x1000 + index
  };
}

function makeDirectory(recordCounts) {
  return createDirectoryState({
    provenance: DIRECTORY_PROVENANCE.TEST_FIXTURE,
    entries: recordCounts.map((count, entryIndex) => ({
      entryId: `entry-${entryIndex}`,
      /*
       * A DISTINCT host per entry, on purpose. `0x6510` runs once per entry and
       * its trailing field is written back to THAT entry's +0x00, which the
       * client later resolves as its connect target (T30/T31). A fixture that
       * gave every entry the same host could not tell a correct trailer from one
       * that always answers with entry 0's.
       */
      host: Buffer.from(`10.0.0.${entryIndex + 1}`, 'latin1'),
      name: Buffer.from(`E${entryIndex}`, 'latin1'),
      raw8: Buffer.alloc(8),
      description: Buffer.from(`entry ${entryIndex} description`, 'latin1'),
      pageField: Buffer.from(`PAGE${entryIndex}`, 'latin1'),
      command6502Unknown0: 0x11111111 + entryIndex,
      command6502Unknown1: 0x22222222 + entryIndex,
      records: Array.from({ length: count }, (_unused, index) => makeRecord(entryIndex, index))
    }))
  });
}

function projectionFor(recordCounts) {
  return createClientDirectoryProjection({
    directory: makeDirectory(recordCounts),
    codecByte: CODEC_BYTE
  });
}

function encodeKey(key, sequence) {
  return encodeSnapField({
    plain: Buffer.from(key, 'latin1'),
    maximumDecodedLength: DIRECTORY_LIMITS.maximumField0Length,
    sequence,
    unknownCodecByte: CODEC_BYTE
  });
}

/** Drive the record-delivery phase to completion the way the client would. */
function deliverAll(projection, sequence = 0x10) {
  const batches = [];
  let guard = 0;
  while (projection.phase === PROJECTION_PHASE.RECORD_DELIVERY) {
    guard += 1;
    assert.ok(guard < 1000, 'record delivery did not terminate');
    const selection = projection.selectCommand6502Response();
    if (selection.mode === 0) continue;
    while (projection.phase === PROJECTION_PHASE.RECORD_DELIVERY) {
      const before = projection.entryIndex;
      batches.push(projection.takeCommand6504Batch({ sequence }));
      if (projection.entryIndex !== before) break;
    }
  }
  return batches;
}

/* ---- 0x6503, the entry list ------------------------------------------- */

test('0x6503 answers the window the client asked for, entry for entry', () => {
  const projection = projectionFor([1, 1, 1]);
  const batch = projection.takeCommand6503Batch({ start: 0, count: 8 });

  assert.equal(batch.total, 3, 'total is the directory entry count, not the batch size');
  assert.equal(batch.batchStart, 0);
  assert.equal(batch.unknownCodecByte, CODEC_BYTE);
  assert.equal(batch.entries.length, 3);
  assert.deepEqual(
    batch.entries.map((entry) => entry.host.toString('latin1')),
    ['10.0.0.1', '10.0.0.2', '10.0.0.3']
  );
  assert.deepEqual(
    batch.entries.map((entry) => entry.name.toString('latin1')),
    ['E0', 'E1', 'E2']
  );
  assert.equal(batch.entries[0].description.toString('latin1'), 'entry 0 description');
  assert.equal(batch.entries[0].raw8.toString('hex'), '0000000000000000');
  // The record walk is untouched: 0x6503 precedes it and takes nothing from it.
  assert.equal(projection.phase, PROJECTION_PHASE.RECORD_DELIVERY);
  assert.equal(projection.entryIndex, 0);
});

test('0x6503 pages a 16-entry directory in the batches the client requests', () => {
  // 16 is the client's own ceiling: FUN_001c70b0 clamps to 0x10, and the mode-1
  // 0x6501 reply sets its batch size to 8 - so a full directory is exactly two
  // requests, which is the only multi-batch case that can occur.
  const projection = projectionFor(new Array(16).fill(1));

  const first = projection.takeCommand6503Batch({ start: 0, count: 8 });
  assert.equal(first.total, 16);
  assert.equal(first.batchStart, 0);
  assert.equal(first.entries.length, 8);
  assert.equal(first.entries[0].host.toString('latin1'), '10.0.0.1');
  assert.equal(first.entries[7].host.toString('latin1'), '10.0.0.8');

  const second = projection.takeCommand6503Batch({ start: 8, count: 8 });
  assert.equal(second.total, 16);
  assert.equal(second.batchStart, 8, 'the client stores this and adds the batch count');
  assert.equal(second.entries.length, 8);
  assert.equal(second.entries[0].host.toString('latin1'), '10.0.0.9');
  assert.equal(second.entries[7].host.toString('latin1'), '10.0.0.16');
});

test('0x6503 truncates the last batch to the entries that remain', () => {
  const projection = projectionFor([1, 1, 1]);
  const first = projection.takeCommand6503Batch({ start: 0, count: 2 });
  assert.equal(first.entries.length, 2);
  // The client asked for two more; only one exists, and declaring two would
  // desynchronise the cursor it advances by the batch count.
  const second = projection.takeCommand6503Batch({ start: 2, count: 2 });
  assert.equal(second.entries.length, 1);
  assert.equal(second.batchStart, 2);
  assert.equal(second.batchStart + second.entries.length, second.total);
});

test('a one-entry directory is a single complete batch', () => {
  const projection = projectionFor([1]);
  const batch = projection.takeCommand6503Batch({ start: 0, count: 8 });
  assert.equal(batch.total, 1);
  assert.equal(batch.entries.length, 1);
  assert.equal(batch.batchStart, 0);
});

test('0x6503 refuses an offset that is not the one this connection is at', () => {
  const projection = projectionFor([1, 1, 1]);
  // Ahead of the cursor: the client would seat entries at the wrong index.
  assert.throws(
    () => projection.takeCommand6503Batch({ start: 1, count: 8 }),
    (error) => error instanceof ProjectionError && error.code === 'PROJECTION_ENTRY_BATCH'
  );
  projection.takeCommand6503Batch({ start: 0, count: 2 });
  // Behind the cursor: a repeat that would double-seat.
  assert.throws(
    () => projection.takeCommand6503Batch({ start: 0, count: 2 }),
    (error) => error instanceof ProjectionError && error.code === 'PROJECTION_ENTRY_BATCH'
  );
  // Past the end: the cursor and the offset agree, but there is nothing left.
  // The client should have stopped asking - `0x365e18 >= 0x365e1e` routes it to
  // phase 8 - so this is a divergence, not an empty page to serve.
  projection.takeCommand6503Batch({ start: 2, count: 8 });
  assert.throws(
    () => projection.takeCommand6503Batch({ start: 3, count: 8 }),
    (error) => error instanceof ProjectionError && error.code === 'PROJECTION_ENTRY_BATCH'
  );
});

test('0x6503 refuses a malformed or empty request window', () => {
  for (const request of [
    { start: 0, count: 0 },
    { start: -1, count: 8 },
    { start: 0, count: -1 },
    { start: 0.5, count: 8 },
    { start: 0, count: 0x10000 },
    { start: 0x10000, count: 8 },
    {}
  ]) {
    const projection = projectionFor([1]);
    assert.throws(
      () => projection.takeCommand6503Batch(request),
      (error) => error instanceof ProjectionError && error.code === 'PROJECTION_ENTRY_BATCH',
      `expected ${JSON.stringify(request)} to be refused`
    );
  }
});

test('0x6503 is refused once the record walk has started', () => {
  // FUN_001c70b0 seats the entry table; running it mid-walk would contradict the
  // table the client has already filled and the slots it has already allocated.
  const projection = projectionFor([2, 1]);
  projection.takeCommand6503Batch({ start: 0, count: 8 });
  projection.selectCommand6502Response();
  projection.takeCommand6504Batch({ sequence: 0x10 });
  assert.throws(
    () => projection.takeCommand6503Batch({ start: 0, count: 8 }),
    (error) => error instanceof ProjectionError && error.code === 'PROJECTION_PHASE'
  );
});

test('0x6503 hands out copies, never the authoritative buffers', () => {
  const directory = makeDirectory([1]);
  const projection = createClientDirectoryProjection({ directory, codecByte: CODEC_BYTE });
  const batch = projection.takeCommand6503Batch({ start: 0, count: 8 });
  const authoritative = directory.entryAt(0);
  for (const field of ['host', 'name', 'raw8', 'description']) {
    assert.notEqual(batch.entries[0][field], authoritative[field], `${field} is a copy`);
    batch.entries[0][field].fill(0x41);
    assert.notEqual(
      authoritative[field].toString('latin1'),
      batch.entries[0][field].toString('latin1'),
      `mutating the response ${field} must not reach directory state`
    );
  }
});

test('the 0x6503 host and the 0x6510 trailer are the same entry field', () => {
  // If these two ever disagreed the client would publish one connect target and
  // then overwrite it with another, which is exactly the T30 failure.
  const projection = projectionFor([1, 1]);
  const listed = projection.takeCommand6503Batch({ start: 0, count: 8 });
  const sequence = 0x22;
  deliverAll(projection, sequence);
  for (const entryIndex of [0, 1]) {
    const answer = projection.resolveCommand6510Response({
      sequence,
      encodedRecordFields: [encodeKey(`K${entryIndex}-0`, sequence)]
    });
    assert.equal(
      answer.unknownTrailingField.toString('latin1'),
      listed.entries[entryIndex].host.toString('latin1'),
      `entry ${entryIndex} trailer must be the host 0x6503 published for it`
    );
  }
});

test('walks entries with 0x6502 mode 1 and reports the proven 0x6504 batch shape', () => {
  const projection = projectionFor([2]);
  const selection = projection.selectCommand6502Response();
  assert.deepEqual(selection, { mode: 1, unknown0: 0x11111111, unknown1: 0x22222222 });

  const batch = projection.takeCommand6504Batch({ sequence: 0x10 });
  assert.equal(batch.unknownTotal, 2);
  assert.equal(batch.unknownStart, 0);
  assert.equal(batch.unknownCodecByte, CODEC_BYTE);
  assert.equal(batch.records.length, 2);
  assert.deepEqual(Object.keys(batch.records[0]).sort(), [
    'unknownDword', 'unknownField0', 'unknownField1', 'unknownField2',
    'unknownRaw8', 'unknownWord0', 'unknownWord1'
  ]);
  // unknownWord6510 is answered by 0x6510, never by 0x6504.
  assert.equal(Object.hasOwn(batch.records[0], 'unknownWord6510'), false);
  assert.equal(projection.phase, PROJECTION_PHASE.KEY_EXCHANGE);
});

test('skips an entry with no records using the proven 0x6502 mode-0 route', () => {
  const projection = projectionFor([0, 1]);
  assert.deepEqual(projection.selectCommand6502Response(), { mode: 0 });
  assert.equal(projection.entryIndex, 1);
  assert.equal(projection.selectCommand6502Response().mode, 1);
});

test('answers 0x6510 by key and returns the words in request order', () => {
  const projection = projectionFor([3]);
  deliverAll(projection);
  const sequence = 0x40;
  // Deliberately not cursor order: the client identifies records by key.
  const requested = ['K0-2', 'K0-0', 'K0-1'];
  const response = projection.resolveCommand6510Response({
    sequence,
    encodedRecordFields: requested.map((key) => encodeKey(key, sequence))
  });
  assert.deepEqual(response.recordWords, [0x1002, 0x1000, 0x1001]);
  assert.equal(response.unknownCodecByte, CODEC_BYTE);
  assert.equal(response.unknownTrailingField.toString('latin1'), '10.0.0.1');
  assert.equal(projection.phase, PROJECTION_PHASE.COMPLETE);
});

test('reordering the keys reorders the words', () => {
  const forward = projectionFor([3]);
  const reverse = projectionFor([3]);
  deliverAll(forward);
  deliverAll(reverse);
  const sequence = 0x41;
  const keys = ['K0-0', 'K0-1', 'K0-2'];
  const first = forward.resolveCommand6510Response({
    sequence,
    encodedRecordFields: keys.map((key) => encodeKey(key, sequence))
  });
  const second = reverse.resolveCommand6510Response({
    sequence,
    encodedRecordFields: [...keys].reverse().map((key) => encodeKey(key, sequence))
  });
  assert.deepEqual(first.recordWords, [0x1000, 0x1001, 0x1002]);
  assert.deepEqual(second.recordWords, [0x1002, 0x1001, 0x1000]);
});

test('fails closed on undecodable, unknown, duplicate and cross-entry keys', () => {
  const sequence = 0x42;
  const cases = [
    [
      'undecodable under the connection codec state',
      () => [encodeSnapField({
        plain: Buffer.from('K0-0', 'latin1'),
        maximumDecodedLength: DIRECTORY_LIMITS.maximumField0Length,
        sequence,
        unknownCodecByte: 0x17
      }), encodeKey('K0-1', sequence)],
      'PROJECTION_KEY_DECODE'
    ],
    [
      'corrupted body',
      () => {
        const field = encodeKey('K0-0', sequence);
        field[4] ^= 0x01;
        return [field, encodeKey('K0-1', sequence)];
      },
      'PROJECTION_KEY_DECODE'
    ],
    [
      'wrong sequence',
      () => [encodeKey('K0-0', sequence + 1), encodeKey('K0-1', sequence)],
      'PROJECTION_KEY_DECODE'
    ],
    [
      'unknown key',
      () => [encodeKey('NOPE', sequence), encodeKey('K0-1', sequence)],
      'PROJECTION_KEY_UNKNOWN'
    ],
    [
      'duplicate key',
      () => [encodeKey('K0-0', sequence), encodeKey('K0-0', sequence)],
      'PROJECTION_KEY_DUPLICATE'
    ],
    [
      'key from another entry',
      () => [encodeKey('K1-0', sequence), encodeKey('K0-1', sequence)],
      'PROJECTION_KEY_UNKNOWN'
    ]
  ];
  for (const [name, buildFields, code] of cases) {
    const projection = projectionFor([2, 2]);
    deliverAll(projection);
    assert.throws(
      () => projection.resolveCommand6510Response({
        sequence,
        encodedRecordFields: buildFields()
      }),
      (error) => error instanceof ProjectionError && error.code === code,
      `${name} must fail closed with ${code}`
    );
  }
});

test('rejects a key count that does not match the window the client should ask for', () => {
  const projection = projectionFor([2]);
  deliverAll(projection);
  const sequence = 0x43;
  assert.throws(
    () => projection.resolveCommand6510Response({
      sequence,
      encodedRecordFields: [encodeKey('K0-0', sequence)]
    }),
    (error) => error instanceof ProjectionError && error.code === 'PROJECTION_KEY_BATCH'
  );
});

test('splits a long entry into the twelve-key batches the builder can emit', () => {
  const projection = projectionFor([20]);
  deliverAll(projection);
  const sequence = 0x44;
  const first = projection.resolveCommand6510Response({
    sequence,
    encodedRecordFields: Array.from({ length: 12 }, (_unused, index) =>
      encodeKey(`K0-${index}`, sequence))
  });
  assert.equal(first.recordWords.length, 12);
  assert.equal(projection.phase, PROJECTION_PHASE.KEY_EXCHANGE);
  const second = projection.resolveCommand6510Response({
    sequence,
    encodedRecordFields: Array.from({ length: 8 }, (_unused, index) =>
      encodeKey(`K0-${index + 12}`, sequence))
  });
  assert.equal(second.recordWords.length, 8);
  assert.deepEqual(second.recordWords, [0x100c, 0x100d, 0x100e, 0x100f, 0x1010, 0x1011, 0x1012, 0x1013]);
  assert.equal(projection.phase, PROJECTION_PHASE.COMPLETE);
});

test('never seats more than the client residency budget and evicts whole entries', () => {
  // Three entries of 30 records: 90 in authoritative state, 64 resident at most.
  const directory = makeDirectory([30, 30, 30]);
  assert.equal(directory.totalRecordCount, 90);
  const projection = createClientDirectoryProjection({ directory, codecByte: CODEC_BYTE });
  deliverAll(projection);
  assert.ok(
    projection.residentRecordCount <= DIRECTORY_LIMITS.clientResidencyBudget,
    `resident ${projection.residentRecordCount} exceeded the budget`
  );
  // FUN_001c7a70 scans the ownership table DOWNWARD from slot 0x3f
  // (0x001c7d18 / 0x001c7e1c), so the victim is the owner of the highest
  // occupied slot - the most recently seated neighbour, entry 1, not entry 0.
  // Entry 0 holds slots 0..29, entry 1 held 30..59, and entry 2 reuses 30..59
  // after entry 1 is freed.
  assert.deepEqual(projection.residentEntryIndexes(), [0, 2]);
  assert.equal(projection.residentRecordCountForEntry(0), 30);
  assert.equal(projection.residentRecordCountForEntry(1), 0);
  assert.equal(projection.residentRecordCountForEntry(2), 30);
  assert.equal(projection.residentRecordCount, 60);
  // Authoritative state is untouched by the client's eviction.
  assert.equal(directory.totalRecordCount, 90);
  assert.equal(directory.entryAt(0).records.length, 30);
});

test('an evicted entry answers with no words while resident entries still answer', () => {
  const directory = makeDirectory([30, 30, 30]);
  const projection = createClientDirectoryProjection({ directory, codecByte: CODEC_BYTE });
  deliverAll(projection);
  const sequence = 0x45;

  // Entry 0 is still resident: three batches of 12, 12 and 6.
  for (const [start, count] of [[0, 12], [12, 12], [24, 6]]) {
    const answer = projection.resolveCommand6510Response({
      sequence,
      encodedRecordFields: Array.from({ length: count }, (_unused, index) =>
        encodeKey(`K0-${start + index}`, sequence))
    });
    assert.equal(answer.recordWords.length, count);
    assert.equal(answer.unknownTrailingField.toString('latin1'), '10.0.0.1');
  }


  // Entry 1 was evicted, so the client holds nothing for it and asks for nothing.
  assert.equal(projection.entryIndex, 1);
  const empty = projection.resolveCommand6510Response({ sequence, encodedRecordFields: [] });
  assert.deepEqual(empty.recordWords, []);
  // Entry 1's OWN host, not entry 0's: the trailer is written back to the entry
  // the walk is currently on, so answering with the wrong one would overwrite
  // that entry's connect target.
  assert.equal(empty.unknownTrailingField.toString('latin1'), '10.0.0.2');
  assert.equal(projection.entryIndex, 2);

  // Entry 2 is resident and answers normally.
  const resumed = projection.resolveCommand6510Response({
    sequence,
    encodedRecordFields: Array.from({ length: 12 }, (_unused, index) =>
      encodeKey(`K2-${index}`, sequence))
  });
  assert.equal(resumed.recordWords.length, 12);
});

test('a key for an evicted record is refused rather than answered from state', () => {
  const directory = makeDirectory([30, 30, 30]);
  const projection = createClientDirectoryProjection({ directory, codecByte: CODEC_BYTE });
  deliverAll(projection);
  const sequence = 0x46;
  // Walk entry 0 out of the way, then offer an evicted entry-1 key at entry 1's
  // turn. Authoritative state still has that record; this connection does not.
  for (const [start, count] of [[0, 12], [12, 12], [24, 6]]) {
    projection.resolveCommand6510Response({
      sequence,
      encodedRecordFields: Array.from({ length: count }, (_unused, index) =>
        encodeKey(`K0-${start + index}`, sequence))
    });
  }
  assert.equal(directory.entryAt(1).records.length, 30, 'authoritative state still holds them');
  assert.throws(
    () => projection.resolveCommand6510Response({
      sequence,
      encodedRecordFields: [encodeKey('K1-0', sequence)]
    }),
    (error) => error instanceof ProjectionError && error.code === 'PROJECTION_KEY_BATCH'
  );
});

test('splits one entry across several 0x6504 batches when a batch size is set', () => {
  const directory = makeDirectory([5]);
  const projection = createClientDirectoryProjection({
    directory,
    codecByte: CODEC_BYTE,
    recordBatchSize: 2
  });
  assert.equal(projection.selectCommand6502Response().mode, 1);

  const first = projection.takeCommand6504Batch({ sequence: 0x60 });
  assert.equal(first.unknownTotal, 5);
  assert.equal(first.unknownStart, 0);
  assert.equal(first.records.length, 2);
  assert.equal(projection.phase, PROJECTION_PHASE.RECORD_DELIVERY);
  assert.equal(projection.entryIndex, 0, 'an incomplete batch stays on the same entry');

  const second = projection.takeCommand6504Batch({ sequence: 0x61 });
  assert.equal(second.unknownStart, 2);
  assert.equal(second.records.length, 2);
  assert.equal(projection.phase, PROJECTION_PHASE.RECORD_DELIVERY);

  const third = projection.takeCommand6504Batch({ sequence: 0x62 });
  assert.equal(third.unknownStart, 4);
  assert.equal(third.records.length, 1);
  // start + count now equals the total, so the entry is complete.
  assert.equal(projection.phase, PROJECTION_PHASE.KEY_EXCHANGE);
  assert.equal(projection.residentRecordCountForEntry(0), 5);

  const sequence = 0x63;
  const answer = projection.resolveCommand6510Response({
    sequence,
    encodedRecordFields: Array.from({ length: 5 }, (_unused, index) =>
      encodeKey(`K0-${index}`, sequence))
  });
  assert.deepEqual(answer.recordWords, [0x1000, 0x1001, 0x1002, 0x1003, 0x1004]);
});

test('a response never exposes authoritative buffers to its consumer', () => {
  const directory = makeDirectory([1]);
  const projection = createClientDirectoryProjection({ directory, codecByte: CODEC_BYTE });
  projection.selectCommand6502Response();
  const batch = projection.takeCommand6504Batch({ sequence: 0x70 });
  batch.records[0].unknownField0[0] = 0x00;
  batch.records[0].unknownRaw8[0] = 0xff;
  assert.equal(directory.entryAt(0).records[0].unknownField0.toString('latin1'), 'K0-0');
  assert.equal(directory.entryAt(0).records[0].unknownRaw8[0], 0);

  const sequence = 0x71;
  const answer = projection.resolveCommand6510Response({
    sequence,
    encodedRecordFields: [encodeKey('K0-0', sequence)]
  });
  answer.unknownTrailingField[0] = 0x00;
  assert.equal(directory.entryAt(0).pageField.toString('latin1'), 'PAGE0');
});

test('rejects an unusable record batch size', () => {
  for (const recordBatchSize of [0, -1, 256, 1.5]) {
    assert.throws(
      () => createClientDirectoryProjection({
        directory: makeDirectory([1]),
        codecByte: CODEC_BYTE,
        recordBatchSize
      }),
      (error) => error instanceof ProjectionError && error.code === 'PROJECTION_BATCH_SIZE'
    );
  }
});

test('two projections over one directory stay independent', () => {
  const directory = makeDirectory([2, 2]);
  const first = createClientDirectoryProjection({ directory, codecByte: CODEC_BYTE });
  const second = createClientDirectoryProjection({ directory, codecByte: CODEC_BYTE });

  first.selectCommand6502Response();
  first.takeCommand6504Batch({ sequence: 0x50 });
  assert.equal(first.entryIndex, 1);
  assert.equal(first.residentRecordCount, 2);

  // The second connection has not moved at all.
  assert.equal(second.entryIndex, 0);
  assert.equal(second.residentRecordCount, 0);
  assert.equal(second.phase, PROJECTION_PHASE.RECORD_DELIVERY);

  deliverAll(second);
  assert.equal(second.phase, PROJECTION_PHASE.KEY_EXCHANGE);
  assert.equal(first.phase, PROJECTION_PHASE.RECORD_DELIVERY);
  assert.equal(directory.totalRecordCount, 4);
});

test('refuses commands that arrive in the wrong phase', () => {
  const projection = projectionFor([1]);
  assert.throws(
    () => projection.resolveCommand6510Response({ sequence: 1, encodedRecordFields: [] }),
    (error) => error instanceof ProjectionError && error.code === 'PROJECTION_PHASE'
  );
  deliverAll(projection);
  assert.throws(
    () => projection.selectCommand6502Response(),
    (error) => error instanceof ProjectionError && error.code === 'PROJECTION_PHASE'
  );
  assert.throws(
    () => projection.takeCommand6504Batch({ sequence: 1 }),
    (error) => error instanceof ProjectionError && error.code === 'PROJECTION_PHASE'
  );
});

test('requires a real directory and a connection codec byte', () => {
  assert.throws(
    () => createClientDirectoryProjection({ directory: {}, codecByte: 0 }),
    (error) => error instanceof ProjectionError && error.code === 'PROJECTION_DIRECTORY'
  );
  assert.throws(
    () => createClientDirectoryProjection({ directory: makeDirectory([1]), codecByte: 256 }),
    (error) => error instanceof ProjectionError && error.code === 'PROJECTION_CODEC_STATE'
  );
});

test('a resumed 0x6510 re-enters the key exchange over the records the client still holds', () => {
  // T28 (runtime) + FUN_001c8790 (corpus): the resume restarts the SAME
  // positional window at cursor 0, so a completed projection must answer it
  // rather than refuse. Two records, because one cannot distinguish the models.
  const projection = projectionFor([2]);
  deliverAll(projection);
  assert.equal(projection.phase, PROJECTION_PHASE.KEY_EXCHANGE);

  const keys = ['K0-0', 'K0-1'];
  const fresh = projection.resolveCommand6510Response({
    sequence: 0x02,
    encodedRecordFields: keys.map((key) => encodeKey(key, 0x02))
  });
  assert.equal(fresh.recordWords.length, 2);
  assert.equal(projection.phase, PROJECTION_PHASE.COMPLETE);

  // THE RESUME. The same projection object - that is the whole point of session
  // ownership - and the client asks for both records again at cursor 0.
  const resumed = projection.resolveCommand6510Response({
    sequence: 0x47,
    encodedRecordFields: keys.map((key) => encodeKey(key, 0x47))
  });
  assert.equal(resumed.recordWords.length, 2, 'both records answered, in request order');
  assert.equal(
    projection.phase,
    PROJECTION_PHASE.COMPLETE,
    'and it settles back to complete, so a second resume behaves the same way'
  );

  // Repeatable: the client reconnected twice within run 7.
  const again = projection.resolveCommand6510Response({
    sequence: 0x55,
    encodedRecordFields: keys.map((key) => encodeKey(key, 0x55))
  });
  assert.equal(again.recordWords.length, 2);
});

test('a resume works when the FIRST entry holds no records', () => {
  /*
   * Regression, found by review 2026-08-06. The resume guard asked whether
   * entry 0 held records, so a directory whose first entry had none - an area
   * with no rooms, an ordinary state - failed every resume with
   * PROJECTION_RESUME_EMPTY, which is the player-visible "could not connect to
   * lobby server". It could not happen before 0x6503 shipped, because the
   * client could never walk past entry 0 while the entry total stayed 0.
   */
  const projection = projectionFor([0, 2]);
  const sequence = 0x31;
  projection.takeCommand6503Batch({ start: 0, count: 8 });
  deliverAll(projection, sequence);
  assert.equal(projection.phase, PROJECTION_PHASE.KEY_EXCHANGE);

  // Entry 0 seated nothing, so the client asks for no keys and gets entry 0's
  // own host back; entry 1 then answers normally.
  assert.deepEqual(
    projection.resolveCommand6510Response({ sequence, encodedRecordFields: [] }).recordWords,
    []
  );
  projection.resolveCommand6510Response({
    sequence,
    encodedRecordFields: [encodeKey('K1-0', sequence), encodeKey('K1-1', sequence)]
  });
  assert.equal(projection.phase, PROJECTION_PHASE.COMPLETE);

  // The resume: the client restarts at entry 0, which still holds nothing.
  const resumed = projection.resolveCommand6510Response({ sequence, encodedRecordFields: [] });
  assert.deepEqual(resumed.recordWords, []);
  assert.equal(resumed.unknownTrailingField.toString('latin1'), '10.0.0.1');
  // And entry 1's retained records are still answerable afterwards.
  const answered = projection.resolveCommand6510Response({
    sequence,
    encodedRecordFields: [encodeKey('K1-0', sequence), encodeKey('K1-1', sequence)]
  });
  assert.equal(answered.recordWords.length, 2);
  assert.equal(answered.unknownTrailingField.toString('latin1'), '10.0.0.2');
});

test('a resumed 0x6510 still fails closed on a key the connection does not hold', () => {
  // Re-entry must not weaken the matching. ONLY the phase gate changed.
  const projection = projectionFor([2]);
  deliverAll(projection);
  projection.resolveCommand6510Response({
    sequence: 0x02,
    encodedRecordFields: ['K0-0', 'K0-1'].map((key) => encodeKey(key, 0x02))
  });

  assert.throws(
    () => projection.resolveCommand6510Response({
      sequence: 0x47,
      encodedRecordFields: [encodeKey('K0-0', 0x47), encodeKey('NOPE', 0x47)]
    }),
    (error) => error.code === 'PROJECTION_KEY_UNKNOWN'
  );
});

test('a resumed 0x6510 whose count does not match the resident window is refused', () => {
  const projection = projectionFor([2]);
  deliverAll(projection);
  projection.resolveCommand6510Response({
    sequence: 0x02,
    encodedRecordFields: ['K0-0', 'K0-1'].map((key) => encodeKey(key, 0x02))
  });

  assert.throws(
    // One key when the client holds two: either the model or the client diverged.
    () => projection.resolveCommand6510Response({
      sequence: 0x47,
      encodedRecordFields: [encodeKey('K0-0', 0x47)]
    }),
    (error) => error.code === 'PROJECTION_KEY_BATCH'
  );
});

/* ---- the 0x6510 word is a REFERENCE, resolved when the client asks ------- */

test('the 0x6510 word is resolved at ANSWER time, not snapshotted at 0x6504 time', () => {
  /*
   * THE DEFECT, and it is an ordering defect of the same class as recording
   * presence only at the deepest level: the projection copied
   * `record.unknownWord6510` into its resident table when the `0x6504` batch was
   * delivered, and answered `0x6510` from that copy - a value describing a moment
   * several round trips earlier. It was latent only because the shipped directory
   * carries a literal 0 there.
   *
   * DIRECTIONAL: with the snapshot restored, `live` below is read once during
   * `deliverAll` and both answers come back the same.
   */
  let population = 7;
  const projection = createClientDirectoryProjection({
    directory: makeDirectory([2]),
    codecByte: CODEC_BYTE,
    resolveRecordWord: () => population
  });
  deliverAll(projection);

  const answerWith = (sequence) => projection.resolveCommand6510Response({
    sequence,
    encodedRecordFields: ['K0-0', 'K0-1'].map((key) => encodeKey(key, sequence))
  });
  assert.deepEqual(answerWith(0x50).recordWords, [7, 7]);

  // A player arrives between one ladder run and the next.
  population = 9;
  const second = createClientDirectoryProjection({
    directory: makeDirectory([2]),
    codecByte: CODEC_BYTE,
    resolveRecordWord: () => population
  });
  deliverAll(second);
  population = 11;
  assert.deepEqual(
    second.resolveCommand6510Response({
      sequence: 0x51,
      encodedRecordFields: ['K0-0', 'K0-1'].map((key) => encodeKey(key, 0x51))
    }).recordWords,
    [11, 11],
    'the count that changed AFTER 0x6504 is the one on the wire'
  );
});

test('with no resolver the 0x6510 word still comes from the directory, read at answer time', () => {
  const projection = projectionFor([2]);
  deliverAll(projection);
  const sequence = 0x52;
  assert.deepEqual(
    projection.resolveCommand6510Response({
      sequence,
      encodedRecordFields: ['K0-0', 'K0-1'].map((key) => encodeKey(key, sequence))
    }).recordWords,
    [0x1000, 0x1001],
    'the default behaviour is unchanged; only WHEN it is read moved'
  );
});

test('a 0x6510 word outside the BE16 field is refused rather than truncated', () => {
  const projection = createClientDirectoryProjection({
    directory: makeDirectory([1]),
    codecByte: CODEC_BYTE,
    resolveRecordWord: () => 0x10000
  });
  deliverAll(projection);
  assert.throws(
    () => projection.resolveCommand6510Response({
      sequence: 0x53,
      encodedRecordFields: [encodeKey('K0-0', 0x53)]
    }),
    (error) => error instanceof ProjectionError && error.code === 'PROJECTION_WORD_RANGE'
  );
});

test('the 0x6510 current-players word is a LIVE query, not a value snapshotted at delivery', () => {
  /*
   * The rig showed Server Select reading "Current players 0P" with a player
   * signed in. The cause was not a wrong number - the field had no runtime input
   * at all: the projection fell back to `record.unknownWord6510`, a configuration
   * constant, so it would read 0 with fifty players online.
   *
   * Two properties are pinned, and the second is the one that rots quietly:
   *   1. a supplied resolver is actually CONSULTED, and
   *   2. it is consulted at ANSWER time, so a count that changes after the 0x6504
   *      delivery is still reflected. Snapshotting by value looks correct in a
   *      single-player test and is stale the moment anyone else connects.
   */
  let live = 0;
  let consulted = 0;
  const projection = createClientDirectoryProjection({
    directory: makeDirectory([1]),
    codecByte: CODEC_BYTE,
    resolveRecordWord: () => { consulted += 1; return live; }
  });
  deliverAll(projection);

  // The count changes AFTER delivery - exactly the window a snapshot would miss.
  live = 3;
  const sequence = 0x40;
  const first = projection.resolveCommand6510Response({
    sequence, encodedRecordFields: [encodeKey('K0-0', sequence)]
  });
  assert.ok(consulted > 0, 'the supplied resolver was consulted at all');
  assert.deepEqual(first.recordWords, [3], 'the answer reflects the count at ANSWER time');
});
