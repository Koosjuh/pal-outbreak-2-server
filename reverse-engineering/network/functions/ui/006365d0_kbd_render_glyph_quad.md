# 0x006365d0 kbd_render_glyph_quad

| field | value |
|---|---|
| Original address | 0x006365d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006365d0 |
| Resolved name | kbd_render_glyph_quad |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00636890
**Callees:** FUN_006381e0
**Referenced globals:** 0x715da8 state struct; 0x690d70/0x690d74 glyph metrics
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Computes a textured quad (x0/x1/y0/y1 from font metrics DAT_00690d70/74) at (param_1,param_2) and submits it to the sprite drawer FUN_006381e0.

## Notes / uncertainty
Draws one textured glyph quad from font metrics (0x690d70/74, gid=*(base+6)) scaled by +0x14; submits via FUN_006381e0 selector -28. glyph_metrics field offsets inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006365d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
