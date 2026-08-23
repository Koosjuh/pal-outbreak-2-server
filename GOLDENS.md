# GOLDENS.md — the record of known states (read this before "restore to X")

This is the ONE place a good state is written down. If a state isn't here with its
**commit + per-file md5 + how the env was set + who confirmed it on the rig**, it is
NOT a golden — it's a memory, and memories are what cost us a day on 2026-07-04/05.

**A doc that says "VALIDATED" is not a golden.** A golden is an artifact you can
check. The md5 is the point: it's the fingerprint of what was *actually on the Pi*
when it worked, so "restore to X" is verifiable against reality instead of a story.

## How to use this file
- **Before saying "restore to commit X":** find X here, check the md5 matches
  (`git show X:server/snap_server.js | tr -d '\r' | md5sum | cut -c1-8`).
- **After a deploy:** `deploy-pi.ps1` prints the Pi md5 — confirm it equals the md5
  below. If they differ, the Pi is NOT running this state (deploy drift = exactly the
  `737041b7` mess below).
- **Env flags live in systemd drop-ins on the Pi** (`/etc/systemd/system/pal-server.service.d/*.conf`),
  NOT in git. That's a real gap — the flags below are recorded here by hand until we
  mirror the drop-ins into the repo. Verify against the live Pi:
  `ssh … "systemctl show pal-server.service -p Environment"`.
- **Not recoverable, ever:** client session/registration state is ephemeral and
  re-established every boot. No file can freeze it. Don't pretend otherwise.

---

## CONFIRMED — someone watched this work on the rig

### `joiner-render-2026-07-16`  ⭐ LATEST milestone — first-ever JOINER room render (create + join, both in room)
- **Commit:** deployed artifact = `e1d4a09` (SNAP_JOIN_OP10_SUBC=1 in the tracked drop-in); code fix
  `e7757e0` (SNAP_JOIN_OP10_SUBC join-accept sub-0x0C); recorded in docs commit `b12253e`. Tag:
  `golden-joiner-render-2026-07-16` on `e1d4a09`. Branch `feat/area-op48-activation`.
- **md5 (Pi == repo, ssh-verified 2026-07-16, nora):** `game_udp_server.js` = `cead951e5d04d34d0976fe3861a42ba1`
  · `snap_server.js` = `407dbdda24a4c9880c1fc947c4e934b3` (unchanged since the member-join candidate; differs
  from g2-solved `8e01d0dc`) · `lobby_state.js` = `b1616d5458b183c844da3e23a5e323ff` (changed via `3f0ba96`).
- **Flags:** tracked `deploy/pal-server.service.d/00-pal-server.conf` (repo == Pi). Adds `SNAP_JOIN_OP10_SUBC=1`
  over the member-join set. NOTE: `SNAP_JOINER_BROADCAST=1` is ON but MOOT (commit `c73393e`). Carries the
  ~23-flag experimental set (`FLAG-AUDIT-2026-07-12.md`) still individually unconfirmed.
- **Rig-confirmed (owner, 2-device, 2026-07-16 22:48):** emulator creates "ROOM" (renders) AND the real-PS2
  joiner's room screen LOADS for the first time ever; both players in the room. Journal OUT #1251
  JOIN-ACCEPT op10 sub=0x0c count=2 seq=0x26a. Evidence: `captures/g12-joiner/joiner4-confirm-2026-07-16.pcapng`,
  `journal-joiner4-2026-07-16.log` (untracked, on disk), `joinsm-samples-confirm-2026-07-16.jsonl`, owner
  savestate slot 3.
- **Scope of the claim:** create render + join render + both-in-room ONLY. This is a witnessed STATE, not a
  met goal — G12-5 is NOT MET (owner: member list/chat/scenario/cast/rules/counts still broken).
