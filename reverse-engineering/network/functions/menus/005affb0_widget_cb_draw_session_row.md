# 0x005affb0 widget_cb_draw_session_row

| field | value |
|---|---|
| Original address | 0x005affb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005affb0 |
| Resolved name | widget_cb_draw_session_row |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005b0950, FUN_005bb060, FUN_0062fea0
**Referenced globals:** 0x6389c0 PTR_s_ses_Titels_ label ptrs; 0x6c386e/0x6c3878 per-row table (0x15c stride)
**Referenced strings:** ses_Titels_
**Referenced opcodes:** —
**State vars:** +3 row index; +4 state

## Behavioral explanation
Per-frame draw callback that renders a session-title list row with its score: copies coord/label tables (PTR_s_ses_Titels_), fetches a localized string and the row score (score_fetch_clamped), formats and prints them via ui_draw_text at the row position.

## Notes / uncertainty
Draws title(0x6c3878)/subtitle/summed-score per row; status byte==3 selects highlight color. Exact split of copied coord tables (auStack_28/88 aliasing) approximated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005affb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
