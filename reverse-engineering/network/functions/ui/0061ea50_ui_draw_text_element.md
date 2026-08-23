# 0x0061ea50 ui_draw_text_element

| field | value |
|---|---|
| Original address | 0x0061ea50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061ea50 |
| Resolved name | ui_draw_glyph_at |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0061eab0 (keyboard_element_render)
**Callees:** FUN_0061c940 (acquire draw handle), FUN_0061cc80 (layout/measure), extern 0x1af080, extern 0x1af0d0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Draws a single glyph/icon element (a paging arrow or highlight marker) at a computed screen position. Sequence:
1. `h = FUN_0061c940()` — acquire/allocate a draw handle or select the glyph resource for `param_1`.
2. `pos = FUN_0061cc80(h, param_3)` — run layout/measure with the handle and the x-reference `param_3`, yielding the resolved x position (this is the same measure helper `keyboard_element_render` uses to center strings).
3. `0x1af080(pos, param_2)` — set draw position to (resolved-x, `param_2`=y).
4. `0x1af0d0(h)` — submit/draw the handle.

The three callers in `keyboard_element_render` pass a small selector (`1/2/3` = which arrow/marker glyph, e.g. prev/current/next), a fixed y (`0x16e`=366, `0x17e`=382, `0x18e`=398), and an x anchor derived from the element geometry (`sVar1-4`). Pure GS rendering.

## Input / output
- `param_1` (glyph/element selector, small int: 1,2,3, or a computed 1/3) — chooses which icon.
- `param_2` (y coordinate, e.g. 0x16e/0x17e/0x18e).
- `param_3` (x anchor / reference for layout).
- **Returns:** `void`.

## Side effects
- Acquires and releases a draw handle (FUN_0061c940 / submit via 0x1af0d0); emits GS draw commands. No global writes visible.

## Important branches
- None — straight-line. All variation comes from the callee behavior keyed on `param_1`.

## Constants & flags
- None literal here. Selector values `1/2/3` and y `0x16e/0x17e/0x18e` are supplied by the caller.

## Corrected reconstruction
```c
// Draw one glyph/marker (e.g. a paging arrow) at (laid-out x, y).
// param_1: glyph selector  param_2: y  param_3: x anchor/reference
void ui_draw_glyph_at(u64 glyph_sel, u64 y, u64 x_anchor)
{
    void *h  = ui_acquire_draw_handle(glyph_sel);   // FUN_0061c940 [inferred]
    int   x  = ui_layout_measure(h, x_anchor);      // FUN_0061cc80 [inferred: resolved x]
    gs_set_position(x, y);                           // extern 0x1af080
    gs_draw_submit(h);                               // extern 0x1af0d0
}
```

## Evidence
- Raw decompile: 4-call straight line, three params, `void`.
- Callee `FUN_0061cc80` is the same helper `keyboard_element_render` uses at its centering path (`FUN_0061cc80(acStack_80, entry.width)`), supporting the "layout/measure → x" reading.
- Call sites in eab0: `FUN_0061ea50(1,0x18e,sVar1-4)`, `(2,0x17e,...)`, `(3,0x18e,...)`, `(uVar7,0x18e,...)`.
- Runtime-unvalidated; extern semantics inferred.

## Remaining uncertainty
- Whether `FUN_0061c940` acquires vs selects a resource, and whether `FUN_0061cc80` returns an x vs a full rect, are inferred. Parameter types are `undefined8` in the decompile; treated as small ints/coords.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061ea50.c`  — untouched decompiler output.
