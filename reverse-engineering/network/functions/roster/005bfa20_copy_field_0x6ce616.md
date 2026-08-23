# 0x005bfa20 copy_field_0x6ce616

| field | value |
|---|---|
| Original address | 0x005bfa20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bfa20 |
| Resolved name | recordA_strcpy_name_0x6ce616 |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad890
**Callees:** func_0x00109eb8 (strcpy — 2-arg NUL-terminated string copy)
**Referenced globals:** 0x6ce616 — record-A string field, stride 0x144, **1-based** index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Overlay accessor thunk. strcpy's the NUL-terminated string field at offset 0x6ce616 of render-record
`(idx-1)` in the 0x144-stride record-A table into the caller's buffer. Index is **1-based** here (the
`-1`), unlike the `+0x00`/`+0x12` accessors which are 0-based — so callers pass a 1..N row number and
this normalizes to a 0-based slot. The field is a display string (name/title text drawn for the row).

## Input / output
- `param_1` (u16 via `& 0xffff`): 1-based entry number `idx` (slot = idx-1).
- `param_2` (char*): destination buffer for the copied string.
- Returns `0` (ignored).

## Side effects
strcpy into `*param_2` (length = source string length + NUL). No global writes.

## Important branches
None. Note: `func_0x00109eb8` is the 2-argument copy used elsewhere for name strings (contrast the
3-argument `func_0x001069a8(dst,src,0xf0)` fixed memcpy in FUN_005c0d30) → confirmed strcpy semantics.

## Constants & flags
- `0x144` — record stride.
- `(idx-1)` — 1-based indexing convention.
- `0x6ce616` — absolute base of this string array (offset within record family is >stride, so treat as its own field array).

## Corrected reconstruction
```c
// record-A string array: base 0x6ce616, stride 0x144, 1-based index (slot = idx-1).
u64 recordA_strcpy_name_0x6ce616(u16 idx, char *out) {
    strcpy(out, (const char*)((idx - 1) * 0x144 + 0x6ce616));  // func_0x00109eb8 = strcpy
    return 0;
}
```

## Evidence
- Raw: `FUN_005bfa20.c` — `func_0x00109eb8(param_2, ((param_1&0xffff)-1)*0x144 + 0x6ce616)`.
- `func_0x00109eb8` is 2-arg (strcpy) vs. the 3-arg fixed memcpy `func_0x001069a8` seen in roster_get_entry (005c0d30).

## Remaining uncertainty
Whether the string is a player name vs. room title not runtime-confirmed; `func_0x00109eb8` assumed
strcpy from arity + usage (very likely, not proven bounded).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bfa20.c`  — untouched decompiler output.
