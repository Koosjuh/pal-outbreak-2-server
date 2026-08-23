# 0x005e9300 tag_read_attr_2a3

| field | value |
|---|---|
| Original address | 0x005e9300 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9300 |
| Resolved name | tag_read_attr_2a3 |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (address-taken; dispatched from the markup tag table)
**Callees:** FUN_005ec1b0 (attribute-value extractor)
**Referenced globals:** markup-ctx base `iRam007012a0`; field `+0x2a3` (16-byte string)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x2a3

## Behavioral explanation
Markup attribute handler. Extracts the tag value into the 16-byte field `ctx+0x2a3` via
`FUN_005ec1b0`. At commit time `FUN_005ef3f0` resolves it with `FUN_005ec4f0` (name→id)
and, if valid (>= 0), stores the id into the per-glyph array slot
`ctx+0x128[ctx+0x124]` (index taken from the run's glyph counter `+0x124`). So `+0x2a3`
is a *named* per-glyph style attribute (paired with `+0x2b3`, see `tag_read_attr_2b3`).

## Input / output
- Input: `param_1` = `char**` parser cursor pointer.
- Output: `undefined8` 0 (consumed).

## Side effects
- Writes up to 16 bytes (incl NUL) to `ctx+0x2a3`; advances `*param_1`.

## Important branches
None here; validity gate (`>= 0`) is in `FUN_005ef3f0`.

## Constants & flags
- `0x10` = destination capacity; downstream `ctx+0x128[ ]` = per-glyph id array indexed by `ctx+0x124`.

## Corrected reconstruction
```c
/* +0x2a3 : 16-byte named per-glyph attr; resolved into ctx+0x128[ctx+0x124] */
undefined8 tag_read_attr_2a3(char **cursor)
{
    parse_attr_value(cursor, (u8*)g_markup_ctx + 0x2a3, 0x10);  /* FUN_005ec1b0 */
    return 0;
}
```

## Evidence
- Raw: `FUN_005ec1b0(param_1, iRam007012a0 + 0x2a3, 0x10)`.
- Consumer: `FUN_005ef3f0`: `lVar2 = FUN_005ec4f0(base+0x2a3); if (-1 < lVar2)
  *(int*)(*(s16*)(base+0x124)*4 + base+0x128) = lVar2;`. Runtime-unvalidated.

## Remaining uncertainty
Specific attribute (which glyph property) unknown; the named→id-into-glyph-array role is certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9300.c`  — untouched decompiler output.
