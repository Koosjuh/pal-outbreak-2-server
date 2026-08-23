# 0x005d6810 list_advance_if_next_inuse

| field | value |
|---|---|
| Original address | 0x005d6810 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6810 |
| Resolved name | list_advance_if_next_inuse |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d6920, FUN_005d71e0, FUN_005d72d0, FUN_005d8840
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node+0x41

## Behavioral explanation
Generic helper: returns the first list node whose alloc flag (+0x41) is clear, else the given node.

## Notes / uncertainty
Renamed from list_first_alloc_node: advances cursor by one iff next node alloc!=0, else holds. Pins cursor at in-use/free boundary. Table keeps old name per convention.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6810.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
