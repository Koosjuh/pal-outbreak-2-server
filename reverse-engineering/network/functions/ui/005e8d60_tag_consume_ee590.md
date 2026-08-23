# 0x005e8d60 tag_paragraph_reset_attrs

| field | value |
|---|---|
| Original address | 0x005e8d60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8d60 |
| Resolved name | tag_consume_ee590 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup-tag jump table)
**Callees:** FUN_005eef70 (paragraph flush + pen restore), FUN_005ee590 (reset attr state)
**Referenced globals:** (via callees) +0xdf6/+0xdf8 (reset to 0x1e), +0xaf6/+0xbf6/+0xcf6 (cleared), +0xd8bc..+0xd8c2 (pen)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** — (delegated)

## Behavioral explanation
Two-step paragraph-break tag: flush + pen-restore (`FUN_005eef70`), then reset inline attribute state
(`FUN_005ee590`: advance-width/height back to `0x1e`, clear the three attr string buffers). Identical to
`FUN_005e8d30` **minus** the trailing `FUN_005ee610` re-emit — i.e. "break and clear attributes" without
advancing the pen for an empty run.

## Input / output
- `param_1` [inferred `TagCtx*`] — unused.
- `param_2` [inferred `ParseCursor*`] — forwarded to `FUN_005eef70`.
- Returns `0`.

## Side effects
- Line finalize + pen restore (`FUN_005eef70`).
- Attr reset: `+0xdf6 = +0xdf8 = 0x1e`; clear `+0xaf6/+0xbf6/+0xcf6` (`FUN_005ee590`).

## Important branches
- None locally; mode branch inside `FUN_005eef70`.

## Constants & flags
- `0x1e` (30) — default advance-width / line-height.

## Corrected reconstruction
```c
undefined8 tag_paragraph_reset_attrs(TagCtx *tag_ctx, ParseCursor *cur)
{
    text_flush_paragraph(cur);   // FUN_005eef70
    text_reset_attrs();          // FUN_005ee590
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e8d60.c` (40 bytes) — two sequential calls.
- Callee semantics as in `FUN_005e8d30` (which additionally calls `FUN_005ee610`).
- Runtime-unvalidated.

## Remaining uncertainty
- Suggested rename `tag_paragraph_reset_attrs`.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8d60.c`  — untouched decompiler output.
