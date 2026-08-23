# PAL Outbreak File #2 (SLES_533.19) — UNIFIED LOBBY ARCHITECTURE (2026-07-03)

One coherent model of the online lobby state machine + data flow, from Server-Select through
Create-a-Game, synthesised from the PAL client decompile and the 8 prior RE docs. Ground truth =
`analysis/claude-helper-module-full-2026-05-29.txt` (netwk overlay), `…game-module-full…`,
`…netwk-strings…`. Grades: **Confirmed** (decompile file:line) / **Likely** / **Hypothesis**.

**Two headline results (both previously "needs live PINE", now pinned statically):**
- **2a RE-ENTRY STALL** — re-entry uses a *different* area-select variant (`FUN_005ad680`, auto-select)
  than first entry (`FUN_005ad030`, wait-for-X). Both gate op06 on box-enable-byte `0x6c386e+box*0x15c
  == 3`, which the op48 consumer `FUN_005c1220` copies from the **local** area-blob `+0x14c` status.
  The op48 flood = the app retry timer resending op48 because the **re-entry op48 reply is never
  consumed** (`uRam006cb9dd` never set). Fully mapped; residual is reliable-delivery of that reply.
- **2b SCENARIO SOURCE** — **DECISIVELY PINNED.** The create-screen scenario list is built by
  `FUN_005fe300` (helper:50200-50230) from the **area record `+0x03` byte** (a scenario-group enable
  BITMASK, accessor `FUN_005baf20`, helper:11886) plus resident EE tables `0x341ac8`/`0x341ad0`. Our
  server leaves `+0x03 = 0` ⇒ zero scenarios enabled ⇒ scenario index invalid ⇒ title lookup null ⇒
  **"(null)"**. **Fix = write area record `+0x03` (and `+0x04`) in the `0x6204` area blob.** No poke,
  no client patch.

---

## 1. THE STATE MACHINE

Top navigator = `FUN_005acab0` dispatching **`cRam006c4b90` (screen byte0)** (helper:2325-2364):
`0`=title/menu, `1`=**Area-Select** (`thunk_FUN_005ace00`), `2`=**in-area Lobby** (`FUN_005f76f0`),
`0xe`=**Room interior / slot list** (`FUN_0062d5e0`), `7`=log screen, `4`/`5`/`0xc`=others. **Confirmed.**

Area-Select sub-navigator = `FUN_005ace00` dispatching **`0x6c4b9e` (obj+0xe)** (helper:2484-2496):
`0`→`FUN_005acea0`(init), `1`→`FUN_005ad030`(**first-entry select, wait-for-X**),
`2`→`FUN_005ad530`(→lobby transition), `3`→`FUN_005ad680`(**re-entry auto-select**). **Confirmed.**

