# 0x0061e710 ui_return_true_stub

| field | value |
|---|---|
| Original address | 0x0061e710 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061e710 |
| Resolved name | ui_return_true_stub |
| Subsystem | helpers |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061f850
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Constant stub returning 1 (predicate always-true), consumed by keyboard-flush FUN_0061f850.

## Notes / uncertainty
Constant `return 1` stub; role (always-true gate vs stubbed callback) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061e710.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
