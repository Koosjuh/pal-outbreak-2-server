# 0x005fc6b0 reply_handler_state13

| field | value |
|---|---|
| Original address | 0x005fc6b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fc6b0 |
| Resolved name | reply_ack_pending13_opendetail_or_backout |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (registered as a reply/completion callback)
**Callees:** FUN_005f8b50 (open room-detail for selection), FUN_005f6970 (back out / pop, arg 4)
**Referenced globals:** cRam006c4b90 (screen_id gate), cRam006c4fbb (pending_tag = 0x13), uRam006c4600 (selected room)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb (==0x13 gate)

## Behavioral explanation
Reply/ACK handler for the op that latched pending-tag **0x13**. Gated on `screen_id != 6` and
`pending_tag == 0x13`; clears the tag up front. On OK (0x00) it opens the room-detail screen for the
currently selected room by calling FUN_005f8b50(selected_room /*0x6c4600*/). On any error (nonzero)
it backs out via FUN_005f6970(4) (pop/return-to-list with reason code 4).

## Input / output
- `param_1` : `u8* replyBody` — byte 0 status (0x00 OK / nonzero error).
- returns `void`.

## Side effects
- `pending_tag` (0x6c4fbb) := 0.
- OK: FUN_005f8b50(uRam006c4600) — open detail for selected room.
- error: FUN_005f6970(4) — back out.

## Important branches
- `screen_id == 6` OR `pending_tag != 0x13` → no-op.
- clear tag; `status == 0x00` → open detail (selection 0x6c4600).
- `status != 0x00` → FUN_005f6970(4) back out.

## Constants & flags
- `pending_tag == 0x13` selector. `screen_id 6` = in-game. back-out reason `4`.
- 0x6c4600 = current selected room index (GLOBALS: "selected room").

## Corrected reconstruction
```c
void reply_ack_pending13(const uint8_t *replyBody)
{
    if (g_screen_id == SCREEN_INGAME /*6*/) return;
    if (g_pending_tag != PENDING_13 /*0x13*/) return;

    uint8_t status = replyBody[0];
    g_pending_tag = 0;
    if (status == REPLY_OK /*0x00*/) {
        open_room_detail(g_selected_room /*0x6c4600*/);  // FUN_005f8b50
    } else {
        room_flow_backout(4);                            // FUN_005f6970
    }
}
```

## Evidence
- `sources/overlays/overlay-3dat-decompile/FUN_005fc6b0.c` — CFG: OK→f8b50(0x6c4600); error→f6970(4).
- GLOBALS.md 0x6c4600 selected room; FUN_005f8b50 references 0x6c0760 room-list / 0x6970a0 detail buf.

## Remaining uncertainty
- Which op latched 0x13 (likely a room-detail/enter precheck); runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fc6b0.c`  — untouched decompiler output.
