# 0x001edd9c snap_frames_ntoh

| field | value |
|---|---|
| Original address | 0x001edd9c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001edd9c |
| Resolved name | snap_frames_ntoh |
| Subsystem | packets |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d72a8
**Callees:** FUN_001069a8, FUN_001e2394, FUN_001e23dc, FUN_001ebca8, FUN_001ed6bc, FUN_001eda10, FUN_001ee060
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Incoming parse: walks sub-frames byte-swapping net->host (FUN_001e23dc=ntohs x2, FUN_001e2394=ntohl x3), validating each 10-bit length is >=0x10 and within remaining bytes; returns error codes 0xffffe0c3/c5 on malformed frames.

## Notes / uncertainty
Inbound deserialize+validate gate; ntohs/ntohl then len bounds (0x10<=len<=remaining). Errors 0xffffe0c3 truncate/overrun, 0xffffe0c5 bad length. Confirms 0x10 header layout matching dispatch.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001edd9c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
