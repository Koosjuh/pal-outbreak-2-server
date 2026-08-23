# 0x00623090 screen_handler_submachine

| field | value |
|---|---|
| Original address | 0x00623090 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00623090 |
| Resolved name | screen_handler_submachine |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_0060f8d0, FUN_0060f910, FUN_0061e940, FUN_0061e9c0, FUN_0061ea10, FUN_0061f0d0
**Referenced globals:** 0x715298 screen struct ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** substate @ struct+1; struct+0x28 flag

## Behavioral explanation
Screen handler wrapping a sub-machine (FUN_0060f910 step / FUN_0060f8d0 start) with a param from struct+0x10; maps its result to advance/abort.

## Notes / uncertainty
Wraps nested lobby-op SM FUN_0060f8d0 start / FUN_0060f910 step with param obj+0x10; step result 2 latches obj+0x28. Likely room enter/create/transfer wrapper - decompile 0x60f8d0/0x60f910 next.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00623090.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
