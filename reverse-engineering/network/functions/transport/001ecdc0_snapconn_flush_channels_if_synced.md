# 0x001ecdc0 snapconn_flush_channels_if_synced

| field | value |
|---|---|
| Original address | 0x001ecdc0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ecdc0 |
| Resolved name | subpool_release_all_if_idle (aka snapconn_flush_channels_if_synced) |
| Subsystem | transport |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d46ec (session bring-up / teardown)
**Callees:** FUN_001eb2d4 (tier depth), FUN_001eb434 (dequeue node, -0x1b56 = empty), FUN_001ee024 (release one buffer's backing memory), FUN_001e2010 (release the pool header)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** pool fill counts +0x5c/+0x62/+0x68 (tier0/1/2 original fill from subpool_init)

## Behavioral explanation
Tears down / flushes the 3-tier buffer pool, but **only when no buffers are outstanding**. It first
checks that each tier's current free depth (`FUN_001eb2d4`) equals its original fill count
(+0x5c/+0x62/+0x68 as programmed by `subpool_init`) — i.e. every preallocated buffer has been returned.
If so, it dequeues every node from all three tiers (`FUN_001eb434` until the `-0x1b56` empty sentinel),
releasing each buffer's backing memory (`FUN_001ee024`), then releases the pool header (`FUN_001e2010`)
and returns 0. If any tier still has buffers in flight, it does nothing and returns `-7999` (busy). This
is the idle-gated release used at session end so that in-flight reliable buffers are never freed under
the transport.

The deeply nested decompiler output is a mechanical rendering of three sequential drain loops sharing the
`-0x1b56` "queue empty → advance to next tier" sentinel; there is no real nesting.

## Input / output
- **param_1** (int): the pool header (same object built by `subpool_init`; tiers at +0x00/+0x14/+0x28).
- **Returns** (int): `0` = released; `-7999` (0xffffe0c1) = not idle (buffers outstanding), nothing done;
  a nonzero `FUN_001eb434`/`FUN_001ee024` error is propagated if release fails mid-drain.

## Side effects
- On the idle path: empties all three tier free-lists, frees each buffer via `FUN_001ee024`, and frees
  the pool header via `FUN_001e2010`. The pool pointer held by the caller is dangling afterward.
- On the busy path: no state change.

## Important branches
- **Idle gate:** `depth(tier0)==+0x5c && depth(tier1)==+0x62 && depth(tier2)==+0x68`? No → return `-7999`.
- Drain tier0: `FUN_001eb434(pool,&buf)` until `-0x1b56`; each non-empty result `!=0` (hard error) →
  return it; each `0` → `FUN_001ee024(buf)`; if that returns nonzero → return it.
- Then drain tier1 (pool+0x14), then tier2 (pool+0x28), identically.
- All drained → `FUN_001e2010(pool)`, return 0.

## Constants & flags
- `-0x1b56` = per-tier "empty, advance" sentinel (same value used by `subpool_alloc`).
- `-7999` (0xffffe0c1) = "pool busy / not idle" — buffers still allocated somewhere.
- Idle test compares live depth to the +0x5c/+0x62/+0x68 fill counts set by `subpool_init`.

## Corrected reconstruction
```c
// Release the whole pool, but only if every buffer has been returned (idle).
int subpool_release_all_if_idle(subpool_t *p)
{
    // idle == all preallocated buffers are back on their free-lists
    if (list_depth(&p->tier0) != p->t0_fill /*+0x5c*/ ||
        list_depth(&p->tier1) != p->t1_fill /*+0x62*/ ||
        list_depth(&p->tier2) != p->t2_fill /*+0x68*/)
        return -7999;                                   // busy: outstanding buffers

    for (each tier T in {tier0, tier1, tier2}) {        // pool+0x00, +0x14, +0x28
        for (;;) {
            void *buf;
            int rc = list_dequeue(&T, &buf);            // FUN_001eb434
            if (rc == -0x1b56) break;                   // tier empty -> next tier
            if (rc != 0) return rc;                     // hard error
            rc = buffer_destroy(buf);                   // FUN_001ee024 (free backing mem)
            if (rc != 0) return rc;
        }
    }
    pool_header_free(p);                                // FUN_001e2010
    return 0;
}
```

## Evidence
- Idle test reads +0x5c/+0x62/+0x68 = the exact fill counters `subpool_init` writes after preallocating
  each tier; comparing to `FUN_001eb2d4` (live depth) proves "nothing outstanding".
- Same tier bases (+0x00/+0x14/+0x28) and `-0x1b56` empty sentinel as `subpool_alloc`/`subpool_free`.
- Paired with `subpool_init` under the same caller `FUN_001d46ec` = init/teardown pair.
- Confidence **High**; **Runtime validated: no**.

## Remaining uncertainty
Whether `FUN_001ee024` frees the buffer to the system heap or returns it to a higher pool, and whether
`FUN_001e2010` frees or just resets the 0x78 header. The original name "flush_channels_if_synced" and this
"release_if_idle" reading are the same mechanism (drain-when-quiescent); "release/destroy" is favoured
because the depth==fill-count gate means *fully returned*, not *seq-synchronised*.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ecdc0.c`  — untouched decompiler output.
