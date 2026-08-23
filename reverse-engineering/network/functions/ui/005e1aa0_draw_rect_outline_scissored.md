# 0x005e1aa0 draw_rect_outline_scissored

| field | value |
|---|---|
| Original address | 0x005e1aa0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e1aa0 |
| Resolved name | draw_rect_outline_scissored |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dcb90, FUN_005e4840
**Callees:** FUN_005dda30
**Referenced globals:** iRam00701070+0x18 flags, +0x1a/+0x1c/+0x1e/+0x20 margins
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701070+0x18 (viewport flags)

## Behavioral explanation
Draws a rectangle outline (4 thick edges) clipped to the current viewport scissor read from the +0x701070 struct.

## Notes / uncertainty
Rect outline (thickness param_6) clamped to viewport @0x701070 margins + inner content window (0x248/0x17c), early-cull if start past inner window. Flag test +0x18 bits 0x4/0x2 has identical then/else branches (no observable effect); margin field names inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e1aa0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
