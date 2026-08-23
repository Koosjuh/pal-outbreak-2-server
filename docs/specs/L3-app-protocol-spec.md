# L3 — SN@P Application Protocol Specification (LIVING DOCUMENT)

**Purpose.** The graduation contract for the production application layer (`server/` L3: areas,
rooms, slots, populations, create/join). Same rules as the L1 spec: the PAL client binary + the
now-capturable client requests are the specification; Bioserver2 (KDDI) is a **structural reference
for intent only**, never wire ground truth. Each claim tagged ✅ Confirmed / 🟡 Hypothesis / ⛔
Rejected, with binary evidence, runtime observation, harness test, production implication.

Prereq: the L1 transport works (2026-07-02 milestone) — op49/op48 now transmit, so the client
finally emits the room/slot requests that were previously invisible.

Last updated: 2026-07-02. Scope of this revision: op49 (`LOID`/`STAT`) room-list query — request
layout (captured on the wire) + reply contract (from the client's parser).

---

## 1. The lobby hierarchy (from Bioserver2 reference — intent only) 🟡
Area → Room → Slot(game). PAL command families (shared app naming, KDDI wire not applicable):
Area: AREACOUNT/NAME/PLAYERCNT/STATUS/SELECT (0x620x). Room: ROOMSCOUNT/NAME/PLAYERCNT/STATUS/
ENTER (0x630x). Slot: SLOTCOUNT/TITLE/STATUS/CREATE (0x640x) + RULES (0x66xx). On PAL/SN@P these
manifest as UDP-9090 opcodes (op49 etc.), NOT the TCP 0x63xx ids — mapping is per-opcode RE below.

---

## 2. op49 — room-list query (`LOID` + `STAT`) 

### 2.1 Request layout ✅ Confirmed (captured on the wire 2026-07-02)
Run 2026-07-02_09-23-11, node 59286. op49 = SN@P opcode 0x0049, sent as a **coalesced** reliable
datagram (kind 0xF8/0xB0), body **plaintext** (tags readable). One captured frame (id 0x2d):
```
hdr: f8 3b 00 49 | 02 f8 07 d0 (token) | 00 00 00 2d (id) | 00 00 00 2b (ack) ; len 0x3b
body(@+0x10): 00 00 00 00 | 03 00 00 00 | "LOID" 01 00 00 00 00
              | "STAT" 21 | 00 08 00 00 | 00 08 00 00
              | "STAT" 21 | 02 00 00 00 | 02 00 00 00
(coalesced 2nd sub-frame follows: b0 3b 00 49 … same shape, id 0x24-ish)
```
Interpretation (Confirmed structure, 🟡 field meanings):
- body+0 = 0; body+4 = **term count = 3**; then 3 query terms.
- Term = 4-char **tag** + params. Tags seen: **`LOID`** (list of room IDs) with param `01`;
  **`STAT!`** (`STAT`+0x21) twice, with range params (`0x0800,0x0800` then `2,2`).
- Matches driver FUN_005c14a0 (LOID + STAT + STAT build) and its **4 sub-queries** (counter
  0x6cb9ec 0→3), each a separate op49 datagram (ids 0x2d..0x34 observed).
- **Bioserver2 map:** `LOID`≈ROOMSCOUNT/room-id-list; `STAT`≈room/slot status. (intent only.)

### 2.2 Reply contract ✅ Confirmed (client parser FUN_005c13e0)
Route: dispatcher FUN_001d9f78 op49 → slot 0x32 → FUN_005c3da0 (matches reply+0x0c == registered
query id) → **FUN_005c13e0**. Parser:
- **reply header byte[0]** = status: `0x00` success, `0x27` fail (→ 0x6cba05=2, abort). ✅
- **byte[1] / short[2]**: sub-query continuation — `if (byte[1]!=1 || short[2]==0) → 0x6cba05=1`
  (this sub-query done, advance). Our who=0xB0 reply yields byte[1]=0 → advances. ✅
- **body+8 (int)** = record count. Records start at body+0xc, **stride 0x28**. ✅
- **rec+0x14 (short)** = per-record **player count**, summed across records into `sRam006cf286`
  (= "In Lobby: N"). ✅
- Other rec fields (id, name, status) are **NOT read by FUN_005c13e0**. ⚠️ (see §2.3 gap)

### 2.3 GAP — what populates the room NAME/status display 🟡 Unknown (needs client observation)
- Display table 0x6c3030 (rendered) is filled by completion cb **FUN_005f7b30** from per-slot
  tables 0x6cf142 (status)/0x6cf154 (byte)/**0x6cf29a (name)**, count = `uRam006ce5c0` (=6, set by
  op49 driver init from the AREA slots 0x6fec04).
- **op49's consumer FUN_005c13e0 does NOT write 0x6cf29a/0x6cf142** — it only sums player counts.
  The op49 driver state0 **zeroes** the 0x6cf27c region (incl. 0x6cf29a). So room names are empty
  unless something else writes them.
- **Hypothesis:** room names/ids come from a **follow-up query** the client issues after op49 (the
  `LOID` reply may return ids that trigger per-id name queries), OR from the slot-create flow, OR
  the 6 displayed entries are empty AREA slots the user fills by creating a game (Area→Room→Slot).
- **Harness test (next):** answer op49 with `count=1, rec+0x14=playercount>0` and observe: does
  "In Lobby: N" change? does a room row render? does the client emit a NEW query (revealing the
  name path)? This is the decisive observation the binary alone can't settle.

### 2.4 Current server reply ✅ (working, empty)
`SNAP_ROOMLIST_REPLY=1` sends op49 reply with `count=0` → client advances (cursor unlocks) but
shows an empty list. Proven this session (op49 completed 4 sub-queries). To show a room, extend to
`count≥1` with records (§2.2 layout) — the `SNAP_ROOMLIST_COUNT` experiment.

### 2.5 Caution — 4 sub-queries accumulate
op49 fires 4 sub-queries; each reply runs FUN_005c13e0, which **adds** rec+0x14 to `sRam006cf286`.
So a naive `count=1, playercount=N` reply to all 4 sub-queries yields "In Lobby: 4N". The
LOID vs STAT sub-queries likely expect different record content; the reply may need to differ per
sub-query (subid). To be resolved by the §2.3 observation. 🟡

---

## 3. Next targets (after op49 room-list is understood)
- Room ENTER (post-list): the query the client emits when selecting a room.
- Slot list + CREATESLOT (create a game) — the host path; maps to op01 room-register (prior memory,
  re-confirm on SN@P).
- Area population (TCP 0x6205 AREAPLAYERCNT) driven by real session counts.
Each derived from the client request (now capturable) + validated by client reaction; Bioserver2
for field meaning only.

---

## 4. Room CREATE — blocked by scenario/modifier data (2026-07-02, user-observed)

User reached the in-lobby room-create flow (cursor now unlocked) and reported: **"users can create
rooms which I tried but I can't"** + **"scenario was null in room creation."**

### 4.1 Root cause — synthetic area blob omits scenario/modifier data ✅ Confirmed
- Our `0x6204` area blob (`snap_server.js buildAreaBlob`) sets name/desc/status but leaves the
  **modifiers field at record+0x16c ZEROED** (code comment: "modifiers (+0x16c, stride 0x3c) left
  zero for v1 (names-first)"). Per memory area-data-protocol-decoded, +0x16c links to the
  difficulty / "No. of Players" / scenario localized tables. Empty +0x16c ⇒ the client has **no
  scenario list** to assign to a new game ⇒ "scenario null" ⇒ create blocked.
- This is the **application-data boundary**: transport works, but room creation needs REAL area
  content (scenarios/modifiers), not synthetic AREA0001..6. Exactly the "we send fake stuff" limit.
- **Production implication (L3):** populate the area record +0x16c modifier/scenario structure with
  real File #2 scenario data (scenario id/name + difficulty + player-count options). Needs the
  +0x16c layout decoded (partially in area-data-protocol-decoded; complete it against the client's
  create/scenario parser).

### 4.2 op41 — room-phase sync opcode, currently UNHANDLED 🟡 Hypothesis
- Post-lobby (in the room) the client sends **op41** (`b0 98 00 41`, ~152B, **Blowfish-encrypted
  body**) every ~2-3s, on both the game token and a second token — 91 in 6 min, all falling to
  'unknown' (suppressed). Sender uses `FUN_001e180c(...,0x41,0)` (overlay `FUN_005ff4b0(...,0x41)`
  wrappers in the room/slot region). Likely room/member state-sync or the create/config channel.
- **Harness test (next):** decode op41's decrypted body (server has the conn key); determine whether
  it's presence/sync (ack-only) or a query the server must answer for create to proceed.

### 4.3 Next decode targets (ordered)
1. **Area +0x16c modifier/scenario layout** — the direct blocker for room create ("scenario null").
   Decode the client's scenario/create parser + populate real data.
2. **op41 body** — decrypt + classify (sync vs query).
3. The create/CREATESLOT request itself (what the client sends on confirm) + its reply.

---

## 5. Room CREATE (Free mode) — RULE screen, "Scenario (null)" (2026-07-02, screenshot + capture)

Screenshot: RULE screen (Free-mode room create) — fields: Room Title (empty), Password:"Impossible"
(garbage rule value), **Scenario: (null)**, Character: Kevin (populated from disc), Finish.

### 5.1 Finish is LOCALLY blocked by null scenario ✅ Confirmed (runtime)
User pressed Finish with Scenario=(null): **no create/CREATESLOT packet emitted** — only op41 sync.
⇒ the client validates scenario CLIENT-SIDE and refuses to send the create request until a scenario
is selected. So scenario data is a hard prerequisite; the create-request layout stays uncapturable
until the scenario field is populated.

### 5.2 Scenario + RULE data are server-supplied and missing ✅ Confirmed (behavior)
Character (Kevin) is disc-local and populates fine. Scenario is null and the RULE value
("Impossible" for Password) is garbage ⇒ both are SERVER-supplied app data we don't provide.
Bioserver2 intent map: SCENESELECT/SLOTSCENTYPE (scenario+type), RULESCOUNT/RULEDESCRIPT/RULEVALUE/
RULEATTRIB (rules) — on SN@P these arrive via tagged queries (§5.3).

### 5.3 op09 `USER` query — candidate scenario/rule fetch 🟡 Hypothesis
On the RULE screen the client sends **op09** (`b0 18 00 09`, plaintext body): 
`body: 00 00 00 27 | 0c 00 00 00 | 00 00 00 00 | "USER"` — a tagged query in the op49 LOID/STAT
family (tag = "USER"). Currently unanswered (falls to 'unknown'/suppressed). Likely the
user/scenario/rule data fetch that populates this form. NEXT: decode op09's client reply parser
(dispatcher slot for 0x09) + what tag(s) return scenario vs rule data, then answer with real File #2
scenarios (Wild Things / Underbelly / Flashback / Desperate Times / End of the Road) and rule set.
File #2 scenario list is fixed/known — the server just needs to deliver it in the right layout.

### 5.4 Next decode targets (updated)
1. **op09 `USER` (+ any scenario/rule tagged query) reply layout** — the direct unblock for
   "Scenario (null)". Decode the client parser (slot for op09), derive the reply, answer with the
   5 File #2 scenarios; validate the Scenario field populates on the RULE screen.
2. Then RULE values (RULESCOUNT-family) so "Password/rules" render correctly.
3. Then the create/CREATESLOT request (only capturable once scenario is set) + reply.

---

## 6. Area +0x16c modifier/rule region — LAYOUT DECODED (2026-07-02, subagents + FUN_005c2f40/2bc0/2d70)

Decoded from FUN_005c2f40 (reads blob 0x361a70 + box*0x1e4 + 0x16c) + renderers FUN_005c2bc0
(players/wait groups) + FUN_005c2d70 (difficulty/buffer groups). ✅ Confirmed layout, 🟡 exact
option-index values (validate on rig).

Region at blob **+0x16c** (per box, stride 0x3c):
- **+0x00 byte = "No. of Players" field** (packed): bits0-1 current value, bits2-3 min, bits4-5 max
  (FUN_005c2bc0: uVar3=(b>>2&3) min, uVar1=((b>>4&3)-min)+1 count, value=(b&3)-min). bit6/bit7 =
  changeable/flag (FUN_005c2f40 splits >>6&1, >>7&1).
- **+0x01 byte = "wait limit" field** (same packing).
- **+0x02 byte = difficulty-group count N1**; **entries at +0x03**, stride 4 = `[opt_index, value,
  enable(!=0), attribute]` → FUN_005c2d70 indexes localized table by opt_index*0x120.
- **+0x2b byte = buffer-group count N2**; **entries at +0x2c**, stride 4, same 4-byte format.
- Localized option tables: FUN_005c2e90(0)="No. of Players", (1)="difficulty control", FUN_005c2ad0()
  =buffer; per-option stride 0x120 (name +0, value-count +0x1f, values +0x20+i*0x20). Strings are the
  game's own (language-correct) — server supplies only the index/value/flag bytes.

Content model = Bioserver2 RuleSet (RuleSet.java): per-area rules {name, attribute(1=changeable/
0=fixed), value} + attributes[][] options. Normal = fixed defaults; Free = all changeable;
Nightmare/etc = specific flags fixed. Maps 1:1 to the +0x16c fields above.

**Current server:** buildAreaBlob (snap_server.js:159) writes name/desc/status, leaves +0x16c ZERO
=> RULE screen indexes uninitialized memory (garbage "Password: Impossible") + Scenario (null).

### 6.1 Decisive experiment (Model A vs B) — NEXT
Populate +0x16c with a valid rule set (derived layout + bioserver Free content), deploy, drive to the
RULE screen:
- Rules render sane AND scenario becomes selectable → **Model A** (area seeds scenario) — done.
- Rules render but scenario still (null) → **Model B**: scenario needs a separate per-slot scene-type
  reply (SLOTSCENTYPE 0x650A / SCENESELECT 0x6509 equiv on SN@P) — decode + answer that next.
Flag-gated; isolated from the working area-select render (which reads name/status, not +0x16c).

---

## 7. Character selection also blocked — same root (2026-07-02, user-observed + ISO strings)

User: "I should be able to select multiple characters" — only "Kevin" is selectable on the RULE
screen. Same root as scenario(null): the room-config block is uninitialized.
- ISO string "No available characters remain." (netwk 0xc7880) + "CHARACTER SELECT"/"Which character
  will you use?" ⇒ character AVAILABILITY is room-state/server-driven (Outbreak claims characters —
  no duplicates in a room). Character names/models are DISC-local (not in network strings, like
  scenario titles). ⇒ server supplies availability; disc supplies the roster.
- Kevin shows = disc default (first entry); the rest need server room-config that we don't send.
⇒ Scenario(null) + garbage rules + only-Kevin are ONE problem: the server populates no room-config.
Decisive +0x16c experiment (§6.1) should be observed for ALL THREE (rules render? scenario
selectable? full character roster?). Whatever stays stuck → its own per-slot query (Model B).
