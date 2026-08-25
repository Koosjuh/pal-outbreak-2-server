# openSNAP deep dive — byte-level reference (2026-08-24)

Source: vendored read-only copy `references/external_repos/openSNAP` (GrenderG/openSNAP, commit
`bcd22f8`, AGPL-3.0 — protocol facts free; **never copy code** into `server/`/`server-v2/`).
Every claim below is an **Observation of openSNAP's code** (file:line cited). openSNAP itself
distinguishes generic SN@P transport claims (backed by `SLUS_204.98`/`SLUS_206.42` addresses it
quotes in comments) from Auto-Modellista(AM)-specific payload shapes; that split is preserved here.
Companion doc: `OPENSNAP-CROSSREF-2026-08-24.md` (op/flag mapping vs our PAL RE).

All multi-byte fields **big-endian** throughout (`protocol/fields.py:18-33`, codec `'>2H3L'`).

---

## 1. Bootstrap flow (UDP 9090)

Two variants keyed on the **footer**: primary `0xBA476611` ("SWAN" challenge/response flow) and KAGE
`0xBA476610` (direct success, `SLUS_204.98`-era) — `bootstrap/handlers.py:83,290-293`. The server
remembers which footer each endpoint used and mirrors it on replies (`udp_server.py:292-300,625`).

### 1.1 CMD_LOGIN_CLIENT (0x2C) request
- Payload offset 0: NUL-terminated login string, **newline-terminated** inside (`test\n\0`); a
  variant packs TWO newline-terminated copies back-to-back before the NUL ("@cei-auth" copy) —
  account key = first line (`handlers.py:273-287`).
- Session created immediately: `create_or_replace` → session_id = first 8 hex digits of
  `md5(client_host + username + password_verifier)` as u32 (`sessions.py:164-171`). Deterministic,
  per host+account.

### 1.2 Primary flow: 0x2C → **0x40 challenge** → 0x41 → 0x2D/0x2E
- Reply to 0x2C is **CMD 0x40 (BOOTSTRAP_LOGIN_SWAN)** carrying an encrypted challenge, flags
  `0x3000` (channel bits, NO response bit) (`handlers.py:124-132`). So 0x40 here is a
  **bootstrap-channel challenge command** — NOT a game-phase keepalive. (Our PAL op40 keepalive
  finding is a different, game-phase usage; the two must not be conflated.)
- Challenge plaintext (`handlers.py:323-350`):
  `>HHL128s3L128sL` = u16 0, u16 bootstrap_port, u32 seed_len, 128s seed, u32 magic_len,
  u32 magic_len (again), u32 0, 128s magic, u32 0 — where
  `magic = BlowfishECB(magic_key, pack('128s', server_secret))` and the whole struct is then
  `BlowfishECB(bootstrap_key, …)`. **Crypto = Blowfish ECB, zero-padded to 8-byte blocks**
  (`handlers.py:296-320`). Default `bootstrap_key = b'SNAP-SWAN'`, default
  `server_secret = 'Totally secret server secret!'` (`config.py:18-19`).
  `magic_key = SHA1(password + seed)` (20 bytes); `verifier = SHA256(password)` hex
  (`accounts.py:139-147`).
- Client answers **CMD 0x41 (SWAN_CHECK)**: payload decrypts under bootstrap_key; the server checks
  `c_string at clear+8 == server_secret` (`handlers.py:376-381`). Session is looked up **by
  endpoint** (`handlers.py:190`).
- Success: **CMD 0x2D**, flags `0x3000|0x4000`, payload =
  `BlowfishECB(bootstrap_key, pack('>40s6L', login+'\n', game_ip_u32, game_port, game_port, 0,0,0))`
  (`handlers.py:384-401`). The echoed login **must keep the newline** — SLUS_206.42
  `kkBootStrapLoginSuccess` strcmp's it against the stored raw field (comment at
  `handlers.py:393-397`). This payload is what redirects the client to the game server (9091).
- Failure: **CMD 0x2E**, payload `>2L` = (0, reason). Reasons: 0x00 unknown, 0x01 generic,
  **0x13 invalid-password** (dedicated client branch) (`constants.py:52-63`, `handlers.py:475-478`).

### 1.3 KAGE variant (footer …10)
One round-trip: 0x2C → **0x2D directly**, payload
`BlowfishECB(login_password, pack('>40s6L', raw_login, ip, port, port, 0,0,0))` — the key is the
account's **cleartext password** (`SLUS_204.98` stores `login_password` at `app+0x47c` and decrypts
0x2D with it; `handlers.py:135-163,353-373`).

