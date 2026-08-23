# 0x005c8e00 state_handler_poll_result_advance

| field | value |
|---|---|
| Original address | 0x005c8e00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c8e00 |
| Resolved name | state_handler_poll_result_advance |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005de170
**Referenced globals:** 0x701070+1/+2 (state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+1

## Behavioral explanation
State handler: polls FUN_005de170(1); if result value ==2 resets session state to 2/0.

## Notes / uncertainty
Polls reply channel FUN_005de170(1); on result code==2 sets major state (0x701070+1)=2, step=0. 'code 2=success' inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c8e00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
