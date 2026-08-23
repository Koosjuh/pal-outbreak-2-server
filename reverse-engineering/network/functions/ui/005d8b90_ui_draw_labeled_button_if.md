# 0x005d8b90 ui_draw_labeled_button_if

| field | value |
|---|---|
| Original address | 0x005d8b90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d8b90 |
| Resolved name | ui_draw_labeled_button_if |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eca10
**Callees:** FUN_005cab10, FUN_005da650
**Referenced globals:** 0x00643380/0x00643388 sentinel strings
**Referenced strings:** (two sentinel strings at 0x643380/0x643388)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
If the passed label string does not match either of two sentinel strings (0x643380/0x643388), sets the draw region (FUN_005da650) and renders a mode-1 widget via FUN_005cab10.

## Notes / uncertainty
Draws style-1 button only if label != two sentinel strings (0x643380/0x643388 — skip/empty placeholders, contents unread). Primitive sig FUN_005cab10(style,sub,x0,y0,x1,y1,color,size). Non-protocol.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d8b90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
