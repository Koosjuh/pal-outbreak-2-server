# 0x001c56f0 recv_download_chunk_C

| field | value |
|---|---|
| Original address | 0x001c56f0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c56f0 |
| Resolved name | recv_download_chunk_C |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3ab0, FUN_001c3b10, FUN_001c3b90
**Referenced globals:** 0x365ce4 idx; 0x365ce8 offset; 0x365c24 sizes; 0x365c20 count; 0x35ccc0 ring; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x3f
**State vars:** 0x365ce4/0x365ce8; conn+0xd

## Behavioral explanation
Reply-0x3f handler: validates slot/offset (0x365ce4/0x365ce8), copies body into ring 0x35ccc0+idx*0x800+off, advances offset/slot, terminates to state 0x3f when done else loops 0x3d.

## Notes / uncertainty
op3f body: FIXED 0x2f2 copy (no remainder trim) into ring+slot*0x800+off, slot cap 0x7ff/2, done->substate 0x3f (op31). Last-window over-copy into padding is a noted hazard.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c56f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
