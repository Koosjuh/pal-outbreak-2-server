# 0x005cf8e0 cursor_scroll_up_step

| field | value |
|---|---|
| Original address | 0x005cf8e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cf8e0 |
| Resolved name | cursor_scroll_up_step |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cfb20
**Callees:** FUN_0061e720
**Referenced globals:** 0x701078+0x10/0x12/0x20 cursor; 0x701078+4/5/6 counters; 0x701068+0x5ffc0 display-list; 0x701070+4/8 scroll
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701078+4; 0x701078+5

## Behavioral explanation
Advances the cursor/list one step upward, adjusting cursor y against the selected entry position with clamping, and plays the move SFX.

## Notes / uncertainty
Mirror of cf680 (up-step); sub_index floor=1. Same 0x12/20/162 constants. Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cf8e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
