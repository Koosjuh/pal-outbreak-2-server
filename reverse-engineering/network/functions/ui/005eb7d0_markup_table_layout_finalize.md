# 0x005eb7d0 markup_table_layout_finalize

| field | value |
|---|---|
| Original address | 0x005eb7d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb7d0 |
| Resolved name | markup_cell_layout_finalize |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005eb640, FUN_005eb750, FUN_005f10a0
**Callees:** FUN_005f00b0, FUN_005f0190, FUN_005f0300, FUN_005f0340, FUN_005f0a10, FUN_005efa60, FUN_005ef640, FUN_005ef780
**Referenced globals:** +0xd894 (current cell index); +0x24e0 (cell array, stride 0x5c); +0x186 (pass); +0x18d (dirty flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd894; +0x186

## Behavioral explanation
Finalizes the layout of the current markup cell/box. It fetches the current cell by index
(`*(u16)(ui_ctx+0xd894)`) into the cell array at `ui_ctx+0x24e0` (stride `0x5c` = 92 bytes), and if the
cell holds a live box record it: marks the context dirty (`+0x18d = 1`), runs box-open bookkeeping
(`FUN_005f00b0`), optionally applies the pending string attribute (`FUN_005efa60(+0xf1c)` when
`+0x186 == 0`), then allocates/commits the box via `FUN_005f0a10`. On success it re-fetches the cell,
clears the sub-height accumulator `cell+0x24 (+0x2504)`, and runs three sub-layout passes
(`FUN_005f0190/005f0300/005f0340`). If the cell is a multi-row/table container (`cell+0x2528 != 0`) it
walks the child-cell linked list (via next-index `cell+0x42`, stride `0x5c`) summing each child box's
height plus inter-row spacing into the container height accumulator `cell+0x2520`, then commits with
`FUN_005ef640`. Finally `FUN_005ef780` closes the box. Returns 0 on success, -1 on any missing-cell /
alloc-failure gate.

## Input / output
- No parameters (operates on the current cell selected by `ui_ctx+0xd894`).
- Returns `undefined4`: `0` success; `0xffffffff` (-1) on failure (no cell / `FUN_005f0a10 < 0` /
  cell freed mid-way).

## Side effects
- Sets `ui_ctx+0x18d = 1` (dirty).
- `cell+0x2504 = 0` (reset sub-accumulator); accumulates into `cell+0x2520` (container height).
- Calls box lifecycle helpers `FUN_005f00b0` (open), `FUN_005f0a10` (alloc/commit), `FUN_005ef640`
  (container commit), `FUN_005ef780` (close), `FUN_005efa60` (apply pending string attr).

## Important branches
- **cell box ptr (`cell[0]`) == 0** → return -1 (no live cell).
- **`ui_ctx+0x186 == 0`** → apply pending string attribute `FUN_005efa60(ui_ctx+0xf1c)`.
- **`FUN_005f0a10() < 0`** → return -1 (alloc/commit failed).
- **cell freed after re-fetch (`cell[0] == 0`)** → return -1.
- **`cell+0x2528 != 0`** (container flag) → walk child list `cell+0x42`, accumulate heights into
  `cell+0x2520`, then `FUN_005ef640`.

## Constants & flags
- Cell stride `0x5c`; index = `*(u16)(ui_ctx+0xd894)`; array base `ui_ctx+0x24e0`.
  Decompiler `(idx*0x18 - idx)*4` == `idx*0x17*4` == `idx*0x5c`.
- Cell fields: `+0` box ptr, `+0x24 (0x2504)` sub-accumulator, `+0x30 (0x2510)` border/pad half,
  `+0x32 (0x2512)` spacing, `+0x40 (0x2520)` height accumulator, `+0x48 (0x2528)` container flag,
  `+0x62 (0x2542?)`… `+0x42` next-cell index (in the child link). Box record: `+0x1e` height/width.
  [offsets inferred from arithmetic]
- `+0x186 == 0` — the pass that applies the pending string attribute.

## Corrected reconstruction
```c
#define CELL_STRIDE 0x5c
#define CELL(idx)   ((struct cell*)((char*)ui_ctx + 0x24e0 + (idx) * CELL_STRIDE))

undefined4 markup_cell_layout_finalize(void)
{
    struct cell *c = CELL(ui_ctx->cur_cell);          // idx = *(u16)+0xd894
    if (c->box == 0) return -1;                        // +0x24e0 slot empty

    ui_ctx->dirty = 1;                                 // +0x18d
    box_open(c);                                        // FUN_005f00b0
    if (ui_ctx->pass == 0)                              // +0x186 == 0
        apply_pending_str(&ui_ctx->pending.str_f1c);   // FUN_005efa60(+0xf1c)

    if (commit_box() < 0) return -1;                   // FUN_005f0a10

    c = CELL(ui_ctx->cur_cell);                         // re-fetch (may have moved/freed)
    if (c->box == 0) return -1;

    c->sub_accum = 0;                                   // +0x2504
    sublayout_pass_a(c, c->box);                        // FUN_005f0190
    sublayout_pass_b(c, c->box);                        // FUN_005f0300
    sublayout_pass_c(c, c->box);                        // FUN_005f0340

    if (c->is_container) {                              // +0x2528
        c->height_accum = c->box->extent_1e            // +0x2520 = box+0x1e - 2*border
                        + c->border * -2;              // +0x2510
        struct cell *ch = c;
        while (ch->next_idx != 0) {                     // +0x42 child link
            struct cell *nx = CELL(ch->next_idx);
            ch = /* next cell's slot */ nx;
            c->height_accum += c->spacing + c->border * 2;                     // +0x2512,+0x2510
            c->height_accum += nx->box->extent_1e + c->border * -2;            // child box +0x1e
        }
        commit_container(c);                            // FUN_005ef640
    }
    close_box(c);                                       // FUN_005ef780
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005eb7d0.c` (cell-index stride `0x5c`; child walk
  via `*(u16)((int)piVar5 + 0x42)`; height accumulation into `+0x2520`; gates on `cell[0]==0`,
  `FUN_005f0a10 < 0`, `+0x2528`).
- Cell stride and index math match 0x5eba50 and 0x5ebd20.
- Confidence **Medium** (dense box-model arithmetic; field names inferred). UI markup, not net.

## Remaining uncertainty
Exact cell/box field semantics (border vs padding vs margin at +0x2510/+0x2512); the precise pointer
identity walked in the child loop (`piVar5` reassignment); roles of `FUN_005f0190/0300/0340`.
