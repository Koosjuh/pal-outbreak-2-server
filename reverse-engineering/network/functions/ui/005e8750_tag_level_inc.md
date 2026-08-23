# 0x005e8750 tag_level_inc

| field | value |
|---|---|
| Original address | 0x005e8750 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8750 |
| Resolved name | tag_indent_level_inc |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup dispatch table)
**Callees:** FUN_005ef0e0 (flush + conditional line-feed), FUN_005ef780 (per-entry layout refresh)
**Referenced globals:** ctx+0xd892 (entry_mode); +0xd894 (entry_index); +0x14 (global level nibble); per-entry +0x2531 (level nibble)
**Referenced strings:** —
**Referenced opcodes:** — (UI, not SN@P)
**State vars:** ctx+0x14 low nibble; per-entry +0x2531 low nibble; +0xd892

## Behavioral explanation
Markup tag that raises the indent/level counter by one (saturating at 0xF). It first flushes the
current glyph run and conditionally line-feeds via `FUN_005ef0e0` (line-feed only if the pen is
not already at column origin — `ctx+0xd8bc != 0`), so the indent change starts on a fresh line
without inserting a blank one. Then it increments the **low nibble** of the level counter,
clamped at `0xF`: in the global stream (`ctx+0xd892 == 0`) it is `ctx+0x14`; in per-menu-cell
mode it is the per-entry byte `ctx[entry_index*0x5c + 0x2531]`, after which `FUN_005ef780()`
runs — a per-entry layout refresh that re-derives the cell's margin/extent from the new level.
The high nibble of the level byte is preserved (masked with `0xF0`), so it stores an unrelated
sub-field.

## Input / output
- `param_1` (undefined8): markup cursor — unused (no inline argument).
- `param_2` (undefined8): pending glyph-run accumulator — forwarded to `FUN_005ef0e0`.
- returns 0.

## Side effects
- `FUN_005ef0e0(param_2)`: flush run, conditional line-feed, pen reset, run length = 0, accumulator emptied.
- Global path: `lvl = ctx[0x14] & 0xF; if (lvl != 0xF) ctx[0x14] = (ctx[0x14] & 0xF0) | (lvl+1)`.
- Per-cell path: same nibble-increment on `base[0x2531]`, then `FUN_005ef780()`.

## Important branches
- `ctx+0xd892 == 0` → increment global `+0x14` nibble (unless already `0xF`).
- else → increment per-entry `+0x2531` nibble (unless `0xF`), then call `FUN_005ef780`.
- Saturation guard: `nibble == 0xF` → leave unchanged (no wrap).

## Constants & flags
- Level nibble mask `0xF` (value 0..15); high nibble `0xF0` preserved (separate field).
- `ctx+0xd892` — `entry_mode` (0 global / non-0 per-cell); per-entry stride `0x5c`.
- `FUN_005ef780` — per-entry layout/margin refresh [inferred; per-cell path only].

## Corrected reconstruction
```c
#define ENTRY_STRIDE 0x5c
static inline uint8_t nib_inc(uint8_t b){ uint8_t n=b&0xF; return n==0xF ? b : (b&0xF0)|(n+1); }

undefined8 tag_indent_level_inc(void *cursor /*unused*/, uint8_t *run_acc)
{
    txtmarkup_flush_cond_linefeed(run_acc);             // FUN_005ef0e0
    if (g_txtctx->entry_mode == 0) {
        g_txtctx->level = nib_inc(g_txtctx->level);     // +0x14
    } else {
        uint8_t *base = (uint8_t*)g_txtctx + g_txtctx->entry_index * ENTRY_STRIDE;
        base[0x2531] = nib_inc(base[0x2531]);
        entry_layout_refresh();                         // FUN_005ef780 [inferred]
    }
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e8750.c`.
- `FUN_005ef0e0` (read): flush that line-feeds only when `ctx+0xd8bc != 0` (avoids blank line) — the indent-safe flusher.
- Nibble math `& 0xf`, saturate at `0xf`, preserve `& 0xf0`, mirror of the decrement in `FUN_005e8810`.
- UI-only; no net reference. Runtime-unvalidated.

## Remaining uncertainty
- `FUN_005ef780` body not decompiled (per-entry layout refresh is inferred).
- What the level nibble controls precisely (indent columns vs. font size step vs. list depth) and what the preserved high nibble holds.
