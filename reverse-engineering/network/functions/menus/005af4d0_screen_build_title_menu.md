# 0x005af4d0 screen_build_title_menu

| field | value |
|---|---|
| Original address | 0x005af4d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005af4d0 |
| Resolved name | screen_build_title_menu |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005af780, FUN_00618b60, FUN_00618ba0
**Referenced globals:** 0x6c45f8/fc/4600 session counts (cleared); 0x874f33 uRam00874f33; 0x638860.. label string table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xe build state; +0xf

## Behavioral explanation
Builds a title/session menu screen: FSM on +0xe allocates widgets via widget_alloc (0x618ba0), assigns sprite/asset ids and callback labels, then lays out a column of text labels via ui_draw_text from a string-pointer block (0x638860+).

## Notes / uncertainty
Two-phase build/run FSM on screen+0xe; commit clears session counters 0x6c45f8/fc/4600 and publishes selection to 0x874f33. Inline label callback LAB_005af4a0 and deco sprites 0x1d/5 not separately traced. No wire I/O.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005af4d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
