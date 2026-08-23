# 0x005fed10 screen_enter_with_render_cb

| field | value |
|---|---|
| Original address | 0x005fed10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fed10 |
| Resolved name | screen_enter_overlay_0x17 |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe730 (screen dispatcher)
**Callees:** FUN_005b68e0 (teardown prior overlay), FUN_005c44a0 (register overlay render callback with input-mode)
**Referenced globals:** ctx +0xf/+0x10 step; +0x443 screen mode; +0x42b active-overlay id (set 0x17)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xf/+0x10 step; +0x443 mode

## Behavioral explanation
One-shot screen-enter stub in the `FUN_005fe730` dispatch table. It advances the screen step, sets the screen mode field to 2, tears down the previous overlay, tags the active-overlay id as `0x17`, and registers render callback `0x601300` with input-mode 1. One member of a family of near-identical enter stubs that differ only by overlay id and render cb (peers: FUN_005ff690→0x18, FUN_005ff760→0x19). No network.

## Input / output
- **param_1** (`int`, screen_ctx*): active screen; +0xf/+0x10 step, +0x42b overlay id, +0x443 mode.
- **returns** `void`.

## Side effects
- +0xf incremented; +0x10 = 0.
- +0x443 = 2 (screen mode).
- `FUN_005b68e0()` teardown; +0x42b = 0x17; `FUN_005c44a0(1, 0x601300)` render-cb register.

## Important branches
None (straight-line, runs once when the dispatcher reaches this step).

## Constants & flags
- `0x17` = active-overlay id (+0x42b) — dispatch tag for this screen.
- `0x443` mode value `2` [inferred: input/render mode].
- `FUN_005c44a0` first arg `1` = input-mode (1 = interactive) [inferred]; `0x601300` = render cb.

## Corrected reconstruction
```c
// Enter screen with active-overlay id 0x17 and render cb 0x601300.
void screen_enter_overlay_0x17(screen_ctx *s)   // param_1
{
    s->major_step += 1;                          // +0xf
    s->substate    = 0;                          // +0x10
    s->screen_mode = 2;                          // +0x443
    overlay_teardown();                          // FUN_005b68e0
    s->active_overlay = 0x17;                    // +0x42b
    overlay_register_cb(1, 0x601300);            // FUN_005c44a0(mode, cb)
}
```

## Evidence
- Raw decompile `FUN_005fed10.c` (exact).
- Overlay-id +0x42b family: FUN_005ff690 (0x18), FUN_005ff760 (0x19), FUN_005fb790 (0x12) — identical write pattern.
- Runtime-unvalidated.

## Remaining uncertainty
- Meaning of the +0x443 mode value (2) and the `FUN_005c44a0` first arg (1 vs 0 in FUN_005ff690) inferred as input/render mode; not traced into `FUN_005c44a0`.
- The screen behind overlay 0x17 / render cb 0x601300 is not separately reconstructed.
```
