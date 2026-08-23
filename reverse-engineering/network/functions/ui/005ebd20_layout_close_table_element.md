# 0x005ebd20 layout_close_table_element

| field | value |
|---|---|
| Original address | 0x005ebd20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ebd20 |
| Resolved name | layout_close_element_pop |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f0e10, FUN_005f10a0, FUN_005f1570
**Callees:** FUN_005ec100 (set_glyph_metrics), FUN_005f0b20, FUN_005f10a0, FUN_005f2280, FUN_005ed160, FUN_005ef0e0, FUN_005ef780
**Referenced globals:** +0xd892 (element-stack depth); +0xd894 (current element idx); +0xd89a (idx map); +0x186 (pass); +0x182 (max content height); +0x18c; +0xd8d0 (pen/cursor)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd892; +0x186

## Behavioral explanation
Closes (pops) one nested layout element off the markup element stack and folds its box metrics into the
parent — the box-model counterpart of a closing tag (`</table>`, `</td>`, etc.). Guard: if the element
stack is empty (`+0xd892 == 0`) it returns 0 (nothing to close). Otherwise it reads/pops a 4-byte token
(`FUN_005f10a0(...,4)`), resolves the element index from the stack map (`+0xd894 = (u16)(+0xd89a)[depth]`),
and locates that element's cell/box (array `+0x24e0`, stride `0x5c`). If the box is live it:
restores glyph metrics for the element's saved style (`set_glyph_metrics(cell+0x252f)`), clears
per-element scratch (`cell+0x252e`, `cell+0x2530` bit0, `ui_ctx+0x18c`, `cell+0x252f`), then — on the
measure pass (`+0x186 == 0xf6`) — computes content extents:
- if `cell+0x2527` (row count) != 0, derives content height from `(rows-1) * (spacing + 2*border)` and
  raises `cell+0x2500`;
- promotes `cell+0x2500` → `cell+0x24fc` (max), and folds min/max width/height into `cell+0x24fe`/parent
  box `box+0x1e/+0x20/+0x22/+0x2c` and the counter `box+0x44`.
It then runs `FUN_005f2280` (commit element box), raises the document max height `ui_ctx+0x182`,
decrements the stack depth (`+0xd892--`), commits the popped box (`FUN_005f0b20`, -1 on failure), and
closes it (`FUN_005ef780` ×2 around `FUN_005ed160`). Returns 0 / -1.

## Input / output
- `param_1`, `param_2` (`undefined8`): the markup parse cursor / token source passed to `FUN_005f10a0`
  and `FUN_005ef0e0` (element close context).
- Returns `undefined4`: `0` success / no-op; `0xffffffff` on read-pop failure, empty cell, or commit
  failure.

## Side effects
- Decrements element-stack depth `ui_ctx+0xd892`.
- Sets `ui_ctx+0x18c = 0`; clears `cell+0x252e`, `cell+0x252f`, `cell+0x2530 &= 0xfe`.
- Raises parent box extents (`box+0x1e/+0x20/+0x22/+0x2c`, `box+0x44++`) and document max height
  `ui_ctx+0x182` on the measure pass.
- Calls element lifecycle helpers (`FUN_005f2280` commit-metrics, `FUN_005f0b20` finalize,
  `FUN_005ef780` close, `FUN_005ed160`, `FUN_005ef0e0`).

## Important branches
- **`ui_ctx+0xd892 == 0`** → return 0 (empty stack; nothing to pop).
- **`FUN_005f10a0(param_1,param_2,4) < 0`** → return -1 (token read failed).
- **cell box ptr == 0** → return -1.
- **`+0x186 == 0xf6` (measure) AND `cell+0x2527 != 0`** → row-count → content-height derivation into
  `cell+0x2500`.
- **`cell+0x2528 == 0`** (not a container) → fold `+0xd8d0` pen into `cell+0x24fe` min-width; **else if
  `+0x186 != 0`** → `cell+0x2520 = +0xd8d0`.
- **`cell+0x2527 == 0`** → advance parent box height (`box+0x2c` and, on measure, `box+0x20`, `box+0x44++`).
- **post-decrement `+0xd892 == 0` after --** (`cVar1 == 0` before dec) → return -1 guard.
- **`FUN_005f0b20(cell) < 0`** → return -1.

