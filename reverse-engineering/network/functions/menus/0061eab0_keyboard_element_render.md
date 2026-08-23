# 0x0061eab0 keyboard_element_render

| field | value |
|---|---|
| Original address | 0x0061eab0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061eab0 |
| Resolved name | text_entry_element_render |
| Subsystem | menus |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00619800
**Callees:** FUN_005b7cd0 (draw filled/highlight box), FUN_0061cc80 (measure/center), FUN_0061ea50 (draw glyph/arrow)
**Referenced globals:**
- `0x669c60` — per-element geometry table, 8 bytes/entry: `+0` x (short, `-1`=center sentinel), `+2` y (short), `+4` box-width/height (short, `sVar1`), `+6` color index (short) into `0x669c40`.
- `0x669c40` — color/palette table (u32 entries, indexed by geometry `+6`).
- Format/label strings: `0x669d10`, `0x669d18`, `0x669d20`, `0x669d30`, `0x669d40`.
- Literal strings: `0x3c9580` (case 1 label), `0x86f820` (case 0xd), `0x86f810` (case 0xe password label), `0x86f864` (case 0xc box arg), `0x6fc5e8`/`0x365c64` (case 0x12/0x13 colors), `0x365bf4`/`0x365d34` (per-page color tables), `0x365cf0` (total-pages count).
- Entered-text buffers: `0x715368` (0x80-byte name), `0x715344` (0x15-byte field), `0x715360`.
**Referenced strings:** password mask `'*'`; page-counter format `0x669d40`.
**Referenced opcodes:** —
**State vars:** `0x7152e0` (mode char, `'5'` special), `0x7152e4`, `0x7152e6` (signed value), `0x7152ea` (current page index), `0x7152f6`, `0x365cf0` (total page count).

## Behavioral explanation
Renders one element of the on-screen text-entry / soft-keyboard / paged-list UI (the create-room name & password entry screen and its list pager). `param_1` selects the element; a big `switch(param_1)` (cases 0–0x15) either:
- **Builds a display string** into `acStack_80[128]` (from a literal, a `sprintf`-style format + state var, or a raw copy of an entered-text buffer) and falls through to the common draw tail `LAB_0061f028`, which draws the string at the element's geometry with its palette color; or
- **Draws directly and returns** (highlight boxes via `FUN_005b7cd0`, paging arrows via `FUN_0061ea50`) for the interactive cases (0xc, 0x10, 0x11, 0x12/0x13/0x14).

Both stack buffers are zero-initialized first (128-byte string, 20-byte scratch). Geometry for the element is read from `0x669c60 + param_1*8`.

Key cases:
- **0** — format scratch from `0x669d10` with state `0x7152f6`, transform via `0x1b7650`, draw.
- **1** — copy label `0x3c9580`.
- **5** — format from `0x669d18` with `0x7152e4`.
- **6** — copy up to 0x80 bytes of the entered name from `0x715368`.
- **7** — copy up to 0x15 bytes from `0x715344`.
- **8** — format from `0x669d20` with `0x715360`.
- **0xc** — draw a highlight box (`FUN_005b7cd0`) at the element rect, then a marker glyph `FUN_0061ea50(1,0x18e,width-4)`; sets GS blend/color state around it; returns.
- **0xd** — copy `0x86f820`.
- **0xe** — copy password label `0x86f810`, then overwrite every character with `'*'` (password masking).
- **0xf** — take signed `0x7152e6`: negative → absolute value; `==1` → `0`; format via `0x669d30`. (A signed counter with a "1 means blank" special case.)
- **0x10 / 0x15** — page counter: draw selection box, format `"cur+1 / total"` (`0x669d40`, args `0x7152ea+1`, `0x365cf0`), then draw prev/cur/next arrows via `FUN_0061ea50`; arrow set depends on whether current==first or current==last and on mode char `0x7152e0=='5'` (`uVar7` 3→1). Returns.
- **0x11** — like 0x10 but a single arrow.
- **0x12 / 0x13 / 0x14** — draw only a colored box (`FUN_005b7cd0`) with a case-specific palette (fixed color, `0x365c64`, or per-page `0x365bf4[page]`). Return.
- **default / LAB_0061f028** — the common text-draw tail (see below).

