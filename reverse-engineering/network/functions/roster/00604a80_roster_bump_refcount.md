# 0x00604a80 roster_bump_refcount

| field | value |
|---|---|
| Original address | 0x00604a80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00604a80 |
| Resolved name | roster_member_bump_refcount |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00604180, FUN_006195b0
**Callees:** FUN_00604860 (table_find_by_id)
**Referenced globals:** — (pool via `param_1`)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** entry+0x20 refcount

## Behavioral explanation
Looks up a member by id in a stride-0x38 pool (via table_find_by_id, capacity 0x32) and increments
that entry's reference count at `+0x20`, saturating at `-1` (i.e. `-1` = "pinned / never decrement").
Returns 1 on hit, -1 if the id is absent. Used when a second reference to an existing member record is
taken (e.g. the same member appears in both the roster and a room view) so the record isn't freed
while still in use.

## Input / output
- `param_1` (undefined8): pool base (stride 0x38; id at +0x10, refcount `s32` at +0x20).
- `param_2` (undefined8): pointer to the 16-byte member id to find.
- **return** `undefined4`: `1` = found & bumped; `0xffffffff (-1)` = not found.

## Side effects
- On hit: `entry[+0x20]++` unless it is already `-1` (sentinel — left untouched).

## Important branches
- `idx = table_find_by_id(pool, 0x32, id)`.
- `idx == -1` → `return -1` (no such member).
- else `rc = entry[+0x20]`: if `rc != -1` → `entry[+0x20] = rc + 1`. Return `1`.

## Constants & flags
- `0x32` — pool capacity passed to table_find_by_id.
- `0x38` — entry stride; `+0x10` id; `+0x20` `s32` refcount.
- `-1` at `+0x20` — pinned/sentinel refcount (not incremented).

## Corrected reconstruction
```c
// Increment refcount of the pool member matching `id`; 1 on hit, -1 if absent.
int roster_member_bump_refcount(void *pool, const u8 *id) {
    int idx = table_find_by_id((int)pool, 0x32, id);
    if (idx == -1) return -1;
    s32 *rc = (s32*)((int)pool + idx*0x38 + 0x20);
    if (*rc != -1) *rc = *rc + 1;               // -1 = pinned sentinel
    return 1;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_00604a80.c`.
- Delegates to table_find_by_id (0x00604860) with the 0x32/0x38 roster convention.

## Remaining uncertainty
The `-1` sentinel interpretation (pin vs. error) and the paired decrement site are not traced here;
unvalidated → capped High.
