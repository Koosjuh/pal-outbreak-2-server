# 0x005ef4f0 ui_table_block_close

| field | value |
|---|---|
| Original address | 0x005ef4f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ef4f0 |
| Resolved name | ui_table_block_close |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e8510
**Callees:** FUN_005d8b00 (draw_region_end)
**Referenced globals:** iRam007012a0; +0x186 render-pass mode; +0xe96b draw-suppress; +0x4 active-op field
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xe96b; +0x4

## Behavioral explanation
Closing counterpart to `ui_table_state_reset` (0x005ef3f0). In draw mode (`+0x186 == 0`) with
drawing enabled (`+0xe96b == 0`) it ends the current draw region (`draw_region_end`, 0x005d8b00),
then unconditionally clears the context active-op field (`ctx+0x4 = 0`) and the caller's active
flag (`*param_1 = 0`). This is the same `+0x186/+0xe96b` draw gate + buffer reset tail seen in the
text-flush variants — a block/element close.

## Input / output
- `param_1` : `char*/u8*` — caller's active flag; cleared to 0.
- `void` return.

## Side effects
- Draw path: `draw_region_end()` (`FUN_005d8b00`).
- Always: `ctx+0x4 = 0`; `*param_1 = 0`.

## Important branches
- `if (ctx+0x186 == 0 && ctx+0xe96b == 0) draw_region_end();` — draw teardown only in the draw pass
  with draw enabled; measure pass skips it.

## Constants & flags
- `+0x186 == 0` = draw pass; `+0xe96b` = draw-suppress (nonzero suppresses).
- `+0x4` = pending active-op/buffer field (cleared).

## Corrected reconstruction
```c
// Close a table/draw block: end the draw region (draw pass) and reset the active-op flags.
void ui_table_block_close(u8 *active_flag /*param_1*/)
{
    UiCtx *ctx = (UiCtx *)iRam007012a0;
    if (ctx->render_pass == 0 && ctx->draw_suppress == 0)   // +0x186, +0xe96b
        draw_region_end();                                  // 0x005d8b00
    ctx->active_op = 0;                                     // +0x4
    *active_flag = 0;
}
```

## Evidence
- Raw `FUN_005ef4f0.c`: `if (+0x186==0 && +0xe96b==0) FUN_005d8b00();` then `ctx+0x4=0; *param_1=0`.
- Mirrors the tail of ui_dialog_close_reset/render_text_token_flush (0x005ef0e0) and pairs with
  ui_table_state_reset's open (0x005ef3f0).
- Runtime-unvalidated.

## Remaining uncertainty
- Whether the caller-passed flag is the same "active-op" concept as `ctx+0x4` or a separate node
  guard. Renamed from "dialog_close_simple" — the draw-region pairing points to a table/element
  block close.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ef4f0.c`  — untouched decompiler output.
