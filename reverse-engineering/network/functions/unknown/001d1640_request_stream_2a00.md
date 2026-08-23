# 0x001d1640 request_stream_2a00

| field | value |
|---|---|
| Original address | 0x001d1640 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1640 |
| Resolved name | queue_stream_request_2a00_if_online |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ccb80 (queue_stream_request)
**Referenced globals:** cRam00343577 (asset-source / offline-mode flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00343577

## Behavioral explanation
Conditionally queues a background stream/asset request of kind `0x2a00`, keyed by an index derived from `param_1`. It is gated on the asset-source flag `cRam00343577` being `0` (online/default source): when set (offline/HDD-only) the request is suppressed. The index is packed into the high 16 bits (`param_1 << 16`), i.e. the request id is `param_1` in the upper half with a zero low half — the low half is presumably a sub-id the stream engine fills or ignores.

## Input / output
- **Params:** `param_1` = stream index (placed in the high 16 bits of the request id).
- **Returns:** void.

## Side effects
- When online: `FUN_001ccb80(param_1 << 16, 0x2a00)` — enqueues a stream request. No effect when offline.

## Important branches
- **`cRam00343577 == 0`** (online) → issue the request.
- **`cRam00343577 != 0`** (offline) → do nothing (the asset is unavailable/unnecessary from the local source).

## Constants & flags
- `0x2a00` = stream/request **kind** selector for `FUN_001ccb80` (sibling 0x1d1680 uses kind `0x2000`).
- `<< 0x10` = pack `param_1` into the high 16 bits of the request id.
- `cRam00343577`: 0 = online/default source, non-0 = offline (polarity per GLOBALS "offline-mode"; consistent with 0x1d1110's branch) [inferred].

## Corrected reconstruction
```c
extern void queue_stream_request(uint32_t id, int kind); // FUN_001ccb80
static uint8_t g_offline_mode;                            // cRam00343577

void queue_stream_request_2a00_if_online(int index)
{
    if (g_offline_mode == 0)                              // online only
        queue_stream_request((uint32_t)index << 16, 0x2a00);
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001d1640.c` — `if (cRam00343577 == '\0') FUN_001ccb80(param_1 << 0x10, 0x2a00);`.
- Sibling 0x1d1680 shares the identical offline gate and `FUN_001ccb80` call with kind 0x2000.

## Remaining uncertainty
- Meaning of kind `0x2a00` and the low-16 sub-id; `FUN_001ccb80` internals (audio stream vs generic asset DMA) not traced here.
- Offline-flag polarity inferred. Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1640.c`  — untouched decompiler output.
