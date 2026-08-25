# Room-chat + joiner-scenario wire analysis (2026-08-24 2-console rig)

> **DISPUTED — nora review 2026-08-24 (late), sub-7 chat hypothesis NOT GROUNDED; flag stays OFF.**
> §1's "in-room text = op-0x10 sub-7" reading rests on the corpus NAME `inroom_recv_chat_text`
> (classification-grade, its own record says the chat-vs-charstats question was "not traced"), and
> it CONTRADICTS two standing findings this doc failed to cite: `FACTS.md` CURRENT MODEL (G12
> config section, **Confirmed** snap-re 2026-07-17): sub-7 = **rule DESCRIPTIONS** into
> `0x6fffd1[rule#*0x114+off]` (`G12-config-unlock-RE-2026-07-17.md:34`), and
> `B1-GAME-START-MODEL.md:76`: sub-7 = **charstats chunks** (5/member). The only corpus READERS of
> `0x6fffd1` treat it as 0xF0 blobs; no renderer draws it as chat. Sending chat there could corrupt
> rule descriptions (slots 0..3 collide with rule numbers 0..3) on the screen confirmed working
> tonight. **Falsifier before any flip:** PINE-watch `0x6fffd1 + slot*0x114` + the rule-desc render
> while the HOST sends one in-room line. The §1 byte OFFSETS (slot@app+4, len@app+5, off u16@app+6,
> data@app+8) are independently Confirmed either way. The in-room chat RENDER path is therefore
> **OPEN again** — "delivered+acked, renders nowhere we have identified".

Evidence: `scratchpad/rig2-%02d.pcap0` (18,679 UDP frames, 21:14–21:19) + `journal-snap.log`.
PS2 = .129 "real", emulator = .248 "test123", server = .121. LE scenario fix live (OBAREA-W5).

## 1. Room chat — delivered + acked on the wire; wrong CARRIER for the in-room surface

### Wire (Observation)
Every chat frame is op-0x0F. Flag family tracks the surface exactly:
```
LOBBY (works):  .248→.121 0xb400 seq36 "test1231234"  → relay .121→.129 0xb400 seq82   (rendered)
                .129→.121 0xb400 seq106 "real1afghjpqr"→ relay .121→.248 0xb400 seq40   (rendered)
ROOM  (broken): .129→.121 0xa400 seq156 "real12356"    → relay .121→.248 0xa400 seq68 → .248 BARE-ACK 68
                .248→.121 0xa400 seq79  "test..eklmno" → relay .121→.129 0xa400 seq146→ .129 BARE-ACK 146
```
So room chat IS relayed both directions, correct 0xA4xx room scope (journal `lobby-chat …
screenType:4 relayed:1`), and the recipient transport-ACKs it. The lobby vs room relay differ
in ONLY the channel bit (0xB400 vs 0xA400) — nothing else. Delivery is not the problem.

### Why it doesn't render (Inference, High — decompile-backed)
The in-room text surface is fed by a DIFFERENT opcode than the lobby scrollback:
- Lobby chat renders via the op-0x0F path (`chat_cmd03_recv_line_to_scrollback` 0x005b5520 /
  append `0x006000e0`) → the 8-row scrollback. This is what worked tonight.
- **In-room text is delivered by op-0x10 SEND_TARGET sub-event 7**, not op-0x0F: the game-channel
  dispatcher `FUN_005bba20` (slot 0x13) `case 7 → FUN_005bc1c0` (`inroom_recv_member_text_fragment`),
  **gated by `0x6ff2b1`** (the in-room flag), memcpy of `{slot@+4, len@+5, offset@+6, data@+8}`
  into the per-player chat buffer `0x6fffd1 + slot*0x114`. Confirmed: `FUN_005bba20` switch dumped
  from `overlay-3dat-decompile/FUN_005bba20.c` (case 7).

The server relays in-room chat as op-0x0F 0xA400. The in-room screen listens on op-0x10 sub-7.
Hence "lobby chat works, room chat does not, though both are on the wire."

