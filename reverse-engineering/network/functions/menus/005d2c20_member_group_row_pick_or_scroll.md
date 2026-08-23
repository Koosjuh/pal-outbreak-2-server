# 0x005d2c20 member_group_row_pick_or_scroll

| field | value |
|---|---|
| Original address | 0x005d2c20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d2c20 |
| Resolved name | member_group_row_pick_or_scroll |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d1e80
**Callees:** FUN_005d5df0, FUN_0061e730
**Referenced globals:** 0x701068+0x5ffc0 entity array; 0x701078+2..0x1c row/thumb state; 0x701070+0x4/0x8 scroll
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701078+6 orientation flag

## Behavioral explanation
For a multi-row list group under the cursor, recomputes row index / thumb geometry and nudges scroll/cursor via 5df0.

## Notes / uncertainty
RENAMED from list_row_scroll_recompute: handles click in an open member group - group mini-scrollbar (returns head_idx, stays open) or row-pick+commit (copies member +0x60/+0x5f into head, collapses, returns 0). Called only by 1e80. Thumb ladders summarized.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d2c20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
