# 0x00631f80 softkbd_delete_char_at

| field | value |
|---|---|
| Original address | 0x00631f80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631f80 |
| Resolved name | softkbd_delete_char_at |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631030
**Callees:** FUN_006341d0, FUN_00637e10
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x28 dirty

## Behavioral explanation
Deletes one char at a given cursor position in a buffer (null then shift), returns the position; no-op if position 0.

## Notes / uncertainty
Parameterised delete: nulls buf[0] then copies from cols_to_index(caret) forward -> prefix delete up to caret. Exact caller intent (prefix vs single) noted uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631f80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
