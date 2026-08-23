# 0x001de298 snap_send_op43

| field | value |
|---|---|
| Original address | 0x001de298 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001de298 |
| Resolved name | snap_send_op43 |
| Subsystem | menus |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520
**Referenced strings:** —
**Referenced opcodes:** 0x43
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends opcode-0x43 (who 0xa000) with a single htonl u32; completion cb 0x2e, seq arg 0.

## Notes / uncertainty
Already fully reconstructed (corrected C block present, control flow fully resolved). op-0x43 domain meaning still unconfirmed on wire; only mode==1 accepted.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001de298.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
