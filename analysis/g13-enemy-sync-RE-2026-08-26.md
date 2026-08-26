# G13 — enemy sync: the in-game peer/entity layer (live Ghidra + pcap, 2026-08-26)

Traced the in-game peer-session layer end-to-end (send AND receive AND loopback), decoded the
message/record format byte-for-byte against `captures/v2-live/ingame2.pcap`, and found a
**100 %-dropped message class**.

**VERDICT (one line): the game runs TWO transport classes on op-0x0F — reliable (`0xA0xx`) and
unreliable (`0x20xx`). Our server relays the reliable one and drops 100 % of the unreliable one.
The unreliable class carries (a) the peer keepalive that prevents the 31 s peer-timeout sweep and
(b) the entire `id=0x0008` world-entity channel. That is a server-side fix and the flag to test it
already exists (`SNAP_GAME_BEACON_RELAY`).**

---

## 0. Evidence base

- Live Ghidra bridge, `SLES_533.19` main-EE (primary).
- `captures/v2-live/ingame2.pcap`, `char.pcap`, `rig4.pcap` (wire, secondary).
- Cross-checks: `reverse-engineering/network/functions/transport/001caa30_snap_send_reliable.md`,
  `.../001caad0_snap_send_unreliable.md`, `.../chat/001df1d8_snap_send_op0f_unrel.md`;
  openSNAP `opensnap/protocol/commands.py` naming.
- Read-only inspection of `server-v2/src/udp/snap-lobby-session.js`,
  `server-v2/src/udp/snap-lobby-sessions.js`, `server-v2/src/transport/reliable-channel.js`.

---

## 1. CORRECTION to `analysis/g13-wire-samples-2026-08-26.txt` (do not carry the old reading forward)

`ingame2.pcap` contains **two distinct game sessions**, and the roles are swapped between them.
The old doc's role labels mixed them, which produced the phantom "the joiner re-emits the host's
own message" observation.

| phase | window | peer 0 | peer 1 |
|---|---|---|---|
| 1 | t = 120 – ~2384 s | **192.168.2.248** (real PS2) | .129 present but sends no game records |
| 2 (the co-op run) | t = 2384 – 2647 s | **192.168.2.129** (PCSX2) | **192.168.2.248** (real PS2) |

Evidence (Confirmed, tshark provenance trace): first slot-tagged record originated per flow —
`.248→.121 slot0 @ t=120.205`, `.129→.121 slot0 @ t=2384.111`, `.248→.121 slot1 @ t=2385.734`.
Propagation chains show every phase-2 slot-0 record originating at `.129` and being relayed to
`.248`, and every slot-1 record originating at `.248` and relayed to `.129`.

Consequence: **the 08-25 "top 4 bits = the SENDER's own peer index" model is CORRECT and survives.**
The doc's sample labelled "JOINER .248 multi-message frame" is a PHASE-1 frame in which `.248` was
peer 0. There is no echo layer, no shared-object channel in the slot field, and no exception to
`FUN_001be9c0`'s own-index tagging. **Q3 is resolved as "artefact of mixed sessions".**

---

## 2. The layer stack (all Confirmed, live decompile)

```
game logic
   |  appends 12-byte-header RECORDS into its own buffer
   v
FUN_001be1d0(buf,len)      "queue one outbound message"
   |  writes  u16 (myPeerIdx<<12)|len  + body   into  STAGING queue 0x352800
   v
FUN_001be330               <-- NET-SM STATE 5 HANDLER (the in-game splitter)
   |  walks the body record-by-record and FANS IT THREE WAYS:
   |     record[+2] == 0x04  ->  0x352c20  (RELIABLE   outbound)
   |     record[+2] != 0x04  ->  0x353040  (UNRELIABLE outbound)
   |     EVERY record        ->  0x351fe0  (LOCAL LOOPBACK / apply stream)
   v
FUN_001be7a0 -> FUN_001caa30(buf,len) -> FUN_001df1d8(conn, 0x8000, ...)   [RELIABLE   op-0x0F]
FUN_001be8b0 -> FUN_001caad0(buf,len) -> FUN_001df1d8(conn, 0x0000, ...)   [UNRELIABLE op-0x0F]

receive:
slot 0x12 cb 0x1cac70 (reliable)  \
slot 0x14 cb FUN_001cad10 (unrel) / --> SAME ring 0x36a900..0x36b900 (DAT_00248850)
   -> FUN_001cab70 -> FUN_001caed0 -> FUN_001caf60 -> queue 0x354080
   -> FUN_001beb90 (peer router) -> appends  u16 (peerIdx<<12)|len + body  to 0x351fe0
   -> FUN_001be700(&ptr,&peerIdx)  = THE CONSUMER API
   -> FUN_001bfb10 -> FUN_001bd940 -> game
```

