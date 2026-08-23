# 0x001db7e8 snap_session_open

| field | value |
|---|---|
| Original address | 0x001db7e8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001db7e8 |
| Resolved name | snap_session_open |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00102790, FUN_001069a8, FUN_00109eb8, FUN_0010a4f0, FUN_001d4d24, FUN_001d507c, FUN_001d5288, FUN_001d53cc, FUN_001e180c, FUN_001e2304, FUN_001e2928, FUN_001eabc0, FUN_001eac0c, FUN_001ead70, FUN_001eaddc, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x484/0x4ac(keys); conn+0x510/0x518; conn+0x80(state); conn+0x520(subpool)
**Referenced strings:** 0x4c43 'LC' TLV tag; 0x4d52 'MR' TLV tag
**Referenced opcodes:** 0x2c
**State vars:** 0x80(conn-state=1); 0x7c(timeout); DAT_0025b790(errno)

## Behavioral explanation
Builds and sends the SN@P session-open/connect request (opcode 0x2c, who 0x3000): copies key material to conn+0x484/0x4ac, encodes peer/port/name fields, appends LC/MR TLVs (FUN_001eac0c 0x4c43/0x4d52), sends, sets state 0x80=1 and arms timeout; registers completion cb 0x1c.

## Notes / uncertainty
op0x2c session-open request, who 0x3000: memset desc(0x128), fill endpoint/keys, LC(0x4c43)/MR(0x4d52) keepalive TLVs, send, state->1, cb 0x1c. Guard session_id==1 & g_conn!=0 else errno 0x64. Two 16-bit port fields (+0xa/+0x40) and 0x2382 seg-accept const uncertain.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001db7e8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
