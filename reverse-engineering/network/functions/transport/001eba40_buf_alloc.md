# 0x001eba40 buf_alloc

| field | value |
|---|---|
| Original address | 0x001eba40 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eba40 |
| Resolved name | buf_alloc |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ebae0, FUN_001ed0bc
**Callees:** FUN_001e1e4c
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a buffer/packet node of size param_2, setting capacity(+8), type(+10), flags(+0xe)=0, len(+0xc)=0; returns OOM sentinel on failure.

## Notes / uncertainty
buf_node constructor: mem_alloc(size) then init +0x08 capacity/+0x0a kind/+0x0c len=0/+0x0e flags=0; OOM returns SNAP_ERR_OOM 0xffffe4a9. Whether alloc includes header bytes unresolved.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eba40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
