# 0x005de880 heap_find_block_by_addr

| field | value |
|---|---|
| Original address | 0x005de880 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005de880 |
| Resolved name | heap_find_block_by_addr |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dea10
**Callees:** —
**Referenced globals:** iRam00701068+0x4db70/+0x4f364 (list head/sentinel)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Walks the heap block linked-list looking for the node whose payload address (+4) equals param, returns node or 0.

## Notes / uncertainty
Already reconstructed; list-walk match on +0x04 payload addr, sentinel terminator, verified. Complete.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005de880.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
