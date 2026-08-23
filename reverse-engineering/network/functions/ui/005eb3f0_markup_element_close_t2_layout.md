# 0x005eb3f0 markup_element_close_t2_layout

| field | value |
|---|---|
| Original address | 0x005eb3f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb3f0 |
| Resolved name | markup_row_close_layout |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f0e10, FUN_005f10a0, FUN_005f1570
**Callees:** FUN_005f10a0 (inner close/measure)
**Referenced globals:** g_mkp+0xd892 (table depth); +0xd894 (cell idx); +0xd89a[] (per-depth cell table); +0x186 (pass mode); +0x182 (page width); per-cell +0x24e0 (obj) and geometry fields
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** g_mkp+0xd892, +0xd894, +0x186

## Behavioral explanation
End-of-"type-2" element (a table ROW / block wrapping cells) layout pass. If no table is open
(`+0xd892==0`) it returns 0. Otherwise it runs the inner close `FUN_005f10a0(cursor,out,2)`, reloads the
current cell from `+0xd89a[depth]`, and folds the just-closed row's geometry into its parent render
object (`cell->obj`): it adds the row's border + measured height into the parent's running height
(`obj+0x2e`), mirrors that to `obj+0x24`, computes a content width floor (`cell+0x2500 - cell+0x2512`)
and raises `cell+0x24fc`, then raises the parent min-width `obj+0x1c` from
`measured_w + 2*border_b + 2*border`. In measure pass it also raises the page width `+0x182`. Finally it
decrements the table depth. Unlike the cell finalizer (0x5eacd0) it does NOT commit to the document flow
or touch the grid — it only rolls the row up into its parent. UI markup only.

## Input / output
- `param_1` — `char **cursor`; `param_2` — `char *out` (reset to empty).
- Return `u32`: `0` success/no-op; `0xFFFFFFFF` on inner-close failure or missing parent object.

## Side effects
- `FUN_005f10a0` closes/measures inner content.
- `+0xd894 = +0xd89a[depth]`; `cell+0x252e = 0`; `g_mkp+4 = 0`; `out[0] = 0`.
- Parent obj: `obj+0x2e += cell+0x2512 + cell+0x24fe`; `obj+0x24 = obj+0x2e`; `obj+0x1c = max(..)`.
- `cell+0x24fc = max(cell+0x24fc, cell+0x2500 - cell+0x2512)`.
- Measure pass: `+0x182 = max(+0x182, cell+0x2508 + cell+0x24fc)`.
- Decrements `+0xd892`.

## Important branches
- `+0xd892 == 0` -> return 0.
- `FUN_005f10a0(...) < 0` -> return -1.
- `cell->obj (+0x24e0) == 0` -> return -1.
- `cell+0x2500 - cell+0x2512 > cell+0x24fc` -> raise `cell+0x24fc`.
- computed `w > obj+0x1c` -> raise `obj+0x1c` (min content width).
- `+0x186 == 0xF6` (measure) -> raise page width `+0x182`.

## Constants & flags
- `PASS_MEASURE 0xF6`. Cell stride 92, base `+0x24e0`.
- Width floor formula uses `2*border_b (+0x2525)` and `2*border (+0x2512)`.

## Corrected reconstruction
```c
u32 markup_row_close_layout(char **cursor, char *out) {
    if (g_mkp->table_depth == 0) return 0;                        // +0xd892
    if (FUN_005f10a0(cursor, out, 2) < 0) return (u32)-1;

    g_mkp->cur_cell = g_mkp->cell_index_by_depth[g_mkp->table_depth]; // +0xd894=+0xd89a[depth]
    MkpCell *c   = MKP_CELL(g_mkp->cur_cell);
    void   *obj  = c->obj;                                        // +0x24e0
    if (obj == 0) return (u32)-1;

    c->flag_252e = 0;  g_mkp->emit_len = 0;  *out = 0;

    *(s16*)(obj+0x2e) += c->border_u16 /*+0x2512*/ + c->measured_h /*+0x24fe*/;
    *(u16*)(obj+0x24)  = *(u16*)(obj+0x2e);

    s32 floor = (u16)c->w_2500 - (u16)c->border_u16;              // +0x2500 - +0x2512
    if ((s32)(u16)c->measured_w < floor) c->measured_w = (u16)floor; // +0x24fc

    u32 w = (u16)c->measured_w + (u8)c->border_b*2 /*+0x2525*/ + (u16)c->border_u16*2;
    if (*(u16*)(obj+0x1c) < w) *(s16*)(obj+0x1c) = (s16)w;

    if (g_mkp->pass_mode == (s8)0xF6) {                           // measure
        u32 pw = (u16)c->x /*+0x2508*/ + (u16)c->measured_w;
        if (g_mkp->page_w < pw) g_mkp->page_w = (s16)pw;          // +0x182
    }
    if (g_mkp->table_depth != 0) g_mkp->table_depth--;
    return 0;
}
```

## Evidence
- Control flow and every offset transcribed from `FUN_005eb3f0.c`.
- Cell-stride math, `+0xd89a[depth]` reload, and `PASS_MEASURE 0xF6` match 0x5eacd0.
- Runtime-unvalidated; parent-object field labels inferred from accumulation pattern.

## Remaining uncertainty
Semantic split between `obj+0x24` and `obj+0x2e` (both track height) and the exact meaning of
`cell+0x2500`/`+0x2512`/`+0x2525` (content width / cell border / cell padding) is inferred. Whether
"type-2" is precisely a table row vs a generic block wrapper is unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eb3f0.c`  — untouched decompiler output.
