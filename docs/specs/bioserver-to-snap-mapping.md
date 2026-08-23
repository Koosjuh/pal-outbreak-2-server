# Bioserver → SN@P/PAL app-protocol mapping (living spec)

**Goal (owner):** recreate the Japanese Bioserver faithfully, then translate it to the PAL SN@P protocol.
This spec is the correspondence contract: every Bioserver command, its semantics, and how PAL/SN@P
realizes it (or the gap). Bioserver = *intent* reference (KDDI/JP middleware, TCP); the PAL client is the
sole wire authority. Companion to `L1-snap-transport-spec.md` (transport) and `L3-app-protocol-spec.md`.

Sources: `references/bioserver/.../bioserv2/bioserver/{Commands,PacketHandler,Room,Slot,RuleSet}.java`;
`server/snap_server.js` (TCP 10127); `server/game_udp_server.js` (UDP 9090 SN@P).

---

## 1. Two-transport architecture (PAL)

PAL splits Bioserver's single stream into TWO transports:

| Layer | Port | Carries | Our server |
|---|---|---|---|
| **Lobby app protocol** | TCP 10127 | the Bioserver `0x6XXX` query/response commands (login, area grid, room/slot lists, rules, chat) | `snap_server.js` |
| **SN@P interactive transport** | UDP 9090 | the *interactive* in-area lobby + game: reliable op48 (area activation), op49 (room-list), op07/08 (leave), op01 (register), op40 (keepalive), op0a (modifier panel) | `game_udp_server.js` |

Bioserver is a pure query-driven TCP protocol: `who=CLIENT(0x81) qsw=QUERY(0x01) cmd=0x6XXX` → server
answers `qsw=TELL(0x02)` (+ `BROADCAST 0x10` to all clients for live updates). Direction bytes:
SERVER 0x18, CLIENT 0x81, GAMESERVER 0x28, GAMECLIENT 0x82.

## 2. Bioserver command set by phase (Commands.java) + PAL status

Legend: ✅ implemented (TCP) · 🟢 implemented via SN@P (UDP) · 🔶 PAL-repurposed (different meaning) ·
⬜ gap (not implemented) · ➖ not needed yet.

### Phase A — Login / auth / session
| Cmd | ID | Bioserver semantics | PAL status |
|---|---|---|---|
| LOGIN | 0x6101 | authenticate handle+password | ✅ snap_server + 🟢 UDP 154b register-auth (blowfish key = password from accounts.json). **BLOCKER: register-812** (see network-flow-and-login-812 doc) |
| CONNCHECK | 0x6001 | keepalive every 60s | ✅ snap_server; 🟢 UDP op40 keepalive (~5s) prevents 840 |
| CHECKVERSION | 0x6103 | client version check | ⬜ |
| CHECKRND | 0x600E | random-number check | ⬜ |
| IDHNPAIRS / HNSELECT | 0x6131/0x6132 | offer + choose ID/handle pairs | ✅ defined (snap_server) |
| SESSION_VERIFY | **0x6110** | — (**PAL-ONLY**, not in Bioserver) | 🔶 PAL post-CONNCHECK challenge reply (snap_server FUN_001c6840) |
| MOTHEDAY | 0x614C | **message of the day** (html/xml) | ⬜ **← the "2 empty boxes after sign-in"** the owner asked about |
| LOGOUT | 0x6006 | logout | ⬜ |
| UNKN61A0/61A1/6104/6181 | … | timeouts / db-registration | ⬜ (mostly benign) |

### Phase B — Character / rankings
| CHARSELECT | 0x6190 | selected char + stats | ✅ defined. (Offline shows all 8; online roster is room-gated — confirmed by pad drive) |
| RANKINGS | 0x6145 | area-lobby player ranking | ⬜ |
| POSTGAMEINFO | 0x6138 | post-game stats for rankings | ⬜ |

