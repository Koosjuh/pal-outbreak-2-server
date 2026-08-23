# 0x001c92d0 snap_init_transfer_ids

| field | value |
|---|---|
| Original address | 0x001c92d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c92d0 |
| Resolved name | snap_xfer_dispatch_by_mode |
| Subsystem | session |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (a substate handler of the transfer/lookup engine, reached via the `snap_app_sm_pump` step table or a direct pump substate)
**Callees:** FUN_001c3a60 (poll_msg_class), FUN_001c3b90 (recv_n), FUN_001069a8 (memcpy), FUN_001c3b10 (recv_u32)
**Referenced globals:** 0x365dd0=inbound-message class byte; 0x365dd1=10-byte transfer id (+NUL 0x365ddb); 0x365de1=4-byte tag (+NUL 0x365de5); 0x365dec=mirror of total length; 0x365e0c/0x365e0e/0x365e10/0x365e12/0x365e18=room-list request counters
**Referenced strings:** —
**Referenced opcodes:** — (drives which app op the pump will issue next by setting the substate)
**State vars:** sm+0x00 mode; sm+0x0c major_phase(byte→7=error); sm+0x0d substate; sm+0x48 xfer_offset [idx 0x12]; sm+0x4e handshake scratch; sm+0x70 xfer_total [idx 0x1c]; sm+0x74 xfer_total2 [idx 0x1d]; sm+0xdc error [idx 0x37]

## Behavioral explanation
Entry dispatcher for the SN@P transfer/lookup engine. It branches on the engine's **mode word** `sm+0x00` and seeds the substate `sm+0xd` for whatever request the mode wants next.

For the two **data-transfer** modes (`0`/`7` = download/upload) it first peeks the inbound-message class via `FUN_001c3a60` (result cached in `cRam00365dd0`):
- class `0` → not ready yet: re-arm substate `0x23` (poll again).
- class `1` → a transfer-setup header is available: receive the `0xe`-byte handshake into `sm+0x4e`, publish the **10-byte transfer id** to `0x365dd1` and the **4-byte tag** to `0x365de1` (both NUL-terminated), read two u32 length words (`FUN_001c3b10`) into `sm+0x70`/`sm+0x74` (mirroring the total to `0x365dec`), zero the send/recv offset `sm+0x48`, and advance to substate `0x17` (the chunk send/recv loop). A short read (`< 0`) errors the SM (result `-1`, phase 7, cursors cleared).
- any other class → same error/teardown.

The other modes are pure substate seeds:
| mode | substate set | meaning |
|---|---|---|
| 1 | 0x34 | op0a member-list request path |
| 2 | 0x10 | op12 named-download path |
| 3 | 0x1f | op26 create/prepare path |
| 4 | 0x08 | op1e/op1c room-list path — also latches the room index `0x365e0c = (u16)sm+0x04` and zeroes the room-list counters |
| 5 | 0x04 | op1c room-list request path |
| 6 | 0x10 | op12 path (same as mode 2) |

## Input / output
- **Param:** `sm` — transfer/lookup engine object (the same object threaded through `snap_app_sm_pump`).
- **Returns:** `undefined8` — always `0`; status flows through `sm` fields.

## Side effects
- Transfer-setup (mode 0/7, class 1): fills globals `0x365dd1` (id), `0x365de1` (tag), `0x365dec` (total); sets `sm+0x70/0x74` (totals), `sm+0x48 = 0` (offset), `sm+0xd = 0x17`.
- Mode 4: `0x365e0c = 0x365e0e = (u16)sm+0x04`; `0x365e10 = 0x365e18 = 0x365e12 = 0`; `sm+0xd = 8`.
- Error legs: `sm+0xdc = -1`, `sm+0x0c = 7`, cursor block (`+0xd/0xe/0xf` bytes, `+0x10/0x12/0x14/0x16` u16) cleared.

## Important branches
- `mode ∈ {0,7}` → transfer-setup, gated on `FUN_001c3a60` class (0→wait 0x23, 1→parse, else→error).
- `recv_n(sm, sm+0x4e, 0xe) < 0` → error/teardown.
- `mode 1/2/3/4/5/6` → deterministic substate seed (table above).

