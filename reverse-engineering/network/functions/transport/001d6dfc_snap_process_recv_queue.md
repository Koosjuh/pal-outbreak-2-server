# 0x001d6dfc snap_process_recv_queue

| field | value |
|---|---|
| Original address | 0x001d6dfc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d6dfc |
| Resolved name | snap_process_recv_queue |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d72a8
**Callees:** FUN_001d9f78, FUN_001eb2d4, FUN_001eb434, FUN_001ec9e0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x68 delivered-message queue

## Behavioral explanation
Drains the reassembled reliable-in queue (conn+0x68), handing each completed message to the app-dispatch (001d9f78) and freeing it.

## Notes / uncertainty
Drains in-order ready queue conn+0x68, dispatches each msg to app handler FUN_001d9f78, frees to conn+0x520. -0x1b56 empty sentinel. Consumer of the delivery gate's output; loop continues on successful free.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d6dfc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
