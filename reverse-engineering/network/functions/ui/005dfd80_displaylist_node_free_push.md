# 0x005dfd80 displaylist_node_free_push

| field | value |
|---|---|
| Original address | 0x005dfd80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dfd80 |
| Resolved name | displaylist_node_free_push |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dfee0
**Callees:** —
**Referenced globals:** iRam00701068+0x5ff6c (free-list head)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701068+0x5ff6c

## Behavioral explanation
Zeros a 0x80-byte node and pushes it back onto the free list head at +0x5ff6c.

## Notes / uncertainty
memset(node,0,0x80) then push to free-list head; next@+0x20. memset (func_0x00106b60) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dfd80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
