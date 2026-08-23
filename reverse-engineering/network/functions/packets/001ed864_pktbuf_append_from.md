# 0x001ed864 pktbuf_append_from

| field | value |
|---|---|
| Original address | 0x001ed864 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed864 |
| Resolved name | pktbuf_append_from |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5ae4
**Callees:** FUN_001069a8, FUN_001ebca8, FUN_001ed21c, FUN_001ed2c0, FUN_001ed360, FUN_001ed6bc
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf used-length

## Behavioral explanation
Appends the entire payload of source buffer param_2 into dest param_1 (checks fit +4 header slack, memcpy, advance).

## Notes / uncertainty
Coalesce: appends src whole payload into dst; fit-check reserves +4 slack that the copy does not use (purpose inferred).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed864.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