### 1.4 Game-side login: CMD_LOGIN_TO_KICS (0x01) → 0x29
On UDP 9091. Session resolved by id then endpoint, then **endpoint is REBOUND** to the new
game-channel address (`game/handlers.py:45-48`) — this is how one session migrates 9090→9091.
Re-login **silently clears stale room membership** (host: dissolve whole room; guest: leave)
(`game/handlers.py:77-97`). Request payload ≥0x130 bytes: ip u32@0, mtu@4, flags@8, version@12,
login cstr@16, region@0x20, marker_bb@0x24, marker_dd@0x28, auth_blob 0x80@0x80, team cstr@0x128
(`game/handlers.py:116-130`). Reply: **CMD 0x29**, flags `0x3000`, payload
`>3L` = (game_port, `0x01234567`, session_id) (`game/handlers.py:65-74`).

## 2. Game engine — inbound lifecycle (`core/engine.py`)

Order per datagram (`engine.py:96-259`): decode → per-message: normalize session id (stale
header id → endpoint-bound session, `engine.py:367-388`) → **bare-ACK short-circuit** → seq
accept → duplicate policy → route → dispatch; finally drop redundant bare acks from outbound.

- **Bare ACK recognition (inbound):** `command==0x00 && (flags & 0x6000)==0x6000` → ignored by the
  engine entirely (`engine.py:140-146`); ACK retirement happened earlier in the transport layer
  (§2.6). Bare ACK **build (outbound):** `CMD_ACK` with empty payload forces
  `sequence_number=0, packet_number=0`; only the ack field carries state (`context.py:42-47`) —
  reusing a fresh sequence there "can leave the client's own reliable send queue unretired"
  (`udp_server.py:56-60`).
- **Per-session seq window:** `accept_incoming` rejects `seq <= last_incoming_sequence`, else
  advances it (`sessions.py:113-124`). Outbound allocation is **split**: reliable messages use
  `request_number++` (post-increment, starts 0), unreliable use `++sequence_number` (starts 1) —
  two independent counters (`sessions.py:98-111`).
- **DuplicateAckPolicy** (`engine.py:42-47,431-440`) — applies only when accept_incoming rejects:
  - `DUPLICATE_RELIABLE`: reliable AND command in {0x0F SEND, 0x10 SEND_TARGET} AND NOT
    (embedded_in_multi && seq==0) (`engine.py:418-429`) → reply transport-ACK only, skip handler.
  - `STALE_DUPLICATE_LEAVE`: command==0x07 LEAVE AND reliable AND NOT(embedded&&seq==0) AND
    `session.last_incoming_sequence > message.sequence_number` (`engine.py:473-496`) → ACK only.
    Rationale quoted: leave callbacks "run immediate UI state transitions and are not keyed by
    transport sequence"; replaying old-wrapper leaves drives redundant transitions.
  - Everything else that fails accept_incoming still **dispatches normally** (exact-seq reliable
    join/create/leave retries are handled by handler-level replay caches, §3).
  - Duplicate-ACK flags per command: SEND_TARGET → `0x2000|0x4000`; SEND → channel-dependent
    (lobby relay → `0x3000|0x4000`, room relay/room → `0x2000|0x4000`); LEAVE → its channel |
    `0x4000` (`engine.py:498-529`).
- **Multi (0x0800) handling:** decoder walks sub-frames; each child after a FLAG_MULTI parent is
  `embedded_in_multi=True` and its header ack word is **garbage** (client never initializes child
  +0x0c; `models.py:29-35`). If a duplicate reliable **multi parent** SEND is suppressed, embedded
  seq-0 reliable SENDs in the same datagram are suppressed too (they're tied to the outer
  transport seq); embedded SEND_TARGET / CHANGE_ATTRIBUTE still replay (`engine.py:442-471`).
- **Reply ACK number:** default = request.sequence_number (`context.py:39-40`); for embedded
  seq-0 requests handlers use `_ack_for_request` = latest accepted inbound seq
  (`plugin.py:1332-1344`); unsolicited pushes use `_ack_for_session` = last_incoming_sequence or 0
  (`plugin.py:1324-1329`).
- **Outbound bare-ACK dedup:** a standalone CMD_ACK to (endpoint,session,ack) is dropped when
  another FLAG_RESPONSE packet in the same result already carries that ack number
  (`engine.py:539-582`) — client's `kkDispatchingPacket` feeds every response packet through
  `kkSetRevAck` before dispatch, making the bare ACK redundant.
- **Echo (0x14):** mirrors the full payload back, `channel|0x4000`, same command (`engine.py:390-410`).
  **Logout (0x02):** deliberate no-op (`engine.py:412-416`).

