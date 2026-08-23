# 0x005eca10 draw_hrule_or_underline

| field | value |
|---|---|
| Original address | 0x005eca10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eca10 |
| Resolved name | draw_text_decoration_line |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ed0c0 (layout_and_draw_rule), FUN_005f3150
**Callees:** FUN_005d8b90, FUN_005d8c90, FUN_005d9bd0, FUN_005d9ca0 (line/decoration draw primitives); `func_0x0010a050` (strlen) [inferred]
**Referenced globals:** iRam007012a0; +0x20 (href/link-target buffer); +0xe96b (force-draw flag); +0x17f (decoration style 0..3); +0x180 (glyph height/thickness, u8); +0x17d / +0x17e (border-left / border-right flags); +0x178 (link/decoration color, u32); +0x124 (current font index, short) / +0x128 (font-color table); +0xd8c8 (x adjust, u16); +0x8f6 / +0x9f6 (decoration-state scratch bytes)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x17f (style), +0x17d/+0x17e (borders), +0x8f6

## Behavioral explanation
Draws a horizontal decoration line — a text underline (for `<a>` links / underlined runs), a strike/rule, or a table-cell border — beneath the current run. It is gated: it only draws when the link-target buffer at `+0x20` is non-empty (`strlen != 0`, i.e. this run is a hyperlink and gets an underline) **or** the force-draw flag `+0xe96b` is set (unconditional rule, e.g. `<hr>`). It then dispatches on the decoration style byte `+0x17f` (0..3) and the two border flags `+0x17d`/`+0x17e` to one of four low-level line primitives, each of which strokes a horizontal segment from `x` to `x+width` at the run's baseline, using either the current font color (`+0x128[+0x124]`) or the dedicated decoration color (`+0x178`). Before drawing, the y coordinate is advanced by the element height (`param_3[+2]`).

## Input / output
- `param_1` — opaque draw context/handle; its low 16 bits also seed the segment x (`(param_1 & 0xffff) + x_adjust`).
- `param_2` — `short` baseline y; incremented by the element height before drawing.
- `param_3` — `int` pointer to the element metrics record; `*(short*)(param_3+2)` = element height added to y.
- returns `void`.

## Side effects
- Emits draw calls into the display list via the four primitives (visible output).
- Style 0 path clears the decoration-state byte `+0x8f6` to 0.
- No other renderer state written.

## Important branches
- **Gate:** `strlen(href@+0x20) != 0 || +0xe96b != 0` — otherwise return without drawing.
- **style = +0x17f:**
  - `== 3`: draw via `FUN_005d8b90` with **font color** `+0x128[cur_font]`. No border/underline-buffer variants.
  - `== 2`: **decoration color** `+0x178`; border select:
    - `+0x17d != 0` -> `FUN_005d9bd0`; else `+0x17e != 0` -> `FUN_005d9ca0`; else `FUN_005d8c90`. Extra arg = `+0x9f6`.
  - `== 1`: same border select as style 2 but extra arg = `+0x8f6`.
  - `== 0`: first `*(u8*)(+0x8f6) = 0`; **font color** `+0x128[cur_font]`; border select:
    - `+0x17d != 0` -> `FUN_005d9bd0`; else `+0x17e != 0` -> `FUN_005d9ca0`; else `FUN_005d8b90`. Extra arg = `+0x8f6`.
- All paths first do `param_2 += *(short*)(param_3+2)` (advance y by element height).

## Constants & flags
- `+0x17f` decoration style: `0`=default underline (font color, resets +0x8f6), `1`=underline variant A (uses +0x8f6 state), `2`=underline variant B (uses +0x9f6 state), `3`=plain rule (font color, no state). [inferred labels]
- `+0x17d` = has-left-border, `+0x17e` = has-right-border: select the border-aware primitive (9bd0 for left, 9ca0 for right) over the plain one (8b90/8c90).
- glyph thickness `+0x180` subtracted from y to get the segment top (`y - glyph_w` .. `y`).
- x = `(ctx & 0xffff) + *(u16*)(+0xd8c8)` (scroll/indent x adjust).

## Corrected reconstruction
```c
// Draw the underline / rule / border segment under the current run.
// Gate: only when this run is a link (href set) or a forced rule (+0xe96b).
void draw_text_decoration_line(u64 ctx, short y, int *elem)
{
    RendererState *R = (RendererState *)iRam007012a0;
    if (strlen(R->href /*+0x20*/) == 0 && R->force_rule /*+0xe96b*/ == 0)
        return;

    char   style   = R->decor_style;      // +0x17f  (0..3)
    u8     thick   = R->glyph_h;          // +0x180
    u16    x       = (u16)ctx + R->x_adjust;   // +0xd8c8
    u32    fcolor  = R->font_color_tab[R->cur_font];   // +0x128[ +0x124 ]
    u32    dcolor  = R->decor_color;      // +0x178

    y += (short)elem[/*+2 bytes*/];       // advance y by element height

    if (style == 3) {
        FUN_005d8b90(ctx, y - thick, fcolor, thick, x, y, &R->href);
    } else if (style == 2) {
        if (R->border_l)       FUN_005d9bd0(ctx, y-thick, dcolor, thick, x, y, &R->href, &R->st_9f6);
        else if (R->border_r)  FUN_005d9ca0(ctx, y-thick, dcolor, thick, x, y, &R->href, &R->st_9f6);
        else                   FUN_005d8c90(ctx, y-thick, dcolor, thick, x, y, &R->href, &R->st_9f6);
    } else if (style == 1) {
        if (R->border_l)       FUN_005d9bd0(ctx, y-thick, dcolor, thick, x, y, &R->href, &R->st_8f6);
        else if (R->border_r)  FUN_005d9ca0(ctx, y-thick, dcolor, thick, x, y, &R->href, &R->st_8f6);
        else                   FUN_005d8c90(ctx, y-thick, dcolor, thick, x, y, &R->href, &R->st_8f6);
    } else { // style == 0
        R->st_8f6 = 0;
        if (R->border_l)       FUN_005d9bd0(ctx, y-thick, fcolor, thick, x, y, &R->href, &R->st_8f6);
        else if (R->border_r)  FUN_005d9ca0(ctx, y-thick, fcolor, thick, x, y, &R->href, &R->st_8f6);
        else                   FUN_005d8b90(ctx, y-thick, fcolor, thick, x, y, &R->href);
    }
}
```

## Evidence
- Raw decompile: gate `func_0x0010a050(base+0x20) != 0 || base[0xe96b] != 0`; four-way `switch (base[0x17f])`; nested `base[0x17d]`/`base[0x17e]` border tests; color source `*(u32*)(base[0x124]*4 + base + 0x128)` (font) vs `*(u32*)(base+0x178)` (decor); `param_2 += *(short*)(param_3+2)`; `y - (u8)base[0x180]`; x `= (uVar2&0xffff) + (u16)base[0xd8c8]`.
- Style-0 clears `base[0x8f6]=0` before drawing.

## Remaining uncertainty
Primitive signatures (005d8b90/8c90/9bd0/9ca0) not decoded here — arg roles (color/thickness/state buffer) inferred from position and the two color sources. The 0..3 style labels and border-flag meanings are inferred; the +0x8f6/+0x9f6 scratch bytes carry underline continuation state whose exact use lives in the primitives. Runtime-unvalidated. Confidence Medium.
