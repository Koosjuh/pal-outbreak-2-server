# 0x00614e60 build_sprite_quads

| field | value |
|---|---|
| Original address | 0x00614e60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00614e60 |
| Resolved name | build_sprite_quads |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00614c80
**Callees:** FUN_00637f90
**Referenced globals:** 0x64b820 (uv/coord table); iRam0070d1c0+0x1aec0 (draw ctx)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0x1aec0

## Behavioral explanation
Builds textured sprite quad vertices from a sprite descriptor (pos/uv/flip per param_1[5] orientation) and submits each via 637f90 using the draw context.

## Notes / uncertainty
6-short sprite records -> textured quads with 4-way UV flip (orient 0-3) from DAT_0064b820, submit via 637f90+ctx; record fields [2]/[3] and 14B vertex layout inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00614e60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
