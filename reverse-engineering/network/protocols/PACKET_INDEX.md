# PACKET_INDEX — opcodes → builder / parser / handler chains

_Auto-generated from the classified corpus (`gen-protocol-menu.js`). Roles/direction inferred from behavior summaries; verify per record. This is the client-side protocol contract the server must satisfy._

| Opcode | Dir | Builder (C->S) | Parser/Handler (S->C) | Dispatcher | # fns |
|---|---|---|---|---|---|
| `0x00` | C->S | 0x001c4100 | — | — | 1 |
| `0x01` | C->S | 0x001c3c90 0x001ef540 0x005c4d20 0x005d7420 0x005d76b0 | — | — | 5 |
| `0x02` | C->S/S->C | 0x001c3c90 0x001dbd0c 0x001dbe60 0x001ef5c0 0x005c5ff0 | 0x005bc860 | — | 6 |
| `0x03` | S->C/C->S | 0x001dbefc 0x005c5bb0 0x005c6500 0x005d74a0 | 0x001d9f78 0x005bc860 | — | 7 |
| `0x04` | S->C/C->S | 0x001d0040 0x001dc310 0x001dc508 0x005c5c10 0x005d70b0 0x005d7760 | 0x001d9f78 0x005bc860 | — | 11 |
| `0x05` | C->S/S->C | 0x001c8dd0 0x001dc804 0x005c5d30 0x005c6500 0x005d71e0 0x005d7760 | 0x001d9f78 0x005bc860 | — | 8 |
| `0x06` | C->S/S->C | 0x001cfa30 0x001dc9fc 0x001dcbf4 0x001dcdfc 0x001ef4f0 0x005b3ed0 0x005c3490 0x005c5db0 0x005c6500 0x005c9690 0x005ca0a0 0x005d70b0 0x005d71e0 0x005d7320 0x005d7760 0x005d7e00 | 0x001d9f78 0x005bb670 0x005bc860 | — | 20 |
| `0x07` | S->C/C->S | 0x001cfc90 0x001dd07c 0x001dd1dc 0x001ef610 0x005c5e30 0x005c6500 0x005ce530 | 0x005bc860 | — | 9 |
| `0x08` | C->S/S->C | 0x001cfb30 0x001dd33c 0x001ef690 0x005c5eb0 0x005c6500 | 0x005bc860 | — | 6 |
| `0x09` | C->S | 0x001cf8e0 0x001dd5f8 0x001dd840 0x005b25c0 0x005c5cd0 0x005c6500 0x006290e0 | — | — | 8 |
| `0x0a` | C->S/S->C | 0x001c8f50 0x001d0230 0x001ddee8 0x001de0c0 0x001ef710 0x005c5f10 | 0x005bc430 0x005c3370 | — | 8 |
| `0x0b` | C->S/S->C | 0x001d0400 0x001dda88 0x001ef770 0x005c5f70 0x005cf1e0 | 0x005bc590 0x005bc860 | — | 7 |
| `0x0c` | S->C/C->S | 0x001de470 0x001ef7d0 0x005c3490 0x005c6050 0x00604180 | 0x001d9f78 | — | 8 |
| `0x0d` | C->S/S->C | 0x001c94c0 0x001de648 | 0x001d9f78 0x005bc590 0x005bc860 | — | 5 |
| `0x0e` | C->S/S->C | 0x001c4070 0x001ddc60 0x001ef830 0x005c6150 | 0x005bc790 0x005bc860 | — | 6 |
| `0x0f` | C->S/S->C | 0x001c46a0 0x001de840 0x001df1d8 0x001ef8d0 0x005c61b0 | 0x001d9f78 | — | 6 |
| `0x10` | C->S/S->C | 0x001c3c90 0x001de9e8 0x001ded08 0x001df380 0x001df66c 0x001ef9a0 0x005c5c70 | 0x001c9b00 0x001d9f78 | — | 9 |
| `0x11` | S->C/C->S | 0x001dfbf8 0x005c60d0 0x00628110 | 0x001c9b00 0x001d9f78 | — | 5 |
| `0x12` | C->S/S->C | 0x001c48c0 0x001df9a8 0x001efa70 | 0x001c4960 | — | 4 |
| `0x13` | C->S/S->C | 0x001dfad0 0x001efb80 | 0x005bba20 0x005bc860 | — | 4 |
| `0x14` | C->S/S->C | 0x001c4c80 0x001dfda0 | 0x001c4d40 | — | 3 |
| `0x15` | S->C | — | 0x005bc860 | — | 1 |
| `0x16` | C->S | 0x001c4560 0x001efcf0 | — | — | 2 |
| `0x17` | C->S | 0x001efda0 | — | — | 1 |
| `0x18` | C->S | 0x001c42d0 0x001efee0 | — | — | 2 |
| `0x19` | C->S | 0x001eff60 | — | — | 1 |
| `0x1a` | C->S | 0x001c43c0 | — | — | 1 |
| `0x1c` | C->S | 0x001c6dc0 0x001efe00 | — | — | 2 |
| `0x1d` | C->S | 0x001efe70 | — | — | 1 |
| `0x1e` | C->S/S->C | 0x001c7580 | 0x001c9b00 | — | 2 |
| `0x1f` | S->C | — | 0x001c9b00 | — | 1 |
| `0x20` | C->S | 0x001c7000 | — | — | 1 |
| `0x22` | C->S/S->C | 0x001c7980 | 0x001d9f78 | — | 2 |
| `0x23` | C->S/S->C | 0x00627d60 0x00627ea0 0x00627f20 | — | — | 3 |
| `0x24` | C->S | 0x001c85c0 | — | — | 1 |
| `0x25` | C->S | 0x001dff7c | — | — | 1 |
| `0x26` | C->S | 0x001c5900 | — | — | 1 |
| `0x28` | S->C | 0x001c67b0 | — | — | 1 |
| `0x29` | S->C | — | 0x001c9b00 | — | 1 |
| `0x2a` | S->C | — | 0x001d9678 0x001d9f78 | — | 2 |
| `0x2b` | C->S/S->C | 0x001c5bd0 | 0x001d9f78 | — | 2 |
| `0x2c` | C->S | 0x001db7e8 | — | — | 1 |
| `0x2d` | S->C/C->S | 0x001c5ea0 | 0x001c5a20 0x001c5c90 0x001c9b00 | — | 4 |
| `0x2e` | S->C | — | 0x001d9f78 | — | 1 |
| `0x2f` | C->S/S->C | 0x001c6060 0x005c1f30 | 0x001c6130 | — | 3 |
| `0x31` | C->S | 0x001c6330 | — | — | 1 |
| `0x32` | C->S | 0x001df044 | — | — | 1 |
| `0x33` | C->S/S->C | 0x001c64f0 | 0x001c65c0 | — | 2 |
| `0x34` | C->S | 0x001e0188 | — | — | 1 |
| `0x35` | C->S | 0x001c8b60 0x005c1e70 | — | — | 2 |
| `0x37` | S->C | — | 0x001c9b00 | — | 1 |
| `0x39` | C->S/S->C | 0x001c4fb0 | 0x001c5040 | — | 2 |
| `0x3b` | C->S/S->C | 0x001c51a0 | 0x001c5260 | — | 2 |
| `0x3d` | C->S/S->C | 0x001c5480 0x001d9b6c | 0x001c5510 0x001d9f78 | — | 4 |
| `0x3e` | C->S | 0x001e05c8 0x005c2080 | — | — | 2 |
| `0x3f` | C->S/S->C | 0x001c5630 0x001e0774 | 0x001c56f0 | — | 3 |
| `0x40` | S->C | — | 0x001d9f78 | — | 1 |
| `0x41` | S->C/C->S | 0x001d9b6c 0x005c1f30 | — | — | 2 |
| `0x43` | C->S | 0x001de298 0x005c2080 | — | — | 2 |
| `0x44` | S->C | — | 0x001d9f78 | — | 1 |
| `0x45` | C->S/S->C | 0x001c69b0 | 0x001d9f78 | — | 2 |
| `0x46` | S->C/C->S | 0x001dc0b8 | 0x001d9f78 | — | 2 |
| `0x47` | C->S/S->C | 0x001c6b90 0x001ddda0 | 0x001c6c60 0x001c9b00 | — | 4 |
| `0x48` | S->C/C->S | 0x001e094c 0x005bca90 | 0x001d9f78 | — | 5 |
| `0x49` | C->S | 0x001e0ed8 0x005c1e70 | — | — | 2 |
| `0x4a` | S->C/C->S | 0x001efc90 | 0x001c9b00 | — | 2 |
| `0x4b` | S->C | — | 0x001c9b00 | — | 1 |
| `0x54` | S->C | — | 0x001c9b00 | — | 1 |
| `0x55` | S->C | — | 0x001c9b00 | — | 1 |
| `0x59` | S->C | — | 0x001c9b00 | — | 1 |
| `0x62` | C->S | 0x001ca410 | — | — | 1 |
| `0x63` | C->S | 0x001ca410 | — | — | 1 |
| `0x64` | C->S | 0x001ca410 | — | — | 1 |
| `0x6b` | S->C | — | 0x001d9f78 | — | 1 |
| `0x6e` | C->S/S->C | 0x005c04f0 0x005c05c0 0x005c1f30 0x005c1ff0 | — | — | 4 |
| `0x70` | C->S | 0x005c0750 0x005c2080 | — | — | 2 |
| `0x75` | S->C | — | 0x001d9f78 | — | 1 |
| `0x7b` | C->S | 0x005c02b0 0x005c1e70 | — | — | 2 |
| `0x86` | C->S/S->C | 0x005c0a00 0x005c0dc0 | 0x005c0ae0 | — | 3 |
| `0x91` | C->S | 0x005c08b0 | — | — | 1 |
| `0xd3` | S->C/C->S | 0x005c2120 0x005c2250 | 0x005c21c0 | — | 3 |

