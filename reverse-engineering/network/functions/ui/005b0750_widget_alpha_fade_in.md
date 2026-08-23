# 0x005b0750 widget_alpha_fade_in

| field | value |
|---|---|
| Original address | 0x005b0750 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b0750 |
| Resolved name | widget_alpha_fade_in |
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
Color pulse animation (brighten) for the currently selected row: over 16 steps ramps a color channel up then latches to full white; mirror of widget_color_pulse_down.

## Notes / uncertainty
Exact mirror of fade_out: alpha 0->255 on the selected row, latches 0xffffffff. Renamed pulse_up->alpha_fade_in.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b0750.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
