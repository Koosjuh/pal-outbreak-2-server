# SAVESTATE ATLAS — direct p2s memory reads across all 20 owner states (2026-08-24)

**Method (proven, no rig needed):** PCSX2 `.p2s` = zip with zstd (method 93) entries; parse the
local file header manually and `zstandard`-decompress `eeMemory.bin` (32MB EE RAM, EE address ==
file offset) + `Screenshot.png` (the on-screen moment). Sweep script + per-state JSON + shots:
scratchpad `atlas/`. Sources for the address map: FACTS.md CURRENT MODEL,
`analysis/op28-channel-bit-dispatch-2026-08-24.md`, `docs/design/v2-port/RULES-MASK-RE.md`.
Grades: **Observation** = bytes read from a state; **Inference** = derived; caveats in §7.

## 1. Per-state protocol snapshot (Observation)

screen `0x6c4b90` · latched tag `0x6cbc7c` · ctr = `conn+0x61a`/`+0x61b` (lobby/room reliable
counters) · handles = `0x6ce5cf`/`0x6ce5d0` · err = `0x25b790` · pend = armed `0x6ca960`
entries (tag,pktid):

| state | saved | screen | tag | ctr | handles | err | pend |
|---|---|---|---|---|---|---|---|
| 01 | 08-08 19:31 | 1 AreaSelect | 0x43 | 1/0 | 0/0 | 0 | (0,0) |
| 01.bak | 08-07 08:38 | 3 create | 0x21 | 0/0 | 1/1 | 0 | (0,1) |
| 02 | 08-08 19:35 | 3 RULE screen (red) | 0x2f | 1/0 | 1/1 | 0 | — |
| 02.bak | 08-07 21:08 | 2 Lobby | 0x2f | 1/0 | 0/0 | 0 | (0x43,0)(0,0) |
| 03 | 08-08 19:41 | 4 in-room (MEMBER DATA) | 0x21 | 0/0 | 1/2 | 0 | (0x86,0)(0x7b,0)(0x7b,1)(0,0) |
| 04 | 08-08 19:42 | 5 press-start/loading | 0x91 | 0/0 | 1/1 | 0 | (0,0) |
| 05 | 08-08 19:43 | 1* in-game aftermath | 0x20* | 0/0 | 0/0 | 0 | junk* |
| 05.bak | 07-12 14:19 | 4 in-room | 0x7b | 0/0 | 1/1 | 0 | (0,0)(0,0)(0,1) |
| 06 | 07-18 11:33 | 4 in-room | 0x7b | 0/0 | 1/2 | **0x65** | (0,0)(0,0)(0,1) |
| 07 | 08-08 19:45 | 4 EXIT-PARK | **0x43** | **11/1** | **0/2** | 0 | **(0x70,0)** |
| 07.bak | 07-17 14:20 | 4 exit-park (July) | 0x7b | 0/1 | **1**/2 | 0 | (0x70,0) |
| 08 | 07-19 12:36 | 4 in-room | 0x7b | 0/0 | 1/2 | 0 | (0,0)(0,0)(0,1) |
| 08.bak | 07-16 21:51 | 6 "connection error" dialog | 0x86 | n/a | 0/0 | 0 | (0x21,3) |
| 09 | 07-19 12:38 | 4 in-room | 0x7b | 0/0 | 1/2 | 0 | (0,0)(0,0)(0,1) |
| 09.bak | 07-16 19:15 | 5 loading | 0x7b | 0/1 | 1/2 | 0 | (0x91,0) |
| 10 | 07-18 10:48 | 4 in-room | 0x86 | 0/0 | 1/2 | **0x65** | (0,0)(0,0)(0,1) |
| 10.bak | 07-17 08:09 | 4 in-room | 0x7b | 0/0 | 1/2 | 0 | (0,0)(0,0)(0,1) |

\* slot 05 is IN-GAME: the lobby overlay is unloaded, so `0x6ca960`/cb-table/create-gate reads
are repurposed memory (§7). 04.bak (07-12, screen 3) omitted rows match the pattern above.

## 2. FINDING A — the red RULE screen fully explained from one state, and the fix verified byte-against-byte

