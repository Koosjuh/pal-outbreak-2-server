# 0x005e91c0 tag_read_str_1328

| field | value |
|---|---|
| Original address | 0x005e91c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e91c0 |
| Resolved name | tag_read_str_1328 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (address-taken; dispatched from the markup tag table)
**Callees:** FUN_005ec1b0 (attribute-value extractor)
**Referenced globals:** markup-ctx base `iRam007012a0`; field `+0x1328` (0x100-byte string)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x1328

## Behavioral explanation
Markup attribute handler; twin of `tag_read_str_1428`. Extracts the current tag's
attribute value into the 256-byte string field `ctx+0x1328` via `FUN_005ec1b0`. This is
the second of the two strings the anchor-draw routine `FUN_005ee470` forwards to
`FUN_005d9790` (drawn text for a link/highlight region).

## Input / output
- Input: `param_1` = `char**` parser cursor pointer.
- Output: `undefined8` 0 (consumed).

## Side effects
- Writes up to 256 bytes (incl NUL) to `ctx+0x1328`; advances `*param_1`.

## Important branches
None here (inside `FUN_005ec1b0`).

## Constants & flags
- `0x100` = destination capacity.

## Corrected reconstruction
```c
/* +0x1328 : 256-byte text string, 2nd draw arg in FUN_005ee470/FUN_005d9790 */
undefined8 tag_read_str_1328(char **cursor)
{
    parse_attr_value(cursor, (u8*)g_markup_ctx + 0x1328, 0x100);  /* FUN_005ec1b0 */
    return 0;
}
```

## Evidence
- Raw: `FUN_005ec1b0(param_1, iRam007012a0 + 0x1328, 0x100)`.
- Consumer: `FUN_005ee470` passes `iRam007012a0 + 0x1328` to `FUN_005d9790`. Runtime-unvalidated.

## Remaining uncertainty
Role relative to `+0x1428` (label vs value) inferred from draw-arg order.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e91c0.c`  — untouched decompiler output.
