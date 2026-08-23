# 0x005e9300 tag_read_attr_2a3

| field | value |
|---|---|
| Original address | 0x005e9300 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9300 |
| Resolved name | tag_read_attr_2a3 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x2a3 (short str field, 16)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Field handler: copies a 0x10-byte string token into cfg+0x2a3.

## Notes / uncertainty
16B named per-glyph attr ctx+0x2a3; resolved into per-glyph array ctx+0x128[ctx+0x124] in FUN_005ef3f0. Upgraded Medium->High. Which glyph property unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9300.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
