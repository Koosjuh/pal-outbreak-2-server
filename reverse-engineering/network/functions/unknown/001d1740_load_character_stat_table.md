# 0x001d1740 load_character_stat_table

| field | value |
|---|---|
| Original address | 0x001d1740 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1740 |
| Resolved name | load_character_stat_table |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001cce80, FUN_001ce090, FUN_001ce2d0
**Callees:** FUN_0019a010, FUN_0019a110, FUN_0019a1e0, FUN_001a9d30, FUN_001cbc40, FUN_001cbcb0, FUN_001cbd20
**Referenced globals:** 0x52d624.. char/entity stat table (stride 0x48); struct+0x814 count
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Parses a data blob and fills per-entity stat/transform records in the 0x52d620 character table.

## Notes / uncertainty
Fills 0x52d620 entity stat/transform table (stride 0x4c) from archive; per-record model-handle resolve with 0xff0 fallback; param_3 selects model source. Transform field labels inferred. Not network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1740.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
