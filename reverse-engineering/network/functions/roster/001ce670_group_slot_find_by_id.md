# 0x001ce670 group_slot_find_by_id

| field | value |
|---|---|
| Original address | 0x001ce670 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ce670 |
| Resolved name | group_slot_find_by_id |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ce6d0
**Callees:** —
**Referenced globals:** 0x36c310 group table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns the group slot in 0x36c310 whose short@8==param_1, else 0 (single-key lookup).

## Notes / uncertainty
Single-key lookup: active && id1(+8)==p1, else NULL. id2-agnostic variant used by roster-update.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ce670.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
