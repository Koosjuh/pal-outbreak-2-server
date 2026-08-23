# 0x005fa890 grid_find_match

| field | value |
|---|---|
| Original address | 0x005fa890 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fa890 |
| Resolved name | party_grid_req_is_satisfiable |
| Subsystem | roster |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005fa990
**Callees:** —
**Referenced globals:** party/roster grid (param_1 base, 4 × 0x3b0); requirement list (param_1+0x1a/0x1c, stride 4)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Single-row form of FUN_005fa700: for **one** requirement row (index `param_2`), scan the 4 party-grid
slots and return 1 as soon as an occupied slot matches that requirement's type/id (same 6↔0x5b
variant equivalence), else 0. Used by FUN_005fa990 as the cursor/selection skip predicate — "is this
requirement satisfiable by the current grid?".

## Input / output
- `param_1` (int): party grid base (slots at `base + col*0x3b0`).
- `param_2` (int): requirement row index; row fields at `base + param_2*4 + {0x1a,0x1c}`.
- **return** `undefined4`: `1` = a matching occupied slot exists; `0` = none in the 4 slots.

## Side effects
None (read-only).

## Important branches
`slot = base + col*0x3b0`, `req = base + param_2*4`:
- `slot[0x309c] == 0` → empty → next slot.
- `req[0x1a] != 0` (alt requirement):
  - `slot[0x318a] == 0`: return 1 iff `slot[0x3188]==6 && req[0x1c]=='['`.
  - else: return 1 iff `u16 slot[0x3188] == (u8)req[0x1c]`.
- `req[0x1a] == 0` (normal requirement):
  - `slot[0x318a] == 0`: return 1 iff `u16 slot[0x3188] == (u8)req[0x1c]`.
  - else: only the `req[0x1c]==6 && slot[0x3188]==0x5b` case returns 1.
- Loop exhausts 4 slots (`iVar2 > 3`) → return 0.

## Constants & flags
Identical field/constant set to FUN_005fa700: slot stride `0x3b0`, `+0x309c` occupied, `+0x3188` u16
type, `+0x318a` variant flag, `6`↔`0x5b('[')` dual-form.

## Corrected reconstruction
```c
// Returns 1 if requirement row `req_idx` is satisfied by any occupied grid slot, else 0.
int party_grid_req_is_satisfiable(int grid, int req_idx) {
    u8 *req = (u8*)(grid + req_idx*4);            // req[0x1a]=flag, req[0x1c]=type/id
    for (int col = 0; col < 4; col++) {
        u8 *slot = (u8*)(grid + col*0x3b0);
        if (slot[0x309c] == 0) continue;          // empty slot
        u16 s_type = *(u16*)(slot + 0x3188);
        s16 s_var  = *(s16*)(slot + 0x318a);
        if (req[0x1a] != 0) {                      // alt requirement
            if (s_var == 0) { if (s_type == 6 && req[0x1c] == '[') return 1; }
            else            { if (s_type == (u8)req[0x1c])        return 1; }
        } else {                                   // normal requirement
            if (s_var == 0) { if (s_type == (u8)req[0x1c])        return 1; }
            else            { if (req[0x1c] == 6 && s_type == 0x5b) return 1; }
        }
    }
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005fa890.c` (`iVar3 = param_1 + iVar2*0x3b0`).
- Byte-for-byte the inner-row logic of FUN_005fa700; caller FUN_005fa990 uses it while advancing a cursor.

## Remaining uncertainty
Same as FUN_005fa700: the dual-form character semantics and `+0x1a` flag meaning are inferred; not
runtime-validated → Medium.
