# 0x001e0358 snap_set_op_handler_2b_enter

| field | value |
|---|---|
| Original address | 0x001e0358 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e0358 |
| Resolved name | snap_set_op_handler_2b_enter |
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
Sends NO wire message; only queues a local completion callback (FUN_001d4d24 id 0x2b) when the session is up and send-lock clear.

## Notes / uncertainty
CORRECTED: not a sender/cb-queue. Installs param_2 as handler for op 0x2b (ENTER) in conn op-handler table conn[+0x548+op*4] via FUN_001d4d24, gated by session + op-lock conn+0x50c. errno 0x66=busy, 0x64=no-session. Handler value type (fnptr vs id) uncertain.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e0358.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
