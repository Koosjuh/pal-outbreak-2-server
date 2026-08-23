# 0x00634310 wstr_pixel_width_min2

| field | value |
|---|---|
| Original address | 0x00634310 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00634310 |
| Resolved name | wstr_pixel_width_min2 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006320f0
**Callees:** FUN_00637d10, FUN_00637e90
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sums glyph pixel widths but forces a minimum advance of 2 per single-width glyph (monospace-ish measure).

## Notes / uncertainty
Indexed total-width with min-cell clamp: advance==1 bumped to 2. Reason for the specific ==1 clamp inferred (hairline/combining glyph).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00634310.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
