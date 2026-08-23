# 0x005eac40 markup_attr_parse_int_e08

| field | value |
|---|---|
| Original address | 0x005eac40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eac40 |
| Resolved name | markup_attr_parse_int_e08 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec4f0
**Referenced globals:** +0x186 (gate); +0xe08 (attr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Attribute parser (mode 0xf6): parses tag field to a 32-bit value (FUN_005ec4f0) at +0xe08.

## Notes / uncertainty
Ungated-by-emptiness int/color parse -> +0xe08 when pass_mode 0xF6. e08 vs e0c distinction unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eac40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
