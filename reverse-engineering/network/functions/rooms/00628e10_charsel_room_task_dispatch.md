# 0x00628e10 charsel_room_task_dispatch

| field | value |
|---|---|
| Original address | 0x00628e10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00628e10 |
| Resolved name | charsel_room_task_dispatch |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f76f0, FUN_005f8d40, FUN_005fe620
**Callees:** FUN_00628f00, FUN_00628f70, FUN_006290e0, FUN_00629200, FUN_00629330, FUN_00629370, FUN_006293b0, FUN_006293f0, FUN_006296a0
**Referenced globals:** 0x695cf8 charsel-substate
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam00695cf8 substate

## Behavioral explanation
Per-frame task dispatcher for the character/room-select machine: runs sub-state uRam00695cf8 (cases 0-8) across select/confirm/register/password sub-steps.

## Notes / uncertainty
Exact 9-case switch on uRam00695cf8. Steps 3-6 (29200/29330/29370/293b0) roles not individually decoded (out of slice).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00628e10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
