/**
 * The AREA DIRECTORY: the content of the op-0x48 reply, and nothing else.
 *
 * ## Why this is not a handler constant
 *
 * The op-0x48 records decide which of the ten Area-Select boxes light up, what
 * player count each one shows, and - through the key at record `+0x20` - which
 * box a later refresh resolves to and which area an ENTER asks for. That is
 * CONTENT. It belongs to an operator, exactly like `state/area-table.js`'s names
 * and descriptions, and burying it inside the handler that serialises it is how
 * a deployment ends up unable to change what it publishes without a code change.
 *
 * ## What the client actually does with each field
 *
 * `FUN_005c1220.c:18-48`, per record:
 *   - the LAST TWO ASCII characters of `name[16]` are parsed as a decimal id
 *     1..10 and select box 0..9. `"AREA0007"` is box 6. A name whose last two
 *     characters are not digits selects nothing and the record is wasted, so the
 *     constraint is enforced here rather than discovered on a rig.
 *   - `+0x10` -> the box's player count, and the SUM across all records is the
 *     "Server full" gate (`FUN_005bc990`, against the TCP-10127 `0x6504` max).
 *   - `+0x20` -> `0x6fec28 + box*0x24`, the key the ~25/s refresh looks the box up
 *     by (`FUN_005c70e0` -> `FUN_005bf280`, which returns -1 and DROPS the record
 *     on no match) and the value the ENTER request sends back
 *     (`FUN_005bfa70.c:19-24`).
 *
 * ## The V1 defect this exists to not repeat
 *
 * The archive session that rendered Area Select on real hardware shipped `+0x20`
 * = 0 for all ten records
 * (`captures/udp9090/2026_07_30_14_52_53_udp_192_0_2_248_2000.log:160`, sanitized; the
 * 392-byte reply: ten `"AREA00nn"` names followed by twenty zero bytes each).
 * With every key equal, `FUN_005bf280` matched box 0 for every one of them, so
 * all 1915 refreshes in that session resolved to the same box and the per-area
 * counts were structurally incapable of being real. Distinct non-zero keys are
 * therefore REQUIRED here, not merely preferred.
 */

/** Where the content came from. Stated by the caller, never inferred. */
export const AREA_DIRECTORY_PROVENANCE = Object.freeze({
  OPERATOR: 'operator',
  V1_OBSERVED: 'v1-observed',
  TEST_FIXTURE: 'test-fixture'
});

/**
 * Ten, because `FUN_005c1220` maps ids 1..10 onto ten boxes and the area table
 * the TCP half publishes holds ten records of stride 0x1e4. A different count is
 * untested against the client's fixed-size tables, so it is refused rather than
 * silently served - the same rule `state/area-table.js` states for its own count.
 */
export const AREA_DIRECTORY_BOX_COUNT = 10;

export class AreaDirectoryError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'AreaDirectoryError';
    this.code = code;
  }
}

function fail(code, message) {
  throw new AreaDirectoryError(code, message);
}

/**
 * One published area.
 *
 * `boxId` is 1..10 and is what the name's trailing digits must encode; it is
 * carried explicitly so the name and the box cannot disagree silently.
 */
function normalizeArea(area, index) {
  const where = `area ${index}`;
  if (area == null || typeof area !== 'object' || Array.isArray(area)) {
    fail('AREA_DIRECTORY_SHAPE', `${where} must be an object`);
  }
  const allowed = ['name', 'boxId', 'key'];
  const extra = Object.keys(area).filter((field) => !allowed.includes(field));
  if (extra.length > 0) {
    fail('AREA_DIRECTORY_SHAPE', `${where} has unsupported fields: ${extra.join(', ')}`);
  }
  if (typeof area.name !== 'string' || area.name.length === 0) {
    fail('AREA_DIRECTORY_NAME', `${where} needs a non-empty name`);
  }
  // 16 bytes INCLUDING the terminating NUL: the record field is `name[16]` raw
  // and `FUN_005c1220` calls strlen on it.
  if (Buffer.byteLength(area.name, 'latin1') >= 0x10) {
    fail(
      'AREA_DIRECTORY_NAME',
      `${where} name "${area.name}" does not fit the 16-byte record field with its NUL`
    );
  }
  const boxInRange = Number.isSafeInteger(area.boxId) &&
    area.boxId >= 1 && area.boxId <= AREA_DIRECTORY_BOX_COUNT;
  if (!boxInRange) {
    fail('AREA_DIRECTORY_BOX', `${where} boxId must be 1..${AREA_DIRECTORY_BOX_COUNT}`);
  }
  const trailingDigits = area.name.slice(-2);
  if (!/^[0-9]{2}$/.test(trailingDigits) || Number(trailingDigits) !== area.boxId) {
    fail(
      'AREA_DIRECTORY_NAME',
      `${where} name "${area.name}" must end in the two decimal digits of its box id ` +
      `(${String(area.boxId).padStart(2, '0')}); FUN_005c1220 reads name[strlen-2..strlen-1]`
    );
  }
  if (!Number.isSafeInteger(area.key) || area.key < 1 || area.key > 0xffffffff) {
    fail(
      'AREA_DIRECTORY_KEY',
      `${where} key must be a NON-ZERO uint32: zero matches the client's zeroed lookup table ` +
      'at 0x6fec28 and every refresh would resolve to box 0'
    );
  }
  return Object.freeze({ name: area.name, boxId: area.boxId, key: area.key });
}

/**
 * An immutable published area directory.
 *
 * Immutable because every session's op-0x48 reply must agree: the key at `+0x20`
 * has to be IDENTICAL across replies or the refresh poll stops resolving
 * (`FUN_005bf280` returns -1 and drops the record). Live player counts are
 * therefore passed in per reply rather than stored, so the mutable part cannot
 * accidentally be the part that must not change.
 */
