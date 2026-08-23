# 0x005bfcb0 get_short_0x6cf142

| field | value |
|---|---|
| Original address | 0x005bfcb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bfcb0 |
| Resolved name | recordB_get_short_0x6cf142 |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ada90, FUN_005f7b30, FUN_005b57e0
**Callees:** —
**Referenced globals:** 0x6cf142 — record-family-B base, field @+0x00 (u16), stride 0x144, 0-based
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Overlay accessor thunk. Reads the +0x00 u16 field of render-record `idx` in the 0x144-stride
"record-family @0x6cf142" (the parallel table to record-A @0x6ce49a). 0-based index. This is the
family's leading numeric field — its byte sibling FUN_005bfcf0 reads +0x12 (0x6cf154), the same
relative layout as record-A's (+0x00 u16, +0x12 u8), i.e. this is a structurally identical list-row
cache used by a different list/screen (three callers span both fill and render paths).

## Input / output
- `param_1` (u16 via `& 0xffff`): entry index `idx`.
- `param_2` (u16*): destination.
- Returns `0` (ignored).

## Side effects
Writes one u16 to `*param_2`.

## Important branches
None.

## Constants & flags
- `0x144` — stride.
- `0x6cf154 - 0x6cf142 = 0x12` — byte-field offset (FUN_005bfcf0), matching record-A's +0x12.

## Corrected reconstruction
```c
// record-family-B: base 0x6cf142, stride 0x144, 0-based. +0x00 = u16.
u64 recordB_get_short_0x6cf142(u16 idx, u16 *out) {
    *out = *(u16*)(idx * 0x144 + 0x6cf142);
    return 0;
}
```

## Evidence
- Raw: `FUN_005bfcb0.c` — `*param_2 = *(u16*)((param_1&0xffff)*0x144 + 0x6cf142)`.
- Layout parallels record-A (FUN_005bf980/9e0): same +0x00 u16 / +0x12 u8 pattern.

## Remaining uncertainty
Field semantics (id/count/handle) and which UI list this family backs vs. record-A — not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bfcb0.c`  — untouched decompiler output.
