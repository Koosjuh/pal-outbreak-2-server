# 0x001c67b0 snap_send_op28_reply

| field | value |
|---|---|
| Original address | 0x001c67b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c67b0 |
| Resolved name | snap_send_op28_request |
| Subsystem | session |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00 (transport recv/send FSM pump)
**Callees:** FUN_001c3c90 (begin_tx), FUN_001ee590 (net_sendto), FUN_001c3840 (tx_commit — stub)
**Referenced globals:** conn+0x1c socket fd; conn+0x28 tx-header ptr; conn+0x38 tx-length; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x28
**State vars:** conn+0xd next-state = 0x24

## Behavioral explanation
Body-less SN@P reliable frame carrying application opcode **0x28** — the client-side op28 message. Builds the bare 8-byte frame (no extra body appended at this layer), transmits it, and on success advances the dispatch state (`conn+0xd`) to **0x24**. This is the transport-level *builder* only: the op28 completion semantics that matter to the lobby (per FACTS, the op28 reply's sub-byte echoes the op06 send-seq, `push[2]==msg[2]`) are stamped upstream into the header's seq/echo bytes by `begin_tx` and the caller — they are not visible in this bare builder, which just frames + sends whatever the header already holds. Same transmit idiom as the body-less request senders.

## Input / output
- **param_1** `snap_connection*` — active transport connection.
- **returns** `long`: `0` on success (state → 0x24); negative `tx_commit` code on failure (state unchanged).

## Side effects
- Builds tx header at `*(conn+0x28)` with opcode 0x28 class bytes, reliable seq (`conn+0x3d++`), payload length 0; resets `conn+0x38`.
- Sends one datagram of `payload_len + 8` bytes on `conn+0x1c`.
- On success sets `conn+0xd = 0x24`.

## Important branches
- `tx_commit() > -2` → `rc = 0`, `conn+0xd = 0x24`.
- else → return negative code, leave state unchanged.

## Constants & flags
- App opcode **0x28**; `who = 1` reliable (`begin_tx` stamps header[5] = `conn+0x3d++`); next state **0x24**; header overhead 8 bytes.

## Corrected reconstruction
```c
// Body-less SN@P frame, opcode 0x28. Reliable. Advances FSM to state 0x24.
// The op06-seq echo that drives op28 completion is written into the header
// upstream (begin_tx seq / caller), not here.
long snap_send_op28_request(snap_connection *conn)
{
    begin_tx(conn, /*opcode=*/0x28, /*who=*/1, /*flag=*/0);      // FUN_001c3c90
    *(u16 *)conn->tx_hdr = bswap16((u16)conn->tx_len);           // len big-endian (0)
    net_sendto(conn->fd, conn->tx_hdr, (short)conn->tx_len + 8); // FUN_001ee590
    long rc = tx_commit(conn);                                   // FUN_001c3840
    if (rc > -2) { rc = 0; conn->next_state = 0x24; }
    return rc;
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001c67b0.c`.
- Byte-identical control flow to the sibling body-less senders except `begin_tx` opcode (0x28) and the state constant (`conn+0xd = 0x24`).
- op28 completion = sub-byte echo of op06 send-seq: FACTS / memory `g2-completion-is-sub-byte-echo` (push[2]==msg[2]); the echo lives in header[5], stamped before this builder runs.

## Remaining uncertainty
- Whether opcode 0x28 here is the "reply" or an equal-and-opposite client "request" is naming only; renamed to `_request` because the builder emits (client→server) rather than parses. The seq/echo value it carries is set upstream and not observable in this function. `tx_commit` return convention inferred (stub decompile). Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c67b0.c`  — untouched decompiler output.
