# 0x005bf940 get_short_0x6ce49a

| field | value |
|---|---|
| Original address | 0x005bf940 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf940 |
| Resolved name | get_registry_entry_short_0x6ce49a |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad890 (registry/room render query), FUN_005b57a0
**Callees:** —
**Referenced globals:** 0x6ce49a (registry render table base, stride 0x144, **0-based** index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads the 16-bit field at the base offset 0x6ce49a of registry render entry `[index]` (0x144-stride)
into the caller out-pointer. This is the **head field** of the 0x144-stride registry entry (base of
the same table whose 1-based string field is read by 0x005bf3c0 at +0x158). Unlike the 1-based
`copy_field_0x6ce5f2`, this accessor is **0-based** (`(param_1 & 0xffff) * 0x144`) — the two callers
(`FUN_005ad890` render query, `FUN_005b57a0`) index rows directly. The u16 head field is a class of
id/type/count scalar drawn per registry row.

## Input / output
- `param_1` (uint) — 0-based entry index (`& 0xffff`).
- `param_2` (u16* out) — destination; receives the entry's +0x00 u16.
- Returns 0 (constant).

## Side effects
Writes `*out`. No global mutation.

## Important branches
None. Only the `& 0xffff` index truncation. No bounds check.

## Constants & flags
- `0x144` — registry entry stride. `0x6ce49a` — table base / head field (+0x00). Index 0-based.
- Note: SM writes at 0x6ce49c (base + 2); this accessor reads 0x6ce49a (base + 0) — a different sub-field.

## Corrected reconstruction
```c
// registry render table (0x144 stride), 0-based index; +0x00 u16 head field
int get_registry_entry_short(uint index /*&0xffff*/, u16 *out) {
    *out = registry_entry[index & 0xffff].head_u16;   // *(u16*)(idx*0x144 + 0x6ce49a)
    return 0;
}
```

## Evidence
- Raw decompile: `*param_2 = *(u16*)((param_1&0xffff)*0x144 + 0x6ce49a)`.
- Same 0x144-stride table as 0x005bf3c0 (0x6ce5f2 = 0x6ce49a + 0x158); shared caller FUN_005ad890.
- Runtime-unvalidated (static only).

## Remaining uncertainty
- 0-based here vs 1-based in the sibling copy (0x005bf3c0) implies either two distinct tables sharing a
  layout or a deliberate off-by-one keying; not runtime-disambiguated. Head-field meaning unknown.
- Prior note flags 0x6ce49a (read) vs 0x6ce49c (SM write) offset mismatch — a possible +2 sub-field split.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf940.c`  — untouched decompiler output.