export class AreaDirectory {
  #provenance;
  #areas;

  constructor({ provenance, areas } = {}) {
    if (!Object.values(AREA_DIRECTORY_PROVENANCE).includes(provenance)) {
      fail(
        'AREA_DIRECTORY_PROVENANCE',
        'provenance must be stated explicitly as operator, v1-observed, or test-fixture'
      );
    }
    if (!Array.isArray(areas) || areas.length !== AREA_DIRECTORY_BOX_COUNT) {
      fail(
        'AREA_DIRECTORY_COUNT',
        `a directory publishes exactly ${AREA_DIRECTORY_BOX_COUNT} areas; any other count is ` +
        "untested against the client's fixed box table"
      );
    }
    this.#provenance = provenance;
    this.#areas = Object.freeze(areas.map(normalizeArea));

    const seenBoxes = new Set();
    const seenKeys = new Set();
    for (const area of this.#areas) {
      if (seenBoxes.has(area.boxId)) {
        fail('AREA_DIRECTORY_BOX', `box ${area.boxId} is published twice`);
      }
      if (seenKeys.has(area.key)) {
        // Two areas sharing a key is V1's defect in miniature: the refresh would
        // resolve both to whichever box `FUN_005bf280` scanned first.
        fail('AREA_DIRECTORY_KEY', `key 0x${area.key.toString(16)} is published twice`);
      }
      seenBoxes.add(area.boxId);
      seenKeys.add(area.key);
    }
  }

  get provenance() {
    return this.#provenance;
  }

  get areaCount() {
    return this.#areas.length;
  }

  /** The published areas, box order. */
  areas() {
    return [...this.#areas];
  }

  /** The area a given `+0x20` key belongs to, or null. This is the ENTER lookup. */
  areaByKey(key) {
    return this.#areas.find((area) => area.key === key) ?? null;
  }

  /**
   * The area holding a given box, or null. The COUNT-PUSH lookup: a push
   * fabricates the `+0x20` key the client itself queried with (the wire field
   * the client's registry-A sweep `FUN_005bf280` matches on), so it needs the
   * key FOR a box rather than the box FOR a key.
   */
  areaByBox(boxId) {
    return this.#areas.find((area) => area.boxId === boxId) ?? null;
  }

  /**
   * The op-0x48 records for one reply.
   *
   * `playerCountFor(area)` supplies the live count. It is a function rather than
   * a stored number so that a directory cannot be half-updated: the identity
   * fields are frozen and the volatile field is fetched at send time.
   *
   * The sum is returned alongside because it is the "Server full" gate's left
   * operand (`FUN_005bc990`: sum >= `record[0]+0x12a` refuses the lobby), and the
   * right operand lives on the TCP-10127 side. The caller logs both so a refusal
   * is attributable instead of appearing as a mute stall.
   */
  records(playerCountFor = () => 0) {
    if (typeof playerCountFor !== 'function') {
      fail('AREA_DIRECTORY_COUNTS', 'playerCountFor must be a function');
    }
    let population = 0;
    const records = this.#areas.map((area) => {
      const count = playerCountFor(area);
      if (!Number.isSafeInteger(count) || count < 0 || count > 0xffff) {
        // 0xffff, not 0xffffffff: `FUN_005bc990` reads `lhu(rec+0x10)`, so only
        // the low half is ever summed and a larger number would be a lie.
        fail(
          'AREA_DIRECTORY_COUNTS',
          `player count for box ${area.boxId} must be 0..65535, not ${count}`
        );
      }
      population += count;
      return { name: area.name, playerCount: count, word1: 0, word2: 0, word3: 0, key: area.key };
    });
    return { records, population };
  }
}

/**
 * The ten areas V1 published, with the one thing V1 got wrong corrected.
 *
 * Names are byte-identical to the archive's 392-byte reply. The keys are NEW:
 * V1 sent zero for all ten and this ships the 1-based box id, which is the
 * smallest value that satisfies "distinct and non-zero". Nothing in the client
 * interprets the key - `FUN_005bf280` only compares it - so any distinct
 * non-zero set is equivalent, and the legible one is preferred.
 */
export function createV1ObservedAreaDirectory() {
  return new AreaDirectory({
    provenance: AREA_DIRECTORY_PROVENANCE.V1_OBSERVED,
    areas: Array.from({ length: AREA_DIRECTORY_BOX_COUNT }, (_unused, index) => ({
      name: `AREA00${String(index + 1).padStart(2, '0')}`,
      boxId: index + 1,
      key: index + 1
    }))
  });
}

/**
 * Parse an operator-authored directory document, the seam for `config/`.
 *
 * `key` is optional and defaults to the box id for exactly the reason above; it
 * is stated here rather than hidden as a fallback so that a document which omits
 * it still gets distinct non-zero keys instead of ten zeros.
 */
export function parseAreaDirectoryDocument(document, { source = 'area directory' } = {}) {
  if (document == null || typeof document !== 'object' || Array.isArray(document)) {
    fail('AREA_DIRECTORY_SHAPE', `${source} must be a JSON object`);
  }
  if (!Array.isArray(document.areas)) {
    fail('AREA_DIRECTORY_SHAPE', `${source} needs an "areas" array`);
  }
  return new AreaDirectory({
    provenance: document.provenance,
    areas: document.areas.map((area, index) => {
      if (area == null || typeof area !== 'object') {
        fail('AREA_DIRECTORY_SHAPE', `${source} area ${index} must be an object`);
      }
      return { name: area.name, boxId: area.boxId, key: area.key ?? area.boxId };
    })
  });
}
