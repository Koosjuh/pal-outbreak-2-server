# 0x005ce4e0 confirm_phase_reset

| field | value |
|---|---|
| Original address | 0x005ce4e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ce4e0 |
| Resolved name | confirm_phase_reset |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ce530
**Callees:** —
**Referenced globals:** 0x701070+0x33 flag; 0x701068+0x68e85 phase; 0x701068+0x68e86 flag; 0x701078+1 repeat
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x68e85; 0x701068+0x68e86

## Behavioral explanation
Resets confirm-related state: clears 0x701070+0x33, sets lobby phase 0x68e85=1 and 0x68e86=1, clears cursor repeat flag.

## Notes / uncertainty
Resets confirm phase: scr+0x33=0, ov+0x68e85=1, ov+0x68e86=1, cur[1]=0. Sibling of scroll_state_reset. Role of scr+0x33 inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ce4e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
