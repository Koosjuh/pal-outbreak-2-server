# 0x005f2e50 ui_place_inline_sprite

| field | value |
|---|---|
| Original address | 0x005f2e50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f2e50 |
| Resolved name | ui_place_inline_image |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ee610 (image/sprite element handler)
**Callees:** FUN_005ee220 (blit sprite in draw pass), FUN_005f3230 (wrap to next line)
**Referenced globals:** ctx+0x186 pass; ctx+0x188 root idx; ctx+0xdf6/+0xdf8 element width/height; ctx+0x16 running height; ctx+0xd8ce/+0xd8d0/+0xd8d2/+0xd8d6/+0xd8dc line cursors; ctx+0xd8de line-has-content; node+0x2500/+0x2502 extents, +0x251a/+0x251c pad, +0x251e indent, +0x2530 flags, +0x2518 draw-order; root array +0x1540
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x186; ctx+0xd8ce; ctx+0xd8de

## Behavioral explanation
Places an **inline image/sprite** of size `ctx->elemW (+0xdf6)` × `ctx->elemH (+0xdf8)`. Structurally
identical to the text-token and fixed-row placers: in the **measure pass** it grows the running height
(+0x16) and the node's min/pref content extents by the element width (honoring the nowrap flag), and bumps
the line-content marker (+0xd8de) by the element width. In the layout/draw passes it computes x from the
node indent and line cursor, wraps via `FUN_005f3230` if the element would overrun the content right edge
(+0xd8dc), and in the draw pass blits the sprite via `FUN_005ee220(x, y, root)`. It then advances the line
H-cursor (+0xd8ce/+0xd8d2) by the element width and, in arrange pass, updates the root record's max
width/height and the node draw-order.

## Input / output
- (void) — element size comes from globals +0xdf6/+0xdf8; cursors are the global layout state.
- Returns void.

## Important branches
- `pass == 0xF6` (measure): grow +0x16 by elemW; grow +0x2502 (pref) and, if wrappable, +0x2500 (min),
  else clamp min↑pref; increment +0xd8de by elemW; return.
- else: `x = indent + lineX`; if wrappable and (line empty OR `x+elemW <= contentRight`) → advance by gap
  (+0xd8d6); else wrap via `FUN_005f3230`. In draw pass add node left pad (+0x251a) and top pad (+0x251c).
- draw: `FUN_005ee220(x, y, root)` blit.
- `pass == 1` (arrange): `root[0] = max(root[0], lineX+ )`, `root[1] = max(root[1], elemH)`; node
  draw-order (+0x2518) = snapshot (+0xd8d4).

## Constants & flags
- element size: width +0xdf6, height +0xdf8 (global scratch set by the caller before this call).
- node flag `+0x2530 & 0x2` = nowrap.
- `pass`: 0xF6 measure / 0 draw / 1 arrange.

## Corrected reconstruction
```c
void ui_place_inline_image(void) {
    u8* ctx = (u8*)0x007012a0;
    u16* root = (u16*)(ctx + *(u16*)(ctx+0x188)*4 + 0x1540);
    LayoutNode* n = node_at(ctx, *(u16*)(ctx+0xd894));
    u16 ew = *(u16*)(ctx+0xdf6), eh = *(u16*)(ctx+0xdf8);

    if (*(char*)(ctx+0x186) == PASS_MEASURE) {
        u16 indent = n->indent /*+0x251e*/;
        *(s16*)(ctx+0x16) += ew;
        *(u8*)(ctx+0xd8de) += (u8)ew;
        u16 pref = indent + *(u16*)(ctx+0x16);
        if (n->w2502 < pref) n->w2502 = pref;
        if ((n->flags & 2) == 0) { u16 mn = indent + ew; if (n->w2500 < mn) n->w2500 = mn; }
        else if (n->w2500 < n->w2502) n->w2500 = n->w2502;
        return;
    }

    u16 x = n->indent + *(u16*)(ctx+0xd8ce);
    if ((n->flags & 2) == 0) {
        if (*(u16*)(ctx+0xd8ce) == 0 || x + ew <= *(u16*)(ctx+0xd8dc))
            x += *(u16*)(ctx+0xd8d6);
        else
            x = (u16)ui_line_wrap((u8*)n, &root);            // FUN_005f3230
    } else {
        x += *(u16*)(ctx+0xd8d6);
    }
    s16 yPad = 0;
    if (*(char*)(ctx+0x186) == PASS_DRAW) { yPad = n->padTop/*+0x251c*/; x += n->padLeft/*+0x251a*/; }
    ui_blit_sprite(x, *(s16*)(ctx+0xd8d0) + yPad + *(s16*)(ctx+0xd8d8), root);   // FUN_005ee220

    u16 adv = *(u16*)(ctx+0xd8ce) + ew;
    *(u16*)(ctx+0xd8d2) = adv;  *(u16*)(ctx+0xd8ce) = adv;
    *(s16*)(ctx+0x16) += ew;    *(u8*)(ctx+0xd8de) += (u8)ew;

    if (*(char*)(ctx+0x186) == PASS_ARRANGE) {
        if (root[0] < *(u16*)(ctx+0xd8d2)) root[0] = *(u16*)(ctx+0xd8d2);
        if (root[1] < *(u16*)(ctx+0xdf8))  root[1] = *(u16*)(ctx+0xdf8);
        n->drawOrder/*+0x2518*/ = *(u16*)(ctx+0xd8d4);
    }
}
```

## Evidence
- Raw: `FUN_005f2e50.c` (768 bytes). Same measure/draw/arrange skeleton as the text/row placers with an
  explicit sprite blit (`FUN_005ee220`) using element size globals +0xdf6/+0xdf8. Caller FUN_005ee610.

## Remaining uncertainty
- `+0xd8de` is incremented by width here (vs set to 1 elsewhere) — treated as a line-content/advance
  accumulator; exact semantics inferred. High confidence on the placement role, no runtime trace, no net.
