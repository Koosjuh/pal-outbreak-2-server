# 0x00634010 wstr_char_index_at_pixel

| field | value |
|---|---|
| Original address | 0x00634010 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00634010 |
| Resolved name | wstr_glyph_advance_at_budget |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631ac0, FUN_00632390
**Callees:** FUN_00637e90 (font-loaded guard), FUN_00637d10 (glyph metrics), func_0x001af420 (advance)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Font-guarded text hit-test. Accumulates glyph advances over the string until the NUL or the pixel budget is reached, counting glyphs consumed (`iVar4`). If the accumulated width *exceeds* the budget it returns -1 (string overflows the field); otherwise it returns the advance width of the glyph at the stop index (`param_1[iVar4]`) — i.e. the width of the next/boundary glyph. Used to map a pixel column to a caret position when clamping a scroll window.

## Input / output
- Params: `short *s` (param_1, UTF-16), `int budget` (param_2, pixel budget).
- Returns: `undefined8` — advance (px) of the boundary glyph, `-1` (0xffffffffffffffff) on overflow, `0` if the font is not loaded.

## Side effects
- None (pure read + stack scratch).

## Important branches
- `FUN_00637e90() == 0` (font not ready) -> return 0.
- Inner loop stops on `*s == 0` or `acc >= budget`.
- `acc > budget` after loop -> return -1 (overflow: didn't fit).
- else -> return `glyph_advance(param_1[iVar4])` (advance of the char at the stop count).

## Constants & flags
- `-1` sentinel = overflow. `0` = font-not-loaded (indistinguishable from a zero-advance boundary glyph — caller must have checked font).

## Corrected reconstruction
```c
// -1 if `s` overflows `budget`; else advance(px) of the boundary glyph
int wstr_glyph_advance_at_budget(const u16 *s, int budget)
{
    if (font_ready() == 0) return 0;                 // FUN_00637e90

    int acc = 0;         // iVar5 accumulated width
    int i   = 0;         // iVar4 glyph count consumed
    GlyphMetrics m;
    const u16 *p = s;
    while (*p != 0 && acc < budget) {
        get_glyph_metrics(*p, &m);                   // FUN_00637d10
        acc += glyph_advance(&m);                     // func_0x001af420
        p++; i++;
    }
    if (acc > budget) return -1;                      // overflow

    get_glyph_metrics(s[i], &m);                      // boundary glyph
    return glyph_advance(&m);
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_00634010.c` (size 192).
- `FUN_00637e90` guard + `FUN_00637d10`/`func_0x001af420` metrics pair; `0xffffffffffffffff` return literal = -1.

## Remaining uncertainty
- Whether callers want the boundary-glyph advance or the count `i` — the decompile returns the advance, but `i` is the more natural "index at pixel"; renamed to reflect the actual return. FUN_00631ac0/FUN_00632390 use disambiguate. Runtime-unvalidated.
