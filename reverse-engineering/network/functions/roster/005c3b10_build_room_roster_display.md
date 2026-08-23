# 0x005c3b10 build_room_roster_display

| field | value |
|---|---|
| Original address | 0x005c3b10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c3b10 |
| Resolved name | compose_room_config_glyph_line |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c4600
**Callees:** FUN_005bf1e0 (selector read), FUN_005c4f00 (page/column selector), FUN_005c2ae0 (0x3c-stride template ptr), FUN_005c2e90 (label glyph-table ptr), FUN_005c2ad0 (2nd glyph-table ptr), FUN_005c3c40 (glyph blit)
**Referenced globals:** 0x6cc044/0x6cc045 (active player-slot byte array); 0x6d2296 (`bRam006d2296`, slot count); label tables via 0x34359d (scenario id) & 0x368474 (+0x12fc)
**Referenced strings:** indirectly `No. of Players` / `defficulity control` (via FUN_005c2e90 pointer tables)
**Referenced opcodes:** —
**State vars:** cRam0034359d (scenario/difficulty id), bRam006ce5ce/6ce5cf (selector state)

## Behavioral explanation
This is **not** a member-roster row builder — it composes the room-detail **config line** (player-count
/ difficulty style header) into the caller's display buffer using a **glyph-tile font**. Flow:
1. Fetch the current list selector `sel = FUN_005bf1e0(0)` and a page/column selector `col = FUN_005c4f00()`.
2. Resolve a 0x3c-byte **template record** `tmpl = FUN_005c2ae0(sel-1, col)` (base + idx*0x3c + 0x16c).
3. Gather the active player-slot bytes into a 0x20 stack buffer `slots[]`: source pointer starts at
   0x6cc044 and length at `bRam006d2296`; if `tmpl[0]` bit7 set, advance source to 0x6cc045 and
   decrement length; if `tmpl[1]` bit7 set, advance source +1 and decrement length again; clamp length
   to ≥0; copy that many bytes.
4. Emit **section 1**: `used = FUN_005c3c40(dst, slots, tmpl[2], &tmpl[3], FUN_005c2e90(1))` — lays out
   `tmpl[2]` fields from descriptor list `&tmpl[3]` using the difficulty/label glyph table, consuming
   `used` variable bytes from `slots[]`.
5. Emit **section 2**: `FUN_005c3c40(dst, slots+used, tmpl[0x2b], &tmpl[0x2c], FUN_005c2ad0())` — the
   second field group, resuming at `slots[used]`, using the 0x368474+0x12fc glyph table.

Each `FUN_005c3c40` field is 4 bytes {glyphset, literal, is_variable, ?}: if `is_variable` it pulls the
next byte from `slots[]`, else uses the literal; then blits a glyph bitmap (0x20 bytes/glyph) from the
glyph-set record (stride 0x120; dst offset at +0x1d, length at +0x1e, bitmap base at +0x3e) into `dst`.

## Input / output
- `param_1` (u8* `dst`): display/tile buffer to compose into (per prior note the room-detail target near 0x6fb76b).
- Returns void.

## Side effects
Writes composed glyph tiles into `*dst`. Reads scenario/selector globals and the player-slot array;
no global writes here (the source arrays are populated upstream).

## Important branches
- `tmpl[0] bit7` → shift source to 0x6cc045 and `len--` (skip a leading slot; likely host/self slot).
- `tmpl[1] bit7` → source++ and `len--` (skip a second slot).
- `(char)len < 0` → `len = 0` (underflow clamp after the two decrements).
- copy loop bounded by `len` into the fixed 0x20 buffer (no explicit cap vs 0x20 — trusts len ≤ 0x20).
- Inside FUN_005c3c40: `descriptor[2]==0` → literal `descriptor[1]`; else variable byte from `slots[]`
  with wraparound index `& 0xff`.

