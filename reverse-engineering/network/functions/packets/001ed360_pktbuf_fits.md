# 0x001ed360 pktbuf_fits

| field | value |
|---|---|
| Original address | 0x001ed360 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed360 |
| Resolved name | pktbuf_fits |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5ae4, FUN_001ed2c0, FUN_001ed74c, FUN_001ed864
**Callees:** FUN_001ebca8, FUN_001ebd04
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf used-length; buf capacity

## Behavioral explanation
Bounds check: used-length + param_2 <= capacity-0x2c (does param_2 more payload bytes fit).

## Notes / uncertainty
Bounds predicate used_len+(n&0xffff) <= capacity-0x2c. Pure read of +0x08/+0x0c. Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed360.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
