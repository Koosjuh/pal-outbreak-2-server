# 0x0061cc80 text_center_x

| field | value |
|---|---|
| Original address | 0x0061cc80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061cc80 |
| Resolved name | text_center_x |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061c9f0, FUN_0061d080, FUN_0061d210, FUN_0061d3a0, FUN_0061ea50, FUN_0061eab0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Computes a horizontally-centered X coordinate for a string given its measured pixel width against a 640px screen.

## Notes / uncertainty
(640 - glyphs*(scale/2))/2 center math. func_0x001ae3e0 assumed glyph count (scale/2 factor implies it).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061cc80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
