# 0x001c3420 rate_clamp_max

| field | value |
|---|---|
| Original address | 0x001c3420 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3420 |
| Resolved name | conn_raise_watermark |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c2da0, FUN_001c4070, FUN_001c9810, FUN_001c9850, FUN_001c9b00 (SN@P transport paths)
**Callees:** —
**Referenced globals:** 0x35ccb3 (u8 clamp-disable / override flag); conn+0xe0 (s32 watermark field)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam0035ccb3

## Behavioral explanation
Monotonically raises a per-connection watermark field at `conn+0xe0` toward `param_2`, never
lowering it, and only when the global override flag `0x35ccb3` is clear. Concretely: if the override
is off **and** the incoming value `param_2` is greater than the stored watermark, the watermark is
updated to `param_2`; otherwise it is left unchanged. This is the classic "high-water mark" update
used across the SN@P transport (five call sites in the reliable-send / windowing paths) to track the
maximum of some running quantity — most plausibly a highest-seen sequence number or send-window
bound on the connection object (`conn+0xe0`). The override flag `0x35ccb3`, when set, freezes the
watermark (a global disable of the raise, e.g. during teardown or a test mode).

The name was refined from `rate_clamp_max` to `conn_raise_watermark`: it does not clamp a value down
to a max — it raises a stored max up to a new floor. "Clamp" was misleading.

## Input / output
- `param_1` (`Conn *conn`) — connection object; watermark at `+0xe0`.
- `param_2` (`s32`) — candidate new watermark.
- No return (void).

## Side effects
- Writes `conn->watermark (+0xe0) = param_2` **iff** `0x35ccb3 == 0` and `param_2 > conn->watermark`.

## Important branches
- `0x35ccb3 != 0` (override set) -> do nothing.
- `param_2 <= conn->watermark` -> do nothing (never lowers).
- `0x35ccb3 == 0 && param_2 > conn->watermark` -> raise watermark to `param_2`.

## Constants & flags
- `0x35ccb3` = watermark-raise DISABLE / override flag (0 = normal raise allowed, nonzero = frozen).
- `conn+0xe0` = per-connection monotonic watermark (highest-seen value; see snap_connection layout).

## Corrected reconstruction
```c
// Raise (never lower) the per-connection watermark, unless globally frozen.
void conn_raise_watermark(Conn *conn, s32 candidate) {
    if (g_watermark_frozen /* 0x35ccb3 */ == 0 &&
        candidate > conn->watermark /* +0xe0 */) {
        conn->watermark = candidate;
    }
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001c3420.c` —
  `if ((cRam0035ccb3 == '\0') && (*(int*)(param_1+0xe0) < param_2)) *(int*)(param_1+0xe0) = param_2;`.
- Five callers are SN@P transport functions (send/window bookkeeping), consistent with a seq/window
  high-water mark on the connection object.
- Runtime-unvalidated.

## Remaining uncertainty
- Exact semantic of `conn+0xe0` (highest seq vs. window size vs. rate token) — inferred from the
  transport call sites; cross-check against `structure-layouts/snap_connection.md` to confirm the field.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3420.c`  — untouched decompiler output.
