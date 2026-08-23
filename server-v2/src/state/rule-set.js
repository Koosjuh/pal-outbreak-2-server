/**
 * RULE SET: the per-room game rules, ported from bioserver `RuleSet.java`.
 * PORT-PLAN §A.1 row "RuleSet". Engine-side only - no new wire messages; the
 * rule browse/edit UI surface is owner-DEFERRED. The module exists so the
 * engine is complete: B1 needs difficulty / friendly-fire / nightmare /
 * infinity at game start.
 *
 * Reference oracle (Observation, code-read):
 * `references/bioserver/.../bioserv2/bioserver/RuleSet.java`. Everything below -
 * the per-area tables, the changeable flags, the value->meaning mappings, the
 * reset values - is copied from that file, quirks included:
 *
 * - Areas 2 (nightmare fixed on), 3 (friendly fire fixed on), 4 "panic"
 *   (ff+nightmare fixed on), 5 "infinity" (ff/nm selectable, infinity fixed
 *   on); every other area has only players / wait limit / difficulty
 *   (RuleSet.java constructor switch, lines 62-239).
 * - Rule 0 players: value 0/1/2 -> 2/3/4 max (getNumberOfPlayers, lines
 *   359-366). Rule 1 wait limit: 0..4 -> 3/5/10/15/30 minutes (getWaitTime,
 *   lines 348-357, default 30). Rule 2 difficulty: 0..3 = easy..very hard.
 * - Defaults everywhere: players=2 (four players), wait=2 (ten minutes),
 *   difficulty=3 (very hard).
 * - getFriendlyFire reads ruleset[3] only when ff/ts/pa (lines 369-372);
 *   getNightmare reads [3] for nm, [4] for ts/pa (lines 381-385); getInfinity
 *   reads [5] for ts only (lines 386-389).
 * - reset() (lines 294-310): players 2, wait 2, difficulty 3, then per flag:
 *   ff/nm -> [3]=1; pa -> [3]=1,[4]=1; ts -> [3]=0,[4]=0,[5]=1.
 *
 * The reference's `setRuleValue` does NOT check the changeable flag
 * (RuleSet.java lines 340-342; PacketHandler.sendSetRule applies whatever the
 * host sent). We mirror that: the mask is advertised, not enforced - enforcing
 * it here would refuse traffic the reference accepts. Bounds ARE checked,
 * because Java got an ArrayIndexOutOfBoundsException for free and we must not
 * let peer bytes index off a table.
 */

export class RuleSetError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'RuleSetError';
    this.code = code;
  }
}

function fail(code, message) {
  throw new RuleSetError(code, message);
}

const PLAYER_ATTRIBUTES = ['two players', 'three players', 'four players'];
const WAIT_ATTRIBUTES = [
  'three minutes', 'five minutes', 'ten minutes', 'fifteen minutes', 'thirty minutes'
];
const DIFFICULTY_ATTRIBUTES = ['easy', 'normal', 'hard', 'very hard'];
const ONOFF_ATTRIBUTES = ['off', 'on'];

// The three rules every area has, with the reference's default values.
const BASE_RULES = [
  { name: 'number of players', changeable: 1, value: 2, attributes: PLAYER_ATTRIBUTES },
  { name: 'wait limit', changeable: 1, value: 2, attributes: WAIT_ATTRIBUTES },
  { name: 'difficulty level', changeable: 1, value: 3, attributes: DIFFICULTY_ATTRIBUTES }
];

// area flavour -> extra rules + which flag drives ff/nm/infinity reads.
// Mirrors the RuleSet.java constructor switch exactly.
const AREA_FLAVOURS = new Map([
  [2, {
    flag: 'nm',
    extra: [{ name: 'nightmare', changeable: 0, value: 1, attributes: ONOFF_ATTRIBUTES }]
  }],
  [3, {
    flag: 'ff',
    extra: [{ name: 'friendly fire', changeable: 0, value: 1, attributes: ONOFF_ATTRIBUTES }]
  }],
  [4, {
    flag: 'pa',
    extra: [
      { name: 'friendly fire', changeable: 0, value: 1, attributes: ONOFF_ATTRIBUTES },
      { name: 'nightmare', changeable: 0, value: 1, attributes: ONOFF_ATTRIBUTES }
    ]
  }],
  [5, {
    flag: 'ts',
    extra: [
      { name: 'friendly fire', changeable: 1, value: 0, attributes: ONOFF_ATTRIBUTES },
      { name: 'nightmare', changeable: 1, value: 0, attributes: ONOFF_ATTRIBUTES },
      { name: 'infinity', changeable: 0, value: 1, attributes: ONOFF_ATTRIBUTES }
    ]
  }]
]);

export class RuleSet {
  #area;
  #flag;      // null | 'ff' | 'nm' | 'pa' | 'ts'
  #rules;     // [{ name, changeable, value, attributes }]

