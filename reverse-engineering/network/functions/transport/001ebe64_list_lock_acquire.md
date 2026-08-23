# 0x001ebe64 list_lock_acquire

| field | value |
|---|---|
| Original address | 0x001ebe64 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebe64 |
| Resolved name | list_lock_acquire |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001eb4dc, FUN_001eb5ac, FUN_001eb688, FUN_001eb888, FUN_001eb8d0, FUN_001eb918
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Invokes the list's lock callback at +8 (passing the lock object at +0x10 and a command code) if one is registered.

## Notes / uncertainty
Renamed from lock_invoke: guarded lock callback at container+0x8 with cmd=1 (ACQUIRE); cmd numbering inferred from sibling callers.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebe64.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
