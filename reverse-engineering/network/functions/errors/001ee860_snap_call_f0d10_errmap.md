# 0x001ee860 snap_call_f0d10_errmap

| field | value |
|---|---|
| Original address | 0x001ee860 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee860 |
| Resolved name | snap_call_f0d10_errmap |
| Subsystem | errors |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c08e0
**Callees:** FUN_001f0d10
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Calls FUN_001f0d10() and remaps its return into a normalized error space (-2→-3, passes -6 through, else -1 unless real value).

## Notes / uncertainty
Error-normalization wrapper over FUN_001f0d10: -2->-3, -6->-2, -1->-1, else pass-through. Corrected the prior note (-6 is remapped to -2, not passed through). Inner code domain meanings inferred, not runtime-traced.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee860.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