### Buffer map (Confirmed — `FUN_001bdc10`, the net-layer init)

| queue obj | data buffer | cap | role |
|---|---|---|---|
| `0x354080` | `0x353880` | 0x800 | inbound reassembled messages |
| `0x353860` | `0x353060` | 0x800 | keepalive scratch |
| `0x353040` | `0x352c40` | 0x400 | **UNRELIABLE outbound** |
| `0x352c20` | `0x352820` | 0x400 | **RELIABLE outbound** |
| `0x352800` | `0x352000` | 0x800 | game staging (pre-split) |
| `0x351fe0` | `0x34dfe0` | 0x4000 | **apply stream** (remote + own loopback) |
| `0x34df80 + i*0x18` | `0x349f80 + i*0x1000` | 0x1000 | per-peer stream, i < peerCount |

Queue struct: `+4` read ptr, `+8` buffer, `+0xc` write ptr, `+0x10` capacity
(`FUN_001bf140/160/170/1e0/200/230/2a0`).

Init args (Confirmed, `FUN_001bf800`):
`FUN_001bdc10(conn=uRam0035a6f4, myPeerIdx=cRam0035b721, peerCount=cRam0035b720)`.
- **`0x35b720` = peer count, `0x35b721` = my peer index** — PINE-readable game-start globals.
- All peers are set `active = 1` at init; `gameObj[0x11] = (myIdx == 0)` is the **is-host** flag.
- **No RNG seed is passed into this layer** → the peer-session layer does *not* do a lockstep seed
  exchange. (A seed could still ride the lobby game-start payload; out of scope here.)

---

## 3. Net state machine (`bRam003540a6`, table `PTR_LAB_00248370`)

Table entries resolved via `xrefs_from` on `0x00248370..0x0024838c` (Confirmed):

| state | handler stub | what it does |
|---|---|---|
| 0 | `0x001be070` | calls `FUN_001bef30(k)` — a state SET; argument not readable (see §7) |
| 1 | `0x001be080` | calls `FUN_001bef30(k)` |
| 2 | `0x001be090` | calls `FUN_001bef30(k)` |
| 3 | `0x001be0a0` | calls `FUN_001bef30(k)` |
| 4 | `0x001be0b0` | reads `DAT_00248350`, calls `FUN_001bef30(k)` (a timed transition) |
| **5** | `0x001be0d0` | **IN-GAME**: reads `DAT_00259090`, branches, calls **`FUN_001be330`** (the splitter) |
| 6 | `0x001be120` | no calls / no data refs found |
| 7 | `0x001be130` | **TERMINAL** — `FUN_001bde80` returns `-1` when state == 7 |

Transitions out of band:
- Any framing error → `FUN_001bef70(code, a, b)` → stores `0x3541f4/f8/fc` → `FUN_001bef30(7)` = dead.
- `FUN_001beb90` error codes: `2` = transport read error, `4` = negative queue length,
  `5` = **peer index >= peerCount**. `FUN_001be330` error code `5` = record shorter than 13 bytes.
- Savestates (08-26) show state = **5** in game. Confirmed.

---

## 4. Message + record format (Confirmed — parses byte-perfect on every sample in the pcap)

### 4.1 Message (the `(slot<<12)|len` frame)

```
u16 LE header : bits 15..12 = SENDER'S PEER INDEX   (slot)
                bits 11..0  = BODY LENGTH
<body_len bytes>
```
Several messages may be concatenated in one SN@P payload. Framing is length-exact; a gap kills the
session (`FUN_001beb90` → `FUN_001bef70(4|5)` → state 7).

Reserved slot: **`0x0F` = CONTROL, not a peer.** `FUN_001befc0` (peer timeout) injects
`thunk_FUN_001bffc0(0x351fe0, 0xf003)` + `01 <peerIdx> <reason>` directly into the apply stream, and
`FUN_001bfb10` decodes exactly that (`if (peerIdx == 0xf && body[0] == 1)` → remove peer, and
**re-evaluate host-ness**: `gameObj[0x11] = (peerList[0] == myId)` = host migration).

### 4.2 Record (the 12-byte header inside a body)

