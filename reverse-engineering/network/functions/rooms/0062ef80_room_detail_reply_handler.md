# 0x0062ef80 room_detail_reply_handler

| field | value |
|---|---|
| Original address | 0x0062ef80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062ef80 |
| Resolved name | room_detail_reply_handler |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0fd0
**Referenced globals:** 0x6c4600 selected-room; 0x6c5510 room-detail
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4b90 phase(!=6 guard)

## Behavioral explanation
Reply callback: on status 0 loads room-detail record for selected room 0x6c4600 into 0x6c5510 via FUN_005c0fd0, else clears 0x6c5510.

## Notes / uncertainty
Already fully reconstructed. Single-room detail fetch cb (no pending_tag gate, busy-screen only); success loads 0x6c5510 for selected_room, else clears. Open: 0x6c5510 layout; 1-based vs 0-based selected_room.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062ef80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
