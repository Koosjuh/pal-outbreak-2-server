# 0x005d1c20 clamp_cursor_scroll_bounds

| field | value |
|---|---|
| Original address | 0x005d1c20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d1c20 |
| Resolved name | clamp_cursor_scroll_bounds |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** 0x701070+0x4/0x8/0xc/0x10 scroll+content; 0x701070+0x1a..0x20 margins; 0x701078+0x10/0x12 cursor
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Clamps scroll offset and cursor x/y to valid on-screen bounds.

## Notes / uncertainty
Post-input clamp: scroll to [0,content-viewport] (0x17c/0x248), cursor to margin box (0x1b6/0x276 minus margins). Straight min/max; fully determinate.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d1c20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
