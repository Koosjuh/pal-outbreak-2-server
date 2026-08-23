# 0x005dae40 ui_spawn_list_widget

| field | value |
|---|---|
| Original address | 0x005dae40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dae40 |
| Resolved name | ui_spawn_list_widget |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cd320
**Callees:** FUN_005dfde0
**Referenced globals:** iRam00701068+0x68e7f: UI state flag; LAB_005daee0
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x68e7f

## Behavioral explanation
UI widget factory (type 1): allocates node, installs draw callback FUN_005daf30 (selection-list overlay); sets flag 0x68e7f=3.

## Notes / uncertainty
Renamed from ui_spawn_widget_type1: factory (pool 1), installs list-draw cb FUN_005daf30, flag 0x68e7f=3. State value 3 meaning unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dae40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
