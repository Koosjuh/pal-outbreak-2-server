# 0x005e94c0 tag_read_enum_4e4

| field | value |
|---|---|
| Original address | 0x005e94c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e94c0 |
| Resolved name | tag_read_enum_4e4 |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (address-taken; dispatched from the markup tag table)
**Callees:** FUN_005ec1b0 (attribute-value extractor); FUN_005ec920 (keyword→enum table lookup)
**Referenced globals:** markup-ctx base `iRam007012a0`; field `+0x4e4` (enum byte)
**Referenced strings:** keyword table @0x6482b0 (0x48 bytes = 9 entries × 8-byte stride)
**Referenced opcodes:** —
**State vars:** ctx+0x4e4

## Behavioral explanation
Enumerated-attribute handler. Extracts the tag value into a 256-byte stack buffer via
`FUN_005ec1b0`, then resolves it against the keyword table at `0x6482b0` with
`FUN_005ec920`, storing the resulting enum byte at `ctx+0x4e4`. `FUN_005ec920` case-folds
the token through `DAT_006493b0`, then linear-scans the table (entries `{const char *kw;
u8 kwlen; …; u8 value@+5}`, stride 8, count = `0x48 >> 3 = 9`) using a `strncmp`-style
compare (`func_0x0010a338`); on match it returns the entry's value byte, else 0. So this
maps a named keyword to one of ~9 enum values for a block/segment property.

## Input / output
- Input: `param_1` = `char**` parser cursor pointer.
- Output: `undefined8` 0 (consumed).

## Side effects
- Writes one byte to `ctx+0x4e4` (the resolved enum, or 0 if no keyword matched).
- Advances `*param_1`.

## Important branches
- Inside `FUN_005ec920`: loop over up to 9 table entries; first `strncmp==0` returns that
  entry's value; fall-through (no match) returns 0 → `ctx+0x4e4 = 0` (default enum).

## Constants & flags
- Table `0x6482b0`, `0x48` bytes, stride 8 → 9 keyword→value entries.
- `DAT_006493b0` = case-fold table used to normalize the token before compare.
- `ctx+0x4e4` = 1-byte enum; reset to `0` region-wide by `FUN_005ef1a0` (block reset).

## Corrected reconstruction
```c
/* Enum attribute: keyword -> one of ~9 values via table@0x6482b0, stored at ctx+0x4e4 */
undefined8 tag_read_enum_4e4(char **cursor)
{
    u8 buf[0x100];
    parse_attr_value(cursor, buf, 0x100);                 /* FUN_005ec1b0 */
    u8 val = keyword_to_enum(buf, KW_TABLE_6482b0, 0x48); /* FUN_005ec920; 0x48/8 = 9 entries */
    *(u8*)(g_markup_ctx + 0x4e4) = val;                   /* 0 if no match */
    return 0;
}
```

## Evidence
- Raw: `FUN_005ec1b0(param_1, buf, 0x100); uVar1 = FUN_005ec920(buf, 0x6482b0, 0x48);
  *(u8*)(iRam007012a0 + 0x4e4) = uVar1;`.
- `FUN_005ec920`: case-fold via `DAT_006493b0`, table stride 8, count `param_3>>3`,
  compare `func_0x0010a338`, return `*(u8*)(entry+5)`. Runtime-unvalidated.

## Remaining uncertainty
The keyword set / enum meaning (e.g. alignment, wrap mode, block type) not resolved (table
literals not dumped); the lookup mechanics and 9-entry count are certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e94c0.c`  — untouched decompiler output.
