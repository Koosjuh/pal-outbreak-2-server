# 0x001ebd2c buf_get_field4

| field | value |
|---|---|
| Original address | 0x001ebd2c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebd2c |
| Resolved name | buf_get_prev |
| Subsystem | transport |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (indirect / typed-accessor; see dup at 0x001ebda4)
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x4 backward link (prev)

## Behavioral explanation
Returns the word at buffer `+0x4`, which is the backward (`prev`) link of the intrusive
doubly-linked list node. The 0x10-byte header is `{next@+0, prev@+4, capacity@+8, id@+0xa,
len@+0xc, flags@+0xe}`; `buf_get_next` (0x001ebd54) reads `+0`, this reads `+4`. Byte-identical
sibling `node_get_field4_dup` (0x001ebda4) is the same accessor emitted under a different type.

## Input / output
- `param_1` (`int` → `struct snap_buf *`): node header.
- Returns `void*` (`struct snap_buf *`): the `prev` link at `+0x4`.

## Side effects
- None (pure read).

## Important branches
- None.

## Constants & flags
- None.

## Corrected reconstruction
```c
struct snap_buf *buf_get_prev(struct snap_buf *buf) {
    return buf->prev;   // +0x4 : backward list link
}
```

## Evidence
- Raw: `FUN_001ebd2c.c` — `return *(u32*)(p+4)`.
- Pairs with `buf_get_next` (+0) → confirms an intrusive doubly-linked node layout.
- Confidence **High**; runtime validation pending.

## Remaining uncertainty
- "prev" vs "next" orientation of the two links is inferred from convention (next=+0, prev=+4);
  not runtime-confirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebd2c.c`  — untouched decompiler output.
