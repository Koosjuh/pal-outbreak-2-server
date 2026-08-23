# 0x005bf980 copy_shorts_0x6ce49a

| field | value |
|---|---|
| Original address | 0x005bf980 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf980 |
| Resolved name | recordA_copy_counts_0x6ce49a |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b0950 (clamps the two returned u16 to 9999, then draws them)
**Callees:** —
**Referenced globals:** 0x6ce49a — list-entry render table "record-A", stride 0x144, field @+0x00 (u16 array)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Overlay accessor thunk. Bulk-copies `count` little-endian 16-bit words out of the +0x00 field of
render-record `idx` in the 0x144-stride "record-A" table (base 0x6ce49a) into the caller's buffer.
The only observed caller (FUN_005b0950) requests `count=2` and then clamps both words to ≤9999 before
display — i.e. the +0x00 field is a pair of 4-digit numeric counters (current/max-style values) shown
in a lobby/room list row. Index is 0-based (no `-1`).

## Input / output
- `param_1` (u16 via `& 0xffff`): entry index `idx` into the 0x144-stride table.
- `param_2` (u16 via `& 0xffff`): `count` = number of u16 words to copy.
- `param_3` (u16*): destination buffer `out`.
- Returns `0` (undefined8, ignored).

## Side effects
Writes `count` u16 into `*out`. No globals modified; pure read of table memory.

## Important branches
None — single counted loop `for i in 0..count`. No bounds check on `idx` or `count` (caller supplies).

## Constants & flags
- `0x144` (324) — table stride (per-entry render record size, shared by the record-A/-B accessor family).
- `9999` — display clamp applied by caller FUN_005b0950 (4-digit field), evidence the words are decimal counters.

## Corrected reconstruction
```c
// record-A render table: base 0x6ce49a, stride 0x144, 0-based index.
// +0x00 field = u16[] numeric counters (drawn as ≤4-digit numbers).
u64 recordA_copy_counts_0x6ce49a(u16 idx, u16 count, u16 *out) {
    for (int i = 0; i < count; i++)
        out[i] = *(u16*)(idx * 0x144 + i * 2 + 0x6ce49a);   // LE, no swap
    return 0;
}
```

## Evidence
- Raw: `FUN_005bf980.c` — loop `i<(param_2&0xffff)`, src `(param_1&0xffff)*0x144 + i*2 + 0x6ce49a`.
- Caller `FUN_005b0950.c`: calls with `count=2`, then `if (9999 < out[0]) out[0]=9999; if (9999 < out[1]) out[1]=9999;` → two decimal counters.
- Sibling accessor `FUN_005bf9e0` reads a u8 at +0x12 (0x6ce4ac) of the same record.

## Remaining uncertainty
Exact domain meaning of the two counters (current/max players vs. score/limit) not runtime-confirmed;
mechanical copy is certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf980.c`  — untouched decompiler output.
