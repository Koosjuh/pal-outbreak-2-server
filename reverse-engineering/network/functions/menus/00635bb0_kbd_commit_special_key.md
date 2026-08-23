# 0x00635bb0 kbd_commit_special_key

| field | value |
|---|---|
| Original address | 0x00635bb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00635bb0 |
| Resolved name | kbd_commit_special_key |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00636f90
**Callees:** FUN_00631ff0, FUN_006322c0, FUN_00635ba0, FUN_00637140, FUN_00637540, FUN_00637690
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x1e active-key; 0x24/0x25 cursor; 0x248 status

## Behavioral explanation
Commits a special-key (case 6/7) selection: resolves via 635ba0, updates active key 0x1e, then full repaint (layout/cursor/redraw), preserving cursor col/row.

## Notes / uncertainty
Action class 6/7: switch active key +0x1e via lookup(class 5), preserve cursor, full redraw, status 1; else no change.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00635bb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
