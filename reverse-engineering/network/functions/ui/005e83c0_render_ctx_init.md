# 0x005e83c0 render_ctx_init

| field | value |
|---|---|
| Original address | 0x005e83c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e83c0 |
| Resolved name | textmarkup_ctx_reset |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (dispatch-table / setup path; no direct xref in overlay)
**Callees:** func_0x00109eb8 (strcpy-like)
**Referenced globals:** iRam007012a0 (text-markup render ctx base); 0x648500 / 0x648508 (default attribute strings)
**Referenced strings:** the two 16-byte defaults at 0x648500 / 0x648508
**Referenced opcodes:** — (UI text system, not SN@P)
**State vars:** ctx+4 (pending_run_len); ctx+0x1c; ctx+0xd8bc..d8cc (pen/cursor state); ctx+0x2a3 / +0x2b3 (default attr strings)

## Behavioral explanation
Resets the shared text-markup render context to a clean state at the start of a text-layout pass.
It zeroes the pending glyph-run length, the pen/cursor coordinates and their origin
counters (the `+0xd8bc..+0xd8c6` block that every flush routine reads/writes), clears the
`param_2` accumulator byte, and installs two default attribute strings into the context's
two 16-byte string slots (`+0x2a3`, `+0x2b3`) via a `strcpy`-style copy from `0x648500` /
`0x648508`. This is the initializer counterpart to the `tag_*` handlers, all of which mutate
the same `iRam007012a0` block.

## Input / output
- `param_1` (undefined8): caller/render handle — unused here (kept for the uniform handler ABI).
- `param_2` (undefined1*): pending glyph-run accumulator; its first byte is cleared to 0 (empty run).
- returns 0 (undefined8) — conventional success sentinel shared by all tag handlers.

## Side effects
- `ctx+0x04 = 0` — pending run length reset.
- `*param_2 = 0` — accumulator emptied.
- `ctx+0xd8c4 = ctx+0xd8c6 = ctx+0xd8c0 = ctx+0xd8bc = ctx+0xd8c2 = ctx+0xd8be = 0` — pen X/Y, origin X/Y and the two spare counters cleared.
- `ctx+0xd8cc = 0` (byte) — pen/state flag cleared.
- `ctx+0x1c = 0`.
- `strcpy(ctx+0x2a3, 0x648500)`, `strcpy(ctx+0x2b3, 0x648508)` — seed the two default attribute strings.

## Important branches
None — straight-line initializer, no conditionals.

## Constants & flags
- `0x648500`, `0x648508` — pointers to the two default attribute/style strings (16-byte slots at ctx+0x2a3/+0x2b3).
- `func_0x00109eb8` — library `strcpy`/string-copy (dest, src) [inferred from 2-arg copy-into-ctx pattern].

## Corrected reconstruction
```c
// Text-markup render context (subset), base = *(char**)0x007012a0
typedef struct RenderCtx {
    /* +0x04  */ uint32_t pending_run_len;   // glyphs staged before a flush
    /* +0x1c  */ uint32_t field_1c;
    /* +0x2a3 */ char     default_attr_a[16];
    /* +0x2b3 */ char     default_attr_b[16];
    /* +0xd8bc*/ int16_t  pen_x;             // current cursor X
    /* +0xd8be*/ int16_t  pen_y;             // current cursor Y
    /* +0xd8c0*/ int16_t  pen_x_origin;      // line-start X (carriage return target)
    /* +0xd8c2*/ int16_t  pen_y_origin;
    /* +0xd8c4*/ int16_t  spare_c4;
    /* +0xd8c6*/ int16_t  spare_c6;
    /* +0xd8cc*/ uint8_t  pen_flag;
} RenderCtx;
extern RenderCtx *g_txtctx;                  // iRam007012a0

undefined8 textmarkup_ctx_reset(void *render_handle /*unused*/, uint8_t *run_acc)
{
    g_txtctx->pending_run_len = 0;
    *run_acc                  = 0;           // empty pending glyph run
    g_txtctx->spare_c4      = 0;
    g_txtctx->spare_c6      = 0;
    g_txtctx->pen_x_origin  = 0;
    g_txtctx->pen_x         = 0;
    g_txtctx->pen_y_origin  = 0;
    g_txtctx->pen_y         = 0;
    g_txtctx->pen_flag      = 0;
    g_txtctx->field_1c      = 0;
    strcpy(g_txtctx->default_attr_a, (const char *)0x648500);
    strcpy(g_txtctx->default_attr_b, (const char *)0x648508);
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e83c0.c` (10 straight-line stores + 2 copies).
- The `+0xd8bc..+0xd8c6` pen block and `+0x04` run length are exactly the fields read back by the flush routines `FUN_005ef040/005eef70/005ef0e0`, confirming this is their initializer.
- `func_0x00109eb8(dst, src)` used identically as a string copy in `FUN_005e88c0`.
- No net opcode, string, or wire reference. UI-only. Runtime-unvalidated.

## Remaining uncertainty
- Exact semantics of `+0x1c` and the two spare pen counters (`+0xd8c4/+0xc6`) and `+0xd8cc`.
- Whether `0x648500/0x648508` are user-facing strings or attribute descriptors (contents not dumped).
