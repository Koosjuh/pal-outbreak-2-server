# 0x005d8ea0 ui_draw_rect_bounded

| field | value |
|---|---|
| Original address | 0x005d8ea0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d8ea0 |
| Resolved name | ui_draw_rect_bounded |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ed6e0
**Callees:** FUN_005cab10, FUN_005da650, FUN_005da730
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
If the rect has positive width/height and FUN_005da730 clears, sets region and draws a mode-0xd/type-5 filled rect via FUN_005cab10.

## Notes / uncertainty
Bounds-checked style-0xd/sub-5 filled rect: requires positive width AND height AND FUN_005da730()==0 clip test. What FUN_005da730 actually tests (scissor/occlusion) undecompiled. Non-protocol.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d8ea0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
