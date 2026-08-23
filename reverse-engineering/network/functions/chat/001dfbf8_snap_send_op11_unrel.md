# 0x001dfbf8 snap_send_op11_unrel

| field | value |
|---|---|
| Original address | 0x001dfbf8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dfbf8 |
| Resolved name | snap_send_op11_unrel |
| Subsystem | chat |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520
**Referenced strings:** —
**Referenced opcodes:** 0x11
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends opcode-0x11 with who param_2|0x2000 (unreliable): copies a param_4-length blob; no completion cb.

## Notes / uncertainty
Unreliable op11, flags = who|0x2000. Same template as op0f-unrel. No caller; inbound 0x11→conn+0x5e8. Payload meaning inferred from opcode/dispatch only.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dfbf8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
