# 0x001de9e8 snap_send_op10_multi

| field | value |
|---|---|
| Original address | 0x001de9e8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001de9e8 |
| Resolved name | snap_send_op10_multi |
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
Builds/sends opcode-0x10 (who param_4|0xa400): prefixes a count (param_5) then param_5 htonl u32 recipient ids (from varargs) followed by a param_3-length blob; no completion cb.

## Notes / uncertainty
Reliable op10 targeted multicast, varargs recipient ids (8B stride); who|0xa400; htonl [count][ids][blob]. No caller yet; helper names inferred; who low-bit 0x0400 semantics unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001de9e8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
