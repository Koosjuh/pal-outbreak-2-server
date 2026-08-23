# 0x005e8960 tag_flush_then_380

| field | value |
|---|---|
| Original address | 0x005e8960 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8960 |
| Resolved name | tag_newline_reset_style |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup dispatch table)
**Callees:** FUN_005ef040 (flush + line-feed), FUN_005ef380 (reset attributes / reload palette)
**Referenced globals:** iRam007012a0 (via callees)
**Referenced strings:** —
**Referenced opcodes:** — (UI, not SN@P)
**State vars:** — (delegated)

## Behavioral explanation
Markup tag that emits a newline and then resets the active text style. It first flushes the
pending glyph run and line-feeds via `FUN_005ef040`, then calls `FUN_005ef380`, which is an
attribute/line-state finalizer that reloads the color palette (`FUN_005ef380` is in the caller
set of the palette-loader `FUN_005ec100`). Net effect: end the current line and return the
render attributes (color, and likely the style flags) to their default for the next line — the
behavior expected of a paragraph/reset tag as opposed to a plain `<br>`.

## Input / output
- `param_1` (undefined8): markup cursor — unused (no inline argument).
- `param_2` (undefined8): pending glyph-run accumulator — forwarded to `FUN_005ef040`.
- returns 0.

## Side effects
- `FUN_005ef040(param_2)`: flush run into layout, line-feed, pen reset, run length = 0, accumulator emptied.
- `FUN_005ef380()`: reset line/attribute state and reload the palette (`FUN_005ec100`).

## Important branches
None.

## Constants & flags
None local. (`FUN_005ef380` selects a default palette row internally.)

## Corrected reconstruction
```c
// Newline that also resets text attributes/color to default for the next line.
undefined8 tag_newline_reset_style(void *cursor /*unused*/, uint8_t *run_acc)
{
    txtmarkup_flush_and_linefeed(run_acc);   // FUN_005ef040
    txtmarkup_reset_line_style();            // FUN_005ef380 -> reloads palette (FUN_005ec100)
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e8960.c` — two calls + `return 0`.
- `FUN_005ef040` (read) = flush + line-feed.
- `FUN_005ef380` appears in `FUN_005ec100`'s caller list (from the palette-loader's callers), so it reapplies the fg/bg color pair — the "reset style" step.
- UI-only; no net reference. Runtime-unvalidated.

## Remaining uncertainty
- `FUN_005ef380` body not fully decompiled — it reloads the palette (confirmed via xref) but which additional flags it resets (17c/17d/17e, level) is not verified.
