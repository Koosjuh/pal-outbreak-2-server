# 0x0062f060 enter_step_ack_handler

| field | value |
|---|---|
| Original address | 0x0062f060 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062f060 |
| Resolved name | enter_step_ack_handler |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0
**Referenced globals:** 0x6c4fbb pending-step; 0x6c550e flag; 0x6c4ba0/b9f substates; 0x6c5530 timer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4fbb pending-step(==0x0a)

## Behavioral explanation
Reply callback (expects cRam006c4fbb==0x0a): status 0 sets 0x6c550e=1 and bumps ba0; status 0xff resets ba0=0, b9f=1, timer 0x6c5530=0x708 and FUN_005be9a0(error).

## Notes / uncertainty
Already fully reconstructed. Enter-step ack (pending_tag 0x0a): 0x00 ok -> flag 0x6c550e=1 + step++; 0xff fail -> bounce to list; other statuses ignored (stay pending). Open: 0x6c550e meaning; why other statuses no-op.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062f060.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
