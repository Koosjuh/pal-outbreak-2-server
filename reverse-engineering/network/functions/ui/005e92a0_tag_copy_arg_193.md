# 0x005e92a0 tag_read_attr_193

| field | value |
|---|---|
| Original address | 0x005e92a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e92a0 |
| Resolved name | tag_read_attr_193 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (address-taken; dispatched from the markup tag table)
**Callees:** FUN_005ec1b0 (attribute-value extractor)
**Referenced globals:** markup-ctx base `iRam007012a0`; field `+0x193` (16-byte string)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x193

## Behavioral explanation
Markup attribute handler. Extracts the tag's value into the 16-byte field `ctx+0x193`
via `FUN_005ec1b0`. On the next run-commit (`FUN_005ef3f0`) this field is passed to
`FUN_005ec4f0` (name→numeric resolver); if it resolves (>= 0) the result is stored at
`ctx+0x120` — the current run's primary style/color id (`FUN_005ef3f0` also feeds
`ctx+0x120` into `FUN_005d8a70`). So `+0x193` is a *named* style attribute (e.g. a
color/font keyword) that becomes a numeric id at draw time.

## Input / output
- Input: `param_1` = `char**` parser cursor pointer.
- Output: `undefined8` 0 (consumed).

## Side effects
- Writes up to 16 bytes (incl NUL) to `ctx+0x193`; advances `*param_1`.

## Important branches
None here (inside `FUN_005ec1b0`); resolution/validity gate (`>= 0`) is in `FUN_005ef3f0`.

## Constants & flags
- `0x10` = destination capacity; downstream `ctx+0x120` = resolved primary id (see `FUN_005ef3f0`).

## Corrected reconstruction
```c
/* +0x193 : 16-byte named style attr; resolved to id ctx+0x120 by FUN_005ef3f0 */
undefined8 tag_read_attr_193(char **cursor)
{
    parse_attr_value(cursor, (u8*)g_markup_ctx + 0x193, 0x10);  /* FUN_005ec1b0 */
    return 0;
}
```

## Evidence
- Raw: `FUN_005ec1b0(param_1, iRam007012a0 + 0x193, 0x10)`.
- Consumer: `FUN_005ef3f0`: `lVar2 = FUN_005ec4f0(base+0x193); if (-1 < lVar2) *(int*)(base+0x120) = lVar2;`
  then `FUN_005d8a70(*(u32*)(base+0x120))`. Runtime-unvalidated.

## Remaining uncertainty
Precise attribute meaning (color vs font vs other id) not pinned; that it is a named→id
style attribute feeding `ctx+0x120` is certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e92a0.c`  — untouched decompiler output.