---

## Per-opcode detail

### `0x00`  (C->S)
**Builders (C->S):**
- 0x001c4100 snap_send_session_hello — Builds the session open/register handshake: derives+stores the session key at conn+0x4c (FUN_001c3ab0), emits selector(0,2) with two config strings and a capability/flags byte, transmits, advances to state 0x36.

### `0x01`  (C->S)
**Builders (C->S):**
- 0x001c3c90 build_packet_header — Builds the 8-byte tx header at obj+0x28: type byte param_3 (0x01/0x02/0x10), length-derived bytes from DAT_002484c0/510 tables, and an auto-incrementing sequence (obj+0x3d) for reliable types; resets payload length obj+0x38.
- 0x001ef540 snap_req_op01_session_open — SN@P RPC stub: sends app opcode 0x01 carrying three 32-bit config words (likely session-open/login params), returns result.
- 0x005c4d20 send_op01_to_conn — Builds a 0x8000-reliable packet with app-opcode 0x01 + payload and sends it to a specific decoded connID target.
- 0x005d7420 build_req_op01 — Builds a txn record with opcode 0x01 subtype 1 for the current room payload, stamps seq byte, who-byte 0; sets pending kind=1.
- 0x005d76b0 build_req_op01_sub2 — Builds an opcode 0x01 subtype 2 txn record for the current room, copies who-bytes; if FUN_005df7b0(room) reports not-ready sets state 6 with error class 0x124=2.

### `0x02`  (C->S/S->C)
**Builders (C->S):**
- 0x001c3c90 build_packet_header — Builds the 8-byte tx header at obj+0x28: type byte param_3 (0x01/0x02/0x10), length-derived bytes from DAT_002484c0/510 tables, and an auto-incrementing sequence (obj+0x3d) for reliable types; resets payload length obj+0x38.
- 0x001dbd0c snap_send_close — Sends a zero-length reliable opcode-2 message (session close/bye) when conn+0x50c lock is clear; sets errno 0x65/0x66 on alloc/send fail.
- 0x001dbe60 snap_close — Public session-close wrapper: validates param_1==1/conn!=0 then delegates to snap_send_close(conn).
- 0x001ef5c0 snap_req_op02 — SN@P RPC stub: sends app opcode 0x02 with empty body (likely session close/status), returns result.
- 0x005c5ff0 send_op02 — Builds and sends a 4-byte reliable app-opcode 0x02 packet to the target.
**Parsers/Handlers (S->C):**
- 0x005bc860 register_snap_message_handlers — Registers the overlay's SN@P message handlers on the connection handle (0x6febac) via func_0x001d4d24(handle, code, addr): binds codes 0xd/0xe/0xb->name-reply, 3/7->area count, 0x13->in-room subdispatch, 0x15/4/5/2/6/8/10 to their handlers.

### `0x03`  (S->C/C->S)
**Builders (C->S):**
- 0x001dbefc snap_send_op03 — Builds/sends a reliable (who 0xb000) opcode-3 message carrying a 16-byte blob (param_2 copied via FUN_00109eb8); completion cb 0x1d, seq counter conn+0x614.
- 0x005c5bb0 send_op03 — Builds and sends a 4-byte reliable app-opcode 0x03 packet to the target conn (roster-sync step).
- 0x005c6500 room_roster_sync_sm — Room create/enter roster-sync state machine (phases in cRam006cbb90): builds member list from candidate table, waits for accepts, then broadcasts op03/05/06/07/08/09 to sync every member and fires completion cb.
- 0x005d74a0 build_req_op03 — Builds a txn record opcode 0x03 subtype 1 for the current room payload, stamps seq, then FUN_005d6a10(record+0x108,1,1) to register a slot; sets pending kind=2.
**Parsers/Handlers (S->C):**
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.
- 0x005bc860 register_snap_message_handlers — Registers the overlay's SN@P message handlers on the connection handle (0x6febac) via func_0x001d4d24(handle, code, addr): binds codes 0xd/0xe/0xb->name-reply, 3/7->area count, 0x13->in-room subdispatch, 0x15/4/5/2/6/8/10 to their handlers.

### `0x04`  (S->C/C->S)
**Builders (C->S):**
- 0x001d0040 libsnap_send_op04_create_slot — Channel 0x2000, alloc tag 4, reliable send FUN_001cce80 (offline FUN_001a1750) with tmpl 0x24cc50/0x24cc60/0x24cc80 (uRam0034357a); parses the reply into 0x3ce350 and sets list ptr 0x3ce30c.
- 0x001dc310 snap_send_op05_data — Builds/sends reliable (who 0xb000) opcode-4 with a single htonl u32 payload (create-slot / room id); completion cb 0x1e, seq conn+0x615.
- 0x001dc508 snap_send_create_room — Builds/sends reliable opcode-4 with a 0x2c-byte struct: name (FUN_00109eb8), a packed 16-bit field, optional string (+0x14), and two more packed shorts/u32; completion cb 0x1f, seq conn+0x616.
- 0x005c5c10 send_op04_create_slot — Builds and sends the reliable app-opcode 0x04 create-slot packet (full 0x304-byte body) to the target.
- 0x005d70b0 build_req_enter_or_create — Builds a txn-queue record for the current room: opcode 0x06 (enter, if the looked-up room is the current one, state=5) else 0x04 (create-slot, state=3), subtype 1, copying who-bytes 0x108/0x109 from the room.
- 0x005d7760 session_enter_dispatch — Given a request key and subtype, finds/creates a session-pool node (0x4f370): for enter/create (4/5) checks slot via FUN_005d6a50, for 6 rejects if occupied, else allocates a fresh session node (evicting the oldest) and sets its state to 3 (in-progress).
**Parsers/Handlers (S->C):**
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.
- 0x005bc860 register_snap_message_handlers — Registers the overlay's SN@P message handlers on the connection handle (0x6febac) via func_0x001d4d24(handle, code, addr): binds codes 0xd/0xe/0xb->name-reply, 3/7->area count, 0x13->in-room subdispatch, 0x15/4/5/2/6/8/10 to their handlers.

### `0x05`  (C->S/S->C)
**Builders (C->S):**
- 0x001c8dd0 snap_send_op05_or_finalize — If create-in-progress flag set, finalizes/errors the session; otherwise builds and sends an op-0x05 packet.
- 0x001dc804 snap_send_op05 — Builds/sends opcode-5 with a single htonl u32, who 0xa000 (reliable set, no DATA bit); completion cb 0x20, seq conn+0x617.
- 0x005c5d30 send_op05 — Builds and sends a reliable app-opcode 0x05 packet with a 2-byte payload (slot idx + count) to the target.
- 0x005c6500 room_roster_sync_sm — Room create/enter roster-sync state machine (phases in cRam006cbb90): builds member list from candidate table, waits for accepts, then broadcasts op03/05/06/07/08/09 to sync every member and fires completion cb.
- 0x005d71e0 build_req_enter_or_prev — Like build_req_enter_or_create but using the reverse room iterator (FUN_005d6810): opcode 0x06/state5 if current, else opcode 0x05/state4, subtype 1.
- 0x005d7760 session_enter_dispatch — Given a request key and subtype, finds/creates a session-pool node (0x4f370): for enter/create (4/5) checks slot via FUN_005d6a50, for 6 rejects if occupied, else allocates a fresh session node (evicting the oldest) and sets its state to 3 (in-progress).
**Parsers/Handlers (S->C):**
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.
- 0x005bc860 register_snap_message_handlers — Registers the overlay's SN@P message handlers on the connection handle (0x6febac) via func_0x001d4d24(handle, code, addr): binds codes 0xd/0xe/0xb->name-reply, 3/7->area count, 0x13->in-room subdispatch, 0x15/4/5/2/6/8/10 to their handlers.

