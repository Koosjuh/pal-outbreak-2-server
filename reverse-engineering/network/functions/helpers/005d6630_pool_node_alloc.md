# 0x005d6630 pool_node_alloc

| field | value |
|---|---|
| Original address | 0x005d6630 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6630 |
| Resolved name | pool_node_alloc |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d70b0, FUN_005d71e0, FUN_005d7320, FUN_005d7420, FUN_005d74a0, FUN_005d76b0
**Callees:** FUN_005dedc0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node+0x41 alloc flag

## Behavioral explanation
Generic free-list allocator: walks a singly-linked node list to the first free node (+0x41==0), initializes it and marks it allocated.

## Notes / uncertainty
Alloc-first-free in place (no move-to-front). alloc flag = int-index [0x41] = byte +0x104. FUN_005dedc0 key-init not separately decompiled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6630.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
