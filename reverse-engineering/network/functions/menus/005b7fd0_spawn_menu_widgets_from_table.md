# 0x005b7fd0 spawn_menu_widgets_from_table

| field | value |
|---|---|
| Original address | 0x005b7fd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b7fd0 |
| Resolved name | spawn_menu_widgets_from_table |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b3cb0, FUN_005b3ed0, FUN_005b41b0, FUN_005f62e0, FUN_005faa60, FUN_005fba80, FUN_00601760, FUN_006018d0, FUN_006020e0, FUN_00602230, FUN_00604af0, FUN_00607b10, FUN_00627ea0, FUN_00628110, FUN_006290e0, FUN_0062d140
**Callees:** FUN_005b8130
**Referenced globals:** PTR_DAT_00639440 / PTR_DAT_00639b90 (per-screen widget descriptor tables); DAT_00639c20/c22 (widget position table); uRam006c4fd3 (screen build/teardown flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4fd3

## Behavioral explanation
Instantiate a menu screen's widgets from two descriptor tables indexed by param_1 (PTR_DAT_00639440 and PTR_DAT_00639b90): for each 6-short descriptor alloc an object (FUN_005b8130) and set its type/pos (from DAT_00639c20), callback param and flags.

## Notes / uncertainty
Screen constructor: two descriptor tables (0x639440/0x639b90) of 6-short widgets, alloc+init each (pos from 0x639c20). Descriptor shorts [2]/[3] and A-vs-B purpose unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b7fd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
