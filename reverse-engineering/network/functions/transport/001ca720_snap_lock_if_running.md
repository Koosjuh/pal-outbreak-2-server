# 0x001ca720 snap_lock_if_running

| field | value |
|---|---|
| Original address | 0x001ca720 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ca720 |
| Resolved name | snap_lock_if_running |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001cac50
**Referenced globals:** 0x248858=worker thread id
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Takes the transport mutex (FUN_001cac50/WaitSema) only if the worker thread is running.

## Notes / uncertainty
Guarded lock: WaitSema(mutex) only if worker thread id 0x248858 != -1. Trivial.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ca720.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
