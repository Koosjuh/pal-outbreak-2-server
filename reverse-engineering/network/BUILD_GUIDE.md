# BUILD_GUIDE — implementing the multiplayer server from the corpus

**Purpose:** the decoding is done. This is the bridge from the RE corpus to a server implementation:
for each multiplayer flow, the exact message sequence the **client** drives, what the **server** must
send/expect, the packet fields, and the reconstructed client functions that prove it. Every claim links
to a function record (`functions/<subsystem>/<addr>_*.md`) or the packet/subcommand indexes. Confidence
is per-record; runtime-Confirmed items are the safe foundation.

> Read with: `protocols/PACKET_INDEX.md` (opcode→builder/parser/handler), `protocols/SUBCOMMAND_INDEX.md`
> (op10/op28 sub-selectors), `structures/structure-layouts/` (wire structs), `SUBSYSTEM_MAP.md`.

---

## 0. Transport contract (SN@P reliable UDP :9090) — build this first
The app protocol rides a custom reliable layer. The server MUST honor it or nothing above works.
- **Framing:** every packet ends with trailer `ba 47 66 11`; header carries who-byte (bit `0x8000`
  reliable, `0x2000` set, `0x1000` DATA), 10-bit length, opcode word (`subSel<<8 | opcode`), seq.
  See `snap_flush_send` (0x1d6468), `snap_packet_enqueue_send` (0x1e180c).
- **Reliability:** in-order delivery with a reorder window. **The client ACKs an inbound reliable
  segment only if `msgSeq >= its expected-seq`** (reorder gate) — *before* app dispatch. → the server
  must send reliable pushes with the next in-window seq; a below-window seq is silently dropped.
  **[Confirmed, rig]** `snap_recv_accept_reorder_gate` (0x1d6988), `snap_inorder_delivery_gate`
  (0x1e1c10), ack builder `snap_build_ack_header` (0x1d63b8, header word `0x6010`).
