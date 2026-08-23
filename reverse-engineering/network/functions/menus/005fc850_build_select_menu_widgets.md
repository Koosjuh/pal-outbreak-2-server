# 0x005fc850 build_select_menu_widgets

| field | value |
|---|---|
| Original address | 0x005fc850 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fc850 |
| Resolved name | build_select_menu_widgets |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f9280, FUN_005f9540, FUN_005fa490
**Callees:** FUN_005b8130, FUN_005ba570, FUN_005ba7b0, FUN_00618b60, FUN_00618ba0
**Referenced globals:** 0x6498b0/0x649a90/0x649aa0 layout tables; 0x6c4fcd list flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds the scenario/room select-menu widget set per layout arg (0-3): allocates buttons with ids 0x50/0x51/0xd9+ and callbacks LAB_005fd3e0 / FUN_005fd630.

## Notes / uncertainty
Rebuilds select-menu widget set for 4 layouts (0-3): headers 0x50/0x51, animated items 0xd9+i (cb FUN_005fd630), descriptor-driven rows from 0x649a90[layout], then input group FUN_005ba570(0x1c/0xb)+activate. Which real screen each layout maps to is inferred from callers.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fc850.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
