# 0x001d533c snap_alloc_ctrl_buf_876

| field | value |
|---|---|
| Original address | 0x001d533c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d533c |
| Resolved name | snap_alloc_ctrl_buf_876 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6ee0, FUN_001d9b6c
**Callees:** FUN_001d5288
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a 0x36c-payload control buffer via the packet allocator.

## Notes / uncertainty
Fixed 0x36c-payload wrapper over snap_alloc_pkt_buf (block=0x380). Used by prepare/room-control builders FUN_001d6ee0/FUN_001d9b6c. Exact messages built not resolved.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d533c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
