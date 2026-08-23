# 0x006020e0 build_room_stats_menu

| field | value |
|---|---|
| Original address | 0x006020e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006020e0 |
| Resolved name | build_room_stats_menu |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ffbe0, FUN_00600200
**Callees:** FUN_005b6c90, FUN_005b7fd0, FUN_005ba7b0, FUN_005f58c0, FUN_00618b60, FUN_00618ba0
**Referenced globals:** item ids 0x8a/0x37; 0x907 cursor bind
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0x907 cursor bind

## Behavioral explanation
Builds the in-room stats/action menu: allocates widget nodes (FUN_00618ba0), sets the roster renderer FUN_00602340 as an item draw-cb, and wires action handlers LAB_00602610/00603b30/00603c30 plus localized labels.

## Notes / uncertainty
Builds in-room stats/action menu: 2 roster items(0x8a) with roster render cb FUN_00602340 + 3 action buttons(LAB_00602610/00603b30/00603c30), binds 3-entry cursor. Restores cursor from confirmed_sel. Directly relevant to G12 roster visibility. Button labels/effects not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006020e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
