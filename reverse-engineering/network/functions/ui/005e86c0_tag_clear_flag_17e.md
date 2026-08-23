# 0x005e86c0 tag_clear_flag_17e

| field | value |
|---|---|
| Original address | 0x005e86c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e86c0 |
| Resolved name | tag_style_17e_off |
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
Inverse of `tag_style_17e_on` (`0x005e8690`): flushes the current run and carriage-returns the
pen via `FUN_005eef70`, then clears style flag `ctx+0x17e = 0`, ending the `0x17e` style span for
following glyphs.

## Input / output
- `param_1` (undefined8): markup cursor — unused.
- `param_2` (undefined8): pending glyph-run accumulator — forwarded to `FUN_005eef70`.
- returns 0.

## Side effects
- `FUN_005eef70(param_2)`: flush run, carriage-return pen, reset run length, empty accumulator.
- `ctx+0x17e = 0`.

## Important branches
None.

## Constants & flags
- `ctx+0x17e` — style attribute bit (set by `0x005e8690`).

## Corrected reconstruction
```c
// Disable render style attribute 0x17e.
undefined8 tag_style_17e_off(void *cursor /*unused*/, uint8_t *run_acc)
{
    txtmarkup_flush_to_origin(run_acc);   // FUN_005eef70
    g_txtctx->style_17e = 0;              // +0x17e
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e86c0.c` — flush + single store of 0.
- Exact inverse of `FUN_005e8690`; shared flusher `FUN_005eef70` documented there.
- UI-only; no net reference. Runtime-unvalidated.

## Remaining uncertainty
- Visual meaning of `+0x17e` (see the `_on` record).