```
 SERVER-SELECT  (TCP 10127; entry list 0x365xxx via 0x6501-0x6504; area grid via 0x6203/0x6204)
   │  X on a server  ── emits TCP session/area-list request; server streams 0x6204 chunks into
   │                    the area blob 0x361a70[box*0x1e4]  (name+0x1c, status+0x14c, +0x03 scen mask…)
   ▼
 AREA-SELECT (screen byte0=1)
   FIRST ENTRY : FUN_005acd60 sets byte0=1, 0x6c4b9e=0 → FUN_005acea0 → 0x6c4b9e=1 → FUN_005ad030
   RE-ENTRY    : FUN_00601700 (when cRam006c4fbb==0x22) → FUN_005acda0 sets byte0=1, 0x6c4b9e=3,
                 preselect uRam006c45f8=uRam00874fd4 → FUN_005ad680  (helper:2423-2439, 52233-52247)
   │  op48 "NAME" grid query armed by FUN_005bf340 → driver FUN_005c0ff0 (helper:16580),
   │     reply consumer FUN_005c1220 registered at id-table 0x700630
   │  X on an area  ── gate FUN_005ad350(box)==1 (needs box enable byte 0x6c386e+box*0x15c==3)
   │                   → FUN_005ad030 case4 / FUN_005ad680 case3-4 → FUN_005bfa70  == op06 AREA-CONFIRM
   │     server reply: op06 → op28/sel6 → slot 0x21 → FUN_005bfb40 (sets uRam006cbc84=0)  [Confirmed]
   │  Triangle       ── FUN_005ad350 +0x11==2 path returns -1 (cancel) OR back to Server-Select
   ▼
 (transition FUN_005ad530: arms op49 room-list via FUN_005bfbe0→FUN_005c14a0; byte0→2)
   ▼
 IN-AREA LOBBY (screen byte0=2, FUN_005f76f0; nested SM bytes 0x6c4b91 / 0x6c4b9e — lobby-buttons doc)
   │  state0 FUN_005f78c0 arms op49 LOID/STAT room-list; reply FUN_005c3da0→FUN_005c13e0→FUN_005f7b30
   │     server reply: op49 → slot 0x32; sums rec+0x14 → "In Lobby:N"; fills rows 0x6c3030   [Confirmed]
   │  highlight area/tab ── cmd-0x0a modifier query (FUN_005c3190, cb FUN_005c3370, slot 0x18)
   │     server reply: who=0xA0 status=0 count=0 → uRam006cba55=1 → panel 0x6d2297 draws   [Confirmed]
   │  cursor==0 / Triangle ── EXIT AREA: FUN_005f8220→FUN_005bfd80 (op07/op08), sets 0x6ff2b1=0
   │     server reply: op07/08 → op28/sel7+8 (SNAP_LOBBY_LEAVE_REPLY) → back to AREA-SELECT (re-entry) │
   │  cursor 1..N-1 (a room row) ── ENTER ROOM: FUN_0062d4e0 → screen byte0=0xe               │
   │  cursor==roomcount+k ── icons A-D (buddy/list/text/log; lobby-buttons doc §1)            │
   ▼
 ROOM-LIST / SLOT-LIST (screen byte0=0xe, FUN_0062d5e0 → FUN_0062d950 dispatch on obj+0x10)
   │  case2 FUN_0062dc40 (30 slot rows 0x6c0760 stride 0x15c; status+0x0e)                    │
   │     Vacant selected (status1) → case5 → FUN_005c0750(0x62ed30) == CREATE session (type 0x70)
   │     Occupied (status3)        → case2 → FUN_005c04f0(…,0x6970a2,0x62ec90) == ENTER (type 0x6e)
   │  case3 FUN_0062de90 (parses 0x29555-byte room/slot blob → 0x6970a0 stride 0x14a8)        │
   │  Room interior also runs FUN_005fe300 which BUILDS the per-slot scenario array (see §2b) │
   ▼
 CREATE "RULE" screen  (FUN_005fada0 obj+0xf tree / FUN_0062dc40 case0 / FUN_0062de90 case5)
   │  init: config struct @ (screen_obj + 0x1e50, 0xd4 bytes); memset + func_0x007de670;
   │        seed +0x1f18←scenario, +0x1f1a/1c←slot flags, +0x1f1e←bRam00343625; copy→0x7004d0;
   │        FUN_005bd940 opens a "prepare" session sending 0x7004d0 (cb 0x5bd8c0)             │
   │  fields: Scenario (null → blocker 2b), Room Title/Password (keyboard, red-locked behind scenario),
   │          No.of Players/Wait/Difficulty (area +0x16c rules), Character (Kevin default)    │
   │  Finish ── FUN_005c0750 create (type 0x70 + config), reply cb FUN_005c05c0 latches in-room
   ▼
 (created / joinable room)
```

BACK edges (Triangle): Area-Select→Server-Select (FUN_005ad350 +0x11 path / FUN_005ad030 case7 reads
pad 0x210); Lobby→Area-Select = **EXIT AREA op07/op08** (re-enters via the FUN_00601700 dirty path,
see 2a); Room-List→Lobby and RULE→Room-List = local `func_0x001b0140(1)` + obj+0xe/0xf reset
(FUN_005fb060 case2 reads pad 0x210). **Confirmed** senders; op-numbers of op07/op08 per server.

---

## 2a. RE-ENTRY STALL — resolved statically

### The two variants (root of the asymmetry) — **Confirmed**
- **First entry**: `FUN_005acd60` → `0x6c4b9e = 0` → `FUN_005acea0` → `=1` → **`FUN_005ad030`**
  (helper:2404-2417, 2519-2521). `FUN_005ad030` is **wait-for-X**: case2 reads pad `0x10`, only then
  case3 calls the select gate. (helper:2595-2658)
- **Re-entry** (after EXIT AREA): `FUN_00601700` fires when `cRam006c4fbb == 0x22` →
  `FUN_005acda0(0x6c4b90, uRam00874fd4)` → `0x6c4b9e = 3` + preselect `uRam006c45f8` → **`FUN_005ad680`**
  (helper:2428-2439, 52233-52247). `FUN_005ad680` is **auto-select**: case2 calls the select gate
  **every frame** with the preselected box, no X needed. (helper:2868-2883)

