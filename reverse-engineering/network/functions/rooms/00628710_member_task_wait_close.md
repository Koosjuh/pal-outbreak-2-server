# 0x00628710 member_task_wait_close

| field | value |
|---|---|
| Original address | 0x00628710 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00628710 |
| Resolved name | member_task_wait_close |
| Subsystem | rooms |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00627d60
**Callees:** FUN_0062ba70
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sub-step that polls FUN_0062ba70 and, when it completes, resets the msg task to state 0.

## Notes / uncertainty
Wait substep: polls FUN_0062ba70; on nonzero resets task selector/sub to 0. Returns -1. Poll completion semantics not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00628710.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
