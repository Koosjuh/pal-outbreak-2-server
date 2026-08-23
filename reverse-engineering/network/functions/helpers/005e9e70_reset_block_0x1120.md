# 0x005e9e70 reset_block_0x1120

| field | value |
|---|---|
| Original address | 0x005e9e70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9e70 |
| Resolved name | markup_meta_block_reset |
| Subsystem | helpers |
| Relevance | unrelated (UI rich-text markup, not SN@P) |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup tag-dispatch table)
**Callees:** func_0x00106b60 (memset) — leaf
**Referenced globals:** iRam007012a0; +0x1120 (0x108-byte meta-tag state block)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1120..+0x1227

## Behavioral explanation
Markup handler that clears the entire 0x108-byte **meta-tag state block** starting at `+0x1120`.
That block is the working area for the meta/attribute tag group decoded by the `ui/` handlers in
this batch: `+0x1120` = "keyword matched" flag (`markup_meta_match_keyword` 0x9ea0), `+0x1124` =
parsed int value (`markup_meta_parse_value` 0x9ef0), `+0x1128..` = parsed string
(`markup_meta_copy_string` 0x9f40). Zeroing the whole region resets match flag, value, and string in
one shot — i.e. the open/reset of a `<meta ...>`-style element before its attributes are parsed.

## Input / output
- No parameters (void). Returns `0`.

## Side effects
- `memset(g_markup+0x1120, 0, 0x108)` — clears meta flag/value/string block.

## Important branches
- None (straight-line memset).

## Constants & flags
- `0x108` (264) — size of the meta-tag state block.

## Corrected reconstruction
```c
int markup_meta_block_reset(void)
{
    memset(g_markup->meta_block /*+0x1120*/, 0, 0x108); // clear matched-flag, value, string
    return 0;
}
```

## Evidence
- Raw: `memset(iRam007012a0 + 0x1120, 0, 0x108)`.
- Block layout corroborated by 0x9ea0 (`+0x1120`), 0x9ef0 (`+0x1124`), 0x9f40/0x9f80 (`+0x1128`).
- Runtime-unvalidated.

## Remaining uncertainty
- Whether reset happens on `<meta` open or close; both consistent with a full clear.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9e70.c`  — untouched decompiler output.