### The op06 gate — **Confirmed**
Both variants emit op06 only when the select gate **`FUN_005ad350(box)` returns 1**
(helper:2645-2657 / 2871-2882 → `FUN_005bfa70` == op06 area-confirm, cb 0x5bfb40, helper:15548-15571).
`FUN_005ad350` first-entry branch (helper:2716-2745):
```
if (*(char*)(box*0x15c + 0x6c386e) != 3) return -1;   // BOX ENABLE BYTE must be 3  (helper:2719)
… (lock-byte +0x01 confirm-dialog dance) …
cRam006c45f8 = box+1; return 1;                        // SELECTED → op06 fires  (helper:2744)
```
The enable byte `0x6c386e+box*0x15c` is written by the grid builder `FUN_005ad890`
(helper:2940 `FUN_005bf9e0`) from display status `0x6ce5f0`, which the **op48 consumer** sets:
`FUN_005c1220` (helper:16700-16701) → `*(box*0x144+0x6ce5f0) = FUN_005c2ab0(box)` and
`FUN_005c2ab0` (helper:17654-17661) = **area-blob `0x361a70+box*0x1e4 + 0x14c`** (`FUN_005c2a40`,
helper:17606-17610). So **box selectable ⟺ op48 reply consumed AND area-blob `+0x14c == 3`.**

### Why the flood, and the dirty state — **Confirmed mechanism / Likely locus**
`FUN_005c1220` runs only if the op48 reply is (a) delivered in-window and (b) id-matched:
`FUN_005c3cf0` (helper:18378) requires `reply[+0xc] == query handle` stored at `0x700630` (one-shot,
cleared on match) and consumer slot `0x700634 != 0`. On success it sets **`uRam006cb9dd = 1`**
(helper:16678). The op48 driver `FUN_005c0ff0` retransmits/re-arms until `uRam006cb9dd` is set; the
per-query retry timer is `FUN_005c7d40` (reload `0x368490`, helper:20976). **op48 floods ⇔ the
re-entry op48 reply is never consumed ⇔ `uRam006cb9dd` stays 0.** Because `FUN_005ad680` auto-selects
every frame and `FUN_005ad350` keeps returning -1 (box enable ≠ 3), no op06 is ever emitted — exactly
the reported symptom.

**What is left dirty:** `0x6c4b9e = 3` (the auto-select variant) itself is by design (re-entry
auto-confirms the preselected area). The blocking condition is that the op48 reply is not consumed on
re-entry. Two server-testable causes, ranked:
1. **[Likely] Reliable-delivery desync after EXIT AREA.** op48 reply is a reliable frame (who 0xB0 =
   0x8000|0x2000|0x1000). The server stamps `reply[0x08] = ctx.txSeq` (game_udp_server.js:559-561).
   After op07/op08 the client's reliable recvBase can reset while the server's `txSeq` keeps climbing
   → the re-entry op48 reply lands out-of-window → dropped → app retry floods op48. This is the same
   class as the known "ACK'd but not delivered" wall, applied to a *reply* after a window reset.
2. **[Hypothesis] id-echo/registration collision.** If `func_0x001e094c` returns -1 on re-entry
   (pool/window), `FUN_005c3e50` (helper:18431) does NOT register the consumer (`0x700634` stays 0) →
   even a delivered reply fails the `!=0` match. Ties the stall to conn+0x520 pool state after back-out.

**Is it server-fixable?** The app-level gate is a **client latch only in the sense that `0x6c4b9e=3`
auto-select is intended** — it is NOT the blocker. The blocker (reply not consumed) is a
**transport/delivery** problem that IS server-influenceable (correct in-window txSeq + per-id ack
through the back-out). The deployed fixes (`sawAreaConfirm` reset on op07/08 line 1085-1089; per-id
op48 ack) address content/pool but not the reliable-window resync across EXIT AREA. **Concrete server
fix:** on the first op48 query after an op07/op08 leave, resync the reply's `reply[0x08]` txSeq to the
client's current expected seq (derive from the inbound query's `wire+0x08`/`+0x0c` ack state) instead
of a monotonic counter, so the re-entry AREA reply is in-window. **Verify:** PINE-watch
`uRam006cb9dd` (0→1 on consume) and box status `0x6ce5f0` (→3); Pi-log/pcap that the re-entry op48
reply is ACK-consumed (op48 flood stops); screenshot the second area confirming (op06 on wire).

