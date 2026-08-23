# 0x005c0850 return_neg1_stub

| field | value |
|---|---|
| Original address | 0x005c0850 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0850 |
| Resolved name | return_neg1_stub |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe8d0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns constant 0xffffffff (-1); trivial stub/placeholder.

## Notes / uncertainty
Twin of return_const_neg1; -1 sentinel, second inert branch of FUN_005fe8d0. Was Low(role); behavior High. Role/slot unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0850.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
