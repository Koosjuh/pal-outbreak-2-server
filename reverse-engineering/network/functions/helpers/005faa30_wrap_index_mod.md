# 0x005faa30 wrap_index_mod

| field | value |
|---|---|
| Original address | 0x005faa30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005faa30 |
| Resolved name | wrap_index_mod |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fa990
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Index-wrap helper: returns param_2 mod count (@+10), or count-1 when negative.

## Notes / uncertainty
index>=0 -> index%count(+0xa); index<0 -> count-1. Exact and trivial.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005faa30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
