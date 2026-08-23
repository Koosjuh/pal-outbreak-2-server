# 0x0062c750 room_action_validate_step

| field | value |
|---|---|
| Original address | 0x0062c750 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062c750 |
| Resolved name | room_action_validate_step |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062c350
**Callees:** FUN_0062c9f0, FUN_0062cb00
**Referenced globals:** +0x10b4 result
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Timer gate then validates the selected member (FUN_0062c9f0); on OK commits/launches (FUN_0062cb00), else stores the result code +2 into +0x10b4.

## Notes / uncertainty
Step2: settle timer(task+4) then FUN_0062c9f0 validate -> 0=commit(FUN_0062cb00), else store (code+2) into ctx+0x10b4 as UI error code. Validate/commit callee payloads out of batch.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062c750.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
