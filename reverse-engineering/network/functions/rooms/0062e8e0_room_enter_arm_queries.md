# 0x0062e8e0 room_enter_arm_queries

| field | value |
|---|---|
| Original address | 0x0062e8e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062e8e0 |
| Resolved name | room_enter_arm_queries |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062dc40, FUN_0062de90
**Callees:** FUN_005aec20, FUN_005c0f60, FUN_005c2820
**Referenced globals:** 0x6c4b90 block; 0x6c79ac room-detail buffer(0xec0); 0x6c4fe6/fe8 player data; 0x6c5510/14/18 timers
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4b9e/9f/ba0/ba1 substates; 0x6c550d/550f flags

## Behavioral explanation
Room leave/cleanup: resets 0x6c4b90 substates (b9e=3), clears roster/room state at 0x6c79ac (0xec0 bytes), reinit timers (0x6c5514=0x3c,0x6c5518=0x14) and re-requests room detail via FUN_005c0f60(...,0x62ef80)/FUN_005c2820(...,0x62eff0).

## Notes / uncertainty
REWROTE + NAME CORRECTION: prior 'room_leave_reset' is a misnomer. Deep read shows this is the room-ENTER commit - called ONLY from create-success (0062dc40 step4 result==0) and enter-flow (0062de90); sets lobby_sm 0x6c4b9e=3 (in-room), clears roster/detail buffer 0x6c79ac (0xec0=4x0x3b0), fires room-detail (FUN_005c0f60 cb 0x62ef80) + player-count (FUN_005c2820 cb 0x62eff0) queries. Directly on the create-roster blocker path (empty result here = '1/0P only CREATOR'). Uncertainty: on-wire opcodes for the two queries.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062e8e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
