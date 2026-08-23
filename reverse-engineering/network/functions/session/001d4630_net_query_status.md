# 0x001d4630 net_query_status

| field | value |
|---|---|
| Original address | 0x001d4630 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d4630 |
| Resolved name | net_query_status |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d44f0
**Callees:** FUN_001f22a0, FUN_001f27c8
**Referenced globals:** 0x36d640 target; 0x36d648 active flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** (param+0x36d648)

## Behavioral explanation
Helper: probes FUN_001f22a0/FUN_001f27c8 and returns 0 (ready) or -1 (not ready) based on status and the 0x36d648 flag.

## Notes / uncertainty
Returns 0=ready iff probe==0 && pending==0 && active-flag(0x36d648+idx)!=0, else -1. 001f22a0/001f27c8 semantics inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d4630.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
