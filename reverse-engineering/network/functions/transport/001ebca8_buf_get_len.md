# 0x001ebca8 buf_get_len

| field | value |
|---|---|
| Original address | 0x001ebca8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebca8 |
| Resolved name | buf_get_len |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5ae4, FUN_001d6468, FUN_001e094c, FUN_001e0ed8, FUN_001e180c, FUN_001e19c4, FUN_001e40b0, FUN_001ed21c, FUN_001ed2c0, FUN_001ed360, FUN_001ed6ec, FUN_001ed7e0, FUN_001ed864, FUN_001ed924, FUN_001edad0, FUN_001edbb8, FUN_001edd9c, FUN_001ee060
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns the buffer's payload length (u16 at +0xc).

## Notes / uncertainty
Reads payload length +0xc; most-called buffer accessor in layer.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebca8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
