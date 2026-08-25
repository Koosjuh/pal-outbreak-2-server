/**
 * The AREA TABLE: the blob the client fetches with `0x6203` + `0x6204`, and the
 * only source of the ten Area-Select boxes' names, descriptions, and - the part
 * that decides whether the lobby is reachable at all - their enable byte.
 *
 * ## Why this exists as its own module
 *
 * Until 2026-08-06 V2 answered `0x6203` with mode 2. `FUN_001c4960.c:26-29` sends
 * mode 2 straight to substate `0x14`, so the client never issued a single
 * `0x6204`, its table at `0x361a70` stayed as it booted, and `FUN_005ad350.c:31`
 * - which refuses entry unless the selected area's `+0x14c` byte is 3 - could
 * never pass. Every Area-Select box was un-enterable no matter what the UDP half
 * did. Mode 1 plus a real blob is the fix, and the blob is CONTENT, so it lives
 * in state with a stated provenance rather than inside a protocol handler.
 *
 * ## The record layout, read off the bytes that rendered
 *
 * Recovered by decoding the seven `0x6204` replies of the V1 session that reached
 * a rendered Area Select on real PS2 hardware
 * (`C:\dnas\pi-evidence-archive\extracted\captures\2026_07_30_14_52_53_snap_session5_trace.log`,
 * RAW-OUT #7..#13, offsets 0 / 0x2f2 / 0x5e4 / 0x8d6 / 0xbc8 / 0xeba / 0x11ac).
 * Every slice's field checksum verifies under sequence + codec byte 0, so the
 * plaintext below is decoded evidence, not a reading of ciphertext.
 *
 * | offset | size | content in V1's blob | status |
 * |---|---|---|---|
 * | `+0x000` | 4 | BE32 `0x0000001f`, the same in all ten | **Unknown**; carried verbatim |
 * | `+0x004` | 0x10 | zero | Unknown; carried verbatim |
 * | `+0x014` | 4 | zero | **PROGRESS-GATED mode mask**; see below |
 * | `+0x018` | 4 | zero | **ALWAYS-AVAILABLE mode mask**; see below |
 * | `+0x01c` | **0x18** | NUL-padded name, e.g. `"Free Area"` | Observation - `FUN_005c0ff0.c:58` copies exactly 0x18 |
 * | `+0x034` | 0x18 | NUL-padded SECOND LINE, rendered under the name | Observation - `FUN_005affb0.c:97-99` at `y+0xe` |
 * | `+0x04c` | 0x100 | NUL-padded description | **plumbed to `0x6c38b9`, no reader found in any identified path** |
 * | `+0x16c` | 2 x 0x3c | room parameters: min/max players, time limit | Observation - `FUN_005c3490.c:69-105` |
 * | `+0x14c` | 1 | 3 for eight areas, 0 for two | Observation - `FUN_005ad350.c:31` gates entry |
 * | `+0x14d` | 0x1f | default room title + password, gated by `+0x16b` bits | PENDING; carried as zero |
 *
 * Ten records of stride `0x1e4` = `0x12e8`, then `0x18` zero bytes, totalling the
 * `0x1300` V1 declared. That closes gap-table U5, which asked why the declaration
 * was `0x1300` rather than `10 * 0x1e4`: it is a 24-byte zero trailer. What reads
 * it is still Unknown (`FUN_005c2ad0` returns a pointer 0x14 into it), so the
 * trailer is reproduced rather than dropped.
 *
 * The gap table records the enter gate as `+0x01`/`+0x02`. Those bytes are `0x00`
 * in the blob that rendered, so that reading is not corroborated here and this
 * module does not act on it; `+0x14c` is the byte with a named consumer.
 *
 * ## The rule/mode masks at `+0x14` and `+0x18` - MECHANISM confirmed, VALUES chosen
 *
 * `FUN_005fe1e0` builds the selectable rule ring from
 *
 *     mask = ((*(u32*)0x3424E8 >> 1) & rec[+0x14]) | rec[+0x18]
 *
 * testing bit `i-1` for `i` in `1..11` (`slti a1,12`). Accessors: `FUN_005bae80`
 * returns `+0x14`, `FUN_005baed0` returns `+0x18`, both through
 * `FUN_005bac60(0)` = `*(u32*)0x6C5480` at stride `0x1e4`, indexed by
 * `bRam006C45F8 - 1` - the AREA index. All Confirmed (`CORRECTIONS.md` C-6).
 *
 * `0x3424E8` is **player savedata**: it lies inside the `0x1474`-byte block at
 * `0x341AC0` that `FUN_001bc2a0`/`FUN_001bc4b0` copy whole to and from a save
 * buffer. So `+0x14` is PROGRESS-GATED and `+0x18` is ALWAYS-AVAILABLE, and
 * **anything that must work on a fresh console belongs in `+0x18`.** The earlier
 * claim that `*(0x3424E8) = 0x1E` is a build constant, and the shipping rule
 * "`+0x14` is ANDed with `0x0F` in this build", are both SUPERSEDED.
 *
 * V1 shipped both fields ZERO in all ten records, so `mask = 0`, so the ring was
 * empty and `obj+0x06` read back memset filler. That is the whole "rules cannot
 * be set" symptom, and it is a DATA problem, not a protocol one.
 *
 * **The values below are CHOSEN SERVER POLICY, PENDING CLIENT VALIDATION.** There
 * is no discovered source of truth for them: the client's `0x3C4D50` is a
 * scenario PROPERTY table indexed by id and never an area-to-mask map; the
 * `0x341AC0` block is player savedata; the corpus' `ENUMS.md` and `CONSTANTS.md`
 * are empty stubs and no `functions/menus/` or `functions/lobby/` record
 * enumerates the mode ids; BioServer is JP File#2 with no PAL area tier of this
 * shape; and every V1 capture only ever replayed the blob we ourselves authored,
 * so reading it back is circular. What is CONSTRAINED is only this: bit `i-1`
 * means mode id `i` for `i` in 1..11.
 *
 * They are therefore configuration, not protocol code, and they are labelled so
 * that no later reader mistakes them for a finding.
 *
 * ## What this module does NOT claim
 *
 * - That ten is a protocol constant. It is the count V1 shipped and the count the
 *   op-0x48 reply names (`AREA0001".."AREA0010"`). A different count is untested,
 *   so it is refused rather than silently served.
 * - Any meaning for `unknownLeadWord` or the trailer.
 * - That `+0x4c` is DEAD. It is plumbed end to end (`FUN_005c0ff0.c:60` ->
 *   `FUN_005bfa20` -> `0x6c38b9 + i*0x15c`) and no reader was found in 1929
 *   decompiled overlay functions, nor in the three Area Select widget callbacks
 *   Ghidra never defined (all three read by raw disassembly of `netwk.bin`: two
 *   are sprite/animation, the third is the screen title). That supports **"not
 *   rendered in any identified path"** - Likely - and NOT "nothing renders it",
 *   which would be an absence claim `docs/CORPUS-METHODOLOGY.md` forbids on sweep
 *   evidence. Cheapest falsifier: a PINE watch on `0x6c38b9 + i*0x15c` during live
 *   Area Select navigation, since runtime observation outranks any static sweep.
 */

/** Where the content came from. Stated by the document, never inferred. */
export const AREA_TABLE_PROVENANCE = Object.freeze({
  OPERATOR: 'operator',
  V1_OBSERVED: 'v1-observed',
  TEST_FIXTURE: 'test-fixture'
});

