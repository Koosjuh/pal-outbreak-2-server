# SESSION LOG — 2026-08-26 (evening) — G13: enemy movement sync

Goal: G13 — enemies load on both consoles but move only on the host; frozen on the joiner.
Player position sync works (peer[1] active, accumulator advancing), so this is the
enemy/object-state layer. One goal, per CLAUDE.md.

## T1 — Grounding (done)
- Read GOALS.md (G13 entry), FACTS.md CURRENT MODEL, SESSION-CLOSEOFF-2026-08-26.md,
  analysis/ingame-peer-vanish-RE-2026-08-26.md, analysis/ingame-receive-stack-RE-2026-08-25.md.
- rig-doctor: HEALTHY (PCSX2 up, PINE ok, no zombies, screen 0x6c4b90=0xc).
- Ghidra MCP bridge live at 127.0.0.1:8080 with the main-EE SLES program open
  (verified decompile_function + xrefs_to end-to-end).

## T2 — Evidence preservation + wire anchors (done, commit 5274cd6a)
- The 08-25/26 in-game pcaps (ingame2/rig4/char.pcap) lived only in the PRIOR session's
  temp scratchpad — copied into captures/v2-live/ (gitignored but durable on disk).
- Extracted real game-packet payloads from ingame2.pcap → analysis/g13-wire-samples-2026-08-26.txt.
  Observations (need decompile confirmation):
  - Payload after the SN@P wrapper = a STREAM of length-framed messages, u16 LE header
    = (slot << 12) | body_len.
  - Host .129 sends ONLY slot-0 messages with body id 0x0001 (its player state, 0x24 bytes).
  - Joiner .248 sends its slot-1/id-0x0002 player message (370, all relayed by the Pi)
    PLUS slot-0 frames carrying id-0x0008 records (per-object marker 09 80 00 NN 03 —
    object/enemy/event candidates) AND an apparent byte-identical re-emit of the host's
    id-0x0001 message.
  - Body shape: u16 id, 0x04, len byte, u32 incrementing counter, payload.

## T3 — snap-re deep trace SPAWNED (running)
Brief: trace the 0x351fe0 consumer + net-SM handlers (PTR_LAB_00248370[0..7], state byte
0x3540a6, in-game=5) via the live Ghidra bridge; decode the message body format against the
wire samples; resolve the host/joiner send asymmetry (Q3); decide the enemy model
(host-authoritative vs deterministic-seed vs gated sim) and the server action (Q5).
Deliverable: analysis/g13-enemy-sync-RE-2026-08-26.md.

