# 0x001de840 snap_send_op0f_reliable

| field | value |
|---|---|
| Original address | 0x001de840 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001de840 |
| Resolved name | snap_send_op0f_reliable |
| Subsystem | chat |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520
**Referenced strings:** —
**Referenced opcodes:** 0x0f
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends opcode-0xf (who param_4|0xa400): copies a param_3-length blob; no completion cb.

## Notes / uncertainty
Reliable op0f blob sender; canonical alloc→reserve→copy→enqueue template. Sole caller build_send_chat_datagram (0x5c4bd0) confirms op0f = chat/DATA carrier. flags = who|0xa400. errno 100/0x65/0x66. Runtime-unvalidated; 0x0400 bit undecoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001de840.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
