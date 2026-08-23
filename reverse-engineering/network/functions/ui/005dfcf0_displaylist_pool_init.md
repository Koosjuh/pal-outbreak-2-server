# 0x005dfcf0 displaylist_pool_init

| field | value |
|---|---|
| Original address | 0x005dfcf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dfcf0 |
| Resolved name | displaylist_pool_init |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c80a0, FUN_005cd650
**Callees:** —
**Referenced globals:** iRam00701068 (overlay base; +0x5ff6c free-list head, +0x4ff6c pool start)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701068+0x5ff6c (free-list head)

## Behavioral explanation
Initializes the display-list node pool: links 511 fixed-size (0x80) nodes into a free list via each node's +0x20 next-pointer.

## Notes / uncertainty
Threads 0x80-byte node free list (head@+0x5ff6c, pool@+0x4ff6c, next@+0x20). 511 links over a 512-slot span; last node's next left unterminated (latent unless block pre-zeroed).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dfcf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
