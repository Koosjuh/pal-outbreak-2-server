# 0x001ca750 snap_unlock_if_running

| field | value |
|---|---|
| Original address | 0x001ca750 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ca750 |
| Resolved name | snap_unlock_if_running |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001cac60
**Referenced globals:** 0x248858=worker thread id
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Releases the transport mutex (FUN_001cac60/SignalSema) only if the worker thread is running.

## Notes / uncertainty
Guarded unlock: SignalSema(mutex) only if worker running. Mirror of 0x1ca720.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ca750.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
