# 0x005eb3a0 markup_attr_int_or_color_f18

| field | value |
|---|---|
| Original address | 0x005eb3a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb3a0 |
| Resolved name | markup_attr_int_or_color_f18 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec4f0
**Referenced globals:** +0xf18 (32-bit attr, e.g. bgcolor)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Attribute handler: if field non-empty, parses it to a 32-bit value (FUN_005ec4f0) at +0xf18.

## Notes / uncertainty
Ungated int/color parse (FUN_005ec4f0) -> +0xf18 when value non-empty. Likely bg/border color; inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eb3a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
