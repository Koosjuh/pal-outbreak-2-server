# 0x005e9910 chat_reset_mode_0x17f

| field | value |
|---|---|
| Original address | 0x005e9910 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9910 |
| Resolved name | chat_input_cancel_commit |
| Subsystem | chat |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (dispatched via a UI/menu callback table, not a direct call)
**Callees:** FUN_005eef70
**Referenced globals:** iRam007012a0 (chat-UI context base); ctx+0x17f (input-mode byte)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x17f (chat input mode)

## Behavioral explanation
A chat text-entry dismissal handler. It clears the input-mode byte at `ctx+0x17f`
(the on-screen-keyboard / message-compose state selector) back to 0 (idle), then hands the
current entry argument to `FUN_005eef70` for follow-up processing (the shared "apply/close
the compose widget" routine also used by the trimmed-commit path `chat_apply_trimmed_msg`
0x5e9a10 and the mode-set siblings 0x9940/0x99c0). This is the "cancel without trimming"
variant: unlike 0x5e9a10 it does NOT strip trailing spaces from the buffer before applying.

## Input / output
- `param_1` — unused here (present in the callback ABI; likely the widget/`this` handle).
- `param_2` — pointer to the pending input record forwarded to `FUN_005eef70`. [inferred: char* / widget-state*]
- returns `0` (undefined8) — success/continue sentinel for the callback dispatcher.

## Side effects
- Writes `ctx+0x17f = 0` (chat compose mode -> idle).
- Calls `FUN_005eef70(param_2)` (commit/close the compose widget). No packets, no ring mutation here.

## Important branches
None — straight-line. (Contrast the sibling 0x5e9a10 which loops to right-trim.)

## Constants & flags
- `ctx+0x17f` — chat input-mode byte. `0` = idle/closed. Written 0 by this fn and by
  `chat_apply_trimmed_msg` (0x5e9a10); set non-zero by the compose-open siblings. [inferred name]

## Corrected reconstruction
```c
// chat compose widget: cancel/close without trimming, then apply.
u64 chat_input_cancel_commit(void *widget /*param_1, unused*/, void *entry /*param_2*/)
{
    ChatUiCtx *ctx = (ChatUiCtx *)iRam007012a0;   // [inferred] chat-UI context base
    ctx->input_mode = 0;                          // ctx+0x17f -> idle
    FUN_005eef70(entry);                          // shared apply/close compose widget
    return 0;
}
```

## Evidence
- Raw: `FUN_005e9910.c` — `*(u8*)(iRam007012a0+0x17f)=0; FUN_005eef70(param_2); return 0;`.
- `ctx+0x17f` is the same byte cleared by 0x5e9a10 (`chat_apply_trimmed_msg`) after its trim
  loop, tying the two into one compose-widget state machine.
- No callers in the static graph => reached through a UI callback pointer table (matches the
  menu-driven chat compose flow). Runtime-unvalidated.

## Remaining uncertainty
- Exact type/semantics of `param_2` and what `FUN_005eef70` finally does (commit vs. close) are
  not decoded here. `param_1` role is unconfirmed. Confidence capped at Medium (no runtime trace).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9910.c`  — untouched decompiler output.
