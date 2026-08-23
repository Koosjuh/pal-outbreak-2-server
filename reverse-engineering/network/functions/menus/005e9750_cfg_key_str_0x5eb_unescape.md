# 0x005e9750 cfg_key_str_0x5eb_unescape

| field | value |
|---|---|
| Original address | 0x005e9750 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9750 |
| Resolved name | cfg_key_str_0x5eb_unescape |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005e82c0, FUN_005ec1b0
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x5eb (0x100 str)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies 0x100-byte string into cfg+0x5eb then normalizes via FUN_005e82c0.

## Notes / uncertainty
Twin of 0x9540 → cfg+0x5eb caption with entity-unescape. Which displayed slot it feeds unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9750.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
