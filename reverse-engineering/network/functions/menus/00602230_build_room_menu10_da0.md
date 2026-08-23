# 0x00602230 build_room_menu10_da0

| field | value |
|---|---|
| Original address | 0x00602230 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00602230 |
| Resolved name | build_room_menu10_da0 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00600200
**Callees:** FUN_005b6c90, FUN_005b7fd0, FUN_005ba7b0, FUN_00618b60, FUN_00618ba0
**Referenced globals:** DAT_00649da0 menu table; PTR_FUN_00649dac callbacks
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0x907 cursor bind

## Behavioral explanation
Builds a 10-item room menu from table DAT_00649da0 (item id 0x67 gets flag), wiring per-item callbacks and localized labels (FUN_005b6c90 0xd/FUN_005b7fd0 0x1c).

## Notes / uncertainty
Third room-menu builder variant over DAT_00649da0 (stride 0x1c); elem_id 0x67 gets +0x03 special-row flag; fixed confirm binds (no +0x97e variant branch). Twin of 0x006018d0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00602230.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
