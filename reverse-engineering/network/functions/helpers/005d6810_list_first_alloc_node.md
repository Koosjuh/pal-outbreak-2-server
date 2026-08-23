# 0x005d6810 list_first_alloc_node

| field | value |
|---|---|
| Original address | 0x005d6810 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6810 |
| Resolved name | list_advance_if_next_inuse |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d6920, FUN_005d71e0, FUN_005d72d0, FUN_005d8840
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node.alloc (+0x104)

## Behavioral explanation
A single-step cursor advance gated on the successor's allocation state. Given a cursor node `param_2`, it looks at `param_2->next`: if the next node exists **and is in-use** (`alloc != 0`) it returns that next node (advance); if the next exists but is **free** (`alloc == 0`) it returns `param_2` (stay — do not advance onto a free node); if there is no next it returns `param_2`. Net rule: "advance one slot only while the following slot is still occupied," which keeps a cursor pinned at the boundary between the in-use prefix and the free tail of the ring. `param_1` is unused. The prior name `list_first_alloc_node` mis-described it; the operation is a conditional advance, hence the rename suggestion `list_advance_if_next_inuse`.

## Input / output
- `param_1` — unused.
- `int *param_2` — current cursor node.
- Returns `param_2->next` if next is in-use, else `param_2`.

## Side effects
None (pure).

## Important branches
- `next == 0` → return `param_2`.
- `next->alloc == 0` (free) → return `param_2` (do not step onto free node).
- `next->alloc != 0` (in-use) → return `next`.

## Constants & flags
- `alloc` (+0x104): 0 = free, nonzero = in-use.

## Corrected reconstruction
```c
// Advance the cursor by one iff the next node is still allocated; otherwise
// hold position (used to keep a cursor at the in-use / free boundary).
pool_node *list_advance_if_next_inuse(pool_node *unused, pool_node *cur) {
    pool_node *nxt = cur->next;
    pool_node *result = cur;
    if (nxt != NULL && nxt->alloc == 0)   // next is free -> stay
        result = cur;
    else if (nxt != NULL)                 // next in-use -> advance
        result = nxt;
    return result;
}
```

## Evidence
- Decompile: `piVar1=*param_2; piVar2=param_2; if(piVar1!=0 && (piVar2=piVar1, piVar1[0x41]==0)) piVar2=param_2; return piVar2;`.

## Remaining uncertainty
- Name changed from `list_first_alloc_node` → `list_advance_if_next_inuse`; original name left in the metadata table per record convention. Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6810.c`  — untouched decompiler output.
