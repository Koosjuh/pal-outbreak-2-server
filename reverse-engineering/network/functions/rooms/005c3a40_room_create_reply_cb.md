# 0x005c3a40 room_create_reply_cb

| field | value |
|---|---|
| Original address | 0x005c3a40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c3a40 |
| Resolved name | room_create_reply_cb |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bf1e0, FUN_005c7d00
**Referenced globals:** 0x6cba7d (reply flag); 0x6ff2b0 (create/own flag, set=1); 0x6fee8c (room handle per slot, stride 0x24); 0x6cfb76 (slot room-name, stride 0x144); 0x6cc01a (local name buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006cba7d; uRam006ff2b0

## Behavioral explanation
Create-room reply handler: on status 0x00 sets 0x6cba7d=1 AND 0x6ff2b0=1, stores the returned room handle (*(param2+4)) into the room record at idx*0x24+0x6fee8c, and copies the room name (0x6cc01a) into the slot's name field; status 0x27 -> fail(2).

## Notes / uncertainty
op04 create reply cb: on 0x00 signals SM ok, sets host flag 0x6ff2b0=1, stores server-minted room handle *(param2+4) into 0x6fee8c[slot] and copies room name into 0x6cfb76[slot]; the create-boundary handle write from the project handoff. Runtime-unvalidated (handle not captured).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c3a40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
