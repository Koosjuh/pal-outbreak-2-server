# 0x005f2280 ui_draw_cell_fill

| field | value |
|---|---|
| Original address | 0x005f2280 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f2280 |
| Resolved name | ui_draw_cell_fill |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ebd20
**Callees:** FUN_005d9ac0, FUN_005efae0
**Referenced globals:** +0x186 draw mode; +0xe96b suppress; node+0x1c/+0x1e size, +0x2a y, +0x10 x, +0x45 style, +0x54 color
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xe96b

## Behavioral explanation
In draw mode renders a node's text/label via draw primitive 0x5d9ac0 using computed bounds, color and child style; empties the string buffer when nothing to draw.

## Notes / uncertainty
Renamed from ui_draw_label: paints a table cell fill rectangle (5d9ac0), inherits parent border/color, auto-height flag byte[0x12]. Word-index field names inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f2280.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