## Constants & flags
- Element/cell stride `0x5c`; index from `(u16)(ui_ctx+0xd89a)[ (u8)(ui_ctx+0xd892) ]` → `+0xd894`.
- Cell fields: `+0x1c(0x24fc)` max-width, `+0x1e(0x24fe)` min-width, `+0x20(0x2500)` content-height,
  `+0x24(0x2504)` , `+0x30(0x2510)` border, `+0x32(0x2512)` spacing, `+0x38(0x2518)`, `+0x40(0x2520)`,
  `+0x47(0x2527)` row count, `+0x48(0x2528)` container flag, `+0x4e(0x252e)`/`+0x4f(0x252f)` style
  scratch, `+0x50(0x2530)` flags. Box: `+0x1e` width, `+0x20`, `+0x22`, `+0x2c` height, `+0x44` child count.
- `+0x186 == 0xf6` = measure pass; `+0xd8d0` = current pen/cursor position; `+0x182` = doc max height.
  [offsets inferred from arithmetic]

## Corrected reconstruction
```c
#define CELL(idx) ((struct cell*)((char*)ui_ctx + 0x24e0 + (idx) * 0x5c))

undefined4 layout_close_element_pop(void *cursor, void *token_src)
{
    if (ui_ctx->stack_depth == 0) return 0;                    // +0xd892 empty

    if (read_token(cursor, token_src, 4) < 0) return -1;       // FUN_005f10a0

    ui_ctx->cur_elem = ui_ctx->stack_map[ui_ctx->stack_depth]; // +0xd894 = (u16)+0xd89a[depth]
    struct cell *c = CELL(ui_ctx->cur_elem);
    struct box *b = c->box;
    if (b == 0) return -1;

    set_glyph_metrics(c->style_scratch);                       // FUN_005ec100(cell+0x252f)
    c->scratch_252e = 0;
    end_element(token_src);                                    // FUN_005ef0e0
    c->flags_2530 &= 0xfe;
    ui_ctx->flag_18c = 0;
    c->style_scratch = 0;                                      // +0x252f

    if (ui_ctx->pass == 0xf6 && c->row_count != 0) {           // measure, has rows
        int h = (c->row_count - 1) * (c->spacing + c->border * 2);
        if (c->content_h < h) c->content_h = h;                // +0x2500
    }
    if (c->max_w < c->content_h) c->max_w = c->content_h;      // +0x24fc = max(., +0x2500)

    if (!c->is_container) {                                     // +0x2528 == 0
        if (c->min_w < ui_ctx->pen) c->min_w = ui_ctx->pen;    // +0x24fe vs +0xd8d0
        if (c->min_w < c->field_2504) c->min_w = c->field_2504;
    } else if (ui_ctx->pass != 0) {
        c->field_2520 = ui_ctx->pen;                           // +0x2520 = +0xd8d0
    }
    c->field_2518 = ui_ctx->pen;                               // +0x2518 = +0xd8d0

    unsigned int w = c->min_w + c->border * 2;                 // +0x24fe + 2*+0x2510
    if (b->width < w) b->width = w;                            // box+0x1e

    if (c->row_count == 0) {
        b->height += c->spacing + c->max_w + c->border * 2;    // box+0x2c
        if (ui_ctx->pass == 0xf6) {
            b->field_20 += c->spacing + c->max_w + c->border * 2;
            b->child_count++;                                  // box+0x44
        }
    }
    if (ui_ctx->pass == 0xf6)
        b->field_22 += c->spacing + c->field_2502 + c->border * 2;

    commit_element_metrics(c);                                 // FUN_005f2280
    if (ui_ctx->pass == 0xf6) {
        unsigned int mh = c->field_2508 + c->max_w;
        if (ui_ctx->doc_max_h < mh) ui_ctx->doc_max_h = mh;    // +0x182
    }

    if (ui_ctx->stack_depth == 0) return -1;
    ui_ctx->stack_depth--;                                     // pop
    if (finalize_element(c) < 0) return -1;                    // FUN_005f0b20
    close_box(c); layout_flush(); close_box(c);                // FUN_005ef780, FUN_005ed160, FUN_005ef780
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005ebd20.c` (stack guard `+0xd892==0`; index map
  `(u16)((u8)(+0xd892)*2 + +0xd89a)`; row-count height `(rows-1)*(spacing+2*border)`; measure gate
  `+0x186 == -10`; depth decrement then `FUN_005f0b20`/`FUN_005ef780`).
- Stride `0x5c` and pass constant `0xf6` match 0x5eb7d0 / the attribute-handler family.
- Confidence **Medium** (heavy box-model arithmetic; many inferred field names). UI markup, not net.

## Remaining uncertainty
Precise cell/box field semantics (which are min vs max vs running width/height); the roles of
`FUN_005f2280`, `FUN_005f0b20`, `FUN_005ed160`, `FUN_005ef0e0`; exact meaning of the second glyph-close
(`FUN_005ef780` twice around `FUN_005ed160`).
