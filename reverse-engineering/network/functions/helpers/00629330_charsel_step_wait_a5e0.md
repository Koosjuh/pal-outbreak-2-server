# 0x00629330 charsel_step_wait_dispatch_to2

| field | value |
|---|---|
| Original address | 0x00629330 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00629330 |
| Resolved name | charsel_step_wait_dispatch_to2 |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628e10 (charsel step-table)
**Callees:** FUN_0062a5e0 (overlay_menu_dispatch_695d10)
**Referenced globals:** — (indirectly 0x695d10 via the dispatcher)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
One entry in the charsel/room-menu step table. Each tick it pumps the sub-screen dispatcher `overlay_menu_dispatch_695d10(ctx, 0)` (FUN_0062a5e0). While the dispatcher returns 0 (still running) the step handler returns `-1` ("stay on this step"). When the dispatcher returns non-zero (sub-machine finished) it advances the owning task record to **state 2, step 0** and still returns `-1`. It is the "wait for the menu sub-machine, then go to state 2" transition.

## Input / output
- `param_1` (undefined8): context/task pointer forwarded to the dispatcher.
- `param_2` (u8*): the task state record — `param_2[0]` = state byte, `param_2[1]` = step byte.
- Returns (u32): always `0xffffffff` (-1) = continue/stay sentinel.

## Side effects
- On completion: `param_2[0] = 2`, `param_2[1] = 0` (transition to state 2).
- Drives the sub-screen dispatcher (which may mutate 0x695d10-driven UI state).

## Important branches
- `dispatch() != 0` (done) → set state 2/step 0.
- else → no state change.

## Constants & flags
- Terminal state = 2. Return sentinel `0xffffffff` = keep-current-step.
- Twin of FUN_006293b0 (identical body, terminal state 0 instead of 2) and FUN_00629370 (waits on FUN_0062ba70).

## Corrected reconstruction
```c
u32 charsel_step_wait_dispatch_to2(void *ctx /*param_1*/, u8 *task /*param_2*/)
{
    if (overlay_menu_dispatch_695d10(ctx, 0) != 0) {   // FUN_0062a5e0
        task[0] = 2;    // next state
        task[1] = 0;    // reset step
    }
    return 0xffffffff;  // stay / continue
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_00629330.c`.
- Dispatcher identity from FUN_0062a5e0 record (switch on uRam00695d10).
- Runtime-unvalidated.

## Remaining uncertainty
- The exact meaning of terminal "state 2" in the charsel task machine (which screen/phase) is not traced; grouped with the FUN_00628e10 step table.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00629330.c`  — untouched decompiler output.
