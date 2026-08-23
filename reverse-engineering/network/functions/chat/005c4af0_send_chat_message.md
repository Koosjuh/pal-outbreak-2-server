# 0x005c4af0 send_chat_message

| field | value |
|---|---|
| Original address | 0x005c4af0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4af0 |
| Resolved name | send_chat_message_and_echo |
| Subsystem | chat |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f4be0 (chat-input / send UI)
**Callees:** FUN_005c4bd0 (build_send_chat_datagram), FUN_0010a050 (strlen), FUN_001069a8 (memcpy), FUN_0010a4f0 (memcpy), FUN_005bdf90 (post UI event)
**Referenced globals:** 0x6fc05a(local echo block, 0x128); 0x6fc17e(sender type byte); 0x6fc06a(echo name); 0x6fc07e(echo text); 0x6febb8(local username)
**Referenced strings:** —
**Referenced opcodes:** — (drives op0f via build_send_chat_datagram)

## Behavioral explanation
The **chat "send" entry point** invoked from the chat-input UI. It does two things: (1) transmits the
message over the wire via `build_send_chat_datagram(type, text, len)` (which emits op0f), then (2)
builds a **local echo** so the sender sees their own line immediately without waiting for a
round-trip: it clears the 0x128 echo block at 0x6fc05a, stamps the sender type
(`0x6fc17e = type`), copies the local username (0x6febb8) into 0x6fc06a and the message text into
0x6fc07e, and posts UI event 5 (`FUN_005bdf90(5, 0)`) to append the echoed line to the display.
The three call args are tail-passed unchanged into `build_send_chat_datagram` (register pass-through).

## Input / output
- `param_1` (`u8 type`) — message/sender type byte (also stored to the echo block at 0x6fc17e).
- `param_2` (`void *text`) — message text.
- `param_3` (`u16 len`) — text length.
- Returns void.

## Side effects
- Sends the datagram over the wire (`build_send_chat_datagram`).
- `memset(0x6fc05a, 0, 0x128)`; `0x6fc17e = type`; copies username → 0x6fc06a, text → 0x6fc07e.
- Posts UI event 5 (`FUN_005bdf90(5, 0)`).

## Important branches
- None — straight-line send-then-echo.

## Constants & flags
- `0x128` (296) — local echo block size at 0x6fc05a.
- `5` — UI event id posted after building the echo.
- Echo layout: type@0x6fc17e, name@0x6fc06a, text@0x6fc07e.

## Corrected reconstruction
```c
// Send a chat line and locally echo it into the on-screen chat block.
void send_chat_message_and_echo(u8 type, const void *text, u16 len) {
    build_send_chat_datagram(type, text, len);          // FUN_005c4bd0 → op0f on the wire

    memset((void*)0x6fc05a, 0, 0x128);                  // local echo block
    *(u8*)0x6fc17e = type;                              // sender/type
    u32 nlen = strlen((char*)0x6febb8);                 // local username
    memcpy((void*)0x6fc06a, (void*)0x6febb8, nlen);     // echo name
    memcpy((void*)0x6fc07e, text, len);                 // echo text
    post_ui_event(5, 0);                                // FUN_005bdf90
}
```

## Evidence
- Raw order: `FUN_005c4bd0(); memset(0x6fc05a,0,0x128); uRam006fc17e=param_1; uVar1=strlen(0x6febb8); memcpy(0x6fc06a,0x6febb8,uVar1); memcpy(0x6fc07e,param_2,param_3); FUN_005bdf90(5,0);`.
- `FUN_005c4bd0` (build_send_chat_datagram) reconstructed = the op0f wire send; args pass through in registers.
- 0x6febb8 = local username (also read by build_send_chat_datagram) ⇒ echo name source.
- Runtime-unvalidated.

## Remaining uncertainty
- Exact meaning of the `type` byte (whisper vs. broadcast vs. system) and the internal layout of the 0x128 echo block beyond the three written fields.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4af0.c`  — untouched decompiler output.
