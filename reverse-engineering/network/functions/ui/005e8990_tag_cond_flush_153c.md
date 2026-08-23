# 0x005e8990 tag_cond_flush_153c

| field | value |
|---|---|
| Original address | 0x005e8990 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8990 |
| Resolved name | tag_conditional_blank_line |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup dispatch table)
**Callees:** FUN_005ef0e0 (flush + conditional line-feed), FUN_005ef040 (flush + line-feed)
**Referenced globals:** ctx+0x188 (page_index); +0x153c (per-page int16 table)
**Referenced strings:** —
**Referenced opcodes:** — (UI, not SN@P)
**State vars:** ctx+0x188; per-page +0x153c

## Behavioral explanation
Markup tag that ends the current line and, conditionally, inserts a second (blank) line. It
always calls `FUN_005ef0e0` first (flush + conditional line-feed — line-feed only if the pen is
off the origin). It then reads a per-page 16-bit value from the table at `ctx+0x153c` indexed by
the current page (`ctx+0x188`, stride 4): if that value is non-zero, it calls `FUN_005ef040`
(an unconditional flush + line-feed), producing an extra line of spacing. This is paragraph
spacing that is enabled per text page — e.g. double-spacing on pages flagged in the `+0x153c`
table, single-spacing elsewhere.

Note the table index uses page*4 while each entry is read as a `short`, so the table holds a
32-bit slot per page of which only the low 16 bits are tested.

## Input / output
- `param_1` (undefined8): markup cursor — unused (no inline argument).
- `param_2` (undefined8): pending glyph-run accumulator — forwarded to both flushers.
- returns 0.

## Side effects
- `FUN_005ef0e0(param_2)`: flush run, conditional line-feed, pen reset, run length = 0, accumulator emptied.
- If `*(int16*)(ctx + page*4 + 0x153c) != 0`: `FUN_005ef040(param_2)` — additional flush + line-feed (blank line).

## Important branches
- `ctx[page*4 + 0x153c] (int16) != 0` → emit the extra line-feed via `FUN_005ef040`.
- else → single line-feed only (from the initial `FUN_005ef0e0`).

## Constants & flags
- `ctx+0x188` — `page_index` (also the index used by every flush routine to pick the layout buffer `ctx+0x1540 + page*4`).
- `ctx+0x153c` — per-page spacing table, 4-byte stride, low 16 bits = "insert blank line" flag/count.

## Corrected reconstruction
```c
undefined8 tag_conditional_blank_line(void *cursor /*unused*/, uint8_t *run_acc)
{
    txtmarkup_flush_cond_linefeed(run_acc);                 // FUN_005ef0e0
    uint16_t page = g_txtctx->page_index;                   // +0x188
    int16_t spacing = *(int16_t*)((uint8_t*)g_txtctx + page*4 + 0x153c);
    if (spacing != 0)
        txtmarkup_flush_and_linefeed(run_acc);              // FUN_005ef040 — extra blank line
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005e8990.c`.
- `ctx+0x188` is the same page index that `FUN_005ef040/eef70/ef0e0` use to select the layout buffer at `ctx+0x1540 + page*4`, confirming it is the page selector.
- `FUN_005ef0e0` (conditional line-feed) and `FUN_005ef040` (unconditional) both read/documented above.
- UI-only; no net reference. Runtime-unvalidated.

## Remaining uncertainty
- Whether the `+0x153c` slot is a boolean, a line count, or packed flags (only `!= 0` is tested here).
- What sets the `+0x153c` table (page setup path not traced).
