# 0x005db6d0 ui_spawn_hscrollbar

| field | value |
|---|---|
| Original address | 0x005db6d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005db6d0 |
| Resolved name | ui_spawn_hscrollbar |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cd320
**Callees:** FUN_005dfde0
**Referenced globals:** iRam00701068+0x68e81: UI state flag; iRam00701070+0x1e/0x1c: geometry; LAB_005db7c0
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x68e81

## Behavioral explanation
UI widget factory: allocates a horizontal-scrollbar node, installs draw callback FUN_005db8a0; sets flag 0x68e81=2.

## Notes / uncertainty
Widget factory kind-2 h-scrollbar; sets flag 0x68e81=2, installs draw cb FUN_005db8a0. Not network. Float geometry decoded; LAB_005db7c0 blob undumped; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005db6d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
