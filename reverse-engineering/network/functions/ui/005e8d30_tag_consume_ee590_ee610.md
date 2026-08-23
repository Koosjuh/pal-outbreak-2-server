# 0x005e8d30 tag_paragraph_reset_and_emit

| field | value |
|---|---|
| Original address | 0x005e8d30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8d30 |
| Resolved name | tag_consume_ee590_ee610 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup-tag jump table)
**Callees:** FUN_005eef70 (paragraph flush + pen restore), FUN_005ee590 (reset attr state), FUN_005ee610 (emit/advance current run)
**Referenced globals:** (via callees) +0xdf6/+0xdf8 (advance-w/height, reset to 0x1e), +0xaf6/+0xbf6/+0xcf6 (attr string buffers, cleared), +0x10/+0x12/+0x182/+0x186/+0x188 (layout), +0xd8bc..+0xd8cc (pen)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** — (delegated)

## Behavioral explanation
Composite paragraph-break tag performing three steps in order:
1. `FUN_005eef70` — flush the current line and restore the pen to the saved paragraph origin.
2. `FUN_005ee590` — reset the per-run attribute state: advance-width `+0xdf6` and line-height `+0xdf8`
   back to default `0x1e` (30), and zero the three 256-byte string attribute buffers
   `+0xaf6/+0xbf6/+0xcf6`.
3. `FUN_005ee610` — emit/advance the pen for the (now empty) run, updating the layout bounding box.

This is the "hard paragraph reset": break, clear all inline attributes to defaults, and re-baseline the
layout cursor. Contrast `FUN_005e8d60`, which does steps 1–2 only (no re-emit).

## Input / output
- `param_1` [inferred `TagCtx*`] — unused.
- `param_2` [inferred `ParseCursor*`] — forwarded to `FUN_005eef70`.
- Returns `0`.

## Side effects
- Line finalize + pen restore (`FUN_005eef70`).
- Attr reset: `+0xdf6 = +0xdf8 = 0x1e`; `memset(+0xaf6/+0xbf6/+0xcf6, 0, 0x100)` (`FUN_005ee590`).
- Pen advance + bbox update: writes `+0xd8c0/+0xd8bc` (pen), `+0xd8cc = 1`, may grow `+0x182`
  (max-width tracker) (`FUN_005ee610`).

## Important branches
- None locally; mode branches (`+0xd892`) are inside the callees (`FUN_005eef70`→`FUN_005f3ac0`,
  `FUN_005ee610`→`FUN_005f2e50`).

## Constants & flags
- `0x1e` (30) — default advance-width / line-height reset value (set by `FUN_005ee590`).

## Corrected reconstruction
```c
undefined8 tag_paragraph_reset_and_emit(TagCtx *tag_ctx, ParseCursor *cur)
{
    text_flush_paragraph(cur);   // FUN_005eef70: finalize + restore pen
    text_reset_attrs();          // FUN_005ee590: +0xdf6/+0xdf8 = 0x1e; clear str buffers
    text_emit_run();             // FUN_005ee610: advance pen, update bbox
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e8d30.c` (48 bytes) — three sequential calls.
- `FUN_005ee590.c`: sets `+0xdf6/+0xdf8 = 0x1e`, memsets the three buffers.
- `FUN_005ee610.c`: word-wrap/advance emitter (reads `+0x10` max width, `+0xdf6` advance, wraps via
  `FUN_005ed460`, updates `+0x182` and pen `+0xd8bc/+0xd8c0`).
- Runtime-unvalidated.

## Remaining uncertainty
- Suggested rename `tag_paragraph_reset_and_emit`.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8d30.c`  — untouched decompiler output.
