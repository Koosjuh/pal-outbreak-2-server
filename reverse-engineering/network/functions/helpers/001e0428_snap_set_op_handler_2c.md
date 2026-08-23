# 0x001e0428 snap_set_op_handler_2c

| field | value |
|---|---|
| Original address | 0x001e0428 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e0428 |
| Resolved name | snap_set_op_handler_2c |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Sends NO wire message; only queues local completion callback id 0x2c under the session/send-lock guard.

## Notes / uncertainty
Sibling of 0x1e0358 for transport room op 0x2c (between ENTER 0x2b and TRANSFER 0x2d; room semantics, maybe LEAVE/ready, unconfirmed). Same conn+0x548 handler-install + 0x50c lock gate.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e0428.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
