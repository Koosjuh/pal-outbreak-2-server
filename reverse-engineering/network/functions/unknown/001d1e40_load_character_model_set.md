# 0x001d1e40 load_character_model_set

| field | value |
|---|---|
| Original address | 0x001d1e40 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1e40 |
| Resolved name | load_character_model_set |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ccd50
**Callees:** FUN_00186320, FUN_00186610, FUN_001889b0, FUN_00188ab0, FUN_00189880, FUN_00189bb0, FUN_00199850, FUN_00199890, FUN_001998c0, FUN_001a9a90, FUN_001a9ae0
**Referenced globals:** 0x4e0660/0x4e0678/0x4ddb43/0x4ddb44 char-group tables; 0x4e0690
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Loads grouped character model/motion records, copying 0x40-byte blocks into 0x4e0xxx tables per group.

## Notes / uncertainty
Grouped character model/motion loader; per-group boundary map, anim-byte scan (rec+0x174<0), dual 0x40-byte copies into caller tables param_3/param_4 keyed by rec[0x5d]; global tables 0x4e0660/78/90, 0x4ddb44. Not network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1e40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
