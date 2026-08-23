# 0x005c8bc0 state_handler_msg_to_error

| field | value |
|---|---|
| Original address | 0x005c8bc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c8bc0 |
| Resolved name | state_handler_msg_to_error |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005d8340
**Referenced globals:** 0x701070+1 (state); 0x700fe0=-1 (result); 0x700fe8
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+1

## Behavioral explanation
State handler: on any dequeued message, sets result=-1 and advances to state 3 (error/leave path).

## Notes / uncertainty
Transport SM fail state: any dequeued reply -> result 0x700fe0=-1, major-state 3 (error/leave). Guard/NAK role uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c8bc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
