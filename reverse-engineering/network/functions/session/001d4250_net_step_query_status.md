# 0x001d4250 net_step_query_status

| field | value |
|---|---|
| Original address | 0x001d4250 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d4250 |
| Resolved name | net_step_query_status |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001f1fe0
**Referenced globals:** 0x36d570 connection-active flag; 0x36d598 handle
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam0036d570; uRam0036d598

## Behavioral explanation
State step: polls FUN_001f1fe0 for a status, sets connection flags (0x36d570) and advances or resets the state counter.

## Notes / uncertainty
Link-up wait step: polls FUN_001f1fe0(&count); count>0 latches 0x36d570=1, clears handle, advances; count==0 or fail resets step; already-latched resets (one-shot). count=interface/link-up meaning inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d4250.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
