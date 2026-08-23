# 0x005ee840 flush_text_run_with_rule

| field | value |
|---|---|
| Original address | 0x005ee840 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ee840 |
| Resolved name | flush_text_run_and_wrap |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005eea60
**Callees:** FUN_005ec170, FUN_005ed0c0, FUN_005ed1a0, FUN_005ed430
**Referenced globals:** iRam007012a0; +0x1c (glyph-buffer length), +0x20 (glyph output buffer); +0xd8bc (run start x), +0xd8c0 (run end x), +0xd8c8 (run width); +0x186 (pass)
**State vars:** +0x186

## Behavioral explanation
Mid-line flush used by the word-wrap loop (layout_text_run) when the pending word would overflow the line: it commits the accumulated glyph run and starts a new line. Steps: (1) on the measure pass, store the run's end x into the caller-provided line record `*param_1`; (2) record run width `+0xd8c8 = run_end(+0xd8c0) - run_start(+0xd8bc)`; (3) NUL-terminate the glyph buffer; (4) draw the run (FUN_005ed0c0); (5) reset the glyph-buffer length +0x1c to 0; (6) commit line metrics + advance to the next line via FUN_005ed430/FUN_005ed1a0/FUN_005ec170 (line-break bookkeeping).

## Input / output
- `param_1` (ptr to `{ short* line_ptr; ... }`) — `*(u32*)param_1` points at the current line record; `*line_ptr` receives the run end x on the measure pass.
- Returns void.

## Side effects
- Measure pass (`+0x186==1`): `**(u16**)param_1 = ctx->run_end (+0xd8c0)`.
- `ctx->run_width (+0xd8c8) = ctx->run_end - ctx->run_start`.
- Glyph buffer `ctx->glyphs[ctx->glyph_len] = 0` (NUL-terminate); then `ctx->glyph_len (+0x1c) = 0`.
- Draw/commit: FUN_005ed0c0(line_ptr) draws the run; FUN_005ed430(&ctx->run_start, param_1) + FUN_005ed1a0(param_1) + FUN_005ec170(&ctx->run_start) perform the newline advance (reset run_start, bump line index/y).

## Important branches
- `if (ctx->pass +0x186 == 1)` → write run end x back to the line record; otherwise skip (draw pass draws directly).

## Constants & flags
- `+0x1c` glyph-buffer write length; `+0x20` glyph buffer base; NUL terminator at `[len]`.
- `+0xd8bc/+0xd8c0/+0xd8c8` = run start / end / width x-coordinates.

## Corrected reconstruction
```c
// param_1 -> { short *line_ptr; ... } : the current line-metric slot
void flush_text_run_and_wrap(RunCtx *rc)
{
    HtmlCtx *ctx = (HtmlCtx*)iRam007012a0;

    if (ctx->pass == PASS_MEASURE)                     // +0x186==1
        *rc->line_ptr = ctx->run_end;                  // record run end x (+0xd8c0)

    ctx->run_width /*+0xd8c8*/ = ctx->run_end /*+0xd8c0*/ - ctx->run_start /*+0xd8bc*/;
    ctx->glyphs[ctx->glyph_len] = 0;                   // +0x20[+0x1c] NUL-terminate
    FUN_005ed0c0(rc->line_ptr);                        // draw the run
    ctx->glyph_len /*+0x1c*/ = 0;

    FUN_005ed430(&ctx->run_start, rc);                 // commit line metrics
    FUN_005ed1a0(rc);                                  // advance line index / y
    FUN_005ec170(&ctx->run_start);                     // reset run start x
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005ee840.c`. Measure-pass writeback line 9–11 (`+0x186==1`, `*(*(u32*)param_1) = *(0xd8c0)`). run_width `+0xd8c8 = +0xd8c0 - +0xd8bc` lines 12–13. NUL at `[+0x1c]` line 14; FUN_005ed0c0 draw line 15; `+0x1c=0` line 16; the three commit/advance calls lines 17–19.
- Same buffer (+0x1c/+0x20) and run cursors as the emit helpers (FUN_005ee920/9a0/9f0) and flush_text_buffer (FUN_005eeca0). Shares FUN_005ed0c0 with flush_text_buffer and FUN_005ed430/FUN_005ed1a0 with finalize_run_metrics.

## Remaining uncertainty
- Exact split of work among FUN_005ed430 (commit metrics) / FUN_005ed1a0 (line advance) / FUN_005ec170 (cursor reset) is inferred from names/usage, not traced. Renamed from "…with_rule" to "…and_wrap": the FUN_005ed0c0 call draws the run (same as flush_text_buffer), no separate rule primitive is invoked here. Not runtime-validated → Medium.
```
