# 0x005bf3c0 copy_field_0x6ce5f2

| field | value |
|---|---|
| Original address | 0x005bf3c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf3c0 |
| Resolved name | get_registry_entry_field_0x6ce5f2 |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad890 (registry/room render query)
**Callees:** func_0x00109eb8 (strcpy)
**Referenced globals:** 0x6ce5f2 (registry render table, stride 0x144, **1-based** index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies a string field at offset 0x6ce5f2 of registry render entry `[index-1]` (0x144-stride table)
into the caller buffer via strcpy. The index is **1-based** (`(param_1 & 0xffff) - 1`), matching the
op06 count table (0x6cfb62, also `(room-1)*0x144`) and the room-index convention returned by
`FUN_005bf1e0(2)` — i.e. this table is keyed by the 1-based room/slot id. The field is a
NUL-terminated string (strcpy), likely the room title or a per-slot display string.

## Input / output
- `param_1` (uint) — 1-based entry id; `(param_1 & 0xffff) - 1` is the row.
- `param_2` (char* out) — destination; receives the copied string.
- Returns 0 (constant).

## Side effects
Writes the caller's `out` (strcpy). No global mutation.

## Important branches
- **1-based indexing:** `param_1 == 0` underflows to row `-1` (reads 0x144 bytes below the table). No
  guard — caller must pass a valid 1-based id. (Matches the op06/room-index convention, so id 0 is
  "no room".)

## Constants & flags
- `0x144` — registry entry stride. `0x6ce5f2` — string field offset within the entry. `func_0x00109eb8` = strcpy. Index 1-based.

## Corrected reconstruction
```c
// registry render table (0x144 stride), 1-based room/slot id
int get_registry_entry_field(uint id /*1-based, &0xffff*/, char *out) {
    strcpy(out, registry_entry[(id & 0xffff) - 1].field_0x6ce5f2);   // func_0x00109eb8
    return 0;
}
```

## Evidence
- Raw decompile: `func_0x00109eb8(param_2, ((param_1&0xffff)-1)*0x144 + 0x6ce5f2)`.
- 1-based `(idx-1)*0x144` convention matches op06 count table 0x6cfb62 and FUN_005bf1e0(2) room ids.
- Runtime-unvalidated (static only).

## Remaining uncertainty
- Exact field meaning (room title vs slot label) not runtime-confirmed; `func_0x00109eb8` treated as
  strcpy (string field) per the diff/getter family conventions.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf3c0.c`  — untouched decompiler output.
