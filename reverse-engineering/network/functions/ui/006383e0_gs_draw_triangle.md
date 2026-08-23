# 0x006383e0 gs_draw_triangle

| field | value |
|---|---|
| Original address | 0x006383e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006383e0 |
| Resolved name | gs_draw_triangle |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dd960
**Callees:** —
**Referenced globals:** 0x70000000 (GIF/GS reg buffer); iRam0028a324 (render gate); iRam0028a458/0028a450 (screen w/h); iRam00289f34 (half-res flag); fRam00289f74 (z/depth)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0028a324 (draw gate)

## Behavioral explanation
Builds a GS packet to draw a scaled 3-vertex triangle (verts param_1[0..5], color param_1[6], depth fRam00289f74); returns 1, gated on iRam0028a324==0.

## Notes / uncertainty
GS 3-vertex flat triangle drawer; structural twin of 0x6381e0 but 3 verts, single flat color in param_1[6..7], and depth from GLOBAL fRam00289f74 (float->int32 with 2^31 overflow path) instead of a param. Distinct GIF template 0x692500. Always returns 1 (even when gated). Uncertain: filled-tri vs strip/fan (template not decoded), input color byte order.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006383e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
