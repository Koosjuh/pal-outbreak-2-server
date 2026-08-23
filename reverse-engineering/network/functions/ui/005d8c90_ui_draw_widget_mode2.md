# 0x005d8c90 ui_draw_widget_mode2

| field | value |
|---|---|
| Original address | 0x005d8c90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d8c90 |
| Resolved name | ui_draw_widget_mode2 |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eca10
**Callees:** FUN_005cab10, FUN_005da650
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sets the draw region and renders a mode-2 overlay widget via FUN_005cab10.

## Notes / uncertainty
Unconditional style-2 draw + viewport extend (FUN_005da650). Style-2 visual meaning not enumerated. Non-protocol.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d8c90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
