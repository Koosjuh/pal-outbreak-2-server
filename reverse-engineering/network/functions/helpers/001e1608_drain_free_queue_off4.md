# 0x001e1608 drain_free_queue_off4

| field | value |
|---|---|
| Original address | 0x001e1608 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e1608 |
| Resolved name | drain_free_queue_off4 |
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
Drains every node from a list at struct+4 back to the conn block-pool then frees the container (variant of e14e8 for the +4 queue).

## Notes / uncertainty
Twin of 0x1e14e8 draining list at container+4; returns 0. Which of +4/+8 queues holds send vs reorder segments unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e1608.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