- **Known-open at this state:** members don't see each other in-room; count mismatch (PS2 "1 play" vs emu 2);
  chat broken; server-select 0 players; area-select 0 players; scenario/cast not selectable (`0x6ff2b1` stuck
  at 1, needs 3); cannot EXIT a lobby room (screen=6 freeze/hang); op10 sub-0x0e unanswered (didn't block render).
- **⚠️ NOT the day-to-day revert floor.** The g2-solved transport behaviors (single-area re-entry + indefinite
  enter/back cycling) are NOT re-verified at `cead951e`, the state stacks ~23 unpinned flags (+ a MOOT one), and
  it has a known in-room EXIT hang. **Revert floor stays `g2-solved-transport-2026-07-11` (`83dcf996`) /
  `g10-g11-2026-07-06` (`ce825e58`, bundle-restorable).**

### `g2-solved-transport-2026-07-11`  — G2 solved, SN@P transport correct end-to-end
- **Commit:** code landed in `ca47e51` (`game_udp_server.js` → `83dcf996`), on branch
  `worktree-g12-step0-wire-matrix`; this golden recorded in the following docs commit. `snap_server.js`
  **unchanged** from the prior golden. **No remote** — restore via the md5 below + `git checkout` on the branch.
- **md5 (Pi == repo, verified 2026-07-11 via `deploy-pi.ps1` + `git show HEAD:server/game_udp_server.js | tr -d '\r' | md5sum`):**
  `game_udp_server.js` = `83dcf99601d7fdeca5edf0d73301cc93`  ·  `snap_server.js` = `8e01d0dc88289540681928c6dcb87004`.
- **What it adds over `g10-g11-2026-07-06`** (which could NOT re-enter an area — G2 was open there):
  1. **Enter/leave completion (G2):** op28 reply SUB byte (wire+0x02) echoes the client send-seq/generation
     (`push[2]=msg[2]`), so op06/op07 completions fire on every cycle.
  2. **ACK invariant:** ACK all reliable ops for **all generations** (was gen-gated → op07/08/09 leaked the
     send-pool → exhaustion `DAT_0025b790=0x65`). Now the send-pool never drains across cycles.
  3. **Proper room list:** op49 via the **success path** renders "vacant" (valid empty) rooms. The error-path
     `SNAP_ROOMLIST_FAILFAST` (which rendered "improper") is **retired to OFF** — code retained as a fallback only.
- **Rig-confirmed:** 2026-07-11 — **owner witnessed**: single area re-entry (screen `0x6c4b90` 1→2) + **indefinite
  enter/back cycling** (10+ cycles, no wedge, instant enters ~0ms server reply, send-pool never exhausts) + room
  list renders proper **"vacant"**. Evidence: `docs/evidence/pcaps/g2-indefinite-cycling-2026-07-11.pcapng` (archived; SLL2 classic-pcap format),
  `docs/findings/protocol/G12-STEP0-WIRE-MATRIX-2026-07-10.md` (+ `-2026-07-11-CONTINUED.md`).
- **Env flags (live Pi drop-ins, read 2026-07-11):** the g10-g11 functional set PLUS: **`SNAP_ROOMLIST_FAILFAST=0`**
  (success-path op49 is the golden behavior — do NOT set this to 1, it renders rooms "improper"),
  **`SNAP_LEAN_HOTPATH=1`** (ON — lean-OFF fills the Pi disk). Full set: `SNAP_ACK_OPS=all`, `SNAP_ACK_OP48_ALWAYS=1`,
  `SNAP_OP48_REPLY_ALL=1`, `SNAP_AREA_OP48=1`, `SNAP_AREA_OP48_COUNT=10`, `SNAP_AREA_CONFIRM_REPLY=1`,
  `SNAP_AREA_LIST=1`, `SNAP_LOBBY_LEAVE_REPLY=1`, `SNAP_REENTRY_CONFIRM_REPLY=1`, `SNAP_ROOMLIST_REPLY=1`,
  `SNAP_CMD0C_SELECTOR12=1`, `SNAP_OP40_KEEPALIVE=1` (key `SNAP-SWAN`), `SNAP_SUPPRESS_UNKNOWN_REPLY=1`,
  `SNAP_TXSEQ_FIX=1`, `SNAP_RESET_SESSION_ON_REGISTER=1`, `SNAP_ROOM_SEQ_ADVANCE=1`, `SNAP_ROOM_SEQ_OFFSET=2`,
  `SNAP_LOBBY_SLOTS=2`/`SNAP_LOBBY_SLOT_MAX_PLAYERS=4`, `SNAP_ROOM_COUNT=1`, `SNAP_ROOM_ENTER_OP=0x31`.
- **⚠️ KNOWN LIMIT (documented, not hidden) — the deep-stall:** this golden is "transport solid + proper vacant
  rooms + normal lobby navigation", NOT "everything perfect". After **heavy aggressive DEEP cycling** (repeatedly
  backing in/out down to the room-**create** screen, ~10 cycles) a **leave/room-level completion can still stall**
  (PINE: `stallTag=8`, armed slot tag `0x43`, `pool-err DAT_0025b790=0x65`) → disconnect. This is a **separate,
  deeper room-level issue** (NOT area re-entry / not the ctx3 lobby-wedge, which is fixed), reserved for the G12
  room-level work (steps ④/⑤). Also: rooms are empty-but-valid ("vacant"), **not real rooms yet** — that's the
  registry (G12). **This is the revert point** when G12 registry work goes sideways.

