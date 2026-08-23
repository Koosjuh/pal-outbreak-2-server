# 0x005dc010 ui_draw_menu_panel

| field | value |
|---|---|
| Original address | 0x005dc010 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dc010 |
| Resolved name | ui_draw_menu_panel |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ddc20, FUN_005de330, FUN_005dfee0, FUN_005e1670, FUN_005e1da0, FUN_005e2060
**Referenced globals:** iRam00701078+2: menu cursor index; FUN_005de330: localized strings
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI draw callback: renders a 3-item menu panel (frame FUN_005e1670, per-row text FUN_005ddc20 stepped 0x14px) and a highlight rect FUN_005e1da0 around the selected row (index +0x78[2]).

## Notes / uncertainty
Draw cb: 210x110 frame + 3 localized rows (20px pitch) + selection highlight at cursor input+2. FUN_005e2060 update side effect not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dc010.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
