# 0x00600aa0 next_occupied_member_slot

| field | value |
|---|---|
| Original address | 0x00600aa0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00600aa0 |
| Resolved name | next_selectable_member_slot |
| Subsystem | roster |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00600b60
**Callees:** —
**Referenced globals:** roster grid @0x6c7c3c (stride 0x3b0, occupied flag +0 i.e. abs 0x6c7c3c); selection key @0x6c8afc
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Given a current 0..3 slot index and a direction, cycle (mod 4) up to 5 steps looking for the next
roster-grid slot that is both occupied **and** passes the id/key compare against `0x6c8afc`. Returns
the found slot index, or the original index if no other qualifying slot exists within a full cycle.
It is the "skip to the next joinable/selectable player" step behind the L/R member cursor.

## Input / output
- `param_1` (uint): current slot index (0..3).
- `param_2` (long): direction — `0` = decrement (previous), nonzero = increment (next).
- **return** `uint`: next qualifying slot index, or `param_1` unchanged if none found in ≤5 tries.

## Side effects
None (read-only scan).

## Important branches
- Step: `idx = (param_2==0 ? idx-1 : idx+1) & 3` (wrap within the 4-slot grid).
- Qualifies iff `*(char*)(idx*0x3b0 + 0x6c7c3c) != 0` (occupied) **and**
  `func_0x00109d70(0x6c8afc, idx*0x3b0 + 0x6c7c3c) != 0` (key compare passes) → return `idx`.
- Counter guards to `< 5` iterations; on exhaustion the return is `param_1` (the pre-loop value,
  captured in `uVar4` on the failing branch).

## Constants & flags
- `0x3b0` — roster grid slot stride (member_record).
- `0x6c7c3c` — grid slot base +0x10 region (member id field within the 0x6c7c2c grid; 0x6c7c3c = 0x6c7c2c+0x10).
- `0x6c8afc` — comparison key (the local/reference member id) [inferred].
- `& 3` — 4-slot wrap.

## Corrected reconstruction
```c
// dir: 0 = previous, nonzero = next. Returns next occupied+matching slot, or `cur` if none.
uint next_selectable_member_slot(uint cur, long dir) {
    uint idx = cur, result = cur;
    for (int tries = 0; ; tries++) {
        idx = (dir == 0) ? (idx - 1) : (idx + 1);
        idx &= 3;                                   // wrap 0..3
        u8 *slot = (u8*)(idx*0x3b0 + 0x6c7c3c);     // grid slot member-id region
        if (*slot != 0 && func_0x00109d70(0x6c8afc, slot) != 0) { result = idx; break; }
        if (++tries >= 5) { result = cur; break; }  // full cycle, nothing found
    }
    return result;
}
```
(Loop condition is a single `do/while`; the counter and `result` selection are folded as shown —
`result = idx` on success, `result = cur` on the 5-try exhaustion.)

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_00600aa0.c`.
- Caller FUN_00600b60 (member cursor advance) passes the current slot `+0x908` and a direction.

## Remaining uncertainty
Exact meaning of the `0x6c8afc` compare key (self-id vs. filter) is inferred; the `func_0x00109d70`
compare direction (skip self vs. require match) is not runtime-proven → capped High.
