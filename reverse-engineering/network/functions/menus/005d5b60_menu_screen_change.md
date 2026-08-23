# 0x005d5b60 menu_screen_change

| field | value |
|---|---|
| Original address | 0x005d5b60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d5b60 |
| Resolved name | menu_screen_change |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c8530, FUN_005c9690, FUN_005ca480, FUN_005ca4f0, FUN_005ca640, FUN_005ce0e0, FUN_005cf010, FUN_005cf1e0, FUN_005d1e80, FUN_005d3930, FUN_005d5640
**Callees:** FUN_005dd920
**Referenced globals:** 0x701070+0x2e screen; 0x701070+1/2; 0x701078
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x2e

## Behavioral explanation
Helper: sets target screen id (0x2e=param) and kicks a screen transition (5dd920).

## Notes / uncertainty
General screen change: screen_id=param, render (2,0), anim_state=2, starts 20-step fade-to-black via 5dd920. Unconditional counterpart to 5c20. Transition arg semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d5b60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
