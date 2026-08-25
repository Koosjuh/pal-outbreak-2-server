# SESSION LOG 2026-08-24 — openSNAP deep-research + openSNAP-informed server fixes

Session goal (owner-directed): deep research on openSNAP (kept as reference) + apply the answers
openSNAP already provides to our open server errors. Pi is OFFLINE (ping 100% loss, owner shutdown
2026-08-09) — local-only session: research, fixes, local test validation; deploys queued.

## T1 — C3 exit-stall: channel-bit mismatch on the completion reply (wire-decoded)

Context: FULL-RECORD §5 "In-room Exit stall" — third op-0x07 class (flags 0xA010, seq 0), answered
sel-7, client acks but never releases; C3 left two hypotheses (echo-key mismatch vs wrong
completion class).

**Observation (RS1-20260808-172534.pcap, frames 5185–5191, tshark udp.payload):**

```
5185 .248→Pi  a818 0008 02f807d0 000000aa 81000000 "STAT@\0\0\0"   ← Exit press, msg 1
              a010 0007 02f807d0 00000000 94000000                 ← rider: LEAVE, zero body, seq 0
5186 Pi→.248  6010 0000 … ack=000000aa      (bare ack for STAT seq 0xaa)
5187 Pi→.248  6010 0000 … ack=00000000      (bare ack for LEAVE seq 0)
5188 Pi→.248  b020 0028 seq=0x98  body: 00000008 00000000 "STAT"…  ← sel-8 completion, flags 0xB020
5189 Pi→.248  b020 0028 seq=0x99  body: 00000007 00000000 …        ← sel-7 completion, flags 0xB020
5190/5191 .248→Pi transport-acks 0x98,0x99  → then nothing but op40/41 keepalives (the park)
```

**openSNAP flag model** (OPENSNAP-CROSSREF-2026-08-24.md §2, from SLUS_206.42): 0x2000=ROOM,
0x1000=LOBBY; lobby context = BOTH bits (0x3000/0xB0xx), room context = 0x2000 only (0xA0xx).
**AM client callback table** (openSNAP commands.py, from jpt_kkCommand/kkSetCallBackFunction):
result-wrapper sub 0x07 → `ResultLeaveRoomCallBack` when cmd type `<> &1000`,
`ResultLeaveLobbyCallBack` when `&1000`. Same &1000 split for sub 0x06 (join) and 0x05 (delete).

**Inference (strong):** the Exit press is a ROOM-channel leave (0xA010, 0x1000 clear). Our sel-7
completion goes out 0xB020 (0x1000 SET = lobby context) → the client dispatches the LOBBY-leave
result path, not the room-leave one → the stored room-leave continuation never fires → client
parks → the 144.8 s per-screen request watchdog kills it. Consistent cross-check: the WORKING
lobby-level leave (B3) requests with 0xB010 (lobby context) and the same 0xB0-flagged reply
completes fine — the reply class only mismatches for in-room Exit.

**Fix shape (to implement, flag-gated):** completion replies (op-0x28) must ECHO the request's
channel bits (0x3000 mask) — reply 0xA020 to 0xA0xx requests, 0xB020 to 0xB0xx requests. Likely
also applies to the sel-8 STAT completion (5188) and to room-context op06/op10 emissions (candidate
mechanism for the create-self op06 12/13 rejection — pending the server-scan report).

Status: Observation (wire) + Inference (mechanism via AM callback table). PAL decompile
corroboration wanted: the SLES_533.19 result-dispatch reading the 0x1000 bit. Local falsifier:
byte-exact test replaying frame 5185 asserting reply flags 0xA020; rig falsifier when Pi returns.

## T2 — contrast: working lobby-leave vs stalling room-leave (same pcap)

**Observation (RS1 pcap rows 4630-4634):** working lobby-leave `b010 0107` seq 0x19 → bare ack
(ack=0x19) → completion `b020 0128` body `00000007 00000000 00000000 19000000` (pkt-echo 0x01,
+0xc echo 0x19 LE) → client immediately proceeds (next op48 at 4634). The stalling room-leave got
the SAME reply shape (pkt-echo 0x00, +0xc echo 0x00 — both correct for its seq-0 request).

