# 0x001e14e8 drain_free_queue_off8

| field | value |
|---|---|
| Original address | 0x001e14e8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e14e8 |
| Resolved name | drain_free_queue_off8 |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d46ec
**Callees:** FUN_001e2010, FUN_001eb434, FUN_001ec9e0
**Referenced globals:** conn+0x520 pool
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Drains every node from a list at struct+8 back to the connection block-pool (conn+0x520), then frees the container.

## Notes / uncertainty
Teardown: pops all nodes from container list at +8, returns each reliable segment to conn+0x520 pool via FUN_001ec9e0 (ACK/reorder reconcile), then frees container. Mid-drain reconcile error leaks remaining nodes.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e14e8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
