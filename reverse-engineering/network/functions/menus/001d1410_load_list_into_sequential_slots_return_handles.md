# 0x001d1410 load_list_into_sequential_slots_return_handles

| field | value |
|---|---|
| Original address | 0x001d1410 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1410 |
| Resolved name | load_list_into_sequential_slots_return_handles |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109eb8, FUN_001a79b0, FUN_001cb360, FUN_001cb5f0, FUN_001cbcb0, FUN_001cf2b0
**Referenced globals:** piRam003435bc work base
**Referenced strings:** 0x24ce50 template
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Fetches tmpl 0x24ce50, parses each record into channels 1.. via FUN_001a79b0/FUN_001cb5f0, and writes the resulting slot handles (FUN_001cbcb0) back into the param_1 output array.

## Notes / uncertainty
Same archive 0x24ce50 as 0x1d1050; installs records 0..count-2 into slots 1.. and returns handles in param_1[]. out-array capacity assumed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1410.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
