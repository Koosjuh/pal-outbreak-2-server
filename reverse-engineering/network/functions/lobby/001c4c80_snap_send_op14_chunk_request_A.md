# 0x001c4c80 snap_send_op14_chunk_request_A

| field | value |
|---|---|
| Original address | 0x001c4c80 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c4c80 |
| Resolved name | snap_send_op14_chunk_request_A |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001c3e10, FUN_001c3ea0, FUN_001ee590
**Referenced globals:** 0x368421 idx; 0x368424 offset; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x14
**State vars:** conn+0xd next-state=0x13

## Behavioral explanation
Emits opcode 0x14 chunk-fetch: appends chunk-idx (0x368421), byte-offset (0x368424), and window size 0x2f2; advances to state 0x13.

## Notes / uncertainty
Machine-A chunk req: idx(be16)+offset(be32)+window 0x2f2; substate->0x13.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c4c80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
