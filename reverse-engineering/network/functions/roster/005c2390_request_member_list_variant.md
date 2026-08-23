# 0x005c2390 request_member_list_variant

| field | value |
|---|---|
| Original address | 0x005c2390 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2390 |
| Resolved name | request_member_list_visible |
| Subsystem | roster |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ffb20 (in-room roster-panel screen)
**Callees:** FUN_005be0a0 (allocate txn slot); FUN_005c27d0 (build op selector); func_0x00106b60 (memset); func_0x001de0c0 (SN@P request-with-callback send)
**Referenced globals:** 0x6ce046 (visible/packed roster table, span 0x460); 0x6cdbe6 (raw roster table, span 0x460); 0x6ca890 (roster fill count); txn table 0x6ca97c/0x6ca97e (stride 0x20); 0x86f840 (room-record pointer arg); 0x6febac (SN@P connection)
**Referenced strings:** —
**Referenced opcodes:** 0x0a member-list
**State vars:** 0x6ca890

## Behavioral explanation
Variant of `request_member_list` that targets the in-room roster panel: it clears **both** the visible/packed
roster table (`0x6ce046`) and the raw roster table (`0x6cdbe6`), each `0x460` bytes, before requesting. It
allocates a txn slot (`FUN_005be0a0(1,0,param_1)`), and on success builds the op selector via `FUN_005c27d0`,
stores it in the txn table (`0x6ca97c[slot]`, stride `0x20`), resets the roster fill count `0x6ca890`, and
sends the request over `0x6febac` for the room record pointed to by the global `0x86f840`, arming the
completion callback `0x5c2460` (`on_reply_member_list_filtered`, which fills the raw list *and* packs the
visible list + double-redraws). Returns the txn slot (or -1). This is the fuller path that ultimately sets the
`0x70047c` roster-ready gate; `request_member_list_op86` (`FUN_005c0a00`) is the simpler counterpart that does
not pack a visible list.

## Input / output
- `param_1`: allocator context (passed to `FUN_005be0a0`).
- Room target: the global room-record pointer `0x86f840` (not a parameter).
- Returns: long — txn slot index, or `-1` on allocation failure.

## Side effects
- `memset(0x6ce046,0,0x460)` and `memset(0x6cdbe6,0,0x460)` — clears both roster tables.
- `0x6ca97c + slot*0x20 = FUN_005c27d0()`; `0x6ca97e + slot*0x20 = txn handle`.
- `0x6ca890 = 0`.
- SN@P send with callback `on_reply_member_list_filtered` (`0x5c2460`).

## Important branches
- `FUN_005be0a0(...) == -1`: skip send, return `-1`.
- else: build + send, return slot.

## Constants & flags
- Two roster spans `0x460` each (4 × `0x118`).
- Txn-table stride `0x20`; room-record source is global `0x86f840`.

## Corrected reconstruction
```c
#define VIS_ROSTER    0x6ce046   // packed/visible roster[4], stride 0x118
#define RAW_ROSTER    0x6cdbe6   // raw roster[4], stride 0x118
#define ROSTER_COUNT  0x6ca890
#define TXN_SEL       0x6ca97c   // stride 0x20
#define TXN_HANDLE    0x6ca97e
#define ROOM_PTR      0x86f840   // room-record pointer (global)
#define SNAP_CONN     0x6febac

long request_member_list_visible(void *alloc_ctx)
{
    memset((void*)VIS_ROSTER, 0, 0x460);
    memset((void*)RAW_ROSTER, 0, 0x460);

    long slot = alloc_txn(1, 0, alloc_ctx);              // FUN_005be0a0
    if (slot == -1)
        return -1;

    uint16_t sel = build_memberlist_op();                // FUN_005c27d0
    int i = (int)slot * 0x20;
    *(uint16_t*)(TXN_SEL + i) = sel;
    *(uint16_t*)ROSTER_COUNT  = 0;

    uint16_t h = snap_send_request(*(void**)SNAP_CONN,
                                   *(void**)ROOM_PTR,
                                   &on_reply_member_list_filtered);  // func_0x001de0c0 -> 0x5c2460
    *(uint16_t*)(TXN_HANDLE + i) = h;
    return slot;
}
```

## Evidence
- Raw decompile `FUN_005c2390.c`: two `memset(...,0x460)` on `0x6ce046` and `0x6cdbe6`; `FUN_005be0a0(1,0,param_1)`;
  `FUN_005c27d0()` → `0x6ca97c`; `func_0x001de0c0(uRam006febac, uRam0086f840, 0x5c2460)`; `uRam006ca890 = 0`.
- Callback `0x5c2460` = `on_reply_member_list_filtered` (this set), which packs `0x6cdbe6`→`0x6ce046` — hence
  both tables are pre-cleared here.

## Remaining uncertainty
- What populates the global room pointer `0x86f840` (vs the indexed room-record table used by `FUN_005c0a00`).
  Selector builder `FUN_005c27d0` internals not traced. Whether both request variants coexist per screen or one
  supersedes the other in the create-room flow is unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2390.c`  — untouched decompiler output.