## 3. Command handlers (AM plugin, `plugins/automodellista/plugin.py`)

Result wrapper (0x28) payload everywhere = `>2L` (selector, status); status 0=OK, 0x27=error
dialog. **Selectors are the GameTags values** (0x04 START_OK for create, 0x06 GAME_START for join,
0x07 GAME_OVER for leave…) — and per `enums.py:14-18`, `kkDispatchingOperation` dispatches wrapper
word0 0x06→join callbacks, 0x07→leave callbacks. (This word0 slot is our PAL "op28 selector".)

| Cmd | Request parse | Reply build | Fanout |
|---|---|---|---|
| 0x0E QUERY_LOBBIES | (none used) | `>3L`(0,1,count) + per-lobby `>16s3L`(name16, users_in, 0, lobby_id); flags `0x3000\|0x4000` (`plugin.py:170-184`) | requester only |
| 0x09 QUERY_ATTRIBUTE | u32 channel_id@0; token `USER` @4 in multi shape | `>L4sL`(channel_id,'USER',count); flags `channel\|0x4000`. Multi burst form embeds follow-up entries with size-word `0x501C` and full 12-byte inner headers `>HBB3L` (`plugin.py:186-231,1034-1065`) | requester |
| 0x0B QUERY_GAME_ROOMS | u32 lobby_id@0 | `>3L`(0,1,count) + per-room `>16s5L`(name16, members, 0, rules, max, room_id) (`plugin.py:233-262`) | requester |
| 0x0A QUERY_USER | ROOM channel only; u32 room_id@0 | `>3L`(room_id,count,count) + per-member `>16s2L32s`(username+'\n' 16, session_id, 32, team32); flags `0x2000\|0x4000` (`plugin.py:264-298`) | requester |
| 0x04 CREATE_GAME_ROOM | name cstr@0, max u32@0x10, password cstr@0x14 ('No PW' sentinel→empty), rules u32@0x28 (`plugin.py:331-335`) | 0x28 wrapper `>2L`(0x04 START_OK, room_id or 0x27); flags `0x2000\|0x4000`. **Result cached by (session,seq)** and replayed verbatim on reliable retransmit (`plugin.py:300-371`) | requester |
| 0x06 JOIN lobby (flags 0x3000) | u32 lobby_id@0 | wrapper `>2L`(0x06, 0/0x27) (`plugin.py:378-405`); implicit room-exit first | requester |
| 0x06 JOIN room (flags 0x2000) | u32 room_id@0 | wrapper(0x06, 0/0x27) **+ per-peer callback**: CMD 0x06, flags `0x2000\|0x4000` (**response, NOT reliable** — "the host does not ACK this callback family", `plugin.py:1289-1291`), payload `>16s2L16s`(joiner_name+'\n', joiner_session_id, 0, team16) (`plugin.py:1263-1297`). Full response bundle (wrapper+callbacks, original seqs) cached per (session, room, seq) and **replayed exactly** on reliable retry (`plugin.py:412-419,565-622`). Un-ACKed callbacks are additionally re-pushed via tick: 3 ticks delay × 3 retries until the joiner's sync (`0x8102`/`0x8008` via 0x10) is seen (`plugin.py:38-39,93-132,1010-1019`) | requester + peers |
| 0x07 LEAVE (0x3000 or 0x2000) | (session state) | wrapper(0x07 GAME_OVER, 0) — **leave keeps the leave selector even post-game**; reusing the join selector sends the client into "Getting information" (`plugin.py:510-513,542-544`). Per-peer callback: CMD 0x07, flags `0x2000\|0x4000`, payload `>L`(leaver_session_id) (`plugin.py:1300-1323`). Wrapper cached per (session, channel, seq) for exact retry replay (`plugin.py:624-661`) | requester + peers |
| 0x0F SEND chat (relay bit 0x0400: lobby `0xB400/0x3400`, room `0xA400`) | payload = `u8 name_len, u8 team_len, name, team, text` — **relayed unchanged** (`plugin.py:1144-1158`) | ACK to sender (CMD 0x00, channel\|0x4000) + one CMD 0x0F per other member, flags `TYPE_RELAY\|0x4000` (lobby `0x1400\|0x4000`, room `0x2400\|0x4000`), **sender excluded** (`plugin.py:712-747,1161-1214`) | peers |
| 0x0F SEND room game pkt (flags 0x2000, no relay bit) | u16 subcommand@0 | ACK to sender + relay full payload to room members with the **request's own type_flags** and packet_number; sender excluded EXCEPT subcommand 0x8001 GAME_START which echoes to all incl. sender (`plugin.py:749-823`, base.py `should_echo_room_game_tag`) | peers(+self for 0x8001) |
| 0x10 SEND_TARGET | u32 target_session_id@4, u16 subcommand@8 | ACK to sender; relay payload to target with **field +0x04 zeroed** (`payload[:4]+\x00*4+payload[8:]`), flags `0x2000\|0x8000` reliable (`plugin.py:916-976,1252-1261`) | one target |
| 0x08/0x0C/0x0D CHANGE_* | — | wrapper `>2L`(selector, 0): 0x08→0x08 JOIN_OK, 0x0C→0x0D RESULT2? (0x0D CHANGE_USER_STATUS→RESULT2=0x0D, 0x0C property→RESULT=0x0C), flags `0x2000\|0x4000` (`plugin.py:978-1008`) | requester |