### `0x06`  (C->S/S->C)
**Builders (C->S):**
- 0x001cfa30 libsnap_send_op06_member_join — Sends the op06 member JOIN/enter: channel (toggle*0x80+0x1800), alloc tag 6, opens reliable send FUN_001cce80 with packed (p3|p1<<16|p2<<8) and marks member flags at 0x4de3e0; offline path calls FUN_001a0eb0.
- 0x001dc9fc snap_send_join — Builds/sends reliable (who 0xb000) opcode-6 with a single htonl u32 (room id) — member JOIN/enter; completion cb 0x21, seq conn+0x618.
- 0x001dcbf4 snap_send_join_named — Builds/sends reliable opcode-6 (len 0x14): htonl u32 (room id) + optional 16-byte string (password/name); completion cb 0x21, seq conn+0x618.
- 0x001dcdfc snap_send_op06_var — Builds/sends opcode-6 (len 0x18, who 0xa000): two htonl u32 + optional string; completion cb 0x22, seq conn+0x619.
- 0x001ef4f0 snap_req_op06_join — SN@P RPC stub: sends app opcode 0x06 (member join/enter) with no body, returns reply result word.
- 0x005b3ed0 roomjoin_state2_enter — Join phase 2: full enter-room flow — builds list/prompt widgets, checks slot availability (+0x43c), handles the join handshake and password/retry sub-widgets (0x5b45f0/47a0).
- 0x005c3490 room_enter_commit_sm — Large enter/create-commit state machine (0x6cba78/7c/7d): builds the room-enter request packet (scenario id, player/difficulty bitfields, flags into 0x6febe4) at 0x7004d0/0x7005b0/0x7005c0 and sends via 0x1de470; on ACK sets the ownership lock uRam006ff2b1=1, uRam006cbc7e=0x10 and kicks bdfe0(0x18).
- 0x005c5db0 send_op06_member_join — Builds and sends the reliable app-opcode 0x06 member-JOIN/enter packet with a 0x22-byte member record to the target.
- 0x005c6500 room_roster_sync_sm — Room create/enter roster-sync state machine (phases in cRam006cbb90): builds member list from candidate table, waits for accepts, then broadcasts op03/05/06/07/08/09 to sync every member and fires completion cb.
- 0x005c9690 room_enter_state_handler — Per-frame handler for a room/lobby screen state: processes the queued net result via FUN_005cc980 and, on the right pad+flag combo, sends op06 (member enter/join) or advances/ tears down the screen.
- 0x005ca0a0 inroom_member_tick — State-8 (in-room) tick: on pad+phase==1 sends op06 and advances to state 9, otherwise runs the roster-fill pass (FUN_005cce30) and the room timeout tick (FUN_005cd1d0).
- 0x005d70b0 build_req_enter_or_create — Builds a txn-queue record for the current room: opcode 0x06 (enter, if the looked-up room is the current one, state=5) else 0x04 (create-slot, state=3), subtype 1, copying who-bytes 0x108/0x109 from the room.
- 0x005d71e0 build_req_enter_or_prev — Like build_req_enter_or_create but using the reverse room iterator (FUN_005d6810): opcode 0x06/state5 if current, else opcode 0x05/state4, subtype 1.
- 0x005d7320 build_req_op06_refresh — Builds an op06 (enter) txn record for the current room, subtype 1, stamps a fresh sequence byte (cRam00701010++) into +0x108 and who-byte from cur_room_whobytes_ptr; sets pending kind=5.
- 0x005d7760 session_enter_dispatch — Given a request key and subtype, finds/creates a session-pool node (0x4f370): for enter/create (4/5) checks slot via FUN_005d6a50, for 6 rejects if occupied, else allocates a fresh session node (evicting the oldest) and sets its state to 3 (in-progress).
- 0x005d7e00 txn_begin_enter — Processes a state-4 subtype-1 txn record: copies its key, looks it up (FUN_005df340), runs session_enter_dispatch; on accept (node state 3) allocates a send object (func_0x01212970) with an 0x8000 buffer and fills its descriptor, or on state 2 marks the record done (state 5).
**Parsers/Handlers (S->C):**
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.
- 0x005bb670 room_member_leave_and_roster_refresh — Handles member-leave (dispatch code 6): decrements per-area count, clears the departing player's id from the 4-slot in-scenario table (0x7006d4) and notifies via FUN_005bb610, or in the alt mode copies the matching roster entry into scratch and fires a roster redraw (0x25/0x23).
- 0x005bc860 register_snap_message_handlers — Registers the overlay's SN@P message handlers on the connection handle (0x6febac) via func_0x001d4d24(handle, code, addr): binds codes 0xd/0xe/0xb->name-reply, 3/7->area count, 0x13->in-room subdispatch, 0x15/4/5/2/6/8/10 to their handlers.

### `0x07`  (S->C/C->S)
**Builders (C->S):**
- 0x001cfc90 send_op07_and_load_table — Channel 0x2100+, alloc tag 7, reliable send FUN_001cce80/offline FUN_001a0df0 with tmpl 0x24cbb0/0x24cbd0; then parses a large reply into 0x3ce2b0/0x3cdc90/0x3cdcb0 with a progress-UI wait loop for big payloads.
- 0x001dd07c snap_send_leave — Builds/sends a zero-length reliable (who 0xb000) opcode-7 (leave room); completion cb 0x23, seq conn+0x61a.
- 0x001dd1dc snap_send_leave_nodata — Builds/sends a zero-length opcode-7 with who 0xa000 (DATA-less leave variant); completion cb 0x24, seq conn+0x61b.
- 0x001ef610 snap_req_op07_leave — SN@P RPC stub: sends app opcode 0x07 (leave) with a 32-bit id + two 16-bit fields, returns result.
- 0x005c5e30 send_op07_charstats — Builds and sends the reliable app-opcode 0x07 leave/notify packet with a 0x36-byte payload to the target.
- 0x005c6500 room_roster_sync_sm — Room create/enter roster-sync state machine (phases in cRam006cbb90): builds member list from candidate table, waits for accepts, then broadcasts op03/05/06/07/08/09 to sync every member and fires completion cb.
- 0x005ce530 room_confirm_nav_input — Input handler for the room confirm/leave dialog (phases 4/5/6 of 0x68e85): on pad it either leaves the room (sends op07 via FUN_005d5c20) or opens the leave sub-screen (FUN_005d09d0), setting a result/SFX code at 0x68e7a; otherwise does normal up/down nav.
**Parsers/Handlers (S->C):**
- 0x005bc860 register_snap_message_handlers — Registers the overlay's SN@P message handlers on the connection handle (0x6febac) via func_0x001d4d24(handle, code, addr): binds codes 0xd/0xe/0xb->name-reply, 3/7->area count, 0x13->in-room subdispatch, 0x15/4/5/2/6/8/10 to their handlers.

### `0x08`  (C->S/S->C)
**Builders (C->S):**
- 0x001cfb30 send_op08_message — Channel 0x2a00, attribute preset (note key0=0x20), alloc tag 8, reliable send FUN_001cce80 (or offline FUN_001a1750), builds tmpl 0x24cb90/0x24cba0 and on success calls FUN_001d24c0.
- 0x001dd33c snap_send_register — Builds/sends opcode-8 register (who param5|0xa000): u32 tag (param_2) + variable blob; skips the tag byteswap when tag == 'NAME' (0x4e414d45); completion cb 0x25, seq conn+0x61c.
- 0x001ef690 snap_req_op08_leave — SN@P RPC stub: sends app opcode 0x08 (leave variant) with 32-bit id + two 16-bit fields, returns result.
- 0x005c5eb0 send_op08 — Builds and sends a 4-byte reliable app-opcode 0x08 leave packet to the target.
- 0x005c6500 room_roster_sync_sm — Room create/enter roster-sync state machine (phases in cRam006cbb90): builds member list from candidate table, waits for accepts, then broadcasts op03/05/06/07/08/09 to sync every member and fires completion cb.
**Parsers/Handlers (S->C):**
- 0x005bc860 register_snap_message_handlers — Registers the overlay's SN@P message handlers on the connection handle (0x6febac) via func_0x001d4d24(handle, code, addr): binds codes 0xd/0xe/0xb->name-reply, 3/7->area count, 0x13->in-room subdispatch, 0x15/4/5/2/6/8/10 to their handlers.

