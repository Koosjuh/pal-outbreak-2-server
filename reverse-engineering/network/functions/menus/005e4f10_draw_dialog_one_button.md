# 0x005e4f10 draw_dialog_one_button

| field | value |
|---|---|
| Original address | 0x005e4f10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e4f10 |
| Resolved name | draw_dialog_one_button |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dd660
**Callees:** FUN_005ddb40, FUN_005ddc20, FUN_005de330, FUN_005e00e0, FUN_005e1670
**Referenced globals:** iRam00701078+2 (selected button)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701078+2

## Behavioral explanation
Renders a single-button modal dialog: 9-slice window, one centered body line and one centered button label (string group 7 indices 3/4), selected-state highlight per +0x701078+2.

## Notes / uncertainty
One-button sibling: centered plate (ew-84)/2, string group 7 idx 3(body)/4(label), highlight on sel==1. Same geometry/plate consts as 005e4b00.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e4f10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
