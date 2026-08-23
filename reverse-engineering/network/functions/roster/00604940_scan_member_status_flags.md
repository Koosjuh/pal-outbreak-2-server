# 0x00604940 scan_member_status_flags

| field | value |
|---|---|
| Original address | 0x00604940 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00604940 |
| Resolved name | roster_aggregate_status |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00604180
**Callees:** —
**Referenced globals:** roster status column @0x70b4d0 (0x32 entries, stride 0x38, `s32` state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x70b4d0

## Behavioral explanation
Aggregates the per-member status column of the 0x32-entry roster into a single tri-state result.
It scans states at `0x70b4d0 + i*0x38`: if **any** entry is state `1` (PENDING/joining) it returns 1
immediately; otherwise, if any entry is state `3` (PRESENT/remote) it returns 2; if neither is seen it
returns 0. Feeds the member-sync state machine (FUN_00604180) to decide whether roster work is still
in flight (1), settled with remote members (2), or empty/idle (0).

## Input / output
- (no params)
- **return** `undefined4`: `1` any pending, else `2` any present, else `0`.

## Side effects
None (read-only aggregate).

## Important branches
For `i` in `0..0x31`, `state = *(s32*)(i*0x38 + 0x70b4d0)`:
- `state == 1` → `return 1` (short-circuit; a pending member exists).
- `state == 3` → set `saw_present = true` (keep scanning).
- Loop end: `return saw_present ? 2 : 0`.

## Constants & flags — member status enum (column @0x70b4d0)
- `0` — empty/free slot.
- `1` — PENDING (join in progress) → highest priority result.
- `3` — PRESENT / remote member seated.
- (`2` as a status value is not tested here; `2` is only the aggregate return.)

## Corrected reconstruction
```c
enum member_status { MS_EMPTY = 0, MS_PENDING = 1, MS_PRESENT = 3 };

// Tri-state roster summary: 1 = any pending, 2 = any present (none pending), 0 = none.
int roster_aggregate_status(void) {
    bool saw_present = false;
    for (int i = 0; i <= 0x31; i++) {
        int state = *(s32*)(i*0x38 + 0x70b4d0);     // roster status column
        if (state == MS_PENDING) return 1;          // short-circuit
        if (state == MS_PRESENT) saw_present = true;
    }
    return saw_present ? 2 : 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_00604940.c`.
- Status column `0x70b4d0` is the `+0x10`-relative status of the same 0x38-stride roster used by
  table_find_by_id (0x00604860) and draw_roster_member_row (0x006050d0, which indexes `0x70b4d0` for the status glyph).

## Remaining uncertainty
Enum labels (PENDING/PRESENT) inferred from the short-circuit priority; state `2`'s meaning as a
stored value is untested here → capped High.
