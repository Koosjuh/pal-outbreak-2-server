# 0x005e9cd0 markup_attr_read_style2d3

| field | value |
|---|---|
| Original address | 0x005e9cd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9cd0 |
| Resolved name | markup_attr_read_style2d3 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x2d3 (16 str)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Field handler: copies a 0x10-byte string into cfg+0x2d3.

## Notes / uncertainty
Markup attr handler: reads ="..." value into 16-byte pending style slot +0x2d3 (consumed by FUN_005ef220 style push). Exact attribute meaning (color/face) depends on undecoded FUN_005ec800.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9cd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
