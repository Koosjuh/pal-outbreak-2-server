# 0x005fc000 roomlist_row_marker_widget_cb

| field | value |
|---|---|
| Original address | 0x005fc000 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fc000 |
| Resolved name | roomlist_row_marker_widget_cb |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00618c20
**Referenced globals:** 0x649890 coord table; 0x6c076f slot flag; cRam006c4fd8 base idx
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Small per-frame widget callback: sets sprite coords from a table by index and toggles visibility from a slot flag (@0x6c076f).

## Notes / uncertainty
Room-list row marker sprite cb: latches coords from 0x649890 table, toggles visibility from slot-occupancy flag ((scroll_base+row)*0x15c+0x6c076f); state 2 frees. Arrow-vs-dot not visually confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fc000.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
