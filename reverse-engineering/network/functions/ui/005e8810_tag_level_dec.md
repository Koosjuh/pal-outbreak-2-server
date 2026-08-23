# 0x005e8810 tag_level_dec

| field | value |
|---|---|
| Original address | 0x005e8810 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8810 |
| Resolved name | tag_indent_level_dec |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup dispatch table)
**Callees:** FUN_005ef0e0 (flush + conditional line-feed)
**Referenced globals:** ctx+0xd892 (entry_mode); +0xd894 (entry_index); +0x14 (global level nibble); per-entry +0x2531 (level nibble)
**Referenced strings:** —
**Referenced opcodes:** — (UI, not SN@P)
**State vars:** ctx+0x14 low nibble; per-entry +0x2531 low nibble; +0xd892

## Behavioral explanation
Inverse of `tag_indent_level_inc` (`0x005e8750`): flushes and conditionally line-feeds via
`FUN_005ef0e0`, then decrements the **low nibble** of the level counter, floored at 0. Global
stream uses `ctx+0x14`; per-menu-cell mode uses `ctx[entry_index*0x5c + 0x2531]`. Unlike the
increment, the decrement does **not** call `FUN_005ef780` (no per-entry layout refresh) — a
minor asymmetry in the original code. The high nibble (`0xF0`) is preserved.

## Input / output
- `param_1` (undefined8): markup cursor — unused.
- `param_2` (undefined8): pending glyph-run accumulator — forwarded to `FUN_005ef0e0`.
- returns 0.

## Side effects
- `FUN_005ef0e0(param_2)`: flush run, conditional line-feed, pen reset, run length = 0, accumulator emptied.
- Global path: `lvl = ctx[0x14] & 0xF; if (lvl != 0) ctx[0x14] = (ctx[0x14] & 0xF0) | (lvl-1)`.
- Per-cell path: same nibble-decrement on `base[0x2531]`.

## Important branches
- `ctx+0xd892 == 0` → decrement global `+0x14` nibble (unless already `0`).
- else → decrement per-entry `+0x2531` nibble (unless `0`).
- Floor guard: `nibble == 0` → leave unchanged (no underflow).

## Constants & flags
- Level nibble mask `0xF`; high nibble `0xF0` preserved.
- `ctx+0xd892` — `entry_mode`; per-entry stride `0x5c`.

## Corrected reconstruction
```c
#define ENTRY_STRIDE 0x5c
static inline uint8_t nib_dec(uint8_t b){ uint8_t n=b&0xF; return n==0 ? b : (b&0xF0)|(n-1); }

undefined8 tag_indent_level_dec(void *cursor /*unused*/, uint8_t *run_acc)
{
    txtmarkup_flush_cond_linefeed(run_acc);             // FUN_005ef0e0
    if (g_txtctx->entry_mode == 0) {
        g_txtctx->level = nib_dec(g_txtctx->level);     // +0x14
    } else {
        uint8_t *base = (uint8_t*)g_txtctx + g_txtctx->entry_index * ENTRY_STRIDE;
        base[0x2531] = nib_dec(base[0x2531]);
        // NOTE: no FUN_005ef780 here (asymmetric with the increment)
    }
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e8810.c`.
- Mirror of `FUN_005e8750` with `-1`/floor-at-0 nibble math and the `FUN_005ef780` call omitted.
- Shared flusher `FUN_005ef0e0` documented under `tag_indent_level_inc`.
- UI-only; no net reference. Runtime-unvalidated.

## Remaining uncertainty
- Whether the missing `FUN_005ef780` on decrement is intentional or a stock omission (per-entry margin may go stale until the next inc/redraw).