Slot 02 (the owner's "rules are red" state, 08-08 19:35, screenshot = RULE screen with Room
Title / Password / No. of Players / Waiting Time all red, Scenario "(null)", Character Kevin):

**Observation (slot-02 memory):**
- Downloaded area blob at `*0x368474 = 0x361a70`; **every area's rule block (`rec+0x16c`) =
  `b0 81 00 00 … 00`** — exactly what OBAREA-V3 serves (verified: in-process serialize of
  `createV1ObservedAreaTable()` V3 → `b081` + zeros, byte-identical).
- Decode per RULES-MASK-RE §2.3: byte0 `0xb0` → players row present, **changeable-bit b6 = 0 →
  RED**; byte1 `0x81` → waiting row present, **b6 = 0 → RED**, 1 choice; group-1 count (+0x02)
  = **0** and group-2 count (+0x2b) = **0** → NO other rule rows exist. Builder table
  `0x6d2296` = 2 rows, flags 0 — matches the render exactly.
- `0x6ff2b0=1, 0x6ff2b1=0` → the create-slot unlock never advanced → **Room Title and Password
  red** (the `0x6ff2b1` lock, the separate known layer).
- Scenario ring value `0x6c4b96 = 0xff` (none) with **savedata bitmap `0x341AD0` = all zero** —
  V3's area-2..10 masks (`+0x14`=`+0x18`=`0x0f00…`) AND zero savedata → empty ring → "(null)".

**Fix check (Observation, in-process):** the OBAREA-V5 table (deployed to the Pi today) serves
`f3 e2 01 01 03 01 01 …` — byte0 `0xf3` (b6 SET → players WHITE, 4 choices, default 4-player),
byte1 `0xe2` (b6 SET → waiting WHITE, 5 choices), group-1 count ≥1 with present+changeable
descriptors, and masks `+0x14`/`+0x18` = `0x7ff` on enabled areas (scenario ring populated with
zero savedata). **V5 changes exactly the bytes slot-02 proves were wrong.** Remaining to MET:
a rig create-screen look (version bump forces the re-download per `FUN_001c4960` version
compare) — and `0x6ff2b1` (title/pw) is NOT touched by V5; that unlock is the create-slot
handshake layer, observed reaching 1 (slot 03) and **3** (slot 04) later in the flow.

## 3. FINDING B — callback-slot address map, extended from live installs (Observation)

Diffing `conn+0x548+slot*4` across the 19 lobby states:

