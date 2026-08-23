# 0x005d6c10 pool_alloc_node

| field | value |
|---|---|
| Original address | 0x005d6c10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6c10 |
| Resolved name | pool_alloc_node |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d7760, FUN_005d78d0
**Callees:** FUN_005dedc0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node+0x104 in-use flag

## Behavioral explanation
Allocates a free node ([0x41]==0) from a pool, moves it to front, initializes its key region via FUN_005dedc0, marks in-use [0x41]=1.

## Notes / uncertainty
Alloc-first-free with move-to-front; symmetric with pool_free_node. Contrasts 0x6630 (in-place) and 0x6770 (tail-recycle). FUN_005dedc0 key-init not decompiled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6c10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
