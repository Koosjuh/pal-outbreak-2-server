# 0x005e3a80 draw_scroll_list_widget

| field | value |
|---|---|
| Original address | 0x005e3a80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e3a80 |
| Resolved name | draw_scroll_list_widget |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005daf30
**Callees:** FUN_005ddc20, FUN_005e0440, FUN_005e07c0, FUN_005e1da0
**Referenced globals:** iRam00701068+0x5ffc0 (element list, 500 entries), +0x69018 (anim); iRam00701078 (list layout: +3 arrow-state, +4 total count, +5 first-visible, +6 direction, +8/+0xa/+0xc geometry, +0x10/+0x12 hit-test, +0x20 active-list idx); iRam00701070+4/+8 (scroll origin)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701078+0x20 (active list index); iRam00701068+0x69018

## Behavioral explanation
Renders a scrollable selectable list: scans the element list (@+0x5ffc0) for type-8 row elements matching the active list (+0x701078+0x20), computes scrollbar geometry, draws each visible row's text (FUN_005ddc20) with selection highlight bars and a scrollbar (FUN_005e07c0).

## Notes / uncertainty
Scrollable list = room-list/roster renderer: scans type-8 rows for active list, computes thumb geom into iRam00701078, draws rows + green(sel)/blue(hover) bars + arrows/thumb when >10. 10-row cap = party/page size. Two mirrored direction branches summarized, raw is authoritative for exact pixels.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e3a80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
