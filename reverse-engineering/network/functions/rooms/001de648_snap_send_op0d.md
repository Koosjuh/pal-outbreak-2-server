# 0x001de648 snap_send_op0d

| field | value |
|---|---|
| Original address | 0x001de648 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001de648 |
| Resolved name | snap_send_op0d |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520; conn+0x620(seq)
**Referenced strings:** —
**Referenced opcodes:** 0x0d
**State vars:** 0x50c(send-lock); 0x620(seq); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends opcode-0xd (who 0xa000) with a single htonl u32; completion cb 0x27, seq conn+0x620.

## Notes / uncertainty
op0d single htonl(u32), who 0xa000; cb 0x27, seq 0x620. Plausibly a room/ready/state toggle; app role inferred, no caller/trace.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001de648.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
