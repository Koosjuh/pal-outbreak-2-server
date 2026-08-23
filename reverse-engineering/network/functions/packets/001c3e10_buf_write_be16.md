# 0x001c3e10 buf_write_be16

| field | value |
|---|---|
| Original address | 0x001c3e10 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3e10 |
| Resolved name | buf_write_be16 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c3f40, FUN_001c4c80, FUN_001c51a0, FUN_001c5630, FUN_001c5bd0, FUN_001c6060, FUN_001c64f0, FUN_001c6b90, FUN_001c7000, FUN_001c7980, FUN_001c94c0
**Callees:** FUN_001069a8
**Referenced globals:** obj+0x2c tx-buf; obj+0x38 tx-len; obj+0x20 cap
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** obj+0x38 tx-len

## Behavioral explanation
Appends a big-endian u16 to the tx payload (obj+0x2c at obj+0x38) with capacity check, advancing length by 2.

## Notes / uncertainty
Serialize big-endian u16 to tx with len+2<=cap check; silent truncation; mirror of buf_write_u8.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3e10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
