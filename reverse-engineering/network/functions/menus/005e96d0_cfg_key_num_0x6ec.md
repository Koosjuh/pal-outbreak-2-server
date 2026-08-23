# 0x005e96d0 cfg_key_num_0x6ec

| field | value |
|---|---|
| Original address | 0x005e96d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e96d0 |
| Resolved name | cfg_key_num_0x6ec |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec650
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x6ec (u16)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x6ec

## Behavioral explanation
Parses decimal into cfg+0x6ec (u16), no default.

## Notes / uncertainty
Decimal→u16 at cfg+0x6ec, raw (no default). Used as type-6/7 row width in FUN_005edc40.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e96d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