| off | size | field | evidence |
|---|---|---|---|
| +0 | u16 LE | **channel / id** (0x0001, 0x0002, 0x0005..0x0008 observed) | wire |
| +2 | u8 | **transport class**: `0x04` → reliable queue, anything else (`0x02` observed) → unreliable | `FUN_001be330` `if (cStack_fe == '\x04')` |
| +3 | u8 | **total record length** incl. this header, unpadded; consumer rounds UP to 4 | `FUN_001be330` `if (bStack_fd & 3) len += 4 - (len & 3)` |
| +4 | u32 LE | sender frame counter (monotonic per console) | wire |
| +8 | u16 LE | id echo (== +0) | wire |
| +10 | u8 | **sub-type** — always equals the first payload TLV tag | wire, 8/8 families |
| +11 | u8 | **owner peer index** | wire (0 for peer-0 records, 1 for peer-1) |
| +12 | .. | payload = TLV(s): `{ u8 tag, u8 len, u8 index, u8 flags }` + data | wire |

Only `+2` and `+3` are read by the transport layer; `+0`, `+4`, `+8..+11` and the payload are
game-level (grade: Likely for the field names, Confirmed for the offsets/values).

### 4.3 Observed channels (co-op phase of `ingame2.pcap`, t ≥ 2384 s)

| id | class | len(s) | n | owner | meaning |
|---|---|---|---|---|---|
| `0x0001` | 0x04 reliable | 0x24 (mostly), 0x1c/0x2c/0x38/0x3c/0x44/0x48/0x50/0x5c | 429 | peer 0 | **player-0 state** (TLV tag 0x00 wrapping tag 0x02 = 16.16 transform) |
| `0x0002` | 0x04 reliable | same shapes | 384 | peer 1 | **player-1 state** |
| `0x0005` | 0x04 reliable | 0x12 / 0x14 | 11 | both | infrequent; sub 0x06 / 0x00 |
| `0x0006` | 0x04 reliable | 0x14 / 0x1c | 19 | both | **session handshake** — first records of the run (`ctr=2`), sub 0x01/0x02 |
| `0x0007` | 0x04 reliable | 0x13 / 0x14 / 0x17 / 0x1c | 5 | both | sub 0x00/0x04 |
| `0x0008` | **0x02 UNRELIABLE** | 0x12 / 0x22 / 0x26 / 0x2a | **111** | peer 1 only | **world-entity channel** (§5) |
| `0x0008` | 0x04 reliable | 0x14 / 0x15 | 3 | both | entity spawn/registration (TLV tag 0x00, `80 00 <idx> 03 ...`) |

Player transform (id 1/2, TLV tag 0x02 len 0x14), decoded 16.16 LE:
`88 2e 65 2b` = 11109.18, `b8 26 88 27` = 10120.15 (peer 0) versus
`b9 2e 05 2b` = 11013.18, `cc bf 8e 27` = 10126.75 (peer 1) — two players ~96 units apart.

---

## 5. The entity channel `id=0x0008` (Q4)

Only stream in the whole capture that is **not** a player and **not** a one-shot:

```
08 00 02 2a  <ctr>  08 00 28 01  | 28 1e 01 04 | 01 1f 3c 00 3c 00 | b8 75 31 30 | 00 00 e0 d2 | ...
^id ^cls ^len        ^id ^sub ^owner  ^tag ^len ^idx ^flags   ^state/anim/timers  ^16.16       ^16.16
```

- 95 × `sub 0x28` (len 0x2a, 30-byte TLV) + 14 × `sub 0x38` (len 0x12) + 1 × `sub 0x2e`, over a
  263-second window → **~0.4 Hz aggregate, inter-arrival 0.28 – 6.5 s**.
- TLV `index` byte is **always 0x01** → exactly ONE entity in this session.
- The 16.16 values move continuously (integer parts 0x2f95 → 0x3031 → 0x30b0 …) and lie in the same
  world-coordinate range as the player transforms.
- `+11` (owner) is always `1` — the console that OWNS/simulates the entity is the one that transmits.

**Model (grade: Likely, strong):** entities are spawned locally on every console from scenario data
(reliable `id=8 type=4` registration, `80 00 <idx> 03`), then **owner-replicated**: the owning
console periodically broadcasts an authoritative transform + state; non-owners simulate/interpolate
between updates. 0.4 Hz is far too slow for the observed motion, so the receiver *must* be running
its own simulation driven by these corrections.

**The symptom falls straight out of this:** a console that receives ZERO `id=0x0008` records never
gets an entity's state/target, so the entity sits at its spawn pose = **frozen**, while the owner
sees it move. The 08-25 note ("the joiner sees a zombie the host does NOT") is the same mechanism
with the roles the other way round — in that phase the joiner was the owner.

