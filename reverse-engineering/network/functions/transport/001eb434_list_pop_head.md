# 0x001eb434 list_pop_head

| field | value |
|---|---|
| Original address | 0x001eb434 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb434 |
| Resolved name | list_pop_head |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5138, FUN_001d6468, FUN_001d6dfc, FUN_001e14e8, FUN_001e1608, FUN_001e2654, FUN_001e366c, FUN_001e3880, FUN_001eb9a0, FUN_001ec1f8, FUN_001ecdc0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Dequeues the head node, decrements count, returns node in param_2; yields 0xffffe4aa when the list is empty.

## Notes / uncertainty
FIFO dequeue of header->next; returns SNAP_ERR_EMPTY 0xffffe4aa on empty. Exact inverse of insert_tail. No runtime proof.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb434.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
