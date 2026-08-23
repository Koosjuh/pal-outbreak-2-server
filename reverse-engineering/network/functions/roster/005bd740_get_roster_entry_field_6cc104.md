# 0x005bd740 get_roster_entry_idstr_6cc104

| field | value |
|---|---|
| Original address | 0x005bd740 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bd740 |
| Resolved name | get_roster_entry_idstr_6cc104 |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3070 (roster query facade)
**Callees:** func_0x00109eb8 (strcpy)
**Referenced globals:** 0x6cc104 (roster-entry table, stride 0x114 — the idstr field @+0x00)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads the **idstr** field (offset +0x00) of roster entry `[index]` in the 0x114-stride table at
0x6cc104 — the persistent roster-entry table that op06 member-JOIN (0x005bb4d0, event 0x1f) fills from
its scratch. `func_0x00109eb8` is a strcpy: the entry's NUL-terminated ASCII id string is copied into
the caller-supplied `out`. The +0x00 field matches the op06 scratch idstr (8 ASCII digits from
`FUN_005c50a0`).

## Input / output
- `param_1` (uint) — entry index (`& 0xff`).
- `param_2` (char* out) — destination buffer; receives the copied idstr.
- Returns 0 (constant).

## Side effects
Writes the caller's `out` buffer (strcpy). No global mutation.

## Important branches
None. Only the `& 0xff` index truncation (table addressed by an 8-bit index).

## Constants & flags
- `0x114` — roster-entry stride. `0x6cc104` — table base / idstr field. `func_0x00109eb8` = strcpy.

## Corrected reconstruction
```c
// roster_entry table @0x6cc104, stride 0x114: char idstr[0x10]@+0; char name[0x14]@+0x10; u8 stats[0xf0]@+0x24
int get_roster_entry_idstr(uint index /*&0xff*/, char *out) {
    strcpy(out, roster_entry[index & 0xff].idstr);   // func_0x00109eb8, base 0x6cc104
    return 0;
}
```

## Evidence
- Raw decompile: `func_0x00109eb8(param_2, (param_1&0xff)*0x114 + 0x6cc104)`.
- 0x114 stride + +0/+0x10/+0x24 field layout matches the op06 scratch (0x6cd672) filled by 0x005bb4d0.
- Runtime-unvalidated (static only).

## Remaining uncertainty
- Whether this table is the same buffer the drawn 0x3b0-stride roster (0x6c7c2c) derives from, or an
  intermediate parse buffer, is not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bd740.c`  — untouched decompiler output.
