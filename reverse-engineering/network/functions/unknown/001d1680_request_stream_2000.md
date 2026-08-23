# 0x001d1680 request_stream_2000

| field | value |
|---|---|
| Original address | 0x001d1680 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1680 |
| Resolved name | queue_stream_request_2000_session_if_online |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ccb80 (queue_stream_request)
**Referenced globals:** cRam00343577 (asset-source / offline-mode flag); uRam0034357a (session/room id)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00343577, uRam0034357a

## Behavioral explanation
Sibling of 0x1d1640: conditionally queues a background stream/asset request of kind `0x2000`, keyed by the current **session/room id** `uRam0034357a`. Gated on the asset-source flag `cRam00343577 == 0` (online/default source); suppressed when offline. Because the id is the session id (not a shift-packed index), this fetches per-session streamed content while a session is active.

## Input / output
- **Params:** none (id sourced from the global `uRam0034357a`).
- **Returns:** void.

## Side effects
- When online: `FUN_001ccb80(uRam0034357a, 0x2000)` — enqueues a session-keyed stream request. No effect when offline.

## Important branches
- **`cRam00343577 == 0`** (online) → issue the request.
- **`cRam00343577 != 0`** (offline) → do nothing.

## Constants & flags
- `0x2000` = stream/request **kind** selector for `FUN_001ccb80` (sibling 0x1d1640 uses `0x2a00`).
- `uRam0034357a` = current session/room id (the same id used to name per-session archives in 0x1cf150 / 0x1d1110).
- Offline-flag polarity inferred (see 0x1d1640 / 0x1d1110).

## Corrected reconstruction
```c
static uint32_t g_session_id;   // uRam0034357a

void queue_stream_request_2000_session_if_online(void)
{
    if (g_offline_mode == 0)                       // online only
        queue_stream_request(g_session_id, 0x2000);
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001d1680.c` — `if (cRam00343577 == '\0') FUN_001ccb80(uRam0034357a, 0x2000);`.
- Shares the offline gate + `FUN_001ccb80` primitive with 0x1d1640; session id `uRam0034357a` cross-references the per-session loaders 0x1cf150 / 0x1d1110.

## Remaining uncertainty
- Meaning of kind `0x2000`; `FUN_001ccb80` internals not traced.
- Offline-flag polarity inferred. Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1680.c`  — untouched decompiler output.
