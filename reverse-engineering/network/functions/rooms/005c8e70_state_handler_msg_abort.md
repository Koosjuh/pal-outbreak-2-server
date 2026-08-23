# 0x005c8e70 state_handler_msg_abort

| field | value |
|---|---|
| Original address | 0x005c8e70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c8e70 |
| Resolved name | state_handler_msg_abort |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005d5e90, FUN_005d8340
**Referenced globals:** 0x700fe8
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
State handler: on any dequeued message, aborts the current op via FUN_005d5e90(-1).

## Notes / uncertainty
Cancel state: dequeues msg from 0x701068+0x4f97c (5d8340); if present clears 0x700fe8 and aborts op via FUN_005d5e90(-1). Callee semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c8e70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
