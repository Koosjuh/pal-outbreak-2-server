# 0x001c4d40 recv_download_chunk_A

| field | value |
|---|---|
| Original address | 0x001c4d40 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c4d40 |
| Resolved name | recv_download_chunk_A |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_0010a4f0, FUN_001c2f30, FUN_001c3ab0, FUN_001c3b10, FUN_001c3b90
**Referenced globals:** 0x368421 idx; 0x368424 offset; 0x36842a count; 0x36846c sizes; 0x368474 ptrs; 0x36842c/0x36844c name; 0x368428/0x368420 done-flags; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x14
**State vars:** 0x368421; 0x368424; conn+0xd

## Behavioral explanation
Reply-0x14 handler: validates idx/offset against 0x368421/0x368424, copies the 0x2f2 body via FUN_001c3b90 into pool ptr (0x368474[idx]+off), advances offset/chunk; on last chunk copies name to 0x36842c and goes to state 0x14, else loops state 0x12.

## Notes / uncertainty
op14 body: validate idx/offset, decrypt into dest_tab[idx]+off (copylen 0x2f2 or size-off last window), advance chunk, on done set 0x368420=1 + persist name, substate->0x12/0x14.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c4d40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
