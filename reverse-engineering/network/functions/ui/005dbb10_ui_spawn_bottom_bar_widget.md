# 0x005dbb10 ui_spawn_bottom_bar_widget

| field | value |
|---|---|
| Original address | 0x005dbb10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dbb10 |
| Resolved name | ui_spawn_bottom_bar_widget |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cd320
**Callees:** FUN_005dfde0
**Referenced globals:** iRam00701068+0x68e82: UI state flag; iRam00701070+0x1e/0x1c/0x20: geometry; LAB_005dbc10
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x68e82

## Behavioral explanation
UI widget factory: allocates a bottom-bar/label node spanning viewport width, installs draw callback FUN_005dbca0; sets flag 0x68e82=1.

## Notes / uncertainty
Factory kind-2 full-width 20px bottom bar; flag 0x68e82=1, draw cb FUN_005dbca0. Bar role (status vs hint) inferred from geometry.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dbb10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
