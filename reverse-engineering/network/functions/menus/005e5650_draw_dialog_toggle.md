# 0x005e5650 draw_dialog_toggle

| field | value |
|---|---|
| Original address | 0x005e5650 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e5650 |
| Resolved name | draw_dialog_toggle |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dd660
**Callees:** FUN_005ddb40, FUN_005ddc20, FUN_005de330, FUN_005e00e0, FUN_005e1670
**Referenced globals:** cRam00700ff0 (toggle flag); iRam00701078+2 (selected button)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00700ff0; iRam00701078+2

## Behavioral explanation
Renders a dialog with a toggle-dependent body (global flag cRam00700ff0 selects string group 8 idx 0 vs 2) and one button (idx 1).

## Notes / uncertainty
Single-button dialog with flag-toggled body: cRam00700ff0==0 -> string 8/0 else 8/2; plate at (+198,+185) label 8/1; highlight on sel==1. Meaning of cRam00700ff0 not identified here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e5650.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
