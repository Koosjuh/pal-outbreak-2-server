# 0x005b08f0 widget_cb_draw_header

| field | value |
|---|---|
| Original address | 0x005b08f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b08f0 |
| Resolved name | widget_cb_draw_header |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_0062fea0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x24 blend flags; +0x2c color

## Behavioral explanation
Per-frame header widget callback: draws a localized title string (id 0x15) at a fixed position via ui_draw_text and sets the widget's blend/color to opaque black.

## Notes / uncertainty
Draws localized header string id 0x15 (font 0x1c) at (0x30,0x14); sets opaque-black backing (+0x2c=0xff000000). String text not resolved (id only).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b08f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
