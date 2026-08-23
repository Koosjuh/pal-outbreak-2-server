# 0x005f47e0 draw_sprite_quad

| field | value |
|---|---|
| Original address | 0x005f47e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f47e0 |
| Resolved name | draw_sprite_quad |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00621fe0
**Callees:** —
**Referenced globals:** DAT_70000000..48(GS packet scratch); iRam0028a324/450/458(screen metrics); 0x6496c0(texture); fRam00289f74(depth)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0028a324

## Behavioral explanation
Builds a GS textured-quad primitive (color/UV/XY) from a sprite descriptor and kicks the DMA packet.

## Notes / uncertainty
GS SPRITE (2-vert quad) emit into GIF packet @0x70000000 with 12.4 fixed-point, 640-virtual scale, field/half-scale; guarded by iRam0028a324. Twin float-clamp idioms are compiler Z saturation, not logic. param_2 descriptor field roles partly inferred. Pure render, VU/GIF scratch not network.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f47e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
