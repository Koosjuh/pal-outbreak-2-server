# 0x005ef0e0 render_text_token_flush_if_pending

| field | value |
|---|---|
| Original address | 0x005ef0e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ef0e0 |
| Resolved name | render_text_token_flush_if_pending |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e8750, FUN_005e8810, FUN_005e8990, FUN_005e89f0, FUN_005e8ad0, FUN_005e8b40, FUN_005e8ca0, FUN_005e9380, FUN_005e9a90, FUN_005e9ae0, FUN_005e9b20, FUN_005ea820, FUN_005ea880, FUN_005ebd20
**Callees:** FUN_005eea60 (layout_text_run), FUN_005eeca0 (emit_text_run), FUN_005eed40 (finalize_run_metrics), FUN_005ec170 (commit_cursor), FUN_005f3cc0 (block-stack variant)
**Referenced globals:** iRam007012a0; +0xd892 depth; +0x188 root idx; +0x1540 root array; +0xd8bc cursor x; +0x4 buffer length
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd892 depth; +0xd8bc cursor

## Behavioral explanation
Third variant of the text-token flush. Same top-level path as `render_text_token_inline` except the
metric-finalize call (`0x005eed40`) is **conditional on a nonzero cursor-x** (`ctx+0xd8bc != 0`) —
i.e. it only advances/closes the run if there is an unflushed run pending on the current line; an
empty line skips the finalize. Then it commits the cursor and clears the buffer. Nested-block path
delegates to `FUN_005f3cc0`. (Prior name "ui_dialog_close_reset" was misleading — this is a
text-run flush, not a dialog teardown.)

## Input / output
- `param_1` : `char*` — pending text buffer; cleared on the top-level path.
- Returns `void`.

## Side effects
- top-level: `layout_text_run`, `emit_text_run`, conditional `finalize_run_metrics(&node)`,
  `commit_cursor(&+0xd8bc)`, `ctx+0x4=0`, `*param_1=0`.
- nested: `FUN_005f3cc0()`.

## Important branches
- `if (ctx[+0xd892]==0)` — depth gate (else delegate to `005f3cc0`).
- `if (*(short*)(ctx+0xd8bc) != 0) finalize_run_metrics(&node);` — only close a run when cursor-x
  is nonzero (pending content on the line).

## Constants & flags
- `+0xd8bc` live cursor-x (0 = at line origin, nothing to flush).
- `+0xd892` depth-0 gate; `+0x1540` root array.

## Corrected reconstruction
```c
// Flush the current text run only if one is pending on the line, then reset the buffer.
void render_text_token_flush_if_pending(char *buf /*param_1*/)
{
    UiCtx *ctx = (UiCtx *)iRam007012a0;

    if (ctx->node_depth == 0) {
        int node = iRam007012a0 + (unsigned)ctx->root_idx * 4 + 0x1540;
        layout_text_run(buf, &node);            // 0x005eea60
        emit_text_run(node);                    // 0x005eeca0
        if (ctx->cursor_x != 0)                 // +0xd8bc: run pending on this line
            finalize_run_metrics(&node);        // 0x005eed40
        commit_cursor(&ctx->cursor_x);          // 0x005ec170
        ctx->text_len = 0;
        *buf = 0;
    } else {
        block_render_text_token_close();        // 0x005f3cc0
    }
}
```

## Evidence
- Raw `FUN_005ef0e0.c`: identical skeleton to 0x005ef040 with the `finalize_run_metrics` call
  guarded by `*(short*)(ctx+0xd8bc)!=0`; delegates to `005f3cc0`.
- Runtime-unvalidated.

## Remaining uncertainty
- Whether callers use this specifically at line/paragraph boundaries (the conditional flush hints
  at end-of-line handling). Renamed from the earlier "dialog close" guess.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ef0e0.c`  — untouched decompiler output.
