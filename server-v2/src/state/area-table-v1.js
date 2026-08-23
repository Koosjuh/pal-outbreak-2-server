import {
  AREA_TABLE_OPTION_LABELS,
  AREA_TABLE_PROVENANCE,
  AREA_TABLE_RULE_SCREEN,
  AreaTable,
  V1_OBSERVED_LEAD_WORD
} from './area-table.js';

/**
 * The area table V1 served on the run that reached a rendered Area Select on
 * REAL PS2 HARDWARE - the only area table ever known to have worked.
 *
 * ## Provenance, exactly
 *
 * Decoded from `2026_07_30_14_52_53_snap_session5_trace.log` in
 * `C:\dnas\pi-evidence-archive\extracted\captures\`: the `0x6203` reply at
 * RAW-OUT #6 declares version `"OBAREA-V1"`, one chunk, length `0x1300`; RAW-OUT
 * #7..#13 carry that chunk in seven `0x6204` slices at offsets 0, 0x2f2, 0x5e4,
 * 0x8d6, 0xbc8, 0xeba and 0x11ac. Each slice is a `FUN_001c3f40` field whose
 * checksum verifies under its frame sequence and codec byte 0, so these strings
 * are DECODED plaintext, not a guess at ciphertext.
 * `test/area-table.test.js` re-derives the same bytes from the committed wire
 * fixture and asserts this module reproduces them exactly.
 *
 * ## What is carried verbatim rather than understood
 *
 * `unknownLeadWord` (`0x0000001f` in all ten records) and the 24-byte zero
 * trailer have no identified reader. They are reproduced because they were part
 * of the blob that rendered, and changing them would change a variable that was
 * never isolated.
 *
 * Two areas ship DISABLED - `"reserved"` and `"SECRET Area"` carry `+0x14c = 0`
 * where the other eight carry 3. That is V1's own choice, reproduced: it is the
 * direct evidence that `+0x14c` is the enable byte `FUN_005ad350.c:31` reads, and
 * inventing an eleventh state by enabling them would discard that control.
 *
 * ## Changing this content
 *
 * The version string is not decoration. `FUN_001c4960.c:46-49` compares it with
 * the client's cached copy at `0x36842c` and SKIPS the entire fetch when they
 * match, so any change to the content needs a new version or a console that
 * already cached the old blob in this power cycle will keep serving it.
 */
/**
 * ALL eleven mode ids the client can reach: bits 0..10 for ids 1..11.
 *
 * `FUN_005fe1e0` tests bit `i-1` while `i + 1 < 0xc`. Eleven is a CLIENT bound,
 * Confirmed. Which id means which rule is NOT known - see below.
 */
const ALL_MODES = 0x7ff;

/**
 * The per-area rule/mode masks. **CHOSEN SERVER POLICY, PENDING CLIENT VALIDATION.**
 *
 * Read `state/area-table.js` before changing any of these. The mechanism is
 * Confirmed; the values are not derived from anything and must never be recorded
 * as retail-accurate. Every one goes in `+0x18` (always-available) rather than
 * `+0x14` (progress-gated), because `+0x14` is ANDed with `(*(0x3424E8) >> 1)`,
 * which is player savedata and is all-but-empty on a FRESH profile - so a rule
 * placed there would not appear on a console that has never played.
 *
 * `+0x14` is therefore deliberately left ZERO everywhere. It is not "unused": it
 * is the field a progressed profile unlocks, and we have no evidence about which
 * modes belong behind progression. Shipping a guess there would make the visible
 * rule list differ between two consoles for reasons we could not explain.
 *
 * How the differentiation below was chosen, stated so it can be argued with:
 * each area's mask is drawn from the DESCRIPTION THIS SERVER PUBLISHES for it.
 * That is our own content, so this is self-consistency, not client evidence - an
 * area advertised as "Nightmare mode is ON by default" offering the whole rule
 * set would contradict its own row on screen. Free Area gets everything because
 * its published description is "Join games or create your own", and because a
 * fresh profile needs at least one area where every rule is reachable.
 *
 * Which bit is which rule is UNKNOWN, so the narrower masks are low contiguous
 * bits - the ids most likely to be the base modes - rather than a scatter that
 * would pretend to know which id is "friendly fire".
 */
