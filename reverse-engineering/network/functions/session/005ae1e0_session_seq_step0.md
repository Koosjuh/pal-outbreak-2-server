# 0x005ae1e0 session_seq_step0

| field | value |
|---|---|
| Original address | 0x005ae1e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ae1e0 |
| Resolved name | session_seq_step0_reset |
| Subsystem | session |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae130 (step dispatcher, case 0)
**Callees:** —
**Referenced globals:** obj+0x993 (step cursor); obj+0x45a; obj+0x44d; 0x701e10
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Case 0 of the per-frame session/connect state machine. The driver `FUN_005ae130(obj)` switches on the step
cursor `obj+0x993` and calls one step handler per tick; this is the entry step. It performs the initial reset
of the sequence:
- clears the input/edge flag `obj+0x45a = 0`,
- clears the global tick/latch `0x701e10 = 0`,
- sets the active/started flag `obj+0x44d = 1`,
- advances the cursor `obj+0x993++` so the next tick runs step 1 (FUN_005ae210).

`obj` is the overlay's session controller object (the same object indexed by +0x993 across steps 0-6). Field
names are inferred from usage: +0x44d reads as a "sequence active" latch set here and consumed downstream.

## Input / output
- `param_1` (int, obj base): session-controller object pointer.
- Returns 0 (undefined8; ignored by the dispatcher).

## Side effects
- `obj+0x45a = 0`, `obj+0x44d = 1`, global `0x701e10 = 0`, `obj+0x993++`.

## Important branches
- None; unconditional reset + advance.

## Constants & flags
- Step cursor field `+0x993` (shared with steps 1-6 via FUN_005ae130). `+0x44d = 1` = sequence-active.

## Corrected reconstruction
```c
// FUN_005ae130 case 0 — connect sequence entry/reset
u64 session_seq_step0_reset(session_ctrl *obj) // param_1
{
    obj->input_edge   = 0;   // +0x45a [inferred]
    g_seq_tick        = 0;   // 0x701e10 [inferred]
    obj->seq_active   = 1;   // +0x44d [inferred]
    obj->step_cursor++;      // +0x993 -> next tick runs step 1
    return 0;
}
```

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ae1e0.c`  — untouched decompiler output.

## Evidence
- Raw: `obj[0x993]++; obj[0x45a]=0; uRam00701e10=0; obj[0x44d]=1; return 0;`.
- Step ordering Confirmed via FUN_005ae130 switch (case 0 → 0x5ae1e0). Field roles Inferred from usage.

## Remaining uncertainty
- Semantic names of +0x45a/+0x44d/0x701e10 are inferred; the object's full layout is not mapped.