### `g10-g11-solid-server-2026-07-06`  — prior day-to-day baseline (G2 was open here)
- **Commit:** `979397b`  ·  **tag:** `golden-g10-g11-2026-07-06`  (code: G10 reset landed in
  `a94f2306`, G11 I/O gates in `c3ea80d`; `979397b` is the tree that was deployed).
- **md5:** `game_udp_server.js` = `ce825e58`  ·  `snap_server.js` = `8e01d0dc`  — **Pi == repo,
  verified 2026-07-06** (`deploy-pi.ps1`).
- **Backup:** complete verified git bundle (`--all`, restorable) at
  `D:/projects/_backups/pal-outbreak-2-server_golden-g10-g11_2026-07-06_979397b.bundle`.
- **Rig-confirmed:** 2026-07-06 — **owner witnessed on REAL PS2 + emulator**: connect → Area Select →
  select an area → **enter the in-area lobby** (op06→op28 sel6→op49, photo + journal); back out →
  **re-select a server (re-register) → enters Area Select again** (G10 — `[G10] resetUdpSessionForRegister`
  fires); the area-select op48 flood (~26/s) is **absorbed 1:1**; **0 errors, 0 UDP snapshot writeFileSync**.
- **Adds over the 07-03 candidate `ec69007`:** G10 re-register epoch reset (`SNAP_RESET_SESSION_ON_REGISTER`)
  + G11 hot-path I/O gates (`SNAP_LEAN_HOTPATH` = scale switch, default OFF; snapshot `writeFileSync` gated
  on `UDP_SNAPSHOTS`). `snap_server.js` is **unchanged** (still the golden `8e01d0dc`).
- **Env flags (live Pi drop-ins, read 2026-07-06):** notably **`SNAP_RESET_SESSION_ON_REGISTER=1`**;
  `SNAP_LEAN_HOTPATH` **unset = OFF** (journal kept for dev — flip ON for production scale); `UDP_SNAPSHOTS`
  **unset = OFF**. Functional set: `SNAP_ACK_OPS=all`, `SNAP_ACK_OP48_ALWAYS=1`, `SNAP_OP48_REPLY_ALL=1`,
  `SNAP_AREA_OP48=1`, `SNAP_AREA_OP48_COUNT=10`, `SNAP_AREA_CONFIRM_REPLY=1`, `SNAP_AREA_LIST=1`,
  `SNAP_LOBBY_LEAVE_REPLY=1`, `SNAP_CMD0C_SELECTOR12=1`, `SNAP_OP40_KEEPALIVE=1` (key `SNAP-SWAN`),
  `SNAP_SUPPRESS_UNKNOWN_REPLY=1`, `SNAP_TXSEQ_FIX=1`, `SNAP_ROOMLIST_REPLY=1`, `SNAP_ROOM_SEQ_ADVANCE=1`.
  **Note:** `SNAP_AREA_SCENARIO` / `SNAP_AREA_MODIFIERS` are **NOT** in this set (unlike the 07-03 candidate).
- **Known-open at this state:** **G2** area re-entry (lobby→back→**new** area) still stalls on the sub-pool-2
  latch; **G11** real **Pi-side scale** number unmeasured (local test = 100 clients clean; flip lean ON + run
  the harness `--confirm-live-rig` for the Pi knee).
