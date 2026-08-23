# 0x005b0950 score_fetch_clamped

| field | value |
|---|---|
| Original address | 0x005b0950 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b0950 |
| Resolved name | score_fetch_clamped |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005affb0, FUN_005f84c0
**Callees:** FUN_005bf980
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Fetches a pair of score values into param_2 via FUN_005bf980(index,2,dst) and clamps each to a max of 9999.

## Notes / uncertainty
record_field_copy(index,2,dst) then per-field clamp to 9999. Callee FUN_005bf980 semantics assumed from arg pattern.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b0950.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
