# ROOM WATCHDOG RE — why a healthy in-room session self-closes at ~72 s / ~145 s

**Question answered:** what periodic server traffic does the PAL client expect while sitting
in a lobby room, and what exactly arms/resets the watchdog that makes it send a voluntary
reliable op-0x02 while the transport is perfect and every op-0x40 keepalive is answered.

**Answer in one line:** it is **not** a heartbeat watchdog and **not** a TCP watchdog — it is
the SN@P **application-liveness watchdog** in the lobby overlay (`cRam006febde` /
`sRam006febe0` / `cRam006febdf` / `sRam006febe2`, armed at session-establish by
`FUN_005bdc70`, ticked every frame by `FUN_005c7d40`, and reset by **one function,
`FUN_005c7d00`, which every inbound lobby-overlay application message calls**). It gives the
server **1800 ticks (~72.8 s measured) of application silence**, then emits the op-0x14 probe,
then **another 1800 ticks**, then declares the connection lost → error event 2 → screen 6 →
`snap_close` → **the op-0x02 we see**. Total budget from the last application message:
**~145.7 s**. `op-0x40` keepalives do not touch it — they are handled in the main-EE
transport and never reach the overlay.

Evidence classes: **O**bservation (decompile / wire / code read), **I**nference,
**H**ypothesis, **C**onclusion. Evidence rank: wire > decompile > corpus notes.
Nothing here changed any server code.

Sources: `reverse-engineering/network/sources/overlays/overlay-3dat-decompile/*.c`,
`reverse-engineering/network/sources/executables/transport-decompile.txt`,
`captures/v2-live/T37-20260808-090328.pcap`, `captures/v2-live/RS1-20260808-172534.pcap`,
`references/bioserver/.../bioserv2/bioserver/HeartBeatThread.java`,
`docs/design/v2-port/BIOSERVER-CONTRACT.md`, `server-v2/src/udp/snap-lobby-session.js`.

---

## 1. The machine

### 1.1 State

| global | width | role | set by |
|---|---|---|---|
| `cRam006febde` | u8 | watchdog ENABLED | `FUN_005bdc70` (session establish) → 1; `FUN_005bb440` (session reset) → 0; give-up → 0 |
| `sRam006febe0` | s16 | idle counter (ticks until probe) | reloaded from `sRam00368490` by `FUN_005c7d00` and by `FUN_005bdc70` |
| `cRam006febdf` | u8 | a probe is outstanding | `FUN_005c7ca0` → 1; `FUN_005c7d00` → 0 |
| `sRam006febe2` | s16 | probe-response deadline | loaded from `sRam00368492` by `FUN_005c7ca0` |
| `sRam00368490` | u16 | idle budget, **server-supplied**, default **0x708 = 1800** | `FUN_001c4450` (op-0x1a session-params reply) |
| `sRam00368492` | u16 | response budget, **server-supplied**, default **0x708 = 1800** | `FUN_001c4450` |

**O** — `FUN_005bdc70` (`overlay-3dat-decompile/FUN_005bdc70.c:20-27`), the SN@P
session-establish success handler (reached from `FUN_005bc990` and `FUN_005bcee0`), arms it:

```c
if ((sRam00368490 != 0) && (sRam00368492 != 0)) {
  sRam006febe0 = sRam00368490;
  uRam006febde = 1;
  uRam006febdf = 0;
}
```

**O** — `FUN_001c4450` (`transport-decompile.txt:2668-2691`) is the op-0x1a session-parameter
receiver. When the reply byte `+6` is `0xFF` (absent/error) it installs **defaults**:
`0x368484=0x14, 0x368486=300, 0x368488=300, 0x36848a=0x1518, 0x36848c=0x708,
0x36848e=0x708, 0x368490=0x708, 0x368492=0x708`; otherwise all eight are read from the
server's reply. **So the server can lengthen or shorten this watchdog** — 0x368490/0x368492
are the 7th and 8th u16 of that block.

