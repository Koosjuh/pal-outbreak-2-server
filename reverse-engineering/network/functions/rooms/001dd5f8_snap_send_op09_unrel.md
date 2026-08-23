# 0x001dd5f8 snap_send_op09_unrel

| field | value |
|---|---|
| Original address | 0x001dd5f8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dd5f8 |
| Resolved name | snap_send_op09_nodata (was: snap_send_op09_unrel — see note) |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24(register reply cb), FUN_001d5288(snap_alloc_pkt_buf), FUN_001e180c(snap_packet_enqueue_send), FUN_001ec9e0(subpool_free), FUN_001ed2c0(pktbuf_reserve)
**Referenced globals:** 0x0025b78c(g_snap_conn); 0x0025b790(g_snap_errno); conn+0x50c(send-lock); conn+0x520(reliable_pool); conn+0x61d(op09 seq)
**Referenced strings:** —
**Referenced opcodes:** 0x09
**State vars:** conn+0x50c(send-lock); conn+0x61d(per-op seq); g_snap_errno

## Behavioral explanation
Builder for **app opcode 0x09 (register)** carrying **two big-endian `u32` values** (8-byte body),
sent with the **non-DATA who-word `0xa000`**. It is the `0xa000` twin of FUN_001dd840 (same 8-byte
two-u32 body, who `0xb000`, seq 0x61e, cb 0x17). Shared idiom: guard → alloc 8 → write two
`htonl` u32 → finalize+enqueue (op 0x09) → register reply cb (tag 0x16) → bump/return seq (conn+0x61d).

**Naming note:** `0xa000` keeps the `0x8000` reliable bit; this is a reliable send, not unreliable —
`_unrel` is a misnomer (only the `0x1000` DATA who-bit differs from FUN_001dd840). Renamed
`snap_send_op09_nodata`.

## Input / output
- `param_1` (`int` sel): must be `1`.
- `param_2` (`u32` a): → +0x00 as `htonl(param_2)` (BE).
- `param_3` (`u32` b): → +0x04 as `htonl(param_3)` (BE).
- `param_4` (`void* cb`): reply/completion callback, tag `0x16`.
- **Returns** (`uint`): assigned seq byte (pre-increment conn+0x61d); `0xffffffff` on failure.

## Side effects
- Alloc/free from `conn->reliable_pool`; 8-byte payload; enqueue on send pool.
- `FUN_001d4d24(1, 0x16, cb)`; increment `conn+0x61d`; set `g_snap_errno` on error.

## Important branches
- `param_1 != 1 || conn == 0` → `g_snap_errno = 0x64`, return -1.
- `conn+0x50c != 0` → `g_snap_errno = 0x66`, return -1.
- `snap_alloc_pkt_buf(conn, 8) == 0` → `g_snap_errno = 0x65`, return -1.
- `pktbuf_reserve(buf, 8) == 0` → `subpool_free`, `g_snap_errno = 0x65`, return -1.
- `snap_packet_enqueue_send(...) != 0` → `g_snap_errno = 0x66`, return -1.
- else → register cb, post-increment seq, return old seq byte.

## Constants & flags
- `0x09` — app opcode (register).
- `0xa000` — who-word: `0x8000` reliable | `0x2000` (no `0x1000` DATA bit). Reliable.
- `8` — payload length (two u32).
- `0x16` — reply/completion callback tag.

## Corrected reconstruction
```c
enum { WHO_RELIABLE=0xa000 };

uint snap_send_op09_nodata(int sel, u32 a, u32 b, void *cb)  // was _unrel
{
    snap_connection *conn = g_snap_conn;
    if (sel != 1 || conn == 0)           { g_snap_errno = 0x64; return -1; }
    if (conn->send_lock /*+0x50c*/ != 0) { g_snap_errno = 0x66; return -1; }

    void *buf = snap_alloc_pkt_buf(conn, 8);
    if (buf == 0)                        { g_snap_errno = 0x65; return -1; }

    u32 *p = pktbuf_reserve(buf, 8);
    if (p == 0) { subpool_free(conn->reliable_pool /*+0x520*/, buf);
                  g_snap_errno = 0x65; return -1; }

    p[0] = htonl(a);
    p[1] = htonl(b);
    if (snap_packet_enqueue_send(conn, buf, WHO_RELIABLE, /*bodyLen*/8, /*op*/0x09,
                                 conn->seq_op09a /*+0x61d*/) != 0) {
        g_snap_errno = 0x66; return -1;
    }
    FUN_001d4d24(1, 0x16, cb);
    return conn->seq_op09a++;
}
```

## Evidence
- Raw `FUN_001dd5f8.c`: `*puVar4=htonl(param_2); puVar4[1]=htonl(param_3);`
  `FUN_001e180c(iVar2,iVar3,0xa000,8,9,*(iVar2+0x61d))`; cb tag `0x16`; seq `conn+0x61d`.
- Pairs with FUN_001dd840 (op09, who 0xb000, seq 0x61e, cb 0x17). Runtime-unvalidated.

## Remaining uncertainty
- The two u32 fields' roles (member id + status? id + slot?) are unconfirmed; the "register" opcode
  label comes from the task/PACKET_INDEX map, but the 2-u32 layout hints at a slot/status update.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dd5f8.c`  — untouched decompiler output.
