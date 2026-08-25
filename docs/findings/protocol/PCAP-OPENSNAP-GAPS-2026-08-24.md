# Pcap sweep with the openSNAP lens — gap fills (2026-08-24)

Sweep of `captures/v2-live/` RS1-20260808-172534 / T35-20260808-001204 / T37-20260808-090328
(T36 is ARP-only — dead capture, nothing to sweep). Method: tshark `udp.payload` dump → full
SN@P message walk (22,261 messages, zero parse errors, multi-datagrams split on inner lengths).
Server = 192.168.2.121. Grades: **Observation** (wire bytes cited) / **Inference** (openSNAP/AM
semantics applied to our wire; PAL check named). openSNAP refs: OPENSNAP-DEEP-DIVE-2026-08-24.md,
OPENSNAP-CROSSREF-2026-08-24.md, indexes/OPCODE-NAME-MAP.md.

## F1 — THE HEADLINE: the wrong-reply-class bug is SYSTEMIC on the room channel, not leave-only

**Observation.** Every room-channel (`0xA000`, 0x1000-clear) reliable client request class in
RS1+T37 was answered with a lobby-context (`0xB000`) reply:

| room-channel request | count (RS1/T37) | our reply | example frames |
|---|---|---|---|
| op-0x0c property upload (240B) | 15 / 30 | `0xB000` op-0x28 | RS1 267→(op28) |
| op-0x0a member list | 6 / 11 | `0xB000` op-0x0a | RS1 3084 window |
| op-0x09 USER/MAXI room counts | 8 / 14 | `0xB000` op-0x09 (12B) | RS1 3084→3088/3089 |
| op-0x08 STAT | 2 / 4 | `0xB000` op-0x28 sel-8 | RS1 5185→5188 (known) |
| op-0x07 room leave | 1 / 2 | `0xB000` op-0x28 sel-7 | RS1 5185→5189 (known, fixed) |
| op-0x0d start barrier (body 00000001) | 1 / 4 | `0xB000` op-0x28 | RS1 4333, T37 357/908/16504/21735 |
| op-0x10 / op-0x0f (T37) | — / 3+1 | `0xB000` op-0x28 | T37 |

**Inference (strong — same mechanism as the CONFIRMED leave case).** The PAL dispatcher routes
BY the received 0x1000 bit (`FUN_001d9f78` case 4/5/6 for op-0x28 subs; the AM callback tables
show the same `&1000` split for the DIRECT commands 0x09/0x0a — `kkQueryGameRoomAttribute` vs
`kkQueryLobbyAttribute` slots, `ResultQueryUserInGameRoomCallBack` vs the lobby variant). So:
- room op-0x09 answered `0xB000` → the LOBBY attribute callback runs, the ROOM count consumer
  never fires → **the "count display stuck / client latches ONE op-0x09 answer" bug**;
- room op-0x0a answered `0xB000` → the room member-list callback never fires → **the
  "Getting information…" starve / members-don't-see-each-other class**;
- room op-0x0d completion answered `0xB000` → the BUSY/start-barrier continuation may never
  fire → **a B1 game-start-stall candidate**.
**Action:** the `SNAP_CHANNEL_BIT_ECHO` echo must generalize: op-0x28 completions for
0x0c/0x0d (already covered by the helper if wired), AND the direct op-0x09/op-0x0a replies.
PAL check per row before flipping each: the op09/op0a reply consumer slots (AM table rows in
OPCODE-NAME-MAP.md; the op28-side split is already Confirmed).

## F2 — the "Unknown" short op-0x0F frames = non-reliable game-channel SEND (the UDP beacon)

**Observation.** 117 (T37) + 1 (RS1) client frames: `cmd 0x0f, flags 0x2000, body = 00 00`
(2 bytes; datagram word `0x2012`), ~1/s cadence in the in-game window; server copies exist
where the echo experiment was on (T37 16515, RS1 4352). Plus exactly ONE reliable room-channel
game packet: T37 16517, `flags 0xA000, cmd 0x0f, 42B` body `280006000414...` (structured
records, no string bit).
**Inference.** Under the AM model op-0x0F with string-bit clear = the GAME PACKET family
(`amkkGamePacketUdpCallBack` non-reliable / `kkGamePacketRudpCallBack` reliable — OPCODE-NAME-MAP
0x0F row). The 2-byte `0000` frames are the client's unreliable in-game beacon; the 42B `0xA000`
frame is a reliable in-game state packet. openSNAP's server RELAYS game packets byte-identical
to the other room members (sender excluded). Our beacon-echo experiment (RS1-A) failed because
an ECHO sends it back to the sender — the one member who must NOT receive it.
**Action:** in-game op-0x0F (string clear) → relay to other in-room members, never the sender,
preserving reliability class. Aligns with the existing `SNAP_GAME_BEACON_RELAY` seam (OFF).