/**
 * WITHHELD 2026-08-07, after review. Every mask below ships ZERO, which restores
 * the blob to the bytes the rig confirmed at `1576e09f`.
 *
 * The values above this line are the policy we WOULD publish. They are kept as
 * written, with their reasoning intact, because the argument for them is sound
 * and the moment `+0x18` is settled they become a one-line edit. What was not
 * sound was shipping them:
 *
 * 1. **They put a confirmed screen at risk for an unconfirmed value.** Eight of
 *    ten records would have carried non-zero at `+0x18` where the rig-confirmed
 *    build shipped zero, and the version tag was bumped to force every console to
 *    discard its cached copy and re-fetch. That is the maximum-blast-radius change
 *    to the one blob whose rendering we have actually observed working.
 *
 * 2. **The corpus disputes what `+0x18` IS.** `005baed0_record_get_dword_0x18` and
 *    `005bae80_record_get_dword_0x14` are filed under ROSTER, reached through
 *    `005bac60_get_record_table_base`, whose other callers are roster accessors;
 *    `menus/005fe1e0_build_scenario_ring` names them "per-profile available-scenario
 *    mask A" and "forced/override mask B", indexed by `bRam006c45f8` = PROFILE, and
 *    `roster/005f78c0_build_room_roster_slots` uses `FUN_005bae80` as a room member
 *    bitmask over table `0x6c3030` at stride `0x15c`. The area reading rests on
 *    `*(u32*)0x6C5480 == 0x368474` - the seated area blob - for which no evidence
 *    exists in this repo. Under `docs/CORPUS-METHODOLOGY.md` that is a discovery
 *    claim, and it is precisely the claim that would license the write.
 *
 * 3. **It contradicts itself.** If the corpus naming is right and `FUN_005fe1e0`
 *    builds the SCENARIO ring, then `+0x18 = 0x7ff` is a forced scenario override -
 *    which cannot coexist with our own finding that named scenarios are gated by
 *    player savedata at `0x341AD0` that no server message can write.
 *
 * The plumbing stays: the `AREA_TABLE_LAYOUT` offsets, `requireModeMask`, the BE32
 * writes and the per-area fields are all still here and still exercised. This is
 * configuration, so turning the rules on later is a constant change, not a rewrite.
 * Create-room does not depend on any of it.
 *
 * To settle it, resolve `*(u32*)0x6C5480` and confirm the index is area and not
 * profile. Until then these are zero.
 *
 * ---
 *
 * UPDATE 2026-08-07 - **premise (2) is now RESOLVED, in favour of the area
 * reading.** A review traced `*(u32*)0x6C5480` end to end:
 *
 * - `FUN_00606ea0.c:13-22` fills `0x6c5480[i] = *(0x3435d4) + i*0x1780` for i in
 *   0..2 - three banks inside one 0x8000 arena, NOT `0x368474`.
 * - `FUN_005ae8a0.c` state 1 arms `FUN_006188b0` via
 *   `FUN_00618800(*(0x3435d4) + 0x8000, 0x5aebf0)`.
 * - `FUN_006188b0.c:50` does `memcpy(iRam006fe8ec, uRam00368474, iRam0036846c)` -
 *   a copy of the downloaded `0x6204` blob (`uRam00368474 = 0x361a70`, set at
 *   `FUN_001c2f80.c:22`) - and publishes it as descriptor[0] at `0x6fe8f8`.
 * - `FUN_005aeb10.c:26-30` snapshots bank0 into bank1, then
 *   `memcpy(bank0, descriptor[0].src, descriptor[0].len)`.
 *
 * So `FUN_005bac60(0)` IS a copy of our area blob at stride 0x1e4, and the corpus'
 * ROSTER/PROFILE filing of `005bac60`/`005bae80`/`005baed0` is wrong. That means
 * the withholding was OVER-CAUTIOUS: `+0x18` almost certainly is the per-area
 * always-available mask after all.
 *
 * **They stay zero for this rig run anyway**, deliberately. The same trace is what
 * licenses `+0x34`, which now ships - so one change at a time on a blob whose
 * rendering is the only one we have ever confirmed. If Area Select still renders
 * with `+0x34` populated, the mechanism is validated by observation and these
 * become a one-line edit with far less risk than publishing both at once.
 */
