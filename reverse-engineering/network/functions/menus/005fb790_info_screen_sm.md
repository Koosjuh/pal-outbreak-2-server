# 0x005fb790 info_screen_sm

| field | value |
|---|---|
| Original address | 0x005fb790 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fb790 |
| Resolved name | info_screen_delayed_overlay_sm |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fb710 (per-frame screen dispatcher)
**Callees:** FUN_005b9060 (load list into buffer), FUN_005b68e0 (begin overlay teardown/transition), FUN_005bfdd0 (register/show overlay builder), FUN_005b6900 (terminal steady-state handler)
**Referenced globals:** screen ctx +0x10 sub-state; +0x16 countdown timer; +0x42b active-overlay-id (set 0x12); +0x5ec list buffer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x10 sub-state (0..3)

## Behavioral explanation
Per-frame state machine for a delayed info/list overlay screen. It fills a list buffer, waits a fixed ~46-frame countdown, then tears down the current overlay and shows a new overlay (id 0x12) built by `0x5fc610`, finally idling in a terminal steady state. `param_1` is the screen/menu context object (same family as the FUN_005fe730 screens; sub-state lives at +0x10). It is a purely local UI SM — no network opcodes are emitted here.

## Input / output
- **param_1** (`int`, screen_ctx*): pointer to the active screen context block; fields at +0x10 (sub-state), +0x16 (timer), +0x42b (overlay id), +0x5ec (list buffer).
- **returns** `void`. Effect is entirely via the context block and the overlay subsystem.

## Side effects
- +0x10 driven 0→1→(timer)→2→3.
- +0x16 initialized to 0x2e (46) as a frame countdown.
- +0x5ec populated by `FUN_005b9060(0x14, …)` (20-entry list load).
- +0x42b set to 0x12 (active-overlay dispatch tag) on entry to state 2.
- Overlay swapped: `FUN_005b68e0()` then `FUN_005bfdd0(0x5fc610)`.

## Important branches
- **sub-state 0 (init):** set +0x10=1; `FUN_005b9060(0x14, param_1+0x5ec)` loads the list; arm timer +0x16 = 0x2e.
- **sub-state 1 (wait):** decrement +0x16; when it goes negative, `+0x10 += 1` → advance to 2. (Written as `+0x10 = +0x10 + 1`, i.e. generic advance.)
- **sub-state 2 (show):** set +0x10=3; `FUN_005b68e0()` (teardown prior overlay); set overlay id +0x42b=0x12; `FUN_005bfdd0(0x5fc610)` shows the new overlay with builder 0x5fc610.
- **sub-state 3 (idle):** `FUN_005b6900()` — terminal per-frame handler for the shown overlay (dismiss/maintain). No further advance from within this fn.

## Constants & flags
- `0x2e` = 46-frame countdown (≈0.77s @60Hz) [inferred timing].
- `0x14` = list length arg (20 entries) to `FUN_005b9060`.
- `0x12` = active-overlay id written to +0x42b (screen-dispatch tag) [evidence: literal store].
- `0x5fc610` = overlay builder/render-cb address passed to `FUN_005bfdd0`.

## Corrected reconstruction
```c
// screen_ctx sub-state machine; runs once per frame from FUN_005fb710.
// Shows info overlay 0x12 after a fixed countdown.
enum { INFO_INIT = 0, INFO_WAIT = 1, INFO_SHOW = 2, INFO_IDLE = 3 };

void info_screen_delayed_overlay_sm(screen_ctx *s)   // param_1
{
    switch (s->substate) {          // +0x10
    case INFO_IDLE:                 // 3
        overlay_run_active();       // FUN_005b6900 — steady/terminal handler
        break;

    case INFO_SHOW:                 // 2
        s->substate      = INFO_IDLE;
        overlay_teardown();         // FUN_005b68e0
        s->active_overlay = 0x12;   // +0x42b
        overlay_show(0x5fc610);     // FUN_005bfdd0(builder)
        break;

    case INFO_WAIT:                 // 1
        if (--s->timer < 0)         // +0x16
            s->substate += 1;       // advance -> INFO_SHOW
        break;

    case INFO_INIT:                 // 0
        s->substate = INFO_WAIT;
        list_load(0x14, s->list_buf); // FUN_005b9060(20, +0x5ec)
        s->timer = 0x2e;            // 46-frame countdown
        break;
    }
}
```

## Evidence
- Raw decompile `FUN_005fb790.c` (states 0/1/2/3 exact); caller FUN_005fb710; callees FUN_005b9060/68e0/bfdd0/6900.
- Overlay-id +0x42b and list-buffer +0x5ec offsets are shared across the FUN_005fe730/FUN_005fb710 screen family (cross-ref FUN_005fed10/005ff690/005ff760 which write +0x42b = 0x17/0x18/0x19).
- Runtime-unvalidated (no PINE/rig trace of this specific screen).

## Remaining uncertainty
- Which list this info screen shows (content of the 20-entry list) is unconfirmed.
- `FUN_005b6900` semantics (pure idle vs. polls for dismissal/back) not traced; state 3 has no exit within this fn, so exit is presumably driven by another handler or by `FUN_005b6900` mutating the context.
- `FUN_005b68e0`/`FUN_005bfdd0` exact contract (register vs. immediately draw) inferred from usage pattern.
```
