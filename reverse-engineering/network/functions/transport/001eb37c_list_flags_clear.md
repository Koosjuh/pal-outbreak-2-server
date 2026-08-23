# 0x001eb37c buf_flags_clear

| field | value |
|---|---|
| Original address | 0x001eb37c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb37c |
| Resolved name | buf_flags_clear |
| Subsystem | transport |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ec9e0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xe buffer/node flags word

## Behavioral explanation
Atomically-in-single-instruction AND-NOT of `param_2` into the 16-bit flags word at `node+0x0e`,
i.e. clears the given mask bits and returns the resulting flags. This is the buffer-node twin of
`buf_flags_set` (0x001ebbd0) and `buf_flags_test` (0x001ebb90); all three operate on the same `+0x0e`
word carried by every `buf_node` produced by `buf_alloc` (0x001eba40, which zeroes `+0x0e` at birth).
The one caller `FUN_001ec9e0` is in the reliable sub-pool family, so this clears per-buffer send/latch
state bits (e.g. a "queued"/"watermark" latch) when a buffer is recycled/freed back to the pool.

## Input / output
- `param_1` (`int`): pointer to a `buf_node` (or any object carrying a flags word at `+0x0e`).
- `param_2` (`ushort`): bit mask to clear.
- returns (`u16`): the new value of `node->flags` after clearing.

## Side effects
- Writes `*(u16*)(node + 0x0e)` (clears `param_2` bits). No allocation, no list mutation, no lock.

## Important branches
None — straight-line read-modify-write.

## Constants & flags
- `+0x0e` = `buf_node.flags`. Individual bit meanings are not fixed by this function; the reliable
  transport bit `0x8000` and who-byte bits `0x1000/0x2000` are wire-header bits and are NOT proven to
  be this internal word — treat specific bit values as [inferred] until a caller pins them.

## Corrected reconstruction
```c
// Clear mask bits in a buffer node's flags word; return the new flags.
uint16_t buf_flags_clear(struct buf_node *node, uint16_t mask) {
    node->flags &= (uint16_t)~mask;   // +0x0e
    return node->flags;
}
```

## Evidence
- Decompile: `node->flags = node->flags & ~mask; return node->flags;` (FUN_001eb37c.c lines 5-6).
- Symmetric with 0x001ebbd0 (set) / 0x001ebb90 (test) on the same `+0x0e` word; `buf_alloc` zeroes
  `+0x0e`. Sole caller in the sub-pool subsystem (FUN_001ec9e0).
- Runtime-unvalidated; bit semantics inferred.

## Remaining uncertainty
Which specific bits `FUN_001ec9e0` clears (pool-recycle latch vs send-pending) is not pinned here.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb37c.c`  — untouched decompiler output.
