# 0x001e1590 alloc_queue_node_18

| field | value |
|---|---|
| Original address | 0x001e1590 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e1590 |
| Resolved name | alloc_queue_node_18 |
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
Allocates a 0x18-byte control struct from the block pool, zeroes head word and inits embedded list head.

## Notes / uncertainty
Twin of 0x1e1468: 0x18 container, one head word +0, list head at +4. Paired with drain_free_queue_off4.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e1590.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
