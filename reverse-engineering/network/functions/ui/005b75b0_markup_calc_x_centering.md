# 0x005b75b0 markup_calc_x_centering

| field | value |
|---|---|
| Original address | 0x005b75b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b75b0 |
| Resolved name | markup_calc_x_centering |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b76f0
**Callees:** —
**Referenced globals:** fRam006ca860 (pen X); fRam006ca86c (base X)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Compute a centered X pen position (fRam006ca860) from a glyph-width scale and run length (float math, even-rounding).

## Notes / uncertainty
Center-align pen X = base + (360 - chars*halfW)/2; sub-unit scale even-snapped. 360px field width unconfirmed vs layout. Raised Low->Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b75b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
