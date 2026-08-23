# 0x005e86f0 tag_set_flag_17d

| field | value |
|---|---|
| Original address | 0x005e86f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e86f0 |
| Resolved name | tag_style_17d_on |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup dispatch table)
**Callees:** FUN_005eef70 (flush-run + CR to origin)
**Referenced globals:** ctx+0x17d (style attribute flag)
**Referenced strings:** —
**Referenced opcodes:** — (UI, not SN@P)
**State vars:** ctx+0x17d

## Behavioral explanation
Markup attribute tag that turns style flag `+0x17d` ON. Flushes the current glyph run and
carriage-returns the pen via `FUN_005eef70`, then sets `ctx+0x17d = 1`, so following glyphs
render with the `0x17d` attribute active. `+0x17d` sits adjacent to the `+0x17e` style flag and
the `+0x17c` selectable flag; the three form a small block of global render attributes toggled
by paired on/off tags.

## Input / output
- `param_1` (undefined8): markup cursor — unused (no inline argument).
- `param_2` (undefined8): pending glyph-run accumulator — forwarded to `FUN_005eef70`.
- returns 0.

## Side effects
- `FUN_005eef70(param_2)`: flush run, carriage-return pen, reset run length, empty accumulator.
- `ctx+0x17d = 1`.

## Important branches
None.

## Constants & flags
- `ctx+0x17d` — style attribute bit (paired with clear-handler `0x005e8720`).

## Corrected reconstruction
```c
// Enable render style attribute 0x17d for following glyphs.
undefined8 tag_style_17d_on(void *cursor /*unused*/, uint8_t *run_acc)
{
    txtmarkup_flush_to_origin(run_acc);   // FUN_005eef70
    g_txtctx->style_17d = 1;              // +0x17d
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e86f0.c` — flush + single store.
- Structurally identical to `FUN_005e8690` (the `+0x17e` setter); inverse is `FUN_005e8720`.
- Shared flusher `FUN_005eef70` documented under `tag_style_17e_on`.
- UI-only; no net reference. Runtime-unvalidated.

## Remaining uncertainty
- Visual meaning of `+0x17d` (bold/color/underline/shadow) — only the on/off toggle is proven.
