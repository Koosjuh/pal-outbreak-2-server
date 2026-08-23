# 0x005c4420 get_signin_result_2

| field | value |
|---|---|
| Original address | 0x005c4420 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4420 |
| Resolved name | get_signin_result_2 |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00627c90
**Callees:** —
**Referenced globals:** 0x6fbe50/52/54; 0x6fbe57 (auth result byte)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006fbe57

## Behavioral explanation
Duplicate sign-in result getter: reads 0x6fbe50/52/54 + 0x6fbe57 into out params.

## Notes / uncertainty
Instruction-identical duplicate of 0x5c4330, different caller (FUN_00627c90). Same record layout.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4420.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
