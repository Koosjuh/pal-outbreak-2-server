import assert from 'node:assert/strict';
import test from 'node:test';

import {
  AREA_DIRECTORY_BOX_COUNT,
  AREA_DIRECTORY_PROVENANCE,
  AreaDirectory,
  AreaDirectoryError,
  createV1ObservedAreaDirectory,
  parseAreaDirectoryDocument
} from '../src/udp/area-directory.js';

/**
 * The op-0x48 content, and the one V1 defect it exists to make unrepeatable.
 */

const v1Name = (id) => `AREA00${String(id).padStart(2, '0')}`;

function areas({ keyFor = (id) => id, nameFor = v1Name } = {}) {
  return Array.from({ length: AREA_DIRECTORY_BOX_COUNT }, (_unused, index) => ({
    name: nameFor(index + 1),
    boxId: index + 1,
    key: keyFor(index + 1)
  }));
}

function directory(overrides = {}) {
  return new AreaDirectory({
    provenance: AREA_DIRECTORY_PROVENANCE.TEST_FIXTURE,
    areas: areas(),
    ...overrides
  });
}

test('the V1-observed directory publishes the ten names the archive reply carried', () => {
  const published = createV1ObservedAreaDirectory();
  assert.equal(published.provenance, AREA_DIRECTORY_PROVENANCE.V1_OBSERVED);
  assert.deepEqual(
    published.areas().map((area) => area.name),
    [
      'AREA0001', 'AREA0002', 'AREA0003', 'AREA0004', 'AREA0005',
      'AREA0006', 'AREA0007', 'AREA0008', 'AREA0009', 'AREA0010'
    ]
  );
});

test('every published key is distinct and non-zero, unlike the ten zeros V1 sent', () => {
  const keys = createV1ObservedAreaDirectory().areas().map((area) => area.key);
  assert.equal(new Set(keys).size, AREA_DIRECTORY_BOX_COUNT);
  assert.ok(keys.every((key) => key !== 0));
});

test('a zero key is refused: it matches the client zeroed lookup table at 0x6fec28', () => {
  assert.throws(
    () => directory({ areas: areas({ keyFor: () => 0 }) }),
    (error) => error instanceof AreaDirectoryError && error.code === 'AREA_DIRECTORY_KEY'
  );
});

test('two areas sharing a key are refused: the refresh would resolve both to one box', () => {
  assert.throws(
    () => directory({ areas: areas({ keyFor: (id) => (id === 7 ? 3 : id) }) }),
    (error) => error instanceof AreaDirectoryError && error.code === 'AREA_DIRECTORY_KEY'
  );
});

test('a name whose trailing digits disagree with its box id is refused', () => {
  assert.throws(
    // FUN_005c1220 reads name[strlen-2..strlen-1]; "AREA0099" would select box 98.
    () => directory({ areas: areas({ nameFor: (id) => (id === 4 ? 'AREA0099' : v1Name(id)) }) }),
    (error) => error instanceof AreaDirectoryError && error.code === 'AREA_DIRECTORY_NAME'
  );
});

test('a name that fills the 16-byte record field leaving no NUL is refused', () => {
  assert.throws(
    () => directory({
      areas: areas({ nameFor: (id) => (id === 1 ? 'AAAAAAAAAAAAAA01' : v1Name(id)) })
    }),
    (error) => error instanceof AreaDirectoryError && error.code === 'AREA_DIRECTORY_NAME'
  );
});

test('a count other than ten is refused rather than silently served', () => {
  assert.throws(
    () => directory({ areas: areas().slice(0, 6) }),
    (error) => error instanceof AreaDirectoryError && error.code === 'AREA_DIRECTORY_COUNT'
  );
});

test('provenance must be stated', () => {
  assert.throws(
    () => new AreaDirectory({ areas: areas() }),
    (error) => error instanceof AreaDirectoryError && error.code === 'AREA_DIRECTORY_PROVENANCE'
  );
});

test('records carry the live count per box and report the population sum', () => {
  const published = directory();
  const counts = new Map([[1, 3], [4, 2], [10, 1]]);
  const { records, population } = published.records((area) => counts.get(area.boxId) ?? 0);
  assert.equal(records.length, AREA_DIRECTORY_BOX_COUNT);
  assert.equal(records[0].playerCount, 3);
  assert.equal(records[3].playerCount, 2);
  assert.equal(records[9].playerCount, 1);
  // The sum is the "Server full" gate's left operand: FUN_005bc990 compares it
  // against the TCP-10127 0x6504 max players.
  assert.equal(population, 6);
});

test('a count above 65535 is refused, because only lhu(rec+0x10) is ever summed', () => {
  assert.throws(
    () => directory().records(() => 0x10000),
    (error) => error instanceof AreaDirectoryError && error.code === 'AREA_DIRECTORY_COUNTS'
  );
});

test('areaByKey resolves the ENTER request back to its box', () => {
  const published = createV1ObservedAreaDirectory();
  assert.equal(published.areaByKey(7).boxId, 7);
  assert.equal(published.areaByKey(0x1234), null);
});

test('an operator document that omits keys inherits the box id, never zero', () => {
  const published = parseAreaDirectoryDocument({
    provenance: AREA_DIRECTORY_PROVENANCE.OPERATOR,
    areas: areas().map(({ name, boxId }) => ({ name, boxId }))
  });
  assert.deepEqual(published.areas().map((area) => area.key), [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);
});
