# 0x005ca420 room_enter_menu_action

| field | value |
|---|---|
| Original address | 0x005ca420 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca420 |
| Resolved name | room_enter_menu_action |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ca6a0, FUN_005cce30, FUN_005d0a40
**Referenced globals:** 0x701070+0x2e sub-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x2e

## Behavioral explanation
State-10 handler invoking FUN_005d0a40 (screen pop/cancel); state-8 runs the roster pass.

## Notes / uncertainty
ACTION->FUN_005d0a40 (enter/select current room), which uses cur_room_slot_probe (005d73c0). Enter-op emission point not decoded here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca420.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
