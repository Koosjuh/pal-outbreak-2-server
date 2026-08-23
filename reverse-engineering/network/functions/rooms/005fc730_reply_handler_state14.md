# 0x005fc730 reply_handler_state14

| field | value |
|---|---|
| Original address | 0x005fc730 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fc730 |
| Resolved name | reply_ack_pending14_step_or_backout |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (registered as a reply/completion callback)
**Callees:** FUN_005f6970 (back out / pop, arg 4)
**Referenced globals:** cRam006c4b90 (screen_id gate), cRam006c4fbb (pending_tag = 0x14), cRam006c4ba0 (screen_step)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb (==0x14 gate)

## Behavioral explanation
Reply/ACK handler for the op that latched pending-tag **0x14**. Gated on `screen_id != 6` and
`pending_tag == 0x14`; clears the tag up front. On OK (0x00) it advances `screen_step` (0x6c4ba0). On
any error (nonzero) it backs out via FUN_005f6970(4). Same family as the other five reply handlers.

## Input / output
- `param_1` : `u8* replyBody` — byte 0 status (0x00 OK / nonzero error).
- returns `void`.

## Side effects
- `pending_tag` (0x6c4fbb) := 0.
- OK: `screen_step` (0x6c4ba0) += 1.
- error: FUN_005f6970(4) — back out.

## Important branches
- `screen_id == 6` OR `pending_tag != 0x14` → no-op.
- clear tag; `status == 0x00` → step++.
- `status != 0x00` → FUN_005f6970(4).

## Constants & flags
- `pending_tag == 0x14` selector. `screen_id 6` = in-game. back-out reason `4`.

## Corrected reconstruction
```c
void reply_ack_pending14(const uint8_t *replyBody)
{
    if (g_screen_id == SCREEN_INGAME /*6*/) return;
    if (g_pending_tag != PENDING_14 /*0x14*/) return;

    uint8_t status = replyBody[0];
    g_pending_tag = 0;
    if (status == REPLY_OK /*0x00*/) {
        g_screen_step += 1;        // cRam006c4ba0
    } else {
        room_flow_backout(4);      // FUN_005f6970
    }
}
```

## Evidence
- `sources/overlays/overlay-3dat-decompile/FUN_005fc730.c` — CFG: OK→step++; error→f6970(4).
- GLOBALS.md 0x6c4ba0 step ctr; sibling handlers confirm family shape.

## Remaining uncertainty
- Which op latched 0x14; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fc730.c`  — untouched decompiler output.