/*
 * PUBLISHED 2026-08-08. The withholding above is now lifted, and the reason it was
 * lifted is recorded rather than the withholding text simply deleted.
 *
 * Both conditions that justified holding these at zero are met:
 *
 * 1. The disputed premise RESOLVED in favour of the area reading. The review
 *    traced `*(u32*)0x6C5480` end to end - `FUN_00606ea0.c:13-22` fills three
 *    banks from `*(0x3435d4)`; `FUN_006188b0.c:50` memcpys the downloaded 0x6204
 *    blob and publishes it as descriptor[0]; `FUN_005aeb10.c:26-30` copies that
 *    into bank 0. So `FUN_005bac60(0)` IS a copy of this blob at stride 0x1e4 and
 *    the corpus' ROSTER/PROFILE filing of those accessors is wrong.
 *
 * 2. The staged validation it was waiting on PASSED. The plan was "ship `+0x34`
 *    first, and if Area Select still renders, the mechanism is confirmed by
 *    observation". T37: every area row rendered its second line on a real PS2.
 *    That is the same accessor family reading the same record, so the addressing
 *    is now runtime-confirmed, which outranks the static dispute entirely.
 *
 * Holding them at zero after that was no longer caution, it was the reason the
 * rule list was empty - `FUN_005fe1e0` builds the selectable ring from
 * `((savedata >> 1) & rec[+0x14]) | rec[+0x18]`, and zero in both fields is an
 * empty ring no matter what else is right.
 *
 * The VALUES remain chosen server policy, exactly as documented above, and must
 * never be recorded as retail-accurate.
 */
const PUBLISHED = (mask) => mask;

const FREE_AREA_MODES = PUBLISHED(ALL_MODES);
/** A themed area: the base modes only, so its own advertised rule stands out. */
const THEMED_AREA_MODES = PUBLISHED(0x00f);
/** The scenario-set areas: a narrower base still, matching a fixed scenario run. */
const SCENARIO_AREA_MODES = PUBLISHED(0x003);
/** Everything, on the area whose published purpose is breaking things. */
const TESTING_AREA_MODES = PUBLISHED(ALL_MODES);
/** Disabled areas are unreachable (`+0x14c = 0`), so an empty ring is honest. */
const DISABLED_AREA_MODES = 0x000;

/*
 * SUPERSEDED 2026-08-09 when SNAP_RULE_MASKS_AUTHENTIC is ON (the default):
 * `docs/design/v2-port/RULES-MASK-RE.md` §1 established that `FUN_005fe1e0`
 * (`+0x14`/`+0x18`) builds the SCENARIO ring - row 8 of the create screen - not
 * the rule/mode list. The per-area narrowing above (0x00f, 0x003) was chosen
 * under the rule-mask belief; as scenario masks those values are arbitrary and
 * would hide most scenarios in six of the eight enabled areas. Until the
 * scenario id-to-title map is recovered (RULES-MASK-RE.md §8.1), every ENABLED
 * area serves the full 11-bit ring. The constants above still feed the
 * flag-OFF blob, byte-identically.
 */

/**
 * The create-screen RULE-ROW content served when SNAP_RULE_MASKS_AUTHENTIC is
 * ON - `RULES-MASK-RE.md` §6.2, the bioserver RuleSet mapped onto the PAL rows.
 *
 * The label-record indices are the client's OWN rule-label table
 * (`FUN_005c2e90(1)`, netwk-strings `0x8de20 + i*0x120`): 1 = Difficulty,
 * 2 = Friendly Fire, 5 = NIGHTMARE, 6 = INFINITY. Confirmed. The Difficulty
 * value 3 = VERY HARD is Confirmed (the string sits at record 1 `+0x80` =
 * entry 3). The `1`/`0` ON/OFF value bytes on the Friendly Fire / Nightmare /
 * Infinity rows are **Likely** (bioserver's `off, on` ordering; the choice
 * strings were too short for the string dump's filter): a wrong index renders
 * a blank value, never a crash - a cheap, visible falsifier.
 */
const DIFFICULTY = 1;
const FRIENDLY_FIRE = 2;
const NIGHTMARE = 5;
const INFINITY_RULE = 6;
const rule = (labelRecord, value, changeable) =>
  Object.freeze({ labelRecord, value, present: true, changeable });
/** bioserver's `difficulty level, changeable, VERY HARD` - on every area. */
const DIFFICULTY_ROW = rule(DIFFICULTY, 3, true);

