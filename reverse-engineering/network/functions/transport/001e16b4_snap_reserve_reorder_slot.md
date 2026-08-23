# 0x001e16b4 snap_reserve_reorder_slot

| field | value |
|---|---|
| Original address | 0x001e16b4 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e16b4 |
| Resolved name | snap_reserve_reorder_slot |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d6988
**Callees:** FUN_001eb3b8, FUN_001eb858, FUN_001ebb90, FUN_001ebbd0, FUN_001ebd54, FUN_001ebd7c, FUN_001ec1f8, FUN_001ed634
**Referenced globals:** conn+0x520 pool
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node flags 0x200/0x1000

## Behavioral explanation
Walks the reorder list at struct+8 looking for a node comparing 0x1000; splits/allocates a fragment via the pool watermark alloc and re-links it, tagging nodes with 0x200/0x1000 markers.

## Notes / uncertainty
Renamed from snap_reassemble_fragment_enqueue: reserves/reuses a reorder-list placeholder bound to seq param_3, skipping 0x1000-occupied nodes, allocating a 0x10 node (flag 0x200) at end if needed, then marks 0x1000 + sets seq. Payload fill happens in caller (accept-gate), not here.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e16b4.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