**Grades:** op06 gate + variant asymmetry + status source **Confirmed**; flood=reply-not-consumed
**Confirmed** (mechanism); delivery-desync as the specific cause **Likely**; pool/id-collision
**Hypothesis**.

---

## 2b. SCENARIO SOURCE — resolved statically (supersedes "not resolvable from static dumps")

### The create-config struct — **Confirmed**
Base = **screen_obj + 0x1e50**, size **0xd4** (helper:48339-48349, 80637-80645, 80793-80803). At
RULE-screen init it is memset, then `func_0x007de670` inits bytes 0..0xc7, then six per-room fields
are seeded (struct offsets = absolute − 0x1e50):

| struct off | abs off | seed source | note |
|---|---|---|---|
| **+0xc8** | +0x1f18 | **`obj+0x1c[sel]`** (FUN_005fada0:48343) / `uRam006c4b9c` (FUN_0062dc40:80641) | **SCENARIO INDEX** |
| +0xca | +0x1f1a | `obj+0x1a[sel]` (signed char) | scenario type/flag |
| +0xcc | +0x1f1c | `obj+0x1b[sel]` (signed char) | scenario sub-variant |
| +0xce | +0x1f1e | `bRam00343625` (global) | character/lang default |
| +0xd0 | +0x1f20 | 0 or 1 (context flag) | — |
| +0xd2 | +0x1f22 | 0 | — |

`sel = sRam006c4b94` (selected slot). The whole struct is copied to global **0x7004d0** (0xf0) and
**sent to the server** as the create-session app payload (`FUN_005bd940`:13734-13743 →
`func_0x001de470(…,0x7004d0,0x5bd8c0)`). **Confirmed.**

### The scenario array writer — **Confirmed** (this is the answer)
The per-slot arrays `obj+0x1a/0x1b/0x1c` (base `param_1+0x1a`, **stride 4**, indexed by `sel`; absolute
`0x6c4baa/bab/bac + sel*4`) are populated by **`FUN_005fe300`** (helper:50183, called from
`FUN_0062d4e0`/`FUN_005fa190`/`FUN_005f91f0` — the room-enter/room-list path):
```
func_0x00106b60(param_1 + 0x1a, 0, 0x400);          // clear the array (256 entries × 4)   :50200
uVar2 = FUN_005baf20(bRam006c45f8 - 1);             // = AREA RECORD +0x03 byte (bitmask)   :50202
for uVar7 in 0..7:                                   // 8 scenario groups
   if (uVar2 & (1<<uVar7)) {                          // bit uVar7 set ⇒ group enabled       :50206
      *(entry + 0x1a) = 0;  *(entry + 0x1b) = 0;
      *(entry + 0x1c) = uVar7;                        // SCENARIO INDEX written here          :50212
      mask = *(byte*)(uVar7 + 0x341ac8);              // resident sub-scenario mask table
      for sub in 0..3: if (mask & (1<<sub)) add variant entry (+0x1b = sub+1)                 :50219-21
   }
// second pass uses FUN_005baf70(area-1) = AREA RECORD +0x04 with table 0x341ad0             :50230-50246
```
`FUN_005baf20(n)` = `*(area_base + n*0x1e4 + 3)` (helper:11886, **area record `+0x03`**).
`FUN_005baf70(n)` = `area_base + n*0x1e4 + 4` (helper:11903, **area record `+0x04`**). `bRam006c45f8`
= confirmed area (box+1, set by FUN_005ad350:2744). **Confirmed.**

### Why "(null)" — **Confirmed cause**
Our `snap_server.js buildAreaBlob()` writes only area-record `+0x1c/+0x4c/+0x14c/+0x16c`; **`+0x03`
and `+0x04` are left 0**. So `FUN_005baf20 == 0` ⇒ no scenario bit set ⇒ `FUN_005fe300` writes **zero
scenario entries** (array stays memset) ⇒ `obj+0x1c[sel] = 0` with **count 0** ⇒ the RULE-screen
scenario index is out-of-range ⇒ the title accessor `func_0x001b6950(idx)` returns null ⇒ renderer at
helper:49736-49755 draws nothing / the "(null)" literal. Character works because `bRam00343625` +
resident char table give a valid default; scenario has **no enabled set at all**. **Confirmed.**

