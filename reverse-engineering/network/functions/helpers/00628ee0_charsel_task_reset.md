# 0x00628ee0 charsel_task_reset

| field | value |
|---|---|
| Original address | 0x00628ee0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00628ee0 |
| Resolved name | charsel_task_reset |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f76f0, FUN_005f8d40, FUN_005fe620
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Clears a msg/task record's state fields (+1,+0xe..+0x11).

## Notes / uncertainty
Zeroes task record visible flag(+1) and state cluster (+0xe..+0x11). Individual roles of the 4 state bytes not separated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00628ee0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
