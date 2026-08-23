import assert from 'node:assert/strict';
import test from 'node:test';

import { DIRECTORY_PROVENANCE, createDirectoryState } from '../src/state/directory-state.js';
import { RigFixtureError, assertNoRigFixtureValues } from '../src/state/rig-fixture-gate.js';

/**
 * The rig / production boundary.
 *
 * This gate exists because the failure it guards against has already happened
 * in this project: a value chosen to make the development rig work survives
 * into a configuration everyone believes is production. It is checked here
 * rather than by review, since a value nobody re-reads is a value nobody
 * notices.
 *
 * Every case below is a value V2 or V1 has actually shipped, not an imagined
 * one.
 */

/** A production-shaped record: real-looking values, a non-zero player cap. */
function cleanRecord(overrides = {}) {
  return {
    recordId: 'lobby-1',
    unknownField0: Buffer.from('lobby1', 'latin1'),
    unknownField1: Buffer.from('eu', 'latin1'),
    unknownRaw8: Buffer.alloc(8),
    unknownField2: Buffer.from('Europe lobby one', 'latin1'),
    unknownWord0: 0,
    unknownWord1: 30,
    unknownDword: 0,
    unknownWord6510: 0,
    ...overrides
  };
}

function cleanEntry(overrides = {}) {
  return {
    entryId: 'eu-1',
    host: Buffer.from('203.0.113.10', 'latin1'),
    name: Buffer.from('Outbreak EU', 'latin1'),
    raw8: Buffer.alloc(8),
    description: Buffer.from('European server', 'latin1'),
    pageField: Buffer.from('eu', 'latin1'),
    command6502Unknown0: 0,
    command6502Unknown1: 0,
    records: [cleanRecord()],
    ...overrides
  };
}

/** `assert.throws` does not hand back the error, and these tests inspect it. */
function refusal(run) {
  try {
    run();
  } catch (error) {
    return error;
  }
  return assert.fail('expected the rig-fixture gate to refuse this directory');
}

function operatorDirectory(entries, rigFixture = false) {
  return createDirectoryState({
    entries,
    provenance: DIRECTORY_PROVENANCE.OPERATOR,
    rigFixture
  });
}

test('a production-shaped operator directory passes with no findings', () => {
  assert.deepEqual(assertNoRigFixtureValues(operatorDirectory([cleanEntry()])), []);
});

test('a private or loopback host is refused, whatever range it is from', () => {
  // A server reachable only from a private network cannot serve real players,
  // so a private literal is decisive evidence that a rig value survived.
  for (const host of [
    '10.0.0.121',    // representative private-network fixture host
    '10.0.0.1',
    '127.0.0.1',
    '172.16.4.9',
    '172.31.255.254',
    '169.254.1.1',
    '0.0.0.0'
  ]) {
    assert.throws(
      () => assertNoRigFixtureValues(
        operatorDirectory([cleanEntry({ host: Buffer.from(host, 'latin1') })])
      ),
      (error) => error instanceof RigFixtureError &&
        error.code === 'RIG_FIXTURE_IN_PRODUCTION' &&
        error.findings.some((finding) => finding.includes(host)),
      `expected ${host} to be refused`
    );
  }
});

test('a routable host outside the private ranges is accepted', () => {
  // The boundaries of each private range must not swallow their neighbours.
  for (const host of ['203.0.113.10', '172.15.0.1', '172.32.0.1', '11.0.0.1', '169.253.0.1']) {
    assert.deepEqual(
      assertNoRigFixtureValues(
        operatorDirectory([cleanEntry({ host: Buffer.from(host, 'latin1') })])
      ),
      [],
      `expected ${host} to pass`
    );
  }
});

test('a hostname is not mistaken for an address', () => {
  // The host field takes a hostname as well as a dotted quad; only the literal
  // private ranges are evidence of a rig, and a name must not trip the check.
  assert.deepEqual(
    assertNoRigFixtureValues(
      operatorDirectory([cleanEntry({ host: Buffer.from('lobby.example.net', 'latin1') })])
    ),
    []
  );
});

test('every placeholder this project has actually shipped is refused', () => {
  for (const [label, entry] of [
    ['V2 pageField', cleanEntry({ pageField: Buffer.from('PAL-V2-0', 'latin1') })],
    ['V2 entry name', cleanEntry({ name: Buffer.from('PAL-V2-RIG', 'latin1') })],
    ['V1 host', cleanEntry({ host: Buffer.from('SLOT0001', 'latin1') })],
    ['V1 lobby name', cleanEntry({ name: Buffer.from('PAL Lobby', 'latin1') })],
    ['V1 slot label', cleanEntry({ description: Buffer.from('Test Slot', 'latin1') })],
    [
      'V2 example record key',
      cleanEntry({ records: [cleanRecord({ unknownField0: Buffer.from('E0R0', 'latin1') })] })
    ],
    [
      'V2 example record field 1',
      cleanEntry({ records: [cleanRecord({ unknownField1: Buffer.from('F1', 'latin1') })] })
    ],
    [
      'V2 example record detail',
      cleanEntry({ records: [cleanRecord({ unknownField2: Buffer.from('RECORD-0', 'latin1') })] })
    ],
    [
      'V1 status string',
      cleanEntry({ records: [cleanRecord({ unknownField2: Buffer.from('OPEN', 'latin1') })] })
    ]
  ]) {
    assert.throws(
      () => assertNoRigFixtureValues(operatorDirectory([entry])),
      (error) => error instanceof RigFixtureError && error.findings.length > 0,
      `expected the ${label} placeholder to be refused`
    );
  }
});

