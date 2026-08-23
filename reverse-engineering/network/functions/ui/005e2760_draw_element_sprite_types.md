# 0x005e2760 draw_element_box_layer

| field | value |
|---|---|
| Original address | 0x005e2760 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e2760 |
| Resolved name | draw_element_box_layer |
| Subsystem | ui |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005daf30 (element-list draw loop)
**Callees:** FUN_005e0440 (filled rect), FUN_005e0510 (corner/triangle), FUN_005e19b0 (vertical line), FUN_005e1a30 (horizontal line), FUN_005e5910 (tiled glyph fill)
**Referenced globals:** iRam00701070 (viewport: +4/+8 scroll origin, +0x14 focus/selection sentinel, +0x1c/+0x20 bottom/right margins)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Per-element "box layer" renderer — a second draw pass over a single UI element that only
handles the box/panel element kinds `0x0d`, `0x0f`, `0x10` (skips everything else). It is
one of the callees of the element-list draw loop FUN_005daf30 (a sibling of the main
element dispatcher FUN_005e2fa0). It viewport-culls the element against the scrollable
content window, then:
- **type 0x0f** (filled panel): draws the fill quad (color `elem+0x58 | 0xff000000`) plus
  a bevel — top/left highlight lines `0x606060` and bottom/right lines that are either
  bright `0xd0d0d0` or white depending on the current-focus sentinel `iRam00701070+0x14`.
- **type 0x10** (button-panel): for subtype `elem+5==2` draws just the fill; for subtype
  `==1` with a border thickness `elem+0x5d != 0` draws a thick beveled border, again
  toggling highlight brightness on `+0x14`.
- **type 0x0d** (glyph-tiled panel, only when the row byte `elem+0 == 4` and subtype
  `elem+5 == 2`): delegates to the tiled-glyph fill FUN_005e5910 with sheet id `elem+0x5f`.

Coordinates are element pos (`+0x34`,`+0x38`) minus scroll origin, size (`+0x40`,`+0x44`).

## Input / output
- Input: `param_1` = pointer to a UI element record (byte-addressed; see field map below).
- Output: none (`void`). Side effects = draw commands.

## Side effects
- Emits filled quads, bevel lines, and (type 0x0d) a tiled-glyph fill. No state writes.

## Important branches
- Early type gate: `elem[2]` must be `0x0d` (and then `elem[5]==2 && elem[0]==4`), `0x0f`,
  or `0x10`; anything else returns immediately.
- Viewport cull: element right/bottom must intersect the content window
  `[iRam00701070+4 .. +4+640-rightMargin] x [+8 .. +8+0x1ac]`; miss → return.
- **0x0f:** draw fill only if `(int)elem+0x58 >= 0` (top bit = "transparent/skip fill");
  bevel only if `elem[0x5d] != 0`. `iRam00701070+0x14 == -1` selects the bright/white
  bottom-right edge, else the alternate edge geometry.
- **0x10:** `elem[5]==2` → fill-only; `elem[5]==1 && elem[0x5d]!=0` → thick border,
  and within that `(int)elem+0x58 < 1` (no fill color) selects the two-tone grey/white
  bevel, else a colored border from `elem+0x58`.
- **0x0d:** always `draw_tiled_glyph_fill(elem, elem[0x5f])`.

## Constants & flags
- Element type bytes are **internal UI element kinds, not SN@P wire opcodes**:
  `0x0d`=glyph/pattern panel, `0x0f`=filled bevel panel, `0x10`=button panel.
- Colors: `0xff606060` dark bevel, `0xffd0d0d0` light bevel, `0xffffffff` white highlight,
  `elem+0x58 | 0xff000000` = element base color forced opaque.
- `iRam00701070+0x14 == -1` = "no active/pressed selection" state → bright edges.
- Content-window height `0x1ac` (428px), width `0x280`(640)-rightMargin.
- Element fields: `+0`=row/kind byte, `+2`=type, `+5`=subtype/state, `+0x34/0x38`=pos x/y,
  `+0x40/0x44`=size w/h, `+0x58`=u32 color, `+0x5d`=border thickness, `+0x5f`=glyph-sheet id.

