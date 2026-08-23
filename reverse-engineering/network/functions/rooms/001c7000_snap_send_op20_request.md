# 0x001c7000 snap_send_op20_request

| field | value |
|---|---|
| Original address | 0x001c7000 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c7000 |
| Resolved name | snap_send_op20_roomlist_page_request |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00 (snap_app_sm_pump; state 0x06)
**Callees:** FUN_001c3c90 (build_header), FUN_001c3e10 (append BE u16), FUN_001ee590 (socket send), FUN_001c3840 (commit reliable)
**Referenced globals:** 0x365e18 received-so-far; 0x365e1a page-size; conn+0x28 tx-hdr; conn+0x38 tx-len; conn+0x1c sockfd; conn+0xd next-state
**Referenced strings:** —
**Referenced opcodes:** 0x20 (room-list page request)
**State vars:** conn+0xd next-state = 0x07

## Behavioral explanation
Requests one **page of room records** (opcode 0x20) during the room-list download. The body is two BE u16 progress counters: `0x365e18` (rooms received so far — the page start index) and `0x365e1a` (page size, 8 from the header init). It transmits and advances to state 0x07, whose reply streams the records into the 0x260-stride array via FUN_001c70b0. The header parser (FUN_001c6e80) seeds these counters; FUN_001c70b0 re-arms state 0x06 to call this again until the whole list is fetched.

## Input / output
- **param_1** `snap_xfer* conn`.
- **return** `long` — 0 on commit success, else negative transport error.

## Side effects
- Builds header (op 0x20) + `u16 received || u16 page_size`; sends; on success next-state 0x07.

## Important branches
- `-2 < FUN_001c3840(conn)` -> return 0, next-state 0x07; else negative error.

## Constants & flags
- `0x20` room-list page opcode; next-state `0x07` -> FUN_001c70b0 page reader.
- args are BE u16 (not u32) — page window is small.

## Corrected reconstruction
```c
long snap_send_op20_roomlist_page_request(snap_xfer *conn)
{
    build_header(conn, /*opcode*/0x20, /*type*/1, /*flag*/0);   // FUN_001c3c90
    append_be_u16(conn, roomlist.received);     // 0x365e18  page start   FUN_001c3e10
    append_be_u16(conn, roomlist.page_size);    // 0x365e1a  page size (8)

    *(u16*)conn->tx_hdr = bswap16((u16)conn->tx_len);
    socket_send(conn->sockfd, conn->tx_hdr, conn->tx_len + 8);

    long rc = commit_reliable(conn);            // FUN_001c3840
    if (rc >= -1) { rc = 0; conn->next_state = 0x07; }
    return rc;
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001c7000.c`.
- Counters 0x365e18/0x365e1a are set by FUN_001c6e80 and advanced by FUN_001c70b0; reply chains at state 0x07.

## Remaining uncertainty
- None material for the builder; page-size is fixed at 8 by the header init but the server may return fewer.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c7000.c`  — untouched decompiler output.
