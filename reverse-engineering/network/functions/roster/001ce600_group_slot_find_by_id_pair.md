# 0x001ce600 group_slot_find_by_id_pair

| field | value |
|---|---|
| Original address | 0x001ce600 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ce600 |
| Resolved name | group_slot_find_by_id_pair |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ce740
**Callees:** —
**Referenced globals:** 0x36c310 group table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns the group slot in 0x36c310 whose short@8==param_1 && short@0xc==param_2, else 0.

## Notes / uncertainty
Two-key lookup: active && id1(+8)==p1 && id2(+0xc)==p2, else NULL. Same predicate as the free routine.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ce600.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
