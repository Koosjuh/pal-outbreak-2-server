# 0x005eacd0 markup_element_close_t1_layout

| field | value |
|---|---|
| Original address | 0x005eacd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eacd0 |
| Resolved name | markup_cell_close_layout_commit |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f0e10, FUN_005f10a0, FUN_005f1570
**Callees:** FUN_005f10a0 (inner close/measure), FUN_005f1da0, FUN_005ec170, FUN_005ed160, FUN_005f21f0
**Referenced globals:** g_mkp+0xd892 (table nesting depth, u8); +0xd894 (current cell index, u16);
+0xd89a[] (per-depth cell-index table); +0x186 (pass mode); +0x188 (place-target index); +0x1540[]
(placed-cell x/y grid); +0x182 (page max width); +0x18b/+0x18c (dirty flags); +0xd8be/+0xd8c2/+0xd8bc
(running document height); +0xd8ce.. (scroll/region snapshot); per-cell struct base +0x24e0
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** g_mkp+0xd892, +0xd894, +0x186

## Behavioral explanation
End-of-cell (type-1 / table-cell) layout finalizer for the markup engine. When a table cell closes it:
(1) runs the inner measure/close `FUN_005f10a0(cursor,out,1)`; (2) resolves the current cell record from
the per-depth index table `+0xd89a[depth]`; (3) folds the cell's content extents into its measured width
`+0x24fc` and height `+0x24fe`; (4) then, depending on nesting depth, EITHER commits the cell to the
document flow (depth reaches 0) — placing it into the grid `+0x1540[]` and advancing the running document
height `+0xd8c2`, refreshing via `FUN_005ec170`/`FUN_005ed160` — OR accumulates its height into the parent
render node (`obj+0x24`, `+0x2e`) when still nested. Finally it flushes the cell via `FUN_005f21f0` and, if
still inside an outer table (`depth>1`), snapshots geometry into the scroll/region block `+0xd8ce..`.
Pure layout math; no protocol.

## Input / output
- `param_1` — `char **cursor` (tag scan cursor), `param_2` — `char *out` (output/emit buffer, reset to
  empty here).
- Return `u32`: `0` success; `0xFFFFFFFF` (-1) on inner-close failure or missing parent node when nested.
  Returns `0` immediately (no work) when `g_mkp+0xd892 == 0` (no open table).

## Side effects
- `FUN_005f10a0` closes/measures the inner element; may recurse.
- Reloads `+0xd894` from `+0xd89a[depth]`; writes cell fields `+0x24fc/+0x24fe/+0x252e`.
- Resets `g_mkp+4 = 0` and `out[0] = 0`.
- Decrements `+0xd892` (depth) by 1 when `depth < 2`.
- On final close (`depth`→0): in place-pass (`+0x186==1`) writes grid coords `+0x1540[+0x188]`; in
  measure-pass (`0xF6`) raises page width `+0x182`; adds cell height to running `+0xd8c2`, mirrors to
  `+0xd8be`, calls `FUN_005ec170(+0xd8bc)` and `FUN_005ed160()`; sets dirty `+0x18c` if `+0x18b`.
- When still nested (`depth>=2`): adds cell height into parent `obj+0x24` and `+0x2e`; in measure-pass
  raises `obj+0x20` and bumps child-count `obj+0x44`; sets dirty `+0x18c` if `obj+0x50 & 1`.
- Always: `FUN_005f21f0(cell+0x24e0)`; if `depth>1` snapshots `obj` geometry into `+0xd8ce..+0xd8de`.

## Important branches
- `+0xd892 == 0` -> return 0 (nothing open).
- `FUN_005f10a0(...) < 0` -> return -1.
- `cell+0x24ec != 0` -> compute content advance via `FUN_005f1da0`, raise `cell+0x24fc`.
- `depth < 2` (final cell): decrement depth; when depth becomes 0, run the document-commit block,
  branching again on pass mode `+0x186` (1 = place, 0xF6 = measure).
- `depth >= 2` (nested): require parent `obj != 0` (else return -1); accumulate into parent; measure-pass
  extra width/count updates.
- Trailer `1 < +0xd892` -> snapshot region geometry (`+0xd8ce..`).

## Constants & flags
- `PASS_PLACE 0x01`, `PASS_MEASURE 0xF6` at `+0x186`. [inferred names]
- Cell stride = `idx*92` (`idx*0x18 - idx`)*4; cell base offset `+0x24e0`.
- `obj+0x50 & 1` = "propagate-dirty" cell flag. [inferred]
- `FUN_005f1da0(src, -10)` = content-advance query (arg `0xFFFFFFFFFFFFFFF6`). [inferred]

