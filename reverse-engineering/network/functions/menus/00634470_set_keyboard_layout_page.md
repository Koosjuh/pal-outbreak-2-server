# 0x00634470 set_keyboard_layout_page

| field | value |
|---|---|
| Original address | 0x00634470 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00634470 |
| Resolved name | set_keyboard_layout_page |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631910, FUN_006345e0, FUN_00635030, FUN_00637140, FUN_006375d0
**Callees:** —
**Referenced globals:** 0x715da8 (kbd state ptr; +9 page, +0x25 sub, +0x2e key); 0x692404 (cell-index table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+9; 0x715da8+0x25

## Behavioral explanation
Recomputes keyboard glyph/geometry pointers for the current page (piRam+9) and sub-index (+0x25): key char, key-quad base (*+4), pos base (*+0), and 0x24-stride cell base (*+0xc).

## Notes / uncertainty
Recomputes soft-keyboard render pointers for current key: keymap[page*4+sub]->key, then quad(*8)/pos(*6)/deco(*0x24 via 0x692404 remap) tables. LayoutDesc field offsets inferred from strides.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00634470.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
