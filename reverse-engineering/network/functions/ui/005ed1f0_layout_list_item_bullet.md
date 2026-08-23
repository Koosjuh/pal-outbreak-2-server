# 0x005ed1f0 layout_list_item_bullet

| field | value |
|---|---|
| Original address | 0x005ed1f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ed1f0 |
| Resolved name | layout_marker_box |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005e9a90, FUN_005e9b20
**Callees:** FUN_005ec170 (recompute x cursor), FUN_005d93f0 (filled-box draw), FUN_005f2450 (nested variant), FUN_005ed160 (advance_line_index)
**Referenced globals:** iRam007012a0; +0xd892 (nesting depth); +0x8f4 (marker box width, u16); +0x8f2 (marker box height, u16); +0x188 (line index); +0x10 (container width); +0x12 (left margin); +0xd8bc (indent x); +0xd8be/+0xd8c6 (cursor y); +0xd8c2 (saved y); +0x186 (pass flag); +0xe96b (suppress-draw); line-record fields +0x1540 (width)/+0x1542 (height)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186 (pass), +0xd892 (depth), +0x8f4/+0x8f2 (marker size)

## Behavioral explanation
Lays out and (on the render pass) draws a rectangular marker/separator box for a list item or block element — a solid box of width `+0x8f4` and height `+0x8f2` placed at the current left indent, with ~10px of vertical gap above and below. If nested inside a table cell (`+0xd892 != 0`) it delegates to the cell variant `FUN_005f2450`. Otherwise, at top level:
1. Establishes a default marker width in `+0x8f4` if unset: full container width `+0x10` on the render pass, or the default `0x248` (584) on the measure pass; clamps a width of 1 up to a minimum of 2.
2. Advances the y cursor `+0xd8be` by 10 (leading gap).
3. On the render pass, optionally applies a centering offset (when `param_1 != 0` and the line is narrower than the available width) and draws the filled box via `FUN_005d93f0(x0, y0, x1, y1)`, gated by the suppress flag `+0xe96b`.
4. Advances y by `marker_height + 10` (trailing gap), snapshots it to `+0xd8c2`, recomputes the x cursor (`FUN_005ec170`).
5. On the measure pass, records the line's width (`x + marker_w`) and height (`marker_h + 0x14`) into the current line record.
6. Resets marker height `+0x8f2 = 0` and advances the line index.

## Input / output
- `param_1` — `long` center-align flag (non-zero -> center the marker within the available width).
- returns `void`.

## Side effects
- On render pass (non-nested, not suppressed): draws the marker box via `FUN_005d93f0`.
- Writes cursor state `+0xd8be`, `+0xd8c2`; marker width `+0x8f4`; resets marker height `+0x8f2`.
- On measure pass: writes line-record width `+0x1540` and height `+0x1542`.
- Advances line index (`FUN_005ed160`); recomputes x (`FUN_005ec170`).

## Important branches
- `+0xd892 != 0` (nested/in-cell): tail-call `FUN_005f2450`, return.
- marker-width defaulting: `+0x8f4 == 0` -> set to `+0x10` (render) or `0x248` (measure); `+0x8f4 == 1` -> set to `2`.
- `+0x186 == 0` (render pass): compute center offset when `param_1 != 0` and `line_width < avail`; draw box unless `+0xe96b`.
- `+0x186 == 1` (measure pass): store line width/height.

## Constants & flags
- `0x248` = 584 = default marker/container width (measure pass), same full-width constant used by `parse_number_or_percent`.
- vertical gaps: `+10` before and `+10` after; line height recorded as `marker_h + 0x14` (20).
- minimum marker width `2`.
- `+0x186`: 0 = render pass, 1 = measure pass.

## Corrected reconstruction
```c
// Lay out (and on render pass draw) a list-item / block marker box.
void layout_marker_box(long center)
{
    RendererState *R = (RendererState *)iRam007012a0;
    if (R->depth /*+0xd892*/ != 0) { FUN_005f2450(); return; }   // nested -> cell variant

    LineRec *line = (LineRec *)((char*)R + R->line_index /*+0x188*/ * 4);   // +0x1540/+0x1542
    unsigned x = (u16)(R->left_margin /*+0x12*/ + R->indent_a /*+0xd8bc*/);
    short x_s = (short)x;

    // default marker width
    if (R->marker_w /*+0x8f4*/ == 0)
        R->marker_w = (R->pass /*+0x186*/ == 0) ? R->box_width /*+0x10*/ : 0x248;
    else if (R->marker_w < 2)
        R->marker_w = 2;

    R->cur_y_b /*+0xd8be*/ += 10;                                // leading gap

    if (R->pass == 0) {                                          // render pass
        if (center != 0) {
            int avail = (int)R->box_width - (int)R->left_margin; // +0x10 - +0x12
            int lw = line->width;                                // +0x1540
            if (lw < avail) {
                int slack = avail - lw; if (slack < 0) slack++;
                x += (u16)(slack >> 1);                          // center offset
            }
        }
        x_s = (short)x;
        if (R->suppress_draw /*+0xe96b*/ == 0) {
            short y = R->cur_y_a /*+0xd8c6*/ + R->cur_y_b;
            FUN_005d93f0(x, y, x + R->marker_w, R->marker_h /*+0x8f2*/ + y);   // filled box
        }
    }

    R->cur_y_b += R->marker_h /*+0x8f2*/ + 10;                   // trailing gap
    R->saved_y /*+0xd8c2*/ = R->cur_y_b;
    FUN_005ec170(&R->indent_a /*+0xd8bc*/);                      // recompute x

    if (R->pass == 1) {                                          // measure pass
        line->width  = x_s + R->marker_w;                        // +0x1540
        line->height = R->marker_h + 0x14;                       // +0x1542
    }
    R->marker_h /*+0x8f2*/ = 0;
    advance_line_index();                                        // FUN_005ed160
}
```

## Evidence
- Raw decompile: depth fork `base[0xd892]=='\0'` else `FUN_005f2450()`; marker-width default `base[0x8f4]==0 -> base[0x10] / 0x248`, `< 2 -> 2`; two `+= 10` / `+= base[0x8f2] + 10` y advances; `FUN_005d93f0(x, y, x + base[0x8f4], base[0x8f2] + y)` gated by `base[0xe96b]`; measure-pass store `*puVar8 = x + base[0x8f4]`, `line+0x1542 = base[0x8f2] + 0x14`; `FUN_005ec170(base+0xd8bc)`; `FUN_005ed160()`.

## Remaining uncertainty
"list item bullet" is the original label; the code is a generic filled marker/separator box (list bullet, block-quote bar, or paragraph rule). `param_1` = center flag inferred from its use gating the center-offset math. Nested variant `FUN_005f2450` not decoded here. `FUN_005d93f0` box-draw arg order (x0,y0,x1,y1) inferred. Confidence Medium; runtime-unvalidated.
