# 0x005e9ef0 markup_meta_parse_value

| field | value |
|---|---|
| Original address | 0x005e9ef0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9ef0 |
| Resolved name | markup_meta_parse_value |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec430, FUN_005ec650
**Referenced globals:** +0x1120 (gate flag); +0x1124 (parsed value)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1120; +0x1124

## Behavioral explanation
If meta-tag flag +0x1120 set, parses the tag field to an int and stores it in +0x1124.

## Notes / uncertainty
Gated on +0x1120: atoi (FUN_005ec650) of char-attr (FUN_005ec430) into +0x1124. Unit inferred from FUN_005d89d0 *0x1e scaling.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9ef0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
