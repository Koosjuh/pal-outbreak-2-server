# 0x005e1da0 draw_rect_outline_viewport

| field | value |
|---|---|
| Original address | 0x005e1da0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e1da0 |
| Resolved name | draw_rect_outline_viewport |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dc010, FUN_005e2fa0, FUN_005e3a80
**Callees:** FUN_005dda30
**Referenced globals:** iRam00701070+0x1a/+0x1c/+0x1e/+0x20 (viewport margins)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Draws a 1px rectangle outline clamped to the viewport extents (0x280x0x1c0 minus margins) from +0x701070.

## Notes / uncertainty
1px rect outline clamped only to viewport margins (640-right/448-bottom); simpler sibling of 0x1aa0 minus inner-window scissor/flag/cull. Same +0x701070 field-name inference.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e1da0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
