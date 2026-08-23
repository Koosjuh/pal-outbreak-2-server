# 0x001eb5ac list_insert_locked

| field | value |
|---|---|
| Original address | 0x001eb5ac |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb5ac |
| Resolved name | list_insert_after_locked |
| Subsystem | transport |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5ae4
**Callees:** FUN_001ebe64 (lock_invoke)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** list header +0x0c count; +0x08 lock callback

## Behavioral explanation
Inserts a new node **after** a given anchor node in a circular doubly-linked list, under the list
lock, and increments the count. Acquires via `lock_invoke(list,1)`; on success splices `new` between
`anchor` and `anchor->next`, then releases via `lock_invoke(list,2)`. Because the header is the
sentinel, passing the header as the anchor inserts at the head — this is the ordered/positional
counterpart to the tail-only `list_insert_tail`. Its sole caller `FUN_001d5ae4` (reliable reorder
path) uses it together with `list_find_pred`/`ptr_equal` to insert a reordered segment at the correct
position in the pending list.

## Input / output
- `param_1` (`int = dlist*`): list header (lock + count).
- `param_2` (`int* = dlist_node*`): anchor node; `new` is inserted immediately after it.
- `param_3` (`int* = dlist_node*`): the new node to link.
- returns `0` on success, else the lock-acquire error (insert skipped).

## Side effects
- On success: `new->next = anchor->next`, `new->prev = anchor`, `anchor->next = new`,
  `new->next->prev = new`, `header->count++`.
- Acquires then releases the list lock.

## Important branches
- `lock_invoke(list,1) != 0` -> return error, no insert.
- else -> splice-after-anchor, `count++`, return `lock_invoke(list,2)`.

## Constants & flags
- Lock ops `1`/`2` (acquire/release). Node links `+0x00 next`, `+0x04 prev`; count `+0x0c`.

## Corrected reconstruction
```c
// Insert `node` immediately after `anchor` in a circular dlist, under the list lock; count++.
int list_insert_after_locked(struct dlist *header,
                             struct dlist_node *anchor,
                             struct dlist_node *node) {
    int rc = lock_invoke(header, LOCK_ACQUIRE /*1*/);
    if (rc == 0) {
        node->next        = anchor->next;   // *param_3     = *param_2
        node->prev        = anchor;         // param_3[1]   = param_2
        anchor->next      = node;           // *param_2     = param_3
        node->next->prev  = node;           // (*param_3)->prev = param_3
        header->count++;                    // +0x0c
        rc = lock_invoke(header, LOCK_RELEASE /*2*/);
    }
    return rc;
}
```

## Evidence
- Decompile lines 8-13: `*param_3=*param_2; param_3[1]=param_2; *param_2=param_3;
  *(*param_3+4)=param_3; count++` inside the `lock==0` guard, then `lock_invoke(...,2)`.
- Locked, positional variant of `list_insert_tail` (0x001eb3b8).

## Remaining uncertainty
Anchor is treated as a plain node; caller must guarantee it belongs to this list (unchecked).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb5ac.c`  — untouched decompiler output.
