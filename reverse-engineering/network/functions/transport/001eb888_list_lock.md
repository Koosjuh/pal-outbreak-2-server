# 0x001eb888 list_lock

| field | value |
|---|---|
| Original address | 0x001eb888 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb888 |
| Resolved name | list_lock |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ebe64
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Acquires the list lock by invoking the lock callback with cmd 1.

## Notes / uncertainty
Wrapper: lock_invoke(list,1) acquire; no-op returning 0 if no callback at +0x08. Lock discipline set by installer, unresolved.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb888.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
