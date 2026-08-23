# 0x005e9940 chat_parse_msg_by_prefix

| field | value |
|---|---|
| Original address | 0x005e9940 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9940 |
| Resolved name | chat_ingest_msg_hash_prefix |
| Subsystem | chat |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0 (decode/copy message text into a bounded buffer), FUN_00109eb8 (strcpy)
**Referenced globals:** 0x7012a0(ptr → chat cfg block); cfg+0x17f(message mode); cfg+0x8f6(system-line buffer); cfg+0x9f6(normal-line buffer)
**Referenced strings:** `'#'` (system-message prefix)
**Referenced opcodes:** —

## Behavioral explanation
One of a family of three message-ingest routines (this one, `chat_parse_msg_mode3` @0x5e99c0, and the
implied mode-2 path here). It decodes the incoming message into a 0x100-byte local buffer via
`FUN_005ec1b0`, then classifies by first character: a leading `'#'` marks a **system message** — it
sets `cfg->msg_mode = 1` and copies the text into the system-line buffer (`cfg+0x8f6`); anything else
is a **normal message** — `cfg->msg_mode = 2`, copied into the normal-line buffer (`cfg+0x9f6`). The
cfg block is reached indirectly through the pointer at 0x7012a0. `msg_mode` is later read by the
renderer to pick which buffer/style to draw.

## Input / output
- `param_1` — opaque message source handle passed to `FUN_005ec1b0` (the raw inbound message).
- Returns `0` always.

## Side effects
- Writes `cfg->msg_mode (cfg+0x17f)` = 1 or 2.
- `strcpy` into `cfg+0x8f6` (system) or `cfg+0x9f6` (normal).

## Important branches
- `decoded[0] == '#'` → `msg_mode = 1`, strcpy to `cfg+0x8f6` (system line).
- else → `msg_mode = 2`, strcpy to `cfg+0x9f6` (normal line).

## Constants & flags
- `'#'` (0x23) — system-message prefix.
- `msg_mode`: `1` = system (`#`), `2` = normal (this fn), `3` = special (sibling 0x5e99c0).
- `0x100` (256) — decode buffer size / max message length.
- Buffer offsets: system `+0x8f6`, normal `+0x9f6` (0x100 apart).

## Corrected reconstruction
```c
// cfg block reached via *(void**)0x7012a0.
enum { MSG_MODE_SYSTEM=1, MSG_MODE_NORMAL=2, MSG_MODE_SPECIAL=3 };

int chat_ingest_msg_hash_prefix(void *msg) {
    char text[0x110];
    decode_message(msg, text, 0x100);                    // FUN_005ec1b0
    chat_cfg *cfg = *(chat_cfg**)0x7012a0;
    if (text[0] == '#') {                                // system line
        cfg->msg_mode /*+0x17f*/ = MSG_MODE_SYSTEM;
        strcpy(&cfg[0x8f6], text);                       // FUN_00109eb8
    } else {                                             // normal line
        cfg->msg_mode = MSG_MODE_NORMAL;
        strcpy(&cfg[0x9f6], text);
    }
    return 0;
}
```

## Evidence
- Raw: `FUN_005ec1b0(param_1, acStack_110, 0x100); if (acStack_110[0]=='#') { *(iRam007012a0+0x17f)=1; strcpy(iRam007012a0+0x8f6, ...);} else { *( +0x17f)=2; strcpy(+0x9f6, ...);}`.
- `iRam007012a0` is a dereferenced pointer (loaded value used as base) ⇒ cfg block pointer at 0x7012a0.
- Sibling 0x5e99c0 sets the same `+0x17f` to 3 ⇒ shared msg_mode enum.
- Runtime-unvalidated.

## Remaining uncertainty
- No caller located; the exact `FUN_005ec1b0` decode (decrypt vs. plain copy, and whether it strips a header) is not traced. The renderer that consumes `msg_mode` + the two buffers is not linked here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9940.c`  — untouched decompiler output.
