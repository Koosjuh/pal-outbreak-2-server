# 0x005bfc60 copy_field_0x6cf29a

| field | value |
|---|---|
| Original address | 0x005bfc60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bfc60 |
| Resolved name | recordB_strcpy_name_0x6cf29a |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f7b30
**Callees:** func_0x00109eb8 (strcpy)
**Referenced globals:** 0x6cf29a — record family @0x6cf142 string field, stride 0x144, **1-based** index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Overlay accessor thunk. strcpy's the NUL-terminated string at 0x6cf29a of record `(idx-1)` in the
0x144-stride "record family @0x6cf142" (the parallel table to record-A). This is the first of a paired
name/name2 string set — its sibling FUN_005bfd30 copies 0x6cf2be, exactly `0x24` bytes further into
the same record. So each entry carries two strings at +0x00 and +0x24 (name / secondary label),
mirroring the roster tables' name/name2 layout.

## Input / output
- `param_1` (u16 via `& 0xffff`): 1-based entry number (slot = idx-1).
- `param_2` (char*): destination string buffer.
- Returns `0` (ignored).

## Side effects
strcpy into `*param_2`. No global writes.

## Important branches
None.

## Constants & flags
- `0x144` — record stride.
- `(idx-1)` — 1-based indexing.
- `0x6cf2be - 0x6cf29a = 0x24` — offset to the paired second string (FUN_005bfd30).

## Corrected reconstruction
```c
// record-family @0x6cf142: string #1 array base 0x6cf29a, stride 0x144, 1-based.
u64 recordB_strcpy_name_0x6cf29a(u16 idx, char *out) {
    strcpy(out, (const char*)((idx - 1) * 0x144 + 0x6cf29a));
    return 0;
}
```

## Evidence
- Raw: `FUN_005bfc60.c` — `func_0x00109eb8(param_2, ((param_1&0xffff)-1)*0x144 + 0x6cf29a)`.
- Paired with FUN_005bfd30 (0x6cf2be, +0x24); index scalars at 0x6cf142/0x6cf154 (FUN_005bfcb0/cf0).

## Remaining uncertainty
Which of the two 0x144 families (record-A @0x6ce49a vs. this @0x6cf142) drives which UI list not
runtime-confirmed; both are list-entry render caches. String role (name vs. title) unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bfc60.c`  — untouched decompiler output.
