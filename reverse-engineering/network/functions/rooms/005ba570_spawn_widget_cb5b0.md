# 0x005ba570 spawn_room_header_widget

| field | value |
|---|---|
| Original address | 0x005ba570 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ba570 |
| Resolved name | spawn_room_header_widget |
| Subsystem | rooms |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** 16 (FUN_005b3ed0, FUN_005b45f0, FUN_005b47a0, FUN_005f62e0, FUN_005f8340, FUN_005fc850, FUN_00604af0, FUN_00607f70, FUN_00628760, FUN_00629a40, FUN_0062b670, FUN_0062cd20, …)
**Callees:** FUN_00618ba0 (widget_pool_alloc)
**Referenced globals:** widget pool @0x7133f0 (indirect, via callee)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates one display node from the 64-entry widget pool and wires it as a room-header widget:
sets the node's "active" byte, installs `room_header_render_cb` (0x005ba5b0) as its per-frame
callback, and stores the caller's `param_1` as the node's row/kind selector (node[3]). The 16
callers are the various room/lobby screens that each want the header rendered with a different
row index. If the pool is full the allocator returns NULL and nothing is created.

## Input / output
- Input: `u8 param_1` — row/kind selector passed straight into node[3] (indexes the flag table
  0x639dc0 in the callback).
- Output: `void` (allocated node not returned to caller).

## Side effects
- Consumes one widget-pool slot (0x54-byte record @0x7133f0). Writes node[0]=1 (active),
  node[0xc]=&room_header_render_cb, node[3]=param_1.

## Important branches
- `alloc == NULL` (pool exhausted) -> do nothing, return. Otherwise initialize the node.

## Constants & flags
- Node layout (0x54 bytes): +0x00 active flag, +0x03 row selector, +0x0c callback pointer
  (initialized by the pool allocator: +0x2c = -1, +0x34 = -58).

## Corrected reconstruction
```c
typedef struct widget_node widget_node;  // 0x54 bytes, pool @0x7133f0

void spawn_room_header_widget(u8 row_selector) {
    widget_node *n = widget_pool_alloc();          // FUN_00618ba0
    if (n != NULL) {
        n->active     = 1;                          // +0x00
        n->render_cb  = room_header_render_cb;      // +0x0c  (FUN_005ba5b0)
        n->row_sel    = row_selector;               // +0x03
    }
}
```

## Evidence
- `FUN_005ba570.c`: `lVar2=FUN_00618ba0(); if(lVar2!=0){ *p=1; *(code**)(p+0xc)=FUN_005ba5b0; p[3]=param_1; }`
- Pool allocator `FUN_00618ba0.c`: scans 64 slots (stride 0x54 @0x7133f0), first byte==0 → mark 1,
  init +0x34=-58, +0x2c=-1, return slot; returns 0 if all 64 used.
- Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ba570.c`  — untouched decompiler output.

## Remaining uncertainty
Exact meaning of node fields beyond {active, selector, callback} not fully mapped; `param_1` typed
`u8` from the decompiler signature.