## Corrected reconstruction
```c
// UI element record (byte layout; only fields used here are named). [inferred]
typedef struct {
    u8  kind;      // +0x00
    u8  _1;
    u8  type;      // +0x02  0x0d/0x0f/0x10 handled here
    u8  _3, size;  // +0x04 text size
    u8  subtype;   // +0x05
    /* ... */
    float x, y;    // +0x34,+0x38 world pos
    float w, h;    // +0x40,+0x44 size
    /* ... */
    u32 color;     // +0x58  top bit set => skip fill
    u8  _5c;
    u8  thickness; // +0x5d  bevel/border thickness (px)
    u8  _5e;
    u8  glyphSheet;// +0x5f  tiled-glyph sheet id (type 0x0d)
} ui_element;

void draw_element_box_layer(ui_element *e)
{
    if (e->type == 0x0d) { if (e->subtype != 2 || e->kind != 4) return; }
    else if (e->type != 0x0f && e->type != 0x10) return;

    viewport_state *vp = (viewport_state *)iRam00701070;
    // viewport cull against scrollable content window
    if (e->x > (float)(vp->scrollX + 640 - vp->margRight)) return;
    if ((float)vp->scrollX - e->w > e->x)                   return;
    if ((float)vp->scrollY - e->h > e->y)                   return;
    if (e->y > (float)(vp->scrollY + 0x1ac))               return;

    float rx = e->x - vp->scrollX, ry = e->y - vp->scrollY;
    float rx1 = rx + e->w,          ry1 = ry + e->h;

    if (e->type == 0x0f) {
        if ((int)e->color >= 0)                    // top bit clear => draw fill
            draw_filled_rect(rx,ry,rx1,ry1, e->color | 0xff000000);
        if (e->thickness) {                        // bevel frame
            draw_hline(rx+1, ry+1, rx-1+e->w, ry+1, 0xff606060);
            draw_vline(rx+1, ry+1, rx+1, ry-1+e->h, 0xff606060);
            if (vp->focusSel == -1) {              // +0x14
                draw_vline(rx1,ry,rx1,ry1, 0xffd0d0d0);
                draw_hline(rx,ry1,rx1,ry1, 0xffd0d0d0);
            } else {
                float ex = rx-1+e->w, ey = ry-1+e->h;
                draw_vline(ex,ry-1,ex,ey, 0xffffffff);
                draw_hline(rx-1,ey,ex,ey, 0xffffffff);
            }
        }
    } else if (e->type == 0x10) {
        if (e->subtype == 2) {
            if ((int)e->color >= 0)
                draw_filled_rect(rx,ry,rx1,ry1, e->color | 0xff000000);
        } else if (e->subtype == 1 && e->thickness) {
            u8 t = e->thickness;
            if ((int)e->color < 1) {               // no fill color => grey/white bevel
                u32 hi = (vp->focusSel == -1) ? 0xffd0d0d0 : 0xffffffff;
                draw_filled_rect(rx,ry,rx+t,ry1, hi);
                draw_filled_rect(rx,ry,rx1,ry+e->thickness, hi);
                draw_filled_rect(rx1-e->thickness,ry+e->thickness,rx1,ry1,0xff606060);
                draw_filled_rect(rx+e->thickness,ry1-e->thickness,rx1,ry1,0xff606060);
                draw_corner(rx,ry1,rx+e->thickness,ry1,rx+e->thickness,ry1-e->thickness,0xff606060);
                draw_corner(rx1,ry,rx1,ry+e->thickness,rx1-e->thickness,ry+e->thickness,0xff606060);
            } else {                               // colored thick border
                u32 c = e->color | 0xff000000;
                draw_filled_rect(rx,ry,rx+t,ry1, c);
                draw_filled_rect(rx,ry,rx1,ry+e->thickness, c);
                draw_filled_rect(rx1-e->thickness-1,ry+e->thickness,rx1,ry1, c);
                draw_filled_rect(rx+e->thickness,ry1-e->thickness-1,rx1,ry1, c);
            }
        }
    } else { // 0x0d
        draw_tiled_glyph_fill(e, e->glyphSheet);
    }
}
```

## Evidence
- Raw decompile: type gate on `pcVar3[2]` (0x0d/0x0f/0x10), viewport cull vs `iRam00701070+4/+8`,
  bevel line calls (FUN_005e19b0/1a30/0510), and type-0x0d delegation to FUN_005e5910.
- Field offsets (+0x34/+0x38 pos, +0x40/+0x44 size, +0x58 color, +0x5d thickness, +0x5f sheet)
  are shared with FUN_005e2fa0/FUN_005e3a80 (same element record). Runtime-unvalidated.

## Remaining uncertainty
- `iRam00701070+0x14` interpreted as a focus/press sentinel (-1 = none); exact semantics unproven.
- The 18 "Removing unreachable block" warnings indicate the decompiler collapsed a jump
  table; the reconstructed branches cover the reachable cases only — some rare subtype
  combinations may be omitted.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e2760.c`  — untouched decompiler output.
