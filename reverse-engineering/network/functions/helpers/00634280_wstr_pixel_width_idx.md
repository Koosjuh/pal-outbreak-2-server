# 0x00634280 wstr_pixel_width_idx

| field | value |
|---|---|
| Original address | 0x00634280 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00634280 |
| Resolved name | wstr_pixel_width_idx |
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
Sums glyph pixel widths of a wide-char string using indexed access (short[i]); total width variant.

## Notes / uncertainty
Indexed (short[i]) total-width variant of 00634160; uses FUN_00637d10 return directly as advance (no func_0x001af420 decode) - assumed equivalent.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00634280.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
