# 0x005eb3a0 markup_attr_int_f18

| field | value |
|---|---|
| Original address | 0x005eb3a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb3a0 |
| Resolved name | markup_attr_int_or_color_f18 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0 (next-attr-value), FUN_005ec4f0 (int-or-color parse)
**Referenced globals:** g_mkp+0xf18 (u32 attribute slot)
**Referenced strings:** — (color-name table lives in FUN_005ec4f0 @ 0x648d10)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Markup attribute handler for a 32-bit numeric/color attribute with NO pass-mode gate. Extracts the value
string; if it is non-empty, parses it with `FUN_005ec4f0` (`#`-prefixed hex, else HTML color-name lookup
returning packed 0xRRGGBB, `-1` on miss) and stores the 32-bit result at `g_mkp+0xf18`. Because it is
ungated (unlike the `+0xe08`/`+0xe0c` siblings) but shares the empty-check of `+0xe0c`, this is a style
attribute applied on every pass — most plausibly a background/border color given `FUN_005ec4f0`'s color
capability. UI markup only.

## Input / output
- `param_1` — `char **cursor`; advanced.
- Return `0`.

## Side effects
- Writes `g_mkp+0xf18` (u32) when the extracted value is non-empty (else slot unchanged).
- Advances `*param_1`.

## Important branches
- `buf[0] != '\0'` -> parse and store; else -> leave `+0xf18` as-is.

## Constants & flags
- Destination `+0xf18` (u32). Buffer `0x100`. Parser returns `-1` for unrecognized color/int.

## Corrected reconstruction
```c
u64 markup_attr_int_or_color_f18(char **cursor) {
    char val[0x110];
    mkp_next_attr_value(cursor, val, 0x100);          // FUN_005ec1b0
    if (val[0] != '\0')
        g_mkp->attr_f18 = mkp_parse_int_or_color(val); // FUN_005ec4f0 -> +0xf18
    return 0;
}
```

## Evidence
- Raw: `FUN_005ec1b0(param_1,buf,0x100); if(buf[0]!=0) *(u32*)(base+0xf18)=FUN_005ec4f0(buf)`.
- `FUN_005ec4f0` = int/HTML-color parser shared with 0x5eabd0 / 0x5eac40 (see those records).
- Runtime-unvalidated.

## Remaining uncertainty
Whether `+0xf18` is a bgcolor, bordercolor, or a plain integer is inferred from the color-capable parser;
not proven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eb3a0.c`  — untouched decompiler output.
