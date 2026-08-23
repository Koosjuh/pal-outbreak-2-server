# RULES-MASK-RE — how the create-room RULE screen decides red vs white

**Date:** 2026-08-08 · **Branch:** `feat/v2-bioserver-port` · **Scope:** the create-room
RULE screen (`captures/create a room .png`): per-row settability, the Scenario row, the
Character row, and exactly which served bytes change each one.

**Bottom line:** every red row on that screen is decided by bytes we serve in the
`0x6204` area blob, and by nothing else — no client query, no savedata, no protocol
message. The client sends NOTHING on the rule screen (`RS1-TCP-INVENTORY.md`), which is
now explained rather than merely observed: it has no reason to, because the whole screen
was assembled from the area record when the create pump ran.

---

## 0. Evidence grades used

**Observation** = read directly out of a decompile / a string dump / a screenshot /
PINE. **Inference** = derived from observations by arithmetic or data flow.
**Hypothesis** = consistent with evidence but not forced by it. Everything below carries
its grade inline. Per `docs/CORPUS-METHODOLOGY.md`, "no other reader" is never claimed.

Primary sources, all cited as `file:line`:
- `analysis/claude-helper-module-full-2026-05-29.txt` (netwk overlay decompile dump)
- `analysis/netwk-strings-2026-05-29.txt` (netwk overlay string dump, with file offsets)
- `captures/create a room .png` (owner screenshot, 2026-08-08 00:13 — **before** the mask
  publish at `68b1a59f` 09:19, which matters in §6)
- `docs/design/v2-port/RIG-SESSION-1.md` R1 (owner, post-publish: "rules NOT selectable")
- `references/bioserver/.../bioserv2/bioserver/RuleSet.java`, `Areas.java`
- `server-v2/src/state/area-table.js`, `area-table-v1.js` (what we ship today)

---

## 1. The screen, mapped to the renderer

`FUN_005fcc70` (`analysis/claude-helper-module-full-2026-05-29.txt:49586-49760`) is the
RULE screen's renderer. Its draw calls are `FUN_005af1e0(x, y, 0, string)` with `y`
literals, and the colour immediately before each is `FUN_005af2c0(index)`. Matching those
`y` literals against the screenshot pins every row (**Observation**, both sides):

| cursor | y (dec) | screenshot row | label source | value source |
|---|---|---|---|---|
| 0 | `0x56` = 86 | Room Title | `FUN_0062fea0(9)` | typed title `0x6970b2` |
| 1 | `0x72` = 114 | Password | `FUN_0062fea0(10)` | typed pw `0x6970a2`, or `FUN_0062fea0(0xb)` |
| 2..7 | `(i+2)*0x1c+0x56` = 142,170,… | No. of Players / Waiting Time / … | row model `+0x6970f6` | row model `+0x69715d + v*0x41` |
| 8 | `0x136` = 310 | **Scenario** | `FUN_0062fea0(6)` | `FUN_005bac80(uRam006c4b96)` |
| 9 | `0x152` = 338 | **Character** | `FUN_0062fea0(0x14)` | `func_0x001b6950(0x6c4bac[i*4])` |

The screenshot's measured baselines (89 / 117 / 146 / 174 / 307 / 340) track those
literals with a constant +3 text offset, so the mapping is not a guess.

> **Correction to the corpus.** `analysis/CREATE-ROOM-GATES-RE.md` §3b filed
> `FUN_005fe1e0` (record `+0x14`/`+0x18`) as the **rule/mode** ring. It is the
> **SCENARIO** ring — its output `screen+6` = `0x6c4b96` is what row 8 renders. The
> corpus' own `menus/005fe1e0_build_scenario_ring` naming was right and
> `state/area-table.js`'s "rule/mode mask" prose is wrong. Marked SUPERSEDED here, not
> rewritten there. See §6. The rule rows are a completely different mechanism (§2), which
> is why publishing the masks at `68b1a59f` did not turn a single rule row white
> (RIG-SESSION-1 R1 — the falsifying observation).

---

## 2. The per-row settability computation (rows 2..7) — Confirmed

### 2.1 The chain, end to end

