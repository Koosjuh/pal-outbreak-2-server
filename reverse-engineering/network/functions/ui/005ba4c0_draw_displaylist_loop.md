# 0x005ba4c0 draw_displaylist_loop

| field | value |
|---|---|
| Original address | 0x005ba4c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ba4c0 |
| Resolved name | draw_displaylist_loop |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628860, FUN_00629c20
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Iterates a display-descriptor array (stride 0xc): for each entry set palette(+2)/mode(+1) and draw(+4 x,+6 y,+3 size,+8 str) until the terminator entry (+0 != 0).

## Notes / uncertainty
Generic descriptor-list draw (stride 0xc, +0!=0 terminator); same row_desc layout as the tick callbacks. Self-contained primitive, behavior certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ba4c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
