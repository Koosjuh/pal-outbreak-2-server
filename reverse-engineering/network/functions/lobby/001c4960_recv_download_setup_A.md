# 0x001c4960 recv_download_setup_A

| field | value |
|---|---|
| Original address | 0x001c4960 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c4960 |
| Resolved name | recv_download_setup_A |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_00106b60, FUN_0010a338, FUN_001c2f30, FUN_001c3a60, FUN_001c3ab0, FUN_001c3b10, FUN_001c3b90
**Referenced globals:** 0x36842c/0x36844c name-bufs; 0x36842a chunk-count; 0x36846c size-table; 0x368474 ptr-table; 0x368421/0x368424 seq; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x12
**State vars:** 0x368421 chunk-idx; 0x368424 offset; conn+0xd=0x12

## Behavioral explanation
Reply-0x12 handler: validates echoed name (memcmp vs 0x36842c), reads a chunk-count (clamped to 2) and per-chunk sizes into the 0x36846c pool table, resets seq (0x368421/0x368424), advances to state 0x12 (chunk-fetch).

## Notes / uncertainty
op12 setup reply: u8 status(1=body/2=skip/else err), name echo memcmp, be16 count<=2, be32 sizes<=0x2000, substate->0x12/0x14. 0x368470/74/78 ptr-table roll (2-arg memcpy) inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c4960.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
