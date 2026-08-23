# 0x005f91f0 create_room_enter_transition

| field | value |
|---|---|
| Original address | 0x005f91f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f91f0 |
| Resolved name | create_room_enter_transition |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f9150
**Callees:** FUN_005adc80, FUN_005b68e0, FUN_005b6900, FUN_005c0400, FUN_005fe300
**Referenced globals:** param+0x10 (step); param+0x42b (fade); param+0x97e
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x10

## Behavioral explanation
SM on +0x10: prepares (FUN_005fe300) and sends the enter-room request FUN_005c0400(id, cb 0x5fc2b0), advancing to the receive step; state 1 spins on FUN_005b6900.

## Notes / uncertainty
Renamed from send_enter_room_req: it sends NO packet. Callee FUN_005c0400 seats room-register 2 and sets host flag 0x6ff2b0=1 (create path); fires cb 0x5fc2b0 synchronously. Relevant to the G12 create-room host-flag work.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f91f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
