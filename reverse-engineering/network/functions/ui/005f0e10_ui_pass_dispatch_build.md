# 0x005f0e10 ui_pass_dispatch_build

| field | value |
|---|---|
| Original address | 0x005f0e10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f0e10 |
| Resolved name | ui_node_edge_dispatch |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ea820, FUN_005ea880, FUN_005eb0f0, FUN_005eb1d0, FUN_005eb5a0, FUN_005eb640, FUN_005eb6f0, FUN_005eb750 (the per-tag build entry points)
**Callees:** FUN_005ea900 (push container), FUN_005eacd0 (finish container), FUN_005eb250 (open row), FUN_005eb3f0 (finish row), FUN_005ebd20 (cell), FUN_005ef550/FUN_005ef5b0 (stack setup), FUN_005ef850 (node push)
**Referenced globals:** ctx+0xd892 node-stack depth; ctx+0xd894 current node idx; ctx+0xd89a node-idx stack; node+0x24fb subtype; node+0x252e valid flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0xd892; node+0x24fb

## Behavioral explanation
Auto-close / auto-open dispatcher run as the document tree is built. `param_3` is a **structural edge
class** (1..4) — roughly "what kind of element is about to be inserted next" — and the routine decides
which currently-open container/row/cell must be implicitly closed or opened first so the table grammar
stays well-formed (the classic HTML-table implicit-tag behavior: a `<td>` auto-closes the previous
`<td>`, a new row auto-closes the open row, etc.). It reads the current top-of-stack node's subtype
(`node->subtype`, +0x24fb: 1=container, 2=row, 3/4=cell) and, gated on `node->valid` (+0x252e), calls
the matching open/close helper. When the stack is empty it first pushes a fresh root container
(`ef550` + `ef850(1)` + `ea900`).

## Input / output
- `param_1`, `param_2` — opaque context/token pair forwarded to every handler (the element being
  inserted; passed straight through, 64-bit each in the decompile).
- `param_3` (char) — edge class: 1,2,3,4 (see branches). Values outside 1..4 → no-op.
- Returns `0` normally, `0xFFFFFFFF` if a stack push fails.

## Side effects
- May push a new node (`ef850(1)` container) and initialize it (`ea900`).
- Calls container/row/cell finish/open handlers, which mutate the node tree and stack depth.

## Important branches
- `curNodeIdx == 0` (empty stack) and edge ∈ {2,3,4}: push+init a root container (`ea900`), then read
  its subtype. Edge 1 with `curNodeIdx < 2` (only root present) → return 0 (nothing to close).
- **Edge 3 or 4** (`param_3==3||4`): if subtype==1 → open a row (`eb250`); else if subtype∈{3,4} and
  `valid` → finish the open cell (`ebd20`).
- **Edge 2** (`param_3==2`): if subtype==2 and `valid` → finish row (`eb3f0`); if subtype∈{3,4} and
  `valid` → finish cell then finish row (`ebd20`,`eb3f0`).
- **Edge 1** (`param_3==1`): needs ≥2 on stack; subtype==1 & valid → close container (`eacd0`);
  subtype==2 → finish row then close container (`eb3f0`,`eacd0`).
- Every `ef850(...) < 0` → return -1.

## Constants & flags
- node subtype (+0x24fb): 1 = container/table, 2 = row, 3 = cell, 4 = cell(continuation/split).
- `node->valid` (+0x252e) nonzero = the container currently holds content worth closing.
- `ef850` arg: 1 = container kind (only kind pushed here).

## Corrected reconstruction
```c
// param_3 = structural edge class about to be inserted (implicit open/close driver)
enum UiEdge { EDGE_CLOSE_CTX=1, EDGE_ROW_BOUNDARY=2, EDGE_CELL_A=3, EDGE_CELL_B=4 };
enum NodeSub { SUB_CONTAINER=1, SUB_ROW=2, SUB_CELL=3, SUB_CELL_CONT=4 };

u32 ui_node_edge_dispatch(ctx_t a, ctx_t b, char edge /*param_3*/) {
    u8* ctx = (u8*)0x007012a0;
    *(u16*)(ctx+0xd894) = ((u16*)(ctx+0xd89a))[*(u8*)(ctx+0xd892)];   // current = stack top
    u16 idx = *(u16*)(ctx+0xd894);
    LayoutNode* n = node_at(ctx, idx);

    if (edge == EDGE_CELL_A || edge == EDGE_CELL_B) {
        if (idx == 0) {                                    // empty -> push root container
            ui_stack_reset(); if (ui_node_push(1) < 0) return -1; ui_container_init(a,b);
        }
        char sub = n->subtype;
        if (sub == SUB_CONTAINER)               ui_row_open(a,b);         // eb250
        else if ((sub==SUB_CELL||sub==SUB_CELL_CONT) && n->valid)
                                                ui_cell_finish(a,b);      // ebd20
    }
    else if (edge == EDGE_ROW_BOUNDARY) {
        char sub;
        if (idx == 0) { ui_stack_reset(); if (ui_node_push(1)<0) return -1; ui_container_init(a,b);
                        sub = n->subtype; }
        else { if (idx < 2) return 0; sub = n->subtype; }
        if (sub == SUB_ROW)      { if (n->valid) ui_row_finish(a,b); }    // eb3f0
        else if (sub==SUB_CELL||sub==SUB_CELL_CONT) {
            if (n->valid) ui_cell_finish(a,b);                            // ebd20
            ui_row_finish(a,b);                                           // eb3f0
        }
    }
    else if (edge == EDGE_CLOSE_CTX) {
        if (idx < 2) return 0;
        if (n->subtype == SUB_CONTAINER) { if (n->valid) ui_container_finish(a,b); } // eacd0
        else if (n->subtype == SUB_ROW)  { if (n->valid) ui_row_finish(a,b);        // eb3f0
                                           ui_container_finish(a,b); }               // eacd0
    }
    return 0;
}
```

## Evidence
- Raw: `FUN_005f0e10.c` (648 bytes). 8 tag-specific callers, callee set is exactly the open/finish
  container/row/cell family — an implicit-tag reconciler, not a packet dispatcher.
- Subtype constants 1/2/3/4 and the +0x252e valid gate are shared with FUN_005f10a0 and FUN_005f1570.

## Remaining uncertainty
- The precise meaning of edge classes 1..4 (which source tags map to each) is inferred from the
  open/close pairing, not proven. Medium confidence. No runtime trace; no network relevance.
