# 0x001e0774 snap_send_op3f

| field | value |
|---|---|
| Original address | 0x001e0774 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e0774 |
| Resolved name | snap_send_op3f_hdr_blob |
| Subsystem | chat |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d5288 (snap_alloc_pkt_buf), FUN_001ed2c0 (pktbuf_reserve), FUN_001ec9e0 (subpool_free), FUN_001069a8 (memcpy ×2), FUN_001e180c (snap_packet_enqueue_send)
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(snap_errno); conn+0x50c(send-lock); conn+0x520(reliable_pool)
**Referenced strings:** —
**Referenced opcodes:** 0x3f
**State vars:** conn+0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
**Reliable opcode-0x3f "4-byte header + blob" sender.** A two-part reliable message: a fixed 4-byte
header word (`param_2`) followed by a variable body (`param_3`, length `param_4` clamped to 0x368).
It allocates a buffer, writes the 4-byte header at the front (`memcpy(region, &hdr, 4)`), then the
body immediately after (`memcpy(region+4, src, len)`), and enqueues with total body length `len+4`
under opcode 0x3f, flags `0xb000` (reliable | who | DATA). No completion callback. The header+payload
framing distinguishes op3f from the raw-blob op3e — op3f prefixes a 4-byte tag/id the receiver
demultiplexes on.

## Input / output
- `param_1` (`int mode`) — must be `1`.
- `param_2` (`u32 hdr`) — 4-byte header word written verbatim at the front.
- `param_3` (`void *src`) — body payload.
- `param_4` (`u32 len`) — body length, clamped to 0x368.
- **Returns** `0` / `-1` (+`snap_errno`).

## Side effects
- Alloc/free `conn->reliable_pool`; enqueues a reliable op3f packet with wire length `len+4`.
- Sets `snap_errno` on failure.

## Important branches
- family guards (`100` / `0x66`).
- `if (len > 0x367) len = 0x368;` — **clamp** the body.
- alloc → `0x65`; reserve → `subpool_free`+`0x65`; enqueue reject → `0x66`; else 0.

## Constants & flags
- `0x368` (872) — max body length (threshold `0x367`).
- `+4` — fixed header prefix size (added to the enqueue body length: `(len & 0xffff) + 4`).
- `0xb000` — reliable | 0x2000 who | 0x1000 DATA. `0x3f` — app opcode. `snap_errno` `100/0x65/0x66`.

## Corrected reconstruction
```c
// Reliable op3f: 4-byte header word + body blob (clamped 0x368), flags 0xb000.
int snap_send_op3f_hdr_blob(int mode, u32 hdr, const void *src, u32 len) {
    snap_connection *conn = g_conn;
    if (mode != 1 || conn == 0) { snap_errno = SNAP_ERR_NOCONN; return -1; }
    if (conn->send_lock != 0)   { snap_errno = SNAP_ERR_BUSY;   return -1; }

    if (len > 0x367) len = 0x368;       // clamp body

    void *buf = snap_alloc_pkt_buf(conn, (u16)len);
    if (buf == 0) { snap_errno = SNAP_ERR_NOBUF; return -1; }
    // NOTE: reserve() advances used_len by `len`, but the code then writes len+4 bytes into the
    // region (relying on the +0x14 alloc slack). Enqueue is told bodyLen = len+4.
    void *region = pktbuf_reserve(buf, (u16)len);
    if (region == 0) { subpool_free(conn->reliable_pool, buf); snap_errno = SNAP_ERR_NOBUF; return -1; }

    memcpy((u8*)region + 0, &hdr, 4);           // 4-byte header word
    memcpy((u8*)region + 4, src, len & 0xffff); // body

    long rc = snap_packet_enqueue_send(conn, buf, /*flags=*/0xb000,
                                       (u16)((len & 0xffff) + 4), 0x3f, 0);
    if (rc == 0) return 0;
    snap_errno = SNAP_ERR_BUSY; return -1;
}
```

## Evidence
- Raw: `FUN_001069a8(region, &uStack_2c, 4)` (header, `uStack_2c = param_2`), then
  `FUN_001069a8(region+4, uStack_28, uStack_24)` (body), then
  `FUN_001e180c(conn, buf, 0xb000, (uStack_24 & 0xffff) + 4, 0x3f, 0)`.
- Clamp: `uStack_24 = param_4; if (0x367 < param_4) uStack_24 = 0x368;`.
- Template helpers reconstructed.
- Runtime-unvalidated; no caller located.

## Remaining uncertainty
- `pktbuf_reserve` is called with `len` but `len+4` bytes are written; the enqueue length is `len+4`.
  This relies on the 0x14-byte slack `snap_alloc_pkt_buf` adds and means the pktbuf `used_len` and the
  declared wire length differ by 4. Whether that is a benign quirk or an intentional "reserve rounds up
  via slack" is unconfirmed without a runtime trace (the enqueue length-match guard `ebca8 == bodyLen+0x10`
  may or may not pass). The header word's high-level meaning (channel id / sub-tag) is unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e0774.c`  — untouched decompiler output.
