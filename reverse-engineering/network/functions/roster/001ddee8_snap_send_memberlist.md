# 0x001ddee8 snap_send_op0a_memberlist_req

| field | value |
|---|---|
| Original address | 0x001ddee8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ddee8 |
| Resolved name | snap_send_op0a_memberlist_req |
| Subsystem | roster |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520
**Referenced strings:** —
**Referenced opcodes:** 0x0a (who 0xb000)
**State vars:** conn+0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Sends the SN@P op-0x0a member-list *request* for one room. It allocates a 4-byte reliable message, writes the room id in network byte order, and enqueues it on the current connection with who-word **0xb000** (reliable 0x8000 | who 0x2000 | DATA 0x1000) and app opcode **10 (0x0a)**. On successful enqueue it registers completion callback id **0x19** with the caller's context. This is the app-layer "give me the members of room N" query whose reply drives the roster grid.

Sibling FUN_001de0c0 is identical except who-word **0xa000** (DATA bit clear) and callback **0x18**.

## Input / output
- `param_1` (int) — channel/kind selector; **must == 1** or the call is rejected (errno 100). [inferred: reliable-channel selector]
- `param_2` (uint) — room id / list key; byteswapped to big-endian into the 4-byte body.
- `param_3` (undefined4) — user completion context passed through to the callback registrar.
- **return** (u32): `0` on successful enqueue; `0xffffffff` on any rejection/failure (see errno).

## Side effects
- Allocates a message from the connection's reliable pool (`FUN_001d5288`) and a 4-byte body slice (`FUN_001ed2c0`); frees the message back to `conn+0x520` (`FUN_001ec9e0`) on the reserve-failure path.
- On enqueue success: registers completion cb **0x19** (`FUN_001d4d24(1,0x19,param_3)`).
- On any failure: sets global errno `DAT_0025b790` (see constants).
- Emits (queues) one reliable op-0x0a segment on the wire.

## Important branches
- `param_1 != 1 || conn == 0` → errno **100 (0x64)**, return -1. (bad state / no session)
- `*(conn+0x50c) != 0` (send-lock/txn busy) → errno **0x66**, return -1.
- `FUN_001d5288 == 0` (no message buffer) → errno **0x65**, return -1.
- body reserve `FUN_001ed2c0 == 0` → free message, errno **0x65**, return -1.
- enqueue `FUN_001e180c != 0` (nonzero = failure) → errno **0x66**, return -1.
- enqueue `== 0` (success) → register cb 0x19, return 0.

## Constants & flags
- `0xb000` = SN@P who-word: reliable(0x8000) | 0x2000 | DATA(0x1000). Evidence: transport who-byte facts + `FUN_001e180c` arg 3.
- `10` = app opcode 0x0a member-list. Evidence: opcode arg to `FUN_001e180c`.
- errno **0x64/100** = invalid-state, **0x65** = alloc/reserve failure, **0x66** = busy/enqueue failure. Evidence: shared with the whole `FUN_001d*/001e*` send family.
- cb **0x19** = op0a-reliable completion id.

## Corrected reconstruction
```c
// who-word bits (SN@P transport)
enum { SNAP_RELIABLE = 0x8000, SNAP_WHO_2000 = 0x2000, SNAP_DATA = 0x1000 };
// send errno (DAT_0025b790)
enum { SNAP_ERR_STATE = 0x64, SNAP_ERR_ALLOC = 0x65, SNAP_ERR_BUSY = 0x66 };

u32 snap_send_op0a_memberlist_req(int channel /*param_1*/, u32 room_id /*param_2*/,
                                  void *user_ctx /*param_3*/)
{
    snap_connection *conn = g_snap_conn;          // DAT_0025b78c
    if (channel != 1 || conn == NULL) { g_snap_errno = SNAP_ERR_STATE; return -1; }
    if (conn->send_lock /*+0x50c*/ != 0)          { g_snap_errno = SNAP_ERR_BUSY;  return -1; }

    void *msg = snap_msg_alloc(conn, 4);          // FUN_001d5288
    if (msg == NULL)                              { g_snap_errno = SNAP_ERR_ALLOC; return -1; }

    u32 *body = snap_msg_reserve(msg, 4);         // FUN_001ed2c0
    if (body == NULL) {
        snap_pool_free(conn->reliable_pool /*+0x520*/, msg);  // FUN_001ec9e0
        g_snap_errno = SNAP_ERR_ALLOC; return -1;
    }
    *body = htonl(room_id);                        // explicit byteswap in decompile

    // who = 0xb000 (reliable|0x2000|DATA), len=4, opcode=0x0a, flag=0
    long rc = snap_enqueue(conn, msg, SNAP_RELIABLE|SNAP_WHO_2000|SNAP_DATA, 4, 0x0a, 0); // FUN_001e180c
    if (rc == 0) { snap_register_completion(1, 0x19, user_ctx); return 0; }  // FUN_001d4d24
    g_snap_errno = SNAP_ERR_BUSY; return -1;
}
```

## Evidence
- Raw decompile lines 12-50 (guard, alloc, `htonl` at 27, `FUN_001e180c(...,0xb000,4,10,0)` at 29, cb `0x19` at 31).
- who/opcode mapping from the SN@P transport facts in the task brief and `snap_connection` +0x50c/+0x520 (structure-layouts/snap_connection.md).
- Runtime-unvalidated: no live trace of the reply parse tied to this send yet.

## Remaining uncertainty
- `param_1` semantics (why must be 1) — assumed reliable-channel selector shared across the send family.
- Exact meaning of who 0xb000 vs 0xa000 (sibling): DATA-bit distinguishes them; which context uses which is not runtime-confirmed.
