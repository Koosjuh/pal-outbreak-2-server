# 0x005d09d0 menu_list_entry_alloc_commit_b

| field | value |
|---|---|
| Original address | 0x005d09d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d09d0 |
| Resolved name | menu_list_entry_alloc_commit_b |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ca290, FUN_005ce530, FUN_005d3930
**Callees:** FUN_005d5a40, FUN_005d5b10, FUN_005d5cc0, FUN_005d71e0, FUN_005d72d0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Variant of 0960: allocate node (72d0/71e0), set label (5cc0), return-to-list (5a40) or error (5b10).

## Notes / uncertainty
Sibling of 0960 with alloc pair 72d0/71e0, no view+0x33 write. A/B allocator distinction unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d09d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
