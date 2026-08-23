# 0x00633fa0 measure_wstr_width_limited

| field | value |
|---|---|
| Original address | 0x00633fa0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00633fa0 |
| Resolved name | measure_wstr_width_limited |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631bb0, FUN_00635cb0
**Callees:** FUN_00637d10
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Walks a wide-char string accumulating glyph pixel widths until a pixel budget (param_2) is reached; returns last glyph advance.

## Notes / uncertainty
Accumulate glyph advances to NUL or pixel budget; returns LAST glyph advance (not total) as decompiled - unusual, callers would disambiguate. No font guard.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00633fa0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
