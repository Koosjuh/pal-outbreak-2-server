# 0x001c5f30 recv_download_setup_D_keyed

| field | value |
|---|---|
| Original address | 0x001c5f30 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c5f30 |
| Resolved name | recv_download_setup_D_keyed |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3ab0, FUN_001c3b10
**Referenced globals:** 0x365cf0 count; 0x365d34 ptrs; 0x365d74 ids; 0x365cf4 sizes; 0x35ccc8 ring; 0x365db4/0x365db8 seq; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x365db4/0x365db8 seq; conn+0xd=0x2b

## Behavioral explanation
Reply handler: reads count (clamped 8) into 0x365cf0, fills dest ptrs (0x365d34 into ring 0x35ccc8, 0x800 stride) plus per-slot id(0x365d74)+size(0x365cf4) pairs, resets seq, advances to state 0x2b.

## Notes / uncertainty
Keyed setup: reuses machine-B ring/tables (0x365cf0/cf4/d34/db4/db8, ring 0x35ccc8) at 0x800 stride + adds per-slot id table 0x365d74; count<=8, no size bound, substate->0x2b (op2f)/0x02 empty. B & D mutually exclusive; id record-class inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c5f30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
