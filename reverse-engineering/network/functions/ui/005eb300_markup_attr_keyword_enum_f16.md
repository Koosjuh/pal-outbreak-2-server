# 0x005eb300 markup_attr_keyword_enum_f16

| field | value |
|---|---|
| Original address | 0x005eb300 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb300 |
| Resolved name | markup_attr_keyword_enum_f16 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec920
**Referenced globals:** +0xf16 (align/enum attr)
**Referenced strings:** 0x648320 (keyword table, len 0x20)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Attribute handler: matches tag field against keyword table 0x648320 (len 0x20), stores the enum at +0xf16 (unconditional).

## Notes / uncertainty
Keyword-enum attr via FUN_005ec920 against table@0x648320 (4 entries) -> +0xf16. Likely halign; keyword strings not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eb300.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
