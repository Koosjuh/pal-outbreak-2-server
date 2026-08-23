# 0x001d5138 snap_sublist_free_all

| field | value |
|---|---|
| Original address | 0x001d5138 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d5138 |
| Resolved name | snap_sublist_free_all |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d46ec
**Callees:** FUN_001e2010, FUN_001eb434, FUN_001ec9e0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Walks a buffer list at param+8 and releases every node back to the pool, then frees the list container.

## Notes / uncertainty
Destructor for snap_alloc_subctx: frees all +8 list nodes to conn->reliable_pool(+0x520) then frees container; -0x1b56 end sentinel.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d5138.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
