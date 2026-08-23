import assert from 'node:assert/strict';
import test from 'node:test';

import { RuleSet, RuleSetError, createRuleSet } from '../src/state/rule-set.js';

/**
 * Contract rows from RuleSet.java, table-driven: the per-area rule tables,
 * changeable masks, value->meaning mappings and reset values are all read
 * directly from the reference constructor switch (lines 62-239), reset()
 * (294-310) and the getters (344-389). BIOSERVER-CONTRACT §3/§5 summarize the
 * same tables.
 */

// One row per area flavour. Areas 1 and 6..10 share the default table.
const AREA_TABLE = [
  {
    area: 1, label: 'default',
    rules: [
      { name: 'number of players', changeable: 1, value: 2, attCount: 3 },
      { name: 'wait limit', changeable: 1, value: 2, attCount: 5 },
      { name: 'difficulty level', changeable: 1, value: 3, attCount: 4 }
    ],
    ff: 0, nm: 0, infinity: 0
  },
  {
    area: 2, label: 'nightmare fixed on',
    rules: [
      { name: 'number of players', changeable: 1, value: 2, attCount: 3 },
      { name: 'wait limit', changeable: 1, value: 2, attCount: 5 },
      { name: 'difficulty level', changeable: 1, value: 3, attCount: 4 },
      { name: 'nightmare', changeable: 0, value: 1, attCount: 2 }
    ],
    ff: 0, nm: 1, infinity: 0
  },
  {
    area: 3, label: 'friendly fire fixed on',
    rules: [
      { name: 'number of players', changeable: 1, value: 2, attCount: 3 },
      { name: 'wait limit', changeable: 1, value: 2, attCount: 5 },
      { name: 'difficulty level', changeable: 1, value: 3, attCount: 4 },
      { name: 'friendly fire', changeable: 0, value: 1, attCount: 2 }
    ],
    ff: 1, nm: 0, infinity: 0
  },
  {
    area: 4, label: 'panic: ff+nightmare fixed on',
    rules: [
      { name: 'number of players', changeable: 1, value: 2, attCount: 3 },
      { name: 'wait limit', changeable: 1, value: 2, attCount: 5 },
      { name: 'difficulty level', changeable: 1, value: 3, attCount: 4 },
      { name: 'friendly fire', changeable: 0, value: 1, attCount: 2 },
      { name: 'nightmare', changeable: 0, value: 1, attCount: 2 }
    ],
    ff: 1, nm: 1, infinity: 0
  },
  {
    area: 5, label: 'infinity: ff/nm selectable, infinity fixed on',
    rules: [
      { name: 'number of players', changeable: 1, value: 2, attCount: 3 },
      { name: 'wait limit', changeable: 1, value: 2, attCount: 5 },
      { name: 'difficulty level', changeable: 1, value: 3, attCount: 4 },
      { name: 'friendly fire', changeable: 1, value: 0, attCount: 2 },
      { name: 'nightmare', changeable: 1, value: 0, attCount: 2 },
      { name: 'infinity', changeable: 0, value: 1, attCount: 2 }
    ],
    ff: 0, nm: 0, infinity: 1
  },
  { area: 7, label: 'default (any non-special area)', rulesFrom: 1 }
];

for (const row of AREA_TABLE) {
  const expected = row.rules ?? AREA_TABLE.find((other) => other.area === row.rulesFrom).rules;
  const flags = row.rules ? row : AREA_TABLE.find((other) => other.area === row.rulesFrom);

  test(`area ${row.area} (${row.label}) matches the RuleSet.java table`, () => {
    const rules = createRuleSet(row.area);
    assert.equal(rules.rulesCount, expected.length);
    expected.forEach((rule, nr) => {
      assert.equal(rules.ruleName(nr), rule.name, `rule ${nr} name`);
      assert.equal(rules.ruleChangeable(nr), rule.changeable, `rule ${nr} changeable`);
      assert.equal(rules.ruleValue(nr), rule.value, `rule ${nr} default value`);
      assert.equal(rules.attributeCount(nr), rule.attCount, `rule ${nr} attribute count`);
    });
    assert.deepEqual(rules.changeableMask(), expected.map((rule) => rule.changeable));
    assert.equal(rules.friendlyFire(), flags.ff);
    assert.equal(rules.nightmare(), flags.nm);
    assert.equal(rules.infinity(), flags.infinity);
    // The shared defaults: players 2 -> 4 players, wait 2 -> 10 min, diff 3.
    assert.equal(rules.numberOfPlayers(), 4);
    assert.equal(rules.waitTimeMinutes(), 10);
    assert.equal(rules.difficulty(), 3);
  });
}

