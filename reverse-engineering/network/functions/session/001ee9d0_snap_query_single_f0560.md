# 0x001ee9d0 snap_query_single_f0560

| field | value |
|---|---|
| Original address | 0x001ee9d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee9d0 |
| Resolved name | snap_query_single_f0560 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0f40
**Callees:** FUN_001f0560
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Calls FUN_001f0560(&out); returns the fetched dword only if the call reports exactly 1 result, else -1.

## Notes / uncertainty
Family-C local accessor: FUN_001f0560(&out); returns out only if count==1 else -1. Callee opaque (not in this decompile set); queried domain unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee9d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
