# 0x001e04f8 snap_set_op_handler_2d_transfer

| field | value |
|---|---|
| Original address | 0x001e04f8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e04f8 |
| Resolved name | snap_set_op_handler_2d_transfer |
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
Sends NO wire message; only queues local completion callback id 0x2d under the session/send-lock guard.

## Notes / uncertainty
Sibling installing handler for op 0x2d (TRANSFER/host-migration) in conn+0x548 table, same gate/errno. TRANSFER exact meaning (host-migration vs slot-transfer) unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e04f8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
