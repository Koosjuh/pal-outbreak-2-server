# 0x005c5060 get_room_max_players

| field | value |
|---|---|
| Original address | 0x005c5060 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5060 |
| Resolved name | get_room_max_players |
| Subsystem | rooms |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bc990
**Callees:** —
**Referenced globals:** 0x365e20 room-record table (stride 0x260); 0x365f80 = record+0x160 (detail_ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Given a 1-based room index, returns the room's **max-player capacity** (u16). The room-list is the
transport-level table at 0x365e20 with a 0x260 stride (op20 room-list page records, see
`recv_roomlist_entries` 0x001c70b0). Each 0x260 record carries at offset +0x160 (absolute
0x365f80) a pointer to a per-room *detail/stats* sub-record; the u16 at detail+0x12a is the room's
max players. This is the same field pair `get_room_list_entry` (0x005c7bd0) copies out as the "max"
count (it reads cur at detail+0x12c/300 and max at detail+0x12a into the UI entry).

## Input / output
- **param_1** (`uint`): room selector; only the low 16 bits are used, 1-based (`(idx & 0xffff) - 1`).
- **returns** (`u16`): `room[idx].detail->max_players`.
No bounds check — an out-of-range or 0 index reads garbage / faults on the NULL detail_ptr deref.

## Side effects
None (pure read).

## Important branches
None — straight-line double dereference.

## Constants & flags
- `0x260` — room_record transport stride (op20 page record).
- `0x365f80` = `0x365e20 + 0x160` — the detail_ptr field inside each record.
- `0x12a` — max-players offset inside the detail sub-record (paired with `0x12c` = current).

## Corrected reconstruction
```c
/* room-list transport table @0x365e20, 0x260-byte stride.
 * record+0x160 (== base 0x365f80) is a pointer to the detail/stats sub-record. */
typedef struct room_detail { /* [inferred] */
    /* ... */
    u16 max_players;   /* +0x12a */
    u16 cur_players;   /* +0x12c (300) */
    /* ... */
} room_detail;

u16 get_room_max_players(u32 room_sel)
{
    u32 idx = (room_sel & 0xffff) - 1;                 /* 1-based -> 0-based */
    room_detail *d = *(room_detail **)(ROOMLIST_BASE   /* 0x365e20 */
                                       + idx * 0x260
                                       + 0x160);        /* == 0x365f80 slot */
    return d->max_players;                              /* +0x12a */
}
```

## Evidence
- Raw decompile: single expression `*(u16*)(*(int*)(((p&0xffff)-1)*0x260 + 0x365f80) + 0x12a)`.
- Cross-ref 0x005c7bd0 `get_room_list_entry`: same `0x365f80` detail_ptr, reads `+0x12a` as max and
  `+300` (0x12c) as current — anchors the field semantics.
- 0x260 stride + 0x365e20 base: room_record.md (op20 transport page record); GLOBALS 0x365e20/0x365f80.
- Caller FUN_005bc990 (member/room UI path). Runtime-unvalidated.

## Remaining uncertainty
cur/max labelling of the +0x12a vs +0x12c pair is inferred from `get_room_list_entry`'s out-struct
usage, not from a runtime read. Confidence capped Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5060.c`  — untouched decompiler output.
