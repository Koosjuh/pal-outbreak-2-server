# 0x005cf600 selection_focus_reset

| field | value |
|---|---|
| Original address | 0x005cf600 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cf600 |
| Resolved name | selection_focus_reset |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cfb20, FUN_005d1e80
**Callees:** FUN_0061e740
**Referenced globals:** 0x701078+0x10/0x12/0x20 cursor; 0x701078+4 flag; 0x701068+0x5ffc0 display-list; 0x701070+8 scroll y
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701078+0x20; 0x701078+4

## Behavioral explanation
Recomputes the cursor y-target from the selected entry, clears the selection index/flag (0x701078+0x20/+4) and plays the cancel SFX.

## Notes / uncertainty
Collapses expanded group + snaps cursor to selected entity row, clears group_count/selected_idx, plays cancel SFX (0061e740). Straight-line, no branches. SFX id inferred; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cf600.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