### The exact fix — **Confirmed field, Likely values**
Server must populate, in the `0x6204` area blob, per area record:
- **`+0x03` (1 byte) = scenario-group enable bitmask** — bit N (N=0..7) enables scenario group N.
- **`+0x04`** = the companion field FUN_005baf70 reads (second scenario pass w/ table 0x341ad0).

File #2 scenario groups (Bioserver intent, verify indices on rig): 0=Wild Things, 1=Underbelly,
2=Flashback, 3=Desperate Times, 4=End of the Road (+ Elimination/Showdown for areas 8/9). A first
test: set `+0x03 = 0x1F` (enable groups 0-4) on a Free area and watch the scenario field flip from
"(null)" to a title + Room Title/Password/Character unlock. **The scenario byte offset (`+0x1f18`
create-config) is data-bound; its true source is area `+0x03`/`+0x04` — a pure server data change.**

**Verify:** PINE-watch `0x6c4bac+sel*4` (scenario index array, should become non-zero set) and the
area record `+0x03`; screenshot Scenario non-null. Keep PINE light (observer effect). **Grades:**
`+0x03`/`+0x04` as the source **Confirmed**; exact File#2 bit→scenario mapping **Likely/rig**.

---

## 3. DATA PROVENANCE TABLE

| Field (screen) | Source | Renderer / consumer | EE address | Server-influenceable? | Grade |
|---|---|---|---|---|---|
| Area name | area blob `+0x1c` | grid `FUN_005affb0`; display `FUN_005c0ff0` | 0x361a70+box*0x1e4+0x1c → 0x6ce5f2 → 0x6c3878 | YES (0x6204/buildAreaBlob) | Confirmed (helper:16631,4911) |
| Area **description** `+0x4c` | area blob `+0x4c` | **none — dead pipeline** | 0x6ce616→0x6c38b9 (write-only) | **NO renderer** | Confirmed (area-desc doc §4) |
| Area status (grey/selectable) | area blob `+0x14c` | `FUN_005c2ab0`→0x6ce5f0→enable 0x6c386e | +0x14c | YES; **==3 gates op06** | Confirmed (helper:17660,2719) |
| "In lobby: N" | op49 reply Σ rec+0x14 | `FUN_005c13e0` | sRam006cf286 | YES (op49) | Confirmed (helper:16735) |
| Room rows (name/status) | slot-0x13 blob + op49 head | `FUN_005f7b30`; rows 0x6c3030/0x6c0760 | 0x6cf29a name (writer=GAP), 0x6c076e status | Partial (head via op49; name via slot-0x13) | Confirmed/Gap |
| No. of Players / Wait / Difficulty | area blob `+0x16c` (0x3c sub-rec) | `FUN_005c2f40`→panel 0x6d2297 | +0x16c | YES (per-area-rulesets doc) | Confirmed |
| Friendly Fire / Nightmare / Infinity | area blob `+0x16c` diff entries [opt,val,en,attr] | `FUN_005c2d70` | +0x16c; opt 5=NM,6=INF | YES | Confirmed fmt / Likely idx |
| **Scenario** | **area record `+0x03`/`+0x04`** → `obj+0x1c[sel]` → config `+0x1f18` | `FUN_005fe300`→`func_0x001b6950` | 0x6c4bac+sel*4; title=disc | **YES — write `+0x03`** | Confirmed (helper:50202,11886) |
| Character (Kevin) | config `+0x1f1e` = `bRam00343625` + resident table | RULE renderer | +0x1f1e | default resident; server sets pick on create | Confirmed default |
| Room Title / Password | keyboard entry (OSK) | `FUN_005fb270`/`FUN_005fb060` | key cRam006c462a | local input; red-locked behind scenario | Confirmed keyboard |

Modifier panel gate: cmd-0x0a reply who=0xA0/status0/count0 → `uRam006cba55=1` (op0c-modifier doc). **Confirmed.**

---

## 4. SERVER CONTRACT (ordered, minimal, to drive one client Area-Select → created room)

Cross-ref = `server/game_udp_server.js` (UDP 9090) / `server/snap_server.js` (TCP 10127).

1. **Area blob (TCP 0x6204)** — per area record: `+0x1c` name, `+0x14c=3` status *(have)*,
   `+0x16c` rules *(have, SNAP_AREA_MODIFIERS)*, **`+0x03` scenario bitmask + `+0x04` companion
   *(MISSING — blocker 2b)*.** `snap_server.js buildAreaBlob` writes only +0x1c/+0x4c/+0x14c/+0x16c.