## F3 — cmd 0x14 SEND_ECHO: an unanswered bandwidth/RTT probe sits in the game-start window

**Observation.** T37 frames 911–944 (immediately after the odd op-0x0d `f7e00001` at frame 908):
a burst of EIGHT 64-byte echo frames, body `NN 55 55 … 55` with NN = 00..07, flags 0x2000/0x6000
(non-reliable), plus recurring 1-byte `01` echoes (RS1 ×5, T35 ×2, T37 ×10) throughout lobby/room
phases. The server NEVER replies to any of them (no srv cmd 0x14 in any capture).
**Inference.** cmd 0x14 = `CMD_SEND_ECHO` → `ResultEchoPacketCallBack` (OPCODE-NAME-MAP row;
deep-dive: `kkSendEchoPacket` shares its callback with 0x13). The 8×64B `0x55`-fill burst is a
classic line probe fired at the game-start transition; the 1-byte `01` is a periodic liveness/RTT
echo. A server that reflects the payload fires the client's echo callback. **B1 game-start
candidate:** the barrier window contains BOTH an op-0x0d answered in the wrong class (F1) and an
echo probe we never reflect.
**Action:** implement echo reflection (mirror body, non-reliable, same channel bits, sender only).
Cheap, isolated, evidence-shaped. PAL check: find the PAL echo sender/cb pair.

## F4 — op-0x0c named: CHANGE_USER_PROPERTY, and its body is (today) an empty record

**Observation.** All op-0x0c requests: `flags 0xA000`, 240-byte body, near-all-zero (RS1 267:
one nonzero tail byte). 15/2/30 per capture, answered sel-0x0c op-0x28 (wrong class, F1).
**Inference.** openSNAP 0x0C = `CMD_CHANGE_USER_PROPERTY`, "common reliable room channel
context" — matches perfectly (always `0xA000`). Our v2 label "ROOM_QUERY (connect screen,
260 bytes)" is a misnomer worth a corpus note: the client is UPLOADING its (currently empty)
member property record, not querying. The record being empty at the connect screen suggests the
client populates it later (or only in-game) — do NOT build roster identity on it yet.

## F5 — op-0x09 layout named (query/response), and both context forms coexist

**Observation.** Request body = `u32BE handle + tag[4]` ("USER"/"MAXI"); reply = request + `u32BE
value` (12B). LOBBY form (`0xB000`, handle = box id) for area counts; ROOM form (`0xA000`,
handle = room handle 2..5, always USER+MAXI as a coalesced pair) after room entry — RS1 3084,
3619, 4314, 5169; T37 345, 2162, 21021, 21716, 22571.
**Inference.** = `CMD_QUERY_ATTRIBUTE` in both channel contexts (AM split row). Reply class per
F1. MAXI replies carry 4 (room max) and USER 1..2 — values are right; only the class is wrong.

## F6 — client-side piggybacked ACKs exist (op-0x10 sub-1 queries arrive as 0xE000)

**Observation.** Client op-0x10 sub-1 member-info queries: `flags 0xE000` (= reliable |
**0x4000** | room) — RS1 3625, T37 16485 — the ack field carries a live server seq.
**Inference.** The client piggybacks ACK on reliable sends; confirms the 0x4000+ack mechanism is
bidirectional and licenses (after a PAL check of our sender side) the server-side piggyback
reduction noted in `reliable-channel.js:72-80`.

## F7 — transport health: every reliable client send in all three captures was acked

**Observation.** Ack census over RS1/T35/T37: zero unacknowledged non-embedded reliable client
sends (bare-ack or 0x4000-reply matched every seq). The G2 ack-everything invariant holds on
the deployed builds; the remaining failures are all REPLY-CLASS problems (F1), not delivery.

## Priority order for implementation (my read)

1. F1 — generalize channel-bit echo to op-0x09/op-0x0a direct replies + all op-0x28 completions
   (count-stuck, roster-starve, start-barrier candidates in one mechanism, one flag).
2. F3 — SEND_ECHO reflection (tiny, isolated, unblocks the B1 window test).
3. F2 — game-packet relay for string-clear op-0x0F under the existing beacon-relay seam.
4. F4/F5/F6 — corpus notes + PAL checks; no server change yet.
