# 0x005e0140 texture_load_register

| field | value |
|---|---|
| Original address | 0x005e0140 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e0140 |
| Resolved name | texture_load_register |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e0270
**Callees:** —
**Referenced globals:** iRam00701068+0x609c0 (texture count/index); iRam00701068+0x607c0 (handle table); uRam003435bc (load scratch)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701068+0x609c0

## Behavioral explanation
Loads/decodes a texture from a source ptr (guarded at 128 max), applies a swizzle/format variant per param, registers it and appends the handle to the table @+0x607c0.

## Notes / uncertainty
Registers one UI texture into handle table @base+0x607c0 (cap 128 @+0x609c0), format variant per param_2 (0/1). GS upload primitives (func_0x001cb360/6a0/5f0/cbcb0) undecoded; 0x10001 flag inferred; VRAM 0x5000 staging arithmetic vs *4 handle stride unverified.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e0140.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
