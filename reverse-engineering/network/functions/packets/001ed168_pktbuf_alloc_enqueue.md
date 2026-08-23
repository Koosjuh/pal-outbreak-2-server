# 0x001ed168 pktbuf_alloc_enqueue

| field | value |
|---|---|
| Original address | 0x001ed168 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed168 |
| Resolved name | pktbuf_alloc_enqueue |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001eb3b8, FUN_001ed0bc
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates+inits a packet buffer (FUN_001ed0bc) then links it into a list/pool (FUN_001eb3b8), returning handle via *param_2.

## Notes / uncertainty
Alloc+init then doubly-linked tail-enqueue onto list param_1 (FUN_001eb3b8: node[0]=list, node[1]=old tail, list.tail=node, count@+0xc++). No caller recorded — which pool queue is unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed168.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
