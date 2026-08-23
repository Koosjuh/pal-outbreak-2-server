# 0x001cf020 roster_id_present_in_any_group_dup

| field | value |
|---|---|
| Original address | 0x001cf020 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cf020 |
| Resolved name | roster_id_present_in_any_group_dup |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ce360 (member-list intersection test)
**Referenced globals:** 0x36c350 group/session table (16 entries × 0xc bytes)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Predicate: given a candidate group/session object `param_1`, returns 1 if that object's member-id list
intersects the member-id list of **any active entry** in the 16-slot table at `0x36c350`, else 0.
Byte-for-byte duplicate of `FUN_001ce420` (a second call site / compiler-emitted clone).

Each `0x36c350` entry is 0xc bytes: `{ u8 active; u8 pad[2]; u8 flags; void *obj; ... }`. An entry is
considered only when `active != 0`, `flags & 4`, and `obj != 0`. For each such entry it calls
`FUN_001ce360(entry->obj, param_1)`, which walks both objects' member arrays (list ptr at `+0x808`,
count at `+0x812`, stride `0x26` int32 = 0x98 bytes) and returns 1 on the first shared non-zero id.
First hit short-circuits the whole scan.

## Input / output
- `param_1` (int/ptr): the candidate group object to test (has `+0x808` list ptr, `+0x812` count).
- Returns `undefined4`: `1` = at least one shared member id found in an active group, `0` otherwise.
- `param_1 == 0` → returns 0 immediately.

## Side effects
- None (read-only membership query).

## Important branches
- `param_1 == 0` → return 0.
- Per entry gate: `active != 0 && (flags & 4) != 0 && obj != 0` → test intersection; else skip.
- `FUN_001ce360(...) != 0` → return 1 (early out).
- Loop bounded at 16 entries (`lVar2 < 0x10`); the decompiler shows `lVar2` reloaded from
  `extraout_t3` after the call (register aliasing artifact) — the loop still advances by one each pass.

## Constants & flags
- `0x36c350` — active-group table base, 16 × 0xc-byte entries.
- flag bit `0x04` at entry `+3` — "eligible/active for intersection" gate.
- `0x26` (×4 = 0x98) — per-member stride inside each object's list at `+0x808`.
- `+0x808` list pointer, `+0x812` u16 member count — the object member-array header (from `FUN_001ce360`).

## Corrected reconstruction
```c
typedef struct group_entry {   // 0xc bytes @ 0x36c350[16]
    uint8_t active;            // +0x0
    uint8_t _pad[2];           // +0x1
    uint8_t flags;             // +0x3  (bit 0x04 = eligible)
    struct group_obj *obj;     // +0x4
} group_entry;

// group_obj: member array ptr @ +0x808, u16 count @ +0x812, entry stride 0x98 (0x26 int32)

extern group_entry GROUP_TABLE[16]; // 0x36c350

// exact duplicate of FUN_001ce420
undefined4 roster_id_present_in_any_group(struct group_obj *cand)
{
    if (cand != 0) {
        for (int i = 0; i < 16; i++) {
            group_entry *e = &GROUP_TABLE[i];
            if (e->active != 0 && (e->flags & 0x04) != 0 && e->obj != 0) {
                if (member_lists_intersect(e->obj, cand))  // FUN_001ce360
                    return 1;
            }
        }
    }
    return 0;
}
```

## Evidence
- Raw: `FUN_001cf020.c` — 16-iter loop, stride `pcVar3 += 0xc`, gates `*pcVar3`, `pcVar3[3] & 4`, `*(int*)(pcVar3+4)`.
- `FUN_001ce360.c` confirms the two-list intersection: outer over `param_1+0x808` (`+0x812` count),
  inner over `param_2+0x808`, compares `*piVar` ids, stride `0x26`, returns 1 on match.
- Record notes it is identical to `FUN_001ce420`. Runtime-unvalidated.

## Remaining uncertainty
- Exact layout of the group object beyond the fields used (only `+0x808`/`+0x812` are load-bearing here).
- Why two identical copies exist (`ce420` vs `cf020`) — most likely distinct call sites inlined.
- Better name candidate: `member_list_intersects_active_group_dup`.
