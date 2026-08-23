# 0x005cebc0 scroll_view_to_entry

| field | value |
|---|---|
| Original address | 0x005cebc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cebc0 |
| Resolved name | scroll_view_to_entry |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cf3a0
**Callees:** —
**Referenced globals:** 0x701068+0x5ffc0 display-list; 0x701068+0x68e78 focused entry; 0x701070+0x1a/0x1c/0x1e/0x20 viewport bounds; 0x701070+4/8 scroll xy; 0x701078+0x10/0x12 target
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x68e78

## Behavioral explanation
Scrolls the list viewport (writes 0x701078+0x10/0x12 and pans 0x701070+4/8) so that display-list entry param_1 is on-screen, clamped to bounds; records the focused entry at 0x68e78.

## Notes / uncertainty
Pans viewport to display entry using float coords node+0x34(X)/+0x38(Y); param_2=force flag (0=far-threshold bail returns 0, clears ov+0x68e78). Clamps 0x17c/0x248, thresholds 0x19c/0x270, sets ov+0x68e78=id. scr scroll/bound field names inferred; 1D-vs-2D axis unclear.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cebc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
