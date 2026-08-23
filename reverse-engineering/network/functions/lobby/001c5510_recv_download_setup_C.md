# 0x001c5510 recv_download_setup_C

| field | value |
|---|---|
| Original address | 0x001c5510 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c5510 |
| Resolved name | recv_download_setup_C |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3ab0, FUN_001c3b10
**Referenced globals:** 0x365c20 count; 0x365c24 sizes; 0x365c64 ptrs; 0x35ccc0 ring-base; 0x365ce4/0x365ce8 seq; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x3d
**State vars:** 0x365ce4/0x365ce8 seq; conn+0xd=0x3d

## Behavioral explanation
Reply-0x3d handler: reads count (clamped 2) into 0x365c20, fills sizes (0x365c24) and dest ptrs (0x365c64 into ring 0x35ccc0, 0x800 stride), resets seq, advances to state 0x3d.

## Notes / uncertainty
op3d setup: be16 count clamp<=2 then ==0 check, dest=ring(0x35ccc0)+i*0x800 (no header offset), be32 sizes NOT bound-checked, substate->0x3d (empty->0x3f fires op31).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c5510.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
