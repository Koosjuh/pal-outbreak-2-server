# 0x001dfbf8 snap_send_op11

| field | value |
|---|---|
| Original address | 0x001dfbf8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dfbf8 |
| Resolved name | snap_send_op11_unrel |
| Subsystem | chat |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d5288 (snap_alloc_pkt_buf), FUN_001ed2c0 (pktbuf_reserve), FUN_001ec9e0 (subpool_free), FUN_001069a8 (memcpy), FUN_001e180c (snap_packet_enqueue_send)
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(snap_errno); conn+0x50c(send-lock); conn+0x520(reliable_pool)
**Referenced strings:** —
**Referenced opcodes:** 0x11
**State vars:** conn+0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
**Unreliable opcode-0x11 blob sender.** Same template as the op0f-unreliable sender, differing only
in the app opcode (0x11) — signature and flags are identical: flags `param_2 | 0x2000`, blob
`(param_3, param_4)`. Inbound 0x11 is dispatched to the `conn+0x5e8` handler slot (PACKET_INDEX),
so op11 is a distinct unreliable data/notify channel that parallels op0f. No completion callback.

## Input / output
- `param_1` (`int mode`) — must be `1`.
- `param_2` (`u16 who`) — who bits, OR-ed with `0x2000`.
- `param_3` (`void *src`) — body.
- `param_4` (`u32 len`) — length (→ `u16`).
- **Returns** `0` / `-1` (+`snap_errno`).

## Side effects
- Alloc/free `conn->reliable_pool`; enqueues an unreliable op11 packet; sets `snap_errno` on failure.

## Important branches
Family-standard ladder: bad-mode/no-conn → 100; `send_lock` → 0x66; alloc → 0x65; reserve →
`subpool_free`+0x65; enqueue reject → 0x66; else 0.

## Constants & flags
- `0x2000` unreliable who bit · `0x11` app opcode · `snap_errno` `100/0x65/0x66`.

## Corrected reconstruction
```c
// Unreliable op11: flags = who | 0x2000, blob = (src, len). Same shape as op0f-unrel, opcode 0x11.
int snap_send_op11_unrel(int mode, u16 who, const void *src, u32 len) {
    snap_connection *conn = g_conn;
    if (mode != 1 || conn == 0) { snap_errno = SNAP_ERR_NOCONN; return -1; }
    if (conn->send_lock != 0)   { snap_errno = SNAP_ERR_BUSY;   return -1; }

    void *buf = snap_alloc_pkt_buf(conn, (u16)len);
    if (buf == 0) { snap_errno = SNAP_ERR_NOBUF; return -1; }
    void *region = pktbuf_reserve(buf, (u16)len);
    if (region == 0) { subpool_free(conn->reliable_pool, buf); snap_errno = SNAP_ERR_NOBUF; return -1; }
    memcpy(region, src, len);

    long rc = snap_packet_enqueue_send(conn, buf, who | 0x2000, (u16)len, 0x11, 0);
    if (rc == 0) return 0;
    snap_errno = SNAP_ERR_BUSY; return -1;
}
```

## Evidence
- Raw: `FUN_001e180c(conn, buf, param_2|0x2000, len, 0x11, 0)` — opcode 0x11, unreliable.
- Dispatcher pairing (inbound 0x11 → conn+0x5e8) from PACKET_INDEX distinguishes it from op0f.
- Template helpers reconstructed.
- Runtime-unvalidated; no caller located.

## Remaining uncertainty
- No caller ⇒ payload meaning of op11 inferred from opcode/dispatch slot only.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dfbf8.c`  — untouched decompiler output.
