# 0x0062ed30 create_room_ack_handler_step14

| field | value |
|---|---|
| Original address | 0x0062ed30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062ed30 |
| Resolved name | create_room_ack_handler_step14 |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005f6970
**Referenced globals:** 0x6c4fbb pending-step; 0x6c4ba0/ba1 substates; 0x6c5539 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4fbb pending-step(==0x14)

## Behavioral explanation
Reply callback (expects cRam006c4fbb==0x14): status 0 sets ba0=7, ba1=0, flag 0x6c5539=0xff; else FUN_005f6970(4) error.

## Notes / uncertainty
Already fully reconstructed. Create-step 0x14 ack: success -> screen_step=7 + flag 0x6c5539=0xff; failure -> hard abort FUN_005f6970(4). Open: 0x6c5539 / step7 meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062ed30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
