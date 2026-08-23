# 0x005cd1d0 room_handshake_retx_tick

| field | value |
|---|---|
| Original address | 0x005cd1d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cd1d0 |
| Resolved name | room_handshake_retx_tick |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ca0a0
**Callees:** FUN_005d59f0, FUN_005d5c20, FUN_005dedf0
**Referenced globals:** 0x701068+0x69014 timer1; 0x701068+0x69018 timer2; 0x701068+0x68e83/0x68e84/0x68e85 phase gates; 0x701078+3 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x69014; 0x701068+0x68e85; 0x701068+0x68e84; 0x701068+0x68e83

## Behavioral explanation
Decrements the two room countdown timers (0x69014/0x69018); when the primary hits 0 under the right phase gates, rebuilds the room key and fires the next send (FUN_005d5c20 or FUN_005d59f0).

## Notes / uncertainty
Renamed from room_timeout_tick. In-room handshake retransmit tick; timer1(+0x69014) only persists its decrement when 3 phase gates (68e83/84==2/85==1) pass; on fire rebuilds room key and sends via 0x2e==8 abort+resend else send-next. Phase values + exact wire op inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cd1d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
