# RIG SESSION 1 — the batched verification run (R1–R10)

One session, ~30 minutes of owner time, clearing every evidence gate for PORT-PLAN
slices 1–3. Division of labour: **the owner drives the PS2 and reports what the
screen shows; Claude drives the emulator, PINE, captures and the journal.** Steps are
ordered so passive reads come first and the wedge-risking repro comes last — if time
runs out, stop after any step; each is independently valuable.

## Before the session (Claude does all of this, owner just confirms ready)
- Deployed build = branch `feat/v2-bioserver-port` tip, md5 repo == Pi for every
  changed file, `:10127`/`:9090` verified BOUND after restart.
- Flags: `SNAP_JOIN_LADDER=ON`, `SNAP_OP10_RELAY=ON` (the join/start plumbing under
  test), `SNAP_EXIT_CLOSE_MIRROR=ON`, `SNAP_COMPLETION_SEQ_ECHO=ON` (the B3 fixes
  under test), `SNAP_GAME_BEACON_ECHO=ON` (the B1 experiment),
  `SNAP_ROOMFLAGS_PUBLISH=OFF`, `SNAP_GAME_BEACON_RELAY=OFF`.
- Capture running (both consoles, never the Pi's own address in the filter);
  journal window noted; PINE sampler armed on the emulator.
- **PS2 power-cycled** (cached `OBAREA-V2` would fake a rules false-negative).

## The steps

| # | Owner does (PS2) | Look for | Clears | 
|---|---|---|---|
| R1 | Sign in, go to Area Select, then into a lobby | Are **rules selectable** now? Do room counts still read `1/0p`? | B4 rules half (first real test of the deployed masks) |
| R2 | Stay on the area screen ~10 s | *(Claude: PINE read `bRam006ce5cf` + `cRam007006a5` on the emulator at the same screen)* | whether min/max players can EVER bind on the selector-0 branch — guessed at twice, settled in one read |
| R3 | *(Claude creates a room from the emulator)* PS2: enter that box, watch the room list | List renders and **keeps refreshing** (the transport fix); then select the room and try to **JOIN** | B2 — the milestone-gating join; also whether "No. of Players" changed |
| R4 | If the PS2 stalls in R3: freeze, don't press anything | *(Claude: PINE `0x6c4b90/0x6c4b9f/0x6c4ba0/0x6cbc7e` at the stalled moment)* | discriminates the three stall hypotheses directly |
| R5 | If joined: open the player-count screen in the room | Count correct? | the untested room-capacity (MAXI) reply branch |
| R6 | **Solo start**: back out, create a room alone, press START | **Does the scenario load?** (Any new symptom ≠ black screen is also a win — say exactly what you see) | THE B1 blocker — the beacon-echo experiment |
| R7 | If R6 loaded AND R3 joined: **create a FRESH room** (a failed start leaves the old room closed by design), both consoles in, press START | Both consoles load; joiner follows the host | first-ever op-0x10 on the wire; the 2-player start |
| R8 | After any game/abort returns you to the meeting room | *(Claude: PINE watch `0x6C4B9E`)* | the meeting-room screen writer |
| R9 | LAST: enter area → leave → enter → **leave again** | Second leave works? (This is the B3 repro; a wedge here ends the console's session, hence last) | both B3 fixes + the M1-vs-M2 mechanism via Claude's PINE watch set |
| R10 | — nothing — | *(Claude: pull one op-0x40 keepalive from the pcap, decrypt offline)* | the keepalive-key discrepancy |

## Honest expectations
- R3 (join) and R6 (solo start) are the two that matter. R3's fix is Conclusion-grade
  (transport bug, byte-proven); R6 is a Hypothesis-grade experiment — a fail there
  still buys the captured beacon exchange that pins the next move.
- A failed R6 must NOT be followed by R7 in the same room — the room is closed
  (BUSY) by design after a start; create a fresh one.
- Everything deployed is one env-flag from rollback; the pre-branch build is on the
  Pi in `src-backup-*` directories.

## Session record
Fill during the run: date/tag, pcap path, journal window, per-step outcome,
owner verdicts. Findings go to `SESSION-LOG-<date>.md` as they happen.

## Results from Rig Test

### R1. Area Select / Lobby
- Rules selectable?
  - [ ] Yes
  - [ x] No
- "No. of Players" shown: 2 (Ps2 and Emulator) which is correct
- Other observations: The bottom 4  oors are ???? and cant be selected. Lobby chat doesnt work. View the service or national ranking button doesnt work. When creating a room the rules are NOT selectable they are red see save state slot 2. When leaving the lobby the count stays 2 so it doesnt go down. Also Selecting after sign in Server 1 or server 2 all lead to the same area select. So it doesnt matter which server i select. 

(Save State Slot: 2)
---

### R2. Area screen (10 seconds)
- Stayed on Area Select for ~10 seconds?
  - [x ] Yes
  - [ ] No
- Anything visible happen? no what do you expect to happen? Its an area select SECRET AREA and Reserved are not selectable and the bottom text says 1-3 even though player count is useless there as a room you can make the player max limit yourself and the max in all online games is 4.
-

(Save State Slot: 1)

---

### R3. Join room

PS2:
- Room list appeared?
  - [ x] Yes
  - [ ] No
- Room list kept refreshing?
  - [ x ] I dont know
  - [ ] No
- Could select the room?
  - [x ] Yes
  - [ ] No
- JOIN succeeded?
  - [ ] Yes
  - [ x] No
- If not, exactly what happened?It stayed on Getting information please wauit for a moment. Connection error occured later on the Emulator aftrer about 5~10 seconds after trying to enter with ps2. 
-

- "No. of Players" shown: 2 in lobby 4 currently playing? That is not correct. 
-

(Save State Slot: 3 but was after disconect)

---

### R4. If JOIN froze
- Screen where it froze:
-
- Music still playing?
  - [ x] Yes
  - [ ] No
- Background still animated?
  - [ x] Yes
  - [ ] No
- Cursor movable?
  - [ ] Yes
  - [ x] No

(Save State Slot: Not possible real ps2 doesnt have save state)

---

### R5. If JOIN succeeded
- Opened player-count screen?
  - [ ] Yes
  - [x ] No
- Player count shown:
-
(Save State Slot: )
---

### R6. Solo START
- Created room?
  - [ x] Yes
  - [ ] No
- Pressed START?
  - [ x] Yes
  - [ ] No

Result:
- [ ] Scenario loaded
- [] Loading screen then failed
- [ ] Black screen
- [ ] Returned somewhere else
- [ x] Other: Picture of a Zombie and network error. then loading and a connection error occurred

(Save State Slot press start / loading screen : 4 )
(Save State Slot aftermath: 5 )
---

### R7. Two-player START
(Only if R3 and R6 both succeeded.)

- Fresh room created?
  - [ x] Yes
  - [ ] No
- Both players joined?
  - [ ] Yes
  - [ x] No
- START pressed?
  - [ ] Yes
  - [ x] No

Result:
- Host: Emulator
- test123
- Joiner: PS2 
- Real

(Save State Slot: 3)
---

### R8. Meeting room
(If returned there.)
 Did not return to the meeting room this time
- Could move?
  - [ ] Yes
  - [ ] No
- Could exit?
  - [ ] Yes
  - [ ] No
- Anything unexpected?
-

(Save State Slot: )

---

### R9. Leave area twice
- First leave worked?
  - [x ] Yes
  - [ ] No
- Re-entered area?
  - [ x] Yes
  - [ ] No
- Second leave worked?
  - [x ] Yes
  - [ ] No
- If not, what happened? I can seem to return now when ever 
-
When creating a lobby and pressing Exit though i couldnt leave that is in save state slot 7.
(Save State Slot: 7)

---

### Result

ALL THE RULES are still red, i cant select a scenario, only the male characters are still selectable, i cant create rules, the rules do not match the area select, it seemed like nothing changed, what did you do for 2-3 hours?! Please review the work and check the save states with the corpus all the answers are either there or via RE in the ISO why is this so difficult?!
