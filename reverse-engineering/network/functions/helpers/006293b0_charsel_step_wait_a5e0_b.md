# 0x006293b0 charsel_step_wait_dispatch_to0

| field | value |
|---|---|
| Original address | 0x006293b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006293b0 |
| Resolved name | charsel_step_wait_dispatch_to0 |
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
Twin of FUN_00629330: each tick it pumps the sub-screen dispatcher `overlay_menu_dispatch_695d10(ctx, 0)` (FUN_0062a5e0) and returns `-1` ("stay") while it is still running. When the dispatcher finishes (returns non-zero) it resets the owning task record to **state 0, step 0** (return to top/idle) rather than advancing to state 2. Used where the charsel step machine wants to run the menu sub-machine and then fall back to the idle state.

## Input / output
- `param_1` (undefined8): context/task pointer forwarded to the dispatcher.
- `param_2` (u8*): task state record — `[0]` state, `[1]` step.
- Returns (u32): always `0xffffffff` (-1) = stay/continue sentinel.

## Side effects
- On completion: `param_2[0] = 0`, `param_2[1] = 0`.
- Drives the sub-screen dispatcher.

## Important branches
- `dispatch() != 0` (done) → set state 0/step 0.
- else → no change.

## Constants & flags
- Terminal state = 0 (vs FUN_00629330's 2). Return sentinel `0xffffffff`.

## Corrected reconstruction
```c
u32 charsel_step_wait_dispatch_to0(void *ctx /*param_1*/, u8 *task /*param_2*/)
{
    if (overlay_menu_dispatch_695d10(ctx, 0) != 0) {   // FUN_0062a5e0
        task[0] = 0;   // back to idle/top state
        task[1] = 0;
    }
    return 0xffffffff;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_006293b0.c` — byte-identical to FUN_00629330 except terminal state (0 vs 2).
- Runtime-unvalidated.

## Remaining uncertainty
- Which caller-side step in FUN_00628e10 selects the to-0 vs to-2 variant is untraced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006293b0.c`  — untouched decompiler output.
