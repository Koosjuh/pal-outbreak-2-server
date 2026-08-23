# 0x001c64f0 snap_send_op33_chunk_request_E

| field | value |
|---|---|
| Original address | 0x001c64f0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c64f0 |
| Resolved name | snap_send_op33_chunk_request_E |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001c3e10, FUN_001c3ea0, FUN_001ee590
**Referenced globals:** 0x365bb4 ids; 0x365c14 idx; 0x365c18 offset; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x33
**State vars:** conn+0xd next-state=0x42

## Behavioral explanation
Emits opcode 0x33 chunk-fetch: appends current slot-id (0x365bb4[idx]), offset (0x365c18), window 0x2d2; advances to state 0x42.

## Notes / uncertainty
Machine-E twin of 0x2f: emits 0x33 (id,offset,window 0x2d2 → state 0x42). Fully parallel to D; runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c64f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
