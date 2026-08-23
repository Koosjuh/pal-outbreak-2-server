# 0x00631bb0 softkbd_cursor_left

| field | value |
|---|---|
| Original address | 0x00631bb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631bb0 |
| Resolved name | softkbd_cursor_left |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006300a0, FUN_00635030
**Callees:** FUN_00630c70, FUN_00631910, FUN_00631a30, FUN_00633fa0
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x2f IME state; +0x260 IME buffer; +0x2a main cursor; +0x4c main buffer; +0x28 dirty; +0x248 result code

## Behavioral explanation
Left key (0x50): if grid-nav allowed moves grid cursor left, else retreats the text cursor (+0x2a) one char.

## Notes / uncertainty
Mirror of cursor_right: grid-move-left or retreat caret by prev-char width (FUN_00633fa0); snap-home on gate. Same FUN_00630c70 uncertainty.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631bb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
