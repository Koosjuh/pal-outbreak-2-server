# 0x0061c7f0 sprite_quad_blit_loop

| field | value |
|---|---|
| Original address | 0x0061c7f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061c7f0 |
| Resolved name | sprite_quad_blit_loop |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00619e00
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Blits param_2 consecutive 10-short sprite records, applying a Y offset (param_3) and -1 height fixup, via the GS sprite-draw primitive.

## Notes / uncertainty
Emits count 10-short(0x14) sprite records to GS primitive func_0x001a2500 with +y_off on field1 and -1 height fixup, packing fields8/9. Field roles (x/y/uv/rgba) inferred from position, unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061c7f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
