# 0x001c6130 recv_download_chunk_D

| field | value |
|---|---|
| Original address | 0x001c6130 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c6130 |
| Resolved name | recv_download_chunk_D |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3ab0, FUN_001c3b10, FUN_001c3b90
**Referenced globals:** 0x365d74 ids; 0x365cf4 sizes; 0x365db4 idx; 0x365db8 offset; 0x365cf0 count; 0x35ccc8 ring; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x2f
**State vars:** 0x365db4/0x365db8; conn+0xd

## Behavioral explanation
Reply-0x2f handler: matches slot-id (0x365d74), reads offset+len, copies body into ring 0x35ccc8+idx*0x800+off, advances slot/offset, terminates to state 0x31 (fsm 3) or 0x02 else loops 0x2b.

## Notes / uncertainty
Machine-D reply reassembler: ring 0x35ccc8 stride 0x800 +0x1000 pad, cap 0x1000, max 8 slots; finalize 0x31 iff fsm_major==3 else 0x02. Body copy uses pre-update base offset. fsm_major==3=create-path inferred; runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c6130.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
