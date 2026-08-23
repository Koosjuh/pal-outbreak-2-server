# 0x001dd840 snap_send_op09

| field | value |
|---|---|
| Original address | 0x001dd840 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dd840 |
| Resolved name | snap_send_op09 |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520; conn+0x61e(seq)
**Referenced strings:** —
**Referenced opcodes:** 0x09
**State vars:** 0x50c(send-lock); 0x61e(seq); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends reliable (who 0xb000) opcode-9 (len 8): two htonl u32; completion cb 0x17, seq conn+0x61e.

## Notes / uncertainty
op09 register, 8-byte two htonl(u32), who 0xb000 (DATA twin of dd5f8); cb 0x17, seq 0x61e. Field roles unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dd840.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
