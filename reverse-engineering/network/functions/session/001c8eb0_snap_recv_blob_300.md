# 0x001c8eb0 snap_recv_blob_300

| field | value |
|---|---|
| Original address | 0x001c8eb0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c8eb0 |
| Resolved name | snap_recv_blob_300 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60, FUN_001c3b90
**Referenced globals:** 0x365df8=blob ptr; 0x35ccc8=scratch buffer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iVar3+0xc=topstate; iVar3+0xdc=error

## Behavioral explanation
Zeroes and reads up to a 0x300-byte blob into the 0x35ccc8 scratch buffer; returns -58 (0xffffffc6) when more data is pending, errors the conn on read failure.

## Notes / uncertainty
memset+reads one SN@P frame (<=0x300) into scratch 0x35ccc8, publishes ptr @0x365df8; on recv<0 faults conn (conn+0xdc=-1, conn+0xc=7 error-state, clears +0xd..+0x16, ret 0); success ret -58 (0xffffffc6)='continue'. FUN_001c3b90 framing per transport records.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c8eb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
