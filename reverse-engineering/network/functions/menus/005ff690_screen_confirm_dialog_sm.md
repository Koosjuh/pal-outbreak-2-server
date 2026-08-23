# 0x005ff690 screen_confirm_dialog_sm

| field | value |
|---|---|
| Original address | 0x005ff690 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ff690 |
| Resolved name | screen_confirm_dialog_0x18_sm |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe730 (screen dispatcher)
**Callees:** FUN_005b68e0 (teardown prior overlay), FUN_005c44a0 (register render cb w/ input-mode), FUN_005b6900 (idle/steady handler), FUN_005ff830 (hard reset to base screen 8)
**Referenced globals:** ctx +0x10 sub-state; +0x16 timer; +0x907 cursor; +0x42b active-overlay id (set 0x18)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x10 sub-state (0..3); +0x16 timer

## Behavioral explanation
4-state confirm-dialog screen. It enters overlay `0x18` (render cb `0x601390`, input-mode 0 = non-interactive/auto), idles while the dialog is shown, and — once armed (state 2, driven externally by the render cb / confirm) — resets the cursor and arms a 10-frame timer, then on timeout **hard-resets the UI back to base screen 8** via `FUN_005ff830`. Used for an auto-dismissing confirmation/notice that bounces the user back to the room/lobby list.

## Input / output
- **param_1** (`undefined8`, screen_ctx*): active screen; +0x10 sub-state, +0x16 timer, +0x907 cursor, +0x42b overlay id.
- **returns** `void`.

## Side effects
- +0x10 driven 0→1 (enter), and 2→3 (arm) → reset.
- +0x42b = 0x18 on enter; render cb 0x601390 registered.
- state 2: +0x907 cursor = 0, +0x16 timer = 10.
- state 3: on timeout `FUN_005ff830(s, 0)` → hard reset to screen 8.

## Important branches
- **state 0 (enter):** +0x10=1; `FUN_005b68e0()` teardown; +0x42b=0x18; `FUN_005c44a0(0, 0x601390)` register render cb.
- **state 1 (idle):** `FUN_005b6900()` — steady handler (advance to state 2 is external, via render cb / user confirm).
- **state 2 (arm):** +0x10=3; +0x907=0; +0x16=10.
- **state 3 (wait+dismiss):** decrement +0x16; when <0 → `FUN_005ff830(s, 0)` (reset to base screen 8).

## Constants & flags
- `0x18` = active-overlay id (+0x42b).
- `FUN_005c44a0` first arg `0` = non-interactive/auto input-mode (contrast FUN_005fed10's `1`).
- arm timer `+0x16 = 10` (~10 frames).
- `0x601390` = render cb.
- `FUN_005ff830(…, 0)` = hard reset to base screen 8 [per prior classification].

## Corrected reconstruction
```c
enum { DLG_ENTER = 0, DLG_IDLE = 1, DLG_ARM = 2, DLG_WAIT = 3 };

// Auto-dismissing confirm dialog (overlay 0x18); on timeout resets to screen 8.
void screen_confirm_dialog_0x18_sm(screen_ctx *s)   // param_1
{
    switch (s->substate) {                    // +0x10
    case DLG_WAIT:                            // 3
        if (--s->timer < 0)                   // +0x16
            reset_to_base_screen(s, 0);       // FUN_005ff830 -> screen 8
        break;
    case DLG_ARM:                            // 2
        s->substate = DLG_WAIT;
        s->cursor   = 0;                      // +0x907
        s->timer    = 10;
        break;
    case DLG_IDLE:                           // 1
        overlay_run_active();                 // FUN_005b6900
        break;
    case DLG_ENTER:                          // 0
        s->substate = DLG_IDLE;
        overlay_teardown();                   // FUN_005b68e0
        s->active_overlay = 0x18;             // +0x42b
        overlay_register_cb(0, 0x601390);     // FUN_005c44a0
        break;
    }
}
```

## Evidence
- Raw decompile `FUN_005ff690.c` (all four states exact).
- `FUN_005ff830` = base-screen-8 reset (prior record note); overlay-id +0x42b family cross-ref.
- Runtime-unvalidated.

## Remaining uncertainty
- What drives state 1→2 (render cb `0x601390` or a user-confirm path) is external and not traced here.
- Semantics of the two-value `FUN_005c44a0` mode arg (0 vs 1) inferred.
```
