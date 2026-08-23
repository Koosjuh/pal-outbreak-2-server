# 0x001dc310 snap_send_create_slot

| field | value |
|---|---|
| Original address | 0x001dc310 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dc310 |
| Resolved name | snap_send_op05_data (was: snap_send_create_slot — see correction) |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24(register reply cb), FUN_001d5288(snap_alloc_pkt_buf), FUN_001e180c(snap_packet_enqueue_send), FUN_001ec9e0(subpool_free), FUN_001ed2c0(pktbuf_reserve)
**Referenced globals:** 0x0025b78c(g_snap_conn); 0x0025b790(g_snap_errno); conn+0x50c(send-lock); conn+0x520(reliable_pool); conn+0x615(seq)
**Referenced strings:** —
**Referenced opcodes:** 0x05 (emitted on-wire; formerly bucketed under 0x04 — corrected below)
**State vars:** conn+0x50c(send-lock); conn+0x615(per-op seq); g_snap_errno

## Behavioral explanation
Minimal SN@P builder that sends a single big-endian `u32` as a **reliable, DATA-who (`0xb000`)**
message. It is the `0xb000` twin of FUN_001dc804 (which sends the identical 4-byte body with the
non-DATA who-word `0xa000`). Both pass **on-wire opcode `5`** to the finalizer — see the correction
note: this function does **not** emit app-opcode 0x04. It follows the shared builder idiom exactly:
guard → alloc → reserve 4 → `htonl(u32)` → finalize+enqueue → register reply cb (tag 0x1e) →
bump/return the sequence byte at conn+0x615.

**Correction (deep read):** the finalizer `FUN_001e180c(conn, pkt, flags, bodyLen, opcode, seq)`
receives `(...,0xb000, 4, 5, conn+0x615)`. Arg-4 is the body length (`4`, matching the 4-byte reserve),
arg-5 is the app opcode (`5`). The prior name `snap_send_create_slot` / the PACKET_INDEX 0x04 bucket
are **incorrect** — verified by the sibling builders where the same slot is unambiguous (dc508 →
`len 0x2c, op 4`; dc9fc → `len 4, op 6`; dd07c → `len 0, op 7`). The genuine create-slot/create-room
builder is FUN_001dc508 (op04).

## Input / output
- `param_1` (`int` sel): must be `1` (primary session).
- `param_2` (`u32`): datum → payload +0x00 as `htonl(param_2)` (BE).
- `param_3` (`void* cb`): reply/completion callback, tag `0x1e`.
- **Returns** (`uint`): assigned sequence byte (pre-increment of conn+0x615); `0xffffffff` on failure.

## Side effects
- Alloc/free from `conn->reliable_pool` (+0x520); 4-byte BE payload; enqueue on send pool.
- `FUN_001d4d24(1, 0x1e, cb)`; increment `conn+0x615`; set `g_snap_errno` on error.

## Important branches
- `param_1 != 1 || conn == 0` → `g_snap_errno = 0x64`, return -1.
- `conn+0x50c != 0` (send-lock) → `g_snap_errno = 0x66`, return -1.
- `snap_alloc_pkt_buf(conn, 4) == 0` → `g_snap_errno = 0x65`, return -1.
- `pktbuf_reserve(buf, 4) == 0` → `subpool_free(...)`, `g_snap_errno = 0x65`, return -1.
- `snap_packet_enqueue_send(...) != 0` → `g_snap_errno = 0x66`, return -1.
- else → register cb, post-increment seq, return old seq byte.

## Constants & flags
- `0x05` — on-wire app opcode (finalizer arg-5).
- `0xb000` — who-word: `0x8000` reliable | `0x2000` | `0x1000` (DATA/who bit). Reliable send.
- `4` — payload length.
- `0x1e` — reply/completion callback tag.
- Errno `0x64`/`0x65`/`0x66` as in the shared idiom.

## Corrected reconstruction
```c
enum { WHO_RELIABLE_DATA=0xb000 };   // 0x8000 reliable | 0x2000 | 0x1000 DATA

uint snap_send_op05_data(int sel, u32 v, void *cb)   // was mis-named snap_send_create_slot
{
    snap_connection *conn = g_snap_conn;
    if (sel != 1 || conn == 0)           { g_snap_errno = 0x64; return -1; }
    if (conn->send_lock /*+0x50c*/ != 0) { g_snap_errno = 0x66; return -1; }

    void *buf = snap_alloc_pkt_buf(conn, 4);
    if (buf == 0)                        { g_snap_errno = 0x65; return -1; }

    u32 *p = pktbuf_reserve(buf, 4);
    if (p == 0) { subpool_free(conn->reliable_pool /*+0x520*/, buf);
                  g_snap_errno = 0x65; return -1; }

    *p = htonl(v);
    if (snap_packet_enqueue_send(conn, buf, WHO_RELIABLE_DATA,
                                 /*bodyLen*/4, /*opcode*/0x05,
                                 conn->seq_op05b /*+0x615*/) != 0) {
        g_snap_errno = 0x66; return -1;
    }
    FUN_001d4d24(1, 0x1e, cb);
    return conn->seq_op05b++;
}
```

## Evidence
- Raw `FUN_001dc310.c` line 30: `FUN_001e180c(iVar2,iVar3,0xb000,4,5,*(iVar2+0x615))`.
- Finalizer arg order proven by cross-family consistency: dc508 `(...,0x2c,4,...)` where 0x2c = its
  alloc/reserve size ⇒ arg-4 = length, arg-5 = opcode; dc9fc `(...,4,6,...)` = op06 join.
- cb tag `0x1e`; seq `conn+0x615`; body = `htonl(param_2)` (inline 4-term swap).
- Shared idiom matches 001d5288/001ed2c0/001e180c/001ec9e0. Runtime-unvalidated.

## Remaining uncertainty
- The app-layer meaning of op05 (and why there are `0xb000` + `0xa000` variants, dc310 vs dc804, with
  separate seq counters 0x615/0x617 and cb tags 0x1e/0x20) is unconfirmed. A live create/enter capture
  should confirm op05 role and settle whether either variant is what the create-registration flow was
  intended to mint. The name change from `create_slot` reflects the corrected on-wire opcode only.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dc310.c`  — untouched decompiler output.