```
area blob (0x6204)            room-parameter block          config-row table        UI model            renderer
rec+0x16c + blk*0x3c   --->   FUN_005c2f40 / c2bc0 / c2d70  --->  0x6d2297 +   --->  0x6970a0 +   --->  FUN_005fcc70
                                                                  i*0x14a5           i*0x14a8
```

1. **Block select.** `FUN_005c2ae0` = `iRam00368474 + (area-1)*0x1e4 + 0x16c + blk*0x3c`
   (`:17680`), where `iRam00368474` is the downloaded blob (`0x361a70`) and `blk =
   FUN_005c4f00()` (`:19146`): `bRam006ce5cf == 1 → 0`, `>= 2 → 1`, `== 0 → -1`.
   **Observation.**
2. **Row build.** `FUN_005c2f40(param)` (`:17886`) memsets `0x6d2294..+0x294a3`, then
   builds rows at `0x6d2297`, stride `0x14a5`, in three groups, and stores the total in
   `cRam006d2296`. **Observation.**
3. **UI copy.** `FUN_005f9280` case 3 (`:47225-47250`) copies that table into `0x6970a0`,
   stride `0x14a8`. `FUN_005fa190` case 3 (`:47855-47872`) does the same for the joiner's
   room view. **Observation.**
4. **Render.** `FUN_005fcc70` (`:49685-49700`). **Observation.**

### 2.2 The row record and the one byte that decides the colour

`FUN_005c2bc0`/`FUN_005c2d70` write exactly four fields per row (`:17766-17848`):

| row field | meaning | written from |
|---|---|---|
| `+0x01` | row NAME (strcpy) | label record `+0x00` |
| `+0x42` | **CHANGEABLE flag** | descriptor `[3]` / block-byte bit 6 |
| `+0x43` | number of choices | computed (group 0) or label record `+0x1f` |
| `+0x44` | current value index | descriptor `[1]` / block-byte bits |
| `+0x65 + i*0x41` | choice i's text (strcpy) | label record `+0x20 + i*0x20` |

`+0x42` lands at UI-model `+0x697138` (`:47240`), and it is read in exactly three places:

```c
/* FUN_005fcc70:49690-49694  — THE COLOUR */
FUN_005af2c0(0);
if (*(char *)(iVar3 + 0x697138) != '\x01') FUN_005af2c0(2);   /* not settable -> colour 2 */

/* FUN_005f9bb0:47564 — cursor may only LAND on a settable row */
if (*(char *)(iVar3 * 0x14a8 + 0x697138) == '\x01') break;

/* FUN_005f9e50:47658 — left/right may only CHANGE a settable row */
if (*(char *)(iVar3 + 0x697138) != '\0') { ...adjust value... }
```

**Confirmed:** `row+0x42 == 1` ⇒ normal colour + focusable + editable. Anything else ⇒
colour 2, cursor skips it, left/right does nothing. That is the red/white decision, and
it is one byte per row that we serve.

*Colour index 2 = red is **Inference**:* `FUN_005af2c0` is `halt_baddata()` in the dump
(`:4205-4217`), so the palette is not decompiled. What is Confirmed is that rows failing
the test take a *different* colour, and that the same index 2 is used for the room-title
and password rows when *they* are not settable — and the screenshot shows exactly those
rows in red.

### 2.3 Where each row's descriptor comes from

`FUN_005c2f40:17911-17931` builds three groups off the block pointer `pbVar3`:

| group | count byte | descriptors | label table |
|---|---|---|---|
| 0 (built-in) | fixed 2 | synthesised from block `+0x00` and `+0x01` | `FUN_005c2e90(0)` — **client-local** |
| 1 | block `+0x02` | block `+0x03`, 4 bytes each (≤10) | `FUN_005c2e90(1)` — **client-local** |
| 2 | block `+0x2b` | block `+0x2c`, 4 bytes each (≤4) | `FUN_005c2ad0()` = blob `+0x12fc` — **served** |

