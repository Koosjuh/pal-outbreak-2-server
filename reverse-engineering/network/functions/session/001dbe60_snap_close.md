# 0x001dbe60 snap_close

| field | value |
|---|---|
| Original address | 0x001dbe60 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dbe60 |
| Resolved name | snap_close |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001dbd0c
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno)
**Referenced strings:** —
**Referenced opcodes:** 0x02
**State vars:** DAT_0025b790(errno)

## Behavioral explanation
Public session-close wrapper: validates param_1==1/conn!=0 then delegates to snap_send_close(conn).

## Notes / uncertainty
Public close: guard then FUN_001dbd0c(conn) (emits opcode 0x02 teardown), else errno=100/-1. 64-bit return contract of impl + close variant not traced.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dbe60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
