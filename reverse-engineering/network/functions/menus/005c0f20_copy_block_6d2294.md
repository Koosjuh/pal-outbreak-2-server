# 0x005c0f20 copy_block_6d2294

| field | value |
|---|---|
| Original address | 0x005c0f20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0f20 |
| Resolved name | snapshot_area_data_block (copy_block_6d2294) |
| Subsystem | menus |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f9280, FUN_005fa190, FUN_005fe8d0, FUN_0062de90 (same room create/enter UI actions as the SM arms)
**Callees:** —
**Referenced globals:** 0x6d2294 (`0x294a3`-byte area/scenario data blob; its head bytes 0x6d2294/0x6d2295/0x6d2296 are read by the create pump)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Bulk byte copy of the large static block at **0x6d2294** (length **0x294a3 = 169,123 bytes**) into
the caller-supplied buffer `param_2`. The block begins one word after the area index at 0x6d2158;
its leading bytes (`cRam006d2294` present-flag, `cRam006d2295`, `bRam006d2296` count) are consumed by
the create pump `FUN_005c3490` and enter pump, so this is the **area/scenario descriptor blob**. The
four callers are the same room create/enter UI actions that arm the SMs, so this snapshots the
area-data block into a working buffer for the pending create/enter operation.

## Input / output
- **Params:** `param_1` — unused (ignored); `param_2` — destination buffer (must be ≥ 0x294a3 bytes).
  **Returns:** `undefined8` 0.
- **Reads:** 0x6d2294 .. 0x6d2294+0x294a3.

## Side effects
- Writes 0x294a3 bytes into `*param_2`. Reads only from the static source; no global mutation.

## Important branches
- None — single byte-copy loop.

## Constants & flags
- `0x294a3` (169,123) — copy length.
- 0x6d2294 — area/scenario data blob base; head bytes are the present-flag / count fields the pumps
  read.

## Corrected reconstruction
```c
// Snapshot the ~165 KB area/scenario data blob at 0x6d2294 into the caller's buffer.
u64 snapshot_area_data_block(void *unused /*param_1*/, u8 *dst /*param_2*/)
{
    const u8 *src = (const u8 *)0x6d2294;
    for (int n = 0x294a3; n > 0; --n)   // 169,123 bytes
        *dst++ = *src++;
    return 0;
}
```

## Evidence
- Raw decompile: byte loop, `iVar1 = 0x294a3`, source 0x6d2294, dest param_2; param_1 unreferenced.
- Head bytes of 0x6d2294 read by create pump `FUN_005c3490` (`bRam006d2296`, `cRam006d2295`,
  `cRam006d2294`), tying the blob to area/scenario descriptor use.

## Remaining uncertainty
- Internal structure of the 165 KB blob is unmapped (resource/scenario tables). Whether callers copy
  it for backup vs transmission is unconfirmed. Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0f20.c`  — untouched decompiler output.
