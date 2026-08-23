# 0x001e04f8 snap_set_op_handler_2d_transfer

| field | value |
|---|---|
| Original address | 0x001e04f8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e04f8 |
| Resolved name | snap_set_op_handler_2d_transfer |
| Subsystem | helpers |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (address-referenced entry point)
**Callees:** FUN_001d4d24 (install handler into `conn[+0x548 + op*4]`)
**Referenced globals:** 0x0025b78c (current `snap_connection*`); 0x0025b790 (errno); conn+0x50c (op lock); conn+0x548 (op-handler table)
**Referenced strings:** —
**Referenced opcodes:** transport room op 0x2d (TRANSFER)
**State vars:** conn+0x50c (op lock); DAT_0025b790 (errno)

## Behavioral explanation
Third member of the op-handler-registration family; registers the handler for **transport room op
0x2d (TRANSFER / host-migration)**. `FUN_001d4d24(1, 0x2d, param_2)` writes `param_2` into
`conn[+0x548 + 0x2d*4]`, returning the prior entry (ignored). Same session/op-lock gate as 0x1e0358
and 0x1e0428; sends no packet. Together the three functions install the completion handlers for the
ENTER(0x2b)/0x2c/TRANSFER(0x2d) room ops before those ops are driven elsewhere.

## Input / output
- `param_1` (`int`): channel/validity selector; must be `1`.
- `param_2` (`undefined4`): handler value stored for op 0x2d [inferred].
- Output (`undefined4`): `0` success; `0xffffffff` on error.

## Side effects
- Success: `conn->op_handler[0x2d] = param_2`.
- Error: `DAT_0025b790` = `0x66` (busy) or `0x64` (no session).

## Important branches
- `param_1 != 1 || conn == 0` -> `errno = 0x64`, return -1.
- `conn+0x50c != 0` (busy) -> `errno = 0x66`, return -1.
- else -> install handler for op 0x2d, return 0.

## Constants & flags
- `0x2d` = transport room op TRANSFER (this fn's op slot).
- `0x66` = errno busy; `0x64` = errno no-session.
- `conn+0x50c` = op lock; `conn+0x548` = op-handler table base.

## Corrected reconstruction
```c
#define OP_TRANSFER 0x2d

u32 snap_set_op_handler_2d_transfer(int channel, u32 handler) {
    if (channel == 1 && g_conn != NULL) {
        if (g_conn->op_lock /*+0x50c*/ == 0) {
            install_op_handler(1, OP_TRANSFER, handler);   // FUN_001d4d24
            return 0;
        }
        g_snap_errno = SNAP_EBUSY;   // 0x66
        return (u32)-1;
    }
    g_snap_errno = SNAP_ENOSESS;     // 0x64
    return (u32)-1;
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001e04f8.c` — the 0x1e0358 shape with
  `FUN_001d4d24(1,0x2d,param_2)`.
- op 0x2d = TRANSFER per the transport room-op set (task header).
- Runtime-unvalidated.

## Remaining uncertainty
- Whether TRANSFER here is host-migration vs. slot-transfer; exact handler value type (see 0x1e0358).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e04f8.c`  — untouched decompiler output.
