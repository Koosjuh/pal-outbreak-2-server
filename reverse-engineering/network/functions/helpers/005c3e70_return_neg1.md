# 0x005c3e70 return_neg1

| field | value |
|---|---|
| Original address | 0x005c3e70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c3e70 |
| Resolved name | return_neg1 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062ab50
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Constant stub returning 0xffffffff (-1).

## Notes / uncertainty
Constant -1 (0xffffffff) invalid/unavailable accessor; pairs with the >=0 valid-handle convention.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c3e70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
