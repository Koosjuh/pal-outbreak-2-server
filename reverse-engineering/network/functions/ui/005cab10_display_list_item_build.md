# 0x005cab10 display_list_item_build

| field | value |
|---|---|
| Original address | 0x005cab10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cab10 |
| Resolved name | display_list_item_build |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005d8b00, FUN_005d8b90, FUN_005d8c90, FUN_005d8d60, FUN_005d8e00, FUN_005d8ea0, FUN_005d8f90, FUN_005d9030, FUN_005d9160, FUN_005d9290, FUN_005d92f0, FUN_005d9350, FUN_005d93f0, FUN_005d9450, FUN_005d9520, FUN_005d95f0, FUN_005d96a0, FUN_005d9790, FUN_005d9890, FUN_005d9940, FUN_005d9ac0, FUN_005d9bd0, FUN_005d9ca0, FUN_005d9d70, FUN_005d9dd0
**Callees:** FUN_001ae3e0, FUN_005ca9c0, FUN_005cf3a0, FUN_005dfbc0
**Referenced globals:** 0x701068+0x5ffc0 display-list[500]; 0x701068+0x68dd4 text heap ptr; 0x701068+0x60dd0 heap base; 0x701088 profile fields(0/0x41/0x4c/0xcd/0x14e/0x14f); 0x701070+0x1a/0x1e origin; 0x701070+0x590 field buf; 0x701070+0x57f field buf
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x68e78 focused row

## Behavioral explanation
Core display-list builder (25 callers): appends a widget/row of a given type into the 0x5ffc0[500] array, copies its text into the 0x68dd4 text heap, and for input-field types (param_9) pulls the value from profile fields at 0x701088; assigns geometry, color slot, and z-order.

## Notes / uncertainty
Central display-list row builder (25 callers): free-slot find, msg-row group linkage, heap-guarded text/value copy (input fields pull profile fields 0x701088 via 2-digit code switch), geometry+color reg+z-order finalize. 2-digit field-code->profile-field map and group state machine (0x14/15/16/1e/0a) inferred, not runtime-traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cab10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
