# 0x005fc360 reply_handler_state0b

| field | value |
|---|---|
| Original address | 0x005fc360 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fc360 |
| Resolved name | reply_ack_pending0b_step_or_dialog48 |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (registered as a reply/completion callback; not statically called)
**Callees:** FUN_005f8d00 (error-dialog dispatch)
**Referenced globals:** cRam006c4b90 (screen_id gate), cRam006c4fbb (pending_tag gate = 0x0b), cRam006c4ba0 (screen_step SM counter)
**Referenced strings:** —
**Referenced opcodes:** — (reply body; op inferred by the pending op that latched tag 0x0b)
**State vars:** cRam006c4fbb (==0x0b gate)

## Behavioral explanation
One member of a six-way family of room-flow reply/ACK handlers (fc360/fc520/fc610/fc6b0/fc730/fc7c0).
Each is armed when the room state machine sends a request and stamps a *pending-op tag* into
`pending_tag` (0x6c4fbb); when the matching reply arrives, the transport delivers the reply body to
this callback. `param_1[0]` low byte is the reply **status**: `0x00`=OK, `0xff`(-1)=error/reject.

This variant handles the operation that latched tag **0x0b**. It is gated twice: the current screen
must not be the in-game screen (`screen_id != 6`) and the pending tag must still be `0x0b` (i.e. this
reply is the one we are waiting on). On OK it clears the pending tag and advances the SM step counter
`screen_step` (0x6c4ba0) by 1 — the SM's per-frame tick then proceeds to the next step. On explicit
error (`-1`) it clears the tag and raises error dialog **0x48** via FUN_005f8d00.

## Input / output
- `param_1` : `u8* replyBody` — pointer to the reply payload; only byte 0 (status) is read.
- returns `void`.

## Side effects
- Writes `pending_tag` (0x6c4fbb) := 0 (clears the wait) on any handled reply.
- On OK: `screen_step` (0x6c4ba0) += 1.
- On error: calls FUN_005f8d00(0x48) → posts error dialog id 0x48.

## Important branches
- `screen_id == 6` OR `pending_tag != 0x0b` → do nothing (reply not for us / wrong screen).
- `status == 0x00` → clear tag, step++.
- `status == 0xff` → clear tag, dialog 0x48.
- any other status → tag left set, no action (only 0x00 and 0xff are handled — distinct from the
  fc610/fc6b0/fc730 siblings which clear the tag up-front and treat all nonzero as error).

## Constants & flags
- `screen_id` sentinel `6` = in-game/active-play screen (reply suppressed there). [inferred from the
  shared `!= 6` guard across the whole family]
- `pending_tag == 0x0b` = this handler's op selector.
- `status`: `0x00`=OK, `0xff`=error. Dialog id `0x48`.

## Corrected reconstruction
```c
// Reply/ACK callback for the room-flow op that latched pending_tag==0x0B.
// param_1 -> reply body; byte[0] = status (0=OK, 0xFF=error).
void reply_ack_pending0b(const uint8_t *replyBody)
{
    if (g_screen_id == SCREEN_INGAME /*6*/) return;   // cRam006c4b90
    if (g_pending_tag != PENDING_0B /*0x0b*/) return; // cRam006c4fbb

    uint8_t status = replyBody[0];
    if (status == REPLY_OK /*0x00*/) {
        g_pending_tag = 0;             // cRam006c4fbb
        g_screen_step += 1;            // cRam006c4ba0 : advance SM
    }
    else if (status == REPLY_ERR /*0xff*/) {
        g_pending_tag = 0;
        show_error_dialog(0x48);       // FUN_005f8d00
    }
    // any other status: leave pending_tag set, keep waiting
}
```

## Evidence
- `sources/overlays/overlay-3dat-decompile/FUN_005fc360.c` — exact control flow (two guards, status
  switch on 0x00 / -1).
- GLOBALS.md: 0x6c4b90 screen_id, 0x6c4ba0 step ctr, 0x6c4fbb pending state; lobby_state_block.md
  (pending_tag = 0x11 enter / 0x17 join family).
- Sibling handlers fc520/fc610/fc6b0/fc730/fc7c0 confirm the family shape.

## Remaining uncertainty
- Which concrete request op latches tag 0x0b (dialog 0x48 identity) is not proven from this fn alone;
  needs the SM sender (0x6c4ba0 writers) trace. Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fc360.c`  — untouched decompiler output.
