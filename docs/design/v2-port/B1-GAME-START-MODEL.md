# B1 — The game-start model: start-press to scenario-load

Date: 2026-08-08 · Author: B1 subagent · Sources ranked: T37 runtime journal + pcap
(`captures/v2-live/T37-20260808-090328.*`) > decompile
(`reverse-engineering/network/sources/overlays/overlay-3dat-decompile/`,
`.../executables/transport-decompile/`) > direct MIPS disasm of `netwk.bin` (base
**0x5ac360**, anchor-checked) > corpus records > bioserver reference.

**Headline (Conclusion, evidence below):** the lobby-side start sequence is ALREADY
COMPLETE on the current server for a solo room. T37 proves every lobby message of the
start path was sent, answered, and consumed: the op-0x08 `STAT` reply at 07:06:24 and
the op-0x0D barrier reply at 07:06:25 both landed, the client finished all screen-5
phases, and handed off to the **game module**. The black screen is NOT a missing
lobby message — it is the **in-game phase**: from 07:06:35 the game module sent an
**unreliable 2-byte op-0x0F probe at 1 Hz for ~119 s** which the server refused every
time (`CHAT_RUNT` ×115), then gave up, returned to the lobby overlay's **post-game
meeting room (screen 0xC)** and wrote the post-game save. The single blocking unknown
for B1 is what that probe is and what must answer or be relayed for it — it lives in
the game module (`game.bin`), outside the 2549-function lobby corpus and stubbed out
of REOF2.

---

## 1. THE ORDERED SEQUENCE — start-press to scenario-load

Screen ids (`0x6C4B90`): 4 = in-room member screen · 5 = room scene / pre-game
staging · 0xC = in-game & post-game results ("meeting room").

### Stage A — screen 4: the START press (all local, no wire message)

| # | Step | Evidence |
|---|---|---|
| A1 | Host button row: cursor 0 = START, gated on `ctx+0x456 >= u16[0x6C076A + (roomIdx-1)*0x15C]` (standby count vs requirement); on failure SFX 5 and nothing else. On success `ctx+0x10 := 4`, `ctx+0x443 := 1` | `FUN_005ff1b0.c:168-179` (Observation). Joiners cannot press START (cursor 0 → SFX 5 only, `:128-130`) |
| A2 | Screen-4 pump state 4: one tick later `ctx+0x10 := 5`, `ctx+0x16 := 900` (a 15/18 s fallback that returns to idle if nothing happens), and calls `FUN_005c4580` | `FUN_005fede0.c:110-118` (Observation) |
| A3 | `FUN_005c4580`: `0x6FF2B1 := 3`, posts **UI event 1** | decompile (Observation) |
| A4 | UI event 1 handler `0x5b5370` (disassembled, not in decompile): if screen == 4 or 0xE, `0x6C4FE5 := 1` | disasm `0x5b5370-0x5b53a0` (Observation) |
| A5 | Next tick, the pre-pump preempt check `FUN_005aec70` sees `ctx[0x455]` (= `0x6C4FE5`) set → `FUN_00616bd0`: **screen := 5**, major `+0xe := 0`, sub `+0xf := 0`, `ctx+0x443 := 2`, clears `ctx+0x1F5C..+0x2E1C` | `FUN_005aec70.c:54-56`, `FUN_00616bd0.c` (Observation) |

**JP contrast:** on BioServer the host BROADCASTS `STARTGAME 0x6508` and the SERVER
broadcasts `GETREADY 0x6910` to the slot (`PacketHandler.java:367-398, 2173`). In PAL
the start press emits NOTHING; the host itself drives the peers in Stage B via
op-0x10 sub-events, and the server's whole job is to answer two queries and relay
op-0x10. (Observation on both sides.)

### Stage B — screen 5 major 0 (`FUN_00616d30`): roster sync + the op-0x0D barrier

Sub-state `+0xf` walk (host has `ctx+0x97e != 0`; a joiner has 0 — set by
`FUN_005f91f0`/`FUN_005fa190`/`FUN_0062d9f0`/`FUN_0062de90`):

