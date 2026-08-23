# BIOSERVER CONTRACT — the JP application protocol the PAL client speaks

**Source (Observation, code-read 2026-08-08):**
`references/bioserver/bioserver-docker-2.4.1/bioserver-docker-2.4.1/bioserv2/bioserver/`
— `bioserv2` is the **File #2** server (its `Commands.java` header says "Biohazard Outbreak
File #2"); `bioserv1` is File #1. Everything below is read directly from the bioserv2 Java
source (PacketHandler.java, GameServerPacketHandler.java, Packet.java, Client.java,
ClientList.java, Slot/Slots/RuleSet, Room/Rooms, Area/Areas, ServerMain, HeartBeatThread,
ServerStreamBuffer, HNPair, PacketString, MessageOfTheDay).

**Evidence class:** everything in this document is **Observation of the reference server's
code** — i.e. what a community re-implementation sends. It is decompile-grade evidence for
what the *client tolerates*, not wire-capture of Capcom's original server. TODO comments in
the source mark fields even the reference authors did not understand; those are flagged.

**Transport note:** the JP/reference transport is plain TCP (lobby port **8200**, game port
**8590**, `ServerMain.java`). Our PAL transport is SN@P; only this layer differs. The
application packet format below is what rides inside.

---

## 1. Packet framing (Packet.java)

12-byte header + payload:

| off | size | field | meaning |
|---|---|---|---|
| 0 | 1 | `who` | 0x81 = client→server (lobby), 0x18 = server→client, 0x82 = game-client, 0x28 = game-server |
| 1 | 1 | `qsw` | 0x01 QUERY, 0x02 TELL (answer), 0x10 BROADCAST |
| 2 | 2 | `cmd` | command code, big-endian |
| 4 | 2 | `len` | payload length (excl. header), BE |
| 6 | 2 | `pid` | packet id, BE |
| 8 | 1 | `err` | 0 = ok, 0xFF = error (set on refusals) |
| 9 | 3 | pad | 0xFF 0xFF 0xFF on server sends |
| 12 | len | payload | |

Rules:
- **TELL replies echo the requester's `pid`.** Server-initiated QUERY/BROADCAST use the
  server's own incrementing counter.
- Multiple packets may be concatenated in one TCP read; the server walks them by
  `len + 12`.
- **Client string payloads are obfuscated** with a per-byte XOR keyed on `pid & 0xff`
  (`calc_shift` in Packet.java: `fixval[i&7] - (i&0xf8) - p + ((p-9+i)&masks[i&7])*2`).
  Server → client strings are sent in **cleartext**. Encrypted-string wire shape:
  `len+2 (BE16), sum (2 bytes), bytes[len]` — the stated length includes a 2-byte "sum"
  which is skipped.
- Plain strings in server payloads: `len (BE16), bytes` (PacketString).
- HNPair on the wire: `00 06 <handle:6> 00 <nlen> <nickname:nlen>` (nickname SJIS).
- 2-byte "number" request payloads (`getNumber()`): first two payload bytes BE16 —
  used for area nr, room nr, slot nr.

Client status model (server-side): `area` (0 = area-select screen, **51 = after-game
lobby**), `room` (0 = room list), `slot` (0 = slot list), `playernum` (host = 1,
joiners 2–4), `hostflag`, `gamenumber`.

Broadcast audiences (PacketHandler broadcast helpers):
- **InAreaNAreaSelect(area)** — clients with `area==nr || area==0`, `room==0`
- **InArea(area)** — `area==nr && room==0`
- **InRoom / InRoomNArea(area,room)** — `area && room && slot==0` (both identical in code)
- **InSlotNRoom(area,room,slot)** — `area && room && (slot==nr || slot==0)` (slot + spectating room)
- **InSlot(area,room,slot)** — exactly the slot members
- **InAgl(gamenr)** — clients whose `gamenumber == gamenr`

World topology: **10 areas** (statuses 3=active/0=inactive), **6 rooms per area** (only
room 1 "free" is ACTIVE; R1–R5 INACTIVE), **20 game slots per room**. Slot statuses:
0 DISABLED, 1 FREE, 2 INCREATE, 3 GAMESET (joinable), 4 BUSY (full / in game).
Scenario ids: 0 training, 1 Wild Things, 2 Underbelly, 3 Flashback, 4 Desperate Times,
5 End of the Road, 6 Elimination 1 (comments say more exist). Slot type word in
SCENESELECT: 0x11 = DVD, 0x12 = HDD (stored raw).

