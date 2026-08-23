# 0x005e96a0 cfg_key_str_0x4eb_raw

| field | value |
|---|---|
| Original address | 0x005e96a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e96a0 |
| Resolved name | cfg_key_str_0x4eb_raw |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x4eb (0x100 str)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Field handler: copies a 0x100-byte string into cfg+0x4eb.

## Notes / uncertainty
Raw string → cfg+0x4eb, NO unescape (unlike 0x9540/0x9750) → identifier/name (inferred). No downstream reader mapped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e96a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
