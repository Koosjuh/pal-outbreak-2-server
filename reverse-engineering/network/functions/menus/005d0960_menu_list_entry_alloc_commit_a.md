# 0x005d0960 menu_list_entry_alloc_commit_a

| field | value |
|---|---|
| Original address | 0x005d0960 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d0960 |
| Resolved name | menu_list_entry_alloc_commit_a |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ca290
**Callees:** FUN_005d5a40, FUN_005d5b10, FUN_005d5cc0, FUN_005d70b0, FUN_005d71a0
**Referenced globals:** 0x701070+0x33 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x33

## Behavioral explanation
Allocates/locates a list node (71a0 then 70b0), sets a display label and returns to list state, else sets error state.

## Notes / uncertainty
Precheck(71a0)->alloc(70b0)->bind(5cc0)+commit(5a40), fail->5b10; clears view+0x33. Callee names inferred (not decompiled).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d0960.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
