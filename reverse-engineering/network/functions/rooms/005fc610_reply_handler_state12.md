# 0x005fc610 reply_handler_state12

| field | value |
|---|---|
| Original address | 0x005fc610 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fc610 |
| Resolved name | reply_ack_pending12_proceed_or_rebuild |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (registered as a reply/completion callback)
**Callees:** FUN_005f7610 (proceed on success), FUN_005b9110 (overlay rebuild/redraw 0x4c)
**Referenced globals:** cRam006c4b90 (screen_id gate), cRam006c4fbb (pending_tag = 0x12), uRam006c4b9f/uRam006c4ba0/uRam006c4ba1 (list/paging counters)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb (==0x12 gate)

## Behavioral explanation
Reply/ACK handler for the op that latched pending-tag **0x12**. Gated on `screen_id != 6` and
`pending_tag == 0x12`; clears the tag up front. On OK (0x00) it calls FUN_005f7610 to proceed
(advance to the next room screen using the current selection). On any error (nonzero) it zeroes the
three list/paging state bytes (0x6c4b9f roster-dirty, 0x6c4ba0 step, 0x6c4ba1) and rebuilds the
overlay list via FUN_005b9110(0x4c) — i.e. resets the list SM back to a clean list view.

## Input / output
- `param_1` : `u8* replyBody` — byte 0 status (0x00 OK / nonzero error).
- returns `void`.

## Side effects
- `pending_tag` (0x6c4fbb) := 0.
- OK: FUN_005f7610() — proceed.
- error: 0x6c4b9f=0, 0x6c4ba0=0, 0x6c4ba1=0; FUN_005b9110(0x4c) — rebuild overlay/list.

## Important branches
- `screen_id == 6` OR `pending_tag != 0x12` → no-op.
- clear tag; `status == 0x00` → FUN_005f7610().
- `status != 0x00` → reset list counters + FUN_005b9110(0x4c). (Any nonzero counts as error.)

## Constants & flags
- `pending_tag == 0x12` selector. `screen_id 6` = in-game. overlay/list id `0x4c`.
- 0x6c4b9f/0x6c4ba0/0x6c4ba1 = contiguous list SM state bytes (roster-dirty/step/next).

## Corrected reconstruction
```c
void reply_ack_pending12(const uint8_t *replyBody)
{
    if (g_screen_id == SCREEN_INGAME /*6*/) return;
    if (g_pending_tag != PENDING_12 /*0x12*/) return;

    uint8_t status = replyBody[0];
    g_pending_tag = 0;
    if (status == REPLY_OK /*0x00*/) {
        room_flow_proceed();           // FUN_005f7610
    } else {
        g_list_dirty = 0;              // 0x6c4b9f
        g_screen_step = 0;             // 0x6c4ba0
        g_list_next  = 0;              // 0x6c4ba1
        overlay_rebuild(0x4c);         // FUN_005b9110
    }
}
```

## Evidence
- `sources/overlays/overlay-3dat-decompile/FUN_005fc610.c` — CFG: OK→f7610; error→3 counter resets +
  b9110(0x4c).
- GLOBALS.md 0x6c4b9f/0x6c4ba0 list SM bytes; PACKET_INDEX FUN_005b9110 overlay build.

## Remaining uncertainty
- What FUN_005f7610 advances to and which op latched 0x12; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fc610.c`  — untouched decompiler output.
