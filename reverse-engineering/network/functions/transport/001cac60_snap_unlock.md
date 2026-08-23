# 0x001cac60 snap_unlock

| field | value |
|---|---|
| Original address | 0x001cac60 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cac60 |
| Resolved name | snap_unlock |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ca750, FUN_001ca780, FUN_001caa30, FUN_001caad0, FUN_001cab70, FUN_001cadc0, FUN_001cae70
**Callees:** —
**Referenced globals:** 0x248848=mutex sema
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Releases the transport mutex (SignalSema on 0x248848).

## Notes / uncertainty
Transport mutex release: SignalSema(0x248848). Also used by stop-thread to hand mutex to worker.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cac60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
