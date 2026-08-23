# 0x00631030 softkbd_backspace_handler

| field | value |
|---|---|
| Original address | 0x00631030 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631030 |
| Resolved name | softkbd_backspace_handler |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006300a0
**Callees:** FUN_00630c70, FUN_00631f80, FUN_00635cb0
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x4a flags; +0x2f IME state; +0x2a/0x2c cursors; +0x260 IME buffer; +0x32 exit code; +0x248 result code

## Behavioral explanation
Backspace/delete key (0x2a): removes a char at the cursor from the active buffer (main +0x4c or IME +0x260) when allowed.

## Notes / uncertainty
Backspace (0x2a): delete-before-caret on active buffer (main +0x4c / IME +0x260); +0x4a bit0 cancel-latch path exits with code 0xff/result 2. FUN_00631f80 delete granularity (1 unit vs glyph) not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631030.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
