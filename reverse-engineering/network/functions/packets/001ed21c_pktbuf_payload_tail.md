# 0x001ed21c pktbuf_payload_tail

| field | value |
|---|---|
| Original address | 0x001ed21c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed21c |
| Resolved name | pktbuf_payload_tail |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6988, FUN_001ed270, FUN_001ed2c0, FUN_001ed74c, FUN_001ed864
**Callees:** FUN_001ebca8
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf used-length

## Behavioral explanation
Returns write cursor = buf+0x2c + used-length (FUN_001ebca8): pointer to end of current payload.

## Notes / uncertainty
Append cursor = node+0x2c+used_length(u16@+0xc). Pure read+arith. used-length assumed payload-only (inferred from +0x2c base).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed21c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
