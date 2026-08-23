# 0x005eb300 markup_attr_align_f16

| field | value |
|---|---|
| Original address | 0x005eb300 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb300 |
| Resolved name | markup_attr_keyword_enum_f16 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0 (next-attr-value), FUN_005ec920 (keyword→enum)
**Referenced globals:** g_mkp+0xf16 (u8 enum attribute slot)
**Referenced strings:** keyword table @ 0x648320 (0x20 bytes = 4 × 8-byte entries)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Markup attribute handler for a keyword-valued (enumerated) attribute — an alignment/style enum. Extracts
the attribute value string, uppercases it and matches it against the 32-byte keyword table at `0x648320`
via `FUN_005ec920`, and stores the resulting enum byte at `g_mkp+0xf16` unconditionally (no pass gate).
`FUN_005ec920` entries are 8 bytes `{ char* keyword; u8 len@+4; u8 enum@+5 }`; it returns the `+5` byte
of the first `strncmp`-matching entry, or `0` if none match. Table size `0x20` -> 4 candidate keywords
(e.g. LEFT/CENTER/RIGHT/…). UI markup only. Sibling of 0x5eb350 (writes `+0xf17`).

## Input / output
- `param_1` — `char **cursor`; advanced past the attribute.
- Return `0`.

## Side effects
- Writes `g_mkp+0xf16` (u8) = matched enum (or 0 on miss).
- Advances `*param_1`.

## Important branches
- Match logic is inside `FUN_005ec920` (linear scan of 4 entries; miss -> 0). No branch in this fn.

## Constants & flags
- Keyword table `0x648320`, byte length `0x20` (4 entries). Enum stored at `+0xf16`.
- The matcher uppercases via `DAT_006493b0` before comparing.

## Corrected reconstruction
```c
// KwEnt { const char *kw; u8 len; u8 code; } packed 8 bytes
u64 markup_attr_keyword_enum_f16(char **cursor) {
    char val[0x110];
    mkp_next_attr_value(cursor, val, 0x100);                    // FUN_005ec1b0
    g_mkp->attr_f16 = mkp_keyword_to_enum(val, (KwEnt*)0x648320, 0x20); // FUN_005ec920 -> +0xf16
    return 0;
}
```

## Evidence
- Raw: `FUN_005ec1b0(param_1,buf,0x100); *(u8*)(base+0xf16) = FUN_005ec920(buf, 0x648320, 0x20)`.
- `FUN_005ec920`: uppercases input, iterates `(size>>3)` entries of 8 bytes, `strncmp(input,
  entry.kw, entry.len)`, returns `entry[+5]`; else 0 — read from its decompile.
- Runtime-unvalidated.

## Remaining uncertainty
Which attribute (horizontal align vs another style enum) and the concrete keyword strings at `0x648320`
are not dumped here; "align" is inferred from the adjacent `+0xf16`/`+0xf17` pair.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eb300.c`  — untouched decompiler output.
