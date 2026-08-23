# 0x006018d0 build_room_options_menu10

| field | value |
|---|---|
| Original address | 0x006018d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006018d0 |
| Resolved name | build_room_options_menu10 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fede0
**Callees:** FUN_005b6c90, FUN_005b7fd0, FUN_005ba7b0, FUN_00618b60, FUN_00618ba0
**Referenced globals:** DAT_00649c30 menu item table; PTR_FUN_00649c3c item callbacks
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0x907 cursor bind; param_1+0x97e room-variant

## Behavioral explanation
Builds the 10-item room-options menu from table DAT_00649c30 plus confirm row (parallels FUN_00601760 for the other room variant), labels 0x55/0x56 by variant 0x97e.

## Notes / uncertainty
10-row twin of 0x00601760 over DAT_00649c30 (stride 0x1c, extra +0x02 byte column); confirm ids 0x55/0x56 by variant +0x97e. Which screen uses 8 vs 10 rows not established.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006018d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
