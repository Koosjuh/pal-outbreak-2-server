# 0x00617030 room_phase01_intro_tick

| field | value |
|---|---|
| Original address | 0x00617030 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00617030 |
| Resolved name | room_phase01_intro_tick |
| Subsystem | rooms |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00616c40
**Callees:** FUN_005af300, FUN_00618b60
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xf minor-state; +0x16 countdown; +0xe major-state

## Behavioral explanation
Room phase-1 countdown handler (minor +0xf 0..2): schedules a 10-tick then 2-tick delay, advances the major state, invokes FUN_00618b60 / FUN_005af300 UI/sound.

## Notes / uncertainty
3-step timed intro (minor 0-2, timers 10/2f); advances major on expiry. Pure timing/UI, no net I/O. Callee UI/SE roles inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00617030.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
