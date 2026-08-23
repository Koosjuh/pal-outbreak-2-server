# 0x005daf30 ui_draw_item_list

| field | value |
|---|---|
| Original address | 0x005daf30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005daf30 |
| Resolved name | ui_draw_item_list |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005dfee0, FUN_005e0440, FUN_005e2760, FUN_005e2fa0, FUN_005e3a80
**Referenced globals:** iRam00701068+0x5ffc0: widget/item list (500 ptrs); iRam00701078+0x20: selected index; iRam00701070+0x34: suppress flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x34; 0x20

## Behavioral explanation
UI draw callback: iterates the 500-entry widget/item list (iRam00701068+0x5ffc0), rendering each and drawing a highlight rect (color 0x400000ff) around the currently-selected index (+0x20).

## Notes / uncertainty
Renamed from ui_draw_selection_overlay: renders 500-slot packed item table (0x5ffc0) + translucent highlight (0x400000ff) on selected index (0x78+0x20). Whether list is room-list/roster is state-dependent, not proven; no protocol work.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005daf30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
