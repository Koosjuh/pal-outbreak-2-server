# 0x005dbca0 ui_draw_status_bar_text

| field | value |
|---|---|
| Original address | 0x005dbca0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dbca0 |
| Resolved name | ui_draw_status_bar_text |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005d7410, FUN_005ddc20, FUN_005de330, FUN_005dfee0, FUN_005e07c0
**Referenced globals:** iRam00701068+0x5ffc0: item list; iRam00701068+0x68e84: submenu flag; iRam00701078+1
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x68e84

## Behavioral explanation
UI draw callback: draws a status/label bar (sprite kind 6) plus text (FUN_005ddc20) whose content varies by node lifecycle char — page indices, a joined pair string, or an item's field +0x60.

## Notes / uncertainty
Draw cb: bg sprite kind6 + per-phase context text (item +0x60/+0x64 strings); OSK-suppressed when 0x68e84==1. Renders item name field but no protocol I/O.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dbca0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