export const AREA_TABLE_LAYOUT = Object.freeze({
  /** `FUN_005c2a40` indexes `0x368474 + i * 0x1e4`; V1's blob holds ten. */
  areaCount: 10,
  recordStride: 0x1e4,
  unknownLeadWordOffset: 0x00,
  /** `FUN_005bae80`: ANDed with `(*(0x3424E8) >> 1)`, which is player savedata. */
  progressGatedModeMaskOffset: 0x14,
  /** `FUN_005baed0`: ORed in un-gated. The only masks a FRESH profile ever sees. */
  alwaysAvailableModeMaskOffset: 0x18,
  /** `FUN_005fe1e0` tests bit `i-1` for `i` in 1..11, so bits 11..31 are dead. */
  modeMaskBits: 11,
  nameOffset: 0x1c,
  /**
   * `0x18`, NOT `0x30`. CORRECTED 2026-08-07.
   *
   * SUPERSEDED: this was `0x30` (`0x4c - 0x1c`), inferred from the gap between the
   * name and the description in V1's captured blob. Nothing read the gap, so the
   * inference was never tested - and it was wrong. `FUN_005c2a70` is the accessor,
   * and `FUN_005c0ff0.c:58` copies from it with `memcpy(dst, rec + 0x1c, 0x18)`.
   * The client takes **twenty-four** bytes. The remaining `0x18` is a field of its
   * own at `+0x34`; see `secondLineOffset`.
   *
   * Every name this server ships is well under `0x18` characters, so narrowing the
   * field changes no rendered name - which is why the rig confirmed Area Select
   * with the wrong length. The cost was not a broken name, it was a swallowed
   * field.
   */
  nameFieldLength: 0x18,
  /**
   * The SECOND text line drawn on every Area Select row - the blank the owner saw.
   *
   * Verified by direct read of the corpus rather than relayed: `FUN_005bb060`
   * returns `FUN_005bac60(0) + (index & 0xffff) * 0x1e4 + 0x34`, and
   * `FUN_005affb0.c:97-99` calls
   *   `FUN_005af1e0(x, y, 0, index * 0x15c + 0x6c3878)`   // the NAME, via the UI model
   *   `FUN_005af1e0(x, y + 0xe, 0, FUN_005bb060())`       // THIS, straight from the bank
   * so it renders one line - `0xe` pixels - directly below the name.
   *
   * Note the asymmetry, because it is the reason this was missed: the name is read
   * from the UI model at `0x6c3878` while this is read from the area record itself.
   * A field that never enters the UI model is invisible to any search that starts
   * from the model.
   *
   * `FUN_005bb0b0` also `strcmp`s it when deciding whether the downloaded table
   * differs from the seated one - one of only eight fields in the record it
   * considers identity-bearing. It is not decoration.
   *
   * It has a second reader at `FUN_005ba5b0.c:52`.
   */
  secondLineOffset: 0x34,
  /** `0x4c - 0x34`. NUL-terminated, like the name. */
  secondLineFieldLength: 0x18,
  descriptionOffset: 0x4c,
  /** `0x14c - 0x4c`, likewise NUL-terminated. */
  descriptionFieldLength: 0x100,
  /**
   * The ROOM-PARAMETER block: two copies of `0x3c` bytes at `+0x16c` and `+0x1a8`.
   *
   * On the critical path, which is why it is here and not in the pending pile: we
   * ship these bytes as ZERO, and `FUN_005c3490.c:88` reads max players out of
   * them at `:89` as `(byte0 >> 4 & 3) + 1`. Zero means **a maximum of one player per
   * room** - nobody can ever join anybody.
   *
   * Field semantics CONFIRMED by direct read of `FUN_005c3490.c:69-105`:
   *   uVar10 = byte0 >> 2 & 3   ->  cRam007006a4 = uVar10 + 1   // MIN players
   *   uVar9  = byte0 >> 4 & 3   ->  cRam007006a5 = uVar9  + 1   // MAX players
   *   uVar10 = byte1 & 0x3f     ->  uRam007006a6 = uVar10
   *                                 iRam006febf0 = uVar10 * 300 // ticks
   * Two bits each, so min and max are 1..4 - which is the game's own party size.
   *
   * `bRam007006a4` (min) is read by `FUN_005be330.c:48`, the rule that unlocks
   * scenario and character selection: for the branch that needs it, selection
   * stays LOCKED until the room holds at least min players AND `uRam007006a6` is
   * non-zero. Both are zero in our blob today, so that unlock can never fire.
   *
   * WHICH BLOCK IS USED IS NOT RECOVERED, and writing both does NOT fully close
   * the question. CORRECTED 2026-08-07 - the earlier version of this comment
   * claimed it did, and that was wrong in a way that could misread a rig result.
   *
   * `FUN_005c4f00()`'s return is used TWICE: once as the block index
   * (`FUN_005c3490.c:65`) and once as a BRANCH selector (`:71`, `:93`, and again
   * in `FUN_005be330.c:36`). Writing both blocks identically neutralises the block
   * choice only. It does not neutralise the branch:
   *
   * - returns non-zero: `:89` stores max, `:88` stores min, `:103-105` store the
   *   time-limit unit. Our bytes bind. This is the path this field targets.
   * - returns 0: the min/max stores are SKIPPED entirely and `uRam007006a6` stays
   *   0 from `:92`. Our counts are simply not published. (`FUN_005be330.c:36-45`
   *   unlocks unconditionally there, so selection is not blocked on that branch -
   *   but neither is the party size raised.) Note `:96-100` reads `byte1 & 7` as
   *   an INDEX into the client's `DAT_00640530`; we moved that index 0 -> 1, and
   *   `DAT_00640530` could not be read, so the countdown length on that branch is
   *   an unquantified side effect.
   * - returns -1: `FUN_005c2ae0(i, 0xffff)` reads at `rec + 0x3BFC4 + 0x16c`, far
   *   outside the record. Pre-existing, not a regression, and not covered by
   *   "both blocks" either.
   *
   * The mining claim ("area 1 -> block 0, areas 2..10 -> block 1") is NOT refuted -
   * only unexplained. `FUN_005c4f00` returns 0 for `bRam006ce5cf == 1`, 1 for
   * `>= 2` and -1 for `0`, which maps EXACTLY onto that claim if `bRam006ce5cf`
   * holds the 1-based area index. What is established is the mechanism; whether it
   * carries the area index is **Unknown**. Calling it "refuted" was an absence
   * claim of exactly the kind `docs/CORPUS-METHODOLOGY.md` forbids on this
   * evidence, and it is corrected here rather than quietly reworded.
   *
   * **Consequence for testing, and it matters:** if `bRam006ce5cf` does track the
   * area, then Free Area - the first box, the one anyone tests first - is the
   * selector-0 branch and gets no party size from these bytes. A "still cannot
   * join in Free Area" result would be a FALSE NEGATIVE on this field. Test a
   * non-first area, or read `bRam006ce5cf` over PINE before concluding anything.
   *
   * The rest of the block - `+0x02` and `+0x2b` variable-parameter list counts and
   * their entries, which index a `0x120`-stride label table in the blob trailer -
   * is PENDING. It drives room-parameter UI rows, not whether a game can start.
   */
  roomParameterBlockOffset: 0x16c,
  roomParameterBlockLength: 0x3c,
  roomParameterBlockCount: 2,
  /** `FUN_005ad350.c:31` refuses entry unless this byte is `enabledValue`. */
  enableOffset: 0x14c,
  enabledValue: 3,
  disabledValue: 0,
  /** V1 declared 0x1300, which is `10 * 0x1e4` plus this. Consumer Unknown. */
  trailerLength: 0x18
});