**The only wire deltas in the stalling case:** (1) request channel bits 0xA0 (room) vs 0xB0
(lobby), reply 0xB020 in BOTH cases; (2) the room-leave arrived as an embedded MULTI child
(seq 0) inside the 0xA818 STAT datagram, and we emitted a SEPARATE bare ACK (ack=0) for it —
openSNAP deep-dive fact 10 marks exactly that as the anti-pattern (outer reliable owns the
bundle's only transport ACK; embedded children have legal seq 0 + garbage ack words).

Two candidate mechanisms, possibly cooperating: (H1) completion must echo the request's channel
bits (reply 0xA020); (H2) never bare-ACK an embedded multi-child — ack the outer seq only.
snap-re PAL-dispatch trace in flight to arbitrate H1; H2 is testable purely from openSNAP's
transport model + a byte-exact local fixture.

## T3 — H1 CONFIRMED by decompile; fix implemented + tested (commit pending verify)

**snap-re verdict (analysis/op28-channel-bit-dispatch-2026-08-24.md): CONFIRMED.**
`FUN_001d9f78` case 6 routes the sel-7 completion by the RECEIVED frame's 0x1000 bit:
set → slot 0x23 (lobby-leave cb), clear → slot 0x24 (room-leave cb). Same split for sub
0x05/0x06/0x09/0x0a; none for sub 4 (create) / sub 8 (STAT). Downstream, the mis-fired
lobby cb writes the LOBBY tag so the pending-table scan (`FUN_005be120`, keyed pktid+tag)
never matches the ROOM slot → `cRam006cbb6d` never sets → `FUN_005c1c80` parks in state 1.
Exit is a TWO-leave SM (room 0xA010 → wait → lobby 0xB010): after a correct fix the client
sends a SECOND op-0x07 with 0xB010 — the unambiguous pcap success signal.
Senders are a matched pair: `FUN_001dd07c` lobby-leave (0xb000, ctr conn+0x61a, slot 0x23) /
`FUN_001dd1dc` room-leave (0xa000, ctr conn+0x61b, slot 0x24) — also explains the rider's
seq-0 (separate room-channel counter), which retro-validates v2's rider non-windowing.

**Implemented:** `SNAP_CHANNEL_BIT_ECHO` (v2, default OFF) — completions echo the request's
DATA bit; sel-7/sel-8 + byte-neutral uniformity on enter/room-query/reentry. v2's join
ladder already had the sel-6 room-enter class right (explicit FLAG_SET, slot 0x22). Tests:
byte-exact C3 replay (flag OFF pins the RS1-shipped bytes; ON asserts 0xA020/0xA018),
break-the-fix 2-fail/4-pass, suite 810/0. ALSO fixed (v1): the :1004 addr16 copy-range bug
(corrupted token on every create-self op06 retransmit).

**Rig-free falsifier (pending):** PINE fingerprint of wrong-slot dispatch at the park —
`0x6ce5cf==0 && 0x6ce5d0!=0 && 0x6cbb68==1 && 0x6cbb6d==0` (the mis-fired lobby cb zeroes
the lobby level handle via FUN_005bf130(1) while the room handle stays). Owner savestate
slot 7 IS the park state → local emulator read decides, no Pi required.

**openSNAP answers NOT acted on (with reasons):**
- Create-self op06: openSNAP/AM never self-member-adds (roster = 0x0A pull) — but our
  create-self push is rig-proven load-bearing on PAL; AM-specific divergence, keep ours.
- Rider bare-ACKs (H2): with H1 confirmed as the park mechanism and the seq-0 explained by
  the room-channel counter, no change; stays a watch-item on the next pcap.
- Chat 0xA400/0xB400 + duplicate policy + window semantics: v2 already matches openSNAP
  (independent convergence — deployed, awaiting the 2-console run).
- Bootstrap 0x40 SWAN Blowfish: PAL diverges (op40 = keepalive w/ SNAP-SWAN-keyed body);
  both projects independently landed the same key. No change.

**Corpus correction (per methodology):** archive doc `lobby-back-exitarea-RE-2026-07-03.md`
§5 mis-read the completion consumer's param as the app BODY; it is the 0x10-byte stack
HEADER struct (+0x00 = 0x27/0x28 cmd marker, +0x0c = pktid, NOT body status/match-id).
Banner added; superseded by analysis/op28-channel-bit-dispatch-2026-08-24.md.

## T4 — runtime corroboration from the slot-7 savestate FILE (no rig needed)

Read the owner's exit-stall savestate (sstates/...07.p2s, saved 2026-08-08 19:45) directly:
p2s = zip(zstd), eeMemory.bin = the full 32MB EE image; screenshot embedded.

**Observation (EE bytes at the park):**
- `0x6ce5cf = 0` and `0x6ce5d0 = 2` — EXACTLY the wrong-slot-dispatch signature snap-re
  predicted (the mis-fired LOBBY-leave cb `FUN_005bf130(1)` zeroes the lobby level handle;
  the room handle survives). The discriminating pair: 2/2.
- `0x6cbc7c = 0x43` — the latched completion tag. This is the "armed tag 0x43" from the
  months-old deep-stall note (GOALS.md G2 caveat), now explained: it is the tag written by
  whichever completion callback ran, and the pending-table scan needs tag+pktid to match.
- Screenshot + `0x6c4b90 = 4`: parked ON the room screen ("1/ 0P", wait-timer at 4:48,
  empty room box) — the owner's "pressed Exit, couldn't leave".
- **Prediction refuted (recorded honestly):** `FUN_005c1c80` is IDLE here (0x6cbb68/6c/4c
  all 0), not parked in state 1 — on screen 4 the exit is driven by the screen-4 sub-SM,
  not the lobby back-out SM. The completion-routing mechanism (H1) is unaffected; the SM
  that consumes the released continuation differs by screen.

Verdict: H1 (channel-bit completion routing) = **Confirmed** (decompile) + **runtime-
corroborated** (savestate fingerprint). Remaining to full MET: rig run with
`SNAP_CHANNEL_BIT_ECHO=1` when the Pi returns — success signal = the client's SECOND
op-0x07 (0xB010) right after Exit, then a clean return to the lobby.

## T5 — slot-7 pending table read: tag literals OBSERVED; per-channel counters runtime-confirmed

**Observation (slot-7 eeMemory, direct p2s read):** pending table `0x6ca960` entry[0] armed
with **+0x1c tag = 0x0070, +0x1e pktid = 0x0000**; the latched completion tag `0x6cbc7c` =
**0x43**. 0x70 != 0x43 → the tag mismatch that parks the client is directly visible in memory.
Closes snap-re's ranked unknown #4 without Ghidra: room/create-family tag = 0x70 (matches the
long-standing "0x70 STAT guard"/CREATESLOT create=0x70 notes), lobby-family tag = 0x43 (matches
the historic "armed tag 0x43" — which was actually the LATCHED tag). FUN_005c2080(1)→0x43 /
(2)→0x70 is the constrained mapping (Likely; the two observed values, argument mapping inferred).
**Also:** `conn+0x61a = 11` (lobby-channel reliable counter) vs `conn+0x61b = 1` (room-channel) —
runtime-confirms the per-channel counter pair and exactly explains the room-leave's seq 0
(first-ever room-channel send in that session).

