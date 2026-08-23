# 0x001eb8d0 list_unlock

| field | value |
|---|---|
| Original address | 0x001eb8d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb8d0 |
| Resolved name | list_unlock |
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
Releases the list lock by invoking the lock callback with cmd 2.

## Notes / uncertainty
Wrapper: lock_invoke(list,2) release; symmetric with list_lock.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb8d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