## Corrected reconstruction
```c
// cell = &g_mkp[0x24e0 + idx*92]; obj = *(void**)(cell+0)  (parent/render node)
u32 markup_cell_close_layout_commit(char **cursor, char *out) {
    if (g_mkp->table_depth == 0) return 0;                 // +0xd892
    if (FUN_005f10a0(cursor, out, 1) < 0) return (u32)-1;

    g_mkp->cur_cell = g_mkp->cell_index_by_depth[g_mkp->table_depth]; // +0xd894 = +0xd89a[depth]
    MkpCell *c = MKP_CELL(g_mkp->cur_cell);                // base +0x24e0, stride 92
    void   *parent = c->obj;                               // +0x24e0

    if (c->content_src != 0) {                             // +0x24ec
        u32 adv = (FUN_005f1da0(c->content_src, -10) & 0xffff)
                + c->border_u16 /*+0x2512*/ + c->border_b*2 /*+0x2525*/;
        if (c->measured_w < adv) c->measured_w = adv;      // +0x24fc
    }
    c->flag_252e = 0;
    g_mkp->emit_len = 0;  *out = 0;                        // +4, out[0]

    u32 h = c->border_b /*+0x2525*/ + c->pad_w /*+0x2504*/ + c->border_u16 /*+0x2512*/;
    if (c->measured_h < h) c->measured_h = h;              // +0x24fe

    u8 depth = g_mkp->table_depth;
    if (depth < 2) {                                       // ---- final / top-level cell ----
        if (depth != 0) g_mkp->table_depth = depth - 1;
        if (g_mkp->table_depth == 0) {
            if (g_mkp->pass_mode == 1) {                   // PLACE: write grid coords
                g_mkp->grid[g_mkp->place_index].x = c->x /*+0x2508*/ + c->measured_w; // +0x1540[+0x188]
                g_mkp->grid[g_mkp->place_index].y = c->y /*+0x250a*/ + c->measured_h;
            } else if (g_mkp->pass_mode == (s8)0xF6) {     // MEASURE: raise page width
                u32 w = c->x + c->measured_w;
                if (g_mkp->page_w < w) g_mkp->page_w = w;  // +0x182
            }
            g_mkp->doc_h += c->measured_h;                 // +0xd8c2
            g_mkp->doc_h_mirror = g_mkp->doc_h;            // +0xd8be
            FUN_005ec170(&g_mkp->field_d8bc);
            FUN_005ed160();
            if (g_mkp->flag_18b) g_mkp->dirty_18c = 1;
        }
    } else {                                               // ---- nested cell ----
        if (parent == 0) return (u32)-1;
        *(s16*)(parent+0x24) += c->measured_h;
        *(s16*)(parent+0x2e) += c->measured_h;
        if (g_mkp->pass_mode == (s8)0xF6) {
            u32 w = c->measured_w + *(u16*)(parent+0x3e);
            if (*(u16*)(parent+0x20) < w) *(s16*)(parent+0x20) = w;
            *(s8*)(parent+0x44) += 1;                      // child count
        }
        if (g_mkp->table_depth != 0) g_mkp->table_depth--;
        if (*(u8*)(parent+0x50) & 1) g_mkp->dirty_18c = 1;
    }

    FUN_005f21f0(&c->obj);                                 // flush cell (base +0x24e0)
    if (g_mkp->table_depth > 1) {                          // snapshot outer-table region
        g_mkp->field_16 = 0;
        g_mkp->reg_d8d6 = *(u16*)(parent+0x28);
        g_mkp->reg_d8d8 = *(u16*)(parent+0x2a);
        g_mkp->reg_d8d2 = 0; g_mkp->reg_d8ce = 0; g_mkp->reg_d8de = 0;
        u16 v = *(u16*)(parent+0x2e);
        g_mkp->reg_d8d4 = v; g_mkp->reg_d8d0 = v;
        g_mkp->reg_d8dc = *(u16*)(parent+0x20);
    }
    return 0;
}
```

## Evidence
- Control flow, offsets, and the depth<2 / depth>=2 split are transcribed line-for-line from the raw
  decompile (`FUN_005eacd0.c`).
- Pass-mode constants `1` and `-10` and the cell-stride arithmetic match sibling records (0x5eb3f0,
  0x5eb0f0, 0x5eb250).
- Runtime-unvalidated; field labels within the parent `obj` (`+0x24/+0x2e/+0x20/+0x3e/+0x44/+0x50`)
  inferred from usage.

## Remaining uncertainty
Exact meaning of parent-node fields (`+0x24` vs `+0x2e` both accumulate height; `+0x1c`/`+0x20` widths)
and the `+0xd8ce..` region snapshot semantics are inferred. `FUN_005f1da0`'s `-10` argument role is not
proven. Whether `+0x1540` is a pixel grid or a cell-rect table is unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eacd0.c`  — untouched decompiler output.
