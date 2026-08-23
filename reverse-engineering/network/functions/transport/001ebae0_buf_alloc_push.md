# 0x001ebae0 buf_alloc_push

| field | value |
|---|---|
| Original address | 0x001ebae0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebae0 |
| Resolved name | buf_alloc_push_tail |
| Subsystem | transport |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ebed0 (subpool init)
**Callees:** FUN_001eba40 (buf_alloc), FUN_001eb3b8 (list_insert_tail)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** list header +0x0c count; buf_node header

## Behavioral explanation
Convenience constructor that allocates a buffer node (`buf_alloc`) and, on success, enqueues it at the
tail of a list (`list_insert_tail`). On OOM it returns the `buf_alloc` error and does not touch the
list. Its caller `FUN_001ebed0` is the sub-pool initializer, so this is the routine that pre-populates
a reliable send/free pool with N fixed-size buffers at setup time.

## Input / output
- `param_1` (`dlist*`): destination list (the pool's free list).
- `param_2` (`buf_node**`): OUT — the newly allocated node.
- `param_3` (`ushort`): buffer capacity.
- `param_4` (`ushort`): buffer `kind`/type tag.
- returns `0` on success; `SNAP_ERR_OOM` (`0xffffe4a9`) if allocation failed (nothing enqueued).

## Side effects
- Allocates a buffer; on success links it at the list tail and increments `list->count`.

## Important branches
- `buf_alloc(...) != 0` (OOM) -> return that error; no enqueue.
- else -> `list_insert_tail(list, *out)`, return its result (`0`).

## Constants & flags
- `SNAP_ERR_OOM = 0xffffe4a9`. (Sizes/kinds are caller-supplied by `subpool_init`.)

## Corrected reconstruction
```c
// Allocate a buffer node and push it onto the tail of `list` (pool preallocation).
int buf_alloc_push_tail(struct dlist *list, struct buf_node **out,
                        uint16_t capacity, uint16_t kind) {
    int rc = buf_alloc(out, capacity, kind);   // FUN_001eba40
    if (rc == 0)
        rc = list_insert_tail(list, *out);     // FUN_001eb3b8
    return rc;
}
```

## Evidence
- Decompile lines 7-11: `iVar1=FUN_001eba40(param_2,param_3,param_4); if (iVar1==0)
  iVar1=FUN_001eb3b8(param_1,*param_2);`.
- Caller FUN_001ebed0 loops this to fill a pool (subpool init).

## Remaining uncertainty
Exact pool count / buffer size chosen by `subpool_init` is out of scope here.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebae0.c`  — untouched decompiler output.