## T4 — Cross-check sources wired in (owner directive)
- openSNAP (references/external_repos/openSNAP): protocol/commands.py names the SDK callback
  layer — op-0x0F &8000 = kk/amkkGamePacketRudpCallBack, op-0x10 = kkGamePacketTargetRudpCallBack,
  0x11 = SEND_GAME_PACKET_TO_GAME_SERVER. Confirms our anchors sit on the SN@P SDK's generic
  game-packet channel; the (slot<<12)|len stream is Outbreak's OWN engine layer above it
  (openSNAP won't describe it). (Observation from the vendored source.)
- Network corpus (reverse-engineering/network/): covers the transport boundary functions
  (FUN_001caXXX ring/queue, FUN_001d4d24 slot install) — snap-re told to cite corpus records
  for the boundary instead of re-deriving, live decompile wins on conflict.

## T5 — snap-re verdict (analysis/g13-enemy-sync-RE-2026-08-26.md, commit dfafa921)
The game runs TWO transport classes on op-0x0F: reliable (wire 0xA0, relayed by
SNAP_GAME_RELAY) and UNRELIABLE (wire 0x20) — and the server drops 100% of the unreliable
class (#onGameChannel routes it to #onGameBeacon; both experiment flags default OFF).
The dropped class carries: (a) the 1 Hz peer keepalive (idx<<12)|0 — its loss fires the
31 s peer-timeout sweep, answering ingame-peer-vanish's open question as (a) timeout with
NO re-activation path (active=1 written only at init, FUN_001bdc10); (b) id-0x0008 entity
records (type 0x02, len 0x12–0x2a, 16.16 fixed-point coords, owner-peer byte) — the
enemy/entity-state candidates, owner-replicated over local simulation (Likely).
Also: Q3 asymmetry RESOLVED as an artefact (ingame2.pcap contains two sessions; .248 was
peer 0 then peer 1 — the "joiner re-emits host msg" observation in g13-wire-samples was a
session mix; top-4-bits = sender's own peer index stands Confirmed). No RNG seed in this
layer — not lockstep.

## T6 — Independent verification (this session, Observation)
- Code: snap-lobby-session.js:1970 confirmed — all unreliable op-0f → #onGameBeacon,
  consumed with flags OFF. Relay seam length-safe: decode strips low-10 length bits from
  flags (snap-udp-register-codec.js:182), #requireSendableFlags enforces clear, encode
  restamps.
- Wire (tshark, all three captures): unreliable op-0f from consoles 431 (ingame2) /
  364 (char) / 86 (rig4); forwarded by Pi = 0 / 0 / 0 in every capture.

## T7 — Local test (commit dfafa921), suite green
New test in server-v2/test/snap-lobby-game-beacon.test.js: a REAL 68-byte entity-record
frame (byte-for-byte from ingame2.pcap) relays byte-identically room-scoped with
SNAP_GAME_BEACON_RELAY=1 and is consumed with it OFF. Full suite 838 pass / 0 fail.
Fix candidate = flip the EXISTING flag on the Pi (no code change). nora review in flight.

## T8 — nora verdict: GROUNDED-WITH-CAVEATS (2026-08-26)
Claim chain reproduced independently (code + wire + the DEPLOYED-build journal:
RIG2-20260824-free.journal.log has 3215 lobby-game-beacon lines, all relayed:0 — the
strongest leg). Corrections accepted:
- The 31 s sweep TRIGGER is Inference, not Confirmed — no capture shows a >31 s reliable
  gap (max measured 19.1/22.8 s); the causal link rests on savestate end-state + mechanism.
- One unshown load-bearing step: the peer.lastActivity (+8) WRITE site — must show a
  len-0 keepalive reaches it (snap-re follow-up in flight; blocks the rig ask).
- §6.2 census arithmetic (frames vs records) needs a SUPERSEDED correction (same follow-up).
Hazards: H1 NEW — relayed unreliable frames share the ONE unreliable seq counter with the
op-0x40 keepalive; client high-water filter (`conn+0x10 <= seq`) silently discards a
reordered keepalive → error-840 exposure (low prob / high consequence; watch, pre-agreed
rollback). H2/H3 (relay to a non-in-game room member; peerIdx>=count → net state 7) real
but NOT new — the reliable relay already exercises the same exposure (397 frames to .129
pre-join, survived). H4 none (branches mutually exclusive). H5 room scope survives game
start (game-session.js:115 never touches location). H6 minor (sub/flags echoed verbatim
to a different recipient; all observed frames sub=0). H7/H8 fail-closed + bounded.

## T9 — Pre-flight (nora items), status
1. Pi build verified ✓ — pal-server-v2 active; md5 of snap-lobby-session/sessions,
   reliable-channel, server-config on the Pi == repo exactly (so the seam is wired; no
   RELAY_BEACON_UNWIRED risk). Env today: SNAP_GAME_BEACON_ECHO=0, SNAP_GAME_RELAY=true,
   SNAP_GAME_BEACON_RELAY absent (=false).
2. Safety readouts for the run (PINE, BOTH consoles where reachable — emulator via PINE;
   PS2 via savestate/symptom):
   - net-SM state `0x3540a6` must STAY 5 (7 = terminal death; 0x10/0x15 = error paths)
   - error stash `0x3541f4/f8/fc` stays 0
   - `0x35b720` (peerCount) / `0x35b721` (myIdx) — attribute roles without guessing
   - host peer[1] active `0x3540ec+0x3c` stays 1; lastActivity `+8` keeps advancing
   - watch journal + consoles for error-840 / disconnects (hazard H1)
3. Control for (b): reproduce the SAME cutscene that produced the 2026-08-26 vanish;
   ingame2.pcap is the flag-OFF baseline. peer[1].active staying 1 proves nothing without
   a >31 s reliable-silence window in the run.
4. lastActivity write site: snap-re follow-up IN FLIGHT — REQUIRED before the rig ask.
5. Env change recorded here + runbook updated (v2-server.md SNAP_GAME_BEACON_RELAY entry
   rewritten with the G13 semantics + H1 + rollback):
   - THE CHANGE: add `SNAP_GAME_BEACON_RELAY=true` to /etc/pal-server-v2/env, then
     `sudo systemctl restart pal-server-v2` — BETWEEN RUNS ONLY (a restart freezes an
     active game).
   - ROLLBACK: remove the line (or =false) + restart. No code change either way.
6. §6.2 census correction: in the same snap-re follow-up.

## Experiment success criteria (pre-framed, per nora)
- (a) PRIMARY (mechanism): pcap Pi→client unreliable op-0x0F (`payload[0]&0xf0==0x20 &&
  payload[3]==0x0f`) goes 0 → ≈ the other console's send count, per recipient; AND the max
  inter-arrival gap of ANY Pi→client op-0x0F collapses from 19–23 s to ~1–2 s.
- (b) peer persistence: host peer[1].active stays 1 ACROSS THE CONTROL CUTSCENE with +8
  advancing (needs item 3's control to mean anything).
- (c) enemies move on the joiner — MAY STILL FAIL even if (a)+(b) pass: the RE doc's own
  §7.2/§8 say the client-side record dispatcher (FUN_001bd840/001bd940/001bf800, zero
  xrefs, runtime pointer table) is untraced. If (a) passes and enemies stay frozen, that
  is an INFORMATIVE result promoting that dispatcher trace to mandatory — NOT a failed
  change, NOT auto-revert. And if only (a)+(b) pass, what closes is the PEER-VANISH
  sub-issue; G13 (enemy movement) is NOT met by that alone.

## T10 — Pre-flight COMPLETE (commit 9eb54715); ready for the owner's rig window
snap-re addendum (§A1/A1b/A2 of the RE doc) closed both blockers:
- lastActivity write site CONFIRMED at disassembly level: the stamp (swc1 @001bede0) is in
  the DELAY SLOT of the len==0 branch → a len-0 keepalive always reaches it; only the
  accumulator append is skipped. Per-SLOT stamp (header nibble) — matches the savestate.
  NEW INVARIANT: the relay must never rewrite/re-tag the slot field (byte-identical today).
- Census corrected (SUPERSEDED note): 431 = 219 keepalives + 212 entity frames.
- NEW open question A2.1 (Observation, one capture): the HOST sent ZERO unreliable entity
  frames in co-op (all 99 from the joiner). If the host never transmits id-0x0008, the
  relay cannot animate host-owned enemies on the joiner → the rig-run pcap pass must count
  entity frames BY SOURCE; host=0 with visibly moving host enemies would redirect the fix
  to the game-side dispatcher/ownership rule (§7.2).
ASK TO OWNER: a between-runs window to set SNAP_GAME_BEACON_RELAY=true + restart
pal-server-v2, then a 2-console run reproducing the 08-26 vanish cutscene, full logging
(pcap emulator-side + Pi journal + PINE sampler readouts from T9 item 2).

## T11 — THE RUN (2026-08-26 ~11:36–11:43 UTC, owner live; flag ON) — (a)+(b) PASS, (c) LARGELY
Setup: SNAP_GAME_BEACON_RELAY=true live on the Pi (echo=0), rotating tcpdump on Pi
(g13-run1.pcap), journal (g13-journal.log), PINE watcher on the emulator (g13-watch.log,
scratchpad). Roles this run: emulator .129 = HOST peer0 (login "real"), PS2 .248 = JOINER
peer1 (test123). Owner could only cancel the cutscene on the PS2, not the emulator (G17
asymmetry persists) — which made the host sit through cutscenes = a faithful vanish-window
control.
- (a) RELAY MECHANISM — PASS (Observation, pcap): unreliable op-0x0F now relays BOTH ways,
  ≈100%: joiner sent 81 → Pi forwarded 83 to host; host sent 70 → Pi forwarded 72 to
  joiner (was 0/0 before the flag). Journal: 159 lobby-game-beacon events, relayed:1
  throughout (one relayed:0 = pre-room).
- (b) PEER PERSISTENCE — PASS (Observation, PINE watcher, whole run): peer[1].active NEVER
  left 1 (zero a=0 samples), lastActivity advanced every tick tracking peer0 within <1 s,
  netState held 5 (no 7/0x10/0x15), error stash 0/0/0 — ACROSS the un-skippable cutscenes.
  The 08-26 vanish did not reproduce with the relay ON.
- H1 hazard: did NOT fire — no error-840, no disconnect, no refusals/WINDOW_FULL/dead in
  the journal.
- A2.1 CONFIRMED LIVE: entity frames by origin = joiner 30, HOST **1**. Yet the owner saw
  enemies on BOTH screens (savestates 6,7) — consistent with per-entity OWNERSHIP: this
  zone's enemies are joiner-owned (+11 owner byte=1) and the relay now delivers them to
  the host (explains the original "host does not see the enemy" symptom half).
- (c) GAMEPLAY (owner): enemies visible on both screens (savestates 6,7); movement "a bit
  janky" (savestate 8); savestate 9 = both chars down; "might need a bit of sharpening but
  it's good". NOT yet claiming G13 MET — jank + the savestate 8/9 states need reading, and
  whether enemies MOVED (not just rendered) on the joiner needs the owner's explicit word.
Evidence: captures/v2-live/{g13-run1.pcap,g13-journal.log}; savestates 6/7/8/9 (emulator);
watcher log preserved to captures/v2-live/g13-watch-run1.log.

## T11a — ⚠ CORRECTION (SUPERSEDES the role/IP labels in T11/T12 and the A2.1 reading)
nora's MET review caught the IP↔console mapping inverted (inherited from the 08-25 docs).
Ground truth, three wire legs + hardware:
- ARP MAC OUIs (Confirmed, this rig, 2026-08-26): .129 = 00-13-15 (SONY) = the REAL PS2;
  .248 = 4c-cc-6a (MSI, this PC's NIC) = the PCSX2 emulator; .121 = b8-27-eb (RasPi).
- Journal: .248/test123 ran `create-prepare` ×2 and hit `game-start` first; .129/"real"
  ran `room-enter` (joined) 110 ms after a single transient `create-prepare` probe —
  so create-prepare ALONE does not discriminate the creator (nora addendum); the
  authoritative legs are the next two. Keepalive slot nibbles: .248 emits (0<<12)|0,
  .129 emits (1<<12)|0. Record owner bytes: .248's 30+ records owner=0; .129's single
  record owner=1. (nora's report text still says ".248 = the real PS2" — that physical
  label is SUPERSEDED by the ARP ground truth above; the peer-index findings agree.)
CORRECTED ROLES: **emulator = .248 = test123 = room creator = peer0 = HOST** (matches the
owner's statement and the PINE watcher myIdx=0); **real PS2 = .129 = "real" = joiner =
peer1**. The CONSOLE-level roles in T11 were right; the IPs under them were swapped.
CORRECTED CONSEQUENCES (these strengthen the result):
- Entity frames by origin = **HOST (emulator) 30, joiner (PS2) 1** → the enemies were
  HOST-OWNED. The joiner previously received ZERO of them (frozen) and now receives all
  (32 counted forwarded) → moves and attacks. **The run exercised EXACTLY G13's stated
  symptom direction.** The T11 "joiner-owned / explains the host-missing-enemy half"
  reading is SUPERSEDED. Untested follow-up: the reverse direction (joiner-owned enemies
  animating on the host; n=1 frame this run).
- The watcher (on the emulator = the HOST = peer0): p0 = self, **p1 = the REMOTE joiner**
  — the load-bearing peer for the vanish; it held active=1 all run, as headlined.
- "30 sent → 32 forwarded, zero loss" corrected: 32 > 30 = INBOUND CAPTURE loss (~8
  inbound frames missed Pi-side), not surplus. Honest form: 0 of the OBSERVED inbound
  frames were dropped by the relay.
- (b) DOWNGRADED from PASS: the un-skippable cutscenes produced a max reliable-silence
  gap of only 16.4 s (nora-measured) — under the 31 s sweep threshold, so the vanish
  condition never arose this run; "did not reproduce" ≠ "beaten". A real >31 s-silence
  control run remains open (peer-vanish item, not a G13 gate).
- T13 attribution corrected: the 11:51:41 op-0x25 was the EMULATOR's friend/search
  attempt; the REAL PS2's is the 11:53:01 op-0x25 from .129/"real". Both unanswered.
- Earlier docs (08-25 receive-stack / wire-samples / A2.1) that label .129=host for OTHER
  captures: Likely inverted the same way (hardware MACs are stable; DHCP sticky) — each
  needs a per-capture nibble check before reuse, not a blanket rewrite.
- nora's additional evidence legs (recorded): Pi relay latency for entity frames p50
  1.31 ms (the server cannot be the jank); the Pi's outbound unreliable stream is strictly
  monotonic per recipient (0 non-increasing steps) → H1's silent-discard face had no
  wire-level trigger either.

## T12 — Owner answers + flakiness grounded (2026-08-26)
- OWNER (rig): enemies on the joiner DO move and attack — "yes but a bit flakey, but they
  ended up downing my char." The G13 symptom (frozen on the joiner) is GONE.
- Savestate 9 "both chars down" = downed fast by ONE zombie = the G14 difficulty bug
  (EASY selected, very-hard in effect). NOT a sync glitch. Parked to G14.
- Flakiness grounded (Observation, g13-run1.pcap): joiner entity frames are SPARSE —
  mean gap 5.5 s, max 31 s — event-driven corrections over local simulation, not a
  continuous stream. The relay forwarded ALL of them (30 sent → 32 counted forwarded,
  zero loss). So the jank is the CLIENT's own update cadence + ~LAN latency between
  corrections; the server delivers everything the protocol carries. Further smoothing
  would need the client-side record dispatcher semantics (§7.2 family) — beyond server
  scope, and beyond G13's stated symptom.
- Pi log-retention rule executed + memorialized: all captures/journals archived to
  captures/v2-live/ (+pi-archive-20260826/), Pi /tmp wiped, no capture processes left.

## T13 — PARKING LOT (owner, mid-session): friend-list wedges the lobby (G6, NOT this goal)
Owner: in the lobby, friend list opens and ADDING a friend works (added the "real"
account), but afterwards the client is stuck — can't return to the lobby, can't delete,
"all the functionality is gone."
Evidence pulled (captures/v2-live/g6-friendlist-stuck-20260826.journal.log, streamed off
the Pi per the no-retention rule): the creator console (.129) sent a 59-byte reliable
**op-0x49** which the server only logs as `observed-message` (NO handler, NO reply) —
**the same seq 4570 retransmitted 21× over 52 s** (11:35:01→11:35:53). Mechanism
(Inference, matches the known completion-stall family): an unanswered reliable op-0x49
holds the client's reliable send slot → every later UI action needs the channel → the
screen wedges. This is exactly G6's known server gap (buddy-lookup op48-NAME +
op49-LOID/STAT keyed on handle, reply slot 0x31 — never implemented). NOTE the captured
burst is from the PRE-run lobby phase (11:35); the client apparently recovered on room
entry (the 11:36 game start worked), consistent with a channel reset on transition. The
owner's described incident may be a second occurrence; the mechanism evidence stands.
→ G6 work, parked. Do not conflate with G13.
ALSO (owner, same sitting): lobby "Find users" search sticks at "Searching." — same

## T14 — ✅ G13 MET (owner stamp, 2026-08-26) — SESSION CLOSED
Owner answered "yes to both" on nora's precise MET questions: (1) enemies moved and
attacked on the REAL PS2's (joiner's) screen this run; (2) the owner was playing/watching
the real PS2 when the character was downed. All nora §7 pre-stamp items were completed
first (roles corrected T11a, (b) downgraded, arithmetic fixed, tracked env
deploy/pal-server-v2.env.conf, GOALS promotion). Golden recorded:
`g13-enemy-sync-2026-08-26` (GOLDENS.md, tag golden-g13-enemy-sync-2026-08-26) — the
FIRST v2 golden. Follow-ups recorded in GOALS.md G13 (flaky cadence = client-side;
reverse-direction; >31 s vanish control) — none re-open G13.
NEXT SESSION (fresh, per one-goal rule): G14 — difficulty override (EASY selected, very
hard in effect; one zombie downed both players this run). Also queued: G6 friend/find
(op-0x25 40 B + op-0x49 59 B unanswered — T13 evidence archived), G15 end-screen char,
G16 joiner member list, G17 cutscene-skip asymmetry.
unanswered-lobby-query family (G6/G7: user-search/player-list server gap).
OWNER CORRECTION: the wedge incident above happened on the REAL PS2 (the 11:35 op-0x49
burst was the emulator's own attempt). Fresh journal pull
(g6-ps2-friendlist-20260826.journal.log) pins BOTH consoles' incidents (Observation):
- 11:51:41 PS2 (test123) sends reliable **op-0x25, 40 bytes** → server:
  "no handler for this opcode in the post-selection phase" → never answered → stuck.
- 11:53:01 emulator ("real") sends the same op-0x25, 40 bytes → same no-handler.
So the friend/find-users surface rides (at least) op-0x25 (40 B, un-RE'd, NEW opcode for
the corpus) + op-0x49 (59 B, the known buddy-lookup vehicle). Unanswered reliable query →
wedged reliable slot → the screen loses all functionality. G6 next-session starter:
decode the op-0x25/op-0x49 bodies from these journal lines + captures, map to bioserver
BUDDYLIST/USERSEARCH handlers, implement replies. Parked — not G13.