**NOT ruled out (Hypothesis):** that some enemy classes are additionally gated on `myPeerIdx == 0` /
`gameObj[0x11]` (the is-host flag). Proving or killing that needs the game's entity-AI code, which
is not reachable from this layer (see §7).

---

## 6. THE GAP — what the server drops (Q5, **Confirmed**)

### 6.1 Wire measurement (three independent captures)

| capture | client → Pi, unreliable op-0x0F (`0x20xx`) | Pi → client, unreliable op-0x0F |
|---|---|---|
| `ingame2.pcap` (whole) | `.129` 46 + `.248` 385 = **431** | **0** |
| `ingame2.pcap` (co-op phase) | `.129` 45 + `.248` 150 = **195** | **0** |
| `char.pcap` | `.129` 132 + `.248` 232 = **364** | **0** |
| `rig4.pcap` | `.129` 44 + `.248` 42 = **86** | **0** |

Reliable (`0xA0xx`) op-0x0F relays fine in the same windows (e.g. rig4: 24 in → 25 out).
**Every unreliable game packet ever sent by a console has been discarded by our server.**

### 6.2 What is in the dropped class

Payload census of unreliable op-0x0F bodies in `ingame2.pcap`:

| payload | n | what it is |
|---|---|---|
| `0000` | 168 | `(slot 0 << 12) \| 0` — **peer-0 keepalive** |
| `0010` | 51 | `(slot 1 << 12) \| 0` — **peer-1 keepalive** |
| `<44-byte / 40-byte / 20-byte>` | ~110 | **`id=0x0008` entity records** |

The 2-byte bodies are emitted by `FUN_001be9c0`:
```c
if (((int)lVar2 + iVar5 == 0) && (1.0 < fRam003540bc - fRam003540c0)) {   // nothing sent for >1 s
    FUN_001bf1b0(0x353860);
    thunk_FUN_001bffc0(0x353860, (bRam003540a4 & 0xf) << 0xc);            // header, len = 0
    lVar3 = FUN_001caad0(FUN_001bf170(0x353860), 2);                      // UNRELIABLE, 2 bytes
```
i.e. **an idle peer heartbeat, sent on the unreliable channel** — this is exactly the thing our
server documents as "the in-game 1 Hz beacon, body `00 00`, semantics Unknown, game module outside
the corpus". It is now known: it is the peer-session keepalive, and its two observed bodies are the
two peer indices.

### 6.3 Why dropping it is fatal — the peer sweep (Confirmed end-to-end)

`FUN_001beb90` tail:
```c
for (peer = 0; peer < peerCount; peer++)
  if (peer != myPeerIdx && peer.active == 1 && DAT_00248338 < now - peer.lastActivity) {
      peer.active = 0; cRam003540af--; FUN_001befc0(peer, FUN_001be6a0());   // DAT_00248338 = 31.0 s
  }
```
and at the top of the same routing loop:
```c
if (*(char *)(peerIdx*0x3c + 0x3540ec) == '\0') { FUN_001bf230(0x354080, msgLen); }   // DROP, silently
```
**There is no re-activation path.** `active = 1` is written in exactly one place, `FUN_001bdc10`
(init). Once swept, that peer is dead for the rest of the session, and `FUN_001befc0` injects the
slot-0xF "peer left" control message so the game removes it from the roster and re-computes host-ness.

That is precisely the 2026-08-26 savestate: `peer[1].active = 0`, `lastActivity` frozen,
`peerCount` still 2 → **question (a)/(b) in `ingame-peer-vanish-RE-2026-08-26.md` is answered: (a),
the host timed peer 1 out and then ignored everything it sent.** The trigger is a >31 s window where
the joiner produced no *reliable* records (a cutstage/loading gap) — during which the ONLY thing it
sent was the unreliable keepalive, which we drop.

### 6.4 The server code that drops it

`server-v2/src/udp/snap-lobby-session.js`:
```js
#onGameChannel(message) {
    if (!message.reliable) return this.#onGameBeacon(message);   // <-- everything unreliable goes here
```
`#onGameBeacon` consumes the frame; both `gameBeaconEcho` and `gameBeaconRelay` default `false`
(`server-v2/src/config/server-config.js:356-357`), so nothing leaves. Only the reliable branch
reaches `SNAP_GAME_RELAY`.

### 6.5 The client is already able to consume a relayed unreliable packet (Confirmed)

