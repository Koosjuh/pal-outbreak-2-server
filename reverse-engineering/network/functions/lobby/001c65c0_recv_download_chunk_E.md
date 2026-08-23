# 0x001c65c0 recv_download_chunk_E

| field | value |
|---|---|
| Original address | 0x001c65c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c65c0 |
| Resolved name | recv_download_chunk_E |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3ab0, FUN_001c3b10, FUN_001c3b90
**Referenced globals:** 0x365bb4 ids; 0x365bd4 sizes; 0x365c14 idx; 0x365c18 offset; 0x365bb0 count; 0x35ccb8 ring; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x33
**State vars:** 0x365c14/0x365c18; conn+0xd

## Behavioral explanation
Reply-0x33 handler: matches slot-id (0x365bb4), reads offset+len, copies body into ring 0x35ccb8+idx*0x200+off, advances slot/offset, terminates to state 0x31 else loops 0x41.

## Notes / uncertainty
Machine-E reply reassembler: ring 0x35ccb8 stride/cap 0x200, always finalizes to 0x31 (no fsm_major branch, no +0x1000 pad). runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c65c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