  constructor(area) {
    if (!Number.isSafeInteger(area) || area < 0) {
      fail('RULESET_AREA', `an area number must be a non-negative integer, not ${area}`);
    }
    const flavour = AREA_FLAVOURS.get(area) ?? { flag: null, extra: [] };
    this.#area = area;
    this.#flag = flavour.flag;
    this.#rules = [...BASE_RULES, ...flavour.extra].map((rule) => ({ ...rule }));
  }

  get area() {
    return this.#area;
  }

  /** RULESCOUNT: 3..6 depending on area. */
  get rulesCount() {
    return this.#rules.length;
  }

  #rule(rulenr) {
    if (!Number.isSafeInteger(rulenr) || rulenr < 0 || rulenr >= this.#rules.length) {
      fail('RULESET_RULENR', `rule ${rulenr} does not exist; this area has ${this.#rules.length}`);
    }
    return this.#rules[rulenr];
  }

  /** RULEATTCOUNT. */
  attributeCount(rulenr) {
    return this.#rule(rulenr).attributes.length;
  }

  /** RULEDESCRIPT. */
  ruleName(rulenr) {
    return this.#rule(rulenr).name;
  }

  /** RULEVALUE: the index into the attribute list. */
  ruleValue(rulenr) {
    return this.#rule(rulenr).value;
  }

  /** RULEATTRIB: 1 = player-changeable, 0 = fixed. */
  ruleChangeable(rulenr) {
    return this.#rule(rulenr).changeable;
  }

  /** ATTRDESCRIPT: the choice name for one attribute of one rule. */
  attributeName(rulenr, attnr) {
    const rule = this.#rule(rulenr);
    if (!Number.isSafeInteger(attnr) || attnr < 0 || attnr >= rule.attributes.length) {
      fail(
        'RULESET_ATTNR',
        `attribute ${attnr} does not exist; rule ${rulenr} has ${rule.attributes.length}`
      );
    }
    return rule.attributes[attnr];
  }

  /**
   * The changeable mask, one flag per rule in rule order. This is the
   * engine-side answer the area blob's rule masks are built from.
   */
  changeableMask() {
    return this.#rules.map((rule) => rule.changeable);
  }

  /**
   * SETRULE. Value is bounds-checked against the rule's attribute list; the
   * changeable flag is deliberately NOT enforced (see module docstring).
   */
  setRuleValue(rulenr, value) {
    const rule = this.#rule(rulenr);
    if (!Number.isSafeInteger(value) || value < 0 || value >= rule.attributes.length) {
      fail(
        'RULESET_VALUE',
        `value ${value} is outside rule ${rulenr}'s 0..${rule.attributes.length - 1}`
      );
    }
    rule.value = value;
    return this;
  }

  /** RuleSet.java reset(), lines 294-310, including the per-flag values. */
  reset() {
    this.#rules[0].value = 2;
    this.#rules[1].value = 2;
    this.#rules[2].value = 3;
    if (this.#flag === 'ff' || this.#flag === 'nm') {
      this.#rules[3].value = 1;
    } else if (this.#flag === 'pa') {
      this.#rules[3].value = 1;
      this.#rules[4].value = 1;
    } else if (this.#flag === 'ts') {
      this.#rules[3].value = 0;
      this.#rules[4].value = 0;
      this.#rules[5].value = 1;
    }
    return this;
  }

  /** getNumberOfPlayers: 0/1/2 -> 2/3/4, default 2. */
  numberOfPlayers() {
    switch (this.#rules[0].value) {
      case 0: return 2;
      case 1: return 3;
      case 2: return 4;
      default: return 2;
    }
  }

  /** getWaitTime, in minutes: 0..4 -> 3/5/10/15/30, default 30. */
  waitTimeMinutes() {
    switch (this.#rules[1].value) {
      case 0: return 3;
      case 1: return 5;
      case 2: return 10;
      case 3: return 15;
      case 4: return 30;
      default: return 30;
    }
  }

  /** getDifficulty: the raw value 0..3. */
  difficulty() {
    return this.#rules[2].value;
  }

  /** getFriendlyFire: ruleset[3] when ff/ts/pa, else 0. */
  friendlyFire() {
    if (this.#flag === 'ff' || this.#flag === 'ts' || this.#flag === 'pa') {
      return this.#rules[3].value;
    }
    return 0;
  }

  /** getNightmare: [3] when nm; [4] when ts/pa; else 0. */
  nightmare() {
    if (this.#flag === 'nm') return this.#rules[3].value;
    if (this.#flag === 'ts' || this.#flag === 'pa') return this.#rules[4].value;
    return 0;
  }

  /** getInfinity: [5] when ts, else 0. */
  infinity() {
    if (this.#flag === 'ts') return this.#rules[5].value;
    return 0;
  }
}

export function createRuleSet(area) {
  return new RuleSet(area);
}
