# 0x001dfad0 snap_send_op13

| field | value |
|---|---|
| Original address | 0x001dfad0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dfad0 |
| Resolved name | snap_send_op13 |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d5288, FUN_001e180c
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c
**Referenced strings:** —
**Referenced opcodes:** 0x13
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends a zero-length opcode-0x13 with who 0x2000 (unreliable, empty command); no completion cb.

## Notes / uncertainty
op0x13 twin of op12 (identical skeleton, who 0x2000). op12/op13 pairing semantics unconfirmed by trace.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dfad0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
