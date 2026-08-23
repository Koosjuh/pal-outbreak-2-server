# 0x001d9678 snap_connect_reply_handler

| field | value |
|---|---|
| Original address | 0x001d9678 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d9678 |
| Resolved name | snap_connect_reply_handler |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78
**Callees:** FUN_001069a8, FUN_00109728, FUN_00109d70, FUN_0010a050, FUN_001d507c, FUN_001e2928, FUN_001e5538
**Referenced globals:** conn+0x484(crypto key); conn+0x4ac(crypto key); conn+0x500..0x51c(peer session); conn+0x80(state); conn+0x5b8(cb); 0x2592b0(ip fmt str)
**Referenced strings:** 0x2592b0 (IP printf format)
**Referenced opcodes:** 0x2a
**State vars:** 0x80(conn-state 1->2); 0x7c; 0x51c(timeout)

## Behavioral explanation
Handles the connect/open reply while state==1: decrypts+validates the datagram (FUN_001e5538/FUN_00109d70), records peer session fields (0x500/0x504/0x508/0xa8), formats peer IP string, advances state 1->2 and arms timeout 0x51c; on validation fail delivers status 0x13 and resets.

## Notes / uncertainty
op0x2a connect reply while state==1: decrypt (conn+0x484)+verify tag (conn+0x4ac), latch peer session block 0x500-0x51c incl interned IP string, state 1->2, arm keepalive; auth-fail raises 0x27 event (code 0x13) + reset. FUN_00109d70 tag algo unread; +0x508 caps label inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d9678.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
