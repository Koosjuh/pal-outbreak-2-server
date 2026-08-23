# 0x005b3790 screen_character_select

| field | value |
|---|---|
| Original address | 0x005b3790 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b3790 |
| Resolved name | screen_character_select |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b24e0
**Callees:** FUN_005acd60, FUN_005af300, FUN_005af340, FUN_005b2470, FUN_005b68e0, FUN_005bac80, FUN_005bd940, FUN_005bdae0, FUN_005bdd90, FUN_005c7df0, FUN_005c7e10, FUN_005c7e20, FUN_005ff8d0, FUN_00608670, FUN_00618800, FUN_00619330
**Referenced globals:** 0x874f35 mode; 0x874f38/0x874f3a/0x874f37 host info; 0x343625 flag; 0x6c50f0/0x6c50f4 scroll offsets; 0x6c69e0 detail copy
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0xf sub-state; struct+0x10 nested sub-state; struct+0x1464/0x1466 selection

## Behavioral explanation
Screen-7 character/scenario-select machine: enumerates selectable characters 1..11 (0x5bac80), snapshots host/room info (0x874f3x), builds selection widgets, and toggles mode 0x874f35 on confirm.

## Notes / uncertainty
Char/scenario-select SM: enumerates available chars 1..11 (FUN_005bac80), reads selection/scroll, on confirm sets mode 0x874f35=2, FUN_005ff8d0 + FUN_005b2470(3) fires the app net request. Exact emitted opcode and 0x874f35==3 (scenario-owner) split inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b3790.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
