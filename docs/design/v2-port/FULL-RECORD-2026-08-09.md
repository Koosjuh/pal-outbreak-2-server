# FULL RECORD — the 2026-08-08 → 09 session: everything done, tested, and captured

Written on owner instruction after "stop everything." No spin; failures included.
Branch: `feat/v2-bioserver-port` (all commits listed exist there). Everything below is
from this one session (2026-08-08 morning → 2026-08-09 ~04:30).

---

## 1. What was BUILT (41 commits, `db60236b..c6a91f53`)

**Grounding (6 docs, commit `fce42190`)** — 5 parallel agents + synthesis:
- `BIOSERVER-CONTRACT.md` — the complete JP bioserv2 application contract, including the
  full game-start sequence (GETREADY→0x6911..0x6916→gameserver relay→AGL) and the
  create dialogue (CREATESLOT→SCENESELECT→SLOTNAME→SETRULE→0x6504).
- `SERVER-V2-SURFACE.md` — every handled SN@P opcode, the presence/room state model,
  the do-not-destabilize list.
- `B1-GAME-START-MODEL.md` / `B2-JOIN-FREEZE-EVIDENCE.md` / `B3-LEAVE-TWICE-EVIDENCE.md`
  — evidence bases for the three blockers.
- `PORT-PLAN.md` — the campaign driver: port bioserver logic as a transport-agnostic
  engine, wire to SN@P milestone-first.

**Engine port (`d735fcad`)** — bioserver Slot/Client/RuleSet/getReady state machines as
`server-v2/src/state/{player-profile,room-lifecycle,slot-allocator,rule-set,game-session}.js`,
status lifecycle byte-matched to `Slot.java` (FREE/INCREATE/GAMESET/BUSY), join guards in
PacketHandler order, playernum host=1/joiners 2–4.

**Transport & wire slices** (each individually committed and flag-gated):
- `cb94a8fe` + `069d297a` — reliable sub-messages of walked aggregates are DELIVERED
  (never gap-buffered) + the rig-proven per-rider acks restored.
- `2ab67e87`/`a9970c18`/`11678032`/`3df40e4d` — generalized broadcast, the join ladder
  (allocator guards + rig-proven sub-0x0C confirm + member fan-out), op-0x10
  recipient relay, room→BUSY on the op-0x0D start barrier.
- `c7bf0f4c`/`f8ae342c` — in-game beacon rerouting + flag-gated echo experiment.
- `db0a7f1e`/`e3bc6cf5` — B3 leave fixes (op-0x02 close mirror; +0xc send-seq echo).
- `4f92d809`/`2dfe44a7`/`3e9f2f31` — nora pre-deploy fixes (V1 room-ENTER discriminant,
  profile-less join refusal, flag documentation).
- `4710b0f2`/`57a2c7c7`/`42e52072` — TCP create-config dialogue (later shown wire-inert
  on PAL — see §5), option-label zero records, lobby-button replies per the reference.
