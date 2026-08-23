# 0x005e9540 cfg_key_str_0x3e4_unescape

| field | value |
|---|---|
| Original address | 0x005e9540 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9540 |
| Resolved name | cfg_key_str_0x3e4_unescape |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005e82c0, FUN_005ec1b0
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x3e4 (0x100 str)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies 0x100-byte string into cfg+0x3e4 then normalizes/validates it via FUN_005e82c0.

## Notes / uncertainty
Caption/label string handler → cfg+0x3e4 with entity-unescape (FUN_005e82c0). Mechanism certain; field-role (caption) inferred from FUN_005edc40 measure usage. Dispatch keyword unmapped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9540.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
