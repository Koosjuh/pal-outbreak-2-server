# 0x001cac50 snap_lock

| field | value |
|---|---|
| Original address | 0x001cac50 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cac50 |
| Resolved name | snap_lock |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ca720, FUN_001caa30, FUN_001caad0, FUN_001cab70, FUN_001cadc0, FUN_001cae70
**Callees:** —
**Referenced globals:** 0x248848=mutex sema
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Acquires the transport mutex (WaitSema on 0x248848).

## Notes / uncertainty
Transport mutex acquire: WaitSema(0x248848). Serializes ring/send state between app and worker threads.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cac50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