`FUN_001cadc0` installs BOTH receive callbacks against the SAME ring:
```
FUN_001d4d24(conn, 0x12, 0x1cac70);   // reliable   game packet
FUN_001d4d24(conn, 0x14, 0x1cad10);   // unreliable game packet
```
and `FUN_001cad10` appends into `DAT_00248850` inside `0x36a900..0x36b900` — the identical ring the
reliable callback writes. So the peer router cannot tell the two apart; **a relayed unreliable
packet is consumed exactly like a relayed reliable one.** (openSNAP `commands.py` names slot 0x12
`kkGamePacketRudpCallBack`; the corpus records `001caa30_snap_send_reliable` /
`001caad0_snap_send_unreliable` agree — no contradiction with the live decompile.)

---

## 7. Needs a fresh decompile (could not be reached)

Ranked by value to G13:

1. **`0x001be070 / 080 / 090 / 0a0 / 0b0 / 0d0 / 0120 / 0130`** — the eight net-SM stubs. Ghidra has
   them as raw `LAB_`, not functions, so `decompile_function`/`disassemble_function` refuse. Needed
   to read the *arguments* to `FUN_001bef30(k)` and hence the real state graph for 0..4 and 6.
   *(Fix: mark them as functions in Ghidra, or disassemble `0x1be070..0x1be150` raw.)*
2. **The game-side record dispatcher** — the caller chain above `FUN_001bd940`
   (`FUN_001bd840` / `FUN_001bd940` / `FUN_001bf800` all have **zero xrefs_to**; they are reached
   through a runtime-built pointer table). This is where `id=0x0001..0x0008` are routed and where
   "is this entity mine to simulate?" is decided. Without it, §5 stays *Likely*, not Confirmed.
3. **`FUN_001bfe20`, `FUN_001bdbe0`, `FUN_001bd4f0`, `FUN_001bd740`, `FUN_001bd8f0`** — the rest of
   the adapter, for completeness of the apply path.
4. **`DAT_00259090` / `DAT_00248350` / `DAT_00248358` / `uRam00349f70`** — the state-5 gate and the
   reliable/unreliable send intervals. `uRam00349f70` in particular sets the UNRELIABLE drain rate
   and would explain the 0.4 Hz entity rate.
5. The lobby-side game-start payload (op-0x49 / op-0x10 body) — the only remaining place an RNG seed
   could travel. Not needed if §5 holds, but it is the one way the "deterministic lockstep" model
   could still be alive.

---

## 8. Q5 — verdict and the next experiment

### Verdict

| claim | grade |
|---|---|
| The top 4 bits of the message header are the SENDER's peer index; there is no echo/shared-object channel | **Confirmed** (`FUN_001be9c0`, `FUN_001be330`, `FUN_001beb90`) — Q3 closed |
| `0x351fe0` is a single unified apply stream carrying remote peers' messages AND a loopback of my own | **Confirmed** (`FUN_001be330`, `FUN_001beb90`, `FUN_001be700`) — Q1 answered |
| Record `+2 == 0x04` → reliable, else unreliable; `+3` = padded length | **Confirmed** (`FUN_001be330`) — Q2 answered |
| The client sends a 2-byte per-peer keepalive on the UNRELIABLE channel every ~1 s of idle | **Confirmed** (`FUN_001be9c0` + 219 wire samples) |
| A peer with no traffic for 31.0 s is swept inactive, its packets are then dropped forever, and a slot-0xF "peer left" is injected | **Confirmed** (`FUN_001beb90`, `FUN_001befc0`, `FUN_001bfb10`, `FUN_001bdc10`) |
| Our server relays 0 % of unreliable op-0x0F | **Confirmed** (3 pcaps + the `if (!message.reliable)` branch) |
| `id=0x0008` is the world-entity (enemy/object) channel, owner-replicated, ~0.4 Hz corrections over locally simulated entities | **Likely (strong)** — position range, single index, owner byte, symptom fit; not proven without item §7.2 |
| No RNG seed / lockstep in the peer-session layer | **Confirmed for this layer** (`FUN_001bdc10` takes only conn/myIdx/peerCount) |
| Enemy AI is additionally gated on a host flag | **Hypothesis, untested** |

**So: the server IS missing a message family, and it can send it.** This is not a
client-deterministic dead end and it is not a reliable-window/ordering problem (the reliable relay
was lossless in `rig4` and in the 08-26 journal). It is an entire transport class that was
mis-classified as an unknown 1 Hz beacon and consumed.