### `0x09`  (C->S)
**Builders (C->S):**
- 0x001cf8e0 send_op09_register_member — Builds and sends the op09 register message: channel 0x1200/0x1300 (by param_1), alloc tag 9, encodes a member record from base table (0x3c18b0/0x3c2250) via FUN_001cde00; rolls back alloc on failure.
- 0x001dd5f8 snap_send_op09_nodata — Builds/sends opcode-9 (len 8, who 0xa000): two htonl u32; completion cb 0x16, seq conn+0x61d.
- 0x001dd840 snap_send_op09 — Builds/sends reliable (who 0xb000) opcode-9 (len 8): two htonl u32; completion cb 0x17, seq conn+0x61e.
- 0x005b25c0 lobby_init_and_register_handlers — Screen-0 init: zeroes lobby buffers and registers ~30 command/selector handlers via 0x5bdf70, then builds+submits the session USER registration struct.
- 0x005c5cd0 send_op09_register — Builds and sends a 4-byte reliable app-opcode 0x09 register packet to the target.
- 0x005c6500 room_roster_sync_sm — Room create/enter roster-sync state machine (phases in cRam006cbb90): builds member list from candidate table, waits for accepts, then broadcasts op03/05/06/07/08/09 to sync every member and fires completion cb.
- 0x006290e0 charsel_register_send_step — Charsel sub-step that, after its timer expires, rebuilds the widget/render and sends app opcode 0x09 (register) via FUN_005b7fd0 with the chosen slot.

### `0x0a`  (C->S/S->C)
**Builders (C->S):**
- 0x001c8f50 snap_send_op0a_memberlist_req — Builds and sends the op-0x0a member-list request (subtype byte 1) with a 0x100-byte encoded field from 0x35b9f0, advancing substate to 0x35.
- 0x001d0230 build_and_send_list_screen_msg — Channel 0x2400, alloc tag 10, reliable send FUN_001cce80 (offline FUN_001a1750) with tmpl 0x24cc90/0x24cca0/0x24ccc0; wires up list buffers at 0x301018/0x30101c for the member-list reply.
- 0x001ddee8 snap_send_op0a_memberlist_req — Builds/sends reliable (who 0xb000) opcode-0xa with a single htonl u32 (room id) — member-list request; completion cb 0x19, seq arg 0.
- 0x001de0c0 snap_send_op0a_memberlist_req_alt — Builds/sends opcode-0xa with who 0xa000 (DATA-less member-list request), single htonl u32; completion cb 0x18, seq arg 0.
- 0x001ef710 snap_req_op0a_member_list — SN@P RPC stub: sends app opcode 0x0a (member-list) with a single 16-bit id, returns result.
- 0x005c5f10 send_op0a_member_list — Builds and sends a 4-byte reliable app-opcode 0x0a member-list request to the target.
**Parsers/Handlers (S->C):**
- 0x005bc430 roster_member_update_and_redraw — Member-list handler (dispatch code 0x0a): scans the 4-entry roster (0x6cdbe6) for the id in the payload, copies the id/name/blob fields into the entry and scratch (0x6cd672), and when the entry's active byte (+0xe5)==1 repacks the visible roster (FUN_005bc370) and fires the roster redraw (FUN_005bdfe0 0x24/0x23).
- 0x005c3370 scenario_member_scan_reply_cb — Reply handler for the member/roster list: on status 0x00 walks the variable-length member array (count at +8), copies each active member's 8-word block to 0x7005d0, increments the member counter 0x6ca890, and signals the SM (0x6cba55=1); status 0x27 signals failure (=2).

### `0x0b`  (C->S/S->C)
**Builders (C->S):**
- 0x001d0400 send_op0b_small — Channel (param_2*8 + 0x3000), attribute preset with key0xc=1, alloc tag 0xb (8 bytes), sets buffers at param_1+0x70 and opens a reliable send FUN_001cce80(param_2,-1,buf,3)/offline FUN_001a1750.
- 0x001dda88 snap_send_op0b — Builds/sends reliable (who 0xb000) opcode-0xb with a single htonl u32; completion cb 0x1b (no per-op seq counter, seq arg 0).
- 0x001ef770 snap_req_op0b — SN@P RPC stub: sends app opcode 0x0b with a single 16-bit id, returns result.
- 0x005c5f70 send_op0b_word — Builds and sends a reliable app-opcode 0x0b packet with a 4-byte payload to the target.
- 0x005cf1e0 room_exit_input_handler — Sets phase 0x68e85=0xb and, on confirm pad, either counts pending room ('\r' state1) rows and re-sends op0b (FUN_005d5c20(0xb)) or pops the screen; branches on cRam003c8a80 (connection/link state).
**Parsers/Handlers (S->C):**
- 0x005bc590 handle_name_register_reply — Name/register reply handler (dispatch codes 0xd and 0xb): sub-type 0 loads a name/id record (0x6fc06a/0x6fc07e + params) and dispatches screen 5; sub-types 1/2 hash a 0x20-byte name against the registry (func_0x0010a338 @0x36842c) and, on miss, latch a duplicate/error state (0x700680) and dispatch error screen 0x2b.
- 0x005bc860 register_snap_message_handlers — Registers the overlay's SN@P message handlers on the connection handle (0x6febac) via func_0x001d4d24(handle, code, addr): binds codes 0xd/0xe/0xb->name-reply, 3/7->area count, 0x13->in-room subdispatch, 0x15/4/5/2/6/8/10 to their handlers.

### `0x0c`  (S->C/C->S)
**Builders (C->S):**
- 0x001de470 snap_send_prepare — Builds/sends opcode-0xc PREPARE (who 0xa000): copies a *(conn+0x64)-length session blob from param_2; completion cb 0x26, seq conn+0x61f.
- 0x001ef7d0 snap_req_op0c_prepare — SN@P RPC stub: sends app opcode 0x0c (prepare) with a single 16-bit id, returns result.
- 0x005c3490 room_enter_commit_sm — Large enter/create-commit state machine (0x6cba78/7c/7d): builds the room-enter request packet (scenario id, player/difficulty bitfields, flags into 0x6febe4) at 0x7004d0/0x7005b0/0x7005c0 and sends via 0x1de470; on ACK sets the ownership lock uRam006ff2b1=1, uRam006cbc7e=0x10 and kicks bdfe0(0x18).
- 0x005c6050 send_op0c_prepare — Builds and sends the reliable app-opcode 0x0c prepare packet with a 4-byte payload to the target.
- 0x00604180 member_sync_state_machine — Large 6-case (0x900 selector) member add/remove/sync engine: manages join/leave transactions against the roster status table (0x70b4d0) and pool 0x694700, driving reliable sends (005b8cf0/005b9110/005b8da0) with per-step countdown timers (ctx+0x918) and playing UI feedback (0x1b0140).
**Parsers/Handlers (S->C):**
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.

### `0x0d`  (C->S/S->C)
**Builders (C->S):**
- 0x001c94c0 snap_send_op0d_data_chunk — Builds and sends an op-0x0d data-upload chunk (10-byte id + offset + length, capped to fit 0x300) advancing the sent offset (+0x12) and substate to 0x18.
- 0x001de648 snap_send_op0d — Builds/sends opcode-0xd (who 0xa000) with a single htonl u32; completion cb 0x27, seq conn+0x620.
**Parsers/Handlers (S->C):**
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.
- 0x005bc590 handle_name_register_reply — Name/register reply handler (dispatch codes 0xd and 0xb): sub-type 0 loads a name/id record (0x6fc06a/0x6fc07e + params) and dispatches screen 5; sub-types 1/2 hash a 0x20-byte name against the registry (func_0x0010a338 @0x36842c) and, on miss, latch a duplicate/error state (0x700680) and dispatch error screen 0x2b.
- 0x005bc860 register_snap_message_handlers — Registers the overlay's SN@P message handlers on the connection handle (0x6febac) via func_0x001d4d24(handle, code, addr): binds codes 0xd/0xe/0xb->name-reply, 3/7->area count, 0x13->in-room subdispatch, 0x15/4/5/2/6/8/10 to their handlers.

