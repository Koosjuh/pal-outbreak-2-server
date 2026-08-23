# 0x001c6330 snap_send_op31_finalize

| field | value |
|---|---|
| Original address | 0x001c6330 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c6330 |
| Resolved name | snap_send_op31_finalize |
| Subsystem | lobby |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00 (download-FSM step dispatcher)
**Callees:** FUN_001c3c90 (hdr_begin), FUN_001ee590 (transmit), FUN_001c3840 (flush/no-op)
**Referenced globals:** conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x31 (download finalize/ack, machines D & E)
**State vars:** conn+0xd next-state = 0x40

## Behavioral explanation
Emits a body-less opcode-0x31 message and transmits it, then advances the FSM to `0x40`. `0x31` is the
download-complete / finalize request that both machine D (`recv_download_chunk_D` → 0x31 on the
create path) and machine E (`recv_download_chunk_E` → 0x31 when the last slot is drained) hand control
to. There is no payload: the opcode itself signals "transfer done, proceed". The follow-on state `0x40`
is the first step of the op45/op47 single-buffer download machine (F) — i.e. after finishing the big
transfer the FSM chains straight into the small-buffer download.

## Input / output
- **param_1** = `snap_dl_conn *conn`.
- **returns** `long` — 0 on success, else negative from the transmit path.

## Side effects
- Builds an empty reliable 0x31 message (header only, cursor length 0), sets header length word,
  transmits via `FUN_001ee590`.
- On success sets `conn+0xd = 0x40`.

## Important branches
- `if (-2 < flushResult)` → success: return 0 and set next-state 0x40. (Stub flush → always taken.)

## Constants & flags
- `0x31` — download-finalize opcode.
- `0x40` — next FSM state (entry into the op45/op47 machine F).
- hdr_begin `type=1` — reliable, seq-numbered.

## Corrected reconstruction
```c
#define OP_DL_FINALIZE 0x31
#define ST_DL_F_ENTRY  0x40

long snap_send_op31_finalize(snap_dl_conn *conn)
{
    snap_hdr_begin(conn, OP_DL_FINALIZE, /*type=*/1, /*flag=*/0);   // no payload
    *(u16 *)conn->tx_hdr = bswap16((u16)conn->tx_cursor);          // length (== 0 body)
    snap_transmit(conn->tx_handle, conn->tx_hdr, conn->tx_cursor + 8);

    long r = snap_flush(conn);
    if (r >= -1) { r = 0; conn->fsm_state = ST_DL_F_ENTRY; }       // conn+0xd = 0x40
    return r;
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001c6330.c`.
- hdr_begin/transmit/flush primitives read directly (see 001c6060 record).
- 0x31 as the common terminal target confirmed from FUN_001c6130 (D finalize) and FUN_001c65c0 (E
  finalize) both setting next-state 0x31.
- Confidence **High**; runtime **unvalidated**.

## Remaining uncertainty
- Whether 0x31 carries an implicit ack the peer must acknowledge, or is fire-and-forget before the
  0x40/op45 phase. State chaining (0x40) is confirmed; the peer-side semantics are inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c6330.c` — untouched decompiler output.
