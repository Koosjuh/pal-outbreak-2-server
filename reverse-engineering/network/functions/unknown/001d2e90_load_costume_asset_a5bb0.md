# 0x001d2e90 load_costume_asset_a5bb0

| field | value |
|---|---|
| Original address | 0x001d2e90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d2e90 |
| Resolved name | load_costume_asset_a5bb0 |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_001a5bb0
**Referenced globals:** struct+0xc8c char id; 0x24d120 path fmt
**Referenced strings:** (path fmt @0x24d120)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Same as 0x1d2e00 but dispatches the load through FUN_001a5bb0 instead of 0x1d31b0.

## Notes / uncertainty
Costume/model loader for one actor: id at +0xc8c remapped (0x0061dca0), slot bound, path 0x24d120, loaded into model slot (+3)+8 via FUN_001a5bb0. Non-network. Slot-bind/load callee semantics inferred, not traced.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d2e90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