---

## 2. Login / session (server initiates on TCP accept)

| # | cmd | dir / qsw | payload | server state change | reply/broadcast |
|---|---|---|---|---|---|
| 1 | `LOGIN` 0x6101 | S→C QUERY | seed `{0x28,0x37}` | — | sent immediately on accept |
| 2 | `LOGIN` 0x6101 | C→S TELL | session digits: payload[2..11] are 10 ASCII digits each offset by `pid`; session = `%04d%04d` of (A−seed,B−seed) | DB lookup userid by session; duplicate sessions disconnected; `Client` created (area/room/slot = 0). If DB `gamenumber>0` → `area=51` (returning from a game) | on success → step 3; on failure disconnect |
| 3 | `CHECKVERSION` 0x6103 | S→C QUERY | empty | — | — |
| 4 | `CHECKVERSION` 0x6103 | C→S TELL | version (shifted) — **ignored** by server (File #2 never patched) | — | server sends step 5 |
| 5 | `IDHNPAIRS` 0x6131 | S→C **BROADCAST** (to that socket) | up to 3 stored HNPairs from DB | — | — |
| 6 | `UNKN61A0` 0x61A0 | C→S QUERY | ? | — | TELL fixed 8 bytes `{0,9,1,0x2C, 0,0,2,0x58}` (timeout/latency, 300/600s) |
| 7 | `CHECKRND` 0x600E | C→S QUERY | shifted "0"s | — | TELL `{0,1,<decrypted byte 4>}` |
| 8 | `UNKN61A1` 0x61A1 | C→S QUERY | ? | — | TELL fixed 10 bytes `{0,0,3,0x84, 0,0,7,8, 0,0}` (900/1800s) |
| 9 | `HNSELECT` 0x6132 | C→S QUERY | encrypted HNPair (handle+nickname) | sets client HNPair; handle `"******"` → mint new handle, insert DB; update DB pair | TELL `{0,6,<handle:6>}`. If DB gamenumber>0 also S→C QUERY `POSTGAMEINFO` 0x6138. Then S→C BROADCAST `UNKN6104` 0x6104 (empty) — **this ends the login phase** |
| 10 | `POSTGAMEINFO` 0x6138 | C→S TELL | encrypted stats of the finished game (session, co-players) | reference server ignores it (rankings TODO) | none |
| 11 | `MOTHEDAY` 0x614C | C→S QUERY | ? | — | TELL `{count:1, len:2, html-ish text}` (MOTD; `<BODY>`,`<SIZE=n>`,`<C=n>`,`<BR>`,`<LF=n>`,`<CENTER>`,`<END>` markup) |
| 12 | `CHARSELECT` 0x6190 | C→S QUERY | encrypted **0xD0-byte character/stat blob** | stored on Client (`characterstats`) — later replayed to other players | TELL empty. Sent once before area select **and again when creating/joining a slot** |
| 13 | `UNKN6881` 0x6881 | C→S QUERY | ? | — | TELL `{3, 0,0,2,0x5D, 0,0,0,4, 0,0,2,0x5D}` — sizes of the 6882 blocks |
| 14 | `UNKN6882` 0x6882 | C→S QUERY | `{nr:1, offset:4, size:4}` | — | TELL data chunk from `Packet6881` file blobs |
| 15 | `RANKINGS` 0x6145 | C→S QUERY | area/scenario selector (2 bytes) | — | TELL ranking record (see sendRankings — scenario short, point ints, 6× {status,char,handle,name}) |

Keepalives (HeartBeatThread): every 30 s S→C BROADCAST `HEARTBEAT` 0x6202 payload
`{00 02 00 01 03 E7 00 01}` (no answer expected); every 60 s S→C QUERY `CONNCHECK`
0x6001 (empty) — client must TELL (empty) or is removed. **Clients in area 51 (AGL) are
exempt from CONNCHECK.** Every 5 min ghost slots (GAMESET with 0 players) are reset to
FREE + `SLOTSTATUS` broadcast.

`LOGOUT` 0x6006 C→S QUERY → clears DB gamenumber, removes client (with full slot-cleanup
broadcast side effects, §7), broadcasts AREAPLAYERCNT, TELL empty.

---

## 3. Area select

| cmd | dir | request payload | reply payload | state / broadcast |
|---|---|---|---|---|
| `AREACOUNT` 0x6203 | C→S QUERY | — | `{count:BE16}` (10) | — |
| `AREAPLAYERCNT` 0x6205 | C→S QUERY | area BE16 | 10 bytes: `area:2, inLobby:2, inRooms:2, 0xFFFF, inGame+AGL:2` | — |
| `AREASTATUS` 0x6206 | C→S QUERY | area BE16 | `{area:2, status:1}` (3 = open, 0 = locked) | — |
| `AREANAME` 0x6204 | C→S QUERY | area BE16 | `{area:2, len:2, name}` | — |
| `AREADESCRIPT` 0x620A | C→S QUERY | area BE16 | `{area:2, len:2, markup text}` | — |
| `AREASELECT` 0x6207 | C→S QUERY | area BE16 | TELL `{area:2}` | `client.area = nr`; **BROADCAST `AREAPLAYERCNT`** (QUERY-shape payload, broadcast form) to everyone in that area + area-select screen |
| `EXITAREA` 0x6209 | C→S QUERY | — | TELL empty | `client.area = 0`; BROADCAST `AREAPLAYERCNT` for the departed area |

The rule sets differ **per area** (RuleSet.java): area 2 Nightmare (nightmare fixed on),
3 Survival (friendly fire fixed on), 4 Panic (both on), 5 Infinity (ff/nm selectable,
infinity fixed on), all others: players / wait limit / difficulty only.

---

## 4. Room list (inside an area)

| cmd | dir | request | reply | state / broadcast |
|---|---|---|---|---|
| `ROOMSCOUNT` 0x6301 | C→S QUERY | — | `{count:BE16}` (6) | — |
| `ROOMPLAYERCNT` 0x6303 | C→S QUERY | room BE16 | `{room:2, cnt:2, inGameCnt:2, 0xFFFF, 0x0000}` | — |
| `ROOMSTATUS` 0x6304 | C→S QUERY | room BE16 | `{room:2, status:1}` | — |
| `ROOMNAME` 0x6302 | C→S QUERY | room BE16 | `{room:2, len:2, name}` | — |
| `UNKN6308` 0x6308 | C→S QUERY | room BE16 | echo of ROOMPLAYERCNT-shaped constant `{nr:2, 0,0, 0,3, 0xFFFF, 0,0}` | reference doesn't know this one |
| `ENTERROOM` 0x6305 | C→S QUERY | room BE16 | TELL `{room:2}` | `client.room = nr`; **BROADCAST `ROOMPLAYERCNT`** to the whole area (`broadcastInArea`) |
| `EXITSLOTLIST` 0x6408 | C→S QUERY | — | TELL empty | `client.room = 0`; BROADCAST `ROOMPLAYERCNT` to area |

---

## 5. Slot list (the PAL "room list" inside a room) — browse queries

All slot queries implicitly use the requester's current area+room.

| cmd | dir | request | reply |
|---|---|---|---|
| `SLOTCOUNT` 0x6401 | C→S QUERY | — | `{count:BE16}` (20) |
| `SLOTSTATUS` 0x6404 | C→S QUERY | slot BE16 | `{slot:2, status:1}` (1 free / 2 in-create / 3 joinable / 4 busy) |
| `SLOTPLRSTATUS` 0x6403 | C→S QUERY | slot BE16 | 10 bytes `{slot:2, 0,curPlayers, 0,0(?), 0,maxPlayers, 0,curPlayers(?)}` |
| `SLOTTITLE` 0x6402 | C→S QUERY | slot BE16 | `{slot:2, len:2, title}` (default `"(free)"`) |
| `SLOTATTRIB2` 0x640B | C→S QUERY | slot BE16 | 12 bytes `{slot:2, 0,maxPlayers, 0,4, 0,1, 0,4, 0,1}` (trailing 4 words unknown, TODO in source) |
| `SLOTPWDPROT` 0x6405 | C→S QUERY | slot BE16 | `{slot:2, protection:1}` (0 off / 1 on) |
| `SLOTSCENTYPE` 0x650A | C→S QUERY | slot BE16 | `{slot:2, 0,slotType, 0,scenario}` |
| `PLAYERSTATS` 0x640A | C→S QUERY | slot BE16 | `{slot:2, 0x03(?), playerCnt:1}` then per member: `HNPair, statLen:2, charstats[0xD0]` |
| `SLOTTIMER` 0x6409 | C→S QUERY | slot BE16 | `{0,slot, remainingSecs:BE16}` — **side effect: if remaining == 0 the server fires the whole game-start broadcast (§8)** |
| `UNKN6412` 0x6412 | C→S QUERY | slot BE16 | `{0,slot, 0,0,0,0}` (unknown) |

### Rule/scenario browse (read side; also usable by joiners before joining)

Requests carry `slot:BE16` then optionally `rulenr` at payload[2] and `attnr` at payload[3].

| cmd | dir | request | reply |
|---|---|---|---|
| `RULESCOUNT` 0x6603 | C→S QUERY | slot | `{count:1}` (3–6 depending on area) |
| `RULEATTCOUNT` 0x6607 | C→S QUERY | slot, rulenr | `{rulenr, attCount}` |
| `UNKN6601` 0x6601 | C→S QUERY | nr | `{1, nr:2}` |
| `UNKN6602` 0x6602 | C→S QUERY | nr | `{1, nr:2}` |
| `RULEDESCRIPT` 0x6604 | C→S QUERY | slot, rulenr | `{rulenr, len:2, name}` ("number of players", "wait limit", "difficulty level", …) |
| `RULEVALUE` 0x6606 | C→S QUERY | slot, rulenr | `{rulenr, value:1}` (index into the attribute list) |
| `RULEATTRIB` 0x6605 | C→S QUERY | slot, rulenr | `{rulenr, attribute:1}` (1 = player-changeable, 0 = fixed) |
| `ATTRDESCRIPT` 0x6608 | C→S QUERY | slot, rulenr, attnr | `{rulenr, attnr, len:2, choiceName}` ("two players", "ten minutes", "very hard", …) |
| `ATTRATTRIB` 0x660E | C→S QUERY | slot, rulenr, attnr | `{rulenr, attnr, att:1}` (always 0) |

Rule semantics (RuleSet.java): rule 0 = players (value 0/1/2 → 2/3/4 max), rule 1 = wait
limit (0..4 → 3/5/10/15/30 min), rule 2 = difficulty (0..3 → easy..very hard), then per
area: friendly fire / nightmare / infinity (0 off, 1 on).

---

## 6. Slot create (host) and join

### Create — observed handler order

| # | cmd | dir | payload | server mutation | broadcasts |
|---|---|---|---|---|---|
| 1 | `CREATESLOT` 0x6407 | C→S QUERY | slot BE16 | `client.slot = nr`, **hostflag = 1, playernum = 1**, slot status → INCREATE, slot.host = userid | `SLOTPLRSTATUS` + `SLOTSTATUS` (BROADCAST, audience = slot + room); then TELL `{0, slot}` |
| 2 | `SCENESELECT` 0x6509 | C→S QUERY | `{0,type, 0,scenario}` (type 0x11 DVD / 0x12 HDD) | stores slotType + scenario, arms livetime | TELL `{0,slot, 0,type, 0,scenario}` |
| 3 | `SLOTNAME` 0x6609 | C→S QUERY | encrypted string | slot title set | TELL empty; BROADCAST `SLOTTITLE` to slot+room |
| 4 | `SLOTPASSWD` 0x660A | C→S QUERY | encrypted string | password set (non-empty ⇒ protection ON) | TELL empty |
| 5 | `SETRULE` 0x660B | C→S QUERY | `{rulenr:1, value:1}` | rule value set | TELL `{1}` |
| 6 | `UNKN660C` 0x660C | C→S QUERY | ? | — | TELL empty |
| 7 | `CHARSELECT` 0x6190 | C→S QUERY | 0xD0 char blob (again) | refresh stats | TELL empty |
| 8 | `UNKN6504` 0x6504 | C→S QUERY | `{1?}` | **"last packet from slot creator":** if hostflag, slot status → **GAMESET** (joinable) and livetime armed (waitLimit minutes) | **six broadcasts, in this order, audience slot+room unless noted:** `SLOTPLRSTATUS`, `SLOTPWDPROT` (room-wide), `SLOTSTATUS`, `SLOTSCENTYPE`, `SLOTATTRIB2`, then `PLAYEROK` 0x6506 BROADCAST `{0,playernum, 0,0}` to **slot members only**; finally TELL 0x6504 `{payload[0]}` |

### Join (non-host) — `JOINGAME` 0x6406

Request payload: `slot:BE16`, then encrypted password (`len at [2..3], bytes from [6]`).

Checks in order — each failure is a TELL with **err flag 0xFF** and a PacketString markup
message: status BUSY → "game is full"; status ≠ GAMESET → "not possible"; bad password →
"wrong password".

On success:
1. `playernum = getFreePlayerNum` (**first free of 2,3,4** — host holds 1), `client.slot = nr`.
2. TELL `{0, slot}` (no err).
3. If now full (`count ≥ maxPlayers`) slot status → BUSY.
4. BROADCASTs: `SLOTPLRSTATUS`, `SLOTSTATUS`, `SLOTATTRIB2` (slot+room).
5. **BROADCAST `PLAYERSTATBC` 0x6503** to slot members: joining player's
   `HNPair + statLen:2 + charstats[0xD0]` (note: reference reuses the request pid here).

The joiner then browses rules/stats with the §5 queries and signals readiness the same
way the host does; `PLAYEROK` 0x6506 broadcast (`{0,playernum,0,0}`) tells the slot a
player is "unlocked" (fired inside the 0x6504 handler).

### Chat and event data (room/slot/AGL)

| cmd | dir | payload | audience |
|---|---|---|---|
| `CHATIN` 0x6701 | C→S **BROADCAST** | encrypted string | — |
| `CHATOUT` 0x6702 | S→C BROADCAST | `HNPair(sender), msgLen:2, msg, 0x00, 0x000000FF` (cleartext) | in slot → slot members; else in area (≠51) → area; else gamenumber>0 → AGL. **Note: no chat relay on the room-list floor (area chat requires room==0 per broadcastInArea)** |
| `EVENTDAT` 0x670D | C→S QUERY | encrypted `{recipientHandle, eventData}` | TELL `{0,6,recipientHandle}` to sender |
| `EVENTDATBC` 0x670E | S→C BROADCAST | `{6:2, senderHandle, len:2, eventData}` | **only the addressed recipient** (pre-game + AGL private event channel) |

### Leave / cancel / dissolve — `CANCELSLOT` 0x6501

Sent when a player backs out of rules, when the host aborts creation, **and** when host or
member leaves a set slot.

Host path (hostflag==1): hostflag→0, **slot.reset()** (title "(free)", FREE, rules reset),
BROADCAST `CANCELSLOTBC` 0x6505 (PacketString `"<LF=6><BODY><CENTER>host cancelled
game<END>"`) to slot; then `SLOTPWDPROT`, `SLOTSCENTYPE`, `SLOTTITLE` broadcasts.

All leavers: BROADCAST `LEAVESLOT` 0x6502 `{0,6,handle:6}` to slot; playernum→0, slot→0;
`SLOTATTRIB2` broadcast; recompute status (0 players → FREE; non-full and host remains →
GAMESET); `SLOTPLRSTATUS` + `SLOTSTATUS` broadcasts; TELL 0x6501 empty.

Unexpected disconnect (removeClient) replays the same cascade (host: CANCELSLOTBC + full
slot reset broadcast set; member: LEAVESLOT + status recompute) plus `ROOMPLAYERCNT`.

---

## 7. GAME START — the milestone sequence

### 7.1 Trigger

Two triggers, same server routine `broadcastGetReady`:
- Host sends **`STARTGAME` 0x6508** with `who=0x81, qsw=BROADCAST(0x10)` (one of only two
  client-broadcast commands; the other is CHATIN). No TELL is sent for it.
- Or a `SLOTTIMER` 0x6409 query returns 0 remaining — auto-start on wait-limit expiry.

### 7.2 `broadcastGetReady` (server, in order)

1. If slot has no gamenumber: allocate one (monotone counter), set `cl.gamenumber` on
   **every client in the slot** and persist to DB (`updateClientGame`) — the DB row is how
   the game server and the post-game lobby later recognize the party.
2. Slot status → **BUSY**; BROADCAST `SLOTSTATUS` (slot+room) so nobody else joins.
3. **BROADCAST `GETREADY` 0x6910, empty payload, audience = slot members only.**

### 7.3 Client detail queries after GETREADY (each answered as TELL)

The client requests game details; the reference answers:

| cmd | reply payload | semantics |
|---|---|---|
| `PLAYERCOUNT` 0x6911 | `{n:1}` | players in this slot |
| `PLAYERNUMBER` 0x6912 | `{n:1}` | **the asker's own player number** (host 1, joiners 2–4) |
| `PLAYERSTAT` 0x6913 | request `{playernum:1}` → `{playernum, 0x01, HNPair, statLen:2, charstats[0xD0], 0x00, 0x00, 0x06}` | per-player pre-game stat record (client asks once per player). If that player vanished: `{playernum, 0}` |
| `PLAYERSCORE` 0x6917 | `{playernum:1, scenario:2, int×5}` | ranking scores (reference sends test values 110..550) |
| `GAMESESSION` 0x6915 | `{0x000F:2, "%015d" gamenumber as 15 ASCII digits, 0x0000:2}` | the shared game-session token — **this is what ties the party together on the game server** |
| `GAMEDIFF` 0x6914 | 34 bytes: `{0x00,0x20, 0x01, difficulty, friendlyFire, 0, 0, nightmare, infinity, 0, …zeros}` | rule material for the engine (source note: byte idx 4=FF, 7=nightmare, 8=infinity; comment block also mentions gauge/point-multiplier/item-glow values not implemented) |
| `GSINFO` 0x6916 | `{0x0004:2, ip:4, 0x0002:2, port:BE16(8590), 0x00,0x00,0x1E,0x00}` | **the game-server address handoff** (trailing 4 bytes unknown) |

### 7.4 Handoff to the game server (GameServerThread / GameServerPacketHandler, port 8590)

1. Client opens a TCP connection to the GSINFO address. On accept the game server sends
   **`GSLOGIN` 0x1031 QUERY** with `who=0x28` (GAMESERVER), empty payload.
2. Client TELLs 0x1031 with `who=0x82`: payload = 10 ASCII session digits, each offset by
   `pid` (same scheme as lobby LOGIN but at offset 0). Server resolves session→userid in
   DB, reads the DB **gamenumber**, creates the GS-side Client, sets DB status
   `STATUS_GAME`. Invalid session ⇒ disconnect.
3. **Everything after login is a dumb relay** (`processData` default branch): any inbound
   buffer whose first byte ≠ 0x82/0x02 is copied verbatim to **every game-server client
   with the same gamenumber except the sender**. Framing on this socket
   (`getCompleteGameMessages`): each in-game message's **first byte is its total length**;
   session packets (0x82 0x02) are passed whole. The lobby/packet header does not apply.
   Gameplay sync is therefore fully client-authoritative peer relay.
4. Liveness: any inbound packet marks the GS client alive; a sweep every 30 s drops
   clients that sent nothing since the last sweep.
5. Meanwhile on the **lobby** connection the client sends `UNKN6002` 0x6002 QUERY: server
   resets that client's area/room/slot/playernum (gamenumber and the DB row survive), and
   if the slot count hits 0, resets the slot and broadcasts the full slot state set
   (`SLOTPLRSTATUS`, `SLOTPWDPROT`, `SLOTTITLE`, `SLOTSCENTYPE`, `SLOTATTRIB2`,
   `SLOTSTATUS`); TELL 0x6002 empty. This is how the lobby-side room dissolves while the
   party plays.

### 7.5 Post-game return — After-Game Lobby ("meeting room", area 51)

The client comes back to the lobby server on a **fresh connection** and runs the full
login of §2 again. During `check_session`, DB gamenumber>0 ⇒ the client is placed in
**area 51**; after HNSELECT the server also QUERYs `POSTGAMEINFO` 0x6138 (client TELLs
game stats; reference discards them).

| cmd | dir | payload | state / broadcast |
|---|---|---|---|
| `ENTERAGL` 0x6210 | C→S QUERY | — | `cl.gamenumber` reloaded from DB, area=51. TELL empty. Then BROADCAST `AGLPLAYERCNT` 0x6212 `{0,count}` and BROADCAST `AGLJOIN` 0x6215 `{HNPair, statLen:2, charstats}` — audience: same gamenumber |
| `AGLSTATS` 0x6213 | C→S QUERY | — | TELL `{0x0000, 0x03(?), count:1}` then per member `{HNPair, statLen:2, charstats}` |
| `AGLPLAYERCNT` 0x6212 | C→S QUERY | — | TELL `{0,count}` |
| `CHATIN`/`CHATOUT` | | | chat works here, routed by gamenumber (`broadcastInAgl`) |
| `LEAVEAGL` 0x6211 | C→S QUERY | — | BROADCAST `AGLLEAVE` 0x6214 `{0,6,handle}` to the AGL; **area→0, gamenumber→0 (memory + DB)**; TELL empty; BROADCAST `AGLPLAYERCNT`; BROADCAST `ROOMPLAYERCNT` (hard-coded area1/room1 — a reference-server shortcut) |

After LEAVEAGL the client is back at area select with a clean state.

---

## 8. Messaging / misc (any phase)

| cmd | dir | payload | reply |
|---|---|---|---|
| `GETINFO` 0x6801 | C→S QUERY | encrypted URL string | TELL `{urlLen:2, url, dataLen:2, data}` (info pages) |
| `BUDDYLIST` 0x6707 | C→S QUERY | encrypted handle | online → `{0,0,0,0,0,0,0}`; in-game → `{0,0,0,0,0,0,1}`; offline → markup "not connected" + **err** |
| `CHECKBUDDY` 0x6703 | C→S QUERY | encrypted handle | online → structured record (handle + status words + markup); in-game/offline → markup + err |
| `PRIVATEMSG` 0x6704 | C→S QUERY | encrypted `{recipientHandle, message}` | TELL empty to sender; BROADCAST `PRIVATEMSGBC` 0x6705 to recipient only; offline → markup + err |
| `UNKN6181` 0x6181 | C→S QUERY | ? | TELL empty (blind accept; "something along registration") |

---

## 9. State-machine summary (what must be true for the PAL port)

1. **Server initiates**: LOGIN query on connect; CHECKVERSION; IDHNPAIRS; the 0x6104
   end-of-login broadcast; HEARTBEAT/CONNCHECK timers; GETREADY; POSTGAMEINFO.
   Everything else is client-driven query/response — *the client renders exactly what it
   asked for*, keyed by echoed pid.
2. **Create is a dialogue, not one packet**: CREATESLOT → SCENESELECT → SLOTNAME →
   [SLOTPASSWD] → SETRULE×n → 660C → CHARSELECT → **6504**, and only 6504 flips the slot
   joinable (GAMESET) and emits the 6-broadcast state set + PLAYEROK.
3. **Join is guarded** by slot status and password, answers `{0,slot}`, assigns
   playernum 2–4, and announces the joiner via PLAYERSTATBC (the 0xD0 char blob captured
   at CHARSELECT).
4. **Game start = GETREADY (empty) to slot members only**, followed by seven
   client-driven detail queries (count, own number, per-player stats, scores, session
   token, difficulty, game-server address), then a *separate connection* to the game
   server whose only jobs are session-check and length-byte-framed relay within the
   gamenumber group.
5. **The gamenumber persisted in the DB is the thread** that connects lobby party →
   game-server relay group → after-game lobby membership → POSTGAMEINFO.
6. **Every membership change broadcasts refreshed counters/status** to the enclosing
   scope (slot+room for slot changes, area for room changes, area-select+area for area
   changes). The PAL client's counter displays depend on these pushes, not on re-query.

## 10. Known unknowns in the reference itself (flagged TODO by its authors)

- SLOTPLRSTATUS bytes 4–5 ("playin2" duplicate at 8–9), SLOTATTRIB2 words 3–6,
  HEARTBEAT payload meaning, 61A0/61A1 exact semantics (latency vs timeout),
  GSINFO trailing `00 00 1E 00`, UNKN6308/6412/6601/6602/660C/6504/6002/6181 names,
  slot type values beyond 0x11/0x12, extra GAMEDIFF fields (gauge, point multiplier,
  special-item glow), AGL per-room counting, PLAYERSCORE real content.
- These are places where the PAL client's decompile/wire evidence outranks this document.
