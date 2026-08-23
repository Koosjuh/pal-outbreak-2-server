# 0x001e094c snap_send_op48_name_query

| field | value |
|---|---|
| Original address | 0x001e094c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e094c |
| Resolved name | snap_send_op48_name_query |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_00106b60, FUN_0010a4f0, FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001e2304, FUN_001ebca8, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520
**Referenced strings:** —
**Referenced opcodes:** 0x48
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends reliable (who 0xb000) opcode-0x48 name/roster query: a request-id word then up to 32 entries, each with an htonl id, a 1-byte kind, and a kind-dependent body (type1=two u32, type2=16-byte addr, else one u32); computes length via FUN_001ebca8; completion cb 0x31.

## Notes / uncertainty
The op48 name-loop builder: 8-byte header (htonl reqid + count), up to 32 entries kind=flags>>5: kind1=two u32(len0xd), kind2=16-byte addr(len0x15), default=one u32(len9). who 0xb000, cb 0x31, msg cap 0x2a8. Entry app-semantics (pair/addr/id) inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e094c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
