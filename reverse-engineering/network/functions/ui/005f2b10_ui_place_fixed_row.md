# 0x005f2b10 ui_place_fixed_row

| field | value |
|---|---|
| Original address | 0x005f2b10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f2b10 |
| Resolved name | ui_place_hrule_widget |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ee010 (element handler)
**Callees:** FUN_005f3230 (wrap to next line, returns new x), FUN_005d9350 (line/rule draw primitive)
**Referenced globals:** ctx+0x186 pass; ctx+0x188 root idx; ctx+0x16 running height; ctx+0x18 size-unit; ctx+0xd8ce/+0xd8d0/+0xd8d2/+0xd8d4/+0xd8d6/+0xd8dc line cursors; ctx+0xd8de line-has-content; node+0x2500/+0x2502 extents, +0x251a/+0x251c/+0x251e pad/indent, +0x2530 flags, +0x2518 draw-order; root array +0x1540
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x186; ctx+0xd8d2; ctx+0xd8de

## Behavioral explanation
Places a fixed-height horizontal element (a rule/separator or fixed-size box) whose height is derived from
a size unit: `height = ctx->sizeUnit(+0x18) * 8 + 0x18`. In the **measure pass** it adds that height into
the running-height accumulator (+0x16), marks the line dirty (+0xd8de), and grows the node's pref/min
content extents (+0x2502/+0x2500) honoring the nowrap flag (+0x2530 bit 2). In the layout/draw passes it
computes the element's x from the current line H-cursor (+0xd8ce) and the node indent (+0x251e), performs a
wrap check (calling `FUN_005f3230` when it would overflow the content right edge +0xd8dc), advances the row
cursors (+0xd8d2, +0x16), and — in the draw pass (`pass==0`, not suppressed) — emits the element via
`FUN_005d9350`. In arrange pass it clamps the root record's height to ≥ 0x14 and stamps node draw-order.

## Input / output
- (void) — reads/writes the global layout cursors and the current node/root records.
- Returns void.

## Important branches
- `pass == 0xF6` (measure): `height = sizeUnit*8 + 0x18`; grow extents; mark line content; early path.
- else: wrap decision — if line empty (+0xd8ce==0) OR `right + height <= contentRight(+0xd8dc)` → advance
  x by gap (+0xd8d6); else `x = FUN_005f3230(node, &root)` (wrap). nowrap node (+0x2530&2) never wraps.
- `pass == 0 && suppressDraw == 0` → draw via `FUN_005d9350(x, y, x2, y2)`.
- `pass == 1` (arrange): clamp `root[+2] >= 0x14`; node draw-order (+0x2518) = snapshot (+0xd8d4).

## Constants & flags
- `height = sizeUnit(+0x18)*8 + 0x18` (24px base + 8px per unit).
- node flag `+0x2530 & 0x2` = nowrap.
- root min height clamp = `0x14` (20px).
- `pass`: 0xF6 measure / 0 draw / 1 arrange.

## Corrected reconstruction
```c
void ui_place_hrule_widget(void) {
    u8* ctx = (u8*)0x007012a0;
    u16* root = (u16*)(ctx + *(u16*)(ctx+0x188)*4 + 0x1540);
    LayoutNode* n = node_at(ctx, *(u16*)(ctx+0xd894));
    s16 h = *(s16*)(ctx+0x18)*8 + 0x18;                      // fixed height

    if (*(char*)(ctx+0x186) == PASS_MEASURE) {
        u16 indent = n->indent /*+0x251e*/;
        *(s16*)(ctx+0x16) += h;
        *(u8*)(ctx+0xd8de) = 1;
        u16 pref = indent + *(u16*)(ctx+0x16);
        if (n->w2502 < pref) n->w2502 = pref;
        if ((n->flags & 2) == 0) { u16 mn = indent + h; if (n->w2500 < mn) n->w2500 = mn; }
        else if (n->w2500 < n->w2502) n->w2500 = n->w2502;
        return;
    }

    u16 x = n->indent + *(u16*)(ctx+0xd8ce);
    if ((n->flags & 2) == 0) {
        if (*(u16*)(ctx+0xd8ce) == 0 || x + h <= *(u16*)(ctx+0xd8dc))
            x += *(u16*)(ctx+0xd8d6);
        else
            x = (u16)ui_line_wrap((u8*)n, root);             // FUN_005f3230
    } else {
        x += *(u16*)(ctx+0xd8d6);
    }
    *(s16*)(ctx+0xd8d2) += h;
    *(s16*)(ctx+0x16)  += h;
    if (*(char*)(ctx+0x186)==PASS_DRAW && *(char*)(ctx+0xe96b)==0) {
        s16 y = *(s16*)(ctx+0xd8d8) + n->padTop/*+0x251c*/ + *(s16*)(ctx+0xd8d0) + root[1];
        gfx_draw_line(x + n->padLeft/*+0x251a*/, y - 0x14,
                      n->padLeft + *(u16*)(ctx+0xd8d2) + n->indent + *(u16*)(ctx+0xd8d6), y); // 5d9350
    }
    *(u16*)(ctx+0xd8ce) = *(u16*)(ctx+0xd8d2);
    *(u8*)(ctx+0xd8de) = 1;
    if (*(char*)(ctx+0x186)==PASS_ARRANGE) {
        if (root[1] < 0x14) root[1] = 0x14;
        n->drawOrder/*+0x2518*/ = *(u16*)(ctx+0xd8d4);
    }
}
```

## Evidence
- Raw: `FUN_005f2b10.c` (820 bytes). Structure mirrors ui_place_text_token/ui_place_inline_sprite (same
  wrap/measure/arrange skeleton) with a fixed `sizeUnit*8+0x18` height and the 0x5d9350 line primitive.
  Caller FUN_005ee010.

## Remaining uncertainty
- Whether this is strictly an `<hr>` vs a generic fixed-height block is inferred from the line primitive
  and 20px clamp; renamed from "fixed_row" to "hrule_widget" to reflect the draw call. High confidence on
  geometry, no runtime trace, no network relevance.
