# 0x001c8d30 snap_flush_pending_stage30

| field | value |
|---|---|
| Original address | 0x001c8d30 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c8d30 |
| Resolved name | snap_flush_pending_stage30 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001ee590
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iVar2+0xd=substate

## Behavioral explanation
Byte-swaps the packet length header, computes checksum (FUN_001ee590) and transmits an already-built packet, advancing substate to 0x30.

## Notes / uncertainty
Send tail identical to op0e flush minus builder open/seal; sends a pre-composed packet (by caller FUN_001c9b00) and on success sets ctx+0x0d stage=0x30. Meaning of stage 0x30 in caller SM not traced.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c8d30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