### `0x0e`  (C->S/S->C)
**Builders (C->S):**
- 0x001c4070 snap_send_op0e_flush — Builds and transmits a bare control packet (opener FUN_001c3420 with tag 0xe) — finalizes length and sends; no app payload.
- 0x001ddc60 snap_send_op0e — Builds/sends a zero-length reliable (who 0xb000) opcode-0xe; completion cb 0x1a, seq arg 0.
- 0x001ef830 snap_req_op0e_query3 — SN@P RPC stub: sends app opcode 0x0e with a 16-bit id and returns three 16-bit out-values plus result.
- 0x005c6150 send_op0e_bare — Builds and sends a 4-byte reliable app-opcode 0x0e packet to the target.
**Parsers/Handlers (S->C):**
- 0x005bc790 handle_name_reply_simple — Name reply handler (dispatch code 0xe): sub-type 0 loads the name/id record (0x6fc06a/0x6fc07e) and dispatches screen 5; otherwise hashes the 0x20-byte name into the registry (0x36842c) without the error-latch logic of FUN_005bc590.
- 0x005bc860 register_snap_message_handlers — Registers the overlay's SN@P message handlers on the connection handle (0x6febac) via func_0x001d4d24(handle, code, addr): binds codes 0xd/0xe/0xb->name-reply, 3/7->area count, 0x13->in-room subdispatch, 0x15/4/5/2/6/8/10 to their handlers.

### `0x0f`  (C->S/S->C)
**Builders (C->S):**
- 0x001c46a0 snap_send_op0f_request — Emits empty request opcode 0x0f and transmits; advances to state 0x1e.
- 0x001de840 snap_send_op0f_reliable — Builds/sends opcode-0xf (who param_4|0xa400): copies a param_3-length blob; no completion cb.
- 0x001df1d8 snap_send_op0f_unrel — Builds/sends opcode-0xf with who param_2|0x2000 (unreliable): copies a param_4-length blob; no completion cb.
- 0x001ef8d0 snap_send_op0f_data — SN@P RPC stub: sends app opcode 0x0f carrying a caller data buffer (length clamped to 0xc00), returns result.
- 0x005c61b0 send_op0f_bare — Builds and sends a 4-byte reliable app-opcode 0x0f packet to the target.
**Parsers/Handlers (S->C):**
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.

### `0x10`  (C->S/S->C)
**Builders (C->S):**
- 0x001c3c90 build_packet_header — Builds the 8-byte tx header at obj+0x28: type byte param_3 (0x01/0x02/0x10), length-derived bytes from DAT_002484c0/510 tables, and an auto-incrementing sequence (obj+0x3d) for reliable types; resets payload length obj+0x38.
- 0x001de9e8 snap_send_op10_multi — Builds/sends opcode-0x10 (who param_4|0xa400): prefixes a count (param_5) then param_5 htonl u32 recipient ids (from varargs) followed by a param_3-length blob; no completion cb.
- 0x001ded08 snap_send_op10_multi_ptr — Builds/sends opcode-0x10 (who param_4|0xa400) identical to FUN_001de9e8 but recipient ids come from an array descriptor param_5 (count + ptr) instead of varargs; no completion cb.
- 0x001df380 snap_send_op10_multi_unrel — Builds/sends opcode-0x10 with who param_2|0x2000 (unreliable): count + param_5 htonl u32 ids (varargs) + param_4 blob; no completion cb.
- 0x001df66c snap_send_op10_multi_unrel_ptr — Builds/sends opcode-0x10 with who param_2|0x2000 (unreliable): recipient ids from array descriptor param_5 (count+ptr) + param_4 blob; no completion cb.
- 0x001ef9a0 snap_send_op10_roominfo — SN@P RPC stub: sends app opcode 0x10 (room-info) carrying a caller data buffer (clamped 0xc00), returns result.
- 0x005c5c70 send_op10_room_info — Builds and sends the reliable app-opcode 0x10 room-info packet (0x304-byte body) to the target.
**Parsers/Handlers (S->C):**
- 0x001c9b00 snap_app_sm_pump — The central per-tick app-protocol driver: polls the socket (FUN_001ee430), then on ready dispatches ~40 sub-state handlers (create/list/roster/transfer steps) via a big switch on substate +0xd, arming reply-waits with FUN_001c3450.
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.

### `0x11`  (S->C/C->S)
**Builders (C->S):**
- 0x001dfbf8 snap_send_op11_unrel — Builds/sends opcode-0x11 with who param_2|0x2000 (unreliable): copies a param_4-length blob; no completion cb.
- 0x005c60d0 send_op11_word — Builds and sends a reliable app-opcode 0x11 packet with a 4-byte payload to the target.
- 0x00628110 query_op11_send_step — Sub-step of the member machine that emits app opcode 0x11 (room/member query) via FUN_005b7fd0 and waits on the reliable-send window before setting the +0x443 done flag.
**Parsers/Handlers (S->C):**
- 0x001c9b00 snap_app_sm_pump — The central per-tick app-protocol driver: polls the socket (FUN_001ee430), then on ready dispatches ~40 sub-state handlers (create/list/roster/transfer steps) via a big switch on substate +0xd, arming reply-waits with FUN_001c3450.
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.

### `0x12`  (C->S/S->C)
**Builders (C->S):**
- 0x001c48c0 snap_send_op12_named_request — Emits request opcode 0x12 carrying a name string (from buffer 0x36842c); advances to state 0x11 — starts a named-resource download.
- 0x001df9a8 snap_send_op12 — Builds/sends a zero-length opcode-0x12 with who 0x2000 (unreliable, empty command); no completion cb.
- 0x001efa70 snap_recv_op12_data — SN@P RPC stub: sends app opcode 0x12 and copies the reply payload into the caller buffer, returning received length.
**Parsers/Handlers (S->C):**
- 0x001c4960 recv_download_setup_A — Reply-0x12 handler: validates echoed name (memcmp vs 0x36842c), reads a chunk-count (clamped to 2) and per-chunk sizes into the 0x36846c pool table, resets seq (0x368421/0x368424), advances to state 0x12 (chunk-fetch).

### `0x13`  (C->S/S->C)
**Builders (C->S):**
- 0x001dfad0 snap_send_op13 — Builds/sends a zero-length opcode-0x13 with who 0x2000 (unreliable, empty command); no completion cb.
- 0x001efb80 snap_recv_op13_data — SN@P RPC stub: sends app opcode 0x13 and copies reply payload into caller buffer, returning received length (op12 variant).
**Parsers/Handlers (S->C):**
- 0x005bba20 inroom_subevent_dispatcher — In-room sub-event dispatcher (dispatch code 0x13): switches on the sub-selector byte at msg+8 (cases 1..0x11) to route room title, member add, ready-state, names, chat, scenario, timer and game-event handlers.
- 0x005bc860 register_snap_message_handlers — Registers the overlay's SN@P message handlers on the connection handle (0x6febac) via func_0x001d4d24(handle, code, addr): binds codes 0xd/0xe/0xb->name-reply, 3/7->area count, 0x13->in-room subdispatch, 0x15/4/5/2/6/8/10 to their handlers.

### `0x14`  (C->S/S->C)
**Builders (C->S):**
- 0x001c4c80 snap_send_op14_chunk_request_A — Emits opcode 0x14 chunk-fetch: appends chunk-idx (0x368421), byte-offset (0x368424), and window size 0x2f2; advances to state 0x13.
- 0x001dfda0 snap_send_op14_seq — Builds/sends opcode-0x14 with who param_2|0x2000: copies a param_4-length blob; completion cb 0x28, seq conn+0x621.
**Parsers/Handlers (S->C):**
- 0x001c4d40 recv_download_chunk_A — Reply-0x14 handler: validates idx/offset against 0x368421/0x368424, copies the 0x2f2 body via FUN_001c3b90 into pool ptr (0x368474[idx]+off), advances offset/chunk; on last chunk copies name to 0x36842c and goes to state 0x14, else loops state 0x12.

### `0x15`  (S->C)
**Parsers/Handlers (S->C):**
- 0x005bc860 register_snap_message_handlers — Registers the overlay's SN@P message handlers on the connection handle (0x6febac) via func_0x001d4d24(handle, code, addr): binds codes 0xd/0xe/0xb->name-reply, 3/7->area count, 0x13->in-room subdispatch, 0x15/4/5/2/6/8/10 to their handlers.

### `0x16`  (C->S)
**Builders (C->S):**
- 0x001c4560 snap_send_op16_request — Emits empty request opcode 0x16 and transmits; advances to state 0x15.
- 0x001efcf0 snap_req_op16_query3 — SN@P RPC stub: sends app opcode 0x16 with a 16-bit id; on success (result==0) returns three out-values (2B,4B,2B).

### `0x17`  (C->S)
**Builders (C->S):**
- 0x001efda0 snap_req_op17 — SN@P RPC stub: sends app opcode 0x17 with a single 16-bit id, returns result.

