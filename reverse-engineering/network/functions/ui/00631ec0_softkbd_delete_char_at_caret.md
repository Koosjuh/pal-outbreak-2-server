# 0x00631ec0 softkbd_delete_char_at_caret

| field | value |
|---|---|
| Original address | 0x00631ec0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631ec0 |
| Resolved name | softkbd_delete_char_at_caret |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631790
**Callees:** FUN_006341d0, FUN_00637e10, FUN_00637e90
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x2f IME state; +0x260 IME buffer; +0x4c main buffer; +0x2a/0x2c cursors; +0x28 dirty

## Behavioral explanation
Deletes the char at cursor and shifts the tail of the active buffer left (delete-and-shift), marking dirty.

## Notes / uncertainty
Renamed from delete_to_end: it is a single forward-delete with tail-shift on active buffer (main +0x4c or predictive +0x260), not a truncate.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631ec0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
