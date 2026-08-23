# 0x005e99c0 chat_parse_msg_mode3

| field | value |
|---|---|
| Original address | 0x005e99c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e99c0 |
| Resolved name | chat_ingest_msg_mode3_dispatch |
| Subsystem | chat |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0 (decode/copy message text into a bounded buffer), FUN_005ecf20 (mode-3 consumer/dispatch)
**Referenced globals:** 0x7012a0(ptr → chat cfg block); cfg+0x17f(message mode)
**Referenced strings:** —
**Referenced opcodes:** —

## Behavioral explanation
The **mode-3 sibling** of `chat_ingest_msg_hash_prefix` (0x5e9940). It decodes the inbound message
into a 0x100-byte buffer via the same `FUN_005ec1b0`, unconditionally sets `cfg->msg_mode = 3`, and —
instead of stashing the text into a system/normal line buffer — hands the decoded text to
`FUN_005ecf20` for immediate consumption/dispatch. `msg_mode = 3` is the special/command message
class (distinct from `1` system-`#` and `2` normal), so this path routes structured messages to a
handler rather than the plain display buffers.

## Input / output
- `param_1` — opaque message source handle passed to `FUN_005ec1b0`.
- Returns `0` always.

## Side effects
- `cfg->msg_mode (cfg+0x17f) = 3`.
- Calls `FUN_005ecf20(decoded_text)` (mode-3 consumer).

## Important branches
- None — straight-line: decode → set mode 3 → dispatch.

## Constants & flags
- `msg_mode = 3` — special/command message class (vs 1 system, 2 normal).
- `0x100` (256) — decode buffer size.

## Corrected reconstruction
```c
int chat_ingest_msg_mode3_dispatch(void *msg) {
    char text[0x110];
    decode_message(msg, text, 0x100);                    // FUN_005ec1b0
    chat_cfg *cfg = *(chat_cfg**)0x7012a0;
    cfg->msg_mode /*+0x17f*/ = MSG_MODE_SPECIAL;         // 3
    dispatch_mode3_message(text);                        // FUN_005ecf20
    return 0;
}
```

## Evidence
- Raw: `FUN_005ec1b0(param_1, auStack_110, 0x100); *(iRam007012a0+0x17f)=3; FUN_005ecf20(auStack_110);`.
- Shares `FUN_005ec1b0` + `cfg+0x17f` with 0x5e9940 ⇒ same message pipeline, mode enum value 3.
- Runtime-unvalidated.

## Remaining uncertainty
- No caller located; `FUN_005ecf20` (the mode-3 consumer) is not decoded, so what a "special" message triggers (command? private msg? server directive?) is unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e99c0.c`  — untouched decompiler output.
