# 0x005eabd0 markup_attr_parse_int_e0c

| field | value |
|---|---|
| Original address | 0x005eabd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eabd0 |
| Resolved name | markup_attr_parse_int_e0c |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec4f0
**Referenced globals:** +0x186 (gate); +0xe0c (attr, e.g. color)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Attribute parser (mode 0xf6, only if field non-empty): parses tag field to a 32-bit value (FUN_005ec4f0) at +0xe0c.

## Notes / uncertainty
Same as e08 but +0xe0c, with non-empty guard; FUN_005ec4f0 = #hex/HTML-color/int parser. fg-vs-bg role inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eabd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
