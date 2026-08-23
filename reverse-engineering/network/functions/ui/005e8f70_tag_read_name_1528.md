# 0x005e8f70 tag_read_name_1528

| field | value |
|---|---|
| Original address | 0x005e8f70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8f70 |
| Resolved name | tag_read_name_1528 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0
**Referenced globals:** +0x1528 (16-byte field)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Markup tag handler: extracts a 0x10-byte string arg into render-ctx field +0x1528.

## Notes / uncertainty
FUN_005ec1b0 extracts KEY=value into 16B ctx+0x1528 (anchor NAME attr, matched by 0x5e91f0). Extractor mechanics certain; name role from consumer chain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8f70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
