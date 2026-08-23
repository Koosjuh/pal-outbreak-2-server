# 0x001de0c0 snap_send_op0a_memberlist_req_alt

| field | value |
|---|---|
| Original address | 0x001de0c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001de0c0 |
| Resolved name | snap_send_op0a_memberlist_req_alt |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520
**Referenced strings:** —
**Referenced opcodes:** 0x0a
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends opcode-0xa with who 0xa000 (DATA-less member-list request), single htonl u32; completion cb 0x18, seq arg 0.

## Notes / uncertainty
Identical to 0x001ddee8 except who 0xa000 (DATA bit clear) and cb 0x18. Prior name 'unrel' is inaccurate — both carry the 0x8000 reliable bit; difference is who-byte DATA 0x1000. Which context uses which variant unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001de0c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
