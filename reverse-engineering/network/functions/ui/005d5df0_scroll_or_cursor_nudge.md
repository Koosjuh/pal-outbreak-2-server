# 0x005d5df0 scroll_or_cursor_nudge

| field | value |
|---|---|
| Original address | 0x005d5df0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d5df0 |
| Resolved name | scroll_or_cursor_nudge |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d1670, FUN_005d2c20
**Callees:** —
**Referenced globals:** 0x701070+0x4/0x8 scroll; 0x701078+5 row; 0x701068+0x69018 redraw; 0x701078+3 dir
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x69018

## Behavioral explanation
Helper: by mode, adds to scroll offset (1-4) or bumps cursor row (5-6); flags redraw and records nudge direction.

## Notes / uncertainty
dir 1-4 pan scroll offset, dir 5-6 step cursor_row; always sets redraw latch 0x69018=2 and nudge_dir +3. Row/dir labels inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d5df0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
