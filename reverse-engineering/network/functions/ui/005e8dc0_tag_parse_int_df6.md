# 0x005e8dc0 tag_parse_int_df6

| field | value |
|---|---|
| Original address | 0x005e8dc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8dc0 |
| Resolved name | tag_parse_int_df6 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec650
**Referenced globals:** +0xdf6 (int field)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xdf6

## Behavioral explanation
Markup tag handler: extracts string arg and parses it to an int (FUN_005ec650) stored at +0xdf6.

## Notes / uncertainty
Extract arg, atoi via FUN_005ec650, store u16 at +0xdf6 = advance-width (reset 0x1e, read in ee610). Unit px/cell unpinned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8dc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
