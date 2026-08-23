# 0x005ae210 session_seq_step1

| field | value |
|---|---|
| Original address | 0x005ae210 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ae210 |
| Resolved name | session_seq_step1_init |
| Subsystem | session |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae130 (step dispatcher, case 1)
**Callees:** FUN_00618b60; func_0x003adb80; FUN_005b24c0
**Referenced globals:** obj+0x447; obj+0x993 (step cursor)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Case 1 of the session/connect state machine (after step0 reset). It runs three init/commit calls, clears a
busy flag, and advances to step 2:
- `FUN_00618b60()` — subsystem init/frame-commit (no args passed through).
- `func_0x003adb80()` — external/library init thunk (raw indirect call).
- `FUN_005b24c0()` — a second init routine.
- clears `obj+0x447 = 0` (busy/pending latch),
- advances the cursor `obj+0x993++` → next tick runs step 2 (FUN_005ae260).

All three callees are invoked for their side effects (return values unused). This is the "bring up the
session context" step between the reset (step0) and the resource-load kick (step2).

## Input / output
- `param_1` (int, obj base): session-controller object.
- Returns 0 (ignored).

## Side effects
- Calls FUN_00618b60, func_0x003adb80, FUN_005b24c0 (init side effects).
- `obj+0x447 = 0`; `obj+0x993++`.

## Important branches
- None; unconditional init + advance.

## Constants & flags
- Step cursor `+0x993`. `+0x447` cleared here (busy/pending flag [inferred]).

## Corrected reconstruction
```c
// FUN_005ae130 case 1 — session context init
u64 session_seq_step1_init(session_ctrl *obj) // param_1
{
    FUN_00618b60();          // subsystem init / frame-commit
    (*func_0x003adb80)();    // external init thunk (raw indirect)
    FUN_005b24c0();          // secondary init
    obj->busy = 0;           // +0x447 [inferred]
    obj->step_cursor++;      // +0x993 -> next tick runs step 2
    return 0;
}
```

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ae210.c`  — untouched decompiler output.

## Evidence
- Raw: `FUN_00618b60(); func_0x003adb80(); FUN_005b24c0(); obj[0x447]=0; obj[0x993]++; return 0;`.
- Step ordering Confirmed via FUN_005ae130 (case 1 → 0x5ae210). Callee roles inferred (no arg/return trace).

## Remaining uncertainty
- What each of the three init callees actually initializes; the semantic name of +0x447. Runtime-unvalidated.
