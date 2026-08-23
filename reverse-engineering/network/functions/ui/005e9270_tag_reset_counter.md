# 0x005e9270 tag_line_break_reset

| field | value |
|---|---|
| Original address | 0x005e9270 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9270 |
| Resolved name | tag_line_break_reset |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (address-taken; dispatched from the markup tag table)
**Callees:** FUN_005e9360 → FUN_005ef3f0 (commit current glyph run / line)
**Referenced globals:** markup-ctx base `iRam007012a0`; field `+4` (output length/count)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+4

## Behavioral explanation
Line-break / flush tag handler. Zeroes the running output-length counter `ctx+4`,
NUL-terminates the current output byte (`*param_2 = 0`), then calls `FUN_005e9360`
(trampoline into `FUN_005ef3f0`, which commits the accumulated glyph run: it builds the
per-glyph arrays at `ctx+0x168`/`ctx+0x128`, resolves color/id fields via `FUN_005ec4f0`,
and issues the draw when the draw-enabled flags `ctx+0x186`/`ctx+0xe96b` are clear).
In other words: terminate the current line, emit it, and reset the accumulation cursor.

## Input / output
- Input: `param_1` (unused here — conventional cursor slot), `param_2` = `u8*` current
  output write pointer (NUL-terminated).
- Output: `undefined8` 0 (consumed).

## Side effects
- `ctx+4 = 0` (output length reset).
- `*param_2 = 0` (terminate current output string).
- Calls the commit/draw pipeline (`FUN_005ef3f0`).

## Important branches
None locally; branching (draw-enabled gates) lives in `FUN_005ef3f0`.

## Constants & flags
- `ctx+4` = 32-bit output-length accumulator (also reset by `emit_segment_and_reset`/`FUN_005eef70`).

## Corrected reconstruction
```c
/* Line-break/flush tag: terminate + commit current run, reset accumulator. */
undefined8 tag_line_break_reset(char **cursor /*unused*/, u8 *out_ptr)
{
    *(u32*)(g_markup_ctx + 4) = 0;   /* output length -> 0 */
    *out_ptr = 0;                    /* NUL-terminate current output */
    commit_run();                    /* FUN_005e9360 -> FUN_005ef3f0 */
    return 0;
}
```

## Evidence
- Raw: `*(u32*)(iRam007012a0 + 4) = 0; *param_2 = 0; FUN_005e9360();`.
- `FUN_005ef3f0` (via 9360) resolves `+0x2a3/+0x193/+0x2b3` ids and draws when
  `+0x186==0 && +0xe96b==0`. Runtime-unvalidated.

## Remaining uncertainty
"Line break" naming inferred from flush+reset+commit shape; the three concrete effects are certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9270.c`  — untouched decompiler output.
