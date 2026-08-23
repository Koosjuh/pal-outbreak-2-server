# 0x005c0210 get_byte_0x6cfa30

| field | value |
|---|---|
| Original address | 0x005c0210 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0210 |
| Resolved name | registryB_get_byte_0x6cfa30 |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b5860, FUN_005fc0c0, FUN_0062e9b0, FUN_0062edc0
**Callees:** —
**Referenced globals:** 0x6cfa30 — registry-B table (base 0x6cfa1e), field @+0x12 (u8), stride 0x144, 0-based
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Overlay accessor thunk. Reads the +0x12 byte of render-record `idx` in the 0x144-stride registry-B
table (base 0x6cfa1e). 0-based. Byte counterpart of FUN_005c01d0 (+0x00 u16). Completes the third
family's row head, structurally identical to record-A (FUN_005bf9e0) and family-B (FUN_005bfcf0).

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
- `0x6cfa30 - 0x6cfa1e = 0x12` — field offset.

## Corrected reconstruction
```c
// registry-B render table: base 0x6cfa1e, stride 0x144, 0-based. +0x12 = u8 flag/status.
u64 registryB_get_byte_0x6cfa30(u16 idx, u8 *out) {
    *out = *(u8*)(idx * 0x144 + 0x6cfa30);
    return 0;
}
```

## Evidence
- Raw: `FUN_005c0210.c` — `*param_2 = *(u8*)((param_1&0xffff)*0x144 + 0x6cfa30)`.
- Twin of FUN_005bf9e0 / FUN_005bfcf0 (+0x12 in each family).

## Remaining uncertainty
Byte semantics not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0210.c`  — untouched decompiler output.