Common draw tail `LAB_0061f028`: enable draw (`0x1ad8b0(1)`), set blend/color from the element's palette entry (`0x669c40[geom+6]`), set position, then draw the string — if geometry `+0` x is `-1` the string is **centered** (`FUN_0061cc80(str, width)` computes x); otherwise x = geometry `+0`. Disable draw (`0x1ad8b0(0)`).

## Input / output
- `param_1` (int) — element/case id (0–0x15). Selects geometry row and render behavior.
- **Returns:** `void`.
- **Reads:** entered-text buffers and menu state vars (page index, mode, counters).

## Side effects
- Emits GS draw commands (boxes, text, glyphs); toggles GS draw-enable/blend/color externs (`0x1ad8b0`, `0x1af0a0/b0/c0/060/080/190/0d0`). No protocol/network state; no global writes except transient GS registers.

## Important branches
- `switch(param_1)`: each case selects string source or a direct-draw path; unmatched → `LAB_0061f028` text tail.
- **0xe** password loop: `for(;*p;p++) *p='*'` — masks the copied label.
- **0xf** sign handling: `<0 → -v`; `==1 → 0`; else `v`.
- **0x10 vs 0x15**: 0x10 always draws two arrows; 0x15 chooses arrow set by `page==last?` (`0x7152ea+1 == total`).
- **0xc / 0x10 mode**: `cRam007152e0=='5'` → `uVar7=1` else `3` (alternate arrow glyph, likely enabled/disabled state).
- Tail centering: geometry `x == -1` → center via measure; else fixed x.

## Constants & flags
- `'*'` (0x2A) — password mask character. Evidence: case 0xe overwrite loop.
- geometry `x == -1` — center-text sentinel. Evidence: `if (*psVar5 == -1)` at tail.
- `'5'` (`0x7152e0`) — mode discriminator selecting alternate arrow glyph. `[inferred]` meaning.
- Buffer sizes: name `0x80` (`0x715368`), field `0x15` (`0x715344`).
- `0x365cf0` — total page count; `0x7152ea` — current page (0-based; displayed +1).