## T6 — Pi back online; queued build DEPLOYED (2026-08-24 ~22:07 CEST)

Pi reachable again (owner). Deployed the 6-file delta 8bcb7b80→HEAD to /opt/pal-server-v2
(backup src-backup-20260824-2206; per-file md5 verified; node --check clean): 63f7acaa rules/
area-table fix (journal confirms `area-table-selected version OBAREA-V5`) + SNAP_CHANNEL_BIT_ECHO
code (flag NOT set in env = OFF, byte-identical; flip after the nora verdict). pal-server-v2
ACTIVE, all 5 listeners bound (tcp10127/http/dnas/dns/udp9090@192.168.2.121). V1 pal-server
remains stopped (port 9090 conflict by design).

## T7 — nora pre-deploy review: GROUNDED-WITH-CAVEATS; all caveats actioned

Nora independently re-verified every Confirmed claim (pcap bytes exact, FUN_001d9f78 re-read,
AM slot indices #23/#24 = the SAME 0x23/0x24 PAL uses — stronger than logged; v1 dual-class
reply confirmed at :2072; suite 810/0 reproduced). Verdict GROUNDED-WITH-CAVEATS. Actions:
1. **Echo SCOPED TO SEL-7 ONLY** (caveat 1): room-query/re-entry/STAT also arrive DATA-clear
   (~17-27 replies/session would have flipped); their dispatch is single-slot but their
   callbacks' channel-bit reads are UNREAD (FUN_005b52e0, sub-8/sub-0x0d consumers). Widen
   only with that evidence or a dedicated rig run. Tests updated (sel-8 stays 0xB020).
2. Flag registered in CONFIGURATION_KEYS.optional + v2 runbook (caveat 3 — rollback visibility).
3. v1 :1085/:1115 addr16 range bugs fixed (caveat 4 — same class as :1004; SNAP_ROOM_ENGINE
   paths). 4. T4/FACTS evidence reweighted (see FACTS entry): decisive = the 0x43-latch/pktid-0
   attribution + armed 0x70 pending slot; handle pair demoted to consistent-with; observed
   cb 0x00601420 noted. 5. Analysis-doc stride/"+0x20 in-use" contradiction corrected.
Nora's watch-items logged: the un-observed Vacant-slot CREATE op-0x06 form (caveat 2, DATA bit
unknown — the in-code "always DATA set" comment now carries that qualifier implicitly via the
sel-7 scoping); **sub-0x0a IS channel-split (case 9 → 0x5ac/0x5a8) and v2's roster push sends
DATA-SET 0xB1xx where v1 deliberately used 0xA0 "→ slot 0x18" — a live roster-visibility lead.**

## T8 — pcap sweep (openSNAP lens): the wrong-class bug is SYSTEMIC + 6 more gaps

Sweep of RS1/T35/T37 (22,261 messages, 0 parse errors) → `PCAP-OPENSNAP-GAPS-2026-08-24.md`:
- **F1 (Observation): EVERY room-channel (0xA000) request class gets a lobby-context (0xB000)
  reply** — op-0x0c (x15/x30), op-0x0a member-list, op-0x09 USER/MAXI room counts, op-0x0d
  start-barrier, plus the known 07/08. One mechanism now plausibly covers count-stuck, roster
  starve ("Getting information"), and the B1 game-start stall. WIDENING PLAN (post sel-7 rig
  proof): channel-echo op-0a and op-09 direct replies (both channel-split in the dispatcher)
  first, then 0x0c/0x0d completions after their consumers are read.
- F3: eight unanswered SEND_ECHO (0x14) probes in T37's game-start window — openSNAP: reflect
  the payload (ResultEchoPacketCallBack). Tiny isolated B1 candidate.
- F2: the ~120 "Unknown" short op-0x0F frames = the non-reliable game-channel SEND (in-game
  beacon 0x2012); openSNAP relays byte-identical to OTHERS, never the sender — explains why the
  RS1-A echo experiment made things worse.
- F4: op-0x0c = CHANGE_USER_PROPERTY (our "ROOM_QUERY" label is a misnomer; body near-empty).
- F5: op-0x09 request/reply layout named (handle+tag / +u32 value) — values were right, class wrong.
- F6: the client piggybacks ACKs (op-0x10 sub-1 arrives 0xE000) — licenses server piggyback
  after a PAL check. F7: ack census clean — delivery is SOLVED; remaining failures = reply
  semantics, not transport.

## T9 — savestate atlas (20 states swept) + deploy with SNAP_CHANNEL_BIT_ECHO ON

Atlas: `SAVESTATE-ATLAS-2026-08-24.md`. Headlines:
- **Rules-red CLOSED at the byte level (Observation):** slot-2 held rule blocks `b0 81 00…00`
  for all areas == byte-identical to OBAREA-V3's serialize (in-process confirmed). Decode:
  changeable-bit b6 clear → red; group row counts zero; all-zero savedata bitmap → "(null)"
  scenario; `0x6ff2b1=0` → title/password red (separate create-handshake layer). Deployed
  OBAREA-V5 serves `f3 e2` + real descriptors — exactly the corrected bytes. To MET: one rig
  look at the create screen. The `0x6ff2b1` unlock ladder observed live: 0→1→3.
