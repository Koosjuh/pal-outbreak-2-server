# 0x001d6468 snap_flush_send

| field | value |
|---|---|
| Original address | 0x001d6468 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d6468 |
| Resolved name | snap_flush_send |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d72a8
**Callees:** FUN_001069a8, FUN_001d5688, FUN_001d5ae4, FUN_001d63b8, FUN_001e2304, FUN_001e34dc, FUN_001eb2d4, FUN_001eb3b8, FUN_001eb434, FUN_001ebb90, FUN_001ebbd0, FUN_001ebca8, FUN_001ec9e0, FUN_001ed474, FUN_001ed4cc, FUN_001ed60c, FUN_001ed68c, FUN_001ed6bc, FUN_001ed74c, FUN_001edad0, FUN_001edbb8
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x16 tx-seq allocator; conn+0x143 send err; conn+0x144 win base

## Behavioral explanation
Send-path flush: coalesces (001d5ae4), attaches ack header (001d63b8), assigns outbound seq numbers from conn+0x16, appends the 0xba476611 trailer/checksum, encrypts, and transmits each datagram; failure sets conn+0x143.

## Notes / uncertainty
Send flush: coalesce, pop one node, assign reliable seq from conn+0x58 pool allocator, set send-time/RTO, append 0xba476611 trailer + seal 0x2000, sendto conn+0x48. Full write -> reliable to in-flight conn+0x58 else free conn+0x520. Errors 0x1f5 coalesce / 500 short-write. Word->byte index map proven via sendto args. FUN_001d5688 (ack-seq stamp) inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d6468.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
