# 0x001cae70 snap_dispatch_tick

| field | value |
|---|---|
| Original address | 0x001cae70 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cae70 |
| Resolved name | snap_dispatch_tick |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ca810
**Callees:** FUN_001cac50, FUN_001cac60, FUN_001d72a8
**Referenced globals:** 0x35b9e0=snap handle; 0x3688d0=dispatch result
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x3688d0/d8=guards

## Behavioral explanation
Runs one iteration of the core SN@P datagram dispatcher (FUN_001d72a8) under the transport mutex, storing its result.

## Notes / uncertainty
One-shot guarded core-dispatcher (FUN_001d72a8) tick under a cac50/cac60 critical section; unknown who clears the 0x3688d0/d8 latches.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cae70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
