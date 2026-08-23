# 0x005c0a00 request_member_list_op86

| field | value |
|---|---|
| Original address | 0x005c0a00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0a00 |
| Resolved name | request_member_list |
| Subsystem | roster |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fa190, FUN_005fe500, FUN_005fe8d0, FUN_0062e440 (in-room screens that need the member list)
**Callees:** FUN_005be0a0 (allocate a request/txn slot); FUN_005c0dc0 (build op selector / opcode); func_0x00106b60 (memset); func_0x001de0c0 (SN@P request-with-callback send)
**Referenced globals:** 0x6cdbe6 (raw roster table, span 0x460 = 4×0x118); 0x6ca890 (roster fill count); txn table 0x6ca97c/0x6ca97e (stride 0x20); room-record table 0x6fee68 (stride 0x24); 0x6febac (SN@P connection)
**Referenced strings:** —
**Referenced opcodes:** 0x0a member-list (wire command byte 0x86)
**State vars:** 0x6ca890

## Behavioral explanation
Issues the member-list (op0a) request for a given room and arms `on_reply_member_list` (`FUN_005c0ae0`) to fill
the roster. It first zeroes the raw roster table `0x6cdbe6` (`0x460`), then allocates a request/txn slot via
`FUN_005be0a0(1,0,param_2)`. On success (`slot != -1`) it builds the op selector with `FUN_005c0dc0(param_1)`
and stores it in the txn table (`0x6ca97c[slot]`, stride `0x20`), then sends the request over the connection
`0x6febac` for the room record indexed by `param_1 & 0xffff` in the `0x6fee68` room-record table (stride
`0x24`), with completion callback `0x5c0ae0`. It resets the roster fill count `0x6ca890` to 0 and stores the
returned transaction handle in `0x6ca97e[slot]`. Returns the allocated slot index (or -1 on allocation
failure).

## Input / output
- `param_1` (u16 room index): index into the `0x6fee68` room-record table.
- `param_2`: context passed to the allocator (`FUN_005be0a0`).
- Returns: long — allocated txn slot index, or `-1` if the allocator failed.

## Side effects
- `memset(0x6cdbe6, 0, 0x460)` — clears the raw roster.
- `0x6ca97c + slot*0x20 = FUN_005c0dc0(param_1)` (selector); `0x6ca97e + slot*0x20 = txn handle`.
- `0x6ca890 = 0` — resets roster fill counter for the incoming reply.
- SN@P send with callback `on_reply_member_list`.

## Important branches
- `FUN_005be0a0(...) == -1` (no free txn slot): skip send, return `-1`.
- else: build + send, return slot index.

## Constants & flags
- Roster span `0x460` = 4 × `0x118`.
- Txn-table stride `0x20` (fields +0x14 selector `0x6ca97c`, +0x16 handle `0x6ca97e` relative to `0x6ca968`).
- Room-record stride `0x24` at base `0x6fee68` (`room_record.md`).
- Wire command `0x86` = op0a member-list request per classification.

## Corrected reconstruction
```c
#define RAW_ROSTER    0x6cdbe6   // roster_row[4], stride 0x118
#define ROSTER_COUNT  0x6ca890
#define TXN_SEL       0x6ca97c   // stride 0x20
#define TXN_HANDLE    0x6ca97e   // stride 0x20
#define ROOM_TABLE    0x6fee68   // room_record[], stride 0x24
#define SNAP_CONN     0x6febac

long request_member_list(uint16_t room_index, void *alloc_ctx)
{
    memset((void*)RAW_ROSTER, 0, 0x460);

    long slot = alloc_txn(1, 0, alloc_ctx);              // FUN_005be0a0
    if (slot == -1)
        return -1;

    uint16_t sel = build_memberlist_op(room_index);      // FUN_005c0dc0
    int i = (int)slot * 0x20;
    *(uint16_t*)(TXN_SEL + i) = sel;

    void *room = *(void**)(ROOM_TABLE + (room_index & 0xffff) * 0x24);
    uint16_t h = snap_send_request(*(void**)SNAP_CONN, room, &on_reply_member_list); // func_0x001de0c0 -> 0x5c0ae0

    *(uint16_t*)ROSTER_COUNT = 0;
    *(uint16_t*)(TXN_HANDLE + i) = h;
    return slot;
}
```

## Evidence
- Raw decompile `FUN_005c0a00.c`: `memset(0x6cdbe6,0,0x460)`; `FUN_005be0a0(1,0,param_2)`; `FUN_005c0dc0(param_1)`
  → `0x6ca97c`; `func_0x001de0c0(uRam006febac, *(0x6fee68 + (param_1&0xffff)*0x24), 0x5c0ae0)`; `uRam006ca890 = 0`.
- Callback `0x5c0ae0` = `on_reply_member_list` (this set).
- Room-record base/stride from `room_record.md`.

## Remaining uncertainty
- Whether `FUN_005c0dc0` encodes the literal `0x86` wire byte or a higher-level selector (classification says
  op0a/0x86). The txn-table field offsets (`0x6ca97c`/`0x6ca97e`) relative to its base are inferred from the
  `*0x20` stride. Callers are distinct in-room screens; which one drives the create-room path is not isolated
  here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0a00.c`  — untouched decompiler output.
