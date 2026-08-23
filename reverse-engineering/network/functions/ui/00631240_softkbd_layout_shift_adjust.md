# 0x00631240 softkbd_shift_page_adjust

| field | value |
|---|---|
| Original address | 0x00631240 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631240 |
| Resolved name | softkbd_shift_page_adjust |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631100 (charset cycle)
**Callees:** —
**Referenced globals:** iRam00715da8 (SoftKbd widget-state base)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1e layout/charset page; +0x33 lock flags; +0x20 charset-capability bitmask

## Behavioral explanation
Leaf helper for the charset-cycle key. When the current page is one of the base pages 2/6/7 and shifting is permitted, it promotes the page to its shifted variant by setting bit3 (`| 8`). Purely a page-index mutation; the caller handles the grid repaint.

## Input / output
- No parameters.
- Returns `void`. Output = possibly-modified `+0x1e`.

## Side effects
- OR-sets `0x08` into `+0x1e` (base page -> shifted page) when the guard passes. No other state touched.

## Important branches
- Runs the mutation only if ALL hold:
  - `page == 2 || page == 6 || page == 7`, AND
  - `+0x33 bit0 == 0` (shift not locked/disabled), AND
  - `(caps & (1 << (page+8))) == 0` (the shifted form is allowed for this field).
- Otherwise no-op.

## Constants & flags
- `+0x1e` bit3 (`0x08`) = shifted-variant marker.
- `+0x33 bit0` = shift-lock / disable-shift.
- `+0x20` caps: shifted-form gate bit index = `page + 8`.

## Corrected reconstruction
```c
// helper of softkbd_charset_cycle: promote base page -> shifted variant
void softkbd_shift_page_adjust(void)
{
    SoftKbd *kb = (SoftKbd*)iRam00715da8;
    uint32_t page = kb->layout_page;           // +0x1e

    if ((page == 6 || page == 7 || page == 2) &&
        (kb->flags33 & 1) == 0 &&                        // +0x33 shift not locked
        (kb->charset_caps & (1u << (page + 8))) == 0) {  // +0x20 shifted form allowed
        kb->layout_page |= 8;                  // set shift bit
    }
}
```

## Evidence
- Raw: single compound `if` gating `*(byte*)(+0x1e) |= 8`.
- Cap-bit index `1 << (uVar1 + 8)` mirrors the `page-8` index used in FUN_00631100's shifted-page branch (inverse direction), confirming the shift-bit convention.

## Remaining uncertainty
- The `+0x20` caps bit layout is inferred from the arithmetic shared with FUN_00631100; not runtime-traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631240.c` — untouched decompiler output.
