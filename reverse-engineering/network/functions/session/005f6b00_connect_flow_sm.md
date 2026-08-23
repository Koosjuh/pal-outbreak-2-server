# 0x005f6b00 connect_flow_sm

| field | value |
|---|---|
| Original address | 0x005f6b00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f6b00 |
| Resolved name | connect_flow_sm |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f6aa0
**Callees:** FUN_005af2f0, FUN_005af300, FUN_005af310, FUN_005af340, FUN_005b24c0, FUN_005b9110, FUN_005f4550, FUN_005f6a20, FUN_005f70a0, FUN_005f7270, FUN_00606f10, FUN_00618b60
**Referenced globals:** 0x3c8a80; param+0x11 (step); param+0x97b (context/mode)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x11 (step 0-7); param+0x16 (dwell timer); param+0x97b (context)

## Behavioral explanation
State machine on +0x11 (0-7) driving the connect/lobby-join sequence: memory setup, retry timers, runs the wait-overlay SM FUN_005f7270, resets network via FUN_005b24c0, branches on context byte +0x97b to next screen (FUN_00606f10/FUN_005f4550).

## Notes / uncertainty
Connecting-screen SM (step +0x11 0..7, timer +0x16, mode +0x97b): link/ready polls (005af310/340), wait-overlay (005f7270), net teardown/setup glue, step-7 forks host(0/2->00606f10) vs client(1->clear 0x3c8a80 + 005f4550). Origin of +0x97b value and af310-vs-af340 distinction untraced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f6b00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
