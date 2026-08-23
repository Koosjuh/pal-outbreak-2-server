# 0x00617270 room_phase04_exit_launch_tick

| field | value |
|---|---|
| Original address | 0x00617270 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00617270 |
| Resolved name | room_phase04_exit_launch_tick |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00616c40
**Callees:** FUN_005ac3e0, FUN_005adc80, FUN_005af300, FUN_005b24c0, FUN_005b6900, FUN_00608680, FUN_00618b60
**Referenced globals:** 0x874f9c (ui flag=1); 0x874f35 (mode=3); 0x874fd4 (result from FUN_005adc80)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xf minor-state (0..5); +0x16 countdown

## Behavioral explanation
Room phase-4 sub-state machine (minor 0..5): fade/countdown steps then on state 5 sets shared UI flags and hands off to FUN_00608680 (scene exit/launch) and FUN_005ac3e0.

## Notes / uncertainty
Terminal fade+launch SM (minor 0-5, state0 falls through to 1); state5 sets 0x874f9c=1/0x874f35=3(next-mode)/0x874fd4=result, calls FUN_00608680 scene launch + FUN_005ac3e0 teardown. 'mode 3'=scenario/game inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00617270.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
