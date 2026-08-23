# 0x001e0188 snap_send_op34

| field | value |
|---|---|
| Original address | 0x001e0188 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e0188 |
| Resolved name | snap_send_op34_string |
| Subsystem | chat |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_0010a050 (strlen), FUN_0010a4f0 (memcpy), FUN_001d5288 (snap_alloc_pkt_buf), FUN_001ed2c0 (pktbuf_reserve), FUN_001ec9e0 (subpool_free), FUN_001e180c (snap_packet_enqueue_send), FUN_001d4d24 (snap_set_callback_slot)
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(snap_errno); conn+0x50c(send-lock); conn+0x520(reliable_pool); conn+0x548(callback table)
**Referenced strings:** —
**Referenced opcodes:** 0x34
**State vars:** conn+0x50c(send-lock); DAT_0025b790(errno); callback slot 0x2a

## Behavioral explanation
**Reliable opcode-0x34 C-string sender with a completion callback.** Unlike the raw-blob senders,
op34 measures its argument as a NUL-terminated string (`strlen` via 0x0010a050), **clamps the length
to 0x368** (larger strings are truncated to 0x368), copies it with the `0010a4f0` copy helper, and
sends it reliably (flags `0xb000` = 0x8000 reliable | 0x2000 who | 0x1000 DATA). On successful
enqueue it registers a completion via `snap_set_callback_slot(1, 0x2a, param_3)` — i.e. slot 0x2a of
the connection callback table (conn+0x548) is armed with `param_3`, so the caller is notified/chained
when the reliable send is acked. This is the only sender in this set that carries a completion cb,
marking op34 as a request/response-style reliable text message (large payload, ≤ 0x368).

## Input / output
- `param_1` (`int mode`) — must be `1`.
- `param_2` (`const char *str`) — NUL-terminated source string (length measured, clamped to 0x368).
- `param_3` (`void *cb_arg`) — completion argument stored into callback slot 0x2a on success.
- **Returns** `0` on enqueue (callback armed); `-1` with `snap_errno` on failure (callback **not** armed).

## Side effects
- Alloc/free from `conn->reliable_pool`; enqueues a reliable op34 packet.
- On success: `snap_set_callback_slot(1, 0x2a, param_3)` writes conn+0x548+0x2a*4.
- Sets `snap_errno` on failure.

## Important branches
- `mode != 1 || g_conn == 0` → `snap_errno = 100`, -1.
- `send_lock != 0` → `0x66`, -1.
- `len = strlen(str); if (len > 0x368) len = 0x368;` — **clamp**.
- alloc fail → `0x65`, -1; reserve fail → `subpool_free` + `0x65`, -1.
- enqueue `== 0` (success) → `snap_set_callback_slot(1, 0x2a, cb_arg)`, return 0.
- enqueue `!= 0` → `snap_errno = 0x66`, -1.

## Constants & flags
- `0x368` (872) — maximum string length (clamp ceiling).
- `0xb000` — reliable flags: `0x8000` reliable | `0x2000` who | `0x1000` DATA.
- `0x34` — app opcode. `0x2a` — completion callback slot index (conn+0x548 table).
- `snap_errno`: `100 / 0x65 / 0x66`.

## Corrected reconstruction
```c
// Reliable op34: send a C-string (clamped 0x368) and arm completion slot 0x2a.
int snap_send_op34_string(int mode, const char *str, void *cb_arg) {
    snap_connection *conn = g_conn;
    if (mode != 1 || conn == 0) { snap_errno = SNAP_ERR_NOCONN; return -1; }
    if (conn->send_lock != 0)   { snap_errno = SNAP_ERR_BUSY;   return -1; }

    u32 len = strlen(str);              // FUN_0010a050
    if (len > 0x368) len = 0x368;       // clamp

    void *buf = snap_alloc_pkt_buf(conn, (u16)len);
    if (buf == 0) { snap_errno = SNAP_ERR_NOBUF; return -1; }
    void *region = pktbuf_reserve(buf, (u16)len);
    if (region == 0) { subpool_free(conn->reliable_pool, buf); snap_errno = SNAP_ERR_NOBUF; return -1; }
    memcpy_str(region, str, len);       // FUN_0010a4f0

    long rc = snap_packet_enqueue_send(conn, buf, /*flags=*/0xb000, (u16)len, 0x34, 0);
    if (rc == 0) {
        snap_set_callback_slot(1, /*slot=*/0x2a, cb_arg);   // arm completion
        return 0;
    }
    snap_errno = SNAP_ERR_BUSY; return -1;
}
```

## Evidence
- Raw: `uStack_18 = FUN_0010a050(param_2); if (0x368 < uStack_18) uStack_18 = 0x368;` — strlen + clamp.
- `FUN_001e180c(conn, buf, 0xb000, len, 0x34, 0)` — reliable op34.
- On the enqueue-success path only: `FUN_001d4d24(1, 0x2a, param_3)` = `snap_set_callback_slot` (0x1d4d24 record: writes conn+0x548+idx*4).
- Template helpers reconstructed.
- Runtime-unvalidated; no caller located.

## Remaining uncertainty
- The callback slot 0x2a's consumer (who reads conn+0x548[0x2a]) and whether op34 is chat vs. a system text request is not traced. The `0010a4f0` helper is a bounded copy (not necessarily NUL-preserving) — treated as memcpy of `len` bytes.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e0188.c`  — untouched decompiler output.
