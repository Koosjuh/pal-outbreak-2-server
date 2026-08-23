# 0x00601760 build_room_options_menu8

| field | value |
|---|---|
| Original address | 0x00601760 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00601760 |
| Resolved name | build_room_options_menu8 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fede0
**Callees:** FUN_005b6c90, FUN_005b7fd0, FUN_005ba7b0, FUN_00618b60, FUN_00618ba0
**Referenced globals:** DAT_00649b70 menu item table; PTR_FUN_00649b7c item callbacks
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0x907 cursor bind; param_1+0x97e room-variant

## Behavioral explanation
Builds the 8-item room-options menu (scenario/character list) from table DAT_00649b70 plus a confirm row, wiring per-item widgets (FUN_00618ba0 alloc) and localized labels (FUN_005b6c90/FUN_005b7fd0), with 0x55/0x56 label chosen by room variant 0x97e.

## Notes / uncertainty
Builds 8-row room-options widget menu from DAT_00649b70 (stride 0x18) + variant-selected confirm row (id 0x55/0x56 by +0x97e). Widget-node field layout cross-confirmed by sibling 0x006018d0. +0x97e variant meaning unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00601760.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
