# 0x001c45f0 recv_reply_u32_36847c

| field | value |
|---|---|
| Original address | 0x001c45f0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c45f0 |
| Resolved name | recv_reply_u32_36847c |
| Subsystem | session |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (dispatched by the transport FSM pump via conn+0xd)
**Callees:** FUN_001c3b10 (read_u32_be)
**Referenced globals:** 0x36847c (u32 session parameter); conn[0] fsm major-state (u32); conn+0x30 peer/rx-ctrl ptr (+6 = who/flag byte); conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** — (reply consumer; state-dispatched)
**State vars:** conn[0] fsm major-state; conn+0xd next-state = 0x0e / 0x2d / 0x31

## Behavioral explanation
A one-field reply handler that **routes the next state by the connection's major fsm-state** (`conn[0]`, a u32). It first stores the reply value into `0x36847c`: **0** on an empty/keepalive frame (`peer[6] == 0xff`), else one big-endian **u32** decoded from RX. Then it selects the next dispatch state:
- fsm-state **7, 0, or 1** → **0x0e** (the common login-continuation branch),
- fsm-state **2** → **0x2d** (a room-transfer branch; cf. transport room op 0x2d transfer),
- any other → **0x31**.
This makes the same reply frame steer three different downstream flows depending on where in the session lifecycle it arrives.

## Input / output
- **param_1** `snap_connection*` (as `int*`) — active connection; `conn[0]` = fsm major-state, RX holds the reply.
- **returns** `undefined8` `0` (result via global + state advance).

## Side effects
- Writes global `0x36847c` (u32) = 0 or decoded value.
- On decode, `read_u32_be` advances the RX cursor `conn+0x40` by 4.
- Sets `conn+0xd` to 0x0e / 0x2d / 0x31.

## Important branches
- `peer[6] == -1` (empty) → `0x36847c = 0`; else `0x36847c = read_u32_be(conn)`.
- `conn[0] ∈ {7,0,1}` → `conn+0xd = 0x0e`.
- `conn[0] == 2` → `conn+0xd = 0x2d`.
- else → `conn+0xd = 0x31`.

## Constants & flags
- `peer[6] == 0xff` = empty/keepalive reply sentinel.
- Next-state routing: `{0,1,7}→0x0e`, `2→0x2d`, `default→0x31`.

## Corrected reconstruction
```c
// One-field reply consumer with fsm-state-dependent routing.
undefined8 recv_reply_u32_36847c(snap_connection *conn)
{
    rx_ctrl *peer = conn->peer /*+0x30*/;
    if (peer->flag /*+6*/ == (char)0xff)
        g_param_36847c = 0;
    else
        g_param_36847c = read_u32_be(conn);          // FUN_001c3b10

    switch (conn->fsm_state /*conn[0]*/) {
        case 7: case 0: case 1: conn->next_state = 0x0e; break;
        case 2:                 conn->next_state = 0x2d; break;   // room-transfer branch
        default:                conn->next_state = 0x31; break;
    }
    return 0;
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001c45f0.c`.
- `FUN_001c3b10` = big-endian u32 reader → `0x36847c` is u32.
- `param_1[0xc]` used for the empty-frame test is `conn+0x30` (peer ptr); `*param_1` (conn[0]) is the fsm major-state word tested for the 3-way branch.
- 0x2d aligns with the transport room "transfer" op (0x2d) noted in the task's op map, consistent with the `state==2` room path.

## Remaining uncertainty
- Meaning of parameter `0x36847c` and the exact identity of the 0x0e/0x2d/0x31 target handlers are unresolved; the routing logic itself is exact. Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c45f0.c`  — untouched decompiler output.