Post-game orchestration (AM-specific): track subcommand families 0x0658-5F (end) + 0x1468-6F
(result) per member; when ALL room members reported both, push reliable `>H` 0x8009 to every
member → client's `Recv_GamePacket(0x8009)` → `To_RoomExit(2)` (`plugin.py:825-908`).

## 4. Rooms / lobbies / state

- Rooms: in-memory, id auto-increment from 1; host = creator, member set; **room deleted when last
  member leaves** (`rooms.py:76-85`). No explicit CMD 0x05 DELETE handler in AM — rooms die by
  emptying. Capacity enforced at join (`rooms.py:63-74`).
- Lobbies are static config (id+name); membership lives on the Session (lobby_id/room_id fields).
  Counts computed by scanning sessions (`sessions.py:140-153`).
- Stale-state self-healing: before joins/lists/queries, prune members whose session is gone or
  whose session.room_id==0 (`plugin.py:1101-1118`).
- **No client keepalive is expected by the server**: liveness = "any inbound datagram refreshes
  last-inbound clock" (`udp_server.py:216`). Timeout = retry-capped reliable + **60s inbound
  silence** (client's own escalation is ~5000ms; openSNAP deliberately widened it,
  `udp_server.py:120-129`) → engine.handle_transport_timeout → plugin.on_session_timeout: host
  death dissolves the room silently; guest death broadcasts leave callbacks to peers
  (`engine.py:282-303`, `plugin.py:134-168`).

## 5. Plugin API (`plugins/base.py`)

Hooks a game plugin implements: `register_handlers(router, context)` (register per-command
handlers), `on_tick(context)` (periodic pushes; tick default 10s, `config.py:20`),
`on_session_timeout(context, session)`, `decode_datagram`/`encode_messages` (override wire format —
beta1 shows a second legacy frame format coexisting). An **Outbreak plugin** would supply: our
0x48/0x49 area/roster handlers, the 0x65xx/0x66xx create-slot payloads, member-record blobs
(name16/id/charstats), TCP-side is out of scope (openSNAP has no TCP lobby service).

## 6. Web + DNS + storage (brief)

- Web (Flask): signup/create-id routes per game prefix + AM rule/ranking pages; PS2 fetches
  signup/login pages over HTTP (`opensnap_web/games/automodellista.py:926-1029`). Monster Hunter
  module exists web-side only.
- DNS: static A-record resolver with exact+wildcard entries, falls through to system resolver
  (`opensnap_dns/server.py:109-193`).
- Storage: `sqlite` backend (users, lobbies, sessions, rooms, room_members tables) or in-memory;
  runtime state reset on startup per role (`storage/sqlite.py:95-158`, `engine.py:69-77`).
  Password records stored encoded `v1$SHA256(pw)$SHA1(pw+seed)hex` — cleartext converted on first
  load (`accounts.py:102-147`).

## 7. Test-derived ground truth (byte-exact)

- Login flow fixture (`tests/test_engine_flow.py:48-110`): login payload `b'test\n\x00'`;
  0x2D success clear: cstr@0=`'test\n'`, u32@40=ip, @44=@48=game_port, @52..60=0; 0x29 KICS reply
  u32@8 = session_id.
- Lobby chat release shape (`test_engine_flow.py:675-718`): request type word **`0xB400`**
  (`0x3000|0x0400|0x8000`) — comment: `cpnSendChatText` → `kkSendTextChat(..., a3=0x1000)` produces
  raw `0xb400`; room chat request `0xA400`-family (`FLAG_RELAY|FLAG_ROOM`,
  `test_engine_flow.py:720-758`); chat payload example `b'\x04\x04testteamhello'`; server relays
  payload **unchanged** to peers, ACK type `0x7000` (`0x3000|0x4000`) to sender.
