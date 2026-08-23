# 0x001cb360 gfx_decode_image_dispatch

| field | value |
|---|---|
| Original address | 0x001cb360 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cb360 |
| Resolved name | gfx_decode_image_dispatch |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001afc40, FUN_001cb0e0, FUN_001cb7f0, FUN_001ccb80, FUN_001cce80, FUN_001cd010, FUN_001cd160, FUN_001cd820, FUN_001ce090, FUN_001ce740, FUN_001cf0b0, FUN_001cf100, FUN_001cf150, FUN_001cfb30, FUN_001cfc90, FUN_001d0040, FUN_001d0230, FUN_001d0b00, FUN_001d0b90, FUN_001d0c00, FUN_001d0c90, FUN_001d0d50, FUN_001d0e90, FUN_001d1050, FUN_001d1110, FUN_001d12c0, FUN_001d1410, FUN_001d1530, FUN_001d2970, FUN_001d2b30, FUN_001d31b0, FUN_001d3240, FUN_001d3310, FUN_001d33d0, FUN_001d3500, FUN_001d35d0, FUN_001d3ac0, FUN_001d3b40, FUN_001d3df0, FUN_001d3f60, FUN_001d3fd0, FUN_001d40e0
**Callees:** FUN_001a0df0, FUN_001a0e90
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Image-decode dispatch: routes to FUN_001a0df0 (flag 0x10000 set) or FUN_001a0e90 (size in low 16 bits) to decode a texture/bitmap.

## Notes / uncertainty
Image-decode dispatcher: bit 0x10000 -> decoder A (FUN_001a0df0), else low-16 size!=0 -> decoder B (FUN_001a0e90), else return 0. NOTE 0x10000 is an image-format flag, NOT a transport who-byte bit. ~40 gfx-builder callers.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cb360.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
