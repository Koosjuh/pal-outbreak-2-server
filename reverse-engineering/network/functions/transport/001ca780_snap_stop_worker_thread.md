# 0x001ca780 snap_stop_worker_thread

| field | value |
|---|---|
| Original address | 0x001ca780 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ca780 |
| Resolved name | snap_stop_worker_thread |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001cac60
**Referenced globals:** 0x3688e0=stop flag; 0x248860=done sema; 0x248858=thread id
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Signals the transport worker thread to exit, waits on and deletes its completion semaphore, and invalidates the thread/sema handles.

## Notes / uncertainty
Joiner side of worker shutdown: sets stop flag 0x3688e0, releases mutex, WaitSema on done-sema 0x248860, deletes it, invalidates sema+thread-id to -1. Pairs with worker teardown in 0x1ca810.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ca780.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
