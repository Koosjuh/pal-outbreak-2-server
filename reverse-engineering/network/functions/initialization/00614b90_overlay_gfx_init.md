# 0x00614b90 overlay_gfx_init

| field | value |
|---|---|
| Original address | 0x00614b90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00614b90 |
| Resolved name | overlay_gfx_init |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060f910
**Callees:** FUN_001af0a0, FUN_00612120, FUN_00612ae0, FUN_00613b10, FUN_00614750, FUN_00614c50, FUN_00614c70
**Referenced globals:** iRam0070d1c0 (+8, +0x1aec0 draw ctx)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0x1aec0

## Behavioral explanation
Overlay entry init: programs renderer config regs (001a7b70 keys 0x5e/0x5f/0x60/0x61/0x63/0x6c), sets draw context, then inits sub-systems (612120/612ae0/613b10).

## Notes / uncertainty
Renderer param writes via 001a7b70 (0x5e=blendmode confirmed by 614c80), draw-env acquire into +0x08, sub-screen inits; GS reg key names are placeholders, negative ctx handles inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00614b90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
