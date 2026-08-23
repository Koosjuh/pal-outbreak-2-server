# 0x006313a0 softkbd_jump_grid_to_key

| field | value |
|---|---|
| Original address | 0x006313a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006313a0 |
| Resolved name | softkbd_jump_grid_to_key |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006314a0 (page-key sub-dispatcher)
**Callees:** FUN_00630c50 (IME/lock predicate), FUN_00637260 (select layout page by table index), FUN_00637540 (grid rebuild), FUN_00635ab0 (clear buffers wrapper), FUN_006322c0 (cursor/selection refresh)
**Referenced globals:** iRam00715da8 (SoftKbd widget-state base)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1e layout page; +0x1f field mode; +0x24 grid col; +0x25 grid row; +0x2f IME state; +0x4a status flags; +0x248 result code

## Behavioral explanation
Handler for a "special / jump" key routed here by FUN_006314a0 (the key code arrives in register a0, shown by the decompiler as `extraout_a0_lo`). It switches to a specific layout page (table index 5), sets the cancel-latch flag, and jumps the on-screen key-grid cursor to a cell computed directly from the pressed key code — `col = ((key-0x3a)*5) % 20`, `row = ((key-0x3a)*5) / 20`. On any failure (IME busy/locked, or the page-select rejects) it posts result 5 (blocked) instead.

## Input / output
- No declared parameters; effective input is the **key code in a0** (decompiler artifact `extraout_a0_lo`), in the 0x3a–0x45 range from the caller.
- Returns `void`; output = grid cursor `+0x24/+0x25`, `+0x1e`, `+0x248`.

## Side effects
- Sets `+0x4a bit0` (cancel-latch) before selecting the page.
- `select_layout_page(5,...)` (FUN_00637260) may change `+0x1e`/`+0x1f`.
- On success: writes grid col/row, rebuilds grid (FUN_00637540), clears buffers (FUN_00635ab0), refreshes cursor (FUN_006322c0).
- On failure: `+0x248 = 5` (KBRES_BLOCKED).

## Important branches
- Guard: proceed only if `ime_state==0` (`+0x2f`) AND `FUN_00630c50()==0` (not locked/composing). Else `+0x248 = 5`.
- After `flags4a |= 1` and `select_layout_page(5, &field_mode, &layout_page)`:
  - `== 0` (success): compute `v = ((key-0x3a)*5 & 0xff)+1`; `grid_col = v % 20`; `grid_row = v / 20`; rebuild+clear+refresh.
  - `!= 0` (rejected): `+0x248 = 5`.

## Constants & flags
- Layout table index `5` passed to FUN_00637260.
- Grid dimensions: `20` columns (0x14) per row; `col = v % 20`, `row = v / 20`.
- `+0x4a bit0` = cancel-latch (set here).
- `+0x248 = 5` = blocked/error.

## Corrected reconstruction
```c
// special "jump-to-key" handler; key code arrives in a0 (extraout_a0_lo)
void softkbd_jump_grid_to_key(void)   // implicit uint8_t key in a0
{
    SoftKbd *kb = (SoftKbd*)iRam00715da8;
    uint8_t key = a0;                          // register-passed key (0x3a..0x45) [inferred]

    if (kb->ime_state == IME_IDLE &&           // +0x2f == 0
        ime_lock_predicate() == 0) {           // FUN_00630c50 == 0
        kb->flags4a |= 1;                      // set cancel-latch
        long rc = select_layout_page(5, &kb->field_mode, &kb->layout_page); // FUN_00637260
        if (rc == 0) {
            uint32_t v = (((key - 0x3a) & 0xff) * 5 & 0xff) + 1;
            kb->grid_col = (uint8_t)(v % 20);  // +0x24
            kb->grid_row = (uint8_t)(v / 20);  // +0x25
            softkbd_grid_rebuild();            // FUN_00637540
            softkbd_clear_buffers_refresh();   // FUN_00635ab0
            softkbd_cursor_refresh();          // FUN_006322c0
        } else {
            kb->result = KBRES_BLOCKED;        // +0x248 = 5
        }
    } else {
        kb->result = KBRES_BLOCKED;            // +0x248 = 5
    }
}
```

## Evidence
- Raw: `FUN_00637260(5, +0x1f, +0x1e)` and the `((extraout_a0_lo & 0xff) - 0x3a) * 5` grid math writing `+0x24`/`+0x25`.
- 20-column grid confirmed by FUN_00631910 (grid_cursor_move) wrapping col at 0x14.
- FUN_00635ab0 wraps the buffer-clear leaf FUN_00631620 (see that record).

## Remaining uncertainty
- `extraout_a0_lo` is a decompiler artifact for the key held in a0; treated as the pressed key code — the exact register liveness is not runtime-confirmed (hence Medium).
- Purpose of table index 5 in FUN_00637260 (which page it selects) not resolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006313a0.c` — untouched decompiler output.
