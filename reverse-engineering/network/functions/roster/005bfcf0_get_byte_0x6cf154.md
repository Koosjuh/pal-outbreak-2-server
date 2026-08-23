# 0x005bfcf0 get_byte_0x6cf154

| field | value |
|---|---|
| Original address | 0x005bfcf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bfcf0 |
| Resolved name | recordB_get_byte_0x6cf154 |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ada90, FUN_005f7b30
**Callees:** —
**Referenced globals:** 0x6cf154 — record-family-B (base 0x6cf142), field @+0x12 (u8), stride 0x144, 0-based
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Overlay accessor thunk. Reads the +0x12 byte of render-record `idx` in the 0x144-stride
record-family-B (base 0x6cf142). 0-based. Byte counterpart of FUN_005bfcb0 (+0x00 u16). This is the
exact structural twin of record-A's FUN_005bf9e0 (+0x12 u8), confirming the two 0x144 families share
a row layout and only differ in which list/screen they cache.

## Input / output
- `param_1` (u16 via `& 0xffff`): entry index `idx`.
- `param_2` (u8*): destination byte.
- Returns `0` (ignored).

## Side effects
Writes one byte to `*param_2`.

## Important branches
None.

## Constants & flags
- `0x144` — stride.
- `0x6cf154 - 0x6cf142 = 0x12` — field offset.

## Corrected reconstruction
```c
// record-family-B: base 0x6cf142, stride 0x144, 0-based. +0x12 = u8 flag/status.
u64 recordB_get_byte_0x6cf154(u16 idx, u8 *out) {
    *out = *(u8*)(idx * 0x144 + 0x6cf154);
    return 0;
}
```

## Evidence
- Raw: `FUN_005bfcf0.c` — `*param_2 = *(u8*)((param_1&0xffff)*0x144 + 0x6cf154)`.
- Structural twin of FUN_005bf9e0 (record-A +0x12).

## Remaining uncertainty
Byte semantics (lock/type/status) not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bfcf0.c`  — untouched decompiler output.
