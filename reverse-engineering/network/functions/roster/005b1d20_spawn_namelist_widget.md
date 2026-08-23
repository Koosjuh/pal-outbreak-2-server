# 0x005b1d20 spawn_namelist_widget

| field | value |
|---|---|
| Original address | 0x005b1d20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b1d20 |
| Resolved name | spawn_namelist_widget |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** FUN_005b14b0, FUN_005b1e30, FUN_00618ba0, FUN_00637170
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x45a ready; struct+0x992 ready; struct+0x434 guard; struct+0x42c busy

## Behavioral explanation
Allocates two UI elements and installs 0x5b1b10 as their callback to spawn the name-selection list, gated on ready flags +0x45a/+0x992/+0x434 and a button press.

## Notes / uncertainty
Spawns primary(type3)+secondary(type4) name-list elements with FUN_005b1b10 callback on cross(0x8000) press when ready gates set (+0x45a,+0x992,+0x434,+0x42c) and list non-empty; marks owner busy +0x42c=1, resets sel_index. Ready-flag origins untraced; partial-spawn edge case unverified.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b1d20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
