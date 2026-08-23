# 0x00633470 predictive_update

| field | value |
|---|---|
| Original address | 0x00633470 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00633470 |
| Resolved name | predictive_update |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630f20, FUN_00631560, FUN_00631d60, FUN_00632330, FUN_00635f80
**Callees:** FUN_00632290, FUN_00633390, FUN_006333b0, FUN_00633840, FUN_00635ed0
**Referenced globals:** 0x715da8+0x36; 0x715da8+0x248 (redraw); 0x715da8+0x258 (row count)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x36; 0x715da8+0x248

## Behavioral explanation
Predictive-mode refresh: if converged (FUN_00632290==1 and flag clear) finalize via FUN_00635ed0, else re-enter predictive mode and rebuild candidate grid.

## Notes / uncertainty
If FUN_00632290 converged && !predictive -> finalize (FUN_00635ed0); else re-enter predictive, refresh count, rebuild grid (FUN_00633840), clear redraw kbd+0x248. Predicate/commit callees not reconstructed here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00633470.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