### 1.2 The tick — every frame, on every screen

**O** — `FUN_005acab0` (the top lobby screen dispatcher, called once per frame) calls
`FUN_005be330(uRam0035a6f4)` **before** any screen gate. `FUN_005be330` runs whenever
`iRam006ca950 != 0` (SN@P subsystem up) and its **first** substantive call is
`FUN_005c7d40()` — the watchdog tick — whose non-zero return short-circuits the rest of the
frame's session work (`FUN_005be330.c:13-17`).

**O** — `FUN_005c7d40` (`FUN_005c7d40.c`), verbatim:

```c
if (cRam006febde != '\0') {
  if (cRam006febdf == '\0') {                 // no probe outstanding
    sRam006febe0 = sRam006febe0 + -1;
    if (sRam006febe0 < 0) FUN_005c7ca0();     // -> send the op-0x14 probe
  } else {                                     // probe outstanding
    sRam006febe2 = sRam006febe2 + -1;
    if (sRam006febe2 < 0) {
      cRam006febde = 0;
      FUN_005c7e30(0xb);                      // "connection" error text -> 0x6fc5e8
      FUN_005bdf90(2,0);                      // event 2 = connection lost
      return 1;
    }
  }
}
```

Because it hangs off `FUN_005acab0`, this watchdog runs on **Area Select, the lobby floor,
the room-list, the create screens and inside a room alike** — it is a session-scope timer,
not a room screen timer.

### 1.3 The probe

**O** — `FUN_005c7ca0` (`FUN_005c7ca0.c`):

```c
if (cRam006febde != '\0') {
  auStack_4[0] = 1;
  uRam006febdf = 1;
  uRam006febe2 = uRam00368492;
  func_0x001dfda0(uRam006febac, 0, auStack_4, 1, 0x5c7d20);
}
```

`FUN_001dfda0` (`transport-decompile.txt:16727-16780`) sends **opcode 0x14** with
`who = param_2 | 0x2000` (= `0x2000`, UNRELIABLE), a **1-byte body `01`**, sequence
`conn+0x621`, and installs the completion callback at **handler slot 0x28**
(`FUN_001d4d24(1, 0x28, 0x5c7d20)` → `conn+0x548 + 0x28*4 = conn+0x5e8`).

**O** — the client's own dispatcher `FUN_001d9f78` routes `idx = (cmd & 0x7f) - 3`; **case
0x11 (= inbound cmd 0x14)** is the only case that calls `conn+0x5e8`. So the reply the client
has parked on is **an inbound op-0x14**, not an op-0x28.

**O (wire)** — this datagram is unmistakable in both captures: `fl=0x20 op=0x14 sub=0x0
len=17 total=21 body=01`. It is a *different* message from the 84-byte
`fl=0x20/0x60 op=0x14 len=80 body=00 55 55 …` burst (that one is `FUN_005bcc30`'s 8-shot
RCNT1 bandwidth measurement, callback `0x5bce80`). **Correction: `snap-lobby-session.js:2372-2378`
labels the 17-byte message "FUN_005bcc30 bandwidth probe … no reply is known to be expected".
Both halves of that annotation are wrong** — it is `FUN_005c7ca0`'s liveness probe and a reply
IS expected (slot 0x28). Mark SUPERSEDED per the corpus methodology.

### 1.4 The reset — the single most important fact

**O** — `FUN_005c7d00` (`FUN_005c7d00.c`), 28 bytes, the whole function:

```c
uRam006febdf = 0;                 // clears "probe outstanding"
uRam006febe0 = uRam00368490;      // reloads the idle budget
```

