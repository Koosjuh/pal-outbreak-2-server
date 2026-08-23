# 0x006341d0 wstr_charcount_within_width

| field | value |
|---|---|
| Original address | 0x006341d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006341d0 |
| Resolved name | wstr_charcount_within_width |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631810, FUN_00631ec0, FUN_00631f80, FUN_006320f0, FUN_00632390, FUN_00635cb0
**Callees:** FUN_00637d10, FUN_00637e90
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns the number of wide-chars that fit within a given pixel budget (param_2).

## Notes / uncertainty
Returns glyph COUNT fitting within ushort pixel budget (vs 006340d0's pixels). Crossing glyph counted.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006341d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
