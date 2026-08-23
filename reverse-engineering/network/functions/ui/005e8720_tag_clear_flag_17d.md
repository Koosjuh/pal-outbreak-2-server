# 0x005e8720 tag_clear_flag_17d

| field | value |
|---|---|
| Original address | 0x005e8720 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8720 |
| Resolved name | tag_style_17d_off |
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
Inverse of `tag_style_17d_on` (`0x005e86f0`): flushes the current run and carriage-returns the
pen via `FUN_005eef70`, then clears `ctx+0x17d = 0`, ending the `0x17d` style span.

## Input / output
- `param_1` (undefined8): markup cursor — unused.
- `param_2` (undefined8): pending glyph-run accumulator — forwarded to `FUN_005eef70`.
- returns 0.

## Side effects
- `FUN_005eef70(param_2)`: flush run, carriage-return pen, reset run length, empty accumulator.
- `ctx+0x17d = 0`.

## Important branches
None.

## Constants & flags
- `ctx+0x17d` — style attribute bit (set by `0x005e86f0`).

## Corrected reconstruction
```c
// Disable render style attribute 0x17d.
undefined8 tag_style_17d_off(void *cursor /*unused*/, uint8_t *run_acc)
{
    txtmarkup_flush_to_origin(run_acc);   // FUN_005eef70
    g_txtctx->style_17d = 0;              // +0x17d
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e8720.c` — flush + single store of 0.
- Exact inverse of `FUN_005e86f0`; shared flusher `FUN_005eef70` documented there.
- UI-only; no net reference. Runtime-unvalidated.

## Remaining uncertainty
- Visual meaning of `+0x17d` (see the `_on` record).