A group-1/2 descriptor is `{ [0] labelRecordIndex, [1] value, [2] present, [3] changeable }`
(`FUN_005c2d70:17813-17846`). `[2] == 0` ⇒ **no row at all** (the parameter still exists
with the literal value `[1]`: `FUN_005c3c40:18323-18348` composes the room-list summary
line from the same descriptors and uses `[1]` when `[2]` is clear). `[2] != 0` ⇒ a row,
initial value `[1]`, **white iff `[3] == 1`**. That is bioserver's `Rule(name, changeable,
value)` triple, byte for byte.

The two built-in rows are synthesised at `:17916-17923`:

```
descriptor0 = { 0, block[0] & 0x3f, (block[0]>>7)&1, (block[0]>>6)&1 }   /* No. of Players */
descriptor1 = { 1, block[1] & 0x3f, (block[1]>>7)&1, (block[1]>>6)&1 }   /* Waiting Time  */
```

**So block byte 0 bit 6 is the "No. of Players" white/red bit and block byte 1 bit 6 is
the "Waiting Time" white/red bit. Confirmed.**

Full block-byte layout (`FUN_005c2bc0:17775-17795`, **Confirmed**):

| byte | b7 | b6 | b5..b3 / b5..b4 | b2 | b1..b0 |
|---|---|---|---|---|---|
| block `+0x00` players | row present | **changeable** | b5-4 = max index | b3-2 = min index | default index |
| block `+0x01` waiting | row present | **changeable** | b5-3 = choiceCount-1 | — | b2-0 = default index |

Players choices are the label list sliced `[min..max]`; value = `default - min`.
Waiting choices are `0..count-1`; value = `default`.

### 2.4 The label records — a correction to `AREA_TABLE_OPTION_LABELS`

Both `FUN_005c2bc0`/`FUN_005c2d70` (name at `+0x00`, count at `+0x1f`, entry i at
`+0x20 + i*0x20`) and `FUN_005c3c40` (blit dest `+0x1d`, blit len `+0x1e`, source
`+0x3e + v*0x20` = entry[v] `+0x1e`) are satisfied by ONE layout (**Inference**, forced by
both readings):

```
0x120-byte label record:
  +0x00  char  name[0x1d]      NUL-terminated display name
  +0x1d  u8    blitDestOffset  (room-list summary line)
  +0x1e  u8    blitLength
  +0x1f  u8    choiceCount
  +0x20  entry[8], stride 0x20:  +0x00 char text[0x1e] ; +0x1e u8 code[blitLength]
