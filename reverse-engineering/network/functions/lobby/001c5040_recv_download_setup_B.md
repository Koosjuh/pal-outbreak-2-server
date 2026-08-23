# 0x001c5040 recv_download_setup_B

| field | value |
|---|---|
| Original address | 0x001c5040 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c5040 |
| Resolved name | recv_download_setup_B |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3ab0, FUN_001c3b10
**Referenced globals:** 0x365cf0 count; 0x365cf4 sizes; 0x365d34 ptrs; 0x35ccc8 ring-base; 0x365db4/0x365db8 seq; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x39
**State vars:** 0x365db4/0x365db8 seq; conn+0xd=0x1b

## Behavioral explanation
Reply-0x39 handler: reads a count (clamped 8) into 0x365cf0, fills per-slot sizes (0x365cf4) and dest ptrs (0x365d34 into ring at 0x35ccc8, 0x400 stride), resets seq, advances to state 0x1b.

## Notes / uncertainty
op39 setup: be16 count<=8, per-slot be32 size<=0x400, dest=ring(0x35ccc8)+i*0x400+0x1000, substate->0x1b (empty->0x3b starts machine C).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c5040.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
