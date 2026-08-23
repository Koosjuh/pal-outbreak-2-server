# 0x005f6610 draw_footer_row_cb

| field | value |
|---|---|
| Original address | 0x005f6610 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f6610 |
| Resolved name | draw_footer_row_cb |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_0062fdf0
**Referenced globals:** 0x649740 (x-coord table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+4 (init/step); param+2 (variant flag)

## Behavioral explanation
Display-list draw callback for a footer/status row: sets palette+coords from 0x649740, and on flag+2==0 iterates a glyph table (FUN_0062fdf0(9)) drawing text, else positions a small box (+0x40..+0x46).

## Notes / uncertainty
Footer-row draw node with two variants (text glyph-loop vs scrolling 0x40 box). Meaning of the two variants and owner+8 enable-gate inferred; leading colA/colB set looks like decompiler loop-head duplication.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f6610.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
