# 0x005ca5c0 room_confirm_transition

| field | value |
|---|---|
| Original address | 0x005ca5c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca5c0 |
| Resolved name | room_confirm_transition |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005cce30, FUN_005d5ba0
**Referenced globals:** 0x701070+0x2e sub-state; 0x701078+2 cursor; 0x701070+2 step
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x2e; 0x701070+2

## Behavioral explanation
State-10: confirm via FUN_005d5ba0 and step to 5; state-8: run roster pass.

## Notes / uncertainty
Kind-dispatched: kind0x0a->confirm(step5), kind0x08->roster pass FUN_005cce30. FUN_005cce30 exact work inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca5c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
