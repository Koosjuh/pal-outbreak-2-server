# 0x005afa40 widget_cb_selection_marquee

| field | value |
|---|---|
| Original address | 0x005afa40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005afa40 |
| Resolved name | widget_cb_selection_marquee |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** 0x6c5497 cRam006c5497 selected index; 0x638910 coord/color table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +4 anim state; +0x38 last-sel; +0x2c color; +0x4c/+0x50 lerp

## Behavioral explanation
Per-frame widget callback: animates a widget's RGBA/position by state (+4) with a color/alpha ramp keyed to the current selection index cRam006c5497, sourcing target coords from a const table (0x638910).

## Notes / uncertainty
Renamed from color_fade: tracks selection with an 8-frame vertical slide AND an alpha-pulse FSM on +4. Blink cadence and ARGB channel order inferred, not observed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005afa40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
