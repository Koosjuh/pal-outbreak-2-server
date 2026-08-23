# 0x005f2450 ui_layout_newline_advance

| field | value |
|---|---|
| Original address | 0x005f2450 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f2450 |
| Resolved name | ui_layout_hr_advance |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ed1f0 (block/rule element handler)
**Callees:** FUN_005ec170 (reset line H-cursor), FUN_005d93f0 (line/rule draw primitive), FUN_005ef780 (element style push), FUN_005ed160 (line finalize)
**Referenced globals:** ctx+0x186 pass; ctx+0x188 root idx; ctx+0x8f2/+0x8f4 line height/width; ctx+0xd8ce..+0xd8dc layout cursors; ctx+0xd8d0/+0xd8d4 y-cursors; node+0x251a/+0x251c/+0x251e pad/indent; root array +0x1540
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x186; ctx+0xd8d0; ctx+0xd8d4

## Behavioral explanation
Emits a **horizontal rule / block separator** and advances the vertical layout cursor to a new line. In
the **measure pass** (`pass==0xF6`) it only grows the node's content extents (+0x2500/+0x2502) by the
node indent (+0x251e) plus the line width (+0x8f4). Otherwise it computes the rule width (defaulting to a
full-width `0x248` in arrange pass, or `contentRight-indent` in draw pass), bumps the vertical cursor
(+0xd8d0) by 10px, and — in the draw pass (`pass==0` and not suppressed) — draws the rule via
`FUN_005d93f0(x1,y,x2,y+lineHeight)`. It then advances the cursor by the line height + 10px, snapshots
it into +0xd8d4, resets the horizontal line cursor (`FUN_005ec170`), and in the arrange pass records the
element's hit-rectangle into the root array at +0x1540. Finally it zeroes the line height (+0x8f2) and
finalizes the line (`FUN_005ed160`), bracketed by two element-style pushes (`FUN_005ef780`).

## Input / output
- `param_1` (long) — nonzero indicates the rule is left-indented by the node's left pad (+0x251a added
  to the start x); 0 = flush left.
- Returns void.

## Side effects
- Advances vertical cursors (+0xd8d0 by 20+lineHeight total), snapshots to +0xd8d4/+0xd8d2.
- Measure pass: grows node extents +0x2500/+0x2502.
- Arrange pass: writes root hit-rect array `root[+0x1540]` (+0x1540 x/w, +0x1542 h) and node draw-order +0x2518.
- Draw pass: emits one HR line primitive.
- Zeroes line height +0x8f2; resets H-cursor; finalizes line.

## Important branches
- `pass == 0xF6` (measure): only extent growth, early return path.
- else compute line width default: `lineWidth==0` → arrange:`0x248`, draw:`contentRight-indent`;
  `lineWidth<2` → clamp to 2.
- `pass == 0 && suppressDraw == 0` → draw the rule (`FUN_005d93f0`); indent by +0x251a if `param_1!=0`.
- `pass == 1` (arrange) → write root hit-rect + node draw-order.

## Constants & flags
- `pass`: 0xF6 measure / 0 draw / 1 arrange (cluster convention).
- `0x248` = default full-content-width rule length in arrange pass.
- `+10` px = inter-line gap added twice (before and after the rule).

## Corrected reconstruction
```c
void ui_layout_hr_advance(long indented /*param_1*/) {
    u8* ctx = (u8*)0x007012a0;
    u8* root = ctx + *(u16*)(ctx+0x188)*4;                 // root record base
    LayoutNode* n = node_at(ctx, *(u16*)(ctx+0xd894));

    if (*(char*)(ctx+0x186) == PASS_MEASURE) {
        u16 w = n->indent/*+0x251e*/ + *(u16*)(ctx+0x8f4); // +line width
        if (*(u16*)(ctx+0x2500 - 0x24e0 + (u8*)n - ctx) < w) ; // extents grow (see raw)
        if (n->w2500 < w) n->w2500 = w;
        if (n->w2502 < w) n->w2502 = w;
        return;
    }

    s16* lineW = (s16*)(ctx+0x8f4);
    s16 x1 = *(s16*)(ctx+0xd8ce) + n->indent + *(s16*)(ctx+0xd8d6);
    if (*lineW == 0)
        *lineW = (*(char*)(ctx+0x186)==PASS_DRAW)
               ? *(s16*)(ctx+0xd8dc) - n->indent           // content-right - indent
               : 0x248;                                     // arrange: full width
    else if (*lineW < 2) *lineW = 2;

    *(s16*)(ctx+0xd8d0) += 10;                              // pre-gap
    if (*(char*)(ctx+0x186)==PASS_DRAW && *(char*)(ctx+0xe96b)==0) {
        if (indented) x1 += n->padLeft/*+0x251a*/;
        s16 y = *(s16*)(ctx+0xd8d0) + n->padTop/*+0x251c*/ + *(s16*)(ctx+0xd8d8);
        gfx_draw_line(x1, y, x1 + *lineW, y + *(s16*)(ctx+0x8f2));   // FUN_005d93f0
    }
    *(s16*)(ctx+0xd8d0) += *(s16*)(ctx+0x8f2) + 10;        // post-gap + line height
    *(u16*)(ctx+0xd8d4) = *(u16*)(ctx+0xd8d0);
    ui_line_cursor_reset(ctx+0xd8ce);                      // FUN_005ec170

    if (*(char*)(ctx+0x186)==PASS_ARRANGE) {               // record hit-rect
        *(s16*)(root+0x1540) = x1 + *lineW;
        *(s16*)(root+0x1542) = *(s16*)(ctx+0x8f2) + 0x14;
        n->drawOrder/*+0x2518*/ = *(u16*)(ctx+0xd8d4);
    }
    *(u16*)(ctx+0x8f2) = 0;                                 // reset line height
    ui_elem_style_push((u8*)n);                             // FUN_005ef780(node+0x24e0)
    ui_line_finalize();                                    // FUN_005ed160
    ui_elem_style_push((u8*)n);
}
```

## Evidence
- Raw: `FUN_005f2450.c` (700 bytes). Three-pass structure (measure/draw/arrange) with the `0x248` default
  rule width and the `FUN_005d93f0` line primitive identify a block-separator/HR advance. Caller
  FUN_005ed1f0 handles block-level elements.

## Remaining uncertainty
- The measure-pass extent write reuses node fields via absolute offsets; expressed via the LayoutNode
  view here. `+0x248` full-width default and the exact 10px gaps are verbatim. High confidence on role,
  no runtime trace, no network relevance.