| slot | address | when installed | names |
|---|---|---|---|
| 0x13 | `0x5bba20` | always | op10 game-channel dispatcher (known ✓) |
| 0x15 | `0x5bc360` | always | (constant; un-RE'd) |
| 0x16 | `0x5c0060` | after first room flow | in-room handler (new) |
| 0x17 | `0x5bf740` | nearly always | (known family) |
| 0x18 | `0x5c0ae0` | after first room flow | member-list query consumer (v1 notes' "slot 0x18") |
| 0x1f | `0x5c3a40` | after first create | op28 sel-4 create cb (known ✓) |
| 0x22 | `0x5c05c0` | room-ENTER waits (05.bak, 09.bak) | **sel-6 room-class completion cb — the join ladder's target slot, address now known** |
| 0x23 | `0x5bfe90` | lobby-leave waits (01, 02, 02.bak, **07**) | sel-7 lobby-class cb (known ✓) |
| 0x24 | **`0x5c06c0`** | **exit waits only (07, 07.bak, 09.bak)** | **sel-7 ROOM-class completion cb — closes snap-re ranked unknown #1 (FUN_005c06c0, absent from all dumps) as the literal installed address** |
| 0x25 | `0x5c29c0` (04, 05, 09.bak) / **`0x5c06b0`** (07, 07.bak) | context-dependent | **sel-8 STAT cb has TWO consumers: roster-SM STAT (`FUN_005c29c0`) vs exit-STAT (`FUN_005c06b0`, snap-re unknown #2) — slot 0x25 is re-installed per flow** |
| 0x26 | `0x5bd8c0` → `0x5c39e0` | swaps after first create | two-phase consumer (new) |
| 0x28 | `0x5c7d20` | 01.bak, 03 | per-query retry timer family (matches `FUN_005c7d40` prior RE) |
| ≥0x33 | small ints (`0x10000`, `0x3010200`…) | — | NOT pointers: the cb table ends below 0x33; this region is packed counters/flags (boundary note) |

In state 07 (the park) **both 0x23 and 0x24 are installed** — the mis-routed reply ran 0x23's
`FUN_005bfe90` while 0x24's `FUN_005c06c0` (the armed wait) never fired. Direct memory image of
the confirmed wrong-slot dispatch.

## 4. FINDING C — tag census and the July-vs-August exit-park variant (Observation + Inference)

Latched-tag (`0x6cbc7c`) values observed: `0x20, 0x21, 0x2f, 0x43, 0x7b, 0x86, 0x91`; armed
pending tags: `0x21, 0x43, 0x70, 0x7b, 0x86, 0x91`. So the tag space is a per-flow FAMILY id,
not a 2-value room/lobby pair — 0x43 (lobby-leave family), 0x70 (room/create family), 0x7b/0x86
(in-room query families), 0x91 (game-start family), 0x21 (area/enter family), 0x2f (rule/create
screen family), 0x20 (post-game). Inference: `FUN_005c2080(n)` is a family-id map with at least
these values; the two C3-relevant points stay Confirmed (armed 0x70 vs latched 0x43 in state 07).

**The July park (07.bak) differs from August (07):** same armed `(0x70,0)` + room-ctr=1, but
latched tag `0x7b` (not 0x43) and lobby handle **1** (not zeroed) — in July the lobby-leave cb
did NOT run (V1-era server answered differently); the wait still starved. Inference: the park
has two historic flavors — (a) reply mis-routed to slot 0x23 (August/v2: 0xB020 answer), (b) no
matching completion at all (July/v1 variant). Both are cured by the same rule (answer sel-7
with the request's channel bits so slot 0x24 fires); the channel-echo fix addresses (a)
directly and (b) by construction.

## 5. FINDING D — the create-unlock ladder is observed live (Observation)

`0x6ff2b1`: **0** on the red RULE screen (02) → **1** in-room post-create (03) → **3** at
press-start/loading (04). The known "0x6ff2b1 1→3 unlock layer" is real and DOES complete by
game start on the V3-era server; what never unlocked on the RULE screen itself was 0 → 1.
(All with savedata bitmap zero — unlocks are not savedata-gated on this path.)

## 6. Bonus observations

- Slot 06 and 10 (July in-room states) carry **`0x25b790 = 0x65`** (alloc-fail latch) with clean
  pending tables — the July deep-stall states died with the pool latch set, consistent with the
  G2-era model.
- 08.bak (July 16 exit-freeze aftermath) = the "connection error" dialog with cb table EMPTY and
  a stale `(0x21,3)` pending — full teardown ran; pktid 3 says the area-enter family had reached
  its 4th transaction (the historic "4th reliable txn" jam point).
- State 01 (Area Select, 08-08): latched 0x43 with lobby-ctr=1 — a lobby-leave completed there;
  benign baseline for the tag layer.

## 7. Caveats (methodology)

- **In-game states (slot 05) repurpose lobby globals** — the game overlay replaces the lobby
  overlay, so `0x6ca960`, the cb table, and create gates read as junk there. Only lobby-overlay
  states are cited above.
- Savestate == the moment of SAVE, not the moment of failure; mtimes anchor each to the
  RIG-SESSION-1 timeline but a state can be seconds after the interesting transition.
- The slot 0x33+ "values" are not validated as a table at all — boundary noted, nothing claimed.

## 8. Ghidra-gated unknowns closed or narrowed by this sweep

| snap-re ranked unknown | status now |
|---|---|
| #1 `FUN_005c06c0` (slot 0x24 room-leave cb) | **address + install context observed** (07/07.bak/09.bak); body still undecompiled — the tag it writes is inferable from §4 but unproven |
| #2 `FUN_005c06b0` (sel-8 exit-STAT cb) | **observed installed at slot 0x25 in exit states**; dual-consumer model new |
| #4 tag literals | **family census observed** (§4); `FUN_005c2080` arg→value map still Inference |
| join-ladder target slot 0x22 | **cb address `FUN_005c05c0` observed** |
