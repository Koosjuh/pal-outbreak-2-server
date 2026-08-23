# 0x001eef00 snap_query_id_f0f10

| field | value |
|---|---|
| Original address | 0x001eef00 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eef00 |
| Resolved name | snap_query_id_f0f10 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c19e0, FUN_001ee1e0
**Callees:** FUN_001f0f10
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Calls FUN_001f0f10(); on success writes the returned short as an int into *param_1 and returns 0, else -1.

## Notes / uncertainty
Fetch 16-bit id via FUN_001f0f10; sign-extend to *param_1 and ret 0 on >=0, else -1. Id domain unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eef00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
