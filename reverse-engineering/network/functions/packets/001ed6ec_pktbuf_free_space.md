# 0x001ed6ec pktbuf_free_space

| field | value |
|---|---|
| Original address | 0x001ed6ec |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed6ec |
| Resolved name | pktbuf_free_space |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d72a8
**Callees:** FUN_001ebca8, FUN_001ebd04
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf used-length; buf capacity

## Behavioral explanation
Returns remaining payload bytes = (capacity - used-length) - 0x2c.

## Notes / uncertainty
capacity(+0x08) - used_len(+0x0c) - 0x2c. No zero-clamp; negative on over-full unverified.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed6ec.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
