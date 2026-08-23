# 0x005fa700 party_grid_satisfies_all_reqs

| field | value |
|---|---|
| Original address | 0x005fa700 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fa700 |
| Resolved name | party_grid_satisfies_all_reqs |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005fa490
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Scans the 4-column occupancy grid (@+0x309c, type @+0x3188/+0x318a) verifying every row satisfies a type/id match; returns 0/1.

## Notes / uncertainty
Inner stride resolves to 0x3b0 (member_record grid, 4 slots); predicate that every requirement row is met by an occupied slot. 6<->0x5b('[') dual-form char equivalence keyed by variant flag +0x318a is inferred; +0x1a req-flag meaning unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fa700.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
