# 0x001ded08 snap_send_op10_multi_ptr

| field | value |
|---|---|
| Original address | 0x001ded08 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ded08 |
| Resolved name | snap_send_op10_multi_ptr |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520
**Referenced strings:** —
**Referenced opcodes:** 0x10
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends opcode-0x10 (who param_4|0xa400) identical to FUN_001de9e8 but recipient ids come from an array descriptor param_5 (count + ptr) instead of varargs; no completion cb.

## Notes / uncertainty
Pointer-array twin of de9e8 (ids from {count,u32*} descriptor, 4B stride). No caller; helpers inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ded08.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
