# 0x00631620 softkbd_clear_buffers

| field | value |
|---|---|
| Original address | 0x00631620 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631620 |
| Resolved name | softkbd_clear_buffers |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00635ab0
**Callees:** —
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x260 IME buffer; +0x4c main buffer; +0x2a/0x2c cursors

## Behavioral explanation
Zeroes the keyboard text/IME buffers and cursors (+0x260,+0x262,+0x4c,+0x4e,+0x2c,+0x2a).

## Notes / uncertainty
Leaf: zero main(+0x4c)/IME(+0x260) UTF-16 buffers, their lengths(+0x4e/+0x262), and both carets(+0x2a/+0x2c). Whether length words carry a flag bit not fully confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631620.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
