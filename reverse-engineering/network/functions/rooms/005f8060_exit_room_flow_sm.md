# 0x005f8060 exit_room_flow_sm

| field | value |
|---|---|
| Original address | 0x005f8060 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f8060 |
| Resolved name | exit_room_flow_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f8030, FUN_005fb710
**Callees:** FUN_005b68e0, FUN_005b6900, FUN_005b9060, FUN_005c0e30, FUN_005f6970
**Referenced globals:** param+0x10 (step); param+0x16 (timer); param+0x42b (fade); param+0x997 (context)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x10; param+0x997

## Behavioral explanation
State machine on +0x10 (0-4) for leaving a room: fades/timers, sends the leave request FUN_005c0e30(...,cb 0x5f81a0), then transitions screens via FUN_005f6970 based on context byte +0x997.

## Notes / uncertainty
Leave-room/return-to-lobby SM (+0x10 steps 0-4): fade, room_enter_begin(0,0,0,cb 0x5f81a0) transition, then route on reply-context +0x997 (1=restart,2=next-screen). The actual leave wire opcode is emitted by the pump FUN_005c1c80, not here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f8060.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
