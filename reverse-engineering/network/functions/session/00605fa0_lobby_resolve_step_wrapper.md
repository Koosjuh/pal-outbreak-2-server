# 0x00605fa0 lobby_resolve_step_wrapper

| field | value |
|---|---|
| Original address | 0x00605fa0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00605fa0 |
| Resolved name | lobby_resolve_step_wrapper |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac400
**Callees:** FUN_00606000
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Pumps FUN_00606000 (resolve+connect) one step and maps its result to a tri-state (1 done, 0 pending, -1 error).

## Notes / uncertainty
Tri-state adapter over FUN_00606000(1): 0->done(1), -2->pending(0), else->error(-1). Meaning of the '1' arg and inner code set unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00605fa0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
