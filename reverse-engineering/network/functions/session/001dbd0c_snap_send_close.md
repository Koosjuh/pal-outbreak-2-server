# 0x001dbd0c snap_send_close

| field | value |
|---|---|
| Original address | 0x001dbd0c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dbd0c |
| Resolved name | snap_send_close |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78, FUN_001dbe60
**Callees:** FUN_001d5288, FUN_001e180c
**Referenced globals:** 0x0025b790(errno); conn+0x50c(send-lock)
**Referenced strings:** —
**Referenced opcodes:** 0x02
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Sends a zero-length reliable opcode-2 message (session close/bye) when conn+0x50c lock is clear; sets errno 0x65/0x66 on alloc/send fail.

## Notes / uncertainty
op0x02 zero-len graceful close, who 0xb000, gated on conn+0x50c send-lock clear; errno 0x65 alloc/0x66 busy-or-send. Node not freed on lock-busy path (pool reuse).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dbd0c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
