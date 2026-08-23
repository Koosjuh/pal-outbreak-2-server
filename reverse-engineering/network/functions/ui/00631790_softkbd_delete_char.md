# 0x00631790 softkbd_delete_char

| field | value |
|---|---|
| Original address | 0x00631790 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631790 |
| Resolved name | softkbd_delete_char |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006300a0
**Callees:** FUN_00630c70, FUN_00631810, FUN_00631ec0
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x2f IME state; +0x260 IME buffer; +0x2a/0x2c cursors; +0x4c main buffer; +0x248 result code

## Behavioral explanation
Delete key (0x4c): removes the char at cursor from the active buffer (via delete-to-end or truncate helpers).

## Notes / uncertainty
Forward Delete (0x4c): gated on ime_state==0 (else 5); routes to FUN_00631ec0 (predicate==0) or truncate-at-cursor FUN_00631810. Difference between the two delete paths + 00630c70 arg not fully decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631790.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
