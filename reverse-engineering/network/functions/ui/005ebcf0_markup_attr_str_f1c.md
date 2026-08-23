# 0x005ebcf0 markup_attr_str_f1c

| field | value |
|---|---|
| Original address | 0x005ebcf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ebcf0 |
| Resolved name | markup_attr_str_f1c |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0
**Referenced globals:** iRam007012a0; +0xf1c (attr string buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Markup attribute handler: copies the quoted attribute string into UI ctx buffer +0xf1c.

## Notes / uncertainty
Thinnest handler: tokenizes straight into pending string buffer +0xf1c (0x100), NOT pass-gated; consumed later by 0x5eb7d0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ebcf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