/**
 * The OPTION-LABEL record table in the blob trailer - the `+0x12fc` sub-table.
 *
 * WHAT IS ESTABLISHED (Observation, raw decompile):
 * - `FUN_005c2ad0` returns `blobBase + 0x12fc` (`iRam00368474 + 0x12fc`,
 *   corpus `functions/lobby/005c2ad0_scenario_table_extra_ptr.md`).
 * - `FUN_005c3c40` (sole caller `FUN_005c3b10`) reads records off that pointer
 *   at stride `0x120`: for each 4-byte field descriptor `{recordIndex, literal,
 *   isVariable, ?}` it copies `record[0x1e]` bytes from
 *   `record + 0x3e + value*0x20` to `dst + record[0x1d]`. So a record is:
 *   `+0x1d` u8 destination offset, `+0x1e` u8 blit length, `+0x3e` an array of
 *   `0x20`-byte entries indexed by the field's value. Bytes `+0x00..+0x1c` and
 *   `+0x1f..+0x3d` have no identified reader.
 * - The blit destination buffer and what the `0x20`-byte entries MEAN (glyph
 *   tiles vs. text) are NOT established - corpus grades the block layout
 *   Unknown. `analysis/SELECTION-DATA-MODEL.md`, which the 2026-08-08 handoff
 *   cites for the full structure, is not in the repository.
 *
 * WHY SERVING THE REGION AT ALL IS CORRECT even without content: the client's
 * chunk-0 destination is the STATIC buffer `0x361a70` (`FUN_001c2f80.c:22`,
 * `uRam00368474 = 0x361a70`; chunk 1's buffer is `0x363a70`, exactly `0x2000`
 * later, matching the `FUN_001c4960.c:76` per-chunk clamp of `0x2000`). Our
 * blob ends at `0x1300`, so every option-label read - record 0's own length
 * byte sits at `+0x131a` - lands in bytes of that buffer the download never
 * wrote: stale memory, rendered as the "Password: Impossible"-class garbage
 * the owner reported. Serving ZEROS for the region makes every blit
 * zero-length (`record[0x1e] == 0` copies nothing), which turns garbage into
 * blank. Zero is also the only value with precedent: it is what V1 shipped
 * for every byte it did not name.
 *
 * REAL LABEL CONTENT IS DELIBERATELY NOT AUTHORED HERE. There is no recovered
 * source for it (the retail blob lived on Capcom's server; every V1 capture
 * replays our own bytes; BioServer serves rule labels as query text, not as
 * this table), and whether entries are text or pixel tiles is unproven -
 * authored ASCII into a tile table would render as noise. An operator document
 * may supply record bytes once the structure is recovered.
 */
export const AREA_TABLE_OPTION_LABELS = Object.freeze({
  /** `FUN_005c2ad0`: the table's offset from the blob base. */
  tableOffset: 0x12fc,
  /** `FUN_005c3c40`: `table + descriptor[0] * 0x120`. */
  recordStride: 0x120,
  /** `record[0x1d]`: destination offset of the blit. */
  destinationOffsetByte: 0x1d,
  /** `record[0x1e]`: bytes copied per blit (0 = blit nothing). */
  entryLengthByte: 0x1e,
  /** `record + 0x3e + value*0x20`: the value-indexed entry array. */
  entriesOffset: 0x3e,
  entryStride: 0x20,
  /** `0x3e + 7*0x20 = 0x11e <= 0x120`: entries past 7 would overlap the next record. */
  maximumEntriesPerRecord: 7,
  /**
   * `0x12fc + 11*0x120 = 0x1f5c <= 0x2000`, the client's static chunk-0 buffer
   * (and its own per-chunk clamp). A twelfth record cannot be served whole.
   */
  maximumRecords: 11
});

/**
 * The CREATE-ROOM RULE-SCREEN fields (`docs/design/v2-port/RULES-MASK-RE.md`) -
 * every red/white decision on that screen is one served byte in this record.
 *
 * Mechanism grades, per that document:
 * - Block byte0/byte1 bit layouts: **Confirmed** (`FUN_005c2bc0:17775-17795`).
 *   byte0: b7 row present, b6 CHANGEABLE (white), b5-4 max index, b3-2 min
 *   index, b1-0 default index. byte1: b7 present, b6 changeable, b5-3
 *   choiceCount-1, b2-0 default index.
 * - Group-1 rows: count at block `+0x02`, 4-byte descriptors at `+0x03`
 *   (`FUN_005c2f40:17911-17931`), each `{labelRecordIndex, value, present,
 *   changeable}` (`FUN_005c2d70:17813-17846`). The label records are
 *   CLIENT-LOCAL (`FUN_005c2e90(1)`, 16 records in netwk-strings at
 *   `0x8de20 + i*0x120`): the server only picks which appear, their initial
 *   value, and whether they are white. **Confirmed.**
 * - `rec+0x16b`: bit0 = Room Title settable, bit1 = Password settable
 *   (`FUN_005c2f40:17941-17945` -> `FUN_005fcc70:49601-49660`). **Confirmed.**
 * - `rec+0x03`: the 8-bit base-CAST mask, gated by this byte ALONE - no
 *   savedata term (`FUN_005fe300` via `FUN_005baf20`). **Confirmed.** The old
 *   "5 male characters only" symptom was the BE32 lead word `0x0000001F`
 *   leaking its low byte into `+0x03`.
 * - `rec+0x04..0x13`: a 128-bit extra-cast PERMISSION bitmap, ANDed with
 *   player savedata `0x341ad0` (`FUN_005baf70`). The server can only permit,
 *   never grant. **Confirmed.**
 *
 * NOTE the sibling decode conflict (RULES-MASK-RE.md §7): `FUN_005c3490`'s
 * branch for `FUN_005c4f00() != 0` reads byte1 as `& 0x3f` ticks-unit, which
 * no byte can satisfy simultaneously with the row decode. Unresolved; both
 * `+0x16c` and `+0x1a8` blocks are written identically so the block CHOICE is
 * neutralised, and the discriminating PINE read (`bRam006ce5cf` at the create
 * screen) is the pending falsifier.
 */
export const AREA_TABLE_RULE_SCREEN = Object.freeze({
  /** `FUN_005baf20` returns `*(u8*)(rec + 0x03)`: one bit per base character. */
  castMaskOffset: 0x03,
  /** `FUN_005baf70` returns `rec + 0x04`: the 128-bit extra-cast permission. */
  extraCastPermissionOffset: 0x04,
  extraCastPermissionLength: 0x10,
  /** `FUN_005c2b20`/`FUN_005c2b90`: bit0 title, bit1 password. */
  titlePasswordOffset: 0x16b,
  /** Within a `+0x16c`/`+0x1a8` block: `FUN_005c2f40:17911` reads the count here. */
  groupOneCountOffset: 0x02,
  /** ... and the 4-byte descriptors from here. */
  groupOneDescriptorsOffset: 0x03,
  descriptorStride: 4,
  /**
   * `FUN_005c2f40` clamps group-1 to 10 descriptors; 10 also ends exactly at
   * block `+0x2b`, the group-2 count byte, so an eleventh would overwrite it.
   */
  maximumGroupOneRules: 10,
  /** The client-local rule-label table holds 16 records (netwk-strings 0x8de20..0x8ef00). */
  maximumLabelRecordIndex: 15,
  /** A label record holds 8 entries; a value past that renders blank. */
  maximumChoiceIndex: 7,
  /** byte1 b5-3 store choiceCount-1, so 8 is the ceiling. */
  maximumWaitingChoices: 8
});

