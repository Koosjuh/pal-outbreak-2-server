# 0x001cb0e0 gfx_build_texture_desc

| field | value |
|---|---|
| Original address | 0x001cb0e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cb0e0 |
| Resolved name | gfx_build_texture_desc |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60, FUN_00109728, FUN_00183fd0, FUN_001cb360
**Referenced globals:** 0x36b900/0x36b910=texture descriptor; 0x3435bc=heap base; 0x248870=fmt string; 0x5aa548=flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds a texture/sprite descriptor (width/height, mip shifts, decoded pixel buffers) at 0x36b910 by decoding an image (FUN_001cb360) and computing aligned buffer offsets.

## Notes / uncertainty
Loads image asset (sprintf name + FUN_00183fd0 + gfx_decode_image), reads w/h from header, fills GS texture descriptor @0x36b910 with mip shifts (>>4) and 3 aligned RGBA32 buffers, sets ready flag. Non-protocol; header field offsets inferred from standard GS layout.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cb0e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
