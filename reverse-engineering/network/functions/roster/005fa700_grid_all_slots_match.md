# 0x005fa700 grid_all_slots_match

| field | value |
|---|---|
| Original address | 0x005fa700 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fa700 |
| Resolved name | party_grid_satisfies_all_reqs |
| Subsystem | roster |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005fa490
**Callees:** —
**Referenced globals:** roster/party grid (param_1 base, 4 slots × 0x3b0 stride — the member_record grid @0x6c7c2c); requirement list (param_1+0x1a, stride 4, count at param_1+0xa)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Predicate: does the local 4-slot party/roster grid satisfy **every** entry in a requirement list?
For each requirement row it walks the 4 grid slots (stride **0x3b0** = member_record stride) and
looks for at least one occupied slot whose character-type/id matches the requirement (with a
type-6 ↔ type-0x5b equivalence gated on the slot's variant flag). If any requirement row finds no
matching slot it returns 0 immediately; only when all rows are satisfied does it return 1. This is a
gate on a character/scenario selection (e.g. "this scenario needs these characters present").

## Input / output
- `param_1` (int): base of the party grid block. Grid slots at `base + col*0x3b0` (col 0..3).
  Requirement list is a stride-4 array whose row `r` fields live at `base + r*4 + 0x1a/0x1c`; row
  count is the `s16` at `base + 0xa`.
- **return** `undefined4`: `1` = all requirement rows matched; `0` = at least one row unmatched.

## Side effects
None. Pure read-only predicate over the grid + requirement list.

## Important branches
Per (requirement row `r`, grid slot `col`), with `slot = base + col*0x3b0`, `req = base + r*4`:
- `slot[0x309c] == 0` → slot empty → skip to next slot.
- **req flag `req[0x1a] == 0`** (normal requirement):
  - slot variant `slot[0x318a] == 0` (plain): match iff `u16 slot[0x3188] == (u8)req[0x1c]` (type/id equal).
  - slot variant `!= 0`: match iff `req[0x1c] == 6 && slot[0x3188] == 0x5b` (the 6→0x5b alt-form).
- **req flag `req[0x1a] != 0`** (alt requirement):
  - slot variant `== 0`: match iff `slot[0x3188] == 6 && req[0x1c] == '[' (0x5b)`.
  - slot variant `!= 0`: match iff `u16 slot[0x3188] == (u8)req[0x1c]`.
- A match sets `row_ok = true`. After the 4-slot scan, `!row_ok` → `return 0`.
- Outer loop ends (returns 1) when `row_index+1 >= s16 base[0xa]`.

## Constants & flags
- `0x3b0` — grid slot stride (member_record; matches roster table @0x6c7c2c stride 0x3b0 ×4).
- `+0x309c` — slot occupied flag (nonzero = seated).
- `+0x3188` (u16) — slot character type/id.
- `+0x318a` (s16) — slot variant/alt-form flag (selects which equivalence rule applies).
- `6` ↔ `0x5b ('[')` — the two encodings of one character keyed by the variant flag [inferred: dual-form char].

## Corrected reconstruction
```c
// Party grid: 4 member_record slots at grid + col*0x3b0.
// Requirement list: stride-4 rows; row r fields at grid + r*4 + {0x1a flag, 0x1c type}; count s16 grid[0xa].
int party_grid_satisfies_all_reqs(int grid) {
    for (int row = 0; row < *(s16*)(grid + 0xa); row++) {
        u8 *req = (u8*)(grid + row*4);            // req[0x1a]=flag, req[0x1c]=type/id
        bool row_ok = false;
        for (int col = 0; col < 4; col++) {
            u8 *slot = (u8*)(grid + col*0x3b0);
            if (slot[0x309c] == 0) continue;      // empty slot
            u16 s_type = *(u16*)(slot + 0x3188);
            s16 s_var  = *(s16*)(slot + 0x318a);
            if (req[0x1a] == 0) {                 // normal requirement
                if (s_var == 0) { if (s_type == (u8)req[0x1c]) row_ok = true; }
                else            { if (req[0x1c] == 6 && s_type == 0x5b) row_ok = true; }
            } else {                              // alt requirement
                if (s_var == 0) { if (s_type == 6 && req[0x1c] == '[') row_ok = true; }
                else            { if (s_type == (u8)req[0x1c]) row_ok = true; }
            }
        }
        if (!row_ok) return 0;                    // a requirement went unmet
    }
    return 1;                                     // every requirement satisfied
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005fa700.c` (inner `iVar5 = base + (col*0x10*4 + col*-5)*0x10 = base + col*0x3b0` confirms the 0x3b0 stride).
- Sibling FUN_005fa890 is the single-row form of the same test; same 0x309c/0x3188/0x318a fields and 6/0x5b rule.
- Grid stride 0x3b0 matches member_record / roster table @0x6c7c2c (structure-layouts/member_record.md).

## Remaining uncertainty
Semantics of the 6↔0x5b dual-form (which character) and the meaning of the `+0x1a` requirement flag
are inferred, not runtime-proven. What FUN_005fa490 does with the 0/1 result (which selection it
gates) is not traced here → Medium.
