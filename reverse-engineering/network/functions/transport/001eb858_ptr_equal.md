# 0x001eb858 ptr_equal

| field | value |
|---|---|
| Original address | 0x001eb858 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb858 |
| Resolved name | ptr_equal |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5ae4, FUN_001e16b4, FUN_001e1c10
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Predicate returning true when its two pointer/long args are equal.

## Notes / uncertainty
Pure equality comparator (long==long) used as list_find_pred predicate (1=match). Whether callers compare full pointers or a key field is caller-dependent.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb858.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