**O** — its 26 callers, all of them inbound-message / reply handlers in the lobby overlay
(enumerated from the dump's CALLEES lines):

```
005bb4d0 005bb670 005bb8e0 005bb980 005bba20 005bc430 005bc590 005bc790
005bf740 005bf830 005bfb40 005bfe90 005c0060 005c05c0 005c0ae0 005c1220
005c13e0 005c19d0 005c21c0 005c2460 005c29c0 005c3370 005c39e0 005c3a40
005c3cf0 005c3da0
```

Named ones: `005bba20` = the op-0x10 game-channel sub-event dispatcher; `005bc590` = the
op-0x0F chat parser; `005bc430` = the member/charstats update receiver; `005c0060` = the
op-0x09 count reply; `005c0ae0` = the op-0x0a member-list reply; `005c19d0` = the op-0x49
room-list reply; `005bfb40`/`005bfe90` = enter/leave completions; `005c3a40` = the op-0x04
create reply; `005c05c0` = the create-enter reply.

**C — therefore: ANY inbound SN@P application message that reaches the lobby overlay fully
re-arms the watchdog** (it clears the outstanding-probe flag *and* reloads the idle counter —
so an application message also cancels an already-outstanding probe; the server does not
strictly have to answer op-0x14 at all).

**C — and the op-0x40 keepalive does NOT.** op-0x40 is consumed by the main-EE transport
(`FUN_001d9b6c`, whose first instruction feeds the *other*, 840 watchdog at `conn+0x51c`) and
never enters the overlay. This is exactly why "keepalives 53/53, unacknowledged 0" coexists
with a self-close.

### 1.5 From expiry to the op-0x02 on the wire

**O** — `FUN_005bdf90(2, 0)` dispatches through the event table at `0x6ca8a0` index 2 — the
same "connection error" event the transport error handler `FUN_005bcfd0` uses. Downstream
(all decompile-confirmed): `FUN_005f6970(reason)` sets `uRam006c4b90 = 6` (screen 6) and
`cRam006c4ba0 = reason`; screen 6 runs `FUN_005f6aa0 → FUN_005f6b00 / FUN_005f6d20 →
FUN_005f7270` (a 900-frame disconnect wait), which calls `FUN_005be690` / `FUN_005be700` →
`func_0x001dbe60` = `snap_close` → `FUN_001dbd0c`, which emits a **zero-length reliable
opcode-0x02 with `who = 0xb000`**.

Observed on the wire as `fl=0xb0 op=0x02 sub=0x0 len=16 total=20` — byte-for-byte the close
we have been chasing. The owner's "connection error" popups at those timestamps
(RS1-B §3, 17:41) are the same event's UI.

### 1.6 The state diagram

```
                (session establish: FUN_005bdc70)
                        arm: febde=1, febdf=0, febe0=0x368490 (1800)
                                   |
                                   v
   +----------------------> [ IDLE ]  febe0-- each frame
   |                             |
   |   any inbound overlay       | febe0 < 0
   |   app message               v
   |   (FUN_005c7d00:        FUN_005c7ca0():
   |    febdf=0,             send op-0x14, who=0x2000 (unreliable), body 01,
   |    febe0=0x368490)      seq=conn+0x621, completion slot 0x28 (conn+0x5e8)
   |                         febdf=1, febe2=0x368492 (1800)
   |                             |
   +---------------------- [ PROBE OUTSTANDING ]  febe2-- each frame
   ^                             |
   |                             | febe2 < 0
   |                             v
   |                        febde=0; FUN_005c7e30(0xb); FUN_005bdf90(2,0)
   |                             |
   |                             v
   |                     event 2 "connection lost"
   |                             v
   |                  FUN_005f6970(r): 0x6c4b90 = 6   (screen 6)
   |                             v
   |             FUN_005f6aa0 -> FUN_005f6b00/6d20 -> FUN_005f7270
   |                             v
   |             FUN_005be690/700 -> snap_close (001dbe60 -> 001dbd0c)
   |                             v
   +--(never)             ***  op-0x02, reliable, zero-length, who 0xb000  ***
                                v
                     TCP reconnect + full D904 sign-in
```

---

## 2. The arithmetic — all five data points fit one constant pair

**O (wire, re-parsed from the pcaps for this doc)** — the 17-byte op-0x14 probe → op-0x02
interval, per console per session:

| capture | console | probe | op-0x02 | Δ |
|---|---|---|---|---|
| T37 | .248 emu | 07:08:56.368 | 07:10:09.206 | **72.838** |
| T37 | .129 PS2 | 07:10:10.834 | 07:11:23.674 | **72.840** |
| T37 | .248 emu | 07:16:34.226 | 07:17:47.064 | **72.838** |
| RS1 | .248 host s2 | 17:37:35.612 | 17:38:12.030 | **36.418** |
| RS1 | .129 PS2 | 17:39:09.318 | 17:40:22.161 | **72.843** |
| RS1 | .248 host s3 | 17:40:13.528 | 17:41:26.367 | **72.839** |
| RS1 | .129 PS2 | 17:42:15.125 | 17:43:27.966 | **72.841** |

Six of seven agree to **±5 ms**; the seventh is **exactly half** (36.418 = 72.836/2 — a 2×
tick rate on that screen, **I**). That is the `0x368492 = 0x708 = 1800`-tick response
deadline: 1800 / 72.84 s ⇒ an effective **~24.7 Hz** game loop (PAL 25 fps; the 1.2 % offset
from a nominal 25.0 Hz is not explained here and is not load-bearing — **I**).

The idle half uses the same constant, so the whole budget is 1800 + 1800 = 3600 ticks ≈
**145.7 s** from the last application message. Reconciling the five reported closes (**C**):

| run | idle window (last app msg → probe) | probe → close | total | matches |
|---|---|---|---|---|
| T37 emulator post-create | 68.8 s | 72.84 | **141.6** | reported +141.6 ✔ |
| RS1 PS2 joiner-starve | 69.76 s (after the op-0a reply at 17:37:59.562) | 72.84 | **142.6** | reported +142.6 ✔ |
| RS1 host s3 | 55.48 s | 72.84 | **128.4** | reported +128.4 ✔ (55.48 + 72.84 = 128.32) |
| RS1 host s2 | 36.10 s | 36.42 | **72.5** | reported +72.5 ✔ (both halves at the 2× tick) |
| 2026-08-09 00:32 host | ~72.8 s (full budget) | ~72.8 | **~145.7** | reported +145 ✔ |

**C — the model is quantitatively complete: every close = (idle budget) + (response budget),
each 1800 ticks, and the observed spread is entirely explained by (a) how long after the last
server application message the timer happened to be, and (b) a 1× vs 2× screen tick rate.
145.7 s is the hard ceiling, and no observed close exceeds it.**

**Live counter-example (O)** — T37 .129 probed at 07:16:49.598 and did **not** close: it
resumed querying, the reply hit a `FUN_005c7d00` caller, and the watchdog re-armed. That is
the mechanism working in the positive direction on real hardware.

**Why answering more UDP moved 72/128 → 145 but did not fix it (C):** answering client
queries resets the watchdog, so the last reset moved later — but nothing *periodic* resets it,
so a client that stops asking questions (because it is parked on a stall) still dies exactly
one full 3600-tick budget later.

---

## 3. What the server must send

### 3.1 The contract

> **Every SN@P lobby session must receive at least one lobby-overlay-routed application
> message every `0x368490` ticks (~72.8 s at default). Recommended cadence: 30 s — the same
> cadence the JP reference server broadcasts `HEARTBEAT 0x6202` at.**

### 3.2 Vehicle A (recommended) — a periodic op-0x10 game-channel push

**O** — `FUN_005bc860` installs the op-0x10 handler `FUN_005bba20` at **slot 0x13**
(`func_0x001d4d24(conn, 0x13, 0x5bba20)`) at **session establish** (callers `FUN_005bd2e0`,
`FUN_005bcfd0`) — not at room entry. So this vehicle is valid for the whole session, on any
screen.

**O** — the client dispatcher's case 0xd (inbound cmd **0x10**) routes to `conn+0x594`
(slot 0x13) when `flags & 0x1000 == 0`, `flags & 0x400 == 0`, `flags & 0x8000 != 0` — i.e.
**`who = 0xA000`**. That is exactly the datagram V2 already sends and the rig already proved
(create sub-5 push, join sub-0x0C push; pcap `17:36:59.517 server→.248 fl=0xa0 op=0x10`).

**O** — `FUN_005bba20`'s **first statement is `FUN_005c7d00()`**, before the sub-selector
switch, and the switch has **no default case** (cases 1..0x11 only). Therefore:

| what to send | effect |
|---|---|
| op-0x10, `who = 0xA000`, body `[BE32 count=1][BE32 roomOrMemberHandle]`, app payload byte (wire+0x18) = **0x00** (or ≥ 0x12) | **watchdog reset, zero other side effects** — a pure application keepalive |
| …app payload byte = **0x0A** | reset **plus** the client TELLs back an op-0x0b carrying its remaining standby ticks `uRam006febec` (`FUN_005bc240` → `FUN_005c5f70`) — a genuine ping/pong; this is the PAL analogue of JP `CONNCHECK 0x6001` |
| …app payload byte = **0x0B**, data at +4 = remaining ticks | reset **plus** sets the in-room countdown `0x6fb748 = ticks/30` — this is the **"Left: N min" STANDBY display** (`FUN_005bc270`) |
| …app payload byte = **0x0F** | reset **plus** sets `0x6ff2b2 = 3`, re-arming the member-side join give-up SM (§4) |

Recommendation (**I**, high confidence): use **payload byte 0x00** for the pure keepalive
(no UI coupling, no state coupling, fail-safe if a sub-selector is later reassigned), and send
0x0B separately when a room actually has a standby countdown to publish.

Cadence: **30 s**, i.e. ~2.4× margin inside 72.8 s, matching `HeartBeatThread.java:53-55`.
Audience: every open `SnapLobbySession` (this is a session-scope timer, so it must go to
lobby-floor clients too, not only room members).

### 3.3 Vehicle B (the exact mechanism) — answer the op-0x14 probe

Reply with an **op-0x14** message so the dispatcher's case 0x11 fires the callback the client
installed at slot 0x28 (`FUN_005c7d20`). Body: the obvious candidate is the same 1-byte
`01` echoed back (the dispatcher performs no decode for this case and hands the raw payload
plus a status byte that defaults to 0).

**This is a Hypothesis until `FUN_005c7d20` is decompiled** — it is **not in any dump**
(the overlay index jumps `0x005c7d00 size=28` → `0x005c7d40`, so `0x005c7d20` is a 32-byte
function nobody has read). It very likely clears `006febdf` and/or calls `FUN_005c7d00`
(**I**), but "very likely" is not a licence to ship a reply into a parked callback. Vehicle A
needs no unknown format and subsumes vehicle B (a `FUN_005c7d00` call cancels an outstanding
probe anyway).

### 3.4 Optional, and strictly better than a heartbeat — lengthen the budget

**O** — `sRam00368490` / `sRam00368492` are the 7th and 8th u16 of the op-0x1a session-params
block (`FUN_001c4450`). A server that answers op-0x1a with larger values raises the watchdog
budget directly. **Not recommended as the fix** — it is a bigger blast radius (the same block
carries `0x368484..0x36848e`, two of which `FUN_005bdc70` clamps to 250 and copies to
`0x7006ac`/`0x7006a8`), and the periodic push in §3.2 is what the reference server does. Record
it as the knob that exists.

### 3.5 What will NOT work (**C**)

- **More op-0x40 keepalives / a faster keepalive.** Wrong watchdog. op-0x40 feeds
  `conn+0x51c` (the 840 watchdog) in the main-EE transport and never reaches the overlay.
- **Anything on TCP 10127.** No step of the traced chain touches TCP. The v2 TCP service has
  no periodic sends (`grep setInterval server-v2/src/tcp` → none) and the JP reference's
  `CONNCHECK` is the *server's* liveness check of the client (the server removes a client that
  does not TELL) — it is not a stimulus the client times out on. The "TCP going quiet" theory
  is **rejected**: the mechanism above accounts for all five closes to within 1 s, on two
  consoles, across two captures. (Caveat, **I** not **C**: the client's TCP/D904 path has not
  been swept for its own timer; the claim proved here is that the observed closes need no such
  timer to be explained.)
