# 0x005ca480 room_popup_menu_action_result1

| field | value |
|---|---|
| Original address | 0x005ca480 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca480 |
| Resolved name | room_popup_menu_action_result1 |
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
State-10 handler: sets uRam00701e18=1 (a menu-result selector) and pops via FUN_005d5b60; state-8 runs the roster pass.

## Notes / uncertainty
Two-choice popup resolver twin: ACTION sets 0x701e18=1 then dismiss (005d5b60). Semantic meaning of result 1 vs 2 depends on undecoded 0x701e18 consumer.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca480.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
