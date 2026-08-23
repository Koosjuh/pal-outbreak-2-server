# 0x005fcba0 difficulty_cursor_widget_cb

| field | value |
|---|---|
| Original address | 0x005fcba0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fcba0 |
| Resolved name | difficulty_cursor_widget_cb |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af810, FUN_005bac80, FUN_005bace0
**Referenced globals:** 0x6c4b96 selected difficulty/index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4b96

## Behavioral explanation
Per-frame cursor widget callback: positions/enables the selection cursor sprite from difficulty index uRam006c4b96.

## Notes / uncertainty
Difficulty-row cursor sprite: positions x=slot*10+0x84,y=0x6c from selection uRam006c4b96 via FUN_005bac80/bace0; hidden when gate FUN_005af810==0 or index invalid. func_0x001ae3e0 field offset untraced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fcba0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
