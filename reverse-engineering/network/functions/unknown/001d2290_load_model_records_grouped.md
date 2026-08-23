# 0x001d2290 load_model_records_grouped

| field | value |
|---|---|
| Original address | 0x001d2290 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d2290 |
| Resolved name | load_model_records_grouped |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ccd50
**Callees:** FUN_00186320, FUN_001889b0, FUN_00188ab0, FUN_00189880, FUN_00189bb0, FUN_00199850, FUN_00199890, FUN_001998c0, FUN_001a9a90, FUN_001a9ae0
**Referenced globals:** 0x4052c0/0x40e2c0 model tables; 0x4172c4 per-group count
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Loads grouped model records, copying two 0x40-byte halves into 0x4052c0/0x40e2c0 tables per group.

## Notes / uncertainty
Grouped copier to static tables 0x4052c0/0x40e2c0 (per-group stride 0x180), two 0x40-byte halves per non-first element, counter at 0x4172c4. Table A/B role (render vs collision) inferred. Not network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d2290.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
