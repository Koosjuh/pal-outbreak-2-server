# 0x001e0428 snap_set_op_handler_2c

| field | value |
|---|---|
| Original address | 0x001e0428 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e0428 |
| Resolved name | snap_set_op_handler_2c |
| Subsystem | helpers |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (address-referenced entry point)
**Callees:** FUN_001d4d24 (install handler into `conn[+0x548 + op*4]`)
**Referenced globals:** 0x0025b78c (current `snap_connection*`); 0x0025b790 (errno); conn+0x50c (op lock); conn+0x548 (op-handler table)
**Referenced strings:** —
**Referenced opcodes:** transport room op 0x2c
**State vars:** conn+0x50c (op lock); DAT_0025b790 (errno)

## Behavioral explanation
Identical structure to `snap_set_op_handler_2b_enter` (0x1e0358) but registers the handler for
**transport room op 0x2c** (the op that sits between ENTER 0x2b and TRANSFER 0x2d in the room-op set;
exact room semantics not yet pinned — plausibly LEAVE/ready-ack). `FUN_001d4d24(1, 0x2c, param_2)`
writes `param_2` into `conn[+0x548 + 0x2c*4]`, returning the prior entry (ignored). Gated on session
up and no op in flight (`conn+0x50c == 0`). Sends no packet.

## Input / output
- `param_1` (`int`): channel/validity selector; must be `1`.
- `param_2` (`undefined4`): handler value stored for op 0x2c [inferred].
- Output (`undefined4`): `0` success; `0xffffffff` on error.

## Side effects
- Success: `conn->op_handler[0x2c] = param_2`.
- Error: `DAT_0025b790` = `0x66` (busy) or `0x64` (no session).

## Important branches
- `param_1 != 1 || conn == 0` -> `errno = 0x64`, return -1.
- `conn+0x50c != 0` (busy) -> `errno = 0x66`, return -1.
- else -> install handler for op 0x2c, return 0.

## Constants & flags
- `0x2c` = transport room op registered here.
- `0x66` = errno busy; `0x64` = errno no-session (see 0x1e0358).
- `conn+0x50c` = op lock; `conn+0x548` = op-handler table base.

## Corrected reconstruction
```c
#define OP_2C 0x2c

u32 snap_set_op_handler_2c(int channel, u32 handler) {
    if (channel == 1 && g_conn != NULL) {
        if (g_conn->op_lock /*+0x50c*/ == 0) {
            install_op_handler(1, OP_2C, handler);   // FUN_001d4d24
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
- Raw: `sources/executables/transport-decompile/FUN_001e0428.c` — byte-for-byte the 0x1e0358 shape
  with `FUN_001d4d24(1,0x2c,param_2)`.
- Callee semantics per `FUN_001d4d24` (op-handler table write).
- Runtime-unvalidated; op-0x2c room semantics not confirmed.

## Remaining uncertainty
- Exact room meaning of op 0x2c (LEAVE / ready / sub-op) — not resolvable from this fn alone.
- Handler value type (see 0x1e0358).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e0428.c`  — untouched decompiler output.
