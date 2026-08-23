# 0x001c3880 recv_framed_reassemble

| field | value |
|---|---|
| Original address | 0x001c3880 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3880 |
| Resolved name | recv_framed_reassemble |
| Subsystem | packets |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001ee430, FUN_001ee560
**Referenced globals:** 0x35a714 hdr-scratch; 0x35a71a avail-bytes
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** obj+0x3c in-frame; obj+0x42 frame-len; obj+0x3e recvd

## Behavioral explanation
Reads a length-prefixed frame from the socket (FUN_001ee430/ee560): parses big-endian length at obj+0x42, streams body into obj+0x34 tracking obj+0x3e progress, handles multi-chunk reassembly and returns 1 on complete frame.

## Notes / uncertainty
Main-ee inbound frame reassembler (object state), driven by snap_app_sm_pump: poll type==4, 8-byte header, BE u16 len@obj+0x42, body into obj+0x34 (cap obj+0x24), chunk rollover via obj+0x44; 1/>1/0/-1. Object twin of recv_framed_chunk. Header bytes beyond len parsed downstream.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3880.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