```

`0x20 + 8*0x20 = 0x120` exactly. `state/area-table.js`'s `maximumEntriesPerRecord: 7` and
"`entriesOffset: 0x3e`" describe the blit source, not the entry base — **eight** entries
fit, entry 0 is at `+0x20`. Also: `func_0x00109eb8` is a two-argument **strcpy**, so entry
content is TEXT, not glyph tiles — the "encoding unproven" caveat in that module is now
answered. (Only relevant if we ever populate group 2; group 1 uses the client's own table.)

### 2.5 The client's rule-label table — read out of the string dump

`FUN_005c2e90(0/1)` (`:17850-17884`) returns `PTR_s_No__of_Players_00640480[lang]` /
`PTR_s_defficulity_control_006404a0[lang]`. The English blocks are visible in
`analysis/netwk-strings-2026-05-29.txt` and **every name sits on an exact `0x120`
boundary** — which is itself the proof of the stride (**Observation**):

Players table, base file-offset `0x8dbe0`:

| idx | offset | name | notable entries |
|---|---|---|---|
| 0 | `0x8dbe0` | `No. of Players` | (entries < 8 chars, filtered by the dump) |
| 1 | `0x8dd00` | `Waiting Time` | `+0x20..+0xa0`: `3  minutes`, `5  minutes`, `10 minutes`, `15 minutes`, `30 minutes` — **5 choices** |

Rules table (group 1), base file-offset `0x8de20`:

| idx | offset | name |
|---|---|---|
| 0 | `0x8de20` | `defficulity control` |
| **1** | `0x8df40` | **`Difficulty`** — entry 3 at `+0x80` = `VERY HARD` |
| **2** | `0x8e060` | **`Friendly Fire`** |
| 3 | `0x8e180` | `Movie Skippable` |
| 4 | `0x8e2a0` | `Virus Level` |
| **5** | `0x8e3c0` | **`NIGHTMARE`** |
| **6** | `0x8e4e0` | **`INFINITY`** |
| 7 | `0x8e600` | `SP Item Hint` |
| 8 | `0x8e720` | `Point Multiplier` |
| 9 | `0x8e840` | `Life MAX` |
| 10 | `0x8e960` | `Time Limit` |
| 11 | `0x8ea80` | `Defficulty` |
| 12 | `0x8eba0` | `Defficulty` |
| 13 | `0x8ecc0` | `rank kind` |
| 14 | `0x8ede0` | `rank type` |
| 15 | `0x8ef00` | `Prize Item` |

The French block starts at `0x8f020` (`Nb de joueurs`) with the same `+0x240` gap to
`commande de defficulity` at `0x8f260`, so the two tables are 2 and 16 records.

**Confirmed:** the client already owns every rule name and choice list bioserver serves.
We only choose *which* records appear, their initial value, and whether they are white.

### 2.6 Two independent corroborations of the row model

- **Capacity.** The cursor filter `FUN_005f9bb0:47521-47570` only walks indices 2..7 — six
  rule rows — and the seventh would be drawn at `y = 8*0x1c+0x56 = 0x136`, colliding with
  the Scenario row. bioserver's largest RuleSet (area 5, Infinity) has exactly **6** rules.
- **The screenshot is a byte-level prediction.** We ship `playerCountByte = 0xB0`,
  `timeLimitByte = 0x81` (`area-table.js:402-406`, defaults `max 4 / min 1 / unit 1`).
  Decode: players → present, **not changeable**, min idx 0, max idx 3, default idx 0 ⇒ red
  row, 4 choices, showing choice 0. Waiting → present, **not changeable**, choiceCount =
  `((1>>3)&7)+1 = 1`, default = `1&7 = 1` ⇒ red row with the value index **out of range of
  its own 1-entry list** ⇒ blank. The screenshot shows precisely "No. of Players … 1" and
  "Waiting Time" with an empty value. **This is runtime confirmation of the decode.**

---

## 3. The Room Title and Password rows — record `+0x16b`

`FUN_005c2f40:17941-17945` (the `param==0`, i.e. host/create branch):

```c
uRam006d2294 = FUN_005c2b20(area-1);   /* = *(rec + 0x16b) & 1        */
uRam006d2295 = FUN_005c2b90(area-1);   /* = (*(rec + 0x16b) >> 1) & 1 */
```
(`FUN_005c2b20:17705-17715`, `FUN_005c2b90:17754-17764`.)

Those become `cRam006970a0` / `cRam006970a1` (`FUN_005f9280:47228-47229`), and the
renderer does (`FUN_005fcc70:49601-49660`):

- title: `if (cRam006970a0 == 1) colour 0 else colour 2`
- password: `colour 0; if (cRam006970a1 != 1) colour 2`, and when not settable the VALUE is
  the client string `FUN_0062fea0(0xb)` instead of the typed one.

**Confirmed:** `rec+0x16b` bit0 = room title settable, bit1 = password settable. We ship
`+0x16b = 0x00`, so both rows are red — which is exactly the screenshot.

**Correction:** the screenshot's `Password: Impossible` is NOT stale-buffer garbage (as
`area-table.js`'s option-label docstring supposes). `Impossible` is the client's own
`FUN_0062fea0(0xb)` placeholder for "password cannot be set", drawn *because* bit1 is
clear. **Inference**, but a tight one: the code path is unconditional and the string
appears exactly where that path draws.

When a bit is CLEAR the client falls back to the server's default, which is why the record
has room for one: `FUN_005c3190:17998-18000` copies 0xf bytes from `FUN_005c2b50` =
`rec+0x14d` as the default title, and `FUN_005c3490:18186-18189` copies 8 bytes from
`FUN_005c2b70` = `rec+0x15d` as the default password. So:

| offset | field | grade |
|---|---|---|
| `+0x14d` | default room title, 15 bytes copied | Confirmed |
| `+0x15d` | default password, 8 bytes copied | Confirmed |
| `+0x165..+0x16a` | no identified reader | Unknown |
| `+0x16b` | bit0 title settable, bit1 password settable | Confirmed |

This closes the `+0x14d..+0x16b` "PENDING" row in `state/area-table.js`.

---

## 4. The Character row — record `+0x03` is an 8-bit CAST mask

Row 9's value comes from the 4-byte ring at `screen+0x1a` = `0x6c4baa`
(`FUN_005fcc70:49712-49730`):

```c
iVar7 = sRam006c4b94 * 4;                          /* cursor = screen+4 */
if (*(char *)(iVar7 + 0x6c4baa) == '\0') {          /* kind 0: base cast */
    name = func_0x001b6950(*(char *)(iVar7 + 0x6c4bac));      /* character id  */
    suffix = PTR_DAT_0068ae30[*(char *)(iVar7 + 0x6c4bab)];   /* costume index */
} else {                                            /* kind 1: extra cast */
    row = FUN_005fe4b0(*(char *)(iVar7 + 0x6c4bac)); name = func_0x001b68b0(row);
}
```

That ring is built by `FUN_005fe300` (`:50186-50275`), called from `FUN_005f91f0`
(`:47166-47189`) — a sibling state of the same create-screen SM (`FUN_005f9150` dispatches
both `FUN_005f91f0` and `FUN_005f9280`). It writes 4-byte entries `{kind, costume, id}` and
stores the count at `screen+10` = `0x6c4b9a`:

```
mask8 = FUN_005baf20(area-1) = *(u8*)(rec + 0x03)           /* :11880-11887 */
for i in 0..7:                       if (mask8 & 1<<i):
    emit { 0, 0, i }                                        /* the base character   */
    for k in 0..3: if (*(u8*)(0x341ac8 + i) & 1<<k):
        emit { 0, k+1, i }                                  /* its alternate costume */

