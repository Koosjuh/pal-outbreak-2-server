# 0x005bfd30 copy_field_0x6cf2be

| field | value |
|---|---|
| Original address | 0x005bfd30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bfd30 |
| Resolved name | recordB_strcpy_name2_0x6cf2be |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ada90
**Callees:** func_0x00109eb8 (strcpy)
**Referenced globals:** 0x6cf2be — record-family-B string #2, stride 0x144, **1-based** index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Overlay accessor thunk. strcpy's the second NUL-terminated string field (offset 0x6cf2be) of record
`(idx-1)` in the 0x144-stride record-family-B. Paired with FUN_005bfc60 (string #1 at 0x6cf29a); the
two are `0x24` apart within the same entry → per-entry {name @+0x00-rel, name2 @+0x24-rel}. 1-based
index (the `-1`), matching the other strcpy accessors.

## Input / output
- `param_1` (u16 via `& 0xffff`): 1-based entry number (slot = idx-1).
- `param_2` (char*): destination string buffer.
- Returns `0` (ignored).

## Side effects
strcpy into `*param_2`.

## Important branches
None.

## Constants & flags
- `0x144` — stride.
- `(idx-1)` — 1-based indexing.
- `0x6cf2be = 0x6cf29a + 0x24` — second-string offset relative to string #1.

## Corrected reconstruction
```c
// record-family-B: string #2 array base 0x6cf2be, stride 0x144, 1-based.
u64 recordB_strcpy_name2_0x6cf2be(u16 idx, char *out) {
    strcpy(out, (const char*)((idx - 1) * 0x144 + 0x6cf2be));
    return 0;
}
```

## Evidence
- Raw: `FUN_005bfd30.c` — `func_0x00109eb8(param_2, ((param_1&0xffff)-1)*0x144 + 0x6cf2be)`.
- Paired with FUN_005bfc60 (string #1, delta 0x24).

## Remaining uncertainty
Whether name2 is a secondary label/host name vs. status text not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bfd30.c`  — untouched decompiler output.
