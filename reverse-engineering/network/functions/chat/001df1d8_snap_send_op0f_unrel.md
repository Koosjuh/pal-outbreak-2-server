# 0x001df1d8 snap_send_op0f_unrel

| field | value |
|---|---|
| Original address | 0x001df1d8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001df1d8 |
| Resolved name | snap_send_op0f_unrel |
| Subsystem | chat |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001caa30, FUN_001caad0
**Callees:** FUN_001069a8, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520
**Referenced strings:** —
**Referenced opcodes:** 0x0f
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends opcode-0xf with who param_2|0x2000 (unreliable): copies a param_4-length blob; no completion cb.

## Notes / uncertainty
Unreliable sibling of op0f; flags = who|0x2000. Callers FUN_001caa30/001caad0 (DNAS/announce region). Template clear; per-caller who bits not decoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001df1d8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
