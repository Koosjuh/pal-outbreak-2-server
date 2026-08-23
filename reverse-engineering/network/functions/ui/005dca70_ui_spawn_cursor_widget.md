# 0x005dca70 ui_spawn_cursor_widget

| field | value |
|---|---|
| Original address | 0x005dca70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dca70 |
| Resolved name | ui_spawn_cursor_widget |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cd320
**Callees:** FUN_005dfde0
**Referenced globals:** iRam00701068+0x68e86; iRam00701068+0x68e88; LAB_005dcb30
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x68e86; 0x68e88

## Behavioral explanation
UI widget factory: allocates the pointer/cursor node (~150,100, 20x20), installs draw/hit-test callback FUN_005dcb90; sets flags 0x68e86=1, 0x68e88=0.

## Notes / uncertainty
Factory kind-8 20x20 pointer cursor at 150,100; flags 0x68e86=1/0x68e88=0, hit-test cb FUN_005dcb90. +0xc=5 seed meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dca70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
