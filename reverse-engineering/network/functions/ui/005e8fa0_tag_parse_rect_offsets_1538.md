# 0x005e8fa0 tag_parse_rect_offsets_1538

| field | value |
|---|---|
| Original address | 0x005e8fa0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8fa0 |
| Resolved name | tag_parse_rect_offsets_1538 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0
**Referenced globals:** +0x1538/+0x153a/+0x153c/+0x153e (coord tuple)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1538..+0x153e

## Behavioral explanation
Markup tag handler: parses up to four comma-separated decimal numbers into +0x1538/+0x153a/+0x153c/+0x153e (a rect/coord tuple).

## Notes / uncertainty
Parses up to 4 comma-separated decimals into 4 s16 rect offsets +0x1538..+0x153e, added to base rect in FUN_005ee470 draw. Axis ordering (x/y) inferred from draw-arg order; parse certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8fa0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
