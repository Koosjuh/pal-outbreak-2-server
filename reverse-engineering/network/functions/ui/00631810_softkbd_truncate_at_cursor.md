# 0x00631810 softkbd_truncate_at_cursor

| field | value |
|---|---|
| Original address | 0x00631810 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631810 |
| Resolved name | softkbd_truncate_at_cursor |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00631790
**Callees:** FUN_006341d0, FUN_00637e90
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x28 dirty

## Behavioral explanation
Truncates a text buffer at the cursor index (null-terminates) if cursor < length, marking dirty.

## Notes / uncertainty
Leaf: null-terminate UTF-16 buffer at caret->index (FUN_006341d0) if idx<len(FUN_00637e90), mark dirty. Whether FUN_006341d0 returns caret or caret+1 (delete-one vs delete-to-end) undecided.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631810.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
