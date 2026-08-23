# 0x001c5f30 recv_download_setup_D

| field | value |
|---|---|
| Original address | 0x001c5f30 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c5f30 |
| Resolved name | recv_download_setup_D_keyed |
| Subsystem | lobby |
| Relevance | core |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** dispatched by snap_app_sm_pump inbound table on the op2d reply (machine-D setup)
**Callees:** FUN_001c3ab0 (buf_read_be16 count), FUN_001c3b10 (buf_read_be32 id/size)
**Referenced globals:** 0x365cf0 slot-count (shared w/ machine B); 0x365cf4 size-table (shared);
0x365d34 dest-pointer table (shared); 0x365d74 **id-table** (D-only); 0x35ccc8 ring base (shared w/ B);
0x365db4 slot-idx seq; 0x365db8 offset seq; sm+0x30 rx-header; sm+0x0d substate; sm+0xdc error
**Referenced strings:** —
**Referenced opcodes:** — (reply to op2d; feeds op2f chunk fetch)
**State vars:** 0x365db4/0x365db8 reset to 0; sm+0x0d → 0x2b (fetch) / 0x02 (empty→op18) / 0 (abort)

## Behavioral explanation
Parses the **keyed multi-slot setup reply** for transfer machine **D**. Unlike machine B (from which it
borrows the same ring/tables/seq globals), each of the up to 8 slots carries **two** `be32` values — an
**id/key** (stored in the D-only table `0x365d74`) and a **size** (stored in the shared size table
`0x365cf4`). The destination pointers land in the shared `0x365d34` table but at a **`0x800` stride**
(vs machine B's `0x400`) above the same `+0x1000` ring header. A count of `0` jumps to substate `0x02`
(which fires op18); otherwise it resets the slot/offset seq and advances to substate `0x2b`
(`snap_send_op2f_chunk_request`, 0x001c6060). The per-slot id lets the fetch target specific keyed records
rather than a positional table.

## Input / output
- **param_1** (`snap_xfer_sm *sm`).
- **Returns** (undefined8): `0`.

## Side effects
- `0x365cf0` ← slot count (≤8).
- Per slot i: `0x365d34[i] = ring(0x35ccc8) + i*0x800 + 0x1000`; `0x365d74[i] = id`; `0x365cf4[i] = size`
  (no size bound check).
- `0x365db4 = 0`, `0x365db8 = 0`.
- On disconnect: `abort(sm, 9)`.
- Sets `sm+0x0d` to `0x2b` (fetch) or `0x02` (empty).

## Important branches
- `rx_hdr[6] == -1` → `abort(sm, 9)`.
- `count > 8` → `count = 8` (clamp precedes zero test); `0x365cf0 = count`.
- `count == 0` → `sm+0x0d = 0x02` (skip D → op18).
- else per slot: dest ptr, `id = read_be32(sm)` → `0x365d74[i]`, `size = read_be32(sm)` → `0x365cf4[i]`;
  then seq reset, `sm+0x0d = 0x2b`.

## Constants & flags
- Slot-count clamp `8`; ring base `0x35ccc8`, stride `0x800`, header offset `+0x1000`.
- Shares B's tables (`0x365cf0/0x365cf4/0x365d34/0x365db4/0x365db8`) → machines B and D are mutually
  exclusive in time; D adds the id table `0x365d74`.
- error code `9` disconnect. (No `-1` size-abort path.)

## Corrected reconstruction
```c
undefined8 recv_download_setup_D_keyed(snap_xfer_sm *sm)
{
    if (sm->rx_hdr[6] == (u8)0xFF) { xfer_abort(sm, 9); return 0; }

    u16 count = buf_read_be16(sm) & 0xffff;
    if (count > 8) count = 8;                        // clamp first
    g_slot_count /*0x365cf0 (shared w/ B)*/ = count;
    if (count == 0) { sm->substate = 0x02; return 0; }   // nothing -> op18

    for (u32 i = 0; i < count; i++) {
        g_dest_tab[i]  /*0x365d34[i]*/ = g_ring /*0x35ccc8*/ + i*0x800 + 0x1000;  // 0x800 stride
        g_id_tab[i]    /*0x365d74[i]*/ = buf_read_be32(sm);   // record key/id (D-only)
        g_size_tab[i]  /*0x365cf4[i]*/ = buf_read_be32(sm);   // size (no bound check)
    }
    g_off /*0x365db8*/ = 0; g_slot /*0x365db4*/ = 0;
    sm->substate = 0x2b;                             // -> send op2f chunk request
    return 0;
}
```

## Evidence
- Raw: disconnect leg; `FUN_001c3ab0` count `>8 → 8`, `uRam00365cf0 = count`, `count==0 → sm[0xd]=2`;
  loop `*(i*4+0x365d34) = iRam0035ccc8 + i*0x800 + 0x1000`, `*(i*4+0x365d74) = FUN_001c3b10()` (id),
  `*(i*4+0x365cf4) = FUN_001c3b10()` (size); `sm[0xd]=0x2b`.
- Reuses B's ring/tables but at 0x800 stride and adds the `0x365d74` id table — matches the pump's
  op2d→op2f keyed-download path (setup lands at 0x2b = op2f builder 6060; body parser 0x001c6130).
- Confidence **Medium**: the id semantics (which record class it keys) and the B/D global aliasing are
  inferred from layout, not runtime-traced.

## Remaining uncertainty
- The exact meaning of the per-slot id (record handle vs offset vs version) and what op2d requested is not
  resolved here (needs the op2d builder 0x001c5ea0 and chunk parser 0x001c6130).
- The `0x800` stride over the same ring B uses at `0x400` implies these two machines carry different
  payload classes into the same buffer at different times; the arbiter is the pump substate graph.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c5f30.c`  — untouched decompiler output.
