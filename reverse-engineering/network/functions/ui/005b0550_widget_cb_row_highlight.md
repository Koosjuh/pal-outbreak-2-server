# 0x005b0550 widget_cb_row_highlight

| field | value |
|---|---|
| Original address | 0x005b0550 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b0550 |
| Resolved name | widget_cb_row_highlight |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005b0660, FUN_005b0750
**Referenced globals:** 0x6c5497 selected index; 0x638a20 coord table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +3 row index; +4 state; +5 selected

## Behavioral explanation
Per-frame list-row widget callback: on init sets the row color by whether it is the selected row (cRam006c5497) and its coords from a table (0x638a20); once active dispatches to the fade-out/fade-in pulsers.

## Notes / uncertainty
Row highlight init + dispatch to fade_in/fade_out by +5 flag (inverted sense: +5==0 on selected row -> pulse_up). Coord table 0x638a20.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b0550.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
