# 0x005d5a40 menu_state_return_list

| field | value |
|---|---|
| Original address | 0x005d5a40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d5a40 |
| Resolved name | menu_state_return_list |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ca380, FUN_005d0960, FUN_005d09d0, FUN_005d0a40, FUN_005d3930, FUN_005d47f0, FUN_005d5640, FUN_005d6390
**Callees:** —
**Referenced globals:** 0x701070+0x2c/0x2e state; 0x701078+0x20 selected; 0x701070+0x3a lock; 0x701068+0x60dc7; 0x701068+0x5ffc0 array
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x2e; 0x701070+0x3a

## Behavioral explanation
Helper: resets to the list screen (0x2e=1), clears selection/lock flags, sets render state.

## Notes / uncertainty
Return-to-list: screen_id=1, render (1,1,0); manages input_lock +0x3a (0xf0 if no focus, 0 if idle) + fade color 0xff000000. focus/busy field labels inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d5a40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