### Phase C — Area grid (Server-Select)
| AREACOUNT | 0x6203 | # areas on server | ✅ snap_server |
| AREANAME | 0x6204 | area name | ✅ (Free-first, 10 areas) |
| AREAPLAYERCNT | 0x6205 | players in area | ✅ (hardcoded 0 — needs real registry) |
| AREASTATUS | 0x6206 | available(0)/locked(3) | ✅ |
| AREADESCRIPT | 0x620A | area description | ⬜ (PAL +0x4c pipeline is dead anyway) |
| HEARTBEAT | 0x6202 | 30s broadcast to clients | ✅ defined |
| AREASELECT | 0x6207 | choose area | ✅ snap_server + 🟢 UDP op06 area-confirm |
| EXITAREA | 0x6209 | leave roomlist→arealist | 🟢 UDP op07/op08 leave (SNAP_LOBBY_LEAVE_REPLY — validated: Triangle-back works) |

### Phase D — Rooms (in-area, **6 fixed rooms** — Rooms.java)
| ROOMSCOUNT | 0x6301 | rooms in area (=6) | ✅ defined + 🟢 fixed 6 (FUN_005c14a0) |
| ROOMNAME | 0x6302 | room name | ⬜ **GAP: writer of PAL name table 0x6cf29a undumped** (lobby-rooms-RE) |
| ROOMPLAYERCNT | 0x6303 | players in room | 🟢 UDP op49 sums per-room counts → "In Lobby: N" |
| ROOMSTATUS | 0x6304 | room status | ⬜ |
| ENTERROOM | 0x6305 | enter a room | 🟢 UDP FUN_005c04f0 (server accepts session, reply byte0=0) |

### Phase E — Slots (games in a room, ≤20/room — Slots.java)
| SLOTCOUNT | 0x6401 | # gameslots in room | ✅ defined |
| SLOTSTATUS | 0x6404 | free/used/full | ⬜ |
| SLOTPLRSTATUS | 0x6403 | players in slot | ⬜ |
| SLOTTITLE | 0x6402 | slot title | ⬜ |
| SLOTPWDPROT | 0x6405 | password-protected flag | ⬜ (owner: password user-set, blank=open) |
| SLOTSCENTYPE | 0x650A | scenario + DVD/HDD type | ⬜ **← scenario source** (scenario-null blocker; pre-loaded, not a query per scenario-source-RE) |
| CREATESLOT | 0x6407 | create a slot (host) | ⬜ **GAP** (client emits nothing until scenario set) |
| JOINGAME | 0x6406 | join a slot (non-host) | ⬜ |
| EXITSLOTLIST | 0x6408 | leave slotlist→roomlist | ⬜ |
| SLOTTIMER | 0x6409 | slot wait time | ⬜ |
| PLAYERSTATS | 0x640A | players-in-room stats | ⬜ |

### Phase F — Rules (slot config — RuleSet.java) → PAL area +0x16c
| RULESCOUNT | 0x6603 | # rules for slot | 🟢 PAL: area +0x16c ruleset (validated: players/wait/difficulty selectable on create) |
| RULEDESCRIPT/RULEVALUE/RULEATTRIB | 0x6604/6606/6605 | rule name/value/attr | 🟢 PAL +0x16c option-table (indices decoded from disc: Difficulty=opt1, Nightmare=opt5, Infinity=opt6) |
| RULEATTCOUNT/ATTRDESCRIPT/ATTRATTRIB | 0x6607/6608/660E | attribute count/name | 🟢 PAL +0x16c entries |
| SETRULE | 0x660B | set a rule | ⬜ (host-side; needs create) |
| SLOTNAME | 0x6609 | set slot name | ⬜ (owner: room title) |
| SLOTPASSWD | 0x660A | set slot password | ⬜ (owner: user-set password) |
| SCENESELECT | 0x6509 | select scenario | ⬜ (pre-loaded in PAL, not a query) |

