# 0x001c3b10 buf_read_be32

| field | value |
|---|---|
| Original address | 0x001c3b10 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3b10 |
| Resolved name | buf_read_be32 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c4360, FUN_001c45f0, FUN_001c4730, FUN_001c4960, FUN_001c4d40, FUN_001c5040, FUN_001c5260, FUN_001c5510, FUN_001c56f0, FUN_001c5a20, FUN_001c5c90, FUN_001c5f30, FUN_001c6130, FUN_001c63c0, FUN_001c65c0, FUN_001c6a50, FUN_001c6c60, FUN_001c6e80, FUN_001c7680, FUN_001c7a70, FUN_001c92d0, FUN_001c95e0
**Callees:** FUN_001069a8
**Referenced globals:** obj+0x34 rx-buf; obj+0x40 cursor
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** obj+0x40 cursor

## Behavioral explanation
Reads a big-endian u32 from the rx buffer at cursor obj+0x40 and advances 4.

## Notes / uncertainty
Deserialize big-endian u32 from rx cursor obj+0x40, advance 4, byteswap; unambiguous.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3b10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
