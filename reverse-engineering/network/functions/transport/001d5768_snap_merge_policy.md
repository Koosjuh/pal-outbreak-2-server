# 0x001d5768 snap_merge_policy

| field | value |
|---|---|
| Original address | 0x001d5768 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d5768 |
| Resolved name | snap_merge_policy |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5ae4
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Pure decision table: given two packets' flag masks, returns the allowed coalesce/merge class (8/0x10/0x20/4) or -1 if they can't be merged.

## Notes / uncertainty
Pure coalesce decision table (last-match-wins) returning class 0x04/0x08/0x10/0x20 or -1; the 6 category-bit meanings are inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d5768.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
