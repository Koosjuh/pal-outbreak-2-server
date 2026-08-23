# 0x005e9270 tag_line_break_reset

| field | value |
|---|---|
| Original address | 0x005e9270 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9270 |
| Resolved name | tag_line_break_reset |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005e9360
**Referenced globals:** +4 (out length)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +4

## Behavioral explanation
Markup tag handler: resets out-length +4=0, zeroes output byte, and calls FUN_005e9360 (page/line reset).

## Notes / uncertainty
ctx+4=0, *out=0, then FUN_005e9360->FUN_005ef3f0 commit/draw current run. Three concrete effects certain; 'line break' label inferred from flush+reset+commit shape.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9270.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
