# 0x005fb9b0 info_screen_sm_variant

| field | value |
|---|---|
| Original address | 0x005fb9b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fb9b0 |
| Resolved name | info_screen_delayed_overlay_sm_v2 |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fb710 (per-frame screen dispatcher)
**Callees:** FUN_005b9060 (load list), FUN_005b68e0 (begin overlay teardown), FUN_005c0750 (register/show overlay builder), FUN_005b6900 (terminal steady-state handler)
**Referenced globals:** screen ctx +0x10 sub-state; +0x16 timer; +0x42b active-overlay-id (set 0x13); +0x5ec list buffer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x10 sub-state (0..3)

## Behavioral explanation
Structural twin of `FUN_005fb790` (info_screen_delayed_overlay_sm): same 4-state countdown-then-show sequence, differing only in the overlay id written (0x13 vs 0x12), the show routine (`FUN_005c0750` vs `FUN_005bfdd0`), and the builder address (0x5fc6b0 vs 0x5fc610). Purely local UI; no network opcodes.

## Input / output
- **param_1** (`int`, screen_ctx*): active screen context; +0x10 sub-state, +0x16 timer, +0x42b overlay id, +0x5ec list buffer.
- **returns** `void`.

## Side effects
- +0x10 driven 0→1→(timer)→2→3.
- +0x16 armed to 0x2e (46 frames).
- +0x5ec filled by `FUN_005b9060(0x14, …)`.
- +0x42b set to 0x13 on entry to state 2.
- Overlay swapped via `FUN_005b68e0()` + `FUN_005c0750(0x5fc6b0)`.

## Important branches
- **sub-state 0:** +0x10=1; load list (0x14 entries); timer = 0x2e.
- **sub-state 1:** decrement timer; <0 → advance.
- **sub-state 2:** +0x10=3; teardown; overlay id +0x42b=0x13; show builder 0x5fc6b0 via `FUN_005c0750`.
- **sub-state 3:** `FUN_005b6900()` idle/terminal.

## Constants & flags
- `0x2e` = 46-frame countdown.
- `0x14` = list length (20).
- `0x13` = active-overlay id (+0x42b).
- `0x5fc6b0` = overlay builder passed to `FUN_005c0750`.

## Corrected reconstruction
```c
enum { INFO_INIT = 0, INFO_WAIT = 1, INFO_SHOW = 2, INFO_IDLE = 3 };

// Peer of info_screen_delayed_overlay_sm; overlay 0x13, builder 0x5fc6b0.
void info_screen_delayed_overlay_sm_v2(screen_ctx *s)  // param_1
{
    switch (s->substate) {              // +0x10
    case INFO_IDLE:                     // 3
        overlay_run_active();           // FUN_005b6900
        break;
    case INFO_SHOW:                     // 2
        s->substate       = INFO_IDLE;
        overlay_teardown();             // FUN_005b68e0
        s->active_overlay = 0x13;       // +0x42b
        overlay_show2(0x5fc6b0);        // FUN_005c0750(builder)
        break;
    case INFO_WAIT:                     // 1
        if (--s->timer < 0)             // +0x16
            s->substate += 1;
        break;
    case INFO_INIT:                     // 0
        s->substate = INFO_WAIT;
        list_load(0x14, s->list_buf);   // FUN_005b9060
        s->timer = 0x2e;
        break;
    }
}
```

## Evidence
- Raw decompile `FUN_005fb9b0.c` — byte-for-byte the FUN_005fb790 shape with id 0x13 and show-routine FUN_005c0750(0x5fc6b0).
- Overlay-id +0x42b family cross-ref (FUN_005fed10/ff690/ff760).
- Runtime-unvalidated.

## Remaining uncertainty
- Distinction between the two show routines `FUN_005bfdd0` vs `FUN_005c0750` (likely different overlay layer/z-order or input-mode) not traced.
- Which content list (0x14 entries) this variant presents is unconfirmed.
```
