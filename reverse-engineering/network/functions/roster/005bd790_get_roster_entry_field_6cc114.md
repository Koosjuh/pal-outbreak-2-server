# 0x005bd790 get_roster_entry_name_6cc114

| field | value |
|---|---|
| Original address | 0x005bd790 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bd790 |
| Resolved name | get_roster_entry_name_6cc114 |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3070 (roster query facade)
**Callees:** func_0x00109eb8 (strcpy)
**Referenced globals:** 0x6cc114 (roster-entry table, stride 0x114 — the name field @+0x10)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sibling of `get_roster_entry_idstr` (0x005bd740): reads the **name** field (offset +0x10) of roster
entry `[index]` in the 0x114-stride table at 0x6cc104 (0x6cc114 = base + 0x10). strcpy's the
NUL-terminated display name into the caller buffer. +0x10 matches the op06 scratch name field
(0x6cd682, filled from `member_record.name`).

## Input / output
- `param_1` (uint) — entry index (`& 0xff`).
- `param_2` (char* out) — destination; receives the copied name string.
- Returns 0 (constant).

## Side effects
Writes the caller's `out` buffer (strcpy). No global mutation.

## Important branches
None. Only the `& 0xff` index truncation.

## Constants & flags
- `0x114` — roster-entry stride. `0x6cc114` = table base 0x6cc104 + 0x10 (name field). `func_0x00109eb8` = strcpy.

## Corrected reconstruction
```c
int get_roster_entry_name(uint index /*&0xff*/, char *out) {
    strcpy(out, roster_entry[index & 0xff].name);   // func_0x00109eb8, 0x6cc104 + 0x10
    return 0;
}
```

## Evidence
- Raw decompile: `func_0x00109eb8(param_2, (param_1&0xff)*0x114 + 0x6cc114)`.
- +0x10 name field matches the op06 scratch layout (0x6cd682) in 0x005bb4d0.
- Runtime-unvalidated (static only).

## Remaining uncertainty
- Same table-identity caveat as the idstr getter.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bd790.c`  — untouched decompiler output.
