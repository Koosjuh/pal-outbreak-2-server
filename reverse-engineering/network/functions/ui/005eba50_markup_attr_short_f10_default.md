# 0x005eba50 markup_attr_short_f10_default

| field | value |
|---|---|
| Original address | 0x005eba50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eba50 |
| Resolved name | markup_attr_short_f10_celldefault |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup attribute-handler dispatch table)
**Callees:** FUN_005ec1b0 (parse_quoted_attr_value), FUN_005ec6d0 (parse short-with-default)
**Referenced globals:** +0x186 (pass); +0xd894 (current cell index); +0x24e0 (cell array); +0xf10 (pending short attr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Markup attribute handler for a 16-bit (short) attribute whose default is the current cell's own
metric. It tokenizes the value, and on the `+0x186 == 0xf6` pass calls `FUN_005ec6d0(value, default)`
where the default is `cell->field_0x1c` of the current table cell (looked up via the current-cell
index `+0xd894` into the cell array `+0x24e0`, stride `0x5c`). If no live cell, default = 0. The parsed
short is stored into the pending-element attribute slot `ui_ctx+0xf10`. This "default to current cell
width" pattern marks it as a width-like attribute (e.g. a column/`width=` that inherits the cell's
current width when unspecified or malformed).

## Input / output
- `param_1` (`byte **` [inferred]): attribute cursor.
- Returns 0.

## Side effects
- Advances the cursor; on the `0xf6` pass writes a 16-bit value to `ui_ctx+0xf10`.

## Important branches
- **`ui_ctx+0x186 == 0xf6`** → compute default from current cell, parse short, store `+0xf10`;
  **else** → parse-only.
- **current cell ptr `cell` == 0** → default = 0; **else** default = `cell->field_0x1c`.

## Constants & flags
- Cell array base `ui_ctx+0x24e0`, stride `0x5c` (92 bytes); index `= *(u16)(ui_ctx+0xd894)`.
  The decompiler's `(idx*0x18 - idx)*4` == `idx*0x17*4` == `idx*0x5c`.
- `cell + 0x1c` — the cell metric used as the short's default (width-like). [inferred]
- `+0x186 == 0xf6` — attribute-apply pass.
- `+0xf10` — pending-element short attribute.

## Corrected reconstruction
```c
// Markup attribute handler: short attribute defaulting to the current cell's metric -> pending +0xf10
undefined8 markup_attr_short_f10_celldefault(unsigned char **cursor)
{
    unsigned char val[0x100];
    parse_quoted_attr_value(cursor, val, 0x100);                 // FUN_005ec1b0
    if (ui_ctx->pass == 0xf6) {                                  // +0x186
        struct cell *cell = CURRENT_CELL();                      // ui_ctx+0x24e0 + idx*0x5c
        unsigned short deflt = cell ? cell->metric_0x1c : 0;
        ui_ctx->pending.short_f10 =                              // +0xf10
            parse_short_with_default(val, deflt);                // FUN_005ec6d0
    }
    return 0;
}

// helper: CURRENT_CELL uses idx = *(u16)(ui_ctx+0xd894), stride 0x5c, base ui_ctx+0x24e0
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005eba50.c`
  (default `= *(u16)(cell+0x1c)` when cell nonzero, else 0; `FUN_005ec6d0(buf, default)` → `+0xf10`;
  gated on `+0x186 == -10`).
- Cell-index arithmetic matches `markup_table_layout_finalize` (0x5eb7d0) stride 0x5c.
- Confidence **High**; runtime-unvalidated. UI markup, not net.

## Remaining uncertainty
Precise meaning of `cell+0x1c` (assumed width) and of `FUN_005ec6d0`'s default handling (clamp vs
fallback). Attribute name inferred as width-like from the cell-metric default.
