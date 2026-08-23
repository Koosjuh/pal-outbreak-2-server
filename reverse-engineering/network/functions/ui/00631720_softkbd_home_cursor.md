# 0x00631720 softkbd_home_cursor

| field | value |
|---|---|
| Original address | 0x00631720 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631720 |
| Resolved name | softkbd_home_cursor |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006300a0
**Callees:** —
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x2f IME state; +0x260 IME buffer; +0x2a/0x2c cursors; +0x28 dirty; +0x248 result code

## Behavioral explanation
Clear-field key (0x4a): resets the active buffer cursor (+0x2a or +0x2c) to 0 and marks dirty, result 1.

## Notes / uncertainty
Renamed from clear_line. Home key (0x4a): resets active-buffer caret (+0x2a or +0x2c) to 0 - it moves the caret, does NOT erase text; marks dirty, result 1.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631720.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
