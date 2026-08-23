# 0x005dfee0 displaylist_element_remove

| field | value |
|---|---|
| Original address | 0x005dfee0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dfee0 |
| Resolved name | displaylist_element_remove |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c92d0, FUN_005cd5d0, FUN_005daba0, FUN_005daf30, FUN_005db300, FUN_005db8a0, FUN_005dbca0, FUN_005dc010, FUN_005dc4b0, FUN_005dcb90, FUN_005dd660
**Callees:** FUN_005dfd80
**Referenced globals:** iRam00701068+0x5ff70 (heads); iRam00701068+0x5ff94 (tails)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Unlinks a display-list node from its per-layer doubly-linked queue and returns it to the free list.

## Notes / uncertainty
3-case DLL unlink (head/tail/middle) keyed on prev+0x1c/next+0x20, layer from node+3, then free_push. Textbook; no material uncertainty.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dfee0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
