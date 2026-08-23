# 0x006381e0 gs_draw_line

| field | value |
|---|---|
| Original address | 0x006381e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006381e0 |
| Resolved name | gs_draw_line |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00618e30, FUN_00619170, FUN_00633c10, FUN_006365d0, FUN_006366a0, FUN_00636890
**Callees:** —
**Referenced globals:** 0x70000000 (GIF/GS reg buffer); iRam0028a324 (render gate); iRam0028a458/0028a450 (screen w/h); iRam00289f34 (half-res flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0028a324 (draw gate)

## Behavioral explanation
Builds a GS packet to draw a scaled 2-vertex line/edge (verts param_1[0..3], color func_0x0018f430); gated on iRam0028a324==0.

## Notes / uncertainty
GS 2-vertex line drawer. param_1 = 12-byte {s16 x0,y0,x1,y1; u32 color}, param_2 = per-call Z depth. Virtual 640-wide coords scaled to framebuffer, centered in 4096-range GS 12.4 fixed point; gated on iRam0028a324==0; half-height when iRam00289f34==0. Builds RGBAQ+XYZ2 GIF packet at 0x70000000 via template 0x6924c0 and kicks it. Uncertain: exact ARGB/RGBA input byte order and meaning of the 0x100000000 Q/marker bit; SDK helper semantics not hardware-traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006381e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
