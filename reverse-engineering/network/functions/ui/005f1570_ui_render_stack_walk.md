# 0x005f1570 ui_render_stack_walk

| field | value |
|---|---|
| Original address | 0x005f1570 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f1570 |
| Resolved name | ui_layout_stack_drain |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e7a30 (layout/render top level)
**Callees:** FUN_005eacd0 (container finish), FUN_005eb3f0 (row finish), FUN_005ebd20 (cell finish)
**Referenced globals:** ctx+0xd892 node-stack depth; ctx+0xd894 current node idx; ctx+0xd89a node-idx stack; node+0x24fb subtype
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0xd892; node+0x24fb

## Behavioral explanation
Terminal drain of the layout node stack. When document build finishes there may still be open
containers/rows/cells; this loop pops the node-index stack from the top (`ctx->nodeDepth`) and, for each
still-open node, dispatches its `subtype` (+0x24fb) to the matching finisher — cell(3/4)→`ebd20`,
row(2)→`eb3f0`, container(1)→`eacd0` — until the stack is empty (`nodeDepth == 0`). It is the
"close everything that's still open" pass, guaranteeing a balanced tree before rendering.

## Input / output
- `param_1`, `param_2` — element/token pair forwarded to each finisher (pass-through).
- Returns `0` when the stack drained cleanly; `0xFFFFFFFF` if any finisher returns negative or a node
  has an unexpected subtype (0 or >4).

## Side effects
- Drives `ctx->nodeDepth` (+0xd892) to 0 indirectly (each finisher pops); rewrites `ctx->curNodeIdx`
  (+0xd894) from the stack array each iteration.
- Calls container/row/cell finishers (which pop and finalize geometry).

## Important branches
- `nodeDepth == 0` → return 0 (done).
- subtype 4 or 3 → `ebd20`; if it returns <0 → return -1.
- subtype 2 → `eb3f0`; <0 → return -1.
- subtype 1 → `eacd0`; loop continues while its return ≥ 0, else falls through to return -1.
- subtype anything else (0, >4) → return -1 (malformed node).

## Constants & flags
- subtype (+0x24fb): 1 container, 2 row, 3/4 cell (shared coding).

## Corrected reconstruction
```c
u32 ui_layout_stack_drain(ctx_t a, ctx_t b) {
    u8* ctx = (u8*)0x007012a0;
    for (;;) {
        if (*(u8*)(ctx+0xd892) == 0) return 0;                       // stack empty
        *(u16*)(ctx+0xd894) = ((u16*)(ctx+0xd89a))[*(u8*)(ctx+0xd892)];
        char sub = node_at(ctx, *(u16*)(ctx+0xd894))->subtype;       // +0x24fb

        if (sub == SUB_CELL || sub == SUB_CELL_CONT) {               // 3/4
            if (ui_cell_finish(a,b) < 0) return -1;                  // ebd20
        } else if (sub == SUB_ROW) {                                 // 2
            if (ui_row_finish(a,b) < 0) return -1;                   // eb3f0
        } else if (sub == SUB_CONTAINER) {                           // 1
            if (ui_container_finish(a,b) < 0) return -1;             // eacd0
        } else {
            return -1;                                               // malformed
        }
    }
}
```

## Evidence
- Raw: `FUN_005f1570.c` (308 bytes). Single caller FUN_005e7a30 (the render entry). Callee triad is the
  three finishers, dispatched purely on +0x24fb — confirms the subtype enumeration used cluster-wide.

## Remaining uncertainty
- None material. Straight balanced-tree flush. High confidence, no runtime trace, no network relevance.
