# 0x001ebda4 node_get_field4_dup

| field | value |
|---|---|
| Original address | 0x001ebda4 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebda4 |
| Resolved name | buf_get_prev_dup |
| Subsystem | transport |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (typed twin of 0x001ebd2c)
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x4 backward link (prev)

## Behavioral explanation
Returns the word at node `+0x4` (the `prev` backward link) — byte-identical to `buf_get_prev`
(0x001ebd2c). As with the `next` pair (0x001ebd54 / 0x001ebd7c), the duplicate exists because the
same accessor was instantiated against two node types in source.

## Input / output
- `param_1` (`int` → `struct snap_buf *`): node header.
- Returns `void*` (`struct snap_buf *`): `prev` link at `+0x4`.

## Side effects
- None (pure read).

## Important branches
- None.

## Constants & flags
- None.

## Corrected reconstruction
```c
// identical machine code to buf_get_prev (0x001ebd2c)
struct snap_buf *buf_get_prev_dup(struct snap_buf *node) {
    return node->prev;   // +0x4
}
```

## Evidence
- Raw: `FUN_001ebda4.c` — `return *(u32*)(p+4)`; identical to 0x001ebd2c.
- Confidence **High**; runtime validation pending.

## Remaining uncertainty
- Source-level type distinction not recoverable from the binary; next/prev orientation by convention.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebda4.c`  — untouched decompiler output.
