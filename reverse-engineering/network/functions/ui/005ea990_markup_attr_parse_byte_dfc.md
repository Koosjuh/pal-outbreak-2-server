# 0x005ea990 markup_attr_parse_byte_dfc

| field | value |
|---|---|
| Original address | 0x005ea990 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ea990 |
| Resolved name | markup_attr_parse_byte_dfc |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec650
**Referenced globals:** +0x186 (mode gate 0xf6); +0xdfc (attr value)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Attribute parser (mode +0x186==0xf6 only): parses tag field to a byte at +0xdfc, and if non-zero bumps it by 1.

## Notes / uncertainty
Cell-attr byte parser, gated mode +0x186==0xF6 (decompiler -10): FUN_005ec650 token->byte at +0xdfc, +1 bias if non-zero (0=unset). Attr identity unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ea990.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
