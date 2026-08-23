# 0x001df380 snap_send_op10_multi_unrel

| field | value |
|---|---|
| Original address | 0x001df380 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001df380 |
| Resolved name | snap_send_op10_multi_unrel |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_001d5288, FUN_001e180c, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520
**Referenced strings:** —
**Referenced opcodes:** 0x10
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends opcode-0x10 with who param_2|0x2000 (unreliable): count + param_5 htonl u32 ids (varargs) + param_4 blob; no completion cb.

## Notes / uncertainty
Unreliable (who|0x2000) varargs op10 multicast; NOTE reserve return not null-checked in this build (possible decompiler artifact).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001df380.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
