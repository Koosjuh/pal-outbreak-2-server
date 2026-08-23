# 0x005dcb90 ui_cursor_hittest_select

| field | value |
|---|---|
| Original address | 0x005dcb90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dcb90 |
| Resolved name | ui_cursor_hittest_select |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005dfee0, FUN_005e0570, FUN_005e1aa0, FUN_005e4840
**Referenced globals:** iRam00701068+0x5ffc0/0x5ffbc/0x5ffc4: item lists; iRam00701068+0x68e78: hovered index; iRam00701078+0x10/0x12: cursor x/y; iRam00701070+0x18/0x34/0x36/0x2e/0x3a: UI flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x68e78; 0x18; 0x34; 0x2e

## Behavioral explanation
UI draw/hit-test callback: moves the on-screen cursor, scans the 500-entry item list for the row under the pointer (type-filtered), draws a bounce-animated highlight box (FUN_005e1aa0) around the hovered item and its paired items, and records the hovered index at 0x68e78.

## Notes / uncertainty
Cursor hit-test: scans 500 rows of list 0x5ffc0 filtered by item type +2 (UI class, not opcode), point-in-rect using view pan, records hovered idx 0x68e78, highlights paired rows. Pre-loop bVar10 seed approximate (decompiler-merged); no protocol I/O.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dcb90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
