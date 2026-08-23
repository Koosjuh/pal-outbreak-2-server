# 0x005eb350 markup_attr_align_f17

| field | value |
|---|---|
| Original address | 0x005eb350 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb350 |
| Resolved name | markup_attr_keyword_enum_f17 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0 (next-attr-value), FUN_005ec920 (keyword→enum)
**Referenced globals:** g_mkp+0xf17 (u8 enum attribute slot)
**Referenced strings:** keyword table @ 0x648350 (0x20 bytes = 4 × 8-byte entries)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Keyword-valued markup attribute handler, identical in shape to 0x5eb300 but using a DIFFERENT keyword
table (`0x648350`) and DIFFERENT destination slot (`g_mkp+0xf17`). Extracts the attribute value, matches
it against the table via `FUN_005ec920`, and stores the enum byte at `+0xf17` unconditionally. Given the
`+0xf16`/`+0xf17` adjacency and shared 4-entry tables, this is most likely the vertical-align enum to
0x5eb300's horizontal-align. UI markup only.

## Input / output
- `param_1` — `char **cursor`; advanced.
- Return `0`.

## Side effects
- Writes `g_mkp+0xf17` (u8) = matched enum (or 0).
- Advances `*param_1`.

## Important branches
- None here; match/miss handled inside `FUN_005ec920`.

## Constants & flags
- Keyword table `0x648350`, length `0x20` (4 entries). Enum at `+0xf17`.

## Corrected reconstruction
```c
u64 markup_attr_keyword_enum_f17(char **cursor) {
    char val[0x110];
    mkp_next_attr_value(cursor, val, 0x100);                    // FUN_005ec1b0
    g_mkp->attr_f17 = mkp_keyword_to_enum(val, (KwEnt*)0x648350, 0x20); // FUN_005ec920 -> +0xf17
    return 0;
}
```

## Evidence
- Raw: `FUN_005ec1b0(param_1,buf,0x100); *(u8*)(base+0xf17)=FUN_005ec920(buf,0x648350,0x20)`.
- Byte-for-byte parallel to 0x5eb300 with table/slot swapped.
- Runtime-unvalidated.

## Remaining uncertainty
"Vertical align" is inferred from pairing with `+0xf16`; the keyword strings at `0x648350` are not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eb350.c`  — untouched decompiler output.