- **JP `HEARTBEAT 0x6202` / `CONNCHECK 0x6001` verbatim.** Those are JP-transport commands;
  the PAL client never sends or expects the `0x6xxx` lobby commands on this path (RS1 TCP
  inventory: the create/rules dialogue is not on TCP at all). What ports across is the JP
  server's *behaviour* — a 30 s unsolicited broadcast to every connected client — carried on
  the PAL vehicle in §3.2.

### 3.6 Reconciliation with `BIOSERVER-CONTRACT.md`

| JP contract (§2 keepalives) | PAL equivalent | status |
|---|---|---|
| `HEARTBEAT 0x6202` BROADCAST every 30 s, **no answer expected** | *any* lobby-overlay application push, e.g. op-0x10 `who=0xA000` payload-byte 0x00, every 30 s | **MISSING in v2 — this is the bug** |
| `CONNCHECK 0x6001` QUERY every 60 s, client must TELL | server→client op-0x10 payload-byte 0x0A → client TELLs op-0x0b with `006febec` | not implemented (optional) |
| (implicit) the client's own check that the server is alive | **op-0x14 probe → slot 0x28** — the subject of this doc | v2 explicitly ignores it |
| slot livetime / `SLOTTIMER 0x6409` remaining secs | host-side `iRam006febec` (§4) + op-0x10 payload-byte 0x0B → `0x6fb748` "Left: N min" | not implemented |

