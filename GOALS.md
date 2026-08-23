# GOALS.md — goal-oriented roadmap

The north-star list. Every work session picks ONE goal and drives it toward MET.
Grounded in evidence; status reflects what is actually true on the rig, not hopes.

## Session kickoff (paste this to start a per-goal session)
> Start a goal session on **[G# — the goal]** (or: pick the top OPEN goal in `GOALS.md`).
> Ground first: read `GOALS.md` + `FACTS.md` CURRENT MODEL + the goal's entry, and run
> `node tools/rig-doctor.js` (`rig-launch` if it's down). Then work it per `CLAUDE.md` — evidence only,
> no guessing; validate in PINE/journal before the Pi; `snap-re` for deep decompile, `james` for tooling.
> **Commit EVERY change with why/what so we can always roll back — never change→regress→stuck.**
> When you think it's met, run `nora` to verify it's grounded + validated, then ask me to confirm on the
> rig before marking it MET. One goal, no scatter.

## Process rules (how we work)
- **No self-declared "met".** When I believe a goal is met, I **ask you to confirm on the rig**.
  Only your confirmation flips it to MET (with date). This is the fix for "declared done, wasn't."
- **Regression re-opens.** If a MET goal later breaks, or we find it was incomplete, it goes back to
  OPEN with a note about what regressed.
- **Additive.** New goals get appended to Backlog as we discover them, then promoted.
- **One goal at a time.** Close (or explicitly park) the current goal before starting the next.
- **Status values:** OPEN · IN-PROGRESS · NEEDS-VERIFY (awaiting your confirmation) · MET (date) ·
  REGRESSED · BLOCKED (with reason).

---

## Goals

### G1 — Working lobby (see + select EVERYTHING in a lobby)
**Done =** in the in-area lobby you can SEE and SELECT every element and each is functional.
Working checklist (confirm/adjust):
- [ ] Room list renders (Vacant + occupied slots)
- [ ] Room category tabs (FREE / QUICK START / any others) selectable
- [ ] Select a room row → enter that room
- [ ] Exit area (Triangle / cursor-0) works
- [ ] "In lobby: N" count is correct
- [ ] Right-side lobby buttons all reachable + do their thing (buddy/player-list specifics tracked in G6/G7)
- [ ] Soft keyboard / Past logs / Sub-window (START)

**Status: OPEN — NEVER FULLY WORKED** (corrected 2026-07-04 per owner). Parts render, but the whole has
never held together. This is the foundational goal.

### G2 — Area re-entry (return from lobby, then pick a NEW area)  ✅ SOLVED (owner-confirmed 2026-07-11)
**Done =** from an in-area lobby, Triangle back to Area Select, select a *different* area, and enter
its lobby cleanly — no op48 flood, no freeze.
**Status: SOLVED 2026-07-11. The 2026-07-09 "needs retained server state" theory was REFUTED** — G2 is NOT a
retained-state problem; it was a SN@P reliable-**transport completion** bug, **decoupled from the G12 registry**.
Root cause + fixes (Ghidra + PINE + pcap grounded, no guessed fields):
1. **Enter/leave completion:** op06/op07 completion fires only when the op28 reply's **SUB byte (wire+0x02)**
   echoes the client's send-seq (`conn+0x618`, stamped as a per-cycle *generation*). Server sets `push[2]=msg[2]`
   (`SNAP_REENTRY_CONFIRM_REPLY` / `SNAP_LOBBY_LEAVE_REPLY`). (v3's byte-identical reply stalled because it echoed
   the OUTER seq, not the generation — the old "byte-identical yet stalls" mystery, now resolved.)
2. **ACK invariant:** the transport ACK (frees the client's reliable send block) was generation-gated, so gen≥1
   ops (op07/op08/**op09**) leaked send-pool blocks → exhaustion → stall. Fixed: **ACK all reliable ops for all
   generations** (except the area-select op48 gate).
3. **Lobby cursor:** op49 room-list via the **SUCCESS path** (`SNAP_ROOMLIST_REPLY`, `SNAP_ROOMLIST_FAILFAST=0`)
   renders proper **"vacant"** rooms (the error-path fail-fast rendered "improper").
**Owner-confirmed on the rig 2026-07-11:** single re-entry (screen `0x6c4b90` 1→2) + **INDEFINITE enter/back
cycling** (10+ cycles, no wedge) + rooms render proper "vacant". Evidence: `docs/evidence/pcaps/g2-indefinite-cycling-2026-07-11.pcapng` (archived; SLL2 classic-pcap format),
`docs/findings/protocol/G12-STEP0-WIRE-MATRIX-2026-07-10.md` (+ `-2026-07-11-CONTINUED.md`), `...G12-reliable-pool-RE-2026-07-10.md`,
`...G12-lobby-wedge-RE-2026-07-11.md`. Golden: `g2-solved-transport-2026-07-11` (see GOLDENS.md).
**Known limit (deep-stall — NOT G2):** after heavy aggressive deep cycling down to the room-create screen, a
leave/room-level completion can still stall (`stallTag=8`, armed tag `0x43`, `pool-err=0x65`) → disconnect. That
is a separate, deeper **room-level** issue for the G12 room work, not area re-entry. Documented in the golden caveat.

### G3 — Area-select bottom box (area description)
**Done =** the box under the area grid shows the highlighted area's description text.
**Status: BLOCKED (probably a client dead-end).** RE (Confirmed): `+0x4c` loads to `0x6ce616`→`0x6c38b9`
but **no client function ever draws it**. Likely not server-fixable. Keep only to confirm / find an
alternative surface; do not chase blindly.

### G4 — Two message boxes after sign-in (before server select)
**Done =** the two empty boxes between sign-in and server-select display server content (MOTD / news).
**Status: OPEN.** Client requests `0x6103` (not `0x6105`); needs the `0x6103`/`0x6104` text pipeline.
Earlier `0x6105`/`0x6320` handlers were inert, and one broke the connect flow (reverted).

### G5 — Multiplayer presence (see each other in the lobby)
**Done =** two clients in the same area/lobby see each other — "In lobby: N" and the player list
reflect real connected players.
**Status: OPEN.** Needs a server session/room registry cross-populating area count (`0x6205`) + UDP
`op49` player records. This is the real multiplayer core.

### G6 — Friend list
**Done =** the friend/buddy list in the lobby resolves and displays real entries.
**Status: OPEN.** buddy-lookup = `op48`-NAME + `op49`-LOID/STAT keyed on player handle (`0x7003fd`),
reply slot `0x31`. Server gap.

### G7 — Other lobby buttons (the "????" ones)
**Done =** each lobby button's function is decoded and, where server-driven, implemented
(100-player list, log screen, chat/text, etc.).
**Status: OPEN.** 3-byte nested SM mapped (`0x6c4b90/91/9e`); X-commit `FUN_005f7f30`. Buddy + player
list are server gaps; QuickStart / soft-keyboard need more RE.

### G8 — Second server, Quick Match, and Scenario mode (create/join a scenario game)
**Done =** Server 2 selectable; Quick Match works; you can create/join a scenario game — the
create-slot handshake completes so scenario + rules + character populate, and Finish makes a joinable room.
**Status: OPEN (deep).** Scenario is **client-owned** (Bioserver: `SCENESELECT` only, no list command);
scenario + rules + character are gated on the create-slot handshake (`0x65xx`/`0x66xx`). The big build.

### G9 — Other game modes
**Done =** the remaining game modes identified and supported.
**Status: OPEN.** Not yet enumerated.

### G10 — Solid server: session handling (re-register)  ✅ SOLVED (owner-confirmed 2026-07-06)
**Done =** the server sustains many concurrent clients over a long run **without degrading or needing a
restart** — per-connection state is isolated, dead/idle sessions are reclaimed, re-register *replaces*
(not stacks) a client's session, and DNAS/TLS sockets + buffers are bounded and cleaned up. Endgame
target: **100s of simultaneous connections**.
**Why now (owner, 2026-07-05):** a stable server is the prerequisite for all protocol/lobby tweaking
(G1–G9). You can't iterate on the lobby if the server rots under load.
**Evidence (rig-observed 2026-07-05):** with just **2 clients over ~7 min + reconnects**, new connects
jammed — both stuck in a `post-register-bind` loop, leaked DNAS TLS sockets (`ECONNRESET`/lingering
`dnas_conn`), `regN` accumulating — and **only a `pal-server` restart cleared it**. Classic
accumulated-per-connection-state / no-GC signature; works from a fresh boot, fails under sustained load.
**Status: SOLVED (owner-confirmed on the rig, 2026-07-06).** Root cause (Codex diagnosis, Conclusion):
the server never reset the per-connect-epoch UDP state on the reused `ip:port` session — `s.txSeqNext`
was seeded once and never rewound (the PS2 first-render fix), so on a **re-register** (client re-selects
a server = a new SN@P epoch with a fresh recvBase) the connect-phase op48 reply was stamped out-of-epoch,
the client never got it, and it looped op41 at "connecting". Violates the documented recvBase-must-reset-
per-session-open contract; op41 is the client's op40-keepalive pong (symptom, not the trigger).
**Fix:** `resetUdpSessionForRegister(s)` on `register-request` (commit `32c27fa`), gated behind
`SNAP_RESET_SESSION_ON_REGISTER` (currently deployed ON on the Pi over golden `ec69007`/`8e01d0dc`).
**Rig-validated 2026-07-06 (PS2 + emulator):** re-register no longer stalls → reaches Area Select →
select an area → **enters the in-area lobby** (op06→op28 sel6→op49, photo + journal); the fresh
login→select register (regN=2) still enters (no regression). See
`docs/findings/protocol/G10-area-reentry-udp-stall-RE-2026-07-05.md`. Open decision: fold the flag into
the golden as default-on vs keep opt-in. The **scalability/efficiency** half (100s of connections; the
area-select op48 flood not settling) is split out to **G11**.

### G11 — Absorb the inherent Area Select op48 flood at scale  ✅ DONE (owner-accepted 2026-07-06)
> **Honest scope of "done":** fix built + committed + deployed + gameplay-safe on both platforms, and
> **load-proven locally** (100 clients @ 100%, p50 3ms; knee ~10→~100-150). **Open follow-ups (not
> blocking, tracked):** (1) the real **Pi-side** scale number is unmeasured — needs a `--confirm-live-rig`
> harness run with `SNAP_LEAN_HOTPATH=1`; (2) the Pi runs **lean OFF** today (journal kept for dev) — flip
> ON for production scale; (3) minor: gate `snap_server.js`'s per-session `cmd6504` writeFileSync too.
**Done =** the server absorbs the Area Select op48 flood **statelessly** — acks every op48 by outer id for
all who-bytes, O(1) **small** reply (fits sub-pool-2 ≤~700B), **zero per-query-id state** — so sub-pool-2
free stays >3 (no watermark latch / stall) with **100s of concurrent connections**, each polling ~25/s.
**RE done (2026-07-06, snap-re — CORRECTS the first "make the client settle" framing):** the flood is
**INHERENT and NOT server-fixable at the source.** Area Select runs a frame-timer (countdown `nav+0x1468`
→ refresh flag `+0x146a` → one op48) that re-arms **unconditionally, reply-independent**, ~every 2 frames,
to refresh the per-area player counts (Engine B: `FUN_005c7020`/`FUN_005c70e0` → `0x6fec18`). The only
"rest" state is **leaving the screen** (`+0x146b` cleared). The consumer checks reply byte0==0 then writes
counts — touches no timer/latch, so **no word0/count/terminal flag quiets it**; ~25/s is the designed
cadence (matches the wire: 818/818, fresh incrementing seqs). Doc:
`docs/findings/protocol/G11-areaselect-op48-flood-RE-2026-07-06.md`.
**Status: FIX DEPLOYED + RIG SANITY PASSED (2026-07-06, Pi `ce825e58`, lean OFF).** PS2: connect →
Area Select → entered lobby (op06→op28→op49) → G10 re-register still works; no behavioral change, UDP
snapshot writeFileSync now 0. Left: flip `SNAP_LEAN_HOTPATH=1` for production scale; real Pi knee via a
`--confirm-live-rig` run; minor TCP follow-up = `snap_server.js` has its own per-session `cmd6504`
snapshot writeFileSync to gate too. Audit: the op48 ack/reply hot path
is already **stateless** (local `ids` array, small reply) — the bottleneck was **per-message synchronous
disk I/O**: (1) `log()` = `console.log`+`fs.appendFileSync`, ~5×/op48; (2) an unconditional
`fs.writeFileSync` snapshot header per 0xF0 op48 (a file `runSnapshot` never fills when `UDP_SNAPSHOTS`
is off). **Fix (commit pending):** gate the snapshot setup on `UDP_SNAPSHOTS` + add `SNAP_LEAN_HOTPATH=1`
that no-ops per-message `log()`. **Load-test (tools/loadtest-op48.js, local):** knee moved **~10 clients →
~100–150**; **100 clients ×25/s (2500 req/s) = 100%, p50 3ms** (was ~18% + 700ms). op40 keepalive is a
proper SN@P mechanism (unrelated). **Left:** deploy + a rig sanity check (lean can stay OFF for dev so the
journal keeps logging; flip ON for load/production); real Pi knee needs a `--confirm-live-rig` run.

### G12 — Real server-side session/area/room state model (the multiplayer core)  ⭐ CURRENT GOAL
**Why (root finding 2026-07-09):** the server currently **fakes** the entire application layer — there is NO
per-player membership registry, area-player counts are hardcoded `0` (`snap_server.js` `playerCount:0`),
the room-list is a canned reply, and no server-side model tracks who is in which area/room/slot. The SN@P
**transport** is real + solid (G10/G11 done); what it carries is a facade. That facade walks ONE client
through a fresh forward entry, but collapses on anything that reuses session state — which is why **G2
re-entry cannot complete** (proven by elimination: ~8 mechanisms + a byte-identical reply all ruled out;
re-entry needs retained area/room state the server never had) and why rooms / join / player-lists / real
counts can't work either. This is the difference between "appears to work for one player going forward"
and an actual multiplayer lobby server. Not production-ready without it.
**Done =** a real server-side model, grounded in the JP Bioserver reference (`references/bioserver/`):
- a **live membership registry** keyed by stable player identity (userid/handle/ip) holding `area/room/slot`;
- **state transitions** that mutate it — enter-area (op06/op0106), exit-area (op07/op08), enter/create room —
  mirroring Bioserver `AREASELECT`/`EXITAREA`/`ENTERROOM` (`PacketHandler.java`);
- **area-player-counts (0x6205)** and **room-lists (op49)** derived from ACTUAL state, not stubs/0;
- **multi-client consistency** — 2+ clients see each other's rooms/counts (real broadcasts).
**Status: CURRENT (started 2026-07-09).** Approach: map the Bioserver app contract → SN@P (opcode/id/body,
confirmed on the wire, not guessed); build the registry + transitions incrementally, each validated on the
rig. **CORRECTION (2026-07-11):** the "G2 needs the registry" framing was WRONG — G2 was a transport-completion
bug, now SOLVED and decoupled (see G2). What this session actually established: the SN@P **reliable transport is
now correct end-to-end** (sub-byte completion, ACK-all-generations invariant, proper success-path op49 →
indefinite area enter/back cycling, proper "vacant" rooms; golden `g2-solved-transport-2026-07-11`). The APP
layer is STILL faked and is the real remaining G12 work.
**⭐ UPDATE 2026-07-12 — ordered sub-goals + ONE real advance (create session-open now completes; NOT MET, nora-corrected):**
**⭐ UPDATE 2026-07-16 evening — G12-5 RENDER MECHANISM CONFIRMED ON THE RIG; goal still NOT MET (owner verdict):**
2-device rig run (owner-witnessed, 22:48 Europe/Amsterdam): the PS2 joiner's room screen LOADED for the first
time ever. Root cause + fix: the joiner's screen-4 sub-SM parks at major `0x6c4b9f==5` after sending a
game-channel op10 with app-payload byte (wire+0x18) `0x02` (join-request; pending tag `0x6c4fbb=0x17`,
continuation `FUN_00601300` stored in `uRam006fec00`); a real host answers with op10 sub-`0x0C` (payload
`[0x0C][count LE]`), which fires `FUN_005bbe00` → the continuation → step `0x6c4ba0`=1 → major 5→6 → the room
renders. Fix = `SNAP_JOIN_OP10_SUBC=1` (inside the existing `SNAP_ROOM_INFO_OP10` branch, `server/game_udp_server.js`).
Commits: `bb03ff5` (T21 trace evidence) → `e7757e0` (the fix) → `e1d4a09` (flag ON in the tracked drop-in) →
`27941b4` (T22 2-device evidence) → `2594d02` (owner verdict). Pi gudp md5 `cead951e` == repo; nora pre-deploy
verdict GROUNDED-WITH-CAVEATS. **This CORRECTS the two prior joiner-render models** (tag-0x14 second
session-open; op0a-poll-loop stall) — see the correction banner atop `G12-joiner-render-RE-2026-07-16.md`; the
confirmed model is `docs/findings/protocol/G12-joiner-tag17-RE-2026-07-16.md`.
**Owner verdict (2026-07-16 22:48, T22 addendum): G12-5 does NOT flip to MET.** The render advanced but the
joined room is not functional yet:
1. **Roster/count consistency** — PS2 (joiner) shows "1 play", emulator (creator) shows 2, and members don't
   SEE each other in the room (beyond the count mismatch). Maps to the already-identified
   op0a-lists-all-registry-members + fire-count-once work (T19 items 2/3; owner savestate slot 3, emulator
   creator w/ PS2 joined 2/4 "ROOM", is the evidence base). Owner also reports SERVER SELECT and AREA SELECT
   both show 0 players on this same run — the known hardcoded TCP `0x6205` / registry-cross-population gap
   (G5), not a new issue.
2. **Scenario not selectable + other cast members not selectable** — the known RULE-screen/create-config
   unlock layer (`0x6ff2b1` reaches 1; T13/T17; G8 create-slot handshake). **CORRECTED 2026-07-17
   (`G12-config-unlock-RE-2026-07-17.md`): the gate value is 1, NOT "needs to reach 3"** — `0x6ff2b1=1`
   already enables every config receiver; the real gap is that config is HOST-OWNED (op10 sub-3/5/6/7/8/9
   burst) and the server neither relays it nor echoes the host's TCP `0x6509`/`0x6609`/`0x660B`. See
   FACTS.md CURRENT MODEL for the full contract.
3. **CHAT does not work** — NEW this session, un-RE'd, no root cause yet.
Parking lot (not a current goal): cannot EXIT a lobby room (screen=6 freeze, both on a leftover pre-session
stall and a post-create exit attempt) — candidate G13/G14, see Backlog below.
**▶ RESUME HERE (2026-07-17, supersedes the 2026-07-16 evening pointer):** owner scope decision (T24,
`SESSION-LOG-2026-07-12.md`) — stop per-message flag patching, **port the Bioserver reference server**
as the foundation for the rest of G12 (see the ⭐ 2026-07-17 UPDATE below for the plan + what landed).
The 2026-07-16 gap list (roster/count consistency, scenario/cast/rules unlock, chat) is now mapped into
that plan rather than worked ad hoc: FOUNDATION-MAP status COPY-READY (counts, names, op49 endianness) →
wire into the engine first; NEEDS-VEHICLE/capture-gated (character charstats, config interleave, exit
stages, chat) → one targeted rig capture each, in the order in the FOUNDATION MAP's build order (§ "The
port — build order"). State clean: trunk==Pi `cead951e`, rollback floor `ce825e58`. NOTE:
`SNAP_JOIN_OP10_SUBC` remains an experimental/unpinned flag, not a golden — no `GOLDENS.md` entry exists
for this state; the new `server/lobby_engine.js` (commit `2b7e13c`) is INERT (no frontend routes to it
yet) and likewise not a golden.

`docs/findings/protocol/G12-SUBGOALS-2026-07-12.md` is the authoritative, Codex-reviewed, ordered
breakdown (G12-1..G12-9, dependency chain + per-item Done/Verify criteria). It supersedes the earlier
informal "build order" (① transport ② registry ③ area counts ④ room records ⑤ mutations) and the
2026-07-11 room-entry narrative as the day-to-day tracker; read it first.

**The one real advance this session — G12-1, create session-open ADVANCES:** a post-Finish savestate (slot 4)
+ decompile found the true root cause, correcting all of the session's earlier op06/op09/op10/STAT/cmd0c-seq
work: the create flow is **NOT** `FUN_005fada0` (the op06-ENTER path everything had targeted) — it is a
**different SM, `FUN_005f99c0`**, which registers the room via **op04** (`func_0x001dc508`, cb `FUN_005c3a40`
@ slot 0x1f). Our server never answered op04 at all (pcap: client sends op04 "PAL ...", server replies with
nothing, only op41 inputs follow). Fix: reply op04 with **op28/selector-4/status-0** → `FUN_005c3a40` sets
`0x6cba7d=1` → `FUN_005c3490` sets **`0x6ff2b1=1`**, the single gate that unlocks title/password/scenario/
character. Flag `SNAP_CREATE_SLOT_ACCEPT`, committed `781f496`.
**Status: NEEDS-VERIFY, NOT MET** (nora review 2026-07-12 caught a premature MET stamp and it was reverted —
see `SESSION-LOG-2026-07-12.md` T10/T12 and commit `99802a7`). Grounded in decompile + a local replay of the
real captured op04 bytes only; the commit itself says "NO rig test". Flag is default-OFF, no `GOLDENS.md`
entry. **To flip to MET:** (1) nora pass — done, this is that record; (2) a Pi deploy with the flag ON +
owner-confirmed create-advance on THAT run, evidenced by PINE `0x6cba7d` 0→1 then `0x6ff2b1` 0→1; (3) a
`GOLDENS.md` entry for that confirmed state. None of the three has happened yet.

**Open sub-goals (honest state, from the subgoals doc):**
- **G12-2 — populate the creator's own room (show self as host/member 1):** OPEN. `who=0xA0` fix for the
  create-context op0a member-list reply (slot 0x18 = `FUN_005c0ae0`, fills `0x6cdbe6` + count `0x6ca890`) is
  committed (`392289a`), but the 2026-07-12 rig test (savestate slot 05) STILL showed 0 players. Cause not
  yet grounded — the run lacked full logging (`SNAP_LEAN_HOTPATH` was ON, no pcap), and it may not even have
  been a fresh CREATE. Needs one disciplined re-run with full logging before drawing a conclusion.
- G12-3 — room/slot hierarchy and created-slot descriptor (not started).
- G12-4 — cross-client registration (room A visible in client B's list) (not started).
- **G12-5 — join (2-client co-location) render:** RENDER MECHANISM CONFIRMED on the rig 2026-07-16
  (owner-witnessed 2-device run, `SNAP_JOIN_OP10_SUBC=1`, commits `bb03ff5`/`e7757e0`/`e1d4a09`/`27941b4`/
  `2594d02`) but the goal is NOT MET — remaining gaps: roster/count consistency, scenario/cast/rules unlock,
  chat (NEW, un-RE'd). See the ▶ RESUME HERE pointer above for the ordered next work.
- G12-6 — leave/cancel/dissolve lifecycle + broadcasts (OPEN, not started).
- **G12-7 — real occupancy counts everywhere:** `SNAP_AREA_PLAYERCNT` (Codex, committed `368d184`) is a
  **PROVISIONAL** endpoint-based wiring for Server-Select/Area-Select TCP `0x6205` AREAPLAYERCNT only. The
  in-LOBBY count display is a *different* command (`0x6212` AGLPLAYERCNT / `0x6213` AGLSTATS) whose display
  source is NOT yet RE'd; pre-room counts still read 0 on the rig. Do not conflate the two.
- G12-8 — scenario selectable (fix "(null)") — not started.
- G12-9 — full character roster selectable — not started.

**Correction note:** the 2026-07-11 "ROOM-ENTRY PROTOCOL DECIPHERED" work (op49 rec+0x24 handle, op06 ENTER →
op28 who=0xA0 accept → op10 sub-1 push, flags `SNAP_ROOM_ENTER_ACCEPT`/`ROOM_INFO_OP10`) is still real and
still rig-proven for the JOIN-an-existing-fixture-room path — it is not deleted or wrong. But this session's
savestate work shows the **CREATE** path is a wholly separate SM (`FUN_005f99c0`/op04) that never sends the
op06 ENTER at all until AFTER its own op04+op0c completion — so the earlier op06/op09/op10/STAT create-flow
work (commits `794e76b`/`4365100`/`e2dcad5`/etc.) was downstream of an ENTER that a real Vacant-slot create
never fires, and is not on the critical path for G12-1.
**Reference:** the memory index long ago flagged this ("CORE missing = server session/room registry
cross-populating area counts + room list + membership"); this goal makes it first-class.

**⭐ UPDATE 2026-07-17 — owner scope decision: PORT THE REFERENCE SERVER (FOUNDATION); RE sweep complete:**
Owner (T24/T24-addendum, `SESSION-LOG-2026-07-12.md`): stop per-message flag patching for the rest of
G12; port the Bioserver reference server's logic wholesale (ClientList/Slots/PacketHandler → JS around
`lobby_state`), mapped per-phase via `docs/design/FOUNDATION-MAP-2026-07-17.md` (Bioserver contract ↔
PAL vehicle ↔ status ↔ port action, covering the WHOLE session — server select, area select, room list,
in-room, not just the room layer) and `docs/design/ROOM-ENGINE-DESIGN-2026-07-17.md` (the in-room
component, three-review final: nora × second_opinion × Codex).
- **Step 1 landed (commit `2b7e13c`):** `server/lobby_engine.js` (new, factory-bound pure transitions
  returning emission plans) + `server/lobby_state.js` extensions (slot status lifecycle, playerNo
  assignment, identity/liveness fields, live-scan counts, audience filters). **INERT/tested** — no
  frontend routes to it yet, no wire or behavior change, 41/41 existing `lobby_state` tests still pass.
  Not yet wired to `game_udp_server.js`/`snap_server.js`.
- **RE sweep complete (5 findings docs, snap-re, commits `111e93b`/`dc4a6df`/`83c95b9`/`973fe33`):**
  `G12-count-displays-RE-2026-07-17.md`, `G12-identity-vehicle-RE-2026-07-17.md`,
  `G12-op49-fields-RE-2026-07-17.md`, `G12-config-unlock-RE-2026-07-17.md`,
  `G12-exit-contract-RE-2026-07-17.md` — see FACTS.md CURRENT MODEL for the confirmed content. Turned
  most FOUNDATION-MAP unknowns into either **COPY-READY** (server-select/area-select counts via the
  correct vehicles, real names via `p.handle`, op49 record endianness fix — no new RE needed, just
  wiring) or **vehicle-known + one targeted capture** (character charstats blob, config op10-burst
  interleave + TCP echo ordering, exit two-stage teardown, max-players writer). Also REFUTED the "area
  count = TCP 0x6205" and "config gate needs 0x6ff2b1=3" assumptions (T25 journal evidence; see FACTS).
- **Next (in order):** (1) wire the COPY-READY fixes into the engine as the first rig-checked increment
  (server/area-select counts, real names, op49 BE) — lowest risk, no new RE required; (2) the
  capture-gated items each need ONE targeted rig capture before implementation — character/charstats
  (create→character-select), config interleave (create→configure, TCP+UDP+PINE), exit stages (Triangle-
  back in a room, pcap+PINE tags `0x6c4fbb`/`cRam006cbbe0`), chat (one chat-send). Follow the
  FOUNDATION-MAP "port — build order" (§ engine skeleton → copy-ready counts → identity layer → in-room
  ladder 0→1a→1b→1c → targeted RE in parallel → flag retirement) and the ROOM-ENGINE-DESIGN ladder
  (`SNAP_ROOM_ENGINE` master flag + per-increment sub-flags, each with its own rig pass/fail + fallback).
- **Status: still CURRENT, NOT MET.** This is a re-scoping of HOW the remaining G12 work gets built, not
  a new result to verify; nothing here is rig-confirmed beyond the engine skeleton's local tests.

---

## Backlog (discovered later — promote when ready)
- **Cannot EXIT a lobby room** (2026-07-16, T21 parking-lot note): both a leftover pre-session stall and a
  post-create exit attempt freeze at screen=6 (tag flushed 0x19/0x20→0, roomscr stays 0x10). Candidate
  G13/G14, not started — do not conflate with G12-5 (room render/entry, separate direction).

---

## Confirmed facts feeding these goals
Kept in `FACTS.md` (single source) + `docs/findings/protocol/LOBBY-UNIFIED-ARCHITECTURE-RE-2026-07-03.md`
(the technical model). Notable this session:
- Scenario carrier = area record `+0x03` (bitmask); per-group scenario table `0x341ac8` is network-only
  with **no code writer** in dumps; title resolver `func_0x001b6950` is external (titles are disc/runtime).
- Scenarios are client-owned per Bioserver; online list = 11 (WT,UB,FB,DT,EOTR + Elim×3 + Showdown×3),
  Training excluded.
- PINE "refused" root cause = zombie clients hogging PINE's single slot; clear Established:28011 first.
- 2026-07-04/05: golden recovery + first-area-enter fix. Validated golden = `ec69007`
  (`golden-lobby-full-2026-07-05`, see `GOLDENS.md`); regressor = `d3dacf3` (SNAP_AREA_SCENARIO write);
  first-area-enter advance fix = `SNAP_ACK_OP48_F0=1` (`golden-area-enter-advances-2026-07-05`). See
  `docs/findings/protocol/G2-SESSION-2026-07-05.md`.
