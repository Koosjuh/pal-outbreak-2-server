# 0x005ad9f0 async_reply_handler_tag1

| field | value |
|---|---|
| Original address | 0x005ad9f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ad9f0 |
| Resolved name | async_reply_handler_tag1 |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (invoked by address; registered as reply cb by FUN_005ad680 case3/4 via FUN_005bfa70)
**Callees:** FUN_005be9a0 (error dialog), FUN_005f74d0 (success/advance)
**Referenced globals:** `0x6c4fbb` pending_tag; `0x6c4b90` screen_id; `0x6c4b9f` screen_major; `0x6c4ba0`/`0x6c4ba1`/`0x6c4ba2` step; error descriptor `0x6c517c`
**Referenced strings:** — (0x6c517c is the error-message descriptor)
**Referenced opcodes:** — (consumes an async op reply)
**State vars:** `cRam006c4fbb` pending_tag; `cRam006c4b90` screen_id

## Behavioral explanation
Reply/completion callback for the pending async op tagged **1** (registered by room_select_submit_sm). It runs
only if the current screen isn't the error screen (`screen_id != 6`) and this tag is still pending
(`pending_tag == 1`). It reads the reply status byte (`param_1[0]`), clears the pending tag, and branches:
status `0` (OK) → success path FUN_005f74d0 (advances the flow); non-zero → forces `screen_major = 6`, zeroes
the step bytes, and pops an error dialog (FUN_005be9a0) using the descriptor at `0x6c517c`.

## Input / output
- `param_1` : pointer to the reply buffer; byte `[0]` is the status/result code (0 = OK).
- returns `void`.

## Side effects
- `pending_tag (0x6c4fbb) = 0` (consumes the pending op).
- OK: calls FUN_005f74d0 (advance).
- Error: `screen_major (0x6c4b9f) = 6`; `0x6c4ba0 = 0x6c4ba1 = 0x6c4ba2 = 0`; opens error dialog on `0x6c517c`.

## Important branches
- Guard `screen_id == 6 || pending_tag != 1` → do nothing (stale/duplicate reply, or already in error screen).
- status byte `== 0` → success; `!= 0` → error path (screen_major=6 + dialog).

## Constants & flags
- pending tag value `1` (this handler's tag; sibling FUN_005adbe0 handles tag `5`).
- `screen_major = 6` = error/retry screen major state.
- `0x6c517c` = error-message descriptor passed to FUN_005be9a0.

## Corrected reconstruction
```c
void async_reply_handler_tag1(u8 *reply /*param_1*/)
{
    if (g_screen_id /*0x6c4b90*/ == 6 || g_pending_tag /*0x6c4fbb*/ != 1)
        return;                                   // stale / already in error screen

    u8 status = reply[0];
    g_pending_tag = 0;                            // consume

    if (status == 0) {
        on_room_op_success();                     // FUN_005f74d0
    } else {
        g_screen_major /*0x6c4b9f*/ = 6;          // → error screen
        *(u8*)0x6c4ba0 = 0; *(u8*)0x6c4ba1 = 0; *(u8*)0x6c4ba2 = 0;
        show_error_dialog((void*)0x6c517c);       // FUN_005be9a0
    }
}
```

## Evidence
- Raw guard `cRam006c4b90 != 6 && cRam006c4fbb == 1`; status read `(char)*param_1`; branch to FUN_005f74d0
  vs (screen_major=6 + FUN_005be9a0(0x6c517c)). Registration cross-ref: FUN_005ad680 case3/4. Runtime-unvalidated.

## Remaining uncertainty
- Which specific room op this reply corresponds to (enter vs create vs scenario submit) depends on what
  room_select_submit_sm submitted — not runtime-pinned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ad9f0.c`  — untouched decompiler output.