bitmap128 = FUN_005baf70(area-1) = rec + 0x04                /* :11897-11904 */
for b in 0..127: if ((*(u32*)(0x341ad0 + (b>>5)*4) & 1<<(b&31))
                 &&  (bitmap128[b>>3] & 1<<(b&7))):
    emit { 1, 0, *(u16*)(0x3c4d50 + b*0xc) + 1 }             /* an extra character   */
```

**Confirmed** (decompile). Consequences:

- **The eight base characters are gated by `rec+0x03` ALONE — no savedata term.**
  Server-controllable in full.
- `0x341ac8[i]` (4 bits per character) gates only that character's **alternate costumes**.
  Player savedata; not server-reachable; a fresh console legitimately has none.
- Extra/unlockable cast needs BOTH savedata `0x341ad0[]` AND our `rec+0x04..0x13`. The
  server can only *permit*, never grant.

### The 0x1F accident

`state/area-table.js:722` writes `unknownLeadWord = 0x0000001F` as a **BE32 at `+0x00`**,
which puts **`0x1F` into byte `+0x03`** — five bits set — so we are serving "5 of the 8
base characters". Project history records exactly that symptom: *"the roster partially
unlocked (Kevin only → 5 chars)… 5 = the five male characters"* (`MEMORY.md`,
`CREATE-ROOM-GATES-RE.md` §4). With the canonical File#2 cast order Kevin, Mark, Jim,
George, David, Alyssa, Yoko, Cindy, bits 0..4 are exactly the five males.

**Conclusion (Observation + arithmetic, one step of inference on the cast ordering): the
"only male characters" bug is one served byte — `rec+0x03 = 0x1F` should be `0xFF`.**
`CREATE-ROOM-GATES-RE.md` §3a filed `+0x03` as a "scenario-group mask" and §4 filed the
cast symptom as "`0x6D2296` cast count, writer never ran" — both SUPERSEDED: `0x6d2296` is
the RULE-ROW count (§2), and the cast comes from `+0x03`.

---

## 5. The Scenario row — record `+0x14` / `+0x18`

```c
/* FUN_005fe1e0:50126-50176 */
memset(screen+0x4ba, 0xff, 0x40);  screen[0x53a] = 0;
s0 = ((uRam003424e8 >> 1) & FUN_005bae80(area-1)) | FUN_005baed0(area-1);
for (i = 1; i < 12; i++) if (s0 & (1 << (i-1))) { ring[i] = i; count++; }
screen[0x53c] = firstNonNegative(ring);  screen[6] = ring[screen[0x53c]];  screen[4] = 0;
```
`FUN_005bae80` = `rec+0x14`, `FUN_005baed0` = `rec+0x18` (`:11841-11890`). Row 8 renders
`FUN_005bac80(screen+6)` = `func_0x001b6f50(id)` for `id < 12` (`:11708-11727`).

- **Eleven ids (1..11).** `GOALS.md` records the online scenario list as exactly 11
  (WT, UB, FB, DT, EOTR + Elimination×3 + Showdown×3, Training excluded). **Inference**,
  but the count matches the client's `i+1 < 0xc` bound and `FUN_005bac80`'s `< 12` guard.
- **`(null)` explained.** With both masks zero the ring stays `0xFFFF` memset filler
  (savestate `0x6c4b96 = 0xFFFF`, `CREATE-ROOM-GATES-RE.md` §3b) → `FUN_005bac80(-1)` →
  `func_0x001b6f50` returns NULL → `sprintf("%s")` prints `(null)`. The screenshot shows
  `Scenario  (null)`. **Confirmed by three independent artefacts.**
- **`+0x18` is un-gated**, so the server can open the scenario list on a fresh console
  without any savedata. `+0x14` is ANDed with savedata `0x3424e8 >> 1`. This matches the
  owner's ground truth ("all but one scenario available from a fresh save").
- `+0x14` also has a second, savedata-free reader: `FUN_005f78c0:46236-46252` builds a
  6-slot strip from `FUN_005bae80` RAW. Publishing both fields (as `area-table-v1.js:340`
  now does) is therefore right.

**Status of the scenario row: the fix may already be in the tree and is UNVERIFIED.** The
screenshot predates `68b1a59f` (00:13 vs 09:19), and RIG-SESSION-1 R1 reported only the
rule rows. Falsifier: PINE `0x6c4b96` (expect an id 1..11, not `0xFFFF`) and `0x6c4fca`
(= `screen+0x53a`, the ring count) on the create screen.

---

## 6. Served-vs-expected: the byte diff

### 6.1 What we serialize today

`AreaTable#serialize` (`state/area-table.js:718-786`) writes, per `0x1e4` record:
`+0x00` BE32 lead word · `+0x14`/`+0x18` BE32 masks · `+0x1c` name · `+0x34` second line ·
`+0x4c` description · `+0x14c` enable · `+0x16c`/`+0x1a8` two bytes each. **Everything
else is zero**, including `+0x16b`, block `+0x02` and block `+0x2b`.

