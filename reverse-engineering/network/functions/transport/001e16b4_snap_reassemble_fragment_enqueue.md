# 0x001e16b4 snap_reassemble_fragment_enqueue

| field | value |
|---|---|
| Original address | 0x001e16b4 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e16b4 |
| Resolved name | snap_reserve_reorder_slot |
| Subsystem | transport |
| Relevance | core |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d6988 (accept-gate)
**Callees:** FUN_001ebd54 (head), FUN_001ebd7c (next), FUN_001eb858 (member/end test), FUN_001ebb90 (test flag), FUN_001ec1f8 (alloc), FUN_001eb3b8 (enqueue), FUN_001ebbd0 (set flag), FUN_001ed634 (set seq)
**Referenced globals:** conn+0x520 buffer pool
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node flags 0x200 (allocated placeholder) / 0x1000 (occupied/who)

## Behavioral explanation
Reserves (or reuses) a **reorder-list slot** for an inbound reliable segment with a given sequence number, on the receive path of the accept-gate. It scans the target list (`param_2 + 8`) skipping every node already marked `0x1000` (occupied placeholder). If it reaches the end without finding a free node, it allocates a fresh 0x10-byte descriptor from the buffer pool (`conn+0x520`), appends it, and tags it `0x200` (freshly-allocated placeholder). In all cases it then marks the chosen node `0x1000` (now occupied) and stamps its sequence number (`FUN_001ed634(node, param_3)`). The effect is: "ensure a placeholder exists in the reorder list bound to seq `param_3`," which the fragment reassembler later fills with payload.

## Input / output
- **param_1** (`snap_connection*` as `int`): connection; source of the buffer pool `conn+0x520`.
- **param_2** (`int` list object): the reorder/reassembly list (`list+8` is the embedded list head).
- **param_3** (`undefined4` seq): the sequence number to bind the reserved slot to.
- **Return** (`int`): `0` on success, or the non-zero error from `FUN_001ec1f8` (allocation failure) propagated verbatim.

## Side effects
- May allocate a 0x10-byte node from `conn+0x520` and append it to the list (`FUN_001eb3b8`).
- Sets node flags `0x200` (new node only) and `0x1000` (always), and the node seq to `param_3`.

## Important branches
- Scan loop: `while (member(list,node) && test(node,0x1000) != 0)` → advance past occupied placeholders.
- `member(list, node) != 0` (reached END, no free slot) → allocate + append + set `0x200`.
  - `FUN_001ec1f8(...) != 0` (alloc failed) → `return err`.
- Tail (always): `set(node,0x1000)`, `set_seq(node, param_3)`, return 0.

## Constants & flags
- Node flag `0x200` — freshly allocated placeholder (distinguishes new from reused slot).
- Node flag `0x1000` — slot occupied / bound to a seq.
- `0x10` — allocation size for a new placeholder descriptor.

## Corrected reconstruction
```c
// Ensure a reorder-list placeholder exists bound to sequence `seq`.
enum { F_NEW=0x200, F_OCCUPIED=0x1000 };

int snap_reserve_reorder_slot(snap_connection *conn /*param_1*/,
                              int list /*param_2*/, u32 seq /*param_3*/)
{
    void *node = pkt_head(list + 8);                        // FUN_001ebd54
    while (!pkt_member(list + 8, node) && pkt_test(node, F_OCCUPIED))
        node = pkt_next(node);                              // skip occupied slots

    if (pkt_member(list + 8, node)) {                       // eb858 != 0 → end of list
        int e = pkt_alloc(&conn->pool520 /*+0x520*/, &node, 0x10, 1, 0);
        if (e != 0) return e;
        pkt_enqueue(list + 8, node);                        // FUN_001eb3b8
        pkt_setflag(node, F_NEW);                           // 0x200
    }
    pkt_setflag(node, F_OCCUPIED);                          // 0x1000
    pkt_set_seq(node, seq);                                 // FUN_001ed634
    return 0;
}
```

## Evidence
- `FUN_001eb858(list, node)` used both to terminate the scan (`!= 0` ⇒ end) and to detect "no free slot" ⇒ it is the member/sentinel test.
- Allocates exactly `0x10` bytes (a bare descriptor/placeholder, no payload) and binds it to `param_3` via `FUN_001ed634` (the seq setter used across the send path).
- Called by the accept-gate `FUN_001d6988`, consistent with "reserve a reorder slot for an arriving segment."
- Runtime-unvalidated.

## Remaining uncertainty
- Exact split/reassembly semantics vs. simple slot-reservation: this function only reserves/binds; the payload copy into the placeholder happens in the caller/reassembler, which is not decompiled here. Whether `0x200` vs. `0x1000` distinguishes "empty allocated" from "filled" precisely is inferred from usage.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e16b4.c`  — untouched decompiler output.
