# 0x005cfb20 menu_cursor_autonav_over_list

| field | value |
|---|---|
| Original address | 0x005cfb20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cfb20 |
| Resolved name | menu_cursor_autonav_over_list |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005cf3a0, FUN_005cf600, FUN_005cf680, FUN_005cf8e0
**Referenced globals:** 0x701068 UI ctx base; 0x701068+0x5ffc0 entity ptr array[500]; 0x701068+0x4f8a8/9 analog stick; 0x701068+0x68e78 cursor idx; 0x701068+0x68e7c/d dpad repeat; 0x701078+0x10/0x12 cursor xy; 0x715da8+0x49c/0x49d pad key codes; 0x36d6dc button code
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x18 view flags; 0x701068+0x4f8a0/0x4f8a4 input flags; 0x36d6dc button

## Behavioral explanation
Moves the on-screen cursor via analog stick + D-pad (with repeat timing) across the widget/entity list, calling per-entry select helpers.

## Notes / uncertainty
Per-frame cursor/selection driver: analog free-move, discrete stick nav (8-frame repeat + list-walk via cf3a0), and D-pad/key path (cf600/cf680/cf8e0). Exact stick-sector->direction split {2..9}fwd vs {1,10..15}back is inferred; dir-key ladder summarized.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cfb20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
