# 0x001c6b90 snap_send_op47_chunk_request

| field | value |
|---|---|
| Original address | 0x001c6b90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c6b90 |
| Resolved name | snap_send_op47_chunk_request |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001c3da0, FUN_001c3e10, FUN_001c3ea0, FUN_001ee590
**Referenced globals:** conn+0x48 offset; 0x35b7d0 total; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x47
**State vars:** conn+0xd next-state=0x28

## Behavioral explanation
Emits opcode 0x47 chunk-fetch: byte(1), current offset (conn+0x48), remaining-len (0x35b7d0 - offset); advances to state 0x28.

## Notes / uncertainty
Machine-F chunk request: 0x47 + sub-sel 1, offset conn+0x48, window = remaining (total-offset) → state 0x28. No slot-id (single buffer). runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c6b90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