| sub | Host | Joiner |
|---|---|---|
| 0 | arm the 14-phase roster SM: `FUN_005c6210(candidates from ctx+i*0x3B0+0x309C/0x30AC/0x30C0, done-cb 0x6181e0)`; sub := 1 | skip straight to sub := 2 |
| 1 | pump `FUN_005b6900` until the roster SM's done-cb `0x6181e0` fires → **sub := 3** (disasm `0x6181e0`: `0x6C4FBB := 0`, `0x6C4B9F := 3`) | — |
| 2 | (joiner path) countdown `0x4C` ticks → sub := 3 | same |
| 3 | `ctx+0x42b := 0x1A`; `FUN_005c45b0(0x618090)` arms the **download SM `FUN_005c4760`**; sub := 4 | same |
| 4 | pump until `FUN_00618090` fires: on status 0 `0x6C4B9F++` → sub := 5; on failure `0x6C5521 := 1` + `FUN_005be9a0(0x6c517c)` (error bail) | same |
| 5 | `FUN_005c4600` copies the finished `0x6FB758` block (0x654 bytes) into the screen ctx: member count `+0x990`, per-player id16 `+0x21DC` / name16 `+0x21EC` / charstats 0xF0 `+0x2200` / `+0x22F0` / `+0x2308`; then `FUN_005bac60(0)`+`FUN_005bad10` → **major := 1** | same |

#### B-i. The 14-phase roster SM `FUN_005c6500` — what each phase consumes

(Confirms and extends `analysis/ROSTER-SYNC-SUBSYSTEM.md` §6. "Server duty" is the
complete list of server involvement.)

| Phase | Consumes / produces | Server duty |
|---|---|---|
| 0 | sends op-0x10 **sub-3** to every non-empty candidate (candidate emptiness = first byte of its id string; solo T37 produced **zero** op-0x10 datagrams — Observation, pcap census); sends **op-0x08 `STAT`** via `FUN_005c28f0(0, 0x5C6350)`; → 1 | **relay sub-3 to each joiner**; answer op-0x08 |
| 1 | waits UNBOUNDED; only exit is the op-0x28 **selector 8** reply (status 0, sub echoed) completing the task → cb `FUN_005c6350` sets phase := 4 | **answer op-0x08** → op-0x28 sel 8, status 0, body `[BE32 8][0][tagEcho][0]` (T37: answered 07:06:24.690 ✓) |
| 2 | identical wait to 1 (alternate entry) | same |
| 3 | bare `return` — parked until an external writer changes the phase | none |
| 4 | sets `0x6CBB7C := 900`, phase := 5, falls through | none |
| 5 | waits until `count(0x6FF2B5[i] != 0) == 0x6FF2B3`, else 900-tick timeout then advances anyway. `0x6FF2B5[i] := 1` is written by the HOST's op-0x10 **sub-4 handler** `FUN_005bbfc0` when a joiner's accept arrives; slot 0 (host) is pre-accepted (`sb v0,-3403(at)` @0x5c6624). Solo: gate passes instantly | **relay each joiner's sub-4 to the host** |
| 6/7 | sends op-0x10 **sub-5** `[playerNo, total]` to each accepted member (i ≥ 1) and **sub-9** ("not admitted") to each declined; compacts via `FUN_005c6360`; phase := 8 | relay |
| 8 | branch: `0x6FF2B3 < 2` → 13 (solo shortcut); else 9 | none |
| 9 | sends op-0x10 **sub-6** `[srcIdx, 0, id16, name16]` for every member×member pair | relay |
| 10 | branch as 8 | none |
| 11 | sends op-0x10 **sub-7** charstats chunks (5/member: 4×0x32 + 1×0x28) | relay |
| 12 | sends op-0x10 **sub-8** ("all data delivered") to members 1..`0x700708`-1 | relay |
| 13 | LOCAL: host mirrors its own send-side arrays `0x700710/20/34` → `0x6FFFAD/BD/D1` | none |
| 99 | active := 0, calls done-cb (`0x6181e0` on first start, `0x6181b0` on the post-game re-run) | none |

**The joiner's side of sub-3** (`FUN_005bbf20`, gate `0x6FF2B1 == 1` — true only for
a member who entered via the 0x6E ENTER reply; the host is at 3 and self-delivery
would no-op): clears `0x6FF2B2`/`0x6FF2AF`/`0x6FB758..+0x654`, and if on screen 4 or
0xE **replies op-0x10 sub-4 (accept, `FUN_005c5c10`, 0x304-byte body) and posts UI
event 1** — i.e. sub-3 is what teleports a joiner onto screen 5. On any other screen
it replies **sub-0x10 (decline, `FUN_005c5c70`)**. (Observation.)

#### B-ii. The download SM `FUN_005c4760` and the op-0x0D barrier

- state 0, host (`0x6FF2B0 != 0`): copies `0x6FFFAD/BD/D1` (stride 0x114) into the
  render block `0x6FB86C/7C/90` (stride 0x150), `0x6FB758 := 0x6FF2B3` (count),
  `0x6FB759 := 0x6FF2B4`; → state 4.