| record offset | today | consequence |
|---|---|---|
| `+0x03` | `0x1F` (from the BE32 lead word) | only 5 of 8 characters |
| `+0x04..0x13` | `00`×16 | no extra cast even for a console that unlocked it |
| `+0x14`,`+0x18` | Free `0x7ff`, themed `0x00f`, Elim/Showdown `0x003`, disabled `0` | scenario list, not rules |
| `+0x14d`,`+0x15d` | zero | no default title / password (only matters when `+0x16b` bits are clear) |
| `+0x16b` | `0x00` | **Room Title RED, Password RED** |
| `+0x16c` / `+0x1a8` byte0 | `0xB0` | players row present, **RED**, 4 choices, shows "1" |
| `+0x16d` / `+0x1a9` byte1 | `0x81` | waiting row present, **RED**, 1 choice, value out of range → **blank** |
| block `+0x02` (`+0x16e`/`+0x1aa`) | `0x00` | **no Difficulty / Friendly Fire / Nightmare / Infinity rows at all** |
| block `+0x2b` (`+0x197`/`+0x1d3`) | `0x00` | no server-authored rows (fine; we have no label content) |

Every symptom on the screenshot is on this list.

### 6.2 What reproduces the owner's stated behaviour

Mapping `RuleSet.java`'s per-area tables (areas 1..10 are a 1:1 match with our ten —
`Areas.java:33-42` vs `area-table-v1.js:182-254`) onto the PAL rows:

| bioserver rule | PAL row | source |
|---|---|---|
| `number of players` (changeable 1) | built-in row 0 | block byte0 |
| `wait limit` (changeable 1) | built-in row 1 | block byte1 |
| `difficulty level` (changeable 1, value 3) | group-1 descriptor, label record **1** | block `+0x03` |
| `friendly fire` | group-1 descriptor, label record **2** | block `+0x03` |
| `nightmare` | group-1 descriptor, label record **5** | block `+0x03` |
| `infinity` | group-1 descriptor, label record **6** | block `+0x03` |

**Per-area bytes.** Both blocks (`+0x16c` and `+0x1a8`) get identical content until §7 is
settled.

Common to every area:

