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
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (reply callback, registered by e8e0 / FUN_005c0f60 room-detail request)
**Callees:** FUN_005c0fd0 (load room-detail record)
**Referenced globals:** 0x6c4b90 screen_id; 0x6c4600 selected_room; 0x6c5510 room_detail block
**Referenced strings:** —
**Referenced opcodes:** room-detail reply
**State vars:** guard `screen_id != 6`

## Behavioral explanation
Reply handler for a **single-room detail** fetch. Unlike the list handlers it does not gate on `pending_tag`, only on the busy screen. `param_1[0]` low byte is status: on success it loads the detail record for the currently selected room (`selected_room` 0x6c4600) into the detail block 0x6c5510 via FUN_005c0fd0; on any error it zeroes the detail block (0x6c5510=0), clearing the panel.

## Input / output
- `param_1`: `u32* reply` — `[0]` low byte = status. Void; output via globals.
- Reads `selected_room` (0x6c4600) to pick which room to expand.

## Side effects
- Success: `room_detail (0x6c5510)` filled from FUN_005c0fd0(selected_room, &room_detail).
- Failure: `room_detail = 0`.

## Important branches
- `screen_id==6` → return.
- `status==0` → load detail.
- `status!=0` → clear detail.

## Constants & flags
- `screen_id (0x6c4b90) == 0x06` — busy guard.
- No pending_tag gate (detail fetch is fire-and-forget against the selected room).

## Corrected reconstruction
```c
void room_detail_reply_handler(u32 *reply) {
    if (screen_id == SCREEN_BUSY /*6*/) return;
    u8 status = (u8)reply[0];
    if (status == 0)
        load_room_detail(selected_room /*0x6c4600*/, &room_detail /*0x6c5510*/); // FUN_005c0fd0
    else
        room_detail = 0;                          // clear panel
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_0062ef80.c`.
- FUN_005c0fd0 takes (roomIndex, destPtr) — same getter shape as the list accessors → "load detail record".
- Registered by e8e0 (FUN_005c0f60), the room-detail request path.
- Runtime-unvalidated.

## Remaining uncertainty
- Contents/layout of the 0x6c5510 detail block not enumerated here. Whether `selected_room` is 1-based (as in the list loop) vs 0-based is not confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062ef80.c`  — untouched decompiler output.