- **Callback-slot map extended:** 0x24 = `FUN_005c06c0` (installed only in exit-park states —
  closes snap-re Ghidra-gated #1 as address+context); 0x25 has TWO context-dependent consumers
  (`FUN_005c29c0` roster-STAT / `FUN_005c06b0` exit-STAT); join slot 0x22 = `FUN_005c05c0`;
  state 07 images BOTH 0x23+0x24 installed (the wrong-slot dispatch, photographed).
- **Tags are per-flow FAMILY ids** {0x20,0x21,0x2f,0x43,0x70,0x7b,0x86,0x91}, not a 2-value
  pair. July 07.backup = a second park flavor (no completion at all, latched 0x7b, handle NOT
  zeroed) — the channel-echo rule cures both flavors. 08.backup images the historic 4th-txn jam
  (stale tag 0x21/pktid 3). July 06/10 carry err=0x65 (pool latch).
- **Deployed 2026-08-24 ~22:17 CEST:** sel-7-scoped session.js + config (md5-verified),
  `SNAP_CHANNEL_BIT_ECHO=true` appended to /etc/pal-server-v2/env, service ACTIVE, all 5
  listeners, OBAREA-V5 confirmed in the journal. RIG TEST READY: sign in → Free Area → create
  → the rules screen should show white/selectable rows (V5) → press Exit → the room should
  release (wire signal: client's second op-0x07 `0xB010`; park death gone).

## T10 — RIG RESULTS (owner, 2026-08-24 ~22:30-22:36) + scenario-(null) narrowed to the buffer selector

**Owner-confirmed on the rig (2-console: PS2 .129 "real" + emulator .248 "test123"):**
- **RULES SELECTABLE ✓ and ALL CHARACTERS SELECTABLE ✓** — OBAREA-V5 live. The owner's #1
  item works on real hardware. (GOALS: rules/cast rows of the create screen — rig-confirmed;
  scenario row still "(null)", see below.)
- Chat asymmetric: PS2→emu renders on the emulator; the PS2 renders NOTHING (not even its own
  messages); emu→PS2 not rendered. Journal shows BOTH directions relayed=1 (20:33:04 "real"
  textBytes:5 → relayed:1; 20:33:16 "test123" textBytes:9 → relayed:1) → the emu→PS2 failure is
  delivered-but-not-rendered OR dropped client-side; PS2's missing self-echo contradicts the
  FUN_005C4AF0 local-echo assumption. Wire bytes for this exchange were LOST (the ssh-streamed
  pcap was CRLF-corrupted; replaced with a bounded rotating capture on Pi tmpfs + scp pulls).
  ALSO seen: reliable game-channel op-0x0F frames (0xA000, 42B/22B, bodies 2800…/1400…) from
  the emulator, consumed-not-relayed — the F2/openSNAP model says relay them; candidate for the
  missing emu→PS2 direction if those were chat-adjacent. NEEDS the re-test under the fixed capture.
- PS2 session ended with a clean op-0x02 client-close (answered) at 20:36:28 — no watchdog
  death in this window. Exit-fix verdict: NOT yet tested (owner did not run the in-room Exit).

**Scenario "(null)" — root narrowed (slot-1 savestate, saved 22:33 tonight):**
The served V5 masks LANDED: ring table buffers 0x8d4000 AND 0x8d5780 (via ptr array 0x6c5480)
hold rec0 "Free Area" +0x14=+0x18=0x7ff. Savedata 0x3424e8=0x1e (non-zero), area id 0x6c45f8=1
(correct). Yet ring 0x6c4b96=0xFFFF/count 0 → "(null)". The third buffer 0x8d6f00 is ALL ZERO
and the selector region ~0x6c5498 reads 02 00 01 00 — the ring's FUN_005bac60(0) appears to
have selected the EMPTY buffer while two populated ones sat idle. snap-re tracing the selector
writer + what advances it (analysis/area-table-buffer-selector-2026-08-24.md pending).

## T11 — scenario "(null)" ROOT-CAUSED and FIXED: the mode masks are little-endian

snap-re FALSIFIED T10's buffer-selector premise (FUN_005bac60 takes literal 0; the ring read
the POPULATED bank; bank 2 is dead scratch) and found the real bug: **byte order.** The TCP
0x6204 path is memcpy-verbatim (FUN_001c4d40 → FUN_006188b0 → FUN_005aeb10, NO byteswap —
unlike UDP SN@P) into a little-endian R5900 (proved in-project: slot-1's bank pointers decode
only under LE, matching FUN_00606ea0's `+0x17bb & ~0x3f` arithmetic). Served BE 0x000007FF →
native load 0xFF070000 → zero bits in the ring's tested 0..10 → count 0 → ring 0xFFFF →
func_0x001b6f50(NULL) → sprintf "(null)". Reproduces slot-1 exactly. The masks are the blob's
ONLY multi-byte scalar loads — why rules/cast (byte reads) fixed while scenario stayed dead.
Full trace: analysis/area-table-scenario-mask-LE-2026-08-24.md (incl. corrections: ring-count
falsifier addr = 0x6c50CA not 0x6c4fca; safe blob ceiling = 0x1780 bank size, not the client's
0x2000 guard — single-chunk option labels now refused).

**Fix deployed (~23:00 CEST):** writeUInt32LE at +0x14/+0x18; versions OBAREA-V*→W* (client
caches by version → forces re-download); ceiling 0x1780. Suite 816/809/0; break-the-fix
BE-revert fails 2. Pi active, journal serves `OBAREA-W5`, md5s verified.
**Rig falsifier:** create a room in Free Area → Scenario row shows a NAME (not "(null)"),
left/right walks 11 entries; PINE/savestate: 0x6c4b96 ∈ 1..11, count 0x6c50CA = 11.

## T12 — RIG ROUND 2 (owner, ~23:00-23:20): LE fix CONFIRMED; game STARTED; three new precise failures

**Owner-confirmed working:**
- **SCENARIO SELECTABLE ✓** — the LE mask fix (OBAREA-W5) works on the rig. With rules+cast
  from T10, the create screen is now fully functional for the host: the owner's #1 item.
- **LOBBY chat works** (both ways — savestate slot 2 captured in this state).
- **Create room works; a joiner joined; a GAME STARTED** — first time ever: the host (emulator)
  loaded INTO the game.

**New failures (all on tonight's wire, captures live):**
1. **ROOM chat does not work properly** (lobby chat fine) — scope-specific; analysis in flight.
2. **Joiner sees "Training"** instead of the room's scenario — the joiner-facing room-info
  (op-0x10 sub-1 blob served zeroed / op-0x49 record) never carries the host's chosen scenario;
  id 0 = Training hypothesis. Need: capture the host's scenario choice (op-0x08 attr?) into the
  room registry + echo it to joiners. Analysis in flight.
3. **PS2 joiner stuck at "Game to begin shortly"** while the host plays: journal shows the
  in-game host pumping ~2Hz RELIABLE game-channel op-0x0F frames (flags 0xA000) — **248 events,
  all consumed silently, none relayed**. openSNAP model (deep-dive §3 / F2): reliable game
  packets relay byte-identical to other room members. The joiner is starving on exactly this
  stream (+ possibly the op-0x0D completion class / unanswered 0x14 echoes, F3). Analysis in
  flight → fix spec → flag-gated relay.

## T13 — slot-4 (IN-GAME) memory read: B1's last unknown RESOLVED; the in-game server role
## triangulated (Bioserver + openSNAP + tonight's wire)

**Observation (slot-4 eeMemory, saved 23:21 in-game as host):** the in-game module REPLACES the
callback slot table's game-packet slots with main-EE handlers: slot 0x12=0x001cac70,
0x13=0x001cadb0, 0x14=0x001cad10, 0x15=0x001cadb0 — and **conn+0x590/0x594/0x598/0x59c hold
exactly those four values** (B1-GAME-START-MODEL's remaining unknown = the in-game game-packet
callback set, imaged). The AM/openSNAP callback table names the slots (its #12/#13/#14 = 05DC/
05E0/05E4): **0x12 = GamePacketRUDP (reliable op-0x0F), 0x13 = GamePacketTargetRUDP (op-0x10),
0x14 = GamePacketUDP (unreliable op-0x0F)**. The host's 2Hz reliable op-0x0F pump lands in the
JOINER's slot-0x12 callback — if the server relays it.

**Bioserver gameserver = the full server-side spec** (bioserv2 GameServerPacketHandler.java
processData): `switch(data[0])` — `0x82` GSLOGIN session check; **default: broadcast the raw
bytes to every client with the same gamenumber, EXCLUDING the sender.** No parsing. The JP
in-game server is a pure relay hub. Convergent with openSNAP's game-packet model and with
tonight's starvation. **Also explains RS1-A:** the falsified beacon-ECHO experiment sent the
packet back to the SENDER — the one recipient both references forbid; relay-to-OTHERS was never
tried.

Body framing note: the pump bodies (0x28-len and 0x14-len with matching u16-LE length prefixes)
are consistent with length-prefixed gameserver payloads — the relay must NOT parse them (JP
didn't); capture-side decode only, for diagnostics.

Slots 2/3/4 all new tonight (2 = lobby chat working; 3 = TBD sweep; 4 = in-game). Fix specs
pending from the two wire agents; implementation = flag-gated in-game relay (ack sender,
byte-identical to room members minus sender) + the chat/scenario deltas.

## T13b — slots 2/3: the LE fix's memory falsifier CONFIRMED byte-level

Slot 2 (23:16, in-room) and slot 3 (23:17, screen 5 / 0x6ff2b1=3 ready phase) BOTH show
**ring 0x6c4b96 = 0x8 (real scenario id selected) and count 0x6c50CA = 11** — exactly the
predicted post-fix values (analysis §7). The host's chosen scenario id (8) is in host memory;
the joiner's "Training" = our joiner-facing room-info never carries it (wire spec pending).

## T14 — nora split verdict on the relay slice; SNAP_GAME_RELAY ON, SNAP_ROOM_CHAT_SUB7 HELD

Nora: `SNAP_GAME_RELAY` GROUNDED-WITH-CAVEATS (relay matches the bioserver default-branch;
dedup-relays-once CONFIRMED in the channel; payload-size safe) — may go ON with watches.
`SNAP_ROOM_CHAT_SUB7` **NOT GROUNDED**: sub-7 is Confirmed elsewhere as the rule-DESCRIPTION /
charstats vehicle (0x6fffd1 = desc table; G12-config-unlock-RE-2026-07-17 + B1 §76); the chat
reading was circular (unvalidated function name); flipping it risks corrupting the rule screen
won tonight. Flag stays OFF; DISPUTED banner added to the ROOMCHAT doc (corpus methodology).
In-room chat render path = OPEN again. Actions taken: relay sub byte → 0 (caveat 6, sibling-
shaped, suite 824/817/0); expectations set (relay success = frames reach the joiner; the joiner
entering the game still needs fix #1, real op-0a roster — snap-re Q1-Q4 in flight); watches for
the ungated-recipient case (gamenumber/BUSY gate is the narrowing if trouble) and window-full
refusals. Deferred (recorded): playernum-0 fallback pin, full ON-vs-OFF deepEqual pins, sub-7
NUL-terminator question (moot unless the falsifier revives sub-7 chat).

## T15 — RIG ROUND 3 results + the op-0x10 family trace (the decisive one)

**Owner-confirmed: EXIT RELEASES THE ROOM ✓** — the C3 channel-bit fix works on the rig. The
months-old park-death class is closed (pending only the formal GOALS flip).
Round-3 failures: game did not start (host BLACK SCREEN, PS2 never in); room chat still dead
(expected — sub-7 held); joiner scenario still Training (fix below); NEW: PS2 player renders as
"Jim" regardless of choice (charstats gap, parked). Slots 5/6 = in-room seconds before the
start press (roster count 0x6ff2b3=2 — BOTH members present; accepts 0x6ff2b5=0). Slot 7 now
overwritten (area-select state; fine — its park bug is fixed).

**snap-re op-0x10 family trace (analysis/op10-gamechannel-blobs-RE-2026-08-24.md) — Confirmed:**
1. **Solo-start ROOT (corrects GAME-START-WIRE §2):** not the roster count — the sub-4 accept
   scanner matches the frame's connHandle word against roster memberIds (op-06 +0x10). We stamp
   the RECIPIENT's own session id on relays and serve memberIds 1/2 → never equal → accept never
   marked → 0x6ff2b3=1 at state 8 → solo shortcut, every time. FIX (2-player): per-recipient
   memberId — records about OTHER members carry the recipient's own session handle; self-records
   keep a distinct id; also push existing members' records to a joiner (today it only gets its
   own). N-player needs the ingress-validation Ghidra check (ranked #1 in the trace).
2. **Scenario (corrects ROOMCHAT §2):** the host publishes scenario+rules ONCE, in the CREATE
   body +0x28 optionsWord = the room STAT: scenario = (STAT>>1)&0xFF. Tonight: 020b0a10 → 8 =
   the exact ring value in host memory (T13b). The joiner reads it from the op-0x49 record +0x1c
   (client stores STAT>>1; & 0x8000 = locked; & 0x40000000 = hidden). FIX: capture optionsWord
   into room.flags at create, serve in op-49 +0x1c (SNAP_ROOMFLAGS_PUBLISH is now GROUNDED with
   this exact value). v2 already parses and discards the word.
3. sub-1 is NOT room-info (selector stream: 0=char-ok, 1=mail chunks; our 772-zero push reads as
   "char ok" and clobbers uRam006febe8 — review SNAP_MEMBER_INFO later). sub-4's 780 zeros are
   CORRECT (nothing to fill). sub-7 = charstats chunks (confirms nora's hold). Full per-sub body
   spec + the host start sequence (sub-3→5→6→7×5→8) + the joiner barrier 0x6ff2af documented.
4. Start-visibility: the host's start hides the room via a STAT op-08 SET (|0x40000000) — the
   sel-8 completion class is a hard gate on the roster SM (Ghidra item 3; currently 0xB020).
Black-screen delta vs round 2: unexplained (no savestate of it; candidates: op-0x0D completion
class at the barrier, or in-game load variance). The memberId+STAT fixes change the start path
to non-solo regardless; re-evaluate after them.

## T16 — "Jim" charstats + openSNAP/corpus answer (owner Q: anything in openSNAP or corpus?)

**"Server always sees the PS2 as Jim" = the character charstats gap, already documented.**
G12-identity-vehicle-RE-2026-07-17 §(c)/(d): the character is the 0xf0 charstats blob at member
record +0x18 (charId @+0xc8); the client "displays whatever we echo", and v2 sends a ZEROED
blob → default character (Jim). The blob's server-side transfer vehicle IS the op-0x10 **sub-7
charstats chunks** (corpus `send_op07_charstats` 0x005c5e30: 0x36-byte {slot,len,off,data}
slices of the 0xf0 block, 5/member) — which the HOST emits during the game-start sequence
(FUN_005c6500 state 11). So "Jim" is the SAME root as the solo-start: the host never runs the
non-solo start (sub-5/6/7/8), so charstats never exchange → everyone renders the default. The
memberId/accept fix that unblocks the multi-player start ALSO unblocks character identity.
OPEN sub-question (needs one pcap): where the JOINER first tells the server its character
(create→char-select client→server 0xf0 body) — the server has no confirmed capture of it yet.

**openSNAP:** its whole session/room model keys on **session_id as the member identity**
(rooms.py host_session_id/members:set[int]; handlers.py set_room/leave all by session_id) —
which is exactly the identity the solo-start fix needs (the accept scan matches a session
handle). Confirms the design direction. openSNAP has no charstats (Auto Modellista has no
characters), so the 0xf0 blob is OURS. Its game handler = relay (already adopted). KICS-relogin
clears stale room membership (handlers.py:78) — a robustness pattern worth porting later.

**Corpus:** the charstats path is fully mapped — `get_roster_entry_charstats_6cc128`
(0x005bd7e0), `send_op07_charstats` (0x005c5e30), roster table 0x6cc104/0x700734 stride 0x118,
charId@+0xc8/class@+0xca (the dedup keys that admit distinct members). Everything to serve a
real character exists once we know the joiner's choice.

## T17 — RIG ROUND 4: scenario CONFIRMED; accept-scan bug caught on the wire (the keystone)

Wins: SNAP_ROOM_STAT works (joiner saw the room's scenario, not Training). A full 2-player
game-start handshake RAN (subs 3/4/5, accept blobs f18873/f37422); one console loaded with 2
characters. Roles (wire truth): .248 "test123" = HOST (sent sub-3 start), .129 = JOINER (sub-4).
PCSX2 savestates are EMULATOR-only (.248); the other console's character is WIRE-ONLY.

**Accept-scan bug CONFIRMED ON THE WIRE (f18867-18876):**
```
f18867 .248 sub-3 start   conn=02f807d0 target=2
f18871 .121 relay->.129   conn=028107d0 (recipient)
f18873 .129 sub-4 accept  conn=028107d0 target=028107d0 (joiner accepts as ITSELF)
f18876 .121 relay->.248   conn=02f807d0 (recipient!)
```
Host sub-4 handler FUN_005bbfc0 scans roster memberIds for == the frame conn word (0x02f807d0 =
host's own, because we stamp the RECIPIENT's token on relay); roster holds our minted memberIds
1/2 → never equal → 0x6ff2b5 stays 0 → 0x6ff2b3=1 at state 6/7 → joiner never admitted → its
barrier 0x6ff2af never set → "Stand by" un-pressable, "Game to begin shortly" forever. SINGLE
blocker for joiner-entry + (via the never-run sub-7) character identity ("Jim").

**FIX (2-player):** per-recipient op-06 memberId = the recipient's OWN endpoint token, so R's
scan for a0=own-token matches the joiner's roster slot; self-record distinct; push existing
members to a joiner. memberId endianness vs the conn-word scan (FUN_001d80c8 swaps op-06 +0x10)
= nora/decompile check before flip. N-player = stamp originator's handle on relay (Ghidra
ingress check). Room chat still dead (sub-7=charstats, held; in-room chat render OPEN).


## T18 — nora refuted the mechanism; savestate CONFIRMED the fix anyway (endianness settled)

nora (correctly) refuted the commit's causal story: the accept scan a0 is NOT the relayed wire
token — it is `conn+0x44` (the receiving link's own handle, FUN_001e180c stamps frame+0x30 from
it), and the roster side is an ASCII encode/decode roundtrip (FUN_005c50a0/FUN_005c5120), not a
raw +0x10 byte compare. Open fact: does conn+0x44 == the host endpointToken, and in which order?
DIRECT READ (slots 5/6/8/9, in-room emulator=host): **conn+0x44 = 0x02f807d0 = endpointToken,
NATIVE.** Therefore memberId = recipient.endpointToken written writeUInt32BE → FUN_001d80c8
swaps wire-BE→native 0x02f807d0 → ASCII "02f807d0" → decode 0x02f807d0 == a0 == conn+0x44 →
the joiner's slot matches → 0x6ff2b5[joiner]=1 → count≥2 → non-solo start → barrier 0x6ff2af
set. The fix is GROUNDED (outcome + BE endianness savestate-confirmed); only the docs' reasoning
needed the correction above. No collision: host self-slot memberId = room.handle (small int) ≠
the token; index 0 is pre-set at state 0. FLIPPING SNAP_MEMBER_ID_TOKEN ON.

## T19 — RIG ROUND 5: memberId fix INEFFECTIVE (wrong table); real blocker = the SEATED-slot layer

SNAP_MEMBER_ID_TOKEN ON but the joiner STILL froze (game starts only on host; splash still
"Jim"; member list shows joiners' data but not the joiners). Journal confirms the fix fired
(lobby-join-fanout id=real) — so the code ran and did nothing useful. 07:23 pcap rotated out
(40MB cycle) before capture.

**Why it can't work (corpus rooms.md:7247-7306, Confirmed):** the start roster the accept scan
reads (0x6ff70d ← 0x6ff2bd ← FUN_005c6210) is built from the **4-slot SEATED-player table
0x6c7c2c (stride 0x3b0)**, and the selector-5 room/roster apply "in-room modes 4/0xc REQUIRE the
record name to match a SEATED 0x6c7c2c slot before applying — records for non-seated players
DROP." The memberId I changed (rec+0x10) feeds the DRAWN roster (0x6cdc0a), a DIFFERENT table.
So the joiner is never SEATED in 0x6c7c2c → not in the start roster → not accepted → solo; and
the same non-seating → op-0a member list can't show them. ONE root, two symptoms.

Rolled back SNAP_MEMBER_ID_TOKEN (mechanism refuted by nora, ineffective on the rig — the
honest state). Open question for a proper trace: what SEATS a joiner into 0x6c7c2c (the op-06
add? op-10 sub-1/sub-2? a selector-5 record the server must send?), and what the server must
emit so both the seated-slot table and the start roster include the joiner. This is the true
roster/game-start blocker; the memberId byte was a red herring.

## T20 — RIG ROUND 6: seating + memberId PROVEN WORKING; last gap = host missing from start roster

Savestates 1-4 (emulator = HOST, createdRoom 0x6ff2b0=1; joiner "real" = PS2). NOT the P2P wall.
- Slot 1/2 (in-room): SEAT0 name='real' id="02f807d0" charId=2 — **the joiner is seated in the
  host's 0x6c7c2c with memberId = the HOST's own token**. Both fixes (SNAP_ROSTER_TO_JOINER seat +
  SNAP_MEMBER_ID_TOKEN id) provably landed. 0x6ff2b3=2 (drawn count), 0x6ff2b5=0 (pre-start).
- Slot 4 (screen 5, post-Start): 0x6ff2b5=**01**000000 — the accept scan FIRED AND MATCHED
  (a0=conn+0x44=0x02f807d0 == roster0 id). 0x6ff70d ROSTER0 = 'real' id="02f807d0". BUT
  **0x6ff2b3=1** → solo (needs ≥2). conn+0x44=0x02f807d0, single conn (no per-peer).
- **ROOT (last gap):** the host's start roster (0x6ff70d / seated 0x6c7c2c) contains ONLY the
  joiner. The HOST itself is missing → count=1 not 2 → solo. The host self-seats at create
  (#sendCreateFollowUps op06) but a screen rebuild on the joiner's arrival clears 0x6c7c2c
  (FUN_005aec20 roster clear), leaving only the joiner's fresh seat. Both host+joiner must be in
  0x6c7c2c for count=2.
- **NOT the topology blocker** the seated-slot analysis feared: a0 matched, the accept works over
  a single relay link. The relay CAN do 2-player. Fix = re-seat the host when a joiner arrives so
  0x6c7c2c holds {host, joiner}. Character ("Jim") rides the same non-solo start.

## T21 — difficulty "very hard" = authentic default whose host-override doesn't propagate

Owner: game ran VERY HARD despite setting easy/normal. Not a served-byte bug: OBAREA-W5 serves
the Free Area group-1 difficulty descriptor `01 03 01 01` = {record 1, value 3, present,
changeable} and value 3 = "very hard" (RULES-MASK-RE:209; difficulty choices easy0/normal1/hard2/
veryhard3). This is FAITHFUL to JP bioserver (RuleSet.java:70 `new Rule("difficulty level",1,3)`
- Free Area default = very hard). So the DEFAULT is authentic. The bug: the host's on-screen
change (very-hard -> easy) is not captured into the rules the game starts with -> the game uses
the served default. Same family as "Jim" character not propagating: the host's IN-ROOM
SELECTIONS (character, difficulty/rules) are not reaching game-start. febe4 (STAT src) at the
create screen = the host's packed selections (scenario in low bits); whether the difficulty
sub-choice writes into febe4/STAT or into a separate rule-value store the game-start reads is the
open question. Deferred behind the game-start (hostReseat) verification - it is polish vs the
core "both players load" milestone. To settle: a RULE-screen savestate after the host changes
difficulty, to see if the change is captured in febe4/the rule-value store.

## T22 — hostReseat: joiner reaches "standing by" + relay works (172 relayed=1), but host STILL solo

RIG (07:55:56 start): the joiner (real) room-enter room=0x1, join-confirm, reached "standing by
for game start" (got the host's sub-3). During the 07:55:56-07:58:23 standby window the host
(test123) relayed **172 game-channel op-0x0F packets relayed=1** to the joiner — the SNAP_GAME_RELAY
scope works, the joiner was receiving in-game state. BUT only **1 room-event** from the host in the
whole window — NOT the sub-5/6/7/8 charstats hand-off (~8 msgs) that sets the joiner's barrier
0x6ff2af. So the host went SOLO (0x6ff2b3 < 2) despite hostReseat, pumped state alone, and the
joiner stood by ~147s then presence-detached (watchdog). The 07:59+ relayed=0 pump is AFTER the
joiner left, not the cause.

**hostReseat did NOT reach count=2.** Likely a seating-ORDER/timing bug: the host reseats at slot
0 BEFORE the joiner's op-06, but the joiner's op-06 itself triggers the screen rebuild
(FUN_005aec20) that clears 0x6c7c2c, so the joiner re-seats at slot 0 and the host is lost again
(or host ends at slot 1, wrong order for the state-0 pre-accept). NEEDS the decisive artifact: a
HOST savestate taken within ~5s of pressing Start (before the 147s timeout), to read 0x6c7c2c
(who is seated, which slot), 0x6ff2b3 (count), 0x6ff2b5 (accepts). slot 4 was pre-reseat; slot 5
is in-game garbage; no post-reseat pre-load state exists yet.

## T23 — LIVE PINE (breakthrough): seating SOLVED; joiner REFUSES the start (screen != 4/0xe)

PINE sampler on the host (emulator) caught the game-start live (docs/design/v2-port/
RIG-PINE-2026-08-25/): 08:21:57 screen=4 **count=2**, SEAT0=test123 id=00000001, SEAT1=real
id=02f807d0 — BOTH SEATED with the right ids (hostReseat + memberId WORKED; T15-T22 seating
CLOSED). At Start (08:22:30 screen=5): 0x6ff2b5=**01020000** → host=accepted(1), joiner=**refused
(2)** → count 1 → solo. Root (FUN_005bbf20, Confirmed): the joiner's sub-3 receiver sends sub-4
ACCEPT iff screen 0x6c4b90 ∈ {4,0xe} with 0x6ff2b1==1, ELSE sub-0x10 REFUSE (FUN_005c5c70). The
joiner refused → its screen was NOT 4/0xe when the host's sub-3 arrived. Hypothesis (ties to
"Jim"): the joiner was on the character-select / a non-in-room sub-screen (not readied) when the
host started → refuse, AND charstats never exchanged. Likely a READINESS/sync gap: the host must
not start until the joiner is in-room-ready (screen 4/0xe). NEXT: PC=joiner PINE read to name the
joiner's exact screen at sub-3, deciding server-timing-gate vs joiner-flow.
