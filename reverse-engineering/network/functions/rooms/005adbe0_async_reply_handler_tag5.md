# 0x005adbe0 async_reply_handler_tag5

| field | value |
|---|---|
| Original address | 0x005adbe0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005adbe0 |
| Resolved name | async_reply_handler_tag5 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005b9110, FUN_005f74d0
**Referenced globals:** 0x6c4fbb(pending); 0x6c4b90; 0x6c4b9e/0x6c4b9f/0x6c4ba0/0x6c4ba1
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb; cRam006c4b90

## Behavioral explanation
Async reply callback (pending fbb==5): ok byte0==0 -> success 5f74d0, else reset nav fields and show box (5b9110).

## Notes / uncertainty
Sibling of tag1 for pending_tag==5. Error path is a DEEPER nav rewind: zeros lobby_sm(0x6c4b9e)+screen_major+0x6c4ba0/ba1 and shows msg box 0x4c. Uncertainty: originating op for tag 5 unverified.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005adbe0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
