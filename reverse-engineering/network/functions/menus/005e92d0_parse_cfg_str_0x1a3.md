# 0x005e92d0 tag_read_str_1a3

| field | value |
|---|---|
| Original address | 0x005e92d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e92d0 |
| Resolved name | tag_read_str_1a3 |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (address-taken; dispatched from the markup tag table)
**Callees:** FUN_005ec1b0 (attribute-value extractor)
**Referenced globals:** markup-ctx base `iRam007012a0`; field `+0x1a3` (0x100-byte string)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x1a3

## Behavioral explanation
Markup attribute handler. Extracts the tag value into the 256-byte string `ctx+0x1a3`
via `FUN_005ec1b0`. At run-commit time `FUN_005ef3f0` passes `ctx+0x1a3` to `FUN_005d95f0`
(a text/format consumer) when the draw-enabled flags are clear — so `+0x1a3` holds the
run's text/format payload string.

## Input / output
- Input: `param_1` = `char**` parser cursor pointer.
- Output: `undefined8` 0 (consumed).

## Side effects
- Writes up to 256 bytes (incl NUL) to `ctx+0x1a3`; advances `*param_1`.

## Important branches
None here (inside `FUN_005ec1b0`).

## Constants & flags
- `0x100` = destination capacity.

## Corrected reconstruction
```c
/* +0x1a3 : 256-byte text/format string, consumed by FUN_005d95f0 via FUN_005ef3f0 */
undefined8 tag_read_str_1a3(char **cursor)
{
    parse_attr_value(cursor, (u8*)g_markup_ctx + 0x1a3, 0x100);  /* FUN_005ec1b0 */
    return 0;
}
```

## Evidence
- Raw: `FUN_005ec1b0(param_1, iRam007012a0 + 0x1a3, 0x100)`.
- Consumer: `FUN_005ef3f0` → `FUN_005d95f0(base+0x1a3)` under `+0x186==0 && +0xe96b==0`.
  Runtime-unvalidated.

## Remaining uncertainty
Exact role of the `FUN_005d95f0` consumer (glyph layout vs substitution) not resolved;
copy mechanic and the fact it is a drawn string are certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e92d0.c`  — untouched decompiler output.
