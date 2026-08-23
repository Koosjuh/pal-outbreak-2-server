# 0x001dda88 snap_send_op0b

| field | value |
|---|---|
| Original address | 0x001dda88 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dda88 |
| Resolved name | snap_send_op0b |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520
**Referenced strings:** —
**Referenced opcodes:** 0x0b
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends reliable (who 0xb000) opcode-0xb with a single htonl u32; completion cb 0x1b (no per-op seq counter, seq arg 0).

## Notes / uncertainty
op0b single htonl(u32), who 0xb000; cb 0x1b. Distinctive: passes literal seq 0 (no per-op counter) and returns 0 on success. App role inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dda88.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
