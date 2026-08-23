# 0x005bb610 broadcast_op11_to_room

| field | value |
|---|---|
| Original address | 0x005bb610 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bb610 |
| Resolved name | broadcast_op11_to_room (was: broadcast_to_4_handlers) |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bb670
**Callees:** FUN_005c60d0 (send_op11_word)
**Referenced globals:** 0x007006d4 connection/handler table [4] (stride 8, ptr at each +0)
**Referenced strings:** —
**Referenced opcodes:** app 0x11
**State vars:** —

## Behavioral explanation
Broadcasts a one-byte room event to every connected peer. It walks the 4-entry connection table at
`0x7006d4` (stride 8; the connection/handler pointer is the first word of each entry) and, for each
non-null slot, calls `send_op11_word(conn, &arg)` — emitting a reliable **app-opcode 0x11** control
message carrying the byte `param_2`. Four slots = the room's max of four members (matches the
`member_record`/`room_record` 4-player model). `param_1` is passed in but unused by this function.

Because `send_op11` is the PREPARE-ack/commit companion in the room-setup handshake, this is the
fan-out that pushes a room state/notify byte to all current members at once (e.g. on a member
join/leave or ready-state change).

## Input / output
- `undefined8 param_1` — **unused** here (forwarded context / caller artifact).
- `undefined1 param_2` — the event byte broadcast to each peer (placed in the op11 4-byte body[0]).
- Returns: void.

## Side effects
- Emits up to 4 reliable op11 packets (one per non-null connection slot). No local state written
  besides the 4-byte stack arg holding `param_2`.

## Important branches
- `*(int*)(0x7006d4 + i*8) != 0` → send op11 to that connection.
- `== 0` (empty slot) → skip. Loop `i = 0..3` (fixed 4 slots).

## Constants & flags
- `4` — connection-table length (room max players).
- stride `8` — per-slot size in the table at `0x7006d4` (pointer at offset 0).
- app opcode `0x11` — emitted by the callee (`send_op11_word`).

## Corrected reconstruction
```c
// Room connection table: 4 slots, {conn_ptr; ...} stride 8.
extern struct { void *conn; u32 _x; } g_room_conn[4]; // 0x007006d4

// Broadcast a single event byte to every connected room member via op11.
void broadcast_op11_to_room(u64 unused, u8 event_byte) {
    u8 arg[4];
    arg[0] = event_byte;              // op11 body[0]
    for (int i = 0; i < 4; i++) {
        int conn = *(int*)((u8*)g_room_conn + i * 8); // slot->conn
        if (conn != 0)
            send_op11_word(conn, arg); // FUN_005c60d0: reliable app-0x11 + 4-byte arg
    }
}
```

## Evidence
- Raw decompile: `auStack_4[0] = param_2;` then `do { iVar1 = *(int*)(iVar2*8 + 0x7006d4);
  if (iVar1 != 0) FUN_005c60d0(iVar1, auStack_4); iVar2++; } while (iVar2 < 4);`.
- Callee record `005c60d0_send_op11` — builds a reliable app-0x11 message with one 4-byte argument.
- 4-slot table aligns with the 4-player `room_record`/`member_record` model (structure-layouts).
  Runtime-unvalidated.

## Remaining uncertainty
The meaning of the broadcast byte (which room event) and the caller `FUN_005bb670`'s trigger are not
deep-read here; `param_1`'s intended use (unused in this frame) is unknown. The op11 wire semantics
themselves are inferred (see `send_op11` record). Mechanism/opcode High; event meaning open.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bb610.c`  — untouched decompiler output.