- **New safest day-to-day fallback.** The `lobby-interactive-2026-07-02` entry below remains the deeper floor.

### `lobby-interactive-2026-07-02`
- **Commit:** `0ff7227`  ·  **tag:** `known-good-lobby-interactive-2026-07-02`
- **md5:** `game_udp_server.js` = `84bca4ea`  ·  `snap_server.js` = `e27fe0be`
- **Rig-confirmed:** 2026-07-02 — area → lobby → cursor unlock; owner could click
  everything (per HANDOFF-2026-07-02-transport-solved). L1 transport solved.
- **Known-open at this state:** no Free-first ordering, not all-10 areas, no per-area
  rules, no back-nav. (Those came later — see the 07-03 candidate below.)
- **Safest fallback.** If everything is on fire, this is the floor that was witnessed.

---

## CANDIDATE — claimed validated in a report, but NOT re-confirmed on the rig

> These carry the fingerprint but the "it worked" is prose we no longer take on faith.
> Do not treat as golden until a clean rig pass is witnessed and moved up to CONFIRMED.

### `member-join-2026-07-13` (c047af3)  ⭐ strongest candidate — owner-observed + savestate-proven
- **Commit:** `c047af3` (trunk `feat/area-op48-activation`)  ·  **tag:** `golden-candidate-member-join-2026-07-13`.
- **md5:** `game_udp_server.js` = `dd3097fe`  ·  `snap_server.js` = `407dbdda`  ·  `lobby_state.js` = `a2e73dc3`.
  **Pi == trunk** (deployed dd3097fe, drift resolved 2026-07-13).
- **Flags:** `deploy/pal-server.service.d/00-pal-server.conf` (consolidated, tracked; `SNAP_MEMBER_JOIN_PUSH=1`).
- **Rig-observed (owner, 2026-07-13):** created a room → **"1 player" shown in the room** (first time ever).
  Savestate slot-1 CONFIRMS: `0x6c7c2c` row0 written (`"02000000"`), `0x6cbc7e=0x10`, `0x6cd682="CREATOR"`,
  `0x6cd672="00000002"`, member count=1. The op06→slot-2 `FUN_005bb4d0` member-JOIN push provably RAN
  (`0x6cbc7e`/`0x6cd672`/`0x6cd682` are its writes only).
- **CAVEAT (nora 2026-07-13) — CONFOUND, not isolation:** `SNAP_CREATE_MEMBERLIST=1` was ALSO on. The drawn
  row's byte CONTENT (`0x6c7c2c="02000000"`) traces to the op0a buffer `0x6cdbe6`, NOT the member-JOIN's
  `0x6cd672`. So this run proves **member-JOIN + op0a TOGETHER** draw the player (member-JOIN = draw-enable
  `0x6cbc7e=0x10` + fingerprints; op0a = row content). "member-JOIN alone draws the row" is UNPROVEN — needs
  the isolation control (member-JOIN ON / `CREATE_MEMBERLIST` OFF). Joiner-path reuse is an Inference, not built.
- **Why CANDIDATE not CONFIRMED:** pending a `nora` grounding pass + the owner's explicit MET sign-off. Also
  carries 22 other experimental flags still individually unconfirmed.
- **Known-open at this state:** `1/0p` max-players render; RULE-screen title/password still locked
  (`0x6ff2b1`=1, not 3); scenario null; only 5 chars selectable; joiner broadcast (G12-5) not built.
- **Rollback floor:** golden `g10-g11-2026-07-06` (`979397b`, `ce825e58`), bundle verified restorable.

### `lobby-full-2026-07-03` (ec69007)
- **Commit:** `ec69007`  (last commit before the scenario byte)
- **md5:** `game_udp_server.js` = `25a5c956`  ·  `snap_server.js` = `8e01d0dc`
- **Claimed (MORNING-REPORT-2026-07-03, archived):** Free-first + all-10 areas
  selectable + per-area rules + area→lobby + back-nav; re-selecting a *new* area was
  the known-open bug (G2). Recorded Pi md5 there = `25a5c956` / `8e01d0dc` — which is
  THIS commit, not d3dacf3.