```
+0x03                = FF                     ; all 8 base characters
+0x04..0x13          = FF x16                 ; permit any extra cast the save unlocked
+0x16b               = 03                     ; title + password settable
block +0x00 (players)= F3                     ; present|changeable|max=3|min=0|default=3  -> "4"
block +0x01 (waiting)= E2                     ; present|changeable|count-1=4|default=2    -> "10 minutes"
```

`0xE2` is exact, not chosen: the live PINE read of `DAT_00640530` = `{5400, 9000, 18000,
27000, 54000}` ticks = `{3, 5, 10, 15, 30}` minutes (**Observation**, owner-supplied) is
five entries, byte-identical to `RuleSet.getWaitTime()` — so `choiceCount-1 = 4` (bits
5-3 = `100`) and bioserver's default index 2 ("ten minutes") gives bits 2-0 = `010`.

Per-area group-1 block (`+0x02` = count, `+0x03` = descriptors, 4 bytes each,
`{record, value, present, changeable}`):

| # | area | `+0x02` | descriptors at block `+0x03` | rows on screen |
|---|---|---|---|---|
| 1 | Free Area | `01` | `01 03 01 01` | 3 rows, **all white** |
| 2 | Nightmare | `02` | `01 03 01 01` `05 01 01 00` | Nightmare fixed ON (red) |
| 3 | Survival | `02` | `01 03 01 01` `02 01 01 00` | Friendly Fire fixed ON (red) |
| 4 | Panic | `03` | `01 03 01 01` `02 01 01 00` `05 01 01 00` | two red rows |
| 5 | Infinity | `04` | `01 03 01 01` `02 00 01 01` `05 00 01 01` `06 01 01 00` | ff/nm white, Infinity red — 6 rows total |
| 6 | reserved | `01` | `01 03 01 01` | (area disabled anyway) |
| 7 | TESTING | `01` | `01 03 01 01` | all white |
| 8 | Elimination | `01` | `01 03 01 01` | all white |
| 9 | Showdown | `01` | `01 03 01 01` | all white |
| 10 | SECRET | `01` | `01 03 01 01` | (area disabled anyway) |

That is exactly the owner's criterion: players / waiting time / title / password / scenario
settable everywhere; Free (and every plain area) has **no** fixed rule row; areas 2-5 carry
the fixed ones bioserver marks `changeable = 0`.

Grades: the **descriptor layout, the changeable byte and the row/label indices are
Confirmed.** The **value bytes** are: `03` for Difficulty = `VERY HARD` **Confirmed** (the
string sits at label record 1 `+0x80` = entry 3, `netwk-strings:0x8dfc0`); `01` for
ON and `00` for OFF on the ff/nm/infinity rows is **Likely** (bioserver's `off, on`
ordering; the choice strings are shorter than the string dump's filter so they could not be
read directly). A wrong index renders a blank value, never a crash — the same failure mode
the Waiting Time row shows today, which is a cheap, visible falsifier.

Scenario masks: until the id↔title map is recovered (§8.1), serve `+0x14 = +0x18 = 0x7FF`
on every ENABLED area. The current per-area narrowing (`0x00f`, `0x003`) was chosen under
the belief these were rule masks; as scenario masks those values are arbitrary and would
hide most scenarios in six of eight enabled areas.

Anything that changes any of these bytes MUST bump the version string
(`area-table-v1.js:280/290`) — `FUN_001c4960.c:46-49` skips the fetch on a version match.

---

## 7. The one genuine conflict: block byte 1 has two incompatible decodes

`FUN_005c3490:18139-18165` reads the SAME block bytes a second time, and the two branches
of `FUN_005c4f00()` disagree with each other **and** with the row builder:

| | `FUN_005c4f00() == 0` (`bRam006ce5cf == 1`) | `!= 0` (`>= 2`) |
|---|---|---|
| players | `uRam006ca888 = DAT_00640528[user's choice]` — honours the row | `= DAT_00640528[max]`; min/max published to `0x7006a4/a5` — **ignores the row** |
| waiting | `iRam006febf0 = DAT_00640530[byte1 & 7]` — matches the row decode | `uRam007006a6 = byte1 & 0x3f; ticks = that * 300` — **different field width** |

With `byte1 = 0xE2`: branch 0 gives `DAT_00640530[2] = 18000` ticks = **10 minutes,
correct**. Branch 1 gives `0x22 * 300 = 10200` ticks ≈ 5.7 minutes — and there is no byte
that satisfies both (60 units for 10 minutes = `0x3C` would make the row list 8 choices
long against a 5-entry label record, reading past its end).