The JP server never had to answer a client probe because its 30 s HEARTBEAT meant the client's
idle counter never reached zero. **v2 sends no application traffic at all once a client stops
asking questions, so the probe always fires and nothing ever answers it.** That is a direct
regression against the reference contract, not a PAL-specific mystery.

---

## 4. Two neighbouring in-room timers found on the way (not the op-0x02 cause)

Both live in the same per-frame `FUN_005be330`, both gated on the config-unlock byte
`cRam006ff2b1 != 0`, and split by the host flag `cRam006ff2b0`. Recorded because they are the
"Left: N min" STANDBY machinery the question asked about, and because the server drives both.

**4.1 Host branch (`cRam006ff2b0 != 0`) — the wait-limit / auto-start timer.** `iRam006febec`
decrements per frame; the display value is `iRam006febec / 30`. On expiry (and
`cRam006ff2b1 != 3`): `FUN_005c4f00()` gates on `bRam006ce5cf`; on 0 it sets
`cRam006ff2b1 = 3` and then, reading the room's member count at `0x6cfa2c + idx*0x144`:
**< 2 players → `FUN_005c7e30(7)` + `FUN_005bdf90(0xb,0)`** (abort/notice), **≥ 2 players →
`FUN_005bdf90(1,0)`** — i.e. **the wait-limit expiry is a game-start trigger**, matching JP
`SLOTTIMER 0x6409` returning 0 firing `broadcastGetReady` (BIOSERVER-CONTRACT §7.1). Reload:
`iRam006febec = iRam006febf0` while `cRam007006a6 != 0` and count `< bRam007006a4`;
`iRam006febf0` is seeded from a table at `DAT_00640530` (or `idx * 300`). **O** for the code,
**I** for the JP mapping. The client also answers op-0x10 payload-byte 0x0A with this value,
so the server can read the client's remaining standby time.

