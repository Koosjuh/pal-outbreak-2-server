# 0x005fc520 reply_handler_state0f

| field | value |
|---|---|
| Original address | 0x005fc520 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fc520 |
| Resolved name | reply_ack_pending0f_step_or_dialog48 |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (registered as a reply/completion callback)
**Callees:** FUN_005f8d00 (error-dialog dispatch)
**Referenced globals:** cRam006c4b90 (screen_id gate), cRam006c4fbb (pending_tag gate = 0x0f), cRam006c4ba0 (screen_step SM counter)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb (==0x0f gate)

## Behavioral explanation
Room-flow reply/ACK handler for the op that latched pending-tag **0x0f**. Byte-identical in structure
to fc360 (only the gate tag differs). Gated on `screen_id != 6` and `pending_tag == 0x0f`. On OK
status (0x00) clears the tag and advances `screen_step`; on explicit error (0xff) clears the tag and
raises error dialog **0x48**. See the family overview in `005fc360_reply_handler_state0b.md`.

## Input / output
- `param_1` : `u8* replyBody` — only byte 0 (status: 0x00 OK / 0xff error) is read.
- returns `void`.

## Side effects
- `pending_tag` (0x6c4fbb) := 0 on handled reply.
- OK: `screen_step` (0x6c4ba0) += 1.
- error: FUN_005f8d00(0x48) → error dialog 0x48.

## Important branches
- `screen_id == 6` OR `pending_tag != 0x0f` → no-op.
- `status == 0x00` → clear tag, step++.
- `status == 0xff` → clear tag, dialog 0x48.
- other status → tag left set (keep waiting).

## Constants & flags
- `pending_tag == 0x0f` selector; `screen_id 6` = in-game; `status` 0x00/0xff; dialog 0x48.

## Corrected reconstruction
```c
void reply_ack_pending0f(const uint8_t *replyBody)
{
    if (g_screen_id == SCREEN_INGAME /*6*/) return;
    if (g_pending_tag != PENDING_0F /*0x0f*/) return;

    uint8_t status = replyBody[0];
    if (status == REPLY_OK) {
        g_pending_tag = 0;
        g_screen_step += 1;
    } else if (status == REPLY_ERR /*0xff*/) {
        g_pending_tag = 0;
        show_error_dialog(0x48);   // FUN_005f8d00
    }
}
```

## Evidence
- `sources/overlays/overlay-3dat-decompile/FUN_005fc520.c` — identical CFG to fc360 with tag 0x0f.
- GLOBALS.md 0x6c4b90 / 0x6c4ba0 / 0x6c4fbb; lobby_state_block.md.

## Remaining uncertainty
- Concrete request op behind tag 0x0f unproven; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fc520.c`  — untouched decompiler output.