/**
 * Per-area group-1 rows, in `V1_OBSERVED_AREAS` order. Plain areas carry only
 * the Difficulty row (three white rows total with players + waiting); the
 * themed areas 2..5 add the fixed rows bioserver marks `changeable = 0`, which
 * render RED with the value the area's own description advertises.
 */
const AREA_RULE_ROWS = Object.freeze([
  Object.freeze([DIFFICULTY_ROW]),                                    // Free Area
  Object.freeze([DIFFICULTY_ROW, rule(NIGHTMARE, 1, false)]),         // Nightmare: fixed ON
  Object.freeze([DIFFICULTY_ROW, rule(FRIENDLY_FIRE, 1, false)]),     // Survival: ff fixed ON
  Object.freeze([DIFFICULTY_ROW, rule(FRIENDLY_FIRE, 1, false),
    rule(NIGHTMARE, 1, false)]),                                      // Panic: both fixed ON
  Object.freeze([DIFFICULTY_ROW, rule(FRIENDLY_FIRE, 0, true),
    rule(NIGHTMARE, 0, true), rule(INFINITY_RULE, 1, false)]),        // Infinity: 6 rows total
  Object.freeze([DIFFICULTY_ROW]),                                    // reserved (disabled)
  Object.freeze([DIFFICULTY_ROW]),                                    // TESTING
  Object.freeze([DIFFICULTY_ROW]),                                    // Elimination
  Object.freeze([DIFFICULTY_ROW]),                                    // Showdown
  Object.freeze([DIFFICULTY_ROW])                                     // SECRET (disabled)
]);

/**
 * Common to every area under the flag (`RULES-MASK-RE.md` §6.2):
 * - `roomParameters` byte0 = 0xF3: present, CHANGEABLE, max 4, min 1,
 *   default 4 - "No. of Players" white, opening on "4". Confirmed layout.
 * - byte1 = 0xE2: present, CHANGEABLE, five choices, default index 2 =
 *   "10 minutes". Exact, not chosen: the client's DAT_00640530 is the
 *   PINE-read five-entry {3,5,10,15,30}-minute list, byte-identical to
 *   bioserver's getWaitTime(), whose default index is 2.
 * - castMask 0xFF: all eight base characters (rec+0x03 alone gates them).
 * - extraCastPermission 0xFF x16: permit any extra cast the SAVEDATA unlocked
 *   (the server can only permit, never grant).
 * - titleSettable + passwordSettable: rec+0x16b = 0x03.
 */
const RULE_SCREEN_ROOM_PARAMETERS = Object.freeze({
  maximumPlayers: 4,
  minimumPlayers: 1,
  playerCountChangeable: true,
  defaultPlayers: 4,
  waitingRow: Object.freeze({ changeable: true, choiceCount: 5, defaultChoice: 2 })
});
const RULE_SCREEN_CAST_MASK = 0xff;

const V1_OBSERVED_AREAS = [
  {
    name: 'Free Area',
    secondLine: 'All rules, your choice',
    description: 'Join games or create your own',
    enabled: true,
    alwaysAvailableModeMask: FREE_AREA_MODES
  },
  {
    name: 'Nightmare',
    secondLine: 'Nightmare ON',
    description: 'Nightmare mode is ON by default',
    enabled: true,
    alwaysAvailableModeMask: THEMED_AREA_MODES
  },
  {
    name: 'Survival',
    secondLine: 'Friendly Fire ON',
    description: 'Friendly Fire is ON by default',
    enabled: true,
    alwaysAvailableModeMask: THEMED_AREA_MODES
  },
  {
    name: 'Panic',
    secondLine: 'Nightmare + Fire',
    description: 'Nightmare mode and friendly fire is on!',
    enabled: true,
    alwaysAvailableModeMask: THEMED_AREA_MODES
  },
  {
    name: 'Infinity',
    secondLine: 'Infinite ammo, unranked',
    description: 'Infinite bullets. Not considered for rankings!',
    enabled: true,
    alwaysAvailableModeMask: THEMED_AREA_MODES
  },
  {
    name: 'reserved',
    secondLine: '',
    description: 'reserved',
    enabled: false,
    alwaysAvailableModeMask: DISABLED_AREA_MODES
  },
  {
    name: 'TESTING',
    secondLine: 'Unstable - may crash',
    description: 'For tests. Expect problems and crashes, use at your own risk',
    enabled: true,
    alwaysAvailableModeMask: TESTING_AREA_MODES
  },
  {
    name: 'Elimination',
    secondLine: 'Elimination 1-3',
    description: 'Play scenarios elimination 1-3',
    enabled: true,
    alwaysAvailableModeMask: SCENARIO_AREA_MODES
  },
  {
    name: 'Showdown',
    secondLine: 'Showdown 1-3',
    description: 'Play scenarios showdown 1-3',
    enabled: true,
    alwaysAvailableModeMask: SCENARIO_AREA_MODES
  },
  {
    name: 'SECRET Area',
    secondLine: '?????  Unranked',
    // Two spaces after the question marks, as V1 shipped it.
    description: '?????  Not considered for rankings!',
    enabled: false,
    alwaysAvailableModeMask: DISABLED_AREA_MODES
  }
];

