# 0x005e8e00 tag_parse_int_df8

| field | value |
|---|---|
| Original address | 0x005e8e00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8e00 |
| Resolved name | tag_parse_int_df8 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec650
**Referenced globals:** +0xdf8 (int field)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xdf8

## Behavioral explanation
Markup tag handler: extracts string arg and parses to int (FUN_005ec650) stored at +0xdf8.

## Notes / uncertainty
Sibling of 8dc0 targeting +0xdf8 = line-height (reset 0x1e, height-min in ee610 measure pass). Unit unpinned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8e00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
