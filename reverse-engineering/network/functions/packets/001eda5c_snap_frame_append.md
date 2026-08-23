# 0x001eda5c snap_frame_append

| field | value |
|---|---|
| Original address | 0x001eda5c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eda5c |
| Resolved name | snap_frame_append |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_001ed74c
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads a 0x10-byte sub-frame header, extracts 10-bit length (hdr[0] & 0x3ff), and appends that many bytes via pktbuf_append_bytes.

## Notes / uncertainty
Appends one SN@P sub-frame; length = hdr[0]&0x3ff (10-bit, header-inclusive). No intra-corpus caller; header-inclusive vs body-only inferred from copy starting at header ptr.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eda5c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
