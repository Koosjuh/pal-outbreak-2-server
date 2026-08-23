# 0x005eba50 markup_attr_short_f10_celldefault

| field | value |
|---|---|
| Original address | 0x005eba50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eba50 |
| Resolved name | markup_attr_short_f10_celldefault |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec6d0
**Referenced globals:** +0x186 (gate); +0xd894; +0x24e0; +0xf10 (width attr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Attribute parser (mode 0xf6): parses tag field via FUN_005ec6d0 defaulting to current cell metric (+0x24e0->+0x1c), stores 16-bit at +0xf10.

## Notes / uncertainty
Short attr defaulting to current cell metric (cell+0x1c) -> pending +0xf10 via FUN_005ec6d0. Width-like inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eba50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
