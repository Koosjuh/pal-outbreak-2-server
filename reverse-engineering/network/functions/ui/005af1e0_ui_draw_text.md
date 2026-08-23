# 0x005af1e0 ui_draw_text

| field | value |
|---|---|
| Original address | 0x005af1e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005af1e0 |
| Resolved name | ui_draw_text |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac4c0, FUN_005ae510, FUN_005ae630, FUN_005ae9b0, FUN_005af4d0, FUN_005affb0, FUN_005b08f0, FUN_005b1e80, FUN_005b20c0, FUN_005b29b0, FUN_005b2bc0, FUN_005b3590, FUN_005b4da0, FUN_005b76f0, FUN_005b86c0, FUN_005b8880, FUN_005b8b60, FUN_005b9150, FUN_005ba2e0, FUN_005ba4c0, FUN_005ba520, FUN_005ba5b0, FUN_005ba8d0, FUN_005baa70, FUN_005f54d0, FUN_005f6610, FUN_005f6790, FUN_005f6d20, FUN_005f70b0, FUN_005f84c0, FUN_005f85e0, FUN_005fbbf0, FUN_005fcc70, FUN_005fd9e0, FUN_00601c00, FUN_00601d50, FUN_00602340, FUN_00603940, FUN_00604e70, FUN_006050d0, FUN_00605690, FUN_00605790, FUN_00605a90, FUN_006076c0, FUN_006080d0, FUN_00617fa0, FUN_00628860, FUN_00628cc0, FUN_00629d60, FUN_0062b8b0, FUN_0062f5b0, FUN_0062fa80
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Core text/sprite print primitive: selects a color/palette from param_3 (0-3), sets pen position (x=param_1,y=param_2) and draws the string/asset param_4 via the low-level 0x1af0xx draw routines.

## Notes / uncertainty
Universal draw primitive (52 callers): selector 0-3 picks color-slot arg (-34/-18/-2/-30) then enable+set-pen+emit; >3 skips color. Color-to-visible mapping inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005af1e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
