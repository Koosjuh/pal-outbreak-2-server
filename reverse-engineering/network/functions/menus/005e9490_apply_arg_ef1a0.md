# 0x005e9490 emit_segment_and_reset

| field | value |
|---|---|
| Original address | 0x005e9490 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9490 |
| Resolved name | emit_segment_and_reset |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (address-taken; dispatched from the markup tag table)
**Callees:** FUN_005eef70 (emit accumulated segment); FUN_005ef1a0 (reset per-block defaults)
**Referenced globals:** (via callees) markup-ctx base `iRam007012a0`
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** (via callees) ctx+4, ctx+0x1540[], ctx+0x2e4, ctx+0x4e8/+0x6ec/+0x6ee

## Behavioral explanation
Block/segment boundary tag handler. First calls `FUN_005eef70(param_2)` which, when the
suppress flag `ctx+0xd892==0`, flushes the current text into the segment array at
`ctx+0x1540` (indexed by the segment counter `ctx+0x188`), commits it (`FUN_005eeca0`),
carries the layout cursor forward (`ctx+0xd8bc/0xd8be ← +0xd8c0/0xd8c2`, `FUN_005ec170`),
zeroes the output length `ctx+4`, and NUL-terminates the output byte `*param_2`. Then it
calls `FUN_005ef1a0`, which resets the next block's default state: `memset(ctx+0x2e4, 0,
0x40c)` and restores defaults `ctx+0x4e8=0x100`, `ctx+0x6ec=0x1e`, `ctx+0x6ee=0x1e`.
Net: end the current segment, emit it, and reset for the next.

## Input / output
- Input: `param_1` (unused conventional cursor slot), `param_2` = `u8*` current output
  write pointer (passed to `FUN_005eef70`, NUL-terminated there).
- Output: `undefined8` 0 (consumed).

## Side effects (via callees)
- Emits a segment record into `ctx+0x1540[ctx+0x188]`, advances layout cursor, `ctx+4=0`.
- Resets `ctx+0x2e4[0..0x40c)=0`; `ctx+0x4e8=0x100`, `ctx+0x6ec=0x1e`, `ctx+0x6ee=0x1e`.

## Important branches
- Inside `FUN_005eef70`: `if (ctx+0xd892 == 0)` emit path, else `FUN_005f3ac0()` (suppressed/alt path).

## Constants & flags
- `0x100` (`ctx+0x4e8`), `0x1e`/`0x1e` (`ctx+0x6ec/0x6ee`) = per-block default sizes/limits.
- `0x40c` = size of the block state region at `ctx+0x2e4` (see `tag_read_str_2e4`).

## Corrected reconstruction
```c
/* Segment-boundary tag: emit current segment, then reset next-block defaults. */
undefined8 emit_segment_and_reset(char **cursor /*unused*/, u8 *out_ptr)
{
    emit_current_segment(out_ptr);   /* FUN_005eef70: flush -> ctx+0x1540[ctx+0x188] */
    reset_block_defaults();          /* FUN_005ef1a0: memset ctx+0x2e4, restore defaults */
    return 0;
}
```

## Evidence
- Raw: `FUN_005eef70(param_2); FUN_005ef1a0(); return 0;`.
- `FUN_005eef70` body: segment array `ctx+0x1540` indexed by `ctx+0x188`, cursor carry,
  `ctx+4=0`, `*param_1=0`, gated on `ctx+0xd892`.
- `FUN_005ef1a0` body: `memset(ctx+0x2e4,0,0x40c)`, `ctx+0x4e8=0x100`, `ctx+0x6ec=ctx+0x6ee=0x1e`.
- Runtime-unvalidated.

## Remaining uncertainty
Semantic label of a "segment" (line vs cell vs choice item) inferred from the array-append
shape; the two-step emit-then-reset behavior is certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9490.c`  — untouched decompiler output.
