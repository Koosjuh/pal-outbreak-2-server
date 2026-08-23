# 0x005c01d0 get_short_0x6cfa1e

| field | value |
|---|---|
| Original address | 0x005c01d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c01d0 |
| Resolved name | registryB_get_short_0x6cfa1e |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b58a0, FUN_005fc0c0, FUN_00600f50, FUN_0062e9b0, FUN_0062edc0, FUN_0062f2b0
**Callees:** —
**Referenced globals:** 0x6cfa1e — registry-B render table base, field @+0x00 (u16), stride 0x144, 0-based
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Overlay accessor thunk. Reads the +0x00 u16 field of render-record `idx` in a third 0x144-stride
table (base 0x6cfa1e, "registry-B"), heavily used (6 callers spanning list, detail and menu paths).
Its byte sibling FUN_005c0210 reads +0x12 (0x6cfa30) — again the identical (+0x00 u16, +0x12 u8) row
head shared by all three 0x144 families (record-A @0x6ce49a, family-B @0x6cf142, registry-B @0x6cfa1e).

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
- `0x6cfa30 - 0x6cfa1e = 0x12` — byte-field offset (FUN_005c0210).

## Corrected reconstruction
```c
// registry-B render table: base 0x6cfa1e, stride 0x144, 0-based. +0x00 = u16.
u64 registryB_get_short_0x6cfa1e(u16 idx, u16 *out) {
    *out = *(u16*)(idx * 0x144 + 0x6cfa1e);
    return 0;
}
```

## Evidence
- Raw: `FUN_005c01d0.c` — `*param_2 = *(u16*)((param_1&0xffff)*0x144 + 0x6cfa1e)`.
- Same +0x00/+0x12 head as record-A and family-B; note record-005c01d0.md prior note ties this family to FUN_005c0060 fills.

## Remaining uncertainty
Field semantics and the distinction between the three 0x144 render caches not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c01d0.c`  — untouched decompiler output.
