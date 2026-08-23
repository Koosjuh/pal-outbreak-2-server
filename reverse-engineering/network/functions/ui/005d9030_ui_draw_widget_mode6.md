# 0x005d9030 ui_draw_widget_mode6

| field | value |
|---|---|
| Original address | 0x005d9030 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d9030 |
| Resolved name | ui_draw_widget_mode6 |
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
Sets the draw region, measures a string (func_0x0010a050), and renders a mode-6 overlay widget via FUN_005cab10.

## Notes / uncertainty
Style-6 text widget: strlen(param_6) measure before draw. param_5 role and strlen->primitive data path unclear (decompile drops it). Non-protocol.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d9030.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