**Hypothesis (consistent, not forced):** `bRam006ce5cf` is the LOBBY index within the area
(`FUN_005bf1e0(1)`; the triple `006ce5ce/cf/d0` is set as area/lobby/slot by
`FUN_005c0e30:16474-16480` and forced to `1,1,1` by `FUN_005c22a0:17300-17308`), and the
design is *lobby 1 = the configurable lobby (block 0, rows honoured), lobby ≥ 2 = fixed-rule
lobbies (block 1, values applied directly, rows red)*. If so, block 0 is the one that
matters and writing both identically is harmless-but-wrong for block 1.

**This is unresolved and it is the one thing that could make the fix look like it failed.**
It is settled by one PINE read at the create screen: `bRam006ce5cf` (expect 1) plus
`cRam007006a5` (max players; written only on branch 1). `COLD-START-2026-08-08.md` B4
already flags this read as outstanding; our Area-Select read of `bRam006ce5cf = 0` was
taken on the wrong screen (0 = "not in a lobby" ⇒ `FUN_005c4f00` returns `-1`, an
out-of-record read) and does not answer it.

---

## 8. Needs fresh Ghidra decompile (prioritised)

1. **`func_0x001b6f50` + its table** — scenario id → title, for ids 1..11. Without it we
   cannot narrow `+0x18` per area (Elimination/Showdown), only serve `0x7FF`.
2. **`func_0x001b6950` + its table** — character id → name, to pin which bit of `rec+0x03`
   is which character. The `0xFF` fix does not depend on it; per-area cast limits would.
3. **The netwk label records at file `0x8de20 + i*0x120`** — read byte `+0x1f` and entries
   for records 1, 2, 5, 6. Turns the `01`/`00` value bytes from Likely to Confirmed.
4. **`FUN_005af2c0`** — `halt_baddata()` in the dump; confirms colour index 2 = red.
5. **`FUN_0062fea0`** — the UI string table, to confirm labels 9/`0x0a`/`0x0b`/6/`0x14`.
6. **Writers of `bRam006ce5cf`** (`FUN_005bf0e0` call sites: `FUN_005bfb40`, `FUN_005bfd80`,
   `FUN_005c05c0`, `FUN_005c0400`, `FUN_005c1c80`) — settles §7 statically.
7. **`0x3c4d50`** (`0xc` stride, u16 id, terminator 999) — the extra-cast id table.
8. **`FUN_005c4600`** (sole caller of `FUN_005c3b10`) — where the room-list summary line is
   composed, if we ever author group-2 labels.

---

## 9. Highest-leverage next experiment

**One data-only change, no protocol risk, one rig pass.** Add to `area-table-v1.js`:
`+0x03 = 0xFF`, `+0x04..0x13 = 0xFF`, `+0x16b = 0x03`, block bytes `F3 E2`, group-1 count
+ descriptors per §6.2 (both blocks), `+0x14 = +0x18 = 0x7FF` on enabled areas, and **bump
the version string to `OBAREA-V5`**. Power-cycle the PS2 (a cached version silently skips
the fetch and fakes a negative).

Pass/fail on one screen:

| what to look at | pass |
|---|---|
| Room Title / Password rows | white, cursor lands on them |
| No. of Players | white, shows `4`, left/right changes it |
| Waiting Time | white, shows `10 minutes`, five choices |
| a new `Difficulty` row | present, white, `VERY HARD` |
| Nightmare area | extra `NIGHTMARE` row, RED, value `on` |
| Character | all 8 selectable |
| Scenario | a real title, not `(null)` |

PINE cross-checks (they discriminate a data error from a delivery error):
`bRam006ce5cf` (§7), `cRam006d2296` = row count, `*(u8*)(0x697138 + i*0x14a8)` = 1 per
settable row, `bRam006970f4` = rows in the UI model, `0x6c4b9a` = cast-ring count,
`0x6c4b96` = scenario id.

If the rows stay red while `0x697138` reads 1, the defect is in the renderer path, not the
data. If `cRam006d2296` stays 2 while we ship a non-zero group-1 count, the client is on
the other block (§7) or the blob was cached.
