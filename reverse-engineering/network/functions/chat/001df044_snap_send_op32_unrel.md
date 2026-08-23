# 0x001df044 snap_send_op32_unrel

| field | value |
|---|---|
| Original address | 0x001df044 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001df044 |
| Resolved name | snap_send_op32_unrel |
| Subsystem | chat |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520
**Referenced strings:** —
**Referenced opcodes:** 0x32
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends opcode-0x32 with who 0x2000 (set, unreliable, no DATA/reliable bits): copies a param_3-length blob; no completion cb.

## Notes / uncertainty
Unreliable op32 sender, fixed flags 0x2000 (no 0x8000). Control flow High but NO caller found and payload semantics inferred from dispatch slot conn+0x5fc — likely gameplay data channel, not chat.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001df044.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