export const AREA_TABLE_TRANSFER = Object.freeze({
  /**
   * `FUN_001c4960.c:65-67` clamps the declared chunk count to 2 and treats 0 as
   * terminal. V2 declares ONE: chunk index 1 has a second destination pointer at
   * `0x368474 + 4` whose consumer is Unknown, and V1 never declared it.
   */
  declaredChunkCount: 1,
  maximumChunkCount: 2,
  /**
   * The CLIENT's own guard (`FUN_001c4960.c:76`) is 0x2000 — but the receiving
   * BANK is smaller: `FUN_005aeb10` memcpys the declared blob length into bank 0
   * whose usable size is 0x1780 (the bank-1 snapshot copies 0x177c; banks are
   * `0x17bb & ~0x3f` apart, FUN_00606ea0). A blob in (0x1780, 0x2000] passes the
   * client check and silently scribbles over bank 1 — e.g. option labels ON
   * would be 0x1F5C. Tightened 0x2000 → 0x1780 on the 2026-08-24 trace
   * (analysis/area-table-scenario-mask-LE-2026-08-24.md §6).
   */
  maximumChunkLength: 0x1780,
  /**
   * `FUN_001c4c80.c:11` writes 0x2f2 as the request's length word, and
   * `FUN_001c4d40.c:31` advances the client's cursor by exactly 0x2f2 whatever
   * the reply carried - so a short non-final slice would leave a hole in the
   * blob. Non-final slices are therefore exactly this long.
   */
  sliceLength: 0x2f2,
  /** `FUN_001c4960.c:32` decodes the version field with bound `0x1f`. */
  maximumVersionLength: 0x1f
});

export class AreaTableError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'AreaTableError';
    this.code = code;
  }
}

function fail(code, message) {
  throw new AreaTableError(code, message);
}

/**
 * The `+0x16c` room-parameter bytes, packed in exactly one place.
 *
 * STRUCTURE is Confirmed (`FUN_005c3490.c:69-105`, read directly). VALUES are
 * chosen server policy and are labelled as such at the call site - there is no
 * recovered source for them, because the retail blob lived on Capcom's server and
 * the client caps it at two downloaded sub-blobs of 0x2000.
 *
 * The defaults exist because the alternative is worse: an area that omits this
 * gets the all-zero bytes, and all-zero decodes to a maximum of ONE player. A
 * silent default of "nobody can join" is not a safe default, so the safe party
 * size is the default and an area must opt OUT deliberately.
 */
function normalizeRoomParameters(value, where) {
  const source = value ?? {};
  if (typeof source !== 'object' || Array.isArray(source)) {
    fail('AREA_TABLE_FIELD_TYPE', `${where} roomParameters must be an object`);
  }
  /*
   * The explicit opt-OUT, and the only way to get V1's all-zero bytes.
   *
   * It exists for two callers: the archived-blob fixtures, which must be able to
   * reproduce exactly what V1 shipped, and any future area that genuinely wants
   * the client falling back to its own `DAT_00640528` tables. It is deliberately
   * verbose rather than `roomParameters: null`, because "no room parameters"
   * decodes to a one-player maximum and nobody should be able to select that by
   * writing nothing.
   */
  if (source.published === false) {
    return Object.freeze({
      published: false,
      maximumPlayers: 1, minimumPlayers: 1, timeLimitUnit: 0,
      playerCountByte: 0, timeLimitByte: 0, rules: null
    });
  }
  const {
    // Four: the game's own party size, and the ceiling two bits can express.
    maximumPlayers = 4,
    // One, so a host alone satisfies FUN_005be330's member test and selection can
    // unlock. Raising this delays the unlock until that many players are present.
    minimumPlayers = 1,
    playerCountSelectable = true,
    /*
     * byte0 bit 6, the row's WHITE bit (RULES-MASK-RE.md §2.2, Confirmed): 1 lets
     * the cursor land on "No. of Players" and left/right change it; anything
     * else renders it colour 2 and skips it. Default false = the byte the rig
     * confirmed (0xB0), so a caller that says nothing changes nothing.
     */
    playerCountChangeable = false,
    /*
     * byte0 bits 1-0, the default index the row opens on (the stored index is
     * absolute - players-1 - and the row's initial value is default-min,
     * RULES-MASK-RE.md §2.3). Defaults to the minimum, which encodes the 0
     * bits the rig-confirmed byte carried.
     */
    defaultPlayers = minimumPlayers,
    // Non-zero because FUN_005be330 requires uRam007006a6 != 0 on the branch that
    // gates selection: a zero here leaves scenario and cast LOCKED forever. The
    // magnitude is the retry period (unit * 300 ticks = unit * 5 s at 60 Hz), not
    // a match length, so the smallest useful value is the right one.
    timeLimitUnit = 1,
    difficultySelectable = true,
    /*
     * The Waiting Time row under its ROW decode - `FUN_005c2bc0:17775-17795`,
     * Confirmed: b7 present, b6 changeable, b5-3 choiceCount-1, b2-0 default
     * index into the client's own five-entry list {3,5,10,15,30} minutes
     * (`DAT_00640530`, PINE-read). When null, byte1 keeps the legacy
     * `timeLimitUnit` encoding - the rig-confirmed 0x81 - which under the row
     * decode is a 1-choice row whose value index is out of range (the blank
     * Waiting Time row on the create screen, RULES-MASK-RE.md §2.6). The two
     * decodes are the §7 conflict; this field serves the row decode.
     */
    waitingRow = null,
    /*
     * Group-1 rule rows: `{labelRecord, value, present, changeable}` each, the
     * byte-for-byte image of bioserver's `Rule(name, changeable, value)`.
     * `present: false` keeps the parameter with the literal value but draws no
     * row; `changeable: false` draws it red. Null = no group-1 rows at all,
     * the rig-confirmed zero bytes.
     */
    rules = null
  } = source;

  for (const [name, count] of [['maximumPlayers', maximumPlayers], ['minimumPlayers', minimumPlayers]]) {
    if (!Number.isSafeInteger(count) || count < 1 || count > 4) {
      fail('AREA_TABLE_FIELD_VALUE',
        `${where} ${name} must be 1..4: it is stored in TWO bits as the value minus one ` +
        '(FUN_005c3490.c:88), so anything else silently wraps');
    }
  }
  if (minimumPlayers > maximumPlayers) {
    fail('AREA_TABLE_FIELD_VALUE',
      `${where} minimumPlayers ${minimumPlayers} exceeds maximumPlayers ${maximumPlayers}: ` +
      'FUN_005be330 would never unlock selection, because the member count can never reach it');
  }
  if (!Number.isSafeInteger(timeLimitUnit) || timeLimitUnit < 0 || timeLimitUnit > 0x3f) {
    fail('AREA_TABLE_FIELD_VALUE',
      `${where} timeLimitUnit must be 0..0x3f: the client reads byte1 & 0x3f`);
  }
  if (typeof playerCountChangeable !== 'boolean') {
    fail('AREA_TABLE_FIELD_VALUE', `${where} playerCountChangeable must be a boolean`);
  }
  if (!Number.isSafeInteger(defaultPlayers) ||
      defaultPlayers < minimumPlayers || defaultPlayers > maximumPlayers) {
    fail('AREA_TABLE_FIELD_VALUE',
      `${where} defaultPlayers must lie in ${minimumPlayers}..${maximumPlayers}: the row's ` +
      'choices are the label list sliced [min..max] and an out-of-range default renders blank');
  }

  let waiting = null;
  if (waitingRow != null) {
    if (typeof waitingRow !== 'object' || Array.isArray(waitingRow)) {
      fail('AREA_TABLE_FIELD_TYPE', `${where} waitingRow must be an object`);
    }
    const { changeable = false, choiceCount, defaultChoice } = waitingRow;
    if (typeof changeable !== 'boolean') {
      fail('AREA_TABLE_FIELD_VALUE', `${where} waitingRow.changeable must be a boolean`);
    }
    if (!Number.isSafeInteger(choiceCount) || choiceCount < 1 ||
        choiceCount > AREA_TABLE_RULE_SCREEN.maximumWaitingChoices) {
      fail('AREA_TABLE_FIELD_VALUE',
        `${where} waitingRow.choiceCount must be 1..${AREA_TABLE_RULE_SCREEN.maximumWaitingChoices}: ` +
        'byte1 bits 5-3 store choiceCount-1');
    }
    if (!Number.isSafeInteger(defaultChoice) || defaultChoice < 0 || defaultChoice >= choiceCount) {
      fail('AREA_TABLE_FIELD_VALUE',
        `${where} waitingRow.defaultChoice must be 0..${choiceCount - 1}: an index past the ` +
        'choice list renders a BLANK value - the exact defect the legacy byte produced');
    }
    waiting = { changeable, choiceCount, defaultChoice };
  }

  let ruleRows = null;
  if (rules != null) {
    if (!Array.isArray(rules) || rules.length < 1 ||
        rules.length > AREA_TABLE_RULE_SCREEN.maximumGroupOneRules) {
      fail('AREA_TABLE_FIELD_VALUE',
        `${where} rules must hold 1..${AREA_TABLE_RULE_SCREEN.maximumGroupOneRules} rows: ` +
        'FUN_005c2f40 clamps group-1 at 10, and an 11th descriptor would overwrite the ' +
        'group-2 count byte at block +0x2b');
    }
    ruleRows = Object.freeze(rules.map((rule, index) => {
      const at = `${where} rules[${index}]`;
      if (rule == null || typeof rule !== 'object' || Array.isArray(rule)) {
        fail('AREA_TABLE_FIELD_TYPE', `${at} must be an object`);
      }
      const { labelRecord, value, present = true, changeable = false } = rule;
      if (!Number.isSafeInteger(labelRecord) || labelRecord < 0 ||
          labelRecord > AREA_TABLE_RULE_SCREEN.maximumLabelRecordIndex) {
        fail('AREA_TABLE_FIELD_VALUE',
          `${at} labelRecord must be 0..${AREA_TABLE_RULE_SCREEN.maximumLabelRecordIndex}: the ` +
          'client-local rule-label table holds 16 records');
      }
      if (!Number.isSafeInteger(value) || value < 0 ||
          value > AREA_TABLE_RULE_SCREEN.maximumChoiceIndex) {
        fail('AREA_TABLE_FIELD_VALUE',
          `${at} value must be 0..${AREA_TABLE_RULE_SCREEN.maximumChoiceIndex}: it indexes a ` +
          'label record\'s 8 entries and anything past renders blank');
      }
      if (typeof present !== 'boolean' || typeof changeable !== 'boolean') {
        fail('AREA_TABLE_FIELD_VALUE', `${at} present and changeable must be booleans`);
      }
      return Object.freeze({ labelRecord, value, present, changeable });
    }));
  }

  return Object.freeze({
    published: true,
    maximumPlayers,
    minimumPlayers,
    timeLimitUnit,
    rules: ruleRows,
    /*
     * byte0: b7 present, b6 CHANGEABLE (the row's white bit), b4-5 max-1,
     * b2-3 min-1, b0-1 default index (absolute, players-1). With the defaults
     * (changeable false, defaultPlayers = minimum = 1) this is the
     * rig-confirmed 0xB0 for max 4 / min 1.
     */
    playerCountByte: ((playerCountSelectable ? 1 : 0) << 7) |
      ((playerCountChangeable ? 1 : 0) << 6) |
      (((maximumPlayers - 1) & 3) << 4) | (((minimumPlayers - 1) & 3) << 2) |
      ((defaultPlayers - 1) & 3),
    /*
     * byte1 under the ROW decode when waitingRow is given (b7 present, b6
     * changeable, b5-3 choiceCount-1, b2-0 default index); the legacy
     * `timeLimitUnit` encoding otherwise - byte-identical to what the rig
     * confirmed, which under the row decode is the blank 1-choice row.
     */
    timeLimitByte: waiting != null
      ? 0x80 | ((waiting.changeable ? 1 : 0) << 6) |
        (((waiting.choiceCount - 1) & 7) << 3) | (waiting.defaultChoice & 7)
      : ((difficultySelectable ? 1 : 0) << 7) | (timeLimitUnit & 0x3f)
  });
}

