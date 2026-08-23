# 0x005e8e40 tag_setattr_str_bf6_expand

| field | value |
|---|---|
| Original address | 0x005e8e40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8e40 |
| Resolved name | tag_copy_arg_bf6_expand |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup-tag jump table)
**Callees:** FUN_005ec1b0 (attribute-value extractor), FUN_005e82c0 (in-place escape/token expander)
**Referenced globals:** TRC `iRam007012a0`: +0xbf6 (256-byte string attribute buffer #2)
**Referenced strings:** delimiter/table refs inside `FUN_005e82c0` (`0x6484f8`, `&PTR_DAT_006484c0`, `0x6484e8`)
**Referenced opcodes:** —
**State vars:** +0xbf6

## Behavioral explanation
Attribute-setter tag for the middle string buffer **`+0xbf6`**, with a post-processing step: after
`FUN_005ec1b0` copies the `="value"` argument into `+0xbf6`, it runs `FUN_005e82c0` to **expand escape
tokens in place**. `FUN_005e82c0` scans for a delimiter char (from `0x6484f8`), matches the following
token against a 9-entry keyword table (`&PTR_DAT_006484c0[0..8]`), replaces the delimiter with the
corresponding single character from table `0x6484e8[i]`, and shifts the tail down — i.e. it collapses
`&`-style escapes (or similar) into literal characters. So this tag holds text that may contain escape
sequences that must be resolved before rendering.

## Input / output
- `param_1` [inferred `ParseCursor* (undefined4*)`] — parse cursor, advanced by the extractor.
- Returns `0`.

## Side effects
- Writes up to 256 bytes into `+0xbf6` (extractor), then rewrites `+0xbf6` in place (expander),
  possibly shortening it. `+0xbf6` is part of the per-run trio cleared by `FUN_005ee590`.

## Important branches
- Extraction branches inside `FUN_005ec1b0`.
- Expansion loop inside `FUN_005e82c0`: for each delimiter occurrence, up to 9 table comparisons
  (`iVar2 <= 8`); unmatched delimiters are left (loop restarts at next occurrence).

## Constants & flags
- `0x100` — copy cap.
- Escape table: 9 keywords `&PTR_DAT_006484c0[0..8]` → 9 replacement bytes `0x6484e8[0..8]`; scan
  delimiter string at `0x6484f8`.

## Corrected reconstruction
```c
undefined8 tag_setattr_str_bf6_expand(ParseCursor *cur)
{
    markup_extract_attr(cur, &TRC->attrStrB /*+0xbf6*/, 0x100);  // FUN_005ec1b0
    expand_escapes_in_place(&TRC->attrStrB);                     // FUN_005e82c0
    return 0;
}

// FUN_005e82c0: replace delimiter+keyword with a single char, table-driven (9 entries)
void expand_escapes_in_place(char *s) {
    char *d;
    while ((d = strstr(s, DELIM /*0x6484f8*/)) != NULL) {
        s = d + 1;
        int i;
        for (i = 0; i <= 8; i++) {
            const char *kw = escKeyword[i];      // &PTR_DAT_006484c0[i]
            if (strncmp(d + 1, kw, strlen(kw)) == 0) break;
        }
        if (i > 8) continue;                     // no match: skip this delimiter
        *d = escChar[i];                         // 0x6484e8[i]
        memmove(d + 1, d + 1 + strlen(escKeyword[i]), /*rest incl NUL*/);
    }
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e8e40.c` (60 bytes) — extractor then `FUN_005e82c0`.
- `FUN_005e82c0.c`: `strstr`(0x0010a700)/`strlen`(0x0010a050)/`strncmp`(0x0010a338) against
  `&PTR_DAT_006484c0[iVar2]`, writes `0x6484e8[iVar2]`, shifts tail — table-driven escape collapse.
- Buffer trio membership from `FUN_005ee590.c`.
- Runtime-unvalidated.

## Remaining uncertainty
- Exact escape keywords / replacement chars (table contents at 0x6484c0/0x6484e8/0x6484f8 not dumped).
- Whether the delimiter is `&`, `\`, or `%` — inferred as an escape marker from the collapse pattern.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8e40.c`  — untouched decompiler output.
