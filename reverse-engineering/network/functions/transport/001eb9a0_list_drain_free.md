# 0x001eb9a0 list_drain_free

| field | value |
|---|---|
| Original address | 0x001eb9a0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb9a0 |
| Resolved name | list_drain_free |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001eb434, FUN_001ebe28
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Pops every node from the list and frees each until empty (stops on the empty sentinel).

## Notes / uncertainty
Pop+free every node until SNAP_ERR_EMPTY; frees via FUN_001ebe28->mem_free. Top-of-loop error return preserved exactly. Assumes all nodes are buf_nodes (unproven).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb9a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
