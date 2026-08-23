# 0x005ff1b0 room_setup_cursor_nav

| field | value |
|---|---|
| Original address | 0x005ff1b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ff1b0 |
| Resolved name | room_setup_cursor_nav |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fede0
**Callees:** FUN_005adc80, FUN_005b09b0, FUN_005b14b0, FUN_005f5ea0
**Referenced globals:** 0x6c076a room capacity/count field
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0x907 cursor; param_1+0x97e room-variant; param_1+0x909 confirmed-sel; param_1+0x11 toggle; param_1+0x456 vs capacity

## Behavioral explanation
D-pad cursor/selection logic for the room option list (scenario/difficulty): reads button masks via FUN_005b14b0, clamps cursor 0x907 within range 2..4/3..5 by variant, plays sound, and on confirm advances or calls FUN_005f5ea0.

## Notes / uncertainty
Renamed from room_scenario_cursor_nav. Room-setup cursor SM, two variant layouts (+0x97e); capacity gate compares +0x456 to per-room cap 0x6c076a before START. Roster row check via roster_table +0x309c stride 0x3b0 (confirmed). Pad-mask button identities inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ff1b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
