# 0x005ff760 screen_transition_sm_0x19

| field | value |
|---|---|
| Original address | 0x005ff760 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ff760 |
| Resolved name | screen_delayed_overlay_0x19_sm |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe730 (screen dispatcher)
**Callees:** FUN_005b9060 (load list into buffer), FUN_005b68e0 (teardown prior overlay), FUN_005c0750 (register/show overlay render cb), FUN_005b6900 (idle/steady handler)
**Referenced globals:** ctx +0x10 sub-state; +0x16 timer; +0x42b active-overlay id (set 0x19); +0x5ec list buffer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x10 sub-state (0..3); +0x16 timer

## Behavioral explanation
4-state delayed-overlay screen, the `FUN_005fe730`-family twin of `FUN_005fb790`/`FUN_005fb9b0`: load a list, wait a ~76-frame countdown, tear down and show overlay `0x19` (render cb `0x601420`), then idle. The render cb `0x601420` is itself gated on the pending-op tag `0x19` (per FUN_00601420). Purely local UI sequencing; the actual network transaction it visualizes is issued elsewhere.

## Input / output
- **param_1** (`int`, screen_ctx*): active screen; +0x10 sub-state, +0x16 timer, +0x42b overlay id, +0x5ec list buffer.
- **returns** `void`.

## Side effects
- +0x10 driven 0→1→(timer)→2→3.
- +0x16 armed to 0x4c (76 frames).
- +0x5ec filled by `FUN_005b9060(0x14, …)`.
- +0x42b = 0x19 on state 2; `FUN_005b68e0()` + `FUN_005c0750(0x601420)`.

## Important branches
- **state 0 (init):** +0x10=1; +0x16=0x4c; `FUN_005b9060(0x14, +0x5ec)` load list.
- **state 1 (wait):** decrement +0x16; when <0 → `+0x10++` (→2).
- **state 2 (show):** +0x10=3; `FUN_005b68e0()` teardown; +0x42b=0x19; `FUN_005c0750(0x601420)` show overlay.
- **state 3 (idle):** `FUN_005b6900()`.

## Constants & flags
- `0x4c` = 76-frame countdown (~1.27s @60Hz).
- `0x14` = list length (20) to `FUN_005b9060`.
- `0x19` = active-overlay id (+0x42b); `0x601420` = render cb (pending-op-0x19 gated).

## Corrected reconstruction
```c
enum { SC_INIT = 0, SC_WAIT = 1, SC_SHOW = 2, SC_IDLE = 3 };

// Delayed overlay 0x19 screen (FUN_005fe730 family; peer of FUN_005fb790).
void screen_delayed_overlay_0x19_sm(screen_ctx *s)  // param_1
{
    switch (s->substate) {                    // +0x10
    case SC_IDLE:                             // 3
        overlay_run_active();                 // FUN_005b6900
        break;
    case SC_SHOW:                            // 2
        s->substate = SC_IDLE;
        overlay_teardown();                   // FUN_005b68e0
        s->active_overlay = 0x19;             // +0x42b
        overlay_show2(0x601420);              // FUN_005c0750
        break;
    case SC_WAIT:                            // 1
        if (--s->timer < 0)                   // +0x16
            s->substate += 1;
        break;
    case SC_INIT:                            // 0
        s->substate = SC_WAIT;
        s->timer = 0x4c;
        list_load(0x14, s->list_buf);         // FUN_005b9060
        break;
    }
}
```

## Evidence
- Raw decompile `FUN_005ff760.c` (all four states exact).
- Identical shape to FUN_005fb790/9b0 with id 0x19; render cb 0x601420 gated on pending-op tag 0x19 (prior note, FUN_00601420).
- Runtime-unvalidated.

## Remaining uncertainty
- Which content list (0x14 entries) and which pending network op (tag 0x19) this screen fronts is not confirmed here.
- `FUN_005b6900` idle-vs-poll semantics unchanged from the other screens (untraced).
```
