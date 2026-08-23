# 0x005e1670 draw_window_9slice

| field | value |
|---|---|
| Original address | 0x005e1670 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e1670 |
| Resolved name | draw_window_9slice |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dc010, FUN_005e4b00, FUN_005e4f10, FUN_005e5200, FUN_005e5650
**Callees:** FUN_005ddb40, FUN_005e00e0
**Referenced globals:** sprite sheet 0 via FUN_005e00e0
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Draws a 9-slice window panel (4 corners + 4 edges + center) from sprite sheet 0 via nine FUN_005ddb40 blits.

## Notes / uncertainty
9-slice dialog panel from sheet 0: 4 corners(32px)+4 stretched edges+center, spans w-64/h-64. Two corner blits omit explicit UV in decompile (reg reuse); no sub-64px clamp.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e1670.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
