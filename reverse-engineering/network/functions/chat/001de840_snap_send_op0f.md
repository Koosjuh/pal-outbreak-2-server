# 0x001de840 snap_send_op0f

| field | value |
|---|---|
| Original address | 0x001de840 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001de840 |
| Resolved name | snap_send_op0f_reliable |
| Subsystem | chat |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c4bd0 (build_send_chat_datagram)
**Callees:** FUN_001d5288 (snap_alloc_pkt_buf), FUN_001ed2c0 (pktbuf_reserve), FUN_001ec9e0 (subpool_free), FUN_001069a8 (memcpy), FUN_001e180c (snap_packet_enqueue_send)
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(snap_errno); conn+0x50c(send-lock); conn+0x520(reliable_pool)
**Referenced strings:** —
**Referenced opcodes:** 0x0f
**State vars:** conn+0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
The **reliable opcode-0x0f blob sender** — the transport tail of the in-room/lobby chat path
(`build_send_chat_datagram` at 0x5c4bd0 is its sole caller, so op0f is the chat/DATA carrier).
It follows the canonical SN@P "alloc → reserve → copy → enqueue" send template shared by ~15
app-message senders: it takes a length-`param_3` byte blob, allocates a reliable send buffer from
the connection pool, copies the blob in, and hands it to the generic finalizer
`snap_packet_enqueue_send` with opcode 0x0f and the header-flags word `param_4 | 0xa400`
(reliable 0x8000 + who 0x2000 + 0x0400). Fire-and-forget: no completion callback is registered.

## Input / output
- `param_1` (`int mode`) — must be `1` (active/connected mode); any other value is rejected.
- `param_2` (`void *src`) — pointer to the message body to copy.
- `param_3` (`u32 len`) — body length in bytes (truncated to `u16` for framing).
- `param_4` (`u16 who`) — caller-supplied who/type bits OR-ed with `0xa400` for the wire flags word.
- **Returns** `0` on successful enqueue; `0xffffffff` (-1) on any failure, with `snap_errno`
  (0x25b790) set to the failure code.

## Side effects
- Allocates and (on the reserve-failure path) frees a buffer from `conn->reliable_pool` (+0x520).
- Appends a finalized reliable packet to the connection send queue (via enqueue_send).
- Writes `snap_errno` (0x25b790) on every failure branch.

## Important branches
- `mode != 1 || g_conn == 0` → `snap_errno = 100 (0x64)`, return -1. (No connection / wrong mode.)
- `conn->send_lock (+0x50c) != 0` → `snap_errno = 0x66`, return -1. (Transport busy/guarded.)
- `snap_alloc_pkt_buf == 0` (pool exhausted) → `snap_errno = 0x65`, return -1.
- `pktbuf_reserve == 0` (no payload room) → `subpool_free(pool, buf)`, `snap_errno = 0x65`, return -1.
- `snap_packet_enqueue_send == 0` (accepted) → return 0; **non-zero** (0x27 locked/len-mismatch) →
  `snap_errno = 0x66`, return -1.

## Constants & flags
- `0xa400` — reliable flags for op0f: `0x8000` reliable | `0x2000` who | `0x0400`. `param_4` (who) OR-ed on top.
- `0x0f` — app opcode (chat/DATA carrier).
- `snap_errno`: `100/0x64` = no-conn/bad-mode · `0x65` = alloc/reserve fail · `0x66` = locked / enqueue-reject.

## Corrected reconstruction
```c
// snap_errno codes shared by the send family:
enum { SNAP_ERR_NOCONN=100, SNAP_ERR_NOBUF=0x65, SNAP_ERR_BUSY=0x66 };

// send template: reliable op0f, flags = who | 0xa400
int snap_send_op0f_reliable(int mode, const void *src, u32 len, u16 who) {
    snap_connection *conn = g_conn; // 0x25b78c
    if (mode != 1 || conn == 0)          { snap_errno = SNAP_ERR_NOCONN; return -1; }
    if (conn->send_lock /*+0x50c*/ != 0) { snap_errno = SNAP_ERR_BUSY;   return -1; }

    void *buf = snap_alloc_pkt_buf(conn, (u16)len);
    if (buf == 0)                        { snap_errno = SNAP_ERR_NOBUF;  return -1; }

    void *region = pktbuf_reserve(buf, (u16)len);
    if (region == 0) {                                  // no payload room
        subpool_free(conn->reliable_pool /*+0x520*/, buf);
        snap_errno = SNAP_ERR_NOBUF; return -1;
    }
    memcpy(region, src, len);                           // FUN_001069a8

    long rc = snap_packet_enqueue_send(conn, buf, who | 0xa400, (u16)len,
                                       /*opcode=*/0x0f, /*subSel=*/0);
    if (rc == 0) return 0;
    snap_errno = SNAP_ERR_BUSY; return -1;              // enqueue rejected (0x27)
}
```

## Evidence
- Raw `FUN_001de840.c`: `FUN_001e180c(conn, buf, param_4|0xa400, len, 0xf, 0)` — opcode 0x0f, flags include 0x8000 reliable.
- Sole caller `FUN_005c4bd0` (build_send_chat_datagram) passes `[type,len,name,payload]` as the blob and `who` = 0x1000 (lobby) or 0 (in-room) → op0f is the chat/DATA carrier.
- Helpers reconstructed: `snap_alloc_pkt_buf` (0x1d5288), `pktbuf_reserve` (0x1ed2c0), `snap_packet_enqueue_send` (0x1e180c) all confirm the template semantics.
- Runtime-unvalidated (no wire trace of op0f yet).

## Remaining uncertainty
- The `0x0400` bit inside `0xa400` is not separately decoded (part of the who/type field family). Not runtime-confirmed against a chat capture.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001de840.c`  — untouched decompiler output.
