# 0x005bf9e0 get_byte_0x6ce4ac

| field | value |
|---|---|
| Original address | 0x005bf9e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf9e0 |
| Resolved name | recordA_get_byte_0x6ce4ac |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad890
**Callees:** —
**Referenced globals:** 0x6ce4ac — record-A render table (base 0x6ce49a), field @+0x12 (u8), stride 0x144
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Overlay accessor thunk. Reads a single byte from the +0x12 field of render-record `idx` in the
0x144-stride "record-A" table (the same table whose +0x00 holds the two decimal counters read by
FUN_005bf980). 0-based index. The byte is a per-entry flag/status/small-count drawn for the row.

## Input / output
- `param_1` (u16 via `& 0xffff`): entry index `idx`.
- `param_2` (u8*): destination — receives the byte.
- Returns `0` (ignored).

## Side effects
Writes one byte to `*param_2`. No global writes.

## Important branches
None (straight-line load/store).

## Constants & flags
- `0x144` — record-A stride.
- `0x6ce4ac - 0x6ce49a = 0x12` — this field's offset inside record-A.

## Corrected reconstruction
```c
// record-A: base 0x6ce49a, stride 0x144, 0-based. +0x12 = u8 status/flag byte.
u64 recordA_get_byte_0x6ce4ac(u16 idx, u8 *out) {
    *out = *(u8*)(idx * 0x144 + 0x6ce4ac);
    return 0;
}
```

## Evidence
- Raw: `FUN_005bf9e0.c` — `*param_2 = *(u8*)((param_1&0xffff)*0x144 + 0x6ce4ac)`.
- Shares the 0x144 record with FUN_005bf980 (offset delta 0x12).

## Remaining uncertainty
Semantic role of the byte (lock flag vs. player count vs. type) not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf9e0.c`  — untouched decompiler output.
