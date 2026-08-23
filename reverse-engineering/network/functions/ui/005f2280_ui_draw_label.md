# 0x005f2280 ui_draw_label

| field | value |
|---|---|
| Original address | 0x005f2280 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f2280 |
| Resolved name | ui_draw_cell_fill |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ebd20 (cell finish)
**Callees:** FUN_005d9ac0 (fill/gradient draw primitive), FUN_005efae0 (string-buffer flush, returns a handle)
**Referenced globals:** ctx+0x186 pass; ctx+0xe96b suppress-draw; element list/parent via *param_1; +0x1c/+0x1e size, +0x28/+0x2a x/y (as word[0xa]/+0x2a), +0x30 x2 (word[0xc]), +0x40 y-alt (word[0x10]), +0x1a style, +0x45 parent border, +0x54 color (word[0x15]), +0x48 wrap flag (byte[0x12])
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x186; ctx+0xe96b

## Behavioral explanation
Leaf renderer for a table cell's fill/background region (the shaded rectangle behind a cell's content),
run only in the **draw pass**. If the cell has zero width or height (`word[7]==0 || +0x1e==0`) it just
flushes the string buffer and returns. Otherwise it reads the parent element (`*param_1`) to inherit its
border style (+0x45), computes the fill rectangle from the cell's x (word[0xa]), the cell inset (word[0xc]),
its width (word[7]) and its bottom edge (which depends on a wrap/auto-height flag `byte[0x12]`: if set use
the stored height word[0x10], else use y+height +0x2a/+0x1e), picks a color (own word[0x15], or the
parent's if negative), flushes the string buffer to a handle, and calls the fill primitive `FUN_005d9ac0`.

## Input / output
- `param_1` — cell element (`int*`): word[0]=parent ptr, word[7]=width, +0x1e=height, +0x1a=style,
  word[0xa]=x, +0x2a=y, word[0xc]=x-inset, word[0x10]=alt-height, byte[0x12]=auto-height flag,
  word[0x15]=color.
- Returns void.

## Side effects
- Draw pass only: emits one fill/gradient rectangle; flushes the string buffer.

## Important branches
- `ctx->pass != 0 || ctx->suppressDraw != 0` → no-op.
- `width==0 || height==0` → just flush string buffer, return (empty cell, nothing to fill).
- parent (`*param_1`) null or its own `*parent==0` → skip (no template to inherit).
- `byte[0x12] == 0` (no explicit height) → bottom = y + height; else bottom = y + alt-height (word[0x10]).
- `color (word[0x15]) < 0` → inherit parent color (`parent[0x15]`).
- border flag `parent[+0x45] != 0` passed to primitive as a bool.

## Constants & flags
- `ctx->pass == 0` = draw pass; `ctx->suppressDraw` (+0xe96b) gate.
- `byte[0x12]` = auto-height/wrap flag selecting height source.
- `word[0x15] < 0` sentinel = "inherit color from parent".

## Corrected reconstruction
```c
void ui_draw_cell_fill(CellElem* e /*param_1 as int* */) {
    u8* ctx = (u8*)0x007012a0;
    if (*(char*)(ctx+0x186) != PASS_DRAW || *(char*)(ctx+0xe96b) != 0) return;

    if (e->width /*word[7]*/ == 0 || e->height /*+0x1e*/ == 0) {
        ui_string_flush();                                   // FUN_005efae0
        return;
    }
    CellElem* parent = (CellElem*)e->parent /*word[0]*/;
    if (parent == NULL || parent->parent == 0) return;
    char borderStyle = parent->border /*+0x45*/;

    s16 bottom = (e->autoHeight /*byte[0x12]*/ == 0)
               ? e->x_inset/*word[0xc]*/ + e->y/*+0x2a*/ + e->height/*+0x1e*/
               : e->x_inset               + e->y         + e->altHeight/*word[0x10]*/;
    int color = e->color /*word[0x15]*/;
    if (color < 0) color = parent->color;                    // inherit
    void* strh = ui_string_flush();                          // FUN_005efae0 -> handle
    s16 inset = e->x_inset;
    gfx_fill_rect(e->x/*word[0xa]*/ - inset, e->y - inset,
                  inset + e->x + e->width, bottom,
                  e->style/*+0x1a*/, color, borderStyle != 0, strh);   // FUN_005d9ac0
}
```

## Evidence
- Raw: `FUN_005f2280.c` (312 bytes). Draw-pass gate identical to ui_draw_box; calls 0x5d9ac0 (fill
  primitive taking a string handle from 0x5efae0). Single caller FUN_005ebd20 (cell finalize → paint fill).

## Remaining uncertainty
- Word-index field names (x/x-inset/alt-height/color) are inferred from the primitive's argument order;
  the auto-height flag semantics (byte[0x12]) is deduced. Name changed from "label" to "cell_fill" since it
  paints a rectangle region, not glyphs. High confidence, no runtime trace, no network relevance.
