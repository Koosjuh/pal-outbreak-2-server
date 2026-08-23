# 0x001dfda0 snap_send_op14_seq

| field | value |
|---|---|
| Original address | 0x001dfda0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dfda0 |
| Resolved name | snap_send_op14_seq |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520; conn+0x621(seq)
**Referenced strings:** —
**Referenced opcodes:** 0x14
**State vars:** 0x50c(send-lock); 0x621(seq); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends opcode-0x14 with who param_2|0x2000: copies a param_4-length blob; completion cb 0x28, seq conn+0x621.

## Notes / uncertainty
Renamed from snap_send_op14. Unreliable op14 carrying send-seq conn+0x621 (post-incremented, returned); registers op28 completion (tag 0x28) -> the SUB-echo ack pattern. op14 payload semantics (chat vs data) unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dfda0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
