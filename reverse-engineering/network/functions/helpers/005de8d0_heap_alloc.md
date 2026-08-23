# 0x005de8d0 heap_alloc

| field | value |
|---|---|
| Original address | 0x005de8d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005de8d0 |
| Resolved name | heap_alloc |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dea10
**Callees:** FUN_005de820
**Referenced globals:** iRam00701068+0x4db78 (list) /+0x4f364 (sentinel)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
First-fit allocator: walks the free list for a gap >= (size rounded to 0x10), grabs a descriptor via heap_find_free_node and links the new block in.

## Notes / uncertainty
Already reconstructed; first-fit gap allocator with 16-byte over-align, splice, verified. extraout_a3_lo=cur / extraout_t0_lo=aligned-size are data-flow inferences from splice semantics.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005de8d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
