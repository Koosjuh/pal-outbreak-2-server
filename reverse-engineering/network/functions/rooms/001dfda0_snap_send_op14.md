# 0x001dfda0 snap_send_op14

| field | value |
|---|---|
| Original address | 0x001dfda0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dfda0 |
| Resolved name | snap_send_op14_seq |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d5288 (seg-alloc), FUN_001ed2c0 (payload-reserve), FUN_001ec9e0 (seg-free), FUN_001069a8 (memcpy), FUN_001e180c (frame+enqueue), FUN_001d4d24 (register completion)
**Referenced globals:** 0x0025b78c (`snap_connection*`); 0x0025b790 (errno); conn+0x50c (send-lock); conn+0x520 (pool); **conn+0x621 (send-seq byte)**
**Referenced opcodes:** 0x14 (data message with op28 completion)
**State vars:** conn+0x50c send-lock; conn+0x621 send-seq; DAT_0025b790 errno

## Behavioral explanation
Sends an **unreliable op-0x14 data message that carries a completion sequence**. It copies a `param_4`-length blob into a fresh segment and enqueues it with who = `param_2 | 0x2000`, opcode 0x14, and — unlike the op10 senders — passes the current send-seq byte `conn[0x621]` as the frame's cb/seq field. On successful enqueue it registers an op28 completion callback (tag **0x28**, arg param_5), post-increments `conn[0x621]`, and **returns the send-seq that was used** (0..0xff). This is the classic "message whose op28 reply SUB-byte echoes the send-seq" pattern used for send/ack matching (cf. FACTS: op28 completion = SUB echoes op06/op14 send-seq).

## Input / output
- `param_1` (int) — channel token; must be 1.
- `param_2` (u16) — who-flags, OR-ed with 0x2000.
- `param_3` (void*) — blob source.
- `param_4` (u32) — blob length (also used as u16 reserve size `uStack_34`).
- `param_5` — completion-callback context passed to the op28 registration.
- **return** (u32) — on success the **send-seq byte** used (0..255); `0xFFFFFFFF` on failure.

## Side effects
- Reserves/(on fail)frees a segment on `conn->reliable_pool`.
- Registers a pending op28 completion via `FUN_001d4d24(1, 0x28, param_5)`.
- **Increments `conn[0x621]`** (the per-message send-seq) on success.
- DAT_0025b790 on failure.

## Important branches
- `chan!=1 || conn==0` → errno 100, -1.
- `+0x50c != 0` → errno 0x66, -1.
- alloc fail → errno 0x65, -1.
- reserve fail → free seg, errno 0x65, -1.
- enqueue ok → register cb 0x28, seq++, return old seq; else errno 0x66, -1.

## Constants & flags
- who `0x2000` (unreliable class).
- completion tag `0x28` (op28 reply matcher).
- send-seq at `conn+0x621` (u8, wraps 0xff→0x00).
- errno 0x64/0x65/0x66.

## Corrected reconstruction
```c
u32 snap_send_op14_seq(int chan, u16 who, void *blob, u32 blob_len, void *cb_ctx)
{
    snap_connection *conn = DAT_0025b78c;
    if (chan != 1 || conn == 0)          { DAT_0025b790 = 100;  return -1; }
    if (conn->send_lock /*+0x50c*/ != 0) { DAT_0025b790 = 0x66; return -1; }

    int seg = seg_alloc(conn, blob_len);
    if (seg == 0)                        { DAT_0025b790 = 0x65; return -1; }

    u16 len = (u16)blob_len;
    void *p = seg_reserve(seg, len);
    if (p == 0) { seg_free(conn->reliable_pool, seg); DAT_0025b790 = 0x65; return -1; }

    memcpy_(p, blob, blob_len);
    long rc = frame_enqueue(conn, seg, who | 0x2000, len, 0x14,
                            conn->send_seq /*+0x621*/);   // seq stamped into frame
    if (rc == 0) {
        register_completion(1, 0x28, cb_ctx);             // FUN_001d4d24
        u8 seq = conn->send_seq;
        conn->send_seq = seq + 1;                          // post-increment
        return seq;                                        // caller matches op28 SUB to this
    }
    DAT_0025b790 = 0x66; return -1;
}
```

## Evidence
- Raw: `FUN_001dfda0.c` (lines 32-39): FUN_001e180c 6th arg = `*(u8*)(conn+0x621)`, opcode 0x14; then `FUN_001d4d24(1,0x28,param_5)`, `conn[0x621]++`, returns old byte.
- Struct/FACTS: op28 completion echoes send-seq (memory `g2-completion-is-sub-byte-echo`); conn+0x618/0x621 seq family in snap_connection notes.

## Remaining uncertainty
- op14 payload semantics (chat vs game-data) not runtime-confirmed; conn+0x621 vs +0x618 seq roles not fully separated. Helper names inferred.