### THE next experiment (single flag, no code change)

**Set `SNAP_GAME_BEACON_RELAY=1` on the Pi** (leave `SNAP_GAME_BEACON_ECHO=0` — echoing a peer's own
keepalive back at it is pointless and re-injects its own index).

Why this is safe and correct as-is (read-only review of the existing implementation):
- `#relayGameBeacon` is room-scoped, excludes the sender, and passes the payload **byte-identically**
  (`snap-lobby-sessions.js:582-589`) — the same dumb-relay rule the reliable path already uses.
- `deliverGameBeacon` → `channel.sendUnreliable({ opcode: 0x0f, subSelector, payload, flags })`;
  `#requireSendableFlags` masks the low-10 length bits and `encodeDatagram` recomputes the length,
  so a 44-byte entity record relays as correctly as a 2-byte keepalive. The sender's `0x20xx` flags
  become `0x2000` = the shape the client's slot-0x14 callback expects.
- The recipient's unreliable sequence is stamped by the channel, which is required (the client tests
  `conn+0x10 <= seq`).

**How to verify, in order of decisiveness:**
1. **pcap** — `Pi → client` frames with `udp.payload[0] & 0xf0 == 0x20 && payload[2:4] == 000f` must
   go from 0 to ≈ the peer's send count. (Filter used here:
   `python analysis-scratch an6.py` logic — byte0 high nibble + op word.)
2. **PINE on the host** — read `0x3540ec + 1*0x3c` (peer[1].active). It must stay `1` across a
   cutscene; and `0x3540ec + 1*0x3c + 8` (last-activity float) must keep advancing. Today it freezes
   and the byte goes to 0 (08-26 savestate). Also read `0x35b720` (peerCount) / `0x35b721` (myIdx)
   to confirm roles without guessing.
3. **Rig** — enemies move on the joiner; the joiner's character no longer vanishes on the host after
   a cutscene.

Expected outcome ranking:
- The **peer vanish** should be fixed outright by the keepalive alone (Confirmed mechanism).
- **Enemy movement on the joiner** should be fixed if §5 holds (Likely). If enemies stay frozen
  *while* the entity records are now demonstrably arriving (verify with the pcap), then the
  remaining cause is a client-side ownership/AI gate and item §7.2 becomes mandatory.

### Second-order note (do not bundle into the same run)

`FUN_001be330`'s splitter writes the reliable and unreliable halves of one staged message as **two
separate messages, each with its own `(myIdx<<12)|len` header**. Both must arrive; they are
independently framed, so ordering between the two classes is not load-bearing, but *loss within
either* still kills the session (`FUN_001bef70(4|5)` → state 7). Keep the reliable relay exactly as
it is while testing the beacon relay, so a regression is attributable.

---
---

# ADDENDUM 2026-08-26 (post-nora review: GROUNDED-WITH-CAVEATS)

Two follow-ups from review. Nothing above is rewritten; §6.2's census figure is marked SUPERSEDED
below with the reason, per `docs/CORPUS-METHODOLOGY.md` (the corpus is living — correct it, keep the
old conclusion visible).

## A1. The unshown load-bearing step: does a ZERO-LENGTH keepalive reach the `lastActivity` write?

**YES — Confirmed at disassembly level. The store sits in the MIPS DELAY SLOT of the length check,
so it executes for a len-0 message.** The keepalive half of the fix stands.

The review was right that §6.3 quoted the sweep and the drop-if-inactive line but never showed the
write. There are **two** writes to `peer.lastActivity` (`0x3540ec + idx*0x3c + 8` = `0x3540f4 + idx*0x3c`)
in `FUN_001beb90`, and only one of them matters:

### WRITE #1 — stamps MY OWN slot (irrelevant to the sweep)

```
001bec50: lwc1 f0,0x40bc(at)      ; f0 = fRam003540bc  (now)
001bec58: lbu  a0,0x40a4(at)      ; a0 = bRam003540a4  = MY peer index
001bec5c: sll  v0,a0,0x4          ; v0 = idx*16
001bec60: subu v0,v0,a0           ;    - idx        = idx*15
001bec64: sll  v0,v0,0x2          ;    <<2          = idx*0x3c
001bec68: addu v0,v1,v0           ; v1 = 0x3540f4
001bec70: _swc1 f0,0x0(v0)        ; peer[MY idx].lastActivity = now
```

Fires whenever `FUN_001caf60` successfully pulls bytes off the transport. It stamps the console's
OWN slot, which the sweep explicitly skips (`if (uVar6 != bRam003540a4)`), so it can never keep a
remote peer alive.