- Reliability invariants (`tests/test_udp_reliability.py`): only FLAG_RESPONSE packets retire
  pending reliables, by **exact** ack number+session (82-146); embedded-multi acks ignored (178);
  ack 0 retires seq 0 (114); retransmit = oldest-pending-per-session only (706), 200ms cadence,
  4 counted retries then park-until-timeout (398-495); ≥16 in-flight or seq-gap ≥16 from oldest →
  defer (556-704); leaving a room clears room-channel pending/deferred for that session (522).
- Full captured-log replays run through the engine with **zero unhandled/error datagrams**
  (`tests/test_log_replay.py`), i.e. the handler table in §3 covers the real AM client's entire
  lobby/room traffic (`test_engine_flow.py:3040` asserts router covers all captured commands).

## 8. Answers for OUR known errors (mapping table)

| Our problem | openSNAP mechanism | Where | AM-specific? |
|---|---|---|---|
| (a) client rejects create-self op06 12/13 member add | openSNAP **never sends the joiner a member-add for itself**, and peer join callbacks are `0x2000\|0x4000` response-channel **non-reliable** (host never ACKs that family). Joiner learns the roster by **its own 0x0A query**; peers get the tiny 0x06 callback (name16+session_id+team16). If our create-self push is reliable and/or aimed at the joiner, that matches "client refuses" — the client has no ACK path for it | `plugin.py:1263-1297`, §3 JOIN row | callback payload AM; channel/reliability semantics generic (client callback-table grounded) |
| (b) in-room chat dead | room chat = CMD **0x0F with relay bit**: inbound `0xA400`-family; server ACKs sender (`0x6000` shape) and relays the byte-identical payload to each other member as `0x2400\|0x4000` CMD 0x0F. If our server treats op0F as unknown or echoes to sender, chat stays dead | `plugin.py:731-747,1189-1214`; tests 634-758 | flag routing generic (kkSendTextChat); payload record AM-shaped — verify PAL payload via capture |
| (c) exit-room stall / post-leave park death | three cooperating rules: (1) leave wrapper keeps the **leave selector** (word0 0x07) — echoing a join-flavored selector locks the client in "Getting information"; (2) on leaving a room the server **flushes all room-channel pending+deferred reliables** for that session (stale room pushes after leave = poison); (3) reliable leave retries replay the **same wrapper seq** so the client sees a duplicate, not a fresh callback | `plugin.py:510-513,542-544,624-661`; `engine.py:313-320`; `udp_server.py:359-397` | generic transport + callback semantics |
| (d) enter/back jams at 4th reliable txn (conn+0x520 pool not freed) | client's reliable **receive window is 16** (`kkCreateARUDPRevWindow(0x10)`), and its send pool frees only on **reverse-ACK from FLAG_RESPONSE packets** (`kkSetRevAck`); plain reliable `0xa000` traffic is NOT a retirement source. openSNAP: every response carries `ack=request.seq`, bare ACKs use seq=0/pkt=0, and it never exceeds 16 in flight. Our jam-at-N pattern = some of our replies not carrying the right reverse-ACK (wrong session/seq/flags) so client-side blocks leak | `udp_server.py:51-88,102-135`; `context.py:39-47` | generic (both SLUS builds cited) |
| (e) roster visibility — members don't see each other | roster is **pull+push**: joiner pulls 0x0A (full member records incl. session_ids); peers get 0x06 join callbacks; counts flow via 0x09 'USER' attribute; beta1 additionally pushes an unsolicited 0x09 USER-count to peers after join/leave. Everything keyed on **session_id as the member id** in every record | `plugin.py:264-298,1263-1297`; beta1 `plugin.py:53-77,268-291` | record layouts AM; the query/callback split generic |
| (f) duplicates/retransmits under PINE-sampler load | complete duplicate matrix: seq-window reject + ACK-only for SEND/SEND_TARGET; **exact-replay caches** for create (result by (sess,seq)), join (whole bundle w/ original seqs), leave (wrapper by (sess,channel,seq)); stale-leave = ACK-only; never re-execute side effects on a retransmit | `engine.py:418-529`; `plugin.py:60-68,300-316,565-661` | generic policy, AM cache keys |

**Caveat (methodology):** every row above is openSNAP's *implementation* choice grounded in AM
client binaries/captures. Before our server relies on one, do the one-function check in
SLES_533.19 (same kk* family, addresses differ) — the CROSSREF doc lists which mappings are
already Confirmed vs Inference for PAL.
