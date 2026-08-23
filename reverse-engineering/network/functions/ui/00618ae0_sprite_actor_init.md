# 0x00618ae0 sprite_pair_init_713340

| field | value |
|---|---|
| Original address | 0x00618ae0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00618ae0 |
| Resolved name | sprite_pair_init_713340 |
| Subsystem | ui |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac610, FUN_005ac6f0
**Callees:** func_0x00106b60 (memset)
**Referenced globals:** 0x713340 (fixed sprite object #0), 0x713394 (fixed sprite object #1)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Initializes the two **fixed foreground sprite objects** that live back-to-back at 0x713340 and 0x713394.
`0xa8 = 2 * 0x54`, and `0x713340 + 0x54 = 0x713394`, so the single `memset(0x713340, 0, 0xa8)` clears a
pair of standard 0x54-byte sprite records (the same record layout as the 64-slot table at 0x7133f0). It
then seeds non-zero defaults into both records: white color, a shared texture/draw-context handle
(0xffffffb6 = -74), part index 0, and animation ids 0 and 1 respectively. These two sprites are the pair
later advanced+drawn every frame by `ui_draw_pair_713340` (0x00619220) → `sprite_animate_frame`(0x619270)
→ `sprite_draw_entry`(0x618e30). Domain-agnostic 2D compositor init used to (re)arm a decorative/cursor
sprite pair when a menu/lobby screen is (re)entered.

## Input / output
- Input: none (`void`).
- Output: none (`void`).

## Side effects
Overwrites the 0xa8-byte block at 0x713340 (two sprite records). Field writes below are given relative to
each record base (obj0 = 0x713340, obj1 = 0x713394). Offsets match the sprite struct used table-wide.

| absolute | record.field | value | meaning |
|---|---|---|---|
| 0x713340..+0xa8 | (both records) | 0 | full clear |
| 0x713343 | obj0 +0x03 | 0 | anim id = 0 |
| 0x713397 | obj1 +0x03 | 1 | anim id = 1 |
| 0x71336c | obj0 +0x2c | 0xffffffff | color = opaque white |
| 0x7133c0 | obj1 +0x2c | 0xffffffff | color = opaque white |
| 0x713374 | obj0 +0x34 | 0xffffffb6 (-74) | texture/draw-context handle |
| 0x7133c8 | obj1 +0x34 | 0xffffffb6 (-74) | texture/draw-context handle |
| 0x713362 | obj0 +0x22 | 0 | part-table index = 0 |
| 0x7133b6 | obj1 +0x22 | 0 | part-table index = 0 |

## Important branches
None — straight-line memset + fixed field stores.

## Constants & flags
- `0x54` = sprite record stride (84 bytes); `0xa8` = two records.
- `+0x03` anim id (drives the DAT_006543d0 rate-table index in sprite_animate_frame).
- `+0x22` part-table index into PTR_DAT_0066fdd0 (used by sprite_draw_entry).
- `+0x2c` = RGBA color; `0xffffffff` = opaque white.
- `+0x34` = per-sprite texture/draw-context handle (passed to FUN_00637f90/006381e0); -74 selects a
  specific texture id. [inferred] exact texture.

## Corrected reconstruction
```c
/* 0x00618ae0 — init the fixed foreground sprite pair at 0x713340 / 0x713394.
 * Two adjacent 0x54-byte sprite records (see sprite struct layout). */
#define SPR_STRIDE   0x54
#define SPR_PAIR     ((sprite_t *)0x713340)   /* [0]=0x713340, [1]=0x713394 */

void sprite_pair_init_713340(void)
{
    memset(SPR_PAIR, 0, 2 * SPR_STRIDE);      /* func_0x00106b60 = memset */

    SPR_PAIR[0].anim_id = 0;                  /* +0x03 */
    SPR_PAIR[1].anim_id = 1;                  /* +0x03 */
    SPR_PAIR[0].color   = 0xffffffff;         /* +0x2c white */
    SPR_PAIR[1].color   = 0xffffffff;         /* +0x2c white */
    SPR_PAIR[0].tex_ctx = -74;                /* +0x34 (0xffffffb6) */
    SPR_PAIR[1].tex_ctx = -74;                /* +0x34 */
    SPR_PAIR[0].part_ix = 0;                  /* +0x22 */
    SPR_PAIR[1].part_ix = 0;                  /* +0x22 */
}
```

## Evidence
- Raw decompile: `func_0x00106b60(0x713340,0,0xa8)` = memset; the eight scattered `uRamXXXX = ...` stores.
- Address arithmetic proves the 0xa8 block is exactly two 0x54 records at 0x713340/0x713394; the +0x03,
  +0x22, +0x2c, +0x34 offsets are the same fields read by sprite_animate_frame / sprite_draw_entry /
  ui_draw_pair_713340, cross-confirming the record layout.
- Two callers FUN_005ac610 / FUN_005ac6f0 (screen enter/setup routines). Runtime-unvalidated.

## Remaining uncertainty
Texture handle -74 and the precise on-screen role of the pair (cursor vs. decoration vs. logo) are not
runtime-confirmed. The field writes and struct aliasing are certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00618ae0.c`  — untouched decompiler output.