- state 3, joiner: waits UNBOUNDED on `0x6FF2AF != 0` — set ONLY by op-0x10 **sub-8**
  from the host (relayed). Then the same copy; → state 4.
- state 4: `func_0x001de648(conn, 1, 0x5c4720)` — **sends reliable op-0x0D, flags
  `0xA000|0x14`, body BE32(1), reply slot 0x27**; → state 5.
- state 5: waits UNBOUNDED on `0x6CBAA5`, which the reply cb `FUN_005c4720`
  (disassembled `0x5c4720-0x5c4750`) sets: **status 0 → 1 (ok), status 0x27 → 2
  (fail)**. Nothing else in the reply is read. Ok → state 6 → done-cb(status 0);
  fail → state 7 → done-cb(0xFF).
- The op-0x0D reply arrives as **op-0x28 selector 0x0D** (dispatcher
  `FUN_001d9f78` case 0x25 → inner `iStack_18 = selector-1` case 0xC → slot 0x27 =
  `conn+0x5E4`). The server's existing `#onReentryQuery`
  (`server-v2/src/udp/snap-lobby-session.js:739`) answers exactly this shape with
  status 0. **T37: request 07:06:25.005 (`a014 000d … 00000001`), answered ✓.**

**Two distinct op-0x0D uses, discriminated by the body value (Observation, T37 pcap):**

| body | sender | meaning |
|---|---|---|
| `00000001` | `FUN_005c4760` state 4 (cb `0x5c4720`) | the **game-start barrier** ("I am entering the game") |
| `f7e00001` | `FUN_005bcfd0`/`FUN_005bd2e0` (cb `0x5bcee0`) | session re-open / **post-game re-entry** (seen T37 07:08:48, sub 1) |

Both callbacks read only the status byte, so the server's single status-0 answer is
correct for both (Observation). The "reentry" name on this opcode is therefore
incomplete, not wrong.

### Stage C — screen 5 majors 1..4: local load and the game-module handoff

| major | Handler | Does | Wire |
|---|---|---|---|
| 1 | `FUN_00617030` | fade + scene set-up (`FUN_005af300(0)`, `FUN_00618b60`), two timers | none |
| 2 | `FUN_00617110` | builds the 4-byte per-player character array at `0x70F330` from `ctx+i*0x3B0+0x22C8/+0x22CA` (offsets 0xC8/0xCA **inside the 0xF0 charstats blob** delivered in Stage B; `+0x22CA != 0` → 8 = "NPC/absent"); calls `func_0x001d40e0` — which **loads `data_rom_netwk_player_NN.tm2` textures** (`PTR_s_data_rom_netwk_player_11_tm2_0024da30`), NOT a network send (corrects `SUBSYSTEM_MAP.md:181`); latches `ctx+0xc/9/8` from `ctx+0x1F18/1A/1C` | none |
| 3 | `FUN_00617230` | countdown 0x96 | none |
| 4 | `FUN_00617270` | fades, then case 5: `0x874F9C := 1`, **`0x874F35 := 3`** (the "came from a game" marker read back by the return dispatcher `FUN_005b6070`), `0x874FD4 := roomIdx`; **`FUN_00608680`** fills the lobby→game parameter block: `0x874F38/3A/37` = tile/kind/sub (the scenario identity picked at create time — `FUN_005f99c0.c:23-25`, from the tile model `ctx+0x1A..0x1C` built CLIENT-SIDE by `FUN_005fe300`; the server never transmits a scenario id), `0x874F3B = ctx+6`, own id at `0x874FA0`, and per player `func_0x007df390(i, charId, npcFlag, id16, name16)` into the game module; **`FUN_005ac3e0`**: top-level mode `0x6C4FAA := 4` → the lobby overlay yields, **the game module boots the scenario** | none |

### Stage D — in-game (game module). THIS IS WHERE T37 DIED

T37 solo run, PS2 `.129`, room max 1, box 9, handle 0x1 (all Observation):

