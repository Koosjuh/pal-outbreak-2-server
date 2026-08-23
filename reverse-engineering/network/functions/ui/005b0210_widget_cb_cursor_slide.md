# 0x005b0210 widget_cb_cursor_slide

| field | value |
|---|---|
| Original address | 0x005b0210 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b0210 |
| Resolved name | widget_cb_cursor_slide |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** 0x6c5497 selected index; 0x6389f0 coord table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +4 state; +0x38 last-sel; +0x4c/+0x50 lerp

## Behavioral explanation
Per-frame widget callback that slides a selection highlight to the current cursor position (cRam006c5497): interpolates x or y (by orientation +3) toward the target from a coord table (0x6389f0) over ~16 frames.

## Notes / uncertainty
Caret eases to selected entry over 16f; +3 selects x/y axis, sprite=0x138+orient, color 0x80ff0000. tab[] per-selection indexing approximated as sel*2. Two dead blocks flagged by decompiler.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b0210.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