**4.2 Member branch (`cRam006ff2b0 == 0`) — the join-wait give-up SM.** `iRam006febf4` +
state `cRam006ff2b2`:

```
create/enter reply FUN_005c05c0 (success):  febf4 = 0x96 (150 ticks ~6 s), 6ff2b1 = 1, 6ff2b2 = 1
  2b2 == 1 -> 2b2 = 2; febf4 = 0x708; FUN_005c6150()  -> op-0x10 who 0xA000 payload byte 0x0E
  2b2 == 2 -> 2b2 = 0; FUN_005c7e30(0xc); FUN_005bdf90(0xb,0)   (give up)
  2b2 == 3 -> 2b2 = 1; febf4 = 0x708                             (re-armed)
in-room op-0x10 payload byte 0x0F (FUN_005bc350) -> 6ff2b2 = 3   (the server's re-arm)
```

**O.** This confirms FACTS' "0x0E = a separate 6 s-fallback escalation query" — it is exactly
6 s (150 ticks) after the enter/create reply. Its give-up fires event **0x0b**, not event 2,
so it is a softer path than §1.5 and is *not* what produced the observed op-0x02 (no op-0x10
payload-0x0E was seen on the wire in either capture — **O**). Server action if this ever
bites: push op-0x10 payload byte **0x0F** to members.

