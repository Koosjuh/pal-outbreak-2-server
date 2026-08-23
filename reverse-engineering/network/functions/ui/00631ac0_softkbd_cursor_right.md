# 0x00631ac0 softkbd_cursor_right

| field | value |
|---|---|
| Original address | 0x00631ac0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631ac0 |
| Resolved name | softkbd_cursor_right |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006300a0, FUN_00635030
**Callees:** FUN_00630c70, FUN_00631910, FUN_00631a30, FUN_00634010, FUN_00634160
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x2f IME state; +0x260 IME buffer; +0x2a main cursor; +0x4c main buffer; +0x28 dirty; +0x248 result code

## Behavioral explanation
Right key (0x4f): if grid-nav allowed moves grid cursor right, else advances the text cursor (+0x2a) one char in the main buffer.

## Notes / uncertainty
Right key: grid-move-right when grid nav allowed, else advance text caret +0x2a by char width. FUN_00630c70 gate meaning (boundary guard) and the a0-clamp branch remain inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631ac0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