### `0x18`  (C->S)
**Builders (C->S):**
- 0x001c42d0 snap_send_op18_request — Emits empty request opcode 0x18 and transmits; advances to state 0x03.
- 0x001efee0 snap_req_op18 — SN@P RPC stub: sends app opcode 0x18 with a 32-bit word plus two 16-bit fields, returns result.

### `0x19`  (C->S)
**Builders (C->S):**
- 0x001eff60 snap_send_op19_data_padded — SN@P RPC stub: sends app opcode 0x19 with id, extra 4B+2B header fields and a length-prefixed, 4-byte-aligned payload; returns result (negative -> error).

### `0x1a`  (C->S)
**Builders (C->S):**
- 0x001c43c0 snap_send_op1a_request — Emits empty request opcode 0x1a and transmits; advances to state 0x0f.

### `0x1c`  (C->S)
**Builders (C->S):**
- 0x001c6dc0 snap_send_op1c_roomlist_request — Emits opcode 0x1c room-list request: resets counters (0x365e10; 0x365e00 when fsm-state 1) and appends resume-cursor 0x365e00; advances to state 0x05.
- 0x001efe00 snap_req_op1c_roomlist — SN@P RPC stub: sends app opcode 0x1c with two 32-bit words, returns result.

### `0x1d`  (C->S)
**Builders (C->S):**
- 0x001efe70 snap_req_op1d_roomlist — SN@P RPC stub: sends app opcode 0x1d with two 32-bit words, returns result (op1c twin).

### `0x1e`  (C->S/S->C)
**Builders (C->S):**
- 0x001c7580 snap_send_op1e_detail_request — Emits opcode 0x1e room-detail request: appends the current room's stored id (0x365f7c) and name (record at 0x365e20 indexed by 0x365e0c*0x260); advances to state 0x09.
**Parsers/Handlers (S->C):**
- 0x001c9b00 snap_app_sm_pump — The central per-tick app-protocol driver: polls the socket (FUN_001ee430), then on ready dispatches ~40 sub-state handlers (create/list/roster/transfer steps) via a big switch on substate +0xd, arming reply-waits with FUN_001c3450.

### `0x1f`  (S->C)
**Parsers/Handlers (S->C):**
- 0x001c9b00 snap_app_sm_pump — The central per-tick app-protocol driver: polls the socket (FUN_001ee430), then on ready dispatches ~40 sub-state handlers (create/list/roster/transfer steps) via a big switch on substate +0xd, arming reply-waits with FUN_001c3450.

### `0x20`  (C->S)
**Builders (C->S):**
- 0x001c7000 snap_send_op20_roomlist_page_request — Emits opcode 0x20 room-list page request: appends progress counters 0x365e18/0x365e1a; advances to state 0x07.

### `0x22`  (C->S/S->C)
**Builders (C->S):**
- 0x001c7980 snap_send_op22_request — Emits opcode 0x22 room request: appends counters 0x365e18/0x365e1a and the current room record name (0x365e20 indexed by 0x365e0c); advances to state 0x0b.
**Parsers/Handlers (S->C):**
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.

### `0x23`  (C->S/S->C)
**Builders (C->S):**
- 0x00627d60 member_op23_task_dispatch — Per-frame task dispatcher for the op-0x23 member-list machine: runs sub-state uRam00695ce0 (cases 0-6) across the send/wait/process/refresh/leave sub-steps and resets the task record on completion.
- 0x00627ea0 member_list_send_init — Sub-step 0 of the member machine: snapshots current roster count (FUN_00604810 over 0x694700), builds the descriptor list, and sends app opcode 0x23 (member-list request) via FUN_005b7fd0.
- 0x00627f20 member_list_reply_process — Processes the op-0x23 member-list reply: iterates returned entries (+0xc base, +8 count), marks/selects roster slots, and advances or re-queries via the L1 send-queue guards FUN_005b14b0.

### `0x24`  (C->S)
**Builders (C->S):**
- 0x001c85c0 snap_send_op24_member_batch — Builds and sends the op-0x24 packet carrying up to 12 accumulated member-record pointers (a member-list batch/ack), then advances substate to 0xd.

### `0x25`  (C->S)
**Builders (C->S):**
- 0x001dff7c snap_send_op25_name2int — Builds/sends reliable (who 0xb000) opcode-0x25 (len 0x18): 16-byte field (param_2) + two htonl u32; completion cb 0x29, seq arg 0.

### `0x26`  (C->S)
**Builders (C->S):**
- 0x001c5900 snap_send_op26_create_prepare — Builds the create/prepare packet (opcode 0x26 = 'prepare' slot): sets up room name ptr (default 0x361a50 or conn+4) and data buffer (conn+8/0x35ccc8), emits seq(conn+0x9c)=0 + name string, transmits, advances to state 0x20.

### `0x28`  (S->C)
**Builders (C->S):**
- 0x001c67b0 snap_send_op28_request — Emits opcode 0x28 (the op28 selector reply) with no extra body and transmits; advances to state 0x24.

### `0x29`  (S->C)
**Parsers/Handlers (S->C):**
- 0x001c9b00 snap_app_sm_pump — The central per-tick app-protocol driver: polls the socket (FUN_001ee430), then on ready dispatches ~40 sub-state handlers (create/list/roster/transfer steps) via a big switch on substate +0xd, arming reply-waits with FUN_001c3450.

### `0x2a`  (S->C)
**Parsers/Handlers (S->C):**
- 0x001d9678 snap_connect_reply_handler — Handles the connect/open reply while state==1: decrypts+validates the datagram (FUN_001e5538/FUN_00109d70), records peer session fields (0x500/0x504/0x508/0xa8), formats peer IP string, advances state 1->2 and arms timeout 0x51c; on validation fail delivers status 0x13 and resets.
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.

### `0x2b`  (C->S/S->C)
**Builders (C->S):**
- 0x001c5bd0 snap_send_op2b_enter_request — Emits opcode 0x2b carrying room name (conn+0xa0), a u32 (conn+0xd0) and u16 (conn+0xac); advances to state 0x22 — enter/join-with-payload request.
**Parsers/Handlers (S->C):**
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.

### `0x2c`  (C->S)
**Builders (C->S):**
- 0x001db7e8 snap_session_open — Builds and sends the SN@P session-open/connect request (opcode 0x2c, who 0x3000): copies key material to conn+0x484/0x4ac, encodes peer/port/name fields, appends LC/MR TLVs (FUN_001eac0c 0x4c43/0x4d52), sends, sets state 0x80=1 and arms timeout; registers completion cb 0x1c.

### `0x2d`  (S->C/C->S)
**Builders (C->S):**
- 0x001c5ea0 snap_send_op2d_request — Emits empty request opcode 0x2d and transmits; advances to state 0x2a.
**Parsers/Handlers (S->C):**
- 0x001c5a20 recv_op2d_transfer_setup — Reply parser (create/enter data transfer): reads status byte, validates echoed name (memcmp conn+0x28 vs local), reads total length into conn+0x2c and a flag into conn+0x2a; if nonzero sets window 0x2d2 and advances to state 0x21 (chunk receive) else branches 0x19/0x31/0x3f by fsm-state.
- 0x001c5c90 recv_conn_data_chunk — Per-connection data-chunk receiver: validates echoed name + seq (conn+0x34), computes window using who-byte 0x8000 (fsm-state 3) or 0x1000 else, copies body to conn+0x35 buffer, on completion branches next-state 0x21/0x31/0x19/0x3f by fsm-state.
- 0x001c9b00 snap_app_sm_pump — The central per-tick app-protocol driver: polls the socket (FUN_001ee430), then on ready dispatches ~40 sub-state handlers (create/list/roster/transfer steps) via a big switch on substate +0xd, arming reply-waits with FUN_001c3450.

### `0x2e`  (S->C)
**Parsers/Handlers (S->C):**
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.

### `0x2f`  (C->S/S->C)
**Builders (C->S):**
- 0x001c6060 snap_send_op2f_chunk_request_D — Emits opcode 0x2f chunk-fetch: appends current slot-id (0x365d74[idx]), offset (0x365db8), window 0x2d2; advances to state 0x2c.
- 0x005c1f30 build_msg_op6e_variant — Message builder: opcode 0x6e (arg2), 0x41 (arg1), or 0x2f (arg0) into scratch 0x7018d0, append param_2, finalize.
**Parsers/Handlers (S->C):**
- 0x001c6130 recv_download_chunk_D — Reply-0x2f handler: matches slot-id (0x365d74), reads offset+len, copies body into ring 0x35ccc8+idx*0x800+off, advances slot/offset, terminates to state 0x31 (fsm 3) or 0x02 else loops 0x2b.

