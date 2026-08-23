# 0x001c3a60 buf_read_u8

| field | value |
|---|---|
| Original address | 0x001c3a60 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3a60 |
| Resolved name | buf_read_u8 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c4960, FUN_001c5a20, FUN_001c6a50, FUN_001c6c60, FUN_001c6e80, FUN_001c70b0, FUN_001c7680, FUN_001c7a70, FUN_001c8790, FUN_001c9030, FUN_001c92d0
**Callees:** FUN_001069a8
**Referenced globals:** obj+0x34 rx-buf; obj+0x40 cursor
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** obj+0x40 cursor

## Behavioral explanation
Reads one byte from the rx buffer (obj+0x34 at cursor obj+0x40) and advances the cursor by 1.

## Notes / uncertainty
Deserialize u8 from msgbuf rx (obj+0x34) at cursor obj+0x40, advance 1; no bounds check; full msgbuf_t map vs snap_connection unestablished.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3a60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