function requireNulTerminatedField(value, where, fieldLength) {
  if (!Buffer.isBuffer(value)) fail('AREA_TABLE_FIELD_TYPE', `${where} must be a Buffer`);
  if (value.length >= fieldLength) {
    fail(
      'AREA_TABLE_FIELD_LENGTH',
      `${where} is ${value.length} bytes; the record field holds ${fieldLength} including the ` +
      'terminating NUL, and the client\'s copy bound is not established'
    );
  }
  if (value.includes(0)) {
    fail('AREA_TABLE_FIELD_VALUE', `${where} must not contain an embedded NUL`);
  }
  return Buffer.from(value);
}

function normalizeArea(area, index) {
  const where = `area ${index}`;
  if (area == null || typeof area !== 'object' || Array.isArray(area)) {
    fail('AREA_TABLE_SHAPE', `${where} must be an object`);
  }
  const allowed = [
    'name', 'secondLine', 'description', 'enabled', 'unknownLeadWord',
    'alwaysAvailableModeMask', 'progressGatedModeMask', 'roomParameters',
    'castMask', 'extraCastPermission', 'titleSettable', 'passwordSettable'
  ];
  const extra = Object.keys(area).filter((key) => !allowed.includes(key));
  if (extra.length > 0) {
    fail('AREA_TABLE_SHAPE', `${where} has unsupported fields: ${extra.join(', ')}`);
  }
  /*
   * `secondLine` is the one OPTIONAL field. Every other key is mandatory so a
   * caller cannot silently ship a default it did not think about - but this one
   * was added after the operator document format was already in use, and an area
   * with nothing to say on its second line is a legitimate state (the disabled
   * `reserved` row is exactly that). Omitting it yields an empty string, which is
   * byte-identical to what V1 shipped for every area.
   */
  const optional = [
    'secondLine', 'roomParameters',
    'castMask', 'extraCastPermission', 'titleSettable', 'passwordSettable'
  ];
  const missing = allowed.filter((key) => !optional.includes(key) && !Object.hasOwn(area, key));
  if (missing.length > 0) {
    fail('AREA_TABLE_SHAPE', `${where} is missing required fields: ${missing.join(', ')}`);
  }
  if (typeof area.enabled !== 'boolean') {
    fail('AREA_TABLE_FIELD_VALUE', `${where} enabled must be a boolean`);
  }
  if (!Number.isSafeInteger(area.unknownLeadWord) ||
      area.unknownLeadWord < 0 || area.unknownLeadWord > 0xffffffff) {
    fail('AREA_TABLE_FIELD_VALUE', `${where} unknownLeadWord must be an unsigned 32-bit integer`);
  }
  const castMask = area.castMask ?? null;
  if (castMask != null && (!Number.isSafeInteger(castMask) || castMask < 0 || castMask > 0xff)) {
    fail('AREA_TABLE_FIELD_VALUE',
      `${where} castMask must be an unsigned byte: FUN_005baf20 reads one bit per base character`);
  }
  const extraCastPermission = area.extraCastPermission ?? null;
  if (extraCastPermission != null &&
      (!Buffer.isBuffer(extraCastPermission) ||
        extraCastPermission.length !== AREA_TABLE_RULE_SCREEN.extraCastPermissionLength)) {
    fail('AREA_TABLE_FIELD_VALUE',
      `${where} extraCastPermission must be a Buffer of exactly ` +
      `${AREA_TABLE_RULE_SCREEN.extraCastPermissionLength} bytes: FUN_005baf70 reads a ` +
      '128-bit bitmap at rec+0x04');
  }
  for (const name of ['titleSettable', 'passwordSettable']) {
    if (area[name] != null && typeof area[name] !== 'boolean') {
      fail('AREA_TABLE_FIELD_VALUE', `${where} ${name} must be a boolean`);
    }
  }
  return Object.freeze({
    name: requireNulTerminatedField(
      area.name, `${where} name`, AREA_TABLE_LAYOUT.nameFieldLength
    ),
    /*
     * Optional, and an empty buffer is legitimate: an area may genuinely have
     * nothing to say on its second line. It defaults to empty rather than to a
     * copy of the name, because a caller that forgets it should produce the
     * blank we already know how to recognise, not a duplicated line that looks
     * deliberate.
     */
    secondLine: requireNulTerminatedField(
      area.secondLine ?? Buffer.alloc(0), `${where} secondLine`,
      AREA_TABLE_LAYOUT.secondLineFieldLength
    ),
    roomParameters: normalizeRoomParameters(area.roomParameters, where),
    description: requireNulTerminatedField(
      area.description, `${where} description`, AREA_TABLE_LAYOUT.descriptionFieldLength
    ),
    enabled: area.enabled,
    unknownLeadWord: area.unknownLeadWord,
    /*
     * The rule-screen fields (RULES-MASK-RE.md). All default to the absent
     * state - castMask null leaves the lead word's low byte in place (the
     * historical 0x1F), the permission bitmap stays zero, and both `+0x16b`
     * bits stay clear - so an area that says nothing serializes byte-identically
     * to the rig-confirmed blob.
     */
    castMask,
    extraCastPermission: extraCastPermission == null ? null : Buffer.from(extraCastPermission),
    titleSettable: area.titleSettable ?? false,
    passwordSettable: area.passwordSettable ?? false,
    alwaysAvailableModeMask: requireModeMask(
      area.alwaysAvailableModeMask, `${where} alwaysAvailableModeMask`
    ),
    progressGatedModeMask: requireModeMask(
      area.progressGatedModeMask, `${where} progressGatedModeMask`
    )
  });
}

