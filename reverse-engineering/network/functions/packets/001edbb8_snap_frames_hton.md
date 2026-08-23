# 0x001edbb8 snap_frames_hton

| field | value |
|---|---|
| Original address | 0x001edbb8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001edbb8 |
| Resolved name | snap_frames_hton |
| Subsystem | packets |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6468
**Callees:** FUN_001069a8, FUN_001e2304, FUN_001e234c, FUN_001ebca8, FUN_001ed6bc, FUN_001eda10, FUN_001ee060
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Walks every 0x10-byte sub-frame in the payload and byte-swaps its header fields host->net (FUN_001e234c=htons x2, FUN_001e2304=htonl x3), advancing by len&0x3ff; the outgoing serialize pass.

## Notes / uncertainty
Outbound serialize: walks 0x10-byte frame headers (u16,u16,u32x3), htons/htonl in place, ring-wrap via stack scratch. Length taken from PRE-swap word0; no bounds check (unlike ntoh). Ring helpers inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001edbb8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