/**
 * `OBAREA-V2`. The content genuinely changed, so the version MUST change with it.
 *
 * Every enabled area now carries a string at `+0x34`, which V1 left NUL because it
 * believed `+0x1c` was a 0x30-byte name field. `FUN_005affb0.c:97-99` renders
 * `+0x34` one line below the name, so V1 drew a blank second line on all ten rows -
 * the empty box. Both `+0x16c` room-parameter blocks changed too.
 *
 * Why the bump is load-bearing rather than cosmetic: `FUN_001c4960.c:46-49`
 * compares this against the client's cached copy at `0x36842c` and SKIPS the entire
 * `0x6204` fetch when they match. A console that cached the old table this power
 * cycle would keep it, and the change would look exactly like it had not landed.
 *
 * Nine characters, the same length as `OBAREA-V1`, which the declaration layout
 * depends on. **Whoever next changes a name, a second line, a description, an
 * enable byte, a mask or a room-parameter byte MUST bump this in the same commit.**
 *
 * SUPERSEDED, and recorded because the sequence matters: this was bumped to V2 once
 * before, to accompany non-zero `+0x18` mode masks; those masks were then withheld
 * and it went back to V1; now it is V2 again for a different and better-evidenced
 * reason. For one commit this docstring still said "V1, unchanged" while the export
 * below it read `OBAREA-V2` - a reader grepping the doc would have concluded the
 * wrong thing. Keep the prose and the constant in one place.
 */
export const V1_OBSERVED_AREA_TABLE_VERSION = 'OBAREA-V3';

/**
 * `OBAREA-V4`: the version served WITH the option-label table
 * (`SNAP_OPTION_LABELS`). A separate constant because the two blobs differ and
 * the client caches by version (`FUN_001c4960.c:46-49`): a console that fetched
 * V3 this power cycle must see a new string or it will keep rendering the
 * stale-memory option labels the table exists to blank. Same nine characters,
 * which the declaration layout depends on.
 */
export const OPTION_LABELS_AREA_TABLE_VERSION = 'OBAREA-V4';

/**
 * `OBAREA-V5`: the version served with the rule-screen bytes
 * (`SNAP_RULE_MASKS_AUTHENTIC`) and WITHOUT the option-label table. `OBAREA-V6`
 * is the fourth blob shape - both flags on - which exists only so the two flags
 * stay independent: the client caches by version string alone
 * (`FUN_001c4960.c:46-49`), so every distinct byte image MUST carry a distinct
 * string or a console that fetched one shape this power cycle silently keeps it.
 * Same nine characters, which the declaration layout depends on.
 */
export const RULE_MASKS_AREA_TABLE_VERSION = 'OBAREA-V5';
export const RULE_MASKS_OPTION_LABELS_AREA_TABLE_VERSION = 'OBAREA-V6';

/**
 * A fresh instance per call. Not a module-level singleton: a service owns the
 * table it serves, and two services in one process must be able to hold
 * different ones.
 *
 * `publishOptionLabelTable` (SNAP_OPTION_LABELS, `config.snapLobby`): when true
 * the blob carries the `+0x12fc` option-label table as eleven ZERO records -
 * every blit length byte 0, so the client draws BLANK where it previously drew
 * whatever stale bytes sat in its `0x361a70` buffer past our `0x1300` blob
 * ("Password: Impossible"-class garbage, owner-observed). Zero records, not
 * authored labels: no source for real label content is recovered and the entry
 * encoding (text vs. glyph tiles) is unproven - see AREA_TABLE_OPTION_LABELS
 * in `area-table.js`. False serves the byte-identical rig-confirmed V3 blob.
 */
