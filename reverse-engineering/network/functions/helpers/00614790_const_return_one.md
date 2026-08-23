# 0x00614790 const_return_one

| field | value |
|---|---|
| Original address | 0x00614790 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00614790 |
| Resolved name | const_return_one |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060f910
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns constant 1 (stub predicate / 'ready' flag).

## Notes / uncertainty
Always returns 1; stub enable/ready predicate called from frame renderer 0x60f910. Value certain, guarded-feature role inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00614790.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