### WRITE #2 — the one the fix depends on: per-SLOT, and BEFORE the length test

```
001bed90: lui  v0,0x35
001bed94: subu v1,v1,a0           ; v1 = slot*15   (a0 = slot, from the message header)
001bed98: addiu v0,v0,0x40a0
001bed9c: sll  v1,v1,0x2          ; v1 = slot*0x3c
001beda0: addu v1,v0,v1           ; v1 = 0x3540a0 + slot*0x3c
001beda4: lbu  v0,0x4c(v1)        ; active  @ 0x3540a0+0x4c = 0x3540ec + slot*0x3c
001beda8: bne  v0,zero,0x001bedc8 ; inactive -> fall through to the silent drop
001bedb8: jal  0x001bf230         ;   (drop: pop the message, no stamp, no delivery)
001bedc8: lw   v0,0x50(v1)        ; ACTIVE: msgCount @ +0x50 = 0x3540f0 + slot*0x3c
001bedd4: sw   v0,0x50(v1)        ; msgCount++
001bedd8: lwc1 f0,0x40bc(at)      ; f0 = now
001beddc: beq  s1,zero,0x001bee0c ; s1 = BODY LENGTH; if 0 -> skip the 0x351fe0 append
001bede0: _swc1 f0,0x54(v1)       ; <<< DELAY SLOT: peer[slot].lastActivity = now  -- ALWAYS RUNS
001bede4..08:                     ;   (len>0 only) append header+body to the apply stream 0x351fe0
001bee0c: jal  0x001bf230         ; pop the message from 0x354080
```

`0x54(v1)` = `0x3540a0 + slot*0x3c + 0x54` = `0x3540f4 + slot*0x3c` = peer-table `+8`. Confirmed.

The instruction at `001bede0` is in the delay slot of the `beq s1,zero` at `001beddc`. On MIPS the
delay-slot instruction executes **before** the branch resolves, taken or not. Ordering is therefore:
active-check -> counter++ -> **lastActivity := now** -> *then* the `len == 0` branch skips only the
accumulator append. A zero-length keepalive refreshes the timer and does nothing else — exactly what
a keepalive should do.

This is the delay-slot hazard `CLAUDE.md` / `docs/CORPUS-METHODOLOGY.md` warns about. Here it
happens to work in our favour, and the C decompile (`if (uVar6 != 0) { ...append... }` appearing to
follow the stamp) is a faithful rendering — but the claim is only *provable* from the disassembly.
Reviewers should not accept the C form alone for it.

**Grade: Confirmed.** No `length == 0 -> continue` exists before the stamp.

### A1b. Per-SLOT or per-SENDER? — per-SLOT, from the message header

`a0` at `001bed90` is the slot nibble extracted at `001becfc`-`001bed04`
(`sra v1,a1,0xc` / `andi a0,v1,0xf`), i.e. **the message's own header field, not the source address**
(this layer has no notion of a source address — everything arrives on one SN@P connection). So:

