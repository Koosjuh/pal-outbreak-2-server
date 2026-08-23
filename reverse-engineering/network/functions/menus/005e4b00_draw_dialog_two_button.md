# 0x005e4b00 draw_dialog_two_button

| field | value |
|---|---|
| Original address | 0x005e4b00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e4b00 |
| Resolved name | draw_dialog_two_button |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dd660
**Callees:** FUN_005ddb40, FUN_005ddc20, FUN_005de330, FUN_005e00e0, FUN_005e1670
**Referenced globals:** iRam00701078+2 (selected button); dialog string set via FUN_005de330(7,n)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701078+2

## Behavioral explanation
Renders a modal dialog: 9-slice window (FUN_005e1670), a title/body string and two side-by-side button labels (strings via FUN_005de330, text via FUN_005ddc20), with the selected button highlighted per +0x701078+2.

## Notes / uncertainty
Two-button modal: 9-slice window, two 84x32 plates (+49/+157), body+labels string group 7 idx 0/1/2, grey highlight plate on blink+selected (iRam00701078+2). Highlight-x stale-register when sel not in {1,2} (likely unreachable).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e4b00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
