# 0x0062d8b0 lobby_reply_step5_handler

| field | value |
|---|---|
| Original address | 0x0062d8b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062d8b0 |
| Resolved name | lobby_reply_step5_handler |
| Subsystem | packets |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005b9110, FUN_00617a00
**Referenced globals:** 0x6c4b90 lobby phase; 0x6c4fbb pending-step; 0x6c4b9e/9f/ba0 substates
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4fbb pending-reply-step(==5); 0x6c4b90 phase(!=6 guard)

## Behavioral explanation
Network reply callback (expected step cRam006c4fbb==5): reads status byte *param; 0=success advances substate b9e, else error -> FUN_005b9110(0x4c)+reset 0x6c4b90 block.

## Notes / uncertainty
Renamed from reply_handler_fbb05. Reply cb gated on screen_id!=6 && pending_tag==5; status0=advance lobby_sm/clear major+step, else error dialog 0x4c + lobby_state reset. Fields map cleanly to lobby_state_block. Which op installs it unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062d8b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