### Fix spec (a): room chat
When relaying chat to a member who is **in a room**, emit it as **op-0x10 (SEND_TARGET) sub-event 7**
addressed into that room, body `[roomId u32][?][sub=07][slot@+4][len@+5][offset@+6 = 0][text@+8]`
(the exact header echo matches the other op-0x10 subs we already send, e.g. sub-0x05/sub-0x0C).
Keep op-0x0F for the LOBBY surface. Grade: Inference (High) — the receiver decompile + the
delivered-but-unrendered wire; needs one rig send to confirm the byte layout of sub-7's header.
Cheapest confirm: PINE-watch `0x6fffd1 + slot*0x114` while sending an in-room line.

## 2. Joiner always sees "Training" — the scenario is never on the wire

### What the joiner (.129) received on join (Observation, 21:16:23–24)
```
MEMBER-JOIN seq131  name="real" id=2
op-0x10 sub-0x05 seq132  00000001 00000000 05000000 04 02 0000   = max 4 / current 2   (counts OK)
op-0x10 sub-0x01 seq133  772 bytes, ALL ZERO after the 8-byte header  ← room-info blob, empty
op-0x49 room records seq117-125  52B: 00…01 "12345" 00…01 00…0401…  ← room NAME only, NO scenario
```
The op-0x10 **sub-1 room-info blob is 772 bytes of zeros** (v1's known "0x300 zeroed" placeholder,
here 0x300). op-0x49 carries the room name ("12345") and the 4/1 limits but **no scenario field**.
With no scenario source, the joiner's room screen renders scenario id 0 = **Training**. Confirmed.

### The host's scenario is never transmitted (Observation)
Walked the host's (.248) create + in-room frames: the CREATE body (`f03c0004 … "12345" … 020b0a10`),
the op-0x08 "STAT@" named-channel query, and op-0x09 USER/MAXI carry **no scenario id**. This matches
the established finding that the create-screen scenario RING is CLIENT-LOCAL (the create screen sends
nothing for rule/scenario selection). The game-start op-0x10 sub-3→sub-4 handshake (780-byte sub-4,
seq170) is likewise zeroed. **The server currently has no way to learn the room's scenario**, so it
cannot put it in the joiner's blob — this is a genuine missing wire path, not a serialization bug.

### Fix spec (b): scenario
Two parts, and part 1 needs RE:
1. **CAPTURE (needs decompile):** find where the client emits the chosen scenario id. Bioserver's
   analogue is `SCENESELECT 0x6509` (C→S QUERY `{0,type,0,scenario}`, stored server-side — BIOSERVER-
   CONTRACT.md §153/182). PAL/SN@P has no TCP SCENESELECT (create is client-local), so the candidate
   is a create-time or game-start op-0x10 sub the server currently drops: prime suspects are the
   op-0x0c CHANGE_USER_PROPERTY (F4/PCAP-OPENSNAP-GAPS) or the sub-3/sub-4 start handshake. RE target:
   which of the host's un-decoded fields (create body `020b0a10`; the op-0x0c body) holds a value
   1..11 matching the picked scenario. Grade: Inference/needs-RE.
2. **ECHO:** once captured into the room registry, write the scenario id into the op-0x10 **sub-1**
   room-info blob the joiner reads (`FUN_005bc0e0` = sub-5 limits' sibling; the sub-1 consumer that
   reads the 0x300 blob is the RE target for the exact offset). The blob is already delivered; only
   its content is zero. Grade: Observation (blob is the vehicle) + Inference (offset pending RE).

## Summary
- **Room chat:** delivery works; wrong opcode. Relay in-room chat as **op-0x10 sub-event 7** (into
  `0x6fffd1+slot*0x114`, gate `0x6ff2b1`), keep op-0x0F for the lobby. High-confidence, one-slice fix.
- **Scenario:** the joiner's sub-1 blob and op-0x49 records carry no scenario (→ Training id 0), and
  the host never puts the scenario on the wire — a missing capture path. Needs a short RE to find the
  host's scenario field (candidate: op-0x0c / start handshake), then echo it into the sub-1 blob.
