# 0x005fc7c0 reply_handler_state11

| field | value |
|---|---|
| Original address | 0x005fc7c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fc7c0 |
| Resolved name | reply_ack_pending11_step_or_errctx_dialog14 |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (registered as a reply/completion callback)
**Callees:** FUN_005be9a0 (reset error context @0x6c517c), FUN_005f8d00 (error-dialog dispatch)
**Referenced globals:** cRam006c4b90 (screen_id gate), cRam006c4fbb (pending_tag gate = 0x11), cRam006c4ba0 (screen_step), 0x6c517c (error/dialog context)
**Referenced strings:** —
**Referenced opcodes:** — (tag 0x11 = pending ENTER per lobby_state_block)
**State vars:** cRam006c4fbb (==0x11 gate)

## Behavioral explanation
Reply/ACK handler for the op that latched pending-tag **0x11**. Per lobby_state_block.md, tag 0x11 =
"pending ENTER", so this is the ACK path for the room-ENTER request. Gated on `screen_id != 6` and
`pending_tag == 0x11`; the tag is cleared up front. On OK (0x00) advances `screen_step`. On any
non-zero (error) status it first resets the error/dialog context at 0x6c517c (FUN_005be9a0) and then
raises error dialog **0x14** (FUN_005f8d00).

## Input / output
- `param_1` : `u8* replyBody` — byte 0 status (0x00 OK / nonzero error).
- returns `void`.

## Side effects
- `pending_tag` (0x6c4fbb) := 0 (cleared before branch).
- OK: `screen_step` (0x6c4ba0) += 1.
- error: FUN_005be9a0(0x6c517c) resets dialog/err buffer, then FUN_005f8d00(0x14) posts dialog 0x14.

## Important branches
- `screen_id == 6` OR `pending_tag != 0x11` → no-op.
- clear tag; then `status == 0x00` → step++.
- `status != 0x00` → error: reset err-ctx + dialog 0x14. (Unlike fc360/fc520 this treats *any*
  nonzero, not only 0xff, as error, because the tag is cleared before the branch.)

## Constants & flags
- `pending_tag == 0x11` = ENTER (lobby_state_block.md). `screen_id 6` = in-game. dialog 0x14.
- 0x6c517c = error/dialog redraw context buffer (GLOBALS: "err ctx / dialog redraw buffer").

## Corrected reconstruction
```c
void reply_ack_pending11_enter(const uint8_t *replyBody)
{
    if (g_screen_id == SCREEN_INGAME /*6*/) return;
    if (g_pending_tag != PENDING_ENTER /*0x11*/) return;

    uint8_t status = replyBody[0];
    g_pending_tag = 0;                 // cleared up-front
    if (status == REPLY_OK /*0x00*/) {
        g_screen_step += 1;            // advance SM
    } else {
        reset_error_context(&g_errctx_6c517c);  // FUN_005be9a0
        show_error_dialog(0x14);                 // FUN_005f8d00
    }
}
```

## Evidence
- `sources/overlays/overlay-3dat-decompile/FUN_005fc7c0.c` — CFG (tag cleared before branch; nonzero
  → errctx reset + dialog 0x14).
- lobby_state_block.md: pending_tag 0x11 = enter. GLOBALS.md 0x6c517c err ctx.

## Remaining uncertainty
- Exact wire op that this ACKs (op06 enter vs a transport enter) not proven here; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fc7c0.c`  — untouched decompiler output.
