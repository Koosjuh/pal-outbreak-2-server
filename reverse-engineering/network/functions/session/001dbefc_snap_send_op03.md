# 0x001dbefc snap_send_op03

| field | value |
|---|---|
| Original address | 0x001dbefc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dbefc |
| Resolved name | snap_send_op03 |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109eb8, FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c(send-lock); conn+0x520(subpool); conn+0x614(seq)
**Referenced strings:** —
**Referenced opcodes:** 0x03
**State vars:** 0x50c(send-lock); 0x614(seq); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends a reliable (who 0xb000) opcode-3 message carrying a 16-byte blob (param_2 copied via FUN_00109eb8); completion cb 0x1d, seq counter conn+0x614.

## Notes / uncertainty
op0x03 with 16-byte body, who 0xb000, seq byte conn+0x614 (post-inc, returned), cb 0x1d. App meaning of the 16-byte payload (GUID/token?) unpinned.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dbefc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
