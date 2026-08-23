# 0x001ce550 group_table_free_all

| field | value |
|---|---|
| Original address | 0x001ce550 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ce550 |
| Resolved name | group_table_free_all |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ce4b0
**Referenced globals:** 0x36c310 group table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Iterates all 4 group slots at 0x36c310 and frees each active one via FUN_001ce4b0 (full room/group teardown).

## Notes / uncertainty
Iterates 4 group slots, frees each active via FUN_001ce4b0 (by key). Full group-layer reset. No captured callers.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ce550.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
