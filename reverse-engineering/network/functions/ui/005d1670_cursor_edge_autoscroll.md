# 0x005d1670 cursor_edge_autoscroll

| field | value |
|---|---|
| Original address | 0x005d1670 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d1670 |
| Resolved name | scrollbar_track_arrow_scroll |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (per-frame; no in-corpus caller)
**Callees:** FUN_005d5df0 (directional scroll w/ tag)
**Referenced globals:** view@0x701070 (scroll +4/+8, content +0xc/+0x10, margins +0x1a..+0x20, thumb_v +0x22/+0x24, thumb_h +0x26/+0x28), cursor@0x701078 (cursor +0x10/+0x12, group_count +4), ui@0x701068 (scroll-arrow id +0x68e80/+0x68e81)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ui.vscroll_arrow(+0x68e80), ui.hscroll_arrow(+0x68e81)

## Behavioral explanation
Handles clicks on the scrollbar **arrow buttons** and **track gutter** (as opposed to dragging the
thumb, which is FUN_005d0f90). Only active on the top-level list (`group_count == 0`). If the cursor is
over the vertical scrollbar column: a hit on the top arrow scrolls up one notch and tags the active
arrow id = 3; the bottom arrow scrolls down, tag = 4; a hit on the track gutter above/below the thumb
pages the view by ±0x167 and recomputes the thumb position from `scroll_y`. The horizontal scrollbar
is handled symmetrically (page ±0x200, arrow ids into `ui+0x68e81`). No-op if the axis has no scrollable
content (`content_h`/`content_w == 0`).

## Input / output
- Inputs: cursor position, `view` scroll/content/margin/thumb fields, `cursor.group_count`.
- Output: void (scrolls + tags active arrow).

## Side effects
- FUN_005d5df0(dx,dy,tag) — arrow-button scroll (tags 1/2 vertical, 3/4 horizontal).
- Direct `view.scroll_y`(+8)/`scroll_x`(+4) page adds (±0x167 / ±0x200) and thumb recompute
  (`thumb_v_pos = scroll_y*0x15c/content_h + 0x10`; `thumb_h_pos = scroll_x*0x228/content_w + 0x10`).
- `ui.vscroll_arrow`(+0x68e80) = 3/4; `ui.hscroll_arrow`(+0x68e81) = 3/4.

## Important branches
- `cursor.group_count != 0` → **return** (only top-level list scrolls here).
- Vertical column hit (`margin_left+0x248 < cursor_x < 0x280−margin_right`), `content_h != 0`:
  - `cursor_y ∈ [margin_top, margin_top+0x10)` → 5df0(0,−20,1), arrow=3 (top arrow).
  - `cursor_y ∈ (0x17c, margin_top+0x17c)` → 5df0(0,+20,2), arrow=4 (bottom arrow).
  - `cursor_y ∈ (margin_top+0x10, margin_top+0x17c)` → gutter page: below thumb top → `scroll_y −=
    0x167`; above thumb bottom (`thumb_pos+thumb_size < cursor_y`) → `scroll_y += 0x167`; then
    `thumb_v_pos = scroll_y*0x15c/content_h + 0x10`.
- Horizontal row hit (`margin_top+0x17c < cursor_y < 0x1ac−margin_bottom`), `content_w != 0`:
  - left/right arrow → 5df0(−20,0,3) arrow=3 / 5df0(+20,0,4) arrow=4.
  - gutter → `scroll_x ±= 0x200`; `thumb_h_pos = scroll_x*0x228/content_w + 0x10`.

## Constants & flags
- Vertical column x-band `margin_left+0x248`(584)…`0x280−margin_right`(640); arrow zone height
  `0x10`(16); track end `0x17c`(380). Vertical page `0x167`(359); thumb scale `0x15c`(348).
- Horizontal row y-band `margin_top+0x17c`…`0x1ac−margin_bottom`(428); horizontal page `0x200`(512);
  thumb scale `0x228`(552). Thumb floor `+0x10`.
- Arrow-id tags: 3 = up/left pressed, 4 = down/right pressed (into +0x68e80 / +0x68e81).

## Corrected reconstruction
```c
void scrollbar_track_arrow_scroll(void)   // FUN_005d1670
{
    if (cursor->group_count != 0) return;

    // vertical scrollbar column
    if (view->margin_left + 0x248 < cursor->cursor_x
        && cursor->cursor_x < 0x280 - view->margin_right) {
        if (view->content_h == 0) return;
        int y = cursor->cursor_y, mt = view->margin_top;
        if (mt <= y && y < mt + 0x10) {                 // top arrow
            scroll_dir(0, -20, 1); ui->vscroll_arrow = 3;  return;
        }
        if (0x17c < y && y < mt + 0x17c) {              // bottom arrow
            scroll_dir(0,  20, 2); ui->vscroll_arrow = 4;  return;
        }
        if (mt + 0x10 < y && y < mt + 0x17c) {          // track gutter page
            if (y < view->thumb_v_pos)                       view->scroll_y -= 0x167;
            if (view->thumb_v_pos + view->thumb_v_size < y)  view->scroll_y += 0x167;
            view->thumb_v_pos = (short)(view->scroll_y * 0x15c / view->content_h) + 0x10;
        }
    }
    // horizontal scrollbar row
    if (view->margin_top + 0x17c < cursor->cursor_y
        && cursor->cursor_y < 0x1ac - view->margin_bottom
        && view->content_w != 0) {
        int x = cursor->cursor_x, mr = view->margin_right;
        if (x < mr || mr + 0x10 <= x) {
            if (x < 0x24d || mr + 0x248 <= x) {
                if (mr + 0x10 < x && x < mr + 0x24c) {   // gutter page
                    if (x < view->thumb_h_pos)                      view->scroll_x -= 0x200;
                    if (view->thumb_h_pos + view->thumb_h_size < x) view->scroll_x += 0x200;
                    view->thumb_h_pos = (short)(view->scroll_x * 0x228 / view->content_w) + 0x10;
                }
            } else { scroll_dir( 20, 0, 4); ui->hscroll_arrow = 4; } // right arrow
        } else     { scroll_dir(-20, 0, 3); ui->hscroll_arrow = 3; } // left arrow
    }
}
// scroll_dir(dx,dy,tag) == FUN_005d5df0
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005d1670.c` (size 812).
- Thumb scale `scroll*0x15c/content` and `scroll*0x228/content` mirror the inverse map in FUN_005d0f90
  (`content*(thumb−0x10)/track`); same thumb fields +0x22/+0x24/+0x26/+0x28.

## Remaining uncertainty
- The arrow-vs-track hit bands are transcribed exactly but the `0x68e80/0x68e81` tag ids (3/4) are only
  named by direction from the call args. FUN_005d5df0 assumed relative-scroll-with-tag.
  Runtime-unvalidated. (Renamed from `cursor_edge_autoscroll` — it is scrollbar-track/arrow scroll, not
  cursor-position edge scroll; the latter is FUN_005d0af0.)
