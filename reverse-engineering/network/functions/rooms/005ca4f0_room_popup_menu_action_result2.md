# 0x005ca4f0 room_popup_menu_action_result2

| field | value |
|---|---|
| Original address | 0x005ca4f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca4f0 |
| Resolved name | room_popup_menu_action_result2 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ca6a0, FUN_005cce30, FUN_005d5b60
**Referenced globals:** 0x701e18 menu-result sel; 0x701070+0x2e sub-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x2e; 0x701e18

## Behavioral explanation
State-10 handler: sets uRam00701e18=2 and pops via FUN_005d5b60; state-8 runs the roster pass.

## Notes / uncertainty
Byte-identical twin of 005ca480 except stores 0x701e18=2. Same consumer-semantics uncertainty.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca4f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
