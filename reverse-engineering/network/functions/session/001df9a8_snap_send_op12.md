# 0x001df9a8 snap_send_op12

| field | value |
|---|---|
| Original address | 0x001df9a8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001df9a8 |
| Resolved name | snap_send_op12 |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d5288, FUN_001e180c
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c
**Referenced strings:** —
**Referenced opcodes:** 0x12
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends a zero-length opcode-0x12 with who 0x2000 (unreliable, empty command); no completion cb.

## Notes / uncertainty
op0x12 bare zero-len signal, who 0x2000, no cb/seq. Paired with op0x13; app role (ready/leave) and delivery class of who 0x2000 unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001df9a8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
