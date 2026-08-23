# 0x001c5630 snap_send_op3f_chunk_request_C

| field | value |
|---|---|
| Original address | 0x001c5630 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c5630 |
| Resolved name | snap_send_op3f_chunk_request_C |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001c3e10, FUN_001c3ea0, FUN_001ee590
**Referenced globals:** 0x365ce4 idx; 0x365ce8 offset; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x3f
**State vars:** conn+0xd next-state=0x3e

## Behavioral explanation
Emits opcode 0x3f chunk-fetch: appends slot-idx (0x365ce4), offset (0x365ce8), window 0x2f2; advances to state 0x3e.

## Notes / uncertainty
Machine-C chunk req: slot(be16)+offset(be32)+0x2f2; substate->0x3e.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c5630.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
