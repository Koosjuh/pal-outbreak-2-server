# 0x005e8f70 tag_read_name_1528

| field | value |
|---|---|
| Original address | 0x005e8f70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8f70 |
| Resolved name | tag_read_name_1528 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (address-taken; dispatched from the markup tag table)
**Callees:** FUN_005ec1b0 (attribute-value extractor)
**Referenced globals:** markup-ctx base `iRam007012a0`; field `+0x1528` (16-byte name)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x1528

## Behavioral explanation
Markup attribute handler. Calls the shared `KEY="value"` value extractor
`FUN_005ec1b0` to pull the attribute value for the current tag into the 16-byte field
`ctx+0x1528`, advancing the parser cursor (`param_1` is the in/out cursor pointer).
`ctx+0x1528` is the anchor/link *name* attribute: `tag_keyword_check_1528` later
case-folds it and compares it to a reference keyword to decide whether to fire the
anchor-draw path (`FUN_005ee470`).

## Input / output
- Input: `param_1` = `char**` — pointer to the parser's current source cursor (updated
  by the extractor to point past the consumed value).
- Output: `undefined8` 0 (consumed).

## Side effects
- Writes up to 16 bytes (incl. NUL) to `ctx+0x1528`.
- Advances `*param_1` past the parsed value.

## Important branches
None here; all branching is inside `FUN_005ec1b0` (quoted vs unquoted, delimiter/bounds).

## Constants & flags
- `0x10` = destination capacity (extractor reserves NUL: max 13 payload bytes, stops at `len-3`).

## Corrected reconstruction
```c
/* +0x1528 : 16-byte anchor/link NAME attribute (matched by tag_keyword_check_1528) */
undefined8 tag_read_name_1528(char **cursor)
{
    parse_attr_value(cursor, (u8*)g_markup_ctx + 0x1528, 0x10);  /* FUN_005ec1b0 */
    return 0;
}
```

## Evidence
- Raw: `FUN_005ec1b0(param_1, iRam007012a0 + 0x1528, 0x10)`.
- `FUN_005ec1b0` is the attribute extractor: consumes `=`, optional `"`, copies value
  until quote/delimiter (`&DAT_006491b0[c] & 4`) or `len-3`, NUL-terminates, writes back cursor.
- `FUN_005e91f0`/`FUN_005ee470` consume `+0x1528` as the anchor name. Runtime-unvalidated.

## Remaining uncertainty
"Name/anchor" semantics inferred from the consumer chain; the copy-into-16B mechanic is certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8f70.c`  — untouched decompiler output.
