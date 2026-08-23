# 0x005fec30 screen_wait_net_ready

| field | value |
|---|---|
| Original address | 0x005fec30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fec30 |
| Resolved name | screen_net_gated_confirm_menu |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe730 (screen dispatcher)
**Callees:** FUN_005c0f60 (rebuild overlay from context), FUN_005f4b80 (network pump/update), FUN_005f4be0 (query net pending — 0 = ready/idle), FUN_005b14b0 (poll input mask), FUN_005b09b0 (cursor nav helper), FUN_005f54d0 (draw pass), func_0x001b0140 (SFX cue)
**Referenced globals:** uRam006c4600 menu-context ptr; ctx +0x97f dirty flag; +0x992 busy flag; +0x907 cursor; +0xf/+0x10 step; +0x16 timer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x992 busy; +0x907 cursor; +0xf/+0x10 step

## Behavioral explanation
A screen that is **gated on network readiness** and then presents a small confirm/cancel menu. Each frame it: rebuilds its overlay if marked dirty, pumps the network, and — only when the network reports idle/ready (`FUN_005f4be0()==0`) — processes input over a 3-item cursor menu. Confirm advances the screen step; cancel resets the cursor; otherwise the cursor navigates. Always ends by issuing a draw pass. This is a lobby-stage gate screen (e.g. waiting for a pending network transaction to complete before letting the user proceed).

## Input / output
- **param_1** (`int`, screen_ctx*): active screen; +0x97f dirty, +0x992 busy, +0x907 cursor, +0xf/+0x10 step, +0x16 timer.
- **returns** `void`.

## Side effects
- Consumes/clears dirty flag +0x97f → `FUN_005c0f60(uRam006c4600, 0x600ff0)` rebuild.
- Sets/clears busy flag +0x992.
- On confirm: +0xf++, +0x10=0, +0x16=8, SFX 1.
- On cancel: cursor +0x907=1, SFX 2.
- Always: `FUN_005f54d0(2)` draw.

## Important branches
- **dirty (+0x97f != 0):** clear it; rebuild overlay via `FUN_005c0f60(menu_ctx, 0x600ff0)`.
- Always pump net (`FUN_005f4b80()`).
- **net ready (`FUN_005f4be0()==0`):** set busy +0x992=1, then:
  - **input mask 0x10 pressed (confirm):** advance step (+0xf++, +0x10=0), SFX(1), timer +0x16=8, clear busy.
  - **else mask 0x200 pressed (cancel/back):** SFX(2), cursor +0x907=1, clear busy.
  - **else (no button):** `FUN_005b09b0(&cursor, 1, 3)` — navigate the 3-item cursor.
- **net not ready:** skip the input block (screen stays, still draws).
- Always draw `FUN_005f54d0(2)`.

## Constants & flags
- input masks: `0x10` = confirm/OK, `0x200` = cancel/back [inferred from SFX + step semantics].
- `FUN_005b09b0(cursor, 1, 3)` → cursor range 3 items, step 1.
- SFX ids `1` (confirm), `2` (cancel) via `func_0x001b0140`.
- confirm timer `+0x16 = 8`.
- `FUN_005f4be0() == 0` = network idle/ready gate.

## Corrected reconstruction
```c
// Net-gated confirm menu: only accepts input once the network is idle.
void screen_net_gated_confirm_menu(screen_ctx *s)   // param_1
{
    if (s->dirty) {                                  // +0x97f
        s->dirty = 0;
        overlay_rebuild(uRam006c4600, 0x600ff0);     // FUN_005c0f60
    }
    net_pump();                                      // FUN_005f4b80

    if (net_pending() == 0) {                        // FUN_005f4be0 : ready
        s->busy = 1;                                 // +0x992
        if (input_poll(0x10)) {                      // confirm
            s->major_step += 1; s->substate = 0;     // advance
            sfx(1); s->timer = 8; s->busy = 0;
        } else if (input_poll(0x200)) {              // cancel
            sfx(2); s->cursor = 1; s->busy = 0;      // +0x907
        } else {
            cursor_nav(&s->cursor, 1, 3);            // FUN_005b09b0
        }
    }
    draw_pass(2);                                    // FUN_005f54d0
}
```

## Evidence
- Raw decompile `FUN_005fec30.c` (net gate, input dispatch, draw exact).
- `FUN_005f4b80`/`FUN_005f4be0` are the net pump / pending-query pair used across lobby gate screens.
- +0x992 busy and +0x907 cursor are shared screen-ctx fields (cross-ref FUN_005ff690 which also writes +0x907).
- Runtime-unvalidated.

## Remaining uncertainty
- Exact input-mask semantics (`0x10` confirm vs `0x200` cancel) inferred from step/SFX use, not from the input table.
- Which lobby transaction this screen waits on (`FUN_005f4be0` pending source) is not identified here.
```
