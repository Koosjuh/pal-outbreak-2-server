# 0x005e9580 cfg_key_num_0x4e6_default16

| field | value |
|---|---|
| Original address | 0x005e9580 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9580 |
| Resolved name | cfg_key_num_0x4e6_default16 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec650
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x4e6 (u16)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x4e6

## Behavioral explanation
Parses decimal into cfg+0x4e6 (u16); if zero substitutes default 0x10.

## Notes / uncertainty
Decimal→u16 at cfg+0x4e6, zero→default 0x10. Field is the type-0/1 row width per FUN_005edc40. Full control flow determined.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9580.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
