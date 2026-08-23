# 0x00634010 wstr_glyph_advance_at_budget

| field | value |
|---|---|
| Original address | 0x00634010 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00634010 |
| Resolved name | wstr_glyph_advance_at_budget |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631ac0, FUN_00632390
**Callees:** FUN_00637d10, FUN_00637e90
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Hit-tests a wide-char string: returns the glyph advance at the column reached within pixel budget param_2, or -1 if the string overflows it.

## Notes / uncertainty
Renamed from wstr_char_index_at_pixel: font-guarded, returns -1 on overflow else advance of boundary glyph (returns advance, not the count i). 0=font-not-loaded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00634010.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
