# 0x005eaa10 markup_attr_parse_short_dfe

| field | value |
|---|---|
| Original address | 0x005eaa10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eaa10 |
| Resolved name | markup_attr_parse_short_dfe |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec650
**Referenced globals:** +0x186 (gate); +0xdfe (attr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Attribute parser (mode 0xf6): parses tag field to a 16-bit value stored at +0xdfe.

## Notes / uncertainty
u16 cell-attr into +0xdfe, same 0xF6 gate, no bias. Part of contiguous +0xdfc..+0xe02 attr block. Attr identity unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eaa10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
