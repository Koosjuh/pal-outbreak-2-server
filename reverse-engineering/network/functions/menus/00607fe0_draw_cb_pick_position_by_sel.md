# 0x00607fe0 draw_cb_pick_position_by_sel

| field | value |
|---|---|
| Original address | 0x00607fe0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00607fe0 |
| Resolved name | draw_cb_pick_position_by_sel |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** 0x0064a0d0 static-coord-table; 0x006c5497 sel-index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c5497

## Behavioral explanation
Copies a 2.5-entry static table from 0x64a0d0 to stack, sets draw flags on param, and picks a value indexed by sel 6c5497 (clamped 0-10).

## Notes / uncertainty
Draw callback selecting node+0x2c color/position from static table 0x64a0d0 by sel 0x6c5497 (clamp 10), attr bit 0x80. NO corpus callers -> possibly dead/indirect; liveness and table semantics unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00607fe0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
