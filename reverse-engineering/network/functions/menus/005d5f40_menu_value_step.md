# 0x005d5f40 menu_value_step

| field | value |
|---|---|
| Original address | 0x005d5f40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d5f40 |
| Resolved name | menu_value_step |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005cf010
**Callees:** FUN_0061e720
**Referenced globals:** 0x701078+2 value; 0x701068+0x4f8a4/8/9 input; 0x715da8+0x49c key
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x4f8a4

## Behavioral explanation
Increments/decrements a menu counter (0x701078+2) from pad direction/repeat input, clamps to param, plays a tick sound on change.

## Notes / uncertainty
Bounded numeric spinner (g_ui+2) driven by pad edge/repeat block 0x4f8a4-9 + dir key 0x715da8+0x49c; clamps [1,max]; tick sound on change. Edge-bit/dir-char meanings and what the value feeds (max-players?) inferred; runtime-unvalidated. Control flow preserved exactly.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d5f40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
