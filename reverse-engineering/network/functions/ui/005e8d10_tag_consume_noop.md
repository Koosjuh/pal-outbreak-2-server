# 0x005e8d10 tag_paragraph_flush

| field | value |
|---|---|
| Original address | 0x005e8d10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8d10 |
| Resolved name | tag_consume_noop |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup-tag jump table)
**Callees:** FUN_005eef70 (paragraph flush + pen restore)
**Referenced globals:** (via callee) TRC `iRam007012a0`: +0xd8bc/+0xd8be (pen), +0xd8c0/+0xd8c2 (saved pen)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** — (delegated)

## Behavioral explanation
Thin wrapper markup tag: its whole body is a tail call to `FUN_005eef70`, the **paragraph flush**. Not
a true no-op — `FUN_005eef70` finalizes the current line, then *restores the pen* by copying the saved
origin `+0xd8c0/+0xd8c2` back into the live pen `+0xd8bc/+0xd8be` and resets the pending-run field
`+0x04` and `*param_2`. This is the "carriage return to the saved left margin / paragraph origin" tag.

## Input / output
- `param_1` [inferred `TagCtx*`] — tag context (unused).
- `param_2` [inferred `ParseCursor*`] — parse cursor, forwarded to `FUN_005eef70`.
- Returns `0`.

## Side effects
- All via `FUN_005eef70`: line finalize; `+0xd8bc = +0xd8c0`, `+0xd8be = +0xd8c2` (pen restore);
  `+0x04 = 0`; `*param_2 = 0`. Alt-mode delegates to `FUN_005f3ac0`.

## Important branches
- None in this function; the mode branch (`+0xd892`) lives inside `FUN_005eef70`.

## Constants & flags
- None.

## Corrected reconstruction
```c
undefined8 tag_paragraph_flush(TagCtx *tag_ctx, ParseCursor *cur)
{
    text_flush_paragraph(cur);   // FUN_005eef70: finalize line + restore pen to saved origin
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e8d10.c` (32 bytes) — single call to `FUN_005eef70`.
- `FUN_005eef70.c`: copies `+0xd8c0/+0xd8c2` → `+0xd8bc/+0xd8be` and clears `+0x04`, `*param_1`.
- Runtime-unvalidated.

## Remaining uncertainty
- Suggested rename `tag_paragraph_flush` (not "noop"): the callee does perform a pen-restore flush.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8d10.c`  — untouched decompiler output.
