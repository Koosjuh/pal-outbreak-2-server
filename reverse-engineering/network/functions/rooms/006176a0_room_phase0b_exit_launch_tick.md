# 0x006176a0 room_phase0b_exit_launch_tick

| field | value |
|---|---|
| Original address | 0x006176a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006176a0 |
| Resolved name | room_phase0b_exit_launch_tick |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00616c40
**Callees:** FUN_005ac3e0, FUN_005adc80, FUN_005af300, FUN_005b6900, FUN_00608680, FUN_00618b60
**Referenced globals:** 0x874f9c (ui flag); 0x874f35 (mode); 0x874fd4 (result)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xf minor-state; +0x16 countdown

## Behavioral explanation
Room phase-0x0b finalize sub-state machine (minor 0..5): countdown/fade then on state 5 sets shared UI flags and hands to FUN_00608680 scene launch (mirror of phase-4 0x617270 without the FUN_005b24c0 call).

## Notes / uncertainty
Twin of 0x617270 finalize/launch; differs only by omitting FUN_005b24c0 and the first timer-wait. State5 identical (0x874f9c/35/fd4, FUN_00608680/005ac3e0). Variant-to-slot mapping inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006176a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
