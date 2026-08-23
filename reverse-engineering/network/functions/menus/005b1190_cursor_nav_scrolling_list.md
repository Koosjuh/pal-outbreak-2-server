# 0x005b1190 cursor_nav_scrolling_list

| field | value |
|---|---|
| Original address | 0x005b1190 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b1190 |
| Resolved name | cursor_nav_scrolling_list |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f60d0, FUN_005f8fc0, FUN_00604180, FUN_00627f20, FUN_0062d1b0
**Callees:** FUN_005b14b0, FUN_005b16c0
**Referenced globals:** 0x6ca080 delay counter; pad latches
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
2D grid cursor navigation with hold-delay repeat: manages a page/row index (param_1) and column index (param_2) wrapping against dimensions param_3/param_4 (mode param_5), using input_pressed/input_held and delay counter 0x6ca080.

## Notes / uncertainty
Renamed from cursor_nav_grid: single scroll axis with paging, not a 2-D grid. UP=0x10001 DOWN=0x20002; press moves once + arms 20-frame delay, hold auto-repeats every 5 frames (0x6ca080). abs index = *scrollTop + *cursorRow; mode<2 wrap, >=2 clamp. param_1='top-visible item index' inferred from itemCount-windowRows math, unproven on rig.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b1190.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
