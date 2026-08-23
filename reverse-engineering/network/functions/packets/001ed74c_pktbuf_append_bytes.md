# 0x001ed74c pktbuf_append_bytes

| field | value |
|---|---|
| Original address | 0x001ed74c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed74c |
| Resolved name | pktbuf_append_bytes |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6468, FUN_001d6988, FUN_001d6ee0, FUN_001e3a3c, FUN_001eda5c
**Callees:** FUN_001069a8, FUN_001ed21c, FUN_001ed2c0, FUN_001ed360
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf used-length

## Behavioral explanation
If param_3 bytes fit, memcpy's them from param_2 to buffer tail and advances length; else returns 0xffffe0c2 (no-space).

## Notes / uncertainty
Core append: can_fit else 0xffffe0c2 no-space; memcpy tail + advance used_len. len truncated to u16. advance_len re-runs redundant fit-check.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed74c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
