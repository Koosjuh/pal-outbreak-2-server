# 0x005adbe0 async_reply_handler_tag5

| field | value |
|---|---|
| Original address | 0x005adbe0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005adbe0 |
| Resolved name | async_reply_handler_tag5 |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (invoked by address; registered as a reply cb, tag 5)
**Callees:** FUN_005b9110 (message box), FUN_005f74d0 (success/advance)
**Referenced globals:** `0x6c4fbb` pending_tag; `0x6c4b90` screen_id; `0x6c4b9e` lobby_sm; `0x6c4b9f` screen_major; `0x6c4ba0`/`0x6c4ba1` step
**Referenced strings:** —
**Referenced opcodes:** — (consumes an async op reply)
**State vars:** `cRam006c4fbb` pending_tag; `cRam006c4b90` screen_id

## Behavioral explanation
Sibling of FUN_005ad9f0 but for the pending async op tagged **5**. Runs only if `screen_id != 6` and
`pending_tag == 5`. Reads reply status byte `[0]`, clears the tag, and on OK (`0`) advances via FUN_005f74d0;
on error it **rewinds the room navigation state** — zeroing `lobby_sm (0x6c4b9e)`, `screen_major (0x6c4b9f)`,
`0x6c4ba0`, `0x6c4ba1` — and pops message box `0x4c` (FUN_005b9110). The key difference from tag-1: the error
path resets `lobby_sm` too (a deeper nav rewind) rather than jumping to the error screen.

## Input / output
- `param_1` : reply buffer; byte `[0]` = status (0 = OK).
- returns `void`.

## Side effects
- `pending_tag (0x6c4fbb) = 0`.
- OK → FUN_005f74d0. Error → `0x6c4b9e = 0x6c4b9f = 0x6c4ba0 = 0x6c4ba1 = 0`; message box `0x4c` (FUN_005b9110).

## Important branches
- Guard `screen_id == 6 || pending_tag != 5` → no-op.
- status `== 0` → success; `!= 0` → nav rewind + message `0x4c`.

## Constants & flags
- pending tag value `5` (this handler's tag).
- message id `0x4c` (FUN_005b9110) = the standard error/notice box (same id used by the retry widgets).

## Corrected reconstruction
```c
void async_reply_handler_tag5(u8 *reply /*param_1*/)
{
    if (g_screen_id /*0x6c4b90*/ == 6 || g_pending_tag /*0x6c4fbb*/ != 5)
        return;

    u8 status = reply[0];
    g_pending_tag = 0;

    if (status == 0) {
        on_room_op_success();                     // FUN_005f74d0
    } else {
        g_lobby_sm     /*0x6c4b9e*/ = 0;          // rewind room nav
        g_screen_major /*0x6c4b9f*/ = 0;
        *(u8*)0x6c4ba0 = 0; *(u8*)0x6c4ba1 = 0;
        show_message_box(0x4c);                    // FUN_005b9110
    }
}
```

## Evidence
- Raw guard `cRam006c4b90 != 6 && cRam006c4fbb == 5`; error path clears 0x6c4b9e/9f/ba0/ba1 and calls
  FUN_005b9110(0x4c). Direct structural sibling of FUN_005ad9f0. Runtime-unvalidated.

## Remaining uncertainty
- Tag-5's originating op (which room submit registers tag 5) not pinned; prior note "registered in ad530
  case 2" is unverified against the current source set.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005adbe0.c`  — untouched decompiler output.