/**
 * A rule/mode mask, refused when it sets a bit the client cannot reach.
 *
 * `FUN_005fe1e0` loops `i` from 1 while `i + 1 < 0xc`, so only bits 0..10 are
 * ever tested. A bit above that would be silently dropped by the client, and a
 * silently dropped configuration value is how an operator ends up believing they
 * enabled something they did not. Fail closed with the reason rather than mask it
 * off.
 */
function requireModeMask(value, where) {
  if (!Number.isSafeInteger(value) || value < 0) {
    fail('AREA_TABLE_MODE_MASK', `${where} must be a non-negative whole number`);
  }
  const ceiling = (1 << AREA_TABLE_LAYOUT.modeMaskBits) - 1;
  if (value > ceiling) {
    fail(
      'AREA_TABLE_MODE_MASK',
      `${where} is 0x${value.toString(16)}; FUN_005fe1e0 only tests bits 0..` +
      `${AREA_TABLE_LAYOUT.modeMaskBits - 1} (mode ids 1..${AREA_TABLE_LAYOUT.modeMaskBits}), so ` +
      `anything above 0x${ceiling.toString(16)} would be silently dropped by the client`
    );
  }
  return value;
}

/**
 * One option-label record, validated against the `FUN_005c3c40` access pattern.
 *
 * `null` is a legal record and means "all zeroes": length byte 0, so the client
 * blits nothing for any field that names it - the blank-not-garbage default.
 */
function normalizeOptionLabelRecord(record, index) {
  const where = `optionLabels record ${index}`;
  if (record == null) return null;
  if (typeof record !== 'object' || Array.isArray(record)) {
    fail('AREA_TABLE_OPTION_LABELS', `${where} must be an object or null`);
  }
  const allowed = ['destinationOffset', 'entryLength', 'entries'];
  const extra = Object.keys(record).filter((key) => !allowed.includes(key));
  if (extra.length > 0) {
    fail('AREA_TABLE_OPTION_LABELS', `${where} has unsupported fields: ${extra.join(', ')}`);
  }
  const { destinationOffset = 0, entryLength = 0, entries = [] } = record;
  for (const [name, value] of [
    ['destinationOffset', destinationOffset], ['entryLength', entryLength]
  ]) {
    if (!Number.isSafeInteger(value) || value < 0 || value > 0xff) {
      fail('AREA_TABLE_OPTION_LABELS', `${where} ${name} must be an unsigned byte`);
    }
  }
  if (entryLength > AREA_TABLE_OPTION_LABELS.entryStride) {
    fail(
      'AREA_TABLE_OPTION_LABELS',
      `${where} entryLength 0x${entryLength.toString(16)} exceeds the 0x20-byte entry stride: ` +
      'the blit would read into the neighbouring entry'
    );
  }
  if (!Array.isArray(entries) || entries.length > AREA_TABLE_OPTION_LABELS.maximumEntriesPerRecord) {
    fail(
      'AREA_TABLE_OPTION_LABELS',
      `${where} holds at most ${AREA_TABLE_OPTION_LABELS.maximumEntriesPerRecord} entries: ` +
      'entry 7 would start at +0x11e and overlap the next record'
    );
  }
  const copies = entries.map((entry, entryIndex) => {
    if (!Buffer.isBuffer(entry) || entry.length > AREA_TABLE_OPTION_LABELS.entryStride) {
      fail(
        'AREA_TABLE_OPTION_LABELS',
        `${where} entry ${entryIndex} must be a Buffer of at most 0x20 bytes`
      );
    }
    return Buffer.from(entry);
  });
  return Object.freeze({ destinationOffset, entryLength, entries: Object.freeze(copies) });
}

function normalizeOptionLabels(optionLabels) {
  if (optionLabels == null) return null;
  if (typeof optionLabels !== 'object' || Array.isArray(optionLabels)) {
    fail('AREA_TABLE_OPTION_LABELS', 'optionLabels must be an object with a records array');
  }
  const { records } = optionLabels;
  if (!Array.isArray(records) || records.length < 1 ||
      records.length > AREA_TABLE_OPTION_LABELS.maximumRecords) {
    fail(
      'AREA_TABLE_OPTION_LABELS',
      `optionLabels.records must hold 1..${AREA_TABLE_OPTION_LABELS.maximumRecords} records: ` +
      'the client buffer at 0x361a70 is 0x2000 bytes and record 12 would not fit whole'
    );
  }
  return Object.freeze({
    records: Object.freeze(records.map(normalizeOptionLabelRecord))
  });
}

/**
 * An immutable area table and its wire transfer.
 *
 * Immutable because every connection reads the same content and a client walking
 * a seven-slice transfer must never be handed a blob that changed underneath it.
 * A future operator-published table replaces the object, exactly as
 * `DirectoryState` is replaced.
 */
export class AreaTable {
  #version;
  #provenance;
  #areas;
  #optionLabels;
  #blob;

