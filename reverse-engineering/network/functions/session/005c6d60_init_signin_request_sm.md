# 0x005c6d60 init_signin_request_sm

| field | value |
|---|---|
| Original address | 0x005c6d60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c6d60 |
| Resolved name | init_signin_request_sm |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bd2e0
**Callees:** —
**Referenced globals:** 0x6cbb9c done-cb; 0x6cbbb8 sm-phase; 0x6cbbbc sm-active; 0x6cbb98 pump-fnptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006cbbbc sm-active; cRam006cbbb8 phase

## Behavioral explanation
Registers FUN_005c6da0 as the sign-in/matchmaking request pump and stores its completion callback, arming the state machine.

## Notes / uncertainty
Arms the separate login/matchmaking REQUEST SM (cluster 0x6cbb98/9c/b8/bc), pump=FUN_005c6da0, no re-entry guard. param_1 cb-vs-ctx ambiguous.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c6d60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
