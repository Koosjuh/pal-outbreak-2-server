# 0x005eb9f0 markup_attr_keyword_enum_f17

| field | value |
|---|---|
| Original address | 0x005eb9f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb9f0 |
| Resolved name | markup_attr_keyword_enum_f17 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec920
**Referenced globals:** +0x186 (gate); +0xf17 (align attr)
**Referenced strings:** 0x648350 (keyword table)
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Mode-gated (+0x186==0xf6) version of 0x5eb350: matches keyword table 0x648350 and stores enum at +0xf17.

## Notes / uncertainty
Twin of 0x5eb990; table 0x648350 -> pending +0xf17. Attribute identity unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eb9f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