test('a zero maximum-player cap is refused, because the client reads it as full', () => {
  // FUN_005bc990 compares the summed population with record +0x12a and raises
  // status 0xd, "Server full. You cannot participate." With the cap at 0 that
  // comparison is false for every population, so nobody can ever join.
  const error = refusal(
    () => assertNoRigFixtureValues(
      operatorDirectory([cleanEntry({ records: [cleanRecord({ unknownWord1: 0 })] })])
    )
  );
  assert.ok(error.findings.some((finding) => /maximum players is 0/.test(finding)));

  // One is enough to pass the gate: the gate checks for the rig marker, not for
  // a sensible capacity.
  assert.deepEqual(
    assertNoRigFixtureValues(
      operatorDirectory([cleanEntry({ records: [cleanRecord({ unknownWord1: 1 })] })])
    ),
    []
  );
});

test('non-zero undecoded entry bytes are refused as an unreadable assertion', () => {
  const error = refusal(
    () => assertNoRigFixtureValues(
      operatorDirectory([cleanEntry({ raw8: Buffer.from('0000000000000001', 'hex') })])
    )
  );
  assert.ok(error.findings.some((finding) => /raw8 is non-zero/.test(finding)));
});

test('a test-fixture directory is exempt, because it already declares what it is', () => {
  const state = createDirectoryState({
    provenance: DIRECTORY_PROVENANCE.TEST_FIXTURE,
    entries: [cleanEntry({
      host: Buffer.from('10.0.0.121', 'latin1'),
      pageField: Buffer.from('PAL-V2-0', 'latin1'),
      records: [cleanRecord({ unknownWord1: 0 })]
    })]
  });
  assert.deepEqual(assertNoRigFixtureValues(state), []);
});

test('enforce:false reports every finding at once instead of throwing', () => {
  // This is the path the rig itself takes at startup: it must SEE the whole
  // list, not the first item, because each one has to be closed before the
  // configuration could be production.
  const findings = assertNoRigFixtureValues(
    operatorDirectory([cleanEntry({
      host: Buffer.from('10.0.0.121', 'latin1'),
      pageField: Buffer.from('PAL-V2-0', 'latin1'),
      raw8: Buffer.from('00000000000000ff', 'hex'),
      records: [cleanRecord({
        unknownField0: Buffer.from('E0R0', 'latin1'),
        unknownWord1: 0
      })]
    })], true),
    { enforce: false }
  );
  assert.equal(findings.length, 5, findings.join('\n'));
  assert.ok(findings.some((finding) => /private or loopback/.test(finding)));
  assert.ok(findings.some((finding) => /pageField is the placeholder/.test(finding)));
  assert.ok(findings.some((finding) => /raw8 is non-zero/.test(finding)));
  assert.ok(findings.some((finding) => /unknownField0 is the placeholder/.test(finding)));
  assert.ok(findings.some((finding) => /maximum players is 0/.test(finding)));
});

test('findings name the entry and record they came from', () => {
  // A gate that says only "something is wrong" makes the operator hunt. Each
  // finding has to identify what to change.
  const findings = assertNoRigFixtureValues(
    operatorDirectory([
      cleanEntry(),
      cleanEntry({
        entryId: 'eu-2',
        host: Buffer.from('10.1.2.3', 'latin1'),
        records: [cleanRecord({ recordId: 'lobby-2', unknownWord1: 0 })]
      })
    ]),
    { enforce: false }
  );
  assert.equal(findings.length, 2);
  assert.ok(findings.every((finding) => finding.includes('eu-2')));
  assert.ok(findings.some((finding) => finding.includes('lobby-2')));
});

test('the thrown error carries the findings, not just a message', () => {
  const error = refusal(
    () => assertNoRigFixtureValues(
      operatorDirectory([cleanEntry({ host: Buffer.from('10.0.0.121', 'latin1') })])
    )
  );
  assert.equal(error.name, 'RigFixtureError');
  assert.equal(error.code, 'RIG_FIXTURE_IN_PRODUCTION');
  assert.ok(Array.isArray(error.findings) && error.findings.length === 1);
  // And it says out loud that passing is not a certificate of readiness.
  assert.match(error.message, /NOT production readiness/);
});