## Corrected reconstruction
```c
// Per-element renderer for the text-entry / soft-keyboard / paged-list screen.
// Geometry table entry (8 bytes) at 0x669c60 + id*8:
typedef struct { s16 x; s16 y; s16 wh; s16 color_idx; } ui_geom_t; // x==-1 => center

void text_entry_element_render(int id)
{
    char str[128] = {0};
    u8   scratch[20] = {0};
    ui_geom_t *g = (ui_geom_t*)(0x669c60 + id*8);

    switch (id) {
    case 0:  sprintf(scratch, FMT_0x669d10, state_7152f6); xform_1b7650(scratch, str); goto draw_text;
    case 1:  strcpy(str, LABEL_3c9580); break;
    case 5:  sprintf(str, FMT_0x669d18, state_7152e4); break;
    case 6:  memncpy(str, name_buf_715368, 0x80); break;   // entered room name
    case 7:  memncpy(str, buf_715344, 0x15); break;
    case 8:  sprintf(str, FMT_0x669d20, state_715360); break;

    case 0xc: // highlight box + selection marker glyph
        gs_draw_enable(1); gs_blend(-2); gs_color(0); gs_color2(0x80808080);
        gs_size(g->wh, g->wh);
        draw_box((float)g->x, (float)g->y, 0x4f800000, 0x86f864);
        gs_color(0); gs_color2(0x80008080);
        gs_size(g->wh-4, g->wh-4);
        ui_draw_glyph_at(1, 0x18e, g->wh-4);
        gs_draw_enable(0);
        return;

    case 0xd: strcpy(str, LABEL_86f820); break;
    case 0xe: strcpy(str, LABEL_86f810);
              for (char *p=str; *p; ++p) *p='*';   // password mask
              break;
    case 0xf: { int v = state_7152e6;
                if (v < 0) v = -v; else if (v == 1) v = 0;
                sprintf(str, FMT_0x669d30, v); } break;

    case 0x10: case 0x15: { // paged counter "cur/total" + prev/cur/next arrows
        draw_box((float)g->x,(float)g->y,0x4f800000, page_color_365d34[state_7152ea]);
        sprintf(str, FMT_0x669d40, state_7152ea+1, total_pages_365cf0);
        gs_color(0); gs_color2(0x80808080); gs_set_position(0x21c,0x26); gs_puts(str);
        gs_color(0); gs_color2(0x80008080); gs_size(g->wh-4, g->wh-4);
        int alt = (mode_7152e0 == '5') ? 1 : 3;
        if (id == 0x10) { ui_draw_glyph_at(2,0x17e,g->wh-4); ui_draw_glyph_at(alt,0x18e,g->wh-4); return; }
        if (state_7152ea+1 == total_pages_365cf0) {           // last page
            ui_draw_glyph_at(1,0x16e,g->wh-4);
            ui_draw_glyph_at(2,0x17e,g->wh-4);
            ui_draw_glyph_at(3,0x18e,g->wh-4); return;
        }
        ui_draw_glyph_at(2,0x17e,g->wh-4);                     // not last: no back arrow
        ui_draw_glyph_at(3,0x18e,g->wh-4); return;
    }
    case 0x11: // single arrow variant
        draw_box((float)g->x,(float)g->y,0x4f800000, page_color_365d34[state_7152ea]);
        sprintf(str, FMT_0x669d40, state_7152ea+1, total_pages_365cf0);
        gs_color(0); gs_color2(0x80808080); gs_set_position(0x21c,0x26); gs_puts(str);
        gs_color(0); gs_color2(0x80008080); gs_size(g->wh-4,g->wh-4);
        ui_draw_glyph_at(1,0x18e,g->wh-4); return;

    case 0x12: draw_box((float)g->x,(float)g->y,0x4f800000, 0x6fc5e8); return;
    case 0x13: draw_box((float)g->x,(float)g->y,0x4f800000, color_365c64); return;
    case 0x14: draw_box((float)g->x,(float)g->y,0x4f800000, page_color_365bf4[state_7152ea]); return;
    }

draw_text: // LAB_0061f028 — common string draw with element palette + optional centering
    gs_draw_enable(1);
    gs_blend(-2);
    gs_color(0);
    gs_color2(palette_669c40[g->color_idx]);
    gs_size(g->wh, g->wh - 2);
    if (g->x == -1) {                              // center sentinel
        int cx = ui_layout_measure(str, g->wh);    // FUN_0061cc80
        gs_set_position(cx, g->y);
    } else {
        gs_set_position(g->x, g->y);
    }
    gs_puts_ptr(str);                              // 0x1af0d0
    gs_draw_enable(0);
}
```

## Evidence
- Raw decompile: full `switch(param_1)` with the cases transcribed above; two zeroed stack buffers (`acStack_80[128]`, `auStack_a0[32]`).
- Geometry stride 8 (`param_1*8`) with reads at `+0/+2/+4/+6`; color indexed `*(u32*)(geom[+6]*4 + 0x669c40)`.
- Password mask loop `for(; *pcVar6; ) *pcVar6='*'` (case 0xe).
- Center sentinel `if (*psVar5 == -1)` at `LAB_0061f028`.
- Callees `FUN_005b7cd0` (box), `FUN_0061ea50` (glyph), `FUN_0061cc80` (measure).
- Runtime-unvalidated; extern GS-call names inferred from usage pattern.

## Remaining uncertainty
- The exact roles of the GS externs (`0x1af0a0/b0/c0/060/080/190`, `0x1ad8b0`, `0x1b7650`) are inferred, not decoded; names are best-effort.
- Which physical screen each case id maps to (name field vs password vs list pager) is inferred from the buffers used (name `0x715368`, password label `0x86f810`) — not runtime-confirmed.
- `mode_7152e0=='5'` semantics unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061eab0.c`  — untouched decompiler output.
