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
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628e10
**Callees:** FUN_0062ba70
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sub-step: polls FUN_0062ba70 and, when done, resets msg to state 0.

## Notes / uncertainty
Step handler: pumps FUN_0062ba70 (distinct sub-machine, likely teardown); on done resets task to state 0. FUN_0062ba70 role only used as boolean-done.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00629370.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
