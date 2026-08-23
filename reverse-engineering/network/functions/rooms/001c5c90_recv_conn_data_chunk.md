# 0x001c5c90 recv_conn_data_chunk

| field | value |
|---|---|
| Original address | 0x001c5c90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c5c90 |
| Resolved name | recv_conn_data_chunk |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_0010a338, FUN_001c3b10, FUN_001c3b90
**Referenced globals:** conn+0x28 name; conn+0x2c total; conn+0x34 seq; conn+0x35 buf-ptr; conn+0x3a end; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x2d
**State vars:** conn+0x34 seq; conn+0xd next-state

## Behavioral explanation
Per-connection data-chunk receiver: validates echoed name + seq (conn+0x34), computes window using who-byte 0x8000 (fsm-state 3) or 0x1000 else, copies body to conn+0x35 buffer, on completion branches next-state 0x21/0x31/0x19/0x3f by fsm-state.

## Notes / uncertainty
Chunk-loop for the op2d transfer: frame window 0x8000(op_mode3 reliable)/0x1000(DATA), seq/offset validated vs cursor+0xd0, per-mode terminal on completion. Offset arithmetic transcribed exact but not multi-chunk-traced.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c5c90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
