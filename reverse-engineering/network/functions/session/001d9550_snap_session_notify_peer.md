# 0x001d9550 snap_session_notify_peer

| field | value |
|---|---|
| Original address | 0x001d9550 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d9550 |
| Resolved name | snap_session_notify_connected |
| Subsystem | session |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78 (app-message dispatch — on the connect/open reply)
**Callees:** FUN_001d507c (record peer port)
**Referenced globals:** conn+0x5b8 = session-result callback ptr; conn+0x7c = last-progress ts; conn+0x80 = handshake state
**Referenced strings:** —
**Referenced opcodes:** 0x27 (synthesized session-result event, delivered to the app callback)
**State vars:** conn+0x80 (reset to 0); conn+0x7c (reset to 0)

## Behavioral explanation
Delivers a **synthetic session-result event with status `1` (connected/success)**, carrying the peer's address, to the app callback at `conn+0x5b8`, then resets the handshake state. `param_2` is the parsed connect/open reply datagram; the function pulls peer fields out of it:

- **header block** (`&uStack_40`): `op = 0x27` (session-result), `len = 8`, `who = 0x1000` (DATA), plus a copied peer field `*(param_2+0x30)` and a byteswapped port `bswap32(*(param_2+0x40))`.
- **payload block** (`&uStack_30`): `status = 1`, and `ptr = param_2 + 0x3c` (pointer to the peer address/handle struct inside the reply).

It first records the peer port with `FUN_001d507c(conn, 0, *(u16 *)(param_2+0x3c))`, then (if a callback is registered) invokes it with the two blocks, and finally zeroes `conn+0x7c` / `conn+0x80`.

This is the **success twin** of `snap_session_notify_timeout` (0x001d94b0): same op-0x27 event shape and same callback slot, but status `1` and it forwards the peer address — the client-side "connection established, here is who we're talking to" notification the overlay consumes to move past the connect phase. It is invoked from the received-message dispatcher when the connect reply (op 0x2a family) validates.

## Input / output
- **Params:** `param_1` (`conn`) — transport connection; `param_2` — parsed connect-reply datagram (peer field `+0x30`, addr struct `+0x3c`, port `+0x40`).
- **Returns:** `void`.

## Side effects
- `FUN_001d507c(conn, 0, *(u16 *)(param_2+0x3c))` — records the peer port/addr.
- If `conn+0x5b8 != 0`: `cb(&header{op=0x27,...,peer,port}, &payload{status=1, &addr})`.
- `conn+0x7c = 0`, `conn+0x80 = 0` (handshake reset — establish complete).

## Important branches
- `conn+0x5b8 != 0` → invoke callback; else skip (still records port + resets state).

## Constants & flags
- synthesized event op `0x27`; `len = 8`; `who = 0x1000` (DATA).
- payload status `1` = connected/success (vs `0x14` timeout in the twin).
- peer fields: reply `+0x30` (peer id/field), `+0x3c` (addr struct ptr), `+0x40` (port, byteswapped).

## Corrected reconstruction
```c
struct snap_evt_hdr { u8 op; u8 r0; u16 r1; u16 len; u16 who; u32 peer; u32 z0; u32 port; };
struct snap_evt_pl  { u32 status; void *addr; };

void snap_session_notify_connected(snap_connection *conn, connect_reply *rep) {
    struct snap_evt_hdr h = {
        .op   = 0x27, .r0 = 0, .r1 = 0, .len = 8, .who = 0x1000,
        .peer = rep->peer  /*+0x30*/, .z0 = 0,
        .port = bswap32(rep->port /*+0x40*/),
    };
    struct snap_evt_pl p = { .status = 1, .addr = &rep->addr /*+0x3c*/ };

    record_peer_port(conn, 0, *(u16 *)&rep->addr /*+0x3c*/);   // FUN_001d507c

    if (conn->result_cb /*+0x5b8*/ != 0)
        conn->result_cb(&h, &p);

    conn->last_ts  = 0;   // +0x7c
    conn->hs_state = 0;   // +0x80  (establish complete)
}
```

## Evidence
- Decompile `FUN_001d9550.c`: `uStack_40=0x27, uStack_38=*(param_2+0x30), uStack_3c=8, uStack_3a=0x1000, uStack_30=1, puStack_20=param_2+0x3c, uStack_2c=bswap(*(param_2+0x40))`; `FUN_001d507c(param_1,0,*puStack_20)`; `if (*(conn+0x5b8)!=0)(*cb)(&uStack_40,&uStack_30)`; `conn+0x7c=0; conn+0x80=0`.
- Caller `FUN_001d9f78` (app dispatch) delivers this on the connect reply; twin of `snap_session_notify_timeout` (status 1 vs 0x14). `FUN_001d507c` shared with `snap_build_prepare_msg`'s peer-record step.
- Runtime-unvalidated.

## Remaining uncertainty
- Exact layout of the connect-reply struct `param_2` (fields at +0x30/+0x3c/+0x40) — named from usage; produced by the op-0x2a connect-reply parser (`FUN_001d9678`).
- Payload `status = 1` vs the peer/addr pointer contract expected by the overlay's `conn+0x5b8` handler.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d9550.c`  — untouched decompiler output.
