# 0x001c3ea0 buf_write_be32

| field | value |
|---|---|
| Original address | 0x001c3ea0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3ea0 |
| Resolved name | buf_write_be32 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c4c80, FUN_001c51a0, FUN_001c5630, FUN_001c5900, FUN_001c5bd0, FUN_001c6060, FUN_001c64f0, FUN_001c6b90, FUN_001c6dc0, FUN_001c7580, FUN_001c8b60, FUN_001c94c0
**Callees:** FUN_001069a8
**Referenced globals:** conn+0x2c pkt-base; conn+0x38 write-cursor; conn+0x20 capacity
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x38 write-cursor

## Behavioral explanation
Appends a big-endian 32-bit value to the outgoing packet buffer (byteswap + 4-byte copy, bounds-checked against buf capacity at conn+0x20).

## Notes / uncertainty
Renamed put_u32_be -> buf_write_be32 for family symmetry; serialize big-endian u32 to tx with len+4<=cap check; exact write-mirror of buf_read_be32; silent truncation.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3ea0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
