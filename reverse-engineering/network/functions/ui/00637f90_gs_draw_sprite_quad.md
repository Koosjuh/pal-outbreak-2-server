# 0x00637f90 gs_draw_sprite_quad

| field | value |
|---|---|
| Original address | 0x00637f90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637f90 |
| Resolved name | gs_draw_sprite_quad |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00614e60, FUN_00618e30, FUN_00636890
**Callees:** —
**Referenced globals:** 0x70000000 (GIF/GS reg buffer); iRam0028a324 (render-disable gate); iRam0028a458 (screen width); iRam00289f34 (interlace/half-res flag); iRam0028a2d4/0028a2d8 (viewport origin x/y)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0028a324 (draw gate)

## Behavioral explanation
Builds a GIF/GS packet at 0x70000000 to draw a scaled textured sprite/quad (verts from param_1[0..9], color via func_0x0018f430); gated on iRam0028a324==0.

## Notes / uncertainty
GS/GIF scaled textured 2D sprite draw at 0x70000000; render-gated by iRam0028a324, half-res via iRam00289f34, sw/640 scale, viewport origin. GIFtag magic constants (0x692470/0x535310) meanings inferred. Pure graphics, off net path.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637f90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
