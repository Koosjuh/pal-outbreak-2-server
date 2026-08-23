# 0x00607cf0 txn_state3_recover_resend

| field | value |
|---|---|
| Original address | 0x00607cf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00607cf0 |
| Resolved name | txn_state3_recover_resend |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00607a10
**Callees:** FUN_005b14b0, FUN_005b8cf0, FUN_005b9110
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Txn sub-state 3: 0x13c-tick response wait; on completion (005b14b0(0x10)) resets to state 2 with audio cue 0x4c.

## Notes / uncertainty
State-3 recovery: resends selector -101, 316-tick timeout with 30-tick accept guard, always falls back to state 2. Reached from state1 when err_flag set.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00607cf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