/**
 * `publishAuthenticRuleMasks` (SNAP_RULE_MASKS_AUTHENTIC, `config.snapLobby`):
 * when true the blob carries the create-screen rule bytes of
 * `docs/design/v2-port/RULES-MASK-RE.md` §6.2 - both `+0x16c`/`+0x1a8` blocks
 * `F3 E2` + the per-area group-1 rows, `+0x16b = 0x03`, `+0x03 = 0xFF`,
 * `+0x04..0x13 = 0xFF`, and `+0x14`/`+0x18` = the full 0x7FF scenario ring on
 * enabled areas - under version OBAREA-V5 (V6 with the option-label table).
 * False serves the previous bytes identically. The two flags are independent:
 * either may be on without the other, and each pairing has its own version
 * string because the client caches by version alone.
 */
export function createV1ObservedAreaTable({
  publishOptionLabelTable = false,
  publishAuthenticRuleMasks = false
} = {}) {
  const version = publishAuthenticRuleMasks
    ? (publishOptionLabelTable
      ? RULE_MASKS_OPTION_LABELS_AREA_TABLE_VERSION
      : RULE_MASKS_AREA_TABLE_VERSION)
    : (publishOptionLabelTable
      ? OPTION_LABELS_AREA_TABLE_VERSION
      : V1_OBSERVED_AREA_TABLE_VERSION);
  return new AreaTable({
    version: Buffer.from(version, 'latin1'),
    optionLabels: publishOptionLabelTable
      ? { records: new Array(AREA_TABLE_OPTION_LABELS.maximumRecords).fill(null) }
      : null,
    provenance: AREA_TABLE_PROVENANCE.V1_OBSERVED,
    areas: V1_OBSERVED_AREAS.map((area, index) => ({
      name: Buffer.from(area.name, 'latin1'),
      secondLine: Buffer.from(area.secondLine, 'latin1'),
      description: Buffer.from(area.description, 'latin1'),
      enabled: area.enabled,
      unknownLeadWord: V1_OBSERVED_LEAD_WORD,
      ...(publishAuthenticRuleMasks ? {
        castMask: RULE_SCREEN_CAST_MASK,
        extraCastPermission: Buffer.alloc(
          AREA_TABLE_RULE_SCREEN.extraCastPermissionLength, 0xff
        ),
        titleSettable: true,
        passwordSettable: true,
        roomParameters: {
          ...RULE_SCREEN_ROOM_PARAMETERS,
          rules: AREA_RULE_ROWS[index]
        }
      } : {}),
      alwaysAvailableModeMask: publishAuthenticRuleMasks
        ? (area.enabled ? ALL_MODES : DISABLED_AREA_MODES)
        : area.alwaysAvailableModeMask,
      /*
       * THE SAME MASK, not zero. Corrected 2026-08-08.
       *
       * The old rule here - "everything belongs in +0x18, because +0x14 is ANDed
       * with player savedata and would be invisible on a fresh console" - is true
       * for `FUN_005fe1e0`, and ONLY for it. `FUN_005f78c0.c:47-62` builds the mode
       * button strip from `FUN_005bae80(area - 1)`, which is `+0x14` RAW: no
       * savedata AND, and `+0x18` is not consulted on that path at all.
       *
       * So a fresh console needs `+0x18` non-zero for the selectable rule ring AND
       * `+0x14` non-zero for the button strip. Publishing only one leaves the other
       * empty, which looks exactly like "rules still do not work".
       *
       * Both carry the same value because we have no evidence about which modes
       * belong behind progression - and inventing a split would make two consoles
       * differ for reasons we could not explain.
       *
       * Under SNAP_RULE_MASKS_AUTHENTIC both fields are the full 0x7FF SCENARIO
       * ring on enabled areas (RULES-MASK-RE.md §5: these are the Scenario row's
       * masks, `+0x18` un-gated, `+0x14` savedata-ANDed - and `+0x14` has the
       * savedata-free second reader `FUN_005f78c0`, so both are published).
       */
      progressGatedModeMask: publishAuthenticRuleMasks
        ? (area.enabled ? ALL_MODES : DISABLED_AREA_MODES)
        : area.alwaysAvailableModeMask
    }))
  });
}