```
07:06:18.779  create accepted; member-list answered (1 member)
07:06:24.690  op-0x08 STAT answered            <- roster SM phase 1 exit
07:06:25.005  op-0x0D body 00000001 answered   <- download SM barrier exit
              (screen-5 majors 1..4 run locally, ~10 s of loads/fades)
07:06:35.959  first UNRELIABLE op-0x0F: flags 0x2012, sub 0, body `00 00`,
              own sequence counter 1,2,3...   -> server refuses: CHAT_RUNT
07:06:35..07:08:34   115 of these at 1 Hz, all refused; NOTHING else from the
              client but keepalive responses. BLACK SCREEN for the owner.
07:08:47.520  client opens TCP (pre-browser) and resets it
07:08:48.723  op-0x0D body f7e00001 (sub 1) answered  <- post-game session re-open
07:08:49+     80-byte op-0x0F bandwidth probes, room-query — the client is now in
              the POST-GAME MEETING ROOM (screen 0xC: at 07:09:55 it sent chat
              with screenType:12). The save the owner saw is this room's
              post-game save.
07:09:58.587  op-0x07 leave ANSWERED (depth 4 -> 2)   <- the owner's exit press
07:10:10..    silence from the client except one 17-byte probe
07:11:23.675  op-0x02 session teardown (the wait-overlay gave up, ~85 s later)
07:11:44.891  fresh register epoch (full re-login)    <- "exit doesn't work"
```

The probe datagram, byte-exact (pcap):
`2012 00 0f 028107d0 000000NN xxxxxxxx | 00 00 | ba476611` — flags `0x2000` only
(NOT reliable `0x8000`, NOT string `0x0400`, NOT `0x1000`), so in the receive
dispatcher it routes to **slot 0x14** (`conn+0x598`) — a slot the lobby overlay
NEVER installs (`FUN_005bc860` installs 0xd,0xe,3,7,0x13,0x15,4,5,2,6,0xb,8,10
only). The sender and its expectation are therefore in the **game module**, outside
the lobby corpus; REOF2 has its network code stubbed (`game_init.c:157-158`).
(Observation for the routing and the corpus absence.)

**Placement of the T37 symptom (Conclusion):** every phase of `FUN_005c6500` and of
the screen-5 machine COMPLETED. The black screen sits AFTER `FUN_005ac3e0`, inside
the game module's network-session establishment: it beaconed the 2-byte op-0x0F for
~119 s (a ~120 s watchdog), got 115 refusals, aborted the scenario, and fell back to
the post-game meeting room exactly as if an online game had ended. **Nothing in the
14-phase SM was missing — the missing server behaviour is whatever the in-game
beacon needs** (reply, echo, or relay — Unknown, see gaps). That it is a
peer-sync/session barrier is Inference (1 Hz cadence + clean 120 s timeout + clean
fallback); that the server's silence caused the abort is Inference (it is the only
unanswered traffic in the window).

---

## 2. WHAT THE SERVER MUST DO — by scenario

**Already correct (keep; all consumed exactly as implemented — Observation):**
1. op-0x08 → op-0x28 sel 8, status 0, sub echoed (roster phase 1).
2. op-0x0D → op-0x28 sel 0x0D, status 0, sub echoed — for BOTH body values.
3. The three screen-4 queries (op-0x0a / op-0x09 ×2) with batch walking.

**Missing for SOLO start (the B1 milestone as tested):**
4. Whatever the game module's unreliable 2-byte op-0x0F beacon requires. This is the
   ONE blocking unknown — see Evidence gaps. Until identified, at minimum stop
   classifying it as malformed chat (it is not chat: no 0x0400 flag, no reliable
   bit; the CHAT_RUNT log is a misfile).

**Missing for MULTIPLAYER start (proven absent — zero op-0x10 in T37, and
`snap-lobby-session.js` has no inbound op-0x10 case):**
5. **Relay op-0x10 datagrams to the recipient ids in their body**
   (`[BE32 nRecipients][BE32 recipientId]... [sub @+0x08][data @+0x0C]`, only the
   recipient words byteswapped). Without this: joiners never receive sub-3, never
   accept (sub-4 never reaches the host), the host stalls 900 ticks (15 s @60 /
   18 s @50) at phase 5 and then starts WITHOUT them, and joiner screens never leave
   screen 4.