  constructor({ version, provenance, areas, optionLabels = null }) {
    if (provenance !== AREA_TABLE_PROVENANCE.OPERATOR &&
        provenance !== AREA_TABLE_PROVENANCE.V1_OBSERVED &&
        provenance !== AREA_TABLE_PROVENANCE.TEST_FIXTURE) {
      fail(
        'AREA_TABLE_PROVENANCE',
        'provenance must be stated explicitly as operator, v1-observed, or test-fixture'
      );
    }
    if (!Buffer.isBuffer(version)) {
      fail('AREA_TABLE_VERSION', 'version must be a Buffer');
    }
    if (version.length === 0 || version.length > AREA_TABLE_TRANSFER.maximumVersionLength) {
      /*
       * Empty is refused, not because the parser rejects it, but because
       * `FUN_001c4960.c:46-49` compares the version with the client's cached copy
       * at `0x36842c` and SKIPS the whole fetch when they match. A zero-length
       * version would match a client whose cache is still zeroed, and the blob
       * would never be sent.
       */
      fail(
        'AREA_TABLE_VERSION',
        `version must be 1..${AREA_TABLE_TRANSFER.maximumVersionLength} bytes`
      );
    }
    if (!Array.isArray(areas) || areas.length !== AREA_TABLE_LAYOUT.areaCount) {
      fail(
        'AREA_TABLE_AREA_COUNT',
        `an area table holds exactly ${AREA_TABLE_LAYOUT.areaCount} areas; any other count is ` +
        'untested against the client\'s fixed-stride table'
      );
    }
    this.#version = Buffer.from(version);
    this.#provenance = provenance;
    this.#areas = Object.freeze(areas.map((area, index) => normalizeArea(area, index)));
    this.#optionLabels = normalizeOptionLabels(optionLabels);
    this.#blob = this.#serialize();
    if (this.#blob.length > AREA_TABLE_TRANSFER.maximumChunkLength) {
      fail(
        'AREA_TABLE_LENGTH',
        `the serialized table is ${this.#blob.length} bytes; FUN_001c4960 treats a declared ` +
        `chunk length above ${AREA_TABLE_TRANSFER.maximumChunkLength} as terminal`
      );
    }
  }

