# 0x005ebc50 markup_attr_color_f18

| field | value |
|---|---|
| Original address | 0x005ebc50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ebc50 |
| Resolved name | markup_attr_color_f18 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec4f0
**Referenced globals:** iRam007012a0; +0x186 (pass flag); +0xf18 (attr color slot)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Markup attribute handler: extracts a token and parses it as a color value (parse_color_value) into UI ctx +0xf18 on the measure pass.

## Notes / uncertainty
Color attr via parse_color_value -> 32-bit pending +0xf18; extra non-empty guard vs numeric handlers.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ebc50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
