# 0x005d79e0 roster_clear_all

| field | value |
|---|---|
| Original address | 0x005d79e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d79e0 |
| Resolved name | roster_clear_all |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d7090
**Callees:** FUN_005d6b40, FUN_005d6ce0
**Referenced globals:** 0x004f47c roster pool head
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Drains the roster pool by repeatedly freeing the last active node (pool_last_active + roster_pool_free_node), then calls cleanup func_0x001841d0.

## Notes / uncertainty
Drain loop: pool_next_active + free each node, then finalize func_0x001841d0. Traversal order and finalize exact role inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d79e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
