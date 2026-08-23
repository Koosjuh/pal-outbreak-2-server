# 0x005e91f0 tag_apply_if_name_matches_1528

| field | value |
|---|---|
| Original address | 0x005e91f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e91f0 |
| Resolved name | tag_apply_if_name_matches_1528 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (address-taken; dispatched from the markup tag table — the anchor "apply/close" tag)
**Callees:** func_0x00109d70 (strcmp); FUN_005ee470 (anchor-draw)
**Referenced globals:** markup-ctx base `iRam007012a0`; field `+0x1528` (16-byte name);
`DAT_00648370` (256-byte case-fold/remap table); `DAT_00648510` (reference keyword string)
**Referenced strings:** reference keyword @0x648510
**Referenced opcodes:** —
**State vars:** ctx+0x1528

## Behavioral explanation
The "apply" handler for an anchor/link tag. It normalizes the 16-byte name attribute at
`ctx+0x1528` in place — each of the 16 bytes is remapped through the 256-entry table
`DAT_00648370` (a case-fold / character-canonicalization table) — then compares the
result against the fixed reference keyword at `0x648510` with `strcmp`. On an exact match
(`strcmp == 0`) it invokes `FUN_005ee470`, which walks the 16-slot record array at
`ctx+0xea81` (stride 0x104), finds the record whose name equals `ctx+0xfac1`, and draws
its highlight rectangle (offset by the `rect` tuple `+0x1538..+0x153e`) with the two
strings `+0x1428`/`+0x1328`. Net effect: when the parsed tag name equals the expected
keyword, the corresponding on-screen link region is rendered.

## Input / output
- Input: none (void) — reads global `ctx+0x1528`.
- Output: `undefined8` 0 (consumed).

## Side effects
- Mutates `ctx+0x1528` in place (case-folds all 16 bytes).
- Conditionally calls `FUN_005ee470` → draws a region via `FUN_005d9790`.

## Important branches
- Fixed 16-iteration remap loop (`iVar3 = 0 .. 0xf`) — unconditional canonicalization.
- `strcmp(ctx+0x1528, ref@0x648510) == 0` → call `FUN_005ee470`; non-zero → return without drawing.
- Inside `FUN_005ee470`: guards `ctx+0x186 == 0` AND `ctx+0xe96b == 0` (draw-enabled flags),
  then scans up to 16 records for a name match before drawing.

## Constants & flags
- Remap table `DAT_00648370` (0x100 bytes) = per-byte canonicalization (case fold).
- Reference string `DAT_00648510` = the keyword this tag matches.
- `0x10` = name-field width; `0x104` = record stride in the `+0xea81` array; `0x80` in
  `FUN_005ee470`'s final draw arg = a draw-mode/style flag OR'd into the color id.

## Corrected reconstruction
```c
/* Anchor "apply" tag: if the (case-folded) name attribute equals the fixed keyword,
   render the matching link region. */
undefined8 tag_apply_if_name_matches_1528(void)
{
    u8 *name = (u8*)g_markup_ctx + 0x1528;
    for (int i = 0; i < 0x10; i++)                 /* canonicalize in place */
        name[i] = g_casefold_table_648370[name[i]];/* DAT_00648370 */

    if (strcmp(name, REF_KEYWORD_648510) == 0)     /* func_0x00109d70 == 0 */
        draw_matching_anchor();                    /* FUN_005ee470 */
    return 0;
}
```

## Evidence
- Raw: fixed loop `*(u8*)(base+i+0x1528) = (&DAT_00648370)[*(u8*)(base+i+0x1528)]`;
  `func_0x00109d70(base+0x1528, 0x648510)`; `if (== 0) FUN_005ee470()`.
- `FUN_005ee470` reads `+0xfac1`, scans `+0xea81` (0x104 stride), draws via `FUN_005d9790`
  with rect offsets `+0x1538..+0x153e` and strings `+0x1428`/`+0x1328`.
- Runtime-unvalidated.

## Remaining uncertainty
Literal text of the reference keyword (`0x648510`) not resolved in this pass; the
match-then-draw control flow is certain. `DAT_00648370` assumed a case-fold table by shape.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e91f0.c`  — untouched decompiler output.
