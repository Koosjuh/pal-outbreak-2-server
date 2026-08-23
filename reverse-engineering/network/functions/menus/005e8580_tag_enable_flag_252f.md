# 0x005e8580 tag_enable_flag_252f

| field | value |
|---|---|
| Original address | 0x005e8580 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8580 |
| Resolved name | tag_enable_selectable |
| Subsystem | menus |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup dispatch table)
**Callees:** FUN_005eef70 (flush-run + CR to origin), FUN_005ec100 (load palette)
**Referenced globals:** ctx+0xd892 (entry_mode); +0xd894 (entry_index); +0x17c (global selectable flag); +0x252f/entry (per-entry selectable flag)
**Referenced strings:** —
**Referenced opcodes:** — (menu UI, not SN@P)
**State vars:** ctx+0xd892; +0xd894; +0x17c; per-entry +0x252f

## Behavioral explanation
Markup tag that turns the following text into a *selectable / highlightable* region and
switches the render color to the "enabled" palette. It first flushes the current glyph run and
returns the pen to the line origin via `FUN_005eef70` (the pre-attribute-change flusher — it
does NOT line-feed, it copies pen-origin `+0xd8c0/+0xd8c2` back into pen `+0xd8bc/+0xd8be`).
Then it sets the selectable flag: in the normal/global text stream (`ctx+0xd892 == 0`) it sets
the single global flag `ctx+0x17c = 1`; when rendering into a specific menu cell
(`ctx+0xd892 != 0`) it sets the per-entry flag at `ctx + entry_index*0x5c + 0x252f = 1`.
Finally `FUN_005ec100(1)` reloads the foreground/background color pair from the palette using
color-state `1` (the "enabled/active" row).

Per-entry addressing: `(entry_index*0x18 - entry_index)*4 = entry_index*0x17*4 = entry_index*0x5c`,
i.e. a 0x5c-byte stride per menu-entry record based at `iRam007012a0`.

## Input / output
- `param_1` (undefined8): markup cursor — unused (no inline argument).
- `param_2` (undefined8): pending glyph-run accumulator — forwarded to `FUN_005eef70`.
- returns 0.

## Side effects
- `FUN_005eef70(param_2)`: flush staged run into layout, carriage-return pen to line origin, clear `pending_run_len`, empty accumulator.
- Enable flag ← 1 (global `+0x17c` or per-entry `+0x252f`).
- `FUN_005ec100(1)`: writes `ctx+0x180` (fg) / `ctx+0x181` (bg) from palette tables `0x6494c0`/`0x6494d0`, row = `1*8 + style_index` where `style_index` comes from `ctx+0x124 → ctx+0x168[...]`.

## Important branches
- `ctx+0xd892 == 0` (global stream) → set `ctx+0x17c = 1`.
- else (per-menu-cell) → set `ctx[entry_index*0x5c + 0x252f] = 1`.
- No error/bounds path (entry_index assumed valid).

## Constants & flags
- `ctx+0xd892` — `entry_mode`: 0 = global text stream, non-0 = per-menu-cell rendering.
- Per-entry stride `0x5c` (from `idx*0x18 - idx`, ×4).
- Per-entry field `+0x252f` — selectable/enabled flag. Global counterpart `+0x17c`.
- `FUN_005ec100(1)` — color-state 1 = enabled/active palette row.

## Corrected reconstruction
```c
#define ENTRY_STRIDE 0x5c
// menu-entry record at ctx + idx*0x5c: +0x24fb type, +0x252f selectable, +0x2531 level-nibble

undefined8 tag_enable_selectable(void *cursor /*unused*/, uint8_t *run_acc)
{
    txtmarkup_flush_to_origin(run_acc);                 // FUN_005eef70 (no line-feed)
    if (g_txtctx->entry_mode == 0) {
        g_txtctx->selectable = 1;                       // +0x17c global
    } else {
        uint16_t idx = g_txtctx->entry_index;           // +0xd894
        *((uint8_t*)g_txtctx + idx*ENTRY_STRIDE + 0x252f) = 1;
    }
    palette_load(1);                                    // FUN_005ec100 — enabled color row
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e8580.c`.
- `FUN_005eef70` (read): flush + copy pen-origin into pen (carriage return), no `FUN_005eed40` line-feed — the "before an attribute change" flusher.
- `FUN_005ec100` (read): indexes `0x6494c0/0x6494d0` by `(state&0xff)*8 + ctx[+0x124→+0x168]` into fg `+0x180` / bg `+0x181`.
- Direct inverse of `FUN_005e8600` (`tag_disable_selectable`), which sets the same flag to 0 with `FUN_005ec100(0)`.
- Menu UI; no net reference. Runtime-unvalidated.

## Remaining uncertainty
- Layout of the 0x5c-byte menu-entry record beyond the three touched fields.
- Exact display meaning of "selectable" (input focus vs. mere highlight color).