**Not required from the server at start:** any scenario/stage id (client-local from
the create-time tile model), any countdown (op-0x10 sub-0xB is host/optional), any
GETREADY equivalent (the host's sub-3 IS the PAL GETREADY).

---

## 3. BIOSERVER MAPPING (JP TCP → PAL SN@P)

| JP (bioserv2) | PAL |
|---|---|
| host broadcasts `STARTGAME 0x6508` | host presses START; **no wire message** |
| server: mint gamenr, slot → BUSY, broadcast `GETREADY 0x6910` | host roster SM sends op-0x10 **sub-3** to each member (server relays) |
| client queries `PLAYERCOUNT 0x6911` / `PLAYERNUMBER 0x6912` | host pushes op-0x10 **sub-5** `[playerNo,total]` |
| client queries `PLAYERSTAT 0x6913` per player | host pushes **sub-6** (id/name) + **sub-7** (charstats chunks) |
| (implicit end of detail phase) | host pushes **sub-8**; joiner download SM unblocks |
| client status → STATUS_GAME (`db.updateClientOrigin`) | **op-0x0D body 1** → op-0x28 sel 0x0D status 0 (the barrier) |
| `GSINFO 0x6916` → game-server ip:port; client connects, `GSLOGIN 0x8210` | none observed — the in-game traffic stays on UDP 9090 (the 0x2012 op-0x0F beacon). No GSINFO analogue exists in the lobby corpus |
| game server: **dumb relay** of everything to same-gamenumber clients, never the sender (`GameServerPacketHandler.processData`) | **Hypothesis:** the server must do the same with in-game op-0x0F/op-0x10 traffic scoped to the room; solo JP relays nothing, yet PAL solo still beacons — so the beacon may expect a SERVER echo/ack rather than a peer (Unknown) |
| post-game: `POSTGAMEINFO`, after-game lobby by gamenumber | **op-0x0D body 0xf7e00001** re-open + meeting room (screen 0xC) on the same session |

---

## 4. CORPUS / DOC CORRECTIONS

- `SUBSYSTEM_MAP.md:181` (`0x00617110 room_phase02_broadcast_selects` — "submits it
  to the network layer (func_0x001d40e0)"): **SUPERSEDED.** `FUN_001d40e0` loads
  `data_rom_netwk_player_NN.tm2` character textures (`transport-decompile/
  FUN_001d40e0.c`); phase 2 sends nothing.
- `functions/rooms/001de648_snap_send_op0d.md` "Plausibly a room/ready/state
  toggle": now pinned — **two callers, two meanings by value** (§1 B-ii). The
  server-v2 comment "re-entry query" (`snap-lobby-session.js:730`) describes only
  the `0xf7e00001` use; the `1` use is the game-start barrier.
- `ROSTER-SYNC-SUBSYSTEM.md` §6 stands, with one addition: the done-cbs are now
  disassembled — `0x6181e0` (first start) sets screen-5 sub := 3, `0x6181b0`
  (post-game re-run, armed by `FUN_006173c0`) sets sub := 2; both no-op on screen 6.
- The T37 short op-0x0F is NOT the chat opcode misused: flags `0x2012` routes it to
  slot 0x14, not the chat slots 0x0B/0x0D. `CHAT_RUNT` is a server-side misfile.

## 5. EVIDENCE GAPS — exactly what settles each

1. **The in-game beacon (BLOCKS B1).** Sender of the unreliable op-0x0F flags
   `0x2012` body `00 00` @1 Hz, and what it waits for. Not in the lobby corpus, not
   in REOF2 (network stubbed). Settle by: (a) Ghidra decompile of the game module's
   netcode — find the `FUN_001d4d24(conn, 0x12/0x14, cb)` installers and the
   `FUN_001e180c(..., flags 0x2000, len 2, 0x0F, ...)` call site in `game.bin` /
   the in-game overlay; or (b) PINE breakpoint on `0x1e180c` during the black
   screen to capture the caller's ra; or (c) cheapest rig experiment: **echo the
   beacon back verbatim (and/or relay it room-scoped) and observe whether the
   scenario loads** — a one-line server change that directly tests the JP
   dumb-relay hypothesis.
2. **Post-game meeting-room majors 0x0a/0x0b.** No overlay writer of
   `0x6C4B9E = 0x0a/0x0b` exists in the decompile; presumed written by the game
   module on return (alongside `0x874F35`). Settle with a PINE watch of `0x6C4B9E`
   across a game return, or game-module xref.
3. **The meeting-room exit stall** (T37 07:09:58→07:11:23): op-0x07 was answered,
   client then waited ~85 s and tore down. What completion it still needed is
   unknown (candidates: the op-0x07 a/b-variant `0x1000` flag echo — slots
   0x23 vs 0x24 — or a follow-up query we never see). Settle by diffing the leave
   datagram's flags against the answered reply's flags in the T37 pcap.
4. **`FUN_005b6070`** (game→lobby return dispatcher, reads `0x874F35`): its invoker
   and param encoding are untraced (no overlay callers).
5. **Whether roster phase 0 sub-3 includes the host itself** in multiplayer (solo
   sent none; harmless either way since the host's gate `0x6FF2B1==3` no-ops it) —
   confirm on the first 2-player start attempt.
6. Carried over, unchanged: `0x6FF2B4` semantics in a 2-member room; the writer of
   the candidate table `ctx+0x309C` (suspected `0x6CDBE6`, the op-0x0a output).
