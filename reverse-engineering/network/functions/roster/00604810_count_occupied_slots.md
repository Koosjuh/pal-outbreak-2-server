# 0x00604810 count_occupied_slots

| field | value |
|---|---|
| Original address | 0x00604810 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00604810 |
| Resolved name | count_leading_occupied_slots |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00604e70, FUN_006277a0, FUN_00627ea0, FUN_0062cfd0
**Callees:** —
**Referenced globals:** — (table via `param_1`)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Counts the number of **leading contiguous occupied** entries in a stride-0x38 member table: it
increments a counter while `entry[+0x10] != 0`, stopping at the first empty slot or at the `param_2`
limit. Because the roster is packed (occupants front-loaded), this yields the current player count —
the `N` in the "N/4P" room header. Reused across several room/table headers.

## Input / output
- `param_1` (int): base of a stride-0x38 table (member/room-member table; id/occupied byte at +0x10).
- `param_2` (uint): max entries to consider (only low byte used, `& 0xff`).
- **return** `int`: count of consecutive occupied entries from index 0 (stops at first empty).

## Side effects
None (read-only).

## Important branches
- Loop while `iVar2 < (param_2 & 0xff)` **and** `*(char*)(base + iVar2*0x38 + 0x10) != 0` → count++.
- First empty slot (`[+0x10]==0`) or reaching the limit ends the loop → return count.

## Constants & flags
- `0x38` — table entry stride.
- `+0x10` — occupied/id byte (nonzero = seated).
- `& 0xff` — limit is a byte-sized capacity (e.g. 4 for a room, 0x32 for the roster).

## Corrected reconstruction
```c
// Number of leading occupied entries (packed table) up to `limit`.
int count_leading_occupied_slots(int table, unsigned limit) {
    int n = 0;
    for (int i = 0; i < (int)(limit & 0xff); i++) {
        if (*(char*)(table + i*0x38 + 0x10) == 0) break;   // first gap ends the count
        n++;
    }
    return n;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_00604810.c`.
- Same 0x38-stride/+0x10-occupied convention as table_find_by_id (0x00604860) and table_find_first_free (0x006048f0).
- Caller FUN_00604e70 is the room-header render (feeds the current-player count).

## Remaining uncertainty
"Leading contiguous" is correct only if the table is compacted; if a middle slot can be empty the
count under-reports. Not runtime-validated → capped High.