### `0x31`  (C->S)
**Builders (C->S):**
- 0x001c6330 snap_send_op31_finalize — Emits empty request opcode 0x31 and transmits; advances to state 0x40.

### `0x32`  (C->S)
**Builders (C->S):**
- 0x001df044 snap_send_op32_unrel — Builds/sends opcode-0x32 with who 0x2000 (set, unreliable, no DATA/reliable bits): copies a param_3-length blob; no completion cb.

### `0x33`  (C->S/S->C)
**Builders (C->S):**
- 0x001c64f0 snap_send_op33_chunk_request_E — Emits opcode 0x33 chunk-fetch: appends current slot-id (0x365bb4[idx]), offset (0x365c18), window 0x2d2; advances to state 0x42.
**Parsers/Handlers (S->C):**
- 0x001c65c0 recv_download_chunk_E — Reply-0x33 handler: matches slot-id (0x365bb4), reads offset+len, copies body into ring 0x35ccb8+idx*0x200+off, advances slot/offset, terminates to state 0x31 else loops 0x41.

### `0x34`  (C->S)
**Builders (C->S):**
- 0x001e0188 snap_send_op34_string — Builds/sends reliable (who 0xb000) opcode-0x34: copies a length-prefixed blob (FUN_0010a050 measured, clamped to 0x368); completion cb 0x2a.

### `0x35`  (C->S)
**Builders (C->S):**
- 0x001c8b60 snap_send_op35_record — Builds and sends the op-0x35 packet serializing a fixed profile/config record from 0x365a70 (byte/u16/u32 fields, 3x(u32,byte,byte), 8x u32), then advances substate to 0x2e.
- 0x005c1e70 build_msg_register_variant — Message builder for the register/enter family: opcode 0x7b (arg2), 0x49 (arg1), or 0x35 (arg0) into scratch 0x7018d0, append param_2, finalize.

### `0x37`  (S->C)
**Parsers/Handlers (S->C):**
- 0x001c9b00 snap_app_sm_pump — The central per-tick app-protocol driver: polls the socket (FUN_001ee430), then on ready dispatches ~40 sub-state handlers (create/list/roster/transfer steps) via a big switch on substate +0xd, arming reply-waits with FUN_001c3450.

### `0x39`  (C->S/S->C)
**Builders (C->S):**
- 0x001c4fb0 snap_send_op39_request — Emits empty request opcode 0x39 and transmits; advances to state 0x1a — starts download machine B.
**Parsers/Handlers (S->C):**
- 0x001c5040 recv_download_setup_B — Reply-0x39 handler: reads a count (clamped 8) into 0x365cf0, fills per-slot sizes (0x365cf4) and dest ptrs (0x365d34 into ring at 0x35ccc8, 0x400 stride), resets seq, advances to state 0x1b.

### `0x3b`  (C->S/S->C)
**Builders (C->S):**
- 0x001c51a0 snap_send_op3b_chunk_request_B — Emits opcode 0x3b chunk-fetch: appends slot-idx (0x365db4), offset (0x365db8), window 0x2f2; advances to state 0x1c.
**Parsers/Handlers (S->C):**
- 0x001c5260 recv_download_chunk_B — Reply-0x3b handler: validates slot/offset (0x365db4/0x365db8), copies body into ring 0x35ccc8+idx*0x400+off via FUN_001c3b90, advances offset/slot, terminates at state 0x3b when all slots done else loops 0x1b.

### `0x3d`  (C->S/S->C)
**Builders (C->S):**
- 0x001c5480 snap_send_op3d_request — Emits empty request opcode 0x3d and transmits; advances to state 0x3c — starts download machine C.
- 0x001d9b6c snap_keyexchange_reply — Secure-handshake responder: decrypts incoming (FUN_001e5538 key conn+0x4d4), runs DH/crypto step FUN_001ea8e8 against conn+0x484, builds an 0x88-byte encrypted reply (FUN_001e56c8) and sends it reliably with opcode 0x41; sets errno 0x65/0x66 on alloc/send failure.
**Parsers/Handlers (S->C):**
- 0x001c5510 recv_download_setup_C — Reply-0x3d handler: reads count (clamped 2) into 0x365c20, fills sizes (0x365c24) and dest ptrs (0x365c64 into ring 0x35ccc0, 0x800 stride), resets seq, advances to state 0x3d.
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.

### `0x3e`  (C->S)
**Builders (C->S):**
- 0x001e05c8 snap_send_op3e — Builds/sends reliable (who 0xb000) opcode-0x3e: copies a param_3-length blob clamped to 0x36c; no completion cb.
- 0x005c2080 build_msg_op70_variant — Message builder: opcode 0x70 (arg2), 0x43 (arg1), or 0x3e (arg0) into scratch 0x7018d0, finalize (no body).

### `0x3f`  (C->S/S->C)
**Builders (C->S):**
- 0x001c5630 snap_send_op3f_chunk_request_C — Emits opcode 0x3f chunk-fetch: appends slot-idx (0x365ce4), offset (0x365ce8), window 0x2f2; advances to state 0x3e.
- 0x001e0774 snap_send_op3f_hdr_blob — Builds/sends reliable (who 0xb000) opcode-0x3f: a 4-byte header (param_2/param_3) followed by a param_4-length blob clamped to 0x368; no completion cb.
**Parsers/Handlers (S->C):**
- 0x001c56f0 recv_download_chunk_C — Reply-0x3f handler: validates slot/offset (0x365ce4/0x365ce8), copies body into ring 0x35ccc0+idx*0x800+off, advances offset/slot, terminates to state 0x3f when done else loops 0x3d.

### `0x40`  (S->C)
**Parsers/Handlers (S->C):**
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.

### `0x41`  (S->C/C->S)
**Builders (C->S):**
- 0x001d9b6c snap_keyexchange_reply — Secure-handshake responder: decrypts incoming (FUN_001e5538 key conn+0x4d4), runs DH/crypto step FUN_001ea8e8 against conn+0x484, builds an 0x88-byte encrypted reply (FUN_001e56c8) and sends it reliably with opcode 0x41; sets errno 0x65/0x66 on alloc/send failure.
- 0x005c1f30 build_msg_op6e_variant — Message builder: opcode 0x6e (arg2), 0x41 (arg1), or 0x2f (arg0) into scratch 0x7018d0, append param_2, finalize.

### `0x43`  (C->S)
**Builders (C->S):**
- 0x001de298 snap_send_op43 — Builds/sends opcode-0x43 (who 0xa000) with a single htonl u32; completion cb 0x2e, seq arg 0.
- 0x005c2080 build_msg_op70_variant — Message builder: opcode 0x70 (arg2), 0x43 (arg1), or 0x3e (arg0) into scratch 0x7018d0, finalize (no body).

### `0x44`  (S->C)
**Parsers/Handlers (S->C):**
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.

### `0x45`  (C->S/S->C)
**Builders (C->S):**
- 0x001c69b0 snap_send_op45_request — Emits opcode 0x45 with a single byte(1) selector; advances to state 0x26.
**Parsers/Handlers (S->C):**
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.

### `0x46`  (S->C/C->S)
**Builders (C->S):**
- 0x001dc0b8 snap_send_op46 — Builds/sends reliable opcode-0x46 (len 0x28): two 16-byte name fields, a short (param_4) and a u32 (param_5, htonl); completion cb 0x2f, seq conn+0x614.
**Parsers/Handlers (S->C):**
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.

### `0x47`  (C->S/S->C)
**Builders (C->S):**
- 0x001c6b90 snap_send_op47_chunk_request — Emits opcode 0x47 chunk-fetch: byte(1), current offset (conn+0x48), remaining-len (0x35b7d0 - offset); advances to state 0x28.
- 0x001ddda0 snap_send_op47 — Builds/sends a zero-length reliable (who 0xb000) opcode-0x47; completion cb 0x30, seq arg 0.
**Parsers/Handlers (S->C):**
- 0x001c6c60 recv_op47_download_chunk — Reply-0x47 handler: reads offset+len, if within 0x35b7d0/0x100 stores new cursor at conn+0x48 and stays state 0x27 else state 0x1d, copies body into 0x35b7e0+offset.
- 0x001c9b00 snap_app_sm_pump — The central per-tick app-protocol driver: polls the socket (FUN_001ee430), then on ready dispatches ~40 sub-state handlers (create/list/roster/transfer steps) via a big switch on substate +0xd, arming reply-waits with FUN_001c3450.

