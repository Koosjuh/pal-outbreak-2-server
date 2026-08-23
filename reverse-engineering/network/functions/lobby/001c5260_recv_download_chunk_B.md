# 0x001c5260 recv_download_chunk_B

| field | value |
|---|---|
| Original address | 0x001c5260 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c5260 |
| Resolved name | recv_download_chunk_B |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3ab0, FUN_001c3b10, FUN_001c3b90
**Referenced globals:** 0x365db4 idx; 0x365db8 offset; 0x365cf4 sizes; 0x365cf0 count; 0x35ccc8 ring; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x3b
**State vars:** 0x365db4/0x365db8; conn+0xd

## Behavioral explanation
Reply-0x3b handler: validates slot/offset (0x365db4/0x365db8), copies body into ring 0x35ccc8+idx*0x400+off via FUN_001c3b90, advances offset/slot, terminates at state 0x3b when all slots done else loops 0x1b.

## Notes / uncertainty
op3b body: decrypt into ring+slot*0x400+off+0x1000, slot cap 0x3ff/8, done->substate 0x3b (start machine C).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c5260.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
