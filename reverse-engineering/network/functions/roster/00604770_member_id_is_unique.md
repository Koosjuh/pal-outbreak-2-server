# 0x00604770 member_id_is_unique

| field | value |
|---|---|
| Original address | 0x00604770 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00604770 |
| Resolved name | member_id_absent_from_roster |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00603f30
**Callees:** —
**Referenced globals:** roster id table @0x70b4c0 (0x32 entries, stride 0x38, id at +0x10); self/reserved id @0x6c69cc
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Scans the 0x32-entry SN@P roster table (stride 0x38, id key at `+0x10`, i.e. base `0x70b4c0`) for a
16-byte member id equal to the argument. Returns 1 ("absent / may append") only if no live entry
collides **and** the id is not the reserved/self id at `0x6c69cc`. The comparison stops at the first
occupied entry whose id differs from `0x6c69cc` — i.e. it treats the reserved id specially. Used by
FUN_00603f30 as the de-dup / self-guard before inserting a member.

## Input / output
- `param_1` (undefined8): pointer to the candidate 16-byte member id.
- **return** `undefined4`: `1` = id unique/appendable; `0` = collision or reserved-id mismatch stop.

## Side effects
None (read-only).

## Important branches
For `i` in `0..0x31`, entry `0x70b4c0 + i*0x38`:
- `func_0x0010a338(entry, id, 0x10) != 0` (memcmp: entry id ≠ candidate) → break the scan and check:
  - `func_0x00109d70(0x6c69cc, id) == 0` (candidate == reserved/self id) → `return 0`.
  - else continue to next `i`.
- Loop finishing all 0x32 entries → `return 1` (no collision found).
- Note: the loop `break` on the first **non-matching** entry means the table is treated as a
  contiguous run keyed by `0x6c69cc`; the effective result is "the candidate id does not already sit
  in the reserved run".

## Constants & flags
- `0x32` — roster capacity (50 entries).
- `0x38` — roster entry stride.
- `+0x10` (implicit in `i*0x38 + 0x70b4c0`) — id key offset (0x70b4c0 is the id column base).
- `0x6c69cc` — reserved/self member id [inferred].

## Corrected reconstruction
```c
// Returns 1 if `id` is appendable (not already the reserved-id run), 0 on collision/mismatch.
int member_id_absent_from_roster(const u8 *id) {
    for (int i = 0; i <= 0x31; i++) {
        u8 *entry = (u8*)(i*0x38 + 0x70b4c0);           // roster id column
        if (memcmp(entry, id, 0x10) != 0)               // func_0x0010a338: differs
            return (memcmp((u8*)0x6c69cc, id) == 0) ? 0 // func_0x00109d70: is reserved id?
                                                    : 0; // (both branches yield 0 here)
    }
    return 1;                                            // walked all 0x32 with no differing entry
}
```
Note: as decompiled, the `break` path returns 0 regardless (the inner `func_0x00109d70==0` only
distinguishes which 0 it is); the sole `1` path is exhausting the table. Kept verbatim — behavior is
"return 1 only if every one of the 0x32 id columns equals the candidate", which in practice screens
the reserved-id run. Semantics flagged uncertain.

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_00604770.c`.
- Same 0x70b4c0 / 0x38-stride / 0x10-id table as draw_roster_member_row (0x006050d0) and table_find_by_id (0x00604860).

## Remaining uncertainty
The early-`break`-then-both-branches-return-0 structure is unusual; the intended predicate
(uniqueness vs. reserved-run membership) is not runtime-confirmed → capped High, name marked [inferred].
