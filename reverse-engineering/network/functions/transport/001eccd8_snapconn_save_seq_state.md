# 0x001eccd8 snapconn_save_seq_state

| field | value |
|---|---|
| Original address | 0x001eccd8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eccd8 |
| Resolved name | snapconn_save_seq_state |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d4e7c
**Callees:** FUN_001069a8
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x3c seq/window state block (0x34 bytes)

## Behavioral explanation
memcpy's the 0x34-byte seq/ack-window state block at conn+0x3c out to caller buffer (snapshot of reorder-gate state).

## Notes / uncertainty
memcpy-out of 0x34-byte seq-window block conn+0x3c; memcpy arg order (dst,src,n) assumed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eccd8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
