# 0x005b57a0 room_entry_field_commit

| field | value |
|---|---|
| Original address | 0x005b57a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b57a0 |
| Resolved name | room_entry_field_commit |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (menu field-commit glue, invoked by address / table)
**Callees:** FUN_005c0f00 (get selected list index), FUN_005bf940 (write field into record)
**Referenced globals:** room-list/config table `0x6c3860` (stride `0x15c`; this fn targets `+2` = `0x6c3862`)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
One member of the field-commit glue family (0x5b57a0/57e0/5820/5860/58a0/58e0/5930/5970) that writes a chosen
value into the currently-selected room-list record. It fetches the selected 1-based list index via
FUN_005c0f00 (into a local u16), then calls FUN_005bf940 with that index and a pointer to the target field of
the selected record: `(idx - 1) * 0x15c + 0x6c3862`. `0x6c3860` is the `0x15c`-stride room-list/config table
(the same one memset and flag-iterated by room_select_submit_sm 0x005ad680); `+2` (`0x6c3862`) is this fn's
specific field within each record. FUN_005bf940 performs the actual store (value derived from the index/UI).

## Input / output
- no params.
- returns `void`.

## Side effects
- Writes the `+2` field of room-list record `[idx-1]` at `0x6c3862 + (idx-1)*0x15c` (via FUN_005bf940).

## Important branches
- None at this level (all logic is in FUN_005c0f00 / FUN_005bf940).

## Constants & flags
- table base `0x6c3860`, record stride `0x15c` (348 bytes), this fn's field offset `+2`.
- index from FUN_005c0f00 is **1-based** (the `idx - 1` conversion to a 0-based record).

## Corrected reconstruction
```c
// Room-list / room-config table: 0x15c-byte records at 0x6c3860.
struct room_cfg { /*+0*/ u16 sel_id; /*+2*/ /* this fn's field */ ; /* ... 0x15c bytes ... */ };
static struct room_cfg g_room_cfg[/*10*/] /* @0x6c3860, stride 0x15c */;

void room_entry_field_commit(void)
{
    u16 idx;                                   // 1-based selected list index
    get_selected_list_index(&idx);             // FUN_005c0f00
    // target field = &g_room_cfg[idx-1] + 2  == (idx-1)*0x15c + 0x6c3862
    write_room_field(idx, (u8*)((idx - 1) * 0x15c + 0x6c3862));   // FUN_005bf940
}
```

## Evidence
- Raw: `FUN_005c0f00(&uStack_2); FUN_005bf940(uStack_2, (uStack_2-1)*0x15c + 0x6c3862);`. Stride `0x15c` and
  base `0x6c3860` match the room-list table cleared/iterated by FUN_005ad680 (10 records). Runtime-unvalidated.

## Remaining uncertainty
- What the `+2` field is (room number? attribute?) and what value FUN_005bf940 stores (from the UI vs the
  index) are not decoded — needs FUN_005bf940 / FUN_005c0f00 reconstruction and a runtime trace. The sibling
  functions (57e0…5970) write other offsets of the same record.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b57a0.c`  — untouched decompiler output.
