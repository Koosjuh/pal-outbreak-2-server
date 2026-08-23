# 0x005e8690 tag_set_flag_17e

| field | value |
|---|---|
| Original address | 0x005e8690 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8690 |
| Resolved name | tag_style_17e_on |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup dispatch table)
**Callees:** FUN_005eef70 (flush-run + CR to origin)
**Referenced globals:** ctx+0x17e (style attribute flag)
**Referenced strings:** —
**Referenced opcodes:** — (UI, not SN@P)
**State vars:** ctx+0x17e

## Behavioral explanation
Markup attribute tag that turns style flag `+0x17e` ON. Like all attribute-change tags it first
flushes the current glyph run and carriage-returns the pen to the line origin via `FUN_005eef70`
(so the run already laid down keeps its old style), then sets `ctx+0x17e = 1`. Subsequent
glyphs are rendered with the `0x17e` style active. `+0x17e` is a global (non-per-entry) render
attribute, distinct from the selectable flag `+0x17c` and the companion style flag `+0x17d`.

## Input / output
- `param_1` (undefined8): markup cursor — unused (no inline argument).
- `param_2` (undefined8): pending glyph-run accumulator — forwarded to `FUN_005eef70`.
- returns 0.

## Side effects
- `FUN_005eef70(param_2)`: flush staged run, carriage-return pen, clear `pending_run_len`, empty accumulator.
- `ctx+0x17e = 1`.

## Important branches
None.

## Constants & flags
- `ctx+0x17e` — style attribute bit (paired with clear-handler `0x005e86c0`). Exact visual effect (e.g. bold/color/underline/shadow) not determined; it is a global boolean toggle.

## Corrected reconstruction
```c
// Enable render style attribute 0x17e for following glyphs.
undefined8 tag_style_17e_on(void *cursor /*unused*/, uint8_t *run_acc)
{
    txtmarkup_flush_to_origin(run_acc);   // FUN_005eef70 — flush old-style run first
    g_txtctx->style_17e = 1;              // +0x17e
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e8690.c` — flush + single store.
- `FUN_005eef70` (read) = flush-to-origin (no line-feed), the standard pre-attribute-change flush.
- Paired inverse `FUN_005e86c0` clears the same byte; the `+0x17d` pair (`005e86f0`/`005e8720`) is structurally identical.
- UI-only; no net reference. Runtime-unvalidated.

## Remaining uncertainty
- What `+0x17e` renders as (bold/emphasis/color mode) — only its on/off toggle is proven.