- **Status 2026-07-05:** NOT re-confirmed. First area-enter observed stalling (screen
  stays 1) in ≥2 runs. Unresolved whether that's environmental, a client latch (G2),
  or the "validated" claim was timing/luck. **Pending a clean, PINE-silent rig test of
  exactly this artifact (deploy `8e01d0dc`, not `737041b7`).**
- **Env flags (live Pi drop-ins, read 2026-07-05, dated 07-01/02/03, unchanged since):**
  `SNAP_ACK_OPS=all`, `SNAP_ACK_OP48_ALWAYS=1`, `SNAP_OP48_REPLY_ALL=1`,
  `SNAP_AREA_OP48=1`, `SNAP_AREA_OP48_COUNT=10`, `SNAP_AREA_CONFIRM_REPLY=1`,
  `SNAP_LOBBY_LEAVE_REPLY=1`, `SNAP_AREA_MODIFIERS=1`, `SNAP_AREA_SCENARIO=1`.
  Note: `SNAP_AREA_SCENARIO=1` is **inert on this artifact** — the code that reads it
  does not exist until d3dacf3 (below).

---

## NOT A GOLDEN — recorded so no one restores it by mistake

### `d3dacf3` (currently deployed, stalls)
- **Commit:** `d3dacf3`  ·  **md5:** `game_udp_server.js` = `25a5c956`  ·  `snap_server.js` = `737041b7`
- **What it is:** `ec69007` + a 12-line snap_server-only diff = the `SNAP_AREA_SCENARIO`
  rec+0x03 write. game_udp is byte-identical to the 07-03 candidate.
- **Why it's called out:** on 2026-07-04 a session "restored the 07-03 golden" by
  checking out d3dacf3 — but its snap_server (`737041b7`) is NOT the validated artifact
  (`8e01d0dc`). Same-looking commit, different binary. With `SNAP_AREA_SCENARIO=1` the
  scenario byte write is *active* here (unlike on `8e01d0dc`), so this is a config that
  the 07-03 run never actually ran. Prime suspect for the current stall.
- **To get the real candidate:** `git checkout ec69007 -- server/game_udp_server.js server/snap_server.js`
  → snap_server becomes `8e01d0dc`.

---

### `base-create-capable-2026-07-13` — CURRENT WORKING BASE (NOT golden — untested)
- **Tag:** `base-create-capable-2026-07-12` (code `392289a`); trunk now unified at merge `1879c39`
  (`feat/area-op48-activation`), so **trunk == Pi == `dd3097fe`** (adds the member-JOIN push over 392289a).
- **md5:** `game_udp_server.js` = `dd3097fe`. **Deploy drift RESOLVED 2026-07-13**: the 78 G12 commits that
  lived only on `worktree-g12-step0-wire-matrix` are merged onto the trunk (keep-history, no SHA rewrite).
- **Flags:** consolidated from 17 conflicting systemd drop-ins into ONE tracked file
  `deploy/pal-server.service.d/00-pal-server.conf` (repo == Pi), verified **byte-identical** effective env
  (58 vars, empty diff). Old 17 backed up on Pi `.../backup-2026-07-13/`. Classification: `FLAG-AUDIT-2026-07-12.md`.
- **Why it's here, not CONFIRMED:** it reaches the create-unlock (`0x6ff2b1` 0→1→3, owner-seen) — real
  forward progress the golden lacks — BUT it carries 23 experimental flags NONE individually rig-confirmed,
  and the member-JOIN push is **untested**. **Do NOT call golden until a rig test + owner confirmation.**
- **Rollback floor if this regresses:** the CONFIRMED golden `g10-g11-2026-07-06` (`979397b`, gudp `ce825e58`),
  bundle at `D:/projects/_backups/...979397b.bundle` — verified restorable 2026-07-13.

## Adding a new golden (the rule)
1. Deploy it, confirm `deploy-pi.ps1` shows Pi md5 == repo md5.
2. Witness it work on the rig (state what you saw + platform + date).
3. Only then add it under **CONFIRMED** with commit + md5 + env flags + what was seen.
   Tag the commit (`git tag -a <name> <commit>`) so the pointer is unambiguous.
4. If it was only "claimed" by a report and not witnessed → it goes under **CANDIDATE**,
   not CONFIRMED. That line is the whole reason this file exists.
