# 0x001dc804 snap_send_op05

| field | value |
|---|---|
| Original address | 0x001dc804 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dc804 |
| Resolved name | snap_send_op05 |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520; conn+0x617(seq)
**Referenced strings:** —
**Referenced opcodes:** 0x05
**State vars:** 0x50c(send-lock); 0x617(seq); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends opcode-5 with a single htonl u32, who 0xa000 (reliable set, no DATA bit); completion cb 0x20, seq conn+0x617.

## Notes / uncertainty
op05 single htonl(u32), who 0xa000 (reliable, no DATA bit); cb 0x20, seq 0x617. 0xa000 twin of dc310. op05 app meaning unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dc804.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
