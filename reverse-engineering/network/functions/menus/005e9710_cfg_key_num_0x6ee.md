# 0x005e9710 cfg_key_num_0x6ee

| field | value |
|---|---|
| Original address | 0x005e9710 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9710 |
| Resolved name | cfg_key_num_0x6ee |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec650
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x6ee (u16)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x6ee

## Behavioral explanation
Parses decimal into cfg+0x6ee (u16), no default.

## Notes / uncertainty
Twin of 0x96d0 → cfg+0x6ee (adjacent to 0x6ec, likely a value pair). Raw store. Reader for 0x6ee not mapped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9710.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