## Constants & flags
- `0x3c` (60) — template record stride; `+0x16c` base offset within its table.
- `0x20` (32) — glyph bitmap size and stack buffer size.
- `0x120` (288) — glyph-set descriptor stride; `+0x1d` dst offset, `+0x1e` length, `+0x3e` bitmap base.
- bit7 (`>>7 & 1`) — the two template flags gating slot-skip.
- `0x12fc` — offset of section-2 glyph table from 0x368474.
- FUN_005c4f00 result domain: `bRam006ce5cf==1 → 0`, `<2 → -1`, else `1`.
- FUN_005c2e90 label index from `cRam0034359d` (2→1,3→2,4→3,5→4, else 0); arg 0 → `No. of Players` table, else `defficulity control` table.

## Corrected reconstruction
```c
// Compose the room-detail config line (player-count / difficulty) into `dst` as glyph tiles.
// Exact control flow preserved; field semantics [inferred].
void compose_room_config_glyph_line(u8 *dst /*param_1*/) {
    short sel = (short)get_selector(0);          // FUN_005bf1e0(0) -> bRam006ce5ce
    u16   col = FUN_005c4f00();                  // page/column selector {-1,0,1}
    char *tmpl = (char*)FUN_005c2ae0(sel - 1, col); // 0x3c template record (+0x16c base)

    u8 slots[0x20];
    memset(slots, 0, 0x20);                      // func_0x00106b60

    int   len = (u8)0x6d2296;                    // bRam006d2296 slot count [inferred]
    char *src = (char*)0x6cc044;
    if ((tmpl[0] >> 7) & 1) { src = (char*)0x6cc045; len = (len - 1) & 0xff; } // skip slot 0 [inferred host]
    if ((tmpl[1] >> 7) & 1) { src += 1;            len = (len - 1) & 0xff; }
    if ((char)len < 0) len = 0;
    for (int i = 0; i < len; i++) slots[i] = src[i];

    // section 1: difficulty/label glyphs, tmpl[2] fields from &tmpl[3]
    u8 used = FUN_005c3c40(dst, slots, tmpl[2], &tmpl[3], FUN_005c2e90(1)) & 0xff;
    // section 2: resume at slots[used], tmpl[0x2b] fields from &tmpl[0x2c]
    FUN_005c3c40(dst, slots + used, tmpl[0x2b], &tmpl[0x2c], FUN_005c2ad0());
}

// glyph blitter (FUN_005c3c40)
u8 emit_glyph_fields(u8 *dst, u8 *vars, u8 count, char *desc /*4B each*/, u8 *glyphset_tbl) {
    u32 vi = 0;
    for (int f = 0; f < (count & 0xff); f++, desc += 4) {
        u8 val = (desc[2] == 0) ? desc[1] : vars[vi++ & 0xff];      // literal vs variable
        u8 *gs = glyphset_tbl + desc[0] * 0x120;                    // glyph-set record
        for (int b = 0; b < gs[0x1e]; b++)                          // length
            dst[gs[0x1d] + b] = gs[0x3e + val * 0x20 + b];          // blit 0x20-glyph bitmap
    }
    return vi;
}
```

## Evidence
- Raw: `FUN_005c3b10.c` (control flow above) and `FUN_005c3c40.c` (glyph blit inner loop, stride 0x120, +0x1d/+0x1e/+0x3e).
- Callee semantics: `FUN_005bf1e0.c` (selector 0/1/2 → 0x6ce5ce/cf/d0), `FUN_005c4f00.c` (0x6ce5cf → {-1,0,1}), `FUN_005c2ae0.c` (idx*0x3c+0x16c), `FUN_005c2e90.c` (`No. of Players`/`defficulity control` label tables keyed on 0x34359d), `FUN_005c2ad0.c` (0x368474+0x12fc).

## Remaining uncertainty
- Exact identity of the 0x3c template record and the 0x6cc044 slot array (player character-ids vs. seat
  states) is inferred, not runtime-confirmed.
- Which on-screen field this line renders (room header vs. an entry cell) not proven; caller FUN_005c4600
  context and the 0x6fb76b target are the strongest clues.
- `bRam006d2296` typed as u8 count is inferred; the decompile reads it as a byte.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c3b10.c`  — untouched decompiler output.
