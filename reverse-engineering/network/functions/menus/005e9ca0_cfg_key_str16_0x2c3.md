# 0x005e9ca0 cfg_key_str16_0x2c3

| field | value |
|---|---|
| Original address | 0x005e9ca0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9ca0 |
| Resolved name | cfg_key_str16_0x2c3 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x2c3 (16 str)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Field handler: copies a 0x10-byte string into cfg+0x2c3.

## Notes / uncertainty
16-byte row value token → cfg+0x2c3; decoded by FUN_005ec4f0 at commit (FUN_005ef220) with cfg+0x128 fallback. Numeric-vs-symbolic decode unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9ca0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
