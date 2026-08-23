# 0x005ebb50 markup_attr_byte_f14

| field | value |
|---|---|
| Original address | 0x005ebb50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ebb50 |
| Resolved name | markup_attr_byte_f14 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec650
**Referenced globals:** +0x186 (gate); +0xf14 (attr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Attribute parser (mode 0xf6): parses tag field to a byte at +0xf14, clamping a value of 1 back to 0.

## Notes / uncertainty
Byte attr -> +0xf14 with 1->0 clamp (value 1==default). Attribute meaning unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ebb50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