### Phase G — Game start / session (host broadcasts)
STARTGAME 0x6508, GETREADY 0x6910, PLAYERCOUNT 0x6911, PLAYERNUMBER 0x6912, PLAYERSTAT 0x6913,
GAMEDIFF 0x6914, GAMESESSION 0x6915, GSINFO 0x6916 (gameserver ip:port), GETINFO 0x6801 — **all ⬜**
(the actual co-op game handoff to the gameserver; large frontier).

### Phase H — Slot lifecycle broadcasts
CANCELSLOT 0x6501 🔶(PAL=LOBBY_HEADER), LEAVESLOT 0x6502 🔶(PAL=LOBBY_SLOT), PLAYERSTATBC 0x6503
🔶(PAL=LOBBY_HEADER_DETAILS), CANCELSLOTBC 0x6505, PLAYEROK 0x6506 — **PAL REPURPOSES 0x6501-0x6504**
as the boot-lobby list/detail population (Ghidra FUN_001c6e80/7680/70b0/7a70). ⚠️ Do NOT treat these as
Bioserver slot-lifecycle in PAL.

### Phase I — Chat / social / aftergame
CHATIN/CHATOUT 0x6701/0x6702 ⬜; BUDDYLIST/CHECKBUDDY/PRIVATEMSG 0x6707/6703/6704 ⬜;
ENTERAGL/LEAVEAGL/AGLPLAYERCNT/AGLSTATS 0x6210-0x6213 🔶 (PAL repurposes 0x6211-0x6213 in boot-lobby
progression — snap_server LEAVEAGL/AGLPLAYERCNT/AGLSTATS handlers).

### Phase J — Gameserver
GSLOGIN 0x1031 ⬜, GSINFO 0x6916 ⬜ — the separate game (mission) server. Frontier.

## 3. Key PAL divergences from Bioserver (the "translation")
1. **Two transports** (TCP app + UDP SN@P) vs Bioserver's one TCP stream.
2. **Repurposed IDs**: 0x6110 (SESSION_VERIFY, PAL-only), 0x6501-0x6504 (PAL lobby list/detail, NOT
   Bioserver slot-lifecycle), 0x6211-0x6213 (PAL boot-lobby, NOT aftergame). Trust the Ghidra label, not
   the Bioserver name, for these.
3. **Rules live in area +0x16c** (client-consumed, PAL-specific encoding) rather than per-slot RULE* queries.
4. **Scenario is pre-loaded data**, not a SCENESELECT query (netwk overlay has only NAME/USER/LOID/STAT
   query tags — no scenario tag).
5. **Rooms are 6 fixed** (client-hardcoded); games are SLOTS inside — same as Bioserver Rooms/Slots model.

## 4. Gap analysis → what a working server still needs
Ordered by leverage toward "join a game with another player":
1. **Sign-in (register-812)** — unblock login (state/regN). *Prerequisite for all live testing.*
2. **MOTD 0x614C** — fill the 2 empty post-signin boxes (easy, server-served).
3. **Room names** — resolve the 0x6cf29a writer (undumped) so rooms show names.
4. **Scenario pre-load** — the area-record header byte that sets the create scenario (Model: header
   +0x00..0x34; needs the offset experiment) → unlocks Title/Password/Character/Finish.
5. **CREATESLOT + SLOTSCENTYPE + SETRULE + SLOTNAME/PASSWD** — the create-a-room-and-host path.
6. **JOINGAME + ENTERROOM slot population** — a 2nd console sees + joins the slot.
7. **Server-side session/room/slot registry** — the shared state that cross-populates AREAPLAYERCNT,
   room lists, and slots across clients (currently hardcoded/synthetic). *This is the real multiplayer core.*
8. **STARTGAME + GSINFO + gameserver (0x1031)** — the actual co-op mission handoff. Largest frontier.

## 5. Recommended build order (production `server/`)
L1 transport (spec'd) → login/session → **server-side registry** (accounts, sessions, areas, 6 rooms,
20 slots/room, rules) → area/room/slot query handlers reading the registry → CREATESLOT/JOINGAME mutating
it + broadcasts → scenario/rules on create → gameserver handoff. Graduate each from the SNAP_* harness
once validated against the client.
