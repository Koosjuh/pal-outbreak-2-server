# 0x0062ec90 create_room_ack_handler

| field | value |
|---|---|
| Original address | 0x0062ec90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062ec90 |
| Resolved name | create_room_ack_handler |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0
**Referenced globals:** 0x6c4fbb pending-step; 0x6c4ba0/ba1 substates; 0x6c517c error-arg
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4fbb pending-step(==0x11)

## Behavioral explanation
Reply callback (expects cRam006c4fbb==0x11): status 0 advances substate ba0, else error resets ba0=5, ba1=0 and FUN_005be9a0(0x6c517c).

## Notes / uncertainty
Already fully reconstructed. Create-step ack (pending_tag 0x11): status0 step++, else notice + screen_step=5 recover. Open: meaning of screen_step==5 sub-screen.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062ec90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
