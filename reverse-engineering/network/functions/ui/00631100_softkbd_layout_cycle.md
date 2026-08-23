# 0x00631100 softkbd_charset_cycle

| field | value |
|---|---|
| Original address | 0x00631100 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631100 |
| Resolved name | softkbd_charset_cycle |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006300a0 (softkbd input dispatcher)
**Callees:** FUN_00631240 (shift-page adjust helper), FUN_00637540 / FUN_00637690 / FUN_00637140 (grid rebuild + repaint trio)
**Referenced globals:** iRam00715da8 (SoftKbd widget-state base)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1e layout/charset page; +0x20 charset-capability bitmask; +0x33 lock flags; +0x4a status flags; +0x248 result code

## Behavioral explanation
Handles the "cycle character set" key (raw dispatch key 0x39). The current charset page index lives in `+0x1e`; `+0x20` is a bitmask of which charset pages this input field is *allowed* to use. Depending on the current page, the function either advances to the next available charset (choosing from the caps bitmask), delegates to a shift-variant adjust, toggles the shifted-variant bit (`^8`), or does nothing. On any real change it rebuilds and repaints the on-screen key grid and posts result 1.

## Input / output
- No parameters.
- Returns `void`; effective output = new `+0x1e` page + `+0x248` result.

## Side effects
- Writes `+0x1e` (new charset page).
- Clears `+0x4a bit0` (cancel-latch) on the default path.
- Calls the grid rebuild/repaint trio (FUN_00637540/00637690/00637140).
- Sets `+0x248 = 1` (KBRES_REDRAW).

## Important branches
Guard: only runs if `page < 0x10`. Then `switch(page)`:
- **default** (pages 0,1,3,4,5,8,9): pick next available charset from caps `+0x20`, in priority order:
  - `!(caps & 0x0004)` -> page 2; else `!(caps & 0x0400)` -> page 10 (0xa); else `!(caps & 0x0080)` -> page 7; else if `(caps & 0x8000)` -> **return** (nothing available); else page 0xf. Then clear `+0x4a bit0`.
- **case 2 / 6 / 7**: `shift_page_adjust()` (FUN_00631240).
- **case 10 / 0xe / 0xf** (shifted pages): if `+0x33 bit0` set -> return; if the corresponding cap bit `(caps & (1 << (page-8)))` is set -> return; else toggle page `^8` (drop the shift bit -> base page).
- **case 0xb / 0xc / 0xd**: **return** (no cycle from these pages).
- Fallthrough (any case that didn't return): rebuild+repaint grid, `+0x248 = 1`.

## Constants & flags
- `+0x1e` page: bit3 (`0x08`) = "shifted" variant of a base page. Base pages seen: 2, 7, 0xa(10), 0xf(15). Shifted forms: 0xa/0xe/0xf toggled via `^8`.
- `+0x20` charset caps: bit `0x0004` gates page 2, `0x0400` gates page 10, `0x0080` gates page 7, `0x8000` = "no further charset". For shifted toggle, cap bit index = `page-8`.
- `+0x33 bit0` = shift-lock/disable-shift flag.
- `+0x4a bit0` = cancel-latch, cleared on charset change.

## Corrected reconstruction
```c
// key 0x39: cycle character set / keyboard page
void softkbd_charset_cycle(void)
{
    SoftKbd *kb = (SoftKbd*)iRam00715da8;
    uint8_t page = kb->layout_page;            // +0x1e
    if (page >= 0x10) return;

    switch (page) {
    default: {                                 // 0,1,3,4,5,8,9
        uint32_t caps = kb->charset_caps;      // +0x20
        if      (!(caps & 0x0004)) kb->layout_page = 2;
        else if (!(caps & 0x0400)) kb->layout_page = 10;
        else if (!(caps & 0x0080)) kb->layout_page = 7;
        else if  (caps & 0x8000)   return;     // nothing else available
        else                        kb->layout_page = 0x0f;
        kb->flags4a &= ~1;                     // clear cancel-latch
        break;
    }
    case 2: case 6: case 7:
        softkbd_shift_page_adjust();           // FUN_00631240
        break;
    case 10: case 0x0e: case 0x0f:
        if (kb->flags33 & 1) return;                       // shift locked
        if (kb->charset_caps & (1u << (page - 8))) return; // shifted form not allowed
        kb->layout_page = page ^ 8;            // drop shift bit
        break;
    case 0x0b: case 0x0c: case 0x0d:
        return;                                // no cycle from these pages
    }

    softkbd_grid_rebuild();  // FUN_00637540
    softkbd_grid_layout();   // FUN_00637690
    softkbd_grid_repaint();  // FUN_00637140
    kb->result = KBRES_REDRAW;                 // +0x248 = 1
}
```

## Evidence
- Raw switch on `*(byte*)(+0x1e)` with the exact cap-bit tests (`&4`,`&0x400`,`&0x80`,`&0x8000`) and the `^8` shift toggle.
- The 37540/37690/37140 trio recurs at the tail of every charset/page change handler in this family (00631100, 006312c0, 00631560, 00631670) = "rebuild + repaint grid".
- FUN_00631240 is this function's only non-repaint callee and is the shifted-page helper (see its record).

## Remaining uncertainty
- Absolute charset identities (which page = kana vs latin vs symbols) not resolved; only the numeric transitions and gating bits are certain.
- Cap-bit-to-page mapping (`1 << (page-8)`) inferred from arithmetic, not runtime-traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631100.c` — untouched decompiler output.
