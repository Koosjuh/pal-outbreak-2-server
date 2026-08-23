# 0x00634160 wstr_pixel_width

| field | value |
|---|---|
| Original address | 0x00634160 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00634160 |
| Resolved name | wstr_pixel_width |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630c90, FUN_00631880, FUN_00631ac0, FUN_006320f0, FUN_00632390, FUN_006345e0, FUN_006378b0
**Callees:** FUN_00637d10, FUN_00637e90
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sums glyph pixel widths over a whole wide-char string (total rendered width).

## Notes / uncertainty
Core total-width primitive (7 callers), font-guarded, sums advances to NUL. Simplest of family; metrics-field = horizontal advance assumed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00634160.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
