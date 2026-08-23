# 0x001d2170 load_model_records_single

| field | value |
|---|---|
| Original address | 0x001d2170 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d2170 |
| Resolved name | load_model_records_single |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ccd50
**Callees:** FUN_00186320, FUN_001889b0, FUN_00188ab0, FUN_00189880, FUN_00189bb0, FUN_00199850, FUN_001a9a90, FUN_001a9ae0
**Referenced globals:** 0x3435d8 dest table base; 0x3435bc scratch
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Loads a single model archive and copies 0x40-byte records into the iRam003435d8 table.

## Notes / uncertainty
Flat single-group variant: copies valid 0x40-byte records into iRam3435d8 by rec[0x5d]. Not network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d2170.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
