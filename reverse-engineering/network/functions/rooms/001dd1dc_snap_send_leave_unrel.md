# 0x001dd1dc snap_send_leave_unrel

| field | value |
|---|---|
| Original address | 0x001dd1dc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dd1dc |
| Resolved name | snap_send_leave_nodata (was: snap_send_leave_unrel — see note) |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24(register reply cb), FUN_001d5288(snap_alloc_pkt_buf), FUN_001e180c(snap_packet_enqueue_send)
**Referenced globals:** 0x0025b78c(g_snap_conn); 0x0025b790(g_snap_errno); conn+0x50c(send-lock); conn+0x61b(op07 seq)
**Referenced strings:** —
**Referenced opcodes:** 0x07
**State vars:** conn+0x50c(send-lock); conn+0x61b(per-op seq); g_snap_errno

## Behavioral explanation
Zero-length **op07 (leave room)** builder using the **non-DATA who-word `0xa000`** — the twin of
FUN_001dd07c (who `0xb000`). Same empty-body shape (alloc size 0, no reserve), its own sequence counter
(conn+0x61b) and reply-callback tag (0x24).

**Naming note:** `0xa000` still sets the `0x8000` reliable bit, so this leave is **reliable**, not an
unreliable datagram — the `_unrel` suffix is a misnomer. The only difference from FUN_001dd07c is the
`0x1000` DATA who-bit being clear. Renamed here to `snap_send_leave_nodata` to reflect that.

## Input / output
- `param_1` (`int` sel): must be `1`.
- `param_2` (`void* cb`): reply/completion callback, tag `0x24`.
- **Returns** (`uint`): assigned seq byte (pre-increment conn+0x61b); `0xffffffff` on failure.

## Side effects
- Allocates a 0-length buffer from `conn->reliable_pool`; enqueues on send pool.
- `FUN_001d4d24(1, 0x24, cb)`; increment `conn+0x61b`; set `g_snap_errno` on error.

## Important branches
- `param_1 != 1 || conn == 0` → `g_snap_errno = 0x64`, return -1.
- `conn+0x50c != 0` → `g_snap_errno = 0x66`, return -1.
- `snap_alloc_pkt_buf(conn, 0) == 0` → `g_snap_errno = 0x65`, return -1.
- `snap_packet_enqueue_send(...) != 0` → `g_snap_errno = 0x66`, return -1.
- else → register cb, post-increment seq, return old seq byte.

## Constants & flags
- `0x07` — app opcode (leave room).
- `0xa000` — who-word: `0x8000` reliable | `0x2000` (no `0x1000` DATA bit). Reliable.
- `0` — payload length (empty).
- `0x24` — reply/completion callback tag.

## Corrected reconstruction
```c
enum { WHO_RELIABLE=0xa000 };   // reliable (0x8000) without the 0x1000 DATA bit

uint snap_send_leave_nodata(int sel, void *cb)  // was mis-suffixed _unrel
{
    snap_connection *conn = g_snap_conn;
    if (sel != 1 || conn == 0)           { g_snap_errno = 0x64; return -1; }
    if (conn->send_lock /*+0x50c*/ != 0) { g_snap_errno = 0x66; return -1; }

    void *buf = snap_alloc_pkt_buf(conn, 0);
    if (buf == 0)                        { g_snap_errno = 0x65; return -1; }

    if (snap_packet_enqueue_send(conn, buf, WHO_RELIABLE, /*bodyLen*/0, /*op*/0x07,
                                 conn->seq_op07b /*+0x61b*/) != 0) {
        g_snap_errno = 0x66; return -1;
    }
    FUN_001d4d24(1, 0x24, cb);
    return conn->seq_op07b++;
}
```

## Evidence
- Raw `FUN_001dd1dc.c`: `FUN_001d5288(...,0)`; `FUN_001e180c(iVar2,iVar3,0xa000,0,7,*(iVar2+0x61b))`;
  cb tag `0x24`; seq `conn+0x61b`.
- `0xa000` retains `0x8000` (reliable) — see FUN_001e180c which branches unreliable only when
  `flags & 0x8000 == 0`. So both leave variants are reliable. Runtime-unvalidated.

## Remaining uncertainty
- Why the app needs both DATA (`0xb000`) and non-DATA (`0xa000`) leave variants (different receive-side
  routing?) is unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dd1dc.c`  — untouched decompiler output.
