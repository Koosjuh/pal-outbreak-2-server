# 0x005d68e0 list_rotate_until_head

| field | value |
|---|---|
| Original address | 0x005d68e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d68e0 |
| Resolved name | list_rotate_until_head |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d6920, FUN_005d8840
**Callees:** FUN_005d6840
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Generic helper: rotates the list (via 6840) until the given node is at the head.

## Notes / uncertainty
Rotate/drain until head->next==target. 0x6840 called with 2 args (head,cursor); decompiler showed only one — cursor round-trips via return.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d68e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
