# 0x005de730 heap_pool_init

| field | value |
|---|---|
| Original address | 0x005de730 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005de730 |
| Resolved name | heap_pool_init |
| Subsystem | initialization |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** iRam00701068 (+0x4db70 node table, +0x4f364 sentinel, +0x1a000 arena)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Initializes the overlay's small block-heap: zeroes the 0x1800 free-node table at +0x4db70 and the 0x1a000 data arena, seeding a sentinel free-list node.

## Notes / uncertainty
Already reconstructed; 512-entry 0xc-byte descriptor table + head guard + tail sentinel + 0x1a000 arena verified, consistent with alloc/free/realloc. No captured caller.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005de730.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
