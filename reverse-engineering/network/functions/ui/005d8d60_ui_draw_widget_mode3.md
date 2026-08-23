# 0x005d8d60 ui_draw_widget_mode3

| field | value |
|---|---|
| Original address | 0x005d8d60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d8d60 |
| Resolved name | ui_draw_widget_mode3 |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ed6e0
**Callees:** FUN_005cab10, FUN_005da650
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sets the draw region and renders a mode-3 overlay widget via FUN_005cab10 with fixed color/size.

## Notes / uncertainty
Unconditional style-3 rect draw, default color sentinel 0xffffffffff000001 / size 0x10. Style-3 vs -4 visual difference unknown. Non-protocol.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d8d60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
