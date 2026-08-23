# 0x001ca8c0 snap_worker_thread_init

| field | value |
|---|---|
| Original address | 0x001ca8c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ca8c0 |
| Resolved name | snap_worker_thread_init |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ca810
**Referenced globals:** 0x248868/248860/248848=semas; 0x248858=thread id; 0x3688d0/d8/e0=flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Creates the three transport semaphores (wake/done/mutex) and spawns the worker thread (FUN_001ca810), starting it.

## Notes / uncertainty
Transport bring-up: zeroes 3 state globals, creates 3 binary semaphores (0x248868/60/48), creates+starts worker thread FUN_001ca810 (stack 0x2000, prio 4). Wake/done/mutex role assignment inferred, not traced.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ca8c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
