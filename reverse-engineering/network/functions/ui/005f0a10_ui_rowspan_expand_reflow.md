# 0x005f0a10 ui_rowspan_expand_reflow

| field | value |
|---|---|
| Original address | 0x005f0a10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f0a10 |
| Resolved name | ui_rowspan_expand_reflow |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005eb7d0
**Callees:** FUN_005ef850, FUN_005f00b0, FUN_005f0480, FUN_005f07e0
**Referenced globals:** +0xd894 current node; +0x24e0 pool
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Iterates row-span members (via ui_find_row_span_member), allocating+reflowing a node for each until the chain ends.

## Notes / uncertainty
Row-span analogue of f0930 using f07e0 finder; reflow-then-alloc order, no scope push / no +0x18d. Allocator + head(word0) role inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f0a10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
