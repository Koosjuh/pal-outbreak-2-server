# 0x001d5378 snap_alloc_buf_896

| field | value |
|---|---|
| Original address | 0x001d5378 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d5378 |
| Resolved name | snap_alloc_buf_896_noheader |
| Subsystem | packets |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (no direct static callers found; reachable indirectly / possibly a leftover)
**Callees:** FUN_001ec1f8 (pool_alloc)
**Referenced globals:** conn+0x520 reliable_pool
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x520 pool (via pool_alloc)

## Behavioral explanation
Allocates a 0x380 (896-byte) buffer straight from the send pool with **class 0** and **no** 0x10
header reserve (unlike `snap_alloc_pkt_buf`). Class 0 flips the sub-pool preference order in
`pool_alloc` (tries sub-pool +0x00 first instead of +0x28). Returns the raw block pointer (or 0). It
does not check `pool_alloc`'s return code — it just returns whatever landed in the out-slot (0 on
failure, since `pool_alloc` nulls it first). 0x380 is the recurring maximum reliable-payload size.

## Input / output
- `param_1` (`snap_connection *conn`) — session; `conn+0x520` pool root.
- **Returns** `void *` block (0 on failure). Return code of `pool_alloc` is discarded.

## Side effects
- `pool_alloc` bumps counters/watermarks on the chosen sub-pool; may latch the disable bit.
- No header reserve, no free path.

## Important branches
- None. The success/failure distinction is implicit in the returned pointer (0 = failed).

## Constants & flags
- `0x380` (896) — allocation size (max reliable payload; see the 001d72a8 clamp referenced in FACTS).
- `pool_alloc` args `(class=0, flag=1)` — class 0 prefers sub-pool +0x00; flag 1 honors the latch bit.

## Corrected reconstruction
```c
void *snap_alloc_buf_896_noheader(snap_connection *conn)
{
    void *buf;
    pool_alloc(conn->reliable_pool /*+0x520*/, &buf, 0x380, /*class=*/0, /*flag=*/1);
    return buf;   // 0 on failure (pool_alloc nulls the out-slot); no header reserved
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001d5378.c`.
- `FUN_001ec1f8` (read) confirms the (pool, &out, size, class, flag) signature and that `*out` is nulled before any attempt; class param selects sub-pool order.
- Contrast with `snap_alloc_pkt_buf` (class 1 + 0x10 reserve) fixes the "no header" reading.
- Runtime-unvalidated.

## Remaining uncertainty
- No static callers → purpose (unreliable/bulk staging buffer?) inferred from the class-0/no-header shape only; may be dead code.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d5378.c`  — untouched decompiler output.