2. **op48 grid NAME reply** — AREA activation records (name ends "01".."0N"), `reply[0x10]` echoes
   request_id, `reply[0x08]=txSeq` in-window *(have, SNAP_AREA_OP48)*. **On re-entry (after op07/08)
   resync txSeq to client's expected seq *(MISSING — blocker 2a)*.** game_udp_server.js:501-584,559-561.
3. **op06 area-confirm** — op28/sel6 → slot 0x21 → FUN_005bfb40 *(have, SNAP_AREA_CONFIRM_REPLY;
   sets s.sawAreaConfirm line 1061)*.
4. **op49 room-list** — slot 0x32, sum rec+0x14 for head count *(have, SNAP_ROOMLIST_REPLY)*.
5. **cmd-0x0a modifier** — who=0xA0/status0/count0 *(gap unless SNAP_MODIFIER_REPLY; op0c-modifier doc)*.
6. **EXIT AREA op07/op08** — op28/sel7+8; **reset s.sawAreaConfirm** *(have, line 1085-1089)* — but
   this alone does not resync the reliable window (see 2a #1).
7. **ENTER (type 0x6e) / CREATE (type 0x70) session-open** — accept, reply `byte0=0` (+`reply+0xc`
   id echo) so FUN_005c05c0 latches in-room *(FUN_005c04f0 accept known)*. Room handle table `0x6fee68`
   writer still a GAP (lobby-rooms §6.2).
8. **Slot-0x13 (opcode 0x10) room register** — to show a created slot non-Vacant to others (subcmd
   1/2/6 → 0x6fc2d8/0x7006d4/name tables). *(GAP — needs registry)*.

---

## 5. WHAT'S CLIENT-LIMITED (stop chasing)

- **Area free-text description `+0x4c`** — loaded to 0x6c38b9 but **no renderer reads it** in this
  build. No server payload can display it. (Confirmed, area-desc doc §4.)
- **Scenario TITLE strings** ("Wild Things"…) — disc/scene resource, absent from every dump. The
  server supplies the scenario *index/bitmask* (`+0x03`); the *titles* are the disc's own tables
  (`func_0x001b6950`). We cannot change the words, only which indices are offered. (Confirmed.)
- **`0x6c4b9e=3` re-entry auto-select** — intended client behavior, not itself the bug; do not try to
  force first-entry (`FUN_005ad030`) on re-entry. (Confirmed.)
- **Character/Scenario/Room-Title as client-initiated echoes** — the client picks and sends; the
  server records/acks, it does not push a list (except the scenario *enable set* via `+0x03`).

---

## 6. NEEDS FRESH GHIDRA (prioritised)

1. **`func_0x001b6950` / `0x341ac8` / `0x341ad0`** (game module 0x1b6950) — the scenario title
   accessor + resident group/sub masks — to confirm the File#2 bit→title mapping for `+0x03`/`+0x04`.
2. **Room handle-table `0x6fee68` writer** — so ENTER/CREATE sessions have a valid handle.
3. **`0x6cf29a` room-name writer** — the op49/slot-0x13 name path (GAP) for real room rows.
4. **Reliable recvBase reset on EXIT AREA** — confirm the client zeroes its receive window on op07/08
   (closes 2a #1: needs the SN@P session teardown path around FUN_005bfd80).

---

## 7. HIGHEST-LEVERAGE NEXT EXPERIMENT

**Write area record `+0x03` (scenario bitmask) in the 0x6204 blob** (start `+0x03=0x1F` on the Free
area, `+0x04=0`), gated behind a new `SNAP_AREA_SCENARIO` flag in `snap_server.js buildAreaBlob`.
- Hypothesis: `+0x03` seeds `FUN_005fe300` → the create RULE screen's Scenario flips from "(null)" to
  a title and Room Title/Password/Character unlock.
- Verify: PINE `0x6c4bac` (scenario index array non-zero) + area `+0x03`; screenshot; Pi-journal/pcap
  the enriched blob delivered in-order. Rollback: unset the flag.
- If Scenario populates → blocker 2b closed (create becomes reachable); then capture the type-0x70
  CREATE payload (previously uncapturable) to RE the registry. If not → area `+0x04` / op49 record
  scenario byte is the carrier; pivot per §6 #1.

(2a and 2b are independent; 2b is the higher-value unblock — it opens Create. 2a gates a *second*
area entry and is a transport-resync task best done alongside the L1 window work.)