- A joiner keepalive tagged `(1<<12)|0` refreshes **only `peer[1]`** on the host. That matches the
  08-26 savestate exactly: `peer[1]` was the entry that timed out on the host, while `peer[0]`
  (self, stamped by WRITE #1) kept advancing. Consistent, Confirmed.
- **Corollary the server must respect:** because the stamp is keyed off the header slot, the relay
  MUST NOT rewrite or re-tag that field. `#relayGameChannel` / `#relayGameBeacon` already forward the
  payload byte-identically, so this holds today — but it is now a load-bearing invariant, not an
  incidental one. Any future "normalise the peer index" idea would break peer liveness.
- Second corollary: liveness is driven purely by delivered messages, so a peer that is relayed
  nothing for 31 s dies **even with a perfectly healthy transport**. At this layer silence is
  indistinguishable from death.

## A2. §6.2 census arithmetic — SUPERSEDED and corrected

**SUPERSEDED:** §6.2's row "`<44-byte / 40-byte / 20-byte>` | ~110 | `id=0x0008` entity records".
**Reason:** that `~110` is a **record** count restricted to the **co-op phase**, printed in a table
whose other two rows are **frame** counts over the **whole capture** — three category errors at once
(frames vs records, co-op vs whole-capture), so the column did not sum to §6.1's 431. The two
keepalive rows were correct.

Corrected census of `ingame2.pcap`, unreliable op-0x0F (`byte0 & 0xf0 == 0x20`); all 431 frames pass
the length-field check (`L + 4 == len`, 431/431):

| | phase 1 (t < 2384) | co-op (t >= 2384) | **total FRAMES** |
|---|---|---|---|
| keepalive `0000` (peer 0) | .248 122, .129 1 | .129 45 | **168** |
| keepalive `0010` (peer 1) | — | .248 51 | **51** |
| **keepalive subtotal** | 123 | 96 | **219** |
| entity/data frames | .248 113 | .248 99 | **212** |
| **TOTAL** | 236 | 195 | **431** — reconciles with §6.1 |

Inside those **212 data frames**: **269 messages** and **273 records**
(phase 1: 160 msgs / 163 recs; co-op: 109 msgs / 110 recs). Frames carrying >1 message and messages
carrying >1 record both occur, which is why the three counts differ. The
frames-vs-messages-vs-records distinction is now explicit and should be stated in any future census.

Two substantive things the corrected census surfaces that the old one hid:

1. **In the co-op phase `.129` (host, peer 0) sent 45 unreliable frames and ALL 45 were keepalives —
   zero entity frames.** All 99 entity frames came from `.248` (joiner, peer 1). Consistent with the
   `+11` owner byte being `1` on every `sub 0x28` record (§5) and with the 08-25 note that the joiner
   saw a zombie the host did not. But it does **not** show that the host ever transmits entity state,
   which the current G13 symptom (enemies move on the host) would require. **Open question A2.1:** if
   the host genuinely never sends `id=0x0008`, relaying alone cannot animate the host's enemies on
   the joiner, and §7 item 2 (the game-side dispatcher / ownership rule) becomes mandatory rather
   than optional. Grade: **Observation**, this capture only — do not generalise from one run.
2. The 219 keepalives are ~1/s per console across the active windows, matching `FUN_001be9c0`'s
   `1.0 < now - lastSend` gate. Consistent.

Neither correction changes the §8 verdict or the recommended experiment. A1 promotes the keepalive
half of the fix from "assumed" to Confirmed; A2 is hygiene plus one new open question.

### Added verification step for the rig test

On the `SNAP_GAME_BEACON_RELAY=1` run, in the same pcap pass also count **entity frames by source**
(unreliable bodies that are not `0000`/`0010`). If the host contributes 0 of them while its enemies
visibly move, that is the decisive observation that enemy animation on the host is locally simulated
and NOT replicated outward — which would redirect the fix from the relay to the ownership rule.
Worth capturing on the same run rather than a later one.

## A3 — CORRECTION from run 1 (2026-08-26, main session + nora MET review): IP↔console mapping; A2.1 RESOLVED for run 1

**SUPERSEDES the role labels used in §6/§A2.1 wherever they assumed .129 = emulator/host.**
Hardware ground truth (ARP MAC OUIs on the live rig): .129 = 00-13-15 (SONY) = the REAL
PS2; .248 = 4c-cc-6a (MSI, the PC's NIC) = the PCSX2 emulator. Confirmed by three wire
legs on the run-1 capture (captures/v2-live/g13-run1.pcap): .248/test123 ran the
create-prepare (room creator), keepalive nibble (0<<12)|0 and record owner byte 0; .129/
"real" ran room-enter, nibble (1<<12)|0, owner byte 1. So run 1: emulator = HOST = peer0,
real PS2 = JOINER = peer1.

**A2.1's question is answered for run 1: the HOST DOES transmit entity records** — 30
host entity frames vs 1 from the joiner. The enemies were HOST-owned; the joiner
previously received none of them (the frozen-enemy symptom) and with
`SNAP_GAME_BEACON_RELAY=1` received them all (32 counted forwarded; the 2-frame surplus
vs 30 observed inbound = Pi-side inbound capture loss, not surplus) and the owner
confirmed enemies move and attack on the joiner's screen. The §A2.1 co-op-phase
observation (that capture's host sending zero entity frames) remains as recorded for
ingame2.pcap — that capture's own role labels need the same per-capture nibble check
before reuse (its sessions switched peer indices mid-capture per §A1b).

Run-1 quality legs (nora-measured): Pi relay latency for entity frames p50 1.31 ms;
outbound unreliable stream strictly monotonic per recipient (0 non-increasing steps).
Open follow-ups unchanged: reverse-direction (joiner-owned) replication (n=1 this run);
the >31 s reliable-silence peer-vanish control (max gap this run 16.4 s — condition not
achieved); client-side acceptance of relayed unreliable frames (Pi-side pcap only).
