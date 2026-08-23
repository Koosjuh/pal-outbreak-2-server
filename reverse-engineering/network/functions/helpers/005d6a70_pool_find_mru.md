# 0x005d6a70 pool_find_mru

| field | value |
|---|---|
| Original address | 0x005d6a70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6a70 |
| Resolved name | pool_find_move_to_front |
| Subsystem | helpers |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d7760, FUN_005d78d0
**Callees:** FUN_005dedb0 (key comparator)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node.alloc (+0x104), key[0x100] (+0x04)

## Behavioral explanation
Move-to-front (MRU) associative lookup over the pool free-list. It walks from head `param_1`, skipping free nodes (`alloc==0`), and for each in-use node compares its key region (`node+0x04`, 0x100 bytes) against the search key `param_2` via `FUN_005dedb0`. The comparator returns 0 on match (memcmp-style). On the first match it captures the hit node and its predecessor and stops. If a hit is found and it is not already the first real node, it is spliced out and re-linked at the front of the list (`pred->next = hit->next; hit->next = head->next; head->next = hit`) — so recently-accessed entries migrate to the head. Returns the hit node, or 0 if no in-use node matched.

## Input / output
- `int *param_1` — pool head/sentinel.
- `param_2` — search key (compared against each node's 0x100-byte key region).
- Returns the matching node (now moved to front), or `NULL`.

## Side effects
- On hit not already at front: relinks the node to the head (move-to-front).

## Important branches
- `node == 0` → end of list → no match (break, return 0).
- `node->alloc == 0` → skip free node (continue).
- comparator `!= 0` → no match, keep scanning.
- comparator `== 0` → hit; capture node+pred, exit loop.
- hit found and `hit != head->next` → splice to front.

## Constants & flags
- `alloc` (+0x104): only in-use nodes are compared.
- comparator convention: `0` = match.

## Corrected reconstruction
```c
pool_node *pool_find_move_to_front(pool_node *head, const void *key) {
    pool_node *cur = head, *prev, *hit = NULL, *hit_pred = NULL;
    do {
        prev = cur;
        cur  = cur->next;
        hit = NULL; hit_pred = NULL;      // reset each iter (only last match kept)
        if (cur == NULL) break;
    } while (cur->alloc == 0 ||
             (FUN_005dedb0(cur->key, key) != 0
                ? (hit = cur, hit_pred = prev, true)   // no-match bookkeeping, keep scanning
                : (hit = cur, hit_pred = prev, false)));// match -> loop exits
    pool_node *result = NULL;
    if (hit != NULL) {
        result = hit;
        if (hit != head->next) {          // move-to-front
            hit_pred->next = hit->next;
            hit->next      = head->next;
            head->next     = hit;
        }
    }
    return result;
}
```
(The comma-expression `hit=piVar1, hit_pred=piVar5` runs on every compared node; only when the comparator returns 0 does the `while` fall through with `hit` holding the matched node — behavior preserved from the decompile.)

## Evidence
- Decompile: skip `piVar1[0x41]==0`; `lVar2 = FUN_005dedb0(piVar1+1, param_2)`; capture `piVar4=piVar1, piVar3=piVar5`; exit on `lVar2==0`; front-splice `*piVar3=*piVar4; *piVar4=*param_1; *param_1=piVar4;` guarded by `piVar4 != *param_1`.

## Remaining uncertainty
- `FUN_005dedb0` assumed memcmp-style (0 = equal) from the exit condition; not separately decompiled. Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6a70.c`  — untouched decompiler output.