  get version() {
    return Buffer.from(this.#version);
  }

  get provenance() {
    return this.#provenance;
  }

  get areaCount() {
    return this.#areas.length;
  }

  get byteLength() {
    return this.#blob.length;
  }

  /** How many `0x6204` round trips a full transfer takes. */
  get sliceCount() {
    return Math.ceil(this.#blob.length / AREA_TABLE_TRANSFER.sliceLength);
  }

  areaAt(index) {
    if (!Number.isSafeInteger(index) || index < 0 || index >= this.#areas.length) return null;
    return this.#areas[index];
  }

  /** The `0x6203` chunk table: one declared chunk carrying the whole blob. */
  chunkLengths() {
    return [this.#blob.length];
  }

  /** A copy of the serialized image. Callers never see the internal buffer. */
  serialize() {
    return Buffer.from(this.#blob);
  }

  /**
   * One `0x6204` slice.
   *
   * The offset is validated, never clamped: `FUN_001c4d40.c:30` refuses any reply
   * whose echoed offset is not the client's own cursor, and that cursor moves in
   * fixed `0x2f2` steps, so an off-step offset means the two models diverged and
   * guessing past it would corrupt the table the client seats.
   */
  sliceAt({ chunkIndex, offset } = {}) {
    if (chunkIndex !== 0) {
      fail(
        'AREA_TABLE_CHUNK_INDEX',
        `0x6204 asked for chunk ${chunkIndex}; this table declares ` +
        `${AREA_TABLE_TRANSFER.declaredChunkCount} chunk`
      );
    }
    if (!Number.isSafeInteger(offset) || offset < 0 || offset >= this.#blob.length) {
      fail(
        'AREA_TABLE_OFFSET',
        `0x6204 asked for offset ${offset}; the table is ${this.#blob.length} bytes`
      );
    }
    if (offset % AREA_TABLE_TRANSFER.sliceLength !== 0) {
      fail(
        'AREA_TABLE_OFFSET',
        `0x6204 asked for offset ${offset}, which is not a multiple of the client's own ` +
        `${AREA_TABLE_TRANSFER.sliceLength}-byte cursor step`
      );
    }
    const end = Math.min(offset + AREA_TABLE_TRANSFER.sliceLength, this.#blob.length);
    return {
      chunkIndex,
      offset,
      data: Buffer.from(this.#blob.subarray(offset, end)),
      /** True once this slice completes the declared chunk. */
      final: end >= this.#blob.length
    };
  }

  #serialize() {
    const parts = [];
    for (const area of this.#areas) {
      const record = Buffer.alloc(AREA_TABLE_LAYOUT.recordStride);
      record.writeUInt32BE(area.unknownLeadWord, AREA_TABLE_LAYOUT.unknownLeadWordOffset);
      /*
       * AFTER the lead word, deliberately: the BE32 write puts the lead word's
       * low byte into `+0x03`, which `FUN_005baf20` reads as the base-CAST
       * mask - the historical `0x1F` = "five male characters" accident
       * (RULES-MASK-RE.md §4). An explicit castMask overrides exactly that
       * byte; null preserves the observed lead word whole.
       */
      if (area.castMask != null) {
        record[AREA_TABLE_RULE_SCREEN.castMaskOffset] = area.castMask;
      }
      if (area.extraCastPermission != null) {
        area.extraCastPermission.copy(record, AREA_TABLE_RULE_SCREEN.extraCastPermissionOffset);
      }
      /*
       * LITTLE-endian — CORRECTED 2026-08-24 (analysis/area-table-scenario-
       * mask-LE-2026-08-24.md). The old comment here claimed "a native word on
       * a big-endian EE"; the R5900 is LITTLE-endian (proved in-project by the
       * slot-1 savestate: the bank pointer array reads 0x8d4000/0x8d5780/
       * 0x8d6f00 only under LE, matching FUN_00606ea0's `+0x17bb & ~0x3f`
       * arithmetic). The whole TCP 0x6204 path is memcpy-verbatim (FUN_001c4d40
       * → FUN_006188b0 → FUN_005aeb10 — no byteswap, unlike the UDP SN@P path),
       * so BE32 0x7ff arrived as native 0xFF070000: every bit outside the ring
       * loop's tested 0..10 → count 0 → ring 0xFFFF → "Scenario (null)" —
       * exactly the owner's create screen tonight. These two fields are the
       * blob's ONLY multi-byte scalar loads (rules/cast are byte reads — which
       * is why OBAREA-W5 fixed those while scenario stayed dead).
       */
      record.writeUInt32LE(
        area.progressGatedModeMask, AREA_TABLE_LAYOUT.progressGatedModeMaskOffset
      );
      record.writeUInt32LE(
        area.alwaysAvailableModeMask, AREA_TABLE_LAYOUT.alwaysAvailableModeMaskOffset
      );
      area.name.copy(record, AREA_TABLE_LAYOUT.nameOffset);
      area.secondLine.copy(record, AREA_TABLE_LAYOUT.secondLineOffset);
      /*
       * BOTH blocks, identically. See `roomParameterBlockOffset`: which one the
       * client reads depends on `bRam006ce5cf`, whose contents are Unknown, so
       * writing both removes the question from the outcome.
       */
      for (let block = 0; block < AREA_TABLE_LAYOUT.roomParameterBlockCount; block += 1) {
        const at = AREA_TABLE_LAYOUT.roomParameterBlockOffset +
          block * AREA_TABLE_LAYOUT.roomParameterBlockLength;
        record[at] = area.roomParameters.playerCountByte;
        record[at + 1] = area.roomParameters.timeLimitByte;
        /*
         * The group-1 rule rows, at the FUN_005c2f40 offsets: count at block
         * `+0x02`, 4-byte `{labelRecord, value, present, changeable}`
         * descriptors from `+0x03`. Ten descriptors end exactly at `+0x2b`,
         * the group-2 count, which stays zero.
         */
        if (area.roomParameters.rules != null) {
          record[at + AREA_TABLE_RULE_SCREEN.groupOneCountOffset] =
            area.roomParameters.rules.length;
          area.roomParameters.rules.forEach((rule, index) => {
            const descriptor = at + AREA_TABLE_RULE_SCREEN.groupOneDescriptorsOffset +
              index * AREA_TABLE_RULE_SCREEN.descriptorStride;
            record[descriptor] = rule.labelRecord;
            record[descriptor + 1] = rule.value;
            record[descriptor + 2] = rule.present ? 1 : 0;
            record[descriptor + 3] = rule.changeable ? 1 : 0;
          });
        }
      }
      // `+0x16b` bit0 = Room Title settable, bit1 = Password settable
      // (FUN_005c2b20/FUN_005c2b90, Confirmed). Both false writes the 0x00 the
      // rig-confirmed blob carried.
      record[AREA_TABLE_RULE_SCREEN.titlePasswordOffset] =
        (area.titleSettable ? 1 : 0) | ((area.passwordSettable ? 1 : 0) << 1);
      area.description.copy(record, AREA_TABLE_LAYOUT.descriptionOffset);
      record[AREA_TABLE_LAYOUT.enableOffset] = area.enabled
        ? AREA_TABLE_LAYOUT.enabledValue
        : AREA_TABLE_LAYOUT.disabledValue;
      parts.push(record);
    }
    if (this.#optionLabels == null) {
      // Every byte the records do not name is zero in V1's blob, which is what
      // Buffer.alloc already gives; the trailer is the same. This branch is the
      // byte-identical pre-option-labels blob (0x1300 bytes, md5-pinned by
      // test/area-table-option-labels.test.js).
      parts.push(Buffer.alloc(AREA_TABLE_LAYOUT.trailerLength));
      return Buffer.concat(parts);
    }
    /*
     * The option-label table: the records end at 0x12e8, the table starts at
     * 0x12fc (FUN_005c2ad0), so 0x14 unnamed zero bytes precede it - the same
     * bytes the plain trailer's first 0x14 were. Then each 0x120-stride record,
     * fields at the FUN_005c3c40 offsets, everything unnamed zero. A null
     * record IS the payload zero record: length byte 0 means "blit nothing",
     * which is what replaces the stale-memory garbage with blank.
     */
    parts.push(Buffer.alloc(
      AREA_TABLE_OPTION_LABELS.tableOffset -
      AREA_TABLE_LAYOUT.areaCount * AREA_TABLE_LAYOUT.recordStride
    ));
    for (const record of this.#optionLabels.records) {
      const encoded = Buffer.alloc(AREA_TABLE_OPTION_LABELS.recordStride);
      if (record != null) {
        encoded[AREA_TABLE_OPTION_LABELS.destinationOffsetByte] = record.destinationOffset;
        encoded[AREA_TABLE_OPTION_LABELS.entryLengthByte] = record.entryLength;
        record.entries.forEach((entry, index) => {
          entry.copy(
            encoded,
            AREA_TABLE_OPTION_LABELS.entriesOffset + index * AREA_TABLE_OPTION_LABELS.entryStride
          );
        });
      }
      parts.push(encoded);
    }
    return Buffer.concat(parts);
  }
}

export function createAreaTable(options) {
  return new AreaTable(options);
}

/**
 * Parse an operator-authored area-table document.
 *
 * The seam for `config/`: nothing in the TCP path has to change for an operator
 * to publish their own area names. Names and descriptions are latin1, which is
 * what the PAL field codec transports; `unknownLeadWord` is optional ONLY because
 * its meaning is unknown and V1's value is the sole observed one - a document
 * that omits it inherits that value and the fact is stated here rather than
 * hidden as a fallback.
 */
export function parseAreaTableDocument(document, { source = 'area table document' } = {}) {
  if (document == null || typeof document !== 'object' || Array.isArray(document)) {
    fail('AREA_TABLE_SHAPE', `${source} must be a JSON object`);
  }
  if (typeof document.version !== 'string') {
    fail('AREA_TABLE_VERSION', `${source} must declare a "version" string`);
  }
  if (!Array.isArray(document.areas)) {
    fail('AREA_TABLE_SHAPE', `${source} needs an "areas" array`);
  }
  return new AreaTable({
    version: Buffer.from(document.version, 'latin1'),
    provenance: document.provenance,
    /*
     * The `+0x12fc` option-label table, operator-suppliable as hex because the
     * entry ENCODING is unproven (text vs. glyph tiles - see
     * AREA_TABLE_OPTION_LABELS): a string field here would presume an answer.
     * Omitted = not emitted, the pre-option-labels blob.
     */
    optionLabels: document.optionLabels == null ? null : {
      records: (Array.isArray(document.optionLabels.records)
        ? document.optionLabels.records
        : fail('AREA_TABLE_OPTION_LABELS', `${source} optionLabels needs a records array`)
      ).map((record, index) => {
        if (record == null) return null;
        const entriesHex = record.entriesHex ?? [];
        if (!Array.isArray(entriesHex) ||
            entriesHex.some((hex) => typeof hex !== 'string' || !/^([0-9a-f]{2})*$/i.test(hex))) {
          fail(
            'AREA_TABLE_OPTION_LABELS',
            `${source} optionLabels record ${index} entriesHex must be hex strings`
          );
        }
        return {
          destinationOffset: record.destinationOffset ?? 0,
          entryLength: record.entryLength ?? 0,
          entries: entriesHex.map((hex) => Buffer.from(hex, 'hex'))
        };
      })
    },
    areas: document.areas.map((area, index) => {
      if (area == null || typeof area !== 'object') {
        fail('AREA_TABLE_SHAPE', `${source} area ${index} must be an object`);
      }
      if (typeof area.name !== 'string' || typeof area.description !== 'string') {
        fail('AREA_TABLE_SHAPE', `${source} area ${index} needs "name" and "description" strings`);
      }
      if (area.secondLine != null && typeof area.secondLine !== 'string') {
        fail('AREA_TABLE_SHAPE', `${source} area ${index} "secondLine" must be a string if present`);
      }
      return {
        name: Buffer.from(area.name, 'latin1'),
        /*
         * Optional so documents written before this field existed still parse -
         * and defaulting to empty rather than to the name, because empty is
         * exactly what V1 shipped and is therefore the state we can recognise.
         * This is the line `FUN_005affb0.c:97-99` draws below the name; an
         * operator who wants it filled must say so.
         */
        secondLine: Buffer.from(area.secondLine ?? '', 'latin1'),
        /*
         * Forwarded, not dropped. `normalizeArea` accepts the key, so a document
         * carrying it was previously neither honoured NOR rejected - it silently
         * fell back to the defaults, which is the worst of the three outcomes.
         */
        roomParameters: area.roomParameters,
        description: Buffer.from(area.description, 'latin1'),
        enabled: area.enabled,
        unknownLeadWord: area.unknownLeadWord ?? V1_OBSERVED_LEAD_WORD,
        // Default ZERO, which is what V1 shipped and therefore what "no rules
        // offered" looks like. A document that wants rules must say so: this is
        // chosen policy, and inheriting a non-zero default silently would be
        // exactly the unlabelled choice this whole field is documented against.
        alwaysAvailableModeMask: area.alwaysAvailableModeMask ?? 0,
        progressGatedModeMask: area.progressGatedModeMask ?? 0
      };
    })
  });
}

/**
 * The BE32 at record `+0x00` in every one of V1's ten records.
 *
 * Unknown. No reader has been identified in the corpus or the overlay dumps. It
 * is exported so that a document may carry it explicitly rather than inherit it
 * silently.
 */
export const V1_OBSERVED_LEAD_WORD = 0x0000001f;
