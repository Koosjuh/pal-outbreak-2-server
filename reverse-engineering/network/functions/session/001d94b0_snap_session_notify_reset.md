# 0x001d94b0 snap_session_notify_reset

| field | value |
|---|---|
| Original address | 0x001d94b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d94b0 |
| Resolved name | snap_session_notify_timeout |
| Subsystem | session |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d7104 (handshake pump — every timeout leg)
**Callees:** — (indirect call through conn+0x5b8 session-result callback)
**Referenced globals:** conn+0x5b8 = session-result callback ptr; conn+0x7c = last-progress ts; conn+0x80 = handshake state
**Referenced strings:** —
**Referenced opcodes:** 0x27 (synthesized session-result event, delivered to the app callback)
**State vars:** conn+0x80 (reset to 0); conn+0x7c (reset to 0)

## Behavioral explanation
Delivers a **synthetic session-result event with status `0x14` (timeout/failure)** to the app-layer callback at `conn+0x5b8`, then hard-resets the handshake state machine. It builds two adjacent stack records shaped like a received SN@P control message and passes their addresses to the callback:

- **header block** (`&uStack_30`): `op = 0x27` (the SN@P session-result/status opcode), reserved zeros, `len = 8`, `who = 0x1000` (DATA) — i.e. it forges the framing of an inbound op27 with no real peer data.
- **payload block** (`&uStack_20`): `field = 1`, `status = 0x14`.

After invoking the callback (only if one is registered), it zeroes `conn+0x7c` (last-progress timestamp) and `conn+0x80` (handshake state) — dropping the connection back to the idle/closed handshake state so the upper layer can re-drive or abandon it.

Because it's called from every timeout branch of `snap_handshake_pump`, this is the "the establish handshake gave up" path — the client-side origin of the `0x14`-class session failure surfaced to the overlay (distinct from the peer-delivered success notify `snap_session_notify_peer`, which uses status `1`).

## Input / output
- **Param:** `param_1` (`conn`) — transport connection object.
- **Returns:** `void`.

## Side effects
- If `conn+0x5b8 != 0`: `cb(&header{op=0x27,len=8,who=0x1000}, &payload{1, 0x14})`.
- `conn+0x7c = 0`, `conn+0x80 = 0` (handshake reset to idle).

## Important branches
- `conn+0x5b8 != 0` → invoke callback; else skip (still resets state).

## Constants & flags
- synthesized event op `0x27` (session-result/status).
- `len = 8`, `who = 0x1000` (DATA bit).
- payload `{1, 0x14}` — status `0x14` = handshake timeout/failure.
- reset: `conn+0x7c = 0`, `conn+0x80 = 0`.

## Corrected reconstruction
```c
// Synthetic op-0x27 session-result event (matches the inbound-message shape the
// app callback expects), status 0x14 = handshake timeout.
struct snap_evt_hdr { u8 op; u8 r0; u16 r1; u16 len; u16 who; u32 z0; u32 z1; };
struct snap_evt_pl  { u32 field; u32 status; };

void snap_session_notify_timeout(snap_connection *conn) {
    struct snap_evt_hdr h = { .op = 0x27, .r0 = 0, .r1 = 0,
                              .len = 8, .who = 0x1000, .z0 = 0, .z1 = 0 };
    struct snap_evt_pl  p = { .field = 1, .status = 0x14 };

    if (conn->result_cb /*+0x5b8*/ != 0)
        conn->result_cb(&h, &p);

    conn->last_ts  = 0;   // +0x7c
    conn->hs_state = 0;   // +0x80  (reset handshake)
}
```

## Evidence
- Decompile `FUN_001d94b0.c`: stack fields `uStack_30=0x27, uStack_2c=8, uStack_2a=0x1000, uStack_20=1, uStack_1c=0x14`; `if (*(conn+0x5b8)!=0) (*cb)(&uStack_30,&uStack_20)`; `conn+0x7c=0; conn+0x80=0`.
- Twin of `snap_session_notify_peer` (0x001d9550): identical header shape and callback slot, differing status (`0x14` vs `1`).
- Op `0x27` matches GLOBALS `0x0025b790` "last-error (0x27 result)"; status `0x14`(=20) is the session-result error class.
- Runtime-unvalidated.

## Remaining uncertainty
- Exact field semantics of the payload `{1, 0x14}` — `1` inferred as a result-kind/selector, `0x14` as the status.
- Whether the callback consumes the header as a real datagram or just reads status; the shape is forged to satisfy the same parser as `snap_session_notify_peer`.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d94b0.c`  — untouched decompiler output.
