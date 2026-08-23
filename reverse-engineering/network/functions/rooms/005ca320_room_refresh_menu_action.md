# 0x005ca320 room_refresh_menu_action

| field | value |
|---|---|
| Original address | 0x005ca320 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca320 |
| Resolved name | room_refresh_menu_action |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ca6a0, FUN_005cce30, FUN_005d59f0
**Referenced globals:** 0x701070+0x2e sub-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x2e

## Behavioral explanation
State-10 handler that invokes FUN_005d59f0 (a room send/refresh); state-8 runs the roster pass.

## Notes / uncertainty
Same family; ACTION->FUN_005d59f0 (room refresh/re-request), SCAN->roster scan. Whether 005d59f0 issues an op49 wire re-query vs local refresh not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca320.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
