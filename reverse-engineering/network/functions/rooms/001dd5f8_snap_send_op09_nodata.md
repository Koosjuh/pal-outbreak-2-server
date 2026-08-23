# 0x001dd5f8 snap_send_op09_nodata

| field | value |
|---|---|
| Original address | 0x001dd5f8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dd5f8 |
| Resolved name | snap_send_op09_nodata |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520; conn+0x61d(seq)
**Referenced strings:** —
**Referenced opcodes:** 0x09
**State vars:** 0x50c(send-lock); 0x61d(seq); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends opcode-9 (len 8, who 0xa000): two htonl u32; completion cb 0x16, seq conn+0x61d.

## Notes / uncertainty
op09 register, 8-byte body two htonl(u32), who 0xa000; cb 0x16, seq 0x61d. _unrel misnomer corrected (still reliable). 2-u32 layout looks like slot/status update; field roles unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dd5f8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
