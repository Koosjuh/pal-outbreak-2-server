# 0x005e9510 tag_read_str_2e4

| field | value |
|---|---|
| Original address | 0x005e9510 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9510 |
| Resolved name | tag_read_str_2e4 |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (address-taken; dispatched from the markup tag table)
**Callees:** FUN_005ec1b0 (attribute-value extractor)
**Referenced globals:** markup-ctx base `iRam007012a0`; field `+0x2e4` (0x100-byte string, head of a 0x40c block)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x2e4

## Behavioral explanation
Markup attribute handler. Extracts the tag value into the 256-byte string `ctx+0x2e4`
via `FUN_005ec1b0`. `ctx+0x2e4` is the head of the per-block state region (the whole
0x40c-byte span `+0x2e4..+0x6f0` is `memset` to 0 by `FUN_005ef1a0` at each block reset,
which also restores `+0x4e8=0x100`, `+0x6ec/+0x6ee=0x1e`). So `+0x2e4` holds a block-level
string attribute (e.g. the block's text/name/target), captured before the block is emitted
by `emit_segment_and_reset`.

## Input / output
- Input: `param_1` = `char**` parser cursor pointer.
- Output: `undefined8` 0 (consumed).

## Side effects
- Writes up to 256 bytes (incl NUL) to `ctx+0x2e4`; advances `*param_1`.

## Important branches
None here (inside `FUN_005ec1b0`).

## Constants & flags
- `0x100` = destination capacity; `+0x2e4` is the first field of the 0x40c block-state region.

## Corrected reconstruction
```c
/* +0x2e4 : 256-byte block-level string; head of the 0x40c block-state region
   cleared by FUN_005ef1a0 (reset_block_defaults). */
undefined8 tag_read_str_2e4(char **cursor)
{
    parse_attr_value(cursor, (u8*)g_markup_ctx + 0x2e4, 0x100);  /* FUN_005ec1b0 */
    return 0;
}
```

## Evidence
- Raw: `FUN_005ec1b0(param_1, iRam007012a0 + 0x2e4, 0x100)`.
- Region evidence: `FUN_005ef1a0` `memset(base+0x2e4, 0, 0x40c)` then sets defaults at
  `+0x4e8/+0x6ec/+0x6ee` — placing `+0x2e4` at the head of the block-state block.
  Runtime-unvalidated.

## Remaining uncertainty
Exact block-string role (text vs name vs target) unknown (no dedicated reader in the read
set); copy mechanic and block-region membership are certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9510.c`  — untouched decompiler output.
