# 0x001c3da0 buf_write_u8

| field | value |
|---|---|
| Original address | 0x001c3da0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3da0 |
| Resolved name | buf_write_u8 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c4100, FUN_001c69b0, FUN_001c6b90, FUN_001c85c0, FUN_001c8b60, FUN_001c8f50
**Callees:** FUN_001069a8
**Referenced globals:** obj+0x2c tx-buf; obj+0x38 tx-len; obj+0x20 cap
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** obj+0x38 tx-len

## Behavioral explanation
Appends one byte to the tx payload (obj+0x2c at length obj+0x38) with a capacity check (obj+0x20), advancing the length.

## Notes / uncertainty
Serialize u8 to tx (obj+0x2c) at len obj+0x38 if len+1<=cap(obj+0x20), advance; silent truncation on overflow; returns pre-append pos ptr.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3da0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
