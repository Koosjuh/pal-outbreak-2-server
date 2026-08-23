# 0x001ebae0 buf_alloc_push_tail

| field | value |
|---|---|
| Original address | 0x001ebae0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebae0 |
| Resolved name | buf_alloc_push_tail |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ebed0
**Callees:** FUN_001eb3b8, FUN_001eba40
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a buffer node (buf_alloc) and inserts it at the tail of the given list.

## Notes / uncertainty
buf_alloc then list_insert_tail on success; used by subpool init (FUN_001ebed0) to preallocate pool buffers.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebae0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
