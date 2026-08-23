# 0x005ebcf0 parse_markup_attr_str_f1c

| field | value |
|---|---|
| Original address | 0x005ebcf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ebcf0 |
| Resolved name | markup_attr_str_f1c |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup attribute-handler dispatch table)
**Callees:** FUN_005ec1b0 (parse_quoted_attr_value)
**Referenced globals:** +0xf1c (pending string-attr buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
The thinnest attribute handler: copies the quoted string value directly into the pending-element
string buffer at `ui_ctx+0xf1c` (capacity 0x100). Unlike the numeric/color/keyword handlers it is
**not** gated on `+0x186` and does not tokenize into a stack buffer first — it tokenizes straight into
the destination `+0xf1c`, so the pending string attribute is always refreshed regardless of pass. The
`+0xf1c` buffer is the tail of the pending-attribute block and is consumed later (e.g.
`markup_table_layout_finalize` at 0x5eb7d0 passes `ui_ctx+0xf1c` to `FUN_005efa60`), which fits a
name/label/href-style string attribute.

## Input / output
- `param_1` (`byte **` [inferred]): attribute cursor.
- Returns 0.

## Side effects
- Advances cursor; writes the value string (≤0xFF bytes + NUL) into `ui_ctx+0xf1c`. Always runs (no
  pass gate).

## Important branches
- None — straight-line: tokenize into `+0xf1c`, return 0.

## Constants & flags
- `+0xf1c` — pending-element string attribute buffer, 0x100 bytes; the tail of the `+0xf10..` block.

## Corrected reconstruction
```c
undefined8 markup_attr_str_f1c(unsigned char **cursor)
{
    parse_quoted_attr_value(cursor, ui_ctx->pending.str_f1c, 0x100); // FUN_005ec1b0 -> +0xf1c
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005ebcf0.c`
  (`FUN_005ec1b0(param_1, iRam007012a0 + 0xf1c, 0x100)` — no `+0x186` gate).
- `+0xf1c` is read by 0x5eb7d0 (`FUN_005efa60(iRam007012a0 + 0xf1c)`), confirming it as a persisted
  pending string attribute.
- Confidence **High**; runtime-unvalidated. UI markup, not net.

## Remaining uncertainty
Which attribute (label/name/href); why it skips the pass gate (likely because the string must survive
into the finalize step on any pass).
