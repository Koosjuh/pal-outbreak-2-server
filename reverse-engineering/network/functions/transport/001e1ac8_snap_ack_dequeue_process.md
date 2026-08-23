# 0x001e1ac8 snap_ack_dequeue_process

| field | value |
|---|---|
| Original address | 0x001e1ac8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e1ac8 |
| Resolved name | snap_ack_retire_packet |
| Subsystem | transport |
| Relevance | core |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d6988 (accept-gate)
**Callees:** FUN_001eb784 (list search by key + comparator), FUN_001ebbd0 (set flag), FUN_001eb4dc (unlink), FUN_001e19c4 (RTT/rate accounting), FUN_001ec9e0 (free)
**Referenced globals:** conn+0x60 send pool; conn+0x520 buffer pool
**Referenced strings:** —
**Referenced opcodes:** 0x60 (ack) — this consumes the ack
**State vars:** node flag 0x800 (acked/done); comparator 0x1edfd0

## Behavioral explanation
Retires a single in-flight reliable packet when its acknowledgement arrives. Given the acked sequence key (`param_3`), it searches the caller-supplied list (`param_2 + 8`, the in-flight pool) using `FUN_001eb784` with the seq comparator at `0x1edfd0`. If the packet isn't found there, it falls back to searching the send pool `conn+0x60`. When a matching node is found, it marks it `0x800` (acked), unlinks it, feeds the ack sample to the RTT/congestion accounting (`FUN_001e19c4(conn, node, param_4)`), and frees it back to `conn+0x520`. If the search errors or the key isn't present in either list, it returns without side effects.

## Input / output
- **param_1** (`snap_connection*` as `int`): connection.
- **param_2** (`int` list obj): primary search list (the in-flight pool, `conn+0x58`-class).
- **param_3** (`undefined4` ackKey): the acknowledged sequence number to match.
- **param_4** (`undefined4` sample): RTT/time sample passed to the accounting routine.
- **Return:** void (best-effort retire).

## Side effects
- Marks the matched node `0x800`, unlinks it from its list, and frees it to `conn+0x520`.
- Updates RTT/rate accounting via `FUN_001e19c4`.

## Important branches
- `FUN_001eb784(param_2+8, &node, cmp, key) < 0` (search error) → return (do nothing).
- `node == 0` (not in primary list) → search `conn+0x60`:
  - search `< 0` → return.
  - `node == 0` (still not found) → return.
  - else retarget the list to `conn+0x60`.
- Found → set `0x800`, unlink, account, free.

## Constants & flags
- Node flag `0x800` — acked / completed marker (same bit `snap_send_coalesce` uses for "coalesced/done").
- `0x1edfd0` — comparator function used to match a node by sequence key.
- `conn+0x520` — pool the retired node returns to.

## Corrected reconstruction
```c
// Retire the in-flight reliable packet whose seq == ackKey (ack received).
enum { F_ACKED = 0x800 };

void snap_ack_retire_packet(snap_connection *conn /*param_1*/, int list /*param_2*/,
                            u32 ackKey /*param_3*/, u32 sample /*param_4*/)
{
    void *node;
    int rc = pkt_find(list + 8, &node, (cmp_fn)0x1edfd0, ackKey);   // FUN_001eb784
    if (rc < 0) return;

    if (node == NULL) {                                            // not in-flight → try sendq
        rc = pkt_find(&conn->sendq /*+0x60*/ + 8, &node, (cmp_fn)0x1edfd0, ackKey);
        if (rc < 0 || node == NULL) return;
        list = conn->sendq_field /*+0x60*/;
    }

    pkt_setflag(node, F_ACKED);                                   // 0x800
    pkt_unlink(list + 8, node);                                   // FUN_001eb4dc
    FUN_001e19c4(conn, node, sample);                             // RTT / congestion update
    pkt_free(&conn->pool520 /*+0x520*/, node);                   // FUN_001ec9e0
}
```

## Evidence
- Two-stage search (primary list then `conn+0x60`) with the same comparator `0x1edfd0` ⇒ "find the packet this ack retires."
- Sets `0x800` then frees ⇒ completion/retire semantics; `FUN_001e19c4` on the ack path ⇒ RTT/rate sample (congestion control).
- Called from the accept-gate `FUN_001d6988`, which processes inbound acks.
- Runtime-unvalidated.

## Remaining uncertainty
- Whether `param_2` is always the in-flight pool (`conn+0x58`) or occasionally another list is inferred from the single caller; `param_4`'s exact units (tick delta vs. absolute) are not traced. `FUN_001e19c4` (accounting) is not decompiled here.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e1ac8.c`  — untouched decompiler output.
