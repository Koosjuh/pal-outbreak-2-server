# 0x005e95e0 cfg_key_num_0x4e8_default256_clamp

| field | value |
|---|---|
| Original address | 0x005e95e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e95e0 |
| Resolved name | cfg_key_num_0x4e8_default256_clamp |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec650
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x4e8 (u16)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x4e8

## Behavioral explanation
Parses decimal into cfg+0x4e8 (u16); zero→256, clamps to max 256.

## Notes / uncertainty
Decimal→u16 at cfg+0x4e8, zero→256, clamp max 256. 256 ceiling → length/count limit (inferred).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e95e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