- **ACKs:** the 0x60 packet carries cumulative base (conn+0x44) + SACK. Server must ACK every reliable
  client message; client ACKs are cumulative (base can't skip). **[Confirmed, rig]**
- **Keepalive:** op40 every ~5–10s, body validly encrypted. Cipher = Blowfish-ECB keyed by
  SHA-1(spanA||spanB) — `blowfish_ecb_hashed_key` (0x1ea8e8).
- **struct snap_connection:** `structures/structure-layouts/snap_connection.md` (offsets 0x44 ack-base,
  0x5c expected-seq, 0x520 reliable-pool, 0x618 gen-seq).

## 1. Session open / login
Client SM `snap_app_sm_pump` (0x1c9b00) drives a fixed request→reply ladder after connect:
1. **op0 hello** `snap_send_session_hello` (0x1c4100): latches a session key from the reply's leading
   u16 (feeds every field checksum), sends identity+version+flags. Server: reply with the key seed.
2. **op18 / op1a / op16 / op0f** body-less reliable requests (0x1c42d0/43c0/4560/46a0), each advances the
   ladder; replies carry config/lists. Server: reply per state (see the recv_* records).
3. **register-info** `recv_register_info` (0x1c4730): server sends 3 account u32 (→0x248338/58, 0x349f70)
   + 14 reserved u32.
4. **session-params** `recv_session_params_block` (0x1c4450): 8× u16 timing/limits (defaults
   0x14/0x12c/0x12c/0x1518/0x708×4).
5. **session-config** `snap_recv_session_config` (0x1c91d0): 0x3e-byte block; derives UDP port.
> Server-side: our stack already reaches Area Select, so §1 is largely satisfied; use these records to
> fill any missing reply fields. [Mixed confidence — session ladder High from control flow.]

## 2. Server select / area select
- Area player counts + area list arrive via the reconstructed count vehicles (see `SUBSYSTEM_MAP.md`
  session/menus). Area confirm = op06 (area) → op28 selector-6. **[rig-proven earlier: renders all 10
  areas.]** Screen state `0x6c4b90` (see `lobby_state_block`).

## 3. Room list (browse)
Transport-level pager (client SM states 5–0xc):
- **op1c** request `snap_send_op1c_roomlist_request` (0x1c6dc0) + continuation cursor 0x365e00 →
  server replies header `recv_roomlist_header` (0x1c6e80): total + token.
- **op20** page request `snap_send_op20_roomlist_page_request` (0x1c7000, u16 received || u16 page-size=8)
  → server streams **0x260-byte room records** into `recv_roomlist_entries` (0x1c70b0): fields
  `name@+0x3e, id@+0xf, 8 flag bytes, data@+0xff, token@+0x15c`.
- **op1e** per-room detail (0x1c7580) → `recv_roomlist_entry_detail` (0x1c7680): token.
- **op22** member/population page (0x1c7980).
- App-level op49 room-list (the SNAP 0x28-record form) is the alternate the current server uses:
  `structures/structure-layouts/room_record.md` (name@0, current@+0x14 BE, flags@+0x1c, max@+0x20,
  handle@+0x24 LE). **[Confirmed]**

## 4. Create a room  ← current build blocker lives here
Client create menu SM `room_create_menu_sm` (0x610830); **case 0x12 COMMIT is the client half of the
create-registration** — it resolves scenario, gates reserved/slot, claims ownership, then emits:
- **op26 prepare** `snap_send_op26_create_prepare` (0x1c5900) → server op28 selector-12 reply (slot 0x26).
- **op04 create-slot** `snap_send_create_room` (0x1dc508): **struct** `name[16] + max(u16)@0x10 +
  password[16]@0x14 + flags(u16)@0x24 + scenario(u32)@0x28`; server MUST reply **op28 selector-4
  status-0** → client `FUN_005c3a40` sets ownership `0x6ff2b1=1`, handle→0x6fee8c. **[Confirmed, rig]**
- **op0c** completion (`FUN_005c3490` state `0x6cba78`).
- Ownership latch client-side: `room_slot_claim_ownership` (0x60f2c0) — needs slot `+0x00 live` &
  `+0x08 open`; whether those come from the op49 reply or a later step is the open crux (see record).
> Server has `SNAP_CREATE_SLOT_ACCEPT` implementing the op28 sel-4 accept — Confirmed working (ownership
> commits). Remaining game-fix is the roster/count *render*, §5.

## 5. Roster + counts (populate the room)  ← the visible gap
- **op06 member-JOIN** is the ONLY roster-row fill. Handler `member_join_op06_handler` (0x5bb4d0):
  copies member_record → scratch 0x6cd672, fires **event 0x1f** (ADD → roster table) then **event 0x19**
  (refresh); increments count `*(0x6cfb62+(room-1)*0x144)` capped at 4; trims a trailing `-` name
  sentinel. **[High + rig: row0 populated]**
  - **Delivery rule:** send it as the FIRST reliable after op04-accept (in-window seq) or the reorder
    gate drops it — **[Confirmed, rig: `SNAP_MEMBER_JOIN_AT_ACCEPT`]**.
  - **Render rule:** event 0x19 repaints only when the room node is settled; a self-op06 at build time
    no-ops → re-emit ~500ms later, dedup-safe. (Open: the terminal ntgui repaint is outside the overlay
    dump.) See `member_record` struct + UNRESOLVED.
- **op0a member-list** (pull) fills the *data* buffer 0x6cdbe6 + count 0x6ca890 (who=0xA0→slot 0x18
  `FUN_005c0ae0`). Distinct from the drawn roster table 0x6c7c2c. **[Confirmed]**
- **op10 sub-5** writes the in-room "MAX/CUR P" header (0x6ff2b4/0x6ff2b3); host engine zeroes it each
  rebuild → re-push after create + on each ping. **[Confirmed, rig: renders "4/"]**
- **op09 USER/MAXI register** (`charsel_register_send_step` 0x6290e0 / builders 0x1dd5f8): sub=1,
  value; feeds the room-list row + persistent store (NOT the in-room header — falsified for that).

## 6. Join an existing room (2-client co-location)
Client `room_join_sm` (0x610580): op09 register → roomlist fetch → **op06 enter** (0xe0/type-14 session
open carrying the room handle @wire+0x10) → slot validate → claim ownership.
- Server: op06 enter → **op28 selector-6 who=0xA0** accept (`FUN_005c05c0` sets 0x6ff2b1). **[Confirmed]**
- Render: joiner sends **op10 sub-2 join-request**; host replies **op10 sub-0x0c `[0x0C][count LE]`** →
  fires the joiner's continuation → room renders. **[Confirmed, rig 2-device 2026-07-16]**
- Broadcast the new member's op06 to the other session so both rosters update (`SNAP_JOINER_BROADCAST`).

## 7. Chat
Chat subsystem (33 fns, reconstructed). Message send/receive path in `functions/chat/`; opcode + display
buffer per those records. **[reconstructed; wire-op mapping in chat records — verify on a chat capture.]**

## 8. Leave / dissolve
- **op07 leave** `snap_send_leave` (0x1dd07c, zero-length) / **op08** (0x1dcfb30). Server frees the slot,
  broadcasts departure, and (host leaves) dissolves the room. Exit two-stage teardown is a known open
  item (screen=6 freeze) — see UNRESOLVED / `functions/rooms/` exit records.

---

## How to use this for the server
1. Pick a flow above. 2. Open each cited function record for the exact fields/branches. 3. Cross-check the
packet layout in `protocols/` and the struct in `structures/`. 4. Implement the server reply; the record's
"Important branches" tell you the client's accept conditions. 5. The transport contract (§0) is
non-negotiable — build it first.

**Confidence policy:** §0/§4-op04/§5-op06/op10-sub5/§6 are rig-Confirmed — safe to build on. High-confidence
items are control-flow-proven; verify Medium/Low against a capture before relying on them. The ISO/records
are truth; the current server is a partial reference, not the spec.
