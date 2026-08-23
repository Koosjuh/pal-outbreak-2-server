# 0x001de0c0 snap_send_op0a_memberlist_req_alt

| field | value |
|---|---|
| Original address | 0x001de0c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001de0c0 |
| Resolved name | snap_send_op0a_memberlist_req_alt |
| Subsystem | roster |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520
**Referenced strings:** —
**Referenced opcodes:** 0x0a (who 0xa000)
**State vars:** conn+0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Byte-for-byte the same as `snap_send_op0a_memberlist_req` (0x001ddee8) except two constants: the who-word is **0xa000** (reliable 0x8000 | who 0x2000, **DATA bit 0x1000 clear**) and the completion callback id is **0x18** instead of 0x19. It sends the op-0x0a member-list request with the room id byteswapped into a 4-byte reliable body.

**Name caveat:** the prior "unrel" label is inaccurate — both variants set the 0x8000 reliable bit. The real difference is the who-word DATA bit (0x1000): 0xb000 carries it, 0xa000 does not. This variant is the non-DATA-channel form of the same request.

## Input / output
- `param_1` (int) — channel selector; must == 1 else errno 100.
- `param_2` (uint) — room id / list key; byteswapped to BE into the body.
- `param_3` (undefined4) — completion context.
- **return**: `0` on enqueue success, `0xffffffff` otherwise.

## Side effects
- Allocs reliable message + 4-byte body; frees to `conn+0x520` on reserve failure.
- On success registers completion cb **0x18**.
- Sets `DAT_0025b790` errno on failure.
- Queues one op-0x0a segment with who 0xa000.

## Important branches
Identical to 0x001ddee8:
- `param_1 != 1 || conn == 0` → errno **0x64**, -1.
- `conn+0x50c != 0` → errno **0x66**, -1.
- alloc/reserve fail → errno **0x65**, -1 (reserve fail frees msg first).
- enqueue fail (rc != 0) → errno **0x66**, -1; success (rc == 0) → cb 0x18, return 0.

## Constants & flags
- `0xa000` = reliable(0x8000) | who(0x2000); DATA(0x1000) **clear**. Evidence: `FUN_001e180c` arg 3.
- opcode `10` (0x0a). cb `0x18`. errno set {0x64,0x65,0x66} as in the send family.

## Corrected reconstruction
```c
u32 snap_send_op0a_memberlist_req_alt(int channel /*param_1*/, u32 room_id /*param_2*/,
                                      void *user_ctx /*param_3*/)
{
    snap_connection *conn = g_snap_conn;          // DAT_0025b78c
    if (channel != 1 || conn == NULL) { g_snap_errno = SNAP_ERR_STATE; return -1; }
    if (conn->send_lock /*+0x50c*/ != 0)          { g_snap_errno = SNAP_ERR_BUSY;  return -1; }

    void *msg = snap_msg_alloc(conn, 4);
    if (msg == NULL)                              { g_snap_errno = SNAP_ERR_ALLOC; return -1; }

    u32 *body = snap_msg_reserve(msg, 4);
    if (body == NULL) {
        snap_pool_free(conn->reliable_pool /*+0x520*/, msg);
        g_snap_errno = SNAP_ERR_ALLOC; return -1;
    }
    *body = htonl(room_id);

    // NOTE: who = 0xa000 (reliable|0x2000, DATA bit CLEAR) — the only diff vs 0x001ddee8
    long rc = snap_enqueue(conn, msg, SNAP_RELIABLE|SNAP_WHO_2000, 4, 0x0a, 0);
    if (rc == 0) { snap_register_completion(1, 0x18, user_ctx); return 0; }  // cb 0x18
    g_snap_errno = SNAP_ERR_BUSY; return -1;
}
```

## Evidence
- Raw decompile: `FUN_001e180c(...,0xa000,4,10,0)` at line 29, cb `0x18` at line 32; otherwise identical structure to 0x001ddee8.
- who-bit semantics from SN@P transport facts (0x1000 = DATA).
- Runtime-unvalidated.

## Remaining uncertainty
- Which caller context selects 0xa000 vs 0xb000 (and the 0x18 vs 0x19 completion split) — no xref/trace captured. Both are member-list requests.
