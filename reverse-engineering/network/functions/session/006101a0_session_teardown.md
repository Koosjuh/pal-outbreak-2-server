# 0x006101a0 session_teardown

| field | value |
|---|---|
| Original address | 0x006101a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006101a0 |
| Resolved name | session_teardown |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060f910
**Callees:** FUN_0060e160, FUN_0060f8d0
**Referenced globals:** iRam0070d1c0 (context base); ctx+0x1180 (net sub-context)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Tears down the active session: screen_sm_reset(0) then FUN_0060e160(ctx+0x1180) (transport close).

## Notes / uncertainty
Terminal teardown: SM reset FUN_0060f8d0(0) + close net sub-context at session_ctx(0x70d1c0)+0x1180. Callee contracts inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006101a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
