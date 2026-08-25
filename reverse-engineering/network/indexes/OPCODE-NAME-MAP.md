# SN@P opcode ↔ middleware-name map (corpus index, added 2026-08-24)

Maps our numeric op labels to the SNAP middleware's own command names, sourced from the
Auto Modellista client's callback tables (openSNAP `protocol/commands.py`, derived from
SLUS_206.42 `jpt_kkCommand` @0x003AC280 / `kkSetCallBackFunction` @0x002E9C70) and graded
against OUR PAL (SLES_533.19) evidence. Reference docs:
`docs/findings/protocol/OPENSNAP-CROSSREF-2026-08-24.md` (mapping + framing),
`docs/findings/protocol/OPENSNAP-DEEP-DIVE-2026-08-24.md` (byte-level behaviors),
vendored source `references/external_repos/openSNAP` (AGPL — facts usable, code no-copy).

Grades: **PAL-Confirmed** = our own decompile/wire evidence matches the name's semantics ·
**AM-Inference** = named only by the AM tables; PAL check pending · **PAL-Divergent** =
PAL demonstrably differs from the AM meaning.

| Op | SNAP name (AM) | Grade | PAL evidence / note |
|---|---|---|---|
| 0x00 | CMD_ACK (bare transport ack) | PAL-Confirmed | our 20-byte `0x6010` frames; L1 spec §4 |
| 0x01 | CMD_LOGIN_TO_KICS | AM-Inference | KICS = the KDDI service — names the Bioserver kinship |
| 0x02 | CMD_LOGOUT_CLIENT | PAL-Confirmed (role) | our op-0x02 session close at client give-up (T37, B3) |
| 0x04 | CMD_CREATE_GAME_ROOM | PAL-Confirmed | op04 create-slot mints the room (G12, FUN_005c3a40 cb) |
| 0x05 | CMD_DELETE (lobby/room by 0x1000) | AM-Inference | channel split PAL-Confirmed at the dispatcher (see below) |
| 0x06 | CMD_JOIN (lobby/room by 0x1000) | PAL-Confirmed | dual forms observed; DATA-clear room-ENTER → slot 0x22 (v2 join ladder) |
| 0x07 | CMD_LEAVE (lobby/room by 0x1000) | PAL-Confirmed | matched pair FUN_001dd07c (0xb000, slot 0x23) / FUN_001dd1dc (0xa000, slot 0x24); `analysis/op28-channel-bit-dispatch-2026-08-24.md` |
| 0x08 | CMD_CHANGE_ATTRIBUTE | PAL-Confirmed (role) | our "STAT@" named-channel query; sel-8 completion → slot 0x25 |
| 0x09 | CMD_QUERY_ATTRIBUTE | PAL-Confirmed (role) | our op09 USER/MAXI count queries |
| 0x0A | CMD_QUERY_USER | PAL-Confirmed | op0a member-list (record layout PAL-specific) |
| 0x0B | CMD_QUERY_GAME_ROOMS | AM-Inference | candidate semantic; PAL room list observed on 0x49 instead |
| 0x0E | CMD_QUERY_LOBBIES | AM-Inference | |
| 0x0F | CMD_SEND (chat/game by 0x0400+ctx) | PAL-Confirmed | chat = 0xA4xx room / 0xB4xx area (v2 RS1 fix); 0x0400-clear = game channel |
| 0x10 | CMD_SEND_TARGET (payload subcommands) | PAL-Confirmed | our op10 sub-selector (0x01/0x02/0x0C/0x0E…, slot 0x13 FUN_005bba20) |
| 0x11 | CMD_SEND_GAME_PACKET_TO_GAME_SERVER | AM-Inference | |
| 0x14 | CMD_SEND_ECHO | AM-Inference | |
| 0x27 | (result wrapper, FAIL frame) | PAL-Confirmed | v2 create-reject: reject = opcode 0x27, not a status field |
| 0x28 | CMD_RESULT_WRAPPER (sub = GameTag) | PAL-Confirmed | our op28 completions; sub echo at wire+0x02 = packet number; routing by 0x1000 (FUN_001d9f78) |
| 0x29 | CMD_RESULT_LOGIN_TO_KICS | AM-Inference | v2 op-0x29 success transition (never captured on PAL) |
| 0x2C/0x2D/0x2E/0x31 | bootstrap LOGIN_CLIENT/SUCCESS/FAIL/FAILURE | PAL-Confirmed (0x2C/0x2D) | RS1 wire frames 134-135 decode exactly (0x3096 002c → 0xb096 002d); fail reason 0x13 = bad password (AM) |
| 0x40/0x41 | CMD_BOOTSTRAP_LOGIN_SWAN / _CHECK | **PAL-Divergent** | PAL op40 = phase-3 keepalive (0x30xx, Blowfish SNAP-SWAN zero body); AM uses 0x40 as a bootstrap Blowfish challenge. Same key, different phase — do not conflate |
| 0x48/0x49 | — (absent from AM tables) | PAL-only | our area-grid NAME query / LOID-STAT list; Outbreak-specific (or later SNAP rev) |
| 0x6E | (client cb slot: kkSetJoinGameClassCallBack) | PAL-Confirmed (role) | our 0x6e ENTER reply (sets `0x6ff2b1`) — "join game class" |
| 0x78 | (client cb slot: kkSetLeaveGameClassCallBack) | AM-Inference | candidate for the leave/park path family |

## The confirmed channel-context rule (applies across the table)

`0x1000` set = LOBBY context, clear = ROOM context, for the SAME opcode — separate reliable
seq counters per channel on the client (`conn+0x61a`/`0x61b`), and the op-0x28 result
dispatcher `FUN_001d9f78` selects the completion callback slot BY the received bit (sub 5/6/7
split; none for sub 4/8). **A completion's 0x3000 bits must equal its request's.**
Full trace: `analysis/op28-channel-bit-dispatch-2026-08-24.md`. L1 spec §1.2 carries the
production rule.

## Maintenance

Per `docs/CORPUS-METHODOLOGY.md`: AM-Inference rows are DISCOVERY leads, not PAL facts — do a
one-function PAL check before any implementation relies on one, then upgrade the row with the
evidence cite. Mark rows PAL-Divergent (never delete) when PAL differs.
