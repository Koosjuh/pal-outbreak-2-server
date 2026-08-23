# 0x005ebaf0 markup_attr_short_f12

| field | value |
|---|---|
| Original address | 0x005ebaf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ebaf0 |
| Resolved name | markup_attr_short_f12 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec650
**Referenced globals:** +0x186 (gate); +0xf12 (attr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Attribute parser (mode 0xf6): parses tag field to a 16-bit value at +0xf12.

## Notes / uncertainty
Plain 16-bit numeric attr via FUN_005ec650 -> pending +0xf12, gated 0xf6.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ebaf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
