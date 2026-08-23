# 0x00602700 render_roster_stats_table

| field | value |
|---|---|
| Original address | 0x00602700 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00602700 |
| Resolved name | render_roster_stats_table |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005fede0, FUN_00600200
**Callees:** FUN_005af810, FUN_005bac80, FUN_005bacf0, FUN_00602670, FUN_006038f0, FUN_0062fea0
**Referenced globals:** bRam00341ae4 member count; iRam003435d4+0xcf5c0 per-member stats; +0xcd5ac display-list; +0x1e50/0x1e3c local record
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0x9ab page-index; param_1+0x3f6c compare key

## Behavioral explanation
Builds the per-member roster/stats table (name/time/score rows) for bRam00341ae4 members across pages selected by +0x9ab (0=summary,1=stats,2=times,3=names), formatting each row via FUN_006038f0 into the display list at 0xcd5ac.

## Notes / uncertainty
Roster/stats results renderer, 4 pages (+0x9ab), member loops bound by count bRam00341ae4, frames->h:m:s + 9999 clamps, local-vs-array id split, '---'=str(0x43). Large fn with near-duplicate pages: reconstruction preserves dispatch/gating/math but CONDENSES repeated inner blocks; page 0/1 field offsets partly inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00602700.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