---

## 5. Corrections this trace forces on the corpus / code

1. **`server-v2/src/udp/snap-lobby-session.js:2372-2378` (`#onRttProbe`)** — the note
   "FUN_005bcc30 bandwidth probe; absorbed, no reply is known to be expected" is **SUPERSEDED**
   on both counts for the 17-byte form: the sender is `FUN_005c7ca0`, and a reply IS expected
   (completion slot 0x28 = `conn+0x5e8`, invoked by inbound cmd 0x14). The 84-byte
   `0x55`-filled form *is* `FUN_005bcc30` (callback `0x5bce80`) — two different messages share
   opcode 0x14 and must not be conflated.
2. **`SERVER-V2-SURFACE.md` §1.2** — the `0x14 RTT_PROBE / none / "68 bytes of 0x55, absorbed
   at debug"` row is incomplete for the same reason; the operationally important form is
   17 bytes with body `01`.
3. **`RS1-B-JOIN-STARVE.md` §7 item 4** ("decompile of the op-0x02 sender's arming site — what
   starts the ~142 s give-up timer") is **answered by this document**; the "~142 s application
   give-up timer" is `0x368490 + 0x368492` ticks of application silence, not a per-screen
   dialog timer.
4. **`snap-lobby-session.js:157-171`** (`DEFAULT_IDLE_TIMEOUT_MS` docstring) cites "its app
   request watchdog is 3600 frames (about 72 s PAL)". The 3600-frame counter it refers to
   (`uRam006c5500`, armed by `FUN_005b68e0`, ticked by `FUN_005b6900`, expiry →
   `FUN_005f6970(4)`) is a **real but different** watchdog — a per-screen-state request
   watchdog re-armed only on an SM state *entry* — and it too ends at screen 6 / `snap_close`.
   It was not the cause of the observed closes (those are quantitatively the 1800+1800 pair),
   but it is a second reason a parked client dies and the server cannot heartbeat it away:
   **only an SM state advance re-arms it.** Both should be recorded; do not merge them.
5. The **server's 120 s `DEFAULT_IDLE_TIMEOUT_MS`** is shorter than the client's 145.7 s
   budget. Harmless today (the client dies first), but if §3.2 lands, a silent client would be
   released by the server at 120 s while its own watchdog still had 25 s to run — worth a
   look once the keepalive exists (**I**).

---

## 6. Needs fresh Ghidra decompile (prioritized)

| # | address | why it matters |
|---|---|---|
| 1 | **`FUN_005c7d20`** (0x005c7d20, ~32 bytes, absent from every dump) | the op-0x14 completion callback — decides whether vehicle B (§3.3) is safe and what body the reply needs |
| 2 | `FUN_005be690` / `FUN_005be700` reason mapping + the `0x6ca8a0` event table entries 1, 2, 7, 0x0b | confirms event 2 → screen 6 → `snap_close` end-to-end and tells us what events 7/0x0b actually show |
| 3 | `FUN_005bcce0` (bandwidth-probe result consumer) | closes out the 84-byte op-0x14 burst — is a missing bandwidth reply harmful on its own? |
| 4 | writers of `bRam006ce5cf`, `cRam007006a6`, `bRam007006a4`, `iRam006febf0`, table `DAT_00640530` | the host wait-limit/auto-start parameters — needed before implementing STANDBY properly (§4.1) |
| 5 | `FUN_001c43c0` / `FUN_001c4450` call site chain (which SN@P phase sends op-0x1a, and whether v2 ever reaches it) | decides whether §3.4's knob is reachable at all in the PAL/v2 flow |
| 6 | dispatcher `FUN_001d9f78` case 0x10 → case 0x11 fallthrough | as decompiled, an inbound cmd 0x13 also reaches slot 0x28; confirm whether that is a real fallthrough or a decompiler artifact before sending anything at 0x13 |

---

## 7. Highest-leverage next experiment

**Change (one flag, server-side, no client/ISO change):** add
`SNAP_APP_KEEPALIVE` to `SnapLobbySession` — a timing-wheel timer, **period 30 000 ms**, per
open session, that sends **op-0x10, `who = 0xA000`, body `[BE32 1][BE32 handle-or-0]` + app
payload byte `0x00`** through the same reliable path as the rig-proven sub-0x0C push. Reuse
`buildRoomLimitsPayload`'s framing; the only delta is the payload byte. Default OFF; turn ON
for the run.

**Predictions (falsifiable):**
1. With the flag ON, a console left idle in a created room emits **no 17-byte op-0x14 probe at
   all** (the idle counter never reaches 0) and **no op-0x02** for as long as the test runs
   (≥ 10 min). With the flag OFF the probe reappears at ≤ 72.8 s of silence and the op-0x02
   at probe + 72.84 s.
2. If a probe still appears, the push is not reaching slot 0x13 — check the flags byte on the
   wire is `0xa0` (not `0xb0`: `0x1000` set would route to `conn+0x580`/`0x578` instead).

**How to verify on the rig:**
- **pcap** (the primary): filter UDP 9090; assert zero `op=0x14 len=17` from the console and
  zero client-originated `op=0x02` for the run. Re-use the parser recipe in §2 (16-byte header
  `[flags][innerLen][sub][op][token][seq][ack]`, `flags & 1` = length bit 8).
- **PINE** (the direct read, one sample every ~10 s): `0x006febde` (should stay 1),
  **`0x006febe0` (should saw-tooth back up to 1800 every 30 s — this is the falsifier)**,
  `0x006febdf` (must stay 0), `0x006febe2`, and `0x00368490`/`0x00368492` (record the actual
  budget in use — this is also the first direct confirmation that the defaults 0x708/0x708 are
  what is live).
- **Pi journal:** the new send event once per 30 s per session; `lobby-rtt-probe` should stop
  appearing entirely.

**Why this one first:** it is the smallest server-side change that removes an *entire class* of
"the console gave up while we were debugging something else" — every stall investigation
currently has a 145.7 s shot clock, which is why B1/B2/B3 all end with "and then it closed".
Removing the clock does not fix a single stall, but it makes every subsequent stall
observable for as long as we want to look at it.

---

*Written 2026-08-09. No server code, no existing knowledge-base facts were modified; the
corrections in §5 are recorded here for a follow-up SUPERSEDED annotation at the cited lines.*
