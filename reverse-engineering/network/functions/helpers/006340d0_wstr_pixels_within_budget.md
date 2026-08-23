# 0x006340d0 wstr_pixels_within_budget

| field | value |
|---|---|
| Original address | 0x006340d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006340d0 |
| Resolved name | wstr_pixels_within_budget |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00632390
**Callees:** FUN_00637d10, FUN_00637e90
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns the accumulated pixel width of a wide-char string truncated to a max pixel budget (param_2).

## Notes / uncertainty
Font-guarded; returns accumulated px of prefix within budget (crossing glyph included). Companion to 006341d0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006340d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