### `0x48`  (S->C/C->S)
**Builders (C->S):**
- 0x001e094c snap_send_op48_name_query — Builds/sends reliable (who 0xb000) opcode-0x48 name/roster query: a request-id word then up to 32 entries, each with an htonl id, a 1-byte kind, and a kind-dependent body (type1=two u32, type2=16-byte addr, else one u32); computes length via FUN_001ebca8; completion cb 0x31.
- 0x005bca90 send_name_query — Builds and sends a 'NAME' query request: on sub-type 0 assembles a request struct tagged 0x4e414d45 ('NAME') carrying local name (FUN_005c4f40) and id (FUN_005c4fd0) and transmits via func_0x001e094c with completion callback FUN_005bc990; sub-type '\'' renders an error dialog.
**Parsers/Handlers (S->C):**
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.

### `0x49`  (C->S)
**Builders (C->S):**
- 0x001e0ed8 snap_build_op49_addr_register — Builds the reliable op-0x49 (room-list/register) payload: iterates up to 0x20 address entries (stride 0xc), encodes each by type (1->0xd,2->0x15,else->9 bytes) with byteswapped fields, then hands to the packet enqueuer with opcode 0x49 / who-byte 0xb000.
- 0x005c1e70 build_msg_register_variant — Message builder for the register/enter family: opcode 0x7b (arg2), 0x49 (arg1), or 0x35 (arg0) into scratch 0x7018d0, append param_2, finalize.

### `0x4a`  (S->C/C->S)
**Builders (C->S):**
- 0x001efc90 snap_req_op4a — SN@P RPC stub: sends app opcode 0x4a with a single 16-bit id, returns result.
**Parsers/Handlers (S->C):**
- 0x001c9b00 snap_app_sm_pump — The central per-tick app-protocol driver: polls the socket (FUN_001ee430), then on ready dispatches ~40 sub-state handlers (create/list/roster/transfer steps) via a big switch on substate +0xd, arming reply-waits with FUN_001c3450.

### `0x4b`  (S->C)
**Parsers/Handlers (S->C):**
- 0x001c9b00 snap_app_sm_pump — The central per-tick app-protocol driver: polls the socket (FUN_001ee430), then on ready dispatches ~40 sub-state handlers (create/list/roster/transfer steps) via a big switch on substate +0xd, arming reply-waits with FUN_001c3450.

### `0x54`  (S->C)
**Parsers/Handlers (S->C):**
- 0x001c9b00 snap_app_sm_pump — The central per-tick app-protocol driver: polls the socket (FUN_001ee430), then on ready dispatches ~40 sub-state handlers (create/list/roster/transfer steps) via a big switch on substate +0xd, arming reply-waits with FUN_001c3450.

### `0x55`  (S->C)
**Parsers/Handlers (S->C):**
- 0x001c9b00 snap_app_sm_pump — The central per-tick app-protocol driver: polls the socket (FUN_001ee430), then on ready dispatches ~40 sub-state handlers (create/list/roster/transfer steps) via a big switch on substate +0xd, arming reply-waits with FUN_001c3450.

### `0x59`  (S->C)
**Parsers/Handlers (S->C):**
- 0x001c9b00 snap_app_sm_pump — The central per-tick app-protocol driver: polls the socket (FUN_001ee430), then on ready dispatches ~40 sub-state handlers (create/list/roster/transfer steps) via a big switch on substate +0xd, arming reply-waits with FUN_001c3450.

### `0x62`  (C->S)
**Builders (C->S):**
- 0x001ca410 snap_lookup_resolve_sm — Sub-SM issuing a lookup/keepalive query: phase 0 sends marker 0x62, phase 1 sends 0x63 and resolves via FUN_001c08e0, phase 2 sends 0x64 and on count>=100 sets result state 3.

### `0x63`  (C->S)
**Builders (C->S):**
- 0x001ca410 snap_lookup_resolve_sm — Sub-SM issuing a lookup/keepalive query: phase 0 sends marker 0x62, phase 1 sends 0x63 and resolves via FUN_001c08e0, phase 2 sends 0x64 and on count>=100 sets result state 3.

### `0x64`  (C->S)
**Builders (C->S):**
- 0x001ca410 snap_lookup_resolve_sm — Sub-SM issuing a lookup/keepalive query: phase 0 sends marker 0x62, phase 1 sends 0x63 and resolves via FUN_001c08e0, phase 2 sends 0x64 and on count>=100 sets result state 3.

### `0x6b`  (S->C)
**Parsers/Handlers (S->C):**
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.

### `0x6e`  (C->S/S->C)
**Builders (C->S):**
- 0x005c04f0 send_op6e_with_name — Allocates a txn slot, builds op 0x6e with a string payload (via 1ff0), sends the reliable command (func_0x001dcdfc, arg param_2 + count 1) for room record param_1, and sets room slot 2.
- 0x005c05c0 on_reply_create_enter_op6e — Reply handler for the create/enter (op6e) request: on success sets room-owned state 0x6ff2b1=1 and 0x6ff2b2=1, timer 0x96; on error 0x27 sets fail status and inspects reply field +4==0xf; stores UI status and triggers redraw.
- 0x005c1f30 build_msg_op6e_variant — Message builder: opcode 0x6e (arg2), 0x41 (arg1), or 0x2f (arg0) into scratch 0x7018d0, append param_2, finalize.
- 0x005c1ff0 build_msg_op6e_data — Message builder: opcode 0x6e in scratch 0x7018d0, appends param_1 then a length-prefixed string payload param_2 (strlen via 0x0010a050, bytes via bea60), finalize.

### `0x70`  (C->S)
**Builders (C->S):**
- 0x005c0750 room_commit_send_stat_op70 — If room-owned flag 0x6ff2b1 set, allocates a txn, advances 0x6ff2b1 to 3, and (if host 0x6ff2b0) sends a 'STAT' field =0x40000000 then op 0x70; otherwise invokes callback and bails.
- 0x005c2080 build_msg_op70_variant — Message builder: opcode 0x70 (arg2), 0x43 (arg1), or 0x3e (arg0) into scratch 0x7018d0, finalize (no body).

### `0x75`  (S->C)
**Parsers/Handlers (S->C):**
- 0x001d9f78 snap_app_msg_dispatch — Received-app-message sub-dispatcher: reads who-byte (conn+0x2c) reliable/set/DATA bits and 7-bit selector (conn+0x2e), byteswaps fields, then switches on (selector-3) to the per-type app callback in the conn+0x548..0x610 table (rooms/roster/chat/menus), including nested sub-selector routing for types 0x24/0x25/0x26.

### `0x7b`  (C->S)
**Builders (C->S):**
- 0x005c02b0 send_register_maxi — Allocates a txn slot, builds a register message (opcode 0x7b via 1e70) and sends a 'MAXI' (0x4d415849) reliable command tied to room record param_1 over the SN@P conn.
- 0x005c1e70 build_msg_register_variant — Message builder for the register/enter family: opcode 0x7b (arg2), 0x49 (arg1), or 0x35 (arg0) into scratch 0x7018d0, append param_2, finalize.

### `0x86`  (C->S/S->C)
**Builders (C->S):**
- 0x005c0a00 request_member_list — Zeroes roster table 0x6cdbe6 (0x460), allocates a txn, builds op 0x86 (0dc0) and sends the member-list request for room record param_1; resets roster count 0x6ca890.
- 0x005c0dc0 build_msg_op86 — Message builder: starts a message with opcode 0x86 in scratch 0x7018d0, appends param_1, finalizes.
**Parsers/Handlers (S->C):**
- 0x005c0ae0 on_reply_member_list — Member-list reply handler: iterates reply entries (count at +8), copies each member's name (FUN_005c50a0) and record into roster table 0x6cdbe6 (0x118 stride, count 0x6ca890), then stores UI status and redraws.

### `0x91`  (C->S)
**Builders (C->S):**
- 0x005c08b0 build_msg_op91 — Message builder: starts a message with opcode 0x91 in scratch 0x7018d0, appends param_1 (bea40), then finalizes (bea10/bea80).

### `0xd3`  (S->C/C->S)
**Builders (C->S):**
- 0x005c2120 send_op_d3_prepare — Sets flag 0x7005ad=1, allocates a txn, builds op 0xd3 (2250) and sends the reliable command (func_0x001de470, arg buffer 0x7004d0) with reply slot registration.
- 0x005c2250 build_msg_opd3 — Message builder: opcode 0xd3 in scratch 0x7018d0, finalize (no body).
**Parsers/Handlers (S->C):**
- 0x005c21c0 on_reply_op_d3 — Reply handler for op 0xd3: on success clears status 0x6cbc84=0; on error 0x27 sets 0xff and calls FUN_005c7e30(3); stores UI reply fields (status=result of 2250) and redraws.