- `90fa7c9d`/`d45c1190`/`e776944a`/`2a00c62d`/`6fb36812`/`c48944e7` + hardening
  (`6b373398`..`a8a9db0e`) — the RS1 fix round: op-0x0F routed by the client's own
  0x0400 discriminator, chat carries the 0x0400 string bit, room-event relay rewritten
  (word1 = sender's handle), op-0x0a answered with V1's count-0 body, V1's member-info
  supply channel restored (sel-0x0a roster + op-10 sub-1 answers), count re-push.
- `8bcb7b80` — **SNAP_APP_KEEPALIVE**: the 30 s op-0x10 sub-0x00 push that feeds the
  client's application-liveness watchdog.

## 2. What was TESTED (local)

- Test suite grew **644 → 806 tests, 0 failures at every deploy point** (now 806/799/0/7).
- Every behavioural change carries a **break-the-fix proof** (test shown to fail with the
  fix reverted) — recorded per commit in the workflow outputs.
- Byte-exact regression fixtures replay REAL captured datagrams (T37 create batch,
  op-49 rider aggregate, RS1 chat frames) — not reconstructions.
- **Three nora reviews** (pre-deploy, corpus round, fix round): all GROUNDED-WITH-CAVEATS,
  zero blocking; every caveat either fixed same-night or recorded below.

## 3. What was CAPTURED

- `captures/v2-live/RS1-20260808-172534.pcap` (798 KB, both consoles, the owner's rig
  session) + Pi journal windows for every run (journald persistent).
- T37 pcap re-analyzed (the beacon and join windows, byte level).
- PINE reads: `bRam006ce5cf`/`cRam007006a5` = 0 on Area Select (first-ever, R2);
  watchdog counters `0x6febde/df/e0` sampled every 10 s for 19 min (`samples.csv`,
  66 samples); session budgets `0x368490/92` = 1800/1800 live; wait-table
  `DAT_00640530` = {5400,9000,18000,27000,54000} ticks = **{3,5,10,15,30} minutes**,
  byte-matching JP `RuleSet.getWaitTime()`.
- Screenshots: s01–s15 (sign-in→create→survival→death), `rules-screen-precreate.png`
  (the red rules), survival start/end. Scratchpad + referenced in the session log.
- Owner savestates mapped: slots 1–5, 7 (RIG-SESSION-1.md results section).

## 4. What was VERIFIED on hardware

**Owner-confirmed (RS1 rig session):**
- B3 leave/re-enter works repeatedly ("I can return now whenever") — after months broken.
- Lobby count correct for the first time (2 with both consoles in).
- Area/server select, create, all still working (no regressions).

**Emulator-verified by me (journal + PINE + screenshots):**
- Full connect→lobby→create path clean on every deployed build (zero handler faults).
- **The ~145 s room-death is FIXED**: the client's own watchdog counter saw-tooths back
  up at every 30 s push, 15+ cycles, panic flag never set, zero probes, zero
  app-watchdog closes — where every prior session died at ~145 s. Bonus: post-session,
  the watchdog ran its documented death sequence to the second (probe +72.8 s, give-up
  +145.7 s), validating the RE arithmetic end-to-end.
- The member-info answer channel fires (the starvation that killed both consoles'
  rooms in RS1 is gone from the wire: `unacknowledged:0`, everything answered).

## 5. What was ROOT-CAUSED (with the evidence class)

| Failure | Root cause | Status |
|---|---|---|
| Join starve ("Getting information…") | op-0x0a declared count=1 with no member data behind it; V1 answered count-0 + supplied a member-info channel | Fixed, needs 2-console verify |
| Host death during join | Same application-silence class — its own room broadcasts acked but never answered; NOT caused by the joiner | Fixed (answer channel), survival now gated by design timers |
| Chat never renders | Relay omitted the 0x0400 string-routing bit; client silently discards | Fixed, needs 2-console verify |
| Rooms die at ~145 s | SN@P app-liveness watchdog (`0x6febe0`, 1800+1800 ticks); only application messages reset it; server never initiated any | **Fixed + runtime-validated** |
| Solo room ends at 5:00 | The game's own host wait-limit (<2 players at expiry = designed abort); timer host-local, seeded from served scenario byte[1] bits 0–2 → {3,5,10,15,30} min table; bits 7|6 = player-selectable | Mechanism closed; fix = same served-data surface as rules |
| Count display stuck | Client latches ONE op-0x09 answer; JP re-broadcast on every enter/exit | Fixed (`SNAP_COUNT_PUSH`, deployed OFF pending 2-console) |
| In-room Exit stall | A third op-0x07 variant (flags 0xA010, seq 0) whose completion doesn't release the client; post-leave "parked" clients die 144.8 s later to the per-screen request watchdog | Isolated, not fixed — savestate-7 PINE read is the discriminator |
| Rules/cast/scenario locked | CLIENT-LOCAL computation over the served area/scenario records — the client sends NOTHING on that screen (wire-proven). Owner ground truth: all-cast + all-but-one scenarios + Free-fully-open was the original behavior → all three are server-side served-byte bugs | **RE was mid-write when stopped** — agent reported "I have the full chain"; resumable |

## 6. What I got WRONG (so nobody re-walks these)

1. "Rules are red because V2 doesn't answer the TCP create dialogue" — **refuted by my
   own wire inventory**: all 186 TCP queries were answered; the create screen rides UDP.
2. "The client pumps unanswered messages on the rules screen" — **refuted**: it sends
   nothing there; the gate is client-local.
3. The beacon echo experiment — **falsified**: one echo made the solo start die faster
   (1 beacon vs 115). Correctly turned back OFF.
4. Slice-1a dropped the per-rider acks on an Inference — nora caught it; restored.
5. `SNAP_WAIT_LIMIT` as a push — **stopped before implementation**: the decompile shows
   sub-0x0B sets only the display; the real timer is host-local, rules-seeded.
6. Early framing of the RS1 results as partial wins without seeing that the create
   screen — the thing asked for days ago — was still broken. The cost of 1–5 was borne
   by the owner's rig time and patience.

## 7. DEPLOYED state right now (Pi 192.0.2.121)

- Build: `feat/v2-bioserver-port` through `8bcb7b80` (code), md5-verified per file at
  each of the three deploys; ports bound; service active.
- Flags ON: `SNAP_JOIN_LADDER`, `SNAP_OP10_RELAY`, `SNAP_MEMBER_INFO`,
  `SNAP_OP0A_COUNT0`, `SNAP_APP_KEEPALIVE`, `SNAP_CREATE_CONFIG`, `SNAP_LOBBY_BUTTONS`.
- Flags OFF: `SNAP_OPTION_LABELS`, `SNAP_COUNT_PUSH`, `SNAP_GAME_BEACON_ECHO/RELAY`,
  `SNAP_EXIT_CLOSE_MIRROR`*, `SNAP_COMPLETION_SEQ_ECHO`* (*ON in env from the first
  deploy — B3 confirmed fixed with them on).
- Rollbacks: Pi `src-backup-*` dirs (3 generations) + every change individually
  committed + flags. Runbook lists every flag with default and rollback.

## 8. OPEN — ranked exactly as the owner ranked them

1. **Create screen: rules, cast, scenario selectable** — the ONE thing. The RE agent
   had "the full chain" when stopped; resume it, write the served-byte fix, deploy,
   screenshot Free Area. Wait-time settability rides the same fix (byte[1] bits 7|6).
2. Post-leave/Exit park death (144.8 s) — savestate-7 PINE read set is written and
   pending (RS1-C §C3).
3. Two-console verification of join + chat + counts (10 minutes, no time pressure now
   that rooms survive).
4. Game start beyond the barrier (the in-game handler decompile: `conn+0x590/0x598`
   pointers during the loading screen — B1's remaining unknown).
5. Buttons/labels content (blocked on: no known source for the real label bytes;
   `SELECTION-DATA-MODEL.md` cited by the handoff does not exist in git — needs owner).

## 9. Where everything lives

- Code+docs: branch `feat/v2-bioserver-port` (41 commits, every one message-documented).
- Evidence docs: `docs/design/v2-port/` (PORT-PLAN, RS1-A/B/C, RS1-TCP-INVENTORY,
  ROOM-WATCHDOG-RE, BIOSERVER-CONTRACT, this file).
- Session log: `docs/findings/protocol/SESSION-LOG-2026-08-08.md` (live-appended all night).
- Owner's results: `docs/design/v2-port/RIG-SESSION-1.md`.
- Captures/samples/screenshots: `captures/v2-live/` + the session scratchpad.
