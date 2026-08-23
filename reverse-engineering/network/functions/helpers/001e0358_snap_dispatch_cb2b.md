# 0x001e0358 snap_set_op_handler_2b_enter

| field | value |
|---|---|
| Original address | 0x001e0358 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e0358 |
| Resolved name | snap_set_op_handler_2b_enter |
| Subsystem | helpers |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (address-referenced entry point)
**Callees:** FUN_001d4d24 (install handler into conn op-handler table `conn[+0x548 + op*4]`)
**Referenced globals:** 0x0025b78c (DAT — current `snap_connection*`); 0x0025b790 (DAT — last-error code); conn+0x50c (busy/op-in-progress lock); conn+0x548 (op-handler table base)
**Referenced strings:** —
**Referenced opcodes:** transport room op 0x2b (ENTER)
**State vars:** conn+0x50c (send/op lock); DAT_0025b790 (errno)

## Behavioral explanation
Registers the caller's completion handler for **transport room op 0x2b (ENTER)**. This is the
corrected reading: `FUN_001d4d24(1, 0x2b, param_2)` does **not** send a packet — it writes `param_2`
(the handler value) into the connection's op-handler table at `conn[+0x548 + 0x2b*4]`, returning the
previous entry (ignored here). The function is gated: the session must be up (`conn != 0`) and no op
may be in flight (`conn+0x50c == 0`). On success returns 0; if an op is already pending it sets errno
`0x66` and returns -1; if there is no session it sets errno `0x64` (100) and returns -1. `param_1`
must equal 1 (a channel/validity selector) or the call is treated as "no session".

One of a three-function family (0x2b/0x2c/0x2d) that differ only by the op index they register —
matching the transport room-op trio ENTER(0x2b)/0x2c/TRANSFER(0x2d).

## Input / output
- `param_1` (`int`): channel/validity selector; must be `1`.
- `param_2` (`undefined4`): the handler value stored for op 0x2b (function pointer or context token) [inferred].
- Output (`undefined4`): `0` on success; `0xffffffff` (-1) on error (see errno).

## Side effects
- On success: `conn->op_handler[0x2b] = param_2` (via `conn[+0x548 + 0x2b*4]`).
- On error: writes `DAT_0025b790` (errno) = `0x66` (op busy) or `0x64` (no session). No packets sent.

## Important branches
- `param_1 != 1 || DAT_0025b78c == 0` (no session/bad channel) -> `errno = 0x64`, return -1.
- `conn+0x50c != 0` (an op is already in progress) -> `errno = 0x66`, return -1.
- `conn+0x50c == 0` (idle) -> install handler for op 0x2b, return 0.

## Constants & flags
- `0x2b` = transport room op ENTER (this fn's op slot).
- `0x66` (102) = errno "operation already in progress / busy" (evidence: set when `+0x50c != 0`).
- `0x64` (100) = errno "no session / not ready" (evidence: set when `conn==0` or `param_1!=1`).
- `conn+0x50c` = single-outstanding-op lock (0 = idle) — matches the "pool-guarded +0x50c" create/prepare gate.
- `conn+0x548` = base of the per-op handler table (indexed `op*4`).

## Corrected reconstruction
```c
#define g_conn        (*(struct snap_connection **)0x0025b78c)  // DAT_0025b78c
#define g_snap_errno  (*(u32 *)0x0025b790)                       // DAT_0025b790
#define SNAP_EBUSY    0x66      // op already in progress
#define SNAP_ENOSESS  0x64      // no session / not ready
#define OP_ENTER      0x2b

// conn->op_handler[op]  ==  *(u32*)(conn + 0x548 + op*4)
// FUN_001d4d24(1, op, val): op_handler[op] = val; returns previous (ignored here).

u32 snap_set_op_handler_2b_enter(int channel, u32 handler) {
    if (channel == 1 && g_conn != NULL) {
        if (g_conn->op_lock /*+0x50c*/ == 0) {
            install_op_handler(1, OP_ENTER, handler);   // FUN_001d4d24
            return 0;
        }
        g_snap_errno = SNAP_EBUSY;
        return (u32)-1;
    }
    g_snap_errno = SNAP_ENOSESS;
    return (u32)-1;
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001e0358.c` — the `param_1==1 && DAT_0025b78c!=0`
  gate, the `conn+0x50c==0` lock check, `FUN_001d4d24(1,0x2b,param_2)`, and the `0x66`/`100` errno writes.
- Callee `FUN_001d4d24` confirmed to write `*(conn + param_2*4 + 0x548) = param_3` and return the prior value.
- op 0x2b = ENTER per the transport room-op set (task header / PACKET_INDEX).
- Runtime-unvalidated.

## Remaining uncertainty
- Whether `param_2` is a raw function pointer, a callback context, or a small handler id.
- Whether registration also implicitly arms the ENTER op elsewhere (no send happens in THIS fn).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e0358.c`  — untouched decompiler output.
