# 0x001c3c90 build_packet_header

| field | value |
|---|---|
| Original address | 0x001c3c90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3c90 |
| Resolved name | build_packet_header |
| Subsystem | packets |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c4070, FUN_001c4100, FUN_001c42d0, FUN_001c43c0, FUN_001c4560, FUN_001c46a0, FUN_001c48c0, FUN_001c4c80, FUN_001c4fb0, FUN_001c51a0, FUN_001c5480, FUN_001c5630, FUN_001c5900, FUN_001c5bd0, FUN_001c5ea0, FUN_001c6060, FUN_001c6330, FUN_001c64f0, FUN_001c67b0, FUN_001c69b0, FUN_001c6b90, FUN_001c6dc0, FUN_001c7000, FUN_001c7580, FUN_001c7980, FUN_001c85c0, FUN_001c8b60, FUN_001c8dd0, FUN_001c8f50, FUN_001c94c0
**Callees:** FUN_00106b60
**Referenced globals:** 0x2484c0/0x248510 len-tables; obj+0x28 tx-hdr; obj+0x3d tx-seq
**Referenced strings:** —
**Referenced opcodes:** 0x01, 0x02, 0x10
**State vars:** —

## Behavioral explanation
Builds the 8-byte tx header at obj+0x28: type byte param_3 (0x01/0x02/0x10), length-derived bytes from DAT_002484c0/510 tables, and an auto-incrementing sequence (obj+0x3d) for reliable types; resets payload length obj+0x38.

## Notes / uncertainty
8-byte tx header @obj+0x28: type[2], length bytes[3/4] from DAT_002484c0/510 tables (or template copy if param_2==0), seq[5]=obj+0x3d++ for reliable 0x01/0x10 or template echo for 0x02 (else unsequenced), attr[6], 0xff[7]; resets payload len obj+0x38; returns pkt base obj+0x2c. Table encoding + hdr[0/1] fill undecoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3c90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
