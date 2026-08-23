# 0x005ae210 session_seq_step1_init

| field | value |
|---|---|
| Original address | 0x005ae210 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ae210 |
| Resolved name | session_seq_step1_init |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae130
**Callees:** FUN_005b24c0, FUN_00618b60
**Referenced globals:** obj +0x447/+0x993
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Session-seq step 1: frame-commit + ext init (003adb80) + FUN_005b24c0, clears +0x447, advances cursor.

## Notes / uncertainty
FUN_005ae130 case 1. Runs FUN_00618b60/func_003adb80/FUN_005b24c0 init, clears +0x447, advances cursor. Callee roles inferred (no arg/return trace).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ae210.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
