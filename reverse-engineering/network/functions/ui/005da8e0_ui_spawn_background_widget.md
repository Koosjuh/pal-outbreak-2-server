# 0x005da8e0 ui_spawn_background_widget

| field | value |
|---|---|
| Original address | 0x005da8e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005da8e0 |
| Resolved name | ui_spawn_background_widget |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cd320
**Callees:** FUN_005dfde0
**Referenced globals:** iRam00701068+0x68e7e: UI state flag; LAB_005da980: widget vtable/anim label
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x68e7e

## Behavioral explanation
UI widget factory: allocates a widget node (FUN_005dfde0), zero-inits its fields and installs draw callback FUN_005daba0 (tiled background); sets state flag 0x68e7e=1.

## Notes / uncertainty
Widget factory (pool 0): allocs node, installs draw cb FUN_005daba0, flag 0x68e7e=1. Widget-node struct partially mapped; LAB_005da980 script not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005da8e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
