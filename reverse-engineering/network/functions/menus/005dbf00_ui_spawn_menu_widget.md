# 0x005dbf00 ui_spawn_menu_widget

| field | value |
|---|---|
| Original address | 0x005dbf00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dbf00 |
| Resolved name | ui_spawn_menu_widget |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cd320
**Callees:** FUN_005dfde0
**Referenced globals:** iRam00701068+0x68e83: submenu flag; LAB_005dbfb0
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x68e83

## Behavioral explanation
UI widget factory: allocates a fixed-position menu-panel node (~200,150), installs draw callback FUN_005dc010; clears submenu flag 0x68e83.

## Notes / uncertainty
Factory kind-3 popup menu panel at 200,150; clears 0x68e83, draw cb FUN_005dc010. LAB blob undumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dbf00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
