# 0x005d67d0 list_find_pred

| field | value |
|---|---|
| Original address | 0x005d67d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d67d0 |
| Resolved name | list_find_pred |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d6920, FUN_005d70b0, FUN_005d71a0, FUN_005d8840
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Generic helper: returns the predecessor node of a target in a singly-linked list.

## Notes / uncertainty
Find predecessor of target; returns target itself as sentinel when it's the head's immediate next. Decompiled loop has a redundant re-read (cosmetic artifact).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d67d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
