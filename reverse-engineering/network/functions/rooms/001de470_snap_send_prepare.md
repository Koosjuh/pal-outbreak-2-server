# 0x001de470 snap_send_prepare

| field | value |
|---|---|
| Original address | 0x001de470 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001de470 |
| Resolved name | snap_send_prepare |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520; conn+0x64(payload len); conn+0x61f(seq)
**Referenced strings:** —
**Referenced opcodes:** 0x0c
**State vars:** 0x50c(send-lock); 0x61f(seq); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends opcode-0xc PREPARE (who 0xa000): copies a *(conn+0x64)-length session blob from param_2; completion cb 0x26, seq conn+0x61f.

## Notes / uncertainty
op0c PREPARE (create/enter commit), who 0xa000; variable-length blob memcpy'd verbatim (no swap), length from cached conn+0x64 (u32 for alloc, u16 for reserve/bodyLen); cb 0x26, seq 0x61f. Blob layout defined by caller SM 0x5c3490, not here.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001de470.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
