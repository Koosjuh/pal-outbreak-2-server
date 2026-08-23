# 0x00629370 charsel_step_wait_ba70_to0

| field | value |
|---|---|
| Original address | 0x00629370 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00629370 |
| Resolved name | charsel_step_wait_ba70_to0 |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628e10 (charsel step-table)
**Callees:** FUN_0062ba70 (sub-machine poll / teardown)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Charsel/room-menu step handler that pumps a different sub-machine, `FUN_0062ba70()`, each tick. While it returns 0 the step stays (returns `-1`); when it returns non-zero (finished) the owning task record is reset to **state 0, step 0** and the handler still returns `-1`. This is the "wait for the ba70 sub-machine, then return to the top/idle state 0" transition (a close/teardown wait, versus FUN_00629330 which advances forward to state 2).

## Input / output
- `param_1` (undefined8): context (passed through; FUN_0062ba70 takes no visible arg here).
- `param_2` (u8*): task state record — `[0]` state, `[1]` step.
- Returns (u32): always `0xffffffff` (-1) = stay/continue sentinel.

## Side effects
- On completion: `param_2[0] = 0`, `param_2[1] = 0` (return to state 0).

## Important branches
- `FUN_0062ba70() != 0` (done) → reset to state 0/step 0.
- else → no change.

## Constants & flags
- Terminal state = 0. Return sentinel `0xffffffff`.
- Sibling of FUN_00629330 / FUN_006293b0 (which poll the 695d10 dispatcher). This one polls FUN_0062ba70 (a distinct sub-machine — likely the close/exit path).

## Corrected reconstruction
```c
u32 charsel_step_wait_ba70_to0(void *ctx /*param_1, unused by callee*/, u8 *task /*param_2*/)
{
    if (FUN_0062ba70() != 0) {   // sub-machine finished
        task[0] = 0;             // back to idle/top state
        task[1] = 0;
    }
    return 0xffffffff;           // stay / continue
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_00629370.c`.
- Structural twin of FUN_00629330/FUN_006293b0 confirms the task-record state/step layout.
- Runtime-unvalidated.

## Remaining uncertainty
- FUN_0062ba70's role (teardown vs a specific sub-screen) is not reconstructed here; only its boolean "done" contract is used.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00629370.c`  — untouched decompiler output.
