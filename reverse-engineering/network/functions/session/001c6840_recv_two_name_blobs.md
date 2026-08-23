# 0x001c6840 recv_two_name_blobs

| field | value |
|---|---|
| Original address | 0x001c6840 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c6840 |
| Resolved name | recv_two_name_blobs |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_0010a4f0, FUN_001c3ab0, FUN_001c3b90
**Referenced globals:** 0x35b9e8 count; 0x35b8e0 blob1; 0x35bee0 blob2; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0xd next-state=0x25

## Behavioral explanation
Reply parser (state 0/7): reads an optional u16 into 0x35b9e8 then up to two 0x100-byte blobs into 0x35b8e0 and 0x35bee0; advances to state 0x25.

## Notes / uncertainty
Rewrote: optional u16 id (0x35b9e8) + two 256-byte checksum-validated blobs (FUN_001c3b90) into 0x35b8e0/0x35bee0 at fsm-state 0/7, ->state 0x25; parse/checksum error->conn_reset(code -1), empty->reset(9). Blob content (banner vs name pair) unresolved.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c6840.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
