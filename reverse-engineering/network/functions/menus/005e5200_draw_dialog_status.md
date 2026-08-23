# 0x005e5200 draw_dialog_status

| field | value |
|---|---|
| Original address | 0x005e5200 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e5200 |
| Resolved name | draw_dialog_status |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dd660
**Callees:** FUN_005ddb40, FUN_005ddc20, FUN_005de330, FUN_005e00e0, FUN_005e1670
**Referenced globals:** iRam00701068+0x68e85 (menu sub-state); iRam00701078+2 (selected button)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701068+0x68e85; iRam00701078+2

## Behavioral explanation
Renders a status/confirm dialog whose header text is chosen by menu-state byte +0x68e85 (9 or 10 -> string group 7 idx 5/6) with two buttons.

## Notes / uncertainty
Status/connect dialog: header varies on menu sub-state +0x68e85 (0x0a->7/6, 0x09->7/5), two plates at y+165, labels 7/1,7/2. +0x68e85 is the connection-phase byte also gating modal dim in FUN_005e2060; exact 9-vs-10 phase meaning unpinned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e5200.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
