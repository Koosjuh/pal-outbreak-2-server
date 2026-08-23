# 0x005daf30 ui_draw_selection_overlay

| field | value |
|---|---|
| Original address | 0x005daf30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005daf30 |
| Resolved name | ui_draw_item_list |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (installed as node draw callback by FUN_005dae40)
**Callees:** FUN_005dfee0 (free node), FUN_005e2760 (item pre-pass), FUN_005e2fa0 (draw item), FUN_005e0440 (draw filled rect), FUN_005e3a80 (post-selection hook), func_0x001af030
**Referenced globals:** iRam00701068+0x5ffc0: 500-entry item pointer table; iRam00701078+0x20: selected index; iRam00701070+0x34: input-suppress flag; +0x4/+0x8: scroll offsets; +0x60dc4: destroy counter
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x34; selected-index @ 0x78+0x20

## Behavioral explanation
Per-frame draw callback for the scrollable item list (installed by `ui_spawn_list_widget`). Unless it is being destroyed or input is suppressed (+0x34), it walks the 500-slot item pointer table at `iRam00701068 + 0x5ffc0` in two passes: a reverse pre-pass (indices 499→1) that touches each populated item (`FUN_005e2760`, likely layout/measure), then a forward pass (1→first empty) that draws each item (`FUN_005e2fa0`) and, for the item whose index equals the current selection (`iRam00701078 + 0x20`), draws a translucent highlight rectangle (color 0x400000ff) around it, positioned from the item's rect (+0x34/+0x38) offset by the scroll (+0x4/+0x8). Finally it calls a post-selection hook (`FUN_005e3a80(selected)`) and `func_0x001af030`. This is the visual renderer of whatever list is loaded (room list, roster, menu) — but it performs no protocol work; it only reflects already-populated state.

## Input / output
- `param_1` (`int` → node ptr): the list widget node.
- Returns: void.

## Side effects
- On lifecycle 'c': frees node, `+0x60dc4++`.
- Otherwise: draws items + highlight (display list only), calls FUN_005e3a80 / func_0x001af030.
- No protocol/global-state writes beyond the destroy counter.

## Important branches
- `cVar1 = node[6]`; if `'c'` → free + counter, return.
- Main gate: `else if (((cVar1==1) || (cVar1!=0)) && (+0x34 == 0))` — i.e. any non-zero lifecycle AND input-suppress flag clear. (The `cVar1==1 || cVar1!=0` is a decompiler artifact meaning "cVar1 != 0"; lifecycle 0 skips the body.)
- Reverse pre-pass: `for (i=499; i!=0; i--)` with `i = (i-1) & 0xffff`: `p = table[i]`; `if (p && *p) FUN_005e2760();`.
- Forward draw pass: `for (i=1; i<500; i=(i+1)&0xffff)`: `p = table[i]`; `if (p==0 || *p==0) break;` (stop at first empty slot); `FUN_005e2fa0();` draw item; `if (selected_index == i)` → compute `x = item.f34 - scroll_4`, `y = item.f38 - scroll_8`, `FUN_005e0440(x+1, y+1, item.w40 + x-2, item.h44 + y-1, 0x400000ff)` highlight.
- After loop: `FUN_005e3a80(selected_index); func_0x001af030();`.

## Constants & flags
- Item table: 500 slots (`0..499`), base `iRam00701068 + 0x5ffc0`, 4-byte pointers; slot 0 unused (loops start at 1).
- Empty-slot terminator: `ptr == NULL || *ptr == 0` ends the forward pass (list is packed/contiguous).
- Selected index: `iRam00701078 + 0x20`.
- Highlight color 0x400000ff: ARGB-ish, alpha 0x40 (25%) translucent, blue-ish (0x0000ff) — the selection tint.
- +0x34 input-suppress flag: when set, the whole list draw is skipped.

## Corrected reconstruction
```c
// node callback; item_table @ iRam00701068+0x5ffc0 (500 ptrs)
void ui_draw_item_list(ui_widget_t *node /*p1*/)
{
    ui_block_t  *ui = (ui_block_t *)iRam00701070;
    uint8_t     *ev = (uint8_t *)iRam00701068;
    char **table = (char **)(ev + 0x5ffc0);
    uint32_t selected = *(uint32_t *)((uint8_t *)iRam00701078 + 0x20);

    char lc = node->lifecycle;                 // +6
    if (lc == 'c') { FUN_005dfee0(node); ev[0x60dc4]++; return; }
    if (lc == 0 || ui->input_suppress /*+0x34*/ != 0) return;

    // reverse pre-pass (measure/layout)
    for (unsigned i = 499; i != 0; i = (i - 1) & 0xffff) {
        char *p = table[i];
        if (p && *p) FUN_005e2760(/*item i*/);
    }
    // forward draw pass (packed list, stop at first empty)
    for (unsigned i = 1; i < 500; i = (i + 1) & 0xffff) {
        char *p = table[i];
        if (p == NULL || *p == 0) break;
        FUN_005e2fa0(/*item i*/);
        if (selected == i) {
            ui_item_t *it = (ui_item_t *)table[i];
            float x = it->rx /*+0x34*/ - (float)ui->scroll_x /*+4*/;
            float y = it->ry /*+0x38*/ - (float)ui->scroll_y /*+8*/;
            FUN_005e0440(x + 1.0f, y + 1.0f,
                         it->w /*+0x40*/ + (x - 2.0f),
                         it->h /*+0x44*/ + (y - 1.0f),
                         0x400000ff);          // translucent highlight
        }
    }
    FUN_005e3a80(selected);                     // post-selection hook
    func_0x001af030();
}
```

## Evidence
- Raw decompile: `sources/overlays/overlay-3dat-decompile/FUN_005daf30.c`.
- Installed as callback by FUN_005dae40 (node+0x18). Item table 0x5ffc0 (500 ptrs) and selected-index 0x78+0x20 reused here and in FUN_005e2fa0/FUN_005e3a80 family.
- Highlight via FUN_005e0440 with 0x400000ff constant.
- Runtime-unvalidated (static only).

## Remaining uncertainty
- Roles of FUN_005e2760 (pre-pass) vs FUN_005e2fa0 (draw) inferred from ordering; item struct fields (+0x34/+0x38 rect vs +0x40/+0x44 size) inferred from the rect math. Whether the populated list is the lobby room list / roster in a given state is context-dependent and not proven here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005daf30.c`  — untouched decompiler output.
