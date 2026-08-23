# 0x001e1468 alloc_queue_node_1c

| field | value |
|---|---|
| Original address | 0x001e1468 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e1468 |
| Resolved name | alloc_queue_node_1c |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d46ec
**Callees:** FUN_001e1e4c, FUN_001eb22c
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a 0x1c-byte control struct from the block pool, zeroes two words and inits an embedded list head (FUN_001eb22c).

## Notes / uncertainty
Pool-allocs 0x1c container, zeroes +0/+4, inits circular list head at +8 (FUN_001eb22c). NULL on pool exhaustion. Paired with drain_free_queue_off8. Head words +0/+4 meaning unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e1468.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