test('value->meaning mappings match getNumberOfPlayers/getWaitTime', () => {
  const rules = createRuleSet(1);
  const players = [[0, 2], [1, 3], [2, 4]];
  for (const [value, expected] of players) {
    rules.setRuleValue(0, value);
    assert.equal(rules.numberOfPlayers(), expected);
  }
  const waits = [[0, 3], [1, 5], [2, 10], [3, 15], [4, 30]];
  for (const [value, expected] of waits) {
    rules.setRuleValue(1, value);
    assert.equal(rules.waitTimeMinutes(), expected);
  }
});

test('attribute names match ATTRDESCRIPT ("two players", "ten minutes", "very hard")', () => {
  const rules = createRuleSet(1);
  assert.equal(rules.attributeName(0, 0), 'two players');
  assert.equal(rules.attributeName(1, 2), 'ten minutes');
  assert.equal(rules.attributeName(2, 3), 'very hard');
});

test('reset restores the per-flavour values (RuleSet.java lines 294-310)', () => {
  // Area 5: ff/nm changeable - flip them on, drop infinity's neighbours, reset.
  const rules = createRuleSet(5);
  rules.setRuleValue(0, 0);
  rules.setRuleValue(3, 1);
  rules.setRuleValue(4, 1);
  rules.reset();
  assert.equal(rules.ruleValue(0), 2);
  assert.equal(rules.ruleValue(1), 2);
  assert.equal(rules.ruleValue(2), 3);
  assert.equal(rules.ruleValue(3), 0);   // ts reset: ff back to 0
  assert.equal(rules.ruleValue(4), 0);   // ts reset: nightmare back to 0
  assert.equal(rules.ruleValue(5), 1);   // ts reset: infinity stays 1

  const panic = createRuleSet(4);
  panic.setRuleValue(2, 0);
  panic.reset();
  assert.equal(panic.ruleValue(2), 3);
  assert.equal(panic.ruleValue(3), 1);   // pa reset: ff 1
  assert.equal(panic.ruleValue(4), 1);   // pa reset: nightmare 1
});

test('setRuleValue is bounds-checked but does NOT enforce the changeable mask', () => {
  const rules = createRuleSet(2);
  // Rule 3 (nightmare) is FIXED (changeable 0) - the reference's sendSetRule
  // still applies whatever the host sends, so this must be accepted.
  rules.setRuleValue(3, 0);
  assert.equal(rules.nightmare(), 0);
  // Out-of-table indices are refused - Java threw AIOOBE, we refuse cleanly.
  assert.throws(() => rules.setRuleValue(9, 0), RuleSetError);
  assert.throws(() => rules.setRuleValue(0, 3), RuleSetError);
  assert.throws(() => rules.ruleValue(6), RuleSetError);
  assert.throws(() => rules.attributeName(0, 3), RuleSetError);
});

test('ff/nightmare/infinity read the right rows per flavour (getters, lines 369-389)', () => {
  // Area 5: ff is row 3, nightmare row 4.
  const ts = new RuleSet(5);
  ts.setRuleValue(3, 1);
  ts.setRuleValue(4, 1);
  assert.equal(ts.friendlyFire(), 1);
  assert.equal(ts.nightmare(), 1);
  // Area 2: row 3 is NIGHTMARE - friendlyFire must NOT read it.
  const nm = new RuleSet(2);
  assert.equal(nm.ruleValue(3), 1);
  assert.equal(nm.friendlyFire(), 0);
  assert.equal(nm.nightmare(), 1);
});