## Constants & flags
- Handshake size `0xe` = 10-byte id + 4-byte tag.
- Class byte: `0`=pending, `1`=ready; other=error.
- Major phase `7` = SM error/teardown.
- Substate seeds: `0x08,0x10,0x17,0x1f,0x23,0x34`.

## Corrected reconstruction
```c
extern u8  g_msg_class;      // 0x365dd0 (from FUN_001c3a60)
extern u8  g_xfer_id[11];    // 0x365dd1 (10 + NUL @0x365ddb)
extern u8  g_xfer_tag[5];    // 0x365de1 (4  + NUL @0x365de5)
extern u32 g_xfer_total;     // 0x365dec
extern u16 g_rl_cur, g_rl_cur2, g_rl_c1, g_rl_c2, g_rl_c3; // 0x365e0c/0e/10/12/18

undefined8 snap_xfer_dispatch_by_mode(snap_xfer_sm *sm) {
    switch (sm->mode) {                     // sm+0x00
    case 0: case 7:                         // download/upload transfer setup
        g_msg_class = poll_msg_class();     // FUN_001c3a60
        if (g_msg_class == 0) { sm->substate = 0x23; break; }   // wait
        if (g_msg_class == 1) {
            if (recv_n(sm, sm->hs /*+0x4e*/, 0xe) < 0) {        // short read
                sm->error = -1; sm->phase = 7; sm_clear_cursors(sm); break;
            }
            memcpy(g_xfer_id, sm->hs,      10); g_xfer_id[10] = 0;
            memcpy(g_xfer_tag, sm->hs + 10, 4); g_xfer_tag[4] = 0;
            sm->xfer_total  = recv_u32(sm);  // +0x70
            g_xfer_total    = sm->xfer_total;
            sm->xfer_total2 = recv_u32(sm);  // +0x74
            sm->xfer_offset = 0;             // +0x48
            sm->substate    = 0x17;          // chunk loop
        } else {                             // bad class
            sm->error = -1; sm->phase = 7; sm_clear_cursors(sm);
        }
        break;
    case 1: sm->substate = 0x34; break;      // op0a member-list
    case 2: sm->substate = 0x10; break;      // op12 named download
    case 3: sm->substate = 0x1f; break;      // op26 create/prepare
    case 4:                                  // op1e/op1c room-list
        g_rl_cur = g_rl_cur2 = (u16)sm->arg1 /*+0x04*/;
        g_rl_c1 = g_rl_c2 = g_rl_c3 = 0;
        sm->substate = 0x08;
        break;
    case 5: sm->substate = 0x04; break;      // op1c room-list request
    case 6: sm->substate = 0x10; break;      // op12 named download
    }
    return 0;
}
```

## Evidence
- Decompile `FUN_001c92d0.c`: the `switch(*puVar3)` on mode; the class-gated transfer setup (`FUN_001c3a60`, `FUN_001c3b90(...,+0x4e,0xe)`, `FUN_001069a8(0x365dd1,+0x4e,10)`, `FUN_001069a8(0x365de1,+0x58,4)`, two `FUN_001c3b10` into `[0x1c]/[0x1d]`, `[0x12]=0`, substate 0x17); the mode→substate seeds; the mode-4 room-list counter init.
- Cross-ref: substate `0x17` is consumed by `snap_send_op0d_data_chunk` (0x001c94c0) / `snap_recv_data_chunk` (0x001c95e0); the transfer id `0x365dd1` is their key. Room-list counters `0x365e0c` match the op1c/op1e/op20 builders in PACKET_INDEX.
- Runtime-unvalidated.

## Remaining uncertainty
- `FUN_001c3a60` exact return contract (0/1/other) — inferred from usage.
- Meaning of the second length word `sm+0x74` (`xfer_total2`) — likely a byte-count vs record-count pair; only its read is proven.
- `sm+0x04` (mode-4 room index source) semantics.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c92d0.c`  — untouched decompiler output.
