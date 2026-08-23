# 0x001eb9a0 list_drain

| field | value |
|---|---|
| Original address | 0x001eb9a0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb9a0 |
| Resolved name | list_drain_free |
| Subsystem | transport |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (not cross-referenced in this slice)
**Callees:** FUN_001eb434 (list_pop_head), FUN_001ebe28 (buf_free)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** list header +0x00 next, +0x0c count

## Behavioral explanation
Empties a list by repeatedly popping the head and freeing each popped node, until `list_pop_head`
reports the empty sentinel `-0x1b56`. Each node is released via `FUN_001ebe28` (`buf_free`, which
tail-calls the shared free routine `FUN_001e2010`). The loop also aborts early if either `pop_head`
or `buf_free` returns a nonzero code other than the empty sentinel (that error is returned).
On normal completion it returns `0`. Typically the precursor to `list_destroy` (0x001eb918), which
refuses to free a non-empty header.

## Input / output
- `param_1` (`dlist*`): list header to drain.
- returns `0` when fully drained; a propagated nonzero error if pop/free fails mid-drain (the empty
  sentinel `-0x1b56` is normal loop termination, not an error).

## Side effects
- Pops and frees every node (`header->count` reaches 0). No lock taken by this function.

## Important branches
- `list_pop_head` returns `-0x1b56` (empty) -> break, return `0`.
- `list_pop_head` returns `0` -> `buf_free(node)`; its nonzero result becomes the new loop guard and,
  if nonzero, exits the loop returning that value.
- `list_pop_head` returns any other nonzero -> loop guard nonzero -> return it.

## Constants & flags
- `SNAP_ERR_EMPTY = 0xffffe4aa` (`-0x1b56`) — normal termination sentinel.

## Corrected reconstruction
```c
enum { SNAP_ERR_EMPTY = 0xffffe4aa /* -0x1b56 */ };

// Pop and free every node until the list is empty. Unlocked.
// Exact control flow: error is checked at the TOP of the loop and returned there.
int list_drain_free(struct dlist *header) {
    int rc = 0;
    struct dlist_node *node;
    for (;;) {
        if (rc != 0)                         // a pop error from prior iter propagates here
            return rc;
        rc = list_pop_head(header, &node);   // FUN_001eb434
        if (rc == SNAP_ERR_EMPTY)            // -0x1b56 -> normal done
            break;
        if (rc == 0)
            rc = buf_free(node);             // FUN_001ebe28 -> mem_free (always 0)
    }
    return 0;
}
```

## Evidence
- Decompile lines 8-19: `while` with `rc==0` guard; `rc=FUN_001eb434(...)`; `if (rc==-0x1b56) break;`
  `if (rc==0) rc=FUN_001ebe28(node);`. `FUN_001ebe28` = `{ FUN_001e2010(node); return 0; }`.
- The top-of-loop `if (iStack_1c != 0) return iStack_1c;` (lines 10-11) means a nonzero **pop** error
  (other than the `-0x1b56` empty sentinel, which `break`s) is returned on the next iteration. Since
  `buf_free` always yields 0, the normal path terminates via the empty `break` and returns 0.

## Remaining uncertainty
Whether any node in these lists is NOT a `buf_node` (buf_free assumes the buffer free path) — unproven.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb9a0.c`  — untouched decompiler output.
