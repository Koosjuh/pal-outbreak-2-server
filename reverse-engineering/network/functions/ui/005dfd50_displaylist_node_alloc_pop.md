# 0x005dfd50 displaylist_node_alloc_pop

| field | value |
|---|---|
| Original address | 0x005dfd50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dfd50 |
| Resolved name | displaylist_node_alloc_pop |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dfde0
**Callees:** —
**Referenced globals:** iRam00701068+0x5ff6c (free-list head)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701068+0x5ff6c

## Behavioral explanation
Pops one node off the display-list free list at +0x5ff6c (advances head to node's +0x20 next).

## Notes / uncertainty
Free-list pop: returns old head (in v0; raw mistyped void) or NULL if empty; advances head to next@+0x20. Return typing inferred from caller use.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dfd50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
