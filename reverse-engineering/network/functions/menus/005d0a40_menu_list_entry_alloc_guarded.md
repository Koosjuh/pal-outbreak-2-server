# 0x005d0a40 menu_list_entry_alloc_guarded

| field | value |
|---|---|
| Original address | 0x005d0a40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d0a40 |
| Resolved name | menu_list_entry_alloc_guarded |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ca0a0, FUN_005ca420, FUN_005ce0e0
**Callees:** FUN_005d5a40, FUN_005d5b10, FUN_005d5cc0, FUN_005d7320, FUN_005d73c0
**Referenced globals:** 0x701070+0x38/0x3a modal lock; 0x701068+0x68e83; 0x701078+1/+4
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x38; 0x701070+0x3a

## Behavioral explanation
Allocates a list node only when the modal-lock flags (0x38/0x3a) are clear; resets cursor/count fields then commits.

## Notes / uncertainty
Modal-lock-guarded (view+0x38/+0x3a must be 0) alloc via 73c0/7320; resets ui+0x68e83/cursor+1/group_count on commit. Locked=silent no-op. Callees inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d0a40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
