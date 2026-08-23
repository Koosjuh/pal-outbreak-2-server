# 0x005b0660 widget_alpha_fade_out

| field | value |
|---|---|
| Original address | 0x005b0660 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b0660 |
| Resolved name | widget_alpha_fade_out |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b0550
**Callees:** —
**Referenced globals:** 0x6c5497 selected index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +5 select; +6 pulse-active; +8 step; +0x4c/+0x50 ramp

## Behavioral explanation
Color pulse animation (fade toward dim) for the selected row: over 16 steps decrements a color channel then latches back to full; triggers only when the row is not the current selection.

## Notes / uncertainty
Renamed pulse_down->alpha_fade_out: single-shot alpha ramp 255->0 over 16f on deselected rows; latches 0x00ffffff. 2^31 float guard is defensive.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b0660.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
