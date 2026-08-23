# 0x001eb784 list_find_pred

| field | value |
|---|---|
| Original address | 0x001eb784 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb784 |
| Resolved name | list_find_pred |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e1ac8
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Walks the list applying a predicate callback; returns the first node where it yields >0 (match), or the negative error it returns.

## Notes / uncertainty
Unlocked linear search; tri-state predicate (>0 match, <0 abort, 0 continue). Paired with ptr_equal by FUN_001e1ac8 (find-then-unlink).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb784.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
